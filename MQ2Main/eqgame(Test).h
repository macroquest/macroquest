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
#define __ExpectedVersionDate                                     "Sep 11 2017"
#define __ExpectedVersionTime                                     "20:12:37"
#define __ActualVersionDate_x                                      0xAE4330
#define __ActualVersionTime_x                                      0xAE433C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5AA570
#define __MemChecker1_x                                            0x8A20C0
#define __MemChecker2_x                                            0x640770
#define __MemChecker3_x                                            0x6406C0
#define __MemChecker4_x                                            0x7F4050
#define __EncryptPad0_x                                            0xC41298
#define __EncryptPad1_x                                            0xD1CD50
#define __EncryptPad2_x                                            0xC6ACD8
#define __EncryptPad3_x                                            0xC6A8D8
#define __EncryptPad4_x                                            0xD0B350
#define __EncryptPad5_x                                            0x10C63A8
#define __AC1_x                                                    0x7B3035
#define __AC2_x                                                    0x5633B7
#define __AC3_x                                                    0x561530
#define __AC4_x                                                    0x573751
#define __AC5_x                                                    0x5875FB
#define __AC6_x                                                    0x58B19E
#define __AC7_x                                                    0x581BFC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FACF90

// Direct Input
#define DI8__Main_x                                                0x10C6380
#define DI8__Keyboard_x                                            0x10C6384
#define DI8__Mouse_x                                               0x10C6388
#define DI8__Mouse_Copy_x                                          0xF344AC
#define DI8__Mouse_Check_x                                         0xFBE06C
#define __AutoSkillArray_x                                         0xF353C0
#define __Attack_x                                                 0xFB89C3
#define __Autofire_x                                               0xFB89C4
#define __BindList_x                                               0xC1BDB0
#define g_eqCommandStates_x                                        0xF233D0
#define __Clicks_x                                                 0xF34568
#define __CommandList_x                                            0xC1E4B0
#define __CurrentMapLabel_x                                        0x10CC378
#define __CurrentSocial_x                                          0xBEB4E0
#define __DoAbilityList_x                                          0xF6AC78
#define __do_loot_x                                                0x5326A0
#define __DrawHandler_x                                            0x17338FC
#define __GroupCount_x                                             0xF24B02

