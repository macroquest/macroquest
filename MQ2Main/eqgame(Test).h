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
#define __ExpectedVersionDate                                     "Aug 17 2017"
#define __ExpectedVersionTime                                     "11:49:19"
#define __ActualVersionDate_x                                      0xAD7440
#define __ActualVersionTime_x                                      0xAD744C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5A3A10
#define __MemChecker1_x                                            0x89B810
#define __MemChecker2_x                                            0x6396B0
#define __MemChecker3_x                                            0x639600
#define __MemChecker4_x                                            0x7ED870
#define __EncryptPad0_x                                            0xC32328
#define __EncryptPad1_x                                            0xD0D6E0
#define __EncryptPad2_x                                            0xC5BB10
#define __EncryptPad3_x                                            0xC5B710
#define __EncryptPad4_x                                            0xCFBCE0
#define __EncryptPad5_x                                            0x10B6370
#define __AC1_x                                                    0x7AD035
#define __AC2_x                                                    0x55C807
#define __AC3_x                                                    0x55A980
#define __AC4_x                                                    0x56CB51
#define __AC5_x                                                    0x580A0B
#define __AC6_x                                                    0x5845BE
#define __AC7_x                                                    0x57B00C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FECDFC

// Direct Input
#define DI8__Main_x                                                0x10B6348
#define DI8__Keyboard_x                                            0x10B634C
#define DI8__Mouse_x                                               0x10B6350
#define DI8__Mouse_Copy_x                                          0xF2470C
#define DI8__Mouse_Check_x                                         0xFAE034
#define __AutoSkillArray_x                                         0xF25620
#define __Attack_x                                                 0xFA8C17
#define __Autofire_x                                               0xFA8C18
#define __BindList_x                                               0xC0D050
#define g_eqCommandStates_x                                        0xF13730
#define __Clicks_x                                                 0xF247C8
#define __CommandList_x                                            0xC0F6C8
#define __CurrentMapLabel_x                                        0x10BBDD0
#define __CurrentSocial_x                                          0xBDE424
#define __DoAbilityList_x                                          0xF5AECC
#define __do_loot_x                                                0x52B9B0
#define __DrawHandler_x                                            0x1722C84
#define __GroupCount_x                                             0xF14D62

