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
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "May 11 2017"
#define __ExpectedVersionTime                                     "10:25:37"
#define __ActualVersionDate_x                                      0xAD4290
#define __ActualVersionTime_x                                      0xAD429C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5A2790
#define __MemChecker1_x                                            0x898510
#define __MemChecker2_x                                            0x6386B0
#define __MemChecker3_x                                            0x638600
#define __MemChecker4_x                                            0x7EACE0
#define __EncryptPad0_x                                            0xC2E328
#define __EncryptPad1_x                                            0xD096E0
#define __EncryptPad2_x                                            0xC57B10
#define __EncryptPad3_x                                            0xC57710
#define __EncryptPad4_x                                            0xCF7CE0
#define __EncryptPad5_x                                            0x10B2370
#define __AC1_x                                                    0x7AA185
#define __AC2_x                                                    0x55C537
#define __AC3_x                                                    0x55A6B0
#define __AC4_x                                                    0x56C791
#define __AC5_x                                                    0x57F84B
#define __AC6_x                                                    0x5833FE
#define __AC7_x                                                    0x579E4C
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
#define __do_loot_x                                                0x52B1C0
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
#define __SubscriptionType_x                                       0x10E5D94
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
#define pinstCamActor_x                                            0xE5FE4C
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
#define pinstViewActor_x                                           0xE5FE48
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
#define pinstCRealEstateItemsWnd_x                                 0xE5FD64
#define pinstCAchievementsWnd_x                                    0xE5FDC0
#define pinstCTextOverlay_x                                        0xD1D288
#define pinstCAudioTriggersWindow_x                                0xD1D118
#define pinstCCharacterSelect_x                                    0xE5FCD4
#define pinstCFacePick_x                                           0xE5FA84
#define pinstCNoteWnd_x                                            0xE5FC8C
#define pinstCBookWnd_x                                            0xE5FC94
#define pinstCPetInfoWnd_x                                         0xE5FC98
#define pinstCTrainWnd_x                                           0xE5FC9C
#define pinstCSkillsWnd_x                                          0xE5FCA0
#define pinstCSkillsSelectWnd_x                                    0xE5FCA4
#define pinstCCombatSkillsSelectWnd_x                              0xE5FCA8
#define pinstCFriendsWnd_x                                         0xE5FCAC
#define pinstCAuraWnd_x                                            0xE5FCB0
#define pinstCRespawnWnd_x                                         0xE5FCB4
#define pinstCBandolierWnd_x                                       0xE5FCB8
#define pinstCPotionBeltWnd_x                                      0xE5FCBC
#define pinstCAAWnd_x                                              0xE5FCC0
#define pinstCAlarmWnd_x                                           0xE5FCCC
#define pinstCGroupSearchFiltersWnd_x                              0xE5FCC4
#define pinstCLoadskinWnd_x                                        0xE5FCC8
#define pinstCLargeDialogWnd_x                                     0x10B9050
#define pinstCMusicPlayerWnd_x                                     0xE5FCD0
#define pinstCMailWnd_x                                            0xE5FCD8
#define pinstCMailCompositionWnd_x                                 0xE5FCDC
#define pinstCMailAddressBookWnd_x                                 0xE5FCE0
#define pinstCRaidWnd_x                                            0xE5FCE8
#define pinstCRaidOptionsWnd_x                                     0xE5FCEC
#define pinstCBreathWnd_x                                          0xE5FCF0
#define pinstCMapViewWnd_x                                         0xE5FCF4
#define pinstCMapToolbarWnd_x                                      0xE5FCF8
#define pinstCEditLabelWnd_x                                       0xE5FCFC
#define pinstCTargetWnd_x                                          0xE5FD00
#define pinstCColorPickerWnd_x                                     0xE5FD04
#define pinstCPlayerWnd_x                                          0xE5FD08
#define pinstCOptionsWnd_x                                         0xE5FD0C
#define pinstCBuffWindowNORMAL_x                                   0xE5FD10
#define pinstCBuffWindowSHORT_x                                    0xE5FD14
#define pinstCharacterCreation_x                                   0xE5FD18
#define pinstCCursorAttachment_x                                   0xE5FD1C
#define pinstCCastingWnd_x                                         0xE5FD20
#define pinstCCastSpellWnd_x                                       0xE5FD24
#define pinstCSpellBookWnd_x                                       0xE5FD28
#define pinstCInventoryWnd_x                                       0xE5FD2C
#define pinstCBankWnd_x                                            0xE5FD34
#define pinstCQuantityWnd_x                                        0xE5FD38
#define pinstCLootWnd_x                                            0xE5FD3C
#define pinstCActionsWnd_x                                         0xE5FD40
#define pinstCCombatAbilityWnd_x                                   0xE5FD48
#define pinstCMerchantWnd_x                                        0xE5FD4C
#define pinstCTradeWnd_x                                           0xE5FD54
#define pinstCSelectorWnd_x                                        0xE5FD58
#define pinstCBazaarWnd_x                                          0xE5FD5C
#define pinstCBazaarSearchWnd_x                                    0xE5FD60
#define pinstCGiveWnd_x                                            0xE5FD7C
#define pinstCTrackingWnd_x                                        0xE5FD84
#define pinstCInspectWnd_x                                         0xE5FD88
#define pinstCSocialEditWnd_x                                      0xE5FD8C
#define pinstCFeedbackWnd_x                                        0xE5FD90
#define pinstCBugReportWnd_x                                       0xE5FD94
#define pinstCVideoModesWnd_x                                      0xE5FD98
#define pinstCTextEntryWnd_x                                       0xE5FDA0
#define pinstCFileSelectionWnd_x                                   0xE5FDA4
#define pinstCCompassWnd_x                                         0xE5FDA8
#define pinstCPlayerNotesWnd_x                                     0xE5FDAC
#define pinstCGemsGameWnd_x                                        0xE5FDB0
#define pinstCTimeLeftWnd_x                                        0xE5FDB4
#define pinstCPetitionQWnd_x                                       0xE5FDD0
#define pinstCStoryWnd_x                                           0xE5FDD4
#define pinstCJournalTextWnd_x                                     0xE5FDD8
#define pinstCJournalCatWnd_x                                      0xE5FDDC
#define pinstCBodyTintWnd_x                                        0xE5FDE0
#define pinstCServerListWnd_x                                      0xE5FDE4
#define pinstCAvaZoneWnd_x                                         0xE5FDF0
#define pinstCBlockedBuffWnd_x                                     0xE5FDF4
#define pinstCBlockedPetBuffWnd_x                                  0xE5FDF8
#define pinstCInvSlotMgr_x                                         0xE5FE40
#define pinstCContainerMgr_x                                       0xE5FE44
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
#define pinstCAdvancedLootWnd_x                                    0xE5FE34
#define pinstRewardSelectionWnd_x                                  0x10B8E70
#define pinstEQSuiteTextureLoader_x                                0xD0B458

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x542360
#define __ConvertItemTags_x                                        0x52FCC0
#define __ExecuteCmd_x                                             0x51A810
#define __EQGetTime_x                                              0x897EB0
#define __get_melee_range_x                                        0x521490
#define __GetGaugeValueFromEQ_x                                    0x7A8D40
#define __GetLabelFromEQ_x                                         0x7AA110
#define __ToggleKeyRingItem_x                                      0x488850
#define __GetXTargetType_x                                         0x928AC0
#define __LoadFrontEnd_x                                           0x637D80
#define __NewUIINI_x                                               0x7A8710
#define __ProcessGameEvents_x                                      0x57BBE0
#define __ProcessMouseEvent_x                                      0x57B380
#define CrashDetected_x                                            0x639740
#define wwsCrashReportCheckForUploader_x                           0x7F6B70
#define __AppCrashWrapper_x                                        0xC57704
#define __pCrashHandler_x                                          0x10C7568
#define __CrashHandler_x                                           0x7F6600
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F8DA0
#define DrawNetStatus_x                                            0x5B2460
#define Util__FastTime_x                                           0x897B50
#define Expansion_HoT_x                                            0xF21A70
#define __HelpPath_x                                               0xFA5188
#define __STMLToText_x                                             0x8DDFD0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4230C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DE60
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DC40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D07C0
#define AltAdvManager__IsAbilityReady_x                            0x4D0830
#define AltAdvManager__GetAAById_x                                 0x4D0D20
#define AltAdvManager__CanTrainAbility_x                           0x4D1950
#define AltAdvManager__CanSeeAbility_x                             0x4D1510

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x469D60
#define CharacterZoneClient__HasSkill_x                            0x466C10
#define CharacterZoneClient__MakeMeVisible_x                       0x46B2F0
#define CharacterZoneClient__IsStackBlocked_x                      0x44B330
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44A7F0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464B90
#define CharacterZoneClient__GetItemCountInInventory_x             0x464C70
#define CharacterZoneClient__GetCursorItemCount_x                  0x464D50
#define CharacterZoneClient__FindAffectSlot_x                      0x450880
#define CharacterZoneClient__BardCastBard_x                        0x449F70
#define CharacterZoneClient__GetMaxEffects_x                       0x448CB0
#define CharacterZoneClient__GetEffect_x                           0x44AA20
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4506E0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x448E50
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44F230

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x667570

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x675890

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x591470
#define CButtonWnd__CButtonWnd_x                                   0x8D2360

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x690A80
#define CChatManager__InitContextMenu_x                            0x691BD0
#define CChatManager__FreeChatWindow_x                             0x690510
#define CChatManager__GetLockedActiveChatWindow_x                  0x699C80
#define CChatManager__SetLockedActiveChatWindow_x                  0x690A50

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DC340
#define CContextMenu__dCContextMenu_x                              0x8DC550
#define CContextMenu__AddMenuItem_x                                0x8DC560
#define CContextMenu__RemoveMenuItem_x                             0x8DC840
#define CContextMenu__RemoveAllMenuItems_x                         0x8DC860
#define CContextMenu__CheckMenuItem_x                              0x8DC8E0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8C8870
#define CContextMenuManager__RemoveMenu_x                          0x8C8C20
#define CContextMenuManager__PopupMenu_x                           0x8C9070
#define CContextMenuManager__Flush_x                               0x8C88E0
#define CContextMenuManager__GetMenu_x                             0x419530

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87C1F0
#define CChatService__GetFriendName_x                              0x87C200

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6977C0
#define CChatWindow__Clear_x                                       0x6970B0
#define CChatWindow__WndNotification_x                             0x6980D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CC6F0
#define CComboWnd__Draw_x                                          0x8CC900
#define CComboWnd__GetCurChoice_x                                  0x8CC4A0
#define CComboWnd__GetListRect_x                                   0x8CCBA0
#define CComboWnd__GetTextRect_x                                   0x8CC760
#define CComboWnd__InsertChoice_x                                  0x8CCC10
#define CComboWnd__SetColors_x                                     0x8CC430
#define CComboWnd__SetChoice_x                                     0x8CC460
#define CComboWnd__GetItemCount_x                                  0x8CC490
#define CComboWnd__GetCurChoiceText_x                              0x8CC4E0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A19C0
#define CContainerWnd__vftable_x                                   0xADDE98

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BEB50
#define CDisplay__GetClickedActor_x                                0x4B7470
#define CDisplay__GetUserDefinedColor_x                            0x4B6050
#define CDisplay__GetWorldFilePath_x                               0x4B54A0
#define CDisplay__is3dON_x                                         0x4B4930
#define CDisplay__ReloadUI_x                                       0x4CA120
#define CDisplay__WriteTextHD2_x                                   0x4BAF10
#define CDisplay__TrueDistance_x                                   0x4B80A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F28F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E0880
#define CEditWnd__GetCharIndexPt_x                                 0x8E1900
#define CEditWnd__GetDisplayString_x                               0x8E0A30
#define CEditWnd__GetHorzOffset_x                                  0x8E0D70
#define CEditWnd__GetLineForPrintableChar_x                        0x8E13D0
#define CEditWnd__GetSelStartPt_x                                  0x8E1BB0
#define CEditWnd__GetSTMLSafeText_x                                0x8E0F00
#define CEditWnd__PointFromPrintableChar_x                         0x8E14C0
#define CEditWnd__SelectableCharFromPoint_x                        0x8E1640
#define CEditWnd__SetEditable_x                                    0x8E0ED0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x562FC0
#define CEverQuest__ClickedPlayer_x                                0x55CC80
#define CEverQuest__CreateTargetIndicator_x                        0x55DB70
#define CEverQuest__DeleteTargetIndicator_x                        0x55DBF0
#define CEverQuest__DoTellWindow_x                                 0x475E80
#define CEverQuest__OutputTextToLog_x                              0x475AE0
#define CEverQuest__DropHeldItemOnGround_x                         0x573460
#define CEverQuest__dsp_chat_x                                     0x4761C0
#define CEverQuest__trimName_x                                     0x5595B0
#define CEverQuest__Emote_x                                        0x5717B0
#define CEverQuest__EnterZone_x                                    0x56C920
#define CEverQuest__GetBodyTypeDesc_x                              0x557010
#define CEverQuest__GetClassDesc_x                                 0x560400
#define CEverQuest__GetClassThreeLetterCode_x                      0x560A00
#define CEverQuest__GetDeityDesc_x                                 0x5578F0
#define CEverQuest__GetLangDesc_x                                  0x5573A0
#define CEverQuest__GetRaceDesc_x                                  0x560BC0
#define CEverQuest__InterpretCmd_x                                 0x564740
#define CEverQuest__LeftClickedOnPlayer_x                          0x5782A0
#define CEverQuest__LMouseUp_x                                     0x57A3A0
#define CEverQuest__RightClickedOnPlayer_x                         0x578DB0
#define CEverQuest__RMouseUp_x                                     0x579E00
#define CEverQuest__SetGameState_x                                 0x55D540
#define CEverQuest__UPCNotificationFlush_x                         0x554E20
#define CEverQuest__IssuePetCommand_x                              0x565120

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B2590
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B25F0
#define CGaugeWnd__Draw_x                                          0x6B2A20

