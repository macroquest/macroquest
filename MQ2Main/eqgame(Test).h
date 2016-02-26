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
#define __ExpectedVersionDate                                     "Feb 22 2016"
#define __ExpectedVersionTime                                     "19:24:29"
#define __ActualVersionDate_x                                      0xADB5E8
#define __ActualVersionTime_x                                      0xADB5F4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5A0610
#define __MemChecker1_x                                            0x8A3240
#define __MemChecker2_x                                            0x639B20
#define __MemChecker3_x                                            0x639A70
#define __MemChecker4_x                                            0x7EE930
#define __EncryptPad0_x                                            0xC78710
#define __EncryptPad1_x                                            0xE04060
#define __EncryptPad2_x                                            0xCC2370
#define __EncryptPad3_x                                            0xCC1F70
#define __EncryptPad4_x                                            0xDDD0D0
#define __EncryptPad5_x                                            0x11AFF58
#define __AC1_x                                                    0x7ABB25
#define __AC2_x                                                    0x554717
#define __AC3_x                                                    0x569310
#define __AC4_x                                                    0x570050
#define __AC5_x                                                    0x57C7EE
#define __AC6_x                                                    0x580399
#define __AC7_x                                                    0x576E9C
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
#define __do_loot_x                                                0x51BEF0
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
#define __CastRay_x                                                0x533740
#define __ConvertItemTags_x                                        0x520B70
#define __ExecuteCmd_x                                             0x50B570
#define __EQGetTime_x                                              0x8A2E70
#define __get_melee_range_x                                        0x512230
#define __GetGaugeValueFromEQ_x                                    0x7AA860
#define __GetLabelFromEQ_x                                         0x7ABAB0
#define __ToggleKeyRingItem_x                                      0x47F150
#define __GetXTargetType_x                                         0x9343F0
#define __LoadFrontEnd_x                                           0x6391D0
#define __NewUIINI_x                                               0x7AA170
#define __ProcessGameEvents_x                                      0x578C00
#define __ProcessMouseEvent_x                                      0x5783A0
#define CrashDetected_x                                            0x63ACA0
#define wwsCrashReportCheckForUploader_x                           0x7FE460
#define DrawNetStatus_x                                            0x5B0050
#define Util__FastTime_x                                           0x8A2980
#define Expansion_HoT_x                                            0x101F8B4
#define __HelpPath_x                                               0x10A3030
#define __STMLToText_x                                             0x8E8DE0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420220
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B070

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C5F80
#define AltAdvManager__IsAbilityReady_x                            0x4C5FF0
#define AltAdvManager__GetAAById_x                                 0x4C63B0
#define AltAdvManager__CanTrainAbility_x                           0x4C6C70
#define AltAdvManager__CanSeeAbility_x                             0x4C6870

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465230
#define CharacterZoneClient__MakeMeVisible_x                       0x46AC70
#define CharacterZoneClient__IsStackBlocked_x                      0x448FB0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x448490

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x668C80

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x676C90

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58F520
#define CButtonWnd__CButtonWnd_x                                   0x8DD000

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x692010
#define CChatManager__InitContextMenu_x                            0x692B90

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E7150
#define CContextMenu__dCContextMenu_x                              0x8E7350
#define CContextMenu__AddMenuItem_x                                0x8E7360
#define CContextMenu__RemoveMenuItem_x                             0x8E7650
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7670
#define CContextMenuManager__AddMenu_x                             0x8D3010
#define CContextMenuManager__RemoveMenu_x                          0x8D3350
#define CContextMenuManager__PopupMenu_x                           0x8D37A0
#define CContextMenuManager__Flush_x                               0x8D3080
#define CContextMenuManager__GetMenu_x                             0x4166C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x888110
#define CChatService__GetFriendName_x                              0x888120

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x697E80
#define CChatWindow__Clear_x                                       0x697A40
#define CChatWindow__WndNotification_x                             0x6983B0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D6ED0
#define CComboWnd__Draw_x                                          0x8D70E0
#define CComboWnd__GetCurChoice_x                                  0x8D6CA0
#define CComboWnd__GetListRect_x                                   0x8D7380
#define CComboWnd__GetTextRect_x                                   0x8D6F40
#define CComboWnd__InsertChoice_x                                  0x8D73F0
#define CComboWnd__SetColors_x                                     0x8D6C30
#define CComboWnd__SetChoice_x                                     0x8D6C60
#define CComboWnd__GetItemCount_x                                  0x8D6C90
#define CComboWnd__GetCurChoiceText_x                              0x8D6CE0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A1450
#define CContainerWnd__vftable_x                                   0xAE4FD0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B41E0
#define CDisplay__GetClickedActor_x                                0x4ACD30
#define CDisplay__GetUserDefinedColor_x                            0x4AB5F0
#define CDisplay__GetWorldFilePath_x                               0x4AAA40
#define CDisplay__is3dON_x                                         0x4A9E10
#define CDisplay__ReloadUI_x                                       0x4BF7C0
#define CDisplay__WriteTextHD2_x                                   0x4B0540

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FDD00

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EBB20
#define CEditWnd__GetCharIndexPt_x                                 0x8ECBC0
#define CEditWnd__GetDisplayString_x                               0x8EBCD0
#define CEditWnd__GetHorzOffset_x                                  0x8EC010
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC680
#define CEditWnd__GetSelStartPt_x                                  0x8ECE80
#define CEditWnd__GetSTMLSafeText_x                                0x8EC1B0
#define CEditWnd__PointFromPrintableChar_x                         0x8EC770
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC8F0
#define CEditWnd__SetEditable_x                                    0x8EC180

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x554E60
#define CEverQuest__CreateTargetIndicator_x                        0x555A90
#define CEverQuest__DeleteTargetIndicator_x                        0x555B10
#define CEverQuest__DoTellWindow_x                                 0x55A860
#define CEverQuest__DropHeldItemOnGround_x                         0x563790
#define CEverQuest__dsp_chat_x                                     0x55C250
#define CEverQuest__Emote_x                                        0x55C4B0
#define CEverQuest__EnterZone_x                                    0x5709A0
#define CEverQuest__GetBodyTypeDesc_x                              0x5516C0
#define CEverQuest__GetClassDesc_x                                 0x5573D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5579D0
#define CEverQuest__GetDeityDesc_x                                 0x551FA0
#define CEverQuest__GetLangDesc_x                                  0x551A50
#define CEverQuest__GetRaceDesc_x                                  0x557B90
#define CEverQuest__InterpretCmd_x                                 0x55CD90
#define CEverQuest__LeftClickedOnPlayer_x                          0x575310
#define CEverQuest__LMouseUp_x                                     0x5773F0
#define CEverQuest__RightClickedOnPlayer_x                         0x575E10
#define CEverQuest__RMouseUp_x                                     0x576E50
#define CEverQuest__SetGameState_x                                 0x555510
#define CEverQuest__UPCNotificationFlush_x                         0x55E0F0
#define CEverQuest__IssuePetCommand_x                              0x55DA50

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B22D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B2330
#define CGaugeWnd__Draw_x                                          0x6B2760

