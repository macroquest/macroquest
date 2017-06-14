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
#define __ExpectedVersionDate                                     "Jun 12 2017"
#define __ExpectedVersionTime                                     "13:28:24"
#define __ActualVersionDate_x                                      0xAD4418
#define __ActualVersionTime_x                                      0xAD4424

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5A27F0
#define __MemChecker1_x                                            0x898A80
#define __MemChecker2_x                                            0x6385B0
#define __MemChecker3_x                                            0x638500
#define __MemChecker4_x                                            0x7EAE60
#define __EncryptPad0_x                                            0xC2E328
#define __EncryptPad1_x                                            0xD096E0
#define __EncryptPad2_x                                            0xC57B10
#define __EncryptPad3_x                                            0xC57710
#define __EncryptPad4_x                                            0xCF7CE0
#define __EncryptPad5_x                                            0x10B2370
#define __AC1_x                                                    0x7AA4B5
#define __AC2_x                                                    0x55B687
#define __AC3_x                                                    0x559800
#define __AC4_x                                                    0x56B911
#define __AC5_x                                                    0x57F7AB
#define __AC6_x                                                    0x58335E
#define __AC7_x                                                    0x579DAC
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
#define __do_loot_x                                                0x52A990
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
#define __CastRay_x                                                0x541EF0
#define __ConvertItemTags_x                                        0x52F5B0
#define __ExecuteCmd_x                                             0x519ED0
#define __EQGetTime_x                                              0x898420
#define __get_melee_range_x                                        0x520B30
#define __GetGaugeValueFromEQ_x                                    0x7A9070
#define __GetLabelFromEQ_x                                         0x7AA440
#define __ToggleKeyRingItem_x                                      0x488B90
#define __GetXTargetType_x                                         0x929220
#define __LoadFrontEnd_x                                           0x637C80
#define __NewUIINI_x                                               0x7A8A40
#define __ProcessGameEvents_x                                      0x57BB40
#define __ProcessMouseEvent_x                                      0x57B2E0
#define CrashDetected_x                                            0x639640
#define wwsCrashReportCheckForUploader_x                           0x7F6E30
#define __AppCrashWrapper_x                                        0xC57704
#define __pCrashHandler_x                                          0x10C7568
#define __CrashHandler_x                                           0x7F68C0
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F9060
#define DrawNetStatus_x                                            0x5B24F0
#define Util__FastTime_x                                           0x8980C0
#define Expansion_HoT_x                                            0xF21A70
#define __HelpPath_x                                               0xFA5188
#define __STMLToText_x                                             0x8DE630

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x422FC0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DCF0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DAC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D1030
#define AltAdvManager__IsAbilityReady_x                            0x4D10A0
#define AltAdvManager__GetAAById_x                                 0x4D1590
#define AltAdvManager__CanTrainAbility_x                           0x4D21C0
#define AltAdvManager__CanSeeAbility_x                             0x4D1D80

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46A090
#define CharacterZoneClient__HasSkill_x                            0x466F40
#define CharacterZoneClient__MakeMeVisible_x                       0x46B620
#define CharacterZoneClient__IsStackBlocked_x                      0x44B620
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44AAE0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464EC0
#define CharacterZoneClient__GetItemCountInInventory_x             0x464FA0
#define CharacterZoneClient__GetCursorItemCount_x                  0x465080
#define CharacterZoneClient__FindAffectSlot_x                      0x450B70
#define CharacterZoneClient__BardCastBard_x                        0x44A260
#define CharacterZoneClient__GetMaxEffects_x                       0x448FA0
#define CharacterZoneClient__GetEffect_x                           0x44AD10
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4509D0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449140
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44F520

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x667670

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6759D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x591420
#define CButtonWnd__CButtonWnd_x                                   0x8D28F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6909F0
#define CChatManager__InitContextMenu_x                            0x691B40
#define CChatManager__FreeChatWindow_x                             0x690480
#define CChatManager__GetLockedActiveChatWindow_x                  0x699BF0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6909C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DC980
#define CContextMenu__dCContextMenu_x                              0x8DCB90
#define CContextMenu__AddMenuItem_x                                0x8DCBA0
#define CContextMenu__RemoveMenuItem_x                             0x8DCEA0
#define CContextMenu__RemoveAllMenuItems_x                         0x8DCEC0
#define CContextMenu__CheckMenuItem_x                              0x8DCF40

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8C8E70
#define CContextMenuManager__RemoveMenu_x                          0x8C9210
#define CContextMenuManager__PopupMenu_x                           0x8C9660
#define CContextMenuManager__Flush_x                               0x8C8EE0
#define CContextMenuManager__GetMenu_x                             0x4193C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87C7B0
#define CChatService__GetFriendName_x                              0x87C7C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x697740
#define CChatWindow__Clear_x                                       0x697030
#define CChatWindow__WndNotification_x                             0x698040

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CCCD0
#define CComboWnd__Draw_x                                          0x8CCEE0
#define CComboWnd__GetCurChoice_x                                  0x8CCA80
#define CComboWnd__GetListRect_x                                   0x8CD180
#define CComboWnd__GetTextRect_x                                   0x8CCD40
#define CComboWnd__InsertChoice_x                                  0x8CD1F0
#define CComboWnd__SetColors_x                                     0x8CCA10
#define CComboWnd__SetChoice_x                                     0x8CCA40
#define CComboWnd__GetItemCount_x                                  0x8CCA70
#define CComboWnd__GetCurChoiceText_x                              0x8CCAC0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A1990
#define CContainerWnd__vftable_x                                   0xADE020

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BEC50
#define CDisplay__GetClickedActor_x                                0x4B7550
#define CDisplay__GetUserDefinedColor_x                            0x4B6130
#define CDisplay__GetWorldFilePath_x                               0x4B5580
#define CDisplay__is3dON_x                                         0x4B4A10
#define CDisplay__ReloadUI_x                                       0x4C8BB0
#define CDisplay__WriteTextHD2_x                                   0x4BB010
#define CDisplay__TrueDistance_x                                   0x4B8180

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F2F60

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E0EE0
#define CEditWnd__GetCharIndexPt_x                                 0x8E1F80
#define CEditWnd__GetDisplayString_x                               0x8E1090
#define CEditWnd__GetHorzOffset_x                                  0x8E13D0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E1A40
#define CEditWnd__GetSelStartPt_x                                  0x8E2240
#define CEditWnd__GetSTMLSafeText_x                                0x8E1570
#define CEditWnd__PointFromPrintableChar_x                         0x8E1B30
#define CEditWnd__SelectableCharFromPoint_x                        0x8E1CB0
#define CEditWnd__SetEditable_x                                    0x8E1540

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x562140
#define CEverQuest__ClickedPlayer_x                                0x55BDD0
#define CEverQuest__CreateTargetIndicator_x                        0x55CCD0
#define CEverQuest__DeleteTargetIndicator_x                        0x55CD50
#define CEverQuest__DoTellWindow_x                                 0x476260
#define CEverQuest__OutputTextToLog_x                              0x475EC0
#define CEverQuest__DropHeldItemOnGround_x                         0x5726B0
#define CEverQuest__dsp_chat_x                                     0x4765A0
#define CEverQuest__trimName_x                                     0x5586E0
#define CEverQuest__Emote_x                                        0x5709C0
#define CEverQuest__EnterZone_x                                    0x56BAA0
#define CEverQuest__GetBodyTypeDesc_x                              0x556120
#define CEverQuest__GetClassDesc_x                                 0x55F560
#define CEverQuest__GetClassThreeLetterCode_x                      0x55FB60
#define CEverQuest__GetDeityDesc_x                                 0x556A00
#define CEverQuest__GetLangDesc_x                                  0x5564B0
#define CEverQuest__GetRaceDesc_x                                  0x55FD20
#define CEverQuest__InterpretCmd_x                                 0x5638C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5781F0
#define CEverQuest__LMouseUp_x                                     0x57A300
#define CEverQuest__RightClickedOnPlayer_x                         0x578D00
#define CEverQuest__RMouseUp_x                                     0x579D60
#define CEverQuest__SetGameState_x                                 0x55C6A0
#define CEverQuest__UPCNotificationFlush_x                         0x554AB0
#define CEverQuest__IssuePetCommand_x                              0x5642A0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B25F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B2650
#define CGaugeWnd__Draw_x                                          0x6B2A80

