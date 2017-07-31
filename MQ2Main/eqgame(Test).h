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
#define __ExpectedVersionDate                                     "Jul 20 2017"
#define __ExpectedVersionTime                                     "17:07:40"
#define __ActualVersionDate_x                                      0xAD4420
#define __ActualVersionTime_x                                      0xAD442C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5A2220
#define __MemChecker1_x                                            0x898B10
#define __MemChecker2_x                                            0x638220
#define __MemChecker3_x                                            0x638170
#define __MemChecker4_x                                            0x7EB160
#define __EncryptPad0_x                                            0xC2E328
#define __EncryptPad1_x                                            0xD096E0
#define __EncryptPad2_x                                            0xC57B10
#define __EncryptPad3_x                                            0xC57710
#define __EncryptPad4_x                                            0xCF7CE0
#define __EncryptPad5_x                                            0x10B2370
#define __AC1_x                                                    0x7AA175
#define __AC2_x                                                    0x55B1A7
#define __AC3_x                                                    0x559320
#define __AC4_x                                                    0x56B4F1
#define __AC5_x                                                    0x57F3AB
#define __AC6_x                                                    0x582F5E
#define __AC7_x                                                    0x5799AC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FE4DFC

// Direct Input
#define DI8__Main_x                                                0x10B2348
#define DI8__Keyboard_x                                            0x10B234C
#define DI8__Mouse_x                                               0x10B2350
#define DI8__Mouse_Copy_x                                          0xF2070C
#define DI8__Mouse_Check_x                                         0xFAA034
#define __AutoSkillArray_x                                         0xF21620
#define __Attack_x                                                 0xFA4C17
#define __Autofire_x                                               0xFA4C18
#define __BindList_x                                               0xC09050
#define g_eqCommandStates_x                                        0xF0F730
#define __Clicks_x                                                 0xF207C8
#define __CommandList_x                                            0xC0B6C8
#define __CurrentMapLabel_x                                        0x10B7DD0
#define __CurrentSocial_x                                          0xBDA424
#define __DoAbilityList_x                                          0xF56ECC
#define __do_loot_x                                                0x52A540
#define __DrawHandler_x                                            0x171EC84
#define __GroupCount_x                                             0xF10D62

