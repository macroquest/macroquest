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
#define __ExpectedVersionDate                                     "Oct 12 2017"
#define __ExpectedVersionTime                                     "10:52:35"
#define __ActualVersionDate_x                                      0xAE6390
#define __ActualVersionTime_x                                      0xAE639C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5AB8A0
#define __MemChecker1_x                                            0x8A3ED0
#define __MemChecker2_x                                            0x6418F0
#define __MemChecker3_x                                            0x641840
#define __MemChecker4_x                                            0x7F5A10
#define __EncryptPad0_x                                            0xC432B0
#define __EncryptPad1_x                                            0xD1ED68
#define __EncryptPad2_x                                            0xC6CCF0
#define __EncryptPad3_x                                            0xC6C8F0
#define __EncryptPad4_x                                            0xD0D368
#define __EncryptPad5_x                                            0x10C85A0
#define __AC1_x                                                    0x7B49B5
#define __AC2_x                                                    0x564627
#define __AC3_x                                                    0x5627A0
#define __AC4_x                                                    0x5749C1
#define __AC5_x                                                    0x58887B
#define __AC6_x                                                    0x58C42E
#define __AC7_x                                                    0x582E7C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4B90

// Direct Input
#define DI8__Main_x                                                0x10C8578
#define DI8__Keyboard_x                                            0x10C857C
#define DI8__Mouse_x                                               0x10C8580
#define DI8__Mouse_Copy_x                                          0xF366A4
#define DI8__Mouse_Check_x                                         0xFC0264
#define __AutoSkillArray_x                                         0xF375B8
#define __Attack_x                                                 0xFBABBB
#define __Autofire_x                                               0xFBABBC
#define __BindList_x                                               0xC1DDB0
#define g_eqCommandStates_x                                        0xF253F0
#define __Clicks_x                                                 0xF36760
#define __CommandList_x                                            0xC204B0
#define __CurrentMapLabel_x                                        0x10CE570
#define __CurrentSocial_x                                          0xBED4E0
#define __DoAbilityList_x                                          0xF6CE70
#define __do_loot_x                                                0x533310
#define __DrawHandler_x                                            0x1735AF4
#define __GroupCount_x                                             0xF26CFA

