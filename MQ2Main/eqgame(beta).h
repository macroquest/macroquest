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
#define __ExpectedVersionDate                                     "Dec 11 2017"
#define __ExpectedVersionTime                                     "09:55:16"
#define __ActualVersionDate_x                                      0xAE40E0
#define __ActualVersionTime_x                                      0xAE40EC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5AA160
#define __MemChecker1_x                                            0x8A29C0
#define __MemChecker2_x                                            0x63FF00
#define __MemChecker3_x                                            0x63FE50
#define __MemChecker4_x                                            0x7F45E0
#define __EncryptPad0_x                                            0xC3EFE8
#define __EncryptPad1_x                                            0xD18BA0
#define __EncryptPad2_x                                            0xC67ED0
#define __EncryptPad3_x                                            0xC67AD0
#define __EncryptPad4_x                                            0xD071A0
#define __EncryptPad5_x                                            0x10C22C0
#define __AC1_x                                                    0x7B37E5
#define __AC2_x                                                    0x5634F7
#define __AC3_x                                                    0x561670
#define __AC4_x                                                    0x573841
#define __AC5_x                                                    0x58759B
#define __AC6_x                                                    0x58B14E
#define __AC7_x                                                    0x581B9C
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
#define __do_loot_x                                                0x532490
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
#define __CastRay_x                                                0x549D50
#define __CastRay2_x                                               0x549680
#define __HeadingDiff_x                                            0x932D50
#define __FixHeading_x                                             0x932CE0
#define __get_bearing_x                                            0x5395E0
#define __ConvertItemTags_x                                        0x5370B0
#define __ExecuteCmd_x                                             0x521990
#define __EQGetTime_x                                              0x8A2360
#define __get_melee_range_x                                        0x528650
#define __GetGaugeValueFromEQ_x                                    0x7B23A0
#define __GetLabelFromEQ_x                                         0x7B3770
#define __ToggleKeyRingItem_x                                      0x48FC30
#define __GetXTargetType_x                                         0x934950
#define __LoadFrontEnd_x                                           0x63F5D0
#define __NewUIINI_x                                               0x7B1D70
#define __ProcessGameEvents_x                                      0x583930
#define __ProcessMouseEvent_x                                      0x5830D0
#define CrashDetected_x                                            0x640F90
#define wwsCrashReportCheckForUploader_x                           0x800270
#define __AppCrashWrapper_x                                        0xC67AC4
#define __pCrashHandler_x                                          0x10D79E0
#define __CrashHandler_x                                           0x7FFD00
#define wwsCrashReportPlatformLaunchUploader_x                     0x8024A0
#define DrawNetStatus_x                                            0x5B9C90
#define Util__FastTime_x                                           0x8A2000
#define Expansion_HoT_x                                            0xF317B0
#define __HelpPath_x                                               0xFB4F60
#define __STMLToText_x                                             0x8E89D0
#define __GetAnimationCache_x                                      0x6AEC10
#define Teleport_Table_x                                           0xF20C98
#define Teleport_Table_Size_x                                      0xF22F6C

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423220
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DE90
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DC60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8010
#define AltAdvManager__IsAbilityReady_x                            0x4D8080
#define AltAdvManager__GetAAById_x                                 0x4D8570
#define AltAdvManager__CanTrainAbility_x                           0x4D91A0
#define AltAdvManager__CanSeeAbility_x                             0x4D8D60

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46ADE0
#define CharacterZoneClient__HasSkill_x                            0x466CF0
#define CharacterZoneClient__MakeMeVisible_x                       0x46C950
#define CharacterZoneClient__IsStackBlocked_x                      0x44BE30
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B350
#define CharacterZoneClient__GetItemCountWorn_x                    0x465250
#define CharacterZoneClient__GetItemCountInInventory_x             0x465330
#define CharacterZoneClient__GetCursorItemCount_x                  0x465410
#define CharacterZoneClient__FindAffectSlot_x                      0x4514E0
#define CharacterZoneClient__BardCastBard_x                        0x44AAC0
#define CharacterZoneClient__GetMaxEffects_x                       0x449650
#define CharacterZoneClient__GetEffect_x                           0x44B580
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451340
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4499A0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FE90

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66EE50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67CDB0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598A30
#define CButtonWnd__CButtonWnd_x                                   0x8DCCC0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x697DA0
#define CChatManager__InitContextMenu_x                            0x698EF0
#define CChatManager__FreeChatWindow_x                             0x697850
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A1090
#define CChatManager__SetLockedActiveChatWindow_x                  0x697D70

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6D20
#define CContextMenu__dCContextMenu_x                              0x8E6F30
#define CContextMenu__AddMenuItem_x                                0x8E7450
#define CContextMenu__RemoveMenuItem_x                             0x8E70B0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E70D0
#define CContextMenu__CheckMenuItem_x                              0x8E7150
#define CContextMenu__SetMenuItem_x                                0x8E6FD0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D3250
#define CContextMenuManager__RemoveMenu_x                          0x8D3600
#define CContextMenuManager__PopupMenu_x                           0x8D3A50
#define CContextMenuManager__Flush_x                               0x8D32C0
#define CContextMenuManager__GetMenu_x                             0x419360

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8865E0
#define CChatService__GetFriendName_x                              0x8865F0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69EB60
#define CChatWindow__Clear_x                                       0x69E440
#define CChatWindow__WndNotification_x                             0x69F470

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D70D0
#define CComboWnd__Draw_x                                          0x8D72E0
#define CComboWnd__GetCurChoice_x                                  0x8D6E80
#define CComboWnd__GetListRect_x                                   0x8D7580
#define CComboWnd__GetTextRect_x                                   0x8D7140
#define CComboWnd__InsertChoice_x                                  0x8D76E0
#define CComboWnd__SetColors_x                                     0x8D6E10
#define CComboWnd__SetChoice_x                                     0x8D6E40
#define CComboWnd__GetItemCount_x                                  0x8D6E70
#define CComboWnd__GetCurChoiceText_x                              0x8D6EC0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A8D90
#define CContainerWnd__vftable_x                                   0xAED9F8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5EC0
#define CDisplay__GetClickedActor_x                                0x4BE780
#define CDisplay__GetUserDefinedColor_x                            0x4BD360
#define CDisplay__GetWorldFilePath_x                               0x4BC7B0
#define CDisplay__is3dON_x                                         0x4BBC40
#define CDisplay__ReloadUI_x                                       0x4CFC80
#define CDisplay__WriteTextHD2_x                                   0x4C2250
#define CDisplay__TrueDistance_x                                   0x4BF3B0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FDED0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB280
#define CEditWnd__GetCharIndexPt_x                                 0x8EC3E0
#define CEditWnd__GetDisplayString_x                               0x8EB430
#define CEditWnd__GetHorzOffset_x                                  0x8EB770
#define CEditWnd__GetLineForPrintableChar_x                        0x8EBEA0
#define CEditWnd__GetSelStartPt_x                                  0x8EC6A0
#define CEditWnd__GetSTMLSafeText_x                                0x8EB910
#define CEditWnd__PointFromPrintableChar_x                         0x8EBF90
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC110
#define CEditWnd__SetEditable_x                                    0x8EB8E0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A070
#define CEverQuest__ClickedPlayer_x                                0x563C40
#define CEverQuest__CreateTargetIndicator_x                        0x564B40
#define CEverQuest__DeleteTargetIndicator_x                        0x564BC0
#define CEverQuest__DoTellWindow_x                                 0x4760A0
#define CEverQuest__OutputTextToLog_x                              0x475D00
#define CEverQuest__DropHeldItemOnGround_x                         0x57A5E0
#define CEverQuest__dsp_chat_x                                     0x4763E0
#define CEverQuest__trimName_x                                     0x560550
#define CEverQuest__Emote_x                                        0x5788F0
#define CEverQuest__EnterZone_x                                    0x5739D0
#define CEverQuest__GetBodyTypeDesc_x                              0x55DF90
#define CEverQuest__GetClassDesc_x                                 0x567480
#define CEverQuest__GetClassThreeLetterCode_x                      0x567A80
#define CEverQuest__GetDeityDesc_x                                 0x55E870
#define CEverQuest__GetLangDesc_x                                  0x55E320
#define CEverQuest__GetRaceDesc_x                                  0x567C40
#define CEverQuest__InterpretCmd_x                                 0x56B7F0
#define CEverQuest__LeftClickedOnPlayer_x                          0x580140
#define CEverQuest__LMouseUp_x                                     0x5820F0
#define CEverQuest__RightClickedOnPlayer_x                         0x580C50
#define CEverQuest__RMouseUp_x                                     0x581B50
#define CEverQuest__SetGameState_x                                 0x564510
#define CEverQuest__UPCNotificationFlush_x                         0x55C920
#define CEverQuest__IssuePetCommand_x                              0x56C1D0
#define CEverQuest__ReportSuccessfulHit_x                          0x574EA0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B9A80
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9AE0
#define CGaugeWnd__Draw_x                                          0x6B9F10

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B090
#define CGuild__GetGuildName_x                                     0x43B560
#define CGuild__GetGuildIndex_x                                    0x43C770

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D5F90

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E3380
#define CInvSlotMgr__MoveItem_x                                    0x6E3B40
#define CInvSlotMgr__SelectSlot_x                                  0x6E2C70

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E20D0
#define CInvSlot__SliderComplete_x                                 0x6DF8F0
#define CInvSlot__GetItemBase_x                                    0x6DED50
#define CInvSlot__UpdateItem_x                                     0x6DF2D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E4FA0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E60D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AE210
#define CItemDisplayWnd__UpdateStrings_x                           0x6E71E0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F3A70
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F3FA0
#define CItemDisplayWnd__SetItem_x                                 0x6F98E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E5390

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ED770

