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
#define __ExpectedVersionDate                                     "May 31 2017"
#define __ExpectedVersionTime                                     "15:41:35"
#define __ActualVersionDate_x                                      0xAD2288
#define __ActualVersionTime_x                                      0xAD2294

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5A1130
#define __MemChecker1_x                                            0x896E10
#define __MemChecker2_x                                            0x636F40
#define __MemChecker3_x                                            0x636E90
#define __MemChecker4_x                                            0x7E9770
#define __EncryptPad0_x                                            0xC2C328
#define __EncryptPad1_x                                            0xD076E0
#define __EncryptPad2_x                                            0xC55B10
#define __EncryptPad3_x                                            0xC55710
#define __EncryptPad4_x                                            0xCF5CE0
#define __EncryptPad5_x                                            0x10B0370
#define __AC1_x                                                    0x7A8B85
#define __AC2_x                                                    0x55AEA7
#define __AC3_x                                                    0x559020
#define __AC4_x                                                    0x56B101
#define __AC5_x                                                    0x57E19B
#define __AC6_x                                                    0x581D4E
#define __AC7_x                                                    0x5787AC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FE4DFC

// Direct Input
#define DI8__Main_x                                                0x10B0348
#define DI8__Keyboard_x                                            0x10B034C
#define DI8__Mouse_x                                               0x10B0350
#define DI8__Mouse_Copy_x                                          0xF1E70C
#define DI8__Mouse_Check_x                                         0xFA8034
#define __AutoSkillArray_x                                         0xF1F620
#define __Attack_x                                                 0xFA2C17
#define __Autofire_x                                               0xFA2C18
#define __BindList_x                                               0xC07050
#define g_eqCommandStates_x                                        0xF0D730
#define __Clicks_x                                                 0xF1E7C8
#define __CommandList_x                                            0xC096C8
#define __CurrentMapLabel_x                                        0x10B5DD0
#define __CurrentSocial_x                                          0xBD8424
#define __DoAbilityList_x                                          0xF54ECC
#define __do_loot_x                                                0x529AA0
#define __DrawHandler_x                                            0x171CC84
#define __GroupCount_x                                             0xF0ED62

