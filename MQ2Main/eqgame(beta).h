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
#define __ExpectedVersionDate                                     "Dec  6 2017"
#define __ExpectedVersionTime                                     "04:16:43"
#define __ActualVersionDate_x                                      0xAE5080
#define __ActualVersionTime_x                                      0xAE508C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AB530
#define __MemChecker1_x                                            0x8A3EB0
#define __MemChecker2_x                                            0x640FF0
#define __MemChecker3_x                                            0x640F40
#define __MemChecker4_x                                            0x7F5670
#define __EncryptPad0_x                                            0xC3FFE8
#define __EncryptPad1_x                                            0xD19BA0
#define __EncryptPad2_x                                            0xC68ED0
#define __EncryptPad3_x                                            0xC68AD0
#define __EncryptPad4_x                                            0xD081A0
#define __EncryptPad5_x                                            0x10C32E0
#define __AC1_x                                                    0x7B4645
#define __AC2_x                                                    0x564787
#define __AC3_x                                                    0x562900
#define __AC4_x                                                    0x574AD1
#define __AC5_x                                                    0x58881B
#define __AC6_x                                                    0x58C3CE
#define __AC7_x                                                    0x582E1C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4EE0

// Direct Input
#define DI8__Main_x                                                0x10C32B8
#define DI8__Keyboard_x                                            0x10C32BC
#define DI8__Mouse_x                                               0x10C32C0
#define DI8__Mouse_Copy_x                                          0xF31474
#define DI8__Mouse_Check_x                                         0xFBAFA4
#define __AutoSkillArray_x                                         0xF32388
#define __Attack_x                                                 0xFB5A7B
#define __Autofire_x                                               0xFB5A7C
#define __BindList_x                                               0xC1C368
#define g_eqCommandStates_x                                        0xF201C0
#define __Clicks_x                                                 0xF31530
#define __CommandList_x                                            0xC1EA80
#define __CurrentMapLabel_x                                        0x10C92B0
#define __CurrentSocial_x                                          0xBEB8E8
#define __DoAbilityList_x                                          0xF67C40
#define __do_loot_x                                                0x5337D0
#define __DrawHandler_x                                            0x1732F2C
#define __GroupCount_x                                             0xF21ACA

