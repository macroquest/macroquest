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
#define __ExpectedVersionDate                                     "Dec 14 2017"
#define __ExpectedVersionTime                                     "13:01:48"
#define __ActualVersionDate_x                                      0xAE4098
#define __ActualVersionTime_x                                      0xAE40A4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5AAAC0
#define __MemChecker1_x                                            0x8A2E70
#define __MemChecker2_x                                            0x640800
#define __MemChecker3_x                                            0x640750
#define __MemChecker4_x                                            0x7F4E30
#define __EncryptPad0_x                                            0xC3EFE8
#define __EncryptPad1_x                                            0xD18BA0
#define __EncryptPad2_x                                            0xC67ED0
#define __EncryptPad3_x                                            0xC67AD0
#define __EncryptPad4_x                                            0xD071A0
#define __EncryptPad5_x                                            0x10C22C0
#define __AC1_x                                                    0x7B40D5
#define __AC2_x                                                    0x563C07
#define __AC3_x                                                    0x561D80
#define __AC4_x                                                    0x573F51
#define __AC5_x                                                    0x587CFB
#define __AC6_x                                                    0x58B89E
#define __AC7_x                                                    0x5822FC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4920

// Direct Input
#define DI8__Main_x                                                0x10C2298
#define DI8__Keyboard_x                                            0x10C229C
#define DI8__Mouse_x                                               0x10C22A0
#define DI8__Mouse_Copy_x                                          0xF30454
#define DI8__Mouse_Check_x                                         0xFB9F84
#define __AutoSkillArray_x                                         0xF31368
#define __Attack_x                                                 0xFB4A5B
#define __Autofire_x                                               0xFB4A5C
#define __BindList_x                                               0xC1B368
#define g_eqCommandStates_x                                        0xF1F1A0
#define __Clicks_x                                                 0xF30510
#define __CommandList_x                                            0xC1DA80
#define __CurrentMapLabel_x                                        0x10C8290
#define __CurrentSocial_x                                          0xBEA8E8
#define __DoAbilityList_x                                          0xF66C20
#define __do_loot_x                                                0x532D10
#define __DrawHandler_x                                            0x1731F0C
#define __GroupCount_x                                             0xF20AAA

