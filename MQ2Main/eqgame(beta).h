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
#define __ExpectedVersionDate                                     "Nov  5 2017"
#define __ExpectedVersionTime                                     "03:22:07"
#define __ActualVersionDate_x                                      0xAE4100
#define __ActualVersionTime_x                                      0xAE410C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AAA70
#define __MemChecker1_x                                            0x8A3080
#define __MemChecker2_x                                            0x640770
#define __MemChecker3_x                                            0x6406C0
#define __MemChecker4_x                                            0x7F50C0
#define __EncryptPad0_x                                            0xC3F000
#define __EncryptPad1_x                                            0xD18BB8
#define __EncryptPad2_x                                            0xC67EE8
#define __EncryptPad3_x                                            0xC67AE8
#define __EncryptPad4_x                                            0xD071B8
#define __EncryptPad5_x                                            0x10C22F0
#define __AC1_x                                                    0x7B4065
#define __AC2_x                                                    0x563DA7
#define __AC3_x                                                    0x561F20
#define __AC4_x                                                    0x5740E1
#define __AC5_x                                                    0x587E3B
#define __AC6_x                                                    0x58B9DE
#define __AC7_x                                                    0x58243C
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
#define __do_loot_x                                                0x532BD0
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
#define __CastRay_x                                                0x54A6E0
#define __CastRay2_x                                               0x54A010
#define __HeadingDiff_x                                            0x9332A0
#define __FixHeading_x                                             0x933230
#define __get_bearing_x                                            0x539D20
#define __ConvertItemTags_x                                        0x5377F0
#define __ExecuteCmd_x                                             0x522170
#define __EQGetTime_x                                              0x8A2A20
#define __get_melee_range_x                                        0x528DF0
#define __GetGaugeValueFromEQ_x                                    0x7B2C20
#define __GetLabelFromEQ_x                                         0x7B3FF0
#define __ToggleKeyRingItem_x                                      0x490360
#define __GetXTargetType_x                                         0x934EA0
#define __LoadFrontEnd_x                                           0x63FE40
#define __NewUIINI_x                                               0x7B2600
#define __ProcessGameEvents_x                                      0x5841D0
#define __ProcessMouseEvent_x                                      0x583970
#define CrashDetected_x                                            0x641800
#define wwsCrashReportCheckForUploader_x                           0x800C00
#define __AppCrashWrapper_x                                        0xC67ADC
#define __pCrashHandler_x                                          0x10D7A10
#define __CrashHandler_x                                           0x800690
#define wwsCrashReportPlatformLaunchUploader_x                     0x802E30
#define DrawNetStatus_x                                            0x5BA680
#define Util__FastTime_x                                           0x8A26C0
#define Expansion_HoT_x                                            0xF317C8
#define __HelpPath_x                                               0xFB4F78
#define __STMLToText_x                                             0x8E9110
#define __GetAnimationCache_x                                      0x6AF520

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423550
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E1B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DF80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D85E0
#define AltAdvManager__IsAbilityReady_x                            0x4D8650
#define AltAdvManager__GetAAById_x                                 0x4D8B40
#define AltAdvManager__CanTrainAbility_x                           0x4D9770
#define AltAdvManager__CanSeeAbility_x                             0x4D9330

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x469E90
#define CharacterZoneClient__HasSkill_x                            0x465F00
#define CharacterZoneClient__MakeMeVisible_x                       0x46BA00
#define CharacterZoneClient__IsStackBlocked_x                      0x44C0D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B5F0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464460
#define CharacterZoneClient__GetItemCountInInventory_x             0x464540
#define CharacterZoneClient__GetCursorItemCount_x                  0x464620
#define CharacterZoneClient__FindAffectSlot_x                      0x451760
#define CharacterZoneClient__BardCastBard_x                        0x44AD60
#define CharacterZoneClient__GetMaxEffects_x                       0x4498F0
#define CharacterZoneClient__GetEffect_x                           0x44B820
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4515C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449C40
#define CharacterZoneClient__GetLastEffectSlot_x                   0x450110

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66F7D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67D360

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5992E0
#define CButtonWnd__CButtonWnd_x                                   0x8DD3D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6986D0
#define CChatManager__InitContextMenu_x                            0x699820
#define CChatManager__FreeChatWindow_x                             0x698180
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A19B0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6986A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E7460
#define CContextMenu__dCContextMenu_x                              0x8E7670
#define CContextMenu__AddMenuItem_x                                0x8E7B90
#define CContextMenu__RemoveMenuItem_x                             0x8E77F0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7810
#define CContextMenu__CheckMenuItem_x                              0x8E7890

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D3950
#define CContextMenuManager__RemoveMenu_x                          0x8D3CF0
#define CContextMenuManager__PopupMenu_x                           0x8D4140
#define CContextMenuManager__Flush_x                               0x8D39C0
#define CContextMenuManager__GetMenu_x                             0x4196D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886AA0
#define CChatService__GetFriendName_x                              0x886AB0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69F490
#define CChatWindow__Clear_x                                       0x69ED70
#define CChatWindow__WndNotification_x                             0x69FD90

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D77A0
#define CComboWnd__Draw_x                                          0x8D79B0
#define CComboWnd__GetCurChoice_x                                  0x8D7550
#define CComboWnd__GetListRect_x                                   0x8D7C50
#define CComboWnd__GetTextRect_x                                   0x8D7810
#define CComboWnd__InsertChoice_x                                  0x8D7DB0
#define CComboWnd__SetColors_x                                     0x8D74E0
#define CComboWnd__SetChoice_x                                     0x8D7510
#define CComboWnd__GetItemCount_x                                  0x8D7540
#define CComboWnd__GetCurChoiceText_x                              0x8D7590


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A96B0
#define CContainerWnd__vftable_x                                   0xAEDA18

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C64A0
#define CDisplay__GetClickedActor_x                                0x4BED70
#define CDisplay__GetUserDefinedColor_x                            0x4BD950
#define CDisplay__GetWorldFilePath_x                               0x4BCDA0
#define CDisplay__is3dON_x                                         0x4BC230
#define CDisplay__ReloadUI_x                                       0x4D0260
#define CDisplay__WriteTextHD2_x                                   0x4C2830
#define CDisplay__TrueDistance_x                                   0x4BF9A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FE4C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB9C0
#define CEditWnd__GetCharIndexPt_x                                 0x8ECB10
#define CEditWnd__GetDisplayString_x                               0x8EBB70
#define CEditWnd__GetHorzOffset_x                                  0x8EBEB0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC5E0
#define CEditWnd__GetSelStartPt_x                                  0x8ECDC0
#define CEditWnd__GetSTMLSafeText_x                                0x8EC050
#define CEditWnd__PointFromPrintableChar_x                         0x8EC6D0
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC850
#define CEditWnd__SetEditable_x                                    0x8EC020

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A910
#define CEverQuest__ClickedPlayer_x                                0x5644F0
#define CEverQuest__CreateTargetIndicator_x                        0x5653F0
#define CEverQuest__DeleteTargetIndicator_x                        0x565470
#define CEverQuest__DoTellWindow_x                                 0x476610
#define CEverQuest__OutputTextToLog_x                              0x476270
#define CEverQuest__DropHeldItemOnGround_x                         0x57AE80
#define CEverQuest__dsp_chat_x                                     0x476950
#define CEverQuest__trimName_x                                     0x560E00
#define CEverQuest__Emote_x                                        0x579190
#define CEverQuest__EnterZone_x                                    0x574270
#define CEverQuest__GetBodyTypeDesc_x                              0x55E840
#define CEverQuest__GetClassDesc_x                                 0x567D30
#define CEverQuest__GetClassThreeLetterCode_x                      0x568330
#define CEverQuest__GetDeityDesc_x                                 0x55F120
#define CEverQuest__GetLangDesc_x                                  0x55EBD0
#define CEverQuest__GetRaceDesc_x                                  0x5684F0
#define CEverQuest__InterpretCmd_x                                 0x56C090
#define CEverQuest__LeftClickedOnPlayer_x                          0x5809E0
#define CEverQuest__LMouseUp_x                                     0x582990
#define CEverQuest__RightClickedOnPlayer_x                         0x5814F0
#define CEverQuest__RMouseUp_x                                     0x5823F0
#define CEverQuest__SetGameState_x                                 0x564DC0
#define CEverQuest__UPCNotificationFlush_x                         0x55D1D0
#define CEverQuest__IssuePetCommand_x                              0x56CA70

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BA2F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BA350
#define CGaugeWnd__Draw_x                                          0x6BA780

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B3F0
#define CGuild__GetGuildName_x                                     0x43B8C0
#define CGuild__GetGuildIndex_x                                    0x43CAD0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D6770

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E3B20
#define CInvSlotMgr__MoveItem_x                                    0x6E42E0
#define CInvSlotMgr__SelectSlot_x                                  0x6E3420

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E2880
#define CInvSlot__SliderComplete_x                                 0x6E00A0
#define CInvSlot__GetItemBase_x                                    0x6DF520
#define CInvSlot__UpdateItem_x                                     0x6DFAA0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E5740
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E6880

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AEB60
#define CItemDisplayWnd__UpdateStrings_x                           0x6E7960
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F4500
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F4A10
#define CItemDisplayWnd__SetItem_x                                 0x6FA2E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E5C60

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EDE90