#define __Guilds_x                                                 0xF2C910
#define __gWorld_x                                                 0xF291B4
#define __HotkeyPage_x                                             0xFB3870
#define __HWnd_x                                                   0xFC0380
#define __InChatMode_x                                             0xF3668C
#define __LastTell_x                                               0xF3856C
#define __LMouseHeldTime_x                                         0xF367CC
#define __Mouse_x                                                  0x10C8584
#define __MouseLook_x                                              0xF36726
#define __MouseEventTime_x                                         0xFBB444
#define __gpbCommandEvent_x                                        0xF2927C
#define __NetStatusToggle_x                                        0xF36729
#define __PCNames_x                                                0xF37B7C
#define __RangeAttackReady_x                                       0xF3789C
#define __RMouseHeldTime_x                                         0xF367C8
#define __RunWalkState_x                                           0xF36690
#define __ScreenMode_x                                             0xE74FD0
#define __ScreenX_x                                                0xF36644
#define __ScreenY_x                                                0xF36640
#define __ScreenXMax_x                                             0xF36648
#define __ScreenYMax_x                                             0xF3664C
#define __ServerHost_x                                             0xF26C44
#define __ServerName_x                                             0xF6CE30
#define __ShiftKeyDown_x                                           0xF36D20
#define __ShowNames_x                                              0xF37A5C
#define __Socials_x                                                0xF6CF30
#define __SubscriptionType_x                                       0x10FC5FC
#define __TargetAggroHolder_x                                      0x10D07BC
#define __ZoneType_x                                               0xF36B24
#define __GroupAggro_x                                             0x10D07FC
#define __LoginName_x                                              0xFBEE5C
#define __Inviter_x                                                0xFBAB38
#define __AttackOnAssist_x                                         0xF37A18
#define __UseTellWindows_x                                         0xF37D14

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF292A0
#define instEQZoneInfo_x                                           0xF3691C
#define instKeypressHandler_x                                      0xFBB428
#define pinstActiveBanker_x                                        0xF29258
#define pinstActiveCorpse_x                                        0xF2925C
#define pinstActiveGMaster_x                                       0xF29260
#define pinstActiveMerchant_x                                      0xF29254
#define pinstAggroInfo_x                                           0xD32628
#define pinstAltAdvManager_x                                       0xE76138
#define pinstAuraMgr_x                                             0xD42E40
#define pinstBandageTarget_x                                       0xF29240
#define pinstCamActor_x                                            0xE75A08
#define pinstCDBStr_x                                              0xE74F64
#define pinstCDisplay_x                                            0xF29268
#define pinstCEverQuest_x                                          0x10C86F8
#define pinstEverQuestInfo_x                                       0xF36638
#define pinstCharData_x                                            0xF29224
#define pinstCharSpawn_x                                           0xF2924C
#define pinstControlledMissile_x                                   0xF29220
#define pinstControlledPlayer_x                                    0xF2924C
#define pinstCSidlManager_x                                        0x1734A60
#define pinstCXWndManager_x                                        0x1734A58
#define instDynamicZone_x                                          0xF364D8
#define pinstDZMember_x                                            0xF365E8
#define pinstDZTimerInfo_x                                         0xF365EC
#define pinstEQItemList_x                                          0xF256C8
#define pinstEQObjectList_x                                        0xF266F4
#define instEQMisc_x                                               0xC062B8
#define pinstEQSoundManager_x                                      0xE76708
#define instExpeditionLeader_x                                     0xF36522
#define instExpeditionName_x                                       0xF36562
#define pinstGroup_x                                               0xF26CF6
#define pinstImeManager_x                                          0x1734A64
#define pinstLocalPlayer_x                                         0xF29238
#define pinstMercenaryData_x                                       0xFBBAA8
#define pinstMercenaryStats_x                                      0x10D0908
#define pinstMercAltAbilities_x                                    0xE764C0
#define pinstModelPlayer_x                                         0xF29264
#define pinstPCData_x                                              0xF29224
#define pinstSkillMgr_x                                            0xFBCB18
#define pinstSpawnManager_x                                        0xFBC2F8
#define pinstSpellManager_x                                        0xFBCC60
#define pinstSpellSets_x                                           0xFB38D4
#define pinstStringTable_x                                         0xF291CC
#define pinstSwitchManager_x                                       0xF26888
#define pinstTarget_x                                              0xF29250
#define pinstTargetObject_x                                        0xF29228
#define pinstTargetSwitch_x                                        0xF2922C
#define pinstTaskMember_x                                          0xE74EB0
#define pinstTrackTarget_x                                         0xF29244
#define pinstTradeTarget_x                                         0xF29234
#define instTributeActive_x                                        0xC062DD
#define pinstViewActor_x                                           0xE75A04
#define pinstWorldData_x                                           0xF29208
#define pinstZoneAddr_x                                            0xF36BBC
#define pinstPlayerPath_x                                          0xFBC358
#define pinstTargetIndicator_x                                     0xFBCDF8
#define pinstCTargetManager_x                                      0xFBCE58
#define EQObject_Top_x                                             0xF29218
#define pinstRealEstateItems_x                                     0xFBC984

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE75920
#define pinstCAchievementsWnd_x                                    0xE7597C
#define pinstCTextOverlay_x                                        0xD32BD0
#define pinstCAudioTriggersWindow_x                                0xD329B8
#define pinstCCharacterSelect_x                                    0xE7588C
#define pinstCFacePick_x                                           0xE7563C
#define pinstCFindItemWnd_x                                        0xE7591C
#define pinstCNoteWnd_x                                            0xE75844
#define pinstCBookWnd_x                                            0xE7584C
#define pinstCPetInfoWnd_x                                         0xE75850
#define pinstCTrainWnd_x                                           0xE75854
#define pinstCSkillsWnd_x                                          0xE75858
#define pinstCSkillsSelectWnd_x                                    0xE7585C
#define pinstCCombatSkillsSelectWnd_x                              0xE75860
#define pinstCFriendsWnd_x                                         0xE75864
#define pinstCAuraWnd_x                                            0xE75868
#define pinstCRespawnWnd_x                                         0xE7586C
#define pinstCBandolierWnd_x                                       0xE75870
#define pinstCPotionBeltWnd_x                                      0xE75874
#define pinstCAAWnd_x                                              0xE75878
#define pinstCGroupSearchFiltersWnd_x                              0xE7587C
#define pinstCLoadskinWnd_x                                        0xE75880
#define pinstCAlarmWnd_x                                           0xE75884
#define pinstCMusicPlayerWnd_x                                     0xE75888
#define pinstCMailWnd_x                                            0xE75890
#define pinstCMailCompositionWnd_x                                 0xE75894
#define pinstCMailAddressBookWnd_x                                 0xE75898
#define pinstCRaidWnd_x                                            0xE758A0
#define pinstCRaidOptionsWnd_x                                     0xE758A4
#define pinstCBreathWnd_x                                          0xE758A8
#define pinstCMapViewWnd_x                                         0xE758AC
#define pinstCMapToolbarWnd_x                                      0xE758B0
#define pinstCEditLabelWnd_x                                       0xE758B4
#define pinstCTargetWnd_x                                          0xE758B8
#define pinstCColorPickerWnd_x                                     0xE758BC
#define pinstCPlayerWnd_x                                          0xE758C0
#define pinstCOptionsWnd_x                                         0xE758C4
#define pinstCBuffWindowNORMAL_x                                   0xE758C8
#define pinstCBuffWindowSHORT_x                                    0xE758CC
#define pinstCharacterCreation_x                                   0xE758D0
#define pinstCCursorAttachment_x                                   0xE758D4
#define pinstCCastingWnd_x                                         0xE758D8
#define pinstCCastSpellWnd_x                                       0xE758DC
#define pinstCSpellBookWnd_x                                       0xE758E0
#define pinstCInventoryWnd_x                                       0xE758E4
#define pinstCBankWnd_x                                            0xE758EC
#define pinstCQuantityWnd_x                                        0xE758F0
#define pinstCLootWnd_x                                            0xE758F4
#define pinstCActionsWnd_x                                         0xE758F8
#define pinstCCombatAbilityWnd_x                                   0xE75900
#define pinstCMerchantWnd_x                                        0xE75904
#define pinstCTradeWnd_x                                           0xE7590C
#define pinstCSelectorWnd_x                                        0xE75910
#define pinstCBazaarWnd_x                                          0xE75914
#define pinstCBazaarSearchWnd_x                                    0xE75918
#define pinstCGiveWnd_x                                            0xE75938
#define pinstCTrackingWnd_x                                        0xE75940
#define pinstCInspectWnd_x                                         0xE75944
#define pinstCSocialEditWnd_x                                      0xE75948
#define pinstCFeedbackWnd_x                                        0xE7594C
#define pinstCBugReportWnd_x                                       0xE75950
#define pinstCVideoModesWnd_x                                      0xE75954
#define pinstCTextEntryWnd_x                                       0xE7595C
#define pinstCFileSelectionWnd_x                                   0xE75960
#define pinstCCompassWnd_x                                         0xE75964
#define pinstCPlayerNotesWnd_x                                     0xE75968
#define pinstCGemsGameWnd_x                                        0xE7596C
#define pinstCTimeLeftWnd_x                                        0xE75988
#define pinstCPetitionQWnd_x                                       0xE7598C
#define pinstCStoryWnd_x                                           0xE75990
#define pinstCJournalTextWnd_x                                     0xE75994
#define pinstCJournalCatWnd_x                                      0xE75998
#define pinstCBodyTintWnd_x                                        0xE7599C
#define pinstCServerListWnd_x                                      0xE759A0
#define pinstCAvaZoneWnd_x                                         0xE759AC
#define pinstCBlockedBuffWnd_x                                     0xE759B0
#define pinstCBlockedPetBuffWnd_x                                  0xE759B4
#define pinstCInvSlotMgr_x                                         0xE759FC
#define pinstCContainerMgr_x                                       0xE75A00
#define pinstCAdventureLeaderboardWnd_x                            0x10C90A8
#define pinstCAdventureRequestWnd_x                                0x10C9120
#define pinstCAltStorageWnd_x                                      0x10C9400
#define pinstCAdventureStatsWnd_x                                  0x10C9198
#define pinstCBarterMerchantWnd_x                                  0x10CA148
#define pinstCBarterSearchWnd_x                                    0x10CA1C0
#define pinstCBarterWnd_x                                          0x10CA238
#define pinstCChatWindowManager_x                                  0x10CAA48
#define pinstCDynamicZoneWnd_x                                     0x10CAF78
#define pinstCEQMainWnd_x                                          0x10CB140
#define pinstCFellowshipWnd_x                                      0x10CAF0C
#define pinstCFindLocationWnd_x                                    0x10CB410
#define pinstCGroupSearchWnd_x                                     0x10CB6E0
#define pinstCGroupWnd_x                                           0x10CB758
#define pinstCGuildBankWnd_x                                       0x10CB7D0
#define pinstCGuildMgmtWnd_x                                       0x10CD8C0
#define pinstCHotButtonWnd_x                                       0x10CD9BC
#define pinstCHotButtonWnd1_x                                      0x10CD9BC
#define pinstCHotButtonWnd2_x                                      0x10CD9C0
#define pinstCHotButtonWnd3_x                                      0x10CD9C4
#define pinstCHotButtonWnd4_x                                      0x10CD9E8
#define pinstCItemDisplayManager_x                                 0x10CDE40
#define pinstCItemExpTransferWnd_x                                 0x10CDF3C
#define pinstCLFGuildWnd_x                                         0x10CE218
#define pinstCMIZoneSelectWnd_x                                    0x10CE7F8
#define pinstCConfirmationDialog_x                                 0x10CEF00
#define pinstCPopupWndManager_x                                    0x10CEF00
#define pinstCProgressionSelectionWnd_x                            0x10CEFF0
#define pinstCPvPStatsWnd_x                                        0x10CF0E0
#define pinstCLargeDialogWnd_x                                     0x10CF868
#define pinstCTaskWnd_x                                            0x10D0BE8
#define pinstCTaskSomething_x                                      0xD43A58
#define pinstCTaskTemplateSelectWnd_x                              0x10D0B70
#define pinstCTipWndOFDAY_x                                        0x10D0D50
#define pinstCTipWndCONTEXT_x                                      0x10D0D54
#define pinstCTitleWnd_x                                           0x10D0DD0
#define pinstCContextMenuManager_x                                 0x17348E8
#define pinstCVoiceMacroWnd_x                                      0xFBD230
#define pinstCHtmlWnd_x                                            0xFBD320
#define pinstItemIconCache_x                                       0x10CB0E8
#define pinstCTradeskillWnd_x                                      0x10D0ED0
#define pinstCAdvancedLootWnd_x                                    0xE759F0
#define pinstRewardSelectionWnd_x                                  0x10CF608
#define pinstEQSuiteTextureLoader_x                                0xD20C30
#define pinstCPointMerchantWnd_x                                   0x10CEE88

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54AD80
#define __CastRay2_x                                               0x54A6B0
#define __HeadingDiff_x                                            0x9340E0
#define __FixHeading_x                                             0x934070
#define __get_bearing_x                                            0x53A460
#define __ConvertItemTags_x                                        0x537F30
#define __ExecuteCmd_x                                             0x522820
#define __EQGetTime_x                                              0x8A3870
#define __get_melee_range_x                                        0x5294D0
#define __GetGaugeValueFromEQ_x                                    0x7B3570
#define __GetLabelFromEQ_x                                         0x7B4940
#define __ToggleKeyRingItem_x                                      0x490F10
#define __GetXTargetType_x                                         0x935CE0
#define __LoadFrontEnd_x                                           0x640FC0
#define __NewUIINI_x                                               0x7B2F50
#define __ProcessGameEvents_x                                      0x584C10
#define __ProcessMouseEvent_x                                      0x5843B0
#define CrashDetected_x                                            0x642980
#define wwsCrashReportCheckForUploader_x                           0x8015A0
#define __AppCrashWrapper_x                                        0xC6C8E4
#define __pCrashHandler_x                                          0x10DDDB0
#define __CrashHandler_x                                           0x801030
#define wwsCrashReportPlatformLaunchUploader_x                     0x8037D0
#define DrawNetStatus_x                                            0x5BB210
#define Util__FastTime_x                                           0x8A3510
#define Expansion_HoT_x                                            0xF37A08
#define __HelpPath_x                                               0xFBB1B0
#define __STMLToText_x                                             0x8E9D90
#define __GetAnimationCache_x                                      0x6B0460

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423360
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DFF0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DDC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D9430
#define AltAdvManager__IsAbilityReady_x                            0x4D94A0
#define AltAdvManager__GetAAById_x                                 0x4D9990
#define AltAdvManager__CanTrainAbility_x                           0x4DA5C0
#define AltAdvManager__CanSeeAbility_x                             0x4DA180

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46ADC0
#define CharacterZoneClient__HasSkill_x                            0x466690
#define CharacterZoneClient__MakeMeVisible_x                       0x46C930
#define CharacterZoneClient__IsStackBlocked_x                      0x44C2D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B790
#define CharacterZoneClient__GetItemCountWorn_x                    0x464BF0
#define CharacterZoneClient__GetItemCountInInventory_x             0x464CD0
#define CharacterZoneClient__GetCursorItemCount_x                  0x464DB0
#define CharacterZoneClient__FindAffectSlot_x                      0x451900
#define CharacterZoneClient__BardCastBard_x                        0x44AF10
#define CharacterZoneClient__GetMaxEffects_x                       0x449AA0
#define CharacterZoneClient__GetEffect_x                           0x44B9C0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451760
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449DF0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4502B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6706D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67E5C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x59A4B0
#define CButtonWnd__CButtonWnd_x                                   0x8DE080

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x699590
#define CChatManager__InitContextMenu_x                            0x69A6E0
#define CChatManager__FreeChatWindow_x                             0x699040
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A2890
#define CChatManager__SetLockedActiveChatWindow_x                  0x699560

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E80F0
#define CContextMenu__dCContextMenu_x                              0x8E8300
#define CContextMenu__AddMenuItem_x                                0x8E8810
#define CContextMenu__RemoveMenuItem_x                             0x8E8470
#define CContextMenu__RemoveAllMenuItems_x                         0x8E8490
#define CContextMenu__CheckMenuItem_x                              0x8E8510

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D4650
#define CContextMenuManager__RemoveMenu_x                          0x8D49E0
#define CContextMenuManager__PopupMenu_x                           0x8D4E30
#define CContextMenuManager__Flush_x                               0x8D46C0
#define CContextMenuManager__GetMenu_x                             0x419560

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x887B10
#define CChatService__GetFriendName_x                              0x887B20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A0360
#define CChatWindow__Clear_x                                       0x69FC40
#define CChatWindow__WndNotification_x                             0x6A0C70

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D84A0
#define CComboWnd__Draw_x                                          0x8D86B0
#define CComboWnd__GetCurChoice_x                                  0x8D8250
#define CComboWnd__GetListRect_x                                   0x8D8950
#define CComboWnd__GetTextRect_x                                   0x8D8510
#define CComboWnd__InsertChoice_x                                  0x8D8AB0
#define CComboWnd__SetColors_x                                     0x8D81E0
#define CComboWnd__SetChoice_x                                     0x8D8210
#define CComboWnd__GetItemCount_x                                  0x8D8240
#define CComboWnd__GetCurChoiceText_x                              0x8D8290

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AA600
#define CContainerWnd__vftable_x                                   0xAEFC90

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C70F0
#define CDisplay__GetClickedActor_x                                0x4BF9B0
#define CDisplay__GetUserDefinedColor_x                            0x4BE590
#define CDisplay__GetWorldFilePath_x                               0x4BD9E0
#define CDisplay__is3dON_x                                         0x4BCE70
#define CDisplay__ReloadUI_x                                       0x4D10D0
#define CDisplay__WriteTextHD2_x                                   0x4C3480
#define CDisplay__TrueDistance_x                                   0x4C05E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FF340

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EC640
#define CEditWnd__GetCharIndexPt_x                                 0x8ED780
#define CEditWnd__GetDisplayString_x                               0x8EC7F0
#define CEditWnd__GetHorzOffset_x                                  0x8ECB30
#define CEditWnd__GetLineForPrintableChar_x                        0x8ED250
#define CEditWnd__GetSelStartPt_x                                  0x8EDA30
#define CEditWnd__GetSTMLSafeText_x                                0x8ECCC0
#define CEditWnd__PointFromPrintableChar_x                         0x8ED340
#define CEditWnd__SelectableCharFromPoint_x                        0x8ED4C0
#define CEditWnd__SetEditable_x                                    0x8ECC90

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56B1F0
#define CEverQuest__ClickedPlayer_x                                0x564D70
#define CEverQuest__CreateTargetIndicator_x                        0x565C70
#define CEverQuest__DeleteTargetIndicator_x                        0x565CF0
#define CEverQuest__DoTellWindow_x                                 0x477550
#define CEverQuest__OutputTextToLog_x                              0x4771B0
#define CEverQuest__DropHeldItemOnGround_x                         0x57B760
#define CEverQuest__dsp_chat_x                                     0x477890
#define CEverQuest__trimName_x                                     0x561680
#define CEverQuest__Emote_x                                        0x579A70
#define CEverQuest__EnterZone_x                                    0x574B50
#define CEverQuest__GetBodyTypeDesc_x                              0x55F0D0
#define CEverQuest__GetClassDesc_x                                 0x568610
#define CEverQuest__GetClassThreeLetterCode_x                      0x568C10
#define CEverQuest__GetDeityDesc_x                                 0x55F9B0
#define CEverQuest__GetLangDesc_x                                  0x55F460
#define CEverQuest__GetRaceDesc_x                                  0x568DD0
#define CEverQuest__InterpretCmd_x                                 0x56C970
#define CEverQuest__LeftClickedOnPlayer_x                          0x5812C0
#define CEverQuest__LMouseUp_x                                     0x5833D0
#define CEverQuest__RightClickedOnPlayer_x                         0x581DD0
#define CEverQuest__RMouseUp_x                                     0x582E30
#define CEverQuest__SetGameState_x                                 0x565640
#define CEverQuest__UPCNotificationFlush_x                         0x55DA60
#define CEverQuest__IssuePetCommand_x                              0x56D350

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BB1A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BB200
#define CGaugeWnd__Draw_x                                          0x6BB630

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B860
#define CGuild__GetGuildName_x                                     0x43BD30
#define CGuild__GetGuildIndex_x                                    0x43CF40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D7650

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E4AA0
#define CInvSlotMgr__MoveItem_x                                    0x6E5260
#define CInvSlotMgr__SelectSlot_x                                  0x6E43A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E3800
#define CInvSlot__SliderComplete_x                                 0x6E0F90
#define CInvSlot__GetItemBase_x                                    0x6E03F0
#define CInvSlot__UpdateItem_x                                     0x6E0970

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E66C0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E77F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AEF70
#define CItemDisplayWnd__UpdateStrings_x                           0x6E88E0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F5560
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F5A70
#define CItemDisplayWnd__SetItem_x                                 0x6FB2B0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E6310

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EEEF0

