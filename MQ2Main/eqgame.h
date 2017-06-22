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
#define __ExpectedVersionDate                                     "Jun 19 2017"
#define __ExpectedVersionTime                                     "21:05:02"
#define __ActualVersionDate_x                                      0xAD5418
#define __ActualVersionTime_x                                      0xAD5424

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5A2960
#define __MemChecker1_x                                            0x8990F0
#define __MemChecker2_x                                            0x638700
#define __MemChecker3_x                                            0x638650
#define __MemChecker4_x                                            0x7EB4B0
#define __EncryptPad0_x                                            0xC2F328
#define __EncryptPad1_x                                            0xD0A6E0
#define __EncryptPad2_x                                            0xC58B10
#define __EncryptPad3_x                                            0xC58710
#define __EncryptPad4_x                                            0xCF8CE0
#define __EncryptPad5_x                                            0x10B3370
#define __AC1_x                                                    0x7AA6D5
#define __AC2_x                                                    0x55B8E7
#define __AC3_x                                                    0x559A60
#define __AC4_x                                                    0x56BB71
#define __AC5_x                                                    0x57FA0B
#define __AC6_x                                                    0x5835BE
#define __AC7_x                                                    0x57A00C
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
#define __do_loot_x                                                0x52AD40
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
#define pinstCamActor_x                                            0xE60E4C
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
#define pinstViewActor_x                                           0xE60E48
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
#define pinstCRealEstateItemsWnd_x                                 0xE60D64
#define pinstCAchievementsWnd_x                                    0xE60DC0
#define pinstCTextOverlay_x                                        0xD1E288
#define pinstCAudioTriggersWindow_x                                0xD1E118
#define pinstCCharacterSelect_x                                    0xE60CD4
#define pinstCFacePick_x                                           0xE60A84
#define pinstCNoteWnd_x                                            0xE60C8C
#define pinstCBookWnd_x                                            0xE60C94
#define pinstCPetInfoWnd_x                                         0xE60C98
#define pinstCTrainWnd_x                                           0xE60C9C
#define pinstCSkillsWnd_x                                          0xE60CA0
#define pinstCSkillsSelectWnd_x                                    0xE60CA4
#define pinstCCombatSkillsSelectWnd_x                              0xE60CA8
#define pinstCFriendsWnd_x                                         0xE60CAC
#define pinstCAuraWnd_x                                            0xE60CB0
#define pinstCRespawnWnd_x                                         0xE60CB4
#define pinstCBandolierWnd_x                                       0xE60CB8
#define pinstCPotionBeltWnd_x                                      0xE60CBC
#define pinstCAAWnd_x                                              0xE60CC0
#define pinstCAlarmWnd_x                                           0xE60CCC
#define pinstCGroupSearchFiltersWnd_x                              0xE60CC4
#define pinstCLoadskinWnd_x                                        0xE60CC8
#define pinstCLargeDialogWnd_x                                     0x10BA050
#define pinstCMusicPlayerWnd_x                                     0xE60CD0
#define pinstCMailWnd_x                                            0xE60CD8
#define pinstCMailCompositionWnd_x                                 0xE60CDC
#define pinstCMailAddressBookWnd_x                                 0xE60CE0
#define pinstCRaidWnd_x                                            0xE60CE8
#define pinstCRaidOptionsWnd_x                                     0xE60CEC
#define pinstCBreathWnd_x                                          0xE60CF0
#define pinstCMapViewWnd_x                                         0xE60CF4
#define pinstCMapToolbarWnd_x                                      0xE60CF8
#define pinstCEditLabelWnd_x                                       0xE60CFC
#define pinstCTargetWnd_x                                          0xE60D00
#define pinstCColorPickerWnd_x                                     0xE60D04
#define pinstCPlayerWnd_x                                          0xE60D08
#define pinstCOptionsWnd_x                                         0xE60D0C
#define pinstCBuffWindowNORMAL_x                                   0xE60D10
#define pinstCBuffWindowSHORT_x                                    0xE60D14
#define pinstCharacterCreation_x                                   0xE60D18
#define pinstCCursorAttachment_x                                   0xE60D1C
#define pinstCCastingWnd_x                                         0xE60D20
#define pinstCCastSpellWnd_x                                       0xE60D24
#define pinstCSpellBookWnd_x                                       0xE60D28
#define pinstCInventoryWnd_x                                       0xE60D2C
#define pinstCBankWnd_x                                            0xE60D34
#define pinstCQuantityWnd_x                                        0xE60D38
#define pinstCLootWnd_x                                            0xE60D3C
#define pinstCActionsWnd_x                                         0xE60D40
#define pinstCCombatAbilityWnd_x                                   0xE60D48
#define pinstCMerchantWnd_x                                        0xE60D4C
#define pinstCTradeWnd_x                                           0xE60D54
#define pinstCSelectorWnd_x                                        0xE60D58
#define pinstCBazaarWnd_x                                          0xE60D5C
#define pinstCBazaarSearchWnd_x                                    0xE60D60
#define pinstCGiveWnd_x                                            0xE60D7C
#define pinstCTrackingWnd_x                                        0xE60D84
#define pinstCInspectWnd_x                                         0xE60D88
#define pinstCSocialEditWnd_x                                      0xE60D8C
#define pinstCFeedbackWnd_x                                        0xE60D90
#define pinstCBugReportWnd_x                                       0xE60D94
#define pinstCVideoModesWnd_x                                      0xE60D98
#define pinstCTextEntryWnd_x                                       0xE60DA0
#define pinstCFileSelectionWnd_x                                   0xE60DA4
#define pinstCCompassWnd_x                                         0xE60DA8
#define pinstCPlayerNotesWnd_x                                     0xE60DAC
#define pinstCGemsGameWnd_x                                        0xE60DB0
#define pinstCTimeLeftWnd_x                                        0xE60DB4
#define pinstCPetitionQWnd_x                                       0xE60DD0
#define pinstCStoryWnd_x                                           0xE60DD4
#define pinstCJournalTextWnd_x                                     0xE60DD8
#define pinstCJournalCatWnd_x                                      0xE60DDC
#define pinstCBodyTintWnd_x                                        0xE60DE0
#define pinstCServerListWnd_x                                      0xE60DE4
#define pinstCAvaZoneWnd_x                                         0xE60DF0
#define pinstCBlockedBuffWnd_x                                     0xE60DF4
#define pinstCBlockedPetBuffWnd_x                                  0xE60DF8
#define pinstCInvSlotMgr_x                                         0xE60E40
#define pinstCContainerMgr_x                                       0xE60E44
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
#define pinstCAdvancedLootWnd_x                                    0xE60E34
#define pinstRewardSelectionWnd_x                                  0x10B9E70
#define pinstEQSuiteTextureLoader_x                                0xD0C458

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x542290
#define __ConvertItemTags_x                                        0x52F960
#define __ExecuteCmd_x                                             0x51A2A0
#define __EQGetTime_x                                              0x898A90
#define __get_melee_range_x                                        0x520EE0
#define __GetGaugeValueFromEQ_x                                    0x7A9290
#define __GetLabelFromEQ_x                                         0x7AA660
#define __ToggleKeyRingItem_x                                      0x488B10
#define __GetXTargetType_x                                         0x9295E0
#define __LoadFrontEnd_x                                           0x637DD0
#define __NewUIINI_x                                               0x7A8C60
#define __ProcessGameEvents_x                                      0x57BDA0
#define __ProcessMouseEvent_x                                      0x57B540
#define CrashDetected_x                                            0x639790
#define wwsCrashReportCheckForUploader_x                           0x7F7120
#define __AppCrashWrapper_x                                        0xC58704
#define __pCrashHandler_x                                          0x10C8568
#define __CrashHandler_x                                           0x7F6BB0
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F9350
#define DrawNetStatus_x                                            0x5B2620
#define Util__FastTime_x                                           0x898730
#define Expansion_HoT_x                                            0xF22A70
#define __HelpPath_x                                               0xFA6188
#define __STMLToText_x                                             0x8DEAC0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423110
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DE30
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DC00

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D12F0
#define AltAdvManager__IsAbilityReady_x                            0x4D1360
#define AltAdvManager__GetAAById_x                                 0x4D1850
#define AltAdvManager__CanTrainAbility_x                           0x4D2480
#define AltAdvManager__CanSeeAbility_x                             0x4D2040

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46A040
#define CharacterZoneClient__HasSkill_x                            0x466EF0
#define CharacterZoneClient__MakeMeVisible_x                       0x46B5D0
#define CharacterZoneClient__IsStackBlocked_x                      0x44B620
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44AAE0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464E70
#define CharacterZoneClient__GetItemCountInInventory_x             0x464F50
#define CharacterZoneClient__GetCursorItemCount_x                  0x465030
#define CharacterZoneClient__FindAffectSlot_x                      0x450B90
#define CharacterZoneClient__BardCastBard_x                        0x44A260
#define CharacterZoneClient__GetMaxEffects_x                       0x448FA0
#define CharacterZoneClient__GetEffect_x                           0x44AD10
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4509F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449140
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44F540

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6676B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x675B50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x591690
#define CButtonWnd__CButtonWnd_x                                   0x8D2E50

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x690A90
#define CChatManager__InitContextMenu_x                            0x691BE0
#define CChatManager__FreeChatWindow_x                             0x690520
#define CChatManager__GetLockedActiveChatWindow_x                  0x699CA0
#define CChatManager__SetLockedActiveChatWindow_x                  0x690A60

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DCE10
#define CContextMenu__dCContextMenu_x                              0x8DD020
#define CContextMenu__AddMenuItem_x                                0x8DD540
#define CContextMenu__RemoveMenuItem_x                             0x8DD1A0
#define CContextMenu__RemoveAllMenuItems_x                         0x8DD1C0
#define CContextMenu__CheckMenuItem_x                              0x8DD240

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8C9390
#define CContextMenuManager__RemoveMenu_x                          0x8C9730
#define CContextMenuManager__PopupMenu_x                           0x8C9B80
#define CContextMenuManager__Flush_x                               0x8C9400
#define CContextMenuManager__GetMenu_x                             0x419500

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87CE40
#define CChatService__GetFriendName_x                              0x87CE50

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6977F0
#define CChatWindow__Clear_x                                       0x6970D0
#define CChatWindow__WndNotification_x                             0x6980F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CD1F0
#define CComboWnd__Draw_x                                          0x8CD400
#define CComboWnd__GetCurChoice_x                                  0x8CCFA0
#define CComboWnd__GetListRect_x                                   0x8CD6A0
#define CComboWnd__GetTextRect_x                                   0x8CD260
#define CComboWnd__InsertChoice_x                                  0x8CD710
#define CComboWnd__SetColors_x                                     0x8CCF30
#define CComboWnd__SetChoice_x                                     0x8CCF60
#define CComboWnd__GetItemCount_x                                  0x8CCF90
#define CComboWnd__GetCurChoiceText_x                              0x8CCFE0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A19A0
#define CContainerWnd__vftable_x                                   0xADF020

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BEFE0
#define CDisplay__GetClickedActor_x                                0x4B78D0
#define CDisplay__GetUserDefinedColor_x                            0x4B64B0
#define CDisplay__GetWorldFilePath_x                               0x4B5900
#define CDisplay__is3dON_x                                         0x4B4D90
#define CDisplay__ReloadUI_x                                       0x4C8F40
#define CDisplay__WriteTextHD2_x                                   0x4BB3A0
#define CDisplay__TrueDistance_x                                   0x4B8500

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F3420

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E1370
#define CEditWnd__GetCharIndexPt_x                                 0x8E2410
#define CEditWnd__GetDisplayString_x                               0x8E1520
#define CEditWnd__GetHorzOffset_x                                  0x8E1860
#define CEditWnd__GetLineForPrintableChar_x                        0x8E1ED0
#define CEditWnd__GetSelStartPt_x                                  0x8E26D0
#define CEditWnd__GetSTMLSafeText_x                                0x8E1A00
#define CEditWnd__PointFromPrintableChar_x                         0x8E1FC0
#define CEditWnd__SelectableCharFromPoint_x                        0x8E2140
#define CEditWnd__SetEditable_x                                    0x8E19D0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5623A0
#define CEverQuest__ClickedPlayer_x                                0x55C030
#define CEverQuest__CreateTargetIndicator_x                        0x55CF30
#define CEverQuest__DeleteTargetIndicator_x                        0x55CFB0
#define CEverQuest__DoTellWindow_x                                 0x476210
#define CEverQuest__OutputTextToLog_x                              0x475E70
#define CEverQuest__DropHeldItemOnGround_x                         0x572910
#define CEverQuest__dsp_chat_x                                     0x476550
#define CEverQuest__trimName_x                                     0x558940
#define CEverQuest__Emote_x                                        0x570C20
#define CEverQuest__EnterZone_x                                    0x56BD00
#define CEverQuest__GetBodyTypeDesc_x                              0x556380
#define CEverQuest__GetClassDesc_x                                 0x55F7C0
#define CEverQuest__GetClassThreeLetterCode_x                      0x55FDC0
#define CEverQuest__GetDeityDesc_x                                 0x556C60
#define CEverQuest__GetLangDesc_x                                  0x556710
#define CEverQuest__GetRaceDesc_x                                  0x55FF80
#define CEverQuest__InterpretCmd_x                                 0x563B20
#define CEverQuest__LeftClickedOnPlayer_x                          0x578450
#define CEverQuest__LMouseUp_x                                     0x57A560
#define CEverQuest__RightClickedOnPlayer_x                         0x578F60
#define CEverQuest__RMouseUp_x                                     0x579FC0
#define CEverQuest__SetGameState_x                                 0x55C900
#define CEverQuest__UPCNotificationFlush_x                         0x554D10
#define CEverQuest__IssuePetCommand_x                              0x564500

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B25E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B2640
#define CGaugeWnd__Draw_x                                          0x6B2A70

