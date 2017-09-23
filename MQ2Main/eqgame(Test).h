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
#define __ExpectedVersionDate                                     "Sep 22 2017"
#define __ExpectedVersionTime                                     "12:42:42"
#define __ActualVersionDate_x                                      0xAE5320
#define __ActualVersionTime_x                                      0xAE532C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5AAE60
#define __MemChecker1_x                                            0x8A3000
#define __MemChecker2_x                                            0x640EB0
#define __MemChecker3_x                                            0x640E00
#define __MemChecker4_x                                            0x7F4830
#define __EncryptPad0_x                                            0xC42298
#define __EncryptPad1_x                                            0xD1DD50
#define __EncryptPad2_x                                            0xC6BCD8
#define __EncryptPad3_x                                            0xC6B8D8
#define __EncryptPad4_x                                            0xD0C350
#define __EncryptPad5_x                                            0x10C73A8
#define __AC1_x                                                    0x7B3A45
#define __AC2_x                                                    0x563C07
#define __AC3_x                                                    0x561D80
#define __AC4_x                                                    0x573FA1
#define __AC5_x                                                    0x587E4B
#define __AC6_x                                                    0x58B9FE
#define __AC7_x                                                    0x58244C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FACF90

// Direct Input
#define DI8__Main_x                                                0x10C7380
#define DI8__Keyboard_x                                            0x10C7384
#define DI8__Mouse_x                                               0x10C7388
#define DI8__Mouse_Copy_x                                          0xF354AC
#define DI8__Mouse_Check_x                                         0xFBF06C
#define __AutoSkillArray_x                                         0xF363C0
#define __Attack_x                                                 0xFB99C3
#define __Autofire_x                                               0xFB99C4
#define __BindList_x                                               0xC1CDB0
#define g_eqCommandStates_x                                        0xF243D0
#define __Clicks_x                                                 0xF35568
#define __CommandList_x                                            0xC1F4B0
#define __CurrentMapLabel_x                                        0x10CD378
#define __CurrentSocial_x                                          0xBEC4E0
#define __DoAbilityList_x                                          0xF6BC78
#define __do_loot_x                                                0x532ED0
#define __DrawHandler_x                                            0x17348FC
#define __GroupCount_x                                             0xF25B02

