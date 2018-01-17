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
#define __ExpectedVersionDate                                     "Jan  8 2018"
#define __ExpectedVersionTime                                     "16:56:08"
#define __ActualVersionDate_x                                      0xAE70B8
#define __ActualVersionTime_x                                      0xAE70C4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5AC0C0
#define __MemChecker1_x                                            0x8A5D60
#define __MemChecker2_x                                            0x641CC0
#define __MemChecker3_x                                            0x641C10
#define __MemChecker4_x                                            0x7F74D0
#define __EncryptPad0_x                                            0xC41FE8
#define __EncryptPad1_x                                            0xD1BBA0
#define __EncryptPad2_x                                            0xC6AED0
#define __EncryptPad3_x                                            0xC6AAD0
#define __EncryptPad4_x                                            0xD0A1A0
#define __EncryptPad5_x                                            0x10C52E0
#define __AC1_x                                                    0x7B54D5
#define __AC2_x                                                    0x565087
#define __AC3_x                                                    0x563200
#define __AC4_x                                                    0x575461
#define __AC5_x                                                    0x58921B
#define __AC6_x                                                    0x58CDCE
#define __AC7_x                                                    0x58381C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FACEE0

// Direct Input
#define DI8__Main_x                                                0x10C52B8
#define DI8__Keyboard_x                                            0x10C52BC
#define DI8__Mouse_x                                               0x10C52C0
#define DI8__Mouse_Copy_x                                          0xF33474
#define DI8__Mouse_Check_x                                         0xFBCFA4
#define __AutoSkillArray_x                                         0xF34388
#define __Attack_x                                                 0xFB7A7B
#define __Autofire_x                                               0xFB7A7C
#define __BindList_x                                               0xC1E368
#define g_eqCommandStates_x                                        0xF221C0
#define __Clicks_x                                                 0xF33530
#define __CommandList_x                                            0xC20A80
#define __CurrentMapLabel_x                                        0x10CB2B0
#define __CurrentSocial_x                                          0xBED8E8
#define __DoAbilityList_x                                          0xF69C40
#define __do_loot_x                                                0x534070
#define __DrawHandler_x                                            0x1734F5C
#define __GroupCount_x                                             0xF23ACA

