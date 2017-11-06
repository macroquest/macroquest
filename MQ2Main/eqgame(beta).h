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
#define __ExpectedVersionDate                                     "Nov  6 2017"
#define __ExpectedVersionTime                                     "04:16:18"
#define __ActualVersionDate_x                                      0xAE4090
#define __ActualVersionTime_x                                      0xAE409C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AA6C0
#define __MemChecker1_x                                            0x8A36D0
#define __MemChecker2_x                                            0x640550
#define __MemChecker3_x                                            0x6404A0
#define __MemChecker4_x                                            0x7F5000
#define __EncryptPad0_x                                            0xC3F000
#define __EncryptPad1_x                                            0xD18BB8
#define __EncryptPad2_x                                            0xC67EE8
#define __EncryptPad3_x                                            0xC67AE8
#define __EncryptPad4_x                                            0xD071B8
#define __EncryptPad5_x                                            0x10C22F0
#define __AC1_x                                                    0x7B4285
#define __AC2_x                                                    0x563A67
#define __AC3_x                                                    0x561BE0
#define __AC4_x                                                    0x573DA1
#define __AC5_x                                                    0x587AFB
#define __AC6_x                                                    0x58B69E
#define __AC7_x                                                    0x5820FC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4908

// Direct Input
#define DI8__Main_x                                                0x10C22C8
#define DI8__Keyboard_x                                            0x10C22CC
#define DI8__Mouse_x                                               0x10C22D0
#define DI8__Mouse_Copy_x                                          0xF3046C
#define DI8__Mouse_Check_x                                         0xFB9FB4
#define __AutoSkillArray_x                                         0xF31380
#define __Attack_x                                                 0xFB4A73
#define __Autofire_x                                               0xFB4A74
#define __BindList_x                                               0xC1B378
#define g_eqCommandStates_x                                        0xF1F1B8
#define __Clicks_x                                                 0xF30528
#define __CommandList_x                                            0xC1DA90
#define __CurrentMapLabel_x                                        0x10C82C0
#define __CurrentSocial_x                                          0xBEA8F0
#define __DoAbilityList_x                                          0xF66C38
#define __do_loot_x                                                0x532780
#define __DrawHandler_x                                            0x1731F3C
#define __GroupCount_x                                             0xF20AC2

