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
#define __ExpectedVersionDate                                     "Mar 16 2017"
#define __ExpectedVersionTime                                     "14:59:17"
#define __ActualVersionDate_x                                      0xACBCB8
#define __ActualVersionTime_x                                      0xACBCC4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x59A760
#define __MemChecker1_x                                            0x891340
#define __MemChecker2_x                                            0x630940
#define __MemChecker3_x                                            0x630890
#define __MemChecker4_x                                            0x7E4060
#define __EncryptPad0_x                                            0xC25328
#define __EncryptPad1_x                                            0xD00C90
#define __EncryptPad2_x                                            0xC4E9A8
#define __EncryptPad3_x                                            0xC4E5A8
#define __EncryptPad4_x                                            0xCEF2B0
#define __EncryptPad5_x                                            0x10A9898
#define __AC1_x                                                    0x7A3685
#define __AC2_x                                                    0x554897
#define __AC3_x                                                    0x552A30
#define __AC4_x                                                    0x564DF0
#define __AC5_x                                                    0x577BBB
#define __AC6_x                                                    0x57B76E
#define __AC7_x                                                    0x5721BC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FE7B2C

// Direct Input
#define DI8__Main_x                                                0x10A9870
#define DI8__Keyboard_x                                            0x10A9874
#define DI8__Mouse_x                                               0x10A9878
#define DI8__Mouse_Copy_x                                          0xF17C4C
#define DI8__Mouse_Check_x                                         0xFA155C
#define __Attack_x                                                 0xF9C13F
#define __Autofire_x                                               0xF9C140
#define __BindList_x                                               0xC00108
#define g_eqCommandStates_x                                        0xF06C70
#define __Clicks_x                                                 0xF17D08
#define __CommandList_x                                            0xC02768
#define __CurrentMapLabel_x                                        0x10AF2F8
#define __CurrentSocial_x                                          0xBD2348
#define __DoAbilityList_x                                          0xF4E3F4
#define __do_loot_x                                                0x5233C0
#define __DrawHandler_x                                            0x1716224
#define __GroupCount_x                                             0xF082A2

