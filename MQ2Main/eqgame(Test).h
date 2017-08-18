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
#define __ExpectedVersionDate                                     "Aug  7 2017"
#define __ExpectedVersionTime                                     "16:00:14"
#define __ActualVersionDate_x                                      0xAD7450
#define __ActualVersionTime_x                                      0xAD745C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5A30A0
#define __MemChecker1_x                                            0x89A7E0
#define __MemChecker2_x                                            0x639150
#define __MemChecker3_x                                            0x6390A0
#define __MemChecker4_x                                            0x7ECC50
#define __EncryptPad0_x                                            0xC32328
#define __EncryptPad1_x                                            0xD0D6E0
#define __EncryptPad2_x                                            0xC5BB10
#define __EncryptPad3_x                                            0xC5B710
#define __EncryptPad4_x                                            0xCFBCE0
#define __EncryptPad5_x                                            0x10B6370
#define __AC1_x                                                    0x7AC6D5
#define __AC2_x                                                    0x55BF17
#define __AC3_x                                                    0x55A090
#define __AC4_x                                                    0x56C261
#define __AC5_x                                                    0x58010B
#define __AC6_x                                                    0x583CCE
#define __AC7_x                                                    0x57A70C
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
#define __do_loot_x                                                0x52B0A0
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
#define __CastRay_x                                                0x542630
#define __CastRay2_x                                               0x541F60
#define __HeadingDiff_x                                            0x929310
#define __FixHeading_x                                             0x9292A0
#define __get_bearing_x                                            0x532040
#define __ConvertItemTags_x                                        0x52FCC0
#define __ExecuteCmd_x                                             0x51A600
#define __EQGetTime_x                                              0x89A180
#define __get_melee_range_x                                        0x521240
#define __GetGaugeValueFromEQ_x                                    0x7AB290
#define __GetLabelFromEQ_x                                         0x7AC660
#define __ToggleKeyRingItem_x                                      0x488C30
#define __GetXTargetType_x                                         0x92AF10
#define __LoadFrontEnd_x                                           0x638820
#define __NewUIINI_x                                               0x7AAC60
#define __ProcessGameEvents_x                                      0x57C4A0
#define __ProcessMouseEvent_x                                      0x57BC40
#define CrashDetected_x                                            0x63A1E0
#define wwsCrashReportCheckForUploader_x                           0x7F8C90
#define __AppCrashWrapper_x                                        0xC5B704
#define __pCrashHandler_x                                          0x10CB568
#define __CrashHandler_x                                           0x7F8720
#define wwsCrashReportPlatformLaunchUploader_x                     0x7FAEC0
#define DrawNetStatus_x                                            0x5B2C70
#define Util__FastTime_x                                           0x899E20
#define Expansion_HoT_x                                            0xF25A70
#define __HelpPath_x                                               0xFA9188
#define __STMLToText_x                                             0x8E0370

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x422FC0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DCE0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DAB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D1380
#define AltAdvManager__IsAbilityReady_x                            0x4D13F0
#define AltAdvManager__GetAAById_x                                 0x4D18E0
#define AltAdvManager__CanTrainAbility_x                           0x4D2510
#define AltAdvManager__CanSeeAbility_x                             0x4D20D0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46A320
#define CharacterZoneClient__HasSkill_x                            0x4671D0
#define CharacterZoneClient__MakeMeVisible_x                       0x46B8B0
#define CharacterZoneClient__IsStackBlocked_x                      0x44B990
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44AE50
#define CharacterZoneClient__GetItemCountWorn_x                    0x465150
#define CharacterZoneClient__GetItemCountInInventory_x             0x465230
#define CharacterZoneClient__GetCursorItemCount_x                  0x465310
#define CharacterZoneClient__FindAffectSlot_x                      0x450EE0
#define CharacterZoneClient__BardCastBard_x                        0x44A5D0
#define CharacterZoneClient__GetMaxEffects_x                       0x449310
#define CharacterZoneClient__GetEffect_x                           0x44B080
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x450D40
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4494B0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44F890

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6681B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x676640

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x591E00
#define CButtonWnd__CButtonWnd_x                                   0x8D4620

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691710
#define CChatManager__InitContextMenu_x                            0x692860
#define CChatManager__FreeChatWindow_x                             0x6911A0
#define CChatManager__GetLockedActiveChatWindow_x                  0x69A940
#define CChatManager__SetLockedActiveChatWindow_x                  0x6916E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DE6C0
#define CContextMenu__dCContextMenu_x                              0x8DE8D0
#define CContextMenu__AddMenuItem_x                                0x8DEDF0
#define CContextMenu__RemoveMenuItem_x                             0x8DEA50
#define CContextMenu__RemoveAllMenuItems_x                         0x8DEA70
#define CContextMenu__CheckMenuItem_x                              0x8DEAF0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8CABB0
#define CContextMenuManager__RemoveMenu_x                          0x8CAF40
#define CContextMenuManager__PopupMenu_x                           0x8CB390
#define CContextMenuManager__Flush_x                               0x8CAC20
#define CContextMenuManager__GetMenu_x                             0x4193B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87E380
#define CChatService__GetFriendName_x                              0x87E390

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x698480
#define CChatWindow__Clear_x                                       0x697D60
#define CChatWindow__WndNotification_x                             0x698D90

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CEA00
#define CComboWnd__Draw_x                                          0x8CEC10
#define CComboWnd__GetCurChoice_x                                  0x8CE7B0
#define CComboWnd__GetListRect_x                                   0x8CEEB0
#define CComboWnd__GetTextRect_x                                   0x8CEA70
#define CComboWnd__InsertChoice_x                                  0x8CEF20
#define CComboWnd__SetColors_x                                     0x8CE740
#define CComboWnd__SetChoice_x                                     0x8CE770
#define CComboWnd__GetItemCount_x                                  0x8CE7A0
#define CComboWnd__GetCurChoiceText_x                              0x8CE7F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A2630
#define CContainerWnd__vftable_x                                   0xAE1058

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BF060
#define CDisplay__GetClickedActor_x                                0x4B7950
#define CDisplay__GetUserDefinedColor_x                            0x4B6530
#define CDisplay__GetWorldFilePath_x                               0x4B5980
#define CDisplay__is3dON_x                                         0x4B4E10
#define CDisplay__ReloadUI_x                                       0x4C8FC0
#define CDisplay__WriteTextHD2_x                                   0x4BB420
#define CDisplay__TrueDistance_x                                   0x4B8580

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F4E00

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E2C20
#define CEditWnd__GetCharIndexPt_x                                 0x8E3CC0
#define CEditWnd__GetDisplayString_x                               0x8E2DD0
#define CEditWnd__GetHorzOffset_x                                  0x8E3110
#define CEditWnd__GetLineForPrintableChar_x                        0x8E3780
#define CEditWnd__GetSelStartPt_x                                  0x8E3F80
#define CEditWnd__GetSTMLSafeText_x                                0x8E32B0
#define CEditWnd__PointFromPrintableChar_x                         0x8E3870
#define CEditWnd__SelectableCharFromPoint_x                        0x8E39F0
#define CEditWnd__SetEditable_x                                    0x8E3280

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x562A90
#define CEverQuest__ClickedPlayer_x                                0x55C660
#define CEverQuest__CreateTargetIndicator_x                        0x55D560
#define CEverQuest__DeleteTargetIndicator_x                        0x55D5E0
#define CEverQuest__DoTellWindow_x                                 0x4764F0
#define CEverQuest__OutputTextToLog_x                              0x476150
#define CEverQuest__DropHeldItemOnGround_x                         0x573000
#define CEverQuest__dsp_chat_x                                     0x476830
#define CEverQuest__trimName_x                                     0x558F70
#define CEverQuest__Emote_x                                        0x571310
#define CEverQuest__EnterZone_x                                    0x56C3F0
#define CEverQuest__GetBodyTypeDesc_x                              0x5569B0
#define CEverQuest__GetClassDesc_x                                 0x55FEB0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5604B0
#define CEverQuest__GetDeityDesc_x                                 0x557290
#define CEverQuest__GetLangDesc_x                                  0x556D40
#define CEverQuest__GetRaceDesc_x                                  0x560670
#define CEverQuest__InterpretCmd_x                                 0x564210
#define CEverQuest__LeftClickedOnPlayer_x                          0x578B50
#define CEverQuest__LMouseUp_x                                     0x57AC60
#define CEverQuest__RightClickedOnPlayer_x                         0x579660
#define CEverQuest__RMouseUp_x                                     0x57A6C0
#define CEverQuest__SetGameState_x                                 0x55CF30
#define CEverQuest__UPCNotificationFlush_x                         0x555340
#define CEverQuest__IssuePetCommand_x                              0x564BF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B3380
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B33E0
#define CGaugeWnd__Draw_x                                          0x6B3810

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B250
#define CGuild__GetGuildName_x                                     0x43B720
#define CGuild__GetGuildIndex_x                                    0x43C930

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CF870

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DCAE0
#define CInvSlotMgr__MoveItem_x                                    0x6DD990
#define CInvSlotMgr__SelectSlot_x                                  0x6DCB90

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DBF90
#define CInvSlot__SliderComplete_x                                 0x6D9720
#define CInvSlot__GetItemBase_x                                    0x6D8BA0
#define CInvSlot__UpdateItem_x                                     0x6D9120

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DEDE0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6DFF00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A6C80
#define CItemDisplayWnd__UpdateStrings_x                           0x6E1010
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6EDA90
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6EDFA0
#define CItemDisplayWnd__SetItem_x                                 0x6F3880

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7DE070

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6E75D0