#define __Guilds_x                                                 0xF266D8
#define __gWorld_x                                                 0xF22F7C
#define __HotkeyPage_x                                             0xFAD638
#define __HWnd_x                                                   0xFBA0D0
#define __InChatMode_x                                             0xF30454
#define __LastTell_x                                               0xF32334
#define __LMouseHeldTime_x                                         0xF30594
#define __Mouse_x                                                  0x10C22D4
#define __MouseLook_x                                              0xF304EE
#define __MouseEventTime_x                                         0xFB520C
#define __gpbCommandEvent_x                                        0xF23044
#define __NetStatusToggle_x                                        0xF304F1
#define __PCNames_x                                                0xF3193C
#define __RangeAttackReady_x                                       0xF31664
#define __RMouseHeldTime_x                                         0xF30590
#define __RunWalkState_x                                           0xF30458
#define __ScreenMode_x                                             0xE6ED98
#define __ScreenX_x                                                0xF3040C
#define __ScreenY_x                                                0xF30408
#define __ScreenXMax_x                                             0xF30410
#define __ScreenYMax_x                                             0xF30414
#define __ServerHost_x                                             0xF20A0C
#define __ServerName_x                                             0xF66BF8
#define __ShiftKeyDown_x                                           0xF30AE8
#define __ShowNames_x                                              0xF3181C
#define __Socials_x                                                0xF66CF8
#define __SubscriptionType_x                                       0x10F8A44
#define __TargetAggroHolder_x                                      0x10CA41C
#define __ZoneType_x                                               0xF308EC
#define __GroupAggro_x                                             0x10CA45C
#define __LoginName_x                                              0xFB8BAC
#define __Inviter_x                                                0xFB49F0
#define __AttackOnAssist_x                                         0xF317D8
#define __UseTellWindows_x                                         0xF31AD4

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF23068
#define instEQZoneInfo_x                                           0xF306E4
#define instKeypressHandler_x                                      0xFB51F0
#define pinstActiveBanker_x                                        0xF23020
#define pinstActiveCorpse_x                                        0xF23024
#define pinstActiveGMaster_x                                       0xF23028
#define pinstActiveMerchant_x                                      0xF2301C
#define pinstAggroInfo_x                                           0xD2C3EC
#define pinstAltAdvManager_x                                       0xE6FF00
#define pinstAuraMgr_x                                             0xD3CC08
#define pinstBandageTarget_x                                       0xF23008
#define pinstCamActor_x                                            0xE6F7D0
#define pinstCDBStr_x                                              0xE6ED2C
#define pinstCDisplay_x                                            0xF23030
#define pinstCEverQuest_x                                          0x10C2448
#define pinstEverQuestInfo_x                                       0xF30400
#define pinstCharData_x                                            0xF22FEC
#define pinstCharSpawn_x                                           0xF23014
#define pinstControlledMissile_x                                   0xF22FE8
#define pinstControlledPlayer_x                                    0xF23014
#define pinstCSidlManager_x                                        0x1730EA8
#define pinstCXWndManager_x                                        0x1730EA0
#define instDynamicZone_x                                          0xF302A0
#define pinstDZMember_x                                            0xF303B0
#define pinstDZTimerInfo_x                                         0xF303B4
#define pinstEQItemList_x                                          0xF1F490
#define pinstEQObjectList_x                                        0xF204BC
#define instEQMisc_x                                               0xC037B8
#define pinstEQSoundManager_x                                      0xE704D0
#define instExpeditionLeader_x                                     0xF302EA
#define instExpeditionName_x                                       0xF3032A
#define pinstGroup_x                                               0xF20ABE
#define pinstImeManager_x                                          0x1730EAC
#define pinstLocalPlayer_x                                         0xF23000
#define pinstMercenaryData_x                                       0xFB5870
#define pinstMercenaryStats_x                                      0x10CA568
#define pinstMercAltAbilities_x                                    0xE70288
#define pinstModelPlayer_x                                         0xF2302C
#define pinstPCData_x                                              0xF22FEC
#define pinstSkillMgr_x                                            0xFB6868
#define pinstSpawnManager_x                                        0xFB60C0
#define pinstSpellManager_x                                        0xFB69B0
#define pinstSpellSets_x                                           0xFAD69C
#define pinstStringTable_x                                         0xF22F94
#define pinstSwitchManager_x                                       0xF20650
#define pinstTarget_x                                              0xF23018
#define pinstTargetObject_x                                        0xF22FF0
#define pinstTargetSwitch_x                                        0xF22FF4
#define pinstTaskMember_x                                          0xE6EC78
#define pinstTrackTarget_x                                         0xF2300C
#define pinstTradeTarget_x                                         0xF22FFC
#define instTributeActive_x                                        0xC037DD
#define pinstViewActor_x                                           0xE6F7CC
#define pinstWorldData_x                                           0xF22FD0
#define pinstZoneAddr_x                                            0xF30984
#define pinstPlayerPath_x                                          0xFB6120
#define pinstTargetIndicator_x                                     0xFB6B48
#define pinstCTargetManager_x                                      0xFB6BA8
#define EQObject_Top_x                                             0xF22FE0
#define pinstRealEstateItems_x                                     0xFB66D4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE6F6E8
#define pinstCAchievementsWnd_x                                    0xE6F744
#define pinstCTextOverlay_x                                        0xD2C998
#define pinstCAudioTriggersWindow_x                                0xD2C780
#define pinstCCharacterSelect_x                                    0xE6F654
#define pinstCFacePick_x                                           0xE6F404
#define pinstCFindItemWnd_x                                        0xE6F6E4
#define pinstCNoteWnd_x                                            0xE6F60C
#define pinstCBookWnd_x                                            0xE6F614
#define pinstCPetInfoWnd_x                                         0xE6F618
#define pinstCTrainWnd_x                                           0xE6F61C
#define pinstCSkillsWnd_x                                          0xE6F620
#define pinstCSkillsSelectWnd_x                                    0xE6F624
#define pinstCCombatSkillsSelectWnd_x                              0xE6F628
#define pinstCFriendsWnd_x                                         0xE6F62C
#define pinstCAuraWnd_x                                            0xE6F630
#define pinstCRespawnWnd_x                                         0xE6F634
#define pinstCBandolierWnd_x                                       0xE6F638
#define pinstCPotionBeltWnd_x                                      0xE6F63C
#define pinstCAAWnd_x                                              0xE6F640
#define pinstCAlarmWnd_x                                           0xE6F64C
#define pinstCGroupSearchFiltersWnd_x                              0xE6F644
#define pinstCLoadskinWnd_x                                        0xE6F648
#define pinstCLargeDialogWnd_x                                     0x10C94C8
#define pinstCMusicPlayerWnd_x                                     0xE6F650
#define pinstCMailWnd_x                                            0xE6F658
#define pinstCMailCompositionWnd_x                                 0xE6F65C
#define pinstCMailAddressBookWnd_x                                 0xE6F660
#define pinstCRaidWnd_x                                            0xE6F668
#define pinstCRaidOptionsWnd_x                                     0xE6F66C
#define pinstCBreathWnd_x                                          0xE6F670
#define pinstCMapViewWnd_x                                         0xE6F674
#define pinstCMapToolbarWnd_x                                      0xE6F678
#define pinstCEditLabelWnd_x                                       0xE6F67C
#define pinstCTargetWnd_x                                          0xE6F680
#define pinstCColorPickerWnd_x                                     0xE6F684
#define pinstCPlayerWnd_x                                          0xE6F688
#define pinstCOptionsWnd_x                                         0xE6F68C
#define pinstCBuffWindowNORMAL_x                                   0xE6F690
#define pinstCBuffWindowSHORT_x                                    0xE6F694
#define pinstCharacterCreation_x                                   0xE6F698
#define pinstCCursorAttachment_x                                   0xE6F69C
#define pinstCCastingWnd_x                                         0xE6F6A0
#define pinstCCastSpellWnd_x                                       0xE6F6A4
#define pinstCSpellBookWnd_x                                       0xE6F6A8
#define pinstCInventoryWnd_x                                       0xE6F6AC
#define pinstCBankWnd_x                                            0xE6F6B4
#define pinstCQuantityWnd_x                                        0xE6F6B8
#define pinstCLootWnd_x                                            0xE6F6BC
#define pinstCActionsWnd_x                                         0xE6F6C0
#define pinstCCombatAbilityWnd_x                                   0xE6F6C8
#define pinstCMerchantWnd_x                                        0xE6F6CC
#define pinstCTradeWnd_x                                           0xE6F6D4
#define pinstCSelectorWnd_x                                        0xE6F6D8
#define pinstCBazaarWnd_x                                          0xE6F6DC
#define pinstCBazaarSearchWnd_x                                    0xE6F6E0
#define pinstCGiveWnd_x                                            0xE6F700
#define pinstCTrackingWnd_x                                        0xE6F708
#define pinstCInspectWnd_x                                         0xE6F70C
#define pinstCSocialEditWnd_x                                      0xE6F710
#define pinstCFeedbackWnd_x                                        0xE6F714
#define pinstCBugReportWnd_x                                       0xE6F718
#define pinstCVideoModesWnd_x                                      0xE6F71C
#define pinstCTextEntryWnd_x                                       0xE6F724
#define pinstCFileSelectionWnd_x                                   0xE6F728
#define pinstCCompassWnd_x                                         0xE6F72C
#define pinstCPlayerNotesWnd_x                                     0xE6F730
#define pinstCGemsGameWnd_x                                        0xE6F734
#define pinstCTimeLeftWnd_x                                        0xE6F750
#define pinstCPetitionQWnd_x                                       0xE6F754
#define pinstCStoryWnd_x                                           0xE6F758
#define pinstCJournalTextWnd_x                                     0xE6F75C
#define pinstCJournalCatWnd_x                                      0xE6F760
#define pinstCBodyTintWnd_x                                        0xE6F764
#define pinstCServerListWnd_x                                      0xE6F768
#define pinstCAvaZoneWnd_x                                         0xE6F774
#define pinstCBlockedBuffWnd_x                                     0xE6F778
#define pinstCBlockedPetBuffWnd_x                                  0xE6F77C
#define pinstCInvSlotMgr_x                                         0xE6F7C4
#define pinstCContainerMgr_x                                       0xE6F7C8
#define pinstCAdventureLeaderboardWnd_x                            0x10C2DF8
#define pinstCAdventureRequestWnd_x                                0x10C2E70
#define pinstCAltStorageWnd_x                                      0x10C3150
#define pinstCAdventureStatsWnd_x                                  0x10C2EE8
#define pinstCBarterMerchantWnd_x                                  0x10C3E98
#define pinstCBarterSearchWnd_x                                    0x10C3F10
#define pinstCBarterWnd_x                                          0x10C3F88
#define pinstCChatWindowManager_x                                  0x10C4798
#define pinstCDynamicZoneWnd_x                                     0x10C4CC8
#define pinstCEQMainWnd_x                                          0x10C4E90
#define pinstCFellowshipWnd_x                                      0x10C4C5C
#define pinstCFindLocationWnd_x                                    0x10C5160
#define pinstCGroupSearchWnd_x                                     0x10C5430
#define pinstCGroupWnd_x                                           0x10C54A8
#define pinstCGuildBankWnd_x                                       0x10C5520
#define pinstCGuildMgmtWnd_x                                       0x10C7610
#define pinstCHotButtonWnd_x                                       0x10C770C
#define pinstCHotButtonWnd1_x                                      0x10C770C
#define pinstCHotButtonWnd2_x                                      0x10C7710
#define pinstCHotButtonWnd3_x                                      0x10C7714
#define pinstCHotButtonWnd4_x                                      0x10C7738
#define pinstCItemDisplayManager_x                                 0x10C7B90
#define pinstCItemExpTransferWnd_x                                 0x10C7C8C
#define pinstCLFGuildWnd_x                                         0x10C7F68
#define pinstCMIZoneSelectWnd_x                                    0x10C8548
#define pinstCConfirmationDialog_x                                 0x10C8B60
#define pinstCPopupWndManager_x                                    0x10C8B60
#define pinstCProgressionSelectionWnd_x                            0x10C8C50
#define pinstCPvPStatsWnd_x                                        0x10C8D40
#define pinstCTaskWnd_x                                            0x10CA848
#define pinstCTaskSomething_x                                      0xD3D820
#define pinstCTaskTemplateSelectWnd_x                              0x10CA7D0
#define pinstCTipWndOFDAY_x                                        0x10CA9B0
#define pinstCTipWndCONTEXT_x                                      0x10CA9B4
#define pinstCTitleWnd_x                                           0x10CAA30
#define pinstCContextMenuManager_x                                 0x1730D30
#define pinstCVoiceMacroWnd_x                                      0xFB6F80
#define pinstCHtmlWnd_x                                            0xFB7070
#define pinstItemIconCache_x                                       0x10C4E38
#define pinstCTradeskillWnd_x                                      0x10CAB30
#define pinstCAdvancedLootWnd_x                                    0xE6F7B8
#define pinstRewardSelectionWnd_x                                  0x10C9268
#define pinstEQSuiteTextureLoader_x                                0xD1AA80

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54A290
#define __CastRay2_x                                               0x549BC0
#define __HeadingDiff_x                                            0x933710
#define __FixHeading_x                                             0x9336A0
#define __get_bearing_x                                            0x5398D0
#define __ConvertItemTags_x                                        0x5373A0
#define __ExecuteCmd_x                                             0x521CA0
#define __EQGetTime_x                                              0x8A3070
#define __get_melee_range_x                                        0x528980
#define __GetGaugeValueFromEQ_x                                    0x7B2E40
#define __GetLabelFromEQ_x                                         0x7B4210
#define __ToggleKeyRingItem_x                                      0x490150
#define __GetXTargetType_x                                         0x935380
#define __LoadFrontEnd_x                                           0x63FC20
#define __NewUIINI_x                                               0x7B2810
#define __ProcessGameEvents_x                                      0x583E90
#define __ProcessMouseEvent_x                                      0x583630
#define CrashDetected_x                                            0x6415E0
#define wwsCrashReportCheckForUploader_x                           0x800E30
#define __AppCrashWrapper_x                                        0xC67ADC
#define __pCrashHandler_x                                          0x10D7A10
#define __CrashHandler_x                                           0x8008C0
#define wwsCrashReportPlatformLaunchUploader_x                     0x803060
#define DrawNetStatus_x                                            0x5BA1D0
#define Util__FastTime_x                                           0x8A2D10
#define Expansion_HoT_x                                            0xF317C8
#define __HelpPath_x                                               0xFB4F78
#define __STMLToText_x                                             0x8E9440
#define __GetAnimationCache_x                                      0x6AF3E0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423330
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DF90
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DD60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8440
#define AltAdvManager__IsAbilityReady_x                            0x4D84B0
#define AltAdvManager__GetAAById_x                                 0x4D89A0
#define AltAdvManager__CanTrainAbility_x                           0x4D95D0
#define AltAdvManager__CanSeeAbility_x                             0x4D9190

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46A190
#define CharacterZoneClient__HasSkill_x                            0x466200
#define CharacterZoneClient__MakeMeVisible_x                       0x46BD00
#define CharacterZoneClient__IsStackBlocked_x                      0x44C020
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B540
#define CharacterZoneClient__GetItemCountWorn_x                    0x464760
#define CharacterZoneClient__GetItemCountInInventory_x             0x464840
#define CharacterZoneClient__GetCursorItemCount_x                  0x464920
#define CharacterZoneClient__FindAffectSlot_x                      0x4516D0
#define CharacterZoneClient__BardCastBard_x                        0x44ACB0
#define CharacterZoneClient__GetMaxEffects_x                       0x449840
#define CharacterZoneClient__GetEffect_x                           0x44B770
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451530
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449B90
#define CharacterZoneClient__GetLastEffectSlot_x                   0x450080

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66F5D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67D420

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598F90
#define CButtonWnd__CButtonWnd_x                                   0x8DD6E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x698630
#define CChatManager__InitContextMenu_x                            0x699780
#define CChatManager__FreeChatWindow_x                             0x6980E0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A18C0
#define CChatManager__SetLockedActiveChatWindow_x                  0x698600

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E7790
#define CContextMenu__dCContextMenu_x                              0x8E79A0
#define CContextMenu__AddMenuItem_x                                0x8E7EC0
#define CContextMenu__RemoveMenuItem_x                             0x8E7B20
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7B40
#define CContextMenu__CheckMenuItem_x                              0x8E7BC0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D3CB0
#define CContextMenuManager__RemoveMenu_x                          0x8D4050
#define CContextMenuManager__PopupMenu_x                           0x8D44A0
#define CContextMenuManager__Flush_x                               0x8D3D20
#define CContextMenuManager__GetMenu_x                             0x4194B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x887180
#define CChatService__GetFriendName_x                              0x887190

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69F3B0
#define CChatWindow__Clear_x                                       0x69EC90
#define CChatWindow__WndNotification_x                             0x69FCB0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D7B10
#define CComboWnd__Draw_x                                          0x8D7D20
#define CComboWnd__GetCurChoice_x                                  0x8D78C0
#define CComboWnd__GetListRect_x                                   0x8D7FC0
#define CComboWnd__GetTextRect_x                                   0x8D7B80
#define CComboWnd__InsertChoice_x                                  0x8D8120
#define CComboWnd__SetColors_x                                     0x8D7850
#define CComboWnd__SetChoice_x                                     0x8D7880
#define CComboWnd__GetItemCount_x                                  0x8D78B0
#define CComboWnd__GetCurChoiceText_x                              0x8D7900


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A9580
#define CContainerWnd__vftable_x                                   0xAED9A8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C6280
#define CDisplay__GetClickedActor_x                                0x4BEB40
#define CDisplay__GetUserDefinedColor_x                            0x4BD720
#define CDisplay__GetWorldFilePath_x                               0x4BCB70
#define CDisplay__is3dON_x                                         0x4BC000
#define CDisplay__ReloadUI_x                                       0x4D0040
#define CDisplay__WriteTextHD2_x                                   0x4C2610
#define CDisplay__TrueDistance_x                                   0x4BF770

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FE7E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EBCF0
#define CEditWnd__GetCharIndexPt_x                                 0x8ECE50
#define CEditWnd__GetDisplayString_x                               0x8EBEA0
#define CEditWnd__GetHorzOffset_x                                  0x8EC1E0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC910
#define CEditWnd__GetSelStartPt_x                                  0x8ED110
#define CEditWnd__GetSTMLSafeText_x                                0x8EC380
#define CEditWnd__PointFromPrintableChar_x                         0x8ECA00
#define CEditWnd__SelectableCharFromPoint_x                        0x8ECB80
#define CEditWnd__SetEditable_x                                    0x8EC350

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A5D0
#define CEverQuest__ClickedPlayer_x                                0x5641B0
#define CEverQuest__CreateTargetIndicator_x                        0x5650B0
#define CEverQuest__DeleteTargetIndicator_x                        0x565130
#define CEverQuest__DoTellWindow_x                                 0x4763A0
#define CEverQuest__OutputTextToLog_x                              0x476000
#define CEverQuest__DropHeldItemOnGround_x                         0x57AB40
#define CEverQuest__dsp_chat_x                                     0x4766E0
#define CEverQuest__trimName_x                                     0x560AC0
#define CEverQuest__Emote_x                                        0x578E50
#define CEverQuest__EnterZone_x                                    0x573F30
#define CEverQuest__GetBodyTypeDesc_x                              0x55E500
#define CEverQuest__GetClassDesc_x                                 0x5679F0
#define CEverQuest__GetClassThreeLetterCode_x                      0x567FF0
#define CEverQuest__GetDeityDesc_x                                 0x55EDE0
#define CEverQuest__GetLangDesc_x                                  0x55E890
#define CEverQuest__GetRaceDesc_x                                  0x5681B0
#define CEverQuest__InterpretCmd_x                                 0x56BD50
#define CEverQuest__LeftClickedOnPlayer_x                          0x5806A0
#define CEverQuest__LMouseUp_x                                     0x582650
#define CEverQuest__RightClickedOnPlayer_x                         0x5811B0
#define CEverQuest__RMouseUp_x                                     0x5820B0
#define CEverQuest__SetGameState_x                                 0x564A80
#define CEverQuest__UPCNotificationFlush_x                         0x55CE90
#define CEverQuest__IssuePetCommand_x                              0x56C730

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BA2B0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BA310
#define CGaugeWnd__Draw_x                                          0x6BA740

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B240
#define CGuild__GetGuildName_x                                     0x43B710
#define CGuild__GetGuildIndex_x                                    0x43C920

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D67D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E3BB0
#define CInvSlotMgr__MoveItem_x                                    0x6E4370
#define CInvSlotMgr__SelectSlot_x                                  0x6E34A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E2900
#define CInvSlot__SliderComplete_x                                 0x6E0120
#define CInvSlot__GetItemBase_x                                    0x6DF580
#define CInvSlot__UpdateItem_x                                     0x6DFB00

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E57D0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E6900

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AED60
#define CItemDisplayWnd__UpdateStrings_x                           0x6E7A00
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F4630
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F4B60
#define CItemDisplayWnd__SetItem_x                                 0x6FA4B0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E5B50

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EDFC0

