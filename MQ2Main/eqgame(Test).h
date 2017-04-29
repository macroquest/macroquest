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
#define __ExpectedVersionDate                                     "Apr 27 2017"
#define __ExpectedVersionTime                                     "18:14:17"
#define __ActualVersionDate_x                                      0xAD3240
#define __ActualVersionTime_x                                      0xAD324C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5A1BD0
#define __MemChecker1_x                                            0x8972D0
#define __MemChecker2_x                                            0x637D70
#define __MemChecker3_x                                            0x637CC0
#define __MemChecker4_x                                            0x7E9FA0
#define __EncryptPad0_x                                            0xC2D328
#define __EncryptPad1_x                                            0xD086E0
#define __EncryptPad2_x                                            0xC56B10
#define __EncryptPad3_x                                            0xC56710
#define __EncryptPad4_x                                            0xCF6CE0
#define __EncryptPad5_x                                            0x10B1370
#define __AC1_x                                                    0x7A9555
#define __AC2_x                                                    0x55BB37
#define __AC3_x                                                    0x559CD0
#define __AC4_x                                                    0x56BD91
#define __AC5_x                                                    0x57EDFB
#define __AC6_x                                                    0x5829AE
#define __AC7_x                                                    0x5793FC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FE4DFC

// Direct Input
#define DI8__Main_x                                                0x10B1348
#define DI8__Keyboard_x                                            0x10B134C
#define DI8__Mouse_x                                               0x10B1350
#define DI8__Mouse_Copy_x                                          0xF1F70C
#define DI8__Mouse_Check_x                                         0xFA9034
#define __AutoSkillArray_x                                         0xF20620
#define __Attack_x                                                 0xFA3C17
#define __Autofire_x                                               0xFA3C18
#define __BindList_x                                               0xC08050
#define g_eqCommandStates_x                                        0xF0E730
#define __Clicks_x                                                 0xF1F7C8
#define __CommandList_x                                            0xC0A6C8
#define __CurrentMapLabel_x                                        0x10B6DD0
#define __CurrentSocial_x                                          0xBD9424
#define __DoAbilityList_x                                          0xF55ECC
#define __do_loot_x                                                0x52A7F0
#define __DrawHandler_x                                            0x171DC84
#define __GroupCount_x                                             0xF0FD62

