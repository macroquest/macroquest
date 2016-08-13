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
#define __ExpectedVersionDate                                     "Aug 11 2016"
#define __ExpectedVersionTime                                     "11:27:53"
#define __ActualVersionDate_x                                      0xACD238
#define __ActualVersionTime_x                                      0xACD244

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59C4D0
#define __MemChecker1_x                                            0x895B10
#define __MemChecker2_x                                            0x633200
#define __MemChecker3_x                                            0x633150
#define __MemChecker4_x                                            0x7E4700
#define __EncryptPad0_x                                            0xC6BC08
#define __EncryptPad1_x                                            0xDF6ED0
#define __EncryptPad2_x                                            0xCB4878
#define __EncryptPad3_x                                            0xCB4478
#define __EncryptPad4_x                                            0xDCDA30
#define __EncryptPad5_x                                            0x11A77F0
#define __AC1_x                                                    0x7A46C5
#define __AC2_x                                                    0x556497
#define __AC3_x                                                    0x554630
#define __AC4_x                                                    0x566E40
#define __AC5_x                                                    0x57999B
#define __AC6_x                                                    0x57D55E
#define __AC7_x                                                    0x57405C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EB1FC

// Direct Input
#define DI8__Main_x                                                0x11A77C8
#define DI8__Keyboard_x                                            0x11A77CC
#define DI8__Mouse_x                                               0x11A77D0
#define DI8__Mouse_Copy_x                                          0x1015EBC
#define DI8__Mouse_Check_x                                         0x109F6B4
#define __Attack_x                                                 0x109A397
#define __Autofire_x                                               0x109A398
#define __BindList_x                                               0xC2D700
#define g_eqCommandStates_x                                        0x1005320
#define __Clicks_x                                                 0x1015F78
#define __CommandList_x                                            0xC31AE8
#define __CurrentMapLabel_x                                        0x11AD250
#define __CurrentSocial_x                                          0xBE40A0
#define __DoAbilityList_x                                          0x104C64C
#define __do_loot_x                                                0x51B1D0
#define __DrawHandler_x                                            0x18141D4
#define __GroupCount_x                                             0x10068EA