#define __Guilds_x                                                 0xF266C0
#define __gWorld_x                                                 0xF22F64
#define __HotkeyPage_x                                             0xFAD620
#define __HWnd_x                                                   0xFBA0A0
#define __InChatMode_x                                             0xF3043C
#define __LastTell_x                                               0xF3231C
#define __LMouseHeldTime_x                                         0xF3057C
#define __Mouse_x                                                  0x10C22A4
#define __MouseLook_x                                              0xF304D6
#define __MouseEventTime_x                                         0xFB51F4
#define __gpbCommandEvent_x                                        0xF2302C
#define __NetStatusToggle_x                                        0xF304D9
#define __PCNames_x                                                0xF31924
#define __RangeAttackReady_x                                       0xF3164C
#define __RMouseHeldTime_x                                         0xF30578
#define __RunWalkState_x                                           0xF30440
#define __ScreenMode_x                                             0xE6ED80
#define __ScreenX_x                                                0xF303F4
#define __ScreenY_x                                                0xF303F0
#define __ScreenXMax_x                                             0xF303F8
#define __ScreenYMax_x                                             0xF303FC
#define __ServerHost_x                                             0xF209F4
#define __ServerName_x                                             0xF66BE0
#define __ShiftKeyDown_x                                           0xF30AD0
#define __ShowNames_x                                              0xF31804
#define __Socials_x                                                0xF66CE0
#define __SubscriptionType_x                                       0x10F8A14
#define __TargetAggroHolder_x                                      0x10CA3EC
#define __ZoneType_x                                               0xF308D4
#define __GroupAggro_x                                             0x10CA42C
#define __LoginName_x                                              0xFB8B7C
#define __Inviter_x                                                0xFB49D8
#define __AttackOnAssist_x                                         0xF317C0
#define __UseTellWindows_x                                         0xF31ABC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF23050
#define instEQZoneInfo_x                                           0xF306CC
#define instKeypressHandler_x                                      0xFB51D8
#define pinstActiveBanker_x                                        0xF23008
#define pinstActiveCorpse_x                                        0xF2300C
#define pinstActiveGMaster_x                                       0xF23010
#define pinstActiveMerchant_x                                      0xF23004
#define pinstAggroInfo_x                                           0xD2C3EC
#define pinstAltAdvManager_x                                       0xE6FEE8
#define pinstAuraMgr_x                                             0xD3CBF0
#define pinstBandageTarget_x                                       0xF22FF0
#define pinstCamActor_x                                            0xE6F7B8
#define pinstCDBStr_x                                              0xE6ED14
#define pinstCDisplay_x                                            0xF23018
#define pinstCEverQuest_x                                          0x10C2418
#define pinstEverQuestInfo_x                                       0xF303E8
#define pinstCharData_x                                            0xF22FD4
#define pinstCharSpawn_x                                           0xF22FFC
#define pinstControlledMissile_x                                   0xF22FD0
#define pinstControlledPlayer_x                                    0xF22FFC
#define pinstCSidlManager_x                                        0x1730E78
#define pinstCXWndManager_x                                        0x1730E70
#define instDynamicZone_x                                          0xF30288
#define pinstDZMember_x                                            0xF30398
#define pinstDZTimerInfo_x                                         0xF3039C
#define pinstEQItemList_x                                          0xF1F478
#define pinstEQObjectList_x                                        0xF204A4
#define instEQMisc_x                                               0xC037A8
#define pinstEQSoundManager_x                                      0xE704B8
#define instExpeditionLeader_x                                     0xF302D2
#define instExpeditionName_x                                       0xF30312
#define pinstGroup_x                                               0xF20AA6
#define pinstImeManager_x                                          0x1730E7C
#define pinstLocalPlayer_x                                         0xF22FE8
#define pinstMercenaryData_x                                       0xFB5840
#define pinstMercenaryStats_x                                      0x10CA538
#define pinstMercAltAbilities_x                                    0xE70270
#define pinstModelPlayer_x                                         0xF23014
#define pinstPCData_x                                              0xF22FD4
#define pinstSkillMgr_x                                            0xFB6838
#define pinstSpawnManager_x                                        0xFB6090
#define pinstSpellManager_x                                        0xFB6980
#define pinstSpellSets_x                                           0xFAD684
#define pinstStringTable_x                                         0xF22F7C
#define pinstSwitchManager_x                                       0xF20638
#define pinstTarget_x                                              0xF23000
#define pinstTargetObject_x                                        0xF22FD8
#define pinstTargetSwitch_x                                        0xF22FDC
#define pinstTaskMember_x                                          0xE6EC60
#define pinstTrackTarget_x                                         0xF22FF4
#define pinstTradeTarget_x                                         0xF22FE4
#define instTributeActive_x                                        0xC037CD
#define pinstViewActor_x                                           0xE6F7B4
#define pinstWorldData_x                                           0xF22FB8
#define pinstZoneAddr_x                                            0xF3096C
#define pinstPlayerPath_x                                          0xFB60F0
#define pinstTargetIndicator_x                                     0xFB6B18
#define pinstCTargetManager_x                                      0xFB6B78
#define EQObject_Top_x                                             0xF22FC8
#define pinstRealEstateItems_x                                     0xFB66A4

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE6F6D0
#define pinstCAchievementsWnd_x                                    0xE6F72C
#define pinstCTextOverlay_x                                        0xD2C980
#define pinstCAudioTriggersWindow_x                                0xD2C768
#define pinstCCharacterSelect_x                                    0xE6F63C
#define pinstCFacePick_x                                           0xE6F3EC
#define pinstCFindItemWnd_x                                        0xE6F6CC
#define pinstCNoteWnd_x                                            0xE6F5F4
#define pinstCBookWnd_x                                            0xE6F5FC
#define pinstCPetInfoWnd_x                                         0xE6F600
#define pinstCTrainWnd_x                                           0xE6F604
#define pinstCSkillsWnd_x                                          0xE6F608
#define pinstCSkillsSelectWnd_x                                    0xE6F60C
#define pinstCCombatSkillsSelectWnd_x                              0xE6F610
#define pinstCFriendsWnd_x                                         0xE6F614
#define pinstCAuraWnd_x                                            0xE6F618
#define pinstCRespawnWnd_x                                         0xE6F61C
#define pinstCBandolierWnd_x                                       0xE6F620
#define pinstCPotionBeltWnd_x                                      0xE6F624
#define pinstCAAWnd_x                                              0xE6F628
#define pinstCGroupSearchFiltersWnd_x                              0xE6F62C
#define pinstCLoadskinWnd_x                                        0xE6F630
#define pinstCAlarmWnd_x                                           0xE6F634
#define pinstCMusicPlayerWnd_x                                     0xE6F638
#define pinstCMailWnd_x                                            0xE6F640
#define pinstCMailCompositionWnd_x                                 0xE6F644
#define pinstCMailAddressBookWnd_x                                 0xE6F648
#define pinstCRaidWnd_x                                            0xE6F650
#define pinstCRaidOptionsWnd_x                                     0xE6F654
#define pinstCBreathWnd_x                                          0xE6F658
#define pinstCMapViewWnd_x                                         0xE6F65C
#define pinstCMapToolbarWnd_x                                      0xE6F660
#define pinstCEditLabelWnd_x                                       0xE6F664
#define pinstCTargetWnd_x                                          0xE6F668
#define pinstCColorPickerWnd_x                                     0xE6F66C
#define pinstCPlayerWnd_x                                          0xE6F670
#define pinstCOptionsWnd_x                                         0xE6F674
#define pinstCBuffWindowNORMAL_x                                   0xE6F678
#define pinstCBuffWindowSHORT_x                                    0xE6F67C
#define pinstCharacterCreation_x                                   0xE6F680
#define pinstCCursorAttachment_x                                   0xE6F684
#define pinstCCastingWnd_x                                         0xE6F688
#define pinstCCastSpellWnd_x                                       0xE6F68C
#define pinstCSpellBookWnd_x                                       0xE6F690
#define pinstCInventoryWnd_x                                       0xE6F694
#define pinstCBankWnd_x                                            0xE6F69C
#define pinstCQuantityWnd_x                                        0xE6F6A0
#define pinstCLootWnd_x                                            0xE6F6A4
#define pinstCActionsWnd_x                                         0xE6F6A8
#define pinstCCombatAbilityWnd_x                                   0xE6F6B0
#define pinstCMerchantWnd_x                                        0xE6F6B4
#define pinstCTradeWnd_x                                           0xE6F6BC
#define pinstCSelectorWnd_x                                        0xE6F6C0
#define pinstCBazaarWnd_x                                          0xE6F6C4
#define pinstCBazaarSearchWnd_x                                    0xE6F6C8
#define pinstCGiveWnd_x                                            0xE6F6E8
#define pinstCTrackingWnd_x                                        0xE6F6F0
#define pinstCInspectWnd_x                                         0xE6F6F4
#define pinstCSocialEditWnd_x                                      0xE6F6F8
#define pinstCFeedbackWnd_x                                        0xE6F6FC
#define pinstCBugReportWnd_x                                       0xE6F700
#define pinstCVideoModesWnd_x                                      0xE6F704
#define pinstCTextEntryWnd_x                                       0xE6F70C
#define pinstCFileSelectionWnd_x                                   0xE6F710
#define pinstCCompassWnd_x                                         0xE6F714
#define pinstCPlayerNotesWnd_x                                     0xE6F718
#define pinstCGemsGameWnd_x                                        0xE6F71C
#define pinstCTimeLeftWnd_x                                        0xE6F738
#define pinstCPetitionQWnd_x                                       0xE6F73C
#define pinstCStoryWnd_x                                           0xE6F740
#define pinstCJournalTextWnd_x                                     0xE6F744
#define pinstCJournalCatWnd_x                                      0xE6F748
#define pinstCBodyTintWnd_x                                        0xE6F74C
#define pinstCServerListWnd_x                                      0xE6F750
#define pinstCAvaZoneWnd_x                                         0xE6F75C
#define pinstCBlockedBuffWnd_x                                     0xE6F760
#define pinstCBlockedPetBuffWnd_x                                  0xE6F764
#define pinstCInvSlotMgr_x                                         0xE6F7AC
#define pinstCContainerMgr_x                                       0xE6F7B0
#define pinstCAdventureLeaderboardWnd_x                            0x10C2DC8
#define pinstCAdventureRequestWnd_x                                0x10C2E40
#define pinstCAltStorageWnd_x                                      0x10C3120
#define pinstCAdventureStatsWnd_x                                  0x10C2EB8
#define pinstCBarterMerchantWnd_x                                  0x10C3E68
#define pinstCBarterSearchWnd_x                                    0x10C3EE0
#define pinstCBarterWnd_x                                          0x10C3F58
#define pinstCChatWindowManager_x                                  0x10C4768
#define pinstCDynamicZoneWnd_x                                     0x10C4C98
#define pinstCEQMainWnd_x                                          0x10C4E60
#define pinstCFellowshipWnd_x                                      0x10C4C2C
#define pinstCFindLocationWnd_x                                    0x10C5130
#define pinstCGroupSearchWnd_x                                     0x10C5400
#define pinstCGroupWnd_x                                           0x10C5478
#define pinstCGuildBankWnd_x                                       0x10C54F0
#define pinstCGuildMgmtWnd_x                                       0x10C75E0
#define pinstCHotButtonWnd_x                                       0x10C76DC
#define pinstCHotButtonWnd1_x                                      0x10C76DC
#define pinstCHotButtonWnd2_x                                      0x10C76E0
#define pinstCHotButtonWnd3_x                                      0x10C76E4
#define pinstCHotButtonWnd4_x                                      0x10C7708
#define pinstCItemDisplayManager_x                                 0x10C7B60
#define pinstCItemExpTransferWnd_x                                 0x10C7C5C
#define pinstCLFGuildWnd_x                                         0x10C7F38
#define pinstCMIZoneSelectWnd_x                                    0x10C8518
#define pinstCConfirmationDialog_x                                 0x10C8B30
#define pinstCPopupWndManager_x                                    0x10C8B30
#define pinstCProgressionSelectionWnd_x                            0x10C8C20
#define pinstCPvPStatsWnd_x                                        0x10C8D10
#define pinstCLargeDialogWnd_x                                     0x10C9498
#define pinstCTaskWnd_x                                            0x10CA818
#define pinstCTaskSomething_x                                      0xD3D808
#define pinstCTaskTemplateSelectWnd_x                              0x10CA7A0
#define pinstCTipWndOFDAY_x                                        0x10CA980
#define pinstCTipWndCONTEXT_x                                      0x10CA984
#define pinstCTitleWnd_x                                           0x10CAA00
#define pinstCContextMenuManager_x                                 0x1730D00
#define pinstCVoiceMacroWnd_x                                      0xFB6F50
#define pinstCHtmlWnd_x                                            0xFB7040
#define pinstItemIconCache_x                                       0x10C4E08
#define pinstCTradeskillWnd_x                                      0x10CAB00
#define pinstCAdvancedLootWnd_x                                    0xE6F7A0
#define pinstRewardSelectionWnd_x                                  0x10C9238
#define pinstEQSuiteTextureLoader_x                                0xD1AA68

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54A5C0
#define __CastRay2_x                                               0x549EF0
#define __HeadingDiff_x                                            0x932FC0
#define __FixHeading_x                                             0x932F50
#define __get_bearing_x                                            0x539E60
#define __ConvertItemTags_x                                        0x537930
#define __ExecuteCmd_x                                             0x522260
#define __EQGetTime_x                                              0x8A2810
#define __get_melee_range_x                                        0x528EF0
#define __GetGaugeValueFromEQ_x                                    0x7B2C90
#define __GetLabelFromEQ_x                                         0x7B4060
#define __ToggleKeyRingItem_x                                      0x48FA80
#define __GetXTargetType_x                                         0x934BC0
#define __LoadFrontEnd_x                                           0x63FED0
#define __NewUIINI_x                                               0x7B2670
#define __ProcessGameEvents_x                                      0x584090
#define __ProcessMouseEvent_x                                      0x583830
#define CrashDetected_x                                            0x641890
#define wwsCrashReportCheckForUploader_x                           0x800A20
#define __AppCrashWrapper_x                                        0xC67AC4
#define __pCrashHandler_x                                          0x10D79E0
#define __CrashHandler_x                                           0x8004B0
#define wwsCrashReportPlatformLaunchUploader_x                     0x802C60
#define DrawNetStatus_x                                            0x5BA580
#define Util__FastTime_x                                           0x8A24B0
#define Expansion_HoT_x                                            0xF317B0
#define __HelpPath_x                                               0xFB4F60
#define __STMLToText_x                                             0x8E8AE0
#define __GetAnimationCache_x                                      0x6AF780

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423270
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DEE0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DCB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D7B30
#define AltAdvManager__IsAbilityReady_x                            0x4D7BA0
#define AltAdvManager__GetAAById_x                                 0x4D8090
#define AltAdvManager__CanTrainAbility_x                           0x4D8CC0
#define AltAdvManager__CanSeeAbility_x                             0x4D8880

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46B1D0
#define CharacterZoneClient__HasSkill_x                            0x4670E0
#define CharacterZoneClient__MakeMeVisible_x                       0x46CD40
#define CharacterZoneClient__IsStackBlocked_x                      0x44C160
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B680
#define CharacterZoneClient__GetItemCountWorn_x                    0x465640
#define CharacterZoneClient__GetItemCountInInventory_x             0x465720
#define CharacterZoneClient__GetCursorItemCount_x                  0x465800
#define CharacterZoneClient__FindAffectSlot_x                      0x4517D0
#define CharacterZoneClient__BardCastBard_x                        0x44ADF0
#define CharacterZoneClient__GetMaxEffects_x                       0x449980
#define CharacterZoneClient__GetEffect_x                           0x44B8B0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451630
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449CD0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x450180

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66F860

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67D6E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x599270
#define CButtonWnd__CButtonWnd_x                                   0x8DCD90

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x698990
#define CChatManager__InitContextMenu_x                            0x699AE0
#define CChatManager__FreeChatWindow_x                             0x698440
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A1C20
#define CChatManager__SetLockedActiveChatWindow_x                  0x698960

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6E50
#define CContextMenu__dCContextMenu_x                              0x8E7050
#define CContextMenu__AddMenuItem_x                                0x8E7560
#define CContextMenu__RemoveMenuItem_x                             0x8E71C0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E71E0
#define CContextMenu__CheckMenuItem_x                              0x8E7260
#define CContextMenu__SetMenuItem_x                                0x8E70F0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D33C0
#define CContextMenuManager__RemoveMenu_x                          0x8D3740
#define CContextMenuManager__PopupMenu_x                           0x8D3B90
#define CContextMenuManager__Flush_x                               0x8D3430
#define CContextMenuManager__GetMenu_x                             0x4193B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886A00
#define CChatService__GetFriendName_x                              0x886A10

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69F710
#define CChatWindow__Clear_x                                       0x69EFF0
#define CChatWindow__WndNotification_x                             0x6A0010

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D71F0
#define CComboWnd__Draw_x                                          0x8D7400
#define CComboWnd__GetCurChoice_x                                  0x8D6FA0
#define CComboWnd__GetListRect_x                                   0x8D76A0
#define CComboWnd__GetTextRect_x                                   0x8D7260
#define CComboWnd__InsertChoice_x                                  0x8D7800
#define CComboWnd__SetColors_x                                     0x8D6F30
#define CComboWnd__SetChoice_x                                     0x8D6F60
#define CComboWnd__GetItemCount_x                                  0x8D6F90
#define CComboWnd__GetCurChoiceText_x                              0x8D6FE0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A9930
#define CContainerWnd__vftable_x                                   0xAED9B0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5A90
#define CDisplay__GetClickedActor_x                                0x4BE360
#define CDisplay__GetUserDefinedColor_x                            0x4BCF40
#define CDisplay__GetWorldFilePath_x                               0x4BC390
#define CDisplay__is3dON_x                                         0x4BB820
#define CDisplay__ReloadUI_x                                       0x4CF850
#define CDisplay__WriteTextHD2_x                                   0x4C1E20
#define CDisplay__TrueDistance_x                                   0x4BEF90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FE320

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB390
#define CEditWnd__GetCharIndexPt_x                                 0x8EC4D0
#define CEditWnd__GetDisplayString_x                               0x8EB540
#define CEditWnd__GetHorzOffset_x                                  0x8EB880
#define CEditWnd__GetLineForPrintableChar_x                        0x8EBFA0
#define CEditWnd__GetSelStartPt_x                                  0x8EC780
#define CEditWnd__GetSTMLSafeText_x                                0x8EBA10
#define CEditWnd__PointFromPrintableChar_x                         0x8EC090
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC210
#define CEditWnd__SetEditable_x                                    0x8EB9E0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A780
#define CEverQuest__ClickedPlayer_x                                0x564350
#define CEverQuest__CreateTargetIndicator_x                        0x565250
#define CEverQuest__DeleteTargetIndicator_x                        0x5652D0
#define CEverQuest__DoTellWindow_x                                 0x476410
#define CEverQuest__OutputTextToLog_x                              0x476070
#define CEverQuest__DropHeldItemOnGround_x                         0x57ACF0
#define CEverQuest__dsp_chat_x                                     0x476750
#define CEverQuest__trimName_x                                     0x560C60
#define CEverQuest__Emote_x                                        0x579000
#define CEverQuest__EnterZone_x                                    0x5740E0
#define CEverQuest__GetBodyTypeDesc_x                              0x55E6A0
#define CEverQuest__GetClassDesc_x                                 0x567B90
#define CEverQuest__GetClassThreeLetterCode_x                      0x568190
#define CEverQuest__GetDeityDesc_x                                 0x55EF80
#define CEverQuest__GetLangDesc_x                                  0x55EA30
#define CEverQuest__GetRaceDesc_x                                  0x568350
#define CEverQuest__InterpretCmd_x                                 0x56BF00
#define CEverQuest__LeftClickedOnPlayer_x                          0x5808A0
#define CEverQuest__LMouseUp_x                                     0x582850
#define CEverQuest__RightClickedOnPlayer_x                         0x5813B0
#define CEverQuest__RMouseUp_x                                     0x5822B0
#define CEverQuest__SetGameState_x                                 0x564C20
#define CEverQuest__UPCNotificationFlush_x                         0x55D030
#define CEverQuest__IssuePetCommand_x                              0x56C8E0
#define CEverQuest__ReportSuccessfulHit_x                          0x575830

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BA5F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BA650
#define CGaugeWnd__Draw_x                                          0x6BAA80

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B3B0
#define CGuild__GetGuildName_x                                     0x43B880
#define CGuild__GetGuildIndex_x                                    0x43CA90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D6A90

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E3E20
#define CInvSlotMgr__MoveItem_x                                    0x6E45E0
#define CInvSlotMgr__SelectSlot_x                                  0x6E3720

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E2B80
#define CInvSlot__SliderComplete_x                                 0x6E03A0
#define CInvSlot__GetItemBase_x                                    0x6DF840
#define CInvSlot__UpdateItem_x                                     0x6DFDC0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E5A10
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E6B50

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AEB10
#define CItemDisplayWnd__UpdateStrings_x                           0x6E7C70
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F44D0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F49F0
#define CItemDisplayWnd__SetItem_x                                 0x6FA2D0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E5A80

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EE1D0

