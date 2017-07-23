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
#define __ExpectedVersionDate                                     "Jul 20 2017"
#define __ExpectedVersionTime                                     "16:22:50"
#define __ActualVersionDate_x                                      0xAD5478
#define __ActualVersionTime_x                                      0xAD5484

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5A2FB0
#define __MemChecker1_x                                            0x899830
#define __MemChecker2_x                                            0x638EB0
#define __MemChecker3_x                                            0x638E00
#define __MemChecker4_x                                            0x7EBD70
#define __EncryptPad0_x                                            0xC2F328
#define __EncryptPad1_x                                            0xD0A6E0
#define __EncryptPad2_x                                            0xC58B10
#define __EncryptPad3_x                                            0xC58710
#define __EncryptPad4_x                                            0xCF8CE0
#define __EncryptPad5_x                                            0x10B3370
#define __AC1_x                                                    0x7AB035
#define __AC2_x                                                    0x55BE57
#define __AC3_x                                                    0x559FD0
#define __AC4_x                                                    0x56C1A1
#define __AC5_x                                                    0x58005B
#define __AC6_x                                                    0x583C0E
#define __AC7_x                                                    0x57A65C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FE4DFC

// Direct Input
#define DI8__Main_x                                                0x10B3348
#define DI8__Keyboard_x                                            0x10B334C
#define DI8__Mouse_x                                               0x10B3350
#define DI8__Mouse_Copy_x                                          0xF2170C
#define DI8__Mouse_Check_x                                         0xFAB034
#define __AutoSkillArray_x                                         0xF22620
#define __Attack_x                                                 0xFA5C17
#define __Autofire_x                                               0xFA5C18
#define __BindList_x                                               0xC0A050
#define g_eqCommandStates_x                                        0xF10730
#define __Clicks_x                                                 0xF217C8
#define __CommandList_x                                            0xC0C6C8
#define __CurrentMapLabel_x                                        0x10B8DD0
#define __CurrentSocial_x                                          0xBDB424
#define __DoAbilityList_x                                          0xF57ECC
#define __do_loot_x                                                0x52B0A0
#define __DrawHandler_x                                            0x171FC84
#define __GroupCount_x                                             0xF11D62