#define __Guilds_x                                                 0xF15978
#define __gWorld_x                                                 0xF1221C
#define __HotkeyPage_x                                             0xF9C8CC
#define __HWnd_x                                                   0xFA9150
#define __InChatMode_x                                             0xF1F6F4
#define __LastTell_x                                               0xF215C8
#define __LMouseHeldTime_x                                         0xF1F834
#define __Mouse_x                                                  0x10B1354
#define __MouseLook_x                                              0xF1F78E
#define __MouseEventTime_x                                         0xFA441C
#define __gpbCommandEvent_x                                        0xF122E4
#define __NetStatusToggle_x                                        0xF1F791
#define __PCNames_x                                                0xF20BDC
#define __RangeAttackReady_x                                       0xF20904
#define __RMouseHeldTime_x                                         0xF1F830
#define __RunWalkState_x                                           0xF1F6F8
#define __ScreenMode_x                                             0xE5E418
#define __ScreenX_x                                                0xF1F6AC
#define __ScreenY_x                                                0xF1F6A8
#define __ScreenXMax_x                                             0xF1F6B0
#define __ScreenYMax_x                                             0xF1F6B4
#define __ServerHost_x                                             0xF0FCAC
#define __ServerName_x                                             0xF55E8C
#define __ShiftKeyDown_x                                           0xF1FD88
#define __ShowNames_x                                              0xF20AC4
#define __Socials_x                                                0xF55F8C
#define __SubscriptionType_x                                       0x10E4D94
#define __TargetAggroHolder_x                                      0x10B8FA4
#define __ZoneType_x                                               0xF1FB8C
#define __GroupAggro_x                                             0x10B8FE4
#define __LoginName_x                                              0xFA7C2C
#define __Inviter_x                                                0xFA3B94
#define __AttackOnAssist_x                                         0xF20A80
#define __UseTellWindows_x                                         0xF20D74

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF12308
#define instEQZoneInfo_x                                           0xF1F984
#define instKeypressHandler_x                                      0xFA4400
#define pinstActiveBanker_x                                        0xF122C0
#define pinstActiveCorpse_x                                        0xF122C4
#define pinstActiveGMaster_x                                       0xF122C8
#define pinstActiveMerchant_x                                      0xF122BC
#define pinstAggroInfo_x                                           0xD1BD88
#define pinstAltAdvManager_x                                       0xE5F4F8
#define pinstAuraMgr_x                                             0xD2C4F8
#define pinstBandageTarget_x                                       0xF122A8
#define pinstCamActor_x                                            0xE5EE48
#define pinstCDBStr_x                                              0xE5E3AC
#define pinstCDisplay_x                                            0xF122D0
#define pinstCEverQuest_x                                          0x10B14C8
#define pinstEverQuestInfo_x                                       0xF1F6A0
#define pinstCharData_x                                            0xF1228C
#define pinstCharSpawn_x                                           0xF122B4
#define pinstControlledMissile_x                                   0xF12288
#define pinstControlledPlayer_x                                    0xF122B4
#define pinstCSidlManager_x                                        0x171D074
#define pinstCXWndManager_x                                        0x171D06C
#define instDynamicZone_x                                          0xF1F540
#define pinstDZMember_x                                            0xF1F650
#define pinstDZTimerInfo_x                                         0xF1F654
#define pinstEQItemList_x                                          0xF0E984
#define pinstEQObjectList_x                                        0xF0F75C
#define instEQMisc_x                                               0xBF0690
#define pinstEQSoundManager_x                                      0xE5FAC8
#define instExpeditionLeader_x                                     0xF1F58A
#define instExpeditionName_x                                       0xF1F5CA
#define pinstGroup_x                                               0xF0FD5E
#define pinstImeManager_x                                          0x171D078
#define pinstLocalPlayer_x                                         0xF122A0
#define pinstMercenaryData_x                                       0xFA4A80
#define pinstMercenaryStats_x                                      0x10B90F0
#define pinstMercAltAbilities_x                                    0xE5F880
#define pinstModelPlayer_x                                         0xF122CC
#define pinstPCData_x                                              0xF1228C
#define pinstSkillMgr_x                                            0xFA58E8
#define pinstSpawnManager_x                                        0xFA51D0
#define pinstSpellManager_x                                        0xFA5A30
#define pinstSpellSets_x                                           0xF9C930
#define pinstStringTable_x                                         0xF12234
#define pinstSwitchManager_x                                       0xF0F8F0
#define pinstTarget_x                                              0xF122B8
#define pinstTargetObject_x                                        0xF12290
#define pinstTargetSwitch_x                                        0xF12294
#define pinstTaskMember_x                                          0xE5E2F8
#define pinstTrackTarget_x                                         0xF122AC
#define pinstTradeTarget_x                                         0xF1229C
#define instTributeActive_x                                        0xBF06B5
#define pinstViewActor_x                                           0xE5EE44
#define pinstWorldData_x                                           0xF12270
#define pinstZoneAddr_x                                            0xF1FC24
#define pinstPlayerPath_x                                          0xFA5230
#define pinstTargetIndicator_x                                     0xFA5BC8
#define pinstCTargetManager_x                                      0xFA5C28
#define EQObject_Top_x                                             0xF12280
#define pinstRealEstateItems_x                                     0xFA57D4

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE5ED60
#define pinstCAchievementsWnd_x                                    0xE5EDBC
#define pinstCTextOverlay_x                                        0xD1C288
#define pinstCAudioTriggersWindow_x                                0xD1C118
#define pinstCCharacterSelect_x                                    0xE5ECD0
#define pinstCFacePick_x                                           0xE5EC80
#define pinstCNoteWnd_x                                            0xE5EC88
#define pinstCBookWnd_x                                            0xE5EC90
#define pinstCPetInfoWnd_x                                         0xE5EC94
#define pinstCTrainWnd_x                                           0xE5EC98
#define pinstCSkillsWnd_x                                          0xE5EC9C
#define pinstCSkillsSelectWnd_x                                    0xE5ECA0
#define pinstCCombatSkillsSelectWnd_x                              0xE5ECA4
#define pinstCFriendsWnd_x                                         0xE5ECA8
#define pinstCAuraWnd_x                                            0xE5ECAC
#define pinstCRespawnWnd_x                                         0xE5ECB0
#define pinstCBandolierWnd_x                                       0xE5ECB4
#define pinstCPotionBeltWnd_x                                      0xE5ECB8
#define pinstCAAWnd_x                                              0xE5ECBC
#define pinstCGroupSearchFiltersWnd_x                              0xE5ECC0
#define pinstCLoadskinWnd_x                                        0xE5ECC4
#define pinstCAlarmWnd_x                                           0xE5ECC8
#define pinstCMusicPlayerWnd_x                                     0xE5ECCC
#define pinstCMailWnd_x                                            0xE5ECD4
#define pinstCMailCompositionWnd_x                                 0xE5ECD8
#define pinstCMailAddressBookWnd_x                                 0xE5ECDC
#define pinstCRaidWnd_x                                            0xE5ECE4
#define pinstCRaidOptionsWnd_x                                     0xE5ECE8
#define pinstCBreathWnd_x                                          0xE5ECEC
#define pinstCMapViewWnd_x                                         0xE5ECF0
#define pinstCMapToolbarWnd_x                                      0xE5ECF4
#define pinstCEditLabelWnd_x                                       0xE5ECF8
#define pinstCTargetWnd_x                                          0xE5ECFC
#define pinstCColorPickerWnd_x                                     0xE5ED00
#define pinstCPlayerWnd_x                                          0xE5ED04
#define pinstCOptionsWnd_x                                         0xE5ED08
#define pinstCBuffWindowNORMAL_x                                   0xE5ED0C
#define pinstCBuffWindowSHORT_x                                    0xE5ED10
#define pinstCharacterCreation_x                                   0xE5ED14
#define pinstCCursorAttachment_x                                   0xE5ED18
#define pinstCCastingWnd_x                                         0xE5ED1C
#define pinstCCastSpellWnd_x                                       0xE5ED20
#define pinstCSpellBookWnd_x                                       0xE5ED24
#define pinstCInventoryWnd_x                                       0xE5ED28
#define pinstCBankWnd_x                                            0xE5ED30
#define pinstCQuantityWnd_x                                        0xE5ED34
#define pinstCLootWnd_x                                            0xE5ED38
#define pinstCActionsWnd_x                                         0xE5ED3C
#define pinstCCombatAbilityWnd_x                                   0xE5ED44
#define pinstCMerchantWnd_x                                        0xE5ED48
#define pinstCTradeWnd_x                                           0xE5ED50
#define pinstCSelectorWnd_x                                        0xE5ED54
#define pinstCBazaarWnd_x                                          0xE5ED58
#define pinstCBazaarSearchWnd_x                                    0xE5ED5C
#define pinstCGiveWnd_x                                            0xE5ED78
#define pinstCTrackingWnd_x                                        0xE5ED80
#define pinstCInspectWnd_x                                         0xE5ED84
#define pinstCSocialEditWnd_x                                      0xE5ED88
#define pinstCFeedbackWnd_x                                        0xE5ED8C
#define pinstCBugReportWnd_x                                       0xE5ED90
#define pinstCVideoModesWnd_x                                      0xE5ED94
#define pinstCTextEntryWnd_x                                       0xE5ED9C
#define pinstCFileSelectionWnd_x                                   0xE5EDA0
#define pinstCCompassWnd_x                                         0xE5EDA4
#define pinstCPlayerNotesWnd_x                                     0xE5EDA8
#define pinstCGemsGameWnd_x                                        0xE5EDAC
#define pinstCTimeLeftWnd_x                                        0xE5EDB0
#define pinstCPetitionQWnd_x                                       0xE5EDCC
#define pinstCStoryWnd_x                                           0xE5EDD0
#define pinstCJournalTextWnd_x                                     0xE5EDD4
#define pinstCJournalCatWnd_x                                      0xE5EDD8
#define pinstCBodyTintWnd_x                                        0xE5EDDC
#define pinstCServerListWnd_x                                      0xE5EDE0
#define pinstCAvaZoneWnd_x                                         0xE5EDEC
#define pinstCBlockedBuffWnd_x                                     0xE5EDF0
#define pinstCBlockedPetBuffWnd_x                                  0xE5EDF4
#define pinstCInvSlotMgr_x                                         0xE5EE3C
#define pinstCContainerMgr_x                                       0xE5EE40
#define pinstCAdventureLeaderboardWnd_x                            0x10B1E78
#define pinstCAdventureRequestWnd_x                                0x10B1EF0
#define pinstCAltStorageWnd_x                                      0x10B21D0
#define pinstCAdventureStatsWnd_x                                  0x10B1F68
#define pinstCBarterMerchantWnd_x                                  0x10B2DB8
#define pinstCBarterSearchWnd_x                                    0x10B2E30
#define pinstCBarterWnd_x                                          0x10B2EA8
#define pinstCChatWindowManager_x                                  0x10B3538
#define pinstCDynamicZoneWnd_x                                     0x10B39E8
#define pinstCEQMainWnd_x                                          0x10B3B80
#define pinstCFellowshipWnd_x                                      0x10B397C
#define pinstCFindLocationWnd_x                                    0x10B3E50
#define pinstCGroupSearchWnd_x                                     0x10B4120
#define pinstCGroupWnd_x                                           0x10B4198
#define pinstCGuildBankWnd_x                                       0x10B4210
#define pinstCGuildMgmtWnd_x                                       0x10B6300
#define pinstCHotButtonWnd_x                                       0x10B63FC
#define pinstCHotButtonWnd1_x                                      0x10B63FC
#define pinstCHotButtonWnd2_x                                      0x10B6400
#define pinstCHotButtonWnd3_x                                      0x10B6404
#define pinstCHotButtonWnd4_x                                      0x10B6428
#define pinstCItemDisplayManager_x                                 0x10B6720
#define pinstCItemExpTransferWnd_x                                 0x10B679C
#define pinstCLFGuildWnd_x                                         0x10B6A78
#define pinstCMIZoneSelectWnd_x                                    0x10B7060
#define pinstCConfirmationDialog_x                                 0x10B7768
#define pinstCPopupWndManager_x                                    0x10B7768
#define pinstCProgressionSelectionWnd_x                            0x10B7858
#define pinstCPvPStatsWnd_x                                        0x10B7948
#define pinstCLargeDialogWnd_x                                     0x10B8050
#define pinstCTaskWnd_x                                            0x10B93D0
#define pinstCTaskSomething_x                                      0xD2CEA0
#define pinstCTaskTemplateSelectWnd_x                              0x10B9358
#define pinstCTipWndOFDAY_x                                        0x10B9538
#define pinstCTipWndCONTEXT_x                                      0x10B953C
#define pinstCTitleWnd_x                                           0x10B95B8
#define pinstCContextMenuManager_x                                 0x171CFE4
#define pinstCVoiceMacroWnd_x                                      0xFA6000
#define pinstCHtmlWnd_x                                            0xFA60F0
#define pinstIconCache_x                                           0x10B3B54
#define pinstCTradeskillWnd_x                                      0x10B96B8
#define pinstCAdvancedLootWnd_x                                    0xE5EE30
#define pinstRewardSelectionWnd_x                                  0x10B7E70

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x541930
#define __ConvertItemTags_x                                        0x52F2F0
#define __ExecuteCmd_x                                             0x519E70
#define __EQGetTime_x                                              0x896C70
#define __get_melee_range_x                                        0x520AC0
#define __GetGaugeValueFromEQ_x                                    0x7A8110
#define __GetLabelFromEQ_x                                         0x7A94E0
#define __ToggleKeyRingItem_x                                      0x488560
#define __GetXTargetType_x                                         0x9279E0
#define __LoadFrontEnd_x                                           0x637440
#define __NewUIINI_x                                               0x7A7AE0
#define __ProcessGameEvents_x                                      0x57B190
#define __ProcessMouseEvent_x                                      0x57A930
#define CrashDetected_x                                            0x638E00
#define wwsCrashReportCheckForUploader_x                           0x7F5B20
#define __AppCrashWrapper_x                                        0xC56704
#define __pCrashHandler_x                                          0x10C6568
#define __CrashHandler_x                                           0x7F5580
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F7D20
#define DrawNetStatus_x                                            0x5B1850
#define Util__FastTime_x                                           0x896910
#define Expansion_HoT_x                                            0xF20A70
#define __HelpPath_x                                               0xFA4188
#define __STMLToText_x                                             0x8DCEE0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423100
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DEA0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DC80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D0250
#define AltAdvManager__IsAbilityReady_x                            0x4D02C0
#define AltAdvManager__GetAAById_x                                 0x4D07B0
#define AltAdvManager__CanTrainAbility_x                           0x4D13E0
#define AltAdvManager__CanSeeAbility_x                             0x4D0FA0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x466C10
#define CharacterZoneClient__MakeMeVisible_x                       0x46B2F0
#define CharacterZoneClient__IsStackBlocked_x                      0x44B370
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44A830
#define CharacterZoneClient__GetItemCountWorn_x                    0x464B90
#define CharacterZoneClient__GetItemCountInInventory_x             0x464C70
#define CharacterZoneClient__GetCursorItemCount_x                  0x464D50
#define CharacterZoneClient__FindAffectSlot_x                      0x4508C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x666D50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x675020

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x590980
#define CButtonWnd__CButtonWnd_x                                   0x8D1270

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6900E0
#define CChatManager__InitContextMenu_x                            0x691230
#define CChatManager__FreeChatWindow_x                             0x68FB70
#define CChatManager__GetLockedActiveChatWindow_x                  0x698A90
#define CChatManager__SetLockedActiveChatWindow_x                  0x6900B0
// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DB220
#define CContextMenu__dCContextMenu_x                              0x8DB430
#define CContextMenu__AddMenuItem_x                                0x8DB440
#define CContextMenu__RemoveMenuItem_x                             0x8DB730
#define CContextMenu__RemoveAllMenuItems_x                         0x8DB750
#define CContextMenuManager__AddMenu_x                             0x8C7800
#define CContextMenuManager__RemoveMenu_x                          0x8C7BA0
#define CContextMenuManager__PopupMenu_x                           0x8C7FF0
#define CContextMenuManager__Flush_x                               0x8C7870
#define CContextMenuManager__GetMenu_x                             0x419580
#define CContextMenu__CheckMenuItem_x                              0x8DB7D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87B0B0
#define CChatService__GetFriendName_x                              0x87B0C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x696E40
#define CChatWindow__Clear_x                                       0x696720
#define CChatWindow__WndNotification_x                             0x697380

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CB650
#define CComboWnd__Draw_x                                          0x8CB860
#define CComboWnd__GetCurChoice_x                                  0x8CB400
#define CComboWnd__GetListRect_x                                   0x8CBB00
#define CComboWnd__GetTextRect_x                                   0x8CB6C0
#define CComboWnd__InsertChoice_x                                  0x8CBB70
#define CComboWnd__SetColors_x                                     0x8CB390
#define CComboWnd__SetChoice_x                                     0x8CB3C0
#define CComboWnd__GetItemCount_x                                  0x8CB3F0
#define CComboWnd__GetCurChoiceText_x                              0x8CB440

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A07D0
#define CContainerWnd__vftable_x                                   0xADCE28

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BE5E0
#define CDisplay__GetClickedActor_x                                0x4B6F10
#define CDisplay__GetUserDefinedColor_x                            0x4B5AF0
#define CDisplay__GetWorldFilePath_x                               0x4B4F40
#define CDisplay__is3dON_x                                         0x4B43D0
#define CDisplay__ReloadUI_x                                       0x4C9BB0
#define CDisplay__WriteTextHD2_x                                   0x4BA9A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F18C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DF790
#define CEditWnd__GetCharIndexPt_x                                 0x8E0830
#define CEditWnd__GetDisplayString_x                               0x8DF940
#define CEditWnd__GetHorzOffset_x                                  0x8DFC80
#define CEditWnd__GetLineForPrintableChar_x                        0x8E02F0
#define CEditWnd__GetSelStartPt_x                                  0x8E0AF0
#define CEditWnd__GetSTMLSafeText_x                                0x8DFE20
#define CEditWnd__PointFromPrintableChar_x                         0x8E03E0
#define CEditWnd__SelectableCharFromPoint_x                        0x8E0560
#define CEditWnd__SetEditable_x                                    0x8DFDF0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5625C0
#define CEverQuest__ClickedPlayer_x                                0x55C280
#define CEverQuest__CreateTargetIndicator_x                        0x55D170
#define CEverQuest__DeleteTargetIndicator_x                        0x55D1F0
#define CEverQuest__DoTellWindow_x                                 0x475E80
#define CEverQuest__OutputTextToLog_x                              0x475AE0
#define CEverQuest__DropHeldItemOnGround_x                         0x572FD0
#define CEverQuest__dsp_chat_x                                     0x4761C0
#define CEverQuest__trimName_x                                     0x558BD0
#define CEverQuest__Emote_x                                        0x570DB0
#define CEverQuest__EnterZone_x                                    0x56BF20
#define CEverQuest__GetBodyTypeDesc_x                              0x556630
#define CEverQuest__GetClassDesc_x                                 0x55FA00
#define CEverQuest__GetClassThreeLetterCode_x                      0x560000
#define CEverQuest__GetDeityDesc_x                                 0x556F10
#define CEverQuest__GetLangDesc_x                                  0x5569C0
#define CEverQuest__GetRaceDesc_x                                  0x5601C0
#define CEverQuest__InterpretCmd_x                                 0x563D40
#define CEverQuest__LeftClickedOnPlayer_x                          0x577850
#define CEverQuest__LMouseUp_x                                     0x579950
#define CEverQuest__RightClickedOnPlayer_x                         0x578360
#define CEverQuest__RMouseUp_x                                     0x5793B0
#define CEverQuest__SetGameState_x                                 0x55CB40
#define CEverQuest__UPCNotificationFlush_x                         0x554440
#define CEverQuest__IssuePetCommand_x                              0x564720

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B14D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B1530
#define CGaugeWnd__Draw_x                                          0x6B1960