// CGuild
#define CGuild__FindMemberByName_x                                 0x43AF40
#define CGuild__GetGuildName_x                                     0x43B410
#define CGuild__GetGuildIndex_x                                    0x43C620

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CEB00

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DBD90
#define CInvSlotMgr__MoveItem_x                                    0x6DCC40
#define CInvSlotMgr__SelectSlot_x                                  0x6DBE40

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DB230
#define CInvSlot__SliderComplete_x                                 0x6D89B0
#define CInvSlot__GetItemBase_x                                    0x6D7E30
#define CInvSlot__UpdateItem_x                                     0x6D83B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DE0A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6DF1C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A4AA0
#define CItemDisplayWnd__UpdateStrings_x                           0x6E02B0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6ECD50
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6ED260
#define CItemDisplayWnd__SetItem_x                                 0x6F2AD0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7DBE60

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6E6870

// CLabel 
#define CLabel__Draw_x                                             0x6F9750

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B87C0
#define CListWnd__dCListWnd_x                                      0x8B99E0
#define CListWnd__AddColumn_x                                      0x8B9980
#define CListWnd__AddColumn1_x                                     0x8B9020
#define CListWnd__AddLine_x                                        0x8B8A80
#define CListWnd__AddString_x                                      0x8B8CA0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B5A50
#define CListWnd__CalculateVSBRange_x                              0x8B7C90
#define CListWnd__ClearSel_x                                       0x8B4D70
#define CListWnd__ClearAllSel_x                                    0x8B4D20
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B8650
#define CListWnd__Compare_x                                        0x8B65C0
#define CListWnd__Draw_x                                           0x8B7890
#define CListWnd__DrawColumnSeparators_x                           0x8B7720
#define CListWnd__DrawHeader_x                                     0x8B5030
#define CListWnd__DrawItem_x                                       0x8B6C50
#define CListWnd__DrawLine_x                                       0x8B73C0
#define CListWnd__DrawSeparator_x                                  0x8B77C0
#define CListWnd__EnableLine_x                                     0x8B4F50
#define CListWnd__EnsureVisible_x                                  0x8B5BB0
#define CListWnd__ExtendSel_x                                      0x8B6B60
#define CListWnd__GetColumnMinWidth_x                              0x8B4720
#define CListWnd__GetColumnWidth_x                                 0x8B4650
#define CListWnd__GetCurSel_x                                      0x8B3E20
#define CListWnd__GetItemAtPoint_x                                 0x8B5E50
#define CListWnd__GetItemAtPoint1_x                                0x8B5EC0
#define CListWnd__GetItemData_x                                    0x8B4160
#define CListWnd__GetItemHeight_x                                  0x8B56B0
#define CListWnd__GetItemIcon_x                                    0x8B4350
#define CListWnd__GetItemRect_x                                    0x8B5C90
#define CListWnd__GetItemText_x                                    0x8B4200
#define CListWnd__GetSelList_x                                     0x8B8F10
#define CListWnd__GetSeparatorRect_x                               0x8B64E0
#define CListWnd__InsertLine_x                                     0x8B8E80
#define CListWnd__RemoveLine_x                                     0x8B8E90
#define CListWnd__SetColors_x                                      0x8B3F70
#define CListWnd__SetColumnJustification_x                         0x8B49B0
#define CListWnd__SetColumnWidth_x                                 0x8B46D0
#define CListWnd__SetCurSel_x                                      0x8B3E60
#define CListWnd__SetItemColor_x                                   0x8B8340
#define CListWnd__SetItemData_x                                    0x8B4DD0
#define CListWnd__SetItemText_x                                    0x8B8180
#define CListWnd__ShiftColumnSeparator_x                           0x8B8010
#define CListWnd__Sort_x                                           0x8B9AE0
#define CListWnd__ToggleSel_x                                      0x8B4CA0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x712860

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x733D00
#define CMerchantWnd__RequestBuyItem_x                             0x73ADE0
#define CMerchantWnd__RequestSellItem_x                            0x73B8B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x733FB0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7331B0
#define CMerchantWnd__ActualSelect_x                               0x737C90

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84AB00
#define CPacketScrambler__hton_x                                   0x84AB10

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D7840
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D7920
#define CSidlManager__CreateLabel_x                                0x79C180
#define CSidlManager__CreateXWndFromTemplate_x                     0x8D5DD0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D7C00

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8CED50
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8CEC50
#define CSidlScreenWnd__ConvertToRes_x                             0x8F2E40
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CF660
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D0810
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D08C0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CFDA0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CF010
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CE780
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CF200
#define CSidlScreenWnd__Init1_x                                    0x8D04F0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CF710
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CE940
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CFFE0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CE3E0
#define CSidlScreenWnd__StoreIniVis_x                              0x8CE730
#define CSidlScreenWnd__WndNotification_x                          0x8D0270
#define CSidlScreenWnd__GetChildItem_x                             0x8CE850
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C2000
#define CSidlScreenWnd__m_layoutCopy_x                             0x171E048

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FD680
#define CSkillMgr__GetSkillCap_x                                   0x5FD860
#define CSkillMgr__GetNameToken_x                                  0x5FD230

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F20F0
#define CSliderWnd__SetValue_x                                     0x8F22C0
#define CSliderWnd__SetNumTicks_x                                  0x8F2A40

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A2700

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EC5F0
#define CStmlWnd__CalculateHSBRange_x                              0x8E4CE0
#define CStmlWnd__CalculateVSBRange_x                              0x8E4C50
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E4E60
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E5660
#define CStmlWnd__ForceParseNow_x                                  0x8ECF70
#define CStmlWnd__GetNextTagPiece_x                                0x8E5560
#define CStmlWnd__GetSTMLText_x                                    0x484080
#define CStmlWnd__GetVisibleText_x                                 0x8E60B0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E8510
#define CStmlWnd__MakeStmlColorTag_x                               0x8E3F30
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E3F90
#define CStmlWnd__SetSTMLText_x                                    0x8E9D60
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EC290
#define CStmlWnd__UpdateHistoryString_x                            0x8E6FF0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F0470
#define CTabWnd__DrawCurrentPage_x                                 0x8EFD00
#define CTabWnd__DrawTab_x                                         0x8EFAC0
#define CTabWnd__GetCurrentPage_x                                  0x8F00B0
#define CTabWnd__GetPageInnerRect_x                                0x8EF7B0
#define CTabWnd__GetTabInnerRect_x                                 0x8EF9B0
#define CTabWnd__GetTabRect_x                                      0x8EF880
#define CTabWnd__InsertPage_x                                      0x8F0760
#define CTabWnd__SetPage_x                                         0x8F00E0
#define CTabWnd__SetPageRect_x                                     0x8F03B0
#define CTabWnd__UpdatePage_x                                      0x8F0700
#define CTabWnd__GetPageFromTabIndex_x                             0x8EFA10
#define CTabWnd__GetCurrentTabIndex_x                              0x8EF740

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6DF370
#define CPageWnd__SetTabText_x                                     0x8FBE40

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436AD0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CC680
#define CTextureFont__GetTextExtent_x                              0x8CC3E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x635F20

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F8280

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B20C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029E0
#define CXStr__CXStr1_x                                            0x8B3040
#define CXStr__CXStr3_x                                            0x895300
#define CXStr__dCXStr_x                                            0x47C310
#define CXStr__operator_equal_x                                    0x895470
#define CXStr__operator_equal1_x                                   0x8954C0
#define CXStr__operator_plus_equal1_x                              0x8965C0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C11C0
#define CXWnd__Center_x                                            0x8C7460
#define CXWnd__ClrFocus_x                                          0x8C0D80
#define CXWnd__Destroy_x                                           0x8C7F40
#define CXWnd__DoAllDrawing_x                                      0x8C70B0
#define CXWnd__DrawChildren_x                                      0x8C7250
#define CXWnd__DrawColoredRect_x                                   0x8C15A0
#define CXWnd__DrawTooltip_x                                       0x8C1850
#define CXWnd__DrawTooltipAtPoint_x                                0x8C6030
#define CXWnd__GetBorderFrame_x                                    0x8C1CB0
#define CXWnd__GetChildWndAt_x                                     0x8C7E20
#define CXWnd__GetClientClipRect_x                                 0x8C1A60
#define CXWnd__GetScreenClipRect_x                                 0x8C6730
#define CXWnd__GetScreenRect_x                                     0x8C1E90
#define CXWnd__GetTooltipRect_x                                    0x8C16E0
#define CXWnd__GetWindowTextA_x                                    0x427130
#define CXWnd__IsActive_x                                          0x8BC7F0
#define CXWnd__IsDescendantOf_x                                    0x8C1BF0
#define CXWnd__IsReallyVisible_x                                   0x8C5050
#define CXWnd__IsType_x                                            0x8C74D0
#define CScreenPieceTemplate__IsType_x                             0x8F4AE0
#define CXWnd__Move_x                                              0x8C4730
#define CXWnd__Move1_x                                             0x8C6D40
#define CXWnd__ProcessTransition_x                                 0x8C1160
#define CXWnd__Refade_x                                            0x8C0F30
#define CXWnd__Resize_x                                            0x8C1F60
#define CXWnd__Right_x                                             0x8C6530
#define CXWnd__SetFocus_x                                          0x8C3860
#define CXWnd__SetFont_x                                           0x8C0DD0
#define CXWnd__SetKeyTooltip_x                                     0x8C21D0
#define CXWnd__SetMouseOver_x                                      0x8C6A20
#define CXWnd__StartFade_x                                         0x8C1210
#define CXWnd__GetChildItem_x                                      0x8C6970
#define CXWnd__SetParent_x                                         0x8C7DD0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BE080
#define CXWndManager__DrawWindows_x                                0x8BDCC0
#define CXWndManager__GetKeyboardFlags_x                           0x8BC330
#define CXWndManager__HandleKeyboardMsg_x                          0x8BCC80
#define CXWndManager__RemoveWnd_x                                  0x8BC980

