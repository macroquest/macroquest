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
#define __ExpectedVersionDate                                     "Oct 10 2017"
#define __ExpectedVersionTime                                     "11:31:21"
#define __ActualVersionDate_x                                      0xAE6348
#define __ActualVersionTime_x                                      0xAE6354

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5AAF60
#define __MemChecker1_x                                            0x8A4270
#define __MemChecker2_x                                            0x6414A0
#define __MemChecker3_x                                            0x6413F0
#define __MemChecker4_x                                            0x7F5850
#define __EncryptPad0_x                                            0xC432B0
#define __EncryptPad1_x                                            0xD1ED68
#define __EncryptPad2_x                                            0xC6CCF0
#define __EncryptPad3_x                                            0xC6C8F0
#define __EncryptPad4_x                                            0xD0D368
#define __EncryptPad5_x                                            0x10C85A0
#define __AC1_x                                                    0x7B4975
#define __AC2_x                                                    0x563C07
#define __AC3_x                                                    0x561D80
#define __AC4_x                                                    0x573FA1
#define __AC5_x                                                    0x587E5B
#define __AC6_x                                                    0x58BA0E
#define __AC7_x                                                    0x58245C
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
#define __do_loot_x                                                0x532940
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
#define __CastRay_x                                                0x54A3B0
#define __CastRay2_x                                               0x549CE0
#define __HeadingDiff_x                                            0x9344C0
#define __FixHeading_x                                             0x934450
#define __get_bearing_x                                            0x539A90
#define __ConvertItemTags_x                                        0x537560
#define __ExecuteCmd_x                                             0x521E10
#define __EQGetTime_x                                              0x8A3C10
#define __get_melee_range_x                                        0x528AE0
#define __GetGaugeValueFromEQ_x                                    0x7B3530
#define __GetLabelFromEQ_x                                         0x7B4900
#define __ToggleKeyRingItem_x                                      0x490A20
#define __GetXTargetType_x                                         0x9360C0
#define __LoadFrontEnd_x                                           0x640B70
#define __NewUIINI_x                                               0x7B2F00
#define __ProcessGameEvents_x                                      0x5841F0
#define __ProcessMouseEvent_x                                      0x583990
#define CrashDetected_x                                            0x642530
#define wwsCrashReportCheckForUploader_x                           0x801810
#define __AppCrashWrapper_x                                        0xC6C8E4
#define __pCrashHandler_x                                          0x10DDDB0
#define __CrashHandler_x                                           0x8012A0
#define wwsCrashReportPlatformLaunchUploader_x                     0x803A40
#define DrawNetStatus_x                                            0x5BAB00
#define Util__FastTime_x                                           0x8A38B0
#define Expansion_HoT_x                                            0xF37A08
#define __HelpPath_x                                               0xFBB1B0
#define __STMLToText_x                                             0x8EA130
#define __GetAnimationCache_x                                      0x6B0100

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4233E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E080
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DE50

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8E60
#define AltAdvManager__IsAbilityReady_x                            0x4D8ED0
#define AltAdvManager__GetAAById_x                                 0x4D93C0
#define AltAdvManager__CanTrainAbility_x                           0x4D9FF0
#define AltAdvManager__CanSeeAbility_x                             0x4D9BB0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AA00
#define CharacterZoneClient__HasSkill_x                            0x4662D0
#define CharacterZoneClient__MakeMeVisible_x                       0x46C570
#define CharacterZoneClient__IsStackBlocked_x                      0x44BF70
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B430
#define CharacterZoneClient__GetItemCountWorn_x                    0x464830
#define CharacterZoneClient__GetItemCountInInventory_x             0x464910
#define CharacterZoneClient__GetCursorItemCount_x                  0x4649F0
#define CharacterZoneClient__FindAffectSlot_x                      0x4515A0
#define CharacterZoneClient__BardCastBard_x                        0x44ABB0
#define CharacterZoneClient__GetMaxEffects_x                       0x449740
#define CharacterZoneClient__GetEffect_x                           0x44B660
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451400
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449A90
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FF50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6702A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67DE60

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x599B30
#define CButtonWnd__CButtonWnd_x                                   0x8DE3A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x699260
#define CChatManager__InitContextMenu_x                            0x69A3B0
#define CChatManager__FreeChatWindow_x                             0x698D10
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A2550
#define CChatManager__SetLockedActiveChatWindow_x                  0x699230

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E8480
#define CContextMenu__dCContextMenu_x                              0x8E8690
#define CContextMenu__AddMenuItem_x                                0x8E8BB0
#define CContextMenu__RemoveMenuItem_x                             0x8E8810
#define CContextMenu__RemoveAllMenuItems_x                         0x8E8830
#define CContextMenu__CheckMenuItem_x                              0x8E88B0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D4950
#define CContextMenuManager__RemoveMenu_x                          0x8D4CF0
#define CContextMenuManager__PopupMenu_x                           0x8D5140
#define CContextMenuManager__Flush_x                               0x8D49C0
#define CContextMenuManager__GetMenu_x                             0x419600

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x887CD0
#define CChatService__GetFriendName_x                              0x887CE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A0020
#define CChatWindow__Clear_x                                       0x69F900
#define CChatWindow__WndNotification_x                             0x6A0930

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D87B0
#define CComboWnd__Draw_x                                          0x8D89C0
#define CComboWnd__GetCurChoice_x                                  0x8D8560
#define CComboWnd__GetListRect_x                                   0x8D8C60
#define CComboWnd__GetTextRect_x                                   0x8D8820
#define CComboWnd__InsertChoice_x                                  0x8D8DC0
#define CComboWnd__SetColors_x                                     0x8D84F0
#define CComboWnd__SetChoice_x                                     0x8D8520
#define CComboWnd__GetItemCount_x                                  0x8D8550
#define CComboWnd__GetCurChoiceText_x                              0x8D85A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AA290
#define CContainerWnd__vftable_x                                   0xAEFC48

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C6B40
#define CDisplay__GetClickedActor_x                                0x4BF400
#define CDisplay__GetUserDefinedColor_x                            0x4BDFE0
#define CDisplay__GetWorldFilePath_x                               0x4BD430
#define CDisplay__is3dON_x                                         0x4BC8C0
#define CDisplay__ReloadUI_x                                       0x4D0B20
#define CDisplay__WriteTextHD2_x                                   0x4C2ED0
#define CDisplay__TrueDistance_x                                   0x4C0030

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FF8A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EC9E0
#define CEditWnd__GetCharIndexPt_x                                 0x8EDB30
#define CEditWnd__GetDisplayString_x                               0x8ECB90
#define CEditWnd__GetHorzOffset_x                                  0x8ECED0
#define CEditWnd__GetLineForPrintableChar_x                        0x8ED600
#define CEditWnd__GetSelStartPt_x                                  0x8EDDE0
#define CEditWnd__GetSTMLSafeText_x                                0x8ED070
#define CEditWnd__PointFromPrintableChar_x                         0x8ED6F0
#define CEditWnd__SelectableCharFromPoint_x                        0x8ED870
#define CEditWnd__SetEditable_x                                    0x8ED040

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A7D0
#define CEverQuest__ClickedPlayer_x                                0x564350
#define CEverQuest__CreateTargetIndicator_x                        0x565250
#define CEverQuest__DeleteTargetIndicator_x                        0x5652D0
#define CEverQuest__DoTellWindow_x                                 0x477160
#define CEverQuest__OutputTextToLog_x                              0x476DC0
#define CEverQuest__DropHeldItemOnGround_x                         0x57AD40
#define CEverQuest__dsp_chat_x                                     0x4774A0
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
#define CEverQuest__LeftClickedOnPlayer_x                          0x5808A0
#define CEverQuest__LMouseUp_x                                     0x5829B0
#define CEverQuest__RightClickedOnPlayer_x                         0x5813B0
#define CEverQuest__RMouseUp_x                                     0x582410
#define CEverQuest__SetGameState_x                                 0x564C20
#define CEverQuest__UPCNotificationFlush_x                         0x55D030
#define CEverQuest__IssuePetCommand_x                              0x56C930

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BAE60
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BAEC0
#define CGaugeWnd__Draw_x                                          0x6BB2F0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B520
#define CGuild__GetGuildName_x                                     0x43B9F0
#define CGuild__GetGuildIndex_x                                    0x43CC00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D7410

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E4880
#define CInvSlotMgr__MoveItem_x                                    0x6E5040
#define CInvSlotMgr__SelectSlot_x                                  0x6E4170

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E35C0
#define CInvSlot__SliderComplete_x                                 0x6E0D50
#define CInvSlot__GetItemBase_x                                    0x6E01B0
#define CInvSlot__UpdateItem_x                                     0x6E0730

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E64A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E75D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AEF30
#define CItemDisplayWnd__UpdateStrings_x                           0x6E86E0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F5340
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F5850
#define CItemDisplayWnd__SetItem_x                                 0x6FB130

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E6420

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EECE0