// CLabel 
#define CLabel__Draw_x                                             0x701280

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C3810
#define CListWnd__dCListWnd_x                                      0x8C4AD0
#define CListWnd__AddColumn_x                                      0x8C4A70
#define CListWnd__AddColumn1_x                                     0x8C4100
#define CListWnd__AddLine_x                                        0x8C3AE0
#define CListWnd__AddString_x                                      0x8C3D00
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C0920
#define CListWnd__CalculateVSBRange_x                              0x8C2CD0
#define CListWnd__ClearSel_x                                       0x8BFC40
#define CListWnd__ClearAllSel_x                                    0x8BFBF0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C36A0
#define CListWnd__Compare_x                                        0x8C1610
#define CListWnd__Draw_x                                           0x8C28D0
#define CListWnd__DrawColumnSeparators_x                           0x8C2760
#define CListWnd__DrawHeader_x                                     0x8BFF00
#define CListWnd__DrawItem_x                                       0x8C1C90
#define CListWnd__DrawLine_x                                       0x8C2400
#define CListWnd__DrawSeparator_x                                  0x8C2800
#define CListWnd__EnableLine_x                                     0x8BFE20
#define CListWnd__EnsureVisible_x                                  0x8C0A80
#define CListWnd__ExtendSel_x                                      0x8C1BA0
#define CListWnd__GetColumnMinWidth_x                              0x8BF530
#define CListWnd__GetColumnWidth_x                                 0x8BF460
#define CListWnd__GetCurSel_x                                      0x8BEC30
#define CListWnd__GetItemAtPoint_x                                 0x8C0D20
#define CListWnd__GetItemAtPoint1_x                                0x8C0D90
#define CListWnd__GetItemData_x                                    0x8BEF70
#define CListWnd__GetItemHeight_x                                  0x8C0580
#define CListWnd__GetItemIcon_x                                    0x8BF160
#define CListWnd__GetItemRect_x                                    0x8C0B60
#define CListWnd__GetItemText_x                                    0x8BF010
#define CListWnd__GetSelList_x                                     0x8C3FF0
#define CListWnd__GetSeparatorRect_x                               0x8C1540
#define CListWnd__InsertLine_x                                     0x8C3EE0
#define CListWnd__RemoveLine_x                                     0x8C3EF0
#define CListWnd__SetColors_x                                      0x8BED80
#define CListWnd__SetColumnJustification_x                         0x8BF7C0
#define CListWnd__SetColumnWidth_x                                 0x8BF4E0
#define CListWnd__SetCurSel_x                                      0x8BEC70
#define CListWnd__SetItemColor_x                                   0x8C3390
#define CListWnd__SetItemData_x                                    0x8BFCA0
#define CListWnd__SetItemText_x                                    0x8C31D0
#define CListWnd__ShiftColumnSeparator_x                           0x8C3060
#define CListWnd__Sort_x                                           0x8C4BD0
#define CListWnd__ToggleSel_x                                      0x8BFB70

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71A360

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73DBF0
#define CMerchantWnd__RequestBuyItem_x                             0x747580
#define CMerchantWnd__RequestSellItem_x                            0x749CA0
#define CMerchantWnd__SelectRecoverySlot_x                         0x73E1E0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73AAB0
#define CMerchantWnd__ActualSelect_x                               0x73F170

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x855440
#define CPacketScrambler__hton_x                                   0x855450

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E25D0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E26B0
#define CSidlManager__CreateLabel_x                                0x7A3CA0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E0B80
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E2990

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D9B50
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D9A50
#define CSidlScreenWnd__ConvertToRes_x                             0x8FE6C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DA450
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DB620
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DB6D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DABA0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D9E00
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D9580
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D9FF0
#define CSidlScreenWnd__Init1_x                                    0x8DB2F0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DA500
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D9740
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DADE0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D91E0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D9530
#define CSidlScreenWnd__WndNotification_x                          0x8DB070
#define CSidlScreenWnd__GetChildItem_x                             0x8D9650
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CCFD0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1730E50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x605590
#define CSkillMgr__GetSkillCap_x                                   0x605770
#define CSkillMgr__GetNameToken_x                                  0x605140

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FD980
#define CSliderWnd__SetValue_x                                     0x8FDB50
#define CSliderWnd__SetNumTicks_x                                  0x8FE2D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A9FB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F7780
#define CStmlWnd__CalculateHSBRange_x                              0x8EFCF0
#define CStmlWnd__CalculateVSBRange_x                              0x8EFC60
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EFE70
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F0670
#define CStmlWnd__ForceParseNow_x                                  0x8F8100
#define CStmlWnd__GetNextTagPiece_x                                0x8F0570
#define CStmlWnd__GetSTMLText_x                                    0x484630
#define CStmlWnd__GetVisibleText_x                                 0x8F10C0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F3670
#define CStmlWnd__MakeStmlColorTag_x                               0x8EEF40
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EEFA0
#define CStmlWnd__SetSTMLText_x                                    0x8F4EC0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F7420
#define CStmlWnd__UpdateHistoryString_x                            0x8F1FF0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FB610
#define CTabWnd__DrawCurrentPage_x                                 0x8FAEA0
#define CTabWnd__DrawTab_x                                         0x8FAC60
#define CTabWnd__GetCurrentPage_x                                  0x8FB250
#define CTabWnd__GetPageInnerRect_x                                0x8FA950
#define CTabWnd__GetTabInnerRect_x                                 0x8FAB50
#define CTabWnd__GetTabRect_x                                      0x8FAA20
#define CTabWnd__InsertPage_x                                      0x8FB900
#define CTabWnd__SetPage_x                                         0x8FB280
#define CTabWnd__SetPageRect_x                                     0x8FB550
#define CTabWnd__UpdatePage_x                                      0x8FB8A0
#define CTabWnd__GetPageFromTabIndex_x                             0x8FABB0
#define CTabWnd__GetCurrentTabIndex_x                              0x8FA8E0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E6AB0
#define CPageWnd__SetTabText_x                                     0x907A60

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436DC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D74C0
#define CTextureFont__GetTextExtent_x                              0x8D7220

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63DEB0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903E50

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BCD90

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x8B2490
#define CXStr__CXStr3_x                                            0x89FF60
#define CXStr__dCXStr_x                                            0x7A3C50
#define CXStr__operator_equal_x                                    0x8A00D0
#define CXStr__operator_equal1_x                                   0x8A0120
#define CXStr__operator_plus_equal1_x                              0x8A1220

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D4FC0
#define CXWnd__BringToTop_x                                        0x8CC240
#define CXWnd__Center_x                                            0x8D22E0
#define CXWnd__ClrFocus_x                                          0x8CBE10
#define CXWnd__Destroy_x                                           0x8D2DC0
#define CXWnd__DoAllDrawing_x                                      0x8D1F30
#define CXWnd__DrawChildren_x                                      0x8D20D0
#define CXWnd__DrawColoredRect_x                                   0x8CC620
#define CXWnd__DrawTooltip_x                                       0x8CC8C0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D0EE0
#define CXWnd__GetBorderFrame_x                                    0x8CCCC0
#define CXWnd__GetChildWndAt_x                                     0x8D2CB0
#define CXWnd__GetClientClipRect_x                                 0x8CCAD0
#define CXWnd__GetScreenClipRect_x                                 0x8D15E0
#define CXWnd__GetScreenRect_x                                     0x8CCE70
#define CXWnd__GetTooltipRect_x                                    0x8CC750
#define CXWnd__GetWindowTextA_x                                    0x426F30
#define CXWnd__IsActive_x                                          0x8C7870
#define CXWnd__IsDescendantOf_x                                    0x8CCC10
#define CXWnd__IsReallyVisible_x                                   0x8CFF30
#define CXWnd__IsType_x                                            0x8D2350
#define CScreenPieceTemplate__IsType_x                             0x9005C0
#define CXWnd__Move_x                                              0x8CF640
#define CXWnd__Move1_x                                             0x8D1BF0
#define CXWnd__ProcessTransition_x                                 0x8CC1F0
#define CXWnd__Refade_x                                            0x8CBFC0
#define CXWnd__Resize_x                                            0x8CCF30
#define CXWnd__Right_x                                             0x8D13E0
#define CXWnd__SetFocus_x                                          0x8CE7C0
#define CXWnd__SetFont_x                                           0x8CBE60
#define CXWnd__SetKeyTooltip_x                                     0x8CD1A0
#define CXWnd__SetMouseOver_x                                      0x8D18F0
#define CXWnd__StartFade_x                                         0x8CC290
#define CXWnd__GetChildItem_x                                      0x8D1830
#define CXWnd__SetParent_x                                         0x8D2C60

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C9100
#define CXWndManager__DrawWindows_x                                0x8C8D50
#define CXWndManager__GetKeyboardFlags_x                           0x8C73E0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C7D00
#define CXWndManager__RemoveWnd_x                                  0x8C7A00

