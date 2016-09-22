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
#elif defined(TEST)
#include "eqgame-private(test).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Sep 19 2016"
#define __ExpectedVersionTime                                     "10:53:08"
#define __ActualVersionDate_x                                      0xAD62E0
#define __ActualVersionTime_x                                      0xAD62EC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59EBF0
#define __MemChecker1_x                                            0x898160
#define __MemChecker2_x                                            0x635030
#define __MemChecker3_x                                            0x634F80
#define __MemChecker4_x                                            0x7E6D60
#define __EncryptPad0_x                                            0xC789F0
#define __EncryptPad1_x                                            0xE04C88
#define __EncryptPad2_x                                            0xCC1688
#define __EncryptPad3_x                                            0xCC1288
#define __EncryptPad4_x                                            0xDDA890
#define __EncryptPad5_x                                            0x11B5BE0
#define __AC1_x                                                    0x7A6D15
#define __AC2_x                                                    0x558B37
#define __AC3_x                                                    0x556CD0
#define __AC4_x                                                    0x5694E0
#define __AC5_x                                                    0x57C06B
#define __AC6_x                                                    0x57FC1E
#define __AC7_x                                                    0x57670C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EF21C

// Direct Input
#define DI8__Main_x                                                0x11B5BB8
#define DI8__Keyboard_x                                            0x11B5BBC
#define DI8__Mouse_x                                               0x11B5BC0
#define DI8__Mouse_Copy_x                                          0x10242A4
#define DI8__Mouse_Check_x                                         0x10ADAA4
#define __Attack_x                                                 0x10A8787
#define __Autofire_x                                               0x10A8788
#define __BindList_x                                               0xC3A4A8
#define g_eqCommandStates_x                                        0x1013708
#define __Clicks_x                                                 0x1024360
#define __CommandList_x                                            0xC3E890
#define __CurrentMapLabel_x                                        0x11BB640
#define __CurrentSocial_x                                          0xBEE0B8
#define __DoAbilityList_x                                          0x105AA3C
#define __do_loot_x                                                0x51E100
#define __DrawHandler_x                                            0x1822674
#define __GroupCount_x                                             0x1014CD2