// CDBStr
#define CDBStr__GetString_x                                        0x4B3250

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x451B70
#define EQ_Character__Cur_HP_x                                     0x466540
#define EQ_Character__Cur_Mana_x                                   0x45A2C0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44ADF0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443160
#define EQ_Character__GetFocusRangeModifier_x                      0x4431C0
#define EQ_Character__GetHPRegen_x                                 0x469720
#define EQ_Character__GetEnduranceRegen_x                          0x465B50
#define EQ_Character__GetManaRegen_x                               0x469CC0
#define EQ_Character__Max_Endurance_x                              0x5C3E20
#define EQ_Character__Max_HP_x                                     0x45CE40
#define EQ_Character__Max_Mana_x                                   0x5C3C50
#define EQ_Character__doCombatAbility_x                            0x5C1320
#define EQ_Character__UseSkill_x                                   0x4706B0
#define EQ_Character__GetConLevel_x                                0x5B6AD0
#define EQ_Character__IsExpansionFlag_x                            0x426650
#define EQ_Character__TotalEffect_x                                0x44EEA0
#define EQ_Character__GetPCSpellAffect_x                           0x44B1F0
#define EQ_Character__SpellDuration_x                              0x449190
#define EQ_Character__FindItemByRecord_x                           0x463B90
#define EQ_Character__GetAdjustedSkill_x                           0x466CF0
#define EQ_Character__GetBaseSkill_x                               0x45CD20

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8680B0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5CBED0

