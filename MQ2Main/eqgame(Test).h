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
#define __ExpectedVersionDate                                     "Jun 20 2017"
#define __ExpectedVersionTime                                     "10:10:50"
#define __ActualVersionDate_x                                      0xAD5428
#define __ActualVersionTime_x                                      0xAD5434

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5A39E0
#define __MemChecker1_x                                            0x899750
#define __MemChecker2_x                                            0x639670
#define __MemChecker3_x                                            0x6395C0
#define __MemChecker4_x                                            0x7EBD10
#define __EncryptPad0_x                                            0xC2F328
#define __EncryptPad1_x                                            0xD0A6E0
#define __EncryptPad2_x                                            0xC58B10
#define __EncryptPad3_x                                            0xC58710
#define __EncryptPad4_x                                            0xCF8CE0
#define __EncryptPad5_x                                            0x10B3370
#define __AC1_x                                                    0x7AB265
#define __AC2_x                                                    0x55C8A7
#define __AC3_x                                                    0x55AA20
#define __AC4_x                                                    0x56CB31
#define __AC5_x                                                    0x5809CB
#define __AC6_x                                                    0x58457E
#define __AC7_x                                                    0x57AFCC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FE4DFC

// Direct Input
#define DI8__Main_x                                                0x10B3348
#define DI8__Keyboard_x                                            0x10B334C
#define DI8__Mouse_x                                               0x10B3350
#define DI8__Mouse_Copy_x                                          0xF2170C
#define DI8__Mouse_Check_x                                         0xFAB034
#define __AutoSkillArray_x                                         0xF22620
#define __Attack_x                                                 0xFA5C17
#define __Autofire_x                                               0xFA5C18
#define __BindList_x                                               0xC0A050
#define g_eqCommandStates_x                                        0xF10730
#define __Clicks_x                                                 0xF217C8
#define __CommandList_x                                            0xC0C6C8
#define __CurrentMapLabel_x                                        0x10B8DD0
#define __CurrentSocial_x                                          0xBDB424
#define __DoAbilityList_x                                          0xF57ECC
#define __do_loot_x                                                0x52BB40
#define __DrawHandler_x                                            0x171FC84
#define __GroupCount_x                                             0xF11D62