// CGuild
#define CGuild__FindMemberByName_x                                 0x43AC00
#define CGuild__GetGuildName_x                                     0x43B0D0
#define CGuild__GetGuildIndex_x                                    0x43C2A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CDA10

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DABC0
#define CInvSlotMgr__MoveItem_x                                    0x6DBA70
#define CInvSlotMgr__SelectSlot_x                                  0x6DAC70

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DA070
#define CInvSlot__SliderComplete_x                                 0x6D7880
#define CInvSlot__GetItemBase_x                                    0x6D6D00
#define CInvSlot__UpdateItem_x                                     0x6D7280

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DCED0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6DDFF0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A3B20
#define CItemDisplayWnd__UpdateStrings_x                           0x6DF050
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6EBB20
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6EC060
#define CItemDisplayWnd__SetItem_x                                 0x6F1BB0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7DAEC0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6E5630

// CLabel 
#define CLabel__Draw_x                                             0x6F88B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B7200
#define CListWnd__dCListWnd_x                                      0x8B8420
#define CListWnd__AddColumn_x                                      0x8B83C0
#define CListWnd__AddColumn1_x                                     0x8B7A50
#define CListWnd__AddLine_x                                        0x8B74B0
#define CListWnd__AddString_x                                      0x8B76D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B4490
#define CListWnd__CalculateVSBRange_x                              0x8B66C0
#define CListWnd__ClearSel_x                                       0x8B37B0
#define CListWnd__ClearAllSel_x                                    0x8B3760
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B7090
#define CListWnd__Compare_x                                        0x8B5000
#define CListWnd__Draw_x                                           0x8B62C0
#define CListWnd__DrawColumnSeparators_x                           0x8B6150
#define CListWnd__DrawHeader_x                                     0x8B3A70
#define CListWnd__DrawItem_x                                       0x8B5680
#define CListWnd__DrawLine_x                                       0x8B5DF0
#define CListWnd__DrawSeparator_x                                  0x8B61F0
#define CListWnd__EnableLine_x                                     0x8B3990
#define CListWnd__EnsureVisible_x                                  0x8B45F0
#define CListWnd__ExtendSel_x                                      0x8B5590
#define CListWnd__GetColumnMinWidth_x                              0x8B3160
#define CListWnd__GetColumnWidth_x                                 0x8B3090
#define CListWnd__GetCurSel_x                                      0x8B2870
#define CListWnd__GetItemAtPoint_x                                 0x8B4890
#define CListWnd__GetItemAtPoint1_x                                0x8B4900
#define CListWnd__GetItemData_x                                    0x8B2BB0
#define CListWnd__GetItemHeight_x                                  0x8B40F0
#define CListWnd__GetItemIcon_x                                    0x8B2DA0
#define CListWnd__GetItemRect_x                                    0x8B46D0
#define CListWnd__GetItemText_x                                    0x8B2C50
#define CListWnd__GetSelList_x                                     0x8B7940
#define CListWnd__GetSeparatorRect_x                               0x8B4F30
#define CListWnd__InsertLine_x                                     0x8B78B0
#define CListWnd__RemoveLine_x                                     0x8B78C0
#define CListWnd__SetColors_x                                      0x8B29C0
#define CListWnd__SetColumnJustification_x                         0x8B33F0
#define CListWnd__SetColumnWidth_x                                 0x8B3110
#define CListWnd__SetCurSel_x                                      0x8B28B0
#define CListWnd__SetItemColor_x                                   0x8B6D80
#define CListWnd__SetItemData_x                                    0x8B3810
#define CListWnd__SetItemText_x                                    0x8B6BC0
#define CListWnd__ShiftColumnSeparator_x                           0x8B6A50
#define CListWnd__Sort_x                                           0x8B8520
#define CListWnd__ToggleSel_x                                      0x8B36E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7118C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x732EA0
#define CMerchantWnd__RequestBuyItem_x                             0x739F70
#define CMerchantWnd__RequestSellItem_x                            0x73AA40
#define CMerchantWnd__SelectRecoverySlot_x                         0x733150
#define CMerchantWnd__SelectBuySellSlot_x                          0x732350
#define CMerchantWnd__ActualSelect_x                               0x736E40

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x849540
#define CPacketScrambler__hton_x                                   0x849550

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D61D0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D62B0
#define CSidlManager__CreateLabel_x                                0x79B3D0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8D4760
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D6590

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8CD6F0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8CD5E0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F17A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CE000
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CF1E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CF290
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CE760
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CD9B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CD110
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CDBA0
#define CSidlScreenWnd__Init1_x                                    0x8CEEC0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CE0B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CD2D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CE9A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CCD60
#define CSidlScreenWnd__StoreIniVis_x                              0x8CD0C0
#define CSidlScreenWnd__WndNotification_x                          0x8CEC40
#define CSidlScreenWnd__GetChildItem_x                             0x8CD1E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C09B0
#define CSidlScreenWnd__m_layoutCopy_x                             0x171D048

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FCB90
#define CSkillMgr__GetSkillCap_x                                   0x5FCD70
#define CSkillMgr__GetNameToken_x                                  0x5FC740

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F0A70
#define CSliderWnd__SetValue_x                                     0x8F0C40
#define CSliderWnd__SetNumTicks_x                                  0x8F13C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A1780

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EAF80
#define CStmlWnd__CalculateHSBRange_x                              0x8E3570
#define CStmlWnd__CalculateVSBRange_x                              0x8E34E0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E36F0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E3FD0
#define CStmlWnd__ForceParseNow_x                                  0x8EB900
#define CStmlWnd__GetNextTagPiece_x                                0x8E3ED0
#define CStmlWnd__GetSTMLText_x                                    0x483B70
#define CStmlWnd__GetVisibleText_x                                 0x8E4A20
#define CStmlWnd__InitializeWindowVariables_x                      0x8E6D90
#define CStmlWnd__MakeStmlColorTag_x                               0x8E27E0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E2840
#define CStmlWnd__SetSTMLText_x                                    0x8E85E0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EAC20
#define CStmlWnd__UpdateHistoryString_x                            0x8E5950

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EEE00
#define CTabWnd__DrawCurrentPage_x                                 0x8EE690
#define CTabWnd__DrawTab_x                                         0x8EE450
#define CTabWnd__GetCurrentPage_x                                  0x8EEA40
#define CTabWnd__GetPageInnerRect_x                                0x8EE140
#define CTabWnd__GetTabInnerRect_x                                 0x8EE340
#define CTabWnd__GetTabRect_x                                      0x8EE210
#define CTabWnd__InsertPage_x                                      0x8EF0F0
#define CTabWnd__SetPage_x                                         0x8EEA70
#define CTabWnd__SetPageRect_x                                     0x8EED40
#define CTabWnd__UpdatePage_x                                      0x8EF090
#define CTabWnd__GetPageFromTabIndex_x                             0x8EE3A0
#define CTabWnd__GetCurrentTabIndex_x                              0x8EE0D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6DE1A0
#define CPageWnd__SetTabText_x                                     0x8FA860

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436790

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CB000
#define CTextureFont__GetTextExtent_x                              0x8CAD60

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6356B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F6CA0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B0A30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029E0
#define CXStr__CXStr1_x                                            0x403800
#define CXStr__CXStr3_x                                            0x893BB0
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x893D20
#define CXStr__operator_equal1_x                                   0x893D70
#define CXStr__operator_plus_equal1_x                              0x894E70

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BFBD0
#define CXWnd__Center_x                                            0x8C5E00
#define CXWnd__ClrFocus_x                                          0x8BF790
#define CXWnd__Destroy_x                                           0x8C68E0
#define CXWnd__DoAllDrawing_x                                      0x8C5A40
#define CXWnd__DrawChildren_x                                      0x8C5BF0
#define CXWnd__DrawColoredRect_x                                   0x8BFFB0
#define CXWnd__DrawTooltip_x                                       0x8C0250
#define CXWnd__DrawTooltipAtPoint_x                                0x8C4980
#define CXWnd__GetBorderFrame_x                                    0x8C0670
#define CXWnd__GetChildWndAt_x                                     0x8C67C0
#define CXWnd__GetClientClipRect_x                                 0x8C0470
#define CXWnd__GetScreenClipRect_x                                 0x8C5080
#define CXWnd__GetScreenRect_x                                     0x8C0840
#define CXWnd__GetTooltipRect_x                                    0x8C00E0
#define CXWnd__GetWindowTextA_x                                    0x4270A0
#define CXWnd__IsActive_x                                          0x8BB200
#define CXWnd__IsDescendantOf_x                                    0x8C05B0
#define CXWnd__IsReallyVisible_x                                   0x8C39B0
#define CXWnd__IsType_x                                            0x8C5E70
#define CScreenPieceTemplate__IsType_x                             0x8F34C0
#define CXWnd__Move_x                                              0x8C30A0
#define CXWnd__Move1_x                                             0x8C56F0
#define CXWnd__ProcessTransition_x                                 0x8BFB70
#define CXWnd__Refade_x                                            0x8BF940
#define CXWnd__Resize_x                                            0x8C0910
#define CXWnd__Right_x                                             0x8C4E80
#define CXWnd__SetFocus_x                                          0x8C21C0
#define CXWnd__SetFont_x                                           0x8BF7E0
#define CXWnd__SetKeyTooltip_x                                     0x8C0B80
#define CXWnd__SetMouseOver_x                                      0x8C53D0
#define CXWnd__StartFade_x                                         0x8BFC20
#define CXWnd__GetChildItem_x                                      0x8C5310
#define CXWnd__SetParent_x                                         0x8C6770

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BCAA0
#define CXWndManager__DrawWindows_x                                0x8BC6E0
#define CXWndManager__GetKeyboardFlags_x                           0x8BAD30
#define CXWndManager__HandleKeyboardMsg_x                          0x8BB690
#define CXWndManager__RemoveWnd_x                                  0x8BB390