// CGuild
#define CGuild__FindMemberByName_x                                 0x437020

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CF3E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DBB70
#define CInvSlotMgr__MoveItem_x                                    0x6DCAA0
#define CInvSlotMgr__SelectSlot_x                                  0x6DBC20

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DB000
#define CInvSlot__SliderComplete_x                                 0x6D8830
#define CInvSlot__GetItemBase_x                                    0x6D7C90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DDE80

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A71F0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DF1A0

// CLabel 
#define CLabel__Draw_x                                             0x6FA0A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2CA0
#define CListWnd__dCListWnd_x                                      0x8C3CC0
#define CListWnd__AddColumn_x                                      0x8C3C60
#define CListWnd__AddColumn1_x                                     0x8C34D0
#define CListWnd__AddLine_x                                        0x8C2F50
#define CListWnd__AddString_x                                      0x8C3160
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BFFE0
#define CListWnd__CalculateVSBRange_x                              0x8C2160
#define CListWnd__ClearSel_x                                       0x8BF2E0
#define CListWnd__ClearAllSel_x                                    0x8BF290
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2B30
#define CListWnd__Compare_x                                        0x8C0AE0
#define CListWnd__Draw_x                                           0x8C1D70
#define CListWnd__DrawColumnSeparators_x                           0x8C1C00
#define CListWnd__DrawHeader_x                                     0x8BF5A0
#define CListWnd__DrawItem_x                                       0x8C1130
#define CListWnd__DrawLine_x                                       0x8C18A0
#define CListWnd__DrawSeparator_x                                  0x8C1CA0
#define CListWnd__EnsureVisible_x                                  0x8C0140
#define CListWnd__ExtendSel_x                                      0x8C1040
#define CListWnd__GetColumnMinWidth_x                              0x8BEC50
#define CListWnd__GetColumnWidth_x                                 0x8BEB70
#define CListWnd__GetCurSel_x                                      0x8BE350
#define CListWnd__GetItemAtPoint_x                                 0x8C03E0
#define CListWnd__GetItemAtPoint1_x                                0x8C0450
#define CListWnd__GetItemData_x                                    0x8BE690
#define CListWnd__GetItemHeight_x                                  0x8BFC30
#define CListWnd__GetItemIcon_x                                    0x8BE870
#define CListWnd__GetItemRect_x                                    0x8C0220
#define CListWnd__GetItemText_x                                    0x8BE720
#define CListWnd__GetSelList_x                                     0x8C33C0
#define CListWnd__GetSeparatorRect_x                               0x8C0A00
#define CListWnd__RemoveLine_x                                     0x8C3340
#define CListWnd__SetColors_x                                      0x8BE4A0
#define CListWnd__SetColumnJustification_x                         0x8BEF20
#define CListWnd__SetColumnWidth_x                                 0x8BEC00
#define CListWnd__SetCurSel_x                                      0x8BE390
#define CListWnd__SetItemColor_x                                   0x8C2810
#define CListWnd__SetItemData_x                                    0x8BF340
#define CListWnd__SetItemText_x                                    0x8C2650
#define CListWnd__ShiftColumnSeparator_x                           0x8C24E0
#define CListWnd__Sort_x                                           0x8C3DC0
#define CListWnd__ToggleSel_x                                      0x8BF210

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x713520

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x734880
#define CMerchantWnd__RequestBuyItem_x                             0x73B6E0
#define CMerchantWnd__RequestSellItem_x                            0x73C150
#define CMerchantWnd__SelectRecoverySlot_x                         0x734B30
#define CMerchantWnd__SelectBuySellSlot_x                          0x733D90
#define CMerchantWnd__ActualSelect_x                               0x738600

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x853680
#define CPacketScrambler__hton_x                                   0x853690

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1FB0
#define CSidlManager__CreateLabel_x                                0x79D1C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65FF80
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65FEB0
#define CSidlScreenWnd__ConvertToRes_x                             0x8FDBE0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9B50
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DB050
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DB100
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA5D0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D9500
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8C50
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D96F0
#define CSidlScreenWnd__Init1_x                                    0x8DAD30
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9C00
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8E10
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA820
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D8710
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8BE0
#define CSidlScreenWnd__WndNotification_x                          0x8DAAB0
#define CSidlScreenWnd__GetChildItem_x                             0x8D8D20
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC2C0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FAF40
#define CSkillMgr__GetSkillCap_x                                   0x5FB100
#define CSkillMgr__GetNameToken_x                                  0x5FAB60

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FCEB0
#define CSliderWnd__SetValue_x                                     0x8FD080
#define CSliderWnd__SetNumTicks_x                                  0x8FD800

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A4EA0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F8830
#define CStmlWnd__CalculateHSBRange_x                              0x8F0D70
#define CStmlWnd__CalculateVSBRange_x                              0x8F0E00
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F0F80
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F1860
#define CStmlWnd__ForceParseNow_x                                  0x8F9180
#define CStmlWnd__GetNextTagPiece_x                                0x8F1760
#define CStmlWnd__GetSTMLText_x                                    0x6972E0
#define CStmlWnd__GetVisibleText_x                                 0x8F22B0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F4640
#define CStmlWnd__MakeStmlColorTag_x                               0x8F0070
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F00D0
#define CStmlWnd__SetSTMLText_x                                    0x8F5EA0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F84D0
#define CStmlWnd__UpdateHistoryString_x                            0x8F31F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EF710
#define CTabWnd__DrawCurrentPage_x                                 0x8EEF80
#define CTabWnd__DrawTab_x                                         0x8EED40
#define CTabWnd__GetCurrentPage_x                                  0x8EF350
#define CTabWnd__GetPageInnerRect_x                                0x8EEA30
#define CTabWnd__GetTabInnerRect_x                                 0x8EEC30
#define CTabWnd__GetTabRect_x                                      0x8EEB00
#define CTabWnd__InsertPage_x                                      0x8EFA00
#define CTabWnd__SetPage_x                                         0x8EF380
#define CTabWnd__SetPageRect_x                                     0x8EF650
#define CTabWnd__UpdatePage_x                                      0x8EF9A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432EB0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D68A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9030C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC600

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402A40
#define CXStr__CXStr1_x                                            0x8B1D00
#define CXStr__CXStr3_x                                            0x89F9D0
#define CXStr__dCXStr_x                                            0x7468D0
#define CXStr__operator_equal_x                                    0x89FB40
#define CXStr__operator_equal1_x                                   0x89FB90
#define CXStr__operator_plus_equal1_x                              0x8A0CB0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8CB510
#define CXWnd__Center_x                                            0x8D1670
#define CXWnd__ClrFocus_x                                          0x8CB0F0
#define CXWnd__DoAllDrawing_x                                      0x8D12C0
#define CXWnd__DrawChildren_x                                      0x8D1460
#define CXWnd__DrawColoredRect_x                                   0x8CB8C0
#define CXWnd__DrawTooltip_x                                       0x8CBB70
#define CXWnd__DrawTooltipAtPoint_x                                0x8D0240
#define CXWnd__GetBorderFrame_x                                    0x8CBFD0
#define CXWnd__GetChildWndAt_x                                     0x8D2010
#define CXWnd__GetClientClipRect_x                                 0x8CBD90
#define CXWnd__GetScreenClipRect_x                                 0x8D0940
#define CXWnd__GetScreenRect_x                                     0x8CC160
#define CXWnd__GetTooltipRect_x                                    0x8CBA00
#define CXWnd__GetWindowTextA_x                                    0x4242D0
#define CXWnd__IsActive_x                                          0x8C6AA0
#define CXWnd__IsDescendantOf_x                                    0x8CBF20
#define CXWnd__IsReallyVisible_x                                   0x8CF280
#define CXWnd__IsType_x                                            0x8FF8E0
#define CXWnd__Move_x                                              0x8CE970
#define CXWnd__Move1_x                                             0x8D0F70
#define CXWnd__ProcessTransition_x                                 0x8CB4C0
#define CXWnd__Refade_x                                            0x8CB2A0
#define CXWnd__Resize_x                                            0x8CC220
#define CXWnd__Right_x                                             0x8D0740
#define CXWnd__SetFocus_x                                          0x8CDAD0
#define CXWnd__SetFont_x                                           0x8CB140
#define CXWnd__SetKeyTooltip_x                                     0x8CC490
#define CXWnd__SetMouseOver_x                                      0x8D0C80
#define CXWnd__StartFade_x                                         0x8CB560
#define CXWnd__GetChildItem_x                                      0x8D0BC0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C83B0
#define CXWndManager__DrawWindows_x                                0x8C8000
#define CXWndManager__GetKeyboardFlags_x                           0x8C6610
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6F30
#define CXWndManager__RemoveWnd_x                                  0x8C6C30