#define __Guilds_x                                                 0xF1A978
#define __gWorld_x                                                 0xF1721C
#define __HotkeyPage_x                                             0xFA18CC
#define __HWnd_x                                                   0xFAE150
#define __InChatMode_x                                             0xF246F4
#define __LastTell_x                                               0xF265C8
#define __LMouseHeldTime_x                                         0xF24834
#define __Mouse_x                                                  0x10B6354
#define __MouseLook_x                                              0xF2478E
#define __MouseEventTime_x                                         0xFA941C
#define __gpbCommandEvent_x                                        0xF172E4
#define __NetStatusToggle_x                                        0xF24791
#define __PCNames_x                                                0xF25BDC
#define __RangeAttackReady_x                                       0xF25904
#define __RMouseHeldTime_x                                         0xF24830
#define __RunWalkState_x                                           0xF246F8
#define __ScreenMode_x                                             0xE63418
#define __ScreenX_x                                                0xF246AC
#define __ScreenY_x                                                0xF246A8
#define __ScreenXMax_x                                             0xF246B0
#define __ScreenYMax_x                                             0xF246B4
#define __ServerHost_x                                             0xF14CAC
#define __ServerName_x                                             0xF5AE8C
#define __ShiftKeyDown_x                                           0xF24D88
#define __ShowNames_x                                              0xF25AC4
#define __Socials_x                                                0xF5AF8C
#define __SubscriptionType_x                                       0x10E9DB4
#define __TargetAggroHolder_x                                      0x10BDFA4
#define __ZoneType_x                                               0xF24B8C
#define __GroupAggro_x                                             0x10BDFE4
#define __LoginName_x                                              0xFACC2C
#define __Inviter_x                                                0xFA8B94
#define __AttackOnAssist_x                                         0xF25A80
#define __UseTellWindows_x                                         0xF25D74

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF17308
#define instEQZoneInfo_x                                           0xF24984
#define instKeypressHandler_x                                      0xFA9400
#define pinstActiveBanker_x                                        0xF172C0
#define pinstActiveCorpse_x                                        0xF172C4
#define pinstActiveGMaster_x                                       0xF172C8
#define pinstActiveMerchant_x                                      0xF172BC
#define pinstAggroInfo_x                                           0xD20D88
#define pinstAltAdvManager_x                                       0xE644F8
#define pinstAuraMgr_x                                             0xD314F8
#define pinstBandageTarget_x                                       0xF172A8
#define pinstCamActor_x                                            0xE63E48
#define pinstCDBStr_x                                              0xE633AC
#define pinstCDisplay_x                                            0xF172D0
#define pinstCEverQuest_x                                          0x10B64C8
#define pinstEverQuestInfo_x                                       0xF246A0
#define pinstCharData_x                                            0xF1728C
#define pinstCharSpawn_x                                           0xF172B4
#define pinstControlledMissile_x                                   0xF17288
#define pinstControlledPlayer_x                                    0xF172B4
#define pinstCSidlManager_x                                        0x1722074
#define pinstCXWndManager_x                                        0x172206C
#define instDynamicZone_x                                          0xF24540
#define pinstDZMember_x                                            0xF24650
#define pinstDZTimerInfo_x                                         0xF24654
#define pinstEQItemList_x                                          0xF13984
#define pinstEQObjectList_x                                        0xF1475C
#define instEQMisc_x                                               0xBF5690
#define pinstEQSoundManager_x                                      0xE64AC8
#define instExpeditionLeader_x                                     0xF2458A
#define instExpeditionName_x                                       0xF245CA
#define pinstGroup_x                                               0xF14D5E
#define pinstImeManager_x                                          0x1722078
#define pinstLocalPlayer_x                                         0xF172A0
#define pinstMercenaryData_x                                       0xFA9A80
#define pinstMercenaryStats_x                                      0x10BE0F0
#define pinstMercAltAbilities_x                                    0xE64880
#define pinstModelPlayer_x                                         0xF172CC
#define pinstPCData_x                                              0xF1728C
#define pinstSkillMgr_x                                            0xFAA8E8
#define pinstSpawnManager_x                                        0xFAA1D0
#define pinstSpellManager_x                                        0xFAAA30
#define pinstSpellSets_x                                           0xFA1930
#define pinstStringTable_x                                         0xF17234
#define pinstSwitchManager_x                                       0xF148F0
#define pinstTarget_x                                              0xF172B8
#define pinstTargetObject_x                                        0xF17290
#define pinstTargetSwitch_x                                        0xF17294
#define pinstTaskMember_x                                          0xE632F8
#define pinstTrackTarget_x                                         0xF172AC
#define pinstTradeTarget_x                                         0xF1729C
#define instTributeActive_x                                        0xBF56B5
#define pinstViewActor_x                                           0xE63E44
#define pinstWorldData_x                                           0xF17270
#define pinstZoneAddr_x                                            0xF24C24
#define pinstPlayerPath_x                                          0xFAA230
#define pinstTargetIndicator_x                                     0xFAABC8
#define pinstCTargetManager_x                                      0xFAAC28
#define EQObject_Top_x                                             0xF17280
#define pinstRealEstateItems_x                                     0xFAA7D4

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE63D60
#define pinstCAchievementsWnd_x                                    0xE63DBC
#define pinstCTextOverlay_x                                        0xD21288
#define pinstCAudioTriggersWindow_x                                0xD21118
#define pinstCCharacterSelect_x                                    0xE63CD0
#define pinstCFacePick_x                                           0xE63C80
#define pinstCNoteWnd_x                                            0xE63C88
#define pinstCBookWnd_x                                            0xE63C90
#define pinstCPetInfoWnd_x                                         0xE63C94
#define pinstCTrainWnd_x                                           0xE63C98
#define pinstCSkillsWnd_x                                          0xE63C9C
#define pinstCSkillsSelectWnd_x                                    0xE63CA0
#define pinstCCombatSkillsSelectWnd_x                              0xE63CA4
#define pinstCFriendsWnd_x                                         0xE63CA8
#define pinstCAuraWnd_x                                            0xE63CAC
#define pinstCRespawnWnd_x                                         0xE63CB0
#define pinstCBandolierWnd_x                                       0xE63CB4
#define pinstCPotionBeltWnd_x                                      0xE63CB8
#define pinstCAAWnd_x                                              0xE63CBC
#define pinstCGroupSearchFiltersWnd_x                              0xE63CC0
#define pinstCLoadskinWnd_x                                        0xE63CC4
#define pinstCAlarmWnd_x                                           0xE63CC8
#define pinstCMusicPlayerWnd_x                                     0xE63CCC
#define pinstCMailWnd_x                                            0xE63CD4
#define pinstCMailCompositionWnd_x                                 0xE63CD8
#define pinstCMailAddressBookWnd_x                                 0xE63CDC
#define pinstCRaidWnd_x                                            0xE63CE4
#define pinstCRaidOptionsWnd_x                                     0xE63CE8
#define pinstCBreathWnd_x                                          0xE63CEC
#define pinstCMapViewWnd_x                                         0xE63CF0
#define pinstCMapToolbarWnd_x                                      0xE63CF4
#define pinstCEditLabelWnd_x                                       0xE63CF8
#define pinstCTargetWnd_x                                          0xE63CFC
#define pinstCColorPickerWnd_x                                     0xE63D00
#define pinstCPlayerWnd_x                                          0xE63D04
#define pinstCOptionsWnd_x                                         0xE63D08
#define pinstCBuffWindowNORMAL_x                                   0xE63D0C
#define pinstCBuffWindowSHORT_x                                    0xE63D10
#define pinstCharacterCreation_x                                   0xE63D14
#define pinstCCursorAttachment_x                                   0xE63D18
#define pinstCCastingWnd_x                                         0xE63D1C
#define pinstCCastSpellWnd_x                                       0xE63D20
#define pinstCSpellBookWnd_x                                       0xE63D24
#define pinstCInventoryWnd_x                                       0xE63D28
#define pinstCBankWnd_x                                            0xE63D30
#define pinstCQuantityWnd_x                                        0xE63D34
#define pinstCLootWnd_x                                            0xE63D38
#define pinstCActionsWnd_x                                         0xE63D3C
#define pinstCCombatAbilityWnd_x                                   0xE63D44
#define pinstCMerchantWnd_x                                        0xE63D48
#define pinstCTradeWnd_x                                           0xE63D50
#define pinstCSelectorWnd_x                                        0xE63D54
#define pinstCBazaarWnd_x                                          0xE63D58
#define pinstCBazaarSearchWnd_x                                    0xE63D5C
#define pinstCGiveWnd_x                                            0xE63D78
#define pinstCTrackingWnd_x                                        0xE63D80
#define pinstCInspectWnd_x                                         0xE63D84
#define pinstCSocialEditWnd_x                                      0xE63D88
#define pinstCFeedbackWnd_x                                        0xE63D8C
#define pinstCBugReportWnd_x                                       0xE63D90
#define pinstCVideoModesWnd_x                                      0xE63D94
#define pinstCTextEntryWnd_x                                       0xE63D9C
#define pinstCFileSelectionWnd_x                                   0xE63DA0
#define pinstCCompassWnd_x                                         0xE63DA4
#define pinstCPlayerNotesWnd_x                                     0xE63DA8
#define pinstCGemsGameWnd_x                                        0xE63DAC
#define pinstCTimeLeftWnd_x                                        0xE63DB0
#define pinstCPetitionQWnd_x                                       0xE63DCC
#define pinstCStoryWnd_x                                           0xE63DD0
#define pinstCJournalTextWnd_x                                     0xE63DD4
#define pinstCJournalCatWnd_x                                      0xE63DD8
#define pinstCBodyTintWnd_x                                        0xE63DDC
#define pinstCServerListWnd_x                                      0xE63DE0
#define pinstCAvaZoneWnd_x                                         0xE63DEC
#define pinstCBlockedBuffWnd_x                                     0xE63DF0
#define pinstCBlockedPetBuffWnd_x                                  0xE63DF4
#define pinstCInvSlotMgr_x                                         0xE63E3C
#define pinstCContainerMgr_x                                       0xE63E40
#define pinstCAdventureLeaderboardWnd_x                            0x10B6E78
#define pinstCAdventureRequestWnd_x                                0x10B6EF0
#define pinstCAltStorageWnd_x                                      0x10B71D0
#define pinstCAdventureStatsWnd_x                                  0x10B6F68
#define pinstCBarterMerchantWnd_x                                  0x10B7DB8
#define pinstCBarterSearchWnd_x                                    0x10B7E30
#define pinstCBarterWnd_x                                          0x10B7EA8
#define pinstCChatWindowManager_x                                  0x10B8538
#define pinstCDynamicZoneWnd_x                                     0x10B89E8
#define pinstCEQMainWnd_x                                          0x10B8B80
#define pinstCFellowshipWnd_x                                      0x10B897C
#define pinstCFindLocationWnd_x                                    0x10B8E50
#define pinstCGroupSearchWnd_x                                     0x10B9120
#define pinstCGroupWnd_x                                           0x10B9198
#define pinstCGuildBankWnd_x                                       0x10B9210
#define pinstCGuildMgmtWnd_x                                       0x10BB300
#define pinstCHotButtonWnd_x                                       0x10BB3FC
#define pinstCHotButtonWnd1_x                                      0x10BB3FC
#define pinstCHotButtonWnd2_x                                      0x10BB400
#define pinstCHotButtonWnd3_x                                      0x10BB404
#define pinstCHotButtonWnd4_x                                      0x10BB428
#define pinstCItemDisplayManager_x                                 0x10BB720
#define pinstCItemExpTransferWnd_x                                 0x10BB79C
#define pinstCLFGuildWnd_x                                         0x10BBA78
#define pinstCMIZoneSelectWnd_x                                    0x10BC060
#define pinstCConfirmationDialog_x                                 0x10BC768
#define pinstCPopupWndManager_x                                    0x10BC768
#define pinstCProgressionSelectionWnd_x                            0x10BC858
#define pinstCPvPStatsWnd_x                                        0x10BC948
#define pinstCLargeDialogWnd_x                                     0x10BD050
#define pinstCTaskWnd_x                                            0x10BE3D0
#define pinstCTaskSomething_x                                      0xD31EA0
#define pinstCTaskTemplateSelectWnd_x                              0x10BE358
#define pinstCTipWndOFDAY_x                                        0x10BE538
#define pinstCTipWndCONTEXT_x                                      0x10BE53C
#define pinstCTitleWnd_x                                           0x10BE5B8
#define pinstCContextMenuManager_x                                 0x1721FE4
#define pinstCVoiceMacroWnd_x                                      0xFAB000
#define pinstCHtmlWnd_x                                            0xFAB0F0
#define pinstIconCache_x                                           0x10B8B54
#define pinstCTradeskillWnd_x                                      0x10BE6B8
#define pinstCAdvancedLootWnd_x                                    0xE63E30
#define pinstRewardSelectionWnd_x                                  0x10BCE70
#define pinstEQSuiteTextureLoader_x                                0xD0F458

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x542F40
#define __CastRay2_x                                               0x542870
#define __HeadingDiff_x                                            0x92A350
#define __FixHeading_x                                             0x92A2E0
#define __get_bearing_x                                            0x532950
#define __ConvertItemTags_x                                        0x5305D0
#define __ExecuteCmd_x                                             0x51AF20
#define __EQGetTime_x                                              0x89B1B0
#define __get_melee_range_x                                        0x521B50
#define __GetGaugeValueFromEQ_x                                    0x7ABBF0
#define __GetLabelFromEQ_x                                         0x7ACFC0
#define __ToggleKeyRingItem_x                                      0x489000
#define __GetXTargetType_x                                         0x92BF50
#define __LoadFrontEnd_x                                           0x638D80
#define __NewUIINI_x                                               0x7AB5C0
#define __ProcessGameEvents_x                                      0x57CDA0
#define __ProcessMouseEvent_x                                      0x57C540
#define CrashDetected_x                                            0x63A740
#define wwsCrashReportCheckForUploader_x                           0x7F9800
#define __AppCrashWrapper_x                                        0xC5B704
#define __pCrashHandler_x                                          0x10CB568
#define __CrashHandler_x                                           0x7F9290
#define wwsCrashReportPlatformLaunchUploader_x                     0x7FBA40
#define DrawNetStatus_x                                            0x5B3610
#define Util__FastTime_x                                           0x89AE50
#define Expansion_HoT_x                                            0xF25A70
#define __HelpPath_x                                               0xFA9188
#define __STMLToText_x                                             0x8E1270

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423280
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DFA0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DD70

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D1340
#define AltAdvManager__IsAbilityReady_x                            0x4D13B0
#define AltAdvManager__GetAAById_x                                 0x4D18A0
#define AltAdvManager__CanTrainAbility_x                           0x4D24D0
#define AltAdvManager__CanSeeAbility_x                             0x4D2090

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46A7A0
#define CharacterZoneClient__HasSkill_x                            0x467650
#define CharacterZoneClient__MakeMeVisible_x                       0x46BD30
#define CharacterZoneClient__IsStackBlocked_x                      0x44BDA0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B260
#define CharacterZoneClient__GetItemCountWorn_x                    0x4655D0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4656B0
#define CharacterZoneClient__GetCursorItemCount_x                  0x465790
#define CharacterZoneClient__FindAffectSlot_x                      0x451310
#define CharacterZoneClient__BardCastBard_x                        0x44A9E0
#define CharacterZoneClient__GetMaxEffects_x                       0x449720
#define CharacterZoneClient__GetEffect_x                           0x44B490
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451170
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4498C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FCC0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6686E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x676BD0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x592620
#define CButtonWnd__CButtonWnd_x                                   0x8D5560

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691BB0
#define CChatManager__InitContextMenu_x                            0x692D00
#define CChatManager__FreeChatWindow_x                             0x691640
#define CChatManager__GetLockedActiveChatWindow_x                  0x69AD90
#define CChatManager__SetLockedActiveChatWindow_x                  0x691B80

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DF5C0
#define CContextMenu__dCContextMenu_x                              0x8DF7D0
#define CContextMenu__AddMenuItem_x                                0x8DFCF0
#define CContextMenu__RemoveMenuItem_x                             0x8DF950
#define CContextMenu__RemoveAllMenuItems_x                         0x8DF970
#define CContextMenu__CheckMenuItem_x                              0x8DF9F0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8CBB00
#define CContextMenuManager__RemoveMenu_x                          0x8CBE80
#define CContextMenuManager__PopupMenu_x                           0x8CC2D0
#define CContextMenuManager__Flush_x                               0x8CBB70
#define CContextMenuManager__GetMenu_x                             0x419670

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87F450
#define CChatService__GetFriendName_x                              0x87F460

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6988F0
#define CChatWindow__Clear_x                                       0x6981D0
#define CChatWindow__WndNotification_x                             0x6991F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CF920
#define CComboWnd__Draw_x                                          0x8CFB30
#define CComboWnd__GetCurChoice_x                                  0x8CF6D0
#define CComboWnd__GetListRect_x                                   0x8CFDD0
#define CComboWnd__GetTextRect_x                                   0x8CF990
#define CComboWnd__InsertChoice_x                                  0x8CFE40
#define CComboWnd__SetColors_x                                     0x8CF660
#define CComboWnd__SetChoice_x                                     0x8CF690
#define CComboWnd__GetItemCount_x                                  0x8CF6C0
#define CComboWnd__GetCurChoiceText_x                              0x8CF710

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A2AE0
#define CContainerWnd__vftable_x                                   0xAE1048

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BF0D0
#define CDisplay__GetClickedActor_x                                0x4B79D0
#define CDisplay__GetUserDefinedColor_x                            0x4B65B0
#define CDisplay__GetWorldFilePath_x                               0x4B5A00
#define CDisplay__is3dON_x                                         0x4B4E90
#define CDisplay__ReloadUI_x                                       0x4C9030
#define CDisplay__WriteTextHD2_x                                   0x4BB490
#define CDisplay__TrueDistance_x                                   0x4B8600

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F5D90

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E3B20
#define CEditWnd__GetCharIndexPt_x                                 0x8E4BC0
#define CEditWnd__GetDisplayString_x                               0x8E3CD0
#define CEditWnd__GetHorzOffset_x                                  0x8E4010
#define CEditWnd__GetLineForPrintableChar_x                        0x8E4680
#define CEditWnd__GetSelStartPt_x                                  0x8E4E80
#define CEditWnd__GetSTMLSafeText_x                                0x8E41B0
#define CEditWnd__PointFromPrintableChar_x                         0x8E4770
#define CEditWnd__SelectableCharFromPoint_x                        0x8E48F0
#define CEditWnd__SetEditable_x                                    0x8E4180

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x563380
#define CEverQuest__ClickedPlayer_x                                0x55CF50
#define CEverQuest__CreateTargetIndicator_x                        0x55DE50
#define CEverQuest__DeleteTargetIndicator_x                        0x55DED0
#define CEverQuest__DoTellWindow_x                                 0x476960
#define CEverQuest__OutputTextToLog_x                              0x4765C0
#define CEverQuest__DropHeldItemOnGround_x                         0x5738F0
#define CEverQuest__dsp_chat_x                                     0x476CA0
#define CEverQuest__trimName_x                                     0x559860
#define CEverQuest__Emote_x                                        0x571C00
#define CEverQuest__EnterZone_x                                    0x56CCE0
#define CEverQuest__GetBodyTypeDesc_x                              0x5572A0
#define CEverQuest__GetClassDesc_x                                 0x5607A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x560DA0
#define CEverQuest__GetDeityDesc_x                                 0x557B80
#define CEverQuest__GetLangDesc_x                                  0x557630
#define CEverQuest__GetRaceDesc_x                                  0x560F60
#define CEverQuest__InterpretCmd_x                                 0x564B00
#define CEverQuest__LeftClickedOnPlayer_x                          0x579450
#define CEverQuest__LMouseUp_x                                     0x57B560
#define CEverQuest__RightClickedOnPlayer_x                         0x579F60
#define CEverQuest__RMouseUp_x                                     0x57AFC0
#define CEverQuest__SetGameState_x                                 0x55D820
#define CEverQuest__UPCNotificationFlush_x                         0x555C30
#define CEverQuest__IssuePetCommand_x                              0x5654E0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B37A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B3800
#define CGaugeWnd__Draw_x                                          0x6B3C30

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B6C0
#define CGuild__GetGuildName_x                                     0x43BB90
#define CGuild__GetGuildIndex_x                                    0x43CDA0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CFD50

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DCFD0
#define CInvSlotMgr__MoveItem_x                                    0x6DDE80
#define CInvSlotMgr__SelectSlot_x                                  0x6DD080

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DC480
#define CInvSlot__SliderComplete_x                                 0x6D9C00
#define CInvSlot__GetItemBase_x                                    0x6D9080
#define CInvSlot__UpdateItem_x                                     0x6D9600

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DF2E0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E0400

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A7600
#define CItemDisplayWnd__UpdateStrings_x                           0x6E1510
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6EE000
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6EE530
#define CItemDisplayWnd__SetItem_x                                 0x6F3E80

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7DEA40

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6E7B40