// CLabel 
#define CLabel__Draw_x                                             0x7021C0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C4040
#define CListWnd__dCListWnd_x                                      0x8C52D0
#define CListWnd__AddColumn_x                                      0x8C5270
#define CListWnd__AddColumn1_x                                     0x8C4910
#define CListWnd__AddLine_x                                        0x8C42F0
#define CListWnd__AddString_x                                      0x8C4510
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C1160
#define CListWnd__CalculateVSBRange_x                              0x8C3500
#define CListWnd__ClearSel_x                                       0x8C0490
#define CListWnd__ClearAllSel_x                                    0x8C0440
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C3ED0
#define CListWnd__Compare_x                                        0x8C1E50
#define CListWnd__Draw_x                                           0x8C3110
#define CListWnd__DrawColumnSeparators_x                           0x8C2FA0
#define CListWnd__DrawHeader_x                                     0x8C0750
#define CListWnd__DrawItem_x                                       0x8C24E0
#define CListWnd__DrawLine_x                                       0x8C2C40
#define CListWnd__DrawSeparator_x                                  0x8C3040
#define CListWnd__EnableLine_x                                     0x8C0670
#define CListWnd__EnsureVisible_x                                  0x8C12C0
#define CListWnd__ExtendSel_x                                      0x8C23F0
#define CListWnd__GetColumnMinWidth_x                              0x8BFD80
#define CListWnd__GetColumnWidth_x                                 0x8BFCB0
#define CListWnd__GetCurSel_x                                      0x8BF480
#define CListWnd__GetItemAtPoint_x                                 0x8C1550
#define CListWnd__GetItemAtPoint1_x                                0x8C15C0
#define CListWnd__GetItemData_x                                    0x8BF7C0
#define CListWnd__GetItemHeight_x                                  0x8C0DD0
#define CListWnd__GetItemIcon_x                                    0x8BF9B0
#define CListWnd__GetItemRect_x                                    0x8C1390
#define CListWnd__GetItemText_x                                    0x8BF860
#define CListWnd__GetSelList_x                                     0x8C4800
#define CListWnd__GetSeparatorRect_x                               0x8C1D70
#define CListWnd__InsertLine_x                                     0x8C46F0
#define CListWnd__RemoveLine_x                                     0x8C4700
#define CListWnd__SetColors_x                                      0x8BF5D0
#define CListWnd__SetColumnJustification_x                         0x8C0010
#define CListWnd__SetColumnWidth_x                                 0x8BFD30
#define CListWnd__SetCurSel_x                                      0x8BF4C0
#define CListWnd__SetItemColor_x                                   0x8C3BC0
#define CListWnd__SetItemData_x                                    0x8C04F0
#define CListWnd__SetItemText_x                                    0x8C3A00
#define CListWnd__ShiftColumnSeparator_x                           0x8C3890
#define CListWnd__Sort_x                                           0x8C53D0
#define CListWnd__ToggleSel_x                                      0x8C03C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71B310

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73C6E0
#define CMerchantWnd__RequestBuyItem_x                             0x743790
#define CMerchantWnd__RequestSellItem_x                            0x744260
#define CMerchantWnd__SelectRecoverySlot_x                         0x73C990
#define CMerchantWnd__SelectBuySellSlot_x                          0x73BB90
#define CMerchantWnd__ActualSelect_x                               0x740660

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x855D90
#define CPacketScrambler__hton_x                                   0x855DA0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E2FB0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E3090
#define CSidlManager__CreateLabel_x                                0x7A4F90
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E1550
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E3370

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8DA4E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8DA3D0
#define CSidlScreenWnd__ConvertToRes_x                             0x8FF220
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DADF0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DBFE0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DC090
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DB560
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8DA7A0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D9F00
#define CSidlScreenWnd__GetSidlPiece_x                             0x8DA990
#define CSidlScreenWnd__Init1_x                                    0x8DBCC0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DAEB0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8DA0C0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DB7A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D9B50
#define CSidlScreenWnd__StoreIniVis_x                              0x8D9EB0
#define CSidlScreenWnd__WndNotification_x                          0x8DBA40
#define CSidlScreenWnd__GetChildItem_x                             0x8D9FD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CD800
#define CSidlScreenWnd__m_layoutCopy_x                             0x1734A08

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x606A40
#define CSkillMgr__GetSkillCap_x                                   0x606C20
#define CSkillMgr__GetNameToken_x                                  0x6065F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FE4F0
#define CSliderWnd__SetValue_x                                     0x8FE6C0
#define CSliderWnd__SetNumTicks_x                                  0x8FEE40

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7AB250

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F8050
#define CStmlWnd__CalculateHSBRange_x                              0x8F05D0
#define CStmlWnd__CalculateVSBRange_x                              0x8F0540
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F0750
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F0F50
#define CStmlWnd__ForceParseNow_x                                  0x8F89D0
#define CStmlWnd__GetNextTagPiece_x                                0x8F0E50
#define CStmlWnd__GetSTMLText_x                                    0x4857B0
#define CStmlWnd__GetVisibleText_x                                 0x8F19A0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F3F70
#define CStmlWnd__MakeStmlColorTag_x                               0x8EF820
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EF880
#define CStmlWnd__SetSTMLText_x                                    0x8F57C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F7CF0
#define CStmlWnd__UpdateHistoryString_x                            0x8F28E0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FBEE0
#define CTabWnd__DrawCurrentPage_x                                 0x8FB770
#define CTabWnd__DrawTab_x                                         0x8FB540
#define CTabWnd__GetCurrentPage_x                                  0x8FBB20
#define CTabWnd__GetPageInnerRect_x                                0x8FB230
#define CTabWnd__GetTabInnerRect_x                                 0x8FB430
#define CTabWnd__GetTabRect_x                                      0x8FB300
#define CTabWnd__InsertPage_x                                      0x8FC1D0
#define CTabWnd__SetPage_x                                         0x8FBB50
#define CTabWnd__SetPageRect_x                                     0x8FBE20
#define CTabWnd__UpdatePage_x                                      0x8FC170
#define CTabWnd__GetPageFromTabIndex_x                             0x8FB490
#define CTabWnd__GetCurrentTabIndex_x                              0x8FB1C0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E79A0
#define CPageWnd__SetTabText_x                                     0x908520

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437460

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D7E50
#define CTextureFont__GetTextExtent_x                              0x8D7BB0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63F260

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x904960

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BD6E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A7CF0
#define CXStr__CXStr1_x                                            0x74EED0
#define CXStr__CXStr3_x                                            0x8A07A0
#define CXStr__dCXStr_x                                            0x7A4F40
#define CXStr__operator_equal_x                                    0x8A0910
#define CXStr__operator_equal1_x                                   0x8A0960
#define CXStr__operator_plus_equal1_x                              0x8A1A60