// CLabel 
#define CLabel__Draw_x                                             0x7011A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C3280
#define CListWnd__dCListWnd_x                                      0x8C4540
#define CListWnd__AddColumn_x                                      0x8C44E0
#define CListWnd__AddColumn1_x                                     0x8C3B70
#define CListWnd__AddLine_x                                        0x8C3550
#define CListWnd__AddString_x                                      0x8C3770
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C0390
#define CListWnd__CalculateVSBRange_x                              0x8C2750
#define CListWnd__ClearSel_x                                       0x8BF6A0
#define CListWnd__ClearAllSel_x                                    0x8BF650
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C3110
#define CListWnd__Compare_x                                        0x8C1080
#define CListWnd__Draw_x                                           0x8C2350
#define CListWnd__DrawColumnSeparators_x                           0x8C21E0
#define CListWnd__DrawHeader_x                                     0x8BF960
#define CListWnd__DrawItem_x                                       0x8C1710
#define CListWnd__DrawLine_x                                       0x8C1E80
#define CListWnd__DrawSeparator_x                                  0x8C2280
#define CListWnd__EnableLine_x                                     0x8BF880
#define CListWnd__EnsureVisible_x                                  0x8C04F0
#define CListWnd__ExtendSel_x                                      0x8C1620
#define CListWnd__GetColumnMinWidth_x                              0x8BEF90
#define CListWnd__GetColumnWidth_x                                 0x8BEEC0
#define CListWnd__GetCurSel_x                                      0x8BE680
#define CListWnd__GetItemAtPoint_x                                 0x8C0780
#define CListWnd__GetItemAtPoint1_x                                0x8C07F0
#define CListWnd__GetItemData_x                                    0x8BE9D0
#define CListWnd__GetItemHeight_x                                  0x8BFFE0
#define CListWnd__GetItemIcon_x                                    0x8BEBC0
#define CListWnd__GetItemRect_x                                    0x8C05C0
#define CListWnd__GetItemText_x                                    0x8BEA70
#define CListWnd__GetSelList_x                                     0x8C3A60
#define CListWnd__GetSeparatorRect_x                               0x8C0FA0
#define CListWnd__InsertLine_x                                     0x8C3950
#define CListWnd__RemoveLine_x                                     0x8C3960
#define CListWnd__SetColors_x                                      0x8BE7D0
#define CListWnd__SetColumnJustification_x                         0x8BF220
#define CListWnd__SetColumnWidth_x                                 0x8BEF40
#define CListWnd__SetCurSel_x                                      0x8BE6C0
#define CListWnd__SetItemColor_x                                   0x8C2E00
#define CListWnd__SetItemData_x                                    0x8BF700
#define CListWnd__SetItemText_x                                    0x8C2C40
#define CListWnd__ShiftColumnSeparator_x                           0x8C2AD0
#define CListWnd__Sort_x                                           0x8C4640
#define CListWnd__ToggleSel_x                                      0x8BF5D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71A140

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73DB30
#define CMerchantWnd__RequestBuyItem_x                             0x747440
#define CMerchantWnd__RequestSellItem_x                            0x749B50
#define CMerchantWnd__SelectRecoverySlot_x                         0x73E120
#define CMerchantWnd__SelectBuySellSlot_x                          0x73AC30
#define CMerchantWnd__ActualSelect_x                               0x73F0B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x854F00
#define CPacketScrambler__hton_x                                   0x854F10

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E23B0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E2490
#define CSidlManager__CreateLabel_x                                0x7A3980
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E0940
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E2770

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D9800
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D9700
#define CSidlScreenWnd__ConvertToRes_x                             0x8FE3A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DA100
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DB300
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DB3B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA870
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D9AB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D9230
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D9CA0
#define CSidlScreenWnd__Init1_x                                    0x8DAFD0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DA1C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D93F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DAAB0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D8E80
#define CSidlScreenWnd__StoreIniVis_x                              0x8D91E0
#define CSidlScreenWnd__WndNotification_x                          0x8DAD50
#define CSidlScreenWnd__GetChildItem_x                             0x8D9300
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CCB30
#define CSidlScreenWnd__m_layoutCopy_x                             0x1730E50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x605750
#define CSkillMgr__GetSkillCap_x                                   0x605930
#define CSkillMgr__GetNameToken_x                                  0x605300

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FD640
#define CSliderWnd__SetValue_x                                     0x8FD810
#define CSliderWnd__SetNumTicks_x                                  0x8FDF90

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A9DB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F7420
#define CStmlWnd__CalculateHSBRange_x                              0x8EF980
#define CStmlWnd__CalculateVSBRange_x                              0x8EF8F0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EFB00
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F0300
#define CStmlWnd__ForceParseNow_x                                  0x8F7DA0
#define CStmlWnd__GetNextTagPiece_x                                0x8F0200
#define CStmlWnd__GetSTMLText_x                                    0x484830
#define CStmlWnd__GetVisibleText_x                                 0x8F0D50
#define CStmlWnd__InitializeWindowVariables_x                      0x8F3310
#define CStmlWnd__MakeStmlColorTag_x                               0x8EEBD0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EEC30
#define CStmlWnd__SetSTMLText_x                                    0x8F4B60
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F70C0
#define CStmlWnd__UpdateHistoryString_x                            0x8F1C90

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FB330
#define CTabWnd__DrawCurrentPage_x                                 0x8FABC0
#define CTabWnd__DrawTab_x                                         0x8FA980
#define CTabWnd__GetCurrentPage_x                                  0x8FAF70
#define CTabWnd__GetPageInnerRect_x                                0x8FA670
#define CTabWnd__GetTabInnerRect_x                                 0x8FA870
#define CTabWnd__GetTabRect_x                                      0x8FA740
#define CTabWnd__InsertPage_x                                      0x8FB620
#define CTabWnd__SetPage_x                                         0x8FAFA0
#define CTabWnd__SetPageRect_x                                     0x8FB270
#define CTabWnd__UpdatePage_x                                      0x8FB5C0
#define CTabWnd__GetPageFromTabIndex_x                             0x8FA8D0
#define CTabWnd__GetCurrentTabIndex_x                              0x8FA600

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E6A30
#define CPageWnd__SetTabText_x                                     0x9076C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436F40

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D7150
#define CTextureFont__GetTextExtent_x                              0x8D6EB0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63E0A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903B00

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC6A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A6EF0
#define CXStr__CXStr1_x                                            0x4F93F0
#define CXStr__CXStr3_x                                            0x89F910
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x89FA80
#define CXStr__operator_equal1_x                                   0x89FAD0
#define CXStr__operator_plus_equal1_x                              0x8A0BD0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D4C60
#define CXWnd__BringToTop_x                                        0x8CBD20
#define CXWnd__Center_x                                            0x8D1F40
#define CXWnd__ClrFocus_x                                          0x8CB8F0
#define CXWnd__Destroy_x                                           0x8D2A30
#define CXWnd__DoAllDrawing_x                                      0x8D1B90
#define CXWnd__DrawChildren_x                                      0x8D1D30
#define CXWnd__DrawColoredRect_x                                   0x8CC0F0
#define CXWnd__DrawTooltip_x                                       0x8CC390
#define CXWnd__DrawTooltipAtPoint_x                                0x8D0AF0
#define CXWnd__GetBorderFrame_x                                    0x8CC800
#define CXWnd__GetChildWndAt_x                                     0x8D2910
#define CXWnd__GetClientClipRect_x                                 0x8CC5B0
#define CXWnd__GetScreenClipRect_x                                 0x8D11F0
#define CXWnd__GetScreenRect_x                                     0x8CC9D0
#define CXWnd__GetTooltipRect_x                                    0x8CC220
#define CXWnd__GetWindowTextA_x                                    0x4270D0
#define CXWnd__IsActive_x                                          0x8C7320
#define CXWnd__IsDescendantOf_x                                    0x8CC740
#define CXWnd__IsReallyVisible_x                                   0x8CFB10
#define CXWnd__IsType_x                                            0x8D1FB0
#define CScreenPieceTemplate__IsType_x                             0x900230
#define CXWnd__Move_x                                              0x8CF260
#define CXWnd__Move1_x                                             0x8D1830
#define CXWnd__ProcessTransition_x                                 0x8CBCD0
#define CXWnd__Refade_x                                            0x8CBAA0
#define CXWnd__Resize_x                                            0x8CCAA0
#define CXWnd__Right_x                                             0x8D0FF0
#define CXWnd__SetFocus_x                                          0x8CE3A0
#define CXWnd__SetFont_x                                           0x8CB940
#define CXWnd__SetKeyTooltip_x                                     0x8CCD00
#define CXWnd__SetMouseOver_x                                      0x8D1530
#define CXWnd__StartFade_x                                         0x8CBD70
#define CXWnd__GetChildItem_x                                      0x8D1470
#define CXWnd__SetParent_x                                         0x8D28C0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C8BE0
#define CXWndManager__DrawWindows_x                                0x8C8820
#define CXWndManager__GetKeyboardFlags_x                           0x8C6E50
#define CXWndManager__HandleKeyboardMsg_x                          0x8C77C0
#define CXWndManager__RemoveWnd_x                                  0x8C74B0