#define __Guilds_x                                                 0xF14978
#define __gWorld_x                                                 0xF1121C
#define __HotkeyPage_x                                             0xF9B8CC
#define __HWnd_x                                                   0xFA8150
#define __InChatMode_x                                             0xF1E6F4
#define __LastTell_x                                               0xF205C8
#define __LMouseHeldTime_x                                         0xF1E834
#define __Mouse_x                                                  0x10B0354
#define __MouseLook_x                                              0xF1E78E
#define __MouseEventTime_x                                         0xFA341C
#define __gpbCommandEvent_x                                        0xF112E4
#define __NetStatusToggle_x                                        0xF1E791
#define __PCNames_x                                                0xF1FBDC
#define __RangeAttackReady_x                                       0xF1F904
#define __RMouseHeldTime_x                                         0xF1E830
#define __RunWalkState_x                                           0xF1E6F8
#define __ScreenMode_x                                             0xE5D418
#define __ScreenX_x                                                0xF1E6AC
#define __ScreenY_x                                                0xF1E6A8
#define __ScreenXMax_x                                             0xF1E6B0
#define __ScreenYMax_x                                             0xF1E6B4
#define __ServerHost_x                                             0xF0ECAC
#define __ServerName_x                                             0xF54E8C
#define __ShiftKeyDown_x                                           0xF1ED88
#define __ShowNames_x                                              0xF1FAC4
#define __Socials_x                                                0xF54F8C
#define __SubscriptionType_x                                       0x10E3D94
#define __TargetAggroHolder_x                                      0x10B7FA4
#define __ZoneType_x                                               0xF1EB8C
#define __GroupAggro_x                                             0x10B7FE4
#define __LoginName_x                                              0xFA6C2C
#define __Inviter_x                                                0xFA2B94
#define __AttackOnAssist_x                                         0xF1FA80
#define __UseTellWindows_x                                         0xF1FD74

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF11308
#define instEQZoneInfo_x                                           0xF1E984
#define instKeypressHandler_x                                      0xFA3400
#define pinstActiveBanker_x                                        0xF112C0
#define pinstActiveCorpse_x                                        0xF112C4
#define pinstActiveGMaster_x                                       0xF112C8
#define pinstActiveMerchant_x                                      0xF112BC
#define pinstAggroInfo_x                                           0xD1AD88
#define pinstAltAdvManager_x                                       0xE5E4F8
#define pinstAuraMgr_x                                             0xD2B4F8
#define pinstBandageTarget_x                                       0xF112A8
#define pinstCamActor_x                                            0xE5DE48
#define pinstCDBStr_x                                              0xE5D3AC
#define pinstCDisplay_x                                            0xF112D0
#define pinstCEverQuest_x                                          0x10B04C8
#define pinstEverQuestInfo_x                                       0xF1E6A0
#define pinstCharData_x                                            0xF1128C
#define pinstCharSpawn_x                                           0xF112B4
#define pinstControlledMissile_x                                   0xF11288
#define pinstControlledPlayer_x                                    0xF112B4
#define pinstCSidlManager_x                                        0x171C074
#define pinstCXWndManager_x                                        0x171C06C
#define instDynamicZone_x                                          0xF1E540
#define pinstDZMember_x                                            0xF1E650
#define pinstDZTimerInfo_x                                         0xF1E654
#define pinstEQItemList_x                                          0xF0D984
#define pinstEQObjectList_x                                        0xF0E75C
#define instEQMisc_x                                               0xBEF690
#define pinstEQSoundManager_x                                      0xE5EAC8
#define instExpeditionLeader_x                                     0xF1E58A
#define instExpeditionName_x                                       0xF1E5CA
#define pinstGroup_x                                               0xF0ED5E
#define pinstImeManager_x                                          0x171C078
#define pinstLocalPlayer_x                                         0xF112A0
#define pinstMercenaryData_x                                       0xFA3A80
#define pinstMercenaryStats_x                                      0x10B80F0
#define pinstMercAltAbilities_x                                    0xE5E880
#define pinstModelPlayer_x                                         0xF112CC
#define pinstPCData_x                                              0xF1128C
#define pinstSkillMgr_x                                            0xFA48E8
#define pinstSpawnManager_x                                        0xFA41D0
#define pinstSpellManager_x                                        0xFA4A30
#define pinstSpellSets_x                                           0xF9B930
#define pinstStringTable_x                                         0xF11234
#define pinstSwitchManager_x                                       0xF0E8F0
#define pinstTarget_x                                              0xF112B8
#define pinstTargetObject_x                                        0xF11290
#define pinstTargetSwitch_x                                        0xF11294
#define pinstTaskMember_x                                          0xE5D2F8
#define pinstTrackTarget_x                                         0xF112AC
#define pinstTradeTarget_x                                         0xF1129C
#define instTributeActive_x                                        0xBEF6B5
#define pinstViewActor_x                                           0xE5DE44
#define pinstWorldData_x                                           0xF11270
#define pinstZoneAddr_x                                            0xF1EC24
#define pinstPlayerPath_x                                          0xFA4230
#define pinstTargetIndicator_x                                     0xFA4BC8
#define pinstCTargetManager_x                                      0xFA4C28
#define EQObject_Top_x                                             0xF11280
#define pinstRealEstateItems_x                                     0xFA47D4

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE5DD60
#define pinstCAchievementsWnd_x                                    0xE5DDBC
#define pinstCTextOverlay_x                                        0xD1B288
#define pinstCAudioTriggersWindow_x                                0xD1B118
#define pinstCCharacterSelect_x                                    0xE5DCD0
#define pinstCFacePick_x                                           0xE5DC80
#define pinstCNoteWnd_x                                            0xE5DC88
#define pinstCBookWnd_x                                            0xE5DC90
#define pinstCPetInfoWnd_x                                         0xE5DC94
#define pinstCTrainWnd_x                                           0xE5DC98
#define pinstCSkillsWnd_x                                          0xE5DC9C
#define pinstCSkillsSelectWnd_x                                    0xE5DCA0
#define pinstCCombatSkillsSelectWnd_x                              0xE5DCA4
#define pinstCFriendsWnd_x                                         0xE5DCA8
#define pinstCAuraWnd_x                                            0xE5DCAC
#define pinstCRespawnWnd_x                                         0xE5DCB0
#define pinstCBandolierWnd_x                                       0xE5DCB4
#define pinstCPotionBeltWnd_x                                      0xE5DCB8
#define pinstCAAWnd_x                                              0xE5DCBC
#define pinstCGroupSearchFiltersWnd_x                              0xE5DCC0
#define pinstCLoadskinWnd_x                                        0xE5DCC4
#define pinstCAlarmWnd_x                                           0xE5DCC8
#define pinstCMusicPlayerWnd_x                                     0xE5DCCC
#define pinstCMailWnd_x                                            0xE5DCD4
#define pinstCMailCompositionWnd_x                                 0xE5DCD8
#define pinstCMailAddressBookWnd_x                                 0xE5DCDC
#define pinstCRaidWnd_x                                            0xE5DCE4
#define pinstCRaidOptionsWnd_x                                     0xE5DCE8
#define pinstCBreathWnd_x                                          0xE5DCEC
#define pinstCMapViewWnd_x                                         0xE5DCF0
#define pinstCMapToolbarWnd_x                                      0xE5DCF4
#define pinstCEditLabelWnd_x                                       0xE5DCF8
#define pinstCTargetWnd_x                                          0xE5DCFC
#define pinstCColorPickerWnd_x                                     0xE5DD00
#define pinstCPlayerWnd_x                                          0xE5DD04
#define pinstCOptionsWnd_x                                         0xE5DD08
#define pinstCBuffWindowNORMAL_x                                   0xE5DD0C
#define pinstCBuffWindowSHORT_x                                    0xE5DD10
#define pinstCharacterCreation_x                                   0xE5DD14
#define pinstCCursorAttachment_x                                   0xE5DD18
#define pinstCCastingWnd_x                                         0xE5DD1C
#define pinstCCastSpellWnd_x                                       0xE5DD20
#define pinstCSpellBookWnd_x                                       0xE5DD24
#define pinstCInventoryWnd_x                                       0xE5DD28
#define pinstCBankWnd_x                                            0xE5DD30
#define pinstCQuantityWnd_x                                        0xE5DD34
#define pinstCLootWnd_x                                            0xE5DD38
#define pinstCActionsWnd_x                                         0xE5DD3C
#define pinstCCombatAbilityWnd_x                                   0xE5DD44
#define pinstCMerchantWnd_x                                        0xE5DD48
#define pinstCTradeWnd_x                                           0xE5DD50
#define pinstCSelectorWnd_x                                        0xE5DD54
#define pinstCBazaarWnd_x                                          0xE5DD58
#define pinstCBazaarSearchWnd_x                                    0xE5DD5C
#define pinstCGiveWnd_x                                            0xE5DD78
#define pinstCTrackingWnd_x                                        0xE5DD80
#define pinstCInspectWnd_x                                         0xE5DD84
#define pinstCSocialEditWnd_x                                      0xE5DD88
#define pinstCFeedbackWnd_x                                        0xE5DD8C
#define pinstCBugReportWnd_x                                       0xE5DD90
#define pinstCVideoModesWnd_x                                      0xE5DD94
#define pinstCTextEntryWnd_x                                       0xE5DD9C
#define pinstCFileSelectionWnd_x                                   0xE5DDA0
#define pinstCCompassWnd_x                                         0xE5DDA4
#define pinstCPlayerNotesWnd_x                                     0xE5DDA8
#define pinstCGemsGameWnd_x                                        0xE5DDAC
#define pinstCTimeLeftWnd_x                                        0xE5DDB0
#define pinstCPetitionQWnd_x                                       0xE5DDCC
#define pinstCStoryWnd_x                                           0xE5DDD0
#define pinstCJournalTextWnd_x                                     0xE5DDD4
#define pinstCJournalCatWnd_x                                      0xE5DDD8
#define pinstCBodyTintWnd_x                                        0xE5DDDC
#define pinstCServerListWnd_x                                      0xE5DDE0
#define pinstCAvaZoneWnd_x                                         0xE5DDEC
#define pinstCBlockedBuffWnd_x                                     0xE5DDF0
#define pinstCBlockedPetBuffWnd_x                                  0xE5DDF4
#define pinstCInvSlotMgr_x                                         0xE5DE3C
#define pinstCContainerMgr_x                                       0xE5DE40
#define pinstCAdventureLeaderboardWnd_x                            0x10B0E78
#define pinstCAdventureRequestWnd_x                                0x10B0EF0
#define pinstCAltStorageWnd_x                                      0x10B11D0
#define pinstCAdventureStatsWnd_x                                  0x10B0F68
#define pinstCBarterMerchantWnd_x                                  0x10B1DB8
#define pinstCBarterSearchWnd_x                                    0x10B1E30
#define pinstCBarterWnd_x                                          0x10B1EA8
#define pinstCChatWindowManager_x                                  0x10B2538
#define pinstCDynamicZoneWnd_x                                     0x10B29E8
#define pinstCEQMainWnd_x                                          0x10B2B80
#define pinstCFellowshipWnd_x                                      0x10B297C
#define pinstCFindLocationWnd_x                                    0x10B2E50
#define pinstCGroupSearchWnd_x                                     0x10B3120
#define pinstCGroupWnd_x                                           0x10B3198
#define pinstCGuildBankWnd_x                                       0x10B3210
#define pinstCGuildMgmtWnd_x                                       0x10B5300
#define pinstCHotButtonWnd_x                                       0x10B53FC
#define pinstCHotButtonWnd1_x                                      0x10B53FC
#define pinstCHotButtonWnd2_x                                      0x10B5400
#define pinstCHotButtonWnd3_x                                      0x10B5404
#define pinstCHotButtonWnd4_x                                      0x10B5428
#define pinstCItemDisplayManager_x                                 0x10B5720
#define pinstCItemExpTransferWnd_x                                 0x10B579C
#define pinstCLFGuildWnd_x                                         0x10B5A78
#define pinstCMIZoneSelectWnd_x                                    0x10B6060
#define pinstCConfirmationDialog_x                                 0x10B6768
#define pinstCPopupWndManager_x                                    0x10B6768
#define pinstCProgressionSelectionWnd_x                            0x10B6858
#define pinstCPvPStatsWnd_x                                        0x10B6948
#define pinstCLargeDialogWnd_x                                     0x10B7050
#define pinstCTaskWnd_x                                            0x10B83D0
#define pinstCTaskSomething_x                                      0xD2BEA0
#define pinstCTaskTemplateSelectWnd_x                              0x10B8358
#define pinstCTipWndOFDAY_x                                        0x10B8538
#define pinstCTipWndCONTEXT_x                                      0x10B853C
#define pinstCTitleWnd_x                                           0x10B85B8
#define pinstCContextMenuManager_x                                 0x171BFE4
#define pinstCVoiceMacroWnd_x                                      0xFA5000
#define pinstCHtmlWnd_x                                            0xFA50F0
#define pinstIconCache_x                                           0x10B2B54
#define pinstCTradeskillWnd_x                                      0x10B86B8
#define pinstCAdvancedLootWnd_x                                    0xE5DE30
#define pinstRewardSelectionWnd_x                                  0x10B6E70
#define pinstEQSuiteTextureLoader_x                                0xD09458

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x540C40
#define __ConvertItemTags_x                                        0x52E5A0
#define __ExecuteCmd_x                                             0x519120
#define __EQGetTime_x                                              0x8967B0
#define __get_melee_range_x                                        0x51FD70
#define __GetGaugeValueFromEQ_x                                    0x7A7740
#define __GetLabelFromEQ_x                                         0x7A8B10
#define __ToggleKeyRingItem_x                                      0x488790
#define __GetXTargetType_x                                         0x9272D0
#define __LoadFrontEnd_x                                           0x636610
#define __NewUIINI_x                                               0x7A7110
#define __ProcessGameEvents_x                                      0x57A530
#define __ProcessMouseEvent_x                                      0x579CD0
#define CrashDetected_x                                            0x637FD0
#define wwsCrashReportCheckForUploader_x                           0x7F5430
#define __AppCrashWrapper_x                                        0xC55704
#define __pCrashHandler_x                                          0x10C5568
#define __CrashHandler_x                                           0x7F4EC0
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F7660
#define DrawNetStatus_x                                            0x5B0E20
#define Util__FastTime_x                                           0x896450
#define Expansion_HoT_x                                            0xF1FA70
#define __HelpPath_x                                               0xFA3188
#define __STMLToText_x                                             0x8DC7B0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x422F30
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DCD0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DAB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D0550
#define AltAdvManager__IsAbilityReady_x                            0x4D05C0
#define AltAdvManager__GetAAById_x                                 0x4D0AB0
#define AltAdvManager__CanTrainAbility_x                           0x4D16E0
#define AltAdvManager__CanSeeAbility_x                             0x4D12A0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x469DB0
#define CharacterZoneClient__HasSkill_x                            0x466C60
#define CharacterZoneClient__MakeMeVisible_x                       0x46B340
#define CharacterZoneClient__IsStackBlocked_x                      0x44B390
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44A850
#define CharacterZoneClient__GetItemCountWorn_x                    0x464BE0
#define CharacterZoneClient__GetItemCountInInventory_x             0x464CC0
#define CharacterZoneClient__GetCursorItemCount_x                  0x464DA0
#define CharacterZoneClient__FindAffectSlot_x                      0x4508D0
#define CharacterZoneClient__BardCastBard_x                        0x449FD0
#define CharacterZoneClient__GetMaxEffects_x                       0x448D10
#define CharacterZoneClient__GetEffect_x                           0x44AA80
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x450730
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x448EB0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44F280

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x665FA0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x674360

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58FE10
#define CButtonWnd__CButtonWnd_x                                   0x8D0B50

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68F510
#define CChatManager__InitContextMenu_x                            0x690660
#define CChatManager__FreeChatWindow_x                             0x68EFA0
#define CChatManager__GetLockedActiveChatWindow_x                  0x698730
#define CChatManager__SetLockedActiveChatWindow_x                  0x68F4E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DAB20
#define CContextMenu__dCContextMenu_x                              0x8DAD30
#define CContextMenu__AddMenuItem_x                                0x8DAD40
#define CContextMenu__RemoveMenuItem_x                             0x8DB020
#define CContextMenu__RemoveAllMenuItems_x                         0x8DB040
#define CContextMenu__CheckMenuItem_x                              0x8DB0C0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8C70D0
#define CContextMenuManager__RemoveMenu_x                          0x8C7460
#define CContextMenuManager__PopupMenu_x                           0x8C78B0
#define CContextMenuManager__Flush_x                               0x8C7140
#define CContextMenuManager__GetMenu_x                             0x4193B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87ACE0
#define CChatService__GetFriendName_x                              0x87ACF0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x696270
#define CChatWindow__Clear_x                                       0x695B50
#define CChatWindow__WndNotification_x                             0x696B80

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CAF30
#define CComboWnd__Draw_x                                          0x8CB140
#define CComboWnd__GetCurChoice_x                                  0x8CACE0
#define CComboWnd__GetListRect_x                                   0x8CB3E0
#define CComboWnd__GetTextRect_x                                   0x8CAFA0
#define CComboWnd__InsertChoice_x                                  0x8CB450
#define CComboWnd__SetColors_x                                     0x8CAC70
#define CComboWnd__SetChoice_x                                     0x8CACA0
#define CComboWnd__GetItemCount_x                                  0x8CACD0
#define CComboWnd__GetCurChoiceText_x                              0x8CAD20

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A0480
#define CContainerWnd__vftable_x                                   0xADBE90

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BE800
#define CDisplay__GetClickedActor_x                                0x4B7120
#define CDisplay__GetUserDefinedColor_x                            0x4B5D00
#define CDisplay__GetWorldFilePath_x                               0x4B5150
#define CDisplay__is3dON_x                                         0x4B45E0
#define CDisplay__ReloadUI_x                                       0x4C9DD0
#define CDisplay__WriteTextHD2_x                                   0x4BABC0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F1050

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DF060
#define CEditWnd__GetCharIndexPt_x                                 0x8E00E0
#define CEditWnd__GetDisplayString_x                               0x8DF210
#define CEditWnd__GetHorzOffset_x                                  0x8DF550
#define CEditWnd__GetLineForPrintableChar_x                        0x8DFBB0
#define CEditWnd__GetSelStartPt_x                                  0x8E0390
#define CEditWnd__GetSTMLSafeText_x                                0x8DF6E0
#define CEditWnd__PointFromPrintableChar_x                         0x8DFCA0
#define CEditWnd__SelectableCharFromPoint_x                        0x8DFE20
#define CEditWnd__SetEditable_x                                    0x8DF6B0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x561930
#define CEverQuest__ClickedPlayer_x                                0x55B5F0
#define CEverQuest__CreateTargetIndicator_x                        0x55C4E0
#define CEverQuest__DeleteTargetIndicator_x                        0x55C560
#define CEverQuest__DoTellWindow_x                                 0x475EE0
#define CEverQuest__OutputTextToLog_x                              0x475B40
#define CEverQuest__DropHeldItemOnGround_x                         0x571DD0
#define CEverQuest__dsp_chat_x                                     0x476220
#define CEverQuest__trimName_x                                     0x557F20
#define CEverQuest__Emote_x                                        0x570120
#define CEverQuest__EnterZone_x                                    0x56B290
#define CEverQuest__GetBodyTypeDesc_x                              0x555980
#define CEverQuest__GetClassDesc_x                                 0x55ED70
#define CEverQuest__GetClassThreeLetterCode_x                      0x55F370
#define CEverQuest__GetDeityDesc_x                                 0x556260
#define CEverQuest__GetLangDesc_x                                  0x555D10
#define CEverQuest__GetRaceDesc_x                                  0x55F530
#define CEverQuest__InterpretCmd_x                                 0x5630B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x576C00
#define CEverQuest__LMouseUp_x                                     0x578CF0
#define CEverQuest__RightClickedOnPlayer_x                         0x577710
#define CEverQuest__RMouseUp_x                                     0x578760
#define CEverQuest__SetGameState_x                                 0x55BEB0
#define CEverQuest__UPCNotificationFlush_x                         0x553790
#define CEverQuest__IssuePetCommand_x                              0x563A90

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B10D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B1130
#define CGaugeWnd__Draw_x                                          0x6B1560