#define __Guilds_x                                                 0xF16978
#define __gWorld_x                                                 0xF1321C
#define __HotkeyPage_x                                             0xF9D8CC
#define __HWnd_x                                                   0xFAA150
#define __InChatMode_x                                             0xF206F4
#define __LastTell_x                                               0xF225C8
#define __LMouseHeldTime_x                                         0xF20834
#define __Mouse_x                                                  0x10B2354
#define __MouseLook_x                                              0xF2078E
#define __MouseEventTime_x                                         0xFA541C
#define __gpbCommandEvent_x                                        0xF132E4
#define __NetStatusToggle_x                                        0xF20791
#define __PCNames_x                                                0xF21BDC
#define __RangeAttackReady_x                                       0xF21904
#define __RMouseHeldTime_x                                         0xF20830
#define __RunWalkState_x                                           0xF206F8
#define __ScreenMode_x                                             0xE5F418
#define __ScreenX_x                                                0xF206AC
#define __ScreenY_x                                                0xF206A8
#define __ScreenXMax_x                                             0xF206B0
#define __ScreenYMax_x                                             0xF206B4
#define __ServerHost_x                                             0xF10CAC
#define __ServerName_x                                             0xF56E8C
#define __ShiftKeyDown_x                                           0xF20D88
#define __ShowNames_x                                              0xF21AC4
#define __Socials_x                                                0xF56F8C
#define __SubscriptionType_x                                       0x10E5DB4
#define __TargetAggroHolder_x                                      0x10B9FA4
#define __ZoneType_x                                               0xF20B8C
#define __GroupAggro_x                                             0x10B9FE4
#define __LoginName_x                                              0xFA8C2C
#define __Inviter_x                                                0xFA4B94
#define __AttackOnAssist_x                                         0xF21A80
#define __UseTellWindows_x                                         0xF21D74

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF13308
#define instEQZoneInfo_x                                           0xF20984
#define instKeypressHandler_x                                      0xFA5400
#define pinstActiveBanker_x                                        0xF132C0
#define pinstActiveCorpse_x                                        0xF132C4
#define pinstActiveGMaster_x                                       0xF132C8
#define pinstActiveMerchant_x                                      0xF132BC
#define pinstAggroInfo_x                                           0xD1CD88
#define pinstAltAdvManager_x                                       0xE604F8
#define pinstAuraMgr_x                                             0xD2D4F8
#define pinstBandageTarget_x                                       0xF132A8
#define pinstCamActor_x                                            0xE5FE48
#define pinstCDBStr_x                                              0xE5F3AC
#define pinstCDisplay_x                                            0xF132D0
#define pinstCEverQuest_x                                          0x10B24C8
#define pinstEverQuestInfo_x                                       0xF206A0
#define pinstCharData_x                                            0xF1328C
#define pinstCharSpawn_x                                           0xF132B4
#define pinstControlledMissile_x                                   0xF13288
#define pinstControlledPlayer_x                                    0xF132B4
#define pinstCSidlManager_x                                        0x171E074
#define pinstCXWndManager_x                                        0x171E06C
#define instDynamicZone_x                                          0xF20540
#define pinstDZMember_x                                            0xF20650
#define pinstDZTimerInfo_x                                         0xF20654
#define pinstEQItemList_x                                          0xF0F984
#define pinstEQObjectList_x                                        0xF1075C
#define instEQMisc_x                                               0xBF1690
#define pinstEQSoundManager_x                                      0xE60AC8
#define instExpeditionLeader_x                                     0xF2058A
#define instExpeditionName_x                                       0xF205CA
#define pinstGroup_x                                               0xF10D5E
#define pinstImeManager_x                                          0x171E078
#define pinstLocalPlayer_x                                         0xF132A0
#define pinstMercenaryData_x                                       0xFA5A80
#define pinstMercenaryStats_x                                      0x10BA0F0
#define pinstMercAltAbilities_x                                    0xE60880
#define pinstModelPlayer_x                                         0xF132CC
#define pinstPCData_x                                              0xF1328C
#define pinstSkillMgr_x                                            0xFA68E8
#define pinstSpawnManager_x                                        0xFA61D0
#define pinstSpellManager_x                                        0xFA6A30
#define pinstSpellSets_x                                           0xF9D930
#define pinstStringTable_x                                         0xF13234
#define pinstSwitchManager_x                                       0xF108F0
#define pinstTarget_x                                              0xF132B8
#define pinstTargetObject_x                                        0xF13290
#define pinstTargetSwitch_x                                        0xF13294
#define pinstTaskMember_x                                          0xE5F2F8
#define pinstTrackTarget_x                                         0xF132AC
#define pinstTradeTarget_x                                         0xF1329C
#define instTributeActive_x                                        0xBF16B5
#define pinstViewActor_x                                           0xE5FE44
#define pinstWorldData_x                                           0xF13270
#define pinstZoneAddr_x                                            0xF20C24
#define pinstPlayerPath_x                                          0xFA6230
#define pinstTargetIndicator_x                                     0xFA6BC8
#define pinstCTargetManager_x                                      0xFA6C28
#define EQObject_Top_x                                             0xF13280
#define pinstRealEstateItems_x                                     0xFA67D4

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE5FD60
#define pinstCAchievementsWnd_x                                    0xE5FDBC
#define pinstCTextOverlay_x                                        0xD1D288
#define pinstCAudioTriggersWindow_x                                0xD1D118
#define pinstCCharacterSelect_x                                    0xE5FCD0
#define pinstCFacePick_x                                           0xE5FC80
#define pinstCNoteWnd_x                                            0xE5FC88
#define pinstCBookWnd_x                                            0xE5FC90
#define pinstCPetInfoWnd_x                                         0xE5FC94
#define pinstCTrainWnd_x                                           0xE5FC98
#define pinstCSkillsWnd_x                                          0xE5FC9C
#define pinstCSkillsSelectWnd_x                                    0xE5FCA0
#define pinstCCombatSkillsSelectWnd_x                              0xE5FCA4
#define pinstCFriendsWnd_x                                         0xE5FCA8
#define pinstCAuraWnd_x                                            0xE5FCAC
#define pinstCRespawnWnd_x                                         0xE5FCB0
#define pinstCBandolierWnd_x                                       0xE5FCB4
#define pinstCPotionBeltWnd_x                                      0xE5FCB8
#define pinstCAAWnd_x                                              0xE5FCBC
#define pinstCGroupSearchFiltersWnd_x                              0xE5FCC0
#define pinstCLoadskinWnd_x                                        0xE5FCC4
#define pinstCAlarmWnd_x                                           0xE5FCC8
#define pinstCMusicPlayerWnd_x                                     0xE5FCCC
#define pinstCMailWnd_x                                            0xE5FCD4
#define pinstCMailCompositionWnd_x                                 0xE5FCD8
#define pinstCMailAddressBookWnd_x                                 0xE5FCDC
#define pinstCRaidWnd_x                                            0xE5FCE4
#define pinstCRaidOptionsWnd_x                                     0xE5FCE8
#define pinstCBreathWnd_x                                          0xE5FCEC
#define pinstCMapViewWnd_x                                         0xE5FCF0
#define pinstCMapToolbarWnd_x                                      0xE5FCF4
#define pinstCEditLabelWnd_x                                       0xE5FCF8
#define pinstCTargetWnd_x                                          0xE5FCFC
#define pinstCColorPickerWnd_x                                     0xE5FD00
#define pinstCPlayerWnd_x                                          0xE5FD04
#define pinstCOptionsWnd_x                                         0xE5FD08
#define pinstCBuffWindowNORMAL_x                                   0xE5FD0C
#define pinstCBuffWindowSHORT_x                                    0xE5FD10
#define pinstCharacterCreation_x                                   0xE5FD14
#define pinstCCursorAttachment_x                                   0xE5FD18
#define pinstCCastingWnd_x                                         0xE5FD1C
#define pinstCCastSpellWnd_x                                       0xE5FD20
#define pinstCSpellBookWnd_x                                       0xE5FD24
#define pinstCInventoryWnd_x                                       0xE5FD28
#define pinstCBankWnd_x                                            0xE5FD30
#define pinstCQuantityWnd_x                                        0xE5FD34
#define pinstCLootWnd_x                                            0xE5FD38
#define pinstCActionsWnd_x                                         0xE5FD3C
#define pinstCCombatAbilityWnd_x                                   0xE5FD44
#define pinstCMerchantWnd_x                                        0xE5FD48
#define pinstCTradeWnd_x                                           0xE5FD50
#define pinstCSelectorWnd_x                                        0xE5FD54
#define pinstCBazaarWnd_x                                          0xE5FD58
#define pinstCBazaarSearchWnd_x                                    0xE5FD5C
#define pinstCGiveWnd_x                                            0xE5FD78
#define pinstCTrackingWnd_x                                        0xE5FD80
#define pinstCInspectWnd_x                                         0xE5FD84
#define pinstCSocialEditWnd_x                                      0xE5FD88
#define pinstCFeedbackWnd_x                                        0xE5FD8C
#define pinstCBugReportWnd_x                                       0xE5FD90
#define pinstCVideoModesWnd_x                                      0xE5FD94
#define pinstCTextEntryWnd_x                                       0xE5FD9C
#define pinstCFileSelectionWnd_x                                   0xE5FDA0
#define pinstCCompassWnd_x                                         0xE5FDA4
#define pinstCPlayerNotesWnd_x                                     0xE5FDA8
#define pinstCGemsGameWnd_x                                        0xE5FDAC
#define pinstCTimeLeftWnd_x                                        0xE5FDB0
#define pinstCPetitionQWnd_x                                       0xE5FDCC
#define pinstCStoryWnd_x                                           0xE5FDD0
#define pinstCJournalTextWnd_x                                     0xE5FDD4
#define pinstCJournalCatWnd_x                                      0xE5FDD8
#define pinstCBodyTintWnd_x                                        0xE5FDDC
#define pinstCServerListWnd_x                                      0xE5FDE0
#define pinstCAvaZoneWnd_x                                         0xE5FDEC
#define pinstCBlockedBuffWnd_x                                     0xE5FDF0
#define pinstCBlockedPetBuffWnd_x                                  0xE5FDF4
#define pinstCInvSlotMgr_x                                         0xE5FE3C
#define pinstCContainerMgr_x                                       0xE5FE40
#define pinstCAdventureLeaderboardWnd_x                            0x10B2E78
#define pinstCAdventureRequestWnd_x                                0x10B2EF0
#define pinstCAltStorageWnd_x                                      0x10B31D0
#define pinstCAdventureStatsWnd_x                                  0x10B2F68
#define pinstCBarterMerchantWnd_x                                  0x10B3DB8
#define pinstCBarterSearchWnd_x                                    0x10B3E30
#define pinstCBarterWnd_x                                          0x10B3EA8
#define pinstCChatWindowManager_x                                  0x10B4538
#define pinstCDynamicZoneWnd_x                                     0x10B49E8
#define pinstCEQMainWnd_x                                          0x10B4B80
#define pinstCFellowshipWnd_x                                      0x10B497C
#define pinstCFindLocationWnd_x                                    0x10B4E50
#define pinstCGroupSearchWnd_x                                     0x10B5120
#define pinstCGroupWnd_x                                           0x10B5198
#define pinstCGuildBankWnd_x                                       0x10B5210
#define pinstCGuildMgmtWnd_x                                       0x10B7300
#define pinstCHotButtonWnd_x                                       0x10B73FC
#define pinstCHotButtonWnd1_x                                      0x10B73FC
#define pinstCHotButtonWnd2_x                                      0x10B7400
#define pinstCHotButtonWnd3_x                                      0x10B7404
#define pinstCHotButtonWnd4_x                                      0x10B7428
#define pinstCItemDisplayManager_x                                 0x10B7720
#define pinstCItemExpTransferWnd_x                                 0x10B779C
#define pinstCLFGuildWnd_x                                         0x10B7A78
#define pinstCMIZoneSelectWnd_x                                    0x10B8060
#define pinstCConfirmationDialog_x                                 0x10B8768
#define pinstCPopupWndManager_x                                    0x10B8768
#define pinstCProgressionSelectionWnd_x                            0x10B8858
#define pinstCPvPStatsWnd_x                                        0x10B8948
#define pinstCLargeDialogWnd_x                                     0x10B9050
#define pinstCTaskWnd_x                                            0x10BA3D0
#define pinstCTaskSomething_x                                      0xD2DEA0
#define pinstCTaskTemplateSelectWnd_x                              0x10BA358
#define pinstCTipWndOFDAY_x                                        0x10BA538
#define pinstCTipWndCONTEXT_x                                      0x10BA53C
#define pinstCTitleWnd_x                                           0x10BA5B8
#define pinstCContextMenuManager_x                                 0x171DFE4
#define pinstCVoiceMacroWnd_x                                      0xFA7000
#define pinstCHtmlWnd_x                                            0xFA70F0
#define pinstIconCache_x                                           0x10B4B54
#define pinstCTradeskillWnd_x                                      0x10BA6B8
#define pinstCAdvancedLootWnd_x                                    0xE5FE30
#define pinstRewardSelectionWnd_x                                  0x10B8E70
#define pinstEQSuiteTextureLoader_x                                0xD0B458

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x541AD0
#define __CastRay2_x                                               0x541400
#define __HeadingDiff_x                                            0x9276B0
#define __FixHeading_x                                             0x927640
#define __get_bearing_x                                            0x5314E0
#define __ConvertItemTags_x                                        0x52F160
#define __ExecuteCmd_x                                             0x519A90
#define __EQGetTime_x                                              0x8984B0
#define __get_melee_range_x                                        0x5206E0
#define __GetGaugeValueFromEQ_x                                    0x7A8D30
#define __GetLabelFromEQ_x                                         0x7AA100
#define __ToggleKeyRingItem_x                                      0x4889C0
#define __GetXTargetType_x                                         0x9292B0
#define __LoadFrontEnd_x                                           0x6378F0
#define __NewUIINI_x                                               0x7A8700
#define __ProcessGameEvents_x                                      0x57B740
#define __ProcessMouseEvent_x                                      0x57AEE0
#define CrashDetected_x                                            0x6392B0
#define wwsCrashReportCheckForUploader_x                           0x7F6D80
#define __AppCrashWrapper_x                                        0xC57704
#define __pCrashHandler_x                                          0x10C7568
#define __CrashHandler_x                                           0x7F67E0
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F8F80
#define DrawNetStatus_x                                            0x5B1EB0
#define Util__FastTime_x                                           0x898150
#define Expansion_HoT_x                                            0xF21A70
#define __HelpPath_x                                               0xFA5188
#define __STMLToText_x                                             0x8DE640

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4230C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DDD0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DBA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D0EA0
#define AltAdvManager__IsAbilityReady_x                            0x4D0F10
#define AltAdvManager__GetAAById_x                                 0x4D1400
#define AltAdvManager__CanTrainAbility_x                           0x4D2030
#define AltAdvManager__CanSeeAbility_x                             0x4D1BF0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46A0D0
#define CharacterZoneClient__HasSkill_x                            0x466F80
#define CharacterZoneClient__MakeMeVisible_x                       0x46B660
#define CharacterZoneClient__IsStackBlocked_x                      0x44B6F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44ABB0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464F00
#define CharacterZoneClient__GetItemCountInInventory_x             0x464FE0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4650C0
#define CharacterZoneClient__FindAffectSlot_x                      0x450C40
#define CharacterZoneClient__BardCastBard_x                        0x44A330
#define CharacterZoneClient__GetMaxEffects_x                       0x449070
#define CharacterZoneClient__GetEffect_x                           0x44ADE0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x450AA0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449210
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44F5F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x667300

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6754A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x590FB0
#define CButtonWnd__CButtonWnd_x                                   0x8D29B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x690600
#define CChatManager__InitContextMenu_x                            0x691750
#define CChatManager__FreeChatWindow_x                             0x690090
#define CChatManager__GetLockedActiveChatWindow_x                  0x6997B0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6905D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DC990
#define CContextMenu__dCContextMenu_x                              0x8DCBA0
#define CContextMenu__AddMenuItem_x                                0x8DD0C0
#define CContextMenu__RemoveMenuItem_x                             0x8DCD20
#define CContextMenu__RemoveAllMenuItems_x                         0x8DCD40
#define CContextMenu__CheckMenuItem_x                              0x8DCDC0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8C8F30
#define CContextMenuManager__RemoveMenu_x                          0x8C92D0
#define CContextMenuManager__PopupMenu_x                           0x8C9720
#define CContextMenuManager__Flush_x                               0x8C8FA0
#define CContextMenuManager__GetMenu_x                             0x419490

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87C7D0
#define CChatService__GetFriendName_x                              0x87C7E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x697310
#define CChatWindow__Clear_x                                       0x696C00
#define CChatWindow__WndNotification_x                             0x697C10

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CCD80
#define CComboWnd__Draw_x                                          0x8CCF90
#define CComboWnd__GetCurChoice_x                                  0x8CCB30
#define CComboWnd__GetListRect_x                                   0x8CD230
#define CComboWnd__GetTextRect_x                                   0x8CCDF0
#define CComboWnd__InsertChoice_x                                  0x8CD2A0
#define CComboWnd__SetColors_x                                     0x8CCAC0
#define CComboWnd__SetChoice_x                                     0x8CCAF0
#define CComboWnd__GetItemCount_x                                  0x8CCB20
#define CComboWnd__GetCurChoiceText_x                              0x8CCB70

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A14A0
#define CContainerWnd__vftable_x                                   0xADE028

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BEC30
#define CDisplay__GetClickedActor_x                                0x4B7520
#define CDisplay__GetUserDefinedColor_x                            0x4B6100
#define CDisplay__GetWorldFilePath_x                               0x4B5550
#define CDisplay__is3dON_x                                         0x4B49E0
#define CDisplay__ReloadUI_x                                       0x4C8B90
#define CDisplay__WriteTextHD2_x                                   0x4BAFF0
#define CDisplay__TrueDistance_x                                   0x4B8150

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F2F70

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E0EF0
#define CEditWnd__GetCharIndexPt_x                                 0x8E1F90
#define CEditWnd__GetDisplayString_x                               0x8E10A0
#define CEditWnd__GetHorzOffset_x                                  0x8E13E0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E1A50
#define CEditWnd__GetSelStartPt_x                                  0x8E2250
#define CEditWnd__GetSTMLSafeText_x                                0x8E1580
#define CEditWnd__PointFromPrintableChar_x                         0x8E1B40
#define CEditWnd__SelectableCharFromPoint_x                        0x8E1CC0
#define CEditWnd__SetEditable_x                                    0x8E1550

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x561D20
#define CEverQuest__ClickedPlayer_x                                0x55B8F0
#define CEverQuest__CreateTargetIndicator_x                        0x55C7F0
#define CEverQuest__DeleteTargetIndicator_x                        0x55C870
#define CEverQuest__DoTellWindow_x                                 0x4762A0
#define CEverQuest__OutputTextToLog_x                              0x475F00
#define CEverQuest__DropHeldItemOnGround_x                         0x572290
#define CEverQuest__dsp_chat_x                                     0x4765E0
#define CEverQuest__trimName_x                                     0x558200
#define CEverQuest__Emote_x                                        0x5705A0
#define CEverQuest__EnterZone_x                                    0x56B680
#define CEverQuest__GetBodyTypeDesc_x                              0x555C40
#define CEverQuest__GetClassDesc_x                                 0x55F140
#define CEverQuest__GetClassThreeLetterCode_x                      0x55F740
#define CEverQuest__GetDeityDesc_x                                 0x556520
#define CEverQuest__GetLangDesc_x                                  0x555FD0
#define CEverQuest__GetRaceDesc_x                                  0x55F900
#define CEverQuest__InterpretCmd_x                                 0x5634A0
#define CEverQuest__LeftClickedOnPlayer_x                          0x577DF0
#define CEverQuest__LMouseUp_x                                     0x579F00
#define CEverQuest__RightClickedOnPlayer_x                         0x578900
#define CEverQuest__RMouseUp_x                                     0x579960
#define CEverQuest__SetGameState_x                                 0x55C1C0
#define CEverQuest__UPCNotificationFlush_x                         0x5545D0
#define CEverQuest__IssuePetCommand_x                              0x563E80

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B2140
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B21A0
#define CGaugeWnd__Draw_x                                          0x6B25D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43AFC0
#define CGuild__GetGuildName_x                                     0x43B490
#define CGuild__GetGuildIndex_x                                    0x43C6A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CE650

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DB8B0
#define CInvSlotMgr__MoveItem_x                                    0x6DC760
#define CInvSlotMgr__SelectSlot_x                                  0x6DB960

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DAD60
#define CInvSlot__SliderComplete_x                                 0x6D84F0
#define CInvSlot__GetItemBase_x                                    0x6D7970
#define CInvSlot__UpdateItem_x                                     0x6D7EF0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DDBC0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6DECE0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A4730
#define CItemDisplayWnd__UpdateStrings_x                           0x6DFDD0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6EC850
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6ECD60
#define CItemDisplayWnd__SetItem_x                                 0x6F25E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7DBD90

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6E6380