#define __Guilds_x                                                 0xF2B718
#define __gWorld_x                                                 0xF27FBC
#define __HotkeyPage_x                                             0xFB2678
#define __HWnd_x                                                   0xFBF188
#define __InChatMode_x                                             0xF35494
#define __LastTell_x                                               0xF37374
#define __LMouseHeldTime_x                                         0xF355D4
#define __Mouse_x                                                  0x10C738C
#define __MouseLook_x                                              0xF3552E
#define __MouseEventTime_x                                         0xFBA24C
#define __gpbCommandEvent_x                                        0xF28084
#define __NetStatusToggle_x                                        0xF35531
#define __PCNames_x                                                0xF36984
#define __RangeAttackReady_x                                       0xF366A4
#define __RMouseHeldTime_x                                         0xF355D0
#define __RunWalkState_x                                           0xF35498
#define __ScreenMode_x                                             0xE73FB0
#define __ScreenX_x                                                0xF3544C
#define __ScreenY_x                                                0xF35448
#define __ScreenXMax_x                                             0xF35450
#define __ScreenYMax_x                                             0xF35454
#define __ServerHost_x                                             0xF25A4C
#define __ServerName_x                                             0xF6BC38
#define __ShiftKeyDown_x                                           0xF35B28
#define __ShowNames_x                                              0xF36864
#define __Socials_x                                                0xF6BD38
#define __SubscriptionType_x                                       0x10FB404
#define __TargetAggroHolder_x                                      0x10CF5C4
#define __ZoneType_x                                               0xF3592C
#define __GroupAggro_x                                             0x10CF604
#define __LoginName_x                                              0xFBDC64
#define __Inviter_x                                                0xFB9940
#define __AttackOnAssist_x                                         0xF36820
#define __UseTellWindows_x                                         0xF36B1C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF280A8
#define instEQZoneInfo_x                                           0xF35724
#define instKeypressHandler_x                                      0xFBA230
#define pinstActiveBanker_x                                        0xF28060
#define pinstActiveCorpse_x                                        0xF28064
#define pinstActiveGMaster_x                                       0xF28068
#define pinstActiveMerchant_x                                      0xF2805C
#define pinstAggroInfo_x                                           0xD31608
#define pinstAltAdvManager_x                                       0xE75118
#define pinstAuraMgr_x                                             0xD41E20
#define pinstBandageTarget_x                                       0xF28048
#define pinstCamActor_x                                            0xE749E8
#define pinstCDBStr_x                                              0xE73F44
#define pinstCDisplay_x                                            0xF28070
#define pinstCEverQuest_x                                          0x10C7500
#define pinstEverQuestInfo_x                                       0xF35440
#define pinstCharData_x                                            0xF2802C
#define pinstCharSpawn_x                                           0xF28054
#define pinstControlledMissile_x                                   0xF28028
#define pinstControlledPlayer_x                                    0xF28054
#define pinstCSidlManager_x                                        0x1733868
#define pinstCXWndManager_x                                        0x1733860
#define instDynamicZone_x                                          0xF352E0
#define pinstDZMember_x                                            0xF353F0
#define pinstDZTimerInfo_x                                         0xF353F4
#define pinstEQItemList_x                                          0xF246A8
#define pinstEQObjectList_x                                        0xF254FC
#define instEQMisc_x                                               0xC052B8
#define pinstEQSoundManager_x                                      0xE756E8
#define instExpeditionLeader_x                                     0xF3532A
#define instExpeditionName_x                                       0xF3536A
#define pinstGroup_x                                               0xF25AFE
#define pinstImeManager_x                                          0x173386C
#define pinstLocalPlayer_x                                         0xF28040
#define pinstMercenaryData_x                                       0xFBA8B0
#define pinstMercenaryStats_x                                      0x10CF710
#define pinstMercAltAbilities_x                                    0xE754A0
#define pinstModelPlayer_x                                         0xF2806C
#define pinstPCData_x                                              0xF2802C
#define pinstSkillMgr_x                                            0xFBB920
#define pinstSpawnManager_x                                        0xFBB100
#define pinstSpellManager_x                                        0xFBBA68
#define pinstSpellSets_x                                           0xFB26DC
#define pinstStringTable_x                                         0xF27FD4
#define pinstSwitchManager_x                                       0xF25690
#define pinstTarget_x                                              0xF28058
#define pinstTargetObject_x                                        0xF28030
#define pinstTargetSwitch_x                                        0xF28034
#define pinstTaskMember_x                                          0xE73E90
#define pinstTrackTarget_x                                         0xF2804C
#define pinstTradeTarget_x                                         0xF2803C
#define instTributeActive_x                                        0xC052DD
#define pinstViewActor_x                                           0xE749E4
#define pinstWorldData_x                                           0xF28010
#define pinstZoneAddr_x                                            0xF359C4
#define pinstPlayerPath_x                                          0xFBB160
#define pinstTargetIndicator_x                                     0xFBBC00
#define pinstCTargetManager_x                                      0xFBBC60
#define EQObject_Top_x                                             0xF28020
#define pinstRealEstateItems_x                                     0xFBB78C

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE74900
#define pinstCAchievementsWnd_x                                    0xE7495C
#define pinstCTextOverlay_x                                        0xD31BB0
#define pinstCAudioTriggersWindow_x                                0xD31998
#define pinstCCharacterSelect_x                                    0xE7486C
#define pinstCFacePick_x                                           0xE7461C
#define pinstCFindItemWnd_x                                        0xE748FC
#define pinstCNoteWnd_x                                            0xE74824
#define pinstCBookWnd_x                                            0xE7482C
#define pinstCPetInfoWnd_x                                         0xE74830
#define pinstCTrainWnd_x                                           0xE74834
#define pinstCSkillsWnd_x                                          0xE74838
#define pinstCSkillsSelectWnd_x                                    0xE7483C
#define pinstCCombatSkillsSelectWnd_x                              0xE74840
#define pinstCFriendsWnd_x                                         0xE74844
#define pinstCAuraWnd_x                                            0xE74848
#define pinstCRespawnWnd_x                                         0xE7484C
#define pinstCBandolierWnd_x                                       0xE74850
#define pinstCPotionBeltWnd_x                                      0xE74854
#define pinstCAAWnd_x                                              0xE74858
#define pinstCGroupSearchFiltersWnd_x                              0xE7485C
#define pinstCLoadskinWnd_x                                        0xE74860
#define pinstCAlarmWnd_x                                           0xE74864
#define pinstCMusicPlayerWnd_x                                     0xE74868
#define pinstCMailWnd_x                                            0xE74870
#define pinstCMailCompositionWnd_x                                 0xE74874
#define pinstCMailAddressBookWnd_x                                 0xE74878
#define pinstCRaidWnd_x                                            0xE74880
#define pinstCRaidOptionsWnd_x                                     0xE74884
#define pinstCBreathWnd_x                                          0xE74888
#define pinstCMapViewWnd_x                                         0xE7488C
#define pinstCMapToolbarWnd_x                                      0xE74890
#define pinstCEditLabelWnd_x                                       0xE74894
#define pinstCTargetWnd_x                                          0xE74898
#define pinstCColorPickerWnd_x                                     0xE7489C
#define pinstCPlayerWnd_x                                          0xE748A0
#define pinstCOptionsWnd_x                                         0xE748A4
#define pinstCBuffWindowNORMAL_x                                   0xE748A8
#define pinstCBuffWindowSHORT_x                                    0xE748AC
#define pinstCharacterCreation_x                                   0xE748B0
#define pinstCCursorAttachment_x                                   0xE748B4
#define pinstCCastingWnd_x                                         0xE748B8
#define pinstCCastSpellWnd_x                                       0xE748BC
#define pinstCSpellBookWnd_x                                       0xE748C0
#define pinstCInventoryWnd_x                                       0xE748C4
#define pinstCBankWnd_x                                            0xE748CC
#define pinstCQuantityWnd_x                                        0xE748D0
#define pinstCLootWnd_x                                            0xE748D4
#define pinstCActionsWnd_x                                         0xE748D8
#define pinstCCombatAbilityWnd_x                                   0xE748E0
#define pinstCMerchantWnd_x                                        0xE748E4
#define pinstCTradeWnd_x                                           0xE748EC
#define pinstCSelectorWnd_x                                        0xE748F0
#define pinstCBazaarWnd_x                                          0xE748F4
#define pinstCBazaarSearchWnd_x                                    0xE748F8
#define pinstCGiveWnd_x                                            0xE74918
#define pinstCTrackingWnd_x                                        0xE74920
#define pinstCInspectWnd_x                                         0xE74924
#define pinstCSocialEditWnd_x                                      0xE74928
#define pinstCFeedbackWnd_x                                        0xE7492C
#define pinstCBugReportWnd_x                                       0xE74930
#define pinstCVideoModesWnd_x                                      0xE74934
#define pinstCTextEntryWnd_x                                       0xE7493C
#define pinstCFileSelectionWnd_x                                   0xE74940
#define pinstCCompassWnd_x                                         0xE74944
#define pinstCPlayerNotesWnd_x                                     0xE74948
#define pinstCGemsGameWnd_x                                        0xE7494C
#define pinstCTimeLeftWnd_x                                        0xE74968
#define pinstCPetitionQWnd_x                                       0xE7496C
#define pinstCStoryWnd_x                                           0xE74970
#define pinstCJournalTextWnd_x                                     0xE74974
#define pinstCJournalCatWnd_x                                      0xE74978
#define pinstCBodyTintWnd_x                                        0xE7497C
#define pinstCServerListWnd_x                                      0xE74980
#define pinstCAvaZoneWnd_x                                         0xE7498C
#define pinstCBlockedBuffWnd_x                                     0xE74990
#define pinstCBlockedPetBuffWnd_x                                  0xE74994
#define pinstCInvSlotMgr_x                                         0xE749DC
#define pinstCContainerMgr_x                                       0xE749E0
#define pinstCAdventureLeaderboardWnd_x                            0x10C7EB0
#define pinstCAdventureRequestWnd_x                                0x10C7F28
#define pinstCAltStorageWnd_x                                      0x10C8208
#define pinstCAdventureStatsWnd_x                                  0x10C7FA0
#define pinstCBarterMerchantWnd_x                                  0x10C8F50
#define pinstCBarterSearchWnd_x                                    0x10C8FC8
#define pinstCBarterWnd_x                                          0x10C9040
#define pinstCChatWindowManager_x                                  0x10C9850
#define pinstCDynamicZoneWnd_x                                     0x10C9D80
#define pinstCEQMainWnd_x                                          0x10C9F48
#define pinstCFellowshipWnd_x                                      0x10C9D14
#define pinstCFindLocationWnd_x                                    0x10CA218
#define pinstCGroupSearchWnd_x                                     0x10CA4E8
#define pinstCGroupWnd_x                                           0x10CA560
#define pinstCGuildBankWnd_x                                       0x10CA5D8
#define pinstCGuildMgmtWnd_x                                       0x10CC6C8
#define pinstCHotButtonWnd_x                                       0x10CC7C4
#define pinstCHotButtonWnd1_x                                      0x10CC7C4
#define pinstCHotButtonWnd2_x                                      0x10CC7C8
#define pinstCHotButtonWnd3_x                                      0x10CC7CC
#define pinstCHotButtonWnd4_x                                      0x10CC7F0
#define pinstCItemDisplayManager_x                                 0x10CCC48
#define pinstCItemExpTransferWnd_x                                 0x10CCD44
#define pinstCLFGuildWnd_x                                         0x10CD020
#define pinstCMIZoneSelectWnd_x                                    0x10CD600
#define pinstCConfirmationDialog_x                                 0x10CDD08
#define pinstCPopupWndManager_x                                    0x10CDD08
#define pinstCProgressionSelectionWnd_x                            0x10CDDF8
#define pinstCPvPStatsWnd_x                                        0x10CDEE8
#define pinstCLargeDialogWnd_x                                     0x10CE670
#define pinstCTaskWnd_x                                            0x10CF9F0
#define pinstCTaskSomething_x                                      0xD42A38
#define pinstCTaskTemplateSelectWnd_x                              0x10CF978
#define pinstCTipWndOFDAY_x                                        0x10CFB58
#define pinstCTipWndCONTEXT_x                                      0x10CFB5C
#define pinstCTitleWnd_x                                           0x10CFBD8
#define pinstCContextMenuManager_x                                 0x17336F0
#define pinstCVoiceMacroWnd_x                                      0xFBC038
#define pinstCHtmlWnd_x                                            0xFBC128
#define pinstIconCache_x                                           0x10C9EF0
#define pinstCTradeskillWnd_x                                      0x10CFCD8
#define pinstCAdvancedLootWnd_x                                    0xE749D0
#define pinstRewardSelectionWnd_x                                  0x10CE410
#define pinstEQSuiteTextureLoader_x                                0xD1FC18
#define pinstCPointMerchantWnd_x                                   0x10CDC90

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54A460
#define __CastRay2_x                                               0x549D90
#define __HeadingDiff_x                                            0x933410
#define __FixHeading_x                                             0x9333A0
#define __get_bearing_x                                            0x539E70
#define __ConvertItemTags_x                                        0x537AF0
#define __ExecuteCmd_x                                             0x5223B0
#define __EQGetTime_x                                              0x8A29A0
#define __get_melee_range_x                                        0x529070
#define __GetGaugeValueFromEQ_x                                    0x7B2600
#define __GetLabelFromEQ_x                                         0x7B39D0
#define __ToggleKeyRingItem_x                                      0x490680
#define __GetXTargetType_x                                         0x935010
#define __LoadFrontEnd_x                                           0x640580
#define __NewUIINI_x                                               0x7B1FD0
#define __ProcessGameEvents_x                                      0x5841E0
#define __ProcessMouseEvent_x                                      0x583980
#define CrashDetected_x                                            0x641F40
#define wwsCrashReportCheckForUploader_x                           0x800610
#define __AppCrashWrapper_x                                        0xC6B8CC
#define __pCrashHandler_x                                          0x10DCBB8
#define __CrashHandler_x                                           0x8000A0
#define wwsCrashReportPlatformLaunchUploader_x                     0x802850
#define DrawNetStatus_x                                            0x5BAB80
#define Util__FastTime_x                                           0x8A2640
#define Expansion_HoT_x                                            0xF36810
#define __HelpPath_x                                               0xFB9FB8
#define __STMLToText_x                                             0x8E8E20

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4233F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DFF0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DDC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8BA0
#define AltAdvManager__IsAbilityReady_x                            0x4D8C10
#define AltAdvManager__GetAAById_x                                 0x4D9100
#define AltAdvManager__CanTrainAbility_x                           0x4D9D30
#define AltAdvManager__CanSeeAbility_x                             0x4D98F0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46A850
#define CharacterZoneClient__HasSkill_x                            0x466120
#define CharacterZoneClient__MakeMeVisible_x                       0x46C3C0
#define CharacterZoneClient__IsStackBlocked_x                      0x44C020
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B4E0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464680
#define CharacterZoneClient__GetItemCountInInventory_x             0x464760
#define CharacterZoneClient__GetCursorItemCount_x                  0x464840
#define CharacterZoneClient__FindAffectSlot_x                      0x451560
#define CharacterZoneClient__BardCastBard_x                        0x44AC60
#define CharacterZoneClient__GetMaxEffects_x                       0x4499A0
#define CharacterZoneClient__GetEffect_x                           0x44B710
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4513C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449B40
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FF10

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66FB40

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67D750

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x599A60
#define CButtonWnd__CButtonWnd_x                                   0x8DD0A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6989F0
#define CChatManager__InitContextMenu_x                            0x699B40
#define CChatManager__FreeChatWindow_x                             0x6984A0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A1C70
#define CChatManager__SetLockedActiveChatWindow_x                  0x6989C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E7170
#define CContextMenu__dCContextMenu_x                              0x8E7380
#define CContextMenu__AddMenuItem_x                                0x8E78A0
#define CContextMenu__RemoveMenuItem_x                             0x8E7500
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7520
#define CContextMenu__CheckMenuItem_x                              0x8E75A0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D3670
#define CContextMenuManager__RemoveMenu_x                          0x8D3A10
#define CContextMenuManager__PopupMenu_x                           0x8D3E60
#define CContextMenuManager__Flush_x                               0x8D36E0
#define CContextMenuManager__GetMenu_x                             0x419630

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886C30
#define CChatService__GetFriendName_x                              0x886C40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69F7B0
#define CChatWindow__Clear_x                                       0x69F090
#define CChatWindow__WndNotification_x                             0x6A00C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D74D0
#define CComboWnd__Draw_x                                          0x8D76E0
#define CComboWnd__GetCurChoice_x                                  0x8D7280
#define CComboWnd__GetListRect_x                                   0x8D7980
#define CComboWnd__GetTextRect_x                                   0x8D7540
#define CComboWnd__InsertChoice_x                                  0x8D7AE0
#define CComboWnd__SetColors_x                                     0x8D7210
#define CComboWnd__SetChoice_x                                     0x8D7240
#define CComboWnd__GetItemCount_x                                  0x8D7270
#define CComboWnd__GetCurChoiceText_x                              0x8D72C0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A9960
#define CContainerWnd__vftable_x                                   0xAEEC20

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C6920
#define CDisplay__GetClickedActor_x                                0x4BF1E0
#define CDisplay__GetUserDefinedColor_x                            0x4BDDC0
#define CDisplay__GetWorldFilePath_x                               0x4BD210
#define CDisplay__is3dON_x                                         0x4BC6A0
#define CDisplay__ReloadUI_x                                       0x4D0900
#define CDisplay__WriteTextHD2_x                                   0x4C2CB0
#define CDisplay__TrueDistance_x                                   0x4BFE10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FE540

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB6D0
#define CEditWnd__GetCharIndexPt_x                                 0x8EC770
#define CEditWnd__GetDisplayString_x                               0x8EB880
#define CEditWnd__GetHorzOffset_x                                  0x8EBBC0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC230
#define CEditWnd__GetSelStartPt_x                                  0x8ECA30
#define CEditWnd__GetSTMLSafeText_x                                0x8EBD60
#define CEditWnd__PointFromPrintableChar_x                         0x8EC320
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC4A0
#define CEditWnd__SetEditable_x                                    0x8EBD30

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A7D0
#define CEverQuest__ClickedPlayer_x                                0x564350
#define CEverQuest__CreateTargetIndicator_x                        0x565250
#define CEverQuest__DeleteTargetIndicator_x                        0x5652D0
#define CEverQuest__DoTellWindow_x                                 0x476F70
#define CEverQuest__OutputTextToLog_x                              0x476BD0
#define CEverQuest__DropHeldItemOnGround_x                         0x57AD40
#define CEverQuest__dsp_chat_x                                     0x4772B0
#define CEverQuest__trimName_x                                     0x560C60
#define CEverQuest__Emote_x                                        0x579050
#define CEverQuest__EnterZone_x                                    0x574130
#define CEverQuest__GetBodyTypeDesc_x                              0x55E6A0
#define CEverQuest__GetClassDesc_x                                 0x567BF0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5681F0
#define CEverQuest__GetDeityDesc_x                                 0x55EF80
#define CEverQuest__GetLangDesc_x                                  0x55EA30
#define CEverQuest__GetRaceDesc_x                                  0x5683B0
#define CEverQuest__InterpretCmd_x                                 0x56BF50
#define CEverQuest__LeftClickedOnPlayer_x                          0x580890
#define CEverQuest__LMouseUp_x                                     0x5829A0
#define CEverQuest__RightClickedOnPlayer_x                         0x5813A0
#define CEverQuest__RMouseUp_x                                     0x582400
#define CEverQuest__SetGameState_x                                 0x564C20
#define CEverQuest__UPCNotificationFlush_x                         0x55D030
#define CEverQuest__IssuePetCommand_x                              0x56C930

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BA5A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BA600
#define CGaugeWnd__Draw_x                                          0x6BAA30

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B750
#define CGuild__GetGuildName_x                                     0x43BC20
#define CGuild__GetGuildIndex_x                                    0x43CE30

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D6A60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E3EA0
#define CInvSlotMgr__MoveItem_x                                    0x6E4660
#define CInvSlotMgr__SelectSlot_x                                  0x6E3790

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E2BF0
#define CInvSlot__SliderComplete_x                                 0x6E0370
#define CInvSlot__GetItemBase_x                                    0x6DF810
#define CInvSlot__UpdateItem_x                                     0x6DFD90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E5A90
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E6BC0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AE000
#define CItemDisplayWnd__UpdateStrings_x                           0x6E7CC0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F47A0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F4CA0
#define CItemDisplayWnd__SetItem_x                                 0x6FA4B0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E5390

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EE2D0