// CGuild
#define CGuild__FindMemberByName_x                                 0x43AC80
#define CGuild__GetGuildName_x                                     0x43B150
#define CGuild__GetGuildIndex_x                                    0x43C320

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CD5B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DA750
#define CInvSlotMgr__MoveItem_x                                    0x6DB600
#define CInvSlotMgr__SelectSlot_x                                  0x6DA800

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D9C00
#define CInvSlot__SliderComplete_x                                 0x6D7410
#define CInvSlot__GetItemBase_x                                    0x6D68B0
#define CInvSlot__UpdateItem_x                                     0x6D6E30

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DCA30
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6DDB50

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A3130
#define CItemDisplayWnd__UpdateStrings_x                           0x6DEC30
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6EB6F0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6EBC00
#define CItemDisplayWnd__SetItem_x                                 0x6F1400

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7DA370

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6E5230

// CLabel 
#define CLabel__Draw_x                                             0x6F80A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B6CB0
#define CListWnd__dCListWnd_x                                      0x8B7ED0
#define CListWnd__AddColumn_x                                      0x8B7E70
#define CListWnd__AddColumn1_x                                     0x8B7510
#define CListWnd__AddLine_x                                        0x8B6F70
#define CListWnd__AddString_x                                      0x8B7190
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B3F50
#define CListWnd__CalculateVSBRange_x                              0x8B6170
#define CListWnd__ClearSel_x                                       0x8B3270
#define CListWnd__ClearAllSel_x                                    0x8B3220
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B6B40
#define CListWnd__Compare_x                                        0x8B4AC0
#define CListWnd__Draw_x                                           0x8B5D80
#define CListWnd__DrawColumnSeparators_x                           0x8B5C10
#define CListWnd__DrawHeader_x                                     0x8B3530
#define CListWnd__DrawItem_x                                       0x8B5150
#define CListWnd__DrawLine_x                                       0x8B58B0
#define CListWnd__DrawSeparator_x                                  0x8B5CB0
#define CListWnd__EnableLine_x                                     0x8B3450
#define CListWnd__EnsureVisible_x                                  0x8B40B0
#define CListWnd__ExtendSel_x                                      0x8B5060
#define CListWnd__GetColumnMinWidth_x                              0x8B2C20
#define CListWnd__GetColumnWidth_x                                 0x8B2B50
#define CListWnd__GetCurSel_x                                      0x8B2320
#define CListWnd__GetItemAtPoint_x                                 0x8B4340
#define CListWnd__GetItemAtPoint1_x                                0x8B43B0
#define CListWnd__GetItemData_x                                    0x8B2660
#define CListWnd__GetItemHeight_x                                  0x8B3BB0
#define CListWnd__GetItemIcon_x                                    0x8B2850
#define CListWnd__GetItemRect_x                                    0x8B4180
#define CListWnd__GetItemText_x                                    0x8B2700
#define CListWnd__GetSelList_x                                     0x8B7400
#define CListWnd__GetSeparatorRect_x                               0x8B49E0
#define CListWnd__InsertLine_x                                     0x8B7370
#define CListWnd__RemoveLine_x                                     0x8B7380
#define CListWnd__SetColors_x                                      0x8B2470
#define CListWnd__SetColumnJustification_x                         0x8B2EB0
#define CListWnd__SetColumnWidth_x                                 0x8B2BD0
#define CListWnd__SetCurSel_x                                      0x8B2360
#define CListWnd__SetItemColor_x                                   0x8B6830
#define CListWnd__SetItemData_x                                    0x8B32D0
#define CListWnd__SetItemText_x                                    0x8B6670
#define CListWnd__ShiftColumnSeparator_x                           0x8B6500
#define CListWnd__Sort_x                                           0x8B7FD0
#define CListWnd__ToggleSel_x                                      0x8B31A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7110E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x732720
#define CMerchantWnd__RequestBuyItem_x                             0x7397B0
#define CMerchantWnd__RequestSellItem_x                            0x73A270
#define CMerchantWnd__SelectRecoverySlot_x                         0x7329D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x731BD0
#define CMerchantWnd__ActualSelect_x                               0x736680

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x849220
#define CPacketScrambler__hton_x                                   0x849230

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D5A60
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D5B40
#define CSidlManager__CreateLabel_x                                0x79AA60
#define CSidlManager__CreateXWndFromTemplate_x                     0x8D4000
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D5E20

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8CCFB0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8CCEA0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F0F30
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CD8D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CEA80
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CEB30
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CE000
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CD280
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CC9D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CD470
#define CSidlScreenWnd__Init1_x                                    0x8CE750
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CD980
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CCB90
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CE240
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CC630
#define CSidlScreenWnd__StoreIniVis_x                              0x8CC980
#define CSidlScreenWnd__WndNotification_x                          0x8CE4D0
#define CSidlScreenWnd__GetChildItem_x                             0x8CCAA0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C03D0
#define CSidlScreenWnd__m_layoutCopy_x                             0x171C048

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FBF50
#define CSkillMgr__GetSkillCap_x                                   0x5FC130
#define CSkillMgr__GetNameToken_x                                  0x5FBB00

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F01E0
#define CSliderWnd__SetValue_x                                     0x8F03B0
#define CSliderWnd__SetNumTicks_x                                  0x8F0B30

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A0D90

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EA6F0
#define CStmlWnd__CalculateHSBRange_x                              0x8E2DF0
#define CStmlWnd__CalculateVSBRange_x                              0x8E2D60
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E2F70
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E3770
#define CStmlWnd__ForceParseNow_x                                  0x8EB070
#define CStmlWnd__GetNextTagPiece_x                                0x8E3670
#define CStmlWnd__GetSTMLText_x                                    0x483CA0
#define CStmlWnd__GetVisibleText_x                                 0x8E41C0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E6620
#define CStmlWnd__MakeStmlColorTag_x                               0x8E2060
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E20C0
#define CStmlWnd__SetSTMLText_x                                    0x8E7E80
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EA390
#define CStmlWnd__UpdateHistoryString_x                            0x8E5100

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EE560
#define CTabWnd__DrawCurrentPage_x                                 0x8EDDF0
#define CTabWnd__DrawTab_x                                         0x8EDBC0
#define CTabWnd__GetCurrentPage_x                                  0x8EE1A0
#define CTabWnd__GetPageInnerRect_x                                0x8ED8B0
#define CTabWnd__GetTabInnerRect_x                                 0x8EDAB0
#define CTabWnd__GetTabRect_x                                      0x8ED980
#define CTabWnd__InsertPage_x                                      0x8EE850
#define CTabWnd__SetPage_x                                         0x8EE1D0
#define CTabWnd__SetPageRect_x                                     0x8EE4A0
#define CTabWnd__UpdatePage_x                                      0x8EE7F0
#define CTabWnd__GetPageFromTabIndex_x                             0x8EDB10
#define CTabWnd__GetCurrentTabIndex_x                              0x8ED840

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6DDD00
#define CPageWnd__SetTabText_x                                     0x8F9FA0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436800

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CA8E0
#define CTextureFont__GetTextExtent_x                              0x8CA640

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6348B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F6390

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B0480

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59D5B0
#define CXStr__CXStr1_x                                            0x8A5B80
#define CXStr__CXStr3_x                                            0x8936F0
#define CXStr__dCXStr_x                                            0x744A70
#define CXStr__operator_equal_x                                    0x893860
#define CXStr__operator_equal1_x                                   0x8938B0
#define CXStr__operator_plus_equal1_x                              0x8949B0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BF620
#define CXWnd__Center_x                                            0x8C56A0
#define CXWnd__ClrFocus_x                                          0x8BF200
#define CXWnd__Destroy_x                                           0x8C6190
#define CXWnd__DoAllDrawing_x                                      0x8C52D0
#define CXWnd__DrawChildren_x                                      0x8C5480
#define CXWnd__DrawColoredRect_x                                   0x8BF9F0
#define CXWnd__DrawTooltip_x                                       0x8BFCA0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C4290
#define CXWnd__GetBorderFrame_x                                    0x8C00D0
#define CXWnd__GetChildWndAt_x                                     0x8C6070
#define CXWnd__GetClientClipRect_x                                 0x8BFEA0
#define CXWnd__GetScreenClipRect_x                                 0x8C4980
#define CXWnd__GetScreenRect_x                                     0x8C0280
#define CXWnd__GetTooltipRect_x                                    0x8BFB30
#define CXWnd__GetWindowTextA_x                                    0x4270B0
#define CXWnd__IsActive_x                                          0x8BAC80
#define CXWnd__IsDescendantOf_x                                    0x8C0010
#define CXWnd__IsReallyVisible_x                                   0x8C32D0
#define CXWnd__IsType_x                                            0x8C5710
#define CScreenPieceTemplate__IsType_x                             0x8F2C10
#define CXWnd__Move_x                                              0x8C2A50
#define CXWnd__Move1_x                                             0x8C4FB0
#define CXWnd__ProcessTransition_x                                 0x8BF5C0
#define CXWnd__Refade_x                                            0x8BF3A0
#define CXWnd__Resize_x                                            0x8C0330
#define CXWnd__Right_x                                             0x8C4780
#define CXWnd__SetFocus_x                                          0x8C1BE0
#define CXWnd__SetFont_x                                           0x8BF250
#define CXWnd__SetKeyTooltip_x                                     0x8C05A0
#define CXWnd__SetMouseOver_x                                      0x8C4CB0
#define CXWnd__StartFade_x                                         0x8BF670
#define CXWnd__GetChildItem_x                                      0x8C4BF0
#define CXWnd__SetParent_x                                         0x8C6020

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BC520
#define CXWndManager__DrawWindows_x                                0x8BC160
#define CXWndManager__GetKeyboardFlags_x                           0x8BA7B0
#define CXWndManager__HandleKeyboardMsg_x                          0x8BB110
#define CXWndManager__RemoveWnd_x                                  0x8BAE10

