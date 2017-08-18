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
#define __ExpectedVersionDate                                     "Aug 10 2017"
#define __ExpectedVersionTime                                     "10:26:17"
#define __ActualVersionDate_x                                      0xAD6438
#define __ActualVersionTime_x                                      0xAD6444

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5A2B50
#define __MemChecker1_x                                            0x89A9F0
#define __MemChecker2_x                                            0x638B20
#define __MemChecker3_x                                            0x638A70
#define __MemChecker4_x                                            0x7ED1B0
#define __EncryptPad0_x                                            0xC31328
#define __EncryptPad1_x                                            0xD0C6E0
#define __EncryptPad2_x                                            0xC5AB10
#define __EncryptPad3_x                                            0xC5A710
#define __EncryptPad4_x                                            0xCFACE0
#define __EncryptPad5_x                                            0x10B5370
#define __AC1_x                                                    0x7AC1F5
#define __AC2_x                                                    0x55BAA7
#define __AC3_x                                                    0x559C20
#define __AC4_x                                                    0x56BDF1
#define __AC5_x                                                    0x57FC9B
#define __AC6_x                                                    0x58384E
#define __AC7_x                                                    0x57A29C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FECDFC

// Direct Input
#define DI8__Main_x                                                0x10B5348
#define DI8__Keyboard_x                                            0x10B534C
#define DI8__Mouse_x                                               0x10B5350
#define DI8__Mouse_Copy_x                                          0xF2370C
#define DI8__Mouse_Check_x                                         0xFAD034
#define __AutoSkillArray_x                                         0xF24620
#define __Attack_x                                                 0xFA7C17
#define __Autofire_x                                               0xFA7C18
#define __BindList_x                                               0xC0C050
#define g_eqCommandStates_x                                        0xF12730
#define __Clicks_x                                                 0xF237C8
#define __CommandList_x                                            0xC0E6C8
#define __CurrentMapLabel_x                                        0x10BADD0
#define __CurrentSocial_x                                          0xBDD424
#define __DoAbilityList_x                                          0xF59ECC
#define __do_loot_x                                                0x52AE00
#define __DrawHandler_x                                            0x1721C84
#define __GroupCount_x                                             0xF13D62