//PcClient
#define PcClient__PcClient_x                                       0x5B8900

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446490
#define CCharacterSelect__EnterWorld_x                             0x445C60
#define CCharacterSelect__Quit_x                                   0x444840

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x596EB0
#define EQ_Item__CreateItemTagString_x                             0x849470
#define EQ_Item__IsStackable_x                                     0x83EE40
#define EQ_Item__GetImageNum_x                                     0x841940
#define EQ_Item__CreateItemClient_x                                0x597AB0
#define EQ_Item__GetItemValue_x                                    0x8481C0
#define EQ_Item__ValueSellMerchant_x                               0x84A750
#define EQ_Item__IsKeyRingItem_x                                   0x83F940
#define EQ_Item__CanGoInBag_x                                      0x597040
#define EQ_Item__GetMaxItemCount_x                                 0x83ED30
#define EQ_Item__GetHeldItem_x                                     0x840750
#define EQ_Item__GetAugmentFitBySlot_x                             0x84A570

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D36D0
#define EQ_LoadingS__Array_x                                       0xBF9A78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C6340
#define EQ_PC__GetAlternateAbilityId_x                             0x852BE0
#define EQ_PC__GetCombatAbility_x                                  0x852C70
#define EQ_PC__GetCombatAbilityTimer_x                             0x84D7B0
#define EQ_PC__GetItemRecastTimer_x                                0x5BFAE0
#define EQ_PC__HasLoreItem_x                                       0x5BA0C0
#define EQ_PC__AlertInventoryChanged_x                             0x5B6AA0
#define EQ_PC__GetPcZoneClient_x                                   0x5E03F0
#define EQ_PC__RemoveMyAffect_x                                    0x5BEFB0
#define EQ_PC__GetKeyRingItems_x                                   0x84DBD0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8608F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x854B60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x51EBC0
#define EQItemList__add_object_x                                   0x54B9B0
#define EQItemList__add_item_x                                     0x51EB00
#define EQItemList__delete_item_x                                  0x51EFB0
#define EQItemList__FreeItemList_x                                 0x51EEB0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B24D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CBC70
#define EQPlayer__dEQPlayer_x                                      0x5D42B0
#define EQPlayer__DoAttack_x                                       0x5E5D80
#define EQPlayer__EQPlayer_x                                       0x5D69D0
#define EQPlayer__SetNameSpriteState_x                             0x5D1170
#define EQPlayer__SetNameSpriteTint_x                              0x5CD090
#define PlayerBase__HasProperty_j_x                                0x925A20
#define EQPlayer__IsTargetable_x                                   0x925CC0
#define EQPlayer__CanSee_x                                         0x926220
#define PlayerZoneClient__ChangeHeight_x                           0x5E5C40
#define EQPlayer__CanSeeTargetIndicator_x                          0x926310
#define PlayerBase__GetVisibilityLineSegment_x                     0x925FB0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E05A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5DAA30
#define EQPlayerManager__GetSpawnByName_x                          0x5DAE90
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5DAA60

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59D070
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59D0B0
#define KeypressHandler__ClearCommandStateArray_x                  0x59CC60
#define KeypressHandler__HandleKeyDown_x                           0x59B5C0
#define KeypressHandler__HandleKeyUp_x                             0x59B8E0
#define KeypressHandler__SaveKeymapping_x                          0x59CD30

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70B1F0
#define MapViewMap__SaveEx_x                                       0x70E520