#define __Guilds_x                                                 0xF276E0
#define __gWorld_x                                                 0xF23F84
#define __HotkeyPage_x                                             0xFAE640
#define __HWnd_x                                                   0xFBB0C0
#define __InChatMode_x                                             0xF3145C
#define __LastTell_x                                               0xF3333C
#define __LMouseHeldTime_x                                         0xF3159C
#define __Mouse_x                                                  0x10C32C4
#define __MouseLook_x                                              0xF314F6
#define __MouseEventTime_x                                         0xFB6214
#define __gpbCommandEvent_x                                        0xF2404C
#define __NetStatusToggle_x                                        0xF314F9
#define __PCNames_x                                                0xF32944
#define __RangeAttackReady_x                                       0xF3266C
#define __RMouseHeldTime_x                                         0xF31598
#define __RunWalkState_x                                           0xF31460
#define __ScreenMode_x                                             0xE6FDA0
#define __ScreenX_x                                                0xF31414
#define __ScreenY_x                                                0xF31410
#define __ScreenXMax_x                                             0xF31418
#define __ScreenYMax_x                                             0xF3141C
#define __ServerHost_x                                             0xF21A14
#define __ServerName_x                                             0xF67C00
#define __ShiftKeyDown_x                                           0xF31AF0
#define __ShowNames_x                                              0xF32824
#define __Socials_x                                                0xF67D00
#define __SubscriptionType_x                                       0x10F9A34
#define __TargetAggroHolder_x                                      0x10CB40C
#define __ZoneType_x                                               0xF318F4
#define __GroupAggro_x                                             0x10CB44C
#define __LoginName_x                                              0xFB9B9C
#define __Inviter_x                                                0xFB59F8
#define __AttackOnAssist_x                                         0xF327E0
#define __UseTellWindows_x                                         0xF32ADC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF24070
#define instEQZoneInfo_x                                           0xF316EC
#define instKeypressHandler_x                                      0xFB61F8
#define pinstActiveBanker_x                                        0xF24028
#define pinstActiveCorpse_x                                        0xF2402C
#define pinstActiveGMaster_x                                       0xF24030
#define pinstActiveMerchant_x                                      0xF24024
#define pinstAggroInfo_x                                           0xD2D40C
#define pinstAltAdvManager_x                                       0xE70F08
#define pinstAuraMgr_x                                             0xD3DC10
#define pinstBandageTarget_x                                       0xF24010
#define pinstCamActor_x                                            0xE707D8
#define pinstCDBStr_x                                              0xE6FD34
#define pinstCDisplay_x                                            0xF24038
#define pinstCEverQuest_x                                          0x10C3438
#define pinstEverQuestInfo_x                                       0xF31408
#define pinstCharData_x                                            0xF23FF4
#define pinstCharSpawn_x                                           0xF2401C
#define pinstControlledMissile_x                                   0xF23FF0
#define pinstControlledPlayer_x                                    0xF2401C
#define pinstCSidlManager_x                                        0x1731E98
#define pinstCXWndManager_x                                        0x1731E90
#define instDynamicZone_x                                          0xF312A8
#define pinstDZMember_x                                            0xF313B8
#define pinstDZTimerInfo_x                                         0xF313BC
#define pinstEQItemList_x                                          0xF20498
#define pinstEQObjectList_x                                        0xF214C4
#define instEQMisc_x                                               0xC047A8
#define pinstEQSoundManager_x                                      0xE714D8
#define instExpeditionLeader_x                                     0xF312F2
#define instExpeditionName_x                                       0xF31332
#define pinstGroup_x                                               0xF21AC6
#define pinstImeManager_x                                          0x1731E9C
#define pinstLocalPlayer_x                                         0xF24008
#define pinstMercenaryData_x                                       0xFB6860
#define pinstMercenaryStats_x                                      0x10CB558
#define pinstMercAltAbilities_x                                    0xE71290
#define pinstModelPlayer_x                                         0xF24034
#define pinstPCData_x                                              0xF23FF4
#define pinstSkillMgr_x                                            0xFB7858
#define pinstSpawnManager_x                                        0xFB70B0
#define pinstSpellManager_x                                        0xFB79A0
#define pinstSpellSets_x                                           0xFAE6A4
#define pinstStringTable_x                                         0xF23F9C
#define pinstSwitchManager_x                                       0xF21658
#define pinstTarget_x                                              0xF24020
#define pinstTargetObject_x                                        0xF23FF8
#define pinstTargetSwitch_x                                        0xF23FFC
#define pinstTaskMember_x                                          0xE6FC80
#define pinstTrackTarget_x                                         0xF24014
#define pinstTradeTarget_x                                         0xF24004
#define instTributeActive_x                                        0xC047CD
#define pinstViewActor_x                                           0xE707D4
#define pinstWorldData_x                                           0xF23FD8
#define pinstZoneAddr_x                                            0xF3198C
#define pinstPlayerPath_x                                          0xFB7110
#define pinstTargetIndicator_x                                     0xFB7B38
#define pinstCTargetManager_x                                      0xFB7B98
#define EQObject_Top_x                                             0xF23FE8
#define pinstRealEstateItems_x                                     0xFB76C4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE706F0
#define pinstCAchievementsWnd_x                                    0xE7074C
#define pinstCTextOverlay_x                                        0xD2D9A0
#define pinstCAudioTriggersWindow_x                                0xD2D788
#define pinstCCharacterSelect_x                                    0xE7065C
#define pinstCFacePick_x                                           0xE7040C
#define pinstCFindItemWnd_x                                        0xE706EC
#define pinstCNoteWnd_x                                            0xE70614
#define pinstCBookWnd_x                                            0xE7061C
#define pinstCPetInfoWnd_x                                         0xE70620
#define pinstCTrainWnd_x                                           0xE70624
#define pinstCSkillsWnd_x                                          0xE70628
#define pinstCSkillsSelectWnd_x                                    0xE7062C
#define pinstCCombatSkillsSelectWnd_x                              0xE70630
#define pinstCFriendsWnd_x                                         0xE70634
#define pinstCAuraWnd_x                                            0xE70638
#define pinstCRespawnWnd_x                                         0xE7063C
#define pinstCBandolierWnd_x                                       0xE70640
#define pinstCPotionBeltWnd_x                                      0xE70644
#define pinstCAAWnd_x                                              0xE70648
#define pinstCAlarmWnd_x                                           0xE70654
#define pinstCGroupSearchFiltersWnd_x                              0xE7064C
#define pinstCLoadskinWnd_x                                        0xE70650
#define pinstCLargeDialogWnd_x                                     0x10CA4B8
#define pinstCMusicPlayerWnd_x                                     0xE70658
#define pinstCMailWnd_x                                            0xE70660
#define pinstCMailCompositionWnd_x                                 0xE70664
#define pinstCMailAddressBookWnd_x                                 0xE70668
#define pinstCRaidWnd_x                                            0xE70670
#define pinstCRaidOptionsWnd_x                                     0xE70674
#define pinstCBreathWnd_x                                          0xE70678
#define pinstCMapViewWnd_x                                         0xE7067C
#define pinstCMapToolbarWnd_x                                      0xE70680
#define pinstCEditLabelWnd_x                                       0xE70684
#define pinstCTargetWnd_x                                          0xE70688
#define pinstCColorPickerWnd_x                                     0xE7068C
#define pinstCPlayerWnd_x                                          0xE70690
#define pinstCOptionsWnd_x                                         0xE70694
#define pinstCBuffWindowNORMAL_x                                   0xE70698
#define pinstCBuffWindowSHORT_x                                    0xE7069C
#define pinstCharacterCreation_x                                   0xE706A0
#define pinstCCursorAttachment_x                                   0xE706A4
#define pinstCCastingWnd_x                                         0xE706A8
#define pinstCCastSpellWnd_x                                       0xE706AC
#define pinstCSpellBookWnd_x                                       0xE706B0
#define pinstCInventoryWnd_x                                       0xE706B4
#define pinstCBankWnd_x                                            0xE706BC
#define pinstCQuantityWnd_x                                        0xE706C0
#define pinstCLootWnd_x                                            0xE706C4
#define pinstCActionsWnd_x                                         0xE706C8
#define pinstCCombatAbilityWnd_x                                   0xE706D0
#define pinstCMerchantWnd_x                                        0xE706D4
#define pinstCTradeWnd_x                                           0xE706DC
#define pinstCSelectorWnd_x                                        0xE706E0
#define pinstCBazaarWnd_x                                          0xE706E4
#define pinstCBazaarSearchWnd_x                                    0xE706E8
#define pinstCGiveWnd_x                                            0xE70708
#define pinstCTrackingWnd_x                                        0xE70710
#define pinstCInspectWnd_x                                         0xE70714
#define pinstCSocialEditWnd_x                                      0xE70718
#define pinstCFeedbackWnd_x                                        0xE7071C
#define pinstCBugReportWnd_x                                       0xE70720
#define pinstCVideoModesWnd_x                                      0xE70724
#define pinstCTextEntryWnd_x                                       0xE7072C
#define pinstCFileSelectionWnd_x                                   0xE70730
#define pinstCCompassWnd_x                                         0xE70734
#define pinstCPlayerNotesWnd_x                                     0xE70738
#define pinstCGemsGameWnd_x                                        0xE7073C
#define pinstCTimeLeftWnd_x                                        0xE70758
#define pinstCPetitionQWnd_x                                       0xE7075C
#define pinstCStoryWnd_x                                           0xE70760
#define pinstCJournalTextWnd_x                                     0xE70764
#define pinstCJournalCatWnd_x                                      0xE70768
#define pinstCBodyTintWnd_x                                        0xE7076C
#define pinstCServerListWnd_x                                      0xE70770
#define pinstCAvaZoneWnd_x                                         0xE7077C
#define pinstCBlockedBuffWnd_x                                     0xE70780
#define pinstCBlockedPetBuffWnd_x                                  0xE70784
#define pinstCInvSlotMgr_x                                         0xE707CC
#define pinstCContainerMgr_x                                       0xE707D0
#define pinstCAdventureLeaderboardWnd_x                            0x10C3DE8
#define pinstCAdventureRequestWnd_x                                0x10C3E60
#define pinstCAltStorageWnd_x                                      0x10C4140
#define pinstCAdventureStatsWnd_x                                  0x10C3ED8
#define pinstCBarterMerchantWnd_x                                  0x10C4E88
#define pinstCBarterSearchWnd_x                                    0x10C4F00
#define pinstCBarterWnd_x                                          0x10C4F78
#define pinstCChatWindowManager_x                                  0x10C5788
#define pinstCDynamicZoneWnd_x                                     0x10C5CB8
#define pinstCEQMainWnd_x                                          0x10C5E80
#define pinstCFellowshipWnd_x                                      0x10C5C4C
#define pinstCFindLocationWnd_x                                    0x10C6150
#define pinstCGroupSearchWnd_x                                     0x10C6420
#define pinstCGroupWnd_x                                           0x10C6498
#define pinstCGuildBankWnd_x                                       0x10C6510
#define pinstCGuildMgmtWnd_x                                       0x10C8600
#define pinstCHotButtonWnd_x                                       0x10C86FC
#define pinstCHotButtonWnd1_x                                      0x10C86FC
#define pinstCHotButtonWnd2_x                                      0x10C8700
#define pinstCHotButtonWnd3_x                                      0x10C8704
#define pinstCHotButtonWnd4_x                                      0x10C8728
#define pinstCItemDisplayManager_x                                 0x10C8B80
#define pinstCItemExpTransferWnd_x                                 0x10C8C7C
#define pinstCLFGuildWnd_x                                         0x10C8F58
#define pinstCMIZoneSelectWnd_x                                    0x10C9538
#define pinstCConfirmationDialog_x                                 0x10C9B50
#define pinstCPopupWndManager_x                                    0x10C9B50
#define pinstCProgressionSelectionWnd_x                            0x10C9C40
#define pinstCPvPStatsWnd_x                                        0x10C9D30
#define pinstCTaskWnd_x                                            0x10CB838
#define pinstCTaskSomething_x                                      0xD3E828
#define pinstCTaskTemplateSelectWnd_x                              0x10CB7C0
#define pinstCTipWndOFDAY_x                                        0x10CB9A0
#define pinstCTipWndCONTEXT_x                                      0x10CB9A4
#define pinstCTitleWnd_x                                           0x10CBA20
#define pinstCContextMenuManager_x                                 0x1731D20
#define pinstCVoiceMacroWnd_x                                      0xFB7F70
#define pinstCHtmlWnd_x                                            0xFB8060
#define pinstItemIconCache_x                                       0x10C5E28
#define pinstCTradeskillWnd_x                                      0x10CBB20
#define pinstCAdvancedLootWnd_x                                    0xE707C0
#define pinstRewardSelectionWnd_x                                  0x10CA258
#define pinstEQSuiteTextureLoader_x                                0xD1BA88

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54B080
#define __CastRay2_x                                               0x54A9B0
#define __HeadingDiff_x                                            0x9346B0
#define __FixHeading_x                                             0x934640
#define __get_bearing_x                                            0x53A920
#define __ConvertItemTags_x                                        0x5383F0
#define __ExecuteCmd_x                                             0x522CD0
#define __EQGetTime_x                                              0x8A3850
#define __get_melee_range_x                                        0x529990
#define __GetGaugeValueFromEQ_x                                    0x7B3200
#define __GetLabelFromEQ_x                                         0x7B45D0
#define __ToggleKeyRingItem_x                                      0x48FE30
#define __GetXTargetType_x                                         0x9362B0
#define __LoadFrontEnd_x                                           0x6406C0
#define __NewUIINI_x                                               0x7B2BD0
#define __ProcessGameEvents_x                                      0x584BB0
#define __ProcessMouseEvent_x                                      0x584350
#define CrashDetected_x                                            0x642080
#define wwsCrashReportCheckForUploader_x                           0x801550
#define __AppCrashWrapper_x                                        0xC68AC4
#define __pCrashHandler_x                                          0x10D8A00
#define __CrashHandler_x                                           0x800FE0
#define wwsCrashReportPlatformLaunchUploader_x                     0x803780
#define DrawNetStatus_x                                            0x5BB140
#define Util__FastTime_x                                           0x8A34F0
#define Expansion_HoT_x                                            0xF327D0
#define __HelpPath_x                                               0xFB5F80
#define __STMLToText_x                                             0x8E9EE0
#define __GetAnimationCache_x                                      0x6AFD80

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423330
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DF90
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DD60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8130
#define AltAdvManager__IsAbilityReady_x                            0x4D81A0
#define AltAdvManager__GetAAById_x                                 0x4D8690
#define AltAdvManager__CanTrainAbility_x                           0x4D92C0
#define AltAdvManager__CanSeeAbility_x                             0x4D8E80

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AFC0
#define CharacterZoneClient__HasSkill_x                            0x466ED0
#define CharacterZoneClient__MakeMeVisible_x                       0x46CB30
#define CharacterZoneClient__IsStackBlocked_x                      0x44BFE0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B500
#define CharacterZoneClient__GetItemCountWorn_x                    0x465430
#define CharacterZoneClient__GetItemCountInInventory_x             0x465510
#define CharacterZoneClient__GetCursorItemCount_x                  0x4655F0
#define CharacterZoneClient__FindAffectSlot_x                      0x451660
#define CharacterZoneClient__BardCastBard_x                        0x44AC70
#define CharacterZoneClient__GetMaxEffects_x                       0x449800
#define CharacterZoneClient__GetEffect_x                           0x44B730
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4514C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449B50
#define CharacterZoneClient__GetLastEffectSlot_x                   0x450010

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66FFD0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67DE80

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x599CA0
#define CButtonWnd__CButtonWnd_x                                   0x8DE0D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x698EC0
#define CChatManager__InitContextMenu_x                            0x69A010
#define CChatManager__FreeChatWindow_x                             0x698970
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A2190
#define CChatManager__SetLockedActiveChatWindow_x                  0x698E90

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E8230
#define CContextMenu__dCContextMenu_x                              0x8E8440
#define CContextMenu__AddMenuItem_x                                0x8E8960
#define CContextMenu__RemoveMenuItem_x                             0x8E85C0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E85E0
#define CContextMenu__CheckMenuItem_x                              0x8E8660
#define CContextMenu__SetMenuItem_x                                0x8E84E0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D4690
#define CContextMenuManager__RemoveMenu_x                          0x8D4A20
#define CContextMenuManager__PopupMenu_x                           0x8D4E70
#define CContextMenuManager__Flush_x                               0x8D4700
#define CContextMenuManager__GetMenu_x                             0x419440

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x887820
#define CChatService__GetFriendName_x                              0x887830

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69FC60
#define CChatWindow__Clear_x                                       0x69F550
#define CChatWindow__WndNotification_x                             0x6A0570

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D84E0
#define CComboWnd__Draw_x                                          0x8D86F0
#define CComboWnd__GetCurChoice_x                                  0x8D8290
#define CComboWnd__GetListRect_x                                   0x8D8990
#define CComboWnd__GetTextRect_x                                   0x8D8550
#define CComboWnd__InsertChoice_x                                  0x8D8AF0
#define CComboWnd__SetColors_x                                     0x8D8220
#define CComboWnd__SetChoice_x                                     0x8D8250
#define CComboWnd__GetItemCount_x                                  0x8D8280
#define CComboWnd__GetCurChoiceText_x                              0x8D82D0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A9EF0
#define CContainerWnd__vftable_x                                   0xAEE998

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
#define CEditBaseWnd__SetSel_x                                     0x8FF260

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EC790
#define CEditWnd__GetCharIndexPt_x                                 0x8ED8F0
#define CEditWnd__GetDisplayString_x                               0x8EC940
#define CEditWnd__GetHorzOffset_x                                  0x8ECC80
#define CEditWnd__GetLineForPrintableChar_x                        0x8ED3B0
#define CEditWnd__GetSelStartPt_x                                  0x8EDBB0
#define CEditWnd__GetSTMLSafeText_x                                0x8ECE20
#define CEditWnd__PointFromPrintableChar_x                         0x8ED4A0
#define CEditWnd__SelectableCharFromPoint_x                        0x8ED620
#define CEditWnd__SetEditable_x                                    0x8ECDF0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56B300
#define CEverQuest__ClickedPlayer_x                                0x564ED0
#define CEverQuest__CreateTargetIndicator_x                        0x565DD0
#define CEverQuest__DeleteTargetIndicator_x                        0x565E50
#define CEverQuest__DoTellWindow_x                                 0x476200
#define CEverQuest__OutputTextToLog_x                              0x475E60
#define CEverQuest__DropHeldItemOnGround_x                         0x57B870
#define CEverQuest__dsp_chat_x                                     0x476540
#define CEverQuest__trimName_x                                     0x5617E0
#define CEverQuest__Emote_x                                        0x579B80
#define CEverQuest__EnterZone_x                                    0x574C60
#define CEverQuest__GetBodyTypeDesc_x                              0x55F220
#define CEverQuest__GetClassDesc_x                                 0x568710
#define CEverQuest__GetClassThreeLetterCode_x                      0x568D10
#define CEverQuest__GetDeityDesc_x                                 0x55FB00
#define CEverQuest__GetLangDesc_x                                  0x55F5B0
#define CEverQuest__GetRaceDesc_x                                  0x568ED0
#define CEverQuest__InterpretCmd_x                                 0x56CA80
#define CEverQuest__LeftClickedOnPlayer_x                          0x5813C0
#define CEverQuest__LMouseUp_x                                     0x583370
#define CEverQuest__RightClickedOnPlayer_x                         0x581ED0
#define CEverQuest__RMouseUp_x                                     0x582DD0
#define CEverQuest__SetGameState_x                                 0x5657A0
#define CEverQuest__UPCNotificationFlush_x                         0x55DBB0
#define CEverQuest__IssuePetCommand_x                              0x56D460

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BAB70
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BABD0
#define CGaugeWnd__Draw_x                                          0x6BB000

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B250
#define CGuild__GetGuildName_x                                     0x43B720
#define CGuild__GetGuildIndex_x                                    0x43C930

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D7080

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E4410
#define CInvSlotMgr__MoveItem_x                                    0x6E4BD0
#define CInvSlotMgr__SelectSlot_x                                  0x6E3D00

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E3160
#define CInvSlot__SliderComplete_x                                 0x6E0990
#define CInvSlot__GetItemBase_x                                    0x6DFE30
#define CInvSlot__UpdateItem_x                                     0x6E03B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E5FF0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E7120

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AF060
#define CItemDisplayWnd__UpdateStrings_x                           0x6E8220
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F4AA0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F4FA0
#define CItemDisplayWnd__SetItem_x                                 0x6FA840

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E6320

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EE7C0