// CLabel 
#define CLabel__Draw_x                                             0x701230

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C3070
#define CListWnd__dCListWnd_x                                      0x8C4320
#define CListWnd__AddColumn_x                                      0x8C42C0
#define CListWnd__AddColumn1_x                                     0x8C3960
#define CListWnd__AddLine_x                                        0x8C3340
#define CListWnd__AddString_x                                      0x8C3560
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C0170
#define CListWnd__CalculateVSBRange_x                              0x8C2530
#define CListWnd__ClearSel_x                                       0x8BF490
#define CListWnd__ClearAllSel_x                                    0x8BF440
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2F00
#define CListWnd__Compare_x                                        0x8C0E70
#define CListWnd__Draw_x                                           0x8C2130
#define CListWnd__DrawColumnSeparators_x                           0x8C1FC0
#define CListWnd__DrawHeader_x                                     0x8BF750
#define CListWnd__DrawItem_x                                       0x8C14F0
#define CListWnd__DrawLine_x                                       0x8C1C60
#define CListWnd__DrawSeparator_x                                  0x8C2060
#define CListWnd__EnableLine_x                                     0x8BF670
#define CListWnd__EnsureVisible_x                                  0x8C02D0
#define CListWnd__ExtendSel_x                                      0x8C1400
#define CListWnd__GetColumnMinWidth_x                              0x8BED80
#define CListWnd__GetColumnWidth_x                                 0x8BECB0
#define CListWnd__GetCurSel_x                                      0x8BE480
#define CListWnd__GetItemAtPoint_x                                 0x8C0570
#define CListWnd__GetItemAtPoint1_x                                0x8C05E0
#define CListWnd__GetItemData_x                                    0x8BE7C0
#define CListWnd__GetItemHeight_x                                  0x8BFDD0
#define CListWnd__GetItemIcon_x                                    0x8BE9B0
#define CListWnd__GetItemRect_x                                    0x8C03B0
#define CListWnd__GetItemText_x                                    0x8BE860
#define CListWnd__GetSelList_x                                     0x8C3850
#define CListWnd__GetSeparatorRect_x                               0x8C0D90
#define CListWnd__InsertLine_x                                     0x8C3740
#define CListWnd__RemoveLine_x                                     0x8C3750
#define CListWnd__SetColors_x                                      0x8BE5D0
#define CListWnd__SetColumnJustification_x                         0x8BF010
#define CListWnd__SetColumnWidth_x                                 0x8BED30
#define CListWnd__SetCurSel_x                                      0x8BE4C0
#define CListWnd__SetItemColor_x                                   0x8C2BF0
#define CListWnd__SetItemData_x                                    0x8BF4F0
#define CListWnd__SetItemText_x                                    0x8C2A30
#define CListWnd__ShiftColumnSeparator_x                           0x8C28C0
#define CListWnd__Sort_x                                           0x8C4420
#define CListWnd__ToggleSel_x                                      0x8BF3C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71A3A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73B7F0
#define CMerchantWnd__RequestBuyItem_x                             0x7428E0
#define CMerchantWnd__RequestSellItem_x                            0x7433B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x73BAA0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73ACA0
#define CMerchantWnd__ActualSelect_x                               0x73F790

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x854F60
#define CPacketScrambler__hton_x                                   0x854F70

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E2090
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E2170
#define CSidlManager__CreateLabel_x                                0x7A41E0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E0640
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E2450

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D9520
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D9410
#define CSidlScreenWnd__ConvertToRes_x                             0x8FE420
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9E30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DAFE0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DB090
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA560
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D97E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8F40
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D99D0
#define CSidlScreenWnd__Init1_x                                    0x8DACB0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9EF0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D9100
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA7A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D8BA0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8EF0
#define CSidlScreenWnd__WndNotification_x                          0x8DAA30
#define CSidlScreenWnd__GetChildItem_x                             0x8D9010
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC920
#define CSidlScreenWnd__m_layoutCopy_x                             0x1733810

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x605F00
#define CSkillMgr__GetSkillCap_x                                   0x6060E0
#define CSkillMgr__GetNameToken_x                                  0x605AB0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FD6C0
#define CSliderWnd__SetValue_x                                     0x8FD890
#define CSliderWnd__SetNumTicks_x                                  0x8FE010

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7AA510

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6F90
#define CStmlWnd__CalculateHSBRange_x                              0x8EF4E0
#define CStmlWnd__CalculateVSBRange_x                              0x8EF450
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF660
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EFE60
#define CStmlWnd__ForceParseNow_x                                  0x8F7910
#define CStmlWnd__GetNextTagPiece_x                                0x8EFD60
#define CStmlWnd__GetSTMLText_x                                    0x4851A0
#define CStmlWnd__GetVisibleText_x                                 0x8F08B0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2E80
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE730
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE790
#define CStmlWnd__SetSTMLText_x                                    0x8F46D0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6C30
#define CStmlWnd__UpdateHistoryString_x                            0x8F17F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FAE80
#define CTabWnd__DrawCurrentPage_x                                 0x8FA710
#define CTabWnd__DrawTab_x                                         0x8FA4D0
#define CTabWnd__GetCurrentPage_x                                  0x8FAAC0
#define CTabWnd__GetPageInnerRect_x                                0x8FA1C0
#define CTabWnd__GetTabInnerRect_x                                 0x8FA3C0
#define CTabWnd__GetTabRect_x                                      0x8FA290
#define CTabWnd__InsertPage_x                                      0x8FB170
#define CTabWnd__SetPage_x                                         0x8FAAF0
#define CTabWnd__SetPageRect_x                                     0x8FADC0
#define CTabWnd__UpdatePage_x                                      0x8FB110
#define CTabWnd__GetPageFromTabIndex_x                             0x8FA420
#define CTabWnd__GetCurrentTabIndex_x                              0x8FA150

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E6D70
#define CPageWnd__SetTabText_x                                     0x907780

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4372F0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6E80
#define CTextureFont__GetTextExtent_x                              0x8D6BE0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63E7E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903BC0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC5E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A7320
#define CXStr__CXStr1_x                                            0x74E050
#define CXStr__CXStr3_x                                            0x89F8D0
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x89FA40
#define CXStr__operator_equal1_x                                   0x89FA90
#define CXStr__operator_plus_equal1_x                              0x8A0B90

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8CBB10
#define CXWnd__Center_x                                            0x8D1C50
#define CXWnd__ClrFocus_x                                          0x8CB6F0
#define CXWnd__Destroy_x                                           0x8D2740
#define CXWnd__DoAllDrawing_x                                      0x8D18A0
#define CXWnd__DrawChildren_x                                      0x8D1A40
#define CXWnd__DrawColoredRect_x                                   0x8CBEF0
#define CXWnd__DrawTooltip_x                                       0x8CC1A0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D0820
#define CXWnd__GetBorderFrame_x                                    0x8CC600
#define CXWnd__GetChildWndAt_x                                     0x8D2620
#define CXWnd__GetClientClipRect_x                                 0x8CC3B0
#define CXWnd__GetScreenClipRect_x                                 0x8D0F20
#define CXWnd__GetScreenRect_x                                     0x8CC7C0
#define CXWnd__GetTooltipRect_x                                    0x8CC030
#define CXWnd__GetWindowTextA_x                                    0x4274F0
#define CXWnd__IsActive_x                                          0x8C70F0
#define CXWnd__IsDescendantOf_x                                    0x8CC540
#define CXWnd__IsReallyVisible_x                                   0x8CF850
#define CXWnd__IsType_x                                            0x8D1CC0
#define CScreenPieceTemplate__IsType_x                             0x900310
#define CXWnd__Move_x                                              0x8CEFC0
#define CXWnd__Move1_x                                             0x8D1570
#define CXWnd__ProcessTransition_x                                 0x8CBAC0
#define CXWnd__Refade_x                                            0x8CB890
#define CXWnd__Resize_x                                            0x8CC880
#define CXWnd__Right_x                                             0x8D0D20
#define CXWnd__SetFocus_x                                          0x8CE110
#define CXWnd__SetFont_x                                           0x8CB740
#define CXWnd__SetKeyTooltip_x                                     0x8CCAF0
#define CXWnd__SetMouseOver_x                                      0x8D1260
#define CXWnd__StartFade_x                                         0x8CBB60
#define CXWnd__GetChildItem_x                                      0x8D11A0
#define CXWnd__SetParent_x                                         0x8D25D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C8990
#define CXWndManager__DrawWindows_x                                0x8C85D0
#define CXWndManager__GetKeyboardFlags_x                           0x8C6C30
#define CXWndManager__HandleKeyboardMsg_x                          0x8C7580
#define CXWndManager__RemoveWnd_x                                  0x8C7280