// CLabel 
#define CLabel__Draw_x                                             0x7010A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C3010
#define CListWnd__dCListWnd_x                                      0x8C42B0
#define CListWnd__AddColumn_x                                      0x8C4250
#define CListWnd__AddColumn1_x                                     0x8C38F0
#define CListWnd__AddLine_x                                        0x8C32D0
#define CListWnd__AddString_x                                      0x8C34F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C0150
#define CListWnd__CalculateVSBRange_x                              0x8C24D0
#define CListWnd__ClearSel_x                                       0x8BF490
#define CListWnd__ClearAllSel_x                                    0x8BF440
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2EA0
#define CListWnd__Compare_x                                        0x8C0E20
#define CListWnd__Draw_x                                           0x8C20E0
#define CListWnd__DrawColumnSeparators_x                           0x8C1F70
#define CListWnd__DrawHeader_x                                     0x8BF750
#define CListWnd__DrawItem_x                                       0x8C14B0
#define CListWnd__DrawLine_x                                       0x8C1C10
#define CListWnd__DrawSeparator_x                                  0x8C2010
#define CListWnd__EnableLine_x                                     0x8BF670
#define CListWnd__EnsureVisible_x                                  0x8C02B0
#define CListWnd__ExtendSel_x                                      0x8C13C0
#define CListWnd__GetColumnMinWidth_x                              0x8BED80
#define CListWnd__GetColumnWidth_x                                 0x8BECB0
#define CListWnd__GetCurSel_x                                      0x8BE480
#define CListWnd__GetItemAtPoint_x                                 0x8C0540
#define CListWnd__GetItemAtPoint1_x                                0x8C05B0
#define CListWnd__GetItemData_x                                    0x8BE7C0
#define CListWnd__GetItemHeight_x                                  0x8BFDC0
#define CListWnd__GetItemIcon_x                                    0x8BE9B0
#define CListWnd__GetItemRect_x                                    0x8C0380
#define CListWnd__GetItemText_x                                    0x8BE860
#define CListWnd__GetSelList_x                                     0x8C37E0
#define CListWnd__GetSeparatorRect_x                               0x8C0D50
#define CListWnd__InsertLine_x                                     0x8C36D0
#define CListWnd__RemoveLine_x                                     0x8C36E0
#define CListWnd__SetColors_x                                      0x8BE5D0
#define CListWnd__SetColumnJustification_x                         0x8BF010
#define CListWnd__SetColumnWidth_x                                 0x8BED30
#define CListWnd__SetCurSel_x                                      0x8BE4C0
#define CListWnd__SetItemColor_x                                   0x8C2B90
#define CListWnd__SetItemData_x                                    0x8BF4F0
#define CListWnd__SetItemText_x                                    0x8C29D0
#define CListWnd__ShiftColumnSeparator_x                           0x8C2860
#define CListWnd__Sort_x                                           0x8C43B0
#define CListWnd__ToggleSel_x                                      0x8BF3C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x719FB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73F730
#define CMerchantWnd__RequestBuyItem_x                             0x7472F0
#define CMerchantWnd__RequestSellItem_x                            0x749970
#define CMerchantWnd__SelectRecoverySlot_x                         0x73C9E0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73A870
#define CMerchantWnd__ActualSelect_x                               0x741520

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x854BE0
#define CPacketScrambler__hton_x                                   0x854BF0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E1D00
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1DE0
#define CSidlManager__CreateLabel_x                                0x7A3A80
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E02A0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E20C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D9230
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D9130
#define CSidlScreenWnd__ConvertToRes_x                             0x8FE200
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9B30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DACD0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DAD80
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA260
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D94E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8C60
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D96D0
#define CSidlScreenWnd__Init1_x                                    0x8DA9B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9BE0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8E20
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA4A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D88C0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8C10
#define CSidlScreenWnd__WndNotification_x                          0x8DA730
#define CSidlScreenWnd__GetChildItem_x                             0x8D8D30
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC730
#define CSidlScreenWnd__m_layoutCopy_x                             0x1730E20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6058F0
#define CSkillMgr__GetSkillCap_x                                   0x605AD0
#define CSkillMgr__GetNameToken_x                                  0x6054A0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FD4C0
#define CSliderWnd__SetValue_x                                     0x8FD690
#define CSliderWnd__SetNumTicks_x                                  0x8FDE10

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A9E00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6DB0
#define CStmlWnd__CalculateHSBRange_x                              0x8EF340
#define CStmlWnd__CalculateVSBRange_x                              0x8EF2B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF4C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EFCC0
#define CStmlWnd__ForceParseNow_x                                  0x8F7730
#define CStmlWnd__GetNextTagPiece_x                                0x8EFBC0
#define CStmlWnd__GetSTMLText_x                                    0x4845F0
#define CStmlWnd__GetVisibleText_x                                 0x8F0710
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2CC0
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE590
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE5F0
#define CStmlWnd__SetSTMLText_x                                    0x8F4510
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6A50
#define CStmlWnd__UpdateHistoryString_x                            0x8F1640

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FAC30
#define CTabWnd__DrawCurrentPage_x                                 0x8FA4C0
#define CTabWnd__DrawTab_x                                         0x8FA290
#define CTabWnd__GetCurrentPage_x                                  0x8FA870
#define CTabWnd__GetPageInnerRect_x                                0x8F9F80
#define CTabWnd__GetTabInnerRect_x                                 0x8FA180
#define CTabWnd__GetTabRect_x                                      0x8FA050
#define CTabWnd__InsertPage_x                                      0x8FAF20
#define CTabWnd__SetPage_x                                         0x8FA8A0
#define CTabWnd__SetPageRect_x                                     0x8FAB70
#define CTabWnd__UpdatePage_x                                      0x8FAEC0
#define CTabWnd__GetPageFromTabIndex_x                             0x8FA1E0
#define CTabWnd__GetCurrentTabIndex_x                              0x8F9F10

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E6D00
#define CPageWnd__SetTabText_x                                     0x907570

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436F10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6BA0
#define CTextureFont__GetTextExtent_x                              0x8D6900

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63E170

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9039B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC4A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A6F40
#define CXStr__CXStr1_x                                            0x751280
#define CXStr__CXStr3_x                                            0x89F700
#define CXStr__dCXStr_x                                            0x7A3A30
#define CXStr__operator_equal_x                                    0x89F870
#define CXStr__operator_equal1_x                                   0x89F8C0
#define CXStr__operator_plus_equal1_x                              0x8A09C0