#define __Guilds_x                                                 0xF19978
#define __gWorld_x                                                 0xF1621C
#define __HotkeyPage_x                                             0xFA08CC
#define __HWnd_x                                                   0xFAD150
#define __InChatMode_x                                             0xF236F4
#define __LastTell_x                                               0xF255C8
#define __LMouseHeldTime_x                                         0xF23834
#define __Mouse_x                                                  0x10B5354
#define __MouseLook_x                                              0xF2378E
#define __MouseEventTime_x                                         0xFA841C
#define __gpbCommandEvent_x                                        0xF162E4
#define __NetStatusToggle_x                                        0xF23791
#define __PCNames_x                                                0xF24BDC
#define __RangeAttackReady_x                                       0xF24904
#define __RMouseHeldTime_x                                         0xF23830
#define __RunWalkState_x                                           0xF236F8
#define __ScreenMode_x                                             0xE62418
#define __ScreenX_x                                                0xF236AC
#define __ScreenY_x                                                0xF236A8
#define __ScreenXMax_x                                             0xF236B0
#define __ScreenYMax_x                                             0xF236B4
#define __ServerHost_x                                             0xF13CAC
#define __ServerName_x                                             0xF59E8C
#define __ShiftKeyDown_x                                           0xF23D88
#define __ShowNames_x                                              0xF24AC4
#define __Socials_x                                                0xF59F8C
#define __SubscriptionType_x                                       0x10E8DB4
#define __TargetAggroHolder_x                                      0x10BCFA4
#define __ZoneType_x                                               0xF23B8C
#define __GroupAggro_x                                             0x10BCFE4
#define __LoginName_x                                              0xFABC2C
#define __Inviter_x                                                0xFA7B94
#define __AttackOnAssist_x                                         0xF24A80
#define __UseTellWindows_x                                         0xF24D74

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF16308
#define instEQZoneInfo_x                                           0xF23984
#define instKeypressHandler_x                                      0xFA8400
#define pinstActiveBanker_x                                        0xF162C0
#define pinstActiveCorpse_x                                        0xF162C4
#define pinstActiveGMaster_x                                       0xF162C8
#define pinstActiveMerchant_x                                      0xF162BC
#define pinstAggroInfo_x                                           0xD1FD88
#define pinstAltAdvManager_x                                       0xE634F8
#define pinstAuraMgr_x                                             0xD304F8
#define pinstBandageTarget_x                                       0xF162A8
#define pinstCamActor_x                                            0xE62E4C
#define pinstCDBStr_x                                              0xE623AC
#define pinstCDisplay_x                                            0xF162D0
#define pinstCEverQuest_x                                          0x10B54C8
#define pinstEverQuestInfo_x                                       0xF236A0
#define pinstCharData_x                                            0xF1628C
#define pinstCharSpawn_x                                           0xF162B4
#define pinstControlledMissile_x                                   0xF16288
#define pinstControlledPlayer_x                                    0xF162B4
#define pinstCSidlManager_x                                        0x1721074
#define pinstCXWndManager_x                                        0x172106C
#define instDynamicZone_x                                          0xF23540
#define pinstDZMember_x                                            0xF23650
#define pinstDZTimerInfo_x                                         0xF23654
#define pinstEQItemList_x                                          0xF12984
#define pinstEQObjectList_x                                        0xF1375C
#define instEQMisc_x                                               0xBF4690
#define pinstEQSoundManager_x                                      0xE63AC8
#define instExpeditionLeader_x                                     0xF2358A
#define instExpeditionName_x                                       0xF235CA
#define pinstGroup_x                                               0xF13D5E
#define pinstImeManager_x                                          0x1721078
#define pinstLocalPlayer_x                                         0xF162A0
#define pinstMercenaryData_x                                       0xFA8A80
#define pinstMercenaryStats_x                                      0x10BD0F0
#define pinstMercAltAbilities_x                                    0xE63880
#define pinstModelPlayer_x                                         0xF162CC
#define pinstPCData_x                                              0xF1628C
#define pinstSkillMgr_x                                            0xFA98E8
#define pinstSpawnManager_x                                        0xFA91D0
#define pinstSpellManager_x                                        0xFA9A30
#define pinstSpellSets_x                                           0xFA0930
#define pinstStringTable_x                                         0xF16234
#define pinstSwitchManager_x                                       0xF138F0
#define pinstTarget_x                                              0xF162B8
#define pinstTargetObject_x                                        0xF16290
#define pinstTargetSwitch_x                                        0xF16294
#define pinstTaskMember_x                                          0xE622F8
#define pinstTrackTarget_x                                         0xF162AC
#define pinstTradeTarget_x                                         0xF1629C
#define instTributeActive_x                                        0xBF46B5
#define pinstViewActor_x                                           0xE62E48
#define pinstWorldData_x                                           0xF16270
#define pinstZoneAddr_x                                            0xF23C24
#define pinstPlayerPath_x                                          0xFA9230
#define pinstTargetIndicator_x                                     0xFA9BC8
#define pinstCTargetManager_x                                      0xFA9C28
#define EQObject_Top_x                                             0xF16280
#define pinstRealEstateItems_x                                     0xFA97D4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE62D64
#define pinstCAchievementsWnd_x                                    0xE62DC0
#define pinstCTextOverlay_x                                        0xD20288
#define pinstCAudioTriggersWindow_x                                0xD20118
#define pinstCCharacterSelect_x                                    0xE62CD4
#define pinstCFacePick_x                                           0xE62A84
#define pinstCNoteWnd_x                                            0xE62C8C
#define pinstCBookWnd_x                                            0xE62C94
#define pinstCPetInfoWnd_x                                         0xE62C98
#define pinstCTrainWnd_x                                           0xE62C9C
#define pinstCSkillsWnd_x                                          0xE62CA0
#define pinstCSkillsSelectWnd_x                                    0xE62CA4
#define pinstCCombatSkillsSelectWnd_x                              0xE62CA8
#define pinstCFriendsWnd_x                                         0xE62CAC
#define pinstCAuraWnd_x                                            0xE62CB0
#define pinstCRespawnWnd_x                                         0xE62CB4
#define pinstCBandolierWnd_x                                       0xE62CB8
#define pinstCPotionBeltWnd_x                                      0xE62CBC
#define pinstCAAWnd_x                                              0xE62CC0
#define pinstCAlarmWnd_x                                           0xE62CCC
#define pinstCGroupSearchFiltersWnd_x                              0xE62CC4
#define pinstCLoadskinWnd_x                                        0xE62CC8
#define pinstCLargeDialogWnd_x                                     0x10BC050
#define pinstCMusicPlayerWnd_x                                     0xE62CD0
#define pinstCMailWnd_x                                            0xE62CD8
#define pinstCMailCompositionWnd_x                                 0xE62CDC
#define pinstCMailAddressBookWnd_x                                 0xE62CE0
#define pinstCRaidWnd_x                                            0xE62CE8
#define pinstCRaidOptionsWnd_x                                     0xE62CEC
#define pinstCBreathWnd_x                                          0xE62CF0
#define pinstCMapViewWnd_x                                         0xE62CF4
#define pinstCMapToolbarWnd_x                                      0xE62CF8
#define pinstCEditLabelWnd_x                                       0xE62CFC
#define pinstCTargetWnd_x                                          0xE62D00
#define pinstCColorPickerWnd_x                                     0xE62D04
#define pinstCPlayerWnd_x                                          0xE62D08
#define pinstCOptionsWnd_x                                         0xE62D0C
#define pinstCBuffWindowNORMAL_x                                   0xE62D10
#define pinstCBuffWindowSHORT_x                                    0xE62D14
#define pinstCharacterCreation_x                                   0xE62D18
#define pinstCCursorAttachment_x                                   0xE62D1C
#define pinstCCastingWnd_x                                         0xE62D20
#define pinstCCastSpellWnd_x                                       0xE62D24
#define pinstCSpellBookWnd_x                                       0xE62D28
#define pinstCInventoryWnd_x                                       0xE62D2C
#define pinstCBankWnd_x                                            0xE62D34
#define pinstCQuantityWnd_x                                        0xE62D38
#define pinstCLootWnd_x                                            0xE62D3C
#define pinstCActionsWnd_x                                         0xE62D40
#define pinstCCombatAbilityWnd_x                                   0xE62D48
#define pinstCMerchantWnd_x                                        0xE62D4C
#define pinstCTradeWnd_x                                           0xE62D54
#define pinstCSelectorWnd_x                                        0xE62D58
#define pinstCBazaarWnd_x                                          0xE62D5C
#define pinstCBazaarSearchWnd_x                                    0xE62D60
#define pinstCGiveWnd_x                                            0xE62D7C
#define pinstCTrackingWnd_x                                        0xE62D84
#define pinstCInspectWnd_x                                         0xE62D88
#define pinstCSocialEditWnd_x                                      0xE62D8C
#define pinstCFeedbackWnd_x                                        0xE62D90
#define pinstCBugReportWnd_x                                       0xE62D94
#define pinstCVideoModesWnd_x                                      0xE62D98
#define pinstCTextEntryWnd_x                                       0xE62DA0
#define pinstCFileSelectionWnd_x                                   0xE62DA4
#define pinstCCompassWnd_x                                         0xE62DA8
#define pinstCPlayerNotesWnd_x                                     0xE62DAC
#define pinstCGemsGameWnd_x                                        0xE62DB0
#define pinstCTimeLeftWnd_x                                        0xE62DB4
#define pinstCPetitionQWnd_x                                       0xE62DD0
#define pinstCStoryWnd_x                                           0xE62DD4
#define pinstCJournalTextWnd_x                                     0xE62DD8
#define pinstCJournalCatWnd_x                                      0xE62DDC
#define pinstCBodyTintWnd_x                                        0xE62DE0
#define pinstCServerListWnd_x                                      0xE62DE4
#define pinstCAvaZoneWnd_x                                         0xE62DF0
#define pinstCBlockedBuffWnd_x                                     0xE62DF4
#define pinstCBlockedPetBuffWnd_x                                  0xE62DF8
#define pinstCInvSlotMgr_x                                         0xE62E40
#define pinstCContainerMgr_x                                       0xE62E44
#define pinstCAdventureLeaderboardWnd_x                            0x10B5E78
#define pinstCAdventureRequestWnd_x                                0x10B5EF0
#define pinstCAltStorageWnd_x                                      0x10B61D0
#define pinstCAdventureStatsWnd_x                                  0x10B5F68
#define pinstCBarterMerchantWnd_x                                  0x10B6DB8
#define pinstCBarterSearchWnd_x                                    0x10B6E30
#define pinstCBarterWnd_x                                          0x10B6EA8
#define pinstCChatWindowManager_x                                  0x10B7538
#define pinstCDynamicZoneWnd_x                                     0x10B79E8
#define pinstCEQMainWnd_x                                          0x10B7B80
#define pinstCFellowshipWnd_x                                      0x10B797C
#define pinstCFindLocationWnd_x                                    0x10B7E50
#define pinstCGroupSearchWnd_x                                     0x10B8120
#define pinstCGroupWnd_x                                           0x10B8198
#define pinstCGuildBankWnd_x                                       0x10B8210
#define pinstCGuildMgmtWnd_x                                       0x10BA300
#define pinstCHotButtonWnd_x                                       0x10BA3FC
#define pinstCHotButtonWnd1_x                                      0x10BA3FC
#define pinstCHotButtonWnd2_x                                      0x10BA400
#define pinstCHotButtonWnd3_x                                      0x10BA404
#define pinstCHotButtonWnd4_x                                      0x10BA428
#define pinstCItemDisplayManager_x                                 0x10BA720
#define pinstCItemExpTransferWnd_x                                 0x10BA79C
#define pinstCLFGuildWnd_x                                         0x10BAA78
#define pinstCMIZoneSelectWnd_x                                    0x10BB060
#define pinstCConfirmationDialog_x                                 0x10BB768
#define pinstCPopupWndManager_x                                    0x10BB768
#define pinstCProgressionSelectionWnd_x                            0x10BB858
#define pinstCPvPStatsWnd_x                                        0x10BB948
#define pinstCTaskWnd_x                                            0x10BD3D0
#define pinstCTaskSomething_x                                      0xD30EA0
#define pinstCTaskTemplateSelectWnd_x                              0x10BD358
#define pinstCTipWndOFDAY_x                                        0x10BD538
#define pinstCTipWndCONTEXT_x                                      0x10BD53C
#define pinstCTitleWnd_x                                           0x10BD5B8
#define pinstCContextMenuManager_x                                 0x1720FE4
#define pinstCVoiceMacroWnd_x                                      0xFAA000
#define pinstCHtmlWnd_x                                            0xFAA0F0
#define pinstIconCache_x                                           0x10B7B54
#define pinstCTradeskillWnd_x                                      0x10BD6B8
#define pinstCAdvancedLootWnd_x                                    0xE62E34
#define pinstRewardSelectionWnd_x                                  0x10BBE70
#define pinstEQSuiteTextureLoader_x                                0xD0E458

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x542390
#define __CastRay2_x                                               0x541CC0
#define __HeadingDiff_x                                            0x9296D0
#define __FixHeading_x                                             0x929660
#define __get_bearing_x                                            0x531DA0
#define __ConvertItemTags_x                                        0x52FA20
#define __ExecuteCmd_x                                             0x51A310
#define __EQGetTime_x                                              0x89A390
#define __get_melee_range_x                                        0x520FA0
#define __GetGaugeValueFromEQ_x                                    0x7AADB0
#define __GetLabelFromEQ_x                                         0x7AC180
#define __ToggleKeyRingItem_x                                      0x488C20
#define __GetXTargetType_x                                         0x92B2D0
#define __LoadFrontEnd_x                                           0x6381F0
#define __NewUIINI_x                                               0x7AA780
#define __ProcessGameEvents_x                                      0x57C030
#define __ProcessMouseEvent_x                                      0x57B7D0
#define CrashDetected_x                                            0x639BB0
#define wwsCrashReportCheckForUploader_x                           0x7F8D40
#define __AppCrashWrapper_x                                        0xC5A704
#define __pCrashHandler_x                                          0x10CA568
#define __CrashHandler_x                                           0x7F87A0
#define wwsCrashReportPlatformLaunchUploader_x                     0x7FAF40
#define DrawNetStatus_x                                            0x5B2750
#define Util__FastTime_x                                           0x89A030
#define Expansion_HoT_x                                            0xF24A70
#define __HelpPath_x                                               0xFA8188
#define __STMLToText_x                                             0x8E05A0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4230F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DE00
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DBD0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D1240
#define AltAdvManager__IsAbilityReady_x                            0x4D12B0
#define AltAdvManager__GetAAById_x                                 0x4D17A0
#define AltAdvManager__CanTrainAbility_x                           0x4D23D0
#define AltAdvManager__CanSeeAbility_x                             0x4D1F90

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46A370
#define CharacterZoneClient__HasSkill_x                            0x467220
#define CharacterZoneClient__MakeMeVisible_x                       0x46B900
#define CharacterZoneClient__IsStackBlocked_x                      0x44BA00
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44AEC0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4651A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x465280
#define CharacterZoneClient__GetCursorItemCount_x                  0x465360
#define CharacterZoneClient__FindAffectSlot_x                      0x450F40
#define CharacterZoneClient__BardCastBard_x                        0x44A640
#define CharacterZoneClient__GetMaxEffects_x                       0x449380
#define CharacterZoneClient__GetEffect_x                           0x44B0F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x450DA0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449520
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44F8F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x667B10

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x675E40

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5918C0
#define CButtonWnd__CButtonWnd_x                                   0x8D47A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691040
#define CChatManager__InitContextMenu_x                            0x692190
#define CChatManager__FreeChatWindow_x                             0x690AD0
#define CChatManager__GetLockedActiveChatWindow_x                  0x69A250
#define CChatManager__SetLockedActiveChatWindow_x                  0x691010

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DE8F0
#define CContextMenu__dCContextMenu_x                              0x8DEB00
#define CContextMenu__AddMenuItem_x                                0x8DF020
#define CContextMenu__RemoveMenuItem_x                             0x8DEC80
#define CContextMenu__RemoveAllMenuItems_x                         0x8DECA0
#define CContextMenu__CheckMenuItem_x                              0x8DED20

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8CAD30
#define CContextMenuManager__RemoveMenu_x                          0x8CB0D0
#define CContextMenuManager__PopupMenu_x                           0x8CB520
#define CContextMenuManager__Flush_x                               0x8CADA0
#define CContextMenuManager__GetMenu_x                             0x4194A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87E530
#define CChatService__GetFriendName_x                              0x87E540

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x697DA0
#define CChatWindow__Clear_x                                       0x697680
#define CChatWindow__WndNotification_x                             0x6986A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CEB80
#define CComboWnd__Draw_x                                          0x8CED90
#define CComboWnd__GetCurChoice_x                                  0x8CE930
#define CComboWnd__GetListRect_x                                   0x8CF030
#define CComboWnd__GetTextRect_x                                   0x8CEBF0
#define CComboWnd__InsertChoice_x                                  0x8CF0A0
#define CComboWnd__SetColors_x                                     0x8CE8C0
#define CComboWnd__SetChoice_x                                     0x8CE8F0
#define CComboWnd__GetItemCount_x                                  0x8CE920
#define CComboWnd__GetCurChoiceText_x                              0x8CE970


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A1F30
#define CContainerWnd__vftable_x                                   0xAE0040

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
#define CEditBaseWnd__SetSel_x                                     0x8F5100

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E2E50
#define CEditWnd__GetCharIndexPt_x                                 0x8E3EF0
#define CEditWnd__GetDisplayString_x                               0x8E3000
#define CEditWnd__GetHorzOffset_x                                  0x8E3340
#define CEditWnd__GetLineForPrintableChar_x                        0x8E39B0
#define CEditWnd__GetSelStartPt_x                                  0x8E41B0
#define CEditWnd__GetSTMLSafeText_x                                0x8E34E0
#define CEditWnd__PointFromPrintableChar_x                         0x8E3AA0
#define CEditWnd__SelectableCharFromPoint_x                        0x8E3C20
#define CEditWnd__SetEditable_x                                    0x8E34B0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x562620
#define CEverQuest__ClickedPlayer_x                                0x55C1F0
#define CEverQuest__CreateTargetIndicator_x                        0x55D0F0
#define CEverQuest__DeleteTargetIndicator_x                        0x55D170
#define CEverQuest__DoTellWindow_x                                 0x476540
#define CEverQuest__OutputTextToLog_x                              0x4761A0
#define CEverQuest__DropHeldItemOnGround_x                         0x572B90
#define CEverQuest__dsp_chat_x                                     0x476880
#define CEverQuest__trimName_x                                     0x558B00
#define CEverQuest__Emote_x                                        0x570EA0
#define CEverQuest__EnterZone_x                                    0x56BF80
#define CEverQuest__GetBodyTypeDesc_x                              0x556540
#define CEverQuest__GetClassDesc_x                                 0x55FA40
#define CEverQuest__GetClassThreeLetterCode_x                      0x560040
#define CEverQuest__GetDeityDesc_x                                 0x556E20
#define CEverQuest__GetLangDesc_x                                  0x5568D0
#define CEverQuest__GetRaceDesc_x                                  0x560200
#define CEverQuest__InterpretCmd_x                                 0x563DA0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5786E0
#define CEverQuest__LMouseUp_x                                     0x57A7F0
#define CEverQuest__RightClickedOnPlayer_x                         0x5791F0
#define CEverQuest__RMouseUp_x                                     0x57A250
#define CEverQuest__SetGameState_x                                 0x55CAC0
#define CEverQuest__UPCNotificationFlush_x                         0x554ED0
#define CEverQuest__IssuePetCommand_x                              0x564780

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B2BC0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B2C20
#define CGaugeWnd__Draw_x                                          0x6B3050

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B350
#define CGuild__GetGuildName_x                                     0x43B820
#define CGuild__GetGuildIndex_x                                    0x43CA30

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CF160

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DC3B0
#define CInvSlotMgr__MoveItem_x                                    0x6DD260
#define CInvSlotMgr__SelectSlot_x                                  0x6DC460

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DB860
#define CInvSlot__SliderComplete_x                                 0x6D8FF0
#define CInvSlot__GetItemBase_x                                    0x6D8470
#define CInvSlot__UpdateItem_x                                     0x6D89F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DE690
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6DF7B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A67A0
#define CItemDisplayWnd__UpdateStrings_x                           0x6E08B0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6ED390
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6ED8B0
#define CItemDisplayWnd__SetItem_x                                 0x6F3120

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7DDCC0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6E6ED0

