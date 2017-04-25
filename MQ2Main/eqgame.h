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
#define __ExpectedVersionDate                                     "Apr 24 2017"
#define __ExpectedVersionTime                                     "17:27:37"
#define __ActualVersionDate_x                                      0xACBDD8
#define __ActualVersionTime_x                                      0xACBDE4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x59C440
#define __MemChecker1_x                                            0x8912E0
#define __MemChecker2_x                                            0x632640
#define __MemChecker3_x                                            0x632590
#define __MemChecker4_x                                            0x7E4030
#define __EncryptPad0_x                                            0xC252A8
#define __EncryptPad1_x                                            0xCFFF38
#define __EncryptPad2_x                                            0xC4E928
#define __EncryptPad3_x                                            0xC4E528
#define __EncryptPad4_x                                            0xCEE538
#define __EncryptPad5_x                                            0x10A8B58
#define __AC1_x                                                    0x7A36D5
#define __AC2_x                                                    0x5562D7
#define __AC3_x                                                    0x554470
#define __AC4_x                                                    0x566531
#define __AC5_x                                                    0x57959B
#define __AC6_x                                                    0x57D14E
#define __AC7_x                                                    0x573B9C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FE5D20

// Direct Input
#define DI8__Main_x                                                0x10A8B30
#define DI8__Keyboard_x                                            0x10A8B34
#define DI8__Mouse_x                                               0x10A8B38
#define DI8__Mouse_Copy_x                                          0xF16EFC
#define DI8__Mouse_Check_x                                         0xFA081C
#define __AutoSkillArray_x                                         0xF17E10
#define __Attack_x                                                 0xF9B403
#define __Autofire_x                                               0xF9B404
#define __BindList_x                                               0xC00110
#define g_eqCommandStates_x                                        0xF05F20
#define __Clicks_x                                                 0xF16FB8
#define __CommandList_x                                            0xC02770
#define __CurrentMapLabel_x                                        0x10AE5B8
#define __CurrentSocial_x                                          0xBD2348
#define __DoAbilityList_x                                          0xF4D6B8
#define __do_loot_x                                                0x525090
#define __DrawHandler_x                                            0x171546C
#define __GroupCount_x                                             0xF07552