// CDBStr
#define CDBStr__GetString_x                                        0x4BAEF0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452560
#define EQ_Character__Cur_HP_x                                     0x465D00
#define EQ_Character__Cur_Mana_x                                   0x45AC20
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B7F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443A40
#define EQ_Character__GetFocusRangeModifier_x                      0x443AA0
#define EQ_Character__GetHPRegen_x                                 0x469EE0
#define EQ_Character__GetEnduranceRegen_x                          0x465310
#define EQ_Character__GetManaRegen_x                               0x46A480
#define EQ_Character__Max_Endurance_x                              0x5CC730
#define EQ_Character__Max_HP_x                                     0x45D7A0
#define EQ_Character__Max_Mana_x                                   0x5CC560
#define EQ_Character__doCombatAbility_x                            0x5C9C30
#define EQ_Character__UseSkill_x                                   0x471450
#define EQ_Character__GetConLevel_x                                0x5BF210
#define EQ_Character__IsExpansionFlag_x                            0x426A30
#define EQ_Character__TotalEffect_x                                0x44F890
#define EQ_Character__GetPCSpellAffect_x                           0x44BBF0
#define EQ_Character__SpellDuration_x                              0x449B90
#define EQ_Character__FindItemByRecord_x                           0x463350
#define EQ_Character__GetAdjustedSkill_x                           0x465ED0
#define EQ_Character__GetBaseSkill_x                               0x45D680

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872D70

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D4CE0