// CLabel 
#define CLabel__Draw_x                                             0x7007C0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2B60
#define CListWnd__dCListWnd_x                                      0x8C3E10
#define CListWnd__AddColumn_x                                      0x8C3DB0
#define CListWnd__AddColumn1_x                                     0x8C3450
#define CListWnd__AddLine_x                                        0x8C2E30
#define CListWnd__AddString_x                                      0x8C3050
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BFC60
#define CListWnd__CalculateVSBRange_x                              0x8C2020
#define CListWnd__ClearSel_x                                       0x8BEF70
#define CListWnd__ClearAllSel_x                                    0x8BEF20
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C29F0
#define CListWnd__Compare_x                                        0x8C0950
#define CListWnd__Draw_x                                           0x8C1C20
#define CListWnd__DrawColumnSeparators_x                           0x8C1AB0
#define CListWnd__DrawHeader_x                                     0x8BF230
#define CListWnd__DrawItem_x                                       0x8C0FE0
#define CListWnd__DrawLine_x                                       0x8C1750
#define CListWnd__DrawSeparator_x                                  0x8C1B50
#define CListWnd__EnableLine_x                                     0x8BF150
#define CListWnd__EnsureVisible_x                                  0x8BFDC0
#define CListWnd__ExtendSel_x                                      0x8C0EF0
#define CListWnd__GetColumnMinWidth_x                              0x8BE860
#define CListWnd__GetColumnWidth_x                                 0x8BE790
#define CListWnd__GetCurSel_x                                      0x8BDF50
#define CListWnd__GetItemAtPoint_x                                 0x8C0060
#define CListWnd__GetItemAtPoint1_x                                0x8C00D0
#define CListWnd__GetItemData_x                                    0x8BE2A0
#define CListWnd__GetItemHeight_x                                  0x8BF8B0
#define CListWnd__GetItemIcon_x                                    0x8BE490
#define CListWnd__GetItemRect_x                                    0x8BFEA0
#define CListWnd__GetItemText_x                                    0x8BE340
#define CListWnd__GetSelList_x                                     0x8C3340
#define CListWnd__GetSeparatorRect_x                               0x8C0870
#define CListWnd__InsertLine_x                                     0x8C3230
#define CListWnd__RemoveLine_x                                     0x8C3240
#define CListWnd__SetColors_x                                      0x8BE0A0
#define CListWnd__SetColumnJustification_x                         0x8BEAF0
#define CListWnd__SetColumnWidth_x                                 0x8BE810
#define CListWnd__SetCurSel_x                                      0x8BDF90
#define CListWnd__SetItemColor_x                                   0x8C26E0
#define CListWnd__SetItemData_x                                    0x8BEFD0
#define CListWnd__SetItemText_x                                    0x8C2520
#define CListWnd__ShiftColumnSeparator_x                           0x8C23B0
#define CListWnd__Sort_x                                           0x8C3F10
#define CListWnd__ToggleSel_x                                      0x8BEEA0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7197B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73EFF0
#define CMerchantWnd__RequestBuyItem_x                             0x746B90
#define CMerchantWnd__RequestSellItem_x                            0x749200
#define CMerchantWnd__SelectRecoverySlot_x                         0x73C2C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73A160
#define CMerchantWnd__ActualSelect_x                               0x740DD0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8547A0
#define CPacketScrambler__hton_x                                   0x8547B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E1C40
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1D20
#define CSidlManager__CreateLabel_x                                0x7A31B0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E01E0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E2000

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D9130
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D9020
#define CSidlScreenWnd__ConvertToRes_x                             0x8FDDB0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9A50
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DAC10
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DACC0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA1A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D9400
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8B50
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D95F0
#define CSidlScreenWnd__Init1_x                                    0x8DA8F0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9B10
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8D10
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA3E0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D87B0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8B00
#define CSidlScreenWnd__WndNotification_x                          0x8DA670
#define CSidlScreenWnd__GetChildItem_x                             0x8D8C20
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC480
#define CSidlScreenWnd__m_layoutCopy_x                             0x1730E20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x604EB0
#define CSkillMgr__GetSkillCap_x                                   0x605090
#define CSkillMgr__GetNameToken_x                                  0x604A60

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FD060
#define CSliderWnd__SetValue_x                                     0x8FD230
#define CSliderWnd__SetNumTicks_x                                  0x8FD9B0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A94F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6D40
#define CStmlWnd__CalculateHSBRange_x                              0x8EF280
#define CStmlWnd__CalculateVSBRange_x                              0x8EF1F0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF400
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EFC00
#define CStmlWnd__ForceParseNow_x                                  0x8F76C0
#define CStmlWnd__GetNextTagPiece_x                                0x8EFB00
#define CStmlWnd__GetSTMLText_x                                    0x4843C0
#define CStmlWnd__GetVisibleText_x                                 0x8F0650
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2C20
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE4D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE530
#define CStmlWnd__SetSTMLText_x                                    0x8F4480
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F69E0
#define CStmlWnd__UpdateHistoryString_x                            0x8F1590

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FABE0
#define CTabWnd__DrawCurrentPage_x                                 0x8FA470
#define CTabWnd__DrawTab_x                                         0x8FA230
#define CTabWnd__GetCurrentPage_x                                  0x8FA820
#define CTabWnd__GetPageInnerRect_x                                0x8F9F20
#define CTabWnd__GetTabInnerRect_x                                 0x8FA120
#define CTabWnd__GetTabRect_x                                      0x8F9FF0
#define CTabWnd__InsertPage_x                                      0x8FAED0
#define CTabWnd__SetPage_x                                         0x8FA850
#define CTabWnd__SetPageRect_x                                     0x8FAB20
#define CTabWnd__UpdatePage_x                                      0x8FAE70
#define CTabWnd__GetPageFromTabIndex_x                             0x8FA180
#define CTabWnd__GetCurrentTabIndex_x                              0x8F9EB0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E6280
#define CPageWnd__SetTabText_x                                     0x9071F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436C90

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6A80
#define CTextureFont__GetTextExtent_x                              0x8D67E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63D840

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903630

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC060

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A6610
#define CXStr__CXStr1_x                                            0x8B0E80
#define CXStr__CXStr3_x                                            0x89F290
#define CXStr__dCXStr_x                                            0x47C000
#define CXStr__operator_equal_x                                    0x89F400
#define CXStr__operator_equal1_x                                   0x89F450
#define CXStr__operator_plus_equal1_x                              0x8A0550