#define __Guilds_x                                                 0xF2A718
#define __gWorld_x                                                 0xF26FBC
#define __HotkeyPage_x                                             0xFB1678
#define __HWnd_x                                                   0xFBE188
#define __InChatMode_x                                             0xF34494
#define __LastTell_x                                               0xF36374
#define __LMouseHeldTime_x                                         0xF345D4
#define __Mouse_x                                                  0x10C638C
#define __MouseLook_x                                              0xF3452E
#define __MouseEventTime_x                                         0xFB924C
#define __gpbCommandEvent_x                                        0xF27084
#define __NetStatusToggle_x                                        0xF34531
#define __PCNames_x                                                0xF35984
#define __RangeAttackReady_x                                       0xF356A4
#define __RMouseHeldTime_x                                         0xF345D0
#define __RunWalkState_x                                           0xF34498
#define __ScreenMode_x                                             0xE72FB0
#define __ScreenX_x                                                0xF3444C
#define __ScreenY_x                                                0xF34448
#define __ScreenXMax_x                                             0xF34450
#define __ScreenYMax_x                                             0xF34454
#define __ServerHost_x                                             0xF24A4C
#define __ServerName_x                                             0xF6AC38
#define __ShiftKeyDown_x                                           0xF34B28
#define __ShowNames_x                                              0xF35864
#define __Socials_x                                                0xF6AD38
#define __SubscriptionType_x                                       0x10FA404
#define __TargetAggroHolder_x                                      0x10CE5C4
#define __ZoneType_x                                               0xF3492C
#define __GroupAggro_x                                             0x10CE604
#define __LoginName_x                                              0xFBCC64
#define __Inviter_x                                                0xFB8940
#define __AttackOnAssist_x                                         0xF35820
#define __UseTellWindows_x                                         0xF35B1C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF270A8
#define instEQZoneInfo_x                                           0xF34724
#define instKeypressHandler_x                                      0xFB9230
#define pinstActiveBanker_x                                        0xF27060
#define pinstActiveCorpse_x                                        0xF27064
#define pinstActiveGMaster_x                                       0xF27068
#define pinstActiveMerchant_x                                      0xF2705C
#define pinstAggroInfo_x                                           0xD30608
#define pinstAltAdvManager_x                                       0xE74118
#define pinstAuraMgr_x                                             0xD40E20
#define pinstBandageTarget_x                                       0xF27048
#define pinstCamActor_x                                            0xE739E8
#define pinstCDBStr_x                                              0xE72F44
#define pinstCDisplay_x                                            0xF27070
#define pinstCEverQuest_x                                          0x10C6500
#define pinstEverQuestInfo_x                                       0xF34440
#define pinstCharData_x                                            0xF2702C
#define pinstCharSpawn_x                                           0xF27054
#define pinstControlledMissile_x                                   0xF27028
#define pinstControlledPlayer_x                                    0xF27054
#define pinstCSidlManager_x                                        0x1732868
#define pinstCXWndManager_x                                        0x1732860
#define instDynamicZone_x                                          0xF342E0
#define pinstDZMember_x                                            0xF343F0
#define pinstDZTimerInfo_x                                         0xF343F4
#define pinstEQItemList_x                                          0xF236A8
#define pinstEQObjectList_x                                        0xF244FC
#define instEQMisc_x                                               0xC042B8
#define pinstEQSoundManager_x                                      0xE746E8
#define instExpeditionLeader_x                                     0xF3432A
#define instExpeditionName_x                                       0xF3436A
#define pinstGroup_x                                               0xF24AFE
#define pinstImeManager_x                                          0x173286C
#define pinstLocalPlayer_x                                         0xF27040
#define pinstMercenaryData_x                                       0xFB98B0
#define pinstMercenaryStats_x                                      0x10CE710
#define pinstMercAltAbilities_x                                    0xE744A0
#define pinstModelPlayer_x                                         0xF2706C
#define pinstPCData_x                                              0xF2702C
#define pinstSkillMgr_x                                            0xFBA920
#define pinstSpawnManager_x                                        0xFBA100
#define pinstSpellManager_x                                        0xFBAA68
#define pinstSpellSets_x                                           0xFB16DC
#define pinstStringTable_x                                         0xF26FD4
#define pinstSwitchManager_x                                       0xF24690
#define pinstTarget_x                                              0xF27058
#define pinstTargetObject_x                                        0xF27030
#define pinstTargetSwitch_x                                        0xF27034
#define pinstTaskMember_x                                          0xE72E90
#define pinstTrackTarget_x                                         0xF2704C
#define pinstTradeTarget_x                                         0xF2703C
#define instTributeActive_x                                        0xC042DD
#define pinstViewActor_x                                           0xE739E4
#define pinstWorldData_x                                           0xF27010
#define pinstZoneAddr_x                                            0xF349C4
#define pinstPlayerPath_x                                          0xFBA160
#define pinstTargetIndicator_x                                     0xFBAC00
#define pinstCTargetManager_x                                      0xFBAC60
#define EQObject_Top_x                                             0xF27020
#define pinstRealEstateItems_x                                     0xFBA78C

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE73900
#define pinstCAchievementsWnd_x                                    0xE7395C
#define pinstCTextOverlay_x                                        0xD30BB0
#define pinstCAudioTriggersWindow_x                                0xD30998
#define pinstCCharacterSelect_x                                    0xE7386C
#define pinstCFacePick_x                                           0xE7361C
#define pinstCFindItemWnd_x                                        0xE738FC
#define pinstCNoteWnd_x                                            0xE73824
#define pinstCBookWnd_x                                            0xE7382C
#define pinstCPetInfoWnd_x                                         0xE73830
#define pinstCTrainWnd_x                                           0xE73834
#define pinstCSkillsWnd_x                                          0xE73838
#define pinstCSkillsSelectWnd_x                                    0xE7383C
#define pinstCCombatSkillsSelectWnd_x                              0xE73840
#define pinstCFriendsWnd_x                                         0xE73844
#define pinstCAuraWnd_x                                            0xE73848
#define pinstCRespawnWnd_x                                         0xE7384C
#define pinstCBandolierWnd_x                                       0xE73850
#define pinstCPotionBeltWnd_x                                      0xE73854
#define pinstCAAWnd_x                                              0xE73858
#define pinstCGroupSearchFiltersWnd_x                              0xE7385C
#define pinstCLoadskinWnd_x                                        0xE73860
#define pinstCAlarmWnd_x                                           0xE73864
#define pinstCMusicPlayerWnd_x                                     0xE73868
#define pinstCMailWnd_x                                            0xE73870
#define pinstCMailCompositionWnd_x                                 0xE73874
#define pinstCMailAddressBookWnd_x                                 0xE73878
#define pinstCRaidWnd_x                                            0xE73880
#define pinstCRaidOptionsWnd_x                                     0xE73884
#define pinstCBreathWnd_x                                          0xE73888
#define pinstCMapViewWnd_x                                         0xE7388C
#define pinstCMapToolbarWnd_x                                      0xE73890
#define pinstCEditLabelWnd_x                                       0xE73894
#define pinstCTargetWnd_x                                          0xE73898
#define pinstCColorPickerWnd_x                                     0xE7389C
#define pinstCPlayerWnd_x                                          0xE738A0
#define pinstCOptionsWnd_x                                         0xE738A4
#define pinstCBuffWindowNORMAL_x                                   0xE738A8
#define pinstCBuffWindowSHORT_x                                    0xE738AC
#define pinstCharacterCreation_x                                   0xE738B0
#define pinstCCursorAttachment_x                                   0xE738B4
#define pinstCCastingWnd_x                                         0xE738B8
#define pinstCCastSpellWnd_x                                       0xE738BC
#define pinstCSpellBookWnd_x                                       0xE738C0
#define pinstCInventoryWnd_x                                       0xE738C4
#define pinstCBankWnd_x                                            0xE738CC
#define pinstCQuantityWnd_x                                        0xE738D0
#define pinstCLootWnd_x                                            0xE738D4
#define pinstCActionsWnd_x                                         0xE738D8
#define pinstCCombatAbilityWnd_x                                   0xE738E0
#define pinstCMerchantWnd_x                                        0xE738E4
#define pinstCTradeWnd_x                                           0xE738EC
#define pinstCSelectorWnd_x                                        0xE738F0
#define pinstCBazaarWnd_x                                          0xE738F4
#define pinstCBazaarSearchWnd_x                                    0xE738F8
#define pinstCGiveWnd_x                                            0xE73918
#define pinstCTrackingWnd_x                                        0xE73920
#define pinstCInspectWnd_x                                         0xE73924
#define pinstCSocialEditWnd_x                                      0xE73928
#define pinstCFeedbackWnd_x                                        0xE7392C
#define pinstCBugReportWnd_x                                       0xE73930
#define pinstCVideoModesWnd_x                                      0xE73934
#define pinstCTextEntryWnd_x                                       0xE7393C
#define pinstCFileSelectionWnd_x                                   0xE73940
#define pinstCCompassWnd_x                                         0xE73944
#define pinstCPlayerNotesWnd_x                                     0xE73948
#define pinstCGemsGameWnd_x                                        0xE7394C
#define pinstCTimeLeftWnd_x                                        0xE73950
#define pinstCPetitionQWnd_x                                       0xE7396C
#define pinstCStoryWnd_x                                           0xE73970
#define pinstCJournalTextWnd_x                                     0xE73974
#define pinstCJournalCatWnd_x                                      0xE73978
#define pinstCBodyTintWnd_x                                        0xE7397C
#define pinstCServerListWnd_x                                      0xE73980
#define pinstCAvaZoneWnd_x                                         0xE7398C
#define pinstCBlockedBuffWnd_x                                     0xE73990
#define pinstCBlockedPetBuffWnd_x                                  0xE73994
#define pinstCInvSlotMgr_x                                         0xE739DC
#define pinstCContainerMgr_x                                       0xE739E0
#define pinstCAdventureLeaderboardWnd_x                            0x10C6EB0
#define pinstCAdventureRequestWnd_x                                0x10C6F28
#define pinstCAltStorageWnd_x                                      0x10C7208
#define pinstCAdventureStatsWnd_x                                  0x10C6FA0
#define pinstCBarterMerchantWnd_x                                  0x10C7F50
#define pinstCBarterSearchWnd_x                                    0x10C7FC8
#define pinstCBarterWnd_x                                          0x10C8040
#define pinstCChatWindowManager_x                                  0x10C8850
#define pinstCDynamicZoneWnd_x                                     0x10C8D80
#define pinstCEQMainWnd_x                                          0x10C8F48
#define pinstCFellowshipWnd_x                                      0x10C8D14
#define pinstCFindLocationWnd_x                                    0x10C9218
#define pinstCGroupSearchWnd_x                                     0x10C94E8
#define pinstCGroupWnd_x                                           0x10C9560
#define pinstCGuildBankWnd_x                                       0x10C95D8
#define pinstCGuildMgmtWnd_x                                       0x10CB6C8
#define pinstCHotButtonWnd_x                                       0x10CB7C4
#define pinstCHotButtonWnd1_x                                      0x10CB7C4
#define pinstCHotButtonWnd2_x                                      0x10CB7C8
#define pinstCHotButtonWnd3_x                                      0x10CB7CC
#define pinstCHotButtonWnd4_x                                      0x10CB7F0
#define pinstCItemDisplayManager_x                                 0x10CBC48
#define pinstCItemExpTransferWnd_x                                 0x10CBD44
#define pinstCLFGuildWnd_x                                         0x10CC020
#define pinstCMIZoneSelectWnd_x                                    0x10CC600
#define pinstCConfirmationDialog_x                                 0x10CCD08
#define pinstCPopupWndManager_x                                    0x10CCD08
#define pinstCProgressionSelectionWnd_x                            0x10CCDF8
#define pinstCPvPStatsWnd_x                                        0x10CCEE8
#define pinstCLargeDialogWnd_x                                     0x10CD670
#define pinstCTaskWnd_x                                            0x10CE9F0
#define pinstCTaskSomething_x                                      0xD41A38
#define pinstCTaskTemplateSelectWnd_x                              0x10CE978
#define pinstCTipWndOFDAY_x                                        0x10CEB58
#define pinstCTipWndCONTEXT_x                                      0x10CEB5C
#define pinstCTitleWnd_x                                           0x10CEBD8
#define pinstCContextMenuManager_x                                 0x17326F0
#define pinstCVoiceMacroWnd_x                                      0xFBB038
#define pinstCHtmlWnd_x                                            0xFBB128
#define pinstIconCache_x                                           0x10C8EF0
#define pinstCTradeskillWnd_x                                      0x10CECD8
#define pinstCAdvancedLootWnd_x                                    0xE739D0
#define pinstRewardSelectionWnd_x                                  0x10CD410
#define pinstEQSuiteTextureLoader_x                                0xD1EC18

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x549C30
#define __CastRay2_x                                               0x549560
#define __HeadingDiff_x                                            0x931C90
#define __FixHeading_x                                             0x931C20
#define __get_bearing_x                                            0x539640
#define __ConvertItemTags_x                                        0x5372C0
#define __ExecuteCmd_x                                             0x521BF0
#define __EQGetTime_x                                              0x8A1A60
#define __get_melee_range_x                                        0x528860
#define __GetGaugeValueFromEQ_x                                    0x7B1BF0
#define __GetLabelFromEQ_x                                         0x7B2FC0
#define __ToggleKeyRingItem_x                                      0x490B50
#define __GetXTargetType_x                                         0x933890
#define __LoadFrontEnd_x                                           0x63FE40
#define __NewUIINI_x                                               0x7B15D0
#define __ProcessGameEvents_x                                      0x583990
#define __ProcessMouseEvent_x                                      0x583130
#define CrashDetected_x                                            0x641800
#define wwsCrashReportCheckForUploader_x                           0x7FFB30
#define __AppCrashWrapper_x                                        0xC6A8CC
#define __pCrashHandler_x                                          0x10DBBB8
#define __CrashHandler_x                                           0x7FF5C0
#define wwsCrashReportPlatformLaunchUploader_x                     0x801D60
#define DrawNetStatus_x                                            0x5BA200
#define Util__FastTime_x                                           0x8A1700
#define Expansion_HoT_x                                            0xF35810
#define __HelpPath_x                                               0xFB8FB8
#define __STMLToText_x                                             0x8E7D50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423380
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DF80
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DD50

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D90D0
#define AltAdvManager__IsAbilityReady_x                            0x4D9140
#define AltAdvManager__GetAAById_x                                 0x4D9630
#define AltAdvManager__CanTrainAbility_x                           0x4DA260
#define AltAdvManager__CanSeeAbility_x                             0x4D9E20

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46A710
#define CharacterZoneClient__HasSkill_x                            0x465FE0
#define CharacterZoneClient__MakeMeVisible_x                       0x46C280
#define CharacterZoneClient__IsStackBlocked_x                      0x44BF00
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B3C0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464540
#define CharacterZoneClient__GetItemCountInInventory_x             0x464620
#define CharacterZoneClient__GetCursorItemCount_x                  0x464700
#define CharacterZoneClient__FindAffectSlot_x                      0x451430
#define CharacterZoneClient__BardCastBard_x                        0x44AB40
#define CharacterZoneClient__GetMaxEffects_x                       0x449880
#define CharacterZoneClient__GetEffect_x                           0x44B5F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451290
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449A20
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FDE0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66F390

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67D360

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x599230
#define CButtonWnd__CButtonWnd_x                                   0x8DBF90

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x698200
#define CChatManager__InitContextMenu_x                            0x699350
#define CChatManager__FreeChatWindow_x                             0x697CB0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A1480
#define CChatManager__SetLockedActiveChatWindow_x                  0x6981D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E60A0
#define CContextMenu__dCContextMenu_x                              0x8E62B0
#define CContextMenu__AddMenuItem_x                                0x8E67D0
#define CContextMenu__RemoveMenuItem_x                             0x8E6430
#define CContextMenu__RemoveAllMenuItems_x                         0x8E6450
#define CContextMenu__CheckMenuItem_x                              0x8E64D0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D2520
#define CContextMenuManager__RemoveMenu_x                          0x8D28D0
#define CContextMenuManager__PopupMenu_x                           0x8D2D20
#define CContextMenuManager__Flush_x                               0x8D2590
#define CContextMenuManager__GetMenu_x                             0x4195C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x885C70
#define CChatService__GetFriendName_x                              0x885C80

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69EFC0
#define CChatWindow__Clear_x                                       0x69E8B0
#define CChatWindow__WndNotification_x                             0x69F8D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D6370
#define CComboWnd__Draw_x                                          0x8D6580
#define CComboWnd__GetCurChoice_x                                  0x8D6120
#define CComboWnd__GetListRect_x                                   0x8D6820
#define CComboWnd__GetTextRect_x                                   0x8D63E0
#define CComboWnd__InsertChoice_x                                  0x8D6980
#define CComboWnd__SetColors_x                                     0x8D60B0
#define CComboWnd__SetChoice_x                                     0x8D60E0
#define CComboWnd__GetItemCount_x                                  0x8D6110
#define CComboWnd__GetCurChoiceText_x                              0x8D6160

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A91D0
#define CContainerWnd__vftable_x                                   0xAEDC30

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C6E50
#define CDisplay__GetClickedActor_x                                0x4BF710
#define CDisplay__GetUserDefinedColor_x                            0x4BE2F0
#define CDisplay__GetWorldFilePath_x                               0x4BD740
#define CDisplay__is3dON_x                                         0x4BCBD0
#define CDisplay__ReloadUI_x                                       0x4D0E30
#define CDisplay__WriteTextHD2_x                                   0x4C31E0
#define CDisplay__TrueDistance_x                                   0x4C0340

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FCEE0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EA600
#define CEditWnd__GetCharIndexPt_x                                 0x8EB6A0
#define CEditWnd__GetDisplayString_x                               0x8EA7B0
#define CEditWnd__GetHorzOffset_x                                  0x8EAAF0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EB160
#define CEditWnd__GetSelStartPt_x                                  0x8EB960
#define CEditWnd__GetSTMLSafeText_x                                0x8EAC90
#define CEditWnd__PointFromPrintableChar_x                         0x8EB250
#define CEditWnd__SelectableCharFromPoint_x                        0x8EB3D0
#define CEditWnd__SetEditable_x                                    0x8EAC60

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x569F80
#define CEverQuest__ClickedPlayer_x                                0x563B00
#define CEverQuest__CreateTargetIndicator_x                        0x564A00
#define CEverQuest__DeleteTargetIndicator_x                        0x564A80
#define CEverQuest__DoTellWindow_x                                 0x476EF0
#define CEverQuest__OutputTextToLog_x                              0x476B50
#define CEverQuest__DropHeldItemOnGround_x                         0x57A4F0
#define CEverQuest__dsp_chat_x                                     0x477230
#define CEverQuest__trimName_x                                     0x560410
#define CEverQuest__Emote_x                                        0x578800
#define CEverQuest__EnterZone_x                                    0x5738E0
#define CEverQuest__GetBodyTypeDesc_x                              0x55DE50
#define CEverQuest__GetClassDesc_x                                 0x5673A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5679A0
#define CEverQuest__GetDeityDesc_x                                 0x55E730
#define CEverQuest__GetLangDesc_x                                  0x55E1E0
#define CEverQuest__GetRaceDesc_x                                  0x567B60
#define CEverQuest__InterpretCmd_x                                 0x56B700
#define CEverQuest__LeftClickedOnPlayer_x                          0x580040
#define CEverQuest__LMouseUp_x                                     0x582150
#define CEverQuest__RightClickedOnPlayer_x                         0x580B50
#define CEverQuest__RMouseUp_x                                     0x581BB0
#define CEverQuest__SetGameState_x                                 0x5643D0
#define CEverQuest__UPCNotificationFlush_x                         0x55C7E0
#define CEverQuest__IssuePetCommand_x                              0x56C0E0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B9DA0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9E00
#define CGaugeWnd__Draw_x                                          0x6BA230

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B6E0
#define CGuild__GetGuildName_x                                     0x43BBB0
#define CGuild__GetGuildIndex_x                                    0x43CDC0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D62A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E36B0
#define CInvSlotMgr__MoveItem_x                                    0x6E3E70
#define CInvSlotMgr__SelectSlot_x                                  0x6E2FB0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E2410
#define CInvSlot__SliderComplete_x                                 0x6DFBA0
#define CInvSlot__GetItemBase_x                                    0x6DF020
#define CInvSlot__UpdateItem_x                                     0x6DF5A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E5290
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E63C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AD610
#define CItemDisplayWnd__UpdateStrings_x                           0x6E74D0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F3F40
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F4460
#define CItemDisplayWnd__SetItem_x                                 0x6F9D70

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E4C00

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EDA90