#define __Guilds_x                                                 0xF0D168
#define __gWorld_x                                                 0xF09A0C
#define __HotkeyPage_x                                             0xF940B8
#define __HWnd_x                                                   0xFA0938
#define __InChatMode_x                                             0xF16EE4
#define __LastTell_x                                               0xF18DB4
#define __LMouseHeldTime_x                                         0xF17024
#define __Mouse_x                                                  0x10A8B3C
#define __MouseLook_x                                              0xF16F7E
#define __MouseEventTime_x                                         0xF9BC04
#define __gpbCommandEvent_x                                        0xF09AD4
#define __NetStatusToggle_x                                        0xF16F81
#define __PCNames_x                                                0xF183CC
#define __RangeAttackReady_x                                       0xF180F4
#define __RMouseHeldTime_x                                         0xF17020
#define __RunWalkState_x                                           0xF16EE8
#define __ScreenMode_x                                             0xE55C08
#define __ScreenX_x                                                0xF16E9C
#define __ScreenY_x                                                0xF16E98
#define __ScreenXMax_x                                             0xF16EA0
#define __ScreenYMax_x                                             0xF16EA4
#define __ServerHost_x                                             0xF0749C
#define __ServerName_x                                             0xF4D678
#define __ShiftKeyDown_x                                           0xF17578
#define __ShowNames_x                                              0xF182B4
#define __Socials_x                                                0xF4D778
#define __SubscriptionType_x                                       0x10DC57C
#define __TargetAggroHolder_x                                      0x10B078C
#define __ZoneType_x                                               0xF1737C
#define __GroupAggro_x                                             0x10B07CC
#define __LoginName_x                                              0xF9F414
#define __Inviter_x                                                0xF9B380
#define __AttackOnAssist_x                                         0xF18270
#define __UseTellWindows_x                                         0xF18564

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF09AF8
#define instEQZoneInfo_x                                           0xF17174
#define instKeypressHandler_x                                      0xF9BBE8
#define pinstActiveBanker_x                                        0xF09AB0
#define pinstActiveCorpse_x                                        0xF09AB4
#define pinstActiveGMaster_x                                       0xF09AB8
#define pinstActiveMerchant_x                                      0xF09AAC
#define pinstAggroInfo_x                                           0xD135E8
#define pinstAltAdvManager_x                                       0xE56CE8
#define pinstAuraMgr_x                                             0xD23D58
#define pinstBandageTarget_x                                       0xF09A98
#define pinstCamActor_x                                            0xE56638
#define pinstCDBStr_x                                              0xE55B9C
#define pinstCDisplay_x                                            0xF09AC0
#define pinstCEverQuest_x                                          0x10A8CB0
#define pinstEverQuestInfo_x                                       0xF16E90
#define pinstCharData_x                                            0xF09A7C
#define pinstCharSpawn_x                                           0xF09AA4
#define pinstControlledMissile_x                                   0xF09A78
#define pinstControlledPlayer_x                                    0xF09AA4
#define pinstCSidlManager_x                                        0x171485C
#define pinstCXWndManager_x                                        0x1714854
#define instDynamicZone_x                                          0xF16D30
#define pinstDZMember_x                                            0xF16E40
#define pinstDZTimerInfo_x                                         0xF16E44
#define pinstEQItemList_x                                          0xF06174
#define pinstEQObjectList_x                                        0xF06F4C
#define instEQMisc_x                                               0xBE8808
#define pinstEQSoundManager_x                                      0xE572B8
#define instExpeditionLeader_x                                     0xF16D7A
#define instExpeditionName_x                                       0xF16DBA
#define pinstGroup_x                                               0xF0754E
#define pinstImeManager_x                                          0x1714860
#define pinstLocalPlayer_x                                         0xF09A90
#define pinstMercenaryData_x                                       0xF9C268
#define pinstMercenaryStats_x                                      0x10B08D8
#define pinstMercAltAbilities_x                                    0xE57070
#define pinstModelPlayer_x                                         0xF09ABC
#define pinstPCData_x                                              0xF09A7C
#define pinstSkillMgr_x                                            0xF9D0D0
#define pinstSpawnManager_x                                        0xF9C9B8
#define pinstSpellManager_x                                        0xF9D218
#define pinstSpellSets_x                                           0xF9411C
#define pinstStringTable_x                                         0xF09A24
#define pinstSwitchManager_x                                       0xF070E0
#define pinstTarget_x                                              0xF09AA8
#define pinstTargetObject_x                                        0xF09A80
#define pinstTargetSwitch_x                                        0xF09A84
#define pinstTaskMember_x                                          0xE55AE8
#define pinstTrackTarget_x                                         0xF09A9C
#define pinstTradeTarget_x                                         0xF09A8C
#define instTributeActive_x                                        0xBE882D
#define pinstViewActor_x                                           0xE56634
#define pinstWorldData_x                                           0xF09A60
#define pinstZoneAddr_x                                            0xF17414
#define pinstPlayerPath_x                                          0xF9CA18
#define pinstTargetIndicator_x                                     0xF9D3B0
#define pinstCTargetManager_x                                      0xF9D410
#define EQObject_Top_x                                             0xF09A70
#define pinstRealEstateItems_x                                     0xF9CFBC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE56554
#define pinstCAchievementsWnd_x                                    0xE565B0
#define pinstCTextOverlay_x                                        0xD13AE0
#define pinstCAudioTriggersWindow_x                                0xD13970
#define pinstCCharacterSelect_x                                    0xE564C4
#define pinstCFacePick_x                                           0xE56274
#define pinstCNoteWnd_x                                            0xE5647C
#define pinstCBookWnd_x                                            0xE56484
#define pinstCPetInfoWnd_x                                         0xE56488
#define pinstCTrainWnd_x                                           0xE5648C
#define pinstCSkillsWnd_x                                          0xE56490
#define pinstCSkillsSelectWnd_x                                    0xE56494
#define pinstCCombatSkillsSelectWnd_x                              0xE56498
#define pinstCFriendsWnd_x                                         0xE5649C
#define pinstCAuraWnd_x                                            0xE564A0
#define pinstCRespawnWnd_x                                         0xE564A4
#define pinstCBandolierWnd_x                                       0xE564A8
#define pinstCPotionBeltWnd_x                                      0xE564AC
#define pinstCAAWnd_x                                              0xE564B0
#define pinstCAlarmWnd_x                                           0xE564BC
#define pinstCGroupSearchFiltersWnd_x                              0xE564B4
#define pinstCLoadskinWnd_x                                        0xE564B8
#define pinstCLargeDialogWnd_x                                     0x10AF838
#define pinstCMusicPlayerWnd_x                                     0xE564C0
#define pinstCMailWnd_x                                            0xE564C8
#define pinstCMailCompositionWnd_x                                 0xE564CC
#define pinstCMailAddressBookWnd_x                                 0xE564D0
#define pinstCRaidWnd_x                                            0xE564D8
#define pinstCRaidOptionsWnd_x                                     0xE564DC
#define pinstCBreathWnd_x                                          0xE564E0
#define pinstCMapViewWnd_x                                         0xE564E4
#define pinstCMapToolbarWnd_x                                      0xE564E8
#define pinstCEditLabelWnd_x                                       0xE564EC
#define pinstCTargetWnd_x                                          0xE564F0
#define pinstCColorPickerWnd_x                                     0xE564F4
#define pinstCPlayerWnd_x                                          0xE564F8
#define pinstCOptionsWnd_x                                         0xE564FC
#define pinstCBuffWindowNORMAL_x                                   0xE56500
#define pinstCBuffWindowSHORT_x                                    0xE56504
#define pinstCharacterCreation_x                                   0xE56508
#define pinstCCursorAttachment_x                                   0xE5650C
#define pinstCCastingWnd_x                                         0xE56510
#define pinstCCastSpellWnd_x                                       0xE56514
#define pinstCSpellBookWnd_x                                       0xE56518
#define pinstCInventoryWnd_x                                       0xE5651C
#define pinstCBankWnd_x                                            0xE56524
#define pinstCQuantityWnd_x                                        0xE56528
#define pinstCLootWnd_x                                            0xE5652C
#define pinstCActionsWnd_x                                         0xE56530
#define pinstCCombatAbilityWnd_x                                   0xE56538
#define pinstCMerchantWnd_x                                        0xE5653C
#define pinstCTradeWnd_x                                           0xE56544
#define pinstCSelectorWnd_x                                        0xE56548
#define pinstCBazaarWnd_x                                          0xE5654C
#define pinstCBazaarSearchWnd_x                                    0xE56550
#define pinstCGiveWnd_x                                            0xE5656C
#define pinstCTrackingWnd_x                                        0xE56574
#define pinstCInspectWnd_x                                         0xE56578
#define pinstCSocialEditWnd_x                                      0xE5657C
#define pinstCFeedbackWnd_x                                        0xE56580
#define pinstCBugReportWnd_x                                       0xE56584
#define pinstCVideoModesWnd_x                                      0xE56588
#define pinstCTextEntryWnd_x                                       0xE56590
#define pinstCFileSelectionWnd_x                                   0xE56594
#define pinstCCompassWnd_x                                         0xE56598
#define pinstCPlayerNotesWnd_x                                     0xE5659C
#define pinstCGemsGameWnd_x                                        0xE565A0
#define pinstCTimeLeftWnd_x                                        0xE565A4
#define pinstCPetitionQWnd_x                                       0xE565C0
#define pinstCStoryWnd_x                                           0xE565C4
#define pinstCJournalTextWnd_x                                     0xE565C8
#define pinstCJournalCatWnd_x                                      0xE565CC
#define pinstCBodyTintWnd_x                                        0xE565D0
#define pinstCServerListWnd_x                                      0xE565D4
#define pinstCAvaZoneWnd_x                                         0xE565E0
#define pinstCBlockedBuffWnd_x                                     0xE565E4
#define pinstCBlockedPetBuffWnd_x                                  0xE565E8
#define pinstCInvSlotMgr_x                                         0xE5662C
#define pinstCContainerMgr_x                                       0xE56630
#define pinstCAdventureLeaderboardWnd_x                            0x10A9660
#define pinstCAdventureRequestWnd_x                                0x10A96D8
#define pinstCAltStorageWnd_x                                      0x10A99B8
#define pinstCAdventureStatsWnd_x                                  0x10A9750
#define pinstCBarterMerchantWnd_x                                  0x10AA5A0
#define pinstCBarterSearchWnd_x                                    0x10AA618
#define pinstCBarterWnd_x                                          0x10AA690
#define pinstCChatWindowManager_x                                  0x10AAD20
#define pinstCDynamicZoneWnd_x                                     0x10AB1D0
#define pinstCEQMainWnd_x                                          0x10AB368
#define pinstCFellowshipWnd_x                                      0x10AB164
#define pinstCFindLocationWnd_x                                    0x10AB638
#define pinstCGroupSearchWnd_x                                     0x10AB908
#define pinstCGroupWnd_x                                           0x10AB980
#define pinstCGuildBankWnd_x                                       0x10AB9F8
#define pinstCGuildMgmtWnd_x                                       0x10ADAE8
#define pinstCHotButtonWnd_x                                       0x10ADBE4
#define pinstCHotButtonWnd1_x                                      0x10ADBE4
#define pinstCHotButtonWnd2_x                                      0x10ADBE8
#define pinstCHotButtonWnd3_x                                      0x10ADBEC
#define pinstCHotButtonWnd4_x                                      0x10ADC10
#define pinstCItemDisplayManager_x                                 0x10ADF08
#define pinstCItemExpTransferWnd_x                                 0x10ADF84
#define pinstCLFGuildWnd_x                                         0x10AE260
#define pinstCMIZoneSelectWnd_x                                    0x10AE848
#define pinstCConfirmationDialog_x                                 0x10AEF50
#define pinstCPopupWndManager_x                                    0x10AEF50
#define pinstCProgressionSelectionWnd_x                            0x10AF040
#define pinstCPvPStatsWnd_x                                        0x10AF130
#define pinstCTaskWnd_x                                            0x10B0BB8
#define pinstCTaskSomething_x                                      0xD24690
#define pinstCTaskTemplateSelectWnd_x                              0x10B0B40
#define pinstCTipWndOFDAY_x                                        0x10B0D20
#define pinstCTipWndCONTEXT_x                                      0x10B0D24
#define pinstCTitleWnd_x                                           0x10B0DA0
#define pinstCContextMenuManager_x                                 0x17147CC
#define pinstCVoiceMacroWnd_x                                      0xF9D7E8
#define pinstCHtmlWnd_x                                            0xF9D8D8
#define pinstIconCache_x                                           0x10AB33C
#define pinstCTradeskillWnd_x                                      0x10B0EA0
#define pinstCAdvancedLootWnd_x                                    0xE56620
#define pinstRewardSelectionWnd_x                                  0x10AF658

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x53C1D0
#define __ConvertItemTags_x                                        0x529B90
#define __ExecuteCmd_x                                             0x514720
#define __EQGetTime_x                                              0x890F70
#define __get_melee_range_x                                        0x51B360
#define __GetGaugeValueFromEQ_x                                    0x7A2290
#define __GetLabelFromEQ_x                                         0x7A3660
#define __ToggleKeyRingItem_x                                      0x484220
#define __GetXTargetType_x                                         0x921980
#define __LoadFrontEnd_x                                           0x631D10
#define __NewUIINI_x                                               0x7A1C60
#define __ProcessGameEvents_x                                      0x575930
#define __ProcessMouseEvent_x                                      0x5750D0
#define CrashDetected_x                                            0x6336D0
#define wwsCrashReportCheckForUploader_x                           0x7EFEE0
#define __AppCrashWrapper_x                                        0xC4E51C
#define __pCrashHandler_x                                          0x10BDD50
#define __CrashHandler_x                                           0x7EF970
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F2110
#define DrawNetStatus_x                                            0x5AC090
#define Util__FastTime_x                                           0x890C10
#define Expansion_HoT_x                                            0xF18260
#define __HelpPath_x                                               0xF9B970
#define __STMLToText_x                                             0x8D6C00

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4230A0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DE40
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DC20

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4CBD70
#define AltAdvManager__IsAbilityReady_x                            0x4CBDE0
#define AltAdvManager__GetAAById_x                                 0x4CC2D0
#define AltAdvManager__CanTrainAbility_x                           0x4CCF00
#define AltAdvManager__CanSeeAbility_x                             0x4CCAC0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465F20
#define CharacterZoneClient__MakeMeVisible_x                       0x46A600
#define CharacterZoneClient__IsStackBlocked_x                      0x44A5D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x449A90
#define CharacterZoneClient__GetItemCountWorn_x                    0x463EA0
#define CharacterZoneClient__GetItemCountInInventory_x             0x463F80
#define CharacterZoneClient__GetCursorItemCount_x                  0x464060
#define CharacterZoneClient__FindAffectSlot_x                      0x44FB20

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x661520

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66F720

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58B220
#define CButtonWnd__CButtonWnd_x                                   0x8CB060

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68A8B0
#define CChatManager__InitContextMenu_x                            0x68BA00
#define CChatManager__FreeChatWindow_x                             0x68A340
#define CChatManager__GetLockedActiveChatWindow_x                  0x693270
#define CChatManager__SetLockedActiveChatWindow_x                  0x68A880

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D4F60
#define CContextMenu__dCContextMenu_x                              0x8D5170
#define CContextMenu__AddMenuItem_x                                0x8D5180
#define CContextMenu__RemoveMenuItem_x                             0x8D5470
#define CContextMenu__RemoveAllMenuItems_x                         0x8D5490
#define CContextMenu__CheckMenuItem_x                              0x8D5510

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8C15B0
#define CContextMenuManager__RemoveMenu_x                          0x8C1950
#define CContextMenuManager__PopupMenu_x                           0x8C1DA0
#define CContextMenuManager__Flush_x                               0x8C1620
#define CContextMenuManager__GetMenu_x                             0x419520

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x875440
#define CChatService__GetFriendName_x                              0x875450

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6915E0
#define CChatWindow__Clear_x                                       0x690EC0
#define CChatWindow__WndNotification_x                             0x691B20

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C5400
#define CComboWnd__Draw_x                                          0x8C5610
#define CComboWnd__GetCurChoice_x                                  0x8C51B0
#define CComboWnd__GetListRect_x                                   0x8C58B0
#define CComboWnd__GetTextRect_x                                   0x8C5470
#define CComboWnd__InsertChoice_x                                  0x8C5920
#define CComboWnd__SetColors_x                                     0x8C5140
#define CComboWnd__SetChoice_x                                     0x8C5170
#define CComboWnd__GetItemCount_x                                  0x8C51A0
#define CComboWnd__GetCurChoiceText_x                              0x8C51F0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69B000
#define CContainerWnd__vftable_x                                   0xAD59C0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BA1D0
#define CDisplay__GetClickedActor_x                                0x4B2B10
#define CDisplay__GetUserDefinedColor_x                            0x4B16F0
#define CDisplay__GetWorldFilePath_x                               0x4B0B40
#define CDisplay__is3dON_x                                         0x4AFFD0
#define CDisplay__ReloadUI_x                                       0x4C5750
#define CDisplay__WriteTextHD2_x                                   0x4B6590

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EB610

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D94B0
#define CEditWnd__GetCharIndexPt_x                                 0x8DA550
#define CEditWnd__GetDisplayString_x                               0x8D9660
#define CEditWnd__GetHorzOffset_x                                  0x8D99A0
#define CEditWnd__GetLineForPrintableChar_x                        0x8DA010
#define CEditWnd__GetSelStartPt_x                                  0x8DA810
#define CEditWnd__GetSTMLSafeText_x                                0x8D9B40
#define CEditWnd__PointFromPrintableChar_x                         0x8DA100
#define CEditWnd__SelectableCharFromPoint_x                        0x8DA280
#define CEditWnd__SetEditable_x                                    0x8D9B10

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x55CD60
#define CEverQuest__ClickedPlayer_x                                0x556A20
#define CEverQuest__CreateTargetIndicator_x                        0x557910
#define CEverQuest__DeleteTargetIndicator_x                        0x557990
#define CEverQuest__DoTellWindow_x                                 0x475190
#define CEverQuest__OutputTextToLog_x                              0x474DF0
#define CEverQuest__DropHeldItemOnGround_x                         0x56D770
#define CEverQuest__dsp_chat_x                                     0x4754D0
#define CEverQuest__trimName_x                                     0x553370
#define CEverQuest__Emote_x                                        0x56B550
#define CEverQuest__EnterZone_x                                    0x5666C0
#define CEverQuest__GetBodyTypeDesc_x                              0x550DD0
#define CEverQuest__GetClassDesc_x                                 0x55A1A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x55A7A0
#define CEverQuest__GetDeityDesc_x                                 0x5516B0
#define CEverQuest__GetLangDesc_x                                  0x551160
#define CEverQuest__GetRaceDesc_x                                  0x55A960
#define CEverQuest__InterpretCmd_x                                 0x55E4E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x571FF0
#define CEverQuest__LMouseUp_x                                     0x5740F0
#define CEverQuest__RightClickedOnPlayer_x                         0x572B00
#define CEverQuest__RMouseUp_x                                     0x573B50
#define CEverQuest__SetGameState_x                                 0x5572E0
#define CEverQuest__UPCNotificationFlush_x                         0x54EBE0
#define CEverQuest__IssuePetCommand_x                              0x55EEC0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6ABBC0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6ABC20
#define CGaugeWnd__Draw_x                                          0x6AC050

