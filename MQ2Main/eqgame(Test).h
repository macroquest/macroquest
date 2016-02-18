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
#define __ExpectedVersionDate                                     "Feb 11 2016"
#define __ExpectedVersionTime                                     "13:04:51"
#define __ActualVersionDate_x                                      0xADB5F0
#define __ActualVersionTime_x                                      0xADB5FC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5A06B0
#define __MemChecker1_x                                            0x8A2F00
#define __MemChecker2_x                                            0x639BE0
#define __MemChecker3_x                                            0x639B30
#define __MemChecker4_x                                            0x7EEDB0
#define __EncryptPad0_x                                            0xC78710
#define __EncryptPad1_x                                            0xE04060
#define __EncryptPad2_x                                            0xCC2370
#define __EncryptPad3_x                                            0xCC1F70
#define __EncryptPad4_x                                            0xDDD0D0
#define __EncryptPad5_x                                            0x11AFF58
#define __AC1_x                                                    0x7ABE95
#define __AC2_x                                                    0x5546D7
#define __AC3_x                                                    0x5692C0
#define __AC4_x                                                    0x570000
#define __AC5_x                                                    0x57C79E
#define __AC6_x                                                    0x580349
#define __AC7_x                                                    0x576E4C
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
#define __do_loot_x                                                0x51BE70
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
#define __CastRay_x                                                0x5336C0
#define __ConvertItemTags_x                                        0x520AF0
#define __ExecuteCmd_x                                             0x50B4F0
#define __EQGetTime_x                                              0x8A2B30
#define __get_melee_range_x                                        0x5121A0
#define __GetGaugeValueFromEQ_x                                    0x7AABD0
#define __GetLabelFromEQ_x                                         0x7ABE20
#define __ToggleKeyRingItem_x                                      0x47F3D0
#define __GetXTargetType_x                                         0x9348B0
#define __LoadFrontEnd_x                                           0x639290
#define __NewUIINI_x                                               0x7AA4D0
#define __ProcessGameEvents_x                                      0x578BB0
#define __ProcessMouseEvent_x                                      0x578350
#define CrashDetected_x                                            0x63AD60
#define wwsCrashReportCheckForUploader_x                           0x7FE6F0
#define DrawNetStatus_x                                            0x5B0020
#define Util__FastTime_x                                           0x8A2640
#define Expansion_HoT_x                                            0x101F8B4
#define __HelpPath_x                                               0x10A3030
#define __STMLToText_x                                             0x8E8EE0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420180
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41AFE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C62C0
#define AltAdvManager__IsAbilityReady_x                            0x4C6330
#define AltAdvManager__GetAAById_x                                 0x4C66F0
#define AltAdvManager__CanTrainAbility_x                           0x4C6FB0
#define AltAdvManager__CanSeeAbility_x                             0x4C6BB0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465400
#define CharacterZoneClient__MakeMeVisible_x                       0x46AE40
#define CharacterZoneClient__IsStackBlocked_x                      0x4490B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x448590

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x668E10

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x676C10

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58F4D0
#define CButtonWnd__CButtonWnd_x                                   0x8DD1C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6922D0
#define CChatManager__InitContextMenu_x                            0x692E50

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E7220
#define CContextMenu__dCContextMenu_x                              0x8E7430
#define CContextMenu__AddMenuItem_x                                0x8E7440
#define CContextMenu__RemoveMenuItem_x                             0x8E7730
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7750
#define CContextMenuManager__AddMenu_x                             0x8D30F0
#define CContextMenuManager__RemoveMenu_x                          0x8D3430
#define CContextMenuManager__PopupMenu_x                           0x8D3880
#define CContextMenuManager__Flush_x                               0x8D3160
#define CContextMenuManager__GetMenu_x                             0x416630

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x887D60
#define CChatService__GetFriendName_x                              0x887D70

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x698140
#define CChatWindow__Clear_x                                       0x697D00
#define CChatWindow__WndNotification_x                             0x698680

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D7000
#define CComboWnd__Draw_x                                          0x8D7210
#define CComboWnd__GetCurChoice_x                                  0x8D6DD0
#define CComboWnd__GetListRect_x                                   0x8D74B0
#define CComboWnd__GetTextRect_x                                   0x8D7070
#define CComboWnd__InsertChoice_x                                  0x8D7520
#define CComboWnd__SetColors_x                                     0x8D6D60
#define CComboWnd__SetChoice_x                                     0x8D6D90
#define CComboWnd__GetItemCount_x                                  0x8D6DC0
#define CComboWnd__GetCurChoiceText_x                              0x8D6E10

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A1730
#define CContainerWnd__vftable_x                                   0xAE4FD8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B4480
#define CDisplay__GetClickedActor_x                                0x4ACFD0
#define CDisplay__GetUserDefinedColor_x                            0x4AB890
#define CDisplay__GetWorldFilePath_x                               0x4AACE0
#define CDisplay__is3dON_x                                         0x4AA0B0
#define CDisplay__ReloadUI_x                                       0x4BFA60
#define CDisplay__WriteTextHD2_x                                   0x4B07E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FDE80

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EBBF0
#define CEditWnd__GetCharIndexPt_x                                 0x8ECC90
#define CEditWnd__GetDisplayString_x                               0x8EBDA0
#define CEditWnd__GetHorzOffset_x                                  0x8EC0E0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC750
#define CEditWnd__GetSelStartPt_x                                  0x8ECF50
#define CEditWnd__GetSTMLSafeText_x                                0x8EC280
#define CEditWnd__PointFromPrintableChar_x                         0x8EC840
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC9C0
#define CEditWnd__SetEditable_x                                    0x8EC250

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x554E20
#define CEverQuest__CreateTargetIndicator_x                        0x555A50
#define CEverQuest__DeleteTargetIndicator_x                        0x555AD0
#define CEverQuest__DoTellWindow_x                                 0x55A810
#define CEverQuest__DropHeldItemOnGround_x                         0x563740
#define CEverQuest__dsp_chat_x                                     0x55C200
#define CEverQuest__Emote_x                                        0x55C460
#define CEverQuest__EnterZone_x                                    0x570950
#define CEverQuest__GetBodyTypeDesc_x                              0x551680
#define CEverQuest__GetClassDesc_x                                 0x557390
#define CEverQuest__GetClassThreeLetterCode_x                      0x557990
#define CEverQuest__GetDeityDesc_x                                 0x551F60
#define CEverQuest__GetLangDesc_x                                  0x551A10
#define CEverQuest__GetRaceDesc_x                                  0x557B50
#define CEverQuest__InterpretCmd_x                                 0x55CD40
#define CEverQuest__LeftClickedOnPlayer_x                          0x5752B0
#define CEverQuest__LMouseUp_x                                     0x5773A0
#define CEverQuest__RightClickedOnPlayer_x                         0x575DB0
#define CEverQuest__RMouseUp_x                                     0x576E00
#define CEverQuest__SetGameState_x                                 0x5554D0
#define CEverQuest__UPCNotificationFlush_x                         0x55E0A0
#define CEverQuest__IssuePetCommand_x                              0x55DA00

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B2420
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B2480
#define CGaugeWnd__Draw_x                                          0x6B28B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x437160

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CF580

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DBD00
#define CInvSlotMgr__MoveItem_x                                    0x6DCC40
#define CInvSlotMgr__SelectSlot_x                                  0x6DBDB0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DB190
#define CInvSlot__SliderComplete_x                                 0x6D89D0
#define CInvSlot__GetItemBase_x                                    0x6D7E60

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DE010

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A7570
#define CItemDisplayWnd__UpdateStrings_x                           0x6DF360