// CLabel 
#define CLabel__Draw_x                                             0x700A90

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2020
#define CListWnd__dCListWnd_x                                      0x8C32D0
#define CListWnd__AddColumn_x                                      0x8C3270
#define CListWnd__AddColumn1_x                                     0x8C2910
#define CListWnd__AddLine_x                                        0x8C22F0
#define CListWnd__AddString_x                                      0x8C2510
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BF110
#define CListWnd__CalculateVSBRange_x                              0x8C14F0
#define CListWnd__ClearSel_x                                       0x8BE420
#define CListWnd__ClearAllSel_x                                    0x8BE3D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C1EB0
#define CListWnd__Compare_x                                        0x8BFE20
#define CListWnd__Draw_x                                           0x8C10F0
#define CListWnd__DrawColumnSeparators_x                           0x8C0F80
#define CListWnd__DrawHeader_x                                     0x8BE6E0
#define CListWnd__DrawItem_x                                       0x8C04B0
#define CListWnd__DrawLine_x                                       0x8C0C20
#define CListWnd__DrawSeparator_x                                  0x8C1020
#define CListWnd__EnableLine_x                                     0x8BE600
#define CListWnd__EnsureVisible_x                                  0x8BF270
#define CListWnd__ExtendSel_x                                      0x8C03C0
#define CListWnd__GetColumnMinWidth_x                              0x8BDD10
#define CListWnd__GetColumnWidth_x                                 0x8BDC40
#define CListWnd__GetCurSel_x                                      0x8BD420
#define CListWnd__GetItemAtPoint_x                                 0x8BF510
#define CListWnd__GetItemAtPoint1_x                                0x8BF580
#define CListWnd__GetItemData_x                                    0x8BD760
#define CListWnd__GetItemHeight_x                                  0x8BED60
#define CListWnd__GetItemIcon_x                                    0x8BD950
#define CListWnd__GetItemRect_x                                    0x8BF350
#define CListWnd__GetItemText_x                                    0x8BD800
#define CListWnd__GetSelList_x                                     0x8C2800
#define CListWnd__GetSeparatorRect_x                               0x8BFD40
#define CListWnd__InsertLine_x                                     0x8C26F0
#define CListWnd__RemoveLine_x                                     0x8C2700
#define CListWnd__SetColors_x                                      0x8BD570
#define CListWnd__SetColumnJustification_x                         0x8BDFA0
#define CListWnd__SetColumnWidth_x                                 0x8BDCC0
#define CListWnd__SetCurSel_x                                      0x8BD460
#define CListWnd__SetItemColor_x                                   0x8C1BA0
#define CListWnd__SetItemData_x                                    0x8BE480
#define CListWnd__SetItemText_x                                    0x8C19E0
#define CListWnd__ShiftColumnSeparator_x                           0x8C1870
#define CListWnd__Sort_x                                           0x8C33D0
#define CListWnd__ToggleSel_x                                      0x8BE350

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x719AA0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73AFA0
#define CMerchantWnd__RequestBuyItem_x                             0x742060
#define CMerchantWnd__RequestSellItem_x                            0x742B30
#define CMerchantWnd__SelectRecoverySlot_x                         0x73B250
#define CMerchantWnd__SelectBuySellSlot_x                          0x73A450
#define CMerchantWnd__ActualSelect_x                               0x73EF20

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x854080
#define CPacketScrambler__hton_x                                   0x854090

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E0F80
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1060
#define CSidlManager__CreateLabel_x                                0x7A3800
#define CSidlManager__CreateXWndFromTemplate_x                     0x8DF530
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E1340

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D83C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D82C0
#define CSidlScreenWnd__ConvertToRes_x                             0x8FCDC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D8CD0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D9EB0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D9F60
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D9430
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D8680
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D7DF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D8870
#define CSidlScreenWnd__Init1_x                                    0x8D9B80
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D8D90
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D7FB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D9670
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D7A50
#define CSidlScreenWnd__StoreIniVis_x                              0x8D7DA0
#define CSidlScreenWnd__WndNotification_x                          0x8D9900
#define CSidlScreenWnd__GetChildItem_x                             0x8D7EC0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CB830
#define CSidlScreenWnd__m_layoutCopy_x                             0x1732810

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6057E0
#define CSkillMgr__GetSkillCap_x                                   0x6059C0
#define CSkillMgr__GetNameToken_x                                  0x605390

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FC060
#define CSliderWnd__SetValue_x                                     0x8FC230
#define CSliderWnd__SetNumTicks_x                                  0x8FC9B0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A9B20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F5EA0
#define CStmlWnd__CalculateHSBRange_x                              0x8EE400
#define CStmlWnd__CalculateVSBRange_x                              0x8EE370
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EE580
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EED80
#define CStmlWnd__ForceParseNow_x                                  0x8F6820
#define CStmlWnd__GetNextTagPiece_x                                0x8EEC80
#define CStmlWnd__GetSTMLText_x                                    0x4850C0
#define CStmlWnd__GetVisibleText_x                                 0x8EF7D0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F1DA0
#define CStmlWnd__MakeStmlColorTag_x                               0x8ED650
#define CStmlWnd__MakeWndNotificationTag_x                         0x8ED6B0
#define CStmlWnd__SetSTMLText_x                                    0x8F35F0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F5B40
#define CStmlWnd__UpdateHistoryString_x                            0x8F0710

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F9D40
#define CTabWnd__DrawCurrentPage_x                                 0x8F95D0
#define CTabWnd__DrawTab_x                                         0x8F9390
#define CTabWnd__GetCurrentPage_x                                  0x8F9980
#define CTabWnd__GetPageInnerRect_x                                0x8F9080
#define CTabWnd__GetTabInnerRect_x                                 0x8F9280
#define CTabWnd__GetTabRect_x                                      0x8F9150
#define CTabWnd__InsertPage_x                                      0x8FA030
#define CTabWnd__SetPage_x                                         0x8F99B0
#define CTabWnd__SetPageRect_x                                     0x8F9C80
#define CTabWnd__UpdatePage_x                                      0x8F9FD0
#define CTabWnd__GetPageFromTabIndex_x                             0x8F92E0
#define CTabWnd__GetCurrentTabIndex_x                              0x8F9010

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E6570
#define CPageWnd__SetTabText_x                                     0x906120

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437310

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D5D20
#define CTextureFont__GetTextExtent_x                              0x8D5A80

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63E0D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x902560

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BB530

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029E0
#define CXStr__CXStr1_x                                            0x7E06F0
#define CXStr__CXStr3_x                                            0x89E990
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x89EB00
#define CXStr__operator_equal1_x                                   0x89EB50
#define CXStr__operator_plus_equal1_x                              0x89FC50

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8CAA80
#define CXWnd__Center_x                                            0x8D0B30
#define CXWnd__ClrFocus_x                                          0x8CA660
#define CXWnd__Destroy_x                                           0x8D15F0
#define CXWnd__DoAllDrawing_x                                      0x8D0780
#define CXWnd__DrawChildren_x                                      0x8D0920
#define CXWnd__DrawColoredRect_x                                   0x8CAE50
#define CXWnd__DrawTooltip_x                                       0x8CB100
#define CXWnd__DrawTooltipAtPoint_x                                0x8CF720
#define CXWnd__GetBorderFrame_x                                    0x8CB530
#define CXWnd__GetChildWndAt_x                                     0x8D14D0
#define CXWnd__GetClientClipRect_x                                 0x8CB300
#define CXWnd__GetScreenClipRect_x                                 0x8CFE20
#define CXWnd__GetScreenRect_x                                     0x8CB6D0
#define CXWnd__GetTooltipRect_x                                    0x8CAF90
#define CXWnd__GetWindowTextA_x                                    0x427450
#define CXWnd__IsActive_x                                          0x8C6080
#define CXWnd__IsDescendantOf_x                                    0x8CB480
#define CXWnd__IsReallyVisible_x                                   0x8CE760
#define CXWnd__IsType_x                                            0x8D0BA0
#define CScreenPieceTemplate__IsType_x                             0x8FECB0
#define CXWnd__Move_x                                              0x8CDE50
#define CXWnd__Move1_x                                             0x8D0440
#define CXWnd__ProcessTransition_x                                 0x8CAA20
#define CXWnd__Refade_x                                            0x8CA800
#define CXWnd__Resize_x                                            0x8CB790
#define CXWnd__Right_x                                             0x8CFC20
#define CXWnd__SetFocus_x                                          0x8CCFD0
#define CXWnd__SetFont_x                                           0x8CA6B0
#define CXWnd__SetKeyTooltip_x                                     0x8CBA00
#define CXWnd__SetMouseOver_x                                      0x8D0150
#define CXWnd__StartFade_x                                         0x8CAAD0
#define CXWnd__GetChildItem_x                                      0x8D0090
#define CXWnd__SetParent_x                                         0x8D1480

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C7920
#define CXWndManager__DrawWindows_x                                0x8C7560
#define CXWndManager__GetKeyboardFlags_x                           0x8C5BB0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6520
#define CXWndManager__RemoveWnd_x                                  0x8C6210