#define __Guilds_x                                                 0xF0DEB8
#define __gWorld_x                                                 0xF0A75C
#define __HotkeyPage_x                                             0xF94DF4
#define __HWnd_x                                                   0xFA1678
#define __InChatMode_x                                             0xF17C34
#define __LastTell_x                                               0xF19AF0
#define __LMouseHeldTime_x                                         0xF17D74
#define __Mouse_x                                                  0x10A987C
#define __MouseLook_x                                              0xF17CCE
#define __MouseEventTime_x                                         0xF9C944
#define __gpbCommandEvent_x                                        0xF0A824
#define __NetStatusToggle_x                                        0xF17CD1
#define __PCNames_x                                                0xF19108
#define __RangeAttackReady_x                                       0xF18E3C
#define __RMouseHeldTime_x                                         0xF17D70
#define __RunWalkState_x                                           0xF17C38
#define __ScreenMode_x                                             0xE56968
#define __ScreenX_x                                                0xF17BEC
#define __ScreenY_x                                                0xF17BE8
#define __ScreenXMax_x                                             0xF17BF0
#define __ScreenYMax_x                                             0xF17BF4
#define __ServerHost_x                                             0xF081EC
#define __ServerName_x                                             0xF4E3B4
#define __ShiftKeyDown_x                                           0xF182C8
#define __ShowNames_x                                              0xF18FFC
#define __Socials_x                                                0xF4E4B4
#define __SubscriptionType_x                                       0x10DD334
#define __TargetAggroHolder_x                                      0x10B1544
#define __ZoneType_x                                               0xF180CC
#define __GroupAggro_x                                             0x10B1584
#define __LoginName_x                                              0xFA0154
#define __Inviter_x                                                0xF9C0BC
#define __AttackOnAssist_x                                         0xF18FB8
#define __UseTellWindows_x                                         0xF192A0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF0A848
#define instEQZoneInfo_x                                           0xF17EC4
#define instKeypressHandler_x                                      0xF9C928
#define pinstActiveBanker_x                                        0xF0A800
#define pinstActiveCorpse_x                                        0xF0A804
#define pinstActiveGMaster_x                                       0xF0A808
#define pinstActiveMerchant_x                                      0xF0A7FC
#define pinstAggroInfo_x                                           0xD14348
#define pinstAltAdvManager_x                                       0xE57A38
#define pinstAuraMgr_x                                             0xD24AB8
#define pinstBandageTarget_x                                       0xF0A7E8
#define pinstCamActor_x                                            0xE5738C
#define pinstCDBStr_x                                              0xE568FC
#define pinstCDisplay_x                                            0xF0A810
#define pinstCEverQuest_x                                          0x10A99F0
#define pinstEverQuestInfo_x                                       0xF17BE0
#define pinstCharData_x                                            0xF0A7CC
#define pinstCharSpawn_x                                           0xF0A7F4
#define pinstControlledMissile_x                                   0xF0A7C8
#define pinstControlledPlayer_x                                    0xF0A7F4
#define pinstCSidlManager_x                                        0x1715614
#define pinstCXWndManager_x                                        0x171560C
#define instDynamicZone_x                                          0xF17A80
#define pinstDZMember_x                                            0xF17B90
#define pinstDZTimerInfo_x                                         0xF17B94
#define pinstEQItemList_x                                          0xF06EC4
#define pinstEQObjectList_x                                        0xF07C9C
#define instEQMisc_x                                               0xBE8808
#define pinstEQSoundManager_x                                      0xE58008
#define instExpeditionLeader_x                                     0xF17ACA
#define instExpeditionName_x                                       0xF17B0A
#define pinstGroup_x                                               0xF0829E
#define pinstImeManager_x                                          0x1715618
#define pinstLocalPlayer_x                                         0xF0A7E0
#define pinstMercenaryData_x                                       0xF9CFA8
#define pinstMercenaryStats_x                                      0x10B1690
#define pinstMercAltAbilities_x                                    0xE57DC0
#define pinstModelPlayer_x                                         0xF0A80C
#define pinstPCData_x                                              0xF0A7CC
#define pinstSkillMgr_x                                            0xF9DE10
#define pinstSpawnManager_x                                        0xF9D6F8
#define pinstSpellManager_x                                        0xF9DF58
#define pinstSpellSets_x                                           0xF94E58
#define pinstStringTable_x                                         0xF0A774
#define pinstSwitchManager_x                                       0xF07E30
#define pinstTarget_x                                              0xF0A7F8
#define pinstTargetObject_x                                        0xF0A7D0
#define pinstTargetSwitch_x                                        0xF0A7D4
#define pinstTaskMember_x                                          0xE56848
#define pinstTrackTarget_x                                         0xF0A7EC
#define pinstTradeTarget_x                                         0xF0A7DC
#define instTributeActive_x                                        0xBE882D
#define pinstViewActor_x                                           0xE57388
#define pinstWorldData_x                                           0xF0A7B0
#define pinstZoneAddr_x                                            0xF18164
#define pinstPlayerPath_x                                          0xF9D758
#define pinstTargetIndicator_x                                     0xF9E0F0
#define pinstCTargetManager_x                                      0xF9E150
#define EQObject_Top_x                                             0xF0A7C0
#define pinstRealEstateItems_x                                     0xF9DCFC

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE572A4
#define pinstCAchievementsWnd_x                                    0xE57300
#define pinstCTextOverlay_x                                        0xD14840
#define pinstCAudioTriggersWindow_x                                0xD146D0
#define pinstCCharacterSelect_x                                    0xE57214
#define pinstCFacePick_x                                           0xE56FC4
#define pinstCNoteWnd_x                                            0xE571CC
#define pinstCBookWnd_x                                            0xE571D4
#define pinstCPetInfoWnd_x                                         0xE571D8
#define pinstCTrainWnd_x                                           0xE571DC
#define pinstCSkillsWnd_x                                          0xE571E0
#define pinstCSkillsSelectWnd_x                                    0xE571E4
#define pinstCCombatSkillsSelectWnd_x                              0xE571E8
#define pinstCFriendsWnd_x                                         0xE571EC
#define pinstCAuraWnd_x                                            0xE571F0
#define pinstCRespawnWnd_x                                         0xE571F4
#define pinstCBandolierWnd_x                                       0xE571F8
#define pinstCPotionBeltWnd_x                                      0xE571FC
#define pinstCAAWnd_x                                              0xE57200
#define pinstCGroupSearchFiltersWnd_x                              0xE57204
#define pinstCLoadskinWnd_x                                        0xE57208
#define pinstCAlarmWnd_x                                           0xE5720C
#define pinstCMusicPlayerWnd_x                                     0xE57210
#define pinstCMailWnd_x                                            0xE57218
#define pinstCMailCompositionWnd_x                                 0xE5721C
#define pinstCMailAddressBookWnd_x                                 0xE57220
#define pinstCRaidWnd_x                                            0xE57228
#define pinstCRaidOptionsWnd_x                                     0xE5722C
#define pinstCBreathWnd_x                                          0xE57230
#define pinstCMapViewWnd_x                                         0xE57234
#define pinstCMapToolbarWnd_x                                      0xE57238
#define pinstCEditLabelWnd_x                                       0xE5723C
#define pinstCTargetWnd_x                                          0xE57240
#define pinstCColorPickerWnd_x                                     0xE57244
#define pinstCPlayerWnd_x                                          0xE57248
#define pinstCOptionsWnd_x                                         0xE5724C
#define pinstCBuffWindowNORMAL_x                                   0xE57250
#define pinstCBuffWindowSHORT_x                                    0xE57254
#define pinstCharacterCreation_x                                   0xE57258
#define pinstCCursorAttachment_x                                   0xE5725C
#define pinstCCastingWnd_x                                         0xE57260
#define pinstCCastSpellWnd_x                                       0xE57264
#define pinstCSpellBookWnd_x                                       0xE57268
#define pinstCInventoryWnd_x                                       0xE5726C
#define pinstCBankWnd_x                                            0xE57274
#define pinstCQuantityWnd_x                                        0xE57278
#define pinstCLootWnd_x                                            0xE5727C
#define pinstCActionsWnd_x                                         0xE57280
#define pinstCCombatAbilityWnd_x                                   0xE57288
#define pinstCMerchantWnd_x                                        0xE5728C
#define pinstCTradeWnd_x                                           0xE57294
#define pinstCSelectorWnd_x                                        0xE57298
#define pinstCBazaarWnd_x                                          0xE5729C
#define pinstCBazaarSearchWnd_x                                    0xE572A0
#define pinstCGiveWnd_x                                            0xE572BC
#define pinstCTrackingWnd_x                                        0xE572C4
#define pinstCInspectWnd_x                                         0xE572C8
#define pinstCSocialEditWnd_x                                      0xE572CC
#define pinstCFeedbackWnd_x                                        0xE572D0
#define pinstCBugReportWnd_x                                       0xE572D4
#define pinstCVideoModesWnd_x                                      0xE572D8
#define pinstCTextEntryWnd_x                                       0xE572E0
#define pinstCFileSelectionWnd_x                                   0xE572E4
#define pinstCCompassWnd_x                                         0xE572E8
#define pinstCPlayerNotesWnd_x                                     0xE572EC
#define pinstCGemsGameWnd_x                                        0xE572F0
#define pinstCTimeLeftWnd_x                                        0xE572F4
#define pinstCPetitionQWnd_x                                       0xE57310
#define pinstCSoulmarkWnd_x                                        0xE57314
#define pinstCStoryWnd_x                                           0xE57318
#define pinstCJournalTextWnd_x                                     0xE5731C
#define pinstCJournalCatWnd_x                                      0xE57320
#define pinstCBodyTintWnd_x                                        0xE57324
#define pinstCServerListWnd_x                                      0xE57328
#define pinstCAvaZoneWnd_x                                         0xE57334
#define pinstCBlockedBuffWnd_x                                     0xE57338
#define pinstCBlockedPetBuffWnd_x                                  0xE5733C
#define pinstCInvSlotMgr_x                                         0xE57380
#define pinstCContainerMgr_x                                       0xE57384
#define pinstCAdventureLeaderboardWnd_x                            0x10AA3A0
#define pinstCAdventureRequestWnd_x                                0x10AA418
#define pinstCAltStorageWnd_x                                      0x10AA6F8
#define pinstCAdventureStatsWnd_x                                  0x10AA490
#define pinstCBarterMerchantWnd_x                                  0x10AB2E0
#define pinstCBarterSearchWnd_x                                    0x10AB358
#define pinstCBarterWnd_x                                          0x10AB3D0
#define pinstCChatWindowManager_x                                  0x10ABA60
#define pinstCDynamicZoneWnd_x                                     0x10ABF10
#define pinstCEQMainWnd_x                                          0x10AC0A8
#define pinstCFellowshipWnd_x                                      0x10ABEA4
#define pinstCFindLocationWnd_x                                    0x10AC378
#define pinstCGroupSearchWnd_x                                     0x10AC648
#define pinstCGroupWnd_x                                           0x10AC6C0
#define pinstCGuildBankWnd_x                                       0x10AC738
#define pinstCGuildMgmtWnd_x                                       0x10AE828
#define pinstCHotButtonWnd_x                                       0x10AE924
#define pinstCHotButtonWnd1_x                                      0x10AE924
#define pinstCHotButtonWnd2_x                                      0x10AE928
#define pinstCHotButtonWnd3_x                                      0x10AE92C
#define pinstCHotButtonWnd4_x                                      0x10AE950
#define pinstCItemDisplayManager_x                                 0x10AEC48
#define pinstCItemExpTransferWnd_x                                 0x10AECC4
#define pinstCLFGuildWnd_x                                         0x10AEFA0
#define pinstCMIZoneSelectWnd_x                                    0x10AF588
#define pinstCConfirmationDialog_x                                 0x10AFC90
#define pinstCPopupWndManager_x                                    0x10AFC90
#define pinstCProgressionSelectionWnd_x                            0x10AFD80
#define pinstCPvPStatsWnd_x                                        0x10AFE70
#define pinstCLargeDialogWnd_x                                     0x10B0578
#define pinstCTaskWnd_x                                            0x10B1970
#define pinstCTaskSomething_x                                      0xD253F0
#define pinstCTaskTemplateSelectWnd_x                              0x10B18F8
#define pinstCTipWndOFDAY_x                                        0x10B1AD8
#define pinstCTipWndCONTEXT_x                                      0x10B1ADC
#define pinstCTitleWnd_x                                           0x10B1B58
#define pinstCContextMenuManager_x                                 0x1715584
#define pinstCVoiceMacroWnd_x                                      0xF9E528
#define pinstCHtmlWnd_x                                            0xF9E618
#define pinstIconCache_x                                           0x10AC07C
#define pinstCTradeskillWnd_x                                      0x10B1C58
#define pinstCAdvancedLootWnd_x                                    0xE57374
#define pinstRewardSelectionWnd_x                                  0x10B0398

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x53A660
#define __ConvertItemTags_x                                        0x527EC0
#define __ExecuteCmd_x                                             0x5127E0
#define __EQGetTime_x                                              0x890FC0
#define __get_melee_range_x                                        0x519420
#define __GetGaugeValueFromEQ_x                                    0x7A2240
#define __GetLabelFromEQ_x                                         0x7A3610
#define __ToggleKeyRingItem_x                                      0x482070
#define __GetXTargetType_x                                         0x9217C0
#define __LoadFrontEnd_x                                           0x630010
#define __NewUIINI_x                                               0x7A1C10
#define __ProcessGameEvents_x                                      0x573F50
#define __ProcessMouseEvent_x                                      0x5736F0
#define CrashDetected_x                                            0x6319D0
#define wwsCrashReportCheckForUploader_x                           0x7F00C0
#define __AppCrashWrapper_x                                        0xC4E59C
#define __pCrashHandler_x                                          0x10BEB08
#define __CrashHandler_x                                           0x7EFB50
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F22F0
#define DrawNetStatus_x                                            0x5AA260
#define Util__FastTime_x                                           0x890C60
#define Expansion_HoT_x                                            0xF18FA8
#define __HelpPath_x                                               0xF9C6B0
#define __STMLToText_x                                             0x8D6E10

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420630
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B3D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B1B0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C9690
#define AltAdvManager__IsAbilityReady_x                            0x4C9700
#define AltAdvManager__GetAAById_x                                 0x4C9BF0
#define AltAdvManager__CanTrainAbility_x                           0x4CA820
#define AltAdvManager__CanSeeAbility_x                             0x4CA3E0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4638D0
#define CharacterZoneClient__MakeMeVisible_x                       0x4682E0
#define CharacterZoneClient__IsStackBlocked_x                      0x447C20
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4470E0
#define CharacterZoneClient__GetItemCountWorn_x                    0x461660
#define CharacterZoneClient__GetItemCountInInventory_x             0x461740
#define CharacterZoneClient__GetCursorItemCount_x                  0x461820
#define CharacterZoneClient__FindAffectSlot_x                      0x44D160

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65F830

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66DCE0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5895F0
#define CButtonWnd__CButtonWnd_x                                   0x8CB170

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x688D30
#define CChatManager__InitContextMenu_x                            0x689E80
#define CChatManager__FreeChatWindow_x                             0x688810
#define CChatManager__GetLockedActiveChatWindow_x                  0x691630
#define CChatManager__SetLockedActiveChatWindow_x                  0x688D00
// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D5180
#define CContextMenu__dCContextMenu_x                              0x8D5390
#define CContextMenu__AddMenuItem_x                                0x8D53A0
#define CContextMenu__RemoveMenuItem_x                             0x8D5680
#define CContextMenu__RemoveAllMenuItems_x                         0x8D56A0
#define CContextMenuManager__AddMenu_x                             0x8C16C0
#define CContextMenuManager__RemoveMenu_x                          0x8C1A70
#define CContextMenuManager__PopupMenu_x                           0x8C1EC0
#define CContextMenuManager__Flush_x                               0x8C1730
#define CContextMenuManager__GetMenu_x                             0x416AB0
#define CContextMenu__CheckMenuItem_x                              0x8D5720

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8753D0
#define CChatService__GetFriendName_x                              0x8753E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68F9A0
#define CChatWindow__Clear_x                                       0x68F280
#define CChatWindow__WndNotification_x                             0x68FEE0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C5530
#define CComboWnd__Draw_x                                          0x8C5740
#define CComboWnd__GetCurChoice_x                                  0x8C52E0
#define CComboWnd__GetListRect_x                                   0x8C59E0
#define CComboWnd__GetTextRect_x                                   0x8C55A0
#define CComboWnd__InsertChoice_x                                  0x8C5A50
#define CComboWnd__SetColors_x                                     0x8C5270
#define CComboWnd__SetChoice_x                                     0x8C52A0
#define CComboWnd__GetItemCount_x                                  0x8C52D0
#define CComboWnd__GetCurChoiceText_x                              0x8C5320

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x699380
#define CContainerWnd__vftable_x                                   0xAD58A0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B7AA0
#define CDisplay__GetClickedActor_x                                0x4B03D0
#define CDisplay__GetUserDefinedColor_x                            0x4AEFB0
#define CDisplay__GetWorldFilePath_x                               0x4AE400
#define CDisplay__is3dON_x                                         0x4AD890
#define CDisplay__ReloadUI_x                                       0x4C3070
#define CDisplay__WriteTextHD2_x                                   0x4B3E60

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EB770

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D96C0
#define CEditWnd__GetCharIndexPt_x                                 0x8DA740
#define CEditWnd__GetDisplayString_x                               0x8D9870
#define CEditWnd__GetHorzOffset_x                                  0x8D9BB0
#define CEditWnd__GetLineForPrintableChar_x                        0x8DA210
#define CEditWnd__GetSelStartPt_x                                  0x8DA9F0
#define CEditWnd__GetSTMLSafeText_x                                0x8D9D40
#define CEditWnd__PointFromPrintableChar_x                         0x8DA300
#define CEditWnd__SelectableCharFromPoint_x                        0x8DA480
#define CEditWnd__SetEditable_x                                    0x8D9D10

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x55B620
#define CEverQuest__ClickedPlayer_x                                0x554FE0
#define CEverQuest__CreateTargetIndicator_x                        0x555ED0
#define CEverQuest__DeleteTargetIndicator_x                        0x555F50
#define CEverQuest__DoTellWindow_x                                 0x472F30
#define CEverQuest__OutputTextToLog_x                              0x472B90
#define CEverQuest__DropHeldItemOnGround_x                         0x56BC40
#define CEverQuest__dsp_chat_x                                     0x473270
#define CEverQuest__trimName_x                                     0x551930
#define CEverQuest__Emote_x                                        0x569F90
#define CEverQuest__EnterZone_x                                    0x564F80
#define CEverQuest__GetBodyTypeDesc_x                              0x54F390
#define CEverQuest__GetClassDesc_x                                 0x558760
#define CEverQuest__GetClassThreeLetterCode_x                      0x558D60
#define CEverQuest__GetDeityDesc_x                                 0x54FC70
#define CEverQuest__GetLangDesc_x                                  0x54F720
#define CEverQuest__GetRaceDesc_x                                  0x558F20
#define CEverQuest__InterpretCmd_x                                 0x55CDA0
#define CEverQuest__LeftClickedOnPlayer_x                          0x570610
#define CEverQuest__LMouseUp_x                                     0x572710
#define CEverQuest__RightClickedOnPlayer_x                         0x571120
#define CEverQuest__RMouseUp_x                                     0x572170
#define CEverQuest__SetGameState_x                                 0x5558A0
#define CEverQuest__UPCNotificationFlush_x                         0x54D1A0
#define CEverQuest__IssuePetCommand_x                              0x55D780

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AA030
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AA090
#define CGaugeWnd__Draw_x                                          0x6AA4C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4374B0
#define CGuild__GetGuildName_x                                     0x437980
#define CGuild__GetGuildIndex_x                                    0x438B50

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C65B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D3750
#define CInvSlotMgr__MoveItem_x                                    0x6D4600
#define CInvSlotMgr__SelectSlot_x                                  0x6D3800

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D2C00
#define CInvSlot__SliderComplete_x                                 0x6D0410
#define CInvSlot__GetItemBase_x                                    0x6CF890
#define CInvSlot__UpdateItem_x                                     0x6CFE10

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D5A60
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6D6B80

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79DC40
#define CItemDisplayWnd__UpdateStrings_x                           0x6D7BF0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6E4710
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6E4C50
#define CItemDisplayWnd__SetItem_x                                 0x6EA750

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7D4FC0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6DE220

