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
#define __ExpectedVersionDate                                     "Feb 13 2017"
#define __ExpectedVersionTime                                     "09:44:47"
#define __ActualVersionDate_x                                      0xAC7A28
#define __ActualVersionTime_x                                      0xAC7A34

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5982E0
#define __MemChecker1_x                                            0x88CE90
#define __MemChecker2_x                                            0x62DF60
#define __MemChecker3_x                                            0x62DEB0
#define __MemChecker4_x                                            0x7E0720
#define __EncryptPad0_x                                            0xC1F5E0
#define __EncryptPad1_x                                            0xCFAE78
#define __EncryptPad2_x                                            0xC48C40
#define __EncryptPad3_x                                            0xC48840
#define __EncryptPad4_x                                            0xCE94A0
#define __EncryptPad5_x                                            0x10A36E8
#define __AC1_x                                                    0x79FB35
#define __AC2_x                                                    0x5524B7
#define __AC3_x                                                    0x550650
#define __AC4_x                                                    0x562A10
#define __AC5_x                                                    0x57575B
#define __AC6_x                                                    0x57930E
#define __AC7_x                                                    0x56FDCC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FEB3E0

// Direct Input
#define DI8__Main_x                                                0x10A36C0
#define DI8__Keyboard_x                                            0x10A36C4
#define DI8__Mouse_x                                               0x10A36C8
#define DI8__Mouse_Copy_x                                          0xF11DA4
#define DI8__Mouse_Check_x                                         0xF9B5AC
#define __Attack_x                                                 0xF96293
#define __Autofire_x                                               0xF96294
#define __BindList_x                                               0xBFA400
#define g_eqCommandStates_x                                        0xF00DD0
#define __Clicks_x                                                 0xF11E60
#define __CommandList_x                                            0xBFCA60
#define __CurrentMapLabel_x                                        0x10A9148
#define __CurrentSocial_x                                          0xBCD334
#define __DoAbilityList_x                                          0xF48548
#define __do_loot_x                                                0x521100
#define __DrawHandler_x                                            0x1710074
#define __GroupCount_x                                             0xF023FA