// CLabel 
#define CLabel__Draw_x                                             0x701610

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C3F50
#define CListWnd__dCListWnd_x                                      0x8C5210
#define CListWnd__AddColumn_x                                      0x8C51B0
#define CListWnd__AddColumn1_x                                     0x8C4840
#define CListWnd__AddLine_x                                        0x8C4220
#define CListWnd__AddString_x                                      0x8C4440
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C1050
#define CListWnd__CalculateVSBRange_x                              0x8C3420
#define CListWnd__ClearSel_x                                       0x8C0360
#define CListWnd__ClearAllSel_x                                    0x8C0310
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C3DE0
#define CListWnd__Compare_x                                        0x8C1D50
#define CListWnd__Draw_x                                           0x8C3020
#define CListWnd__DrawColumnSeparators_x                           0x8C2EB0
#define CListWnd__DrawHeader_x                                     0x8C0620
#define CListWnd__DrawItem_x                                       0x8C23E0
#define CListWnd__DrawLine_x                                       0x8C2B50
#define CListWnd__DrawSeparator_x                                  0x8C2F50
#define CListWnd__EnableLine_x                                     0x8C0540
#define CListWnd__EnsureVisible_x                                  0x8C11B0
#define CListWnd__ExtendSel_x                                      0x8C22F0
#define CListWnd__GetColumnMinWidth_x                              0x8BFC50
#define CListWnd__GetColumnWidth_x                                 0x8BFB80
#define CListWnd__GetCurSel_x                                      0x8BF350
#define CListWnd__GetItemAtPoint_x                                 0x8C1450
#define CListWnd__GetItemAtPoint1_x                                0x8C14C0
#define CListWnd__GetItemData_x                                    0x8BF6A0
#define CListWnd__GetItemHeight_x                                  0x8C0CA0
#define CListWnd__GetItemIcon_x                                    0x8BF890
#define CListWnd__GetItemRect_x                                    0x8C1290
#define CListWnd__GetItemText_x                                    0x8BF740
#define CListWnd__GetSelList_x                                     0x8C4730
#define CListWnd__GetSeparatorRect_x                               0x8C1C70
#define CListWnd__InsertLine_x                                     0x8C4620
#define CListWnd__RemoveLine_x                                     0x8C4630
#define CListWnd__SetColors_x                                      0x8BF4A0
#define CListWnd__SetColumnJustification_x                         0x8BFEE0
#define CListWnd__SetColumnWidth_x                                 0x8BFC00
#define CListWnd__SetCurSel_x                                      0x8BF390
#define CListWnd__SetItemColor_x                                   0x8C3AD0
#define CListWnd__SetItemData_x                                    0x8C03C0
#define CListWnd__SetItemText_x                                    0x8C3910
#define CListWnd__ShiftColumnSeparator_x                           0x8C37A0
#define CListWnd__Sort_x                                           0x8C5310
#define CListWnd__ToggleSel_x                                      0x8C0290

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71A7F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73FF90
#define CMerchantWnd__RequestBuyItem_x                             0x747B10
#define CMerchantWnd__RequestSellItem_x                            0x74A110
#define CMerchantWnd__SelectRecoverySlot_x                         0x73D260
#define CMerchantWnd__SelectBuySellSlot_x                          0x73B100
#define CMerchantWnd__ActualSelect_x                               0x741D70

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x855C40
#define CPacketScrambler__hton_x                                   0x855C50

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E30E0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E31C0
#define CSidlManager__CreateLabel_x                                0x7A3F70
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E1670
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E34A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8DA520
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8DA420
#define CSidlScreenWnd__ConvertToRes_x                             0x8FF140
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DAE40
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DC030
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DC0E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DB5A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8DA7F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D9F50
#define CSidlScreenWnd__GetSidlPiece_x                             0x8DA9E0
#define CSidlScreenWnd__Init1_x                                    0x8DBD00
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DAF00
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8DA110
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DB7E0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D9BB0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D9F00
#define CSidlScreenWnd__WndNotification_x                          0x8DBA80
#define CSidlScreenWnd__GetChildItem_x                             0x8DA020
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CD840
#define CSidlScreenWnd__m_layoutCopy_x                             0x1731E40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x606110
#define CSkillMgr__GetSkillCap_x                                   0x6062F0
#define CSkillMgr__GetNameToken_x                                  0x605CC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FE3F0
#define CSliderWnd__SetValue_x                                     0x8FE5C0
#define CSliderWnd__SetNumTicks_x                                  0x8FED40

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7AA340

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F8230
#define CStmlWnd__CalculateHSBRange_x                              0x8F0780
#define CStmlWnd__CalculateVSBRange_x                              0x8F06F0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F0900
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F1100
#define CStmlWnd__ForceParseNow_x                                  0x8F8BB0
#define CStmlWnd__GetNextTagPiece_x                                0x8F1000
#define CStmlWnd__GetSTMLText_x                                    0x484390
#define CStmlWnd__GetVisibleText_x                                 0x8F1B50
#define CStmlWnd__InitializeWindowVariables_x                      0x8F4120
#define CStmlWnd__MakeStmlColorTag_x                               0x8EF9D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EFA30
#define CStmlWnd__SetSTMLText_x                                    0x8F5970
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F7ED0
#define CStmlWnd__UpdateHistoryString_x                            0x8F2A90

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FC0D0
#define CTabWnd__DrawCurrentPage_x                                 0x8FB960
#define CTabWnd__DrawTab_x                                         0x8FB720
#define CTabWnd__GetCurrentPage_x                                  0x8FBD10
#define CTabWnd__GetPageInnerRect_x                                0x8FB410
#define CTabWnd__GetTabInnerRect_x                                 0x8FB610
#define CTabWnd__GetTabRect_x                                      0x8FB4E0
#define CTabWnd__InsertPage_x                                      0x8FC3C0
#define CTabWnd__SetPage_x                                         0x8FBD40
#define CTabWnd__SetPageRect_x                                     0x8FC010
#define CTabWnd__UpdatePage_x                                      0x8FC360
#define CTabWnd__GetPageFromTabIndex_x                             0x8FB670
#define CTabWnd__GetCurrentTabIndex_x                              0x8FB3A0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E72D0
#define CPageWnd__SetTabText_x                                     0x908560

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436E00

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D7E90
#define CTextureFont__GetTextExtent_x                              0x8D7BF0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63E960

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9049A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BD3A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402A20
#define CXStr__CXStr1_x                                            0x9035F0
#define CXStr__CXStr3_x                                            0x8A0780
#define CXStr__dCXStr_x                                            0x608DD0
#define CXStr__operator_equal_x                                    0x8A08F0
#define CXStr__operator_equal1_x                                   0x8A0940
#define CXStr__operator_plus_equal1_x                              0x8A1A40

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D5990
#define CXWnd__BringToTop_x                                        0x8CCA00
#define CXWnd__Center_x                                            0x8D2C70
#define CXWnd__ClrFocus_x                                          0x8CC5F0
#define CXWnd__Destroy_x                                           0x8D3750
#define CXWnd__DoAllDrawing_x                                      0x8D28C0
#define CXWnd__DrawChildren_x                                      0x8D2A60
#define CXWnd__DrawColoredRect_x                                   0x8CCDE0
#define CXWnd__DrawTooltip_x                                       0x8CD090
#define CXWnd__DrawTooltipAtPoint_x                                0x8D1810
#define CXWnd__GetBorderFrame_x                                    0x8CD500
#define CXWnd__GetChildWndAt_x                                     0x8D3630
#define CXWnd__GetClientClipRect_x                                 0x8CD2B0
#define CXWnd__GetScreenClipRect_x                                 0x8D1F10
#define CXWnd__GetScreenRect_x                                     0x8CD6D0
#define CXWnd__GetTooltipRect_x                                    0x8CCF20
#define CXWnd__GetWindowTextA_x                                    0x426F40
#define CXWnd__IsActive_x                                          0x8C8020
#define CXWnd__IsDescendantOf_x                                    0x8CD440
#define CXWnd__IsReallyVisible_x                                   0x8D0830
#define CXWnd__IsType_x                                            0x8D2CE0
#define CScreenPieceTemplate__IsType_x                             0x901030
#define CXWnd__Move_x                                              0x8CFF10
#define CXWnd__Move1_x                                             0x8D2570
#define CXWnd__ProcessTransition_x                                 0x8CC9B0
#define CXWnd__Refade_x                                            0x8CC790
#define CXWnd__Resize_x                                            0x8CD7A0
#define CXWnd__Right_x                                             0x8D1D10
#define CXWnd__SetFocus_x                                          0x8CF070
#define CXWnd__SetFont_x                                           0x8CC640
#define CXWnd__SetKeyTooltip_x                                     0x8CDA10
#define CXWnd__SetMouseOver_x                                      0x8D2260
#define CXWnd__StartFade_x                                         0x8CCA50
#define CXWnd__GetChildItem_x                                      0x8D21A0
#define CXWnd__SetParent_x                                         0x8D35E0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C98B0
#define CXWndManager__DrawWindows_x                                0x8C94F0
#define CXWndManager__GetKeyboardFlags_x                           0x8C7B60
#define CXWndManager__HandleKeyboardMsg_x                          0x8C84C0
#define CXWndManager__RemoveWnd_x                                  0x8C81B0

