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
#define __ExpectedVersionDate                                     "Feb 12 2016"
#define __ExpectedVersionTime                                     "16:33:51"
#define __ActualVersionDate_x                                      0xADB638
#define __ActualVersionTime_x                                      0xADB644

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5A0030
#define __MemChecker1_x                                            0x8A31E0
#define __MemChecker2_x                                            0x639880
#define __MemChecker3_x                                            0x6397D0
#define __MemChecker4_x                                            0x7EEB50
#define __EncryptPad0_x                                            0xC78710
#define __EncryptPad1_x                                            0xE04060
#define __EncryptPad2_x                                            0xCC2370
#define __EncryptPad3_x                                            0xCC1F70
#define __EncryptPad4_x                                            0xDDD0D0
#define __EncryptPad5_x                                            0x11AFF58
#define __AC1_x                                                    0x7ABC45
#define __AC2_x                                                    0x554207
#define __AC3_x                                                    0x568DF0
#define __AC4_x                                                    0x56FB30
#define __AC5_x                                                    0x57C2EE
#define __AC6_x                                                    0x57FEA9
#define __AC7_x                                                    0x57699C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FB268

// Direct Input
#define DI8__Main_x                                                0x11AFF30
#define DI8__Keyboard_x                                            0x11AFF34
#define DI8__Mouse_x                                               0x11AFF38
#define DI8__Mouse_Copy_x                                          0x101E53C
#define DI8__Mouse_Check_x                                         0x10A7E1C
#define __Attack_x                                                 0x10A2ABB
#define __Autofire_x                                               0x10A2ABC
#define __BindList_x                                               0xC3A6A8
#define __bCommandEnabled_x                                        0x100D998
#define __Clicks_x                                                 0x101E5F8
#define __CommandList_x                                            0xC3EA30
#define __CurrentMapLabel_x                                        0x11B5988
#define __CurrentSocial_x                                          0xBF168C
#define __DoAbilityList_x                                          0x1054D70
#define __do_loot_x                                                0x51BAA0
#define __DrawHandler_x                                            0x181C73C
#define __GroupCount_x                                             0x100EF62