// CDBStr
#define CDBStr__GetString_x                                        0x4B2920

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4518F0
#define EQ_Character__Cur_HP_x                                     0x466210
#define EQ_Character__Cur_Mana_x                                   0x459FD0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44AB40
#define EQ_Character__GetFocusCastingTimeModifier_x                0x442E90
#define EQ_Character__GetFocusRangeModifier_x                      0x442EF0
#define EQ_Character__GetHPRegen_x                                 0x4693F0
#define EQ_Character__GetEnduranceRegen_x                          0x465820
#define EQ_Character__GetManaRegen_x                               0x469990
#define EQ_Character__Max_Endurance_x                              0x5C32C0
#define EQ_Character__Max_HP_x                                     0x45CB40
#define EQ_Character__Max_Mana_x                                   0x5C30F0
#define EQ_Character__doCombatAbility_x                            0x5C07D0
#define EQ_Character__UseSkill_x                                   0x470370
#define EQ_Character__GetConLevel_x                                0x5B5E60
#define EQ_Character__IsExpansionFlag_x                            0x4265D0
#define EQ_Character__TotalEffect_x                                0x44EBF0
#define EQ_Character__GetPCSpellAffect_x                           0x44AF40
#define EQ_Character__SpellDuration_x                              0x448EE0
#define EQ_Character__FindItemByRecord_x                           0x463860
#define EQ_Character__GetAdjustedSkill_x                           0x4669C0
#define EQ_Character__GetBaseSkill_x                               0x45CA20