// CDBStr
#define CDBStr__GetString_x                                        0x4BA840

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452790
#define EQ_Character__Cur_HP_x                                     0x465DE0
#define EQ_Character__Cur_Mana_x                                   0x45AD60
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B850
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443720
#define EQ_Character__GetFocusRangeModifier_x                      0x443870
#define EQ_Character__GetHPRegen_x                                 0x469820
#define EQ_Character__GetEnduranceRegen_x                          0x4653F0
#define EQ_Character__GetManaRegen_x                               0x469DC0
#define EQ_Character__Max_Endurance_x                              0x5CC020
#define EQ_Character__Max_HP_x                                     0x45D8E0
#define EQ_Character__Max_Mana_x                                   0x5CBE50
#define EQ_Character__doCombatAbility_x                            0x5C9520
#define EQ_Character__UseSkill_x                                   0x470DA0
#define EQ_Character__GetConLevel_x                                0x5BE890
#define EQ_Character__IsExpansionFlag_x                            0x4B6B50
#define EQ_Character__TotalEffect_x                                0x44F9C0
#define EQ_Character__GetPCSpellAffect_x                           0x44BBE0
#define EQ_Character__SpellDuration_x                              0x449BE0
#define EQ_Character__FindItemByRecord_x                           0x463430
#define EQ_Character__GetAdjustedSkill_x                           0x465FB0
#define EQ_Character__GetBaseSkill_x                               0x45D7C0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x873390

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D4580