#define __Guilds_x                                                 0x1014B78
#define __gWorld_x                                                 0x101141C
#define __HotkeyPage_x                                             0x109B770
#define __HWnd_x                                                   0x10A7E38
#define __InChatMode_x                                             0x101E524
#define __LastTell_x                                               0x102046C
#define __LMouseHeldTime_x                                         0x101E664
#define __Mouse_x                                                  0x11AFF3C
#define __MouseLook_x                                              0x101E5BE
#define __MouseEventTime_x                                         0x10A32C4
#define __gpbCommandEvent_x                                        0x10114E4
#define __NetStatusToggle_x                                        0x101E5C1
#define __PCNames_x                                                0x101FA8C
#define __RangeAttackReady_x                                       0x101F748
#define __RMouseHeldTime_x                                         0x101E660
#define __RunWalkState_x                                           0x101E528
#define __ScreenMode_x                                             0xF5D6C8
#define __ScreenX_x                                                0x101E4DC
#define __ScreenY_x                                                0x101E4D8
#define __ScreenXMax_x                                             0x101E4E0
#define __ScreenYMax_x                                             0x101E4E4
#define __ServerHost_x                                             0x100EEAC
#define __ServerName_x                                             0x1054D30
#define __ShiftKeyDown_x                                           0x101EBCC
#define __ShowNames_x                                              0x101F91C
#define __Socials_x                                                0x1054E30
#define __SubscriptionType_x                                       0x11E3EB8
#define __TargetAggroHolder_x                                      0x11B7BC4
#define __GroupAggro_x                                             0x11B7C04
#define __LoginName_x                                              0x10A6A10
#define __Inviter_x                                                0x10A2A38
#define __AttackOnAssist_x                                         0x101F8C4 

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1011508
#define instEQZoneInfo_x                                           0x101E7B4
#define instKeypressHandler_x                                      0x10A32A8
#define pinstActiveBanker_x                                        0x10114C0
#define pinstActiveCorpse_x                                        0x10114C4
#define pinstActiveGMaster_x                                       0x10114C8
#define pinstActiveMerchant_x                                      0x10114BC
#define pinstAggroInfo_x                                           0xE1FAC0
#define pinstAltAdvManager_x                                       0xF5E7D0
#define pinstAuraMgr_x                                             0xE2B990
#define pinstBandageTarget_x                                       0x10114A8
#define pinstCamActor_x                                            0xF5E0DC
#define pinstCDBStr_x                                              0xF5D65C
#define pinstCDisplay_x                                            0x10114D0
#define pinstCEverQuest_x                                          0x11B00B0
#define pinstCharData_x                                            0x101148C
#define pinstCharSpawn_x                                           0x10114B4
#define pinstControlledMissile_x                                   0x1011488
#define pinstControlledPlayer_x                                    0x10114B4
#define pinstCSidlManager_x                                        0x181BC7C
#define pinstCXWndManager_x                                        0x181BC74
#define instDynamicZone_x                                          0x101E370
#define pinstDZMember_x                                            0x101E480
#define pinstDZTimerInfo_x                                         0x101E484
#define pinstEQItemList_x                                          0x100DBE8
#define instEQMisc_x                                               0xC13AD0
#define pinstEQSoundManager_x                                      0xF5ED30
#define instExpeditionLeader_x                                     0x101E3BA
#define instExpeditionName_x                                       0x101E3FA
#define pinstGroup_x                                               0x100EF5E
#define pinstImeManager_x                                          0x181BC80
#define pinstLocalPlayer_x                                         0x10114A0
#define pinstMercenaryData_x                                       0x10A38F8
#define pinstMercenaryStats_x                                      0x11B7D10
#define pinstMercAltAbilities_x                                    0xF5EB5C
#define pinstModelPlayer_x                                         0x10114CC
#define pinstPCData_x                                              0x101148C
#define pinstSkillMgr_x                                            0x10A4730
#define pinstSpawnManager_x                                        0x10A4018
#define pinstSpellManager_x                                        0x10A4878
#define pinstSpellSets_x                                           0x109B7D4
#define pinstStringTable_x                                         0x1011434
#define pinstSwitchManager_x                                       0x100EAF0
#define pinstTarget_x                                              0x10114B8
#define pinstTargetObject_x                                        0x1011490
#define pinstTargetSwitch_x                                        0x1011494
#define pinstTaskMember_x                                          0xF5D5A8
#define pinstTrackTarget_x                                         0x10114AC
#define pinstTradeTarget_x                                         0x101149C
#define instTributeActive_x                                        0xC13AF5
#define pinstViewActor_x                                           0xF5E0D8
#define pinstWorldData_x                                           0x1011470
#define pinstZoneAddr_x                                            0x101EA74
#define pinstPlayerPath_x                                          0x10A4078
#define pinstTargetIndicator_x                                     0x10A4A10
#define pinstCTargetManager_x                                      0x10A4A70

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1FFA0
#define pinstCAudioTriggersWindow_x                                0xE1FE30
#define pinstCCharacterSelect_x                                    0xF5DF6C
#define pinstCFacePick_x                                           0xF5DD1C
#define pinstCNoteWnd_x                                            0xF5DF24
#define pinstCBookWnd_x                                            0xF5DF2C
#define pinstCPetInfoWnd_x                                         0xF5DF30
#define pinstCTrainWnd_x                                           0xF5DF34
#define pinstCSkillsWnd_x                                          0xF5DF38
#define pinstCSkillsSelectWnd_x                                    0xF5DF3C
#define pinstCCombatSkillsSelectWnd_x                              0xF5DF40
#define pinstCFriendsWnd_x                                         0xF5DF44
#define pinstCAuraWnd_x                                            0xF5DF48
#define pinstCRespawnWnd_x                                         0xF5DF4C
#define pinstCBandolierWnd_x                                       0xF5DF50
#define pinstCPotionBeltWnd_x                                      0xF5DF54
#define pinstCAAWnd_x                                              0xF5DF58
#define pinstCGroupSearchFiltersWnd_x                              0xF5DF5C
#define pinstCLoadskinWnd_x                                        0xF5DF60
#define pinstCAlarmWnd_x                                           0xF5DF64
#define pinstCMusicPlayerWnd_x                                     0xF5DF68
#define pinstCMailWnd_x                                            0xF5DF70
#define pinstCMailCompositionWnd_x                                 0xF5DF74
#define pinstCMailAddressBookWnd_x                                 0xF5DF78
#define pinstCRaidWnd_x                                            0xF5DF80
#define pinstCRaidOptionsWnd_x                                     0xF5DF84
#define pinstCBreathWnd_x                                          0xF5DF88
#define pinstCMapViewWnd_x                                         0xF5DF8C
#define pinstCMapToolbarWnd_x                                      0xF5DF90
#define pinstCEditLabelWnd_x                                       0xF5DF94
#define pinstCTargetWnd_x                                          0xF5DF98
#define pinstCColorPickerWnd_x                                     0xF5DF9C
#define pinstCPlayerWnd_x                                          0xF5DFA0
#define pinstCOptionsWnd_x                                         0xF5DFA4
#define pinstCBuffWindowNORMAL_x                                   0xF5DFA8
#define pinstCBuffWindowSHORT_x                                    0xF5DFAC
#define pinstCharacterCreation_x                                   0xF5DFB0
#define pinstCCursorAttachment_x                                   0xF5DFB4
#define pinstCCastingWnd_x                                         0xF5DFB8
#define pinstCCastSpellWnd_x                                       0xF5DFBC
#define pinstCSpellBookWnd_x                                       0xF5DFC0
#define pinstCInventoryWnd_x                                       0xF5DFC4
#define pinstCBankWnd_x                                            0xF5DFCC
#define pinstCQuantityWnd_x                                        0xF5DFD0
#define pinstCLootWnd_x                                            0xF5DFD4
#define pinstCActionsWnd_x                                         0xF5DFD8
#define pinstCCombatAbilityWnd_x                                   0xF5DFDC
#define pinstCMerchantWnd_x                                        0xF5DFE0
#define pinstCTradeWnd_x                                           0xF5DFE4
#define pinstCSelectorWnd_x                                        0xF5DFE8
#define pinstCBazaarWnd_x                                          0xF5DFEC
#define pinstCBazaarSearchWnd_x                                    0xF5DFF0
#define pinstCGiveWnd_x                                            0xF5E00C
#define pinstCTrackingWnd_x                                        0xF5E014
#define pinstCInspectWnd_x                                         0xF5E018
#define pinstCSocialEditWnd_x                                      0xF5E01C
#define pinstCFeedbackWnd_x                                        0xF5E020
#define pinstCBugReportWnd_x                                       0xF5E024
#define pinstCVideoModesWnd_x                                      0xF5E028
#define pinstCTextEntryWnd_x                                       0xF5E030
#define pinstCFileSelectionWnd_x                                   0xF5E034
#define pinstCCompassWnd_x                                         0xF5E038
#define pinstCPlayerNotesWnd_x                                     0xF5E03C
#define pinstCGemsGameWnd_x                                        0xF5E040
#define pinstCTimeLeftWnd_x                                        0xF5E044
#define pinstCPetitionQWnd_x                                       0xF5E060
#define pinstCSoulmarkWnd_x                                        0xF5E064
#define pinstCStoryWnd_x                                           0xF5E068
#define pinstCJournalTextWnd_x                                     0xF5E06C
#define pinstCJournalCatWnd_x                                      0xF5E070
#define pinstCBodyTintWnd_x                                        0xF5E074
#define pinstCServerListWnd_x                                      0xF5E078
#define pinstCAvaZoneWnd_x                                         0xF5E084
#define pinstCBlockedBuffWnd_x                                     0xF5E088
#define pinstCBlockedPetBuffWnd_x                                  0xF5E08C
#define pinstCInvSlotMgr_x                                         0xF5E0D0
#define pinstCContainerMgr_x                                       0xF5E0D4
#define pinstCAdventureLeaderboardWnd_x                            0x11B0A60
#define pinstCAdventureRequestWnd_x                                0x11B0AD8
#define pinstCAltStorageWnd_x                                      0x11B0DB8
#define pinstCAdventureStatsWnd_x                                  0x11B0B50
#define pinstCBarterMerchantWnd_x                                  0x11B19A0
#define pinstCBarterSearchWnd_x                                    0x11B1A18
#define pinstCBarterWnd_x                                          0x11B1A90
#define pinstCChatManager_x                                        0x11B2120
#define pinstCDynamicZoneWnd_x                                     0x11B25D0
#define pinstCEQMainWnd_x                                          0x11B2768
#define pinstCFellowshipWnd_x                                      0x11B2564
#define pinstCFindLocationWnd_x                                    0x11B2A38
#define pinstCGroupSearchWnd_x                                     0x11B2D08
#define pinstCGroupWnd_x                                           0x11B2D80
#define pinstCGuildBankWnd_x                                       0x11B2DF8
#define pinstCGuildMgmtWnd_x                                       0x11B4EE8
#define pinstCHotButtonWnd_x                                       0x11B4FB4
#define pinstCHotButtonWnd1_x                                      0x11B4FB4
#define pinstCHotButtonWnd2_x                                      0x11B4FB8
#define pinstCHotButtonWnd3_x                                      0x11B4FBC
#define pinstCHotButtonWnd4_x                                      0x11B4FE0
#define pinstCItemDisplayManager_x                                 0x11B52D8
#define pinstCItemExpTransferWnd_x                                 0x11B5354
#define pinstCLFGuildWnd_x                                         0x11B5630
#define pinstCMIZoneSelectWnd_x                                    0x11B5C18
#define pinstCConfirmationDialog_x                                 0x11B6320
#define pinstCPopupWndManager_x                                    0x11B6320
#define pinstCProgressionSelectionWnd_x                            0x11B6410
#define pinstCPvPStatsWnd_x                                        0x11B6500
#define pinstCSystemInfoDialogBox_x                                0x11B6C08
#define pinstCTaskWnd_x                                            0x11B7FD0
#define pinstCTaskSomething_x                                      0xE2C150
#define pinstCTaskTemplateSelectWnd_x                              0x11B7F58
#define pinstCTipWndOFDAY_x                                        0x11B8228
#define pinstCTipWndCONTEXT_x                                      0x11B822C
#define pinstCTitleWnd_x                                           0x11B82A8
#define pinstCContextMenuManager_x                                 0x181BBEC
#define pinstCVoiceMacroWnd_x                                      0x10A4EE0
#define pinstCHtmlWnd_x                                            0x10A4FD8
#define pinstIconCache_x                                           0x11B273C
#define pinstCTradeskillWnd_x                                      0x11B83A8
#define pinstCAdvancedLootWnd_x                                    0xF5E0C4
#define pinstRewardSelectionWnd_x                                  0x11B6A28

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5332F0
#define __ConvertItemTags_x                                        0x520720
#define __ExecuteCmd_x                                             0x50B100
#define __EQGetTime_x                                              0x8A2E10
#define __get_melee_range_x                                        0x511DD0
#define __GetGaugeValueFromEQ_x                                    0x7AA980
#define __GetLabelFromEQ_x                                         0x7ABBD0
#define __ToggleKeyRingItem_x                                      0x47F1A0
#define __GetXTargetType_x                                         0x9345E0
#define __LoadFrontEnd_x                                           0x638F30
#define __NewUIINI_x                                               0x7AA280
#define __ProcessGameEvents_x                                      0x578700
#define __ProcessMouseEvent_x                                      0x577EA0
#define CrashDetected_x                                            0x63AA00
#define wwsCrashReportCheckForUploader_x                           0x7FE630
#define DrawNetStatus_x                                            0x5AFCF0
#define Util__FastTime_x                                           0x8A2920
#define Expansion_HoT_x                                            0x101F8B4
#define __HelpPath_x                                               0x10A3030
#define __STMLToText_x                                             0x8E8EE0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420210
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B060

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C60C0
#define AltAdvManager__IsAbilityReady_x                            0x4C6130
#define AltAdvManager__GetAAById_x                                 0x4C64F0
#define AltAdvManager__CanTrainAbility_x                           0x4C6DB0
#define AltAdvManager__CanSeeAbility_x                             0x4C69B0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465110
#define CharacterZoneClient__MakeMeVisible_x                       0x46AB50
#define CharacterZoneClient__IsStackBlocked_x                      0x448EA0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x448380

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x668A90

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x677280

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58F040
#define CButtonWnd__CButtonWnd_x                                   0x8DD0C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691D40
#define CChatManager__InitContextMenu_x                            0x6928C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E7240
#define CContextMenu__dCContextMenu_x                              0x8E7450
#define CContextMenu__AddMenuItem_x                                0x8E7460
#define CContextMenu__RemoveMenuItem_x                             0x8E7740
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7760
#define CContextMenuManager__AddMenu_x                             0x8D3040
#define CContextMenuManager__RemoveMenu_x                          0x8D33A0
#define CContextMenuManager__PopupMenu_x                           0x8D37F0
#define CContextMenuManager__Flush_x                               0x8D30B0
#define CContextMenuManager__GetMenu_x                             0x4166B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x888180
#define CChatService__GetFriendName_x                              0x888190

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x697BC0
#define CChatWindow__Clear_x                                       0x697770
#define CChatWindow__WndNotification_x                             0x698100

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D6F60
#define CComboWnd__Draw_x                                          0x8D7170
#define CComboWnd__GetCurChoice_x                                  0x8D6D30
#define CComboWnd__GetListRect_x                                   0x8D7410
#define CComboWnd__GetTextRect_x                                   0x8D6FD0
#define CComboWnd__InsertChoice_x                                  0x8D7480
#define CComboWnd__SetColors_x                                     0x8D6CC0
#define CComboWnd__SetChoice_x                                     0x8D6CF0
#define CComboWnd__GetItemCount_x                                  0x8D6D20
#define CComboWnd__GetCurChoiceText_x                              0x8D6D70


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A1230
#define CContainerWnd__vftable_x                                   0xAE5020

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B42E0
#define CDisplay__GetClickedActor_x                                0x4ACE20
#define CDisplay__GetUserDefinedColor_x                            0x4AB6E0
#define CDisplay__GetWorldFilePath_x                               0x4AAB30
#define CDisplay__is3dON_x                                         0x4A9F00
#define CDisplay__ReloadUI_x                                       0x4BF8C0
#define CDisplay__WriteTextHD2_x                                   0x4B0640

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FDEC0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EBCD0
#define CEditWnd__GetCharIndexPt_x                                 0x8ECD50
#define CEditWnd__GetDisplayString_x                               0x8EBE80
#define CEditWnd__GetHorzOffset_x                                  0x8EC1C0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC820
#define CEditWnd__GetSelStartPt_x                                  0x8ED000
#define CEditWnd__GetSTMLSafeText_x                                0x8EC350
#define CEditWnd__PointFromPrintableChar_x                         0x8EC910
#define CEditWnd__SelectableCharFromPoint_x                        0x8ECA90
#define CEditWnd__SetEditable_x                                    0x8EC320

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x554950
#define CEverQuest__CreateTargetIndicator_x                        0x555580
#define CEverQuest__DeleteTargetIndicator_x                        0x555600
#define CEverQuest__DoTellWindow_x                                 0x55A340
#define CEverQuest__DropHeldItemOnGround_x                         0x563270
#define CEverQuest__dsp_chat_x                                     0x55BD30
#define CEverQuest__Emote_x                                        0x55BF90
#define CEverQuest__EnterZone_x                                    0x570480
#define CEverQuest__GetBodyTypeDesc_x                              0x5511B0
#define CEverQuest__GetClassDesc_x                                 0x556EC0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5574C0
#define CEverQuest__GetDeityDesc_x                                 0x551A90
#define CEverQuest__GetLangDesc_x                                  0x551540
#define CEverQuest__GetRaceDesc_x                                  0x557680
#define CEverQuest__InterpretCmd_x                                 0x55C870
#define CEverQuest__LeftClickedOnPlayer_x                          0x574DF0
#define CEverQuest__LMouseUp_x                                     0x576EF0
#define CEverQuest__RightClickedOnPlayer_x                         0x575900
#define CEverQuest__RMouseUp_x                                     0x576950
#define CEverQuest__SetGameState_x                                 0x555000
#define CEverQuest__UPCNotificationFlush_x                         0x55DBD0
#define CEverQuest__IssuePetCommand_x                              0x55D530

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B2040
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B20A0
#define CGaugeWnd__Draw_x                                          0x6B24D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x436E40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CF130

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DB8D0
#define CInvSlotMgr__MoveItem_x                                    0x6DC810
#define CInvSlotMgr__SelectSlot_x                                  0x6DB980

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DAD60
#define CInvSlot__SliderComplete_x                                 0x6D8590
#define CInvSlot__GetItemBase_x                                    0x6D7A00

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DDC20

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A7330
#define CItemDisplayWnd__UpdateStrings_x                           0x6DEF50