//ProfileManager_
#define ProfileManager__GetCurrentProfile_x                        0x866BC0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5CB300

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446200
#define CCharacterSelect__EnterWorld_x                             0x4459D0
#define CCharacterSelect__Quit_x                                   0x4445B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x596400
#define EQ_Item__CreateItemTagString_x                             0x847EE0
#define EQ_Item__IsStackable_x                                     0x83D950
#define EQ_Item__GetImageNum_x                                     0x8403B0
#define EQ_Item__CreateItemClient_x                                0x596FF0
#define EQ_Item__GetItemValue_x                                    0x846C30
#define EQ_Item__ValueSellMerchant_x                               0x849190
#define EQ_Item__IsKeyRingItem_x                                   0x83E3A0
#define EQ_Item__CanGoInBag_x                                      0x596590
#define EQ_Item__GetMaxItemCount_x                                 0x83D840
#define EQ_Item__GetHeldItem_x                                     0x83F1B0
#define EQ_Item__GetAugmentFitBySlot_x                             0x848FB0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D27E0
#define EQ_LoadingS__Array_x                                       0xBF8A78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C5750
#define EQ_PC__GetAlternateAbilityId_x                             0x8516B0
#define EQ_PC__GetCombatAbility_x                                  0x851740
#define EQ_PC__GetCombatAbilityTimer_x                             0x84C1F0
#define EQ_PC__GetItemRecastTimer_x                                0x5BEE90
#define EQ_PC__HasLoreItem_x                                       0x5B9460
#define EQ_PC__AlertInventoryChanged_x                             0x5B5E30
#define EQ_PC__GetPcZoneClient_x                                   0x5DF7A0
#define EQ_PC__RemoveMyAffect_x                                    0x5BE360
#define EQ_PC__GetKeyRingItems_x                                   0x84C610
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x85F3A0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x853630

