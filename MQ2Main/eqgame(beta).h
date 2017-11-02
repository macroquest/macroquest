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
#define __ExpectedVersionDate                                     "Nov  2 2017"
#define __ExpectedVersionTime                                     "04:16:16"
#define __ActualVersionDate_x                                      0xAE4098
#define __ActualVersionTime_x                                      0xAE40A4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AAEB0
#define __MemChecker1_x                                            0x8A3A20
#define __MemChecker2_x                                            0x640FF0
#define __MemChecker3_x                                            0x640F40
#define __MemChecker4_x                                            0x7F56E0
#define __EncryptPad0_x                                            0xC3F000
#define __EncryptPad1_x                                            0xD18BB8
#define __EncryptPad2_x                                            0xC67EE8
#define __EncryptPad3_x                                            0xC67AE8
#define __EncryptPad4_x                                            0xD071B8
#define __EncryptPad5_x                                            0x10C22F0
#define __AC1_x                                                    0x7B4475
#define __AC2_x                                                    0x5641F7
#define __AC3_x                                                    0x562370
#define __AC4_x                                                    0x574591
#define __AC5_x                                                    0x5882DB
#define __AC6_x                                                    0x58BE8E
#define __AC7_x                                                    0x5828DC
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
#define __do_loot_x                                                0x532F30
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
#define __CastRay_x                                                0x54AA30
#define __CastRay2_x                                               0x54A360
#define __HeadingDiff_x                                            0x9336C0
#define __FixHeading_x                                             0x933650
#define __get_bearing_x                                            0x53A080
#define __ConvertItemTags_x                                        0x537B50
#define __ExecuteCmd_x                                             0x522470
#define __EQGetTime_x                                              0x8A33C0
#define __get_melee_range_x                                        0x529130
#define __GetGaugeValueFromEQ_x                                    0x7B3030
#define __GetLabelFromEQ_x                                         0x7B4400
#define __ToggleKeyRingItem_x                                      0x48FE60
#define __GetXTargetType_x                                         0x9352C0
#define __LoadFrontEnd_x                                           0x6406C0
#define __NewUIINI_x                                               0x7B2A00
#define __ProcessGameEvents_x                                      0x584670
#define __ProcessMouseEvent_x                                      0x583E10
#define CrashDetected_x                                            0x642080
#define wwsCrashReportCheckForUploader_x                           0x801370
#define __AppCrashWrapper_x                                        0xC67ADC
#define __pCrashHandler_x                                          0x10D7A10
#define __CrashHandler_x                                           0x800DD0
#define wwsCrashReportPlatformLaunchUploader_x                     0x803570
#define DrawNetStatus_x                                            0x5BA960
#define Util__FastTime_x                                           0x8A3060
#define Expansion_HoT_x                                            0xF317C8
#define __HelpPath_x                                               0xFB4F78
#define __STMLToText_x                                             0x8E9550
#define __GetAnimationCache_x                                      0x6AFE50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4235F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E270
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41E040

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8250
#define AltAdvManager__IsAbilityReady_x                            0x4D82C0
#define AltAdvManager__GetAAById_x                                 0x4D87B0
#define AltAdvManager__CanTrainAbility_x                           0x4D93E0
#define AltAdvManager__CanSeeAbility_x                             0x4D8FA0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x469C50
#define CharacterZoneClient__HasSkill_x                            0x465CC0
#define CharacterZoneClient__MakeMeVisible_x                       0x46B7C0
#define CharacterZoneClient__IsStackBlocked_x                      0x44BE20
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B340
#define CharacterZoneClient__GetItemCountWorn_x                    0x464220
#define CharacterZoneClient__GetItemCountInInventory_x             0x464300
#define CharacterZoneClient__GetCursorItemCount_x                  0x4643E0
#define CharacterZoneClient__FindAffectSlot_x                      0x4514A0
#define CharacterZoneClient__BardCastBard_x                        0x44AAB0
#define CharacterZoneClient__GetMaxEffects_x                       0x449640
#define CharacterZoneClient__GetEffect_x                           0x44B570
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451300
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449990
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FE50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66FF90

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67DC70

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x599710
#define CButtonWnd__CButtonWnd_x                                   0x8DD880

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x698FF0
#define CChatManager__InitContextMenu_x                            0x69A140
#define CChatManager__FreeChatWindow_x                             0x698AA0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A2260
#define CChatManager__SetLockedActiveChatWindow_x                  0x698FC0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E78A0
#define CContextMenu__dCContextMenu_x                              0x8E7AB0
#define CContextMenu__AddMenuItem_x                                0x8E7FD0
#define CContextMenu__RemoveMenuItem_x                             0x8E7C30
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7C50
#define CContextMenu__CheckMenuItem_x                              0x8E7CD0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D3E90
#define CContextMenuManager__RemoveMenu_x                          0x8D4230
#define CContextMenuManager__PopupMenu_x                           0x8D4680
#define CContextMenuManager__Flush_x                               0x8D3F00
#define CContextMenuManager__GetMenu_x                             0x419790

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x887370
#define CChatService__GetFriendName_x                              0x887380

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69FD50
#define CChatWindow__Clear_x                                       0x69F640
#define CChatWindow__WndNotification_x                             0x6A0650

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D7CE0
#define CComboWnd__Draw_x                                          0x8D7EF0
#define CComboWnd__GetCurChoice_x                                  0x8D7A90
#define CComboWnd__GetListRect_x                                   0x8D8190
#define CComboWnd__GetTextRect_x                                   0x8D7D50
#define CComboWnd__InsertChoice_x                                  0x8D82F0
#define CComboWnd__SetColors_x                                     0x8D7A20
#define CComboWnd__SetChoice_x                                     0x8D7A50
#define CComboWnd__GetItemCount_x                                  0x8D7A80
#define CComboWnd__GetCurChoiceText_x                              0x8D7AD0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A9FE0
#define CContainerWnd__vftable_x                                   0xAED9A8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C60A0
#define CDisplay__GetClickedActor_x                                0x4BE960
#define CDisplay__GetUserDefinedColor_x                            0x4BD540
#define CDisplay__GetWorldFilePath_x                               0x4BC990
#define CDisplay__is3dON_x                                         0x4BBE20
#define CDisplay__ReloadUI_x                                       0x4CFE60
#define CDisplay__WriteTextHD2_x                                   0x4C2430
#define CDisplay__TrueDistance_x                                   0x4BF590

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FE9F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EBE00
#define CEditWnd__GetCharIndexPt_x                                 0x8ECF60
#define CEditWnd__GetDisplayString_x                               0x8EBFB0
#define CEditWnd__GetHorzOffset_x                                  0x8EC2F0
#define CEditWnd__GetLineForPrintableChar_x                        0x8ECA20
#define CEditWnd__GetSelStartPt_x                                  0x8ED220
#define CEditWnd__GetSTMLSafeText_x                                0x8EC490
#define CEditWnd__PointFromPrintableChar_x                         0x8ECB10
#define CEditWnd__SelectableCharFromPoint_x                        0x8ECC90
#define CEditWnd__SetEditable_x                                    0x8EC460

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56ADC0
#define CEverQuest__ClickedPlayer_x                                0x564940
#define CEverQuest__CreateTargetIndicator_x                        0x565840
#define CEverQuest__DeleteTargetIndicator_x                        0x5658C0
#define CEverQuest__DoTellWindow_x                                 0x4763E0
#define CEverQuest__OutputTextToLog_x                              0x476040
#define CEverQuest__DropHeldItemOnGround_x                         0x57B330
#define CEverQuest__dsp_chat_x                                     0x476720
#define CEverQuest__trimName_x                                     0x561250
#define CEverQuest__Emote_x                                        0x579640
#define CEverQuest__EnterZone_x                                    0x574720
#define CEverQuest__GetBodyTypeDesc_x                              0x55EC90
#define CEverQuest__GetClassDesc_x                                 0x5681E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5687E0
#define CEverQuest__GetDeityDesc_x                                 0x55F570
#define CEverQuest__GetLangDesc_x                                  0x55F020
#define CEverQuest__GetRaceDesc_x                                  0x5689A0
#define CEverQuest__InterpretCmd_x                                 0x56C540
#define CEverQuest__LeftClickedOnPlayer_x                          0x580E80
#define CEverQuest__LMouseUp_x                                     0x582E30
#define CEverQuest__RightClickedOnPlayer_x                         0x581990
#define CEverQuest__RMouseUp_x                                     0x582890
#define CEverQuest__SetGameState_x                                 0x565210
#define CEverQuest__UPCNotificationFlush_x                         0x55D620
#define CEverQuest__IssuePetCommand_x                              0x56CF20

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BACE0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BAD40
#define CGaugeWnd__Draw_x                                          0x6BB170

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B2A0
#define CGuild__GetGuildName_x                                     0x43B770
#define CGuild__GetGuildIndex_x                                    0x43C980

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D7210

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E45E0
#define CInvSlotMgr__MoveItem_x                                    0x6E4DA0
#define CInvSlotMgr__SelectSlot_x                                  0x6E3ED0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E3330
#define CInvSlot__SliderComplete_x                                 0x6E0B50
#define CInvSlot__GetItemBase_x                                    0x6DFFD0
#define CInvSlot__UpdateItem_x                                     0x6E0550

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E61D0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E7300

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AEF30
#define CItemDisplayWnd__UpdateStrings_x                           0x6E83D0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F4FC0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F54E0
#define CItemDisplayWnd__SetItem_x                                 0x6FACF0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E6060

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EE960