#define __Guilds_x                                                 0x100C500
#define __gWorld_x                                                 0x1008DA4
#define __HotkeyPage_x                                             0x109304C
#define __HWnd_x                                                   0x109F6D0
#define __InChatMode_x                                             0x1015EA4
#define __LastTell_x                                               0x1017D48
#define __LMouseHeldTime_x                                         0x1015FE4
#define __Mouse_x                                                  0x11A77D4
#define __MouseLook_x                                              0x1015F3E
#define __MouseEventTime_x                                         0x109AB9C
#define __gpbCommandEvent_x                                        0x1008E6C
#define __NetStatusToggle_x                                        0x1015F41
#define __PCNames_x                                                0x1017368
#define __RangeAttackReady_x                                       0x10170A4
#define __RMouseHeldTime_x                                         0x1015FE0
#define __RunWalkState_x                                           0x1015EA8
#define __ScreenMode_x                                             0xF550A0
#define __ScreenX_x                                                0x1015E5C
#define __ScreenY_x                                                0x1015E58
#define __ScreenXMax_x                                             0x1015E60
#define __ScreenYMax_x                                             0x1015E64
#define __ServerHost_x                                             0x1006834
#define __ServerName_x                                             0x104C60C
#define __ShiftKeyDown_x                                           0x1016530
#define __ShowNames_x                                              0x1017264
#define __Socials_x                                                0x104C70C
#define __SubscriptionType_x                                       0x11DB37C
#define __TargetAggroHolder_x                                      0x11AF48C
#define __ZoneType_x                                               0x101633C
#define __GroupAggro_x                                             0x11AF4CC
#define __LoginName_x                                              0x109E2AC
#define __Inviter_x                                                0x109A314
#define __AttackOnAssist_x                                         0x1017220
#define __UseTellWindows_x                                         0x1017500

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1008E90
#define instEQZoneInfo_x                                           0x1016134
#define instKeypressHandler_x                                      0x109AB80
#define pinstActiveBanker_x                                        0x1008E48
#define pinstActiveCorpse_x                                        0x1008E4C
#define pinstActiveGMaster_x                                       0x1008E50
#define pinstActiveMerchant_x                                      0x1008E44
#define pinstAggroInfo_x                                           0xE12BC8
#define pinstAltAdvManager_x                                       0xF56160
#define pinstAuraMgr_x                                             0xE23338
#define pinstBandageTarget_x                                       0x1008E30
#define pinstCamActor_x                                            0xF55AB4
#define pinstCDBStr_x                                              0xF55034
#define pinstCDisplay_x                                            0x1008E58
#define pinstCEverQuest_x                                          0x11A7948
#define pinstCharData_x                                            0x1008E14
#define pinstCharSpawn_x                                           0x1008E3C
#define pinstControlledMissile_x                                   0x1008E10
#define pinstControlledPlayer_x                                    0x1008E3C
#define pinstCSidlManager_x                                        0x18135C4
#define pinstCXWndManager_x                                        0x18135BC
#define instDynamicZone_x                                          0x1015CF0
#define pinstDZMember_x                                            0x1015E00
#define pinstDZTimerInfo_x                                         0x1015E04
#define pinstEQItemList_x                                          0x1005570
#define pinstEQObjectList_x                                        0x10062E4
#define instEQMisc_x                                               0xC07EB8
#define pinstEQSoundManager_x                                      0xF566B8
#define instExpeditionLeader_x                                     0x1015D3A
#define instExpeditionName_x                                       0x1015D7A
#define pinstGroup_x                                               0x10068E6
#define pinstImeManager_x                                          0x18135C8
#define pinstLocalPlayer_x                                         0x1008E28
#define pinstMercenaryData_x                                       0x109B200
#define pinstMercenaryStats_x                                      0x11AF5D8
#define pinstMercAltAbilities_x                                    0xF564E8
#define pinstModelPlayer_x                                         0x1008E54
#define pinstPCData_x                                              0x1008E14
#define pinstSkillMgr_x                                            0x109C068
#define pinstSpawnManager_x                                        0x109B950
#define pinstSpellManager_x                                        0x109C1B0
#define pinstSpellSets_x                                           0x10930B0
#define pinstStringTable_x                                         0x1008DBC
#define pinstSwitchManager_x                                       0x1006478
#define pinstTarget_x                                              0x1008E40
#define pinstTargetObject_x                                        0x1008E18
#define pinstTargetSwitch_x                                        0x1008E1C
#define pinstTaskMember_x                                          0xF54F80
#define pinstTrackTarget_x                                         0x1008E34
#define pinstTradeTarget_x                                         0x1008E24
#define instTributeActive_x                                        0xC07EDD
#define pinstViewActor_x                                           0xF55AB0
#define pinstWorldData_x                                           0x1008DF8
#define pinstZoneAddr_x                                            0x10163D4
#define pinstPlayerPath_x                                          0x109B9B0
#define pinstTargetIndicator_x                                     0x109C348
#define pinstCTargetManager_x                                      0x109C3A8

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE130C0
#define pinstCAudioTriggersWindow_x                                0xE12F50
#define pinstCCharacterSelect_x                                    0xF55944
#define pinstCFacePick_x                                           0xF556F4
#define pinstCNoteWnd_x                                            0xF558FC
#define pinstCBookWnd_x                                            0xF55904
#define pinstCPetInfoWnd_x                                         0xF55908
#define pinstCTrainWnd_x                                           0xF5590C
#define pinstCSkillsWnd_x                                          0xF55910
#define pinstCSkillsSelectWnd_x                                    0xF55914
#define pinstCCombatSkillsSelectWnd_x                              0xF55918
#define pinstCFriendsWnd_x                                         0xF5591C
#define pinstCAuraWnd_x                                            0xF55920
#define pinstCRespawnWnd_x                                         0xF55924
#define pinstCBandolierWnd_x                                       0xF55928
#define pinstCPotionBeltWnd_x                                      0xF5592C
#define pinstCAAWnd_x                                              0xF55930
#define pinstCGroupSearchFiltersWnd_x                              0xF55934
#define pinstCLoadskinWnd_x                                        0xF55938
#define pinstCAlarmWnd_x                                           0xF5593C
#define pinstCMusicPlayerWnd_x                                     0xF55940
#define pinstCMailWnd_x                                            0xF55948
#define pinstCMailCompositionWnd_x                                 0xF5594C
#define pinstCMailAddressBookWnd_x                                 0xF55950
#define pinstCRaidWnd_x                                            0xF55958
#define pinstCRaidOptionsWnd_x                                     0xF5595C
#define pinstCBreathWnd_x                                          0xF55960
#define pinstCMapViewWnd_x                                         0xF55964
#define pinstCMapToolbarWnd_x                                      0xF55968
#define pinstCEditLabelWnd_x                                       0xF5596C
#define pinstCTargetWnd_x                                          0xF55970
#define pinstCColorPickerWnd_x                                     0xF55974
#define pinstCPlayerWnd_x                                          0xF55978
#define pinstCOptionsWnd_x                                         0xF5597C
#define pinstCBuffWindowNORMAL_x                                   0xF55980
#define pinstCBuffWindowSHORT_x                                    0xF55984
#define pinstCharacterCreation_x                                   0xF55988
#define pinstCCursorAttachment_x                                   0xF5598C
#define pinstCCastingWnd_x                                         0xF55990
#define pinstCCastSpellWnd_x                                       0xF55994
#define pinstCSpellBookWnd_x                                       0xF55998
#define pinstCInventoryWnd_x                                       0xF5599C
#define pinstCBankWnd_x                                            0xF559A4
#define pinstCQuantityWnd_x                                        0xF559A8
#define pinstCLootWnd_x                                            0xF559AC
#define pinstCActionsWnd_x                                         0xF559B0
#define pinstCCombatAbilityWnd_x                                   0xF559B4
#define pinstCMerchantWnd_x                                        0xF559B8
#define pinstCTradeWnd_x                                           0xF559BC
#define pinstCSelectorWnd_x                                        0xF559C0
#define pinstCBazaarWnd_x                                          0xF559C4
#define pinstCBazaarSearchWnd_x                                    0xF559C8
#define pinstCGiveWnd_x                                            0xF559E4
#define pinstCTrackingWnd_x                                        0xF559EC
#define pinstCInspectWnd_x                                         0xF559F0
#define pinstCSocialEditWnd_x                                      0xF559F4
#define pinstCFeedbackWnd_x                                        0xF559F8
#define pinstCBugReportWnd_x                                       0xF559FC
#define pinstCVideoModesWnd_x                                      0xF55A00
#define pinstCTextEntryWnd_x                                       0xF55A08
#define pinstCFileSelectionWnd_x                                   0xF55A0C
#define pinstCCompassWnd_x                                         0xF55A10
#define pinstCPlayerNotesWnd_x                                     0xF55A14
#define pinstCGemsGameWnd_x                                        0xF55A18
#define pinstCTimeLeftWnd_x                                        0xF55A1C
#define pinstCPetitionQWnd_x                                       0xF55A38
#define pinstCSoulmarkWnd_x                                        0xF55A3C
#define pinstCStoryWnd_x                                           0xF55A40
#define pinstCJournalTextWnd_x                                     0xF55A44
#define pinstCJournalCatWnd_x                                      0xF55A48
#define pinstCBodyTintWnd_x                                        0xF55A4C
#define pinstCServerListWnd_x                                      0xF55A50
#define pinstCAvaZoneWnd_x                                         0xF55A5C
#define pinstCBlockedBuffWnd_x                                     0xF55A60
#define pinstCBlockedPetBuffWnd_x                                  0xF55A64
#define pinstCInvSlotMgr_x                                         0xF55AA8
#define pinstCContainerMgr_x                                       0xF55AAC
#define pinstCAdventureLeaderboardWnd_x                            0x11A82F8
#define pinstCAdventureRequestWnd_x                                0x11A8370
#define pinstCAltStorageWnd_x                                      0x11A8650
#define pinstCAdventureStatsWnd_x                                  0x11A83E8
#define pinstCBarterMerchantWnd_x                                  0x11A9238
#define pinstCBarterSearchWnd_x                                    0x11A92B0
#define pinstCBarterWnd_x                                          0x11A9328
#define pinstCChatManager_x                                        0x11A99B8
#define pinstCDynamicZoneWnd_x                                     0x11A9E68
#define pinstCEQMainWnd_x                                          0x11AA000
#define pinstCFellowshipWnd_x                                      0x11A9DFC
#define pinstCFindLocationWnd_x                                    0x11AA2D0
#define pinstCGroupSearchWnd_x                                     0x11AA5A0
#define pinstCGroupWnd_x                                           0x11AA618
#define pinstCGuildBankWnd_x                                       0x11AA690
#define pinstCGuildMgmtWnd_x                                       0x11AC780
#define pinstCHotButtonWnd_x                                       0x11AC87C
#define pinstCHotButtonWnd1_x                                      0x11AC87C
#define pinstCHotButtonWnd2_x                                      0x11AC880
#define pinstCHotButtonWnd3_x                                      0x11AC884
#define pinstCHotButtonWnd4_x                                      0x11AC8A8
#define pinstCItemDisplayManager_x                                 0x11ACBA0
#define pinstCItemExpTransferWnd_x                                 0x11ACC1C
#define pinstCLFGuildWnd_x                                         0x11ACEF8
#define pinstCMIZoneSelectWnd_x                                    0x11AD4E0
#define pinstCConfirmationDialog_x                                 0x11ADBE8
#define pinstCPopupWndManager_x                                    0x11ADBE8
#define pinstCProgressionSelectionWnd_x                            0x11ADCD8
#define pinstCPvPStatsWnd_x                                        0x11ADDC8
#define pinstCSystemInfoDialogBox_x                                0x11AE4D0
#define pinstCTaskWnd_x                                            0x11AF898
#define pinstCTaskSomething_x                                      0xE23B28
#define pinstCTaskTemplateSelectWnd_x                              0x11AF820
#define pinstCTipWndOFDAY_x                                        0x11AFA00
#define pinstCTipWndCONTEXT_x                                      0x11AFA04
#define pinstCTitleWnd_x                                           0x11AFA80
#define pinstCContextMenuManager_x                                 0x1813534
#define pinstCVoiceMacroWnd_x                                      0x109C780
#define pinstCHtmlWnd_x                                            0x109C870
#define pinstIconCache_x                                           0x11A9FD4
#define pinstCTradeskillWnd_x                                      0x11AFB80
#define pinstCAdvancedLootWnd_x                                    0xF55A9C
#define pinstRewardSelectionWnd_x                                  0x11AE2F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x532330
#define __ConvertItemTags_x                                        0x51FD30
#define __ExecuteCmd_x                                             0x50A630
#define __EQGetTime_x                                              0x895740
#define __get_melee_range_x                                        0x5111F0
#define __GetGaugeValueFromEQ_x                                    0x7A3400
#define __GetLabelFromEQ_x                                         0x7A4650
#define __ToggleKeyRingItem_x                                      0x47D470
#define __GetXTargetType_x                                         0x926740
#define __LoadFrontEnd_x                                           0x6328D0
#define __NewUIINI_x                                               0x7A2DE0
#define __ProcessGameEvents_x                                      0x575DC0
#define __ProcessMouseEvent_x                                      0x575560
#define CrashDetected_x                                            0x634290
#define wwsCrashReportCheckForUploader_x                           0x7F3190
#define DrawNetStatus_x                                            0x5ABEE0
#define Util__FastTime_x                                           0x895250
#define Expansion_HoT_x                                            0x1017210
#define __HelpPath_x                                               0x109A908
#define __STMLToText_x                                             0x8DB520

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4204E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B340
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B120

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C4320
#define AltAdvManager__IsAbilityReady_x                            0x4C4390
#define AltAdvManager__GetAAById_x                                 0x4C4750
#define AltAdvManager__CanTrainAbility_x                           0x4C5010
#define AltAdvManager__CanSeeAbility_x                             0x4C4C10

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x462DD0
#define CharacterZoneClient__MakeMeVisible_x                       0x467870
#define CharacterZoneClient__IsStackBlocked_x                      0x4473D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446890
#define CharacterZoneClient__GetItemCountWorn_x                    0x460C30
#define CharacterZoneClient__GetItemCountInInventory_x             0x460D10
#define CharacterZoneClient__GetCursorItemCount_x                  0x460DF0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6625E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x670F60

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58B450
#define CButtonWnd__CButtonWnd_x                                   0x8CF880

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68B9E0
#define CChatManager__InitContextMenu_x                            0x68C560

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D9880
#define CContextMenu__dCContextMenu_x                              0x8D9A90
#define CContextMenu__AddMenuItem_x                                0x8D9AA0
#define CContextMenu__RemoveMenuItem_x                             0x8D9D90
#define CContextMenu__RemoveAllMenuItems_x                         0x8D9DB0
#define CContextMenuManager__AddMenu_x                             0x8C5E40
#define CContextMenuManager__RemoveMenu_x                          0x8C6190
#define CContextMenuManager__PopupMenu_x                           0x8C65E0
#define CContextMenuManager__Flush_x                               0x8C5EB0
#define CContextMenuManager__GetMenu_x                             0x416980

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87A110
#define CChatService__GetFriendName_x                              0x87A120

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6917C0
#define CChatWindow__Clear_x                                       0x691390
#define CChatWindow__WndNotification_x                             0x691D00

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C9C30
#define CComboWnd__Draw_x                                          0x8C9E40
#define CComboWnd__GetCurChoice_x                                  0x8C99F0
#define CComboWnd__GetListRect_x                                   0x8CA0E0
#define CComboWnd__GetTextRect_x                                   0x8C9CA0
#define CComboWnd__InsertChoice_x                                  0x8CA150
#define CComboWnd__SetColors_x                                     0x8C9980
#define CComboWnd__SetChoice_x                                     0x8C99B0
#define CComboWnd__GetItemCount_x                                  0x8C99E0
#define CComboWnd__GetCurChoiceText_x                              0x8C9A30

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69AD60
#define CContainerWnd__vftable_x                                   0xAD6C30

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B27D0
#define CDisplay__GetClickedActor_x                                0x4AB0A0
#define CDisplay__GetUserDefinedColor_x                            0x4A9C80
#define CDisplay__GetWorldFilePath_x                               0x4A90D0
#define CDisplay__is3dON_x                                         0x4A8560
#define CDisplay__ReloadUI_x                                       0x4BDCC0
#define CDisplay__WriteTextHD2_x                                   0x4AEB20

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EFF10

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DDDB0
#define CEditWnd__GetCharIndexPt_x                                 0x8DEE40
#define CEditWnd__GetDisplayString_x                               0x8DDF60
#define CEditWnd__GetHorzOffset_x                                  0x8DE2A0
#define CEditWnd__GetLineForPrintableChar_x                        0x8DE910
#define CEditWnd__GetSelStartPt_x                                  0x8DF0F0
#define CEditWnd__GetSTMLSafeText_x                                0x8DE440
#define CEditWnd__PointFromPrintableChar_x                         0x8DEA00
#define CEditWnd__SelectableCharFromPoint_x                        0x8DEB80
#define CEditWnd__SetEditable_x                                    0x8DE410

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x556BE0
#define CEverQuest__CreateTargetIndicator_x                        0x557AD0
#define CEverQuest__DeleteTargetIndicator_x                        0x557B50
#define CEverQuest__DoTellWindow_x                                 0x472460
#define CEverQuest__DropHeldItemOnGround_x                         0x56DC80
#define CEverQuest__dsp_chat_x                                     0x4727A0
#define CEverQuest__trimName_x                                     0x553530
#define CEverQuest__Emote_x                                        0x56BFD0
#define CEverQuest__EnterZone_x                                    0x566FD0
#define CEverQuest__GetBodyTypeDesc_x                              0x550F90
#define CEverQuest__GetClassDesc_x                                 0x55A860
#define CEverQuest__GetClassThreeLetterCode_x                      0x55AE60
#define CEverQuest__GetDeityDesc_x                                 0x551870
#define CEverQuest__GetLangDesc_x                                  0x551320
#define CEverQuest__GetRaceDesc_x                                  0x55B020
#define CEverQuest__InterpretCmd_x                                 0x55EE30
#define CEverQuest__LeftClickedOnPlayer_x                          0x5724B0
#define CEverQuest__LMouseUp_x                                     0x5745B0
#define CEverQuest__RightClickedOnPlayer_x                         0x572FC0
#define CEverQuest__RMouseUp_x                                     0x574010
#define CEverQuest__SetGameState_x                                 0x5574A0
#define CEverQuest__UPCNotificationFlush_x                         0x54EDB0
#define CEverQuest__IssuePetCommand_x                              0x55F810

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6ABA90
#define CGaugeWnd__CalcLinesFillRect_x                             0x6ABAF0
#define CGaugeWnd__Draw_x                                          0x6ABF20

