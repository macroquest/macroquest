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
#define __ExpectedVersionDate                                     "May  9 2017"
#define __ExpectedVersionTime                                     "15:07:28"
#define __ActualVersionDate_x                                      0xAD3288
#define __ActualVersionTime_x                                      0xAD3294

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5A2230
#define __MemChecker1_x                                            0x897EC0
#define __MemChecker2_x                                            0x637F10
#define __MemChecker3_x                                            0x637E60
#define __MemChecker4_x                                            0x7EA620
#define __EncryptPad0_x                                            0xC2D328
#define __EncryptPad1_x                                            0xD086E0
#define __EncryptPad2_x                                            0xC56B10
#define __EncryptPad3_x                                            0xC56710
#define __EncryptPad4_x                                            0xCF6CE0
#define __EncryptPad5_x                                            0x10B1370
#define __AC1_x                                                    0x7A9B05
#define __AC2_x                                                    0x55BEF7
#define __AC3_x                                                    0x55A070
#define __AC4_x                                                    0x56C151
#define __AC5_x                                                    0x57F20B
#define __AC6_x                                                    0x582DBE
#define __AC7_x                                                    0x57980C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FE4DFC

// Direct Input
#define DI8__Main_x                                                0x10B1348
#define DI8__Keyboard_x                                            0x10B134C
#define DI8__Mouse_x                                               0x10B1350
#define DI8__Mouse_Copy_x                                          0xF1F70C
#define DI8__Mouse_Check_x                                         0xFA9034
#define __AutoSkillArray_x                                         0xF20620
#define __Attack_x                                                 0xFA3C17
#define __Autofire_x                                               0xFA3C18
#define __BindList_x                                               0xC08050
#define g_eqCommandStates_x                                        0xF0E730
#define __Clicks_x                                                 0xF1F7C8
#define __CommandList_x                                            0xC0A6C8
#define __CurrentMapLabel_x                                        0x10B6DD0
#define __CurrentSocial_x                                          0xBD9424
#define __DoAbilityList_x                                          0xF55ECC
#define __do_loot_x                                                0x52AC40
#define __DrawHandler_x                                            0x171DC84
#define __GroupCount_x                                             0xF0FD62