// CDBStr
#define CDBStr__GetString_x                                        0x4B2B90

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4518D0
#define EQ_Character__Cur_HP_x                                     0x466260
#define EQ_Character__Cur_Mana_x                                   0x45A040
#define EQ_Character__GetAACastingTimeModifier_x                   0x44AB60
#define EQ_Character__GetFocusCastingTimeModifier_x                0x442E90
#define EQ_Character__GetFocusRangeModifier_x                      0x442EF0
#define EQ_Character__GetHPRegen_x                                 0x469440
#define EQ_Character__GetEnduranceRegen_x                          0x465870
#define EQ_Character__GetManaRegen_x                               0x4699E0
#define EQ_Character__Max_Endurance_x                              0x5C2A20
#define EQ_Character__Max_HP_x                                     0x45CBB0
#define EQ_Character__Max_Mana_x                                   0x5C2850
#define EQ_Character__doCombatAbility_x                            0x5BFF20
#define EQ_Character__UseSkill_x                                   0x4703C0
#define EQ_Character__GetConLevel_x                                0x5B5490
#define EQ_Character__IsExpansionFlag_x                            0x4265E0
#define EQ_Character__TotalEffect_x                                0x44EC00
#define EQ_Character__GetPCSpellAffect_x                           0x44AF60
#define EQ_Character__SpellDuration_x                              0x448F00
#define EQ_Character__FindItemByRecord_x                           0x4638D0
#define EQ_Character__GetAdjustedSkill_x                           0x466A10
#define EQ_Character__GetBaseSkill_x                               0x45CA90

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x866780

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5CA9E0