// CGuild
#define CGuild__FindMemberByName_x                                 0x437300

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C7F00

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D5090
#define CInvSlotMgr__MoveItem_x                                    0x6D5F30
#define CInvSlotMgr__SelectSlot_x                                  0x6D5140

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D4540
#define CInvSlot__SliderComplete_x                                 0x6D1D50
#define CInvSlot__GetItemBase_x                                    0x6D11D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D7390

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79EE30
#define CItemDisplayWnd__UpdateStrings_x                           0x6D94D0

// CLabel 
#define CLabel__Draw_x                                             0x6F2B70

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B5B50
#define CListWnd__dCListWnd_x                                      0x8B6B80
#define CListWnd__AddColumn_x                                      0x8B6B20
#define CListWnd__AddColumn1_x                                     0x8B63A0
#define CListWnd__AddLine_x                                        0x8B5E10
#define CListWnd__AddString_x                                      0x8B6030
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B2E10
#define CListWnd__CalculateVSBRange_x                              0x8B5010
#define CListWnd__ClearSel_x                                       0x8B2120
#define CListWnd__ClearAllSel_x                                    0x8B20D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B59E0
#define CListWnd__Compare_x                                        0x8B3980
#define CListWnd__Draw_x                                           0x8B4C10
#define CListWnd__DrawColumnSeparators_x                           0x8B4AA0
#define CListWnd__DrawHeader_x                                     0x8B23E0
#define CListWnd__DrawItem_x                                       0x8B3FD0
#define CListWnd__DrawLine_x                                       0x8B4740
#define CListWnd__DrawSeparator_x                                  0x8B4B40
#define CListWnd__EnsureVisible_x                                  0x8B2F70
#define CListWnd__ExtendSel_x                                      0x8B3EE0
#define CListWnd__GetColumnMinWidth_x                              0x8B1AD0
#define CListWnd__GetColumnWidth_x                                 0x8B1A00
#define CListWnd__GetCurSel_x                                      0x8B11C0
#define CListWnd__GetItemAtPoint_x                                 0x8B3210
#define CListWnd__GetItemAtPoint1_x                                0x8B3280
#define CListWnd__GetItemData_x                                    0x8B1510
#define CListWnd__GetItemHeight_x                                  0x8B2A60
#define CListWnd__GetItemIcon_x                                    0x8B1700
#define CListWnd__GetItemRect_x                                    0x8B3050
#define CListWnd__GetItemText_x                                    0x8B15B0
#define CListWnd__GetSelList_x                                     0x8B6290
#define CListWnd__GetSeparatorRect_x                               0x8B38A0
#define CListWnd__RemoveLine_x                                     0x8B6210
#define CListWnd__SetColors_x                                      0x8B1310
#define CListWnd__SetColumnJustification_x                         0x8B1D60
#define CListWnd__SetColumnWidth_x                                 0x8B1A80
#define CListWnd__SetCurSel_x                                      0x8B1200
#define CListWnd__SetItemColor_x                                   0x8B56D0
#define CListWnd__SetItemData_x                                    0x8B2180
#define CListWnd__SetItemText_x                                    0x8B5510
#define CListWnd__ShiftColumnSeparator_x                           0x8B53A0
#define CListWnd__Sort_x                                           0x8B6C80
#define CListWnd__ToggleSel_x                                      0x8B2050

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70BCF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72D0D0
#define CMerchantWnd__RequestBuyItem_x                             0x734130
#define CMerchantWnd__RequestSellItem_x                            0x734BF0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72D380
#define CMerchantWnd__SelectBuySellSlot_x                          0x72C580
#define CMerchantWnd__ActualSelect_x                               0x731010

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x846C90
#define CPacketScrambler__hton_x                                   0x846CA0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D4880
#define CSidlManager__CreateLabel_x                                0x794D50

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6599C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6598E0
#define CSidlScreenWnd__ConvertToRes_x                             0x8EFDF0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CC5E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CD7B0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CD860
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CCD30
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CBF90
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CB6F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CC180
#define CSidlScreenWnd__Init1_x                                    0x8CD490
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CC690
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CB8B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CCF70
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CB350
#define CSidlScreenWnd__StoreIniVis_x                              0x8CB6A0
#define CSidlScreenWnd__WndNotification_x                          0x8CD210
#define CSidlScreenWnd__GetChildItem_x                             0x8CB7C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BF0E0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1813598

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F75E0
#define CSkillMgr__GetSkillCap_x                                   0x5F77C0
#define CSkillMgr__GetNameToken_x                                  0x5F7200

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EF0A0
#define CSliderWnd__SetValue_x                                     0x8EF270
#define CSliderWnd__SetNumTicks_x                                  0x8EF9F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79CA90

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EAA40
#define CStmlWnd__CalculateHSBRange_x                              0x8E2F60
#define CStmlWnd__CalculateVSBRange_x                              0x8E2FF0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E3170
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E3A50
#define CStmlWnd__ForceParseNow_x                                  0x8EB390
#define CStmlWnd__GetNextTagPiece_x                                0x8E3950
#define CStmlWnd__GetSTMLText_x                                    0x690C30
#define CStmlWnd__GetVisibleText_x                                 0x8E44A0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E6830
#define CStmlWnd__MakeStmlColorTag_x                               0x8E2260
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E22C0
#define CStmlWnd__SetSTMLText_x                                    0x8E8090
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EA6E0
#define CStmlWnd__UpdateHistoryString_x                            0x8E53E0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E1970
#define CTabWnd__DrawCurrentPage_x                                 0x8E1200
#define CTabWnd__DrawTab_x                                         0x8E0FC0
#define CTabWnd__GetCurrentPage_x                                  0x8E15B0
#define CTabWnd__GetPageInnerRect_x                                0x8E0CB0
#define CTabWnd__GetTabInnerRect_x                                 0x8E0EB0
#define CTabWnd__GetTabRect_x                                      0x8E0D80
#define CTabWnd__InsertPage_x                                      0x8E1C60
#define CTabWnd__SetPage_x                                         0x8E15E0
#define CTabWnd__SetPageRect_x                                     0x8E18B0
#define CTabWnd__UpdatePage_x                                      0x8E1C00

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432E60

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C95F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F5220

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AF3B0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x598980
#define CXStr__CXStr1_x                                            0x8F3F90
#define CXStr__CXStr3_x                                            0x892340
#define CXStr__dCXStr_x                                            0x4BE610
#define CXStr__operator_equal_x                                    0x8924B0
#define CXStr__operator_equal1_x                                   0x892500
#define CXStr__operator_plus_equal1_x                              0x893600

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BE320
#define CXWnd__Center_x                                            0x8C4430
#define CXWnd__ClrFocus_x                                          0x8BDF00
#define CXWnd__DoAllDrawing_x                                      0x8C4080
#define CXWnd__DrawChildren_x                                      0x8C4220
#define CXWnd__DrawColoredRect_x                                   0x8BE6D0
#define CXWnd__DrawTooltip_x                                       0x8BE980
#define CXWnd__DrawTooltipAtPoint_x                                0x8C3040
#define CXWnd__GetBorderFrame_x                                    0x8BEDC0
#define CXWnd__GetChildWndAt_x                                     0x8C4E00
#define CXWnd__GetClientClipRect_x                                 0x8BEB90
#define CXWnd__GetScreenClipRect_x                                 0x8C3740
#define CXWnd__GetScreenRect_x                                     0x8BEF90
#define CXWnd__GetTooltipRect_x                                    0x8BE810
#define CXWnd__GetWindowTextA_x                                    0x424480
#define CXWnd__IsActive_x                                          0x8B9940
#define CXWnd__IsDescendantOf_x                                    0x8BED00
#define CXWnd__IsReallyVisible_x                                   0x8C2060
#define CXWnd__IsType_x                                            0x8F1A30
#define CXWnd__Move_x                                              0x8C17B0
#define CXWnd__Move1_x                                             0x8C3D30
#define CXWnd__ProcessTransition_x                                 0x8BE2D0
#define CXWnd__Refade_x                                            0x8BE0B0
#define CXWnd__Resize_x                                            0x8BF050
#define CXWnd__Right_x                                             0x8C3540
#define CXWnd__SetFocus_x                                          0x8C0910
#define CXWnd__SetFont_x                                           0x8BDF50
#define CXWnd__SetKeyTooltip_x                                     0x8BF2B0
#define CXWnd__SetMouseOver_x                                      0x8C3A40
#define CXWnd__StartFade_x                                         0x8BE370
#define CXWnd__GetChildItem_x                                      0x8C3990

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BB1E0
#define CXWndManager__DrawWindows_x                                0x8BAE20
#define CXWndManager__GetKeyboardFlags_x                           0x8B9470
#define CXWndManager__HandleKeyboardMsg_x                          0x8B9DD0
#define CXWndManager__RemoveWnd_x                                  0x8B9AD0