// CLabel 
#define CLabel__Draw_x                                             0x701EF0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C4220
#define CListWnd__dCListWnd_x                                      0x8C54D0
#define CListWnd__AddColumn_x                                      0x8C5470
#define CListWnd__AddColumn1_x                                     0x8C4B10
#define CListWnd__AddLine_x                                        0x8C44F0
#define CListWnd__AddString_x                                      0x8C4710
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C1320
#define CListWnd__CalculateVSBRange_x                              0x8C36E0
#define CListWnd__ClearSel_x                                       0x8C0640
#define CListWnd__ClearAllSel_x                                    0x8C05F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C40B0
#define CListWnd__Compare_x                                        0x8C2010
#define CListWnd__Draw_x                                           0x8C32E0
#define CListWnd__DrawColumnSeparators_x                           0x8C3170
#define CListWnd__DrawHeader_x                                     0x8C0900
#define CListWnd__DrawItem_x                                       0x8C26A0
#define CListWnd__DrawLine_x                                       0x8C2E10
#define CListWnd__DrawSeparator_x                                  0x8C3210
#define CListWnd__EnableLine_x                                     0x8C0820
#define CListWnd__EnsureVisible_x                                  0x8C1480
#define CListWnd__ExtendSel_x                                      0x8C25B0
#define CListWnd__GetColumnMinWidth_x                              0x8BFF30
#define CListWnd__GetColumnWidth_x                                 0x8BFE60
#define CListWnd__GetCurSel_x                                      0x8BF620
#define CListWnd__GetItemAtPoint_x                                 0x8C1720
#define CListWnd__GetItemAtPoint1_x                                0x8C1790
#define CListWnd__GetItemData_x                                    0x8BF970
#define CListWnd__GetItemHeight_x                                  0x8C0F80
#define CListWnd__GetItemIcon_x                                    0x8BFB60
#define CListWnd__GetItemRect_x                                    0x8C1560
#define CListWnd__GetItemText_x                                    0x8BFA10
#define CListWnd__GetSelList_x                                     0x8C4A00
#define CListWnd__GetSeparatorRect_x                               0x8C1F30
#define CListWnd__InsertLine_x                                     0x8C48F0
#define CListWnd__RemoveLine_x                                     0x8C4900
#define CListWnd__SetColors_x                                      0x8BF770
#define CListWnd__SetColumnJustification_x                         0x8C01C0
#define CListWnd__SetColumnWidth_x                                 0x8BFEE0
#define CListWnd__SetCurSel_x                                      0x8BF660
#define CListWnd__SetItemColor_x                                   0x8C3DA0
#define CListWnd__SetItemData_x                                    0x8C06A0
#define CListWnd__SetItemText_x                                    0x8C3BE0
#define CListWnd__ShiftColumnSeparator_x                           0x8C3A70
#define CListWnd__Sort_x                                           0x8C55D0
#define CListWnd__ToggleSel_x                                      0x8C0570

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71AF10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73C510
#define CMerchantWnd__RequestBuyItem_x                             0x7435E0
#define CMerchantWnd__RequestSellItem_x                            0x7440B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x73C7C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73B9C0
#define CMerchantWnd__ActualSelect_x                               0x740490

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x856210
#define CPacketScrambler__hton_x                                   0x856220

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E3360
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E3440
#define CSidlManager__CreateLabel_x                                0x7A4D60
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E1900
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E3720

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8DA810
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8DA700
#define CSidlScreenWnd__ConvertToRes_x                             0x8FF780
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DB120
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DC2F0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DC3A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DB880
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8DAAD0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8DA230
#define CSidlScreenWnd__GetSidlPiece_x                             0x8DACC0
#define CSidlScreenWnd__Init1_x                                    0x8DBFD0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DB1E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8DA3F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DBAC0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D9E90
#define CSidlScreenWnd__StoreIniVis_x                              0x8DA1E0
#define CSidlScreenWnd__WndNotification_x                          0x8DBD50
#define CSidlScreenWnd__GetChildItem_x                             0x8DA300
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CDAE0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1734A08

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6062B0
#define CSkillMgr__GetSkillCap_x                                   0x606490
#define CSkillMgr__GetNameToken_x                                  0x605E60

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FEA30
#define CSliderWnd__SetValue_x                                     0x8FEC00
#define CSliderWnd__SetNumTicks_x                                  0x8FF380

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7AB1B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F8460
#define CStmlWnd__CalculateHSBRange_x                              0x8F09B0
#define CStmlWnd__CalculateVSBRange_x                              0x8F0920
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F0B30
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F1330
#define CStmlWnd__ForceParseNow_x                                  0x8F8DE0
#define CStmlWnd__GetNextTagPiece_x                                0x8F1230
#define CStmlWnd__GetSTMLText_x                                    0x4853E0
#define CStmlWnd__GetVisibleText_x                                 0x8F1D80
#define CStmlWnd__InitializeWindowVariables_x                      0x8F4350
#define CStmlWnd__MakeStmlColorTag_x                               0x8EFC00
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EFC60
#define CStmlWnd__SetSTMLText_x                                    0x8F5BA0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F8100
#define CStmlWnd__UpdateHistoryString_x                            0x8F2CC0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FC300
#define CTabWnd__DrawCurrentPage_x                                 0x8FBB90
#define CTabWnd__DrawTab_x                                         0x8FB950
#define CTabWnd__GetCurrentPage_x                                  0x8FBF40
#define CTabWnd__GetPageInnerRect_x                                0x8FB640
#define CTabWnd__GetTabInnerRect_x                                 0x8FB840
#define CTabWnd__GetTabRect_x                                      0x8FB710
#define CTabWnd__InsertPage_x                                      0x8FC5F0
#define CTabWnd__SetPage_x                                         0x8FBF70
#define CTabWnd__SetPageRect_x                                     0x8FC240
#define CTabWnd__UpdatePage_x                                      0x8FC590
#define CTabWnd__GetPageFromTabIndex_x                             0x8FB8A0
#define CTabWnd__GetCurrentTabIndex_x                              0x8FB5D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E7780
#define CPageWnd__SetTabText_x                                     0x908AA0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437120

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D8160
#define CTextureFont__GetTextExtent_x                              0x8D7EC0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63EE00

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x904EE0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BD780

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029C0
#define CXStr__CXStr1_x                                            0x7E2080
#define CXStr__CXStr3_x                                            0x8A0B00
#define CXStr__dCXStr_x                                            0x6BAD40
#define CXStr__operator_equal_x                                    0x8A0C70
#define CXStr__operator_equal1_x                                   0x8A0CC0
#define CXStr__operator_plus_equal1_x                              0x8A1DC0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8CCCB0
#define CXWnd__Center_x                                            0x8D2F60
#define CXWnd__ClrFocus_x                                          0x8CC890
#define CXWnd__Destroy_x                                           0x8D3A50
#define CXWnd__DoAllDrawing_x                                      0x8D2BB0
#define CXWnd__DrawChildren_x                                      0x8D2D50
#define CXWnd__DrawColoredRect_x                                   0x8CD080
#define CXWnd__DrawTooltip_x                                       0x8CD330
#define CXWnd__DrawTooltipAtPoint_x                                0x8D1B10
#define CXWnd__GetBorderFrame_x                                    0x8CD790
#define CXWnd__GetChildWndAt_x                                     0x8D3930
#define CXWnd__GetClientClipRect_x                                 0x8CD540
#define CXWnd__GetScreenClipRect_x                                 0x8D2210
#define CXWnd__GetScreenRect_x                                     0x8CD970
#define CXWnd__GetTooltipRect_x                                    0x8CD1C0
#define CXWnd__GetWindowTextA_x                                    0x427430
#define CXWnd__IsActive_x                                          0x8C82B0
#define CXWnd__IsDescendantOf_x                                    0x8CD6D0
#define CXWnd__IsReallyVisible_x                                   0x8D0B30
#define CXWnd__IsType_x                                            0x8D2FD0
#define CScreenPieceTemplate__IsType_x                             0x901610
#define CXWnd__Move_x                                              0x8D0210
#define CXWnd__Move1_x                                             0x8D2850
#define CXWnd__ProcessTransition_x                                 0x8CCC50
#define CXWnd__Refade_x                                            0x8CCA20
#define CXWnd__Resize_x                                            0x8CDA40
#define CXWnd__Right_x                                             0x8D2010
#define CXWnd__SetFocus_x                                          0x8CF350
#define CXWnd__SetFont_x                                           0x8CC8E0
#define CXWnd__SetKeyTooltip_x                                     0x8CDCB0
#define CXWnd__SetMouseOver_x                                      0x8D2530
#define CXWnd__StartFade_x                                         0x8CCD00
#define CXWnd__GetChildItem_x                                      0x8D2480
#define CXWnd__SetParent_x                                         0x8D38E0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C9B70
#define CXWndManager__DrawWindows_x                                0x8C97B0
#define CXWndManager__GetKeyboardFlags_x                           0x8C7DE0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C8750
#define CXWndManager__RemoveWnd_x                                  0x8C8440