// CLabel 
#define CLabel__Draw_x                                             0x6F9250

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B8A20
#define CListWnd__dCListWnd_x                                      0x8B9C50
#define CListWnd__AddColumn_x                                      0x8B9BF0
#define CListWnd__AddColumn1_x                                     0x8B9280
#define CListWnd__AddLine_x                                        0x8B8CE0
#define CListWnd__AddString_x                                      0x8B8F00
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B5CB0
#define CListWnd__CalculateVSBRange_x                              0x8B7EF0
#define CListWnd__ClearSel_x                                       0x8B4FC0
#define CListWnd__ClearAllSel_x                                    0x8B4F70
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B88B0
#define CListWnd__Compare_x                                        0x8B6820
#define CListWnd__Draw_x                                           0x8B7AF0
#define CListWnd__DrawColumnSeparators_x                           0x8B7980
#define CListWnd__DrawHeader_x                                     0x8B5280
#define CListWnd__DrawItem_x                                       0x8B6EB0
#define CListWnd__DrawLine_x                                       0x8B7620
#define CListWnd__DrawSeparator_x                                  0x8B7A20
#define CListWnd__EnableLine_x                                     0x8B51A0
#define CListWnd__EnsureVisible_x                                  0x8B5E10
#define CListWnd__ExtendSel_x                                      0x8B6DC0
#define CListWnd__GetColumnMinWidth_x                              0x8B4970
#define CListWnd__GetColumnWidth_x                                 0x8B48A0
#define CListWnd__GetCurSel_x                                      0x8B4080
#define CListWnd__GetItemAtPoint_x                                 0x8B60B0
#define CListWnd__GetItemAtPoint1_x                                0x8B6120
#define CListWnd__GetItemData_x                                    0x8B43C0
#define CListWnd__GetItemHeight_x                                  0x8B5900
#define CListWnd__GetItemIcon_x                                    0x8B45B0
#define CListWnd__GetItemRect_x                                    0x8B5EF0
#define CListWnd__GetItemText_x                                    0x8B4460
#define CListWnd__GetSelList_x                                     0x8B9170
#define CListWnd__GetSeparatorRect_x                               0x8B6740
#define CListWnd__InsertLine_x                                     0x8B90E0
#define CListWnd__RemoveLine_x                                     0x8B90F0
#define CListWnd__SetColors_x                                      0x8B41D0
#define CListWnd__SetColumnJustification_x                         0x8B4C00
#define CListWnd__SetColumnWidth_x                                 0x8B4920
#define CListWnd__SetCurSel_x                                      0x8B40C0
#define CListWnd__SetItemColor_x                                   0x8B85A0
#define CListWnd__SetItemData_x                                    0x8B5020
#define CListWnd__SetItemText_x                                    0x8B83E0
#define CListWnd__ShiftColumnSeparator_x                           0x8B8270
#define CListWnd__Sort_x                                           0x8B9D50
#define CListWnd__ToggleSel_x                                      0x8B4EF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x712360

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x733820
#define CMerchantWnd__RequestBuyItem_x                             0x73A8E0
#define CMerchantWnd__RequestSellItem_x                            0x73B3B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x733AD0
#define CMerchantWnd__SelectBuySellSlot_x                          0x732CD0
#define CMerchantWnd__ActualSelect_x                               0x737790

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84AB10
#define CPacketScrambler__hton_x                                   0x84AB20

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D7900
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D79E0
#define CSidlManager__CreateLabel_x                                0x79BD10
#define CSidlManager__CreateXWndFromTemplate_x                     0x8D5EB0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D7CC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8CEE10
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8CED10
#define CSidlScreenWnd__ConvertToRes_x                             0x8F2E50
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CF720
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D08F0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D09A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CFE70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CF0D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CE840
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CF2C0
#define CSidlScreenWnd__Init1_x                                    0x8D05C0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CF7D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CEA00
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D00B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CE4A0
#define CSidlScreenWnd__StoreIniVis_x                              0x8CE7F0
#define CSidlScreenWnd__WndNotification_x                          0x8D0340
#define CSidlScreenWnd__GetChildItem_x                             0x8CE910
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C21A0
#define CSidlScreenWnd__m_layoutCopy_x                             0x171E048

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FD310
#define CSkillMgr__GetSkillCap_x                                   0x5FD4F0
#define CSkillMgr__GetNameToken_x                                  0x5FCEC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F2110
#define CSliderWnd__SetValue_x                                     0x8F22E0
#define CSliderWnd__SetNumTicks_x                                  0x8F2A60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A2390

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EC600
#define CStmlWnd__CalculateHSBRange_x                              0x8E4CF0
#define CStmlWnd__CalculateVSBRange_x                              0x8E4C60
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E4E70
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E5670
#define CStmlWnd__ForceParseNow_x                                  0x8ECF80
#define CStmlWnd__GetNextTagPiece_x                                0x8E5570
#define CStmlWnd__GetSTMLText_x                                    0x483F50
#define CStmlWnd__GetVisibleText_x                                 0x8E60C0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E8520
#define CStmlWnd__MakeStmlColorTag_x                               0x8E3F40
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E3FA0
#define CStmlWnd__SetSTMLText_x                                    0x8E9D70
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EC2A0
#define CStmlWnd__UpdateHistoryString_x                            0x8E7000

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F0490
#define CTabWnd__DrawCurrentPage_x                                 0x8EFD20
#define CTabWnd__DrawTab_x                                         0x8EFAE0
#define CTabWnd__GetCurrentPage_x                                  0x8F00D0
#define CTabWnd__GetPageInnerRect_x                                0x8EF7D0
#define CTabWnd__GetTabInnerRect_x                                 0x8EF9D0
#define CTabWnd__GetTabRect_x                                      0x8EF8A0
#define CTabWnd__InsertPage_x                                      0x8F0780
#define CTabWnd__SetPage_x                                         0x8F0100
#define CTabWnd__SetPageRect_x                                     0x8F03D0
#define CTabWnd__UpdatePage_x                                      0x8F0720
#define CTabWnd__GetPageFromTabIndex_x                             0x8EFA30
#define CTabWnd__GetCurrentTabIndex_x                              0x8EF760

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6DEE90
#define CPageWnd__SetTabText_x                                     0x8FBE50

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436B40

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CC730
#define CTextureFont__GetTextExtent_x                              0x8CC490

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x635B90

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F8290

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B20D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59E6F0
#define CXStr__CXStr1_x                                            0x403720
#define CXStr__CXStr3_x                                            0x8953E0
#define CXStr__dCXStr_x                                            0x59EAD0
#define CXStr__operator_equal_x                                    0x895550
#define CXStr__operator_equal1_x                                   0x8955A0
#define CXStr__operator_plus_equal1_x                              0x8966A0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C13B0
#define CXWnd__Center_x                                            0x8C7560
#define CXWnd__ClrFocus_x                                          0x8C0F80
#define CXWnd__Destroy_x                                           0x8C8030
#define CXWnd__DoAllDrawing_x                                      0x8C71B0
#define CXWnd__DrawChildren_x                                      0x8C7350
#define CXWnd__DrawColoredRect_x                                   0x8C17A0
#define CXWnd__DrawTooltip_x                                       0x8C1A50
#define CXWnd__DrawTooltipAtPoint_x                                0x8C6110
#define CXWnd__GetBorderFrame_x                                    0x8C1EB0
#define CXWnd__GetChildWndAt_x                                     0x8C7F20
#define CXWnd__GetClientClipRect_x                                 0x8C1C70
#define CXWnd__GetScreenClipRect_x                                 0x8C6810
#define CXWnd__GetScreenRect_x                                     0x8C2050
#define CXWnd__GetTooltipRect_x                                    0x8C18E0
#define CXWnd__GetWindowTextA_x                                    0x427190
#define CXWnd__IsActive_x                                          0x8BC9C0
#define CXWnd__IsDescendantOf_x                                    0x8C1E00
#define CXWnd__IsReallyVisible_x                                   0x8C5120
#define CXWnd__IsType_x                                            0x8C75D0
#define CScreenPieceTemplate__IsType_x                             0x8F4AF0
#define CXWnd__Move_x                                              0x8C4850
#define CXWnd__Move1_x                                             0x8C6E60
#define CXWnd__ProcessTransition_x                                 0x8C1350
#define CXWnd__Refade_x                                            0x8C1120
#define CXWnd__Resize_x                                            0x8C2110
#define CXWnd__Right_x                                             0x8C6610
#define CXWnd__SetFocus_x                                          0x8C39B0
#define CXWnd__SetFont_x                                           0x8C0FD0
#define CXWnd__SetKeyTooltip_x                                     0x8C2370
#define CXWnd__SetMouseOver_x                                      0x8C6B50
#define CXWnd__StartFade_x                                         0x8C1400
#define CXWnd__GetChildItem_x                                      0x8C6A90
#define CXWnd__SetParent_x                                         0x8C7ED0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BE240
#define CXWndManager__DrawWindows_x                                0x8BDE80
#define CXWndManager__GetKeyboardFlags_x                           0x8BC530
#define CXWndManager__HandleKeyboardMsg_x                          0x8BCE50
#define CXWndManager__RemoveWnd_x                                  0x8BCB50