#define __Guilds_x                                                 0xF17978
#define __gWorld_x                                                 0xF1421C
#define __HotkeyPage_x                                             0xF9E8CC
#define __HWnd_x                                                   0xFAB150
#define __InChatMode_x                                             0xF216F4
#define __LastTell_x                                               0xF235C8
#define __LMouseHeldTime_x                                         0xF21834
#define __Mouse_x                                                  0x10B3354
#define __MouseLook_x                                              0xF2178E
#define __MouseEventTime_x                                         0xFA641C
#define __gpbCommandEvent_x                                        0xF142E4
#define __NetStatusToggle_x                                        0xF21791
#define __PCNames_x                                                0xF22BDC
#define __RangeAttackReady_x                                       0xF22904
#define __RMouseHeldTime_x                                         0xF21830
#define __RunWalkState_x                                           0xF216F8
#define __ScreenMode_x                                             0xE60418
#define __ScreenX_x                                                0xF216AC
#define __ScreenY_x                                                0xF216A8
#define __ScreenXMax_x                                             0xF216B0
#define __ScreenYMax_x                                             0xF216B4
#define __ServerHost_x                                             0xF11CAC
#define __ServerName_x                                             0xF57E8C
#define __ShiftKeyDown_x                                           0xF21D88
#define __ShowNames_x                                              0xF22AC4
#define __Socials_x                                                0xF57F8C
#define __SubscriptionType_x                                       0x10E6D94
#define __TargetAggroHolder_x                                      0x10BAFA4
#define __ZoneType_x                                               0xF21B8C
#define __GroupAggro_x                                             0x10BAFE4
#define __LoginName_x                                              0xFA9C2C
#define __Inviter_x                                                0xFA5B94
#define __AttackOnAssist_x                                         0xF22A80
#define __UseTellWindows_x                                         0xF22D74

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF14308
#define instEQZoneInfo_x                                           0xF21984
#define instKeypressHandler_x                                      0xFA6400
#define pinstActiveBanker_x                                        0xF142C0
#define pinstActiveCorpse_x                                        0xF142C4
#define pinstActiveGMaster_x                                       0xF142C8
#define pinstActiveMerchant_x                                      0xF142BC
#define pinstAggroInfo_x                                           0xD1DD88
#define pinstAltAdvManager_x                                       0xE614F8
#define pinstAuraMgr_x                                             0xD2E4F8
#define pinstBandageTarget_x                                       0xF142A8
#define pinstCamActor_x                                            0xE60E48
#define pinstCDBStr_x                                              0xE603AC
#define pinstCDisplay_x                                            0xF142D0
#define pinstCEverQuest_x                                          0x10B34C8
#define pinstEverQuestInfo_x                                       0xF216A0
#define pinstCharData_x                                            0xF1428C
#define pinstCharSpawn_x                                           0xF142B4
#define pinstControlledMissile_x                                   0xF14288
#define pinstControlledPlayer_x                                    0xF142B4
#define pinstCSidlManager_x                                        0x171F074
#define pinstCXWndManager_x                                        0x171F06C
#define instDynamicZone_x                                          0xF21540
#define pinstDZMember_x                                            0xF21650
#define pinstDZTimerInfo_x                                         0xF21654
#define pinstEQItemList_x                                          0xF10984
#define pinstEQObjectList_x                                        0xF1175C
#define instEQMisc_x                                               0xBF2690
#define pinstEQSoundManager_x                                      0xE61AC8
#define instExpeditionLeader_x                                     0xF2158A
#define instExpeditionName_x                                       0xF215CA
#define pinstGroup_x                                               0xF11D5E
#define pinstImeManager_x                                          0x171F078
#define pinstLocalPlayer_x                                         0xF142A0
#define pinstMercenaryData_x                                       0xFA6A80
#define pinstMercenaryStats_x                                      0x10BB0F0
#define pinstMercAltAbilities_x                                    0xE61880
#define pinstModelPlayer_x                                         0xF142CC
#define pinstPCData_x                                              0xF1428C
#define pinstSkillMgr_x                                            0xFA78E8
#define pinstSpawnManager_x                                        0xFA71D0
#define pinstSpellManager_x                                        0xFA7A30
#define pinstSpellSets_x                                           0xF9E930
#define pinstStringTable_x                                         0xF14234
#define pinstSwitchManager_x                                       0xF118F0
#define pinstTarget_x                                              0xF142B8
#define pinstTargetObject_x                                        0xF14290
#define pinstTargetSwitch_x                                        0xF14294
#define pinstTaskMember_x                                          0xE602F8
#define pinstTrackTarget_x                                         0xF142AC
#define pinstTradeTarget_x                                         0xF1429C
#define instTributeActive_x                                        0xBF26B5
#define pinstViewActor_x                                           0xE60E44
#define pinstWorldData_x                                           0xF14270
#define pinstZoneAddr_x                                            0xF21C24
#define pinstPlayerPath_x                                          0xFA7230
#define pinstTargetIndicator_x                                     0xFA7BC8
#define pinstCTargetManager_x                                      0xFA7C28
#define EQObject_Top_x                                             0xF14280
#define pinstRealEstateItems_x                                     0xFA77D4

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE60D60
#define pinstCAchievementsWnd_x                                    0xE60DBC
#define pinstCTextOverlay_x                                        0xD1E288
#define pinstCAudioTriggersWindow_x                                0xD1E118
#define pinstCCharacterSelect_x                                    0xE60CD0
#define pinstCFacePick_x                                           0xE60C80
#define pinstCNoteWnd_x                                            0xE60C88
#define pinstCBookWnd_x                                            0xE60C90
#define pinstCPetInfoWnd_x                                         0xE60C94
#define pinstCTrainWnd_x                                           0xE60C98
#define pinstCSkillsWnd_x                                          0xE60C9C
#define pinstCSkillsSelectWnd_x                                    0xE60CA0
#define pinstCCombatSkillsSelectWnd_x                              0xE60CA4
#define pinstCFriendsWnd_x                                         0xE60CA8
#define pinstCAuraWnd_x                                            0xE60CAC
#define pinstCRespawnWnd_x                                         0xE60CB0
#define pinstCBandolierWnd_x                                       0xE60CB4
#define pinstCPotionBeltWnd_x                                      0xE60CB8
#define pinstCAAWnd_x                                              0xE60CBC
#define pinstCGroupSearchFiltersWnd_x                              0xE60CC0
#define pinstCLoadskinWnd_x                                        0xE60CC4
#define pinstCAlarmWnd_x                                           0xE60CC8
#define pinstCMusicPlayerWnd_x                                     0xE60CCC
#define pinstCMailWnd_x                                            0xE60CD4
#define pinstCMailCompositionWnd_x                                 0xE60CD8
#define pinstCMailAddressBookWnd_x                                 0xE60CDC
#define pinstCRaidWnd_x                                            0xE60CE4
#define pinstCRaidOptionsWnd_x                                     0xE60CE8
#define pinstCBreathWnd_x                                          0xE60CEC
#define pinstCMapViewWnd_x                                         0xE60CF0
#define pinstCMapToolbarWnd_x                                      0xE60CF4
#define pinstCEditLabelWnd_x                                       0xE60CF8
#define pinstCTargetWnd_x                                          0xE60CFC
#define pinstCColorPickerWnd_x                                     0xE60D00
#define pinstCPlayerWnd_x                                          0xE60D04
#define pinstCOptionsWnd_x                                         0xE60D08
#define pinstCBuffWindowNORMAL_x                                   0xE60D0C
#define pinstCBuffWindowSHORT_x                                    0xE60D10
#define pinstCharacterCreation_x                                   0xE60D14
#define pinstCCursorAttachment_x                                   0xE60D18
#define pinstCCastingWnd_x                                         0xE60D1C
#define pinstCCastSpellWnd_x                                       0xE60D20
#define pinstCSpellBookWnd_x                                       0xE60D24
#define pinstCInventoryWnd_x                                       0xE60D28
#define pinstCBankWnd_x                                            0xE60D30
#define pinstCQuantityWnd_x                                        0xE60D34
#define pinstCLootWnd_x                                            0xE60D38
#define pinstCActionsWnd_x                                         0xE60D3C
#define pinstCCombatAbilityWnd_x                                   0xE60D44
#define pinstCMerchantWnd_x                                        0xE60D48
#define pinstCTradeWnd_x                                           0xE60D50
#define pinstCSelectorWnd_x                                        0xE60D54
#define pinstCBazaarWnd_x                                          0xE60D58
#define pinstCBazaarSearchWnd_x                                    0xE60D5C
#define pinstCGiveWnd_x                                            0xE60D78
#define pinstCTrackingWnd_x                                        0xE60D80
#define pinstCInspectWnd_x                                         0xE60D84
#define pinstCSocialEditWnd_x                                      0xE60D88
#define pinstCFeedbackWnd_x                                        0xE60D8C
#define pinstCBugReportWnd_x                                       0xE60D90
#define pinstCVideoModesWnd_x                                      0xE60D94
#define pinstCTextEntryWnd_x                                       0xE60D9C
#define pinstCFileSelectionWnd_x                                   0xE60DA0
#define pinstCCompassWnd_x                                         0xE60DA4
#define pinstCPlayerNotesWnd_x                                     0xE60DA8
#define pinstCGemsGameWnd_x                                        0xE60DAC
#define pinstCTimeLeftWnd_x                                        0xE60DB0
#define pinstCPetitionQWnd_x                                       0xE60DCC
#define pinstCStoryWnd_x                                           0xE60DD0
#define pinstCJournalTextWnd_x                                     0xE60DD4
#define pinstCJournalCatWnd_x                                      0xE60DD8
#define pinstCBodyTintWnd_x                                        0xE60DDC
#define pinstCServerListWnd_x                                      0xE60DE0
#define pinstCAvaZoneWnd_x                                         0xE60DEC
#define pinstCBlockedBuffWnd_x                                     0xE60DF0
#define pinstCBlockedPetBuffWnd_x                                  0xE60DF4
#define pinstCInvSlotMgr_x                                         0xE60E3C
#define pinstCContainerMgr_x                                       0xE60E40
#define pinstCAdventureLeaderboardWnd_x                            0x10B3E78
#define pinstCAdventureRequestWnd_x                                0x10B3EF0
#define pinstCAltStorageWnd_x                                      0x10B41D0
#define pinstCAdventureStatsWnd_x                                  0x10B3F68
#define pinstCBarterMerchantWnd_x                                  0x10B4DB8
#define pinstCBarterSearchWnd_x                                    0x10B4E30
#define pinstCBarterWnd_x                                          0x10B4EA8
#define pinstCChatWindowManager_x                                  0x10B5538
#define pinstCDynamicZoneWnd_x                                     0x10B59E8
#define pinstCEQMainWnd_x                                          0x10B5B80
#define pinstCFellowshipWnd_x                                      0x10B597C
#define pinstCFindLocationWnd_x                                    0x10B5E50
#define pinstCGroupSearchWnd_x                                     0x10B6120
#define pinstCGroupWnd_x                                           0x10B6198
#define pinstCGuildBankWnd_x                                       0x10B6210
#define pinstCGuildMgmtWnd_x                                       0x10B8300
#define pinstCHotButtonWnd_x                                       0x10B83FC
#define pinstCHotButtonWnd1_x                                      0x10B83FC
#define pinstCHotButtonWnd2_x                                      0x10B8400
#define pinstCHotButtonWnd3_x                                      0x10B8404
#define pinstCHotButtonWnd4_x                                      0x10B8428
#define pinstCItemDisplayManager_x                                 0x10B8720
#define pinstCItemExpTransferWnd_x                                 0x10B879C
#define pinstCLFGuildWnd_x                                         0x10B8A78
#define pinstCMIZoneSelectWnd_x                                    0x10B9060
#define pinstCConfirmationDialog_x                                 0x10B9768
#define pinstCPopupWndManager_x                                    0x10B9768
#define pinstCProgressionSelectionWnd_x                            0x10B9858
#define pinstCPvPStatsWnd_x                                        0x10B9948
#define pinstCLargeDialogWnd_x                                     0x10BA050
#define pinstCTaskWnd_x                                            0x10BB3D0
#define pinstCTaskSomething_x                                      0xD2EEA0
#define pinstCTaskTemplateSelectWnd_x                              0x10BB358
#define pinstCTipWndOFDAY_x                                        0x10BB538
#define pinstCTipWndCONTEXT_x                                      0x10BB53C
#define pinstCTitleWnd_x                                           0x10BB5B8
#define pinstCContextMenuManager_x                                 0x171EFE4
#define pinstCVoiceMacroWnd_x                                      0xFA8000
#define pinstCHtmlWnd_x                                            0xFA80F0
#define pinstIconCache_x                                           0x10B5B54
#define pinstCTradeskillWnd_x                                      0x10BB6B8
#define pinstCAdvancedLootWnd_x                                    0xE60E30
#define pinstRewardSelectionWnd_x                                  0x10B9E70
#define pinstEQSuiteTextureLoader_x                                0xD0C458

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5430A0
#define __ConvertItemTags_x                                        0x530760
#define __ExecuteCmd_x                                             0x51B080
#define __EQGetTime_x                                              0x8990F0
#define __get_melee_range_x                                        0x521CE0
#define __GetGaugeValueFromEQ_x                                    0x7A9E20
#define __GetLabelFromEQ_x                                         0x7AB1F0
#define __ToggleKeyRingItem_x                                      0x488CF0
#define __GetXTargetType_x                                         0x929E30
#define __LoadFrontEnd_x                                           0x638D40
#define __NewUIINI_x                                               0x7A97F0
#define __ProcessGameEvents_x                                      0x57CD60
#define __ProcessMouseEvent_x                                      0x57C500
#define CrashDetected_x                                            0x63A700
#define wwsCrashReportCheckForUploader_x                           0x7F7AE0
#define __AppCrashWrapper_x                                        0xC58704
#define __pCrashHandler_x                                          0x10C8568
#define __CrashHandler_x                                           0x7F7570
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F9D10
#define DrawNetStatus_x                                            0x5B3520
#define Util__FastTime_x                                           0x898D90
#define Expansion_HoT_x                                            0xF22A70
#define __HelpPath_x                                               0xFA6188
#define __STMLToText_x                                             0x8DF340

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423240
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DF50
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DD20

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D12E0
#define AltAdvManager__IsAbilityReady_x                            0x4D1350
#define AltAdvManager__GetAAById_x                                 0x4D1840
#define AltAdvManager__CanTrainAbility_x                           0x4D2470
#define AltAdvManager__CanSeeAbility_x                             0x4D2030

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46A230
#define CharacterZoneClient__HasSkill_x                            0x4670E0
#define CharacterZoneClient__MakeMeVisible_x                       0x46B7C0
#define CharacterZoneClient__IsStackBlocked_x                      0x44B7A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44AC60
#define CharacterZoneClient__GetItemCountWorn_x                    0x465060
#define CharacterZoneClient__GetItemCountInInventory_x             0x465140
#define CharacterZoneClient__GetCursorItemCount_x                  0x465220
#define CharacterZoneClient__FindAffectSlot_x                      0x450CF0
#define CharacterZoneClient__BardCastBard_x                        0x44A3E0
#define CharacterZoneClient__GetMaxEffects_x                       0x449120
#define CharacterZoneClient__GetEffect_x                           0x44AE90
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x450B50
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4492C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44F6A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6686F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6769C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5925C0
#define CButtonWnd__CButtonWnd_x                                   0x8D35E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691A70
#define CChatManager__InitContextMenu_x                            0x692BC0
#define CChatManager__FreeChatWindow_x                             0x691500
#define CChatManager__GetLockedActiveChatWindow_x                  0x69AC90
#define CChatManager__SetLockedActiveChatWindow_x                  0x691A40

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DD6A0
#define CContextMenu__dCContextMenu_x                              0x8DD8B0
#define CContextMenu__AddMenuItem_x                                0x8DDDC0
#define CContextMenu__RemoveMenuItem_x                             0x8DDA20
#define CContextMenu__RemoveAllMenuItems_x                         0x8DDA40
#define CContextMenu__CheckMenuItem_x                              0x8DDAC0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8C9B10
#define CContextMenuManager__RemoveMenu_x                          0x8C9EC0
#define CContextMenuManager__PopupMenu_x                           0x8CA310
#define CContextMenuManager__Flush_x                               0x8C9B80
#define CContextMenuManager__GetMenu_x                             0x419610

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x83F810
#define CChatService__GetFriendName_x                              0x87D4A0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6987D0
#define CChatWindow__Clear_x                                       0x6980B0
#define CChatWindow__WndNotification_x                             0x6990E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CD980
#define CComboWnd__Draw_x                                          0x8CDB90
#define CComboWnd__GetCurChoice_x                                  0x8CD730
#define CComboWnd__GetListRect_x                                   0x8CDE30
#define CComboWnd__GetTextRect_x                                   0x8CD9F0
#define CComboWnd__InsertChoice_x                                  0x8CDEA0
#define CComboWnd__SetColors_x                                     0x8CD6C0
#define CComboWnd__SetChoice_x                                     0x8CD6F0
#define CComboWnd__GetItemCount_x                                  0x8CD720
#define CComboWnd__GetCurChoiceText_x                              0x8CD770

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A2990
#define CContainerWnd__vftable_x                                   0xADF030

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BEFC0
#define CDisplay__GetClickedActor_x                                0x4B78B0
#define CDisplay__GetUserDefinedColor_x                            0x4B6490
#define CDisplay__GetWorldFilePath_x                               0x4B58E0
#define CDisplay__is3dON_x                                         0x4B4D70
#define CDisplay__ReloadUI_x                                       0x4C8F20
#define CDisplay__WriteTextHD2_x                                   0x4BB380
#define CDisplay__TrueDistance_x                                   0x4B84E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F3C10

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E1BF0
#define CEditWnd__GetCharIndexPt_x                                 0x8E2C70
#define CEditWnd__GetDisplayString_x                               0x8E1DA0
#define CEditWnd__GetHorzOffset_x                                  0x8E20E0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E2740
#define CEditWnd__GetSelStartPt_x                                  0x8E2F20
#define CEditWnd__GetSTMLSafeText_x                                0x8E2270
#define CEditWnd__PointFromPrintableChar_x                         0x8E2830
#define CEditWnd__SelectableCharFromPoint_x                        0x8E29B0
#define CEditWnd__SetEditable_x                                    0x8E2240

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x563360
#define CEverQuest__ClickedPlayer_x                                0x55CFF0
#define CEverQuest__CreateTargetIndicator_x                        0x55DEF0
#define CEverQuest__DeleteTargetIndicator_x                        0x55DF70
#define CEverQuest__DoTellWindow_x                                 0x4763C0
#define CEverQuest__OutputTextToLog_x                              0x476020
#define CEverQuest__DropHeldItemOnGround_x                         0x5738D0
#define CEverQuest__dsp_chat_x                                     0x476700
#define CEverQuest__trimName_x                                     0x559900
#define CEverQuest__Emote_x                                        0x571BE0
#define CEverQuest__EnterZone_x                                    0x56CCC0
#define CEverQuest__GetBodyTypeDesc_x                              0x557340
#define CEverQuest__GetClassDesc_x                                 0x560780
#define CEverQuest__GetClassThreeLetterCode_x                      0x560D80
#define CEverQuest__GetDeityDesc_x                                 0x557C20
#define CEverQuest__GetLangDesc_x                                  0x5576D0
#define CEverQuest__GetRaceDesc_x                                  0x560F40
#define CEverQuest__InterpretCmd_x                                 0x564AE0
#define CEverQuest__LeftClickedOnPlayer_x                          0x579410
#define CEverQuest__LMouseUp_x                                     0x57B520
#define CEverQuest__RightClickedOnPlayer_x                         0x579F20
#define CEverQuest__RMouseUp_x                                     0x57AF80
#define CEverQuest__SetGameState_x                                 0x55D8C0
#define CEverQuest__UPCNotificationFlush_x                         0x555CD0
#define CEverQuest__IssuePetCommand_x                              0x5654C0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B3530
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B3590
#define CGaugeWnd__Draw_x                                          0x6B39C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B0C0
#define CGuild__GetGuildName_x                                     0x43B590
#define CGuild__GetGuildIndex_x                                    0x43C7A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CFA50

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DCC90
#define CInvSlotMgr__MoveItem_x                                    0x6DDB40
#define CInvSlotMgr__SelectSlot_x                                  0x6DCD40

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DC140
#define CInvSlot__SliderComplete_x                                 0x6D98D0
#define CInvSlot__GetItemBase_x                                    0x6D8D60
#define CInvSlot__UpdateItem_x                                     0x6D92E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DEFA0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E00C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A5820
#define CItemDisplayWnd__UpdateStrings_x                           0x6E11D0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6EDC70
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6EE1A0
#define CItemDisplayWnd__SetItem_x                                 0x6F3A80

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7DCDB0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6E77A0