// EQItemList 
#define EQItemList__EQItemList_x                                   0x51EB60
#define EQItemList__add_object_x                                   0x54B380
#define EQItemList__add_item_x                                     0x51EAA0
#define EQItemList__delete_item_x                                  0x51EF50
#define EQItemList__FreeItemList_x                                 0x51EE50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B1C10

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CB0A0
#define EQPlayer__dEQPlayer_x                                      0x5D3640
#define EQPlayer__DoAttack_x                                       0x5E5420
#define EQPlayer__EQPlayer_x                                       0x5D5D50
#define EQPlayer__SetNameSpriteState_x                             0x5D0590
#define EQPlayer__SetNameSpriteTint_x                              0x5CC4B0
#define PlayerBase__HasProperty_j_x                                0x9241D0
#define EQPlayer__IsTargetable_x                                   0x924470
#define EQPlayer__CanSee_x                                         0x9249D0
#define PlayerZoneClient__ChangeHeight_x                           0x5E52E0
#define EQPlayer__CanSeeTargetIndicator_x                          0x924AC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x924760

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D9D80
#define EQPlayerManager__GetSpawnByName_x                          0x5DA1E0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D9DB0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59C4E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59C520
#define KeypressHandler__ClearCommandStateArray_x                  0x59C0D0
#define KeypressHandler__HandleKeyDown_x                           0x59AA30
#define KeypressHandler__HandleKeyUp_x                             0x59AD50
#define KeypressHandler__SaveKeymapping_x                          0x59C1A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70A250
#define MapViewMap__SaveEx_x                                       0x70D580