#define __Guilds_x                                                 0xF296E0
#define __gWorld_x                                                 0xF25F84
#define __HotkeyPage_x                                             0xFB0640
#define __HWnd_x                                                   0xFBD0C0
#define __InChatMode_x                                             0xF3345C
#define __LastTell_x                                               0xF3533C
#define __LMouseHeldTime_x                                         0xF3359C
#define __Mouse_x                                                  0x10C52C4
#define __MouseLook_x                                              0xF334F6
#define __MouseEventTime_x                                         0xFB8214
#define __gpbCommandEvent_x                                        0xF2604C
#define __NetStatusToggle_x                                        0xF334F9
#define __PCNames_x                                                0xF34944
#define __RangeAttackReady_x                                       0xF3466C
#define __RMouseHeldTime_x                                         0xF33598
#define __RunWalkState_x                                           0xF33460
#define __ScreenMode_x                                             0xE71DA0
#define __ScreenX_x                                                0xF33414
#define __ScreenY_x                                                0xF33410
#define __ScreenXMax_x                                             0xF33418
#define __ScreenYMax_x                                             0xF3341C
#define __ServerHost_x                                             0xF23A14
#define __ServerName_x                                             0xF69C00
#define __ShiftKeyDown_x                                           0xF33AF0
#define __ShowNames_x                                              0xF34824
#define __Socials_x                                                0xF69D00
#define __SubscriptionType_x                                       0x10FBA34
#define __TargetAggroHolder_x                                      0x10CD40C
#define __ZoneType_x                                               0xF338F4
#define __GroupAggro_x                                             0x10CD44C
#define __LoginName_x                                              0xFBBB9C
#define __Inviter_x                                                0xFB79F8
#define __AttackOnAssist_x                                         0xF347E0
#define __UseTellWindows_x                                         0xF34ADC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF26070
#define instEQZoneInfo_x                                           0xF336EC
#define instKeypressHandler_x                                      0xFB81F8
#define pinstActiveBanker_x                                        0xF26028
#define pinstActiveCorpse_x                                        0xF2602C
#define pinstActiveGMaster_x                                       0xF26030
#define pinstActiveMerchant_x                                      0xF26024
#define pinstAggroInfo_x                                           0xD2F40C
#define pinstAltAdvManager_x                                       0xE72F08
#define pinstAuraMgr_x                                             0xD3FC10
#define pinstBandageTarget_x                                       0xF26010
#define pinstCamActor_x                                            0xE727D8
#define pinstCDBStr_x                                              0xE71D34
#define pinstCDisplay_x                                            0xF26038
#define pinstCEverQuest_x                                          0x10C5438
#define pinstEverQuestInfo_x                                       0xF33408
#define pinstCharData_x                                            0xF25FF4
#define pinstCharSpawn_x                                           0xF2601C
#define pinstControlledMissile_x                                   0xF25FF0
#define pinstControlledPlayer_x                                    0xF2601C
#define pinstCSidlManager_x                                        0x1733E98
#define pinstCXWndManager_x                                        0x1733E90
#define instDynamicZone_x                                          0xF332A8
#define pinstDZMember_x                                            0xF333B8
#define pinstDZTimerInfo_x                                         0xF333BC
#define pinstEQItemList_x                                          0xF22498
#define pinstEQObjectList_x                                        0xF234C4
#define instEQMisc_x                                               0xC067A8
#define pinstEQSoundManager_x                                      0xE734D8
#define instExpeditionLeader_x                                     0xF332F2
#define instExpeditionName_x                                       0xF33332
#define pinstGroup_x                                               0xF23AC6
#define pinstImeManager_x                                          0x1733E9C
#define pinstLocalPlayer_x                                         0xF26008
#define pinstMercenaryData_x                                       0xFB8860
#define pinstMercenaryStats_x                                      0x10CD558
#define pinstMercAltAbilities_x                                    0xE73290
#define pinstModelPlayer_x                                         0xF26034
#define pinstPCData_x                                              0xF25FF4
#define pinstSkillMgr_x                                            0xFB9858
#define pinstSpawnManager_x                                        0xFB90B0
#define pinstSpellManager_x                                        0xFB99A0
#define pinstSpellSets_x                                           0xFB06A4
#define pinstStringTable_x                                         0xF25F9C
#define pinstSwitchManager_x                                       0xF23658
#define pinstTarget_x                                              0xF26020
#define pinstTargetObject_x                                        0xF25FF8
#define pinstTargetSwitch_x                                        0xF25FFC
#define pinstTaskMember_x                                          0xE71C80
#define pinstTrackTarget_x                                         0xF26014
#define pinstTradeTarget_x                                         0xF26004
#define instTributeActive_x                                        0xC067CD
#define pinstViewActor_x                                           0xE727D4
#define pinstWorldData_x                                           0xF25FD8
#define pinstZoneAddr_x                                            0xF3398C
#define pinstPlayerPath_x                                          0xFB9110
#define pinstTargetIndicator_x                                     0xFB9B38
#define pinstCTargetManager_x                                      0xFB9B98
#define EQObject_Top_x                                             0xF25FE8
#define pinstRealEstateItems_x                                     0xFB96C4

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE726F0
#define pinstCAchievementsWnd_x                                    0xE7274C
#define pinstCTextOverlay_x                                        0xD2F9A0
#define pinstCAudioTriggersWindow_x                                0xD2F788
#define pinstCCharacterSelect_x                                    0xE7265C
#define pinstCFacePick_x                                           0xE7240C
#define pinstCFindItemWnd_x                                        0xE726EC
#define pinstCNoteWnd_x                                            0xE72614
#define pinstCBookWnd_x                                            0xE7261C
#define pinstCPetInfoWnd_x                                         0xE72620
#define pinstCTrainWnd_x                                           0xE72624
#define pinstCSkillsWnd_x                                          0xE72628
#define pinstCSkillsSelectWnd_x                                    0xE7262C
#define pinstCCombatSkillsSelectWnd_x                              0xE72630
#define pinstCFriendsWnd_x                                         0xE72634
#define pinstCAuraWnd_x                                            0xE72638
#define pinstCRespawnWnd_x                                         0xE7263C
#define pinstCBandolierWnd_x                                       0xE72640
#define pinstCPotionBeltWnd_x                                      0xE72644
#define pinstCAAWnd_x                                              0xE72648
#define pinstCGroupSearchFiltersWnd_x                              0xE7264C
#define pinstCLoadskinWnd_x                                        0xE72650
#define pinstCAlarmWnd_x                                           0xE72654
#define pinstCMusicPlayerWnd_x                                     0xE72658
#define pinstCMailWnd_x                                            0xE72660
#define pinstCMailCompositionWnd_x                                 0xE72664
#define pinstCMailAddressBookWnd_x                                 0xE72668
#define pinstCRaidWnd_x                                            0xE72670
#define pinstCRaidOptionsWnd_x                                     0xE72674
#define pinstCBreathWnd_x                                          0xE72678
#define pinstCMapViewWnd_x                                         0xE7267C
#define pinstCMapToolbarWnd_x                                      0xE72680
#define pinstCEditLabelWnd_x                                       0xE72684
#define pinstCTargetWnd_x                                          0xE72688
#define pinstCColorPickerWnd_x                                     0xE7268C
#define pinstCPlayerWnd_x                                          0xE72690
#define pinstCOptionsWnd_x                                         0xE72694
#define pinstCBuffWindowNORMAL_x                                   0xE72698
#define pinstCBuffWindowSHORT_x                                    0xE7269C
#define pinstCharacterCreation_x                                   0xE726A0
#define pinstCCursorAttachment_x                                   0xE726A4
#define pinstCCastingWnd_x                                         0xE726A8
#define pinstCCastSpellWnd_x                                       0xE726AC
#define pinstCSpellBookWnd_x                                       0xE726B0
#define pinstCInventoryWnd_x                                       0xE726B4
#define pinstCBankWnd_x                                            0xE726BC
#define pinstCQuantityWnd_x                                        0xE726C0
#define pinstCLootWnd_x                                            0xE726C4
#define pinstCActionsWnd_x                                         0xE726C8
#define pinstCCombatAbilityWnd_x                                   0xE726D0
#define pinstCMerchantWnd_x                                        0xE726D4
#define pinstCTradeWnd_x                                           0xE726DC
#define pinstCSelectorWnd_x                                        0xE726E0
#define pinstCBazaarWnd_x                                          0xE726E4
#define pinstCBazaarSearchWnd_x                                    0xE726E8
#define pinstCGiveWnd_x                                            0xE72708
#define pinstCTrackingWnd_x                                        0xE72710
#define pinstCInspectWnd_x                                         0xE72714
#define pinstCSocialEditWnd_x                                      0xE72718
#define pinstCFeedbackWnd_x                                        0xE7271C
#define pinstCBugReportWnd_x                                       0xE72720
#define pinstCVideoModesWnd_x                                      0xE72724
#define pinstCTextEntryWnd_x                                       0xE7272C
#define pinstCFileSelectionWnd_x                                   0xE72730
#define pinstCCompassWnd_x                                         0xE72734
#define pinstCPlayerNotesWnd_x                                     0xE72738
#define pinstCGemsGameWnd_x                                        0xE7273C
#define pinstCTimeLeftWnd_x                                        0xE72758
#define pinstCPetitionQWnd_x                                       0xE7275C
#define pinstCStoryWnd_x                                           0xE72760
#define pinstCJournalTextWnd_x                                     0xE72764
#define pinstCJournalCatWnd_x                                      0xE72768
#define pinstCBodyTintWnd_x                                        0xE7276C
#define pinstCServerListWnd_x                                      0xE72770
#define pinstCAvaZoneWnd_x                                         0xE7277C
#define pinstCBlockedBuffWnd_x                                     0xE72780
#define pinstCBlockedPetBuffWnd_x                                  0xE72784
#define pinstCInvSlotMgr_x                                         0xE727CC
#define pinstCContainerMgr_x                                       0xE727D0
#define pinstCAdventureLeaderboardWnd_x                            0x10C5DE8
#define pinstCAdventureRequestWnd_x                                0x10C5E60
#define pinstCAltStorageWnd_x                                      0x10C6140
#define pinstCAdventureStatsWnd_x                                  0x10C5ED8
#define pinstCBarterMerchantWnd_x                                  0x10C6E88
#define pinstCBarterSearchWnd_x                                    0x10C6F00
#define pinstCBarterWnd_x                                          0x10C6F78
#define pinstCChatWindowManager_x                                  0x10C7788
#define pinstCDynamicZoneWnd_x                                     0x10C7CB8
#define pinstCEQMainWnd_x                                          0x10C7E80
#define pinstCFellowshipWnd_x                                      0x10C7C4C
#define pinstCFindLocationWnd_x                                    0x10C8150
#define pinstCGroupSearchWnd_x                                     0x10C8420
#define pinstCGroupWnd_x                                           0x10C8498
#define pinstCGuildBankWnd_x                                       0x10C8510
#define pinstCGuildMgmtWnd_x                                       0x10CA600
#define pinstCHotButtonWnd_x                                       0x10CA6FC
#define pinstCHotButtonWnd1_x                                      0x10CA6FC
#define pinstCHotButtonWnd2_x                                      0x10CA700
#define pinstCHotButtonWnd3_x                                      0x10CA704
#define pinstCHotButtonWnd4_x                                      0x10CA728
#define pinstCItemDisplayManager_x                                 0x10CAB80
#define pinstCItemExpTransferWnd_x                                 0x10CAC7C
#define pinstCLFGuildWnd_x                                         0x10CAF58
#define pinstCMIZoneSelectWnd_x                                    0x10CB538
#define pinstCConfirmationDialog_x                                 0x10CBB50
#define pinstCPopupWndManager_x                                    0x10CBB50
#define pinstCProgressionSelectionWnd_x                            0x10CBC40
#define pinstCPvPStatsWnd_x                                        0x10CBD30
#define pinstCLargeDialogWnd_x                                     0x10CC4B8
#define pinstCTaskWnd_x                                            0x10CD838
#define pinstCTaskSomething_x                                      0xD40828
#define pinstCTaskTemplateSelectWnd_x                              0x10CD7C0
#define pinstCTipWndOFDAY_x                                        0x10CD9A0
#define pinstCTipWndCONTEXT_x                                      0x10CD9A4
#define pinstCTitleWnd_x                                           0x10CDA20
#define pinstCContextMenuManager_x                                 0x1733D20
#define pinstCVoiceMacroWnd_x                                      0xFB9F70
#define pinstCHtmlWnd_x                                            0xFBA060
#define pinstItemIconCache_x                                       0x10C7E28
#define pinstCTradeskillWnd_x                                      0x10CDB20
#define pinstCAdvancedLootWnd_x                                    0xE727C0
#define pinstRewardSelectionWnd_x                                  0x10CC258
#define pinstEQSuiteTextureLoader_x                                0xD1DA98

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54B920
#define __CastRay2_x                                               0x54B250
#define __HeadingDiff_x                                            0x936860
#define __FixHeading_x                                             0x9367F0
#define __get_bearing_x                                            0x53B1C0
#define __ConvertItemTags_x                                        0x538C90
#define __ExecuteCmd_x                                             0x523550
#define __EQGetTime_x                                              0x8A5700
#define __get_melee_range_x                                        0x52A230
#define __GetGaugeValueFromEQ_x                                    0x7B4090
#define __GetLabelFromEQ_x                                         0x7B5460
#define __ToggleKeyRingItem_x                                      0x490000
#define __GetXTargetType_x                                         0x938460
#define __LoadFrontEnd_x                                           0x641390
#define __NewUIINI_x                                               0x7B3A60
#define __ProcessGameEvents_x                                      0x5855B0
#define __ProcessMouseEvent_x                                      0x584D50
#define CrashDetected_x                                            0x642D50
#define wwsCrashReportCheckForUploader_x                           0x803390
#define __AppCrashWrapper_x                                        0xC6AAC4
#define __pCrashHandler_x                                          0x10DAA00
#define __CrashHandler_x                                           0x802E20
#define wwsCrashReportPlatformLaunchUploader_x                     0x8055C0
#define DrawNetStatus_x                                            0x5BBB00
#define Util__FastTime_x                                           0x8A53A0
#define Expansion_HoT_x                                            0xF347D0
#define __HelpPath_x                                               0xFB7F80
#define __STMLToText_x                                             0x8EBEB0
#define __GetAnimationCache_x                                      0x6B09C0
#define Teleport_Table_x                                           0xF23CB8
#define Teleport_Table_Size_x                                      0xF25F8C

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423260
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DEE0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DCB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8390
#define AltAdvManager__IsAbilityReady_x                            0x4D8400
#define AltAdvManager__GetAAById_x                                 0x4D88F0
#define AltAdvManager__CanTrainAbility_x                           0x4D9520
#define AltAdvManager__CanSeeAbility_x                             0x4D90E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46B2A0
#define CharacterZoneClient__HasSkill_x                            0x4671B0
#define CharacterZoneClient__MakeMeVisible_x                       0x46CE10
#define CharacterZoneClient__IsStackBlocked_x                      0x44BEB0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B3D0
#define CharacterZoneClient__GetItemCountWorn_x                    0x465710
#define CharacterZoneClient__GetItemCountInInventory_x             0x4657F0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4658D0
#define CharacterZoneClient__FindAffectSlot_x                      0x4514E0
#define CharacterZoneClient__BardCastBard_x                        0x44AB40
#define CharacterZoneClient__GetMaxEffects_x                       0x4496D0
#define CharacterZoneClient__GetEffect_x                           0x44B600
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451340
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449A20
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FE90

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x670B70

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67E800

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x59A760
#define CButtonWnd__CButtonWnd_x                                   0x8E0100

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x699C10
#define CChatManager__InitContextMenu_x                            0x69AD60
#define CChatManager__FreeChatWindow_x                             0x6996C0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A2EA0
#define CChatManager__SetLockedActiveChatWindow_x                  0x699BE0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8EA210
#define CContextMenu__dCContextMenu_x                              0x8EA410
#define CContextMenu__AddMenuItem_x                                0x8EA930
#define CContextMenu__RemoveMenuItem_x                             0x8EA590
#define CContextMenu__RemoveAllMenuItems_x                         0x8EA5B0
#define CContextMenu__CheckMenuItem_x                              0x8EA630
#define CContextMenu__SetMenuItem_x                                0x8EA4B0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D6700
#define CContextMenuManager__RemoveMenu_x                          0x8D6AB0
#define CContextMenuManager__PopupMenu_x                           0x8D6F00
#define CContextMenuManager__Flush_x                               0x8D6780
#define CContextMenuManager__GetMenu_x                             0x4193B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x889780
#define CChatService__GetFriendName_x                              0x889790

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A0990
#define CChatWindow__Clear_x                                       0x6A0270
#define CChatWindow__WndNotification_x                             0x6A1290

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8DA550
#define CComboWnd__Draw_x                                          0x8DA760
#define CComboWnd__GetCurChoice_x                                  0x8DA300
#define CComboWnd__GetListRect_x                                   0x8DAA00
#define CComboWnd__GetTextRect_x                                   0x8DA5C0
#define CComboWnd__InsertChoice_x                                  0x8DAB60
#define CComboWnd__SetColors_x                                     0x8DA290
#define CComboWnd__SetChoice_x                                     0x8DA2C0
#define CComboWnd__GetItemCount_x                                  0x8DA2F0
#define CComboWnd__GetCurChoiceText_x                              0x8DA340

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AAB60
#define CContainerWnd__vftable_x                                   0xAF09D0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C62B0
#define CDisplay__GetClickedActor_x                                0x4BEB40
#define CDisplay__GetUserDefinedColor_x                            0x4BD720
#define CDisplay__GetWorldFilePath_x                               0x4BCB70
#define CDisplay__is3dON_x                                         0x4BC000
#define CDisplay__ReloadUI_x                                       0x4D0090
#define CDisplay__WriteTextHD2_x                                   0x4C2620
#define CDisplay__TrueDistance_x                                   0x4BF770

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x901750

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EE760
#define CEditWnd__GetCharIndexPt_x                                 0x8EF8C0
#define CEditWnd__GetDisplayString_x                               0x8EE910
#define CEditWnd__GetHorzOffset_x                                  0x8EEC50
#define CEditWnd__GetLineForPrintableChar_x                        0x8EF380
#define CEditWnd__GetSelStartPt_x                                  0x8EFB80
#define CEditWnd__GetSTMLSafeText_x                                0x8EEDF0
#define CEditWnd__PointFromPrintableChar_x                         0x8EF470
#define CEditWnd__SelectableCharFromPoint_x                        0x8EF5F0
#define CEditWnd__SetEditable_x                                    0x8EEDC0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56BC80
#define CEverQuest__ClickedPlayer_x                                0x5657D0
#define CEverQuest__CreateTargetIndicator_x                        0x5666D0
#define CEverQuest__DeleteTargetIndicator_x                        0x566750
#define CEverQuest__DoTellWindow_x                                 0x476510
#define CEverQuest__OutputTextToLog_x                              0x476170
#define CEverQuest__DropHeldItemOnGround_x                         0x57C200
#define CEverQuest__dsp_chat_x                                     0x476850
#define CEverQuest__trimName_x                                     0x5620E0
#define CEverQuest__Emote_x                                        0x57A510
#define CEverQuest__EnterZone_x                                    0x5755F0
#define CEverQuest__GetBodyTypeDesc_x                              0x55FB20
#define CEverQuest__GetClassDesc_x                                 0x569090
#define CEverQuest__GetClassThreeLetterCode_x                      0x569690
#define CEverQuest__GetDeityDesc_x                                 0x560400
#define CEverQuest__GetLangDesc_x                                  0x55FEB0
#define CEverQuest__GetRaceDesc_x                                  0x569850
#define CEverQuest__InterpretCmd_x                                 0x56D410
#define CEverQuest__LeftClickedOnPlayer_x                          0x581DC0
#define CEverQuest__LMouseUp_x                                     0x583D70
#define CEverQuest__RightClickedOnPlayer_x                         0x5828D0
#define CEverQuest__RMouseUp_x                                     0x5837D0
#define CEverQuest__SetGameState_x                                 0x5660A0
#define CEverQuest__UPCNotificationFlush_x                         0x55E4B0
#define CEverQuest__IssuePetCommand_x                              0x56DDF0
#define CEverQuest__ReportSuccessfulHit_x                          0x576D40

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BB7A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BB800
#define CGaugeWnd__Draw_x                                          0x6BBC30

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B100
#define CGuild__GetGuildName_x                                     0x43B5D0
#define CGuild__GetGuildIndex_x                                    0x43C7D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D8030

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E5400
#define CInvSlotMgr__MoveItem_x                                    0x6E5BC0
#define CInvSlotMgr__SelectSlot_x                                  0x6E4CF0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E4150
#define CInvSlot__SliderComplete_x                                 0x6E1980
#define CInvSlot__GetItemBase_x                                    0x6E0DE0
#define CInvSlot__UpdateItem_x                                     0x6E1360

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E7020
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E8150

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AFEB0
#define CItemDisplayWnd__UpdateStrings_x                           0x6E9230
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F5AA0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F5FD0
#define CItemDisplayWnd__SetItem_x                                 0x6FB880
#define CItemDisplayWnd__AboutToShow_x                             0x6EF950
#define CItemDisplayWnd__WndNotification_x                         0x6FC050

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E8100

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EF7C0