// CLabel 
#define CLabel__Draw_x                                             0x701AC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C39A0
#define CListWnd__dCListWnd_x                                      0x8C4C30
#define CListWnd__AddColumn_x                                      0x8C4BD0
#define CListWnd__AddColumn1_x                                     0x8C4270
#define CListWnd__AddLine_x                                        0x8C3C50
#define CListWnd__AddString_x                                      0x8C3E70
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C0AD0
#define CListWnd__CalculateVSBRange_x                              0x8C2E70
#define CListWnd__ClearSel_x                                       0x8BFDE0
#define CListWnd__ClearAllSel_x                                    0x8BFD90
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C3830
#define CListWnd__Compare_x                                        0x8C17B0
#define CListWnd__Draw_x                                           0x8C2A70
#define CListWnd__DrawColumnSeparators_x                           0x8C2900
#define CListWnd__DrawHeader_x                                     0x8C00A0
#define CListWnd__DrawItem_x                                       0x8C1E30
#define CListWnd__DrawLine_x                                       0x8C25A0
#define CListWnd__DrawSeparator_x                                  0x8C29A0
#define CListWnd__EnableLine_x                                     0x8BFFC0
#define CListWnd__EnsureVisible_x                                  0x8C0C30
#define CListWnd__ExtendSel_x                                      0x8C1D40
#define CListWnd__GetColumnMinWidth_x                              0x8BF6D0
#define CListWnd__GetColumnWidth_x                                 0x8BF600
#define CListWnd__GetCurSel_x                                      0x8BEDE0
#define CListWnd__GetItemAtPoint_x                                 0x8C0ED0
#define CListWnd__GetItemAtPoint1_x                                0x8C0F40
#define CListWnd__GetItemData_x                                    0x8BF110
#define CListWnd__GetItemHeight_x                                  0x8C0720
#define CListWnd__GetItemIcon_x                                    0x8BF300
#define CListWnd__GetItemRect_x                                    0x8C0D10
#define CListWnd__GetItemText_x                                    0x8BF1B0
#define CListWnd__GetSelList_x                                     0x8C4160
#define CListWnd__GetSeparatorRect_x                               0x8C16D0
#define CListWnd__InsertLine_x                                     0x8C4050
#define CListWnd__RemoveLine_x                                     0x8C4060
#define CListWnd__SetColors_x                                      0x8BEF30
#define CListWnd__SetColumnJustification_x                         0x8BF960
#define CListWnd__SetColumnWidth_x                                 0x8BF680
#define CListWnd__SetCurSel_x                                      0x8BEE20
#define CListWnd__SetItemColor_x                                   0x8C3520
#define CListWnd__SetItemData_x                                    0x8BFE40
#define CListWnd__SetItemText_x                                    0x8C3360
#define CListWnd__ShiftColumnSeparator_x                           0x8C31F0
#define CListWnd__Sort_x                                           0x8C4D30
#define CListWnd__ToggleSel_x                                      0x8BFD10

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71AB10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73E2C0
#define CMerchantWnd__RequestBuyItem_x                             0x7479B0
#define CMerchantWnd__RequestSellItem_x                            0x74A0E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x73E8C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73B6F0
#define CMerchantWnd__ActualSelect_x                               0x73F700

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8557B0
#define CPacketScrambler__hton_x                                   0x8557C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E27F0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E28D0
#define CSidlManager__CreateLabel_x                                0x7A3ED0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E0DA0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E2BB0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D9D10
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D9C10
#define CSidlScreenWnd__ConvertToRes_x                             0x8FE8D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DA620
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DB7E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DB890
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DAD80
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D9FD0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D9740
#define CSidlScreenWnd__GetSidlPiece_x                             0x8DA1C0
#define CSidlScreenWnd__Init1_x                                    0x8DB4D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DA6D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D9900
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DAFC0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D9390
#define CSidlScreenWnd__StoreIniVis_x                              0x8D96F0
#define CSidlScreenWnd__WndNotification_x                          0x8DB250
#define CSidlScreenWnd__GetChildItem_x                             0x8D9810
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CD190
#define CSidlScreenWnd__m_layoutCopy_x                             0x1730E50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x605E70
#define CSkillMgr__GetSkillCap_x                                   0x606050
#define CSkillMgr__GetNameToken_x                                  0x605A20

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FDB90
#define CSliderWnd__SetValue_x                                     0x8FDD60
#define CSliderWnd__SetNumTicks_x                                  0x8FE4E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7AA180

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F7880
#define CStmlWnd__CalculateHSBRange_x                              0x8EFDE0
#define CStmlWnd__CalculateVSBRange_x                              0x8EFD50
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EFF60
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F0760
#define CStmlWnd__ForceParseNow_x                                  0x8F8200
#define CStmlWnd__GetNextTagPiece_x                                0x8F0660
#define CStmlWnd__GetSTMLText_x                                    0x4845B0
#define CStmlWnd__GetVisibleText_x                                 0x8F11B0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F3780
#define CStmlWnd__MakeStmlColorTag_x                               0x8EF030
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EF090
#define CStmlWnd__SetSTMLText_x                                    0x8F4FD0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F7520
#define CStmlWnd__UpdateHistoryString_x                            0x8F20F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FB710
#define CTabWnd__DrawCurrentPage_x                                 0x8FAFA0
#define CTabWnd__DrawTab_x                                         0x8FAD60
#define CTabWnd__GetCurrentPage_x                                  0x8FB350
#define CTabWnd__GetPageInnerRect_x                                0x8FAA50
#define CTabWnd__GetTabInnerRect_x                                 0x8FAC50
#define CTabWnd__GetTabRect_x                                      0x8FAB20
#define CTabWnd__InsertPage_x                                      0x8FBA00
#define CTabWnd__SetPage_x                                         0x8FB380
#define CTabWnd__SetPageRect_x                                     0x8FB650
#define CTabWnd__UpdatePage_x                                      0x8FB9A0
#define CTabWnd__GetPageFromTabIndex_x                             0x8FACB0
#define CTabWnd__GetCurrentTabIndex_x                              0x8FA9E0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E74B0
#define CPageWnd__SetTabText_x                                     0x907C10

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436E20

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D7690
#define CTextureFont__GetTextExtent_x                              0x8D73F0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63E960

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x904050

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BCEA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029C0
#define CXStr__CXStr1_x                                            0x443F10
#define CXStr__CXStr3_x                                            0x8A02B0
#define CXStr__dCXStr_x                                            0x5A76B0
#define CXStr__operator_equal_x                                    0x8A0420
#define CXStr__operator_equal1_x                                   0x8A0470
#define CXStr__operator_plus_equal1_x                              0x8A1570

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D5190
#define CXWnd__BringToTop_x                                        0x8CC390
#define CXWnd__Center_x                                            0x8D24F0
#define CXWnd__ClrFocus_x                                          0x8CBF60
#define CXWnd__Destroy_x                                           0x8D2FB0
#define CXWnd__DoAllDrawing_x                                      0x8D2150
#define CXWnd__DrawChildren_x                                      0x8D22F0
#define CXWnd__DrawColoredRect_x                                   0x8CC770
#define CXWnd__DrawTooltip_x                                       0x8CCA20
#define CXWnd__DrawTooltipAtPoint_x                                0x8D10E0
#define CXWnd__GetBorderFrame_x                                    0x8CCE80
#define CXWnd__GetChildWndAt_x                                     0x8D2EA0
#define CXWnd__GetClientClipRect_x                                 0x8CCC40
#define CXWnd__GetScreenClipRect_x                                 0x8D17E0
#define CXWnd__GetScreenRect_x                                     0x8CD030
#define CXWnd__GetTooltipRect_x                                    0x8CC8B0
#define CXWnd__GetWindowTextA_x                                    0x427180
#define CXWnd__IsActive_x                                          0x8C79A0
#define CXWnd__IsDescendantOf_x                                    0x8CCDD0
#define CXWnd__IsReallyVisible_x                                   0x8D0110
#define CXWnd__IsType_x                                            0x8D2560
#define CScreenPieceTemplate__IsType_x                             0x900760
#define CXWnd__Move_x                                              0x8CF810
#define CXWnd__Move1_x                                             0x8D1E10
#define CXWnd__ProcessTransition_x                                 0x8CC340
#define CXWnd__Refade_x                                            0x8CC110
#define CXWnd__Resize_x                                            0x8CD0F0
#define CXWnd__Right_x                                             0x8D15E0
#define CXWnd__SetFocus_x                                          0x8CE960
#define CXWnd__SetFont_x                                           0x8CBFB0
#define CXWnd__SetKeyTooltip_x                                     0x8CD360
#define CXWnd__SetMouseOver_x                                      0x8D1B00
#define CXWnd__StartFade_x                                         0x8CC3E0
#define CXWnd__GetChildItem_x                                      0x8D1A50
#define CXWnd__SetParent_x                                         0x8D2E50

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C9230
#define CXWndManager__DrawWindows_x                                0x8C8E80
#define CXWndManager__GetKeyboardFlags_x                           0x8C7510
#define CXWndManager__HandleKeyboardMsg_x                          0x8C7E40
#define CXWndManager__RemoveWnd_x                                  0x8C7B30