#define __Guilds_x                                                 0xF15978
#define __gWorld_x                                                 0xF1221C
#define __HotkeyPage_x                                             0xF9C8CC
#define __HWnd_x                                                   0xFA9150
#define __InChatMode_x                                             0xF1F6F4
#define __LastTell_x                                               0xF215C8
#define __LMouseHeldTime_x                                         0xF1F834
#define __Mouse_x                                                  0x10B1354
#define __MouseLook_x                                              0xF1F78E
#define __MouseEventTime_x                                         0xFA441C
#define __gpbCommandEvent_x                                        0xF122E4
#define __NetStatusToggle_x                                        0xF1F791
#define __PCNames_x                                                0xF20BDC
#define __RangeAttackReady_x                                       0xF20904
#define __RMouseHeldTime_x                                         0xF1F830
#define __RunWalkState_x                                           0xF1F6F8
#define __ScreenMode_x                                             0xE5E418
#define __ScreenX_x                                                0xF1F6AC
#define __ScreenY_x                                                0xF1F6A8
#define __ScreenXMax_x                                             0xF1F6B0
#define __ScreenYMax_x                                             0xF1F6B4
#define __ServerHost_x                                             0xF0FCAC
#define __ServerName_x                                             0xF55E8C
#define __ShiftKeyDown_x                                           0xF1FD88
#define __ShowNames_x                                              0xF20AC4
#define __Socials_x                                                0xF55F8C
#define __SubscriptionType_x                                       0x10E4D94
#define __TargetAggroHolder_x                                      0x10B8FA4
#define __ZoneType_x                                               0xF1FB8C
#define __GroupAggro_x                                             0x10B8FE4
#define __LoginName_x                                              0xFA7C2C
#define __Inviter_x                                                0xFA3B94
#define __AttackOnAssist_x                                         0xF20A80
#define __UseTellWindows_x                                         0xF20D74

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF12308
#define instEQZoneInfo_x                                           0xF1F984
#define instKeypressHandler_x                                      0xFA4400
#define pinstActiveBanker_x                                        0xF122C0
#define pinstActiveCorpse_x                                        0xF122C4
#define pinstActiveGMaster_x                                       0xF122C8
#define pinstActiveMerchant_x                                      0xF122BC
#define pinstAggroInfo_x                                           0xD1BD88
#define pinstAltAdvManager_x                                       0xE5F4F8
#define pinstAuraMgr_x                                             0xD2C4F8
#define pinstBandageTarget_x                                       0xF122A8
#define pinstCamActor_x                                            0xE5EE48
#define pinstCDBStr_x                                              0xE5E3AC
#define pinstCDisplay_x                                            0xF122D0
#define pinstCEverQuest_x                                          0x10B14C8
#define pinstEverQuestInfo_x                                       0xF1F6A0
#define pinstCharData_x                                            0xF1228C
#define pinstCharSpawn_x                                           0xF122B4
#define pinstControlledMissile_x                                   0xF12288
#define pinstControlledPlayer_x                                    0xF122B4
#define pinstCSidlManager_x                                        0x171D074
#define pinstCXWndManager_x                                        0x171D06C
#define instDynamicZone_x                                          0xF1F540
#define pinstDZMember_x                                            0xF1F650
#define pinstDZTimerInfo_x                                         0xF1F654
#define pinstEQItemList_x                                          0xF0E984
#define pinstEQObjectList_x                                        0xF0F75C
#define instEQMisc_x                                               0xBF0690
#define pinstEQSoundManager_x                                      0xE5FAC8
#define instExpeditionLeader_x                                     0xF1F58A
#define instExpeditionName_x                                       0xF1F5CA
#define pinstGroup_x                                               0xF0FD5E
#define pinstImeManager_x                                          0x171D078
#define pinstLocalPlayer_x                                         0xF122A0
#define pinstMercenaryData_x                                       0xFA4A80
#define pinstMercenaryStats_x                                      0x10B90F0
#define pinstMercAltAbilities_x                                    0xE5F880
#define pinstModelPlayer_x                                         0xF122CC
#define pinstPCData_x                                              0xF1228C
#define pinstSkillMgr_x                                            0xFA58E8
#define pinstSpawnManager_x                                        0xFA51D0
#define pinstSpellManager_x                                        0xFA5A30
#define pinstSpellSets_x                                           0xF9C930
#define pinstStringTable_x                                         0xF12234
#define pinstSwitchManager_x                                       0xF0F8F0
#define pinstTarget_x                                              0xF122B8
#define pinstTargetObject_x                                        0xF12290
#define pinstTargetSwitch_x                                        0xF12294
#define pinstTaskMember_x                                          0xE5E2F8
#define pinstTrackTarget_x                                         0xF122AC
#define pinstTradeTarget_x                                         0xF1229C
#define instTributeActive_x                                        0xBF06B5
#define pinstViewActor_x                                           0xE5EE44
#define pinstWorldData_x                                           0xF12270
#define pinstZoneAddr_x                                            0xF1FC24
#define pinstPlayerPath_x                                          0xFA5230
#define pinstTargetIndicator_x                                     0xFA5BC8
#define pinstCTargetManager_x                                      0xFA5C28
#define EQObject_Top_x                                             0xF12280
#define pinstRealEstateItems_x                                     0xFA57D4

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE5ED60
#define pinstCAchievementsWnd_x                                    0xE5EDBC
#define pinstCTextOverlay_x                                        0xD1C288
#define pinstCAudioTriggersWindow_x                                0xD1C118
#define pinstCCharacterSelect_x                                    0xE5ECD0
#define pinstCFacePick_x                                           0xE5EC80
#define pinstCNoteWnd_x                                            0xE5EC88
#define pinstCBookWnd_x                                            0xE5EC90
#define pinstCPetInfoWnd_x                                         0xE5EC94
#define pinstCTrainWnd_x                                           0xE5EC98
#define pinstCSkillsWnd_x                                          0xE5EC9C
#define pinstCSkillsSelectWnd_x                                    0xE5ECA0
#define pinstCCombatSkillsSelectWnd_x                              0xE5ECA4
#define pinstCFriendsWnd_x                                         0xE5ECA8
#define pinstCAuraWnd_x                                            0xE5ECAC
#define pinstCRespawnWnd_x                                         0xE5ECB0
#define pinstCBandolierWnd_x                                       0xE5ECB4
#define pinstCPotionBeltWnd_x                                      0xE5ECB8
#define pinstCAAWnd_x                                              0xE5ECBC
#define pinstCGroupSearchFiltersWnd_x                              0xE5ECC0
#define pinstCLoadskinWnd_x                                        0xE5ECC4
#define pinstCAlarmWnd_x                                           0xE5ECC8
#define pinstCMusicPlayerWnd_x                                     0xE5ECCC
#define pinstCMailWnd_x                                            0xE5ECD4
#define pinstCMailCompositionWnd_x                                 0xE5ECD8
#define pinstCMailAddressBookWnd_x                                 0xE5ECDC
#define pinstCRaidWnd_x                                            0xE5ECE4
#define pinstCRaidOptionsWnd_x                                     0xE5ECE8
#define pinstCBreathWnd_x                                          0xE5ECEC
#define pinstCMapViewWnd_x                                         0xE5ECF0
#define pinstCMapToolbarWnd_x                                      0xE5ECF4
#define pinstCEditLabelWnd_x                                       0xE5ECF8
#define pinstCTargetWnd_x                                          0xE5ECFC
#define pinstCColorPickerWnd_x                                     0xE5ED00
#define pinstCPlayerWnd_x                                          0xE5ED04
#define pinstCOptionsWnd_x                                         0xE5ED08
#define pinstCBuffWindowNORMAL_x                                   0xE5ED0C
#define pinstCBuffWindowSHORT_x                                    0xE5ED10
#define pinstCharacterCreation_x                                   0xE5ED14
#define pinstCCursorAttachment_x                                   0xE5ED18
#define pinstCCastingWnd_x                                         0xE5ED1C
#define pinstCCastSpellWnd_x                                       0xE5ED20
#define pinstCSpellBookWnd_x                                       0xE5ED24
#define pinstCInventoryWnd_x                                       0xE5ED28
#define pinstCBankWnd_x                                            0xE5ED30
#define pinstCQuantityWnd_x                                        0xE5ED34
#define pinstCLootWnd_x                                            0xE5ED38
#define pinstCActionsWnd_x                                         0xE5ED3C
#define pinstCCombatAbilityWnd_x                                   0xE5ED44
#define pinstCMerchantWnd_x                                        0xE5ED48
#define pinstCTradeWnd_x                                           0xE5ED50
#define pinstCSelectorWnd_x                                        0xE5ED54
#define pinstCBazaarWnd_x                                          0xE5ED58
#define pinstCBazaarSearchWnd_x                                    0xE5ED5C
#define pinstCGiveWnd_x                                            0xE5ED78
#define pinstCTrackingWnd_x                                        0xE5ED80
#define pinstCInspectWnd_x                                         0xE5ED84
#define pinstCSocialEditWnd_x                                      0xE5ED88
#define pinstCFeedbackWnd_x                                        0xE5ED8C
#define pinstCBugReportWnd_x                                       0xE5ED90
#define pinstCVideoModesWnd_x                                      0xE5ED94
#define pinstCTextEntryWnd_x                                       0xE5ED9C
#define pinstCFileSelectionWnd_x                                   0xE5EDA0
#define pinstCCompassWnd_x                                         0xE5EDA4
#define pinstCPlayerNotesWnd_x                                     0xE5EDA8
#define pinstCGemsGameWnd_x                                        0xE5EDAC
#define pinstCTimeLeftWnd_x                                        0xE5EDB0
#define pinstCPetitionQWnd_x                                       0xE5EDCC
#define pinstCStoryWnd_x                                           0xE5EDD0
#define pinstCJournalTextWnd_x                                     0xE5EDD4
#define pinstCJournalCatWnd_x                                      0xE5EDD8
#define pinstCBodyTintWnd_x                                        0xE5EDDC
#define pinstCServerListWnd_x                                      0xE5EDE0
#define pinstCAvaZoneWnd_x                                         0xE5EDEC
#define pinstCBlockedBuffWnd_x                                     0xE5EDF0
#define pinstCBlockedPetBuffWnd_x                                  0xE5EDF4
#define pinstCInvSlotMgr_x                                         0xE5EE3C
#define pinstCContainerMgr_x                                       0xE5EE40
#define pinstCAdventureLeaderboardWnd_x                            0x10B1E78
#define pinstCAdventureRequestWnd_x                                0x10B1EF0
#define pinstCAltStorageWnd_x                                      0x10B21D0
#define pinstCAdventureStatsWnd_x                                  0x10B1F68
#define pinstCBarterMerchantWnd_x                                  0x10B2DB8
#define pinstCBarterSearchWnd_x                                    0x10B2E30
#define pinstCBarterWnd_x                                          0x10B2EA8
#define pinstCChatWindowManager_x                                  0x10B3538
#define pinstCDynamicZoneWnd_x                                     0x10B39E8
#define pinstCEQMainWnd_x                                          0x10B3B80
#define pinstCFellowshipWnd_x                                      0x10B397C
#define pinstCFindLocationWnd_x                                    0x10B3E50
#define pinstCGroupSearchWnd_x                                     0x10B4120
#define pinstCGroupWnd_x                                           0x10B4198
#define pinstCGuildBankWnd_x                                       0x10B4210
#define pinstCGuildMgmtWnd_x                                       0x10B6300
#define pinstCHotButtonWnd_x                                       0x10B63FC
#define pinstCHotButtonWnd1_x                                      0x10B63FC
#define pinstCHotButtonWnd2_x                                      0x10B6400
#define pinstCHotButtonWnd3_x                                      0x10B6404
#define pinstCHotButtonWnd4_x                                      0x10B6428
#define pinstCItemDisplayManager_x                                 0x10B6720
#define pinstCItemExpTransferWnd_x                                 0x10B679C
#define pinstCLFGuildWnd_x                                         0x10B6A78
#define pinstCMIZoneSelectWnd_x                                    0x10B7060
#define pinstCConfirmationDialog_x                                 0x10B7768
#define pinstCPopupWndManager_x                                    0x10B7768
#define pinstCProgressionSelectionWnd_x                            0x10B7858
#define pinstCPvPStatsWnd_x                                        0x10B7948
#define pinstCLargeDialogWnd_x                                     0x10B8050
#define pinstCTaskWnd_x                                            0x10B93D0
#define pinstCTaskSomething_x                                      0xD2CEA0
#define pinstCTaskTemplateSelectWnd_x                              0x10B9358
#define pinstCTipWndOFDAY_x                                        0x10B9538
#define pinstCTipWndCONTEXT_x                                      0x10B953C
#define pinstCTitleWnd_x                                           0x10B95B8
#define pinstCContextMenuManager_x                                 0x171CFE4
#define pinstCVoiceMacroWnd_x                                      0xFA6000
#define pinstCHtmlWnd_x                                            0xFA60F0
#define pinstIconCache_x                                           0x10B3B54
#define pinstCTradeskillWnd_x                                      0x10B96B8
#define pinstCAdvancedLootWnd_x                                    0xE5EE30
#define pinstRewardSelectionWnd_x                                  0x10B7E70
#define pinstEQSuiteTextureLoader_x                                0xD0A458

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x541DE0
#define __ConvertItemTags_x                                        0x52F740
#define __ExecuteCmd_x                                             0x51A2B0
#define __EQGetTime_x                                              0x897860
#define __get_melee_range_x                                        0x520F10
#define __GetGaugeValueFromEQ_x                                    0x7A86C0
#define __GetLabelFromEQ_x                                         0x7A9A90
#define __ToggleKeyRingItem_x                                      0x488800
#define __GetXTargetType_x                                         0x928360
#define __LoadFrontEnd_x                                           0x6375E0
#define __NewUIINI_x                                               0x7A8090
#define __ProcessGameEvents_x                                      0x57B5A0
#define __ProcessMouseEvent_x                                      0x57AD40
#define CrashDetected_x                                            0x638FA0
#define wwsCrashReportCheckForUploader_x                           0x7F6200
#define __AppCrashWrapper_x                                        0xC56704
#define __pCrashHandler_x                                          0x10C6568
#define __CrashHandler_x                                           0x7F5C90
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F8430
#define DrawNetStatus_x                                            0x5B1D30
#define Util__FastTime_x                                           0x897500
#define Expansion_HoT_x                                            0xF20A70
#define __HelpPath_x                                               0xFA4188
#define __STMLToText_x                                             0x8DDA50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x422F60
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DD00
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DAE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D0570
#define AltAdvManager__IsAbilityReady_x                            0x4D05E0
#define AltAdvManager__GetAAById_x                                 0x4D0AD0
#define AltAdvManager__CanTrainAbility_x                           0x4D1700
#define AltAdvManager__CanSeeAbility_x                             0x4D12C0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x469EB0
#define CharacterZoneClient__HasSkill_x                            0x466D60
#define CharacterZoneClient__MakeMeVisible_x                       0x46B440
#define CharacterZoneClient__IsStackBlocked_x                      0x44B500
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44A9C0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464CE0
#define CharacterZoneClient__GetItemCountInInventory_x             0x464DC0
#define CharacterZoneClient__GetCursorItemCount_x                  0x464EA0
#define CharacterZoneClient__FindAffectSlot_x                      0x450A70
#define CharacterZoneClient__BardCastBard_x                        0x44A140
#define CharacterZoneClient__GetMaxEffects_x                       0x448E80
#define CharacterZoneClient__GetEffect_x                           0x44ABF0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4508D0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449020
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44F420

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x666DE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x675120

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x590EC0
#define CButtonWnd__CButtonWnd_x                                   0x8D1DB0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x690230
#define CChatManager__InitContextMenu_x                            0x691380
#define CChatManager__FreeChatWindow_x                             0x68FCC0
#define CChatManager__GetLockedActiveChatWindow_x                  0x699400
#define CChatManager__SetLockedActiveChatWindow_x                  0x690200

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DBDC0
#define CContextMenu__dCContextMenu_x                              0x8DBFC0
#define CContextMenu__AddMenuItem_x                                0x8DBFD0
#define CContextMenu__RemoveMenuItem_x                             0x8DC2B0
#define CContextMenu__RemoveAllMenuItems_x                         0x8DC2D0
#define CContextMenu__CheckMenuItem_x                              0x8DC350

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8C8350
#define CContextMenuManager__RemoveMenu_x                          0x8C86F0
#define CContextMenuManager__PopupMenu_x                           0x8C8B40
#define CContextMenuManager__Flush_x                               0x8C83C0
#define CContextMenuManager__GetMenu_x                             0x4193D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87BC30
#define CChatService__GetFriendName_x                              0x87BC40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x696F60
#define CChatWindow__Clear_x                                       0x696840
#define CChatWindow__WndNotification_x                             0x697860

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CC1A0
#define CComboWnd__Draw_x                                          0x8CC3B0
#define CComboWnd__GetCurChoice_x                                  0x8CBF50
#define CComboWnd__GetListRect_x                                   0x8CC650
#define CComboWnd__GetTextRect_x                                   0x8CC210
#define CComboWnd__InsertChoice_x                                  0x8CC6C0
#define CComboWnd__SetColors_x                                     0x8CBEE0
#define CComboWnd__SetChoice_x                                     0x8CBF10
#define CComboWnd__GetItemCount_x                                  0x8CBF40
#define CComboWnd__GetCurChoiceText_x                              0x8CBF90

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A1170
#define CContainerWnd__vftable_x                                   0xADCE90

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BE8B0
#define CDisplay__GetClickedActor_x                                0x4B71E0
#define CDisplay__GetUserDefinedColor_x                            0x4B5DC0
#define CDisplay__GetWorldFilePath_x                               0x4B5210
#define CDisplay__is3dON_x                                         0x4B46A0
#define CDisplay__ReloadUI_x                                       0x4C9E80
#define CDisplay__WriteTextHD2_x                                   0x4BAC70

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F22C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E0300
#define CEditWnd__GetCharIndexPt_x                                 0x8E1380
#define CEditWnd__GetDisplayString_x                               0x8E04B0
#define CEditWnd__GetHorzOffset_x                                  0x8E07F0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E0E50
#define CEditWnd__GetSelStartPt_x                                  0x8E1630
#define CEditWnd__GetSTMLSafeText_x                                0x8E0980
#define CEditWnd__PointFromPrintableChar_x                         0x8E0F40
#define CEditWnd__SelectableCharFromPoint_x                        0x8E10C0
#define CEditWnd__SetEditable_x                                    0x8E0950

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x562980
#define CEverQuest__ClickedPlayer_x                                0x55C640
#define CEverQuest__CreateTargetIndicator_x                        0x55D530
#define CEverQuest__DeleteTargetIndicator_x                        0x55D5B0
#define CEverQuest__DoTellWindow_x                                 0x475FE0
#define CEverQuest__OutputTextToLog_x                              0x475C40
#define CEverQuest__DropHeldItemOnGround_x                         0x572E20
#define CEverQuest__dsp_chat_x                                     0x476320
#define CEverQuest__trimName_x                                     0x558F70
#define CEverQuest__Emote_x                                        0x571170
#define CEverQuest__EnterZone_x                                    0x56C2E0
#define CEverQuest__GetBodyTypeDesc_x                              0x5569D0
#define CEverQuest__GetClassDesc_x                                 0x55FDC0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5603C0
#define CEverQuest__GetDeityDesc_x                                 0x5572B0
#define CEverQuest__GetLangDesc_x                                  0x556D60
#define CEverQuest__GetRaceDesc_x                                  0x560580
#define CEverQuest__InterpretCmd_x                                 0x564100
#define CEverQuest__LeftClickedOnPlayer_x                          0x577C60
#define CEverQuest__LMouseUp_x                                     0x579D60
#define CEverQuest__RightClickedOnPlayer_x                         0x578770
#define CEverQuest__RMouseUp_x                                     0x5797C0
#define CEverQuest__SetGameState_x                                 0x55CF00
#define CEverQuest__UPCNotificationFlush_x                         0x5547F0
#define CEverQuest__IssuePetCommand_x                              0x564AE0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B1D40
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B1DA0
#define CGaugeWnd__Draw_x                                          0x6B21D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43ADA0
#define CGuild__GetGuildName_x                                     0x43B270
#define CGuild__GetGuildIndex_x                                    0x43C440

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CE2F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DB4B0
#define CInvSlotMgr__MoveItem_x                                    0x6DC360
#define CInvSlotMgr__SelectSlot_x                                  0x6DB560

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DA960
#define CInvSlot__SliderComplete_x                                 0x6D8170
#define CInvSlot__GetItemBase_x                                    0x6D75F0
#define CInvSlot__UpdateItem_x                                     0x6D7B70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DD7B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6DE8D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A40E0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DF9B0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6EC480
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6EC9C0
#define CItemDisplayWnd__SetItem_x                                 0x6F22C0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7DB2D0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6E5FD0