// CXWnd 
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D5950
#define CXWnd__BringToTop_x                                        0x8CC9C0
#define CXWnd__Center_x                                            0x8D2C80
#define CXWnd__ClrFocus_x                                          0x8CC590
#define CXWnd__Destroy_x                                           0x8D3760
#define CXWnd__DoAllDrawing_x                                      0x8D28B0
#define CXWnd__DrawChildren_x                                      0x8D2A60
#define CXWnd__DrawColoredRect_x                                   0x8CCDA0
#define CXWnd__DrawTooltip_x                                       0x8CD050
#define CXWnd__DrawTooltipAtPoint_x                                0x8D1810
#define CXWnd__GetBorderFrame_x                                    0x8CD4C0
#define CXWnd__GetChildWndAt_x                                     0x8D3640
#define CXWnd__GetClientClipRect_x                                 0x8CD270
#define CXWnd__GetScreenClipRect_x                                 0x8D1F00
#define CXWnd__GetScreenRect_x                                     0x8CD690
#define CXWnd__GetTooltipRect_x                                    0x8CCEE0
#define CXWnd__GetWindowTextA_x                                    0x427440
#define CXWnd__IsActive_x                                          0x8C8080
#define CXWnd__IsDescendantOf_x                                    0x8CD400
#define CXWnd__IsReallyVisible_x                                   0x8D0820
#define CXWnd__IsType_x                                            0x8D2CF0
#define CScreenPieceTemplate__IsType_x                             0x901090
#define CXWnd__Move_x                                              0x8CFF00
#define CXWnd__Move1_x                                             0x8D2550
#define CXWnd__ProcessTransition_x                                 0x8CC960
#define CXWnd__Refade_x                                            0x8CC730
#define CXWnd__Resize_x                                            0x8CD760
#define CXWnd__Right_x                                             0x8D1D00
#define CXWnd__SetFocus_x                                          0x8CF040
#define CXWnd__SetFont_x                                           0x8CC5E0
#define CXWnd__SetKeyTooltip_x                                     0x8CD9D0
#define CXWnd__SetMouseOver_x                                      0x8D2250
#define CXWnd__StartFade_x                                         0x8CCA10
#define CXWnd__GetChildItem_x                                      0x8D2190
#define CXWnd__SetParent_x                                         0x8D35F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C9930
#define CXWndManager__DrawWindows_x                                0x8C9570
#define CXWndManager__GetKeyboardFlags_x                           0x8C7BB0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C8510
#define CXWndManager__RemoveWnd_x                                  0x8C8210