// CLabel 
#define CLabel__Draw_x                                             0x6F9E40

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BA820
#define CListWnd__dCListWnd_x                                      0x8BBA40
#define CListWnd__AddColumn_x                                      0x8BB9E0
#define CListWnd__AddColumn1_x                                     0x8BB080
#define CListWnd__AddLine_x                                        0x8BAAE0
#define CListWnd__AddString_x                                      0x8BAD00
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B7A90
#define CListWnd__CalculateVSBRange_x                              0x8B9CE0
#define CListWnd__ClearSel_x                                       0x8B6DB0
#define CListWnd__ClearAllSel_x                                    0x8B6D60
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BA6B0
#define CListWnd__Compare_x                                        0x8B8610
#define CListWnd__Draw_x                                           0x8B98E0
#define CListWnd__DrawColumnSeparators_x                           0x8B9770
#define CListWnd__DrawHeader_x                                     0x8B7070
#define CListWnd__DrawItem_x                                       0x8B8CA0
#define CListWnd__DrawLine_x                                       0x8B9410
#define CListWnd__DrawSeparator_x                                  0x8B9810
#define CListWnd__EnableLine_x                                     0x8B6F90
#define CListWnd__EnsureVisible_x                                  0x8B7BF0
#define CListWnd__ExtendSel_x                                      0x8B8BB0
#define CListWnd__GetColumnMinWidth_x                              0x8B6760
#define CListWnd__GetColumnWidth_x                                 0x8B6690
#define CListWnd__GetCurSel_x                                      0x8B5E80
#define CListWnd__GetItemAtPoint_x                                 0x8B7E90
#define CListWnd__GetItemAtPoint1_x                                0x8B7F00
#define CListWnd__GetItemData_x                                    0x8B61B0
#define CListWnd__GetItemHeight_x                                  0x8B76F0
#define CListWnd__GetItemIcon_x                                    0x8B63A0
#define CListWnd__GetItemRect_x                                    0x8B7CD0
#define CListWnd__GetItemText_x                                    0x8B6250
#define CListWnd__GetSelList_x                                     0x8BAF70
#define CListWnd__GetSeparatorRect_x                               0x8B8530
#define CListWnd__InsertLine_x                                     0x8BAEE0
#define CListWnd__RemoveLine_x                                     0x8BAEF0
#define CListWnd__SetColors_x                                      0x8B5FD0
#define CListWnd__SetColumnJustification_x                         0x8B69F0
#define CListWnd__SetColumnWidth_x                                 0x8B6710
#define CListWnd__SetCurSel_x                                      0x8B5EC0
#define CListWnd__SetItemColor_x                                   0x8BA3A0
#define CListWnd__SetItemData_x                                    0x8B6E10
#define CListWnd__SetItemText_x                                    0x8BA1E0
#define CListWnd__ShiftColumnSeparator_x                           0x8BA070
#define CListWnd__Sort_x                                           0x8BBB40
#define CListWnd__ToggleSel_x                                      0x8B6CE0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x713030

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7344B0
#define CMerchantWnd__RequestBuyItem_x                             0x73B5C0
#define CMerchantWnd__RequestSellItem_x                            0x73C090
#define CMerchantWnd__SelectRecoverySlot_x                         0x734760
#define CMerchantWnd__SelectBuySellSlot_x                          0x733960
#define CMerchantWnd__ActualSelect_x                               0x738470

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84CA10
#define CPacketScrambler__hton_x                                   0x84CA20

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D9710
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D97F0
#define CSidlManager__CreateLabel_x                                0x79C970
#define CSidlManager__CreateXWndFromTemplate_x                     0x8D7CC0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D9AD0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D0C10
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D0B00
#define CSidlScreenWnd__ConvertToRes_x                             0x8F4FE0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D1520
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D26E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D2790
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D1C60
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D0ED0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D0630
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D10C0
#define CSidlScreenWnd__Init1_x                                    0x8D23B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D15D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D07F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D1EA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D0290
#define CSidlScreenWnd__StoreIniVis_x                              0x8D05E0
#define CSidlScreenWnd__WndNotification_x                          0x8D2130
#define CSidlScreenWnd__GetChildItem_x                             0x8D0700
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C3F80
#define CSidlScreenWnd__m_layoutCopy_x                             0x1721048

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FDB50
#define CSkillMgr__GetSkillCap_x                                   0x5FDD30
#define CSkillMgr__GetNameToken_x                                  0x5FD700

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F4290
#define CSliderWnd__SetValue_x                                     0x8F4460
#define CSliderWnd__SetNumTicks_x                                  0x8F4BE0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A2CB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EE710
#define CStmlWnd__CalculateHSBRange_x                              0x8E6C70
#define CStmlWnd__CalculateVSBRange_x                              0x8E6BE0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E6DF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E75F0
#define CStmlWnd__ForceParseNow_x                                  0x8EF090
#define CStmlWnd__GetNextTagPiece_x                                0x8E74F0
#define CStmlWnd__GetSTMLText_x                                    0x484230
#define CStmlWnd__GetVisibleText_x                                 0x8E8040
#define CStmlWnd__InitializeWindowVariables_x                      0x8EA610
#define CStmlWnd__MakeStmlColorTag_x                               0x8E5EC0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E5F20
#define CStmlWnd__SetSTMLText_x                                    0x8EBE60
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EE3B0
#define CStmlWnd__UpdateHistoryString_x                            0x8E8F80

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F25F0
#define CTabWnd__DrawCurrentPage_x                                 0x8F1E80
#define CTabWnd__DrawTab_x                                         0x8F1C40
#define CTabWnd__GetCurrentPage_x                                  0x8F2230
#define CTabWnd__GetPageInnerRect_x                                0x8F1930
#define CTabWnd__GetTabInnerRect_x                                 0x8F1B30
#define CTabWnd__GetTabRect_x                                      0x8F1A00
#define CTabWnd__InsertPage_x                                      0x8F28E0
#define CTabWnd__SetPage_x                                         0x8F2260
#define CTabWnd__SetPageRect_x                                     0x8F2530
#define CTabWnd__UpdatePage_x                                      0x8F2880
#define CTabWnd__GetPageFromTabIndex_x                             0x8F1B90
#define CTabWnd__GetCurrentTabIndex_x                              0x8F18C0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6DF960
#define CPageWnd__SetTabText_x                                     0x8FDFC0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436F00

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CE530
#define CTextureFont__GetTextExtent_x                              0x8CE290

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x636450

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FA400

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B3F90

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x7E5BF0
#define CXStr__CXStr3_x                                            0x8972C0
#define CXStr__dCXStr_x                                            0x8EFB90
#define CXStr__operator_equal_x                                    0x897430
#define CXStr__operator_equal1_x                                   0x897480
#define CXStr__operator_plus_equal1_x                              0x898580

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C31F0
#define CXWnd__Center_x                                            0x8C9350
#define CXWnd__ClrFocus_x                                          0x8C2DC0
#define CXWnd__Destroy_x                                           0x8C9E20
#define CXWnd__DoAllDrawing_x                                      0x8C8FA0
#define CXWnd__DrawChildren_x                                      0x8C9140
#define CXWnd__DrawColoredRect_x                                   0x8C35D0
#define CXWnd__DrawTooltip_x                                       0x8C3880
#define CXWnd__DrawTooltipAtPoint_x                                0x8C7EE0
#define CXWnd__GetBorderFrame_x                                    0x8C3C60
#define CXWnd__GetChildWndAt_x                                     0x8C9D00
#define CXWnd__GetClientClipRect_x                                 0x8C3A70
#define CXWnd__GetScreenClipRect_x                                 0x8C85E0
#define CXWnd__GetScreenRect_x                                     0x8C3E20
#define CXWnd__GetTooltipRect_x                                    0x8C3710
#define CXWnd__GetWindowTextA_x                                    0x4271D0
#define CXWnd__IsActive_x                                          0x8BE820
#define CXWnd__IsDescendantOf_x                                    0x8C3BB0
#define CXWnd__IsReallyVisible_x                                   0x8C6F40
#define CXWnd__IsType_x                                            0x8C93C0
#define CScreenPieceTemplate__IsType_x                             0x8F6C50
#define CXWnd__Move_x                                              0x8C6630
#define CXWnd__Move1_x                                             0x8C8C40
#define CXWnd__ProcessTransition_x                                 0x8C3190
#define CXWnd__Refade_x                                            0x8C2F60
#define CXWnd__Resize_x                                            0x8C3EE0
#define CXWnd__Right_x                                             0x8C83E0
#define CXWnd__SetFocus_x                                          0x8C5780
#define CXWnd__SetFont_x                                           0x8C2E10
#define CXWnd__SetKeyTooltip_x                                     0x8C4150
#define CXWnd__SetMouseOver_x                                      0x8C8920
#define CXWnd__StartFade_x                                         0x8C3240
#define CXWnd__GetChildItem_x                                      0x8C8860
#define CXWnd__SetParent_x                                         0x8C9CB0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C0090
#define CXWndManager__DrawWindows_x                                0x8BFCD0
#define CXWndManager__GetKeyboardFlags_x                           0x8BE360
#define CXWndManager__HandleKeyboardMsg_x                          0x8BECA0
#define CXWndManager__RemoveWnd_x                                  0x8BE9B0