// CLabel 
#define CLabel__Draw_x                                             0x6F8F50

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B7E00
#define CListWnd__dCListWnd_x                                      0x8B9020
#define CListWnd__AddColumn_x                                      0x8B8FC0
#define CListWnd__AddColumn1_x                                     0x8B8660
#define CListWnd__AddLine_x                                        0x8B80C0
#define CListWnd__AddString_x                                      0x8B82E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B50E0
#define CListWnd__CalculateVSBRange_x                              0x8B72D0
#define CListWnd__ClearSel_x                                       0x8B4420
#define CListWnd__ClearAllSel_x                                    0x8B43D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B7C90
#define CListWnd__Compare_x                                        0x8B5C20
#define CListWnd__Draw_x                                           0x8B6EE0
#define CListWnd__DrawColumnSeparators_x                           0x8B6D70
#define CListWnd__DrawHeader_x                                     0x8B46E0
#define CListWnd__DrawItem_x                                       0x8B62B0
#define CListWnd__DrawLine_x                                       0x8B6A10
#define CListWnd__DrawSeparator_x                                  0x8B6E10
#define CListWnd__EnableLine_x                                     0x8B4600
#define CListWnd__EnsureVisible_x                                  0x8B5240
#define CListWnd__ExtendSel_x                                      0x8B61C0
#define CListWnd__GetColumnMinWidth_x                              0x8B3DD0
#define CListWnd__GetColumnWidth_x                                 0x8B3D00
#define CListWnd__GetCurSel_x                                      0x8B34D0
#define CListWnd__GetItemAtPoint_x                                 0x8B54B0
#define CListWnd__GetItemAtPoint1_x                                0x8B5520
#define CListWnd__GetItemData_x                                    0x8B3810
#define CListWnd__GetItemHeight_x                                  0x8B4D50
#define CListWnd__GetItemIcon_x                                    0x8B3A00
#define CListWnd__GetItemRect_x                                    0x8B5300
#define CListWnd__GetItemText_x                                    0x8B38B0
#define CListWnd__GetSelList_x                                     0x8B8550
#define CListWnd__GetSeparatorRect_x                               0x8B5B50
#define CListWnd__InsertLine_x                                     0x8B84C0
#define CListWnd__RemoveLine_x                                     0x8B84D0
#define CListWnd__SetColors_x                                      0x8B3620
#define CListWnd__SetColumnJustification_x                         0x8B4060
#define CListWnd__SetColumnWidth_x                                 0x8B3D80
#define CListWnd__SetCurSel_x                                      0x8B3510
#define CListWnd__SetItemColor_x                                   0x8B7980
#define CListWnd__SetItemData_x                                    0x8B4480
#define CListWnd__SetItemText_x                                    0x8B77C0
#define CListWnd__ShiftColumnSeparator_x                           0x8B7650
#define CListWnd__Sort_x                                           0x8B9120
#define CListWnd__ToggleSel_x                                      0x8B4350

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x711FF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7335B0
#define CMerchantWnd__RequestBuyItem_x                             0x73A650
#define CMerchantWnd__RequestSellItem_x                            0x73B120
#define CMerchantWnd__SelectRecoverySlot_x                         0x733860
#define CMerchantWnd__SelectBuySellSlot_x                          0x732A60
#define CMerchantWnd__ActualSelect_x                               0x737520

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84A1B0
#define CPacketScrambler__hton_x                                   0x84A1C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D6D00
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D6DE0
#define CSidlManager__CreateLabel_x                                0x79B920
#define CSidlManager__CreateXWndFromTemplate_x                     0x8D52B0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D70C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8CE210
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8CE110
#define CSidlScreenWnd__ConvertToRes_x                             0x8F21A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CEB10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CFCD0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CFD80
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CF250
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CE4C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CDC40
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CE6B0
#define CSidlScreenWnd__Init1_x                                    0x8CF9A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CEBC0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CDE00
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CF490
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CD8A0
#define CSidlScreenWnd__StoreIniVis_x                              0x8CDBF0
#define CSidlScreenWnd__WndNotification_x                          0x8CF720
#define CSidlScreenWnd__GetChildItem_x                             0x8CDD10
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C1590
#define CSidlScreenWnd__m_layoutCopy_x                             0x171D048

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FCF70
#define CSkillMgr__GetSkillCap_x                                   0x5FD150
#define CSkillMgr__GetNameToken_x                                  0x5FCB20

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F1450
#define CSliderWnd__SetValue_x                                     0x8F1620
#define CSliderWnd__SetNumTicks_x                                  0x8F1DA0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A1D40

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EB970
#define CStmlWnd__CalculateHSBRange_x                              0x8E40A0
#define CStmlWnd__CalculateVSBRange_x                              0x8E4010
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E4220
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E4A20
#define CStmlWnd__ForceParseNow_x                                  0x8EC2F0
#define CStmlWnd__GetNextTagPiece_x                                0x8E4920
#define CStmlWnd__GetSTMLText_x                                    0x483CD0
#define CStmlWnd__GetVisibleText_x                                 0x8E5470
#define CStmlWnd__InitializeWindowVariables_x                      0x8E78B0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E3310
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E3370
#define CStmlWnd__SetSTMLText_x                                    0x8E9100
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EB610
#define CStmlWnd__UpdateHistoryString_x                            0x8E63A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EF7D0
#define CTabWnd__DrawCurrentPage_x                                 0x8EF060
#define CTabWnd__DrawTab_x                                         0x8EEE30
#define CTabWnd__GetCurrentPage_x                                  0x8EF410
#define CTabWnd__GetPageInnerRect_x                                0x8EEB20
#define CTabWnd__GetTabInnerRect_x                                 0x8EED20
#define CTabWnd__GetTabRect_x                                      0x8EEBF0
#define CTabWnd__InsertPage_x                                      0x8EFAC0
#define CTabWnd__SetPage_x                                         0x8EF440
#define CTabWnd__SetPageRect_x                                     0x8EF710
#define CTabWnd__UpdatePage_x                                      0x8EFA60
#define CTabWnd__GetPageFromTabIndex_x                             0x8EED80
#define CTabWnd__GetCurrentTabIndex_x                              0x8EEAB0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6DEA80
#define CPageWnd__SetTabText_x                                     0x8FB190

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436920

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CBB50
#define CTextureFont__GetTextExtent_x                              0x8CB8B0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x635860

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F75D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B15D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59E6B0
#define CXStr__CXStr1_x                                            0x8F6340
#define CXStr__CXStr3_x                                            0x8947A0
#define CXStr__dCXStr_x                                            0x4D21D0
#define CXStr__operator_equal_x                                    0x894910
#define CXStr__operator_equal1_x                                   0x894960
#define CXStr__operator_plus_equal1_x                              0x895A60

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C07C0
#define CXWnd__Center_x                                            0x8C6970
#define CXWnd__ClrFocus_x                                          0x8C03A0
#define CXWnd__Destroy_x                                           0x8C7450
#define CXWnd__DoAllDrawing_x                                      0x8C65C0
#define CXWnd__DrawChildren_x                                      0x8C6760
#define CXWnd__DrawColoredRect_x                                   0x8C0BA0
#define CXWnd__DrawTooltip_x                                       0x8C0E30
#define CXWnd__DrawTooltipAtPoint_x                                0x8C5550
#define CXWnd__GetBorderFrame_x                                    0x8C1290
#define CXWnd__GetChildWndAt_x                                     0x8C7340
#define CXWnd__GetClientClipRect_x                                 0x8C1050
#define CXWnd__GetScreenClipRect_x                                 0x8C5C40
#define CXWnd__GetScreenRect_x                                     0x8C1440
#define CXWnd__GetTooltipRect_x                                    0x8C0CC0
#define CXWnd__GetWindowTextA_x                                    0x426FE0
#define CXWnd__IsActive_x                                          0x8BBDD0
#define CXWnd__IsDescendantOf_x                                    0x8C11E0
#define CXWnd__IsReallyVisible_x                                   0x8C4590
#define CXWnd__IsType_x                                            0x8C69E0
#define CScreenPieceTemplate__IsType_x                             0x8F3DE0
#define CXWnd__Move_x                                              0x8C3CC0
#define CXWnd__Move1_x                                             0x8C6260
#define CXWnd__ProcessTransition_x                                 0x8C0770
#define CXWnd__Refade_x                                            0x8C0540
#define CXWnd__Resize_x                                            0x8C1500
#define CXWnd__Right_x                                             0x8C5A40
#define CXWnd__SetFocus_x                                          0x8C2E00
#define CXWnd__SetFont_x                                           0x8C03F0
#define CXWnd__SetKeyTooltip_x                                     0x8C1760
#define CXWnd__SetMouseOver_x                                      0x8C5F50
#define CXWnd__StartFade_x                                         0x8C0810
#define CXWnd__GetChildItem_x                                      0x8C5E90
#define CXWnd__SetParent_x                                         0x8C72F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BD650
#define CXWndManager__DrawWindows_x                                0x8BD290
#define CXWndManager__GetKeyboardFlags_x                           0x8BB940
#define CXWndManager__HandleKeyboardMsg_x                          0x8BC260
#define CXWndManager__RemoveWnd_x                                  0x8BBF60