//PcClient
#define PcClient__PcClient_x                                       0x5C1040

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446DF0
#define CCharacterSelect__EnterWorld_x                             0x4465C0
#define CCharacterSelect__Quit_x                                   0x445180

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59F4F0
#define EQ_Item__CreateItemTagString_x                             0x853100
#define EQ_Item__IsStackable_x                                     0x8483B0
#define EQ_Item__GetImageNum_x                                     0x84AF10
#define EQ_Item__CreateItemClient_x                                0x5A00E0
#define EQ_Item__GetItemValue_x                                    0x851B60
#define EQ_Item__ValueSellMerchant_x                               0x854BB0
#define EQ_Item__IsKeyRingItem_x                                   0x848F10
#define EQ_Item__CanGoInBag_x                                      0x59F680
#define EQ_Item__GetMaxItemCount_x                                 0x8482A0
#define EQ_Item__GetHeldItem_x                                     0x849D20
#define EQ_Item__GetAugmentFitBySlot_x                             0x8549E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DB1B0
#define EQ_LoadingS__Array_x                                       0xC0D738

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CEC50
#define EQ_PC__GetAlternateAbilityId_x                             0x85CFB0
#define EQ_PC__GetCombatAbility_x                                  0x85D040
#define EQ_PC__GetCombatAbilityTimer_x                             0x857C10
#define EQ_PC__GetItemRecastTimer_x                                0x5C83E0
#define EQ_PC__HasLoreItem_x                                       0x5C2800
#define EQ_PC__AlertInventoryChanged_x                             0x5BF1C0
#define EQ_PC__GetPcZoneClient_x                                   0x5E9190
#define EQ_PC__RemoveMyAffect_x                                    0x5C7840
#define EQ_PC__GetKeyRingItems_x                                   0x858030
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86ACE0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85EF50