// CDBStr
#define CDBStr__GetString_x                                        0x4BB6B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452AC0
#define EQ_Character__Cur_HP_x                                     0x466270
#define EQ_Character__Cur_Mana_x                                   0x45B190
#define EQ_Character__GetAACastingTimeModifier_x                   0x44BAA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443AF0
#define EQ_Character__GetFocusRangeModifier_x                      0x443B50
#define EQ_Character__GetHPRegen_x                                 0x46A450
#define EQ_Character__GetEnduranceRegen_x                          0x465880
#define EQ_Character__GetManaRegen_x                               0x46A9F0
#define EQ_Character__Max_Endurance_x                              0x5CCE80
#define EQ_Character__Max_HP_x                                     0x45DD10
#define EQ_Character__Max_Mana_x                                   0x5CCCB0
#define EQ_Character__doCombatAbility_x                            0x5CA380
#define EQ_Character__UseSkill_x                                   0x4719C0
#define EQ_Character__GetConLevel_x                                0x5BF8F0
#define EQ_Character__IsExpansionFlag_x                            0x426980
#define EQ_Character__TotalEffect_x                                0x44FBF0
#define EQ_Character__GetPCSpellAffect_x                           0x44BEA0
#define EQ_Character__SpellDuration_x                              0x449E40
#define EQ_Character__FindItemByRecord_x                           0x4638C0
#define EQ_Character__GetAdjustedSkill_x                           0x466440
#define EQ_Character__GetBaseSkill_x                               0x45DBF0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x873C40

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D5470