// CLabel 
#define CLabel__Draw_x                                             0x6FAB80

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BB600
#define CListWnd__dCListWnd_x                                      0x8BC820
#define CListWnd__AddColumn_x                                      0x8BC7C0
#define CListWnd__AddColumn1_x                                     0x8BBE60
#define CListWnd__AddLine_x                                        0x8BB8C0
#define CListWnd__AddString_x                                      0x8BBAE0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B8890
#define CListWnd__CalculateVSBRange_x                              0x8BAAC0
#define CListWnd__ClearSel_x                                       0x8B7BA0
#define CListWnd__ClearAllSel_x                                    0x8B7B50
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BB490
#define CListWnd__Compare_x                                        0x8B9400
#define CListWnd__Draw_x                                           0x8BA6C0
#define CListWnd__DrawColumnSeparators_x                           0x8BA550
#define CListWnd__DrawHeader_x                                     0x8B7E60
#define CListWnd__DrawItem_x                                       0x8B9A80
#define CListWnd__DrawLine_x                                       0x8BA1F0
#define CListWnd__DrawSeparator_x                                  0x8BA5F0
#define CListWnd__EnableLine_x                                     0x8B7D80
#define CListWnd__EnsureVisible_x                                  0x8B89F0
#define CListWnd__ExtendSel_x                                      0x8B9990
#define CListWnd__GetColumnMinWidth_x                              0x8B7550
#define CListWnd__GetColumnWidth_x                                 0x8B7480
#define CListWnd__GetCurSel_x                                      0x8B6C50
#define CListWnd__GetItemAtPoint_x                                 0x8B8C90
#define CListWnd__GetItemAtPoint1_x                                0x8B8D00
#define CListWnd__GetItemData_x                                    0x8B6F90
#define CListWnd__GetItemHeight_x                                  0x8B84E0
#define CListWnd__GetItemIcon_x                                    0x8B7180
#define CListWnd__GetItemRect_x                                    0x8B8AD0
#define CListWnd__GetItemText_x                                    0x8B7030
#define CListWnd__GetSelList_x                                     0x8BBD50
#define CListWnd__GetSeparatorRect_x                               0x8B9320
#define CListWnd__InsertLine_x                                     0x8BBCC0
#define CListWnd__RemoveLine_x                                     0x8BBCD0
#define CListWnd__SetColors_x                                      0x8B6DA0
#define CListWnd__SetColumnJustification_x                         0x8B77E0
#define CListWnd__SetColumnWidth_x                                 0x8B7500
#define CListWnd__SetCurSel_x                                      0x8B6C90
#define CListWnd__SetItemColor_x                                   0x8BB180
#define CListWnd__SetItemData_x                                    0x8B7C00
#define CListWnd__SetItemText_x                                    0x8BAFC0
#define CListWnd__ShiftColumnSeparator_x                           0x8BAE50
#define CListWnd__Sort_x                                           0x8BC920
#define CListWnd__ToggleSel_x                                      0x8B7AD0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x713D90

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x735280
#define CMerchantWnd__RequestBuyItem_x                             0x73C370
#define CMerchantWnd__RequestSellItem_x                            0x73CE40
#define CMerchantWnd__SelectRecoverySlot_x                         0x735530
#define CMerchantWnd__SelectBuySellSlot_x                          0x734730
#define CMerchantWnd__ActualSelect_x                               0x739220

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84D750
#define CPacketScrambler__hton_x                                   0x84D760

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8DA500
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DA5E0
#define CSidlManager__CreateLabel_x                                0x79D7F0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8D8AB0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8DA8C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D19B0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D18B0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F5C70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D22C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D3480
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D3530
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D2A10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D1C70
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D13E0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D1E60
#define CSidlScreenWnd__Init1_x                                    0x8D3160
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D2370
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D15A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D2C50
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D1030
#define CSidlScreenWnd__StoreIniVis_x                              0x8D1390
#define CSidlScreenWnd__WndNotification_x                          0x8D2EE0
#define CSidlScreenWnd__GetChildItem_x                             0x8D14B0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C4D70
#define CSidlScreenWnd__m_layoutCopy_x                             0x1722048

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FE750
#define CSkillMgr__GetSkillCap_x                                   0x5FE930
#define CSkillMgr__GetNameToken_x                                  0x5FE300

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F4F20
#define CSliderWnd__SetValue_x                                     0x8F50F0
#define CSliderWnd__SetNumTicks_x                                  0x8F5870

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A3AB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EF3F0
#define CStmlWnd__CalculateHSBRange_x                              0x8E7930
#define CStmlWnd__CalculateVSBRange_x                              0x8E78A0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E7AB0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E82B0
#define CStmlWnd__ForceParseNow_x                                  0x8EFD70
#define CStmlWnd__GetNextTagPiece_x                                0x8E81B0
#define CStmlWnd__GetSTMLText_x                                    0x484610
#define CStmlWnd__GetVisibleText_x                                 0x8E8D00
#define CStmlWnd__InitializeWindowVariables_x                      0x8EB2D0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E6B80
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E6BE0
#define CStmlWnd__SetSTMLText_x                                    0x8ECB30
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EF090
#define CStmlWnd__UpdateHistoryString_x                            0x8E9C40

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F3280
#define CTabWnd__DrawCurrentPage_x                                 0x8F2B10
#define CTabWnd__DrawTab_x                                         0x8F28D0
#define CTabWnd__GetCurrentPage_x                                  0x8F2EC0
#define CTabWnd__GetPageInnerRect_x                                0x8F25C0
#define CTabWnd__GetTabInnerRect_x                                 0x8F27C0
#define CTabWnd__GetTabRect_x                                      0x8F2690
#define CTabWnd__InsertPage_x                                      0x8F3570
#define CTabWnd__SetPage_x                                         0x8F2EF0
#define CTabWnd__SetPageRect_x                                     0x8F31C0
#define CTabWnd__UpdatePage_x                                      0x8F3510
#define CTabWnd__GetPageFromTabIndex_x                             0x8F2820
#define CTabWnd__GetCurrentTabIndex_x                              0x8F2550

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E05B0
#define CPageWnd__SetTabText_x                                     0x8FEC70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437300

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CF2D0
#define CTextureFont__GetTextExtent_x                              0x8CF030

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x637020

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FB0B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B4F00

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59FE10
#define CXStr__CXStr1_x                                            0x444170
#define CXStr__CXStr3_x                                            0x8980A0
#define CXStr__dCXStr_x                                            0x47C8A0
#define CXStr__operator_equal_x                                    0x898210
#define CXStr__operator_equal1_x                                   0x898260
#define CXStr__operator_plus_equal1_x                              0x899360

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C3FD0
#define CXWnd__Center_x                                            0x8CA100
#define CXWnd__ClrFocus_x                                          0x8C3BA0
#define CXWnd__Destroy_x                                           0x8CABE0
#define CXWnd__DoAllDrawing_x                                      0x8C9D60
#define CXWnd__DrawChildren_x                                      0x8C9F00
#define CXWnd__DrawColoredRect_x                                   0x8C43A0
#define CXWnd__DrawTooltip_x                                       0x8C4650
#define CXWnd__DrawTooltipAtPoint_x                                0x8C8CE0
#define CXWnd__GetBorderFrame_x                                    0x8C4A70
#define CXWnd__GetChildWndAt_x                                     0x8CAAD0
#define CXWnd__GetClientClipRect_x                                 0x8C4870
#define CXWnd__GetScreenClipRect_x                                 0x8C93E0
#define CXWnd__GetScreenRect_x                                     0x8C4C20
#define CXWnd__GetTooltipRect_x                                    0x8C44E0
#define CXWnd__GetWindowTextA_x                                    0x427380
#define CXWnd__IsActive_x                                          0x8BF5F0
#define CXWnd__IsDescendantOf_x                                    0x8C49C0
#define CXWnd__IsReallyVisible_x                                   0x8C7D00
#define CXWnd__IsType_x                                            0x8CA170
#define CScreenPieceTemplate__IsType_x                             0x8F78D0
#define CXWnd__Move_x                                              0x8C7440
#define CXWnd__Move1_x                                             0x8C9A10
#define CXWnd__ProcessTransition_x                                 0x8C3F70
#define CXWnd__Refade_x                                            0x8C3D50
#define CXWnd__Resize_x                                            0x8C4CE0
#define CXWnd__Right_x                                             0x8C91E0
#define CXWnd__SetFocus_x                                          0x8C65A0
#define CXWnd__SetFont_x                                           0x8C3BF0
#define CXWnd__SetKeyTooltip_x                                     0x8C4F40
#define CXWnd__SetMouseOver_x                                      0x8C9700
#define CXWnd__StartFade_x                                         0x8C4020
#define CXWnd__GetChildItem_x                                      0x8C9650
#define CXWnd__SetParent_x                                         0x8CAA80

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C0E90
#define CXWndManager__DrawWindows_x                                0x8C0AE0
#define CXWndManager__GetKeyboardFlags_x                           0x8BF160
#define CXWndManager__HandleKeyboardMsg_x                          0x8BFA90
#define CXWndManager__RemoveWnd_x                                  0x8BF780