// CLabel 
#define CLabel__Draw_x                                             0x6FA750

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B94D0
#define CListWnd__dCListWnd_x                                      0x8BA6F0
#define CListWnd__AddColumn_x                                      0x8BA690
#define CListWnd__AddColumn1_x                                     0x8B9D30
#define CListWnd__AddLine_x                                        0x8B9790
#define CListWnd__AddString_x                                      0x8B99B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B6770
#define CListWnd__CalculateVSBRange_x                              0x8B8990
#define CListWnd__ClearSel_x                                       0x8B5A90
#define CListWnd__ClearAllSel_x                                    0x8B5A40
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B9360
#define CListWnd__Compare_x                                        0x8B72E0
#define CListWnd__Draw_x                                           0x8B85A0
#define CListWnd__DrawColumnSeparators_x                           0x8B8430
#define CListWnd__DrawHeader_x                                     0x8B5D50
#define CListWnd__DrawItem_x                                       0x8B7970
#define CListWnd__DrawLine_x                                       0x8B80D0
#define CListWnd__DrawSeparator_x                                  0x8B84D0
#define CListWnd__EnableLine_x                                     0x8B5C70
#define CListWnd__EnsureVisible_x                                  0x8B68D0
#define CListWnd__ExtendSel_x                                      0x8B7880
#define CListWnd__GetColumnMinWidth_x                              0x8B5440
#define CListWnd__GetColumnWidth_x                                 0x8B5370
#define CListWnd__GetCurSel_x                                      0x8B4B40
#define CListWnd__GetItemAtPoint_x                                 0x8B6B60
#define CListWnd__GetItemAtPoint1_x                                0x8B6BD0
#define CListWnd__GetItemData_x                                    0x8B4E80
#define CListWnd__GetItemHeight_x                                  0x8B63D0
#define CListWnd__GetItemIcon_x                                    0x8B5070
#define CListWnd__GetItemRect_x                                    0x8B69A0
#define CListWnd__GetItemText_x                                    0x8B4F20
#define CListWnd__GetSelList_x                                     0x8B9C20
#define CListWnd__GetSeparatorRect_x                               0x8B7200
#define CListWnd__InsertLine_x                                     0x8B9B90
#define CListWnd__RemoveLine_x                                     0x8B9BA0
#define CListWnd__SetColors_x                                      0x8B4C90
#define CListWnd__SetColumnJustification_x                         0x8B56D0
#define CListWnd__SetColumnWidth_x                                 0x8B53F0
#define CListWnd__SetCurSel_x                                      0x8B4B80
#define CListWnd__SetItemColor_x                                   0x8B9050
#define CListWnd__SetItemData_x                                    0x8B5AF0
#define CListWnd__SetItemText_x                                    0x8B8E90
#define CListWnd__ShiftColumnSeparator_x                           0x8B8D20
#define CListWnd__Sort_x                                           0x8BA7F0
#define CListWnd__ToggleSel_x                                      0x8B59C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x713720

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x734BB0
#define CMerchantWnd__RequestBuyItem_x                             0x73BC90
#define CMerchantWnd__RequestSellItem_x                            0x73C760
#define CMerchantWnd__SelectRecoverySlot_x                         0x734E60
#define CMerchantWnd__SelectBuySellSlot_x                          0x734060
#define CMerchantWnd__ActualSelect_x                               0x738B50

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84B6D0
#define CPacketScrambler__hton_x                                   0x84B6E0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D8540
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D8620
#define CSidlManager__CreateLabel_x                                0x79CE70
#define CSidlManager__CreateXWndFromTemplate_x                     0x8D6AD0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D8900

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8CFA00
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8CF8F0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F3AF0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D0320
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D1500
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D15B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D0A70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CFCD0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CF420
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CFEC0
#define CSidlScreenWnd__Init1_x                                    0x8D11D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D03D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CF5E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D0CB0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CF080
#define CSidlScreenWnd__StoreIniVis_x                              0x8CF3D0
#define CSidlScreenWnd__WndNotification_x                          0x8D0F50
#define CSidlScreenWnd__GetChildItem_x                             0x8CF4F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C2D20
#define CSidlScreenWnd__m_layoutCopy_x                             0x171F048

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FE7F0
#define CSkillMgr__GetSkillCap_x                                   0x5FE9D0
#define CSkillMgr__GetNameToken_x                                  0x5FE3A0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F2D90
#define CSliderWnd__SetValue_x                                     0x8F2F60
#define CSliderWnd__SetNumTicks_x                                  0x8F36E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A3480

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8ED2A0
#define CStmlWnd__CalculateHSBRange_x                              0x8E59A0
#define CStmlWnd__CalculateVSBRange_x                              0x8E5910
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E5B20
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E6320
#define CStmlWnd__ForceParseNow_x                                  0x8EDC20
#define CStmlWnd__GetNextTagPiece_x                                0x8E6220
#define CStmlWnd__GetSTMLText_x                                    0x4842C0
#define CStmlWnd__GetVisibleText_x                                 0x8E6D70
#define CStmlWnd__InitializeWindowVariables_x                      0x8E91D0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E4BF0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E4C50
#define CStmlWnd__SetSTMLText_x                                    0x8EAA30
#define CStmlWnd__StripFirstSTMLLines_x                            0x8ECF40
#define CStmlWnd__UpdateHistoryString_x                            0x8E7CB0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F1110
#define CTabWnd__DrawCurrentPage_x                                 0x8F09A0
#define CTabWnd__DrawTab_x                                         0x8F0770
#define CTabWnd__GetCurrentPage_x                                  0x8F0D50
#define CTabWnd__GetPageInnerRect_x                                0x8F0460
#define CTabWnd__GetTabInnerRect_x                                 0x8F0660
#define CTabWnd__GetTabRect_x                                      0x8F0530
#define CTabWnd__InsertPage_x                                      0x8F1400
#define CTabWnd__SetPage_x                                         0x8F0D80
#define CTabWnd__SetPageRect_x                                     0x8F1050
#define CTabWnd__UpdatePage_x                                      0x8F13A0
#define CTabWnd__GetPageFromTabIndex_x                             0x8F06C0
#define CTabWnd__GetCurrentTabIndex_x                              0x8F03F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E0270
#define CPageWnd__SetTabText_x                                     0x8FCAE0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436CD0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CD330
#define CTextureFont__GetTextExtent_x                              0x8CD090

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x636FE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F8F20

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B2C50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59FE50
#define CXStr__CXStr1_x                                            0x8A8350
#define CXStr__CXStr3_x                                            0x895FE0
#define CXStr__dCXStr_x                                            0x746FB0
#define CXStr__operator_equal_x                                    0x896150
#define CXStr__operator_equal1_x                                   0x8961A0
#define CXStr__operator_plus_equal1_x                              0x8972A0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C1F10
#define CXWnd__Center_x                                            0x8C80D0
#define CXWnd__ClrFocus_x                                          0x8C1AF0
#define CXWnd__Destroy_x                                           0x8C8BC0
#define CXWnd__DoAllDrawing_x                                      0x8C7D00
#define CXWnd__DrawChildren_x                                      0x8C7EB0
#define CXWnd__DrawColoredRect_x                                   0x8C2300
#define CXWnd__DrawTooltip_x                                       0x8C25B0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C6C80
#define CXWnd__GetBorderFrame_x                                    0x8C2A10
#define CXWnd__GetChildWndAt_x                                     0x8C8AA0
#define CXWnd__GetClientClipRect_x                                 0x8C27C0
#define CXWnd__GetScreenClipRect_x                                 0x8C7370
#define CXWnd__GetScreenRect_x                                     0x8C2BD0
#define CXWnd__GetTooltipRect_x                                    0x8C2440
#define CXWnd__GetWindowTextA_x                                    0x427310
#define CXWnd__IsActive_x                                          0x8BD510
#define CXWnd__IsDescendantOf_x                                    0x8C2950
#define CXWnd__IsReallyVisible_x                                   0x8C5CB0
#define CXWnd__IsType_x                                            0x8C8140
#define CScreenPieceTemplate__IsType_x                             0x8F5780
#define CXWnd__Move_x                                              0x8C53B0
#define CXWnd__Move1_x                                             0x8C79C0
#define CXWnd__ProcessTransition_x                                 0x8C1EB0
#define CXWnd__Refade_x                                            0x8C1C80
#define CXWnd__Resize_x                                            0x8C2C90
#define CXWnd__Right_x                                             0x8C7170
#define CXWnd__SetFocus_x                                          0x8C4520
#define CXWnd__SetFont_x                                           0x8C1B40
#define CXWnd__SetKeyTooltip_x                                     0x8C2EF0
#define CXWnd__SetMouseOver_x                                      0x8C76B0
#define CXWnd__StartFade_x                                         0x8C1F60
#define CXWnd__GetChildItem_x                                      0x8C75F0
#define CXWnd__SetParent_x                                         0x8C8A50

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BED90
#define CXWndManager__DrawWindows_x                                0x8BE9D0
#define CXWndManager__GetKeyboardFlags_x                           0x8BD040
#define CXWndManager__HandleKeyboardMsg_x                          0x8BD9A0
#define CXWndManager__RemoveWnd_x                                  0x8BD6A0