// CGuild
#define CGuild__FindMemberByName_x                                 0x43AEE0
#define CGuild__GetGuildName_x                                     0x43B3B0
#define CGuild__GetGuildIndex_x                                    0x43C5C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CEB10

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DBD90
#define CInvSlotMgr__MoveItem_x                                    0x6DCC40
#define CInvSlotMgr__SelectSlot_x                                  0x6DBE40

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DB240
#define CInvSlot__SliderComplete_x                                 0x6D89D0
#define CInvSlot__GetItemBase_x                                    0x6D7E30
#define CInvSlot__UpdateItem_x                                     0x6D83B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DE0A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6DF1C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A4CA0
#define CItemDisplayWnd__UpdateStrings_x                           0x6E02D0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6ECD90
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6ED2C0
#define CItemDisplayWnd__SetItem_x                                 0x6F2BE0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7DC240

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6E68D0

// CLabel 
#define CLabel__Draw_x                                             0x6F99E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B8F00
#define CListWnd__dCListWnd_x                                      0x8BA120
#define CListWnd__AddColumn_x                                      0x8BA0C0
#define CListWnd__AddColumn1_x                                     0x8B9760
#define CListWnd__AddLine_x                                        0x8B91C0
#define CListWnd__AddString_x                                      0x8B93E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B6190
#define CListWnd__CalculateVSBRange_x                              0x8B83C0
#define CListWnd__ClearSel_x                                       0x8B54B0
#define CListWnd__ClearAllSel_x                                    0x8B5460
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B8D90
#define CListWnd__Compare_x                                        0x8B6D00
#define CListWnd__Draw_x                                           0x8B7FC0
#define CListWnd__DrawColumnSeparators_x                           0x8B7E50
#define CListWnd__DrawHeader_x                                     0x8B5770
#define CListWnd__DrawItem_x                                       0x8B7380
#define CListWnd__DrawLine_x                                       0x8B7AF0
#define CListWnd__DrawSeparator_x                                  0x8B7EF0
#define CListWnd__EnableLine_x                                     0x8B5690
#define CListWnd__EnsureVisible_x                                  0x8B62F0
#define CListWnd__ExtendSel_x                                      0x8B7290
#define CListWnd__GetColumnMinWidth_x                              0x8B4E60
#define CListWnd__GetColumnWidth_x                                 0x8B4D90
#define CListWnd__GetCurSel_x                                      0x8B4550
#define CListWnd__GetItemAtPoint_x                                 0x8B6590
#define CListWnd__GetItemAtPoint1_x                                0x8B6600
#define CListWnd__GetItemData_x                                    0x8B48A0
#define CListWnd__GetItemHeight_x                                  0x8B5DF0
#define CListWnd__GetItemIcon_x                                    0x8B4A90
#define CListWnd__GetItemRect_x                                    0x8B63D0
#define CListWnd__GetItemText_x                                    0x8B4940
#define CListWnd__GetSelList_x                                     0x8B9650
#define CListWnd__GetSeparatorRect_x                               0x8B6C20
#define CListWnd__InsertLine_x                                     0x8B95C0
#define CListWnd__RemoveLine_x                                     0x8B95D0
#define CListWnd__SetColors_x                                      0x8B46A0
#define CListWnd__SetColumnJustification_x                         0x8B50F0
#define CListWnd__SetColumnWidth_x                                 0x8B4E10
#define CListWnd__SetCurSel_x                                      0x8B4590
#define CListWnd__SetItemColor_x                                   0x8B8A80
#define CListWnd__SetItemData_x                                    0x8B5510
#define CListWnd__SetItemText_x                                    0x8B88C0
#define CListWnd__ShiftColumnSeparator_x                           0x8B8750
#define CListWnd__Sort_x                                           0x8BA220
#define CListWnd__ToggleSel_x                                      0x8B53E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x712B60

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x733F80
#define CMerchantWnd__RequestBuyItem_x                             0x73B040
#define CMerchantWnd__RequestSellItem_x                            0x73BB10
#define CMerchantWnd__SelectRecoverySlot_x                         0x734230
#define CMerchantWnd__SelectBuySellSlot_x                          0x733430
#define CMerchantWnd__ActualSelect_x                               0x737F00

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84B150
#define CPacketScrambler__hton_x                                   0x84B160

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D7CE0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D7DC0
#define CSidlManager__CreateLabel_x                                0x79C2F0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8D6290
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D80A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8CF2A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8CF190
#define CSidlScreenWnd__ConvertToRes_x                             0x8F3300
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CFBB0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D0D70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D0E20
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D0300
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CF560
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CECC0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CF750
#define CSidlScreenWnd__Init1_x                                    0x8D0A50
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CFC60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CEE80
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D0540
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CE910
#define CSidlScreenWnd__StoreIniVis_x                              0x8CEC70
#define CSidlScreenWnd__WndNotification_x                          0x8D07D0
#define CSidlScreenWnd__GetChildItem_x                             0x8CED90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C25F0
#define CSidlScreenWnd__m_layoutCopy_x                             0x171F048

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FD800
#define CSkillMgr__GetSkillCap_x                                   0x5FD9E0
#define CSkillMgr__GetNameToken_x                                  0x5FD3B0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F25B0
#define CSliderWnd__SetValue_x                                     0x8F2780
#define CSliderWnd__SetNumTicks_x                                  0x8F2F00

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A2900

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8ECA90
#define CStmlWnd__CalculateHSBRange_x                              0x8E5180
#define CStmlWnd__CalculateVSBRange_x                              0x8E50F0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E5300
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E5B00
#define CStmlWnd__ForceParseNow_x                                  0x8ED410
#define CStmlWnd__GetNextTagPiece_x                                0x8E5A00
#define CStmlWnd__GetSTMLText_x                                    0x484030
#define CStmlWnd__GetVisibleText_x                                 0x8E6550
#define CStmlWnd__InitializeWindowVariables_x                      0x8E89B0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E43D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E4430
#define CStmlWnd__SetSTMLText_x                                    0x8EA200
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EC730
#define CStmlWnd__UpdateHistoryString_x                            0x8E7490

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F0910
#define CTabWnd__DrawCurrentPage_x                                 0x8F01A0
#define CTabWnd__DrawTab_x                                         0x8EFF60
#define CTabWnd__GetCurrentPage_x                                  0x8F0550
#define CTabWnd__GetPageInnerRect_x                                0x8EFC50
#define CTabWnd__GetTabInnerRect_x                                 0x8EFE50
#define CTabWnd__GetTabRect_x                                      0x8EFD20
#define CTabWnd__InsertPage_x                                      0x8F0C00
#define CTabWnd__SetPage_x                                         0x8F0580
#define CTabWnd__SetPageRect_x                                     0x8F0850
#define CTabWnd__UpdatePage_x                                      0x8F0BA0
#define CTabWnd__GetPageFromTabIndex_x                             0x8EFEB0
#define CTabWnd__GetCurrentTabIndex_x                              0x8EFBE0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6DF370
#define CPageWnd__SetTabText_x                                     0x8FC310

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436A90

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CCBA0
#define CTextureFont__GetTextExtent_x                              0x8CC900

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x636060

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F8750

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B2730

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x8B3770
#define CXStr__CXStr3_x                                            0x895980
#define CXStr__dCXStr_x                                            0x402A00
#define CXStr__operator_equal_x                                    0x895AF0
#define CXStr__operator_equal1_x                                   0x895B40
#define CXStr__operator_plus_equal1_x                              0x896C40

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C17D0
#define CXWnd__Center_x                                            0x8C7970
#define CXWnd__ClrFocus_x                                          0x8C13A0
#define CXWnd__Destroy_x                                           0x8C8460
#define CXWnd__DoAllDrawing_x                                      0x8C75B0
#define CXWnd__DrawChildren_x                                      0x8C7760
#define CXWnd__DrawColoredRect_x                                   0x8C1BA0
#define CXWnd__DrawTooltip_x                                       0x8C1E50
#define CXWnd__DrawTooltipAtPoint_x                                0x8C6510
#define CXWnd__GetBorderFrame_x                                    0x8C22C0
#define CXWnd__GetChildWndAt_x                                     0x8C8340
#define CXWnd__GetClientClipRect_x                                 0x8C2070
#define CXWnd__GetScreenClipRect_x                                 0x8C6C10
#define CXWnd__GetScreenRect_x                                     0x8C2490
#define CXWnd__GetTooltipRect_x                                    0x8C1CE0
#define CXWnd__GetWindowTextA_x                                    0x4271B0
#define CXWnd__IsActive_x                                          0x8BCF00
#define CXWnd__IsDescendantOf_x                                    0x8C2200
#define CXWnd__IsReallyVisible_x                                   0x8C5530
#define CXWnd__IsType_x                                            0x8C79E0
#define CScreenPieceTemplate__IsType_x                             0x8F4F70
#define CXWnd__Move_x                                              0x8C4C70
#define CXWnd__Move1_x                                             0x8C7260
#define CXWnd__ProcessTransition_x                                 0x8C1770
#define CXWnd__Refade_x                                            0x8C1550
#define CXWnd__Resize_x                                            0x8C2560
#define CXWnd__Right_x                                             0x8C6A10
#define CXWnd__SetFocus_x                                          0x8C3DC0
#define CXWnd__SetFont_x                                           0x8C13F0
#define CXWnd__SetKeyTooltip_x                                     0x8C27C0
#define CXWnd__SetMouseOver_x                                      0x8C6F40
#define CXWnd__StartFade_x                                         0x8C1820
#define CXWnd__GetChildItem_x                                      0x8C6E90
#define CXWnd__SetParent_x                                         0x8C82F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BE790
#define CXWndManager__DrawWindows_x                                0x8BE3E0
#define CXWndManager__GetKeyboardFlags_x                           0x8BCA30
#define CXWndManager__HandleKeyboardMsg_x                          0x8BD390
#define CXWndManager__RemoveWnd_x                                  0x8BD090