// CLabel 
#define CLabel__Draw_x                                             0x6FA560

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BA620
#define CListWnd__dCListWnd_x                                      0x8BB830
#define CListWnd__AddColumn_x                                      0x8BB7D0
#define CListWnd__AddColumn1_x                                     0x8BAE70
#define CListWnd__AddLine_x                                        0x8BA8D0
#define CListWnd__AddString_x                                      0x8BAAF0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B78B0
#define CListWnd__CalculateVSBRange_x                              0x8B9AE0
#define CListWnd__ClearSel_x                                       0x8B6BD0
#define CListWnd__ClearAllSel_x                                    0x8B6B80
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BA4B0
#define CListWnd__Compare_x                                        0x8B8410
#define CListWnd__Draw_x                                           0x8B96E0
#define CListWnd__DrawColumnSeparators_x                           0x8B9570
#define CListWnd__DrawHeader_x                                     0x8B6E90
#define CListWnd__DrawItem_x                                       0x8B8AA0
#define CListWnd__DrawLine_x                                       0x8B9210
#define CListWnd__DrawSeparator_x                                  0x8B9610
#define CListWnd__EnableLine_x                                     0x8B6DB0
#define CListWnd__EnsureVisible_x                                  0x8B7A10
#define CListWnd__ExtendSel_x                                      0x8B89B0
#define CListWnd__GetColumnMinWidth_x                              0x8B6580
#define CListWnd__GetColumnWidth_x                                 0x8B64B0
#define CListWnd__GetCurSel_x                                      0x8B5C80
#define CListWnd__GetItemAtPoint_x                                 0x8B7CB0
#define CListWnd__GetItemAtPoint1_x                                0x8B7D20
#define CListWnd__GetItemData_x                                    0x8B5FC0
#define CListWnd__GetItemHeight_x                                  0x8B7510
#define CListWnd__GetItemIcon_x                                    0x8B61B0
#define CListWnd__GetItemRect_x                                    0x8B7AF0
#define CListWnd__GetItemText_x                                    0x8B6060
#define CListWnd__GetSelList_x                                     0x8BAD60
#define CListWnd__GetSeparatorRect_x                               0x8B8340
#define CListWnd__InsertLine_x                                     0x8BACD0
#define CListWnd__RemoveLine_x                                     0x8BACE0
#define CListWnd__SetColors_x                                      0x8B5DD0
#define CListWnd__SetColumnJustification_x                         0x8B6810
#define CListWnd__SetColumnWidth_x                                 0x8B6530
#define CListWnd__SetCurSel_x                                      0x8B5CC0
#define CListWnd__SetItemColor_x                                   0x8BA1A0
#define CListWnd__SetItemData_x                                    0x8B6C30
#define CListWnd__SetItemText_x                                    0x8B9FE0
#define CListWnd__ShiftColumnSeparator_x                           0x8B9E70
#define CListWnd__Sort_x                                           0x8BB930
#define CListWnd__ToggleSel_x                                      0x8B6B00

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x713570

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x734AE0
#define CMerchantWnd__RequestBuyItem_x                             0x73BBB0
#define CMerchantWnd__RequestSellItem_x                            0x73C680
#define CMerchantWnd__SelectRecoverySlot_x                         0x734D90
#define CMerchantWnd__SelectBuySellSlot_x                          0x733F90
#define CMerchantWnd__ActualSelect_x                               0x738A60

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84C640
#define CPacketScrambler__hton_x                                   0x84C650

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D95B0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D9690
#define CSidlManager__CreateLabel_x                                0x79CEC0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8D7B40
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D9970

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D0AA0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D0990
#define CSidlScreenWnd__ConvertToRes_x                             0x8F4CE0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D13B0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D2580
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D2630
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D1B10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D0D60
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D04C0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D0F50
#define CSidlScreenWnd__Init1_x                                    0x8D2270
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D1460
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D0680
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D1D50
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D0110
#define CSidlScreenWnd__StoreIniVis_x                              0x8D0470
#define CSidlScreenWnd__WndNotification_x                          0x8D1FF0
#define CSidlScreenWnd__GetChildItem_x                             0x8D0590
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C3DB0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1722048

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FDFE0
#define CSkillMgr__GetSkillCap_x                                   0x5FE1C0
#define CSkillMgr__GetNameToken_x                                  0x5FDB90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F3FB0
#define CSliderWnd__SetValue_x                                     0x8F4180
#define CSliderWnd__SetNumTicks_x                                  0x8F4900

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A3190

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EE4A0
#define CStmlWnd__CalculateHSBRange_x                              0x8E6A20
#define CStmlWnd__CalculateVSBRange_x                              0x8E6990
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E6BA0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E73A0
#define CStmlWnd__ForceParseNow_x                                  0x8EEE20
#define CStmlWnd__GetNextTagPiece_x                                0x8E72A0
#define CStmlWnd__GetSTMLText_x                                    0x484220
#define CStmlWnd__GetVisibleText_x                                 0x8E7DF0
#define CStmlWnd__InitializeWindowVariables_x                      0x8EA3A0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E5C70
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E5CD0
#define CStmlWnd__SetSTMLText_x                                    0x8EBBF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EE140
#define CStmlWnd__UpdateHistoryString_x                            0x8E8D20

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F2340
#define CTabWnd__DrawCurrentPage_x                                 0x8F1BD0
#define CTabWnd__DrawTab_x                                         0x8F1990
#define CTabWnd__GetCurrentPage_x                                  0x8F1F80
#define CTabWnd__GetPageInnerRect_x                                0x8F1680
#define CTabWnd__GetTabInnerRect_x                                 0x8F1880
#define CTabWnd__GetTabRect_x                                      0x8F1750
#define CTabWnd__InsertPage_x                                      0x8F2630
#define CTabWnd__SetPage_x                                         0x8F1FB0
#define CTabWnd__SetPageRect_x                                     0x8F2280
#define CTabWnd__UpdatePage_x                                      0x8F25D0
#define CTabWnd__GetPageFromTabIndex_x                             0x8F18E0
#define CTabWnd__GetCurrentTabIndex_x                              0x8F1610

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E00B0
#define CPageWnd__SetTabText_x                                     0x8FDCD0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436E80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CE3B0
#define CTextureFont__GetTextExtent_x                              0x8CE110

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x636AC0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FA110

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B3DE0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x4F1C20
#define CXStr__CXStr3_x                                            0x897070
#define CXStr__dCXStr_x                                            0x59F910
#define CXStr__operator_equal_x                                    0x8971E0
#define CXStr__operator_equal1_x                                   0x897230
#define CXStr__operator_plus_equal1_x                              0x898330

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C2F70
#define CXWnd__Center_x                                            0x8C91C0
#define CXWnd__ClrFocus_x                                          0x8C2B60
#define CXWnd__Destroy_x                                           0x8C9CA0
#define CXWnd__DoAllDrawing_x                                      0x8C8DF0
#define CXWnd__DrawChildren_x                                      0x8C8FA0
#define CXWnd__DrawColoredRect_x                                   0x8C3360
#define CXWnd__DrawTooltip_x                                       0x8C3600
#define CXWnd__DrawTooltipAtPoint_x                                0x8C7D90
#define CXWnd__GetBorderFrame_x                                    0x8C3A70
#define CXWnd__GetChildWndAt_x                                     0x8C9B80
#define CXWnd__GetClientClipRect_x                                 0x8C3820
#define CXWnd__GetScreenClipRect_x                                 0x8C8490
#define CXWnd__GetScreenRect_x                                     0x8C3C40
#define CXWnd__GetTooltipRect_x                                    0x8C3490
#define CXWnd__GetWindowTextA_x                                    0x4270F0
#define CXWnd__IsActive_x                                          0x8BE650
#define CXWnd__IsDescendantOf_x                                    0x8C39B0
#define CXWnd__IsReallyVisible_x                                   0x8C6DC0
#define CXWnd__IsType_x                                            0x8C9230
#define CScreenPieceTemplate__IsType_x                             0x8F6930
#define CXWnd__Move_x                                              0x8C64A0
#define CXWnd__Move1_x                                             0x8C8AA0
#define CXWnd__ProcessTransition_x                                 0x8C2F20
#define CXWnd__Refade_x                                            0x8C2D00
#define CXWnd__Resize_x                                            0x8C3D10
#define CXWnd__Right_x                                             0x8C8290
#define CXWnd__SetFocus_x                                          0x8C55E0
#define CXWnd__SetFont_x                                           0x8C2BB0
#define CXWnd__SetKeyTooltip_x                                     0x8C3F80
#define CXWnd__SetMouseOver_x                                      0x8C87A0
#define CXWnd__StartFade_x                                         0x8C2FC0
#define CXWnd__GetChildItem_x                                      0x8C86F0
#define CXWnd__SetParent_x                                         0x8C9B30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BFEE0
#define CXWndManager__DrawWindows_x                                0x8BFB20
#define CXWndManager__GetKeyboardFlags_x                           0x8BE180
#define CXWndManager__HandleKeyboardMsg_x                          0x8BEAF0
#define CXWndManager__RemoveWnd_x                                  0x8BE7E0