// CLabel 
#define CLabel__Draw_x                                             0x6F1410

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B1030
#define CListWnd__dCListWnd_x                                      0x8B2250
#define CListWnd__AddColumn_x                                      0x8B21F0
#define CListWnd__AddColumn1_x                                     0x8B1880
#define CListWnd__AddLine_x                                        0x8B12E0
#define CListWnd__AddString_x                                      0x8B1500
#define CListWnd__CalculateFirstVisibleLine_x                      0x8AE2E0
#define CListWnd__CalculateVSBRange_x                              0x8B04F0
#define CListWnd__ClearSel_x                                       0x8AD620
#define CListWnd__ClearAllSel_x                                    0x8AD5D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B0EC0
#define CListWnd__Compare_x                                        0x8AEE40
#define CListWnd__Draw_x                                           0x8B0100
#define CListWnd__DrawColumnSeparators_x                           0x8AFF90
#define CListWnd__DrawHeader_x                                     0x8AD8E0
#define CListWnd__DrawItem_x                                       0x8AF4D0
#define CListWnd__DrawLine_x                                       0x8AFC30
#define CListWnd__DrawSeparator_x                                  0x8B0030
#define CListWnd__EnableLine_x                                     0x8AD800
#define CListWnd__EnsureVisible_x                                  0x8AE440
#define CListWnd__ExtendSel_x                                      0x8AF3E0
#define CListWnd__GetColumnMinWidth_x                              0x8ACFD0
#define CListWnd__GetColumnWidth_x                                 0x8ACF00
#define CListWnd__GetCurSel_x                                      0x8AC6D0
#define CListWnd__GetItemAtPoint_x                                 0x8AE6D0
#define CListWnd__GetItemAtPoint1_x                                0x8AE740
#define CListWnd__GetItemData_x                                    0x8ACA10
#define CListWnd__GetItemHeight_x                                  0x8ADF50
#define CListWnd__GetItemIcon_x                                    0x8ACC00
#define CListWnd__GetItemRect_x                                    0x8AE510
#define CListWnd__GetItemText_x                                    0x8ACAB0
#define CListWnd__GetSelList_x                                     0x8B1770
#define CListWnd__GetSeparatorRect_x                               0x8AED70
#define CListWnd__InsertLine_x                                     0x8B16E0
#define CListWnd__RemoveLine_x                                     0x8B16F0
#define CListWnd__SetColors_x                                      0x8AC820
#define CListWnd__SetColumnJustification_x                         0x8AD260
#define CListWnd__SetColumnWidth_x                                 0x8ACF80
#define CListWnd__SetCurSel_x                                      0x8AC710
#define CListWnd__SetItemColor_x                                   0x8B0BB0
#define CListWnd__SetItemData_x                                    0x8AD680
#define CListWnd__SetItemText_x                                    0x8B09F0
#define CListWnd__ShiftColumnSeparator_x                           0x8B0880
#define CListWnd__Sort_x                                           0x8B2350
#define CListWnd__ToggleSel_x                                      0x8AD550

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70A420

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72B940
#define CMerchantWnd__RequestBuyItem_x                             0x732A10
#define CMerchantWnd__RequestSellItem_x                            0x7334E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72BBF0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72ADF0
#define CMerchantWnd__ActualSelect_x                               0x72F8E0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x843D20
#define CPacketScrambler__hton_x                                   0x843D30

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D0020
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D0100
#define CSidlManager__CreateLabel_x                                0x793BB0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8CE5B0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D03E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x656C10
#define CSidlScreenWnd__CalculateVSBRange_x                        0x656B30
#define CSidlScreenWnd__ConvertToRes_x                             0x8EB650
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C7EE0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C90C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C9170
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C8640
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C7890
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C6FF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C7A80
#define CSidlScreenWnd__Init1_x                                    0x8C8DA0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C7F90
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C71B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C8880
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C6C40
#define CSidlScreenWnd__StoreIniVis_x                              0x8C6FA0
#define CSidlScreenWnd__WndNotification_x                          0x8C8B20
#define CSidlScreenWnd__GetChildItem_x                             0x8C70C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BA860
#define CSidlScreenWnd__m_layoutCopy_x                             0x17155E8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F59D0
#define CSkillMgr__GetSkillCap_x                                   0x5F5BB0
#define CSkillMgr__GetNameToken_x                                  0x5F55F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EA920
#define CSliderWnd__SetValue_x                                     0x8EAAF0
#define CSliderWnd__SetNumTicks_x                                  0x8EB270

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79B8A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E62A0
#define CStmlWnd__CalculateHSBRange_x                              0x8DE8C0
#define CStmlWnd__CalculateVSBRange_x                              0x8DE830
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DEA40
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DF320
#define CStmlWnd__ForceParseNow_x                                  0x8E6BF0
#define CStmlWnd__GetNextTagPiece_x                                0x8DF220
#define CStmlWnd__GetSTMLText_x                                    0x6915F0
#define CStmlWnd__GetVisibleText_x                                 0x8DFD70
#define CStmlWnd__InitializeWindowVariables_x                      0x8E20E0
#define CStmlWnd__MakeStmlColorTag_x                               0x8DDB30
#define CStmlWnd__MakeWndNotificationTag_x                         0x8DDB90
#define CStmlWnd__SetSTMLText_x                                    0x8E3930
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E5F40
#define CStmlWnd__UpdateHistoryString_x                            0x8E0CA0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8DD250
#define CTabWnd__DrawCurrentPage_x                                 0x8DCAE0
#define CTabWnd__DrawTab_x                                         0x8DC8B0
#define CTabWnd__GetCurrentPage_x                                  0x8DCE90
#define CTabWnd__GetPageInnerRect_x                                0x8DC5A0
#define CTabWnd__GetTabInnerRect_x                                 0x8DC7A0
#define CTabWnd__GetTabRect_x                                      0x8DC670
#define CTabWnd__InsertPage_x                                      0x8DD540
#define CTabWnd__SetPage_x                                         0x8DCEC0
#define CTabWnd__SetPageRect_x                                     0x8DD190
#define CTabWnd__UpdatePage_x                                      0x8DD4E0
#define CTabWnd__GetPageFromTabIndex_x                             0x8DC800
#define CTabWnd__GetCurrentTabIndex_x                              0x8DC530

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6D6D30
#define CPageWnd__SetTabText_x                                     0x8F4620

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4330E0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C4EE0
#define CTextureFont__GetTextExtent_x                              0x8C4C40

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x62E2A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F0A60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AA980

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x596CA0
#define CXStr__CXStr1_x                                            0x8A0070
#define CXStr__CXStr3_x                                            0x88DF00
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x88E070
#define CXStr__operator_equal1_x                                   0x88E0C0
#define CXStr__operator_plus_equal1_x                              0x88F1C0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B9A40
#define CXWnd__Center_x                                            0x8BFCC0
#define CXWnd__ClrFocus_x                                          0x8B9610
#define CXWnd__Destroy_x                                           0x8C07A0
#define CXWnd__DoAllDrawing_x                                      0x8BF8F0
#define CXWnd__DrawChildren_x                                      0x8BFAA0
#define CXWnd__DrawColoredRect_x                                   0x8B9E30
#define CXWnd__DrawTooltip_x                                       0x8BA0D0
#define CXWnd__DrawTooltipAtPoint_x                                0x8BE840
#define CXWnd__GetBorderFrame_x                                    0x8BA520
#define CXWnd__GetChildWndAt_x                                     0x8C0680
#define CXWnd__GetClientClipRect_x                                 0x8BA2F0
#define CXWnd__GetScreenClipRect_x                                 0x8BEF30
#define CXWnd__GetScreenRect_x                                     0x8BA6F0
#define CXWnd__GetTooltipRect_x                                    0x8B9F60
#define CXWnd__GetWindowTextA_x                                    0x4246A0
#define CXWnd__IsActive_x                                          0x8B5040
#define CXWnd__IsDescendantOf_x                                    0x8BA460
#define CXWnd__IsReallyVisible_x                                   0x8BD880
#define CXWnd__IsType_x                                            0x8ED280
#define CXWnd__Move_x                                              0x8BCF60
#define CXWnd__Move1_x                                             0x8BF590
#define CXWnd__ProcessTransition_x                                 0x8B99E0
#define CXWnd__Refade_x                                            0x8B97B0
#define CXWnd__Resize_x                                            0x8BA7C0
#define CXWnd__Right_x                                             0x8BED30
#define CXWnd__SetFocus_x                                          0x8BC0B0
#define CXWnd__SetFont_x                                           0x8B9660
#define CXWnd__SetKeyTooltip_x                                     0x8BAA30
#define CXWnd__SetMouseOver_x                                      0x8BF270
#define CXWnd__StartFade_x                                         0x8B9A90
#define CXWnd__GetChildItem_x                                      0x8BF1B0
#define CXWnd__SetParent_x                                         0x8C0630

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B68C0
#define CXWndManager__DrawWindows_x                                0x8B6500
#define CXWndManager__GetKeyboardFlags_x                           0x8B4B70
#define CXWndManager__HandleKeyboardMsg_x                          0x8B54D0
#define CXWndManager__RemoveWnd_x                                  0x8B51D0