#define PlayerPointManager__GetAltCurrency_x                       0x866180

// StringTable 
#define StringTable__getString_x                                   0x860C20

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C38B0
#define PcZoneClient__RemovePetEffect_x                            0x5BFFB0
#define PcZoneClient__HasAlternateAbility_x                        0x5C0950
#define PcZoneClient__GetCurrentMod_x                              0x45C2F0
#define PcZoneClient__GetModCap_x                                  0x459A20
#define PcZoneClient__CanEquipItem_x                               0x5C0E70
#define PcZoneClient__GetItemByID_x                                0x5C56B0
#define PcZoneClient__GetItemByItemClass_x                         0x5C6260

//Doors
#define EQSwitch__UseSwitch_x                                      0x553390

//IconCache
#define IconCache__GetIcon_x                                       0x6A7E30

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69ED20
#define CContainerMgr__CloseContainer_x                            0x69F540

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76C070

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58FE40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4ED790
#define EQ_Spell__SpellAffects_x                                   0x4EAE30
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4EAEA0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B080
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A2C0
#define CLootWnd__LootAll_x                                        0x700B50
#define CLootWnd__RequestLootSlot_x                                0x701360
#define EQ_Spell__IsStackable_x                                    0x448D50
#define EQ_Spell__GetSpellAffectBySlot_x                           0x448E00
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43E9C0
#define EQ_Spell__IsSPAStacking_x                                  0x4EA9E0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4EA4B0
#define EQ_Spell__IsNoRemove_x                                     0x434AF0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4EAA00