// CDBStr
#define CDBStr__GetString_x                                        0x4B36E0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452310
#define EQ_Character__Cur_HP_x                                     0x466C50
#define EQ_Character__Cur_Mana_x                                   0x45A9F0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B570
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4438E0
#define EQ_Character__GetFocusRangeModifier_x                      0x443940
#define EQ_Character__GetHPRegen_x                                 0x469E30
#define EQ_Character__GetEnduranceRegen_x                          0x466260
#define EQ_Character__GetManaRegen_x                               0x46A3D0
#define EQ_Character__Max_Endurance_x                              0x5C4F60
#define EQ_Character__Max_HP_x                                     0x45D570
#define EQ_Character__Max_Mana_x                                   0x5C4D90
#define EQ_Character__doCombatAbility_x                            0x5C2460
#define EQ_Character__UseSkill_x                                   0x470DC0
#define EQ_Character__GetConLevel_x                                0x5B7C20
#define EQ_Character__IsExpansionFlag_x                            0x4268C0
#define EQ_Character__TotalEffect_x                                0x44F640
#define EQ_Character__GetPCSpellAffect_x                           0x44B970
#define EQ_Character__SpellDuration_x                              0x449910
#define EQ_Character__FindItemByRecord_x                           0x4642C0
#define EQ_Character__GetAdjustedSkill_x                           0x467400
#define EQ_Character__GetBaseSkill_x                               0x45D450

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x86B670

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5CCF40