// CGuild
#define CGuild__FindMemberByName_x                                 0x439F40
#define CGuild__GetGuildName_x                                     0x43A410
#define CGuild__GetGuildIndex_x                                    0x43B5E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C8100

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D52C0
#define CInvSlotMgr__MoveItem_x                                    0x6D6170
#define CInvSlotMgr__SelectSlot_x                                  0x6D5370

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D4770
#define CInvSlot__SliderComplete_x                                 0x6D1F80
#define CInvSlot__GetItemBase_x                                    0x6D13E0
#define CInvSlot__UpdateItem_x                                     0x6D1960

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D75C0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6D86E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79DC70
#define CItemDisplayWnd__UpdateStrings_x                           0x6D9740
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6E6230
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6E6750
#define CItemDisplayWnd__SetItem_x                                 0x6EC240

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7D50C0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6DFD20

// CLabel 
#define CLabel__Draw_x                                             0x6F2EC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B1030
#define CListWnd__dCListWnd_x                                      0x8B2260
#define CListWnd__AddColumn_x                                      0x8B2200
#define CListWnd__AddColumn1_x                                     0x8B1890
#define CListWnd__AddLine_x                                        0x8B12F0
#define CListWnd__AddString_x                                      0x8B1510
#define CListWnd__CalculateFirstVisibleLine_x                      0x8AE2A0
#define CListWnd__CalculateVSBRange_x                              0x8B04F0
#define CListWnd__ClearSel_x                                       0x8AD5B0
#define CListWnd__ClearAllSel_x                                    0x8AD560
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B0EC0
#define CListWnd__Compare_x                                        0x8AEE20
#define CListWnd__Draw_x                                           0x8B00F0
#define CListWnd__DrawColumnSeparators_x                           0x8AFF80
#define CListWnd__DrawHeader_x                                     0x8AD870
#define CListWnd__DrawItem_x                                       0x8AF4B0
#define CListWnd__DrawLine_x                                       0x8AFC20
#define CListWnd__DrawSeparator_x                                  0x8B0020
#define CListWnd__EnableLine_x                                     0x8AD790
#define CListWnd__EnsureVisible_x                                  0x8AE400
#define CListWnd__ExtendSel_x                                      0x8AF3C0
#define CListWnd__GetColumnMinWidth_x                              0x8ACF60
#define CListWnd__GetColumnWidth_x                                 0x8ACE90
#define CListWnd__GetCurSel_x                                      0x8AC660
#define CListWnd__GetItemAtPoint_x                                 0x8AE6A0
#define CListWnd__GetItemAtPoint1_x                                0x8AE710
#define CListWnd__GetItemData_x                                    0x8AC9A0
#define CListWnd__GetItemHeight_x                                  0x8ADEF0
#define CListWnd__GetItemIcon_x                                    0x8ACB90
#define CListWnd__GetItemRect_x                                    0x8AE4E0
#define CListWnd__GetItemText_x                                    0x8ACA40
#define CListWnd__GetSelList_x                                     0x8B1780
#define CListWnd__GetSeparatorRect_x                               0x8AED40
#define CListWnd__InsertLine_x                                     0x8B16F0
#define CListWnd__RemoveLine_x                                     0x8B1700
#define CListWnd__SetColors_x                                      0x8AC7B0
#define CListWnd__SetColumnJustification_x                         0x8AD1F0
#define CListWnd__SetColumnWidth_x                                 0x8ACF10
#define CListWnd__SetCurSel_x                                      0x8AC6A0
#define CListWnd__SetItemColor_x                                   0x8B0BB0
#define CListWnd__SetItemData_x                                    0x8AD610
#define CListWnd__SetItemText_x                                    0x8B09F0
#define CListWnd__ShiftColumnSeparator_x                           0x8B0880
#define CListWnd__Sort_x                                           0x8B2360
#define CListWnd__ToggleSel_x                                      0x8AD4E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70BFF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72D330
#define CMerchantWnd__RequestBuyItem_x                             0x7343D0
#define CMerchantWnd__RequestSellItem_x                            0x734E90
#define CMerchantWnd__SelectRecoverySlot_x                         0x72D5E0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72C7E0
#define CMerchantWnd__ActualSelect_x                               0x7312B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8438B0
#define CPacketScrambler__hton_x                                   0x8438C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8CFEB0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CFF90
#define CSidlManager__CreateLabel_x                                0x7955D0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8CE460
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D0270

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8C74A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8C7390
#define CSidlScreenWnd__ConvertToRes_x                             0x8EB4F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C7DB0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C8F80
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C9030
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C8500
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C7760
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C6EC0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C7950
#define CSidlScreenWnd__Init1_x                                    0x8C8C50
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C7E60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C7080
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C8740
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C6B20
#define CSidlScreenWnd__StoreIniVis_x                              0x8C6E70
#define CSidlScreenWnd__WndNotification_x                          0x8C89D0
#define CSidlScreenWnd__GetChildItem_x                             0x8C6F90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BA820
#define CSidlScreenWnd__m_layoutCopy_x                             0x1714830

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F7520
#define CSkillMgr__GetSkillCap_x                                   0x5F7700
#define CSkillMgr__GetNameToken_x                                  0x5F70D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EA7A0
#define CSliderWnd__SetValue_x                                     0x8EA970
#define CSliderWnd__SetNumTicks_x                                  0x8EB0F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79B8D0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E6170
#define CStmlWnd__CalculateHSBRange_x                              0x8DE730
#define CStmlWnd__CalculateVSBRange_x                              0x8DE6A0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DE8B0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DF190
#define CStmlWnd__ForceParseNow_x                                  0x8E6AC0
#define CStmlWnd__GetNextTagPiece_x                                0x8DF090
#define CStmlWnd__GetSTMLText_x                                    0x693230
#define CStmlWnd__GetVisibleText_x                                 0x8DFBE0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E1F70
#define CStmlWnd__MakeStmlColorTag_x                               0x8DD9A0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8DDA00
#define CStmlWnd__SetSTMLText_x                                    0x8E37D0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E5E10
#define CStmlWnd__UpdateHistoryString_x                            0x8E0B20

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8DD0B0
#define CTabWnd__DrawCurrentPage_x                                 0x8DC940
#define CTabWnd__DrawTab_x                                         0x8DC700
#define CTabWnd__GetCurrentPage_x                                  0x8DCCF0
#define CTabWnd__GetPageInnerRect_x                                0x8DC3F0
#define CTabWnd__GetTabInnerRect_x                                 0x8DC5F0
#define CTabWnd__GetTabRect_x                                      0x8DC4C0
#define CTabWnd__InsertPage_x                                      0x8DD3A0
#define CTabWnd__SetPage_x                                         0x8DCD20
#define CTabWnd__SetPageRect_x                                     0x8DCFF0
#define CTabWnd__UpdatePage_x                                      0x8DD340
#define CTabWnd__GetPageFromTabIndex_x                             0x8DC650
#define CTabWnd__GetCurrentTabIndex_x                              0x8DC380

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6D8890
#define CPageWnd__SetTabText_x                                     0x8F4550

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x435AF0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C4DB0
#define CTextureFont__GetTextExtent_x                              0x8C4B10

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x62FFB0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F0990

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AA910

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029C0
#define CXStr__CXStr1_x                                            0x8EF700
#define CXStr__CXStr3_x                                            0x88DEF0
#define CXStr__dCXStr_x                                            0x4CD9D0
#define CXStr__operator_equal_x                                    0x88E060
#define CXStr__operator_equal1_x                                   0x88E0B0
#define CXStr__operator_plus_equal1_x                              0x88F1B0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B9A20
#define CXWnd__Center_x                                            0x8BFBD0
#define CXWnd__ClrFocus_x                                          0x8B95F0
#define CXWnd__Destroy_x                                           0x8C06B0
#define CXWnd__DoAllDrawing_x                                      0x8BF820
#define CXWnd__DrawChildren_x                                      0x8BF9C0
#define CXWnd__DrawColoredRect_x                                   0x8B9E00
#define CXWnd__DrawTooltip_x                                       0x8BA0B0
#define CXWnd__DrawTooltipAtPoint_x                                0x8BE770
#define CXWnd__GetBorderFrame_x                                    0x8BA510
#define CXWnd__GetChildWndAt_x                                     0x8C05A0
#define CXWnd__GetClientClipRect_x                                 0x8BA2D0
#define CXWnd__GetScreenClipRect_x                                 0x8BEE70
#define CXWnd__GetScreenRect_x                                     0x8BA6C0
#define CXWnd__GetTooltipRect_x                                    0x8B9F40
#define CXWnd__GetWindowTextA_x                                    0x4270D0
#define CXWnd__IsActive_x                                          0x8B4FD0
#define CXWnd__IsDescendantOf_x                                    0x8BA460
#define CXWnd__IsReallyVisible_x                                   0x8BD7B0
#define CXWnd__IsType_x                                            0x8BFC40
#define CScreenPieceTemplate__IsType_x                             0x8ED1A0
#define CXWnd__Move_x                                              0x8BCEA0
#define CXWnd__Move1_x                                             0x8BF4C0
#define CXWnd__ProcessTransition_x                                 0x8B99C0
#define CXWnd__Refade_x                                            0x8B97A0
#define CXWnd__Resize_x                                            0x8BA780
#define CXWnd__Right_x                                             0x8BEC70
#define CXWnd__SetFocus_x                                          0x8BC010
#define CXWnd__SetFont_x                                           0x8B9640
#define CXWnd__SetKeyTooltip_x                                     0x8BA9F0
#define CXWnd__SetMouseOver_x                                      0x8BF1B0
#define CXWnd__StartFade_x                                         0x8B9A70
#define CXWnd__GetChildItem_x                                      0x8BF0F0
#define CXWnd__SetParent_x                                         0x8C0550

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B6860
#define CXWndManager__DrawWindows_x                                0x8B64A0
#define CXWndManager__GetKeyboardFlags_x                           0x8B4B40
#define CXWndManager__HandleKeyboardMsg_x                          0x8B5460
#define CXWndManager__RemoveWnd_x                                  0x8B5160