// CDBStr
#define CDBStr__GetString_x                                        0x4B35F0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x451B90
#define EQ_Character__Cur_HP_x                                     0x4664F0
#define EQ_Character__Cur_Mana_x                                   0x45A290
#define EQ_Character__GetAACastingTimeModifier_x                   0x44ADF0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4430F0
#define EQ_Character__GetFocusRangeModifier_x                      0x443150
#define EQ_Character__GetHPRegen_x                                 0x4696D0
#define EQ_Character__GetEnduranceRegen_x                          0x465B00
#define EQ_Character__GetManaRegen_x                               0x469C70
#define EQ_Character__Max_Endurance_x                              0x5C45D0
#define EQ_Character__Max_HP_x                                     0x45CE10
#define EQ_Character__Max_Mana_x                                   0x5C4400
#define EQ_Character__doCombatAbility_x                            0x5C1AD0
#define EQ_Character__UseSkill_x                                   0x470660
#define EQ_Character__GetConLevel_x                                0x5B6C80
#define EQ_Character__IsExpansionFlag_x                            0x4266F0
#define EQ_Character__TotalEffect_x                                0x44EEC0
#define EQ_Character__GetPCSpellAffect_x                           0x44B1F0
#define EQ_Character__SpellDuration_x                              0x449190
#define EQ_Character__FindItemByRecord_x                           0x463B60
#define EQ_Character__GetAdjustedSkill_x                           0x466CA0
#define EQ_Character__GetBaseSkill_x                               0x45CCF0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x868760

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5CC5B0