//PcClient
#define PcClient__PcClient_x                                       0x5B9A60

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446C10
#define CCharacterSelect__EnterWorld_x                             0x4463E0
#define CCharacterSelect__Quit_x                                   0x444FD0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x598080
#define EQ_Item__CreateItemTagString_x                             0x84C090
#define EQ_Item__IsStackable_x                                     0x841740
#define EQ_Item__GetImageNum_x                                     0x844200
#define EQ_Item__CreateItemClient_x                                0x598C80
#define EQ_Item__GetItemValue_x                                    0x84ADB0
#define EQ_Item__ValueSellMerchant_x                               0x84D3A0
#define EQ_Item__IsKeyRingItem_x                                   0x842230
#define EQ_Item__CanGoInBag_x                                      0x598210
#define EQ_Item__GetMaxItemCount_x                                 0x841630
#define EQ_Item__GetHeldItem_x                                     0x843020
#define EQ_Item__GetAugmentFitBySlot_x                             0x84D1C0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D3950
#define EQ_LoadingS__Array_x                                       0xBFDA78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C7480
#define EQ_PC__GetAlternateAbilityId_x                             0x8557F0
#define EQ_PC__GetCombatAbility_x                                  0x855880
#define EQ_PC__GetCombatAbilityTimer_x                             0x850400
#define EQ_PC__GetItemRecastTimer_x                                0x5C0C10
#define EQ_PC__HasLoreItem_x                                       0x5BB220
#define EQ_PC__AlertInventoryChanged_x                             0x5B7BF0
#define EQ_PC__GetPcZoneClient_x                                   0x5E1460
#define EQ_PC__RemoveMyAffect_x                                    0x5C00E0
#define EQ_PC__GetKeyRingItems_x                                   0x850820
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8634F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x857760