// CXWnd 
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D4570
#define CXWnd__BringToTop_x                                        0x8CB690
#define CXWnd__Center_x                                            0x8D1830
#define CXWnd__ClrFocus_x                                          0x8CB280
#define CXWnd__Destroy_x                                           0x8D2320
#define CXWnd__DoAllDrawing_x                                      0x8D1460
#define CXWnd__DrawChildren_x                                      0x8D1610
#define CXWnd__DrawColoredRect_x                                   0x8CBA80
#define CXWnd__DrawTooltip_x                                       0x8CBD30
#define CXWnd__DrawTooltipAtPoint_x                                0x8D03F0
#define CXWnd__GetBorderFrame_x                                    0x8CC150
#define CXWnd__GetChildWndAt_x                                     0x8D2200
#define CXWnd__GetClientClipRect_x                                 0x8CBF50
#define CXWnd__GetScreenClipRect_x                                 0x8D0AF0
#define CXWnd__GetScreenRect_x                                     0x8CC320
#define CXWnd__GetTooltipRect_x                                    0x8CBBC0
#define CXWnd__GetWindowTextA_x                                    0x426D00
#define CXWnd__IsActive_x                                          0x8C6C30
#define CXWnd__IsDescendantOf_x                                    0x8CC090
#define CXWnd__IsReallyVisible_x                                   0x8CF410
#define CXWnd__IsType_x                                            0x8D18A0
#define CScreenPieceTemplate__IsType_x                             0x8FFD40
#define CXWnd__Move_x                                              0x8CEB80
#define CXWnd__Move1_x                                             0x8D1130
#define CXWnd__ProcessTransition_x                                 0x8CB640
#define CXWnd__Refade_x                                            0x8CB420
#define CXWnd__Resize_x                                            0x8CC3E0
#define CXWnd__Right_x                                             0x8D08F0
#define CXWnd__SetFocus_x                                          0x8CDCE0
#define CXWnd__SetFont_x                                           0x8CB2D0
#define CXWnd__SetKeyTooltip_x                                     0x8CC650
#define CXWnd__SetMouseOver_x                                      0x8D0E30
#define CXWnd__StartFade_x                                         0x8CB6E0
#define CXWnd__GetChildItem_x                                      0x8D0D80
#define CXWnd__SetParent_x                                         0x8D21B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C84E0
#define CXWndManager__DrawWindows_x                                0x8C8120
#define CXWndManager__GetKeyboardFlags_x                           0x8C6760
#define CXWndManager__HandleKeyboardMsg_x                          0x8C70C0
#define CXWndManager__RemoveWnd_x                                  0x8C6DC0