#define __Guilds_x                                                 0xF08010
#define __gWorld_x                                                 0xF048B4
#define __HotkeyPage_x                                             0xF8EF48
#define __HWnd_x                                                   0xF9B5C8
#define __InChatMode_x                                             0xF11D8C
#define __LastTell_x                                               0xF13C44
#define __LMouseHeldTime_x                                         0xF11ECC
#define __Mouse_x                                                  0x10A36CC
#define __MouseLook_x                                              0xF11E26
#define __MouseEventTime_x                                         0xF96A94
#define __gpbCommandEvent_x                                        0xF0497C
#define __NetStatusToggle_x                                        0xF11E29
#define __PCNames_x                                                0xF13260
#define __RangeAttackReady_x                                       0xF12F94
#define __RMouseHeldTime_x                                         0xF11EC8
#define __RunWalkState_x                                           0xF11D90
#define __ScreenMode_x                                             0xE50AC8
#define __ScreenX_x                                                0xF11D44
#define __ScreenY_x                                                0xF11D40
#define __ScreenXMax_x                                             0xF11D48
#define __ScreenYMax_x                                             0xF11D4C
#define __ServerHost_x                                             0xF02344
#define __ServerName_x                                             0xF48508
#define __ShiftKeyDown_x                                           0xF12420
#define __ShowNames_x                                              0xF13154
#define __Socials_x                                                0xF48608
#define __SubscriptionType_x                                       0x10D7184
#define __TargetAggroHolder_x                                      0x10AB390
#define __ZoneType_x                                               0xF12224
#define __GroupAggro_x                                             0x10AB3D0
#define __LoginName_x                                              0xF9A1A4
#define __Inviter_x                                                0xF96210
#define __AttackOnAssist_x                                         0xF13110
#define __UseTellWindows_x                                         0xF133F8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF049A0
#define instEQZoneInfo_x                                           0xF1201C
#define instKeypressHandler_x                                      0xF96A78
#define pinstActiveBanker_x                                        0xF04958
#define pinstActiveCorpse_x                                        0xF0495C
#define pinstActiveGMaster_x                                       0xF04960
#define pinstActiveMerchant_x                                      0xF04954
#define pinstAggroInfo_x                                           0xD0E528
#define pinstAltAdvManager_x                                       0xE51B98
#define pinstAuraMgr_x                                             0xD1EC98
#define pinstBandageTarget_x                                       0xF04940
#define pinstCamActor_x                                            0xE514E8
#define pinstCDBStr_x                                              0xE50A5C
#define pinstCDisplay_x                                            0xF04968
#define pinstCEverQuest_x                                          0x10A3840
#define pinstEverQuestInfo_x                                       0xF11D38
#define pinstCharData_x                                            0xF04924
#define pinstCharSpawn_x                                           0xF0494C
#define pinstControlledMissile_x                                   0xF04920
#define pinstControlledPlayer_x                                    0xF0494C
#define pinstCSidlManager_x                                        0x170F464
#define pinstCXWndManager_x                                        0x170F45C
#define instDynamicZone_x                                          0xF11BD8
#define pinstDZMember_x                                            0xF11CE8
#define pinstDZTimerInfo_x                                         0xF11CEC
#define pinstEQItemList_x                                          0xF01020
#define pinstEQObjectList_x                                        0xF01DF4
#define instEQMisc_x                                               0xBE2B18
#define pinstEQSoundManager_x                                      0xE52168
#define instExpeditionLeader_x                                     0xF11C22
#define instExpeditionName_x                                       0xF11C62
#define pinstGroup_x                                               0xF023F6
#define pinstImeManager_x                                          0x170F468
#define pinstLocalPlayer_x                                         0xF04938
#define pinstMercenaryData_x                                       0xF970F8
#define pinstMercenaryStats_x                                      0x10AB4DC
#define pinstMercAltAbilities_x                                    0xE51F20
#define pinstModelPlayer_x                                         0xF04964
#define pinstPCData_x                                              0xF04924
#define pinstSkillMgr_x                                            0xF97F60
#define pinstSpawnManager_x                                        0xF97848
#define pinstSpellManager_x                                        0xF980A8
#define pinstSpellSets_x                                           0xF8EFAC
#define pinstStringTable_x                                         0xF048CC
#define pinstSwitchManager_x                                       0xF01F88
#define pinstTarget_x                                              0xF04950
#define pinstTargetObject_x                                        0xF04928
#define pinstTargetSwitch_x                                        0xF0492C
#define pinstTaskMember_x                                          0xE509A8
#define pinstTrackTarget_x                                         0xF04944
#define pinstTradeTarget_x                                         0xF04934
#define instTributeActive_x                                        0xBE2B3D
#define pinstViewActor_x                                           0xE514E4
#define pinstWorldData_x                                           0xF04908
#define pinstZoneAddr_x                                            0xF122BC
#define pinstPlayerPath_x                                          0xF978A8
#define pinstTargetIndicator_x                                     0xF98240
#define pinstCTargetManager_x                                      0xF982A0
#define EQObject_Top_x                                             0xF04918
#define pinstRealEstateItems_x                                     0xF97E4C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE51400
#define pinstCAchievementsWnd_x                                    0xE5145C
#define pinstCTextOverlay_x                                        0xD0EA20
#define pinstCAudioTriggersWindow_x                                0xD0E8B0
#define pinstCCharacterSelect_x                                    0xE51374
#define pinstCFacePick_x                                           0xE51124
#define pinstCNoteWnd_x                                            0xE5132C
#define pinstCBookWnd_x                                            0xE51334
#define pinstCPetInfoWnd_x                                         0xE51338
#define pinstCTrainWnd_x                                           0xE5133C
#define pinstCSkillsWnd_x                                          0xE51340
#define pinstCSkillsSelectWnd_x                                    0xE51344
#define pinstCCombatSkillsSelectWnd_x                              0xE51348
#define pinstCFriendsWnd_x                                         0xE5134C
#define pinstCAuraWnd_x                                            0xE51350
#define pinstCRespawnWnd_x                                         0xE51354
#define pinstCBandolierWnd_x                                       0xE51358
#define pinstCPotionBeltWnd_x                                      0xE5135C
#define pinstCAAWnd_x                                              0xE51360
#define pinstCAlarmWnd_x                                           0xE5136C
#define pinstCGroupSearchFiltersWnd_x                              0xE51364
#define pinstCLoadskinWnd_x                                        0xE51368
#define pinstCLargeDialogWnd_x                                     0x10AA3C8
#define pinstCMusicPlayerWnd_x                                     0xE51370
#define pinstCMailWnd_x                                            0xE51378
#define pinstCMailCompositionWnd_x                                 0xE5137C
#define pinstCMailAddressBookWnd_x                                 0xE51380
#define pinstCRaidWnd_x                                            0xE51388
#define pinstCRaidOptionsWnd_x                                     0xE5138C
#define pinstCBreathWnd_x                                          0xE51390
#define pinstCMapViewWnd_x                                         0xE51394
#define pinstCMapToolbarWnd_x                                      0xE51398
#define pinstCEditLabelWnd_x                                       0xE5139C
#define pinstCTargetWnd_x                                          0xE513A0
#define pinstCColorPickerWnd_x                                     0xE513A4
#define pinstCPlayerWnd_x                                          0xE513A8
#define pinstCOptionsWnd_x                                         0xE513AC
#define pinstCBuffWindowNORMAL_x                                   0xE513B0
#define pinstCBuffWindowSHORT_x                                    0xE513B4
#define pinstCharacterCreation_x                                   0xE513B8
#define pinstCCursorAttachment_x                                   0xE513BC
#define pinstCCastingWnd_x                                         0xE513C0
#define pinstCCastSpellWnd_x                                       0xE513C4
#define pinstCSpellBookWnd_x                                       0xE513C8
#define pinstCInventoryWnd_x                                       0xE513CC
#define pinstCBankWnd_x                                            0xE513D4
#define pinstCQuantityWnd_x                                        0xE513D8
#define pinstCLootWnd_x                                            0xE513DC
#define pinstCActionsWnd_x                                         0xE513E0
#define pinstCCombatAbilityWnd_x                                   0xE513E8
#define pinstCMerchantWnd_x                                        0xE513EC
#define pinstCTradeWnd_x                                           0xE513F0
#define pinstCSelectorWnd_x                                        0xE513F4
#define pinstCBazaarWnd_x                                          0xE513F8
#define pinstCBazaarSearchWnd_x                                    0xE513FC
#define pinstCGiveWnd_x                                            0xE51418
#define pinstCTrackingWnd_x                                        0xE51420
#define pinstCInspectWnd_x                                         0xE51424
#define pinstCSocialEditWnd_x                                      0xE51428
#define pinstCFeedbackWnd_x                                        0xE5142C
#define pinstCBugReportWnd_x                                       0xE51430
#define pinstCVideoModesWnd_x                                      0xE51434
#define pinstCTextEntryWnd_x                                       0xE5143C
#define pinstCFileSelectionWnd_x                                   0xE51440
#define pinstCCompassWnd_x                                         0xE51444
#define pinstCPlayerNotesWnd_x                                     0xE51448
#define pinstCGemsGameWnd_x                                        0xE5144C
#define pinstCTimeLeftWnd_x                                        0xE51450
#define pinstCPetitionQWnd_x                                       0xE5146C
#define pinstCSoulmarkWnd_x                                        0xE51470
#define pinstCStoryWnd_x                                           0xE51474
#define pinstCJournalTextWnd_x                                     0xE51478
#define pinstCJournalCatWnd_x                                      0xE5147C
#define pinstCBodyTintWnd_x                                        0xE51480
#define pinstCServerListWnd_x                                      0xE51484
#define pinstCAvaZoneWnd_x                                         0xE51490
#define pinstCBlockedBuffWnd_x                                     0xE51494
#define pinstCBlockedPetBuffWnd_x                                  0xE51498
#define pinstCInvSlotMgr_x                                         0xE514DC
#define pinstCContainerMgr_x                                       0xE514E0
#define pinstCAdventureLeaderboardWnd_x                            0x10A41F0
#define pinstCAdventureRequestWnd_x                                0x10A4268
#define pinstCAltStorageWnd_x                                      0x10A4548
#define pinstCAdventureStatsWnd_x                                  0x10A42E0
#define pinstCBarterMerchantWnd_x                                  0x10A5130
#define pinstCBarterSearchWnd_x                                    0x10A51A8
#define pinstCBarterWnd_x                                          0x10A5220
#define pinstCChatWindowManager_x                                  0x10A58B0
#define pinstCDynamicZoneWnd_x                                     0x10A5D60
#define pinstCEQMainWnd_x                                          0x10A5EF8
#define pinstCFellowshipWnd_x                                      0x10A5CF4
#define pinstCFindLocationWnd_x                                    0x10A61C8
#define pinstCGroupSearchWnd_x                                     0x10A6498
#define pinstCGroupWnd_x                                           0x10A6510
#define pinstCGuildBankWnd_x                                       0x10A6588
#define pinstCGuildMgmtWnd_x                                       0x10A8678
#define pinstCHotButtonWnd_x                                       0x10A8774
#define pinstCHotButtonWnd1_x                                      0x10A8774
#define pinstCHotButtonWnd2_x                                      0x10A8778
#define pinstCHotButtonWnd3_x                                      0x10A877C
#define pinstCHotButtonWnd4_x                                      0x10A87A0
#define pinstCItemDisplayManager_x                                 0x10A8A98
#define pinstCItemExpTransferWnd_x                                 0x10A8B14
#define pinstCLFGuildWnd_x                                         0x10A8DF0
#define pinstCMIZoneSelectWnd_x                                    0x10A93D8
#define pinstCConfirmationDialog_x                                 0x10A9AE0
#define pinstCPopupWndManager_x                                    0x10A9AE0
#define pinstCProgressionSelectionWnd_x                            0x10A9BD0
#define pinstCPvPStatsWnd_x                                        0x10A9CC0
#define pinstCTaskWnd_x                                            0x10AB7C0
#define pinstCTaskSomething_x                                      0xD1F550
#define pinstCTaskTemplateSelectWnd_x                              0x10AB748
#define pinstCTipWndOFDAY_x                                        0x10AB928
#define pinstCTipWndCONTEXT_x                                      0x10AB92C
#define pinstCTitleWnd_x                                           0x10AB9A8
#define pinstCContextMenuManager_x                                 0x170F3D4
#define pinstCVoiceMacroWnd_x                                      0xF98678
#define pinstCHtmlWnd_x                                            0xF98768
#define pinstIconCache_x                                           0x10A5ECC
#define pinstCTradeskillWnd_x                                      0x10ABAA8
#define pinstCAdvancedLootWnd_x                                    0xE514D0
#define pinstRewardSelectionWnd_x                                  0x10AA1E8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5383A0
#define __ConvertItemTags_x                                        0x525C00
#define __ExecuteCmd_x                                             0x510570
#define __EQGetTime_x                                              0x88CB20
#define __get_melee_range_x                                        0x517160
#define __GetGaugeValueFromEQ_x                                    0x79E870
#define __GetLabelFromEQ_x                                         0x79FAC0
#define __ToggleKeyRingItem_x                                      0x4802D0
#define __GetXTargetType_x                                         0x91D590
#define __LoadFrontEnd_x                                           0x62D630
#define __NewUIINI_x                                               0x79E240
#define __ProcessGameEvents_x                                      0x571B60
#define __ProcessMouseEvent_x                                      0x571300
#define CrashDetected_x                                            0x62EFF0
#define wwsCrashReportCheckForUploader_x                           0x7EC230
#define __AppCrashWrapper_x                                        0xC48834
#define __pCrashHandler_x                                          0x10B8958
#define __CrashHandler_x                                           0x7EBCC0
#define wwsCrashReportPlatformLaunchUploader_x                     0x7EE460
#define DrawNetStatus_x                                            0x5A7E80
#define Util__FastTime_x                                           0x88C7C0
#define Expansion_HoT_x                                            0xF13100
#define __HelpPath_x                                               0xF96800
#define __STMLToText_x                                             0x8D2A50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4204D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B280
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B060

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C75F0
#define AltAdvManager__IsAbilityReady_x                            0x4C7660
#define AltAdvManager__GetAAById_x                                 0x4C7B50
#define AltAdvManager__CanTrainAbility_x                           0x4C8780
#define AltAdvManager__CanSeeAbility_x                             0x4C8340

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463930
#define CharacterZoneClient__MakeMeVisible_x                       0x468340
#define CharacterZoneClient__IsStackBlocked_x                      0x447D30
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4471F0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4616C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4617A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x461880
#define CharacterZoneClient__FindAffectSlot_x                      0x44D250

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65CD50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66B010

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x587290
#define CButtonWnd__CButtonWnd_x                                   0x8C6CF0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x686150
#define CChatManager__InitContextMenu_x                            0x686CD0
#define CChatManager__FreeChatWindow_x                             0x685C30
#define CChatManager__GetLockedActiveChatWindow_x                  0x68B480
#define CChatManager__SetLockedActiveChatWindow_x                  0x686120

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D0DA0
#define CContextMenu__dCContextMenu_x                              0x8D0FB0
#define CContextMenu__AddMenuItem_x                                0x8D0FC0
#define CContextMenu__RemoveMenuItem_x                             0x8D12B0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D12D0
#define CContextMenu__CheckMenuItem_x                              0x8D1350

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8BD240
#define CContextMenuManager__RemoveMenu_x                          0x8BD5E0
#define CContextMenuManager__PopupMenu_x                           0x8BDA30
#define CContextMenuManager__Flush_x                               0x8BD2B0
#define CContextMenuManager__GetMenu_x                             0x416970

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x870FD0
#define CChatService__GetFriendName_x                              0x870FE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68BFC0
#define CChatWindow__Clear_x                                       0x68BBA0
#define CChatWindow__WndNotification_x                             0x68C4F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C10A0
#define CComboWnd__Draw_x                                          0x8C12B0
#define CComboWnd__GetCurChoice_x                                  0x8C0E50
#define CComboWnd__GetListRect_x                                   0x8C1550
#define CComboWnd__GetTextRect_x                                   0x8C1110
#define CComboWnd__InsertChoice_x                                  0x8C15C0
#define CComboWnd__SetColors_x                                     0x8C0DE0
#define CComboWnd__SetChoice_x                                     0x8C0E10
#define CComboWnd__GetItemCount_x                                  0x8C0E40
#define CComboWnd__GetCurChoiceText_x                              0x8C0E90


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6956F0
#define CContainerWnd__vftable_x                                   0xAD14F0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B5B50
#define CDisplay__GetClickedActor_x                                0x4AE490
#define CDisplay__GetUserDefinedColor_x                            0x4AD070
#define CDisplay__GetWorldFilePath_x                               0x4AC4C0
#define CDisplay__is3dON_x                                         0x4AB950
#define CDisplay__ReloadUI_x                                       0x4C10C0
#define CDisplay__WriteTextHD2_x                                   0x4B1F10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E7500

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D52E0
#define CEditWnd__GetCharIndexPt_x                                 0x8D6370
#define CEditWnd__GetDisplayString_x                               0x8D5490
#define CEditWnd__GetHorzOffset_x                                  0x8D57D0
#define CEditWnd__GetLineForPrintableChar_x                        0x8D5E40
#define CEditWnd__GetSelStartPt_x                                  0x8D6620
#define CEditWnd__GetSTMLSafeText_x                                0x8D5970
#define CEditWnd__PointFromPrintableChar_x                         0x8D5F30
#define CEditWnd__SelectableCharFromPoint_x                        0x8D60B0
#define CEditWnd__SetEditable_x                                    0x8D5940

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x559240
#define CEverQuest__ClickedPlayer_x                                0x552C00
#define CEverQuest__CreateTargetIndicator_x                        0x553AF0
#define CEverQuest__DeleteTargetIndicator_x                        0x553B70
#define CEverQuest__DoTellWindow_x                                 0x472F90
#define CEverQuest__OutputTextToLog_x                              0x472BF0
#define CEverQuest__DropHeldItemOnGround_x                         0x569860
#define CEverQuest__dsp_chat_x                                     0x4732D0
#define CEverQuest__trimName_x                                     0x54F550
#define CEverQuest__Emote_x                                        0x567BB0
#define CEverQuest__EnterZone_x                                    0x562BA0
#define CEverQuest__GetBodyTypeDesc_x                              0x54CFB0
#define CEverQuest__GetClassDesc_x                                 0x556380
#define CEverQuest__GetClassThreeLetterCode_x                      0x556980
#define CEverQuest__GetDeityDesc_x                                 0x54D890
#define CEverQuest__GetLangDesc_x                                  0x54D340
#define CEverQuest__GetRaceDesc_x                                  0x556B40
#define CEverQuest__InterpretCmd_x                                 0x55A9C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x56E220
#define CEverQuest__LMouseUp_x                                     0x570320
#define CEverQuest__RightClickedOnPlayer_x                         0x56ED30
#define CEverQuest__RMouseUp_x                                     0x56FD80
#define CEverQuest__SetGameState_x                                 0x5534C0
#define CEverQuest__UPCNotificationFlush_x                         0x54ADC0
#define CEverQuest__IssuePetCommand_x                              0x55B3A0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A6590
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A65F0
#define CGaugeWnd__Draw_x                                          0x6A6A20

