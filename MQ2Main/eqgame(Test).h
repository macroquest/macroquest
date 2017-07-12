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
#define __ExpectedVersionDate                                     "Jul 10 2017"
#define __ExpectedVersionTime                                     "12:47:45"
#define __ActualVersionDate_x                                      0xAD5498
#define __ActualVersionTime_x                                      0xAD54A4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5A29E0
#define __MemChecker1_x                                            0x898DE0
#define __MemChecker2_x                                            0x638770
#define __MemChecker3_x                                            0x6386C0
#define __MemChecker4_x                                            0x7EB120
#define __EncryptPad0_x                                            0xC2F328
#define __EncryptPad1_x                                            0xD0A6E0
#define __EncryptPad2_x                                            0xC58B10
#define __EncryptPad3_x                                            0xC58710
#define __EncryptPad4_x                                            0xCF8CE0
#define __EncryptPad5_x                                            0x10B3370
#define __AC1_x                                                    0x7AA785
#define __AC2_x                                                    0x55B8E7
#define __AC3_x                                                    0x559A60
#define __AC4_x                                                    0x56BC31
#define __AC5_x                                                    0x57FAEB
#define __AC6_x                                                    0x58369E
#define __AC7_x                                                    0x57A0EC
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
#define __do_loot_x                                                0x52ACA0
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
#define __SubscriptionType_x                                       0x10E6DB4
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
#define __CastRay_x                                                0x542230
#define __ConvertItemTags_x                                        0x52F8C0
#define __ExecuteCmd_x                                             0x51A1F0
#define __EQGetTime_x                                              0x898780
#define __get_melee_range_x                                        0x520E40
#define __GetGaugeValueFromEQ_x                                    0x7A9340
#define __GetLabelFromEQ_x                                         0x7AA710
#define __ToggleKeyRingItem_x                                      0x488B00
#define __GetXTargetType_x                                         0x929470
#define __LoadFrontEnd_x                                           0x637E40
#define __NewUIINI_x                                               0x7A8D10
#define __ProcessGameEvents_x                                      0x57BE80
#define __ProcessMouseEvent_x                                      0x57B620
#define CrashDetected_x                                            0x639800
#define wwsCrashReportCheckForUploader_x                           0x7F7000
#define __AppCrashWrapper_x                                        0xC58704
#define __pCrashHandler_x                                          0x10C8568
#define __CrashHandler_x                                           0x7F6A60
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F9200
#define DrawNetStatus_x                                            0x5B2660
#define Util__FastTime_x                                           0x898420
#define Expansion_HoT_x                                            0xF22A70
#define __HelpPath_x                                               0xFA6188
#define __STMLToText_x                                             0x8DE870

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423200
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DF10
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DCE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D10B0
#define AltAdvManager__IsAbilityReady_x                            0x4D1120
#define AltAdvManager__GetAAById_x                                 0x4D1610
#define AltAdvManager__CanTrainAbility_x                           0x4D2240
#define AltAdvManager__CanSeeAbility_x                             0x4D1E00

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46A180
#define CharacterZoneClient__HasSkill_x                            0x467030
#define CharacterZoneClient__MakeMeVisible_x                       0x46B710
#define CharacterZoneClient__IsStackBlocked_x                      0x44B700
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44ABC0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464FB0
#define CharacterZoneClient__GetItemCountInInventory_x             0x465090
#define CharacterZoneClient__GetCursorItemCount_x                  0x465170
#define CharacterZoneClient__FindAffectSlot_x                      0x450C70
#define CharacterZoneClient__BardCastBard_x                        0x44A340
#define CharacterZoneClient__GetMaxEffects_x                       0x449080
#define CharacterZoneClient__GetEffect_x                           0x44ADF0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x450AD0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449220
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44F620

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x667880

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x675AE0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5917D0
#define CButtonWnd__CButtonWnd_x                                   0x8D2B80

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x690D40
#define CChatManager__InitContextMenu_x                            0x691E90
#define CChatManager__FreeChatWindow_x                             0x6907D0
#define CChatManager__GetLockedActiveChatWindow_x                  0x699F50
#define CChatManager__SetLockedActiveChatWindow_x                  0x690D10

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DCBD0
#define CContextMenu__dCContextMenu_x                              0x8DCDE0
#define CContextMenu__AddMenuItem_x                                0x8DD2F0
#define CContextMenu__RemoveMenuItem_x                             0x8DCF50
#define CContextMenu__RemoveAllMenuItems_x                         0x8DCF70
#define CContextMenu__CheckMenuItem_x                              0x8DCFF0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8C90D0
#define CContextMenuManager__RemoveMenu_x                          0x8C9460
#define CContextMenuManager__PopupMenu_x                           0x8C98B0
#define CContextMenuManager__Flush_x                               0x8C9140
#define CContextMenuManager__GetMenu_x                             0x4195D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87CA20
#define CChatService__GetFriendName_x                              0x87CA30

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x697AA0
#define CChatWindow__Clear_x                                       0x697380
#define CChatWindow__WndNotification_x                             0x6983A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CCF40
#define CComboWnd__Draw_x                                          0x8CD150
#define CComboWnd__GetCurChoice_x                                  0x8CCCF0
#define CComboWnd__GetListRect_x                                   0x8CD3F0
#define CComboWnd__GetTextRect_x                                   0x8CCFB0
#define CComboWnd__InsertChoice_x                                  0x8CD460
#define CComboWnd__SetColors_x                                     0x8CCC80
#define CComboWnd__SetChoice_x                                     0x8CCCB0
#define CComboWnd__GetItemCount_x                                  0x8CCCE0
#define CComboWnd__GetCurChoiceText_x                              0x8CCD30

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A1C50
#define CContainerWnd__vftable_x                                   0xADF0A0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BEE80
#define CDisplay__GetClickedActor_x                                0x4B7780
#define CDisplay__GetUserDefinedColor_x                            0x4B6360
#define CDisplay__GetWorldFilePath_x                               0x4B57B0
#define CDisplay__is3dON_x                                         0x4B4C40
#define CDisplay__ReloadUI_x                                       0x4C8DE0
#define CDisplay__WriteTextHD2_x                                   0x4BB240
#define CDisplay__TrueDistance_x                                   0x4B83B0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F3130

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E1120
#define CEditWnd__GetCharIndexPt_x                                 0x8E2190
#define CEditWnd__GetDisplayString_x                               0x8E12D0
#define CEditWnd__GetHorzOffset_x                                  0x8E1610
#define CEditWnd__GetLineForPrintableChar_x                        0x8E1C70
#define CEditWnd__GetSelStartPt_x                                  0x8E2440
#define CEditWnd__GetSTMLSafeText_x                                0x8E17A0
#define CEditWnd__PointFromPrintableChar_x                         0x8E1D60
#define CEditWnd__SelectableCharFromPoint_x                        0x8E1ED0
#define CEditWnd__SetEditable_x                                    0x8E1770

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x562460
#define CEverQuest__ClickedPlayer_x                                0x55C030
#define CEverQuest__CreateTargetIndicator_x                        0x55CF30
#define CEverQuest__DeleteTargetIndicator_x                        0x55CFB0
#define CEverQuest__DoTellWindow_x                                 0x476320
#define CEverQuest__OutputTextToLog_x                              0x475F80
#define CEverQuest__DropHeldItemOnGround_x                         0x5729D0
#define CEverQuest__dsp_chat_x                                     0x476660
#define CEverQuest__trimName_x                                     0x558940
#define CEverQuest__Emote_x                                        0x570CE0
#define CEverQuest__EnterZone_x                                    0x56BDC0
#define CEverQuest__GetBodyTypeDesc_x                              0x556380
#define CEverQuest__GetClassDesc_x                                 0x55F880
#define CEverQuest__GetClassThreeLetterCode_x                      0x55FE80
#define CEverQuest__GetDeityDesc_x                                 0x556C60
#define CEverQuest__GetLangDesc_x                                  0x556710
#define CEverQuest__GetRaceDesc_x                                  0x560040
#define CEverQuest__InterpretCmd_x                                 0x563BE0
#define CEverQuest__LeftClickedOnPlayer_x                          0x578530
#define CEverQuest__LMouseUp_x                                     0x57A640
#define CEverQuest__RightClickedOnPlayer_x                         0x579040
#define CEverQuest__RMouseUp_x                                     0x57A0A0
#define CEverQuest__SetGameState_x                                 0x55C900
#define CEverQuest__UPCNotificationFlush_x                         0x554D20
#define CEverQuest__IssuePetCommand_x                              0x5645C0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B2850
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B28B0
#define CGaugeWnd__Draw_x                                          0x6B2CE0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43AF50
#define CGuild__GetGuildName_x                                     0x43B420
#define CGuild__GetGuildIndex_x                                    0x43C630

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CED80

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DBFD0
#define CInvSlotMgr__MoveItem_x                                    0x6DCE80
#define CInvSlotMgr__SelectSlot_x                                  0x6DC080

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DB480
#define CInvSlot__SliderComplete_x                                 0x6D8C10
#define CInvSlot__GetItemBase_x                                    0x6D80A0
#define CInvSlot__UpdateItem_x                                     0x6D8620

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DE2E0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6DF400

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A4D50
#define CItemDisplayWnd__UpdateStrings_x                           0x6E0520
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6ECFE0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6ED4F0
#define CItemDisplayWnd__SetItem_x                                 0x6F2E30

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7DC3C0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6E6B30