// CDBStr
#define CDBStr__GetString_x                                        0x4BA480

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4525A0
#define EQ_Character__Cur_HP_x                                     0x4668D0
#define EQ_Character__Cur_Mana_x                                   0x45B8D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B660
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443630
#define EQ_Character__GetFocusRangeModifier_x                      0x443780
#define EQ_Character__GetHPRegen_x                                 0x46A470
#define EQ_Character__GetEnduranceRegen_x                          0x465EE0
#define EQ_Character__GetManaRegen_x                               0x46AA10
#define EQ_Character__Max_Endurance_x                              0x5CB630
#define EQ_Character__Max_HP_x                                     0x45E450
#define EQ_Character__Max_Mana_x                                   0x5CB460
#define EQ_Character__doCombatAbility_x                            0x5C8B30
#define EQ_Character__UseSkill_x                                   0x472800
#define EQ_Character__GetConLevel_x                                0x5BE2C0
#define EQ_Character__IsExpansionFlag_x                            0x4B67E0
#define EQ_Character__TotalEffect_x                                0x44F7D0
#define EQ_Character__GetPCSpellAffect_x                           0x44B9F0
#define EQ_Character__SpellDuration_x                              0x4499F0
#define EQ_Character__FindItemByRecord_x                           0x463F40
#define EQ_Character__GetAdjustedSkill_x                           0x466AA0
#define EQ_Character__GetBaseSkill_x                               0x45E330
#define EQ_Character__CanUseItem_x                                 0x45E330

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8727F0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D3D20