#define __Guilds_x                                                 0x101A8E8
#define __gWorld_x                                                 0x101718C
#define __HotkeyPage_x                                             0x10A143C
#define __HWnd_x                                                   0x10ADAC0
#define __InChatMode_x                                             0x102428C
#define __LastTell_x                                               0x1026138
#define __LMouseHeldTime_x                                         0x10243CC
#define __Mouse_x                                                  0x11B5BC4
#define __MouseLook_x                                              0x1024326
#define __MouseEventTime_x                                         0x10A8F8C
#define __gpbCommandEvent_x                                        0x1017254
#define __NetStatusToggle_x                                        0x1024329
#define __PCNames_x                                                0x1025758
#define __RangeAttackReady_x                                       0x1025494
#define __RMouseHeldTime_x                                         0x10243C8
#define __RunWalkState_x                                           0x1024290
#define __ScreenMode_x                                             0xF63488
#define __ScreenX_x                                                0x1024244
#define __ScreenY_x                                                0x1024240
#define __ScreenXMax_x                                             0x1024248
#define __ScreenYMax_x                                             0x102424C
#define __ServerHost_x                                             0x1014C1C
#define __ServerName_x                                             0x105A9FC
#define __ShiftKeyDown_x                                           0x1024920
#define __ShowNames_x                                              0x1025654
#define __Socials_x                                                0x105AAFC
#define __SubscriptionType_x                                       0x11E976C
#define __TargetAggroHolder_x                                      0x11BD87C
#define __ZoneType_x                                               0x1024724
#define __GroupAggro_x                                             0x11BD8BC
#define __LoginName_x                                              0x10AC69C
#define __Inviter_x                                                0x10A8704
#define __AttackOnAssist_x                                         0x1025610
#define __UseTellWindows_x                                         0x10258F0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1017278
#define instEQZoneInfo_x                                           0x102451C
#define instKeypressHandler_x                                      0x10A8F70
#define pinstActiveBanker_x                                        0x1017230
#define pinstActiveCorpse_x                                        0x1017234
#define pinstActiveGMaster_x                                       0x1017238
#define pinstActiveMerchant_x                                      0x101722C
#define pinstAggroInfo_x                                           0xE20EE8
#define pinstAltAdvManager_x                                       0xF64548
#define pinstAuraMgr_x                                             0xE31658
#define pinstBandageTarget_x                                       0x1017218
#define pinstCamActor_x                                            0xF63E9C
#define pinstCDBStr_x                                              0xF6341C
#define pinstCDisplay_x                                            0x1017240
#define pinstCEverQuest_x                                          0x11B5D38
#define pinstCharData_x                                            0x10171FC
#define pinstCharSpawn_x                                           0x1017224
#define pinstControlledMissile_x                                   0x10171F8
#define pinstControlledPlayer_x                                    0x1017224
#define pinstCSidlManager_x                                        0x1821A64
#define pinstCXWndManager_x                                        0x1821A5C
#define instDynamicZone_x                                          0x10240D8
#define pinstDZMember_x                                            0x10241E8
#define pinstDZTimerInfo_x                                         0x10241EC
#define pinstEQItemList_x                                          0x1013958
#define pinstEQObjectList_x                                        0x10146CC
#define instEQMisc_x                                               0xC14C40
#define pinstEQSoundManager_x                                      0xF64AA0
#define instExpeditionLeader_x                                     0x1024122
#define instExpeditionName_x                                       0x1024162
#define pinstGroup_x                                               0x1014CCE
#define pinstImeManager_x                                          0x1821A68
#define pinstLocalPlayer_x                                         0x1017210
#define pinstMercenaryData_x                                       0x10A95F0
#define pinstMercenaryStats_x                                      0x11BD9C8
#define pinstMercAltAbilities_x                                    0xF648D0
#define pinstModelPlayer_x                                         0x101723C
#define pinstPCData_x                                              0x10171FC
#define pinstSkillMgr_x                                            0x10AA458
#define pinstSpawnManager_x                                        0x10A9D40
#define pinstSpellManager_x                                        0x10AA5A0
#define pinstSpellSets_x                                           0x10A14A0
#define pinstStringTable_x                                         0x10171A4
#define pinstSwitchManager_x                                       0x1014860
#define pinstTarget_x                                              0x1017228
#define pinstTargetObject_x                                        0x1017200
#define pinstTargetSwitch_x                                        0x1017204
#define pinstTaskMember_x                                          0xF63368
#define pinstTrackTarget_x                                         0x101721C
#define pinstTradeTarget_x                                         0x101720C
#define instTributeActive_x                                        0xC14C65
#define pinstViewActor_x                                           0xF63E98
#define pinstWorldData_x                                           0x10171E0
#define pinstZoneAddr_x                                            0x10247BC
#define pinstPlayerPath_x                                          0x10A9DA0
#define pinstTargetIndicator_x                                     0x10AA738
#define pinstCTargetManager_x                                      0x10AA798

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE213E0
#define pinstCAudioTriggersWindow_x                                0xE21270
#define pinstCCharacterSelect_x                                    0xF63D2C
#define pinstCFacePick_x                                           0xF63ADC
#define pinstCNoteWnd_x                                            0xF63CE4
#define pinstCBookWnd_x                                            0xF63CEC
#define pinstCPetInfoWnd_x                                         0xF63CF0
#define pinstCTrainWnd_x                                           0xF63CF4
#define pinstCSkillsWnd_x                                          0xF63CF8
#define pinstCSkillsSelectWnd_x                                    0xF63CFC
#define pinstCCombatSkillsSelectWnd_x                              0xF63D00
#define pinstCFriendsWnd_x                                         0xF63D04
#define pinstCAuraWnd_x                                            0xF63D08
#define pinstCRespawnWnd_x                                         0xF63D0C
#define pinstCBandolierWnd_x                                       0xF63D10
#define pinstCPotionBeltWnd_x                                      0xF63D14
#define pinstCAAWnd_x                                              0xF63D18
#define pinstCGroupSearchFiltersWnd_x                              0xF63D1C
#define pinstCLoadskinWnd_x                                        0xF63D20
#define pinstCAlarmWnd_x                                           0xF63D24
#define pinstCMusicPlayerWnd_x                                     0xF63D28
#define pinstCMailWnd_x                                            0xF63D30
#define pinstCMailCompositionWnd_x                                 0xF63D34
#define pinstCMailAddressBookWnd_x                                 0xF63D38
#define pinstCRaidWnd_x                                            0xF63D40
#define pinstCRaidOptionsWnd_x                                     0xF63D44
#define pinstCBreathWnd_x                                          0xF63D48
#define pinstCMapViewWnd_x                                         0xF63D4C
#define pinstCMapToolbarWnd_x                                      0xF63D50
#define pinstCEditLabelWnd_x                                       0xF63D54
#define pinstCTargetWnd_x                                          0xF63D58
#define pinstCColorPickerWnd_x                                     0xF63D5C
#define pinstCPlayerWnd_x                                          0xF63D60
#define pinstCOptionsWnd_x                                         0xF63D64
#define pinstCBuffWindowNORMAL_x                                   0xF63D68
#define pinstCBuffWindowSHORT_x                                    0xF63D6C
#define pinstCharacterCreation_x                                   0xF63D70
#define pinstCCursorAttachment_x                                   0xF63D74
#define pinstCCastingWnd_x                                         0xF63D78
#define pinstCCastSpellWnd_x                                       0xF63D7C
#define pinstCSpellBookWnd_x                                       0xF63D80
#define pinstCInventoryWnd_x                                       0xF63D84
#define pinstCBankWnd_x                                            0xF63D8C
#define pinstCQuantityWnd_x                                        0xF63D90
#define pinstCLootWnd_x                                            0xF63D94
#define pinstCActionsWnd_x                                         0xF63D98
#define pinstCCombatAbilityWnd_x                                   0xF63D9C
#define pinstCMerchantWnd_x                                        0xF63DA0
#define pinstCTradeWnd_x                                           0xF63DA4
#define pinstCSelectorWnd_x                                        0xF63DA8
#define pinstCBazaarWnd_x                                          0xF63DAC
#define pinstCBazaarSearchWnd_x                                    0xF63DB0
#define pinstCGiveWnd_x                                            0xF63DCC
#define pinstCTrackingWnd_x                                        0xF63DD4
#define pinstCInspectWnd_x                                         0xF63DD8
#define pinstCSocialEditWnd_x                                      0xF63DDC
#define pinstCFeedbackWnd_x                                        0xF63DE0
#define pinstCBugReportWnd_x                                       0xF63DE4
#define pinstCVideoModesWnd_x                                      0xF63DE8
#define pinstCTextEntryWnd_x                                       0xF63DF0
#define pinstCFileSelectionWnd_x                                   0xF63DF4
#define pinstCCompassWnd_x                                         0xF63DF8
#define pinstCPlayerNotesWnd_x                                     0xF63DFC
#define pinstCGemsGameWnd_x                                        0xF63E00
#define pinstCTimeLeftWnd_x                                        0xF63E04
#define pinstCPetitionQWnd_x                                       0xF63E20
#define pinstCSoulmarkWnd_x                                        0xF63E24
#define pinstCStoryWnd_x                                           0xF63E28
#define pinstCJournalTextWnd_x                                     0xF63E2C
#define pinstCJournalCatWnd_x                                      0xF63E30
#define pinstCBodyTintWnd_x                                        0xF63E34
#define pinstCServerListWnd_x                                      0xF63E38
#define pinstCAvaZoneWnd_x                                         0xF63E44
#define pinstCBlockedBuffWnd_x                                     0xF63E48
#define pinstCBlockedPetBuffWnd_x                                  0xF63E4C
#define pinstCInvSlotMgr_x                                         0xF63E90
#define pinstCContainerMgr_x                                       0xF63E94
#define pinstCAdventureLeaderboardWnd_x                            0x11B66E8
#define pinstCAdventureRequestWnd_x                                0x11B6760
#define pinstCAltStorageWnd_x                                      0x11B6A40
#define pinstCAdventureStatsWnd_x                                  0x11B67D8
#define pinstCBarterMerchantWnd_x                                  0x11B7628
#define pinstCBarterSearchWnd_x                                    0x11B76A0
#define pinstCBarterWnd_x                                          0x11B7718
#define pinstCChatManager_x                                        0x11B7DA8
#define pinstCDynamicZoneWnd_x                                     0x11B8258
#define pinstCEQMainWnd_x                                          0x11B83F0
#define pinstCFellowshipWnd_x                                      0x11B81EC
#define pinstCFindLocationWnd_x                                    0x11B86C0
#define pinstCGroupSearchWnd_x                                     0x11B8990
#define pinstCGroupWnd_x                                           0x11B8A08
#define pinstCGuildBankWnd_x                                       0x11B8A80
#define pinstCGuildMgmtWnd_x                                       0x11BAB70
#define pinstCHotButtonWnd_x                                       0x11BAC6C
#define pinstCHotButtonWnd1_x                                      0x11BAC6C
#define pinstCHotButtonWnd2_x                                      0x11BAC70
#define pinstCHotButtonWnd3_x                                      0x11BAC74
#define pinstCHotButtonWnd4_x                                      0x11BAC98
#define pinstCItemDisplayManager_x                                 0x11BAF90
#define pinstCItemExpTransferWnd_x                                 0x11BB00C
#define pinstCLFGuildWnd_x                                         0x11BB2E8
#define pinstCMIZoneSelectWnd_x                                    0x11BB8D0
#define pinstCConfirmationDialog_x                                 0x11BBFD8
#define pinstCPopupWndManager_x                                    0x11BBFD8
#define pinstCProgressionSelectionWnd_x                            0x11BC0C8
#define pinstCPvPStatsWnd_x                                        0x11BC1B8
#define pinstCSystemInfoDialogBox_x                                0x11BC8C0
#define pinstCTaskWnd_x                                            0x11BDC88
#define pinstCTaskSomething_x                                      0xE31F10
#define pinstCTaskTemplateSelectWnd_x                              0x11BDC10
#define pinstCTipWndOFDAY_x                                        0x11BDDF0
#define pinstCTipWndCONTEXT_x                                      0x11BDDF4
#define pinstCTitleWnd_x                                           0x11BDE70
#define pinstCContextMenuManager_x                                 0x18219D4
#define pinstCVoiceMacroWnd_x                                      0x10AAB70
#define pinstCHtmlWnd_x                                            0x10AAC60
#define pinstIconCache_x                                           0x11B83C4
#define pinstCTradeskillWnd_x                                      0x11BDF70
#define pinstCAdvancedLootWnd_x                                    0xF63E84
#define pinstRewardSelectionWnd_x                                  0x11BC6E0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x535330
#define __ConvertItemTags_x                                        0x522C60
#define __ExecuteCmd_x                                             0x50D510
#define __EQGetTime_x                                              0x897D90
#define __get_melee_range_x                                        0x514100
#define __GetGaugeValueFromEQ_x                                    0x7A5A50
#define __GetLabelFromEQ_x                                         0x7A6CA0
#define __ToggleKeyRingItem_x                                      0x47F690
#define __GetXTargetType_x                                         0x92E0C0
#define __LoadFrontEnd_x                                           0x634700
#define __NewUIINI_x                                               0x7A5420
#define __ProcessGameEvents_x                                      0x578470
#define __ProcessMouseEvent_x                                      0x577C10
#define CrashDetected_x                                            0x6360C0
#define wwsCrashReportCheckForUploader_x                           0x7F55D0
#define DrawNetStatus_x                                            0x5AE870
#define Util__FastTime_x                                           0x8978A0
#define Expansion_HoT_x                                            0x1025600
#define __HelpPath_x                                               0x10A8CF8
#define __STMLToText_x                                             0x8E2F60

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420590
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B3E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B1C0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C65F0
#define AltAdvManager__IsAbilityReady_x                            0x4C6660
#define AltAdvManager__GetAAById_x                                 0x4C6A20
#define AltAdvManager__CanTrainAbility_x                           0x4C72E0
#define AltAdvManager__CanSeeAbility_x                             0x4C6EE0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x462CF0
#define CharacterZoneClient__MakeMeVisible_x                       0x467790
#define CharacterZoneClient__IsStackBlocked_x                      0x447380
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446840
#define CharacterZoneClient__GetItemCountWorn_x                    0x460B30
#define CharacterZoneClient__GetItemCountInInventory_x             0x460C10
#define CharacterZoneClient__GetCursorItemCount_x                  0x460CF0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x664550

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x672CF0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58DB50
#define CButtonWnd__CButtonWnd_x                                   0x8D7260

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68DAB0
#define CChatManager__InitContextMenu_x                            0x68E630

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E12C0
#define CContextMenu__dCContextMenu_x                              0x8E14D0
#define CContextMenu__AddMenuItem_x                                0x8E14E0
#define CContextMenu__RemoveMenuItem_x                             0x8E17D0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E17F0
#define CContextMenuManager__AddMenu_x                             0x8CD810
#define CContextMenuManager__RemoveMenu_x                          0x8CDB50
#define CContextMenuManager__PopupMenu_x                           0x8CDFA0
#define CContextMenuManager__Flush_x                               0x8CD880
#define CContextMenuManager__GetMenu_x                             0x416A10

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87C640
#define CChatService__GetFriendName_x                              0x87C650

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x693880
#define CChatWindow__Clear_x                                       0x693460
#define CChatWindow__WndNotification_x                             0x693DC0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D1610
#define CComboWnd__Draw_x                                          0x8D1820
#define CComboWnd__GetCurChoice_x                                  0x8D13C0
#define CComboWnd__GetListRect_x                                   0x8D1AC0
#define CComboWnd__GetTextRect_x                                   0x8D1680
#define CComboWnd__InsertChoice_x                                  0x8D1B30
#define CComboWnd__SetColors_x                                     0x8D1350
#define CComboWnd__SetChoice_x                                     0x8D1380
#define CComboWnd__GetItemCount_x                                  0x8D13B0
#define CComboWnd__GetCurChoiceText_x                              0x8D1400


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69CFC0
#define CContainerWnd__vftable_x                                   0xADFCF0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B4AA0
#define CDisplay__GetClickedActor_x                                0x4AD360
#define CDisplay__GetUserDefinedColor_x                            0x4ABF40
#define CDisplay__GetWorldFilePath_x                               0x4AB390
#define CDisplay__is3dON_x                                         0x4AA820
#define CDisplay__ReloadUI_x                                       0x4BFFB0
#define CDisplay__WriteTextHD2_x                                   0x4B0DF0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F79B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E57F0
#define CEditWnd__GetCharIndexPt_x                                 0x8E6890
#define CEditWnd__GetDisplayString_x                               0x8E59A0
#define CEditWnd__GetHorzOffset_x                                  0x8E5CE0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E6350
#define CEditWnd__GetSelStartPt_x                                  0x8E6B50
#define CEditWnd__GetSTMLSafeText_x                                0x8E5E80
#define CEditWnd__PointFromPrintableChar_x                         0x8E6440
#define CEditWnd__SelectableCharFromPoint_x                        0x8E65C0
#define CEditWnd__SetEditable_x                                    0x8E5E50

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x559280
#define CEverQuest__CreateTargetIndicator_x                        0x55A170
#define CEverQuest__DeleteTargetIndicator_x                        0x55A1F0
#define CEverQuest__DoTellWindow_x                                 0x4723F0
#define CEverQuest__DropHeldItemOnGround_x                         0x570320
#define CEverQuest__dsp_chat_x                                     0x472730
#define CEverQuest__trimName_x                                     0x555BD0
#define CEverQuest__Emote_x                                        0x56E670
#define CEverQuest__EnterZone_x                                    0x569670
#define CEverQuest__GetBodyTypeDesc_x                              0x553630
#define CEverQuest__GetClassDesc_x                                 0x55CF00
#define CEverQuest__GetClassThreeLetterCode_x                      0x55D500
#define CEverQuest__GetDeityDesc_x                                 0x553F10
#define CEverQuest__GetLangDesc_x                                  0x5539C0
#define CEverQuest__GetRaceDesc_x                                  0x55D6C0
#define CEverQuest__InterpretCmd_x                                 0x5614D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x574B60
#define CEverQuest__LMouseUp_x                                     0x576C60
#define CEverQuest__RightClickedOnPlayer_x                         0x575670
#define CEverQuest__RMouseUp_x                                     0x5766C0
#define CEverQuest__SetGameState_x                                 0x559B40
#define CEverQuest__UPCNotificationFlush_x                         0x551450
#define CEverQuest__IssuePetCommand_x                              0x561EB0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6ADDB0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6ADE10
#define CGaugeWnd__Draw_x                                          0x6AE240