//PcClient
#define PcClient__PcClient_x                                       0x5C06F0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446C60
#define CCharacterSelect__EnterWorld_x                             0x446430
#define CCharacterSelect__Quit_x                                   0x444FF0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59E8E0
#define EQ_Item__CreateItemTagString_x                             0x8535B0
#define EQ_Item__IsStackable_x                                     0x8488E0
#define EQ_Item__GetImageNum_x                                     0x84B3B0
#define EQ_Item__CreateItemClient_x                                0x59F9B0
#define EQ_Item__GetItemValue_x                                    0x852000
#define EQ_Item__ValueSellMerchant_x                               0x855090
#define EQ_Item__IsKeyRingItem_x                                   0x849390
#define EQ_Item__CanGoInBag_x                                      0x59EA70
#define EQ_Item__GetMaxItemCount_x                                 0x8487D0
#define EQ_Item__GetHeldItem_x                                     0x84A1D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x854EB0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DAA20
#define EQ_LoadingS__Array_x                                       0xC0BC78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CE540
#define EQ_PC__GetAlternateAbilityId_x                             0x85D430
#define EQ_PC__GetCombatAbility_x                                  0x85D4C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8580F0
#define EQ_PC__GetItemRecastTimer_x                                0x5C7CD0
#define EQ_PC__HasLoreItem_x                                       0x5C1EB0
#define EQ_PC__AlertInventoryChanged_x                             0x5BE840
#define EQ_PC__GetPcZoneClient_x                                   0x5E8B80
#define EQ_PC__RemoveMyAffect_x                                    0x5C7130
#define EQ_PC__GetKeyRingItems_x                                   0x858510
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86B170
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85F3D0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5269F0
#define EQItemList__add_object_x                                   0x553DE0
#define EQItemList__add_item_x                                     0x526930
#define EQItemList__delete_item_x                                  0x526DE0
#define EQItemList__FreeItemList_x                                 0x526CE0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9B40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D4320
#define EQPlayer__dEQPlayer_x                                      0x5DCA00
#define EQPlayer__DoAttack_x                                       0x5EE510
#define EQPlayer__EQPlayer_x                                       0x5DF130
#define EQPlayer__SetNameSpriteState_x                             0x5D9830
#define EQPlayer__SetNameSpriteTint_x                              0x5D5740
#define PlayerBase__HasProperty_j_x                                0x931AC0
#define EQPlayer__IsTargetable_x                                   0x931D60
#define EQPlayer__CanSee_x                                         0x9322C0
#define PlayerZoneClient__ChangeHeight_x                           0x5EE3D0
#define EQPlayer__CanSee1_x                                        0x9323B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x932050

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8D30
#define PlayerZoneClient__IsValidTeleport_x                        0x554680
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2C40


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E31A0
#define EQPlayerManager__GetSpawnByName_x                          0x5E3600
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E31D0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4ED0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4F10
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4AC0
#define KeypressHandler__HandleKeyDown_x                           0x5A33E0
#define KeypressHandler__HandleKeyUp_x                             0x5A3700
#define KeypressHandler__SaveKeymapping_x                          0x5A4B90