// EQItemList 
#define EQItemList__EQItemList_x                                   0x51FC10
#define EQItemList__add_object_x                                   0x54CAB0
#define EQItemList__add_item_x                                     0x51FB50
#define EQItemList__delete_item_x                                  0x520000
#define EQItemList__FreeItemList_x                                 0x51FF00

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B2990

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CCCE0
#define EQPlayer__dEQPlayer_x                                      0x5D5330
#define EQPlayer__DoAttack_x                                       0x5E6DF0
#define EQPlayer__EQPlayer_x                                       0x5D7A50
#define EQPlayer__SetNameSpriteState_x                             0x5D21F0
#define EQPlayer__SetNameSpriteTint_x                              0x5CE100
#define PlayerBase__HasProperty_j_x                                0x928760
#define EQPlayer__IsTargetable_x                                   0x928A00
#define EQPlayer__CanSee_x                                         0x928F60
#define PlayerZoneClient__ChangeHeight_x                           0x5E6CB0
#define EQPlayer__CanSee1_x                                        0x929050
#define PlayerBase__GetVisibilityLineSegment_x                     0x928CF0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E1610
#define PlayerZoneClient__IsValidTeleport_x                        0x54D350

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5DBAB0
#define EQPlayerManager__GetSpawnByName_x                          0x5DBF10
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5DBAE0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59E1A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59E1E0
#define KeypressHandler__ClearCommandStateArray_x                  0x59DD90
#define KeypressHandler__HandleKeyDown_x                           0x59C6F0
#define KeypressHandler__HandleKeyUp_x                             0x59CA10
#define KeypressHandler__SaveKeymapping_x                          0x59DE60

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70C720
#define MapViewMap__SaveEx_x                                       0x70FA50