#define __Guilds_x                                                 0xF17978
#define __gWorld_x                                                 0xF1421C
#define __HotkeyPage_x                                             0xF9E8CC
#define __HWnd_x                                                   0xFAB150
#define __InChatMode_x                                             0xF216F4
#define __LastTell_x                                               0xF235C8
#define __LMouseHeldTime_x                                         0xF21834
#define __Mouse_x                                                  0x10B3354
#define __MouseLook_x                                              0xF2178E
#define __MouseEventTime_x                                         0xFA641C
#define __gpbCommandEvent_x                                        0xF142E4
#define __NetStatusToggle_x                                        0xF21791
#define __PCNames_x                                                0xF22BDC
#define __RangeAttackReady_x                                       0xF22904
#define __RMouseHeldTime_x                                         0xF21830
#define __RunWalkState_x                                           0xF216F8
#define __ScreenMode_x                                             0xE60418
#define __ScreenX_x                                                0xF216AC
#define __ScreenY_x                                                0xF216A8
#define __ScreenXMax_x                                             0xF216B0
#define __ScreenYMax_x                                             0xF216B4
#define __ServerHost_x                                             0xF11CAC
#define __ServerName_x                                             0xF57E8C
#define __ShiftKeyDown_x                                           0xF21D88
#define __ShowNames_x                                              0xF22AC4
#define __Socials_x                                                0xF57F8C
#define __SubscriptionType_x                                       0x10E6DB4
#define __TargetAggroHolder_x                                      0x10BAFA4
#define __ZoneType_x                                               0xF21B8C
#define __GroupAggro_x                                             0x10BAFE4
#define __LoginName_x                                              0xFA9C2C
#define __Inviter_x                                                0xFA5B94
#define __AttackOnAssist_x                                         0xF22A80
#define __UseTellWindows_x                                         0xF22D74

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF14308
#define instEQZoneInfo_x                                           0xF21984
#define instKeypressHandler_x                                      0xFA6400
#define pinstActiveBanker_x                                        0xF142C0
#define pinstActiveCorpse_x                                        0xF142C4
#define pinstActiveGMaster_x                                       0xF142C8
#define pinstActiveMerchant_x                                      0xF142BC
#define pinstAggroInfo_x                                           0xD1DD88
#define pinstAltAdvManager_x                                       0xE614F8
#define pinstAuraMgr_x                                             0xD2E4F8
#define pinstBandageTarget_x                                       0xF142A8
#define pinstCamActor_x                                            0xE60E4C
#define pinstCDBStr_x                                              0xE603AC
#define pinstCDisplay_x                                            0xF142D0
#define pinstCEverQuest_x                                          0x10B34C8
#define pinstEverQuestInfo_x                                       0xF216A0
#define pinstCharData_x                                            0xF1428C
#define pinstCharSpawn_x                                           0xF142B4
#define pinstControlledMissile_x                                   0xF14288
#define pinstControlledPlayer_x                                    0xF142B4
#define pinstCSidlManager_x                                        0x171F074
#define pinstCXWndManager_x                                        0x171F06C
#define instDynamicZone_x                                          0xF21540
#define pinstDZMember_x                                            0xF21650
#define pinstDZTimerInfo_x                                         0xF21654
#define pinstEQItemList_x                                          0xF10984
#define pinstEQObjectList_x                                        0xF1175C
#define instEQMisc_x                                               0xBF2690
#define pinstEQSoundManager_x                                      0xE61AC8
#define instExpeditionLeader_x                                     0xF2158A
#define instExpeditionName_x                                       0xF215CA
#define pinstGroup_x                                               0xF11D5E
#define pinstImeManager_x                                          0x171F078
#define pinstLocalPlayer_x                                         0xF142A0
#define pinstMercenaryData_x                                       0xFA6A80
#define pinstMercenaryStats_x                                      0x10BB0F0
#define pinstMercAltAbilities_x                                    0xE61880
#define pinstModelPlayer_x                                         0xF142CC
#define pinstPCData_x                                              0xF1428C
#define pinstSkillMgr_x                                            0xFA78E8
#define pinstSpawnManager_x                                        0xFA71D0
#define pinstSpellManager_x                                        0xFA7A30
#define pinstSpellSets_x                                           0xF9E930
#define pinstStringTable_x                                         0xF14234
#define pinstSwitchManager_x                                       0xF118F0
#define pinstTarget_x                                              0xF142B8
#define pinstTargetObject_x                                        0xF14290
#define pinstTargetSwitch_x                                        0xF14294
#define pinstTaskMember_x                                          0xE602F8
#define pinstTrackTarget_x                                         0xF142AC
#define pinstTradeTarget_x                                         0xF1429C
#define instTributeActive_x                                        0xBF26B5
#define pinstViewActor_x                                           0xE60E48
#define pinstWorldData_x                                           0xF14270
#define pinstZoneAddr_x                                            0xF21C24
#define pinstPlayerPath_x                                          0xFA7230
#define pinstTargetIndicator_x                                     0xFA7BC8
#define pinstCTargetManager_x                                      0xFA7C28
#define EQObject_Top_x                                             0xF14280
#define pinstRealEstateItems_x                                     0xFA77D4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE60D64
#define pinstCAchievementsWnd_x                                    0xE60DC0
#define pinstCTextOverlay_x                                        0xD1E288
#define pinstCAudioTriggersWindow_x                                0xD1E118
#define pinstCCharacterSelect_x                                    0xE60CD4
#define pinstCFacePick_x                                           0xE60A84
#define pinstCNoteWnd_x                                            0xE60C8C
#define pinstCBookWnd_x                                            0xE60C94
#define pinstCPetInfoWnd_x                                         0xE60C98
#define pinstCTrainWnd_x                                           0xE60C9C
#define pinstCSkillsWnd_x                                          0xE60CA0
#define pinstCSkillsSelectWnd_x                                    0xE60CA4
#define pinstCCombatSkillsSelectWnd_x                              0xE60CA8
#define pinstCFriendsWnd_x                                         0xE60CAC
#define pinstCAuraWnd_x                                            0xE60CB0
#define pinstCRespawnWnd_x                                         0xE60CB4
#define pinstCBandolierWnd_x                                       0xE60CB8
#define pinstCPotionBeltWnd_x                                      0xE60CBC
#define pinstCAAWnd_x                                              0xE60CC0
#define pinstCAlarmWnd_x                                           0xE60CCC
#define pinstCGroupSearchFiltersWnd_x                              0xE60CC4
#define pinstCLoadskinWnd_x                                        0xE60CC8
#define pinstCLargeDialogWnd_x                                     0x10BA050
#define pinstCMusicPlayerWnd_x                                     0xE60CD0
#define pinstCMailWnd_x                                            0xE60CD8
#define pinstCMailCompositionWnd_x                                 0xE60CDC
#define pinstCMailAddressBookWnd_x                                 0xE60CE0
#define pinstCRaidWnd_x                                            0xE60CE8
#define pinstCRaidOptionsWnd_x                                     0xE60CEC
#define pinstCBreathWnd_x                                          0xE60CF0
#define pinstCMapViewWnd_x                                         0xE60CF4
#define pinstCMapToolbarWnd_x                                      0xE60CF8
#define pinstCEditLabelWnd_x                                       0xE60CFC
#define pinstCTargetWnd_x                                          0xE60D00
#define pinstCColorPickerWnd_x                                     0xE60D04
#define pinstCPlayerWnd_x                                          0xE60D08
#define pinstCOptionsWnd_x                                         0xE60D0C
#define pinstCBuffWindowNORMAL_x                                   0xE60D10
#define pinstCBuffWindowSHORT_x                                    0xE60D14
#define pinstCharacterCreation_x                                   0xE60D18
#define pinstCCursorAttachment_x                                   0xE60D1C
#define pinstCCastingWnd_x                                         0xE60D20
#define pinstCCastSpellWnd_x                                       0xE60D24
#define pinstCSpellBookWnd_x                                       0xE60D28
#define pinstCInventoryWnd_x                                       0xE60D2C
#define pinstCBankWnd_x                                            0xE60D34
#define pinstCQuantityWnd_x                                        0xE60D38
#define pinstCLootWnd_x                                            0xE60D3C
#define pinstCActionsWnd_x                                         0xE60D40
#define pinstCCombatAbilityWnd_x                                   0xE60D48
#define pinstCMerchantWnd_x                                        0xE60D4C
#define pinstCTradeWnd_x                                           0xE60D54
#define pinstCSelectorWnd_x                                        0xE60D58
#define pinstCBazaarWnd_x                                          0xE60D5C
#define pinstCBazaarSearchWnd_x                                    0xE60D60
#define pinstCGiveWnd_x                                            0xE60D7C
#define pinstCTrackingWnd_x                                        0xE60D84
#define pinstCInspectWnd_x                                         0xE60D88
#define pinstCSocialEditWnd_x                                      0xE60D8C
#define pinstCFeedbackWnd_x                                        0xE60D90
#define pinstCBugReportWnd_x                                       0xE60D94
#define pinstCVideoModesWnd_x                                      0xE60D98
#define pinstCTextEntryWnd_x                                       0xE60DA0
#define pinstCFileSelectionWnd_x                                   0xE60DA4
#define pinstCCompassWnd_x                                         0xE60DA8
#define pinstCPlayerNotesWnd_x                                     0xE60DAC
#define pinstCGemsGameWnd_x                                        0xE60DB0
#define pinstCTimeLeftWnd_x                                        0xE60DB4
#define pinstCPetitionQWnd_x                                       0xE60DD0
#define pinstCStoryWnd_x                                           0xE60DD4
#define pinstCJournalTextWnd_x                                     0xE60DD8
#define pinstCJournalCatWnd_x                                      0xE60DDC
#define pinstCBodyTintWnd_x                                        0xE60DE0
#define pinstCServerListWnd_x                                      0xE60DE4
#define pinstCAvaZoneWnd_x                                         0xE60DF0
#define pinstCBlockedBuffWnd_x                                     0xE60DF4
#define pinstCBlockedPetBuffWnd_x                                  0xE60DF8
#define pinstCInvSlotMgr_x                                         0xE60E40
#define pinstCContainerMgr_x                                       0xE60E44
#define pinstCAdventureLeaderboardWnd_x                            0x10B3E78
#define pinstCAdventureRequestWnd_x                                0x10B3EF0
#define pinstCAltStorageWnd_x                                      0x10B41D0
#define pinstCAdventureStatsWnd_x                                  0x10B3F68
#define pinstCBarterMerchantWnd_x                                  0x10B4DB8
#define pinstCBarterSearchWnd_x                                    0x10B4E30
#define pinstCBarterWnd_x                                          0x10B4EA8
#define pinstCChatWindowManager_x                                  0x10B5538
#define pinstCDynamicZoneWnd_x                                     0x10B59E8
#define pinstCEQMainWnd_x                                          0x10B5B80
#define pinstCFellowshipWnd_x                                      0x10B597C
#define pinstCFindLocationWnd_x                                    0x10B5E50
#define pinstCGroupSearchWnd_x                                     0x10B6120
#define pinstCGroupWnd_x                                           0x10B6198
#define pinstCGuildBankWnd_x                                       0x10B6210
#define pinstCGuildMgmtWnd_x                                       0x10B8300
#define pinstCHotButtonWnd_x                                       0x10B83FC
#define pinstCHotButtonWnd1_x                                      0x10B83FC
#define pinstCHotButtonWnd2_x                                      0x10B8400
#define pinstCHotButtonWnd3_x                                      0x10B8404
#define pinstCHotButtonWnd4_x                                      0x10B8428
#define pinstCItemDisplayManager_x                                 0x10B8720
#define pinstCItemExpTransferWnd_x                                 0x10B879C
#define pinstCLFGuildWnd_x                                         0x10B8A78
#define pinstCMIZoneSelectWnd_x                                    0x10B9060
#define pinstCConfirmationDialog_x                                 0x10B9768
#define pinstCPopupWndManager_x                                    0x10B9768
#define pinstCProgressionSelectionWnd_x                            0x10B9858
#define pinstCPvPStatsWnd_x                                        0x10B9948
#define pinstCTaskWnd_x                                            0x10BB3D0
#define pinstCTaskSomething_x                                      0xD2EEA0
#define pinstCTaskTemplateSelectWnd_x                              0x10BB358
#define pinstCTipWndOFDAY_x                                        0x10BB538
#define pinstCTipWndCONTEXT_x                                      0x10BB53C
#define pinstCTitleWnd_x                                           0x10BB5B8
#define pinstCContextMenuManager_x                                 0x171EFE4
#define pinstCVoiceMacroWnd_x                                      0xFA8000
#define pinstCHtmlWnd_x                                            0xFA80F0
#define pinstIconCache_x                                           0x10B5B54
#define pinstCTradeskillWnd_x                                      0x10BB6B8
#define pinstCAdvancedLootWnd_x                                    0xE60E34
#define pinstRewardSelectionWnd_x                                  0x10B9E70
#define pinstEQSuiteTextureLoader_x                                0xD0C458

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x542630
#define __CastRay2_x                                               0x541F60
#define __HeadingDiff_x                                            0x9280C0
#define __FixHeading_x                                             0x928050
#define __get_bearing_x                                            0x532040
#define __ConvertItemTags_x                                        0x52FCC0
#define __ExecuteCmd_x                                             0x51A600
#define __EQGetTime_x                                              0x8991D0
#define __get_melee_range_x                                        0x521240
#define __GetGaugeValueFromEQ_x                                    0x7A9BF0
#define __GetLabelFromEQ_x                                         0x7AAFC0
#define __ToggleKeyRingItem_x                                      0x488E30
#define __GetXTargetType_x                                         0x929CC0
#define __LoadFrontEnd_x                                           0x638580
#define __NewUIINI_x                                               0x7A95C0
#define __ProcessGameEvents_x                                      0x57C3F0
#define __ProcessMouseEvent_x                                      0x57BB90
#define CrashDetected_x                                            0x639F40
#define wwsCrashReportCheckForUploader_x                           0x7F7D20
#define __AppCrashWrapper_x                                        0xC58704
#define __pCrashHandler_x                                          0x10C8568
#define __CrashHandler_x                                           0x7F7780
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F9F20
#define DrawNetStatus_x                                            0x5B2CC0
#define Util__FastTime_x                                           0x898E70
#define Expansion_HoT_x                                            0xF22A70
#define __HelpPath_x                                               0xFA6188
#define __STMLToText_x                                             0x8DF140

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423150
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DE60
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DC30

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D1380
#define AltAdvManager__IsAbilityReady_x                            0x4D13F0
#define AltAdvManager__GetAAById_x                                 0x4D18E0
#define AltAdvManager__CanTrainAbility_x                           0x4D2510
#define AltAdvManager__CanSeeAbility_x                             0x4D20D0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46A3A0
#define CharacterZoneClient__HasSkill_x                            0x467250
#define CharacterZoneClient__MakeMeVisible_x                       0x46B930
#define CharacterZoneClient__IsStackBlocked_x                      0x44B980
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44AE40
#define CharacterZoneClient__GetItemCountWorn_x                    0x4651D0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4652B0
#define CharacterZoneClient__GetCursorItemCount_x                  0x465390
#define CharacterZoneClient__FindAffectSlot_x                      0x450ED0
#define CharacterZoneClient__BardCastBard_x                        0x44A5C0
#define CharacterZoneClient__GetMaxEffects_x                       0x449300
#define CharacterZoneClient__GetEffect_x                           0x44B070
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x450D30
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4494A0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44F880

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x667E70

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x676210

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x591C20
#define CButtonWnd__CButtonWnd_x                                   0x8D3590

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691330
#define CChatManager__InitContextMenu_x                            0x692480
#define CChatManager__FreeChatWindow_x                             0x690DC0
#define CChatManager__GetLockedActiveChatWindow_x                  0x69A520
#define CChatManager__SetLockedActiveChatWindow_x                  0x691300

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DD4A0
#define CContextMenu__dCContextMenu_x                              0x8DD6B0
#define CContextMenu__AddMenuItem_x                                0x8DDBC0
#define CContextMenu__RemoveMenuItem_x                             0x8DD820
#define CContextMenu__RemoveAllMenuItems_x                         0x8DD840
#define CContextMenu__CheckMenuItem_x                              0x8DD8C0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8C9B00
#define CContextMenuManager__RemoveMenu_x                          0x8C9EA0
#define CContextMenuManager__PopupMenu_x                           0x8CA2F0
#define CContextMenuManager__Flush_x                               0x8C9B70
#define CContextMenuManager__GetMenu_x                             0x419510

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87D410
#define CChatService__GetFriendName_x                              0x87D420

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x698070
#define CChatWindow__Clear_x                                       0x697960
#define CChatWindow__WndNotification_x                             0x698970

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CD960
#define CComboWnd__Draw_x                                          0x8CDB70
#define CComboWnd__GetCurChoice_x                                  0x8CD710
#define CComboWnd__GetListRect_x                                   0x8CDE10
#define CComboWnd__GetTextRect_x                                   0x8CD9D0
#define CComboWnd__InsertChoice_x                                  0x8CDE80
#define CComboWnd__SetColors_x                                     0x8CD6A0
#define CComboWnd__SetChoice_x                                     0x8CD6D0
#define CComboWnd__GetItemCount_x                                  0x8CD700
#define CComboWnd__GetCurChoiceText_x                              0x8CD750


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A2230
#define CContainerWnd__vftable_x                                   0xADF080

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BEFE0
#define CDisplay__GetClickedActor_x                                0x4B78D0
#define CDisplay__GetUserDefinedColor_x                            0x4B64B0
#define CDisplay__GetWorldFilePath_x                               0x4B5900
#define CDisplay__is3dON_x                                         0x4B4D90
#define CDisplay__ReloadUI_x                                       0x4C8F40
#define CDisplay__WriteTextHD2_x                                   0x4BB3A0
#define CDisplay__TrueDistance_x                                   0x4B8500

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F3A20

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E19F0
#define CEditWnd__GetCharIndexPt_x                                 0x8E2A70
#define CEditWnd__GetDisplayString_x                               0x8E1BA0
#define CEditWnd__GetHorzOffset_x                                  0x8E1EE0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E2540
#define CEditWnd__GetSelStartPt_x                                  0x8E2D20
#define CEditWnd__GetSTMLSafeText_x                                0x8E2070
#define CEditWnd__PointFromPrintableChar_x                         0x8E2630
#define CEditWnd__SelectableCharFromPoint_x                        0x8E27B0
#define CEditWnd__SetEditable_x                                    0x8E2040

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5629D0
#define CEverQuest__ClickedPlayer_x                                0x55C5A0
#define CEverQuest__CreateTargetIndicator_x                        0x55D4A0
#define CEverQuest__DeleteTargetIndicator_x                        0x55D520
#define CEverQuest__DoTellWindow_x                                 0x476540
#define CEverQuest__OutputTextToLog_x                              0x4761A0
#define CEverQuest__DropHeldItemOnGround_x                         0x572F40
#define CEverQuest__dsp_chat_x                                     0x476880
#define CEverQuest__trimName_x                                     0x558EB0
#define CEverQuest__Emote_x                                        0x571250
#define CEverQuest__EnterZone_x                                    0x56C330
#define CEverQuest__GetBodyTypeDesc_x                              0x5568F0
#define CEverQuest__GetClassDesc_x                                 0x55FDF0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5603F0
#define CEverQuest__GetDeityDesc_x                                 0x5571D0
#define CEverQuest__GetLangDesc_x                                  0x556C80
#define CEverQuest__GetRaceDesc_x                                  0x5605B0
#define CEverQuest__InterpretCmd_x                                 0x564150
#define CEverQuest__LeftClickedOnPlayer_x                          0x578AA0
#define CEverQuest__LMouseUp_x                                     0x57ABB0
#define CEverQuest__RightClickedOnPlayer_x                         0x5795B0
#define CEverQuest__RMouseUp_x                                     0x57A610
#define CEverQuest__SetGameState_x                                 0x55CE70
#define CEverQuest__UPCNotificationFlush_x                         0x555280
#define CEverQuest__IssuePetCommand_x                              0x564B30

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B2ED0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B2F30
#define CGaugeWnd__Draw_x                                          0x6B3360

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B210
#define CGuild__GetGuildName_x                                     0x43B6E0
#define CGuild__GetGuildIndex_x                                    0x43C8F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CF3A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DC5F0
#define CInvSlotMgr__MoveItem_x                                    0x6DD4A0
#define CInvSlotMgr__SelectSlot_x                                  0x6DC6A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DBAA0
#define CInvSlot__SliderComplete_x                                 0x6D9230
#define CInvSlot__GetItemBase_x                                    0x6D86C0
#define CInvSlot__UpdateItem_x                                     0x6D8C40

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DE8F0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6DFA10

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A5600
#define CItemDisplayWnd__UpdateStrings_x                           0x6E0B20
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6ED5C0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6EDAF0
#define CItemDisplayWnd__SetItem_x                                 0x6F3490

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7DCAE0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6E70F0