// CLabel 
#define CLabel__Draw_x                                             0x6F9AF0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B8B60
#define CListWnd__dCListWnd_x                                      0x8B9D90
#define CListWnd__AddColumn_x                                      0x8B9D30
#define CListWnd__AddColumn1_x                                     0x8B93C0
#define CListWnd__AddLine_x                                        0x8B8E20
#define CListWnd__AddString_x                                      0x8B9040
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B5E00
#define CListWnd__CalculateVSBRange_x                              0x8B8020
#define CListWnd__ClearSel_x                                       0x8B5120
#define CListWnd__ClearAllSel_x                                    0x8B50D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B89F0
#define CListWnd__Compare_x                                        0x8B6970
#define CListWnd__Draw_x                                           0x8B7C30
#define CListWnd__DrawColumnSeparators_x                           0x8B7AC0
#define CListWnd__DrawHeader_x                                     0x8B53E0
#define CListWnd__DrawItem_x                                       0x8B7000
#define CListWnd__DrawLine_x                                       0x8B7760
#define CListWnd__DrawSeparator_x                                  0x8B7B60
#define CListWnd__EnableLine_x                                     0x8B5300
#define CListWnd__EnsureVisible_x                                  0x8B5F60
#define CListWnd__ExtendSel_x                                      0x8B6F10
#define CListWnd__GetColumnMinWidth_x                              0x8B4AD0
#define CListWnd__GetColumnWidth_x                                 0x8B4A00
#define CListWnd__GetCurSel_x                                      0x8B41C0
#define CListWnd__GetItemAtPoint_x                                 0x8B61F0
#define CListWnd__GetItemAtPoint1_x                                0x8B6260
#define CListWnd__GetItemData_x                                    0x8B4510
#define CListWnd__GetItemHeight_x                                  0x8B5A60
#define CListWnd__GetItemIcon_x                                    0x8B4700
#define CListWnd__GetItemRect_x                                    0x8B6030
#define CListWnd__GetItemText_x                                    0x8B45B0
#define CListWnd__GetSelList_x                                     0x8B92B0
#define CListWnd__GetSeparatorRect_x                               0x8B6890
#define CListWnd__InsertLine_x                                     0x8B9220
#define CListWnd__RemoveLine_x                                     0x8B9230
#define CListWnd__SetColors_x                                      0x8B4310
#define CListWnd__SetColumnJustification_x                         0x8B4D60
#define CListWnd__SetColumnWidth_x                                 0x8B4A80
#define CListWnd__SetCurSel_x                                      0x8B4200
#define CListWnd__SetItemColor_x                                   0x8B86E0
#define CListWnd__SetItemData_x                                    0x8B5180
#define CListWnd__SetItemText_x                                    0x8B8520
#define CListWnd__ShiftColumnSeparator_x                           0x8B83B0
#define CListWnd__Sort_x                                           0x8B9E90
#define CListWnd__ToggleSel_x                                      0x8B5050

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x712BB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x734010
#define CMerchantWnd__RequestBuyItem_x                             0x73B0B0
#define CMerchantWnd__RequestSellItem_x                            0x73BB80
#define CMerchantWnd__SelectRecoverySlot_x                         0x7342C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7334C0
#define CMerchantWnd__ActualSelect_x                               0x737F70

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84AD90
#define CPacketScrambler__hton_x                                   0x84ADA0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D7A80
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D7B60
#define CSidlManager__CreateLabel_x                                0x79C430
#define CSidlManager__CreateXWndFromTemplate_x                     0x8D6010
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D7E40

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8CEFE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8CEED0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F3010
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CF900
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D0AC0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D0B70
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D0040
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CF2B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CEA00
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CF4A0
#define CSidlScreenWnd__Init1_x                                    0x8D0790
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CF9B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CEBC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D0280
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CE660
#define CSidlScreenWnd__StoreIniVis_x                              0x8CE9B0
#define CSidlScreenWnd__WndNotification_x                          0x8D0510
#define CSidlScreenWnd__GetChildItem_x                             0x8CEAD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C22B0
#define CSidlScreenWnd__m_layoutCopy_x                             0x171F048

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FD780
#define CSkillMgr__GetSkillCap_x                                   0x5FD960
#define CSkillMgr__GetNameToken_x                                  0x5FD330

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F22C0
#define CSliderWnd__SetValue_x                                     0x8F2490
#define CSliderWnd__SetNumTicks_x                                  0x8F2C10

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A29B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EC7D0
#define CStmlWnd__CalculateHSBRange_x                              0x8E4ED0
#define CStmlWnd__CalculateVSBRange_x                              0x8E4E40
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E5050
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E5850
#define CStmlWnd__ForceParseNow_x                                  0x8ED150
#define CStmlWnd__GetNextTagPiece_x                                0x8E5750
#define CStmlWnd__GetSTMLText_x                                    0x484000
#define CStmlWnd__GetVisibleText_x                                 0x8E62A0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E8700
#define CStmlWnd__MakeStmlColorTag_x                               0x8E4120
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E4180
#define CStmlWnd__SetSTMLText_x                                    0x8E9F60
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EC470
#define CStmlWnd__UpdateHistoryString_x                            0x8E71E0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F0640
#define CTabWnd__DrawCurrentPage_x                                 0x8EFED0
#define CTabWnd__DrawTab_x                                         0x8EFCA0
#define CTabWnd__GetCurrentPage_x                                  0x8F0280
#define CTabWnd__GetPageInnerRect_x                                0x8EF990
#define CTabWnd__GetTabInnerRect_x                                 0x8EFB90
#define CTabWnd__GetTabRect_x                                      0x8EFA60
#define CTabWnd__InsertPage_x                                      0x8F0930
#define CTabWnd__SetPage_x                                         0x8F02B0
#define CTabWnd__SetPageRect_x                                     0x8F0580
#define CTabWnd__UpdatePage_x                                      0x8F08D0
#define CTabWnd__GetPageFromTabIndex_x                             0x8EFBF0
#define CTabWnd__GetCurrentTabIndex_x                              0x8EF920

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6DF5B0
#define CPageWnd__SetTabText_x                                     0x8FC000

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436B00

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CC8F0
#define CTextureFont__GetTextExtent_x                              0x8CC650

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6360D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F8440

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B2210

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x4F19F0
#define CXStr__CXStr3_x                                            0x8956B0
#define CXStr__dCXStr_x                                            0x79C3E0
#define CXStr__operator_equal_x                                    0x895820
#define CXStr__operator_equal1_x                                   0x895870
#define CXStr__operator_plus_equal1_x                              0x896970

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C14B0
#define CXWnd__Center_x                                            0x8C76D0
#define CXWnd__ClrFocus_x                                          0x8C10A0
#define CXWnd__Destroy_x                                           0x8C81C0
#define CXWnd__DoAllDrawing_x                                      0x8C7320
#define CXWnd__DrawChildren_x                                      0x8C74C0
#define CXWnd__DrawColoredRect_x                                   0x8C18A0
#define CXWnd__DrawTooltip_x                                       0x8C1B50
#define CXWnd__DrawTooltipAtPoint_x                                0x8C6290
#define CXWnd__GetBorderFrame_x                                    0x8C1F70
#define CXWnd__GetChildWndAt_x                                     0x8C80A0
#define CXWnd__GetClientClipRect_x                                 0x8C1D70
#define CXWnd__GetScreenClipRect_x                                 0x8C6980
#define CXWnd__GetScreenRect_x                                     0x8C2140
#define CXWnd__GetTooltipRect_x                                    0x8C19E0
#define CXWnd__GetWindowTextA_x                                    0x4271B0
#define CXWnd__IsActive_x                                          0x8BCB40
#define CXWnd__IsDescendantOf_x                                    0x8C1EB0
#define CXWnd__IsReallyVisible_x                                   0x8C52C0
#define CXWnd__IsType_x                                            0x8C7740
#define CScreenPieceTemplate__IsType_x                             0x8F4CA0
#define CXWnd__Move_x                                              0x8C4990
#define CXWnd__Move1_x                                             0x8C6FC0
#define CXWnd__ProcessTransition_x                                 0x8C1450
#define CXWnd__Refade_x                                            0x8C1230
#define CXWnd__Resize_x                                            0x8C2210
#define CXWnd__Right_x                                             0x8C6780
#define CXWnd__SetFocus_x                                          0x8C3AE0
#define CXWnd__SetFont_x                                           0x8C10F0
#define CXWnd__SetKeyTooltip_x                                     0x8C2480
#define CXWnd__SetMouseOver_x                                      0x8C6CB0
#define CXWnd__StartFade_x                                         0x8C1500
#define CXWnd__GetChildItem_x                                      0x8C6BF0
#define CXWnd__SetParent_x                                         0x8C8050

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BE3E0
#define CXWndManager__DrawWindows_x                                0x8BE020
#define CXWndManager__GetKeyboardFlags_x                           0x8BC670
#define CXWndManager__HandleKeyboardMsg_x                          0x8BCFD0
#define CXWndManager__RemoveWnd_x                                  0x8BCCD0