// CDBStr
#define CDBStr__GetString_x                                        0x4B3210

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x451C40
#define EQ_Character__Cur_HP_x                                     0x466580
#define EQ_Character__Cur_Mana_x                                   0x45A330
#define EQ_Character__GetAACastingTimeModifier_x                   0x44AEC0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443230
#define EQ_Character__GetFocusRangeModifier_x                      0x443290
#define EQ_Character__GetHPRegen_x                                 0x469760
#define EQ_Character__GetEnduranceRegen_x                          0x465B90
#define EQ_Character__GetManaRegen_x                               0x469D00
#define EQ_Character__Max_Endurance_x                              0x5C38F0
#define EQ_Character__Max_HP_x                                     0x45CEB0
#define EQ_Character__Max_Mana_x                                   0x5C3720
#define EQ_Character__doCombatAbility_x                            0x5C0DF0
#define EQ_Character__UseSkill_x                                   0x4706F0
#define EQ_Character__GetConLevel_x                                0x5B64E0
#define EQ_Character__IsExpansionFlag_x                            0x4266C0
#define EQ_Character__TotalEffect_x                                0x44EF70
#define EQ_Character__GetPCSpellAffect_x                           0x44B2C0
#define EQ_Character__SpellDuration_x                              0x449260
#define EQ_Character__FindItemByRecord_x                           0x463BF0
#define EQ_Character__GetAdjustedSkill_x                           0x466D30
#define EQ_Character__GetBaseSkill_x                               0x45CD90

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8688E0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5CB9A0