// CXWnd 
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D46A0
#define CXWnd__BringToTop_x                                        0x8CB990
#define CXWnd__Center_x                                            0x8D19C0
#define CXWnd__ClrFocus_x                                          0x8CB570
#define CXWnd__Destroy_x                                           0x8D24A0
#define CXWnd__DoAllDrawing_x                                      0x8D1610
#define CXWnd__DrawChildren_x                                      0x8D17B0
#define CXWnd__DrawColoredRect_x                                   0x8CBD50
#define CXWnd__DrawTooltip_x                                       0x8CBFF0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D05E0
#define CXWnd__GetBorderFrame_x                                    0x8CC440
#define CXWnd__GetChildWndAt_x                                     0x8D2390
#define CXWnd__GetClientClipRect_x                                 0x8CC200
#define CXWnd__GetScreenClipRect_x                                 0x8D0CD0
#define CXWnd__GetScreenRect_x                                     0x8CC5E0
#define CXWnd__GetTooltipRect_x                                    0x8CBE80
#define CXWnd__GetWindowTextA_x                                    0x426EA0
#define CXWnd__IsActive_x                                          0x8C7060
#define CXWnd__IsDescendantOf_x                                    0x8CC390
#define CXWnd__IsReallyVisible_x                                   0x8CF630
#define CXWnd__IsType_x                                            0x8D1A30
#define CScreenPieceTemplate__IsType_x                             0x9000C0
#define CXWnd__Move_x                                              0x8CEDB0
#define CXWnd__Move1_x                                             0x8D12F0
#define CXWnd__ProcessTransition_x                                 0x8CB930
#define CXWnd__Refade_x                                            0x8CB710
#define CXWnd__Resize_x                                            0x8CC690
#define CXWnd__Right_x                                             0x8D0AD0
#define CXWnd__SetFocus_x                                          0x8CDF50
#define CXWnd__SetFont_x                                           0x8CB5C0
#define CXWnd__SetKeyTooltip_x                                     0x8CC900
#define CXWnd__SetMouseOver_x                                      0x8D1000
#define CXWnd__StartFade_x                                         0x8CB9E0
#define CXWnd__GetChildItem_x                                      0x8D0F50
#define CXWnd__SetParent_x                                         0x8D2340

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C8910
#define CXWndManager__DrawWindows_x                                0x8C8560
#define CXWndManager__GetKeyboardFlags_x                           0x8C6BD0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C7500
#define CXWndManager__RemoveWnd_x                                  0x8C71F0