//PcClient
#define PcClient__PcClient_x                                       0x5C1730

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446ED0
#define CCharacterSelect__EnterWorld_x                             0x4466A0
#define CCharacterSelect__Quit_x                                   0x445260

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59FEB0
#define EQ_Item__CreateItemTagString_x                             0x853F10
#define EQ_Item__IsStackable_x                                     0x849180
#define EQ_Item__GetImageNum_x                                     0x84BD00
#define EQ_Item__CreateItemClient_x                                0x5A0AB0
#define EQ_Item__GetItemValue_x                                    0x852960
#define EQ_Item__ValueSellMerchant_x                               0x8559E0
#define EQ_Item__IsKeyRingItem_x                                   0x849CE0
#define EQ_Item__CanGoInBag_x                                      0x5A0040
#define EQ_Item__GetMaxItemCount_x                                 0x849070
#define EQ_Item__GetHeldItem_x                                     0x84AB20
#define EQ_Item__GetAugmentFitBySlot_x                             0x855800

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DB9D0
#define EQ_LoadingS__Array_x                                       0xC0E738

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CF390
#define EQ_PC__GetAlternateAbilityId_x                             0x85DF10
#define EQ_PC__GetCombatAbility_x                                  0x85DFA0
#define EQ_PC__GetCombatAbilityTimer_x                             0x858A40
#define EQ_PC__GetItemRecastTimer_x                                0x5C8B30
#define EQ_PC__HasLoreItem_x                                       0x5C2EF0
#define EQ_PC__AlertInventoryChanged_x                             0x5BF8A0
#define EQ_PC__GetPcZoneClient_x                                   0x5E9A90
#define EQ_PC__RemoveMyAffect_x                                    0x5C7F90
#define EQ_PC__GetKeyRingItems_x                                   0x858E60
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86BC40
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85FEB0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x527540
#define EQItemList__add_object_x                                   0x554950
#define EQItemList__add_item_x                                     0x527480
#define EQItemList__delete_item_x                                  0x527930
#define EQItemList__FreeItemList_x                                 0x527830

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4BA930

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D5210
#define EQPlayer__dEQPlayer_x                                      0x5DD840
#define EQPlayer__DoAttack_x                                       0x5EF400
#define EQPlayer__EQPlayer_x                                       0x5DFF70
#define EQPlayer__SetNameSpriteState_x                             0x5DA720
#define EQPlayer__SetNameSpriteTint_x                              0x5D6630
#define PlayerBase__HasProperty_j_x                                0x9324A0
#define EQPlayer__IsTargetable_x                                   0x932740
#define EQPlayer__CanSee_x                                         0x932CA0
#define PlayerZoneClient__ChangeHeight_x                           0x5EF2C0
#define EQPlayer__CanSee1_x                                        0x932D90
#define PlayerBase__GetVisibilityLineSegment_x                     0x932A30

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E9C40
#define PlayerZoneClient__IsValidTeleport_x                        0x5551F0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D3CD0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E40D0
#define EQPlayerManager__GetSpawnByName_x                          0x5E4530
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E4100

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A6080
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A60C0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A5C70
#define KeypressHandler__HandleKeyDown_x                           0x5A45C0
#define KeypressHandler__HandleKeyUp_x                             0x5A48E0
#define KeypressHandler__SaveKeymapping_x                          0x5A5D40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x713CA0
#define MapViewMap__SaveEx_x                                       0x716FD0