//PcClient
#define PcClient__PcClient_x                                       0x5B72E0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446210
#define CCharacterSelect__EnterWorld_x                             0x4459E0
#define CCharacterSelect__Quit_x                                   0x4445C0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x595870
#define EQ_Item__CreateItemTagString_x                             0x847B50
#define EQ_Item__IsStackable_x                                     0x83D210
#define EQ_Item__GetImageNum_x                                     0x83FCD0
#define EQ_Item__CreateItemClient_x                                0x596460
#define EQ_Item__GetItemValue_x                                    0x846880
#define EQ_Item__ValueSellMerchant_x                               0x848E70
#define EQ_Item__IsKeyRingItem_x                                   0x83DD00
#define EQ_Item__CanGoInBag_x                                      0x595A00
#define EQ_Item__GetMaxItemCount_x                                 0x83D100
#define EQ_Item__GetHeldItem_x                                     0x83EAF0
#define EQ_Item__GetAugmentFitBySlot_x                             0x848CA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D2B60
#define EQ_LoadingS__Array_x                                       0xBF7A78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C4F30
#define EQ_PC__GetAlternateAbilityId_x                             0x851310
#define EQ_PC__GetCombatAbility_x                                  0x8513A0
#define EQ_PC__GetCombatAbilityTimer_x                             0x84BED0
#define EQ_PC__GetItemRecastTimer_x                                0x5BE6D0
#define EQ_PC__HasLoreItem_x                                       0x5B8A90
#define EQ_PC__AlertInventoryChanged_x                             0x5B5460
#define EQ_PC__GetPcZoneClient_x                                   0x5DEF40
#define EQ_PC__RemoveMyAffect_x                                    0x5BDBA0
#define EQ_PC__GetKeyRingItems_x                                   0x84C2F0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x85EFF0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x853280