// CDBStr
#define CDBStr__GetString_x                                        0x4BA650

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452660
#define EQ_Character__Cur_HP_x                                     0x4658A0
#define EQ_Character__Cur_Mana_x                                   0x45AD00
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B650
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443590
#define EQ_Character__GetFocusRangeModifier_x                      0x4436E0
#define EQ_Character__GetHPRegen_x                                 0x4692E0
#define EQ_Character__GetEnduranceRegen_x                          0x464EB0
#define EQ_Character__GetManaRegen_x                               0x469880
#define EQ_Character__Max_Endurance_x                              0x5CC900
#define EQ_Character__Max_HP_x                                     0x45D880
#define EQ_Character__Max_Mana_x                                   0x5CC730
#define EQ_Character__doCombatAbility_x                            0x5C9E00
#define EQ_Character__UseSkill_x                                   0x470860
#define EQ_Character__GetConLevel_x                                0x5BEFB0
#define EQ_Character__IsExpansionFlag_x                            0x4B69D0
#define EQ_Character__TotalEffect_x                                0x44F790
#define EQ_Character__GetPCSpellAffect_x                           0x44B9E0
#define EQ_Character__SpellDuration_x                              0x4499E0
#define EQ_Character__FindItemByRecord_x                           0x462F10
#define EQ_Character__GetAdjustedSkill_x                           0x465A70
#define EQ_Character__GetBaseSkill_x                               0x45D760

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x873580

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D4E80