//PcClient
#define PcClient__PcClient_x                                       0x5B8320

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446550
#define CCharacterSelect__EnterWorld_x                             0x445D20
#define CCharacterSelect__Quit_x                                   0x444910

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5969A0
#define EQ_Item__CreateItemTagString_x                             0x849450
#define EQ_Item__IsStackable_x                                     0x83EBE0
#define EQ_Item__GetImageNum_x                                     0x8415F0
#define EQ_Item__CreateItemClient_x                                0x597580
#define EQ_Item__GetItemValue_x                                    0x8481A0
#define EQ_Item__ValueSellMerchant_x                               0x84A770
#define EQ_Item__IsKeyRingItem_x                                   0x83F640
#define EQ_Item__CanGoInBag_x                                      0x596B30
#define EQ_Item__GetMaxItemCount_x                                 0x83EAD0
#define EQ_Item__GetHeldItem_x                                     0x840430
#define EQ_Item__GetAugmentFitBySlot_x                             0x84A590

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D34A0
#define EQ_LoadingS__Array_x                                       0xBF9A78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C5E10
#define EQ_PC__GetAlternateAbilityId_x                             0x852C70
#define EQ_PC__GetCombatAbility_x                                  0x852D00
#define EQ_PC__GetCombatAbilityTimer_x                             0x84D7C0
#define EQ_PC__GetItemRecastTimer_x                                0x5BF5A0
#define EQ_PC__HasLoreItem_x                                       0x5B9AE0
#define EQ_PC__AlertInventoryChanged_x                             0x5B64B0
#define EQ_PC__GetPcZoneClient_x                                   0x5DFEC0
#define EQ_PC__RemoveMyAffect_x                                    0x5BEA70
#define EQ_PC__GetKeyRingItems_x                                   0x84DBE0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x860950
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x854BE0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x51E780
#define EQItemList__add_object_x                                   0x54B620
#define EQItemList__add_item_x                                     0x51E6C0
#define EQItemList__delete_item_x                                  0x51EB70
#define EQItemList__FreeItemList_x                                 0x51EA70

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B24E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CB740
#define EQPlayer__dEQPlayer_x                                      0x5D3D80
#define EQPlayer__DoAttack_x                                       0x5E5840
#define EQPlayer__EQPlayer_x                                       0x5D64A0
#define EQPlayer__SetNameSpriteState_x                             0x5D0C40
#define EQPlayer__SetNameSpriteTint_x                              0x5CCB60
#define PlayerBase__HasProperty_j_x                                0x925A70
#define EQPlayer__IsTargetable_x                                   0x925D10
#define EQPlayer__CanSee_x                                         0x926270
#define PlayerZoneClient__ChangeHeight_x                           0x5E5700
#define EQPlayer__CanSee1_x                                        0x926360
#define PlayerBase__GetVisibilityLineSegment_x                     0x926000

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E0070

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5DA510
#define EQPlayerManager__GetSpawnByName_x                          0x5DA970
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5DA540

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59CA80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59CAC0
#define KeypressHandler__ClearCommandStateArray_x                  0x59C670
#define KeypressHandler__HandleKeyDown_x                           0x59AFD0
#define KeypressHandler__HandleKeyUp_x                             0x59B2F0
#define KeypressHandler__SaveKeymapping_x                          0x59C740

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70ACF0
#define MapViewMap__SaveEx_x                                       0x70E020