// CLabel 
#define CLabel__Draw_x                                             0x6FA130

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B95E0
#define CListWnd__dCListWnd_x                                      0x8BA800
#define CListWnd__AddColumn_x                                      0x8BA7A0
#define CListWnd__AddColumn1_x                                     0x8B9E40
#define CListWnd__AddLine_x                                        0x8B98A0
#define CListWnd__AddString_x                                      0x8B9AC0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B68A0
#define CListWnd__CalculateVSBRange_x                              0x8B8AB0
#define CListWnd__ClearSel_x                                       0x8B5BD0
#define CListWnd__ClearAllSel_x                                    0x8B5B80
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B9470
#define CListWnd__Compare_x                                        0x8B7410
#define CListWnd__Draw_x                                           0x8B86C0
#define CListWnd__DrawColumnSeparators_x                           0x8B8550
#define CListWnd__DrawHeader_x                                     0x8B5E90
#define CListWnd__DrawItem_x                                       0x8B7A90
#define CListWnd__DrawLine_x                                       0x8B81F0
#define CListWnd__DrawSeparator_x                                  0x8B85F0
#define CListWnd__EnableLine_x                                     0x8B5DB0
#define CListWnd__EnsureVisible_x                                  0x8B6A00
#define CListWnd__ExtendSel_x                                      0x8B79A0
#define CListWnd__GetColumnMinWidth_x                              0x8B5580
#define CListWnd__GetColumnWidth_x                                 0x8B54B0
#define CListWnd__GetCurSel_x                                      0x8B4C80
#define CListWnd__GetItemAtPoint_x                                 0x8B6C90
#define CListWnd__GetItemAtPoint1_x                                0x8B6D00
#define CListWnd__GetItemData_x                                    0x8B4FC0
#define CListWnd__GetItemHeight_x                                  0x8B6510
#define CListWnd__GetItemIcon_x                                    0x8B51B0
#define CListWnd__GetItemRect_x                                    0x8B6AD0
#define CListWnd__GetItemText_x                                    0x8B5060
#define CListWnd__GetSelList_x                                     0x8B9D30
#define CListWnd__GetSeparatorRect_x                               0x8B7330
#define CListWnd__InsertLine_x                                     0x8B9CA0
#define CListWnd__RemoveLine_x                                     0x8B9CB0
#define CListWnd__SetColors_x                                      0x8B4DD0
#define CListWnd__SetColumnJustification_x                         0x8B5810
#define CListWnd__SetColumnWidth_x                                 0x8B5530
#define CListWnd__SetCurSel_x                                      0x8B4CC0
#define CListWnd__SetItemColor_x                                   0x8B9160
#define CListWnd__SetItemData_x                                    0x8B5C30
#define CListWnd__SetItemText_x                                    0x8B8FA0
#define CListWnd__ShiftColumnSeparator_x                           0x8B8E30
#define CListWnd__Sort_x                                           0x8BA900
#define CListWnd__ToggleSel_x                                      0x8B5B00

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7132D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x734850
#define CMerchantWnd__RequestBuyItem_x                             0x73B930
#define CMerchantWnd__RequestSellItem_x                            0x73C400
#define CMerchantWnd__SelectRecoverySlot_x                         0x734B00
#define CMerchantWnd__SelectBuySellSlot_x                          0x733D00
#define CMerchantWnd__ActualSelect_x                               0x7387F0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84B7B0
#define CPacketScrambler__hton_x                                   0x84B7C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D8440
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D8520
#define CSidlManager__CreateLabel_x                                0x79CC70
#define CSidlManager__CreateXWndFromTemplate_x                     0x8D69D0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D8800

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8CF9F0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8CF8F0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F3900
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D0300
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D14C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D1570
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D0A40
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CFCB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CF420
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CFEA0
#define CSidlScreenWnd__Init1_x                                    0x8D1190
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D03B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CF5E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D0C80
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CF080
#define CSidlScreenWnd__StoreIniVis_x                              0x8CF3D0
#define CSidlScreenWnd__WndNotification_x                          0x8D0F10
#define CSidlScreenWnd__GetChildItem_x                             0x8CF4F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C2DE0
#define CSidlScreenWnd__m_layoutCopy_x                             0x171F048

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FE090
#define CSkillMgr__GetSkillCap_x                                   0x5FE270
#define CSkillMgr__GetNameToken_x                                  0x5FDC40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F2BB0
#define CSliderWnd__SetValue_x                                     0x8F2D80
#define CSliderWnd__SetNumTicks_x                                  0x8F3500

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A3260

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8ED0A0
#define CStmlWnd__CalculateHSBRange_x                              0x8E57B0
#define CStmlWnd__CalculateVSBRange_x                              0x8E5720
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E5930
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E6130
#define CStmlWnd__ForceParseNow_x                                  0x8EDA20
#define CStmlWnd__GetNextTagPiece_x                                0x8E6030
#define CStmlWnd__GetSTMLText_x                                    0x484270
#define CStmlWnd__GetVisibleText_x                                 0x8E6B80
#define CStmlWnd__InitializeWindowVariables_x                      0x8E8FE0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E4A00
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E4A60
#define CStmlWnd__SetSTMLText_x                                    0x8EA830
#define CStmlWnd__StripFirstSTMLLines_x                            0x8ECD40
#define CStmlWnd__UpdateHistoryString_x                            0x8E7AC0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F0F30
#define CTabWnd__DrawCurrentPage_x                                 0x8F07C0
#define CTabWnd__DrawTab_x                                         0x8F0590
#define CTabWnd__GetCurrentPage_x                                  0x8F0B70
#define CTabWnd__GetPageInnerRect_x                                0x8F0280
#define CTabWnd__GetTabInnerRect_x                                 0x8F0480
#define CTabWnd__GetTabRect_x                                      0x8F0350
#define CTabWnd__InsertPage_x                                      0x8F1220
#define CTabWnd__SetPage_x                                         0x8F0BA0
#define CTabWnd__SetPageRect_x                                     0x8F0E70
#define CTabWnd__UpdatePage_x                                      0x8F11C0
#define CTabWnd__GetPageFromTabIndex_x                             0x8F04E0
#define CTabWnd__GetCurrentTabIndex_x                              0x8F0210

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6DFBC0
#define CPageWnd__SetTabText_x                                     0x8FC900

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436E00

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CD310
#define CTextureFont__GetTextExtent_x                              0x8CD070

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x636800

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F8D40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B2E20

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x8F7AB0
#define CXStr__CXStr3_x                                            0x8960C0
#define CXStr__dCXStr_x                                            0x40BAA0
#define CXStr__operator_equal_x                                    0x896230
#define CXStr__operator_equal1_x                                   0x896280
#define CXStr__operator_plus_equal1_x                              0x897380

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C1FC0
#define CXWnd__Center_x                                            0x8C8140
#define CXWnd__ClrFocus_x                                          0x8C1BA0
#define CXWnd__Destroy_x                                           0x8C8C10
#define CXWnd__DoAllDrawing_x                                      0x8C7DA0
#define CXWnd__DrawChildren_x                                      0x8C7F40
#define CXWnd__DrawColoredRect_x                                   0x8C23B0
#define CXWnd__DrawTooltip_x                                       0x8C2660
#define CXWnd__DrawTooltipAtPoint_x                                0x8C6D20
#define CXWnd__GetBorderFrame_x                                    0x8C2AB0
#define CXWnd__GetChildWndAt_x                                     0x8C8AF0
#define CXWnd__GetClientClipRect_x                                 0x8C2870
#define CXWnd__GetScreenClipRect_x                                 0x8C7410
#define CXWnd__GetScreenRect_x                                     0x8C2C70
#define CXWnd__GetTooltipRect_x                                    0x8C24F0
#define CXWnd__GetWindowTextA_x                                    0x4272C0
#define CXWnd__IsActive_x                                          0x8BD5B0
#define CXWnd__IsDescendantOf_x                                    0x8C2A00
#define CXWnd__IsReallyVisible_x                                   0x8C5D60
#define CXWnd__IsType_x                                            0x8C81B0
#define CScreenPieceTemplate__IsType_x                             0x8F5550
#define CXWnd__Move_x                                              0x8C5460
#define CXWnd__Move1_x                                             0x8C7A40
#define CXWnd__ProcessTransition_x                                 0x8C1F70
#define CXWnd__Refade_x                                            0x8C1D40
#define CXWnd__Resize_x                                            0x8C2D40
#define CXWnd__Right_x                                             0x8C7210
#define CXWnd__SetFocus_x                                          0x8C45B0
#define CXWnd__SetFont_x                                           0x8C1BF0
#define CXWnd__SetKeyTooltip_x                                     0x8C2FB0
#define CXWnd__SetMouseOver_x                                      0x8C7720
#define CXWnd__StartFade_x                                         0x8C2010
#define CXWnd__GetChildItem_x                                      0x8C7660
#define CXWnd__SetParent_x                                         0x8C8AA0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BEE30
#define CXWndManager__DrawWindows_x                                0x8BEA80
#define CXWndManager__GetKeyboardFlags_x                           0x8BD0E0
#define CXWndManager__HandleKeyboardMsg_x                          0x8BDA40
#define CXWndManager__RemoveWnd_x                                  0x8BD740