//PcClient
#define PcClient__PcClient_x                                       0x5B8AD0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446470
#define CCharacterSelect__EnterWorld_x                             0x445C40
#define CCharacterSelect__Quit_x                                   0x444820

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5970E0
#define EQ_Item__CreateItemTagString_x                             0x849A80
#define EQ_Item__IsStackable_x                                     0x83F0E0
#define EQ_Item__GetImageNum_x                                     0x841BE0
#define EQ_Item__CreateItemClient_x                                0x597CE0
#define EQ_Item__GetItemValue_x                                    0x8487A0
#define EQ_Item__ValueSellMerchant_x                               0x84ADA0
#define EQ_Item__IsKeyRingItem_x                                   0x83FBD0
#define EQ_Item__CanGoInBag_x                                      0x597270
#define EQ_Item__GetMaxItemCount_x                                 0x83EFD0
#define EQ_Item__GetHeldItem_x                                     0x8409F0
#define EQ_Item__GetAugmentFitBySlot_x                             0x84ABC0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D3930
#define EQ_LoadingS__Array_x                                       0xBFAA78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C6AE0
#define EQ_PC__GetAlternateAbilityId_x                             0x853270
#define EQ_PC__GetCombatAbility_x                                  0x853300
#define EQ_PC__GetCombatAbilityTimer_x                             0x84DE00
#define EQ_PC__GetItemRecastTimer_x                                0x5C0280
#define EQ_PC__HasLoreItem_x                                       0x5BA290
#define EQ_PC__AlertInventoryChanged_x                             0x5B6C50
#define EQ_PC__GetPcZoneClient_x                                   0x5E0B40
#define EQ_PC__RemoveMyAffect_x                                    0x5BF750
#define EQ_PC__GetKeyRingItems_x                                   0x84E220
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x860F70
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8551E0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x51EF90
#define EQItemList__add_object_x                                   0x54BD60
#define EQItemList__add_item_x                                     0x51EED0
#define EQItemList__delete_item_x                                  0x51F380
#define EQItemList__FreeItemList_x                                 0x51F280

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B28A0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CC350
#define EQPlayer__dEQPlayer_x                                      0x5D4990
#define EQPlayer__DoAttack_x                                       0x5E64C0
#define EQPlayer__EQPlayer_x                                       0x5D70B0
#define EQPlayer__SetNameSpriteState_x                             0x5D1850
#define EQPlayer__SetNameSpriteTint_x                              0x5CD770
#define PlayerBase__HasProperty_j_x                                0x925DA0
#define EQPlayer__IsTargetable_x                                   0x926040
#define EQPlayer__CanSee_x                                         0x9265A0
#define PlayerZoneClient__ChangeHeight_x                           0x5E6380
#define EQPlayer__CanSeeTargetIndicator_x                          0x926690
#define PlayerBase__GetVisibilityLineSegment_x                     0x926330

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E0CF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5DB190
#define EQPlayerManager__GetSpawnByName_x                          0x5DB5F0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5DB1C0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59D280
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59D2C0
#define KeypressHandler__ClearCommandStateArray_x                  0x59CE70
#define KeypressHandler__HandleKeyDown_x                           0x59B7D0
#define KeypressHandler__HandleKeyUp_x                             0x59BAF0
#define KeypressHandler__SaveKeymapping_x                          0x59CF40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70B4F0
#define MapViewMap__SaveEx_x                                       0x70E820