// CDBStr
#define CDBStr__GetString_x                                        0x4B3630

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x451EE0
#define EQ_Character__Cur_HP_x                                     0x4667D0
#define EQ_Character__Cur_Mana_x                                   0x45A570
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B160
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4434B0
#define EQ_Character__GetFocusRangeModifier_x                      0x443510
#define EQ_Character__GetHPRegen_x                                 0x4699B0
#define EQ_Character__GetEnduranceRegen_x                          0x465DE0
#define EQ_Character__GetManaRegen_x                               0x469F50
#define EQ_Character__Max_Endurance_x                              0x5C4810
#define EQ_Character__Max_HP_x                                     0x45D0F0
#define EQ_Character__Max_Mana_x                                   0x5C4640
#define EQ_Character__doCombatAbility_x                            0x5C1D10
#define EQ_Character__UseSkill_x                                   0x470940
#define EQ_Character__GetConLevel_x                                0x5B72F0
#define EQ_Character__IsExpansionFlag_x                            0x426640
#define EQ_Character__TotalEffect_x                                0x44F210
#define EQ_Character__GetPCSpellAffect_x                           0x44B560
#define EQ_Character__SpellDuration_x                              0x449500
#define EQ_Character__FindItemByRecord_x                           0x463E40
#define EQ_Character__GetAdjustedSkill_x                           0x466F80
#define EQ_Character__GetBaseSkill_x                               0x45CFD0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x86A5A0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5CC7B0