// CDBStr
#define CDBStr__GetString_x                                        0x4BAA70

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452920
#define EQ_Character__Cur_HP_x                                     0x465AE0
#define EQ_Character__Cur_Mana_x                                   0x45AF50
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B900
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443880
#define EQ_Character__GetFocusRangeModifier_x                      0x4439D0
#define EQ_Character__GetHPRegen_x                                 0x469520
#define EQ_Character__GetEnduranceRegen_x                          0x4650F0
#define EQ_Character__GetManaRegen_x                               0x469AC0
#define EQ_Character__Max_Endurance_x                              0x5CC1B0
#define EQ_Character__Max_HP_x                                     0x45DAD0
#define EQ_Character__Max_Mana_x                                   0x5CBFE0
#define EQ_Character__doCombatAbility_x                            0x5C96B0
#define EQ_Character__UseSkill_x                                   0x470AA0
#define EQ_Character__GetConLevel_x                                0x5BEC80
#define EQ_Character__IsExpansionFlag_x                            0x4B6DC0
#define EQ_Character__TotalEffect_x                                0x44FA50
#define EQ_Character__GetPCSpellAffect_x                           0x44BC90
#define EQ_Character__SpellDuration_x                              0x449C90
#define EQ_Character__FindItemByRecord_x                           0x463150
#define EQ_Character__GetAdjustedSkill_x                           0x465CB0
#define EQ_Character__GetBaseSkill_x                               0x45D9B0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872CC0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D4790