// CDBStr
#define CDBStr__GetString_x                                        0x4AE500

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x450B50
#define EQ_Character__Cur_HP_x                                     0x465520
#define EQ_Character__Cur_Mana_x                                   0x4592D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x449DA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x442120
#define EQ_Character__GetFocusRangeModifier_x                      0x442180
#define EQ_Character__GetHPRegen_x                                 0x468700
#define EQ_Character__GetEnduranceRegen_x                          0x464B30
#define EQ_Character__GetManaRegen_x                               0x468CA0
#define EQ_Character__Max_Endurance_x                              0x5BDF50
#define EQ_Character__Max_HP_x                                     0x45BE40
#define EQ_Character__Max_Mana_x                                   0x5BDD80
#define EQ_Character__doCombatAbility_x                            0x5BB460
#define EQ_Character__UseSkill_x                                   0x46F680
#define EQ_Character__GetConLevel_x                                0x5B0710
#define EQ_Character__IsExpansionFlag_x                            0x426600
#define EQ_Character__TotalEffect_x                                0x44DE50
#define EQ_Character__GetPCSpellAffect_x                           0x44A1A0
#define EQ_Character__SpellDuration_x                              0x448140
#define EQ_Character__FindItemByRecord_x                           0x462B70
#define EQ_Character__GetAdjustedSkill_x                           0x465CD0
#define EQ_Character__GetBaseSkill_x                               0x45BD20

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x860F50

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5C5F30

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x445460
#define CCharacterSelect__EnterWorld_x                             0x444C30
#define CCharacterSelect__Quit_x                                   0x443820

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x590C70
#define EQ_Item__CreateItemTagString_x                             0x842240
#define EQ_Item__IsStackable_x                                     0x837CB0
#define EQ_Item__GetImageNum_x                                     0x83A740
#define EQ_Item__CreateItemClient_x                                0x591870
#define EQ_Item__GetItemValue_x                                    0x840FA0
#define EQ_Item__ValueSellMerchant_x                               0x843510
#define EQ_Item__IsKeyRingItem_x                                   0x838710
#define EQ_Item__CanGoInBag_x                                      0x590E00
#define EQ_Item__GetMaxItemCount_x                                 0x837BA0
#define EQ_Item__GetHeldItem_x                                     0x839550
#define EQ_Item__GetAugmentFitBySlot_x                             0x843330

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4CE360
#define EQ_LoadingS__Array_x                                       0xBF0BB8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C03E0
#define EQ_PC__GetAlternateAbilityId_x                             0x84B980
#define EQ_PC__GetCombatAbility_x                                  0x84BA10
#define EQ_PC__GetCombatAbilityTimer_x                             0x846560
#define EQ_PC__GetItemRecastTimer_x                                0x5B9B10
#define EQ_PC__HasLoreItem_x                                       0x5B3D00
#define EQ_PC__AlertInventoryChanged_x                             0x5B06E0
#define EQ_PC__GetPcZoneClient_x                                   0x5DA320
#define EQ_PC__RemoveMyAffect_x                                    0x5B8FE0
#define EQ_PC__GetKeyRingItems_x                                   0x846980
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x859690
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x84D900

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5193F0
#define EQItemList__add_object_x                                   0x545B40
#define EQItemList__add_item_x                                     0x519330
#define EQItemList__delete_item_x                                  0x5197E0
#define EQItemList__FreeItemList_x                                 0x5196E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4AD790

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C5CD0
#define EQPlayer__dEQPlayer_x                                      0x5CE270
#define EQPlayer__DoAttack_x                                       0x5DFF90
#define EQPlayer__EQPlayer_x                                       0x5D0980
#define EQPlayer__SetNameSpriteState_x                             0x5CB1C0
#define EQPlayer__SetNameSpriteTint_x                              0x5C70E0
#define PlayerBase__HasProperty_j_x                                0x91E190
#define EQPlayer__IsTargetable_x                                   0x91E430
#define EQPlayer__CanSee_x                                         0x91E990
#define PlayerZoneClient__ChangeHeight_x                           0x5DFE50
#define EQPlayer__CanSeeTargetIndicator_x                          0x91EA80
#define PlayerBase__GetVisibilityLineSegment_x                     0x91E720

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D4980
#define EQPlayerManager__GetSpawnByName_x                          0x5D4DE0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D49B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x596D40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x596D80
#define KeypressHandler__ClearCommandStateArray_x                  0x596930
#define KeypressHandler__HandleKeyDown_x                           0x595290
#define KeypressHandler__HandleKeyUp_x                             0x5955B0
#define KeypressHandler__SaveKeymapping_x                          0x596A00