// CDBStr
#define CDBStr__GetString_x                                        0x4B35D0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x451ED0
#define EQ_Character__Cur_HP_x                                     0x466850
#define EQ_Character__Cur_Mana_x                                   0x45A5E0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B150
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443460
#define EQ_Character__GetFocusRangeModifier_x                      0x4434C0
#define EQ_Character__GetHPRegen_x                                 0x469A30
#define EQ_Character__GetEnduranceRegen_x                          0x465E60
#define EQ_Character__GetManaRegen_x                               0x469FD0
#define EQ_Character__Max_Endurance_x                              0x5C4870
#define EQ_Character__Max_HP_x                                     0x45D160
#define EQ_Character__Max_Mana_x                                   0x5C46A0
#define EQ_Character__doCombatAbility_x                            0x5C1D70
#define EQ_Character__UseSkill_x                                   0x4709C0
#define EQ_Character__GetConLevel_x                                0x5B72F0
#define EQ_Character__IsExpansionFlag_x                            0x426800
#define EQ_Character__TotalEffect_x                                0x44F200
#define EQ_Character__GetPCSpellAffect_x                           0x44B550
#define EQ_Character__SpellDuration_x                              0x4494F0
#define EQ_Character__FindItemByRecord_x                           0x463EA0
#define EQ_Character__GetAdjustedSkill_x                           0x467000
#define EQ_Character__GetBaseSkill_x                               0x45D040

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x869620

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5CC8B0