// CGuild
#define CGuild__FindMemberByName_x                                 0x437500
#define CGuild__GetGuildName_x                                     0x4379D0
#define CGuild__GetGuildIndex_x                                    0x438BA0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C2B20

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CFC90
#define CInvSlotMgr__MoveItem_x                                    0x6D0B40
#define CInvSlotMgr__SelectSlot_x                                  0x6CFD40

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CF140
#define CInvSlot__SliderComplete_x                                 0x6CC950
#define CInvSlot__GetItemBase_x                                    0x6CBDE0
#define CInvSlot__UpdateItem_x                                     0x6CC360

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D1FA0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6D30C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79A270
#define CItemDisplayWnd__UpdateStrings_x                           0x6D40E0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6E0B30
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6E1070
#define CItemDisplayWnd__SetItem_x                                 0x6E6B20

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7D15B0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6DA680

// CLabel 
#define CLabel__Draw_x                                             0x6ED860

// CListWnd
#define CListWnd__CListWnd_x                                       0x8ACCE0
#define CListWnd__dCListWnd_x                                      0x8ADF00
#define CListWnd__AddColumn_x                                      0x8ADEA0
#define CListWnd__AddColumn1_x                                     0x8AD540
#define CListWnd__AddLine_x                                        0x8ACFA0
#define CListWnd__AddString_x                                      0x8AD1C0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A9F80
#define CListWnd__CalculateVSBRange_x                              0x8AC1B0
#define CListWnd__ClearSel_x                                       0x8A9290
#define CListWnd__ClearAllSel_x                                    0x8A9240
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8ACB70
#define CListWnd__Compare_x                                        0x8AAAE0
#define CListWnd__Draw_x                                           0x8ABDB0
#define CListWnd__DrawColumnSeparators_x                           0x8ABC40
#define CListWnd__DrawHeader_x                                     0x8A9550
#define CListWnd__DrawItem_x                                       0x8AB170
#define CListWnd__DrawLine_x                                       0x8AB8E0
#define CListWnd__DrawSeparator_x                                  0x8ABCE0
#define CListWnd__EnableLine_x                                     0x8A9470
#define CListWnd__EnsureVisible_x                                  0x8AA0E0
#define CListWnd__ExtendSel_x                                      0x8AB080
#define CListWnd__GetColumnMinWidth_x                              0x8A8C40
#define CListWnd__GetColumnWidth_x                                 0x8A8B70
#define CListWnd__GetCurSel_x                                      0x8A8350
#define CListWnd__GetItemAtPoint_x                                 0x8AA370
#define CListWnd__GetItemAtPoint1_x                                0x8AA3E0
#define CListWnd__GetItemData_x                                    0x8A8690
#define CListWnd__GetItemHeight_x                                  0x8A9BD0
#define CListWnd__GetItemIcon_x                                    0x8A8880
#define CListWnd__GetItemRect_x                                    0x8AA1B0
#define CListWnd__GetItemText_x                                    0x8A8730
#define CListWnd__GetSelList_x                                     0x8AD430
#define CListWnd__GetSeparatorRect_x                               0x8AAA00
#define CListWnd__InsertLine_x                                     0x8AD3A0
#define CListWnd__RemoveLine_x                                     0x8AD3B0
#define CListWnd__SetColors_x                                      0x8A84A0
#define CListWnd__SetColumnJustification_x                         0x8A8ED0
#define CListWnd__SetColumnWidth_x                                 0x8A8BF0
#define CListWnd__SetCurSel_x                                      0x8A8390
#define CListWnd__SetItemColor_x                                   0x8AC860
#define CListWnd__SetItemData_x                                    0x8A92F0
#define CListWnd__SetItemText_x                                    0x8AC6A0
#define CListWnd__ShiftColumnSeparator_x                           0x8AC530
#define CListWnd__Sort_x                                           0x8AE000
#define CListWnd__ToggleSel_x                                      0x8A91C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x706A00

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x727E10
#define CMerchantWnd__RequestBuyItem_x                             0x72EEB0
#define CMerchantWnd__RequestSellItem_x                            0x72F980
#define CMerchantWnd__SelectRecoverySlot_x                         0x7280C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7272C0
#define CMerchantWnd__ActualSelect_x                               0x72BD80

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x83FC90
#define CPacketScrambler__hton_x                                   0x83FCA0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8CBCC0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CBDA0
#define CSidlManager__CreateLabel_x                                0x7901A0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8CA260
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8CC080

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x654110
#define CSidlScreenWnd__CalculateVSBRange_x                        0x654040
#define CSidlScreenWnd__ConvertToRes_x                             0x8E73E0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C3A60
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C4C30
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C4CE0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C41C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C3410
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C2B70
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C3600
#define CSidlScreenWnd__Init1_x                                    0x8C4910
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C3B10
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C2D30
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C4400
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C27C0
#define CSidlScreenWnd__StoreIniVis_x                              0x8C2B20
#define CSidlScreenWnd__WndNotification_x                          0x8C4690
#define CSidlScreenWnd__GetChildItem_x                             0x8C2C40
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B6400
#define CSidlScreenWnd__m_layoutCopy_x                             0x170F438

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F2ED0
#define CSkillMgr__GetSkillCap_x                                   0x5F30B0
#define CSkillMgr__GetNameToken_x                                  0x5F2AF0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E6680
#define CSliderWnd__SetValue_x                                     0x8E6850
#define CSliderWnd__SetNumTicks_x                                  0x8E6FD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x797EB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E1FC0
#define CStmlWnd__CalculateHSBRange_x                              0x8DA590
#define CStmlWnd__CalculateVSBRange_x                              0x8DA510
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DA710
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DAFF0
#define CStmlWnd__ForceParseNow_x                                  0x8E2980
#define CStmlWnd__GetNextTagPiece_x                                0x8DAEF0
#define CStmlWnd__GetSTMLText_x                                    0x68B440
#define CStmlWnd__GetVisibleText_x                                 0x8DBA40
#define CStmlWnd__InitializeWindowVariables_x                      0x8DDDC0
#define CStmlWnd__MakeStmlColorTag_x                               0x8D9810
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D9870
#define CStmlWnd__SetSTMLText_x                                    0x8DF610
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E1C60
#define CStmlWnd__UpdateHistoryString_x                            0x8DC980

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8D8E90
#define CTabWnd__DrawCurrentPage_x                                 0x8D8720
#define CTabWnd__DrawTab_x                                         0x8D84E0
#define CTabWnd__GetCurrentPage_x                                  0x8D8AD0
#define CTabWnd__GetPageInnerRect_x                                0x8D81D0
#define CTabWnd__GetTabInnerRect_x                                 0x8D83D0
#define CTabWnd__GetTabRect_x                                      0x8D82A0
#define CTabWnd__InsertPage_x                                      0x8D9180
#define CTabWnd__SetPage_x                                         0x8D8B00
#define CTabWnd__SetPageRect_x                                     0x8D8DD0
#define CTabWnd__UpdatePage_x                                      0x8D9120
#define CTabWnd__GetPageFromTabIndex_x                             0x8D8430
#define CTabWnd__GetCurrentTabIndex_x                              0x8D8160

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6D3270
#define CPageWnd__SetTabText_x                                     0x8F03F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x433120

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C0A50
#define CTextureFont__GetTextExtent_x                              0x8C07B0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x62B8D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EC830

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A6600

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029B0
#define CXStr__CXStr1_x                                            0x8EB5A0
#define CXStr__CXStr3_x                                            0x889A60
#define CXStr__dCXStr_x                                            0x7CD2D0
#define CXStr__operator_equal_x                                    0x889BD0
#define CXStr__operator_equal1_x                                   0x889C20
#define CXStr__operator_plus_equal1_x                              0x88AD20

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B55E0
#define CXWnd__Center_x                                            0x8BB820
#define CXWnd__ClrFocus_x                                          0x8B51A0
#define CXWnd__Destroy_x                                           0x8BC300
#define CXWnd__DoAllDrawing_x                                      0x8BB470
#define CXWnd__DrawChildren_x                                      0x8BB610
#define CXWnd__DrawColoredRect_x                                   0x8B59B0
#define CXWnd__DrawTooltip_x                                       0x8B5C50
#define CXWnd__DrawTooltipAtPoint_x                                0x8BA410
#define CXWnd__GetBorderFrame_x                                    0x8B60C0
#define CXWnd__GetChildWndAt_x                                     0x8BC1E0
#define CXWnd__GetClientClipRect_x                                 0x8B5E70
#define CXWnd__GetScreenClipRect_x                                 0x8BAB10
#define CXWnd__GetScreenRect_x                                     0x8B6290
#define CXWnd__GetTooltipRect_x                                    0x8B5AE0
#define CXWnd__GetWindowTextA_x                                    0x424650
#define CXWnd__IsActive_x                                          0x8B0CB0
#define CXWnd__IsDescendantOf_x                                    0x8B6000
#define CXWnd__IsReallyVisible_x                                   0x8B9440
#define CXWnd__IsType_x                                            0x8E9040
#define CXWnd__Move_x                                              0x8B8B10
#define CXWnd__Move1_x                                             0x8BB110
#define CXWnd__ProcessTransition_x                                 0x8B5580
#define CXWnd__Refade_x                                            0x8B5350
#define CXWnd__Resize_x                                            0x8B6360
#define CXWnd__Right_x                                             0x8BA910
#define CXWnd__SetFocus_x                                          0x8B7C40
#define CXWnd__SetFont_x                                           0x8B51F0
#define CXWnd__SetKeyTooltip_x                                     0x8B65D0
#define CXWnd__SetMouseOver_x                                      0x8BAE00
#define CXWnd__StartFade_x                                         0x8B5630
#define CXWnd__GetChildItem_x                                      0x8BAD50
#define CXWnd__SetParent_x                                         0x8BC190

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B2520
#define CXWndManager__DrawWindows_x                                0x8B2160
#define CXWndManager__GetKeyboardFlags_x                           0x8B07E0
#define CXWndManager__HandleKeyboardMsg_x                          0x8B1140
#define CXWndManager__RemoveWnd_x                                  0x8B0E40