//PcClient
#define PcClient__PcClient_x                                       0x5B9140

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446810
#define CCharacterSelect__EnterWorld_x                             0x445FE0
#define CCharacterSelect__Quit_x                                   0x444BC0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x597800
#define EQ_Item__CreateItemTagString_x                             0x84AFC0
#define EQ_Item__IsStackable_x                                     0x840A00
#define EQ_Item__GetImageNum_x                                     0x843440
#define EQ_Item__CreateItemClient_x                                0x598400
#define EQ_Item__GetItemValue_x                                    0x849D20
#define EQ_Item__ValueSellMerchant_x                               0x84C2A0
#define EQ_Item__IsKeyRingItem_x                                   0x841460
#define EQ_Item__CanGoInBag_x                                      0x597990
#define EQ_Item__GetMaxItemCount_x                                 0x8408F0
#define EQ_Item__GetHeldItem_x                                     0x842240
#define EQ_Item__GetAugmentFitBySlot_x                             0x84C0C0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D39B0
#define EQ_LoadingS__Array_x                                       0xBFDA78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C6D30
#define EQ_PC__GetAlternateAbilityId_x                             0x854740
#define EQ_PC__GetCombatAbility_x                                  0x8547D0
#define EQ_PC__GetCombatAbilityTimer_x                             0x84F2F0
#define EQ_PC__GetItemRecastTimer_x                                0x5C04D0
#define EQ_PC__HasLoreItem_x                                       0x5BA900
#define EQ_PC__AlertInventoryChanged_x                             0x5B72C0
#define EQ_PC__GetPcZoneClient_x                                   0x5E0E10
#define EQ_PC__RemoveMyAffect_x                                    0x5BF9A0
#define EQ_PC__GetKeyRingItems_x                                   0x84F710
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x862440
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x856690