//PcClient
#define PcClient__PcClient_x                                       0x5C0100

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446B20
#define CCharacterSelect__EnterWorld_x                             0x4462F0
#define CCharacterSelect__Quit_x                                   0x444EB0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59E350
#define EQ_Item__CreateItemTagString_x                             0x852910
#define EQ_Item__IsStackable_x                                     0x847C10
#define EQ_Item__GetImageNum_x                                     0x84A710
#define EQ_Item__CreateItemClient_x                                0x59F480
#define EQ_Item__GetItemValue_x                                    0x851370
#define EQ_Item__ValueSellMerchant_x                               0x8543F0
#define EQ_Item__IsKeyRingItem_x                                   0x848700
#define EQ_Item__CanGoInBag_x                                      0x59E4E0
#define EQ_Item__GetMaxItemCount_x                                 0x847B00
#define EQ_Item__GetHeldItem_x                                     0x849530
#define EQ_Item__GetAugmentFitBySlot_x                             0x854210

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA5C0
#define EQ_LoadingS__Array_x                                       0xC0BC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CDB50
#define EQ_PC__GetAlternateAbilityId_x                             0x85C980
#define EQ_PC__GetCombatAbility_x                                  0x85CA10
#define EQ_PC__GetCombatAbilityTimer_x                             0x857450
#define EQ_PC__GetItemRecastTimer_x                                0x5C7320
#define EQ_PC__HasLoreItem_x                                       0x5C18C0
#define EQ_PC__AlertInventoryChanged_x                             0x5BE270
#define EQ_PC__GetPcZoneClient_x                                   0x5E8280
#define EQ_PC__RemoveMyAffect_x                                    0x5C6750
#define EQ_PC__GetKeyRingItems_x                                   0x857870
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86A710
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85E950

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5266E0
#define EQItemList__add_object_x                                   0x5537B0
#define EQItemList__add_item_x                                     0x526620
#define EQItemList__delete_item_x                                  0x526AD0
#define EQItemList__FreeItemList_x                                 0x5269D0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9740

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D39E0
#define EQPlayer__dEQPlayer_x                                      0x5DC1A0
#define EQPlayer__DoAttack_x                                       0x5EDA10
#define EQPlayer__EQPlayer_x                                       0x5DE8C0
#define EQPlayer__SetNameSpriteState_x                             0x5D8FD0
#define EQPlayer__SetNameSpriteTint_x                              0x5D4EE0
#define PlayerBase__HasProperty_j_x                                0x9310D0
#define EQPlayer__IsTargetable_x                                   0x931370
#define EQPlayer__CanSee_x                                         0x9318D0
#define PlayerZoneClient__ChangeHeight_x                           0x5ED8D0
#define EQPlayer__CanSee1_x                                        0x9319C0
#define PlayerBase__GetVisibilityLineSegment_x                     0x931660

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8430
#define PlayerZoneClient__IsValidTeleport_x                        0x554070
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2870

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E28B0
#define EQPlayerManager__GetSpawnByName_x                          0x5E2D10
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E28E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A49A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A49E0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4590
#define KeypressHandler__HandleKeyDown_x                           0x5A2EB0
#define KeypressHandler__HandleKeyUp_x                             0x5A31D0
#define KeypressHandler__SaveKeymapping_x                          0x5A4660