//PcClient
#define PcClient__PcClient_x                                       0x5C0AB0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446D50
#define CCharacterSelect__EnterWorld_x                             0x446520
#define CCharacterSelect__Quit_x                                   0x4450E0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59EC90
#define EQ_Item__CreateItemTagString_x                             0x8530F0
#define EQ_Item__IsStackable_x                                     0x8487E0
#define EQ_Item__GetImageNum_x                                     0x84B280
#define EQ_Item__CreateItemClient_x                                0x59FD60
#define EQ_Item__GetItemValue_x                                    0x851BB0
#define EQ_Item__ValueSellMerchant_x                               0x854B60
#define EQ_Item__IsKeyRingItem_x                                   0x849290
#define EQ_Item__CanGoInBag_x                                      0x59EE20
#define EQ_Item__GetMaxItemCount_x                                 0x8486D0
#define EQ_Item__GetHeldItem_x                                     0x84A080
#define EQ_Item__GetAugmentFitBySlot_x                             0x854980

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DAB80
#define EQ_LoadingS__Array_x                                       0xC0BC78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CE6E0
#define EQ_PC__GetAlternateAbilityId_x                             0x85D040
#define EQ_PC__GetCombatAbility_x                                  0x85D0D0
#define EQ_PC__GetCombatAbilityTimer_x                             0x857BB0
#define EQ_PC__GetItemRecastTimer_x                                0x5C7E60
#define EQ_PC__HasLoreItem_x                                       0x5C2270
#define EQ_PC__AlertInventoryChanged_x                             0x5BEC30
#define EQ_PC__GetPcZoneClient_x                                   0x5E8D90
#define EQ_PC__RemoveMyAffect_x                                    0x5C72C0
#define EQ_PC__GetKeyRingItems_x                                   0x857FD0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86AD00
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85EF90

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526E90
#define EQItemList__add_object_x                                   0x554200
#define EQItemList__add_item_x                                     0x526DD0
#define EQItemList__delete_item_x                                  0x527280
#define EQItemList__FreeItemList_x                                 0x527180

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9D40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D4530
#define EQPlayer__dEQPlayer_x                                      0x5DCBE0
#define EQPlayer__DoAttack_x                                       0x5EE710
#define EQPlayer__EQPlayer_x                                       0x5DF310
#define EQPlayer__SetNameSpriteState_x                             0x5D9A30
#define EQPlayer__SetNameSpriteTint_x                              0x5D5950
#define PlayerBase__HasProperty_j_x                                0x9316B0
#define EQPlayer__IsTargetable_x                                   0x931950
#define EQPlayer__CanSee_x                                         0x931EB0
#define PlayerZoneClient__ChangeHeight_x                           0x5EE5D0
#define EQPlayer__CanSee1_x                                        0x931FA0
#define PlayerBase__GetVisibilityLineSegment_x                     0x931C40

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8F40
#define PlayerZoneClient__IsValidTeleport_x                        0x554AB0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2E40


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E33D0
#define EQPlayerManager__GetSpawnByName_x                          0x5E3830
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E3400

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A5280
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A52C0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4E70
#define KeypressHandler__HandleKeyDown_x                           0x5A3790
#define KeypressHandler__HandleKeyUp_x                             0x5A3AB0
#define KeypressHandler__SaveKeymapping_x                          0x5A4F40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x712AD0
#define MapViewMap__SaveEx_x                                       0x715E00