// EQItemList 
#define EQItemList__EQItemList_x                                   0x527100
#define EQItemList__add_object_x                                   0x553FA0
#define EQItemList__add_item_x                                     0x527040
#define EQItemList__delete_item_x                                  0x5274F0
#define EQItemList__FreeItemList_x                                 0x5273F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4BA0D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D4A80
#define EQPlayer__dEQPlayer_x                                      0x5DD0C0
#define EQPlayer__DoAttack_x                                       0x5EEB20
#define EQPlayer__EQPlayer_x                                       0x5DF7E0
#define EQPlayer__SetNameSpriteState_x                             0x5D9F80
#define EQPlayer__SetNameSpriteTint_x                              0x5D5EA0
#define PlayerBase__HasProperty_j_x                                0x9317B0
#define EQPlayer__IsTargetable_x                                   0x931A50
#define EQPlayer__CanSee_x                                         0x931FB0
#define PlayerZoneClient__ChangeHeight_x                           0x5EE9E0
#define EQPlayer__CanSee1_x                                        0x9320A0
#define PlayerBase__GetVisibilityLineSegment_x                     0x931D40

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E9340
#define PlayerZoneClient__IsValidTeleport_x                        0x554840
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D3500

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E37D0
#define EQPlayerManager__GetSpawnByName_x                          0x5E3C30
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E3800

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A56B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A56F0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A52A0
#define KeypressHandler__HandleKeyDown_x                           0x5A3BF0
#define KeypressHandler__HandleKeyUp_x                             0x5A3F10
#define KeypressHandler__SaveKeymapping_x                          0x5A5370