// CDBStr
#define CDBStr__GetString_x                                        0x4BB100

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452760
#define EQ_Character__Cur_HP_x                                     0x465EB0
#define EQ_Character__Cur_Mana_x                                   0x45ADF0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B740
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4437A0
#define EQ_Character__GetFocusRangeModifier_x                      0x443800
#define EQ_Character__GetHPRegen_x                                 0x46A090
#define EQ_Character__GetEnduranceRegen_x                          0x4654C0
#define EQ_Character__GetManaRegen_x                               0x46A630
#define EQ_Character__Max_Endurance_x                              0x5CC770
#define EQ_Character__Max_HP_x                                     0x45D970
#define EQ_Character__Max_Mana_x                                   0x5CC5A0
#define EQ_Character__doCombatAbility_x                            0x5C9C70
#define EQ_Character__UseSkill_x                                   0x471600
#define EQ_Character__GetConLevel_x                                0x5BF1A0
#define EQ_Character__IsExpansionFlag_x                            0x426970
#define EQ_Character__TotalEffect_x                                0x44F890
#define EQ_Character__GetPCSpellAffect_x                           0x44BB40
#define EQ_Character__SpellDuration_x                              0x449AE0
#define EQ_Character__FindItemByRecord_x                           0x463520
#define EQ_Character__GetAdjustedSkill_x                           0x466080
#define EQ_Character__GetBaseSkill_x                               0x45D850

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x873EF0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D4D90