// CDBStr
#define CDBStr__GetString_x                                        0x4B34A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x451C70
#define EQ_Character__Cur_HP_x                                     0x466630
#define EQ_Character__Cur_Mana_x                                   0x45A3E0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44AED0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443210
#define EQ_Character__GetFocusRangeModifier_x                      0x443270
#define EQ_Character__GetHPRegen_x                                 0x469810
#define EQ_Character__GetEnduranceRegen_x                          0x465C40
#define EQ_Character__GetManaRegen_x                               0x469DB0
#define EQ_Character__Max_Endurance_x                              0x5C4140
#define EQ_Character__Max_HP_x                                     0x45CF60
#define EQ_Character__Max_Mana_x                                   0x5C3F70
#define EQ_Character__doCombatAbility_x                            0x5C1640
#define EQ_Character__UseSkill_x                                   0x4707A0
#define EQ_Character__GetConLevel_x                                0x5B6D00
#define EQ_Character__IsExpansionFlag_x                            0x426700
#define EQ_Character__TotalEffect_x                                0x44EFA0
#define EQ_Character__GetPCSpellAffect_x                           0x44B2D0
#define EQ_Character__SpellDuration_x                              0x449270
#define EQ_Character__FindItemByRecord_x                           0x463CA0
#define EQ_Character__GetAdjustedSkill_x                           0x466DE0
#define EQ_Character__GetBaseSkill_x                               0x45CE40

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x868C60

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5CC140