// EQItemList 
#define EQItemList__EQItemList_x                                   0x51DE10
#define EQItemList__add_object_x                                   0x54A6D0
#define EQItemList__add_item_x                                     0x51DD50
#define EQItemList__delete_item_x                                  0x51E200
#define EQItemList__FreeItemList_x                                 0x51E100

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B1EA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CA780
#define EQPlayer__dEQPlayer_x                                      0x5D2DB0
#define EQPlayer__DoAttack_x                                       0x5E48B0
#define EQPlayer__EQPlayer_x                                       0x5D54D0
#define EQPlayer__SetNameSpriteState_x                             0x5CFC70
#define EQPlayer__SetNameSpriteTint_x                              0x5CBB90
#define PlayerBase__HasProperty_j_x                                0x923A80
#define EQPlayer__IsTargetable_x                                   0x923D20
#define EQPlayer__CanSee_x                                         0x924280
#define PlayerZoneClient__ChangeHeight_x                           0x5E4770
#define EQPlayer__CanSeeTargetIndicator_x                          0x924370
#define PlayerBase__GetVisibilityLineSegment_x                     0x924010

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5DF0F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D9590
#define EQPlayerManager__GetSpawnByName_x                          0x5D99F0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D95C0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59B950
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59B990
#define KeypressHandler__ClearCommandStateArray_x                  0x59B540
#define KeypressHandler__HandleKeyDown_x                           0x599EA0
#define KeypressHandler__HandleKeyUp_x                             0x59A1C0
#define KeypressHandler__SaveKeymapping_x                          0x59B610