//PcClient
#define PcClient__PcClient_x                                       0x5C0FF0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446B70
#define CCharacterSelect__EnterWorld_x                             0x446340
#define CCharacterSelect__Quit_x                                   0x444F00

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59F590
#define EQ_Item__CreateItemTagString_x                             0x854370
#define EQ_Item__IsStackable_x                                     0x849630
#define EQ_Item__GetImageNum_x                                     0x84C160
#define EQ_Item__CreateItemClient_x                                0x5A0180
#define EQ_Item__GetItemValue_x                                    0x852DD0
#define EQ_Item__ValueSellMerchant_x                               0x855E60
#define EQ_Item__IsKeyRingItem_x                                   0x84A180
#define EQ_Item__CanGoInBag_x                                      0x59F720
#define EQ_Item__GetMaxItemCount_x                                 0x849520
#define EQ_Item__GetHeldItem_x                                     0x84AF70
#define EQ_Item__GetAugmentFitBySlot_x                             0x855C80

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DB470
#define EQ_LoadingS__Array_x                                       0xC0E738

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CEC90
#define EQ_PC__GetAlternateAbilityId_x                             0x85E210
#define EQ_PC__GetCombatAbility_x                                  0x85E2A0
#define EQ_PC__GetCombatAbilityTimer_x                             0x858EC0
#define EQ_PC__GetItemRecastTimer_x                                0x5C8420
#define EQ_PC__HasLoreItem_x                                       0x5C27B0
#define EQ_PC__AlertInventoryChanged_x                             0x5BF150
#define EQ_PC__GetPcZoneClient_x                                   0x5E9330
#define EQ_PC__RemoveMyAffect_x                                    0x5C7880
#define EQ_PC__GetKeyRingItems_x                                   0x8592E0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86BF10
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x860180

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526B60
#define EQItemList__add_object_x                                   0x553F30
#define EQItemList__add_item_x                                     0x526AA0
#define EQItemList__delete_item_x                                  0x526F50
#define EQItemList__FreeItemList_x                                 0x526E50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4BA3C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D4B30
#define EQPlayer__dEQPlayer_x                                      0x5DD180
#define EQPlayer__DoAttack_x                                       0x5EECC0
#define EQPlayer__EQPlayer_x                                       0x5DF8A0
#define EQPlayer__SetNameSpriteState_x                             0x5DA040
#define EQPlayer__SetNameSpriteTint_x                              0x5D5F50
#define PlayerBase__HasProperty_j_x                                0x9328D0
#define EQPlayer__IsTargetable_x                                   0x932B70
#define EQPlayer__CanSee_x                                         0x9330D0
#define PlayerZoneClient__ChangeHeight_x                           0x5EEB80
#define EQPlayer__CanSee1_x                                        0x9331C0
#define PlayerBase__GetVisibilityLineSegment_x                     0x932E60

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E94E0
#define PlayerZoneClient__IsValidTeleport_x                        0x5547D0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D3720

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E38E0
#define EQPlayerManager__GetSpawnByName_x                          0x5E3D40
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E3910

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A5750
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A5790
#define KeypressHandler__ClearCommandStateArray_x                  0x5A5340
#define KeypressHandler__HandleKeyDown_x                           0x5A3C90
#define KeypressHandler__HandleKeyUp_x                             0x5A3FB0
#define KeypressHandler__SaveKeymapping_x                          0x5A5410

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7138A0
#define MapViewMap__SaveEx_x                                       0x716BD0