#define PlayerPointManager__GetAltCurrency_x                       0x866770

// StringTable 
#define StringTable__getString_x                                   0x8612A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C4060
#define PcZoneClient__RemovePetEffect_x                            0x5C0750
#define PcZoneClient__HasAlternateAbility_x                        0x5C10F0
#define PcZoneClient__GetCurrentMod_x                              0x45C2C0
#define PcZoneClient__GetModCap_x                                  0x4599F0
#define PcZoneClient__CanEquipItem_x                               0x5C1610
#define PcZoneClient__GetItemByID_x                                0x5C5E60
#define PcZoneClient__GetItemByItemClass_x                         0x5C6A00

//Doors
#define EQSwitch__UseSwitch_x                                      0x553650

//IconCache
#define IconCache__GetIcon_x                                       0x6A7E20

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69ED30
#define CContainerMgr__CloseContainer_x                            0x69F550

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76C2B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5900B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4ED960
#define EQ_Spell__SpellAffects_x                                   0x4EB000
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4EB070
#define CharacterZoneClient__CalcAffectChange_x                    0x44B080
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A2C0
#define CLootWnd__LootAll_x                                        0x700DB0
#define CLootWnd__RequestLootSlot_x                                0x7015C0
#define EQ_Spell__IsStackable_x                                    0x448D40
#define EQ_Spell__GetSpellAffectBySlot_x                           0x448DF0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43E950
#define EQ_Spell__IsSPAStacking_x                                  0x4EABB0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4EA680
#define EQ_Spell__IsNoRemove_x                                     0x434AD0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4EABD0