// CDBStr
#define CDBStr__GetString_x                                        0x4A8330

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F4E0
#define EQ_Character__Cur_HP_x                                     0x464900
#define EQ_Character__Cur_Mana_x                                   0x457950
#define EQ_Character__GetAACastingTimeModifier_x                   0x4487A0
#define EQ_Character__GetCharInfo2_x                               0x872CF0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43FA30
#define EQ_Character__GetFocusRangeModifier_x                      0x43FC70
#define EQ_Character__Max_Endurance_x                              0x5C2880
#define EQ_Character__Max_HP_x                                     0x45A550
#define EQ_Character__Max_Mana_x                                   0x5C26B0
#define EQ_Character__doCombatAbility_x                            0x5BFCF0
#define EQ_Character__UseSkill_x                                   0x46FE60
#define EQ_Character__GetConLevel_x                                0x5B46C0
#define EQ_Character__IsExpansionFlag_x                            0x423810
#define EQ_Character__TotalEffect_x                                0x44C750
#define EQ_Character__GetPCSpellAffect_x                           0x448B90
#define EQ_Character__SpellDuration_x                              0x446AC0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x594E80
#define EQ_Item__CreateItemTagString_x                             0x851F50
#define EQ_Item__IsStackable_x                                     0x8460D0
#define EQ_Item__GetImageNum_x                                     0x848DB0
#define EQ_Item__CreateItemClient_x                                0x595A60
#define EQ_Item__GetItemValue_x                                    0x850BE0
#define EQ_Item__ValueSellMerchant_x                               0x8532D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C8130
#define EQ_LoadingS__Array_x                                       0xC218E8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C3ED0
#define EQ_PC__GetAlternateAbilityId_x                             0x85B580
#define EQ_PC__GetCombatAbility_x                                  0x85B610
#define EQ_PC__GetCombatAbilityTimer_x                             0x856410
#define EQ_PC__GetItemTimerValue_x                                 0x5BD7F0
#define EQ_PC__HasLoreItem_x                                       0x5B7B90
#define EQ_PC__AlertInventoryChanged_x                             0x5B4690
#define EQ_PC__GetPcZoneClient_x                                   0x5DE5B0
#define EQ_PC__RemoveMyAffect_x                                    0x5BCC90