#define PlayerPointManager__GetAltCurrency_x                       0x871FB0

// StringTable 
#define StringTable__getString_x                                   0x86C240

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CC200
#define PcZoneClient__RemovePetEffect_x                            0x5C88F0
#define PcZoneClient__HasAlternateAbility_x                        0x5C9290
#define PcZoneClient__GetCurrentMod_x                              0x45CE20
#define PcZoneClient__GetModCap_x                                  0x45A550
#define PcZoneClient__CanEquipItem_x                               0x5C97B0
#define PcZoneClient__GetItemByID_x                                0x5CE000
#define PcZoneClient__GetItemByItemClass_x                         0x5CEBB0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C7B30

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B8F0

//IconCache
#define IconCache__GetIcon_x                                       0x6B0730

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A7610
#define CContainerMgr__CloseContainer_x                            0x6A7E30

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x774D60

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x598550

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5900
#define EQ_Spell__SpellAffects_x                                   0x4F2B20
#define EQ_Spell__SpellAffectBase_x                                0x4F2B90
#define CharacterZoneClient__CalcAffectChange_x                    0x44B9D0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AC10
#define CLootWnd__LootAll_x                                        0x709160
#define CLootWnd__RequestLootSlot_x                                0x709970
#define EQ_Spell__IsStackable_x                                    0x4494E0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449590
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EFA0
#define EQ_Spell__IsSPAStacking_x                                  0x4F2690
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3700
#define EQ_Spell__IsNoRemove_x                                     0x435140
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F26B0