// EQItemList 
#define EQItemList__EQItemList_x                                   0x51F2F0
#define EQItemList__add_object_x                                   0x54C2A0
#define EQItemList__add_item_x                                     0x51F230
#define EQItemList__delete_item_x                                  0x51F6E0
#define EQItemList__FreeItemList_x                                 0x51F5E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B28A0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CC550
#define EQPlayer__dEQPlayer_x                                      0x5D4BA0
#define EQPlayer__DoAttack_x                                       0x5E6780
#define EQPlayer__EQPlayer_x                                       0x5D72C0
#define EQPlayer__SetNameSpriteState_x                             0x5D1A60
#define EQPlayer__SetNameSpriteTint_x                              0x5CD970
#define PlayerBase__HasProperty_j_x                                0x927720
#define EQPlayer__IsTargetable_x                                   0x9279C0
#define EQPlayer__CanSee_x                                         0x927F20
#define PlayerZoneClient__ChangeHeight_x                           0x5E6640
#define EQPlayer__CanSee1_x                                        0x928010
#define PlayerBase__GetVisibilityLineSegment_x                     0x927CB0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E0FC0
#define PlayerZoneClient__IsValidTeleport_x                        0x54CB60

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5DB460
#define EQPlayerManager__GetSpawnByName_x                          0x5DB8C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5DB490

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59D8E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59D920
#define KeypressHandler__ClearCommandStateArray_x                  0x59D4D0
#define KeypressHandler__HandleKeyDown_x                           0x59BE30
#define KeypressHandler__HandleKeyUp_x                             0x59C150
#define KeypressHandler__SaveKeymapping_x                          0x59D5A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70BF00
#define MapViewMap__SaveEx_x                                       0x70F230