// CDBStr
#define CDBStr__GetString_x                                        0x4B2C00

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x451A70
#define EQ_Character__Cur_HP_x                                     0x466360
#define EQ_Character__Cur_Mana_x                                   0x45A140
#define EQ_Character__GetAACastingTimeModifier_x                   0x44ACD0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443000
#define EQ_Character__GetFocusRangeModifier_x                      0x443060
#define EQ_Character__GetHPRegen_x                                 0x469540
#define EQ_Character__GetEnduranceRegen_x                          0x465970
#define EQ_Character__GetManaRegen_x                               0x469AE0
#define EQ_Character__Max_Endurance_x                              0x5C3770
#define EQ_Character__Max_HP_x                                     0x45CCB0
#define EQ_Character__Max_Mana_x                                   0x5C35A0
#define EQ_Character__doCombatAbility_x                            0x5C0C70
#define EQ_Character__UseSkill_x                                   0x4704C0
#define EQ_Character__GetConLevel_x                                0x5B62F0
#define EQ_Character__IsExpansionFlag_x                            0x426520
#define EQ_Character__TotalEffect_x                                0x44EDA0
#define EQ_Character__GetPCSpellAffect_x                           0x44B0D0
#define EQ_Character__SpellDuration_x                              0x449070
#define EQ_Character__FindItemByRecord_x                           0x4639D0
#define EQ_Character__GetAdjustedSkill_x                           0x466B10
#define EQ_Character__GetBaseSkill_x                               0x45CB90

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x867740

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5CB770