// CDBStr
#define CDBStr__GetString_x                                        0x4BA670

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452720
#define EQ_Character__Cur_HP_x                                     0x466AB0
#define EQ_Character__Cur_Mana_x                                   0x45BAB0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B810
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4437E0
#define EQ_Character__GetFocusRangeModifier_x                      0x443930
#define EQ_Character__GetHPRegen_x                                 0x46A650
#define EQ_Character__GetEnduranceRegen_x                          0x4660C0
#define EQ_Character__GetManaRegen_x                               0x46ABF0
#define EQ_Character__Max_Endurance_x                              0x5CCFD0
#define EQ_Character__Max_HP_x                                     0x45E630
#define EQ_Character__Max_Mana_x                                   0x5CCE00
#define EQ_Character__doCombatAbility_x                            0x5CA4D0
#define EQ_Character__UseSkill_x                                   0x4729E0
#define EQ_Character__GetConLevel_x                                0x5BF720
#define EQ_Character__IsExpansionFlag_x                            0x4B69C0
#define EQ_Character__TotalEffect_x                                0x44F950
#define EQ_Character__GetPCSpellAffect_x                           0x44BBA0
#define EQ_Character__SpellDuration_x                              0x449BA0
#define EQ_Character__FindItemByRecord_x                           0x464120
#define EQ_Character__GetAdjustedSkill_x                           0x466C80
#define EQ_Character__GetBaseSkill_x                               0x45E510

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x873A30

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D5600