// MapViewMap 
#define MapViewMap__Clear_x                                        0x712D30
#define MapViewMap__SaveEx_x                                       0x716060

#define PlayerPointManager__GetAltCurrency_x                       0x870E30

// StringTable 
#define StringTable__getString_x                                   0x86B010

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CC1C0
#define PcZoneClient__RemovePetEffect_x                            0x5C88B0
#define PcZoneClient__HasAlternateAbility_x                        0x5C9250
#define PcZoneClient__GetCurrentMod_x                              0x45CC50
#define PcZoneClient__GetModCap_x                                  0x45A380
#define PcZoneClient__CanEquipItem_x                               0x5C9770
#define PcZoneClient__GetItemByID_x                                0x5CDFC0
#define PcZoneClient__GetItemByItemClass_x                         0x5CEB70

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B970

//IconCache
#define IconCache__GetIcon_x                                       0x6AFDF0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A6CF0
#define CContainerMgr__CloseContainer_x                            0x6A7510

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x773FF0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x598480

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5700
#define EQ_Spell__SpellAffects_x                                   0x4F2920
#define EQ_Spell__SpellAffectBase_x                                0x4F2990
#define CharacterZoneClient__CalcAffectChange_x                    0x44BA80
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ACC0
#define CLootWnd__LootAll_x                                        0x708640
#define CLootWnd__RequestLootSlot_x                                0x708E50
#define EQ_Spell__IsStackable_x                                    0x449740
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4497F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F240
#define EQ_Spell__IsSPAStacking_x                                  0x4F2490
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3500
#define EQ_Spell__IsNoRemove_x                                     0x435320
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F24B0