// MapViewMap 
#define MapViewMap__Clear_x                                        0x709A70
#define MapViewMap__SaveEx_x                                       0x70CDA0

#define PlayerPointManager__GetAltCurrency_x                       0x864840

// StringTable 
#define StringTable__getString_x                                   0x85F320

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C24B0
#define PcZoneClient__RemovePetEffect_x                            0x5BEBA0
#define PcZoneClient__HasAlternateAbility_x                        0x5BF540
#define PcZoneClient__GetCurrentMod_x                              0x45C060
#define PcZoneClient__GetModCap_x                                  0x4597A0
#define PcZoneClient__CanEquipItem_x                               0x5BFA60
#define PcZoneClient__GetItemByID_x                                0x5C42A0
#define PcZoneClient__GetItemByItemClass_x                         0x5C4E50

//Doors
#define EQSwitch__UseSwitch_x                                      0x5520C0

//IconCache
#define IconCache__GetIcon_x                                       0x6A6900

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69D7E0
#define CContainerMgr__CloseContainer_x                            0x69E000

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76A950

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58E830

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4ECB40
#define EQ_Spell__SpellAffects_x                                   0x4EA1E0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4EA250
#define CharacterZoneClient__CalcAffectChange_x                    0x44ADF0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A030
#define CLootWnd__LootAll_x                                        0x6FF2E0
#define CLootWnd__RequestLootSlot_x                                0x6FFAF0
#define EQ_Spell__IsStackable_x                                    0x448AD0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x448B80
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43E6F0
#define EQ_Spell__IsSPAStacking_x                                  0x4E9D90
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4E9860
#define EQ_Spell__IsNoRemove_x                                     0x434810
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4E9DB0