//PcClient
#define PcClient__PcClient_x                                       0x5C1570

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446CD0
#define CCharacterSelect__EnterWorld_x                             0x4464A0
#define CCharacterSelect__Quit_x                                   0x445060

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59F640
#define EQ_Item__CreateItemTagString_x                             0x853E20
#define EQ_Item__IsStackable_x                                     0x8490E0
#define EQ_Item__GetImageNum_x                                     0x84BBD0
#define EQ_Item__CreateItemClient_x                                0x5A0770
#define EQ_Item__GetItemValue_x                                    0x852800
#define EQ_Item__ValueSellMerchant_x                               0x8558D0
#define EQ_Item__IsKeyRingItem_x                                   0x849BD0
#define EQ_Item__CanGoInBag_x                                      0x59F7D0
#define EQ_Item__GetMaxItemCount_x                                 0x848FD0
#define EQ_Item__GetHeldItem_x                                     0x84AA00
#define EQ_Item__GetAugmentFitBySlot_x                             0x855700

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA730
#define EQ_LoadingS__Array_x                                       0xC0CC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CF4F0
#define EQ_PC__GetAlternateAbilityId_x                             0x85DC20
#define EQ_PC__GetCombatAbility_x                                  0x85DCB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8588F0
#define EQ_PC__GetItemRecastTimer_x                                0x5C8CC0
#define EQ_PC__HasLoreItem_x                                       0x5C2D30
#define EQ_PC__AlertInventoryChanged_x                             0x5BF6D0
#define EQ_PC__GetPcZoneClient_x                                   0x5E9BC0
#define EQ_PC__RemoveMyAffect_x                                    0x5C80F0
#define EQ_PC__GetKeyRingItems_x                                   0x858D10
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86B920
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85FB90