// CLabel 
#define CLabel__Draw_x                                             0x702660

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C60D0
#define CListWnd__dCListWnd_x                                      0x8C7490
#define CListWnd__AddColumn_x                                      0x8C7430
#define CListWnd__AddColumn1_x                                     0x8C69A0
#define CListWnd__AddLine_x                                        0x8C6380
#define CListWnd__AddString_x                                      0x8C65A0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C3090
#define CListWnd__CalculateVSBRange_x                              0x8C5050
#define CListWnd__ClearSel_x                                       0x8C23A0
#define CListWnd__ClearAllSel_x                                    0x8C2350
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C5F60
#define CListWnd__Compare_x                                        0x8C3D80
#define CListWnd__Draw_x                                           0x8C5950
#define CListWnd__DrawColumnSeparators_x                           0x8C4EE0
#define CListWnd__DrawHeader_x                                     0x8C2660
#define CListWnd__DrawItem_x                                       0x8C4410
#define CListWnd__DrawLine_x                                       0x8C4B80
#define CListWnd__DrawSeparator_x                                  0x8C4F80
#define CListWnd__EnableLine_x                                     0x8C2580
#define CListWnd__EnsureVisible_x                                  0x8C31F0
#define CListWnd__ExtendSel_x                                      0x8C4320
#define CListWnd__GetColumnMinWidth_x                              0x8C1C60
#define CListWnd__GetColumnWidth_x                                 0x8C1B90
#define CListWnd__GetCurSel_x                                      0x8C1370
#define CListWnd__GetItemAtPoint_x                                 0x8C3490
#define CListWnd__GetItemAtPoint1_x                                0x8C3500
#define CListWnd__GetItemData_x                                    0x8C16A0
#define CListWnd__GetItemHeight_x                                  0x8C2CE0
#define CListWnd__GetItemIcon_x                                    0x8C1890
#define CListWnd__GetItemRect_x                                    0x8C32D0
#define CListWnd__GetItemText_x                                    0x8C1740
#define CListWnd__GetSelList_x                                     0x8C6890
#define CListWnd__GetSeparatorRect_x                               0x8C3CA0
#define CListWnd__InsertLine_x                                     0x8C6780
#define CListWnd__RemoveLine_x                                     0x8C6790
#define CListWnd__SetColors_x                                      0x8C14C0
#define CListWnd__SetColumnJustification_x                         0x8C1EF0
#define CListWnd__SetColumnWidth_x                                 0x8C1C10
#define CListWnd__SetCurSel_x                                      0x8C13B0
#define CListWnd__SetItemColor_x                                   0x8C5790
#define CListWnd__SetItemData_x                                    0x8C2400
#define CListWnd__SetItemText_x                                    0x8C55D0
#define CListWnd__ShiftColumnSeparator_x                           0x8C53E0
#define CListWnd__Sort_x                                           0x8C7590
#define CListWnd__ToggleSel_x                                      0x8C22D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71B640

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x740DF0
#define CMerchantWnd__RequestBuyItem_x                             0x748AF0
#define CMerchantWnd__RequestSellItem_x                            0x74B110
#define CMerchantWnd__SelectRecoverySlot_x                         0x73E010
#define CMerchantWnd__SelectBuySellSlot_x                          0x73BEB0
#define CMerchantWnd__ActualSelect_x                               0x742C40

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x857AD0
#define CPacketScrambler__hton_x                                   0x857AE0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E5080
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E5160
#define CSidlManager__CreateLabel_x                                0x7A4F10
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E3630
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E5440

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8DC5A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8DC490
#define CSidlScreenWnd__ConvertToRes_x                             0x901630
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DCEB0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DE060
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DE110
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DD600
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8DC860
#define CSidlScreenWnd__EnableIniStorage_x                         0x8DBFC0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8DCA50
#define CSidlScreenWnd__Init1_x                                    0x8DDD50
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DCF60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8DC180
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DD840
#define CSidlScreenWnd__StoreIniInfo_x                             0x8DBC10
#define CSidlScreenWnd__StoreIniVis_x                              0x8DBF70
#define CSidlScreenWnd__WndNotification_x                          0x8DDAD0
#define CSidlScreenWnd__GetChildItem_x                             0x8DC090
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CFA10
#define CSidlScreenWnd__m_layoutCopy_x                             0x1733E40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x606D20
#define CSkillMgr__GetSkillCap_x                                   0x606F00
#define CSkillMgr__GetNameToken_x                                  0x6068D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9008F0
#define CSliderWnd__SetValue_x                                     0x900AC0
#define CSliderWnd__SetNumTicks_x                                  0x901240

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7AB1A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8FA1F0
#define CStmlWnd__CalculateHSBRange_x                              0x8F2750
#define CStmlWnd__CalculateVSBRange_x                              0x8F26C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F28D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F30D0
#define CStmlWnd__ForceParseNow_x                                  0x8FAB70
#define CStmlWnd__GetNextTagPiece_x                                0x8F2FD0
#define CStmlWnd__GetSTMLText_x                                    0x4846B0
#define CStmlWnd__GetVisibleText_x                                 0x8F3B20
#define CStmlWnd__InitializeWindowVariables_x                      0x8F60F0
#define CStmlWnd__MakeStmlColorTag_x                               0x8F19A0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F1A00
#define CStmlWnd__SetSTMLText_x                                    0x8F7950
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F9E90
#define CStmlWnd__UpdateHistoryString_x                            0x8F4A60

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FE0A0
#define CTabWnd__DrawCurrentPage_x                                 0x8FD930
#define CTabWnd__DrawTab_x                                         0x8FD6F0
#define CTabWnd__GetCurrentPage_x                                  0x8FDCE0
#define CTabWnd__GetPageInnerRect_x                                0x8FD3E0
#define CTabWnd__GetTabInnerRect_x                                 0x8FD5E0
#define CTabWnd__GetTabRect_x                                      0x8FD4B0
#define CTabWnd__InsertPage_x                                      0x8FE390
#define CTabWnd__SetPage_x                                         0x8FDD10
#define CTabWnd__SetPageRect_x                                     0x8FDFE0
#define CTabWnd__UpdatePage_x                                      0x8FE330
#define CTabWnd__GetPageFromTabIndex_x                             0x8FD640
#define CTabWnd__GetCurrentTabIndex_x                              0x8FD370

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E8300
#define CPageWnd__SetTabText_x                                     0x90A960

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436C60

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D9F00
#define CTextureFont__GetTextExtent_x                              0x8D9C60

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63F630

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x906DA0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BF410

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A84F0
#define CXStr__CXStr1_x                                            0x752950
#define CXStr__CXStr3_x                                            0x8A25F0
#define CXStr__dCXStr_x                                            0x476110
#define CXStr__operator_equal_x                                    0x8A2760
#define CXStr__operator_equal1_x                                   0x8A27B0
#define CXStr__operator_plus_equal1_x                              0x8A38B0