#define __IsResEffectSpell_x                                       0x448E90

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8723D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B1C20
#define CTargetWnd__WndNotification_x                              0x7B1710
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B1E00

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B6D10

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E6630
#define EqSoundManager__PlayScriptMp3_x                            0x4E80D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A1890

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E09A0
#define CSidlManager__FindAnimation1_x                             0x8D5CC0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4DB1A0
#define CAltAbilityData__GetMercMaxRank_x                          0x4DB150
#define CAltAbilityData__GetMaxRank_x                              0x4CF9A0

//CTargetRing
#define CTargetRing__Cast_x                                        0x58D950

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x458A00
#define CharacterBase__CreateItemGlobalIndex_x                     0x4753E0
#define CharacterBase__CreateItemIndex_x                           0x518530
#define CharacterBase__GetItemPossession_x                         0x443CF0
#define CharacterBase__GetItemByGlobalIndex_x                      0x876A10
#define CharacterBase__GetEffectId_x                               0x4589C0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x687C80
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6873E0

//messages
#define msg_spell_worn_off_x                                       0x4F5510
#define msg_new_text_x                                             0x4FEB70
#define msgTokenTextParam_x                                        0x4FB3B0

//SpellManager
#define SpellManager__vftable_x                                    0xABB150
#define SpellManager__SpellManager_x                               0x47E180
#define Spellmanager__CheckSpellRequirementAssociations_x          0x6046C0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x92A100

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F1B10
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43E880
#define ItemGlobalIndex__IsEquippedLocation_x                      0x448AE0
#define ItemGlobalIndex__IsValidIndex_x                            0x4582C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x874890
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8737D0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F9C30

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6A3A60
#define CCursorAttachment__Deactivate_x                            0x6A2FB0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8F1AB0