//PcClient
#define PcClient__PcClient_x                                       0x5B9150

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x4467F0
#define CCharacterSelect__EnterWorld_x                             0x445FC0
#define CCharacterSelect__Quit_x                                   0x444BA0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x597630
#define EQ_Item__CreateItemTagString_x                             0x84A150
#define EQ_Item__IsStackable_x                                     0x83FB90
#define EQ_Item__GetImageNum_x                                     0x842620
#define EQ_Item__CreateItemClient_x                                0x598210
#define EQ_Item__GetItemValue_x                                    0x848EA0
#define EQ_Item__ValueSellMerchant_x                               0x84B410
#define EQ_Item__IsKeyRingItem_x                                   0x8405E0
#define EQ_Item__CanGoInBag_x                                      0x5977C0
#define EQ_Item__GetMaxItemCount_x                                 0x83FA80
#define EQ_Item__GetHeldItem_x                                     0x841430
#define EQ_Item__GetAugmentFitBySlot_x                             0x84B230

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D3930
#define EQ_LoadingS__Array_x                                       0xBFAA78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C6D80
#define EQ_PC__GetAlternateAbilityId_x                             0x853890
#define EQ_PC__GetCombatAbility_x                                  0x853920
#define EQ_PC__GetCombatAbilityTimer_x                             0x84E460
#define EQ_PC__GetItemRecastTimer_x                                0x5C0520
#define EQ_PC__HasLoreItem_x                                       0x5BA910
#define EQ_PC__AlertInventoryChanged_x                             0x5B72C0
#define EQ_PC__GetPcZoneClient_x                                   0x5E0EC0
#define EQ_PC__RemoveMyAffect_x                                    0x5BF9F0
#define EQ_PC__GetKeyRingItems_x                                   0x84E880
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x861590
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x855810