// CXWnd 
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D7A10
#define CXWnd__BringToTop_x                                        0x8CEC50
#define CXWnd__Center_x                                            0x8D4D60
#define CXWnd__ClrFocus_x                                          0x8CE810
#define CXWnd__Destroy_x                                           0x8D5810
#define CXWnd__DoAllDrawing_x                                      0x8D49B0
#define CXWnd__DrawChildren_x                                      0x8D4B50
#define CXWnd__DrawColoredRect_x                                   0x8CF020
#define CXWnd__DrawTooltip_x                                       0x8CF2D0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D3920
#define CXWnd__GetBorderFrame_x                                    0x8CF720
#define CXWnd__GetChildWndAt_x                                     0x8D5700
#define CXWnd__GetClientClipRect_x                                 0x8CF4E0
#define CXWnd__GetScreenClipRect_x                                 0x8D4020
#define CXWnd__GetScreenRect_x                                     0x8CF8B0
#define CXWnd__GetTooltipRect_x                                    0x8CF160
#define CXWnd__GetWindowTextA_x                                    0x426D50
#define CXWnd__IsActive_x                                          0x8CA250
#define CXWnd__IsDescendantOf_x                                    0x8CF670
#define CXWnd__IsReallyVisible_x                                   0x8D2980
#define CXWnd__IsType_x                                            0x8D4DD0
#define CScreenPieceTemplate__IsType_x                             0x9034B0
#define CXWnd__Move_x                                              0x8D2080
#define CXWnd__Move1_x                                             0x8D4660
#define CXWnd__ProcessTransition_x                                 0x8CEBF0
#define CXWnd__Refade_x                                            0x8CE9C0
#define CXWnd__Resize_x                                            0x8CF970
#define CXWnd__Right_x                                             0x8D3E20
#define CXWnd__SetFocus_x                                          0x8D11E0
#define CXWnd__SetFont_x                                           0x8CE860
#define CXWnd__SetKeyTooltip_x                                     0x8CFBE0
#define CXWnd__SetMouseOver_x                                      0x8D4360
#define CXWnd__StartFade_x                                         0x8CECA0
#define CXWnd__GetChildItem_x                                      0x8D42B0
#define CXWnd__SetParent_x                                         0x8D56B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8CBB00
#define CXWndManager__DrawWindows_x                                0x8CB740
#define CXWndManager__GetKeyboardFlags_x                           0x8C9DC0
#define CXWndManager__HandleKeyboardMsg_x                          0x8CA6F0
#define CXWndManager__RemoveWnd_x                                  0x8CA3E0