// CDBStr
#define CDBStr__GetString_x                                        0x4A6AB0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44D980
#define EQ_Character__Cur_HP_x                                     0x462470
#define EQ_Character__Cur_Mana_x                                   0x455FD0
#define EQ_Character__GetAACastingTimeModifier_x                   0x446BA0
#define EQ_Character__GetCharInfo2_x                               0x8663E0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EF50
#define EQ_Character__GetFocusRangeModifier_x                      0x43EFB0
#define EQ_Character__Max_Endurance_x                              0x5BDDA0
#define EQ_Character__Max_HP_x                                     0x458BF0
#define EQ_Character__Max_Mana_x                                   0x5BDBD0
#define EQ_Character__doCombatAbility_x                            0x5BB2C0
#define EQ_Character__UseSkill_x                                   0x46C8F0
#define EQ_Character__GetConLevel_x                                0x5B0560
#define EQ_Character__IsExpansionFlag_x                            0x4239B0
#define EQ_Character__TotalEffect_x                                0x44AC20
#define EQ_Character__GetPCSpellAffect_x                           0x446FA0
#define EQ_Character__SpellDuration_x                              0x444EA0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x4421D0
#define CCharacterSelect__EnterWorld_x                             0x4419A0
#define CCharacterSelect__Quit_x                                   0x440580

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x590C60
#define EQ_Item__CreateItemTagString_x                             0x8455D0
#define EQ_Item__IsStackable_x                                     0x83AD20
#define EQ_Item__GetImageNum_x                                     0x83D740
#define EQ_Item__CreateItemClient_x                                0x591850
#define EQ_Item__GetItemValue_x                                    0x844300
#define EQ_Item__ValueSellMerchant_x                               0x8468E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C64E0
#define EQ_LoadingS__Array_x                                       0xC14728

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C02C0
#define EQ_PC__GetAlternateAbilityId_x                             0x84EC90
#define EQ_PC__GetCombatAbility_x                                  0x84ED20
#define EQ_PC__GetCombatAbilityTimer_x                             0x849AA0
#define EQ_PC__GetItemTimerValue_x                                 0x5B9970
#define EQ_PC__HasLoreItem_x                                       0x5B3A90
#define EQ_PC__AlertInventoryChanged_x                             0x5B0530
#define EQ_PC__GetPcZoneClient_x                                   0x5DA9D0
#define EQ_PC__RemoveMyAffect_x                                    0x5B8E20

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50F270
#define EQItemList__add_object_x                                   0x53B960
#define EQItemList__add_item_x                                     0x50F1B0
#define EQItemList__delete_item_x                                  0x50F660
#define EQItemList__FreeItemList_x                                 0x50F560

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A5D80

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C5950
#define EQPlayer__dEQPlayer_x                                      0x5CE770
#define EQPlayer__DoAttack_x                                       0x5E0730
#define EQPlayer__EQPlayer_x                                       0x5D0B90
#define EQPlayer__SetNameSpriteState_x                             0x5CB710
#define EQPlayer__SetNameSpriteTint_x                              0x5C6D90
#define PlayerBase__HasProperty_j_x                                0x922980
#define EQPlayer__IsTargetable_x                                   0x923280
#define EQPlayer__CanSee_x                                         0x9237A0
#define PlayerZoneClient__ChangeHeight_x                           0x5E05F0
#define EQPlayer__CanSeeTargetIndicator_x                          0x923890

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D4ED0
#define EQPlayerManager__GetSpawnByName_x                          0x5D5330
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D4F00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x596D20
#define KeypressHandler__AttachKeyToEqCommand_x                    0x596D60
#define KeypressHandler__ClearCommandStateArray_x                  0x596910
#define KeypressHandler__HandleKeyDown_x                           0x595270
#define KeypressHandler__HandleKeyUp_x                             0x595590
#define KeypressHandler__SaveKeymapping_x                          0x5969E0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x704680
#define MapViewMap__SaveEx_x                                       0x7079B0