// MapViewMap 
#define MapViewMap__Clear_x                                        0x712140
#define MapViewMap__SaveEx_x                                       0x715470
#define MapViewMap__SetZoom_x                                      0x711DC0

#define PlayerPointManager__GetAltCurrency_x                       0x8708B0

// StringTable 
#define StringTable__getString_x                                   0x86AA40

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB0C0
#define PcZoneClient__RemovePetEffect_x                            0x5C77F0
#define PcZoneClient__HasAlternateAbility_x                        0x5C8190
#define PcZoneClient__GetCurrentMod_x                              0x45D900
#define PcZoneClient__GetModCap_x                                  0x45B030
#define PcZoneClient__CanEquipItem_x                               0x5C8670
#define PcZoneClient__GetItemByID_x                                0x5CCED0
#define PcZoneClient__GetItemByItemClass_x                         0x5CDA70
#define PcZoneClient__RemoveBuffEffect_x                           0x5C6A00

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B1A0

//IconCache
#define IconCache__GetIcon_x                                       0x6AF240

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A6120
#define CContainerMgr__CloseContainer_x                            0x6A6940

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x773080

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x597450

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4E40
#define EQ_Spell__SpellAffects_x                                   0x4F2020
#define EQ_Spell__SpellAffectBase_x                                0x4F2090
#define CharacterZoneClient__CalcAffectChange_x                    0x44B880
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AB20
#define CLootWnd__LootAll_x                                        0x707A20
#define CLootWnd__RequestLootSlot_x                                0x708230
#define EQ_Spell__IsStackable_x                                    0x459090
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4494C0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EB70
#define EQ_Spell__IsSPAStacking_x                                  0x4F1B90
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2C30
#define EQ_Spell__IsNoRemove_x                                     0x434CD0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1BB0