// CDBStr
#define CDBStr__GetString_x                                        0x4BA080

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452890
#define EQ_Character__Cur_HP_x                                     0x466CC0
#define EQ_Character__Cur_Mana_x                                   0x45BCA0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B990
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4439A0
#define EQ_Character__GetFocusRangeModifier_x                      0x443AF0
#define EQ_Character__GetHPRegen_x                                 0x46A860
#define EQ_Character__GetEnduranceRegen_x                          0x4662D0
#define EQ_Character__GetManaRegen_x                               0x46AE00
#define EQ_Character__Max_Endurance_x                              0x5CC630
#define EQ_Character__Max_HP_x                                     0x45E820
#define EQ_Character__Max_Mana_x                                   0x5CC460
#define EQ_Character__doCombatAbility_x                            0x5C9B30
#define EQ_Character__UseSkill_x                                   0x472BF0
#define EQ_Character__GetConLevel_x                                0x5BEC20
#define EQ_Character__IsExpansionFlag_x                            0x4B63E0
#define EQ_Character__TotalEffect_x                                0x44FAC0
#define EQ_Character__GetPCSpellAffect_x                           0x44BD20
#define EQ_Character__SpellDuration_x                              0x449D20
#define EQ_Character__FindItemByRecord_x                           0x464310
#define EQ_Character__GetAdjustedSkill_x                           0x466E90
#define EQ_Character__GetBaseSkill_x                               0x45E700

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872C00

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D4DB0