// CDBStr
#define CDBStr__GetString_x                                        0x4B35B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x451F40
#define EQ_Character__Cur_HP_x                                     0x466820
#define EQ_Character__Cur_Mana_x                                   0x45A5A0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B1D0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443590
#define EQ_Character__GetFocusRangeModifier_x                      0x4435F0
#define EQ_Character__GetHPRegen_x                                 0x469A00
#define EQ_Character__GetEnduranceRegen_x                          0x465E30
#define EQ_Character__GetManaRegen_x                               0x469FA0
#define EQ_Character__Max_Endurance_x                              0x5C4550
#define EQ_Character__Max_HP_x                                     0x45D120
#define EQ_Character__Max_Mana_x                                   0x5C4380
#define EQ_Character__doCombatAbility_x                            0x5C1A50
#define EQ_Character__UseSkill_x                                   0x470990
#define EQ_Character__GetConLevel_x                                0x5B6D60
#define EQ_Character__IsExpansionFlag_x                            0x426700
#define EQ_Character__TotalEffect_x                                0x44F270
#define EQ_Character__GetPCSpellAffect_x                           0x44B5D0
#define EQ_Character__SpellDuration_x                              0x449570
#define EQ_Character__FindItemByRecord_x                           0x463E70
#define EQ_Character__GetAdjustedSkill_x                           0x466FD0
#define EQ_Character__GetBaseSkill_x                               0x45D000

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x86A740

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5CC5C0