#define PlayerPointManager__GetAltCurrency_x                       0x8613D0

// StringTable 
#define StringTable__getString_x                                   0x85BFF0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BD830
#define PcZoneClient__RemovePetEffect_x                            0x5B9E40
#define PcZoneClient__HasAlternateAbility_x                        0x5BA7E0
#define PcZoneClient__GetCurrentMod_x                              0x457F90
#define PcZoneClient__GetModCap_x                                  0x455750

//Doors
#define EQSwitch__UseSwitch_x                                      0x54D6E0

//IconCache
#define IconCache__GetIcon_x                                       0x6A1330

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6980E0
#define CContainerMgr__CloseContainer_x                            0x698900

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x764F90

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x589ED0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DE580
#define EQ_Spell__SpellAffects_x                                   0x4DBC30
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DBCA0
#define CharacterZoneClient__CalcAffectChange_x                    0x445FD0
#define CLootWnd__LootAll_x                                        0x6F9F10

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AB8C0
#define CTargetWnd__WndNotification_x                              0x7AB3B0
#define CTargetWnd__UpdateBuffs_x                                  0x7ABAA0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B0AA0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D7490

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x495C40

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DD3E0
#define CSidlManager__FindAnimation1_x                             0x8D2760

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CDC50
#define CAltAbilityData__GetMercMaxRank_x                          0x4CDC00
#define CAltAbilityData__GetMaxRank_x                              0x4C29D0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5877B0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454860

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x682B20
#define CCastSpellWnd__IsBardSongPlaying_x                         0x682280

//messages
#define msg_spell_worn_off_x                                       0x4E5FD0
#define msg_new_text_x                                             0x4EF430
#define msgTokenTextParam_x                                        0x4EBE00

//SpellManager
#define SpellManager__vftable_x                                    0xAB2EF8
#define SpellManager__SpellManager_x                               0x47A330
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5FE430