// CLabel 
#define CLabel__Draw_x                                             0x6F9E90

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2D20
#define CListWnd__dCListWnd_x                                      0x8C3D50
#define CListWnd__AddColumn_x                                      0x8C3CF0
#define CListWnd__AddColumn1_x                                     0x8C3560
#define CListWnd__AddLine_x                                        0x8C2FE0
#define CListWnd__AddString_x                                      0x8C31F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C0060
#define CListWnd__CalculateVSBRange_x                              0x8C21D0
#define CListWnd__ClearSel_x                                       0x8BF370
#define CListWnd__ClearAllSel_x                                    0x8BF320
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2BB0
#define CListWnd__Compare_x                                        0x8C0B60
#define CListWnd__Draw_x                                           0x8C1DE0
#define CListWnd__DrawColumnSeparators_x                           0x8C1C70
#define CListWnd__DrawHeader_x                                     0x8BF630
#define CListWnd__DrawItem_x                                       0x8C11B0
#define CListWnd__DrawLine_x                                       0x8C1910
#define CListWnd__DrawSeparator_x                                  0x8C1D10
#define CListWnd__EnsureVisible_x                                  0x8C01C0
#define CListWnd__ExtendSel_x                                      0x8C10C0
#define CListWnd__GetColumnMinWidth_x                              0x8BECE0
#define CListWnd__GetColumnWidth_x                                 0x8BEC00
#define CListWnd__GetCurSel_x                                      0x8BE3C0
#define CListWnd__GetItemAtPoint_x                                 0x8C0450
#define CListWnd__GetItemAtPoint1_x                                0x8C04C0
#define CListWnd__GetItemData_x                                    0x8BE710
#define CListWnd__GetItemHeight_x                                  0x8BFCC0
#define CListWnd__GetItemIcon_x                                    0x8BE8F0
#define CListWnd__GetItemRect_x                                    0x8C0290
#define CListWnd__GetItemText_x                                    0x8BE7A0
#define CListWnd__GetSelList_x                                     0x8C3450
#define CListWnd__GetSeparatorRect_x                               0x8C0A80
#define CListWnd__RemoveLine_x                                     0x8C33D0
#define CListWnd__SetColors_x                                      0x8BE510
#define CListWnd__SetColumnJustification_x                         0x8BEFB0
#define CListWnd__SetColumnWidth_x                                 0x8BEC90
#define CListWnd__SetCurSel_x                                      0x8BE400
#define CListWnd__SetItemColor_x                                   0x8C2890
#define CListWnd__SetItemData_x                                    0x8BF3D0
#define CListWnd__SetItemText_x                                    0x8C26D0
#define CListWnd__ShiftColumnSeparator_x                           0x8C2560
#define CListWnd__Sort_x                                           0x8C3E50
#define CListWnd__ToggleSel_x                                      0x8BF2A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x713570

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x734910
#define CMerchantWnd__RequestBuyItem_x                             0x73B750
#define CMerchantWnd__RequestSellItem_x                            0x73C1C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x734BC0
#define CMerchantWnd__SelectBuySellSlot_x                          0x733E20
#define CMerchantWnd__ActualSelect_x                               0x738680

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8536A0
#define CPacketScrambler__hton_x                                   0x8536B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E20C0
#define CSidlManager__CreateLabel_x                                0x79D220

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65FDB0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65FCD0
#define CSidlScreenWnd__ConvertToRes_x                             0x8FDDA0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9C00
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DB0F0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DB1A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA660
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D95B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8CE0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D97A0
#define CSidlScreenWnd__Init1_x                                    0x8DADC0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9CB0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8EA0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA8B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D87A0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8C70
#define CSidlScreenWnd__WndNotification_x                          0x8DAB40
#define CSidlScreenWnd__GetChildItem_x                             0x8D8DB0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC360

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FAC20
#define CSkillMgr__GetSkillCap_x                                   0x5FADE0
#define CSkillMgr__GetNameToken_x                                  0x5FA840

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FD050
#define CSliderWnd__SetValue_x                                     0x8FD220
#define CSliderWnd__SetNumTicks_x                                  0x8FD9A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A4FB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F89E0
#define CStmlWnd__CalculateHSBRange_x                              0x8F0EF0
#define CStmlWnd__CalculateVSBRange_x                              0x8F0F80
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F1100
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F19E0
#define CStmlWnd__ForceParseNow_x                                  0x8F9330
#define CStmlWnd__GetNextTagPiece_x                                0x8F18E0
#define CStmlWnd__GetSTMLText_x                                    0x697010
#define CStmlWnd__GetVisibleText_x                                 0x8F2430
#define CStmlWnd__InitializeWindowVariables_x                      0x8F47C0
#define CStmlWnd__MakeStmlColorTag_x                               0x8F01F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F0250
#define CStmlWnd__SetSTMLText_x                                    0x8F6030
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F8680
#define CStmlWnd__UpdateHistoryString_x                            0x8F3370

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EF880
#define CTabWnd__DrawCurrentPage_x                                 0x8EF0F0
#define CTabWnd__DrawTab_x                                         0x8EEEC0
#define CTabWnd__GetCurrentPage_x                                  0x8EF4C0
#define CTabWnd__GetPageInnerRect_x                                0x8EEBB0
#define CTabWnd__GetTabInnerRect_x                                 0x8EEDB0
#define CTabWnd__GetTabRect_x                                      0x8EEC80
#define CTabWnd__InsertPage_x                                      0x8EFB70
#define CTabWnd__SetPage_x                                         0x8EF4F0
#define CTabWnd__SetPageRect_x                                     0x8EF7C0
#define CTabWnd__UpdatePage_x                                      0x8EFB10

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432C80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6930

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903210

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC5B0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029C0
#define CXStr__CXStr1_x                                            0x441250
#define CXStr__CXStr3_x                                            0x89F970
#define CXStr__dCXStr_x                                            0x901FB0
#define CXStr__operator_equal_x                                    0x89FAE0
#define CXStr__operator_equal1_x                                   0x89FB30
#define CXStr__operator_plus_equal1_x                              0x8A0C50

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8CB5A0
#define CXWnd__Center_x                                            0x8D1620
#define CXWnd__ClrFocus_x                                          0x8CB190
#define CXWnd__DoAllDrawing_x                                      0x8D1250
#define CXWnd__DrawChildren_x                                      0x8D1400
#define CXWnd__DrawColoredRect_x                                   0x8CB960
#define CXWnd__DrawTooltip_x                                       0x8CBC10
#define CXWnd__DrawTooltipAtPoint_x                                0x8D0210
#define CXWnd__GetBorderFrame_x                                    0x8CC050
#define CXWnd__GetChildWndAt_x                                     0x8D1FF0
#define CXWnd__GetClientClipRect_x                                 0x8CBE20
#define CXWnd__GetScreenClipRect_x                                 0x8D0900
#define CXWnd__GetScreenRect_x                                     0x8CC210
#define CXWnd__GetTooltipRect_x                                    0x8CBAA0
#define CXWnd__GetWindowTextA_x                                    0x4241C0
#define CXWnd__IsActive_x                                          0x8C6B30
#define CXWnd__IsDescendantOf_x                                    0x8CBF90
#define CXWnd__IsReallyVisible_x                                   0x8CF250
#define CXWnd__IsType_x                                            0x8FFA50
#define CXWnd__Move_x                                              0x8CE9F0
#define CXWnd__Move1_x                                             0x8D0F30
#define CXWnd__ProcessTransition_x                                 0x8CB550
#define CXWnd__Refade_x                                            0x8CB330
#define CXWnd__Resize_x                                            0x8CC2C0
#define CXWnd__Right_x                                             0x8D0700
#define CXWnd__SetFocus_x                                          0x8CDB80
#define CXWnd__SetFont_x                                           0x8CB1E0
#define CXWnd__SetKeyTooltip_x                                     0x8CC530
#define CXWnd__SetMouseOver_x                                      0x8D0C30
#define CXWnd__StartFade_x                                         0x8CB5F0
#define CXWnd__GetChildItem_x                                      0x8D0B70

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C8470
#define CXWndManager__DrawWindows_x                                0x8C80B0
#define CXWndManager__GetKeyboardFlags_x                           0x8C6670
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6FD0
#define CXWndManager__RemoveWnd_x                                  0x8C6CC0