// CDBStr
#define CDBStr__GetString_x                                        0x4ABE40

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E1D0
#define EQ_Character__Cur_HP_x                                     0x462ED0
#define EQ_Character__Cur_Mana_x                                   0x456980
#define EQ_Character__GetAACastingTimeModifier_x                   0x4473F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F6B0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F710
#define EQ_Character__GetHPRegen_x                                 0x4660E0
#define EQ_Character__GetEnduranceRegen_x                          0x4622F0
#define EQ_Character__GetManaRegen_x                               0x466680
#define EQ_Character__Max_Endurance_x                              0x5BC3D0
#define EQ_Character__Max_HP_x                                     0x459600
#define EQ_Character__Max_Mana_x                                   0x5BC200
#define EQ_Character__doCombatAbility_x                            0x5B98F0
#define EQ_Character__UseSkill_x                                   0x46D360
#define EQ_Character__GetConLevel_x                                0x5AE840
#define EQ_Character__IsExpansionFlag_x                            0x423BE0
#define EQ_Character__TotalEffect_x                                0x44B470
#define EQ_Character__GetPCSpellAffect_x                           0x4477F0
#define EQ_Character__SpellDuration_x                              0x4456F0
#define EQ_Character__FindItemByRecord_x                           0x460330
#define EQ_Character__GetAdjustedSkill_x                           0x463680
#define EQ_Character__GetBaseSkill_x                               0x4594E0