//PcClient
#define PcClient__PcClient_x                                       0x5B8B30

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446570
#define CCharacterSelect__EnterWorld_x                             0x445D40
#define CCharacterSelect__Quit_x                                   0x444920

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x597230
#define EQ_Item__CreateItemTagString_x                             0x8496B0
#define EQ_Item__IsStackable_x                                     0x83EEA0
#define EQ_Item__GetImageNum_x                                     0x8419C0
#define EQ_Item__CreateItemClient_x                                0x597DF0
#define EQ_Item__GetItemValue_x                                    0x8483F0
#define EQ_Item__ValueSellMerchant_x                               0x84A9E0
#define EQ_Item__IsKeyRingItem_x                                   0x83F9A0
#define EQ_Item__CanGoInBag_x                                      0x5973C0
#define EQ_Item__GetMaxItemCount_x                                 0x83ED90
#define EQ_Item__GetHeldItem_x                                     0x8407D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x84A800

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D3670
#define EQ_LoadingS__Array_x                                       0xBFAA78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C6650
#define EQ_PC__GetAlternateAbilityId_x                             0x852E50
#define EQ_PC__GetCombatAbility_x                                  0x852EE0
#define EQ_PC__GetCombatAbilityTimer_x                             0x84DA40
#define EQ_PC__GetItemRecastTimer_x                                0x5BFDF0
#define EQ_PC__HasLoreItem_x                                       0x5BA2F0
#define EQ_PC__AlertInventoryChanged_x                             0x5B6CD0
#define EQ_PC__GetPcZoneClient_x                                   0x5E05E0
#define EQ_PC__RemoveMyAffect_x                                    0x5BF2C0
#define EQ_PC__GetKeyRingItems_x                                   0x84DE60
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x860B30
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x854DC0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x51EEE0
#define EQItemList__add_object_x                                   0x54BD40
#define EQItemList__add_item_x                                     0x51EE20
#define EQItemList__delete_item_x                                  0x51F2D0
#define EQItemList__FreeItemList_x                                 0x51F1D0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B27D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CBEE0
#define EQPlayer__dEQPlayer_x                                      0x5D4530
#define EQPlayer__DoAttack_x                                       0x5E5F50
#define EQPlayer__EQPlayer_x                                       0x5D6C50
#define EQPlayer__SetNameSpriteState_x                             0x5D13F0
#define EQPlayer__SetNameSpriteTint_x                              0x5CD300
#define PlayerBase__HasProperty_j_x                                0x925C30
#define EQPlayer__IsTargetable_x                                   0x925ED0
#define EQPlayer__CanSee_x                                         0x926430
#define PlayerZoneClient__ChangeHeight_x                           0x5E5E10
#define EQPlayer__CanSeeTargetIndicator_x                          0x926520
#define PlayerBase__GetVisibilityLineSegment_x                     0x9261C0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E0790

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5DAC20
#define EQPlayerManager__GetSpawnByName_x                          0x5DB080
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5DAC50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59D2A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59D2E0
#define KeypressHandler__ClearCommandStateArray_x                  0x59CE90
#define KeypressHandler__HandleKeyDown_x                           0x59B7F0
#define KeypressHandler__HandleKeyUp_x                             0x59BB10
#define KeypressHandler__SaveKeymapping_x                          0x59CF60

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70B540
#define MapViewMap__SaveEx_x                                       0x70E870