// CLabel 
#define CLabel__Draw_x                                             0x6FA260

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2C90
#define CListWnd__dCListWnd_x                                      0x8C3CC0
#define CListWnd__AddColumn_x                                      0x8C3C60
#define CListWnd__AddColumn1_x                                     0x8C34D0
#define CListWnd__AddLine_x                                        0x8C2F50
#define CListWnd__AddString_x                                      0x8C3160
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BFFD0
#define CListWnd__CalculateVSBRange_x                              0x8C2150
#define CListWnd__ClearSel_x                                       0x8BF2E0
#define CListWnd__ClearAllSel_x                                    0x8BF290
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2B20
#define CListWnd__Compare_x                                        0x8C0AD0
#define CListWnd__Draw_x                                           0x8C1D60
#define CListWnd__DrawColumnSeparators_x                           0x8C1BF0
#define CListWnd__DrawHeader_x                                     0x8BF5A0
#define CListWnd__DrawItem_x                                       0x8C1120
#define CListWnd__DrawLine_x                                       0x8C1890
#define CListWnd__DrawSeparator_x                                  0x8C1C90
#define CListWnd__EnsureVisible_x                                  0x8C0130
#define CListWnd__ExtendSel_x                                      0x8C1030
#define CListWnd__GetColumnMinWidth_x                              0x8BEC50
#define CListWnd__GetColumnWidth_x                                 0x8BEB70
#define CListWnd__GetCurSel_x                                      0x8BE340
#define CListWnd__GetItemAtPoint_x                                 0x8C03D0
#define CListWnd__GetItemAtPoint1_x                                0x8C0440
#define CListWnd__GetItemData_x                                    0x8BE680
#define CListWnd__GetItemHeight_x                                  0x8BFC30
#define CListWnd__GetItemIcon_x                                    0x8BE860
#define CListWnd__GetItemRect_x                                    0x8C0210
#define CListWnd__GetItemText_x                                    0x8BE710
#define CListWnd__GetSelList_x                                     0x8C33C0
#define CListWnd__GetSeparatorRect_x                               0x8C0A00
#define CListWnd__RemoveLine_x                                     0x8C3340
#define CListWnd__SetColors_x                                      0x8BE490
#define CListWnd__SetColumnJustification_x                         0x8BEF20
#define CListWnd__SetColumnWidth_x                                 0x8BEC00
#define CListWnd__SetCurSel_x                                      0x8BE380
#define CListWnd__SetItemColor_x                                   0x8C2800
#define CListWnd__SetItemData_x                                    0x8BF340
#define CListWnd__SetItemText_x                                    0x8C2640
#define CListWnd__ShiftColumnSeparator_x                           0x8C24D0
#define CListWnd__Sort_x                                           0x8C3DC0
#define CListWnd__ToggleSel_x                                      0x8BF210

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7137D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x734C40
#define CMerchantWnd__RequestBuyItem_x                             0x73BAA0
#define CMerchantWnd__RequestSellItem_x                            0x73C510
#define CMerchantWnd__SelectRecoverySlot_x                         0x734EF0
#define CMerchantWnd__SelectBuySellSlot_x                          0x734150
#define CMerchantWnd__ActualSelect_x                               0x7389C0