// CDBStr
#define CDBStr__GetString_x                                        0x4B35D0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x451CF0
#define EQ_Character__Cur_HP_x                                     0x4666E0
#define EQ_Character__Cur_Mana_x                                   0x45A470
#define EQ_Character__GetAACastingTimeModifier_x                   0x44AF70
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4432F0
#define EQ_Character__GetFocusRangeModifier_x                      0x443350
#define EQ_Character__GetHPRegen_x                                 0x4698C0
#define EQ_Character__GetEnduranceRegen_x                          0x465CF0
#define EQ_Character__GetManaRegen_x                               0x469E60
#define EQ_Character__Max_Endurance_x                              0x5C52F0
#define EQ_Character__Max_HP_x                                     0x45CFF0
#define EQ_Character__Max_Mana_x                                   0x5C5120
#define EQ_Character__doCombatAbility_x                            0x5C27F0
#define EQ_Character__UseSkill_x                                   0x470850
#define EQ_Character__GetConLevel_x                                0x5B7BD0
#define EQ_Character__IsExpansionFlag_x                            0x426840
#define EQ_Character__TotalEffect_x                                0x44F020
#define EQ_Character__GetPCSpellAffect_x                           0x44B370
#define EQ_Character__SpellDuration_x                              0x449310
#define EQ_Character__FindItemByRecord_x                           0x463D30
#define EQ_Character__GetAdjustedSkill_x                           0x466E90
#define EQ_Character__GetBaseSkill_x                               0x45CED0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x868E50

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5CD340