#define PlayerPointManager__GetAltCurrency_x                       0x870D80

// StringTable 
#define StringTable__getString_x                                   0x86B030

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CBC40
#define PcZoneClient__RemovePetEffect_x                            0x5C8330
#define PcZoneClient__HasAlternateAbility_x                        0x5C8CD0
#define PcZoneClient__GetCurrentMod_x                              0x45CF80
#define PcZoneClient__GetModCap_x                                  0x45A6B0
#define PcZoneClient__CanEquipItem_x                               0x5C91F0
#define PcZoneClient__GetItemByID_x                                0x5CDA50
#define PcZoneClient__GetItemByItemClass_x                         0x5CE600
#define PcZoneClient__RemoveBuffEffect_x                           0x5C7570

//Doors
#define EQSwitch__UseSwitch_x                                      0x55BB00

//IconCache
#define IconCache__GetIcon_x                                       0x6AFB50

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A6A30
#define CContainerMgr__CloseContainer_x                            0x6A7250

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x773820

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x597D00

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5270
#define EQ_Spell__SpellAffects_x                                   0x4F2460
#define EQ_Spell__SpellAffectBase_x                           0x4F24D0
#define CharacterZoneClient__CalcAffectChange_x                    0x44BB20
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ADC0
#define CLootWnd__LootAll_x                                        0x7083E0
#define CLootWnd__RequestLootSlot_x                                0x708BF0
#define EQ_Spell__IsStackable_x                                    0x449690
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449740
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EE80
#define EQ_Spell__IsSPAStacking_x                                  0x4F1FD0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3070
#define EQ_Spell__IsNoRemove_x                                     0x434F70
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1FF0