#define PlayerPointManager__GetAltCurrency_x                       0x868650

// StringTable 
#define StringTable__getString_x                                   0x862770

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C42A0
#define PcZoneClient__RemovePetEffect_x                            0x5C09A0
#define PcZoneClient__HasAlternateAbility_x                        0x5C1340
#define PcZoneClient__GetCurrentMod_x                              0x45C5A0
#define PcZoneClient__GetModCap_x                                  0x459CD0
#define PcZoneClient__CanEquipItem_x                               0x5C1860
#define PcZoneClient__GetItemByID_x                                0x5C60A0
#define PcZoneClient__GetItemByItemClass_x                         0x5C6C50

//Doors
#define EQSwitch__UseSwitch_x                                      0x553BB0

//IconCache
#define IconCache__GetIcon_x                                       0x6A8AC0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69F9C0
#define CContainerMgr__CloseContainer_x                            0x6A01E0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76CF30

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x590820

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4EDAE0
#define EQ_Spell__SpellAffects_x                                   0x4EB170
#define EQ_Spell__SpellAffectBase_x                           0x4EB1E0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B3F0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A630
#define CLootWnd__LootAll_x                                        0x7017E0
#define CLootWnd__RequestLootSlot_x                                0x701FF0
#define EQ_Spell__IsStackable_x                                    0x4490D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449180
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43ED10
#define EQ_Spell__IsSPAStacking_x                                  0x4EAD20
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4EA7F0
#define EQ_Spell__IsNoRemove_x                                     0x434EB0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4EAD40