// EQItemList 
#define EQItemList__EQItemList_x                                   0x51F2F0
#define EQItemList__add_object_x                                   0x54C130
#define EQItemList__add_item_x                                     0x51F230
#define EQItemList__delete_item_x                                  0x51F6E0
#define EQItemList__FreeItemList_x                                 0x51F5E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B28D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CC650
#define EQPlayer__dEQPlayer_x                                      0x5D4CA0
#define EQPlayer__DoAttack_x                                       0x5E6830
#define EQPlayer__EQPlayer_x                                       0x5D73D0
#define EQPlayer__SetNameSpriteState_x                             0x5D1B60
#define EQPlayer__SetNameSpriteTint_x                              0x5CDA70
#define PlayerBase__HasProperty_j_x                                0x9264D0
#define EQPlayer__IsTargetable_x                                   0x926770
#define EQPlayer__CanSee_x                                         0x926CD0
#define PlayerZoneClient__ChangeHeight_x                           0x5E66F0
#define EQPlayer__CanSeeTargetIndicator_x                          0x926DC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x926A60

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E1070

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5DB500
#define EQPlayerManager__GetSpawnByName_x                          0x5DB960
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5DB530

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59D820
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59D860
#define KeypressHandler__ClearCommandStateArray_x                  0x59D410
#define KeypressHandler__HandleKeyDown_x                           0x59BD70
#define KeypressHandler__HandleKeyUp_x                             0x59C090
#define KeypressHandler__SaveKeymapping_x                          0x59D4E0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70BC60
#define MapViewMap__SaveEx_x                                       0x70EF90