#define PlayerPointManager__GetAltCurrency_x                       0x864CB0

// StringTable 
#define StringTable__getString_x                                   0x85F6D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C2D50
#define PcZoneClient__RemovePetEffect_x                            0x5BF360
#define PcZoneClient__HasAlternateAbility_x                        0x5BFD00
#define PcZoneClient__GetCurrentMod_x                              0x45BFF0
#define PcZoneClient__GetModCap_x                                  0x459730
#define PcZoneClient__CanEquipItem_x                               0x5C02B0
#define PcZoneClient__GetItemByID_x                                0x5C4B40
#define PcZoneClient__GetItemByItemClass_x                         0x5C5670

//Doors
#define EQSwitch__UseSwitch_x                                      0x552D60

//IconCache
#define IconCache__GetIcon_x                                       0x6A6C70

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69DB30
#define CContainerMgr__CloseContainer_x                            0x69E350

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76B200

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58F3A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4EC930
#define EQ_Spell__SpellAffects_x                                   0x4E9FE0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4EA050
#define CharacterZoneClient__CalcAffectChange_x                    0x44A010
#define CLootWnd__LootAll_x                                        0x6FFB00
#define CLootWnd__RequestLootSlot_x                                0x700310

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B0AA0
#define CTargetWnd__WndNotification_x                              0x7B0590
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B0C80

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B5B80

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E5610
#define EqSoundManager__PlayScriptMp3_x                            0x4E70B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A0F40

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DEDC0
#define CSidlManager__FindAnimation1_x                             0x8D4190

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D9FE0
#define CAltAbilityData__GetMercMaxRank_x                          0x4D9F90
#define CAltAbilityData__GetMaxRank_x                              0x4CE900

//CTargetRing
#define CTargetRing__Cast_x                                        0x58CC70

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x458750
#define CharacterBase__CreateItemGlobalIndex_x                     0x475040
#define CharacterBase__CreateItemIndex_x                           0x5180F0
#define CharacterBase__GetItemPossession_x                         0x443A70
#define CharacterBase__GetItemByGlobalIndex_x                      0x874DB0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6872D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x686A30

//messages
#define msg_spell_worn_off_x                                       0x4F43E0
#define msg_new_text_x                                             0x4FD9A0
#define msgTokenTextParam_x                                        0x4FA200

//SpellManager
#define SpellManager__vftable_x                                    0xAB9150
#define SpellManager__SpellManager_x                               0x47DCC0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x603AD0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x928500

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F0AB0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43E620
#define ItemGlobalIndex__IsEquippedLocation_x                      0x448860
#define ItemGlobalIndex__IsValidIndex_x                            0x458020

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x872C10
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x871B50

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F8B00

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6A2880
#define CCursorAttachment__Deactivate_x                            0x6A1DC0