// MapViewMap 
#define MapViewMap__Clear_x                                        0x712CF0
#define MapViewMap__SaveEx_x                                       0x716020

#define PlayerPointManager__GetAltCurrency_x                       0x871370

// StringTable 
#define StringTable__getString_x                                   0x86B4A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CBAB0
#define PcZoneClient__RemovePetEffect_x                            0x5C81A0
#define PcZoneClient__HasAlternateAbility_x                        0x5C8B40
#define PcZoneClient__GetCurrentMod_x                              0x45CD90
#define PcZoneClient__GetModCap_x                                  0x45A4C0
#define PcZoneClient__CanEquipItem_x                               0x5C9060
#define PcZoneClient__GetItemByID_x                                0x5CD8C0
#define PcZoneClient__GetItemByItemClass_x                         0x5CE460
#define PcZoneClient__RemoveBuffEffect_x                           0x5C73E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B7C0

//IconCache
#define IconCache__GetIcon_x                                       0x6AFA10

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A6940
#define CContainerMgr__CloseContainer_x                            0x6A7160

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x773C60

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5979C0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4F80
#define EQ_Spell__SpellAffects_x                                   0x4F2170
#define EQ_Spell__SpellAffectBase_x                           0x4F21E0
#define CharacterZoneClient__CalcAffectChange_x                    0x44BA70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AD10
#define CLootWnd__LootAll_x                                        0x708630
#define CLootWnd__RequestLootSlot_x                                0x708E40
#define EQ_Spell__IsStackable_x                                    0x449600
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4496B0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43ED20
#define EQ_Spell__IsSPAStacking_x                                  0x4F1CE0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2D80
#define EQ_Spell__IsNoRemove_x                                     0x434DF0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1D00