// CDBStr
#define CDBStr__GetString_x                                        0x4BB400

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452430
#define EQ_Character__Cur_HP_x                                     0x465BC0
#define EQ_Character__Cur_Mana_x                                   0x45AB10
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B6D0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443990
#define EQ_Character__GetFocusRangeModifier_x                      0x4439F0
#define EQ_Character__GetHPRegen_x                                 0x469DA0
#define EQ_Character__GetEnduranceRegen_x                          0x4651D0
#define EQ_Character__GetManaRegen_x                               0x46A340
#define EQ_Character__Max_Endurance_x                              0x5CBE80
#define EQ_Character__Max_HP_x                                     0x45D690
#define EQ_Character__Max_Mana_x                                   0x5CBCB0
#define EQ_Character__doCombatAbility_x                            0x5C9380
#define EQ_Character__UseSkill_x                                   0x471310
#define EQ_Character__GetConLevel_x                                0x5BE850
#define EQ_Character__IsExpansionFlag_x                            0x426990
#define EQ_Character__TotalEffect_x                                0x44F760
#define EQ_Character__GetPCSpellAffect_x                           0x44BAD0
#define EQ_Character__SpellDuration_x                              0x449A70
#define EQ_Character__FindItemByRecord_x                           0x463230
#define EQ_Character__GetAdjustedSkill_x                           0x465D90
#define EQ_Character__GetBaseSkill_x                               0x45D570

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x871E80

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D44A0