// CDBStr
#define CDBStr__GetString_x                                        0x4BA850

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452690
#define EQ_Character__Cur_HP_x                                     0x466D90
#define EQ_Character__Cur_Mana_x                                   0x45BA30
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B6E0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443690
#define EQ_Character__GetFocusRangeModifier_x                      0x4437E0
#define EQ_Character__GetHPRegen_x                                 0x46A930
#define EQ_Character__GetEnduranceRegen_x                          0x4663A0
#define EQ_Character__GetManaRegen_x                               0x46AED0
#define EQ_Character__Max_Endurance_x                              0x5CDA50
#define EQ_Character__Max_HP_x                                     0x45E5B0
#define EQ_Character__Max_Mana_x                                   0x5CD880
#define EQ_Character__doCombatAbility_x                            0x5CAF50
#define EQ_Character__UseSkill_x                                   0x472CD0
#define EQ_Character__GetConLevel_x                                0x5C01A0
#define EQ_Character__IsExpansionFlag_x                            0x4B6AB0
#define EQ_Character__TotalEffect_x                                0x44F7D0
#define EQ_Character__GetPCSpellAffect_x                           0x44BA70
#define EQ_Character__SpellDuration_x                              0x449A70
#define EQ_Character__FindItemByRecord_x                           0x464400
#define EQ_Character__GetAdjustedSkill_x                           0x466F60
#define EQ_Character__GetBaseSkill_x                               0x45E490
#define EQ_Character__CanUseItem_x                                 0x468E40

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8758A0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D60E0