// EQItemList 
#define EQItemList__EQItemList_x                                   0x510250
#define EQItemList__add_item_x                                     0x53CE00
#define EQItemList__delete_item_x                                  0x510650
#define EQItemList__FreeItemList_x                                 0x510550

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A75F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C94A0
#define EQPlayer__dEQPlayer_x                                      0x5D2350
#define EQPlayer__DoAttack_x                                       0x5E44A0
#define EQPlayer__EQPlayer_x                                       0x5D4770
#define EQPlayer__SetNameSpriteState_x                             0x5CF240
#define EQPlayer__SetNameSpriteTint_x                              0x5CA8D0
#define EQPlayer__IsBodyType_j_x                                   0x9305C0
#define EQPlayer__IsTargetable_x                                   0x930EC0
#define EQPlayer__CanSee_x                                         0x9313E0
#define PlayerZoneClient__ChangeHeight_x                           0x5E4360
#define EQPlayer__CanSeeTargetIndicator_x                          0x9314D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D8AF0
#define EQPlayerManager__GetSpawnByName_x                          0x5D8F50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59AF40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59AF80
#define KeypressHandler__ClearCommandStateArray_x                  0x59AB20
#define KeypressHandler__HandleKeyDown_x                           0x599480
#define KeypressHandler__HandleKeyUp_x                             0x5997A0
#define KeypressHandler__SaveKeymapping_x                          0x59ABF0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70B900
#define MapViewMap__SaveEx_x                                       0x70F1E0