#define PlayerPointManager__GetAltCurrency_x                       0x871CD0

// StringTable 
#define StringTable__getString_x                                   0x86BF70

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CC910
#define PcZoneClient__RemovePetEffect_x                            0x5C9000
#define PcZoneClient__HasAlternateAbility_x                        0x5C99A0
#define PcZoneClient__GetCurrentMod_x                              0x45D1C0
#define PcZoneClient__GetModCap_x                                  0x45A8F0
#define PcZoneClient__CanEquipItem_x                               0x5C9EC0
#define PcZoneClient__GetItemByID_x                                0x5CE710
#define PcZoneClient__GetItemByItemClass_x                         0x5CF2B0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C8240

//Doors
#define EQSwitch__UseSwitch_x                                      0x55C320

//IconCache
#define IconCache__GetIcon_x                                       0x6B0A90

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A7980
#define CContainerMgr__CloseContainer_x                            0x6A81A0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x774E00

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x598EC0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5F90
#define EQ_Spell__SpellAffects_x                                   0x4F31B0
#define EQ_Spell__SpellAffectBase_x                                0x4F3220
#define CharacterZoneClient__CalcAffectChange_x                    0x44BD30
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AF70
#define CLootWnd__LootAll_x                                        0x709570
#define CLootWnd__RequestLootSlot_x                                0x709D80
#define EQ_Spell__IsStackable_x                                    0x449830
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4498E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F2E0
#define EQ_Spell__IsSPAStacking_x                                  0x4F2D20
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3D90
#define EQ_Spell__IsNoRemove_x                                     0x435480
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F2D40