//PcClient
#define PcClient__PcClient_x                                       0x5C1FF0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446B50
#define CCharacterSelect__EnterWorld_x                             0x446320
#define CCharacterSelect__Quit_x                                   0x444EE0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5A0100
#define EQ_Item__CreateItemTagString_x                             0x855C20
#define EQ_Item__IsStackable_x                                     0x84AF30
#define EQ_Item__GetImageNum_x                                     0x84DA20
#define EQ_Item__CreateItemClient_x                                0x5A1250
#define EQ_Item__GetItemValue_x                                    0x854680
#define EQ_Item__ValueSellMerchant_x                               0x857710
#define EQ_Item__IsKeyRingItem_x                                   0x84BA00
#define EQ_Item__CanGoInBag_x                                      0x5A0290
#define EQ_Item__GetMaxItemCount_x                                 0x84AE20
#define EQ_Item__GetHeldItem_x                                     0x84C830
#define EQ_Item__GetAugmentFitBySlot_x                             0x857530

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA9B0
#define EQ_LoadingS__Array_x                                       0xC0EC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CFF70
#define EQ_PC__GetAlternateAbilityId_x                             0x85FB30
#define EQ_PC__GetCombatAbility_x                                  0x85FBC0
#define EQ_PC__GetCombatAbilityTimer_x                             0x85A780
#define EQ_PC__GetItemRecastTimer_x                                0x5C9730
#define EQ_PC__HasLoreItem_x                                       0x5C37A0
#define EQ_PC__AlertInventoryChanged_x                             0x5C0150
#define EQ_PC__GetPcZoneClient_x                                   0x5EA6C0
#define EQ_PC__RemoveMyAffect_x                                    0x5C8B60
#define EQ_PC__GetKeyRingItems_x                                   0x85ABA0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86D850
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x861AB0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5282A0
#define EQItemList__add_object_x                                   0x5554F0
#define EQItemList__add_item_x                                     0x5281E0
#define EQItemList__delete_item_x                                  0x528690
#define EQItemList__FreeItemList_x                                 0x528590

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9A20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D5DA0
#define EQPlayer__dEQPlayer_x                                      0x5DE560
#define EQPlayer__DoAttack_x                                       0x5EFEA0
#define EQPlayer__EQPlayer_x                                       0x5E0C90
#define EQPlayer__SetNameSpriteState_x                             0x5DB390
#define EQPlayer__SetNameSpriteTint_x                              0x5D72B0
#define PlayerBase__HasProperty_j_x                                0x934C70
#define EQPlayer__IsTargetable_x                                   0x934F10
#define EQPlayer__CanSee_x                                         0x935470
#define PlayerZoneClient__ChangeHeight_x                           0x5EFD60
#define EQPlayer__CanSee1_x                                        0x935560
#define PlayerBase__GetVisibilityLineSegment_x                     0x935200

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5EA870
#define PlayerZoneClient__IsValidTeleport_x                        0x555D90
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2C80

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E4D00
#define EQPlayerManager__GetSpawnByName_x                          0x5E5160
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E4D30

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A6880
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A68C0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A6470
#define KeypressHandler__HandleKeyDown_x                           0x5A4D90
#define KeypressHandler__HandleKeyUp_x                             0x5A50B0
#define KeypressHandler__SaveKeymapping_x                          0x5A6540