// CGuild
#define CGuild__FindMemberByName_x                                 0x43AC30
#define CGuild__GetGuildName_x                                     0x43B100
#define CGuild__GetGuildIndex_x                                    0x43C2D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CEA70

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DBC50
#define CInvSlotMgr__MoveItem_x                                    0x6DCB00
#define CInvSlotMgr__SelectSlot_x                                  0x6DBD00

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DB100
#define CInvSlot__SliderComplete_x                                 0x6D8910
#define CInvSlot__GetItemBase_x                                    0x6D7D70
#define CInvSlot__UpdateItem_x                                     0x6D82F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DDF60
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6DF080

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A4750
#define CItemDisplayWnd__UpdateStrings_x                           0x6E0190
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6ECC20
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6ED160
#define CItemDisplayWnd__SetItem_x                                 0x6F2A80

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7DBAD0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6E6760

// CLabel 
#define CLabel__Draw_x                                             0x6F9730

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B82F0
#define CListWnd__dCListWnd_x                                      0x8B9520
#define CListWnd__AddColumn_x                                      0x8B94C0
#define CListWnd__AddColumn1_x                                     0x8B8B50
#define CListWnd__AddLine_x                                        0x8B85B0
#define CListWnd__AddString_x                                      0x8B87D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B55B0
#define CListWnd__CalculateVSBRange_x                              0x8B77C0
#define CListWnd__ClearSel_x                                       0x8B48D0
#define CListWnd__ClearAllSel_x                                    0x8B4880
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B8180
#define CListWnd__Compare_x                                        0x8B6120
#define CListWnd__Draw_x                                           0x8B73D0
#define CListWnd__DrawColumnSeparators_x                           0x8B7260
#define CListWnd__DrawHeader_x                                     0x8B4B90
#define CListWnd__DrawItem_x                                       0x8B67A0
#define CListWnd__DrawLine_x                                       0x8B6F00
#define CListWnd__DrawSeparator_x                                  0x8B7300
#define CListWnd__EnableLine_x                                     0x8B4AB0
#define CListWnd__EnsureVisible_x                                  0x8B5710
#define CListWnd__ExtendSel_x                                      0x8B66B0
#define CListWnd__GetColumnMinWidth_x                              0x8B4280
#define CListWnd__GetColumnWidth_x                                 0x8B41B0
#define CListWnd__GetCurSel_x                                      0x8B3970
#define CListWnd__GetItemAtPoint_x                                 0x8B59A0
#define CListWnd__GetItemAtPoint1_x                                0x8B5A10
#define CListWnd__GetItemData_x                                    0x8B3CC0
#define CListWnd__GetItemHeight_x                                  0x8B5210
#define CListWnd__GetItemIcon_x                                    0x8B3EB0
#define CListWnd__GetItemRect_x                                    0x8B57E0
#define CListWnd__GetItemText_x                                    0x8B3D60
#define CListWnd__GetSelList_x                                     0x8B8A40
#define CListWnd__GetSeparatorRect_x                               0x8B6040
#define CListWnd__InsertLine_x                                     0x8B89B0
#define CListWnd__RemoveLine_x                                     0x8B89C0
#define CListWnd__SetColors_x                                      0x8B3AC0
#define CListWnd__SetColumnJustification_x                         0x8B4510
#define CListWnd__SetColumnWidth_x                                 0x8B4230
#define CListWnd__SetCurSel_x                                      0x8B39B0
#define CListWnd__SetItemColor_x                                   0x8B7E70
#define CListWnd__SetItemData_x                                    0x8B4930
#define CListWnd__SetItemText_x                                    0x8B7CB0
#define CListWnd__ShiftColumnSeparator_x                           0x8B7B40
#define CListWnd__Sort_x                                           0x8B9620
#define CListWnd__ToggleSel_x                                      0x8B4800

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x712710

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x733D00
#define CMerchantWnd__RequestBuyItem_x                             0x73ADD0
#define CMerchantWnd__RequestSellItem_x                            0x73B8A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x733FB0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7331B0
#define CMerchantWnd__ActualSelect_x                               0x737CA0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84A6C0
#define CPacketScrambler__hton_x                                   0x84A6D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D7290
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D7370
#define CSidlManager__CreateLabel_x                                0x79C090
#define CSidlManager__CreateXWndFromTemplate_x                     0x8D5840
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D7650

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8CE7A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8CE6A0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F27D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CF0B0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D0280
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D0330
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CF800
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CEA60
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CE1D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CEC50
#define CSidlScreenWnd__Init1_x                                    0x8CFF50
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CF160
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CE390
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CFA40
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CDE20
#define CSidlScreenWnd__StoreIniVis_x                              0x8CE180
#define CSidlScreenWnd__WndNotification_x                          0x8CFCD0
#define CSidlScreenWnd__GetChildItem_x                             0x8CE2A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C1AE0
#define CSidlScreenWnd__m_layoutCopy_x                             0x171E048

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FD580
#define CSkillMgr__GetSkillCap_x                                   0x5FD760
#define CSkillMgr__GetNameToken_x                                  0x5FD130

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F1A80
#define CSliderWnd__SetValue_x                                     0x8F1C50
#define CSliderWnd__SetNumTicks_x                                  0x8F23D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A23B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EBF10
#define CStmlWnd__CalculateHSBRange_x                              0x8E4620
#define CStmlWnd__CalculateVSBRange_x                              0x8E4590
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E47A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E4FA0
#define CStmlWnd__ForceParseNow_x                                  0x8EC890
#define CStmlWnd__GetNextTagPiece_x                                0x8E4EA0
#define CStmlWnd__GetSTMLText_x                                    0x483C70
#define CStmlWnd__GetVisibleText_x                                 0x8E59F0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E7E50
#define CStmlWnd__MakeStmlColorTag_x                               0x8E3890
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E38F0
#define CStmlWnd__SetSTMLText_x                                    0x8E96A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EBBB0
#define CStmlWnd__UpdateHistoryString_x                            0x8E6930

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EFD80
#define CTabWnd__DrawCurrentPage_x                                 0x8EF610
#define CTabWnd__DrawTab_x                                         0x8EF3E0
#define CTabWnd__GetCurrentPage_x                                  0x8EF9C0
#define CTabWnd__GetPageInnerRect_x                                0x8EF0D0
#define CTabWnd__GetTabInnerRect_x                                 0x8EF2D0
#define CTabWnd__GetTabRect_x                                      0x8EF1A0
#define CTabWnd__InsertPage_x                                      0x8F0070
#define CTabWnd__SetPage_x                                         0x8EF9F0
#define CTabWnd__SetPageRect_x                                     0x8EFCC0
#define CTabWnd__UpdatePage_x                                      0x8F0010
#define CTabWnd__GetPageFromTabIndex_x                             0x8EF330
#define CTabWnd__GetCurrentTabIndex_x                              0x8EF060

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6DF230
#define CPageWnd__SetTabText_x                                     0x8FB7E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4367C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CC0A0
#define CTextureFont__GetTextExtent_x                              0x8CBE00

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x636020

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F7C20

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B1A10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59EC30
#define CXStr__CXStr1_x                                            0x8A70F0
#define CXStr__CXStr3_x                                            0x894DF0
#define CXStr__dCXStr_x                                            0x8F6980
#define CXStr__operator_equal_x                                    0x894F60
#define CXStr__operator_equal1_x                                   0x894FB0
#define CXStr__operator_plus_equal1_x                              0x8960B0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C0CA0
#define CXWnd__Center_x                                            0x8C6E60
#define CXWnd__ClrFocus_x                                          0x8C08A0
#define CXWnd__Destroy_x                                           0x8C7940
#define CXWnd__DoAllDrawing_x                                      0x8C6AB0
#define CXWnd__DrawChildren_x                                      0x8C6C50
#define CXWnd__DrawColoredRect_x                                   0x8C1080
#define CXWnd__DrawTooltip_x                                       0x8C1330
#define CXWnd__DrawTooltipAtPoint_x                                0x8C5A20
#define CXWnd__GetBorderFrame_x                                    0x8C17A0
#define CXWnd__GetChildWndAt_x                                     0x8C7820
#define CXWnd__GetClientClipRect_x                                 0x8C1550
#define CXWnd__GetScreenClipRect_x                                 0x8C6110
#define CXWnd__GetScreenRect_x                                     0x8C1970
#define CXWnd__GetTooltipRect_x                                    0x8C11C0
#define CXWnd__GetWindowTextA_x                                    0x427050
#define CXWnd__IsActive_x                                          0x8BC2F0
#define CXWnd__IsDescendantOf_x                                    0x8C16E0
#define CXWnd__IsReallyVisible_x                                   0x8C4A50
#define CXWnd__IsType_x                                            0x8C6ED0
#define CScreenPieceTemplate__IsType_x                             0x8F4420
#define CXWnd__Move_x                                              0x8C4160
#define CXWnd__Move1_x                                             0x8C6760
#define CXWnd__ProcessTransition_x                                 0x8C0C40
#define CXWnd__Refade_x                                            0x8C0A30
#define CXWnd__Resize_x                                            0x8C1A40
#define CXWnd__Right_x                                             0x8C5F10
#define CXWnd__SetFocus_x                                          0x8C32D0
#define CXWnd__SetFont_x                                           0x8C08F0
#define CXWnd__SetKeyTooltip_x                                     0x8C1CB0
#define CXWnd__SetMouseOver_x                                      0x8C6440
#define CXWnd__StartFade_x                                         0x8C0CF0
#define CXWnd__GetChildItem_x                                      0x8C6380
#define CXWnd__SetParent_x                                         0x8C77D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BDB80
#define CXWndManager__DrawWindows_x                                0x8BD7C0
#define CXWndManager__GetKeyboardFlags_x                           0x8BBE20
#define CXWndManager__HandleKeyboardMsg_x                          0x8BC780
#define CXWndManager__RemoveWnd_x                                  0x8BC480