//PcClient
#define PcClient__PcClient_x                                       0x5C0DE0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446A90
#define CCharacterSelect__EnterWorld_x                             0x446260
#define CCharacterSelect__Quit_x                                   0x444E20

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59F0B0
#define EQ_Item__CreateItemTagString_x                             0x853920
#define EQ_Item__IsStackable_x                                     0x848EA0
#define EQ_Item__GetImageNum_x                                     0x84B900
#define EQ_Item__CreateItemClient_x                                0x5A0180
#define EQ_Item__GetItemValue_x                                    0x852390
#define EQ_Item__ValueSellMerchant_x                               0x855400
#define EQ_Item__IsKeyRingItem_x                                   0x849930
#define EQ_Item__CanGoInBag_x                                      0x59F240
#define EQ_Item__GetMaxItemCount_x                                 0x848D90
#define EQ_Item__GetHeldItem_x                                     0x84A720
#define EQ_Item__GetAugmentFitBySlot_x                             0x855230

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA7F0
#define EQ_LoadingS__Array_x                                       0xC0BC78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CEE30
#define EQ_PC__GetAlternateAbilityId_x                             0x85D780
#define EQ_PC__GetCombatAbility_x                                  0x85D810
#define EQ_PC__GetCombatAbilityTimer_x                             0x858460
#define EQ_PC__GetItemRecastTimer_x                                0x5C85B0
#define EQ_PC__HasLoreItem_x                                       0x5C25A0
#define EQ_PC__AlertInventoryChanged_x                             0x5BEF60
#define EQ_PC__GetPcZoneClient_x                                   0x5E9580
#define EQ_PC__RemoveMyAffect_x                                    0x5C7A10
#define EQ_PC__GetKeyRingItems_x                                   0x858880
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86B480
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85F6F0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5271C0
#define EQItemList__add_object_x                                   0x554510
#define EQItemList__add_item_x                                     0x527100
#define EQItemList__delete_item_x                                  0x5275B0
#define EQItemList__FreeItemList_x                                 0x5274B0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9900

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D4C20
#define EQPlayer__dEQPlayer_x                                      0x5DD2F0
#define EQPlayer__DoAttack_x                                       0x5EEF10
#define EQPlayer__EQPlayer_x                                       0x5DFA10
#define EQPlayer__SetNameSpriteState_x                             0x5DA120
#define EQPlayer__SetNameSpriteTint_x                              0x5D6040
#define PlayerBase__HasProperty_j_x                                0x931A80
#define EQPlayer__IsTargetable_x                                   0x931D20
#define EQPlayer__CanSee_x                                         0x932280
#define PlayerZoneClient__ChangeHeight_x                           0x5EEDD0
#define EQPlayer__CanSee1_x                                        0x932370
#define PlayerBase__GetVisibilityLineSegment_x                     0x932010

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E9730
#define PlayerZoneClient__IsValidTeleport_x                        0x554DB0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2A50


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E3BC0
#define EQPlayerManager__GetSpawnByName_x                          0x5E4020
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E3BF0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A5690
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A56D0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A5280
#define KeypressHandler__HandleKeyDown_x                           0x5A3BA0
#define KeypressHandler__HandleKeyUp_x                             0x5A3EC0
#define KeypressHandler__SaveKeymapping_x                          0x5A5350

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7134A0
#define MapViewMap__SaveEx_x                                       0x7167D0