#define __IsResEffectSpell_x                                       0x449890

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87C9F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BAFF0
#define CTargetWnd__WndNotification_x                              0x7BAAE0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BB1D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C0120

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EDFF0
#define EqSoundManager__PlayScriptMp3_x                            0x4EFA90

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A9220

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EAD00
#define CSidlManager__FindAnimation1_x                             0x8E0070

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2AB0
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2A60
#define CAltAbilityData__GetMaxRank_x                              0x4D7250

//CTargetRing
#define CTargetRing__Cast_x                                        0x595D40

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459350
#define CharacterBase__CreateItemGlobalIndex_x                     0x476170
#define CharacterBase__CreateItemIndex_x                           0x520710
#define CharacterBase__GetItemPossession_x                         0x444620
#define CharacterBase__GetItemByGlobalIndex_x                      0x880840
#define CharacterBase__GetEffectId_x                               0x459310

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68FC20
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68F380

//messages
#define msg_spell_worn_off_x                                       0x4FD220
#define msg_new_text_x                                             0x5068E0
#define msgTokenTextParam_x                                        0x5030C0

//SpellManager
#define SpellManager__vftable_x                                    0xACA3F8
#define SpellManager__SpellManager_x                               0x47EDC0
#define Spellmanager__LoadTextSpells_x          0x60CD90

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935B30

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488780
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43F170
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4494E0
#define ItemGlobalIndex__IsValidIndex_x                            0x458BF0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87E6B0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87D5F0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x701480

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6ABA20
#define CCursorAttachment__Deactivate_x                            0x6AAF70

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FCBC0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48CF60