//PcClient
#define PcClient__PcClient_x                                       0x5B8BB0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446890
#define CCharacterSelect__EnterWorld_x                             0x446060
#define CCharacterSelect__Quit_x                                   0x444C40

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5972C0
#define EQ_Item__CreateItemTagString_x                             0x84B360
#define EQ_Item__IsStackable_x                                     0x840C00
#define EQ_Item__GetImageNum_x                                     0x8436B0
#define EQ_Item__CreateItemClient_x                                0x597EA0
#define EQ_Item__GetItemValue_x                                    0x84A0A0
#define EQ_Item__ValueSellMerchant_x                               0x84C660
#define EQ_Item__IsKeyRingItem_x                                   0x8416F0
#define EQ_Item__CanGoInBag_x                                      0x597450
#define EQ_Item__GetMaxItemCount_x                                 0x840AF0
#define EQ_Item__GetHeldItem_x                                     0x8424E0
#define EQ_Item__GetAugmentFitBySlot_x                             0x84C490

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D37D0
#define EQ_LoadingS__Array_x                                       0xBFCA78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C6A70
#define EQ_PC__GetAlternateAbilityId_x                             0x854A50
#define EQ_PC__GetCombatAbility_x                                  0x854AE0
#define EQ_PC__GetCombatAbilityTimer_x                             0x84F6C0
#define EQ_PC__GetItemRecastTimer_x                                0x5C0200
#define EQ_PC__HasLoreItem_x                                       0x5BA370
#define EQ_PC__AlertInventoryChanged_x                             0x5B6D30
#define EQ_PC__GetPcZoneClient_x                                   0x5E0AE0
#define EQ_PC__RemoveMyAffect_x                                    0x5BF6D0
#define EQ_PC__GetKeyRingItems_x                                   0x84FAE0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x862780
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8569F0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x51F000
#define EQItemList__add_object_x                                   0x54BF00
#define EQItemList__add_item_x                                     0x51EF40
#define EQItemList__delete_item_x                                  0x51F3F0
#define EQItemList__FreeItemList_x                                 0x51F2F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B2800

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CC360
#define EQPlayer__dEQPlayer_x                                      0x5D49B0
#define EQPlayer__DoAttack_x                                       0x5E6470
#define EQPlayer__EQPlayer_x                                       0x5D70D0
#define EQPlayer__SetNameSpriteState_x                             0x5D1870
#define EQPlayer__SetNameSpriteTint_x                              0x5CD780
#define PlayerBase__HasProperty_j_x                                0x927AE0
#define EQPlayer__IsTargetable_x                                   0x927D80
#define EQPlayer__CanSee_x                                         0x9282E0
#define PlayerZoneClient__ChangeHeight_x                           0x5E6330
#define EQPlayer__CanSee1_x                                        0x9283D0
#define PlayerBase__GetVisibilityLineSegment_x                     0x928070

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E0C90
#define PlayerZoneClient__IsValidTeleport_x                        0x54C7A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5DB130
#define EQPlayerManager__GetSpawnByName_x                          0x5DB590
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5DB160

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59D3C0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59D400
#define KeypressHandler__ClearCommandStateArray_x                  0x59CFB0
#define KeypressHandler__HandleKeyDown_x                           0x59B910
#define KeypressHandler__HandleKeyUp_x                             0x59BC30
#define KeypressHandler__SaveKeymapping_x                          0x59D080

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70B9C0
#define MapViewMap__SaveEx_x                                       0x70ECF0