#define PlayerPointManager__GetAltCurrency_x                       0x8676B0

// StringTable 
#define StringTable__getString_x                                   0x8618C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C4300
#define PcZoneClient__RemovePetEffect_x                            0x5C09F0
#define PcZoneClient__HasAlternateAbility_x                        0x5C1390
#define PcZoneClient__GetCurrentMod_x                              0x45C610
#define PcZoneClient__GetModCap_x                                  0x459D40
#define PcZoneClient__CanEquipItem_x                               0x5C18B0
#define PcZoneClient__GetItemByID_x                                0x5C6100
#define PcZoneClient__GetItemByItemClass_x                         0x5C6CA0

//Doors
#define EQSwitch__UseSwitch_x                                      0x553B20

//IconCache
#define IconCache__GetIcon_x                                       0x6A86B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69F5B0
#define CContainerMgr__CloseContainer_x                            0x69FDD0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76CBD0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x590640

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4ED910
#define EQ_Spell__SpellAffects_x                                   0x4EAFB0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4EB020
#define CharacterZoneClient__CalcAffectChange_x                    0x44B3E0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A620
#define CLootWnd__LootAll_x                                        0x7014F0
#define CLootWnd__RequestLootSlot_x                                0x701D00
#define EQ_Spell__IsStackable_x                                    0x4490B0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449160
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43ECC0
#define EQ_Spell__IsSPAStacking_x                                  0x4EAB60
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4EA630
#define EQ_Spell__IsNoRemove_x                                     0x434E40
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4EAB80