// CDBStr
#define CDBStr__GetString_x                                        0x4B2F00

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x451880
#define EQ_Character__Cur_HP_x                                     0x466210
#define EQ_Character__Cur_Mana_x                                   0x459FC0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44AB00
#define EQ_Character__GetFocusCastingTimeModifier_x                0x442E70
#define EQ_Character__GetFocusRangeModifier_x                      0x442ED0
#define EQ_Character__GetHPRegen_x                                 0x4693F0
#define EQ_Character__GetEnduranceRegen_x                          0x465820
#define EQ_Character__GetManaRegen_x                               0x469990
#define EQ_Character__Max_Endurance_x                              0x5C4170
#define EQ_Character__Max_HP_x                                     0x45CB30
#define EQ_Character__Max_Mana_x                                   0x5C3FA0
#define EQ_Character__doCombatAbility_x                            0x5C1670
#define EQ_Character__UseSkill_x                                   0x470370
#define EQ_Character__GetConLevel_x                                0x5B6AF0
#define EQ_Character__IsExpansionFlag_x                            0x4265A0
#define EQ_Character__TotalEffect_x                                0x44EBB0
#define EQ_Character__GetPCSpellAffect_x                           0x44AF00
#define EQ_Character__SpellDuration_x                              0x448EA0
#define EQ_Character__FindItemByRecord_x                           0x463860
#define EQ_Character__GetAdjustedSkill_x                           0x4669C0
#define EQ_Character__GetBaseSkill_x                               0x45CA10

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x867C40

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5CC170