//PcClient
#define PcClient__PcClient_x                                       0x5C0A80

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446E00
#define CCharacterSelect__EnterWorld_x                             0x4465D0
#define CCharacterSelect__Quit_x                                   0x445190

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59EC40
#define EQ_Item__CreateItemTagString_x                             0x852E10
#define EQ_Item__IsStackable_x                                     0x848420
#define EQ_Item__GetImageNum_x                                     0x84AF10
#define EQ_Item__CreateItemClient_x                                0x59FD80
#define EQ_Item__GetItemValue_x                                    0x851840
#define EQ_Item__ValueSellMerchant_x                               0x854870
#define EQ_Item__IsKeyRingItem_x                                   0x848EF0
#define EQ_Item__CanGoInBag_x                                      0x59EDD0
#define EQ_Item__GetMaxItemCount_x                                 0x848310
#define EQ_Item__GetHeldItem_x                                     0x849D00
#define EQ_Item__GetAugmentFitBySlot_x                             0x8546A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA0D0
#define EQ_LoadingS__Array_x                                       0xC0BC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CEB60
#define EQ_PC__GetAlternateAbilityId_x                             0x85CCE0
#define EQ_PC__GetCombatAbility_x                                  0x85CD70
#define EQ_PC__GetCombatAbilityTimer_x                             0x857890
#define EQ_PC__GetItemRecastTimer_x                                0x5C8320
#define EQ_PC__HasLoreItem_x                                       0x5C2240
#define EQ_PC__AlertInventoryChanged_x                             0x5BEBD0
#define EQ_PC__GetPcZoneClient_x                                   0x5E9350
#define EQ_PC__RemoveMyAffect_x                                    0x5C7750
#define EQ_PC__GetKeyRingItems_x                                   0x857CB0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86A9F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85EC60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526F80
#define EQItemList__add_object_x                                   0x554060
#define EQItemList__add_item_x                                     0x526EC0
#define EQItemList__delete_item_x                                  0x527370
#define EQItemList__FreeItemList_x                                 0x527270

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9360

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D4A70
#define EQPlayer__dEQPlayer_x                                      0x5DD200
#define EQPlayer__DoAttack_x                                       0x5EEAF0
#define EQPlayer__EQPlayer_x                                       0x5DF920
#define EQPlayer__SetNameSpriteState_x                             0x5DA050
#define EQPlayer__SetNameSpriteTint_x                              0x5D5F70
#define PlayerBase__HasProperty_j_x                                0x9313D0
#define EQPlayer__IsTargetable_x                                   0x931670
#define EQPlayer__CanSee_x                                         0x931BD0
#define PlayerZoneClient__ChangeHeight_x                           0x5EE9B0
#define EQPlayer__CanSee1_x                                        0x931CC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x931960

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E9500
#define PlayerZoneClient__IsValidTeleport_x                        0x554900
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2430

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E3990
#define EQPlayerManager__GetSpawnByName_x                          0x5E3DF0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E39C0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A52D0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A5310
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4EC0
#define KeypressHandler__HandleKeyDown_x                           0x5A37E0
#define KeypressHandler__HandleKeyUp_x                             0x5A3B00
#define KeypressHandler__SaveKeymapping_x                          0x5A4F90