// CGuild
#define CGuild__FindMemberByName_x                                 0x4371C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CA240

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D73F0
#define CInvSlotMgr__MoveItem_x                                    0x6D82A0
#define CInvSlotMgr__SelectSlot_x                                  0x6D74A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D68A0
#define CInvSlot__SliderComplete_x                                 0x6D40B0
#define CInvSlot__GetItemBase_x                                    0x6D3530

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D96D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A1460
#define CItemDisplayWnd__UpdateStrings_x                           0x6DB800

// CLabel 
#define CLabel__Draw_x                                             0x6F4EB0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BD460
#define CListWnd__dCListWnd_x                                      0x8BE4A0
#define CListWnd__AddColumn_x                                      0x8BE440
#define CListWnd__AddColumn1_x                                     0x8BDCC0
#define CListWnd__AddLine_x                                        0x8BD720
#define CListWnd__AddString_x                                      0x8BD940
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BA720
#define CListWnd__CalculateVSBRange_x                              0x8BC930
#define CListWnd__ClearSel_x                                       0x8B9A40
#define CListWnd__ClearAllSel_x                                    0x8B99F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BD2F0
#define CListWnd__Compare_x                                        0x8BB2A0
#define CListWnd__Draw_x                                           0x8BC530
#define CListWnd__DrawColumnSeparators_x                           0x8BC3C0
#define CListWnd__DrawHeader_x                                     0x8B9D00
#define CListWnd__DrawItem_x                                       0x8BB8F0
#define CListWnd__DrawLine_x                                       0x8BC060
#define CListWnd__DrawSeparator_x                                  0x8BC460
#define CListWnd__EnsureVisible_x                                  0x8BA880
#define CListWnd__ExtendSel_x                                      0x8BB800
#define CListWnd__GetColumnMinWidth_x                              0x8B93F0
#define CListWnd__GetColumnWidth_x                                 0x8B9320
#define CListWnd__GetCurSel_x                                      0x8B8AF0
#define CListWnd__GetItemAtPoint_x                                 0x8BAB20
#define CListWnd__GetItemAtPoint1_x                                0x8BAB90
#define CListWnd__GetItemData_x                                    0x8B8E30
#define CListWnd__GetItemHeight_x                                  0x8BA380
#define CListWnd__GetItemIcon_x                                    0x8B9020
#define CListWnd__GetItemRect_x                                    0x8BA960
#define CListWnd__GetItemText_x                                    0x8B8ED0
#define CListWnd__GetSelList_x                                     0x8BDBB0
#define CListWnd__GetSeparatorRect_x                               0x8BB1C0
#define CListWnd__RemoveLine_x                                     0x8BDB30
#define CListWnd__SetColors_x                                      0x8B8C40
#define CListWnd__SetColumnJustification_x                         0x8B9680
#define CListWnd__SetColumnWidth_x                                 0x8B93A0
#define CListWnd__SetCurSel_x                                      0x8B8B30
#define CListWnd__SetItemColor_x                                   0x8BCFE0
#define CListWnd__SetItemData_x                                    0x8B9AA0
#define CListWnd__SetItemText_x                                    0x8BCE20
#define CListWnd__ShiftColumnSeparator_x                           0x8BCCB0
#define CListWnd__Sort_x                                           0x8BE5A0
#define CListWnd__ToggleSel_x                                      0x8B9970

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70E090

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72F410
#define CMerchantWnd__RequestBuyItem_x                             0x7364C0
#define CMerchantWnd__RequestSellItem_x                            0x736F90
#define CMerchantWnd__SelectRecoverySlot_x                         0x72F6C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72E8C0
#define CMerchantWnd__ActualSelect_x                               0x733390

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x849080
#define CPacketScrambler__hton_x                                   0x849090

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DC270
#define CSidlManager__CreateLabel_x                                0x7973E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65B940
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65B870
#define CSidlScreenWnd__ConvertToRes_x                             0x8F7890
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D3FC0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D5180
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D5230
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D4700
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D3970
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D30E0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D3B60
#define CSidlScreenWnd__Init1_x                                    0x8D4E50
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D4070
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D32A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D4940
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D2D40
#define CSidlScreenWnd__StoreIniVis_x                              0x8D3090
#define CSidlScreenWnd__WndNotification_x                          0x8D4BD0
#define CSidlScreenWnd__GetChildItem_x                             0x8D31B0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C6A10
#define CSidlScreenWnd__m_layoutCopy_x                             0x1821A38

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F9F40
#define CSkillMgr__GetSkillCap_x                                   0x5FA120
#define CSkillMgr__GetNameToken_x                                  0x5F9B60

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F6B40
#define CSliderWnd__SetValue_x                                     0x8F6D10
#define CSliderWnd__SetNumTicks_x                                  0x8F7490

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79F0C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F24A0
#define CStmlWnd__CalculateHSBRange_x                              0x8EA9D0
#define CStmlWnd__CalculateVSBRange_x                              0x8EAA60
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EABE0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EB4C0
#define CStmlWnd__ForceParseNow_x                                  0x8F2DF0
#define CStmlWnd__GetNextTagPiece_x                                0x8EB3C0
#define CStmlWnd__GetSTMLText_x                                    0x692D00
#define CStmlWnd__GetVisibleText_x                                 0x8EBF10
#define CStmlWnd__InitializeWindowVariables_x                      0x8EE2A0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E9CD0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E9D30
#define CStmlWnd__SetSTMLText_x                                    0x8EFAF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F2140
#define CStmlWnd__UpdateHistoryString_x                            0x8ECE50

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E93E0
#define CTabWnd__DrawCurrentPage_x                                 0x8E8C70
#define CTabWnd__DrawTab_x                                         0x8E8A30
#define CTabWnd__GetCurrentPage_x                                  0x8E9020
#define CTabWnd__GetPageInnerRect_x                                0x8E8720
#define CTabWnd__GetTabInnerRect_x                                 0x8E8920
#define CTabWnd__GetTabRect_x                                      0x8E87F0
#define CTabWnd__InsertPage_x                                      0x8E96D0
#define CTabWnd__SetPage_x                                         0x8E9050
#define CTabWnd__SetPageRect_x                                     0x8E9320
#define CTabWnd__UpdatePage_x                                      0x8E9670

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432D30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D0FC0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6328B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FCCE0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B6C50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029B0
#define CXStr__CXStr1_x                                            0x43F700
#define CXStr__CXStr3_x                                            0x894AF0
#define CXStr__dCXStr_x                                            0x471FF0
#define CXStr__operator_equal_x                                    0x894C60
#define CXStr__operator_equal1_x                                   0x894CB0
#define CXStr__operator_plus_equal1_x                              0x895DB0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C5C40
#define CXWnd__Center_x                                            0x8CBE30
#define CXWnd__ClrFocus_x                                          0x8C5820
#define CXWnd__DoAllDrawing_x                                      0x8CBA80
#define CXWnd__DrawChildren_x                                      0x8CBC20
#define CXWnd__DrawColoredRect_x                                   0x8C5FF0
#define CXWnd__DrawTooltip_x                                       0x8C62A0
#define CXWnd__DrawTooltipAtPoint_x                                0x8CA9C0
#define CXWnd__GetBorderFrame_x                                    0x8C66D0
#define CXWnd__GetChildWndAt_x                                     0x8CC7E0
#define CXWnd__GetClientClipRect_x                                 0x8C64A0
#define CXWnd__GetScreenClipRect_x                                 0x8CB0C0
#define CXWnd__GetScreenRect_x                                     0x8C68B0
#define CXWnd__GetTooltipRect_x                                    0x8C6130
#define CXWnd__GetWindowTextA_x                                    0x424540
#define CXWnd__IsActive_x                                          0x8C1250
#define CXWnd__IsDescendantOf_x                                    0x8C6610
#define CXWnd__IsReallyVisible_x                                   0x8C99F0
#define CXWnd__IsType_x                                            0x8F9540
#define CXWnd__Move_x                                              0x8C90F0
#define CXWnd__Move1_x                                             0x8CB720
#define CXWnd__ProcessTransition_x                                 0x8C5BE0
#define CXWnd__Refade_x                                            0x8C59C0
#define CXWnd__Resize_x                                            0x8C6970
#define CXWnd__Right_x                                             0x8CAEC0
#define CXWnd__SetFocus_x                                          0x8C8280
#define CXWnd__SetFont_x                                           0x8C5870
#define CXWnd__SetKeyTooltip_x                                     0x8C6BE0
#define CXWnd__SetMouseOver_x                                      0x8CB400
#define CXWnd__StartFade_x                                         0x8C5C90
#define CXWnd__GetChildItem_x                                      0x8CB340

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C2AE0
#define CXWndManager__DrawWindows_x                                0x8C2720
#define CXWndManager__GetKeyboardFlags_x                           0x8C0D80
#define CXWndManager__HandleKeyboardMsg_x                          0x8C16E0
#define CXWndManager__RemoveWnd_x                                  0x8C13E0