#define __IsResEffectSpell_x                                       0x449200

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x874220

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B3CA0
#define CTargetWnd__WndNotification_x                              0x7B3790
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B3E80

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B8DA0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E67C0
#define EqSoundManager__PlayScriptMp3_x                            0x4E8260

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A1860

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E2250
#define CSidlManager__FindAnimation1_x                             0x8D7570

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4DB260
#define CAltAbilityData__GetMercMaxRank_x                          0x4DB210
#define CAltAbilityData__GetMaxRank_x                              0x4CFA00

//CTargetRing
#define CTargetRing__Cast_x                                        0x58E0E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x458CB0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4756B0
#define CharacterBase__CreateItemIndex_x                           0x518830
#define CharacterBase__GetItemPossession_x                         0x444060
#define CharacterBase__GetItemByGlobalIndex_x                      0x878070
#define CharacterBase__GetEffectId_x                               0x458C70

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x688760
#define CCastSpellWnd__IsBardSongPlaying_x                         0x687EC0

//messages
#define msg_spell_worn_off_x                                       0x4F5640
#define msg_new_text_x                                             0x4FECA0
#define msgTokenTextParam_x                                        0x4FB4E0

//SpellManager
#define SpellManager__vftable_x                                    0xABD178
#define SpellManager__SpellManager_x                               0x47E300
#define Spellmanager__LoadTextSpells_x          0x604F30

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x92BA30

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F1C00
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EC30
#define ItemGlobalIndex__IsEquippedLocation_x                      0x448E80
#define ItemGlobalIndex__IsValidIndex_x                            0x458550

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x875EE0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x874E20

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6FA7B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6A46F0
#define CCursorAttachment__Deactivate_x                            0x6A3C30

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8F34B0