//ProfileManager_
#define ProfileManager__GetCurrentProfile_x                        0x860E00

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5C43D0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442A20
#define CCharacterSelect__EnterWorld_x                             0x4421F0
#define CCharacterSelect__Quit_x                                   0x440DD0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58EEA0
#define EQ_Item__CreateItemTagString_x                             0x842630
#define EQ_Item__IsStackable_x                                     0x837F00
#define EQ_Item__GetImageNum_x                                     0x83A940
#define EQ_Item__CreateItemClient_x                                0x58FA80
#define EQ_Item__GetItemValue_x                                    0x841370
#define EQ_Item__ValueSellMerchant_x                               0x843970
#define EQ_Item__IsKeyRingItem_x                                   0x838950
#define EQ_Item__CanGoInBag_x                                      0x58F030
#define EQ_Item__GetMaxItemCount_x                                 0x837DF0
#define EQ_Item__GetHeldItem_x                                     0x839750
#define EQ_Item__GetAugmentFitBySlot_x                             0x843790

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4CBC80
#define EQ_LoadingS__Array_x                                       0xBF0BB0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BE860
#define EQ_PC__GetAlternateAbilityId_x                             0x84BE20
#define EQ_PC__GetCombatAbility_x                                  0x84BEB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x846B40
#define EQ_PC__GetItemRecastTimer_x                                0x5B7FA0
#define EQ_PC__HasLoreItem_x                                       0x5B1E60
#define EQ_PC__AlertInventoryChanged_x                             0x5AE810
#define EQ_PC__GetPcZoneClient_x                                   0x5D89E0
#define EQ_PC__RemoveMyAffect_x                                    0x5B7470
#define EQ_PC__GetKeyRingItems_x                                   0x846F60
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x859810
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x84DDC0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5174B0
#define EQItemList__add_object_x                                   0x5440A0
#define EQItemList__add_item_x                                     0x5173F0
#define EQItemList__delete_item_x                                  0x5178A0
#define EQItemList__FreeItemList_x                                 0x5177A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4AB0F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C4170
#define EQPlayer__dEQPlayer_x                                      0x5CC730
#define EQPlayer__DoAttack_x                                       0x5DE8D0
#define EQPlayer__EQPlayer_x                                       0x5CEE40
#define EQPlayer__SetNameSpriteState_x                             0x5C9680
#define EQPlayer__SetNameSpriteTint_x                              0x5C5580
#define PlayerBase__HasProperty_j_x                                0x91DFD0
#define EQPlayer__IsTargetable_x                                   0x91E270
#define EQPlayer__CanSee_x                                         0x91E7D0
#define PlayerZoneClient__ChangeHeight_x                           0x5DE790
#define EQPlayer__CanSeeTargetIndicator_x                          0x91E8C0
#define PlayerBase__GetVisibilityLineSegment_x                     0x91E560

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D3010
#define EQPlayerManager__GetSpawnByName_x                          0x5D3470
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D3040

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x595040
#define KeypressHandler__AttachKeyToEqCommand_x                    0x595080
#define KeypressHandler__ClearCommandStateArray_x                  0x594C30
#define KeypressHandler__HandleKeyDown_x                           0x593590
#define KeypressHandler__HandleKeyUp_x                             0x5938B0
#define KeypressHandler__SaveKeymapping_x                          0x594D00