//PcClient
#define PcClient__PcClient_x                                       0x5B8130

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446350
#define CCharacterSelect__EnterWorld_x                             0x445B20
#define CCharacterSelect__Quit_x                                   0x444710

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x596910
#define EQ_Item__CreateItemTagString_x                             0x848AF0
#define EQ_Item__IsStackable_x                                     0x83E250
#define EQ_Item__GetImageNum_x                                     0x840C60
#define EQ_Item__CreateItemClient_x                                0x5974D0
#define EQ_Item__GetItemValue_x                                    0x847810
#define EQ_Item__ValueSellMerchant_x                               0x849E00
#define EQ_Item__IsKeyRingItem_x                                   0x83ECA0
#define EQ_Item__CanGoInBag_x                                      0x596AA0
#define EQ_Item__GetMaxItemCount_x                                 0x83E140
#define EQ_Item__GetHeldItem_x                                     0x83FA80
#define EQ_Item__GetAugmentFitBySlot_x                             0x849C20

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D2B60
#define EQ_LoadingS__Array_x                                       0xBF8A78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C5C80
#define EQ_PC__GetAlternateAbilityId_x                             0x8521C0
#define EQ_PC__GetCombatAbility_x                                  0x852250
#define EQ_PC__GetCombatAbilityTimer_x                             0x84CE60
#define EQ_PC__GetItemRecastTimer_x                                0x5BF420
#define EQ_PC__HasLoreItem_x                                       0x5B98E0
#define EQ_PC__AlertInventoryChanged_x                             0x5B62C0
#define EQ_PC__GetPcZoneClient_x                                   0x5DFBF0
#define EQ_PC__RemoveMyAffect_x                                    0x5BE8F0
#define EQ_PC__GetKeyRingItems_x                                   0x84D280
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x85FEA0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x854130