//PcClient
#define PcClient__PcClient_x                                       0x5B8930

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x4461B0
#define CCharacterSelect__EnterWorld_x                             0x445980
#define CCharacterSelect__Quit_x                                   0x444560

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x596EF0
#define EQ_Item__CreateItemTagString_x                             0x849060
#define EQ_Item__IsStackable_x                                     0x83EB00
#define EQ_Item__GetImageNum_x                                     0x841540
#define EQ_Item__CreateItemClient_x                                0x597AF0
#define EQ_Item__GetItemValue_x                                    0x847DB0
#define EQ_Item__ValueSellMerchant_x                               0x84A320
#define EQ_Item__IsKeyRingItem_x                                   0x83F550
#define EQ_Item__CanGoInBag_x                                      0x597080
#define EQ_Item__GetMaxItemCount_x                                 0x83E9F0
#define EQ_Item__GetHeldItem_x                                     0x840350
#define EQ_Item__GetAugmentFitBySlot_x                             0x84A140

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D2D50
#define EQ_LoadingS__Array_x                                       0xBF9A78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C6680
#define EQ_PC__GetAlternateAbilityId_x                             0x8526C0
#define EQ_PC__GetCombatAbility_x                                  0x852750
#define EQ_PC__GetCombatAbilityTimer_x                             0x84D370
#define EQ_PC__GetItemRecastTimer_x                                0x5BFE20
#define EQ_PC__HasLoreItem_x                                       0x5BA0E0
#define EQ_PC__AlertInventoryChanged_x                             0x5B6AC0
#define EQ_PC__GetPcZoneClient_x                                   0x5E0630
#define EQ_PC__RemoveMyAffect_x                                    0x5BF2F0
#define EQ_PC__GetKeyRingItems_x                                   0x84D790
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8603D0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x854640