// EQItemList 
#define EQItemList__EQItemList_x                                   0x527A30
#define EQItemList__add_object_x                                   0x554B10
#define EQItemList__add_item_x                                     0x527970
#define EQItemList__delete_item_x                                  0x527E20
#define EQItemList__FreeItemList_x                                 0x527D20

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9920

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D52C0
#define EQPlayer__dEQPlayer_x                                      0x5DDA80
#define EQPlayer__DoAttack_x                                       0x5EF3A0
#define EQPlayer__EQPlayer_x                                       0x5E01B0
#define EQPlayer__SetNameSpriteState_x                             0x5DA8B0
#define EQPlayer__SetNameSpriteTint_x                              0x5D67C0
#define PlayerBase__HasProperty_j_x                                0x932A70
#define EQPlayer__IsTargetable_x                                   0x932D10
#define EQPlayer__CanSee_x                                         0x933270
#define PlayerZoneClient__ChangeHeight_x                           0x5EF260
#define EQPlayer__CanSee1_x                                        0x933360
#define PlayerBase__GetVisibilityLineSegment_x                     0x933000

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E9D70
#define PlayerZoneClient__IsValidTeleport_x                        0x5553B0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2A40


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E4200
#define EQPlayerManager__GetSpawnByName_x                          0x5E4660
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E4230

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A5D30
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A5D70
#define KeypressHandler__ClearCommandStateArray_x                  0x5A5920
#define KeypressHandler__HandleKeyDown_x                           0x5A4240
#define KeypressHandler__HandleKeyUp_x                             0x5A4560
#define KeypressHandler__SaveKeymapping_x                          0x5A59F0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x713180
#define MapViewMap__SaveEx_x                                       0x7164B0
#define MapViewMap__SetZoom_x                                      0x712DF0