#define PlayerPointManager__GetAltCurrency_x                       0x871630

// StringTable 
#define StringTable__getString_x                                   0x86B7B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CC390
#define PcZoneClient__RemovePetEffect_x                            0x5C8A80
#define PcZoneClient__HasAlternateAbility_x                        0x5C9420
#define PcZoneClient__GetCurrentMod_x                              0x45CD30
#define PcZoneClient__GetModCap_x                                  0x45A460
#define PcZoneClient__CanEquipItem_x                               0x5C9940
#define PcZoneClient__GetItemByID_x                                0x5CE1A0
#define PcZoneClient__GetItemByItemClass_x                         0x5CED50
#define PcZoneClient__RemoveBuffEffect_x                           0x5C7CC0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55BF00

//IconCache
#define IconCache__GetIcon_x                                       0x6B0480

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A7380
#define CContainerMgr__CloseContainer_x                            0x6A7BA0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x773F00

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x598140

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4DD0
#define EQ_Spell__SpellAffects_x                                   0x4F1FC0
#define EQ_Spell__SpellAffectBase_x                           0x4F2030
#define CharacterZoneClient__CalcAffectChange_x                    0x44B870
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AB10
#define CLootWnd__LootAll_x                                        0x708E70
#define CLootWnd__RequestLootSlot_x                                0x709680
#define EQ_Spell__IsStackable_x                                    0x449400
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4494B0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43ED80
#define EQ_Spell__IsSPAStacking_x                                  0x4F1B30
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2BD0
#define EQ_Spell__IsNoRemove_x                                     0x434E50
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1B50