#define PlayerPointManager__GetAltCurrency_x                       0x868800

// StringTable 
#define StringTable__getString_x                                   0x862AB0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C3FE0
#define PcZoneClient__RemovePetEffect_x                            0x5C06D0
#define PcZoneClient__HasAlternateAbility_x                        0x5C1070
#define PcZoneClient__GetCurrentMod_x                              0x45C5D0
#define PcZoneClient__GetModCap_x                                  0x459D00
#define PcZoneClient__CanEquipItem_x                               0x5C1590
#define PcZoneClient__GetItemByID_x                                0x5C5DE0
#define PcZoneClient__GetItemByItemClass_x                         0x5C6990

//Doors
#define EQSwitch__UseSwitch_x                                      0x553810

//IconCache
#define IconCache__GetIcon_x                                       0x6A83F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69F2C0
#define CContainerMgr__CloseContainer_x                            0x69FAE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76C8A0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5902F0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4ED840
#define EQ_Spell__SpellAffects_x                                   0x4EAED0
#define EQ_Spell__SpellAffectBase_x                           0x4EAF40
#define CharacterZoneClient__CalcAffectChange_x                    0x44B460
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A6A0
#define CLootWnd__LootAll_x                                        0x701220
#define CLootWnd__RequestLootSlot_x                                0x701A30
#define EQ_Spell__IsStackable_x                                    0x449140
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4491F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EDF0
#define EQ_Spell__IsSPAStacking_x                                  0x4EAA80
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4EA550
#define EQ_Spell__IsNoRemove_x                                     0x434F40
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4EAAA0