// CDBStr
#define CDBStr__GetString_x                                        0x4A8D70

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44D910
#define EQ_Character__Cur_HP_x                                     0x462390
#define EQ_Character__Cur_Mana_x                                   0x455ED0
#define EQ_Character__GetAACastingTimeModifier_x                   0x446B50
#define EQ_Character__GetCharInfo2_x                               0x868900
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EE70
#define EQ_Character__GetFocusRangeModifier_x                      0x43EED0
#define EQ_Character__Max_Endurance_x                              0x5C0500
#define EQ_Character__Max_HP_x                                     0x458AF0
#define EQ_Character__Max_Mana_x                                   0x5C0330
#define EQ_Character__doCombatAbility_x                            0x5BDA20
#define EQ_Character__UseSkill_x                                   0x46C810
#define EQ_Character__GetConLevel_x                                0x5B2EA0
#define EQ_Character__IsExpansionFlag_x                            0x423A90
#define EQ_Character__TotalEffect_x                                0x44ABA0
#define EQ_Character__GetPCSpellAffect_x                           0x446F50
#define EQ_Character__SpellDuration_x                              0x444E50
#define EQ_Character__FindItemByRecord_x                           0x45F820

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x4421B0
#define CCharacterSelect__EnterWorld_x                             0x441980
#define CCharacterSelect__Quit_x                                   0x440560

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5933C0
#define EQ_Item__CreateItemTagString_x                             0x847A00
#define EQ_Item__IsStackable_x                                     0x83D1F0
#define EQ_Item__GetImageNum_x                                     0x83FCC0
#define EQ_Item__CreateItemClient_x                                0x593FA0
#define EQ_Item__GetItemValue_x                                    0x8466B0
#define EQ_Item__ValueSellMerchant_x                               0x848D10
#define EQ_Item__IsKeyRingItem_x                                   0x83DCD0
#define EQ_Item__CanGoInBag_x                                      0x593550
#define EQ_Item__GetMaxItemCount_x                                 0x83CE70
#define EQ_Item__GetHeldItem_x                                     0x83EAC0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C8730
#define EQ_LoadingS__Array_x                                       0xC214C0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C2A20
#define EQ_PC__GetAlternateAbilityId_x                             0x851080
#define EQ_PC__GetCombatAbility_x                                  0x851110
#define EQ_PC__GetCombatAbilityTimer_x                             0x84BE90
#define EQ_PC__GetItemTimerValue_x                                 0x5BC0D0
#define EQ_PC__HasLoreItem_x                                       0x5B63B0
#define EQ_PC__AlertInventoryChanged_x                             0x5B2E70
#define EQ_PC__GetPcZoneClient_x                                   0x5DD100
#define EQ_PC__RemoveMyAffect_x                                    0x5BB570
#define EQ_PC__GetKeyRingItems_x                                   0x84C2B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x512170
#define EQItemList__add_object_x                                   0x53DF00
#define EQItemList__add_item_x                                     0x5120B0
#define EQItemList__delete_item_x                                  0x512560
#define EQItemList__FreeItemList_x                                 0x512460

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A8020

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C8120
#define EQPlayer__dEQPlayer_x                                      0x5D0FE0
#define EQPlayer__DoAttack_x                                       0x5E2FD0
#define EQPlayer__EQPlayer_x                                       0x5D3400
#define EQPlayer__SetNameSpriteState_x                             0x5CDF30
#define EQPlayer__SetNameSpriteTint_x                              0x5C9530
#define PlayerBase__HasProperty_j_x                                0x92A2C0
#define EQPlayer__IsTargetable_x                                   0x92ABC0
#define EQPlayer__CanSee_x                                         0x92B0E0
#define PlayerZoneClient__ChangeHeight_x                           0x5E2E90
#define EQPlayer__CanSeeTargetIndicator_x                          0x92B1D0
#define PlayerBase__GetVisibilityLineSegment_x                     0x92AE70

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D7740
#define EQPlayerManager__GetSpawnByName_x                          0x5D7BA0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D7770

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x599470
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5994B0
#define KeypressHandler__ClearCommandStateArray_x                  0x599060
#define KeypressHandler__HandleKeyDown_x                           0x5979C0
#define KeypressHandler__HandleKeyUp_x                             0x597CE0
#define KeypressHandler__SaveKeymapping_x                          0x599130