// CDBStr
#define CDBStr__GetString_x                                        0x4A9E80

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E2C0
#define EQ_Character__Cur_HP_x                                     0x462F30
#define EQ_Character__Cur_Mana_x                                   0x456A10
#define EQ_Character__GetAACastingTimeModifier_x                   0x447500
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F7A0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F800
#define EQ_Character__GetHPRegen_x                                 0x466140
#define EQ_Character__GetEnduranceRegen_x                          0x462350
#define EQ_Character__GetManaRegen_x                               0x4666E0
#define EQ_Character__Max_Endurance_x                              0x5B9F10
#define EQ_Character__Max_HP_x                                     0x459690
#define EQ_Character__Max_Mana_x                                   0x5B9D40
#define EQ_Character__doCombatAbility_x                            0x5B7430
#define EQ_Character__UseSkill_x                                   0x46D3C0
#define EQ_Character__GetConLevel_x                                0x5AC460
#define EQ_Character__IsExpansionFlag_x                            0x423B90
#define EQ_Character__TotalEffect_x                                0x44B560
#define EQ_Character__GetPCSpellAffect_x                           0x447900
#define EQ_Character__SpellDuration_x                              0x445800
#define EQ_Character__FindItemByRecord_x                           0x4603B0
#define EQ_Character__GetAdjustedSkill_x                           0x4636E0
#define EQ_Character__GetBaseSkill_x                               0x459570

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x85CA80

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5C1BB0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442B30
#define CCharacterSelect__EnterWorld_x                             0x442300
#define CCharacterSelect__Quit_x                                   0x440EE0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58CB00
#define EQ_Item__CreateItemTagString_x                             0x83E650
#define EQ_Item__IsStackable_x                                     0x834090
#define EQ_Item__GetImageNum_x                                     0x836B60
#define EQ_Item__CreateItemClient_x                                0x58D6E0
#define EQ_Item__GetItemValue_x                                    0x83D3B0
#define EQ_Item__ValueSellMerchant_x                               0x83F8F0
#define EQ_Item__IsKeyRingItem_x                                   0x834B70
#define EQ_Item__CanGoInBag_x                                      0x58CC90
#define EQ_Item__GetMaxItemCount_x                                 0x833F80
#define EQ_Item__GetHeldItem_x                                     0x835960
#define EQ_Item__GetAugmentFitBySlot_x                             0x83F710

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C9B90
#define EQ_LoadingS__Array_x                                       0xBEAEB0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BC2B0
#define EQ_PC__GetAlternateAbilityId_x                             0x847D10
#define EQ_PC__GetCombatAbility_x                                  0x847DA0
#define EQ_PC__GetCombatAbilityTimer_x                             0x842AA0
#define EQ_PC__GetItemRecastTimer_x                                0x5B5AE0
#define EQ_PC__HasLoreItem_x                                       0x5AFA70
#define EQ_PC__AlertInventoryChanged_x                             0x5AC430
#define EQ_PC__GetPcZoneClient_x                                   0x5D6040
#define EQ_PC__RemoveMyAffect_x                                    0x5B4FB0
#define EQ_PC__GetKeyRingItems_x                                   0x842EC0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x855460
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x849C60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5151F0
#define EQItemList__add_object_x                                   0x541D10
#define EQItemList__add_item_x                                     0x515130
#define EQItemList__delete_item_x                                  0x5155E0
#define EQItemList__FreeItemList_x                                 0x5154E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A90B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C1950
#define EQPlayer__dEQPlayer_x                                      0x5C9F10
#define EQPlayer__DoAttack_x                                       0x5DBF40
#define EQPlayer__EQPlayer_x                                       0x5CC620
#define EQPlayer__SetNameSpriteState_x                             0x5C6E60
#define EQPlayer__SetNameSpriteTint_x                              0x5C2D60
#define PlayerBase__HasProperty_j_x                                0x919DB0
#define EQPlayer__IsTargetable_x                                   0x91A050
#define EQPlayer__CanSee_x                                         0x91A5B0
#define PlayerZoneClient__ChangeHeight_x                           0x5DBE00
#define EQPlayer__CanSeeTargetIndicator_x                          0x91A6A0
#define PlayerBase__GetVisibilityLineSegment_x                     0x91A340

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D0690
#define EQPlayerManager__GetSpawnByName_x                          0x5D0AF0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D06C0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x592B90
#define KeypressHandler__AttachKeyToEqCommand_x                    0x592BD0
#define KeypressHandler__ClearCommandStateArray_x                  0x592780
#define KeypressHandler__HandleKeyDown_x                           0x5910E0
#define KeypressHandler__HandleKeyUp_x                             0x591400
#define KeypressHandler__SaveKeymapping_x                          0x592850

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FF390
#define MapViewMap__SaveEx_x                                       0x7026C0