#define PlayerPointManager__GetAltCurrency_x                       0x869700

// StringTable 
#define StringTable__getString_x                                   0x863820

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C49F0
#define PcZoneClient__RemovePetEffect_x                            0x5C10E0
#define PcZoneClient__HasAlternateAbility_x                        0x5C1A80
#define PcZoneClient__GetCurrentMod_x                              0x45CA20
#define PcZoneClient__GetModCap_x                                  0x45A150
#define PcZoneClient__CanEquipItem_x                               0x5C1FA0
#define PcZoneClient__GetItemByID_x                                0x5C67F0
#define PcZoneClient__GetItemByItemClass_x                         0x5C73A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x554470

//IconCache
#define IconCache__GetIcon_x                                       0x6A8FA0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69FE90
#define CContainerMgr__CloseContainer_x                            0x6A06B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76D5F0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x591060

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4EDB80
#define EQ_Spell__SpellAffects_x                                   0x4EB210
#define EQ_Spell__SpellAffectBase_x                           0x4EB280
#define CharacterZoneClient__CalcAffectChange_x                    0x44B800
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AA40
#define CLootWnd__LootAll_x                                        0x701F30
#define CLootWnd__RequestLootSlot_x                                0x702740
#define EQ_Spell__IsStackable_x                                    0x4494E0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449590
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F140
#define EQ_Spell__IsSPAStacking_x                                  0x4EADC0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4EA890
#define EQ_Spell__IsNoRemove_x                                     0x435320
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4EADE0