#define __IsResEffectSpell_x                                       0x449990

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87D8D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BBFB0
#define CTargetWnd__WndNotification_x                              0x7BBAA0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BC190

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C10E0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EE8E0
#define EqSoundManager__PlayScriptMp3_x                            0x4F0380

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A9AF0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EBC70
#define CSidlManager__FindAnimation1_x                             0x8E0F80

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E3300
#define CAltAbilityData__GetMercMaxRank_x                          0x4E32B0
#define CAltAbilityData__GetMaxRank_x                              0x4D7AE0

//CTargetRing
#define CTargetRing__Cast_x                                        0x596770

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459860
#define CharacterBase__CreateItemGlobalIndex_x                     0x476750
#define CharacterBase__CreateItemIndex_x                           0x520BB0
#define CharacterBase__GetItemPossession_x                         0x444720
#define CharacterBase__GetItemByGlobalIndex_x                      0x881710
#define CharacterBase__GetEffectId_x                               0x459820

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6907D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68FF30

//messages
#define msg_spell_worn_off_x                                       0x4FDAA0
#define msg_new_text_x                                             0x507150
#define msgTokenTextParam_x                                        0x503930

//SpellManager
#define SpellManager__vftable_x                                    0xACB3F8
#define SpellManager__SpellManager_x                               0x47F460
#define Spellmanager__LoadTextSpells_x                             0x60D920

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x936800

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488E00
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43F200
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4495C0
#define ItemGlobalIndex__IsValidIndex_x                            0x459150

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87F590
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87E4D0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x702410

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AC6D0
#define CCursorAttachment__Deactivate_x                            0x6ABC10

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FD9F0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FDB70

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48D670