//PcClient
#define PcClient__PcClient_x                                       0x5C06A0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446CE0
#define CCharacterSelect__EnterWorld_x                             0x4464B0
#define CCharacterSelect__Quit_x                                   0x445070

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59EC20
#define EQ_Item__CreateItemTagString_x                             0x8522C0
#define EQ_Item__IsStackable_x                                     0x8478B0
#define EQ_Item__GetImageNum_x                                     0x84A3E0
#define EQ_Item__CreateItemClient_x                                0x59F820
#define EQ_Item__GetItemValue_x                                    0x850CF0
#define EQ_Item__ValueSellMerchant_x                               0x853D10
#define EQ_Item__IsKeyRingItem_x                                   0x848400
#define EQ_Item__CanGoInBag_x                                      0x59EDB0
#define EQ_Item__GetMaxItemCount_x                                 0x8477A0
#define EQ_Item__GetHeldItem_x                                     0x8491F0
#define EQ_Item__GetAugmentFitBySlot_x                             0x853B40

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DB660
#define EQ_LoadingS__Array_x                                       0xC0C738

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CE3A0
#define EQ_PC__GetAlternateAbilityId_x                             0x85C150
#define EQ_PC__GetCombatAbility_x                                  0x85C1E0
#define EQ_PC__GetCombatAbilityTimer_x                             0x856D30
#define EQ_PC__GetItemRecastTimer_x                                0x5C7B40
#define EQ_PC__HasLoreItem_x                                       0x5C1E60
#define EQ_PC__AlertInventoryChanged_x                             0x5BE800
#define EQ_PC__GetPcZoneClient_x                                   0x5E89B0
#define EQ_PC__RemoveMyAffect_x                                    0x5C6FA0
#define EQ_PC__GetKeyRingItems_x                                   0x857150
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x869E20
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85E0A0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526910
#define EQItemList__add_object_x                                   0x553760
#define EQItemList__add_item_x                                     0x526850
#define EQItemList__delete_item_x                                  0x526D00
#define EQItemList__FreeItemList_x                                 0x526C00

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4BA5C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D4240
#define EQPlayer__dEQPlayer_x                                      0x5DC860
#define EQPlayer__DoAttack_x                                       0x5EE330
#define EQPlayer__EQPlayer_x                                       0x5DEF90
#define EQPlayer__SetNameSpriteState_x                             0x5D9740
#define EQPlayer__SetNameSpriteTint_x                              0x5D5660
#define PlayerBase__HasProperty_j_x                                0x930050
#define EQPlayer__IsTargetable_x                                   0x9302F0
#define EQPlayer__CanSee_x                                         0x930850
#define PlayerZoneClient__ChangeHeight_x                           0x5EE1F0
#define EQPlayer__CanSee1_x                                        0x930940
#define PlayerBase__GetVisibilityLineSegment_x                     0x9305E0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8B60
#define PlayerZoneClient__IsValidTeleport_x                        0x554020

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2F90
#define EQPlayerManager__GetSpawnByName_x                          0x5E33F0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2FC0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4DC0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4E00
#define KeypressHandler__ClearCommandStateArray_x                  0x5A49B0
#define KeypressHandler__HandleKeyDown_x                           0x5A3300
#define KeypressHandler__HandleKeyUp_x                             0x5A3620
#define KeypressHandler__SaveKeymapping_x                          0x5A4A80