#define PlayerPointManager__GetAltCurrency_x                       0x8669A0

// StringTable 
#define StringTable__getString_x                                   0x860C80

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C3380
#define PcZoneClient__RemovePetEffect_x                            0x5BFA70
#define PcZoneClient__HasAlternateAbility_x                        0x5C0410
#define PcZoneClient__GetCurrentMod_x                              0x45C360
#define PcZoneClient__GetModCap_x                                  0x459A90
#define PcZoneClient__CanEquipItem_x                               0x5C0930
#define PcZoneClient__GetItemByID_x                                0x5C5180
#define PcZoneClient__GetItemByItemClass_x                         0x5C5D30

//Doors
#define EQSwitch__UseSwitch_x                                      0x552F10

//IconCache
#define IconCache__GetIcon_x                                       0x6A7920

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69E830
#define CContainerMgr__CloseContainer_x                            0x69F050

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76BB80

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58F9E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4ED6C0
#define EQ_Spell__SpellAffects_x                                   0x4EAD60
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4EADD0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B150
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A390
#define CLootWnd__LootAll_x                                        0x700600
#define CLootWnd__RequestLootSlot_x                                0x700E10
#define EQ_Spell__IsStackable_x                                    0x448E10
#define EQ_Spell__GetSpellAffectBySlot_x                           0x448EC0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EA90
#define EQ_Spell__IsSPAStacking_x                                  0x4EA910
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4EA3E0
#define EQ_Spell__IsNoRemove_x                                     0x434B70
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4EA930