// MapViewMap 
#define MapViewMap__Clear_x                                        0x712940
#define MapViewMap__SaveEx_x                                       0x715C70
#define MapViewMap__SetZoom_x                                      0x7125D0

#define PlayerPointManager__GetAltCurrency_x                       0x870CC0

// StringTable 
#define StringTable__getString_x                                   0x86AD20

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CC0C0
#define PcZoneClient__RemovePetEffect_x                            0x5C87F0
#define PcZoneClient__HasAlternateAbility_x                        0x5C9190
#define PcZoneClient__GetCurrentMod_x                              0x45DCD0
#define PcZoneClient__GetModCap_x                                  0x45B400
#define PcZoneClient__CanEquipItem_x                               0x5C9670
#define PcZoneClient__GetItemByID_x                                0x5CDED0
#define PcZoneClient__GetItemByItemClass_x                         0x5CEA80
#define PcZoneClient__RemoveBuffEffect_x                           0x5C7A00

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B950

//IconCache
#define IconCache__GetIcon_x                                       0x6AFDB0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A6CE0
#define CContainerMgr__CloseContainer_x                            0x6A7500

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x773840

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x597C60

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4800
#define EQ_Spell__SpellAffects_x                                   0x4F19E0
#define EQ_Spell__SpellAffectBase_x                                0x4F1A50
#define CharacterZoneClient__CalcAffectChange_x                    0x44BBB0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AE50
#define CLootWnd__LootAll_x                                        0x7082D0
#define CLootWnd__RequestLootSlot_x                                0x708AE0
#define EQ_Spell__IsStackable_x                                    0x459370
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4497F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EEF0
#define EQ_Spell__IsSPAStacking_x                                  0x4F1550
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F25F0
#define EQ_Spell__IsNoRemove_x                                     0x434F30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1570