// EQItemList 
#define EQItemList__EQItemList_x                                   0x51F500
#define EQItemList__add_object_x                                   0x54BDA0
#define EQItemList__add_item_x                                     0x51F440
#define EQItemList__delete_item_x                                  0x51F8F0
#define EQItemList__FreeItemList_x                                 0x51F7F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B21F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CBF10
#define EQPlayer__dEQPlayer_x                                      0x5D4540
#define EQPlayer__DoAttack_x                                       0x5E5FB0
#define EQPlayer__EQPlayer_x                                       0x5D6C60
#define EQPlayer__SetNameSpriteState_x                             0x5D1400
#define EQPlayer__SetNameSpriteTint_x                              0x5CD320
#define PlayerBase__HasProperty_j_x                                0x925270
#define EQPlayer__IsTargetable_x                                   0x925510
#define EQPlayer__CanSee_x                                         0x925A70
#define PlayerZoneClient__ChangeHeight_x                           0x5E5E70
#define EQPlayer__CanSeeTargetIndicator_x                          0x925B60
#define PlayerBase__GetVisibilityLineSegment_x                     0x925800

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E07E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5DAC90
#define EQPlayerManager__GetSpawnByName_x                          0x5DB0F0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5DACC0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59CFD0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59D010
#define KeypressHandler__ClearCommandStateArray_x                  0x59CBC0
#define KeypressHandler__HandleKeyDown_x                           0x59B520
#define KeypressHandler__HandleKeyUp_x                             0x59B840
#define KeypressHandler__SaveKeymapping_x                          0x59CC90

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70B0A0
#define MapViewMap__SaveEx_x                                       0x70E3D0