#define __IsResEffectSpell_x                                       0x449730

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87D020

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BB8F0
#define CTargetWnd__WndNotification_x                              0x7BB3E0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BBAD0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C0A10

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED7B0
#define EqSoundManager__PlayScriptMp3_x                            0x4EF250

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8C30

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EB320
#define CSidlManager__FindAnimation1_x                             0x8E05B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E22A0
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2250
#define CAltAbilityData__GetMaxRank_x                              0x4D6AF0

//CTargetRing
#define CTargetRing__Cast_x                                        0x595600

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4594D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4755C0
#define CharacterBase__CreateItemIndex_x                           0x520000
#define CharacterBase__GetItemPossession_x                         0x4444C0
#define CharacterBase__GetItemByGlobalIndex_x                      0x880E70
#define CharacterBase__GetEffectId_x                               0x459490

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68F7B0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68EF10

//messages
#define msg_spell_worn_off_x                                       0x4FCA10
#define msg_new_text_x                                             0x506190
#define msgTokenTextParam_x                                        0x502990

//SpellManager
#define SpellManager__vftable_x                                    0xAC9280
#define SpellManager__SpellManager_x                               0x47E220
#define Spellmanager__LoadTextSpells_x                             0x60C480

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935EA0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488150
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EC40
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449350
#define ItemGlobalIndex__IsValidIndex_x                            0x458DA0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87ECE0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87DC20

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7014D0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AB640
#define CCursorAttachment__Deactivate_x                            0x6AAB90

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FCE80
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FD000

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x6040C0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C9A0

//IString
#define IString__Append_x                                          0x47EEA0

//Camera
#define CDisplay__cameraType_x                                     0xE6F7E0
#define EverQuest__Cameras_x                                       0xF31AE0