//PcClient
#define PcClient__PcClient_x                                       0x5B9A20

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446620
#define CCharacterSelect__EnterWorld_x                             0x445DF0
#define CCharacterSelect__Quit_x                                   0x4449D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x598040
#define EQ_Item__CreateItemTagString_x                             0x84A090
#define EQ_Item__IsStackable_x                                     0x83FA10
#define EQ_Item__GetImageNum_x                                     0x8424C0
#define EQ_Item__CreateItemClient_x                                0x598C30
#define EQ_Item__GetItemValue_x                                    0x848D50
#define EQ_Item__ValueSellMerchant_x                               0x84B360
#define EQ_Item__IsKeyRingItem_x                                   0x840470
#define EQ_Item__CanGoInBag_x                                      0x5981D0
#define EQ_Item__GetMaxItemCount_x                                 0x83F900
#define EQ_Item__GetHeldItem_x                                     0x8412C0
#define EQ_Item__GetAugmentFitBySlot_x                             0x84B180

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D3870
#define EQ_LoadingS__Array_x                                       0xBFAA78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C7800
#define EQ_PC__GetAlternateAbilityId_x                             0x853790
#define EQ_PC__GetCombatAbility_x                                  0x853820
#define EQ_PC__GetCombatAbilityTimer_x                             0x84E380
#define EQ_PC__GetItemRecastTimer_x                                0x5C0FB0
#define EQ_PC__HasLoreItem_x                                       0x5BB1E0
#define EQ_PC__AlertInventoryChanged_x                             0x5B7BA0
#define EQ_PC__GetPcZoneClient_x                                   0x5E1890
#define EQ_PC__RemoveMyAffect_x                                    0x5C0480
#define EQ_PC__GetKeyRingItems_x                                   0x84E7A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8614F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x855770