// CObfuscator
#define CObfuscator__doit_x                                        0x853510

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E2160
#define CSidlManager__CreateLabel_x                                0x79D530

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x660120
#define CSidlScreenWnd__CalculateVSBRange_x                        0x660050
#define CSidlScreenWnd__ConvertToRes_x                             0x8FDD60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9C90
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DB1A0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DB250
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA710
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D9640
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8D90
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D9830
#define CSidlScreenWnd__Init1_x                                    0x8DAE70
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9D40
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8F50
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA960
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D8850
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8D20
#define CSidlScreenWnd__WndNotification_x                          0x8DABF0
#define CSidlScreenWnd__GetChildItem_x                             0x8D8E60
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC2B0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FAF30
#define CSkillMgr__GetSkillCap_x                                   0x5FB0F0
#define CSkillMgr__GetNameToken_x                                  0x5FAB50

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FD010
#define CSliderWnd__SetValue_x                                     0x8FD1E0
#define CSliderWnd__SetNumTicks_x                                  0x8FD960

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A5220

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F8920
#define CStmlWnd__CalculateHSBRange_x                              0x8F0E60
#define CStmlWnd__CalculateVSBRange_x                              0x8F0EF0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F1060
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F1940
#define CStmlWnd__ForceParseNow_x                                  0x8F92E0
#define CStmlWnd__GetNextTagPiece_x                                0x8F1840
#define CStmlWnd__GetSTMLText_x                                    0x6975A0
#define CStmlWnd__GetVisibleText_x                                 0x8F2390
#define CStmlWnd__InitializeWindowVariables_x                      0x8F4700
#define CStmlWnd__MakeStmlColorTag_x                               0x8F0160
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F01C0
#define CStmlWnd__SetSTMLText_x                                    0x8F5F60
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F85C0
#define CStmlWnd__UpdateHistoryString_x                            0x8F32C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EF7F0
#define CTabWnd__DrawCurrentPage_x                                 0x8EF060
#define CTabWnd__DrawTab_x                                         0x8EEE20
#define CTabWnd__GetCurrentPage_x                                  0x8EF430
#define CTabWnd__GetPageInnerRect_x                                0x8EEB10
#define CTabWnd__GetTabInnerRect_x                                 0x8EED10
#define CTabWnd__GetTabRect_x                                      0x8EEBE0
#define CTabWnd__InsertPage_x                                      0x8EFAE0
#define CTabWnd__SetPage_x                                         0x8EF460
#define CTabWnd__SetPageRect_x                                     0x8EF730
#define CTabWnd__UpdatePage_x                                      0x8EFA80

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432FC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D69D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903210

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC2F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59CBD0
#define CXStr__CXStr1_x                                            0x4037C0
#define CXStr__CXStr3_x                                            0x89F690
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x89F800
#define CXStr__operator_equal1_x                                   0x89F850
#define CXStr__operator_plus_equal1_x                              0x8A0970

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8CB4C0
#define CXWnd__Center_x                                            0x8D16D0
#define CXWnd__ClrFocus_x                                          0x8CB0A0
#define CXWnd__DoAllDrawing_x                                      0x8D1300
#define CXWnd__DrawChildren_x                                      0x8D14B0
#define CXWnd__DrawColoredRect_x                                   0x8CB870
#define CXWnd__DrawTooltip_x                                       0x8CBB10
#define CXWnd__DrawTooltipAtPoint_x                                0x8D0250
#define CXWnd__GetBorderFrame_x                                    0x8CBF80
#define CXWnd__GetChildWndAt_x                                     0x8D2090
#define CXWnd__GetClientClipRect_x                                 0x8CBD30
#define CXWnd__GetScreenClipRect_x                                 0x8D0950
#define CXWnd__GetScreenRect_x                                     0x8CC150
#define CXWnd__GetTooltipRect_x                                    0x8CB9A0
#define CXWnd__GetWindowTextA_x                                    0x4242A0
#define CXWnd__IsActive_x                                          0x8C6AD0
#define CXWnd__IsDescendantOf_x                                    0x8CBEC0
#define CXWnd__IsReallyVisible_x                                   0x8CF280
#define CXWnd__IsType_x                                            0x8FFA30
#define CXWnd__Move_x                                              0x8CE9B0
#define CXWnd__Move1_x                                             0x8D0FA0
#define CXWnd__ProcessTransition_x                                 0x8CB470
#define CXWnd__Refade_x                                            0x8CB250
#define CXWnd__Resize_x                                            0x8CC220
#define CXWnd__Right_x                                             0x8D0750
#define CXWnd__SetFocus_x                                          0x8CDB10
#define CXWnd__SetFont_x                                           0x8CB0F0
#define CXWnd__SetKeyTooltip_x                                     0x8CC480
#define CXWnd__SetMouseOver_x                                      0x8D0C90
#define CXWnd__StartFade_x                                         0x8CB510
#define CXWnd__GetChildItem_x                                      0x8D0BD0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C83F0
#define CXWndManager__DrawWindows_x                                0x8C8030
#define CXWndManager__GetKeyboardFlags_x                           0x8C6610
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6F60
#define CXWndManager__RemoveWnd_x                                  0x8C6C60