#define PlayerPointManager__GetAltCurrency_x                       0x85ABA0

// StringTable 
#define StringTable__getString_x                                   0x855790

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B99A0
#define PcZoneClient__RemovePetEffect_x                            0x5B5FB0
#define PcZoneClient__HasAlternateAbility_x                        0x5B6950
#define PcZoneClient__GetCurrentMod_x                              0x458A30
#define PcZoneClient__GetModCap_x                                  0x456190
#define PcZoneClient__CanEquipItem_x                               0x5B6F00
#define PcZoneClient__GetItemByID_x                                0x5BB790
#define PcZoneClient__GetItemByItemClass_x                         0x5BC1D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x549630

//IconCache
#define IconCache__GetIcon_x                                       0x69BD10

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x692A70
#define CContainerMgr__CloseContainer_x                            0x693290

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x760140

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x585D00

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E3DC0
#define EQ_Spell__SpellAffects_x                                   0x4E1470
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E14E0
#define CharacterZoneClient__CalcAffectChange_x                    0x446930
#define CLootWnd__LootAll_x                                        0x6F4C60
#define CLootWnd__RequestLootSlot_x                                0x6F5470

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A7190
#define CTargetWnd__WndNotification_x                              0x7A6C80
#define CTargetWnd__RefreshTargetBuffs_x                           0x7A7370

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AC280

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DCA90

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498A60

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8D4910
#define CSidlManager__FindAnimation1_x                             0x8C9C90

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D1320
#define CAltAbilityData__GetMercMaxRank_x                          0x4D12D0
#define CAltAbilityData__GetMaxRank_x                              0x4C5CA0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5835C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x455170
#define CharacterBase__CreateItemGlobalIndex_x                     0x472190
#define CharacterBase__CreateItemIndex_x                           0x50E6A0
#define CharacterBase__GetItemPossession_x                         0x440370
#define CharacterBase__GetItemByGlobalIndex_x                      0x86ACB0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x67D270
#define CCastSpellWnd__IsBardSongPlaying_x                         0x67C9D0

//messages
#define msg_spell_worn_off_x                                       0x4EB9B0
#define msg_new_text_x                                             0x4F4E30
#define msgTokenTextParam_x                                        0x4F17E0

//SpellManager
#define SpellManager__vftable_x                                    0xAAE020
#define SpellManager__SpellManager_x                               0x47AEA0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5F9DC0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x91E0B0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E7F30
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AF20
#define ItemGlobalIndex__IsEquippedLocation_x                      0x445190
#define ItemGlobalIndex__IsValidIndex_x                            0x4549E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x868AC0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x867A00

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6EDAB0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x697910
#define CCursorAttachment__Deactivate_x                            0x696E50