// EQItemList 
#define EQItemList__EQItemList_x                                   0x51EFA0
#define EQItemList__add_object_x                                   0x54B7D0
#define EQItemList__add_item_x                                     0x51EEE0
#define EQItemList__delete_item_x                                  0x51F390
#define EQItemList__FreeItemList_x                                 0x51F290

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B1EF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CB510
#define EQPlayer__dEQPlayer_x                                      0x5D3B40
#define EQPlayer__DoAttack_x                                       0x5E5560
#define EQPlayer__EQPlayer_x                                       0x5D6260
#define EQPlayer__SetNameSpriteState_x                             0x5D0A00
#define EQPlayer__SetNameSpriteTint_x                              0x5CC920
#define PlayerBase__HasProperty_j_x                                0x924B70
#define EQPlayer__IsTargetable_x                                   0x924E10
#define EQPlayer__CanSee_x                                         0x925370
#define PlayerZoneClient__ChangeHeight_x                           0x5E5420
#define EQPlayer__CanSeeTargetIndicator_x                          0x925460
#define PlayerBase__GetVisibilityLineSegment_x                     0x925100

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5DFDA0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5DA240
#define EQPlayerManager__GetSpawnByName_x                          0x5DA6A0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5DA270

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59CA50
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59CA90
#define KeypressHandler__ClearCommandStateArray_x                  0x59C640
#define KeypressHandler__HandleKeyDown_x                           0x59AFA0
#define KeypressHandler__HandleKeyUp_x                             0x59B2C0
#define KeypressHandler__SaveKeymapping_x                          0x59C710

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70A980
#define MapViewMap__SaveEx_x                                       0x70DCB0