#define __IsResEffectSpell_x                                       0x449610

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8752F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B4600
#define CTargetWnd__WndNotification_x                              0x7B40F0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B47E0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B96F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E67B0
#define EqSoundManager__PlayScriptMp3_x                            0x4E8250

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A1A30

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E3150
#define CSidlManager__FindAnimation1_x                             0x8D84E0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4DB210
#define CAltAbilityData__GetMercMaxRank_x                          0x4DB1C0
#define CAltAbilityData__GetMaxRank_x                              0x4CF9F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x58E910

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4590E0
#define CharacterBase__CreateItemGlobalIndex_x                     0x475B40
#define CharacterBase__CreateItemIndex_x                           0x519150
#define CharacterBase__GetItemPossession_x                         0x4444A0
#define CharacterBase__GetItemByGlobalIndex_x                      0x879140
#define CharacterBase__GetEffectId_x                               0x4590A0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x688CD0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x688430

//messages
#define msg_spell_worn_off_x                                       0x4F56D0
#define msg_new_text_x                                             0x4FED20
#define msgTokenTextParam_x                                        0x4FB560

//SpellManager
#define SpellManager__vftable_x                                    0xABD178
#define SpellManager__SpellManager_x                               0x47E740
#define Spellmanager__LoadTextSpells_x          0x605650

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x92CA70

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F1CC0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43F060
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449280
#define ItemGlobalIndex__IsValidIndex_x                            0x458980

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x876FB0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x875EF0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6FADD0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6A4BB0
#define CCursorAttachment__Deactivate_x                            0x6A4100

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8F4420