// MapViewMap 
#define MapViewMap__Clear_x                                        0x706A20
#define MapViewMap__SaveEx_x                                       0x709D50

#define PlayerPointManager__GetAltCurrency_x                       0x8637A0

// StringTable 
#define StringTable__getString_x                                   0x85E440

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BFF90
#define PcZoneClient__RemovePetEffect_x                            0x5BC5A0
#define PcZoneClient__HasAlternateAbility_x                        0x5BCF40
#define PcZoneClient__GetCurrentMod_x                              0x457E90
#define PcZoneClient__GetModCap_x                                  0x455650
#define PcZoneClient__CanEquipItem_x                               0x5BD4F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54FD80

//IconCache
#define IconCache__GetIcon_x                                       0x6A35B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69A340
#define CContainerMgr__CloseContainer_x                            0x69AB60

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x767310

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58C5D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E0510
#define EQ_Spell__SpellAffects_x                                   0x4DDBC0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DDC30
#define CharacterZoneClient__CalcAffectChange_x                    0x445F80
#define CLootWnd__LootAll_x                                        0x6FC250
#define CLootWnd__RequestLootSlot_x                                0x6FCA60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7ADF30
#define CTargetWnd__WndNotification_x                              0x7ADA20
#define CTargetWnd__RefreshTargetBuffs_x                           0x7AE110

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B3120

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D9480

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x497F30

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E4E20
#define CSidlManager__FindAnimation1_x                             0x8DA170

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CFDC0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CFD70
#define CAltAbilityData__GetMaxRank_x                              0x4C4CA0

//CTargetRing
#define CTargetRing__Cast_x                                        0x589EA0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4547B0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4715E0
#define CharacterBase__CreateItemIndex_x                           0x50B680
#define CharacterBase__GetItemPossession_x                         0x50CA30
#define CharacterBase__GetItemByGlobalIndex_x                      0x876760

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x684AF0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x684250

//messages
#define msg_spell_worn_off_x                                       0x4E7FB0
#define msg_new_text_x                                             0x4F1420
#define msgTokenTextParam_x                                        0x4EDDF0

//SpellManager
#define SpellManager__vftable_x                                    0xABBFA8
#define SpellManager__SpellManager_x                               0x47A420
#define Spellmanager__CheckSpellRequirementAssociations_x          0x600E10

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x92EC00

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E4560
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43A540
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444830
#define ItemGlobalIndex__IsValidIndex_x                            0x454070

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x874570
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8734B0