#define PlayerPointManager__GetAltCurrency_x                       0x866CF0

// StringTable 
#define StringTable__getString_x                                   0x860E60

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C3BD0
#define PcZoneClient__RemovePetEffect_x                            0x5C02C0
#define PcZoneClient__HasAlternateAbility_x                        0x5C0C60
#define PcZoneClient__GetCurrentMod_x                              0x45C410
#define PcZoneClient__GetModCap_x                                  0x459B40
#define PcZoneClient__CanEquipItem_x                               0x5C1180
#define PcZoneClient__GetItemByID_x                                0x5C59D0
#define PcZoneClient__GetItemByItemClass_x                         0x5C6570

//Doors
#define EQSwitch__UseSwitch_x                                      0x553650

//IconCache
#define IconCache__GetIcon_x                                       0x6A80F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69EFD0
#define CContainerMgr__CloseContainer_x                            0x69F7F0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76C320

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x590200

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4ED8B0
#define EQ_Spell__SpellAffects_x                                   0x4EAF50
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4EAFC0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B160
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A3A0
#define CLootWnd__LootAll_x                                        0x700E80
#define CLootWnd__RequestLootSlot_x                                0x701690
#define EQ_Spell__IsStackable_x                                    0x448E30
#define EQ_Spell__GetSpellAffectBySlot_x                           0x448EE0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EA70
#define EQ_Spell__IsSPAStacking_x                                  0x4EAB00
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4EA5D0
#define EQ_Spell__IsNoRemove_x                                     0x434B10
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4EAB20