#define PlayerPointManager__GetAltCurrency_x                       0x86DCC0

// StringTable 
#define StringTable__getString_x                                   0x868690

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C2330
#define PcZoneClient__RemovePetEffect_x                            0x5BDCE0
#define PcZoneClient__HasAlternateAbility_x                        0x5BE7A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E9D0

//IconCache
#define IconCache__GetIcon_x                                       0x6A7970

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69E770
#define CContainerMgr__CloseContainer_x                            0x69EF90

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76D480

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58DFC0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DFEA0
#define EQ_Spell__SpellAffects_x                                   0x4DD580
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DD5F0
#define CharacterZoneClient__CalcAffectChange_x                    0x447BF0
#define CLootWnd__LootAll_x                                        0x701220

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B2E00
#define CTargetWnd__WndNotification_x                              0x7B28F0
#define CTargetWnd__UpdateBuffs_x                                  0x7B2FE0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B7FE0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D92C0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x497C90

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EB150
#define CSidlManager__FindAnimation1_x                             0x8DFEB0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CF840
#define CAltAbilityData__GetMercMaxRank_x                          0x4CF7F0
#define CAltAbilityData__GetMaxRank_x                              0x4C4640

//CTargetRing
#define CTargetRing__Cast_x                                        0x58B8C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x456330

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6890D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x688890