// EQItemList 
#define EQItemList__EQItemList_x                                   0x51FD70
#define EQItemList__add_object_x                                   0x54CC60
#define EQItemList__add_item_x                                     0x51FCB0
#define EQItemList__delete_item_x                                  0x520160
#define EQItemList__FreeItemList_x                                 0x520060

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B2890

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CD0E0
#define EQPlayer__dEQPlayer_x                                      0x5D5720
#define EQPlayer__DoAttack_x                                       0x5E7210
#define EQPlayer__EQPlayer_x                                       0x5D7E50
#define EQPlayer__SetNameSpriteState_x                             0x5D25E0
#define EQPlayer__SetNameSpriteTint_x                              0x5CE500
#define PlayerBase__HasProperty_j_x                                0x9265D0
#define EQPlayer__IsTargetable_x                                   0x926870
#define EQPlayer__CanSee_x                                         0x926DD0
#define PlayerZoneClient__ChangeHeight_x                           0x5E70D0
#define EQPlayer__CanSeeTargetIndicator_x                          0x926EC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x926B60

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E1A40

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5DBED0
#define EQPlayerManager__GetSpawnByName_x                          0x5DC330
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5DBF00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59E1E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59E220
#define KeypressHandler__ClearCommandStateArray_x                  0x59DDD0
#define KeypressHandler__HandleKeyDown_x                           0x59C730
#define KeypressHandler__HandleKeyUp_x                             0x59CA50
#define KeypressHandler__SaveKeymapping_x                          0x59DEA0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70C0B0
#define MapViewMap__SaveEx_x                                       0x70F3E0