#define __IsResEffectSpell_x                                       0x449870

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87C8B0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BB770
#define CTargetWnd__WndNotification_x                              0x7BB260
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BB950

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C0890

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED0C0
#define EqSoundManager__PlayScriptMp3_x                            0x4EEB60

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A84C0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EA9C0
#define CSidlManager__FindAnimation1_x                             0x8DFCD0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E19A0
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1950
#define CAltAbilityData__GetMaxRank_x                              0x4D61E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5958B0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459680
#define CharacterBase__CreateItemGlobalIndex_x                     0x475620
#define CharacterBase__CreateItemIndex_x                           0x520560
#define CharacterBase__GetItemPossession_x                         0x444690
#define CharacterBase__GetItemByGlobalIndex_x                      0x880700
#define CharacterBase__GetEffectId_x                               0x459640

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68FA80
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68F1E0

//messages
#define msg_spell_worn_off_x                                       0x4FC290
#define msg_new_text_x                                             0x505A10
#define msgTokenTextParam_x                                        0x502210

//SpellManager
#define SpellManager__vftable_x                                    0xAC9278
#define SpellManager__SpellManager_x                               0x47E230
#define Spellmanager__LoadTextSpells_x                             0x60C780

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9356E0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487A90
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EE10
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449500
#define ItemGlobalIndex__IsValidIndex_x                            0x458EB0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87E570
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87D4B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7012F0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AB9E0
#define CCursorAttachment__Deactivate_x                            0x6AAF30

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FC9C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FCB40

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C300

//IString
#define IString__Append_x                                          0x47EEB0

//Camera
#define CDisplay__cameraType_x                                     0xE6F7C8
#define EverQuest__Cameras_x                                       0xF31AC8