#define __IsResEffectSpell_x                                       0x4491F0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8732B0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B2650
#define CTargetWnd__WndNotification_x                              0x7B2140
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B2830

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B7740

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E6570
#define EqSoundManager__PlayScriptMp3_x                            0x4E8010

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A1A00

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E1020
#define CSidlManager__FindAnimation1_x                             0x8D6400

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4DB120
#define CAltAbilityData__GetMercMaxRank_x                          0x4DB0D0
#define CAltAbilityData__GetMaxRank_x                              0x4CFA30

//CTargetRing
#define CTargetRing__Cast_x                                        0x58DF00

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x458D00
#define CharacterBase__CreateItemGlobalIndex_x                     0x475740
#define CharacterBase__CreateItemIndex_x                           0x518870
#define CharacterBase__GetItemPossession_x                         0x444040
#define CharacterBase__GetItemByGlobalIndex_x                      0x877100
#define CharacterBase__GetEffectId_x                               0x458CC0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x688510
#define CCastSpellWnd__IsBardSongPlaying_x                         0x687C70

//messages
#define msg_spell_worn_off_x                                       0x4F54B0
#define msg_new_text_x                                             0x4FEB00
#define msgTokenTextParam_x                                        0x4FB340

//SpellManager
#define SpellManager__vftable_x                                    0xABB160
#define SpellManager__SpellManager_x                               0x47E390
#define Spellmanager__CheckSpellRequirementAssociations_x          0x604FE0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x92A7E0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F1A90
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EBF0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x448E60
#define ItemGlobalIndex__IsValidIndex_x                            0x4585C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x874F70
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x873EB0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6FA380

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6A42F0
#define CCursorAttachment__Deactivate_x                            0x6A3830

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8F20B0