#define PlayerPointManager__GetAltCurrency_x                       0x866F10

// StringTable 
#define StringTable__getString_x                                   0x861820

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C4D80
#define PcZoneClient__RemovePetEffect_x                            0x5C1480
#define PcZoneClient__HasAlternateAbility_x                        0x5C1E20
#define PcZoneClient__GetCurrentMod_x                              0x45C4A0
#define PcZoneClient__GetModCap_x                                  0x459BD0
#define PcZoneClient__CanEquipItem_x                               0x5C2340
#define PcZoneClient__GetItemByID_x                                0x5C6B80
#define PcZoneClient__GetItemByItemClass_x                         0x5C7720

//Doors
#define EQSwitch__UseSwitch_x                                      0x554550

//IconCache
#define IconCache__GetIcon_x                                       0x6A8E20

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69FD10
#define CContainerMgr__CloseContainer_x                            0x6A0530

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76CF60

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x590FE0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4EDA30
#define EQ_Spell__SpellAffects_x                                   0x4EB0D0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4EB140
#define CharacterZoneClient__CalcAffectChange_x                    0x44B200
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A440
#define CLootWnd__LootAll_x                                        0x701980
#define CLootWnd__RequestLootSlot_x                                0x702190
#define EQ_Spell__IsStackable_x                                    0x448EE0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x448F90
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EB50
#define EQ_Spell__IsSPAStacking_x                                  0x4EAC80
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4EA750
#define EQ_Spell__IsNoRemove_x                                     0x434D00
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4EACA0