// CDBStr
#define CDBStr__GetString_x                                        0x4A85B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F5D0
#define EQ_Character__Cur_HP_x                                     0x464AD0
#define EQ_Character__Cur_Mana_x                                   0x457B30
#define EQ_Character__GetAACastingTimeModifier_x                   0x4488A0
#define EQ_Character__GetCharInfo2_x                               0x872950
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43FB50
#define EQ_Character__GetFocusRangeModifier_x                      0x43FD90
#define EQ_Character__Max_Endurance_x                              0x5C2750
#define EQ_Character__Max_HP_x                                     0x45A730
#define EQ_Character__Max_Mana_x                                   0x5C2580
#define EQ_Character__doCombatAbility_x                            0x5BFBD0
#define EQ_Character__UseSkill_x                                   0x470030
#define EQ_Character__GetConLevel_x                                0x5B46A0
#define EQ_Character__IsExpansionFlag_x                            0x4237E0
#define EQ_Character__TotalEffect_x                                0x44C840
#define EQ_Character__GetPCSpellAffect_x                           0x448C90

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x594DD0
#define EQ_Item__CreateItemTagString_x                             0x851DC0
#define EQ_Item__IsStackable_x                                     0x8461A0
#define EQ_Item__GetImageNum_x                                     0x848E70
#define EQ_Item__CreateItemClient_x                                0x5959A0
#define EQ_Item__GetItemValue_x                                    0x850A60
#define EQ_Item__ValueSellMerchant_x                               0x853150

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C83B0
#define EQ_LoadingS__Array_x                                       0xC218E8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C3DA0
#define EQ_PC__GetAlternateAbilityId_x                             0x85B360
#define EQ_PC__GetCombatAbility_x                                  0x85B3F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x856290
#define EQ_PC__GetItemTimerValue_x                                 0x5BD6C0
#define EQ_PC__HasLoreItem_x                                       0x5B7B80
#define EQ_PC__AlertInventoryChanged_x                             0x5B4670
#define EQ_PC__GetPcZoneClient_x                                   0x5DE4A0
#define EQ_PC__RemoveMyAffect_x                                    0x5BCB60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5101E0
#define EQItemList__add_item_x                                     0x510120
#define EQItemList__delete_item_x                                  0x5105E0
#define EQItemList__FreeItemList_x                                 0x5104E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A7890

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C9350
#define EQPlayer__dEQPlayer_x                                      0x5D2210
#define EQPlayer__DoAttack_x                                       0x5E4390
#define EQPlayer__EQPlayer_x                                       0x5D4630
#define EQPlayer__SetNameSpriteState_x                             0x5CF0F0
#define EQPlayer__SetNameSpriteTint_x                              0x5CA780
#define EQPlayer__IsBodyType_j_x                                   0x930AB0
#define EQPlayer__IsTargetable_x                                   0x9313B0
#define EQPlayer__CanSee_x                                         0x9318D0
#define PlayerZoneClient__ChangeHeight_x                           0x5E4250
#define EQPlayer__CanSeeTargetIndicator_x                          0x9319C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D8A20
#define EQPlayerManager__GetSpawnByName_x                          0x5D8E80

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59AF00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59AF40
#define KeypressHandler__ClearCommandStateArray_x                  0x59AAE0
#define KeypressHandler__HandleKeyDown_x                           0x599440
#define KeypressHandler__HandleKeyUp_x                             0x599760
#define KeypressHandler__SaveKeymapping_x                          0x59ABB0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70BBB0
#define MapViewMap__SaveEx_x                                       0x70F490

#define PlayerPointManager__GetAltCurrency_x                       0x86D910

// StringTable 
#define StringTable__getString_x                                   0x868460

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C2200
#define PcZoneClient__RemovePetEffect_x                            0x5BDBB0
#define PcZoneClient__HasAlternateAbility_x                        0x5BE670

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E9D0

//IconCache
#define IconCache__GetIcon_x                                       0x6A7C70

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69EA40
#define CContainerMgr__CloseContainer_x                            0x69F260

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76D7E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58DF70

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DFDB0
#define EQ_Spell__SpellAffects_x                                   0x4DD490
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DD500
#define CharacterZoneClient__CalcAffectChange_x                    0x447CF0
#define CLootWnd__LootAll_x                                        0x701420

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B31E0
#define CTargetWnd__WndNotification_x                              0x7B2CD0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B83C0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D9230

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x497E60

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EB210
#define CSidlManager__FindAnimation1_x                             0x8E0040

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CF8D0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CF880
#define CAltAbilityData__GetMaxRank_x                              0x4C4980

//CTargetRing
#define CTargetRing__Cast_x                                        0x58B850

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x456500

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x689380
#define CCastSpellWnd__IsBardSongPlaying_x                         0x688B40