#define PlayerPointManager__GetAltCurrency_x                       0x871AF0

// StringTable 
#define StringTable__getString_x                                   0x86BC50

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CCA60
#define PcZoneClient__RemovePetEffect_x                            0x5C9190
#define PcZoneClient__HasAlternateAbility_x                        0x5C9B30
#define PcZoneClient__GetCurrentMod_x                              0x45DAE0
#define PcZoneClient__GetModCap_x                                  0x45B210
#define PcZoneClient__CanEquipItem_x                               0x5CA010
#define PcZoneClient__GetItemByID_x                                0x5CE870
#define PcZoneClient__GetItemByItemClass_x                         0x5CF410
#define PcZoneClient__RemoveBuffEffect_x                           0x5C83A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55C4E0

//IconCache
#define IconCache__GetIcon_x                                       0x6B03B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A7290
#define CContainerMgr__CloseContainer_x                            0x6A7AB0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x773E60

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5986C0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4EE0
#define EQ_Spell__SpellAffects_x                                   0x4F20C0
#define EQ_Spell__SpellAffectBase_x                                0x4F2130
#define CharacterZoneClient__CalcAffectChange_x                    0x44BA30
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ACD0
#define CLootWnd__LootAll_x                                        0x7089E0
#define CLootWnd__RequestLootSlot_x                                0x7091F0
#define EQ_Spell__IsStackable_x                                    0x4591F0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449670
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43ED30
#define EQ_Spell__IsSPAStacking_x                                  0x4F1C30
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2CD0
#define EQ_Spell__IsNoRemove_x                                     0x434E20
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1C50