#define PlayerPointManager__GetAltCurrency_x                       0x865780

// StringTable 
#define StringTable__getString_x                                   0x8601D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C3200
#define PcZoneClient__RemovePetEffect_x                            0x5BF8F0
#define PcZoneClient__HasAlternateAbility_x                        0x5C0290
#define PcZoneClient__GetCurrentMod_x                              0x45C160
#define PcZoneClient__GetModCap_x                                  0x4598A0
#define PcZoneClient__CanEquipItem_x                               0x5C07B0
#define PcZoneClient__GetItemByID_x                                0x5C4FF0
#define PcZoneClient__GetItemByItemClass_x                         0x5C5BA0

//Doors
#define EQSwitch__UseSwitch_x                                      0x553100

//IconCache
#define IconCache__GetIcon_x                                       0x6A75F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69E510
#define CContainerMgr__CloseContainer_x                            0x69ED30

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76B880

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58F8E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4ECD80
#define EQ_Spell__SpellAffects_x                                   0x4EA420
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4EA490
#define CharacterZoneClient__CalcAffectChange_x                    0x44AF60
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A1A0
#define CLootWnd__LootAll_x                                        0x7001C0
#define CLootWnd__RequestLootSlot_x                                0x7009D0
#define EQ_Spell__IsStackable_x                                    0x448C20
#define EQ_Spell__GetSpellAffectBySlot_x                           0x448CD0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43E860
#define EQ_Spell__IsSPAStacking_x                                  0x4E9FD0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4E9AA0
#define EQ_Spell__IsNoRemove_x                                     0x434950
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4E9FF0