#define __IsResEffectSpell_x                                       0x448E90

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x871D50

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B1A00
#define CTargetWnd__WndNotification_x                              0x7B14F0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B1BE0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B6AF0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E6480
#define EqSoundManager__PlayScriptMp3_x                            0x4E7F20

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A15D0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E0510
#define CSidlManager__FindAnimation1_x                             0x8D5800

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4DAE90
#define CAltAbilityData__GetMercMaxRank_x                          0x4DAE40
#define CAltAbilityData__GetMaxRank_x                              0x4CF6E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x58D6F0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x458A20
#define CharacterBase__CreateItemGlobalIndex_x                     0x475430
#define CharacterBase__CreateItemIndex_x                           0x518100
#define CharacterBase__GetItemPossession_x                         0x443D10
#define CharacterBase__GetItemByGlobalIndex_x                      0x876480
#define CharacterBase__GetEffectId_x                               0x4589E0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x687C10
#define CCastSpellWnd__IsBardSongPlaying_x                         0x687370

//messages
#define msg_spell_worn_off_x                                       0x4F5330
#define msg_new_text_x                                             0x4FE990
#define msgTokenTextParam_x                                        0x4FB1D0

//SpellManager
#define SpellManager__vftable_x                                    0xABA160
#define SpellManager__SpellManager_x                               0x47E180
#define Spellmanager__CheckSpellRequirementAssociations_x          0x604520

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x929D40

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F1950
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43E8F0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x448B00
#define ItemGlobalIndex__IsValidIndex_x                            0x458280

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8742F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x873230

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F99A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6A3A60
#define CCursorAttachment__Deactivate_x                            0x6A2FA0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8F15F0