// MapViewMap 
#define MapViewMap__Clear_x                                        0x702DB0
#define MapViewMap__SaveEx_x                                       0x7060E0

#define PlayerPointManager__GetAltCurrency_x                       0x85EEF0

// StringTable 
#define StringTable__getString_x                                   0x859B40

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BBE60
#define PcZoneClient__RemovePetEffect_x                            0x5B8470
#define PcZoneClient__HasAlternateAbility_x                        0x5B8E10
#define PcZoneClient__GetCurrentMod_x                              0x4589A0
#define PcZoneClient__GetModCap_x                                  0x456100
#define PcZoneClient__CanEquipItem_x                               0x5B93C0
#define PcZoneClient__GetItemByID_x                                0x5BDC50
#define PcZoneClient__GetItemByItemClass_x                         0x5BE780

//Doors
#define EQSwitch__UseSwitch_x                                      0x54BA70

//IconCache
#define IconCache__GetIcon_x                                       0x69F830

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x696700
#define CContainerMgr__CloseContainer_x                            0x696F20

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x763B60

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x588070

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E5EA0
#define EQ_Spell__SpellAffects_x                                   0x4E3550
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E35C0
#define CharacterZoneClient__CalcAffectChange_x                    0x446820
#define CLootWnd__LootAll_x                                        0x6F86A0
#define CLootWnd__RequestLootSlot_x                                0x6F8EB0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AAB70
#define CTargetWnd__WndNotification_x                              0x7AA660
#define CTargetWnd__RefreshTargetBuffs_x                           0x7AAD50

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AFC60

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DEB70

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x49AA20

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8D8CF0
#define CSidlManager__FindAnimation1_x                             0x8CDFE0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D3470
#define CAltAbilityData__GetMercMaxRank_x                          0x4D3420
#define CAltAbilityData__GetMaxRank_x                              0x4C7D40

//CTargetRing
#define CTargetRing__Cast_x                                        0x585970

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4550C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x472130
#define CharacterBase__CreateItemIndex_x                           0x510A20
#define CharacterBase__GetItemPossession_x                         0x440290
#define CharacterBase__GetItemByGlobalIndex_x                      0x86F090

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x67FE30
#define CCastSpellWnd__IsBardSongPlaying_x                         0x67F590

//messages
#define msg_spell_worn_off_x                                       0x4EDAC0
#define msg_new_text_x                                             0x4F7090
#define msgTokenTextParam_x                                        0x4F38F0

//SpellManager
#define SpellManager__vftable_x                                    0xAB2068
#define SpellManager__SpellManager_x                               0x47AED0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5FC8E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9222E0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E9FF0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AE20
#define ItemGlobalIndex__IsEquippedLocation_x                      0x445090
#define ItemGlobalIndex__IsValidIndex_x                            0x4548F0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x86CEA0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x86BDE0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F1660

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x69B440
#define CCursorAttachment__Deactivate_x                            0x69A980