// CDBStr
#define CDBStr__GetString_x                                        0x4A8420

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F3D0
#define EQ_Character__Cur_HP_x                                     0x4647E0
#define EQ_Character__Cur_Mana_x                                   0x457850
#define EQ_Character__GetAACastingTimeModifier_x                   0x448690
#define EQ_Character__GetCharInfo2_x                               0x872D50
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F8D0
#define EQ_Character__GetFocusRangeModifier_x                      0x43FB10
#define EQ_Character__Max_Endurance_x                              0x5C2840
#define EQ_Character__Max_HP_x                                     0x45A450
#define EQ_Character__Max_Mana_x                                   0x5C2670
#define EQ_Character__doCombatAbility_x                            0x5BFCC0
#define EQ_Character__UseSkill_x                                   0x46FD50
#define EQ_Character__GetConLevel_x                                0x5B4370
#define EQ_Character__IsExpansionFlag_x                            0x4236F0
#define EQ_Character__TotalEffect_x                                0x44C640
#define EQ_Character__GetPCSpellAffect_x                           0x448A80
#define EQ_Character__SpellDuration_x                              0x4469B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x594910
#define EQ_Item__CreateItemTagString_x                             0x851F70
#define EQ_Item__IsStackable_x                                     0x846150
#define EQ_Item__GetImageNum_x                                     0x848E10
#define EQ_Item__CreateItemClient_x                                0x5954E0
#define EQ_Item__GetItemValue_x                                    0x850C10
#define EQ_Item__ValueSellMerchant_x                               0x853300

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C81C0
#define EQ_LoadingS__Array_x                                       0xC218E8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C3EA0
#define EQ_PC__GetAlternateAbilityId_x                             0x85B5E0
#define EQ_PC__GetCombatAbility_x                                  0x85B670
#define EQ_PC__GetCombatAbilityTimer_x                             0x856430
#define EQ_PC__GetItemTimerValue_x                                 0x5BD7B0
#define EQ_PC__HasLoreItem_x                                       0x5B7840
#define EQ_PC__AlertInventoryChanged_x                             0x5B4340
#define EQ_PC__GetPcZoneClient_x                                   0x5DE4A0
#define EQ_PC__RemoveMyAffect_x                                    0x5BCC50

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50FDF0
#define EQItemList__add_item_x                                     0x50FD30
#define EQItemList__delete_item_x                                  0x5101F0
#define EQItemList__FreeItemList_x                                 0x5100F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A7700

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C9440
#define EQPlayer__dEQPlayer_x                                      0x5D2300
#define EQPlayer__DoAttack_x                                       0x5E43A0
#define EQPlayer__EQPlayer_x                                       0x5D4720
#define EQPlayer__SetNameSpriteState_x                             0x5CF1E0
#define EQPlayer__SetNameSpriteTint_x                              0x5CA870
#define EQPlayer__IsBodyType_j_x                                   0x9307C0
#define EQPlayer__IsTargetable_x                                   0x9310C0
#define EQPlayer__CanSee_x                                         0x9315E0
#define PlayerZoneClient__ChangeHeight_x                           0x5E4260
#define EQPlayer__CanSeeTargetIndicator_x                          0x9316D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D8AA0
#define EQPlayerManager__GetSpawnByName_x                          0x5D8F00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59A9A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59A9E0
#define KeypressHandler__ClearCommandStateArray_x                  0x59A580
#define KeypressHandler__HandleKeyDown_x                           0x598EE0
#define KeypressHandler__HandleKeyUp_x                             0x599200
#define KeypressHandler__SaveKeymapping_x                          0x59A650

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70B950
#define MapViewMap__SaveEx_x                                       0x70F230