// MapViewMap 
#define MapViewMap__Clear_x                                        0x712430
#define MapViewMap__SaveEx_x                                       0x715760

#define PlayerPointManager__GetAltCurrency_x                       0x86FF30

// StringTable 
#define StringTable__getString_x                                   0x86A150

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB910
#define PcZoneClient__RemovePetEffect_x                            0x5C8010
#define PcZoneClient__HasAlternateAbility_x                        0x5C89B0
#define PcZoneClient__GetCurrentMod_x                              0x45CB40
#define PcZoneClient__GetModCap_x                                  0x45A270
#define PcZoneClient__CanEquipItem_x                               0x5C8ED0
#define PcZoneClient__GetItemByID_x                                0x5CD710
#define PcZoneClient__GetItemByItemClass_x                         0x5CE2C0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B070

//IconCache
#define IconCache__GetIcon_x                                       0x6AF650

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A6550
#define CContainerMgr__CloseContainer_x                            0x6A6D70

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x773770

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x597C60

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F56A0
#define EQ_Spell__SpellAffects_x                                   0x4F2D30
#define EQ_Spell__SpellAffectBase_x                           0x4F2DA0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B960
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ABA0
#define CLootWnd__LootAll_x                                        0x707D00
#define CLootWnd__RequestLootSlot_x                                0x708510
#define EQ_Spell__IsStackable_x                                    0x449640
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4496F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F190
#define EQ_Spell__IsSPAStacking_x                                  0x4F28A0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2360
#define EQ_Spell__IsNoRemove_x                                     0x435350
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F28C0