#define __IsResEffectSpell_x                                       0x449270

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8743D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B37A0
#define CTargetWnd__WndNotification_x                              0x7B3290
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B3980

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B8890

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E6500
#define EqSoundManager__PlayScriptMp3_x                            0x4E7FA0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A1970

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E2480
#define CSidlManager__FindAnimation1_x                             0x8D76F0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4DB020
#define CAltAbilityData__GetMercMaxRank_x                          0x4DAFD0
#define CAltAbilityData__GetMaxRank_x                              0x4CF8F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x58DBA0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x458CF0
#define CharacterBase__CreateItemGlobalIndex_x                     0x475710
#define CharacterBase__CreateItemIndex_x                           0x518580
#define CharacterBase__GetItemPossession_x                         0x444140
#define CharacterBase__GetItemByGlobalIndex_x                      0x878220
#define CharacterBase__GetEffectId_x                               0x458CB0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6880B0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x687810

//messages
#define msg_spell_worn_off_x                                       0x4F53F0
#define msg_new_text_x                                             0x4FEA40
#define msgTokenTextParam_x                                        0x4FB280

//SpellManager
#define SpellManager__vftable_x                                    0xABC168
#define SpellManager__SpellManager_x                               0x47E3D0
#define Spellmanager__LoadTextSpells_x          0x604A50

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x92BDF0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F19D0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43ED20
#define ItemGlobalIndex__IsEquippedLocation_x                      0x448EF0
#define ItemGlobalIndex__IsValidIndex_x                            0x4585B0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x876090
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x874FD0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6FA090

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6A4010
#define CCursorAttachment__Deactivate_x                            0x6A3550

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8F3790