#define __IsResEffectSpell_x                                       0x449530

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87D200

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BBA70
#define CTargetWnd__WndNotification_x                              0x7BB560
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BBC50

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C0BA0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED6A0
#define EqSoundManager__PlayScriptMp3_x                            0x4EF140

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8AA0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EB430
#define CSidlManager__FindAnimation1_x                             0x8E07D0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E20E0
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2090
#define CAltAbilityData__GetMaxRank_x                              0x4D6900

//CTargetRing
#define CTargetRing__Cast_x                                        0x595D80

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459440
#define CharacterBase__CreateItemGlobalIndex_x                     0x4755E0
#define CharacterBase__CreateItemIndex_x                           0x520820
#define CharacterBase__GetItemPossession_x                         0x4442F0
#define CharacterBase__GetItemByGlobalIndex_x                      0x881060
#define CharacterBase__GetEffectId_x                               0x459400

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x690190
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68F8F0

//messages
#define msg_spell_worn_off_x                                       0x4FC860
#define msg_new_text_x                                             0x505FF0
#define msgTokenTextParam_x                                        0x5027F0

//SpellManager
#define SpellManager__vftable_x                                    0xAC9290
#define SpellManager__SpellManager_x                               0x47E220
#define Spellmanager__LoadTextSpells_x          0x60CD50

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935DE0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487EF0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EC90
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4491A0
#define ItemGlobalIndex__IsValidIndex_x                            0x458CB0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87EEC0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87DE00

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x701D10

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AC0A0
#define CCursorAttachment__Deactivate_x                            0x6AB5F0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FD090
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FD210

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x604900

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C740

//IString
#define IString__Append_x                                          0x47EEA0

//Camera
#define CDisplay__cameraType_x                                     0xE6F7E0
#define EverQuest__Cameras_x                                       0xF31AE0