#define __IsResEffectSpell_x                                       0x449630

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87DB80

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BBF70
#define CTargetWnd__WndNotification_x                              0x7BBA60
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BC150

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C10A0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EE250
#define EqSoundManager__PlayScriptMp3_x                            0x4EFCF0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A94E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EC010
#define CSidlManager__FindAnimation1_x                             0x8E1330

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2E00
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2DB0
#define CAltAbilityData__GetMaxRank_x                              0x4D7510

//CTargetRing
#define CTargetRing__Cast_x                                        0x595E00

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459500
#define CharacterBase__CreateItemGlobalIndex_x                     0x476380
#define CharacterBase__CreateItemIndex_x                           0x520170
#define CharacterBase__GetItemPossession_x                         0x4443D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8819D0
#define CharacterBase__GetEffectId_x                               0x4594C0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6903C0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68FB20

//messages
#define msg_spell_worn_off_x                                       0x4FD430
#define msg_new_text_x                                             0x506AF0
#define msgTokenTextParam_x                                        0x5032D0

//SpellManager
#define SpellManager__vftable_x                                    0xACB400
#define SpellManager__SpellManager_x                               0x47F000
#define Spellmanager__LoadTextSpells_x          0x60D190

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x936BE0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488990
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EEC0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449260
#define ItemGlobalIndex__IsValidIndex_x                            0x458DF0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87F840
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87E780

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x702140

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AC360
#define CCursorAttachment__Deactivate_x                            0x6AB8A0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FDF30
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FE0B0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48D200