#define __IsResEffectSpell_x                                       0x449540

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87C480

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BAE70
#define CTargetWnd__WndNotification_x                              0x7BA960
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BB050

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7BFFB0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED660
#define EqSoundManager__PlayScriptMp3_x                            0x4EF100

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8870

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EA8B0
#define CSidlManager__FindAnimation1_x                             0x8DFC10

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1F20
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1ED0
#define CAltAbilityData__GetMaxRank_x                              0x4D66C0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5950A0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459370
#define CharacterBase__CreateItemGlobalIndex_x                     0x475230
#define CharacterBase__CreateItemIndex_x                           0x51FCE0
#define CharacterBase__GetItemPossession_x                         0x444350
#define CharacterBase__GetItemByGlobalIndex_x                      0x8802C0
#define CharacterBase__GetEffectId_x                               0x459330

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68EFD0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68E730

//messages
#define msg_spell_worn_off_x                                       0x4FC950
#define msg_new_text_x                                             0x5060D0
#define msgTokenTextParam_x                                        0x5028D0

//SpellManager
#define SpellManager__vftable_x                                    0xAC9260
#define SpellManager__SpellManager_x                               0x47DEA0
#define Spellmanager__LoadTextSpells_x                             0x60BD40

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935470

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487C60
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EA90
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449220
#define ItemGlobalIndex__IsValidIndex_x                            0x458BD0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87E140
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87D080

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x700A10

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AAE60
#define CCursorAttachment__Deactivate_x                            0x6AA3A0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FC560
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FC6E0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C4B0

//IString
#define IString__Append_x                                          0x47EBC0

//Camera
#define CDisplay__cameraType_x                                     0xE6F7C8
#define EverQuest__Cameras_x                                       0xF31AC8

//LootFiltersManager
#define pinstLootFiltersManager_x                                  0xD3C248
#define LootFiltersManager__AddItemLootFilter_x                    0x4940E0