#define PlayerPointManager__GetAltCurrency_x                       0x86DCF0

// StringTable 
#define StringTable__getString_x                                   0x8686B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C22F0
#define PcZoneClient__RemovePetEffect_x                            0x5BDCA0
#define PcZoneClient__HasAlternateAbility_x                        0x5BE760

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E500

//IconCache
#define IconCache__GetIcon_x                                       0x6A7760

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69E550
#define CContainerMgr__CloseContainer_x                            0x69ED70

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76D4A0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58DAE0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DFC60
#define EQ_Spell__SpellAffects_x                                   0x4DD340
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DD3B0
#define CharacterZoneClient__CalcAffectChange_x                    0x447AE0
#define CLootWnd__LootAll_x                                        0x701180

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B2F90
#define CTargetWnd__WndNotification_x                              0x7B2A80
#define CTargetWnd__UpdateBuffs_x                                  0x7B3170

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B8170

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D90E0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x497D70

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EB300
#define CSidlManager__FindAnimation1_x                             0x8DFFB0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CF750
#define CAltAbilityData__GetMercMaxRank_x                          0x4CF700
#define CAltAbilityData__GetMaxRank_x                              0x4C4780

//CTargetRing
#define CTargetRing__Cast_x                                        0x58B3C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x456260

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x688F20
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6886E0