#define __IsResEffectSpell_x                                       0x449770

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87BAF0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BA650
#define CTargetWnd__WndNotification_x                              0x7BA140
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BA830

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7BF780

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EE300
#define EqSoundManager__PlayScriptMp3_x                            0x4EFDA0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A9730

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E9C30
#define CSidlManager__FindAnimation1_x                             0x8DEF60

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2E40
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2DF0
#define CAltAbilityData__GetMaxRank_x                              0x4D7780

//CTargetRing
#define CTargetRing__Cast_x                                        0x595520

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459220
#define CharacterBase__CreateItemGlobalIndex_x                     0x4760A0
#define CharacterBase__CreateItemIndex_x                           0x51FF50
#define CharacterBase__GetItemPossession_x                         0x444540
#define CharacterBase__GetItemByGlobalIndex_x                      0x87F940
#define CharacterBase__GetEffectId_x                               0x4591E0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68F3D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68EB30

//messages
#define msg_spell_worn_off_x                                       0x4FD250
#define msg_new_text_x                                             0x506910
#define msgTokenTextParam_x                                        0x5030F0

//SpellManager
#define SpellManager__vftable_x                                    0xAC9418
#define SpellManager__SpellManager_x                               0x47ED40
#define Spellmanager__LoadTextSpells_x          0x60C680

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9343B0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488B80
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43F0B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4493B0
#define ItemGlobalIndex__IsValidIndex_x                            0x458AC0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87D7B0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87C6F0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x700CE0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AB290
#define CCursorAttachment__Deactivate_x                            0x6AA7D0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FB560

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                                0x48D330