#define __IsResEffectSpell_x                                       0x448F60

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x872580

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B1730
#define CTargetWnd__WndNotification_x                              0x7B1220
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B1910

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B6810

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E6330
#define EqSoundManager__PlayScriptMp3_x                            0x4E7DD0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A15C0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E0520
#define CSidlManager__FindAnimation1_x                             0x8D58E0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4DACD0
#define CAltAbilityData__GetMercMaxRank_x                          0x4DAC80
#define CAltAbilityData__GetMaxRank_x                              0x4CF550

//CTargetRing
#define CTargetRing__Cast_x                                        0x58D290

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x458AC0
#define CharacterBase__CreateItemGlobalIndex_x                     0x475470
#define CharacterBase__CreateItemIndex_x                           0x517D40
#define CharacterBase__GetItemPossession_x                         0x443DB0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8763E0
#define CharacterBase__GetEffectId_x                               0x458A80

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x687820
#define CCastSpellWnd__IsBardSongPlaying_x                         0x686F80

//messages
#define msg_spell_worn_off_x                                       0x4F5210
#define msg_new_text_x                                             0x4FE860
#define msgTokenTextParam_x                                        0x4FB0A0

//SpellManager
#define SpellManager__vftable_x                                    0xABA160
#define SpellManager__SpellManager_x                               0x47E0B0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x6041A0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x929DD0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F1810
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43E9B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x448BB0
#define ItemGlobalIndex__IsValidIndex_x                            0x458330

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x874250
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x873190

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F94A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6A3560
#define CCursorAttachment__Deactivate_x                            0x6A2AB0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8F1610