#define __IsResEffectSpell_x                                       0x4496F0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87D6C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BBCD0
#define CTargetWnd__WndNotification_x                              0x7BB7C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BBEB0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C0E00

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED710
#define EqSoundManager__PlayScriptMp3_x                            0x4EF1B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8A50

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EBDC0
#define CSidlManager__FindAnimation1_x                             0x8E10A0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2030
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1FE0
#define CAltAbilityData__GetMaxRank_x                              0x4D67E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x596300

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4594D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x475410
#define CharacterBase__CreateItemIndex_x                           0x521040
#define CharacterBase__GetItemPossession_x                         0x444530
#define CharacterBase__GetItemByGlobalIndex_x                      0x881500
#define CharacterBase__GetEffectId_x                               0x459490

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x690100
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68F860

//messages
#define msg_spell_worn_off_x                                       0x4FCA10
#define msg_new_text_x                                             0x506190
#define msgTokenTextParam_x                                        0x502990

//SpellManager
#define SpellManager__vftable_x                                    0xACA268
#define SpellManager__SpellManager_x                               0x47E000
#define Spellmanager__LoadTextSpells_x                             0x60CFD0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x936DD0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487EA0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EC50
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4493A0
#define ItemGlobalIndex__IsValidIndex_x                            0x458D30

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87F380
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87E2C0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x701860

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6ABFD0
#define CCursorAttachment__Deactivate_x                            0x6AB520

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FD8F0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FDA70

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x604C80

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C710

//IString
#define IString__Append_x                                          0x47EC30

//Camera
#define CDisplay__cameraType_x                                     0xE707E8
#define EverQuest__Cameras_x                                       0xF32AE8