#define __IsResEffectSpell_x                                       0x449010

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x872AF0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B27B0
#define CTargetWnd__WndNotification_x                              0x7B22A0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B2990

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B78B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E6680
#define EqSoundManager__PlayScriptMp3_x                            0x4E8120

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A18B0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E1220
#define CSidlManager__FindAnimation1_x                             0x8D6500

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4DB150
#define CAltAbilityData__GetMercMaxRank_x                          0x4DB100
#define CAltAbilityData__GetMaxRank_x                              0x4CF990

//CTargetRing
#define CTargetRing__Cast_x                                        0x58E890

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x458B90
#define CharacterBase__CreateItemGlobalIndex_x                     0x4755D0
#define CharacterBase__CreateItemIndex_x                           0x5192F0
#define CharacterBase__GetItemPossession_x                         0x443EA0
#define CharacterBase__GetItemByGlobalIndex_x                      0x877130
#define CharacterBase__GetEffectId_x                               0x458B50

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x688C30
#define CCastSpellWnd__IsBardSongPlaying_x                         0x688390

//messages
#define msg_spell_worn_off_x                                       0x4F5550
#define msg_new_text_x                                             0x4FEBB0
#define msgTokenTextParam_x                                        0x4FB3F0

//SpellManager
#define SpellManager__vftable_x                                    0xABB160
#define SpellManager__SpellManager_x                               0x47E3C0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x605680

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x92A950

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F1B30
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EA80
#define ItemGlobalIndex__IsEquippedLocation_x                      0x448C90
#define ItemGlobalIndex__IsValidIndex_x                            0x458410

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x874FB0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x873EF0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6FA9A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6A4A60
#define CCursorAttachment__Deactivate_x                            0x6A3FA0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8F2290