#define __IsResEffectSpell_x                                       0x448C00

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x870340

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B0060
#define CTargetWnd__WndNotification_x                              0x7AFB50
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B0240

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B5150

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E5770
#define EqSoundManager__PlayScriptMp3_x                            0x4E7210

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A1060

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DE690
#define CSidlManager__FindAnimation1_x                             0x8D3A30

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4DA270
#define CAltAbilityData__GetMercMaxRank_x                          0x4DA220
#define CAltAbilityData__GetMaxRank_x                              0x4CEBE0

//CTargetRing
#define CTargetRing__Cast_x                                        0x58C100

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x458740
#define CharacterBase__CreateItemGlobalIndex_x                     0x4750E0
#define CharacterBase__CreateItemIndex_x                           0x517350
#define CharacterBase__GetItemPossession_x                         0x443AC0
#define CharacterBase__GetItemByGlobalIndex_x                      0x874990
#define CharacterBase__GetEffectId_x                               0x458700

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x686550
#define CCastSpellWnd__IsBardSongPlaying_x                         0x685CB0

//messages
#define msg_spell_worn_off_x                                       0x4F4590
#define msg_new_text_x                                             0x4FDB50
#define msgTokenTextParam_x                                        0x4FA3B0

//SpellManager
#define SpellManager__vftable_x                                    0xAB8168
#define SpellManager__SpellManager_x                               0x47DDF0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x602EC0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x927DF0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F0C60
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43E610
#define ItemGlobalIndex__IsEquippedLocation_x                      0x448880
#define ItemGlobalIndex__IsValidIndex_x                            0x457FF0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x872800
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x871740

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F82F0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6A2540
#define CCursorAttachment__Deactivate_x                            0x6A1A80

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8EF6E0