#define __IsResEffectSpell_x                                       0x448D70

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8712C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B0FE0
#define CTargetWnd__WndNotification_x                              0x7B0AD0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B11C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B60B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E59C0
#define EqSoundManager__PlayScriptMp3_x                            0x4E7460

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A1080

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DF930
#define CSidlManager__FindAnimation1_x                             0x8D4CE0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4DA310
#define CAltAbilityData__GetMercMaxRank_x                          0x4DA2C0
#define CAltAbilityData__GetMaxRank_x                              0x4CEC20

//CTargetRing
#define CTargetRing__Cast_x                                        0x58D1C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4588B0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4751E0
#define CharacterBase__CreateItemIndex_x                           0x518500
#define CharacterBase__GetItemPossession_x                         0x443BE0
#define CharacterBase__GetItemByGlobalIndex_x                      0x875910
#define CharacterBase__GetEffectId_x                               0x458870

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x687310
#define CCastSpellWnd__IsBardSongPlaying_x                         0x686A70

//messages
#define msg_spell_worn_off_x                                       0x4F4840
#define msg_new_text_x                                             0x4FDE00
#define msgTokenTextParam_x                                        0x4FA660

//SpellManager
#define SpellManager__vftable_x                                    0xAB9170
#define SpellManager__SpellManager_x                               0x47DE20
#define Spellmanager__CheckSpellRequirementAssociations_x          0x603E90

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x928E80

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F0F10
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43E780
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4489C0
#define ItemGlobalIndex__IsValidIndex_x                            0x458180

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x873780
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8726C0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F91A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6A3220
#define CCursorAttachment__Deactivate_x                            0x6A2770

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8F0950