#define PlayerPointManager__GetAltCurrency_x                       0x865D00

// StringTable 
#define StringTable__getString_x                                   0x860700

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C3C00
#define PcZoneClient__RemovePetEffect_x                            0x5C02F0
#define PcZoneClient__HasAlternateAbility_x                        0x5C0C90
#define PcZoneClient__GetCurrentMod_x                              0x45BFE0
#define PcZoneClient__GetModCap_x                                  0x459720
#define PcZoneClient__CanEquipItem_x                               0x5C11B0
#define PcZoneClient__GetItemByID_x                                0x5C59F0
#define PcZoneClient__GetItemByItemClass_x                         0x5C65A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5536A0

//IconCache
#define IconCache__GetIcon_x                                       0x6A7E30

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69ED50
#define CContainerMgr__CloseContainer_x                            0x69F570

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76BF50

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58FE90

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4ECC90
#define EQ_Spell__SpellAffects_x                                   0x4EA330
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4EA3A0
#define CharacterZoneClient__CalcAffectChange_x                    0x44AD90
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x449FD0
#define CLootWnd__LootAll_x                                        0x7009A0
#define CLootWnd__RequestLootSlot_x                                0x7011B0
#define EQ_Spell__IsStackable_x                                    0x448A70
#define EQ_Spell__GetSpellAffectBySlot_x                           0x448B20
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43E6D0
#define EQ_Spell__IsSPAStacking_x                                  0x4E9EE0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4E99B0
#define EQ_Spell__IsNoRemove_x                                     0x434810
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4E9F00