// MapViewMap 
#define MapViewMap__Clear_x                                        0x713FD0
#define MapViewMap__SaveEx_x                                       0x717300
#define MapViewMap__SetZoom_x                                      0x713C60

#define PlayerPointManager__GetAltCurrency_x                       0x873960

// StringTable 
#define StringTable__getString_x                                   0x86DB80

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CD4E0
#define PcZoneClient__RemovePetEffect_x                            0x5C9C10
#define PcZoneClient__HasAlternateAbility_x                        0x5CA5B0
#define PcZoneClient__GetCurrentMod_x                              0x45DA60
#define PcZoneClient__GetModCap_x                                  0x45B190
#define PcZoneClient__CanEquipItem_x                               0x5CAA90
#define PcZoneClient__GetItemByID_x                                0x5CF2F0
#define PcZoneClient__GetItemByItemClass_x                         0x5CFE90
#define PcZoneClient__RemoveBuffEffect_x                           0x5C8E10

//Doors
#define EQSwitch__UseSwitch_x                                      0x55CDF0

//IconCache
#define IconCache__GetIcon_x                                       0x6B0FF0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A7F10
#define CContainerMgr__CloseContainer_x                            0x6A8730

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x774F70

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x599190

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5240
#define EQ_Spell__SpellAffects_x                                   0x4F2420
#define EQ_Spell__SpellAffectBase_x                                0x4F2490
#define CharacterZoneClient__CalcAffectChange_x                    0x44B900
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ABA0
#define CLootWnd__LootAll_x                                        0x7098D0
#define CLootWnd__RequestLootSlot_x                                0x70A0E0
#define EQ_Spell__IsStackable_x                                    0x459190
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449520
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EBE0
#define EQ_Spell__IsSPAStacking_x                                  0x4F1F90
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3030
#define EQ_Spell__IsNoRemove_x                                     0x434CA0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1FB0