#define __IsResEffectSpell_x                                       0x4497E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87C930

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BB660
#define CTargetWnd__WndNotification_x                              0x7BB150
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BB840

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C0780

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EDB30
#define EqSoundManager__PlayScriptMp3_x                            0x4EF5D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8ED0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EAFF0
#define CSidlManager__FindAnimation1_x                             0x8E0370

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E24C0
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2470
#define CAltAbilityData__GetMaxRank_x                              0x4D6C90

//CTargetRing
#define CTargetRing__Cast_x                                        0x595930

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4596D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x475810
#define CharacterBase__CreateItemIndex_x                           0x520510
#define CharacterBase__GetItemPossession_x                         0x444570
#define CharacterBase__GetItemByGlobalIndex_x                      0x880790
#define CharacterBase__GetEffectId_x                               0x459690

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68F8E0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68F040

//messages
#define msg_spell_worn_off_x                                       0x4FCDD0
#define msg_new_text_x                                             0x506560
#define msgTokenTextParam_x                                        0x502D60

//SpellManager
#define SpellManager__vftable_x                                    0xAC9270
#define SpellManager__SpellManager_x                               0x47E460
#define Spellmanager__LoadTextSpells_x                             0x60C690

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9359C0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4883D0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EDA0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449430
#define ItemGlobalIndex__IsValidIndex_x                            0x458F70

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87E5F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87D530

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7013F0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AB780
#define CCursorAttachment__Deactivate_x                            0x6AACC0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FCB40
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FCCC0

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x604320

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48CC50

//IString
#define IString__Append_x                                          0x47F090

//Camera
#define CDisplay__cameraType_x                                     0xE6F7E0
#define EverQuest__Cameras_x                                       0xF31AE0