// MapViewMap 
#define MapViewMap__Clear_x                                        0x704980
#define MapViewMap__SaveEx_x                                       0x707CB0

#define PlayerPointManager__GetAltCurrency_x                       0x85F040

// StringTable 
#define StringTable__getString_x                                   0x8599C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BD9E0
#define PcZoneClient__RemovePetEffect_x                            0x5B9FE0
#define PcZoneClient__HasAlternateAbility_x                        0x5BA980
#define PcZoneClient__GetCurrentMod_x                              0x45B2F0
#define PcZoneClient__GetModCap_x                                  0x458A30
#define PcZoneClient__CanEquipItem_x                               0x5BAF30
#define PcZoneClient__GetItemByID_x                                0x5BF7D0
#define PcZoneClient__GetItemByItemClass_x                         0x5C0300

//Doors
#define EQSwitch__UseSwitch_x                                      0x54D500

//IconCache
#define IconCache__GetIcon_x                                       0x6A14A0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x698300
#define CContainerMgr__CloseContainer_x                            0x698B20

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7653F0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x589C40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E8380
#define EQ_Spell__SpellAffects_x                                   0x4E5A30
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E5AA0
#define CharacterZoneClient__CalcAffectChange_x                    0x449270
#define CLootWnd__LootAll_x                                        0x6FA250
#define CLootWnd__RequestLootSlot_x                                0x6FAA60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AABB0
#define CTargetWnd__WndNotification_x                              0x7AA6A0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7AAD90

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AFC90

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E1080
#define EqSoundManager__PlayScriptMp3_x                            0x4E2B20

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x49CB60

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8D8AE0
#define CSidlManager__FindAnimation1_x                             0x8CDE90

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D5AA0
#define CAltAbilityData__GetMercMaxRank_x                          0x4D5A50
#define CAltAbilityData__GetMaxRank_x                              0x4CA420

//CTargetRing
#define CTargetRing__Cast_x                                        0x587530

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x457A00
#define CharacterBase__CreateItemGlobalIndex_x                     0x474350
#define CharacterBase__CreateItemIndex_x                           0x5129A0
#define CharacterBase__GetItemPossession_x                         0x442CF0
#define CharacterBase__GetItemByGlobalIndex_x                      0x86F120

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x681AD0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x681230

//messages
#define msg_spell_worn_off_x                                       0x4EFDA0
#define msg_new_text_x                                             0x4F9360
#define msgTokenTextParam_x                                        0x4F5BC0

//SpellManager
#define SpellManager__vftable_x                                    0xAB2108
#define SpellManager__SpellManager_x                               0x47D0B0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5FE450

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9224A0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4EC450
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43D8B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x447AD0
#define ItemGlobalIndex__IsValidIndex_x                            0x457250

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x86CFA0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x86BEE0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F3110

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x69D0A0
#define CCursorAttachment__Deactivate_x                            0x69C5F0