#define __IsResEffectSpell_x                                       0x4495C0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87F550

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BCB60
#define CTargetWnd__WndNotification_x                              0x7BC650
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BCD40

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C1C80

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EDB10
#define EqSoundManager__PlayScriptMp3_x                            0x4EF5B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8B40

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EDD90
#define CSidlManager__FindAnimation1_x                             0x8E3060

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2310
#define CAltAbilityData__GetMercMaxRank_x                          0x4E22C0
#define CAltAbilityData__GetMaxRank_x                              0x4D6A40

//CTargetRing
#define CTargetRing__Cast_x                                        0x596DD0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4594A0
#define CharacterBase__CreateItemGlobalIndex_x                     0x475700
#define CharacterBase__CreateItemIndex_x                           0x5218B0
#define CharacterBase__GetItemPossession_x                         0x4443B0
#define CharacterBase__GetItemByGlobalIndex_x                      0x883390
#define CharacterBase__GetEffectId_x                               0x459460

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x690C70
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6903D0

//messages
#define msg_spell_worn_off_x                                       0x4FCCA0
#define msg_new_text_x                                             0x506420
#define msgTokenTextParam_x                                        0x502C20

//SpellManager
#define SpellManager__vftable_x                                    0xACC288
#define SpellManager__SpellManager_x                               0x47E330
#define Spellmanager__LoadTextSpells_x                             0x60DC10

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x938F80

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487F50
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EB00
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449240
#define ItemGlobalIndex__IsValidIndex_x                            0x458CD0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x881210
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x880150

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7028B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6ACC20
#define CCursorAttachment__Deactivate_x                            0x6AC170

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FFDF0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FFF70

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C7A0

//IString
#define IString__Append_x                                          0x47EF60

//Camera
#define CDisplay__cameraType_x                                     0xE727E8
#define EverQuest__Cameras_x                                       0xF34AE8

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x494490
#define pinstLootFiltersManager_x                                  0xD40248