#define __IsResEffectSpell_x                                       0x448BA0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8717C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B16D0
#define CTargetWnd__WndNotification_x                              0x7B11C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B18B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B67C0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E5900
#define EqSoundManager__PlayScriptMp3_x                            0x4E73A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A1370

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DFEB0
#define CSidlManager__FindAnimation1_x                             0x8D5270

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4DA3C0
#define CAltAbilityData__GetMercMaxRank_x                          0x4DA370
#define CAltAbilityData__GetMaxRank_x                              0x4CEE70

//CTargetRing
#define CTargetRing__Cast_x                                        0x58D740

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x458760
#define CharacterBase__CreateItemGlobalIndex_x                     0x475090
#define CharacterBase__CreateItemIndex_x                           0x518A60
#define CharacterBase__GetItemPossession_x                         0x4439F0
#define CharacterBase__GetItemByGlobalIndex_x                      0x875E10
#define CharacterBase__GetEffectId_x                               0x458720

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x687A90
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6871F0

//messages
#define msg_spell_worn_off_x                                       0x4F4670
#define msg_new_text_x                                             0x4FDC30
#define msgTokenTextParam_x                                        0x4FA490

//SpellManager
#define SpellManager__vftable_x                                    0xABA158
#define SpellManager__SpellManager_x                               0x47DD40
#define Spellmanager__CheckSpellRequirementAssociations_x          0x604470

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x929610

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F0D60
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43E5F0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x448820
#define ItemGlobalIndex__IsValidIndex_x                            0x457F90

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x873C80
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x872BC0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F9980

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6A3A70
#define CCursorAttachment__Deactivate_x                            0x6A2FB0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8F0F80