#define __IsResEffectSpell_x                                       0x448F70

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8728D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B1D30
#define CTargetWnd__WndNotification_x                              0x7B1820
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B1F10

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B6E30

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E6500
#define EqSoundManager__PlayScriptMp3_x                            0x4E7FA0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A1820

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E0750
#define CSidlManager__FindAnimation1_x                             0x8D5A40

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4DAF40
#define CAltAbilityData__GetMercMaxRank_x                          0x4DAEF0
#define CAltAbilityData__GetMaxRank_x                              0x4CF760

//CTargetRing
#define CTargetRing__Cast_x                                        0x58DAA0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x458B00
#define CharacterBase__CreateItemGlobalIndex_x                     0x475520
#define CharacterBase__CreateItemIndex_x                           0x518470
#define CharacterBase__GetItemPossession_x                         0x443DF0
#define CharacterBase__GetItemByGlobalIndex_x                      0x876710
#define CharacterBase__GetEffectId_x                               0x458AC0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x687E70
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6875D0

//messages
#define msg_spell_worn_off_x                                       0x4F53E0
#define msg_new_text_x                                             0x4FEA30
#define msgTokenTextParam_x                                        0x4FB270

//SpellManager
#define SpellManager__vftable_x                                    0xABB168
#define SpellManager__SpellManager_x                               0x47E130
#define Spellmanager__CheckSpellRequirementAssociations_x          0x604650

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x929F90

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F19D0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43E9A0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x448BE0
#define ItemGlobalIndex__IsValidIndex_x                            0x458360

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x874590
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8734D0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F9D40

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6A3D20
#define CCursorAttachment__Deactivate_x                            0x6A3270

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8F17C0
