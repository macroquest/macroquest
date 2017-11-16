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
#define __ExpectedVersionDate                                     "Nov 16 2017"
#define __ExpectedVersionTime                                     "04:18:45"
#define __ActualVersionDate_x                                      0xAE5090
#define __ActualVersionTime_x                                      0xAE509C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AB020
#define __MemChecker1_x                                            0x8A4230
#define __MemChecker2_x                                            0x641220
#define __MemChecker3_x                                            0x641170
#define __MemChecker4_x                                            0x7F5980
#define __EncryptPad0_x                                            0xC3FFE8
#define __EncryptPad1_x                                            0xD19BA0
#define __EncryptPad2_x                                            0xC68ED0
#define __EncryptPad3_x                                            0xC68AD0
#define __EncryptPad4_x                                            0xD081A0
#define __EncryptPad5_x                                            0x10C32C0
#define __AC1_x                                                    0x7B4B45
#define __AC2_x                                                    0x564247
#define __AC3_x                                                    0x5623C0
#define __AC4_x                                                    0x574581
#define __AC5_x                                                    0x5882DB
#define __AC6_x                                                    0x58BE8E
#define __AC7_x                                                    0x5828DC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4920

// Direct Input
#define DI8__Main_x                                                0x10C3298
#define DI8__Keyboard_x                                            0x10C329C
#define DI8__Mouse_x                                               0x10C32A0
#define DI8__Mouse_Copy_x                                          0xF31454
#define DI8__Mouse_Check_x                                         0xFBAF84
#define __AutoSkillArray_x                                         0xF32368
#define __Attack_x                                                 0xFB5A5B
#define __Autofire_x                                               0xFB5A5C
#define __BindList_x                                               0xC1C368
#define g_eqCommandStates_x                                        0xF201A0
#define __Clicks_x                                                 0xF31510
#define __CommandList_x                                            0xC1EA80
#define __CurrentMapLabel_x                                        0x10C9290
#define __CurrentSocial_x                                          0xBEB8E8
#define __DoAbilityList_x                                          0xF67C20
#define __do_loot_x                                                0x533270
#define __DrawHandler_x                                            0x1732F0C
#define __GroupCount_x                                             0xF21AAA

#define __Guilds_x                                                 0xF276C0
#define __gWorld_x                                                 0xF23F64
#define __HotkeyPage_x                                             0xFAE620
#define __HWnd_x                                                   0xFBB0A0
#define __InChatMode_x                                             0xF3143C
#define __LastTell_x                                               0xF3331C
#define __LMouseHeldTime_x                                         0xF3157C
#define __Mouse_x                                                  0x10C32A4
#define __MouseLook_x                                              0xF314D6
#define __MouseEventTime_x                                         0xFB61F4
#define __gpbCommandEvent_x                                        0xF2402C
#define __NetStatusToggle_x                                        0xF314D9
#define __PCNames_x                                                0xF32924
#define __RangeAttackReady_x                                       0xF3264C
#define __RMouseHeldTime_x                                         0xF31578
#define __RunWalkState_x                                           0xF31440
#define __ScreenMode_x                                             0xE6FD80
#define __ScreenX_x                                                0xF313F4
#define __ScreenY_x                                                0xF313F0
#define __ScreenXMax_x                                             0xF313F8
#define __ScreenYMax_x                                             0xF313FC
#define __ServerHost_x                                             0xF219F4
#define __ServerName_x                                             0xF67BE0
#define __ShiftKeyDown_x                                           0xF31AD0
#define __ShowNames_x                                              0xF32804
#define __Socials_x                                                0xF67CE0
#define __SubscriptionType_x                                       0x10F9A14
#define __TargetAggroHolder_x                                      0x10CB3EC
#define __ZoneType_x                                               0xF318D4
#define __GroupAggro_x                                             0x10CB42C
#define __LoginName_x                                              0xFB9B7C
#define __Inviter_x                                                0xFB59D8
#define __AttackOnAssist_x                                         0xF327C0
#define __UseTellWindows_x                                         0xF32ABC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF24050
#define instEQZoneInfo_x                                           0xF316CC
#define instKeypressHandler_x                                      0xFB61D8
#define pinstActiveBanker_x                                        0xF24008
#define pinstActiveCorpse_x                                        0xF2400C
#define pinstActiveGMaster_x                                       0xF24010
#define pinstActiveMerchant_x                                      0xF24004
#define pinstAggroInfo_x                                           0xD2D3EC
#define pinstAltAdvManager_x                                       0xE70EE8
#define pinstAuraMgr_x                                             0xD3DBF0
#define pinstBandageTarget_x                                       0xF23FF0
#define pinstCamActor_x                                            0xE707B8
#define pinstCDBStr_x                                              0xE6FD14
#define pinstCDisplay_x                                            0xF24018
#define pinstCEverQuest_x                                          0x10C3418
#define pinstEverQuestInfo_x                                       0xF313E8
#define pinstCharData_x                                            0xF23FD4
#define pinstCharSpawn_x                                           0xF23FFC
#define pinstControlledMissile_x                                   0xF23FD0
#define pinstControlledPlayer_x                                    0xF23FFC
#define pinstCSidlManager_x                                        0x1731E78
#define pinstCXWndManager_x                                        0x1731E70
#define instDynamicZone_x                                          0xF31288
#define pinstDZMember_x                                            0xF31398
#define pinstDZTimerInfo_x                                         0xF3139C
#define pinstEQItemList_x                                          0xF20478
#define pinstEQObjectList_x                                        0xF214A4
#define instEQMisc_x                                               0xC047A8
#define pinstEQSoundManager_x                                      0xE714B8
#define instExpeditionLeader_x                                     0xF312D2
#define instExpeditionName_x                                       0xF31312
#define pinstGroup_x                                               0xF21AA6
#define pinstImeManager_x                                          0x1731E7C
#define pinstLocalPlayer_x                                         0xF23FE8
#define pinstMercenaryData_x                                       0xFB6840
#define pinstMercenaryStats_x                                      0x10CB538
#define pinstMercAltAbilities_x                                    0xE71270
#define pinstModelPlayer_x                                         0xF24014
#define pinstPCData_x                                              0xF23FD4
#define pinstSkillMgr_x                                            0xFB7838
#define pinstSpawnManager_x                                        0xFB7090
#define pinstSpellManager_x                                        0xFB7980
#define pinstSpellSets_x                                           0xFAE684
#define pinstStringTable_x                                         0xF23F7C
#define pinstSwitchManager_x                                       0xF21638
#define pinstTarget_x                                              0xF24000
#define pinstTargetObject_x                                        0xF23FD8
#define pinstTargetSwitch_x                                        0xF23FDC
#define pinstTaskMember_x                                          0xE6FC60
#define pinstTrackTarget_x                                         0xF23FF4
#define pinstTradeTarget_x                                         0xF23FE4
#define instTributeActive_x                                        0xC047CD
#define pinstViewActor_x                                           0xE707B4
#define pinstWorldData_x                                           0xF23FB8
#define pinstZoneAddr_x                                            0xF3196C
#define pinstPlayerPath_x                                          0xFB70F0
#define pinstTargetIndicator_x                                     0xFB7B18
#define pinstCTargetManager_x                                      0xFB7B78
#define EQObject_Top_x                                             0xF23FC8
#define pinstRealEstateItems_x                                     0xFB76A4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE706D0
#define pinstCAchievementsWnd_x                                    0xE7072C
#define pinstCTextOverlay_x                                        0xD2D980
#define pinstCAudioTriggersWindow_x                                0xD2D768
#define pinstCCharacterSelect_x                                    0xE7063C
#define pinstCFacePick_x                                           0xE703EC
#define pinstCFindItemWnd_x                                        0xE706CC
#define pinstCNoteWnd_x                                            0xE705F4
#define pinstCBookWnd_x                                            0xE705FC
#define pinstCPetInfoWnd_x                                         0xE70600
#define pinstCTrainWnd_x                                           0xE70604
#define pinstCSkillsWnd_x                                          0xE70608
#define pinstCSkillsSelectWnd_x                                    0xE7060C
#define pinstCCombatSkillsSelectWnd_x                              0xE70610
#define pinstCFriendsWnd_x                                         0xE70614
#define pinstCAuraWnd_x                                            0xE70618
#define pinstCRespawnWnd_x                                         0xE7061C
#define pinstCBandolierWnd_x                                       0xE70620
#define pinstCPotionBeltWnd_x                                      0xE70624
#define pinstCAAWnd_x                                              0xE70628
#define pinstCAlarmWnd_x                                           0xE70634
#define pinstCGroupSearchFiltersWnd_x                              0xE7062C
#define pinstCLoadskinWnd_x                                        0xE70630
#define pinstCLargeDialogWnd_x                                     0x10CA498
#define pinstCMusicPlayerWnd_x                                     0xE70638
#define pinstCMailWnd_x                                            0xE70640
#define pinstCMailCompositionWnd_x                                 0xE70644
#define pinstCMailAddressBookWnd_x                                 0xE70648
#define pinstCRaidWnd_x                                            0xE70650
#define pinstCRaidOptionsWnd_x                                     0xE70654
#define pinstCBreathWnd_x                                          0xE70658
#define pinstCMapViewWnd_x                                         0xE7065C
#define pinstCMapToolbarWnd_x                                      0xE70660
#define pinstCEditLabelWnd_x                                       0xE70664
#define pinstCTargetWnd_x                                          0xE70668
#define pinstCColorPickerWnd_x                                     0xE7066C
#define pinstCPlayerWnd_x                                          0xE70670
#define pinstCOptionsWnd_x                                         0xE70674
#define pinstCBuffWindowNORMAL_x                                   0xE70678
#define pinstCBuffWindowSHORT_x                                    0xE7067C
#define pinstCharacterCreation_x                                   0xE70680
#define pinstCCursorAttachment_x                                   0xE70684
#define pinstCCastingWnd_x                                         0xE70688
#define pinstCCastSpellWnd_x                                       0xE7068C
#define pinstCSpellBookWnd_x                                       0xE70690
#define pinstCInventoryWnd_x                                       0xE70694
#define pinstCBankWnd_x                                            0xE7069C
#define pinstCQuantityWnd_x                                        0xE706A0
#define pinstCLootWnd_x                                            0xE706A4
#define pinstCActionsWnd_x                                         0xE706A8
#define pinstCCombatAbilityWnd_x                                   0xE706B0
#define pinstCMerchantWnd_x                                        0xE706B4
#define pinstCTradeWnd_x                                           0xE706BC
#define pinstCSelectorWnd_x                                        0xE706C0
#define pinstCBazaarWnd_x                                          0xE706C4
#define pinstCBazaarSearchWnd_x                                    0xE706C8
#define pinstCGiveWnd_x                                            0xE706E8
#define pinstCTrackingWnd_x                                        0xE706F0
#define pinstCInspectWnd_x                                         0xE706F4
#define pinstCSocialEditWnd_x                                      0xE706F8
#define pinstCFeedbackWnd_x                                        0xE706FC
#define pinstCBugReportWnd_x                                       0xE70700
#define pinstCVideoModesWnd_x                                      0xE70704
#define pinstCTextEntryWnd_x                                       0xE7070C
#define pinstCFileSelectionWnd_x                                   0xE70710
#define pinstCCompassWnd_x                                         0xE70714
#define pinstCPlayerNotesWnd_x                                     0xE70718
#define pinstCGemsGameWnd_x                                        0xE7071C
#define pinstCTimeLeftWnd_x                                        0xE70738
#define pinstCPetitionQWnd_x                                       0xE7073C
#define pinstCStoryWnd_x                                           0xE70740
#define pinstCJournalTextWnd_x                                     0xE70744
#define pinstCJournalCatWnd_x                                      0xE70748
#define pinstCBodyTintWnd_x                                        0xE7074C
#define pinstCServerListWnd_x                                      0xE70750
#define pinstCAvaZoneWnd_x                                         0xE7075C
#define pinstCBlockedBuffWnd_x                                     0xE70760
#define pinstCBlockedPetBuffWnd_x                                  0xE70764
#define pinstCInvSlotMgr_x                                         0xE707AC
#define pinstCContainerMgr_x                                       0xE707B0
#define pinstCAdventureLeaderboardWnd_x                            0x10C3DC8
#define pinstCAdventureRequestWnd_x                                0x10C3E40
#define pinstCAltStorageWnd_x                                      0x10C4120
#define pinstCAdventureStatsWnd_x                                  0x10C3EB8
#define pinstCBarterMerchantWnd_x                                  0x10C4E68
#define pinstCBarterSearchWnd_x                                    0x10C4EE0
#define pinstCBarterWnd_x                                          0x10C4F58
#define pinstCChatWindowManager_x                                  0x10C5768
#define pinstCDynamicZoneWnd_x                                     0x10C5C98
#define pinstCEQMainWnd_x                                          0x10C5E60
#define pinstCFellowshipWnd_x                                      0x10C5C2C
#define pinstCFindLocationWnd_x                                    0x10C6130
#define pinstCGroupSearchWnd_x                                     0x10C6400
#define pinstCGroupWnd_x                                           0x10C6478
#define pinstCGuildBankWnd_x                                       0x10C64F0
#define pinstCGuildMgmtWnd_x                                       0x10C85E0
#define pinstCHotButtonWnd_x                                       0x10C86DC
#define pinstCHotButtonWnd1_x                                      0x10C86DC
#define pinstCHotButtonWnd2_x                                      0x10C86E0
#define pinstCHotButtonWnd3_x                                      0x10C86E4
#define pinstCHotButtonWnd4_x                                      0x10C8708
#define pinstCItemDisplayManager_x                                 0x10C8B60
#define pinstCItemExpTransferWnd_x                                 0x10C8C5C
#define pinstCLFGuildWnd_x                                         0x10C8F38
#define pinstCMIZoneSelectWnd_x                                    0x10C9518
#define pinstCConfirmationDialog_x                                 0x10C9B30
#define pinstCPopupWndManager_x                                    0x10C9B30
#define pinstCProgressionSelectionWnd_x                            0x10C9C20
#define pinstCPvPStatsWnd_x                                        0x10C9D10
#define pinstCTaskWnd_x                                            0x10CB818
#define pinstCTaskSomething_x                                      0xD3E808
#define pinstCTaskTemplateSelectWnd_x                              0x10CB7A0
#define pinstCTipWndOFDAY_x                                        0x10CB980
#define pinstCTipWndCONTEXT_x                                      0x10CB984
#define pinstCTitleWnd_x                                           0x10CBA00
#define pinstCContextMenuManager_x                                 0x1731D00
#define pinstCVoiceMacroWnd_x                                      0xFB7F50
#define pinstCHtmlWnd_x                                            0xFB8040
#define pinstItemIconCache_x                                       0x10C5E08
#define pinstCTradeskillWnd_x                                      0x10CBB00
#define pinstCAdvancedLootWnd_x                                    0xE707A0
#define pinstRewardSelectionWnd_x                                  0x10CA238
#define pinstEQSuiteTextureLoader_x                                0xD1BA68

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54AC00
#define __CastRay2_x                                               0x54A530
#define __HeadingDiff_x                                            0x9341D0
#define __FixHeading_x                                             0x934160
#define __get_bearing_x                                            0x53A3C0
#define __ConvertItemTags_x                                        0x537E90
#define __ExecuteCmd_x                                             0x5227A0
#define __EQGetTime_x                                              0x8A3BD0
#define __get_melee_range_x                                        0x529470
#define __GetGaugeValueFromEQ_x                                    0x7B3700
#define __GetLabelFromEQ_x                                         0x7B4AD0
#define __ToggleKeyRingItem_x                                      0x48FDB0
#define __GetXTargetType_x                                         0x935DD0
#define __LoadFrontEnd_x                                           0x6408F0
#define __NewUIINI_x                                               0x7B30D0
#define __ProcessGameEvents_x                                      0x584670
#define __ProcessMouseEvent_x                                      0x583E10
#define CrashDetected_x                                            0x6422B0
#define wwsCrashReportCheckForUploader_x                           0x801800
#define __AppCrashWrapper_x                                        0xC68AC4
#define __pCrashHandler_x                                          0x10D89E0
#define __CrashHandler_x                                           0x801290
#define wwsCrashReportPlatformLaunchUploader_x                     0x803A40
#define DrawNetStatus_x                                            0x5BAD40
#define Util__FastTime_x                                           0x8A3870
#define Expansion_HoT_x                                            0xF327B0
#define __HelpPath_x                                               0xFB5F60
#define __STMLToText_x                                             0x8EA020
#define __GetAnimationCache_x                                      0x6B00B0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423400
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E070
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DE40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8210
#define AltAdvManager__IsAbilityReady_x                            0x4D8280
#define AltAdvManager__GetAAById_x                                 0x4D8770
#define AltAdvManager__CanTrainAbility_x                           0x4D93A0
#define AltAdvManager__CanSeeAbility_x                             0x4D8F60

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AE10
#define CharacterZoneClient__HasSkill_x                            0x466CF0
#define CharacterZoneClient__MakeMeVisible_x                       0x46C980
#define CharacterZoneClient__IsStackBlocked_x                      0x44BE20
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B340
#define CharacterZoneClient__GetItemCountWorn_x                    0x465250
#define CharacterZoneClient__GetItemCountInInventory_x             0x465330
#define CharacterZoneClient__GetCursorItemCount_x                  0x465410
#define CharacterZoneClient__FindAffectSlot_x                      0x4514D0
#define CharacterZoneClient__BardCastBard_x                        0x44AAB0
#define CharacterZoneClient__GetMaxEffects_x                       0x449640
#define CharacterZoneClient__GetEffect_x                           0x44B570
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451330
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449990
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FE80

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x670200

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67E170

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x599890
#define CButtonWnd__CButtonWnd_x                                   0x8DE200

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x699220
#define CChatManager__InitContextMenu_x                            0x69A370
#define CChatManager__FreeChatWindow_x                             0x698CD0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A2520
#define CChatManager__SetLockedActiveChatWindow_x                  0x6991F0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E8370
#define CContextMenu__dCContextMenu_x                              0x8E8580
#define CContextMenu__AddMenuItem_x                                0x8E8AA0
#define CContextMenu__RemoveMenuItem_x                             0x8E8700
#define CContextMenu__RemoveAllMenuItems_x                         0x8E8720
#define CContextMenu__CheckMenuItem_x                              0x8E87A0
#define CContextMenu__SetMenuItem_x                                0x8E8620

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D47D0
#define CContextMenuManager__RemoveMenu_x                          0x8D4B60
#define CContextMenuManager__PopupMenu_x                           0x8D4FB0
#define CContextMenuManager__Flush_x                               0x8D4840
#define CContextMenuManager__GetMenu_x                             0x419590

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x887CC0
#define CChatService__GetFriendName_x                              0x887CD0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69FFF0
#define CChatWindow__Clear_x                                       0x69F8D0
#define CChatWindow__WndNotification_x                             0x6A0900

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D8630
#define CComboWnd__Draw_x                                          0x8D8840
#define CComboWnd__GetCurChoice_x                                  0x8D83E0
#define CComboWnd__GetListRect_x                                   0x8D8AE0
#define CComboWnd__GetTextRect_x                                   0x8D86A0
#define CComboWnd__InsertChoice_x                                  0x8D8C40
#define CComboWnd__SetColors_x                                     0x8D8370
#define CComboWnd__SetChoice_x                                     0x8D83A0
#define CComboWnd__GetItemCount_x                                  0x8D83D0
#define CComboWnd__GetCurChoiceText_x                              0x8D8420


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AA230
#define CContainerWnd__vftable_x                                   0xAEE9A8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C60A0
#define CDisplay__GetClickedActor_x                                0x4BE960
#define CDisplay__GetUserDefinedColor_x                            0x4BD540
#define CDisplay__GetWorldFilePath_x                               0x4BC990
#define CDisplay__is3dON_x                                         0x4BBE20
#define CDisplay__ReloadUI_x                                       0x4CFE60
#define CDisplay__WriteTextHD2_x                                   0x4C2430
#define CDisplay__TrueDistance_x                                   0x4BF590

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FF480

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EC8D0
#define CEditWnd__GetCharIndexPt_x                                 0x8EDA30
#define CEditWnd__GetDisplayString_x                               0x8ECA80
#define CEditWnd__GetHorzOffset_x                                  0x8ECDC0
#define CEditWnd__GetLineForPrintableChar_x                        0x8ED4F0
#define CEditWnd__GetSelStartPt_x                                  0x8EDCF0
#define CEditWnd__GetSTMLSafeText_x                                0x8ECF60
#define CEditWnd__PointFromPrintableChar_x                         0x8ED5E0
#define CEditWnd__SelectableCharFromPoint_x                        0x8ED760
#define CEditWnd__SetEditable_x                                    0x8ECF30

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56ADB0
#define CEverQuest__ClickedPlayer_x                                0x564990
#define CEverQuest__CreateTargetIndicator_x                        0x565890
#define CEverQuest__DeleteTargetIndicator_x                        0x565910
#define CEverQuest__DoTellWindow_x                                 0x476110
#define CEverQuest__OutputTextToLog_x                              0x475D70
#define CEverQuest__DropHeldItemOnGround_x                         0x57B320
#define CEverQuest__dsp_chat_x                                     0x476450
#define CEverQuest__trimName_x                                     0x5612A0
#define CEverQuest__Emote_x                                        0x579630
#define CEverQuest__EnterZone_x                                    0x574710
#define CEverQuest__GetBodyTypeDesc_x                              0x55ECE0
#define CEverQuest__GetClassDesc_x                                 0x5681D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5687D0
#define CEverQuest__GetDeityDesc_x                                 0x55F5C0
#define CEverQuest__GetLangDesc_x                                  0x55F070
#define CEverQuest__GetRaceDesc_x                                  0x568990
#define CEverQuest__InterpretCmd_x                                 0x56C530
#define CEverQuest__LeftClickedOnPlayer_x                          0x580E80
#define CEverQuest__LMouseUp_x                                     0x582E30
#define CEverQuest__RightClickedOnPlayer_x                         0x581990
#define CEverQuest__RMouseUp_x                                     0x582890
#define CEverQuest__SetGameState_x                                 0x565260
#define CEverQuest__UPCNotificationFlush_x                         0x55D670
#define CEverQuest__IssuePetCommand_x                              0x56CF10

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BAF90
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BAFF0
#define CGaugeWnd__Draw_x                                          0x6BB420

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B090
#define CGuild__GetGuildName_x                                     0x43B560
#define CGuild__GetGuildIndex_x                                    0x43C770

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D7440

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E4800
#define CInvSlotMgr__MoveItem_x                                    0x6E4FC0
#define CInvSlotMgr__SelectSlot_x                                  0x6E40F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E3550
#define CInvSlot__SliderComplete_x                                 0x6E0D70
#define CInvSlot__GetItemBase_x                                    0x6E01F0
#define CInvSlot__UpdateItem_x                                     0x6E0770

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E6420
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E7560

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AF550
#define CItemDisplayWnd__UpdateStrings_x                           0x6E86A0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F4F50
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F5460
#define CItemDisplayWnd__SetItem_x                                 0x6FAD50

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E6900

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EEC50

// CLabel 
#define CLabel__Draw_x                                             0x701B80

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C4150
#define CListWnd__dCListWnd_x                                      0x8C53F0
#define CListWnd__AddColumn_x                                      0x8C5390
#define CListWnd__AddColumn1_x                                     0x8C4A30
#define CListWnd__AddLine_x                                        0x8C4410
#define CListWnd__AddString_x                                      0x8C4630
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C1250
#define CListWnd__CalculateVSBRange_x                              0x8C3610
#define CListWnd__ClearSel_x                                       0x8C0560
#define CListWnd__ClearAllSel_x                                    0x8C0510
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C3FE0
#define CListWnd__Compare_x                                        0x8C1F40
#define CListWnd__Draw_x                                           0x8C3210
#define CListWnd__DrawColumnSeparators_x                           0x8C30A0
#define CListWnd__DrawHeader_x                                     0x8C0820
#define CListWnd__DrawItem_x                                       0x8C25D0
#define CListWnd__DrawLine_x                                       0x8C2D40
#define CListWnd__DrawSeparator_x                                  0x8C3140
#define CListWnd__EnableLine_x                                     0x8C0740
#define CListWnd__EnsureVisible_x                                  0x8C13B0
#define CListWnd__ExtendSel_x                                      0x8C24E0
#define CListWnd__GetColumnMinWidth_x                              0x8BFE50
#define CListWnd__GetColumnWidth_x                                 0x8BFD80
#define CListWnd__GetCurSel_x                                      0x8BF540
#define CListWnd__GetItemAtPoint_x                                 0x8C1650
#define CListWnd__GetItemAtPoint1_x                                0x8C16C0
#define CListWnd__GetItemData_x                                    0x8BF890
#define CListWnd__GetItemHeight_x                                  0x8C0EA0
#define CListWnd__GetItemIcon_x                                    0x8BFA80
#define CListWnd__GetItemRect_x                                    0x8C1490
#define CListWnd__GetItemText_x                                    0x8BF930
#define CListWnd__GetSelList_x                                     0x8C4920
#define CListWnd__GetSeparatorRect_x                               0x8C1E60
#define CListWnd__InsertLine_x                                     0x8C4810
#define CListWnd__RemoveLine_x                                     0x8C4820
#define CListWnd__SetColors_x                                      0x8BF690
#define CListWnd__SetColumnJustification_x                         0x8C00E0
#define CListWnd__SetColumnWidth_x                                 0x8BFE00
#define CListWnd__SetCurSel_x                                      0x8BF580
#define CListWnd__SetItemColor_x                                   0x8C3CD0
#define CListWnd__SetItemData_x                                    0x8C05C0
#define CListWnd__SetItemText_x                                    0x8C3B10
#define CListWnd__ShiftColumnSeparator_x                           0x8C39A0
#define CListWnd__Sort_x                                           0x8C54F0
#define CListWnd__ToggleSel_x                                      0x8C0490

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71ACF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x740110
#define CMerchantWnd__RequestBuyItem_x                             0x747F50
#define CMerchantWnd__RequestSellItem_x                            0x74A640
#define CMerchantWnd__SelectRecoverySlot_x                         0x73D430
#define CMerchantWnd__SelectBuySellSlot_x                          0x73B390
#define CMerchantWnd__ActualSelect_x                               0x741E90

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x855F40
#define CPacketScrambler__hton_x                                   0x855F50

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E31D0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E32B0
#define CSidlManager__CreateLabel_x                                0x7A4520
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E1760
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E3590

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8DA680
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8DA570
#define CSidlScreenWnd__ConvertToRes_x                             0x8FF360
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DAFA0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DC160
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DC210
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DB6F0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8DA950
#define CSidlScreenWnd__EnableIniStorage_x                         0x8DA0A0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8DAB40
#define CSidlScreenWnd__Init1_x                                    0x8DBE50
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DB060
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8DA260
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DB930
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D9D00
#define CSidlScreenWnd__StoreIniVis_x                              0x8DA050
#define CSidlScreenWnd__WndNotification_x                          0x8DBBD0
#define CSidlScreenWnd__GetChildItem_x                             0x8DA170
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CDA40
#define CSidlScreenWnd__m_layoutCopy_x                             0x1731E20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x605F80
#define CSkillMgr__GetSkillCap_x                                   0x606160
#define CSkillMgr__GetNameToken_x                                  0x605B30

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FE630
#define CSliderWnd__SetValue_x                                     0x8FE800
#define CSliderWnd__SetNumTicks_x                                  0x8FEF80

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7AA830

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F8370
#define CStmlWnd__CalculateHSBRange_x                              0x8F08C0
#define CStmlWnd__CalculateVSBRange_x                              0x8F0830
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F0A40
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F1240
#define CStmlWnd__ForceParseNow_x                                  0x8F8CF0
#define CStmlWnd__GetNextTagPiece_x                                0x8F1140
#define CStmlWnd__GetSTMLText_x                                    0x484440
#define CStmlWnd__GetVisibleText_x                                 0x8F1C90
#define CStmlWnd__InitializeWindowVariables_x                      0x8F4260
#define CStmlWnd__MakeStmlColorTag_x                               0x8EFB10
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EFB70
#define CStmlWnd__SetSTMLText_x                                    0x8F5AC0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F8010
#define CStmlWnd__UpdateHistoryString_x                            0x8F2BD0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FC210
#define CTabWnd__DrawCurrentPage_x                                 0x8FBAA0
#define CTabWnd__DrawTab_x                                         0x8FB860
#define CTabWnd__GetCurrentPage_x                                  0x8FBE50
#define CTabWnd__GetPageInnerRect_x                                0x8FB550
#define CTabWnd__GetTabInnerRect_x                                 0x8FB750
#define CTabWnd__GetTabRect_x                                      0x8FB620
#define CTabWnd__InsertPage_x                                      0x8FC500
#define CTabWnd__SetPage_x                                         0x8FBE80
#define CTabWnd__SetPageRect_x                                     0x8FC150
#define CTabWnd__UpdatePage_x                                      0x8FC4A0
#define CTabWnd__GetPageFromTabIndex_x                             0x8FB7B0
#define CTabWnd__GetCurrentTabIndex_x                              0x8FB4E0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E7710
#define CPageWnd__SetTabText_x                                     0x9086C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436C20

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D7FE0
#define CTextureFont__GetTextExtent_x                              0x8D7D40

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63EB80

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x904B00

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BD7F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A7480
#define CXStr__CXStr1_x                                            0x8B2ED0
#define CXStr__CXStr3_x                                            0x8A0B00
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x8A0C70
#define CXStr__operator_equal1_x                                   0x8A0CC0
#define CXStr__operator_plus_equal1_x                              0x8A1DC0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D5AD0
#define CXWnd__BringToTop_x                                        0x8CCC10
#define CXWnd__Center_x                                            0x8D2DD0
#define CXWnd__ClrFocus_x                                          0x8CC7E0
#define CXWnd__Destroy_x                                           0x8D38B0
#define CXWnd__DoAllDrawing_x                                      0x8D2A00
#define CXWnd__DrawChildren_x                                      0x8D2BB0
#define CXWnd__DrawColoredRect_x                                   0x8CD000
#define CXWnd__DrawTooltip_x                                       0x8CD2B0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D1970
#define CXWnd__GetBorderFrame_x                                    0x8CD720
#define CXWnd__GetChildWndAt_x                                     0x8D3790
#define CXWnd__GetClientClipRect_x                                 0x8CD4D0
#define CXWnd__GetScreenClipRect_x                                 0x8D2070
#define CXWnd__GetScreenRect_x                                     0x8CD8F0
#define CXWnd__GetTooltipRect_x                                    0x8CD140
#define CXWnd__GetWindowTextA_x                                    0x426F50
#define CXWnd__IsActive_x                                          0x8C8200
#define CXWnd__IsDescendantOf_x                                    0x8CD660
#define CXWnd__IsReallyVisible_x                                   0x8D09B0
#define CXWnd__IsType_x                                            0x8D2E40
#define CScreenPieceTemplate__IsType_x                             0x901210
#define CXWnd__Move_x                                              0x8D0140
#define CXWnd__Move1_x                                             0x8D26C0
#define CXWnd__ProcessTransition_x                                 0x8CCBB0
#define CXWnd__Refade_x                                            0x8CC990
#define CXWnd__Resize_x                                            0x8CD9B0
#define CXWnd__Right_x                                             0x8D1E70
#define CXWnd__SetFocus_x                                          0x8CF2B0
#define CXWnd__SetFont_x                                           0x8CC830
#define CXWnd__SetKeyTooltip_x                                     0x8CDC10
#define CXWnd__SetMouseOver_x                                      0x8D23B0
#define CXWnd__StartFade_x                                         0x8CCC60
#define CXWnd__GetChildItem_x                                      0x8D2300
#define CXWnd__SetParent_x                                         0x8D3740

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C9AC0
#define CXWndManager__DrawWindows_x                                0x8C9700
#define CXWndManager__GetKeyboardFlags_x                           0x8C7D30
#define CXWndManager__HandleKeyboardMsg_x                          0x8C86A0
#define CXWndManager__RemoveWnd_x                                  0x8C8390

// CDBStr
#define CDBStr__GetString_x                                        0x4BA680

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452590
#define EQ_Character__Cur_HP_x                                     0x4668D0
#define EQ_Character__Cur_Mana_x                                   0x45B8E0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B650
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443650
#define EQ_Character__GetFocusRangeModifier_x                      0x4437A0
#define EQ_Character__GetHPRegen_x                                 0x46A4A0
#define EQ_Character__GetEnduranceRegen_x                          0x465EE0
#define EQ_Character__GetManaRegen_x                               0x46AA40
#define EQ_Character__Max_Endurance_x                              0x5CCA40
#define EQ_Character__Max_HP_x                                     0x45E460
#define EQ_Character__Max_Mana_x                                   0x5CC870
#define EQ_Character__doCombatAbility_x                            0x5C9F40
#define EQ_Character__UseSkill_x                                   0x472830
#define EQ_Character__GetConLevel_x                                0x5BF3C0
#define EQ_Character__IsExpansionFlag_x                            0x4B69D0
#define EQ_Character__TotalEffect_x                                0x44F7C0
#define EQ_Character__GetPCSpellAffect_x                           0x44B9E0
#define EQ_Character__SpellDuration_x                              0x4499E0
#define EQ_Character__FindItemByRecord_x                           0x463F40
#define EQ_Character__GetAdjustedSkill_x                           0x466AA0
#define EQ_Character__GetBaseSkill_x                               0x45E340

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x873E80

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D5080

//PcClient
#define PcClient__PcClient_x                                       0x5C11F0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446AE0
#define CCharacterSelect__EnterWorld_x                             0x4462B0
#define CCharacterSelect__Quit_x                                   0x444E70

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59F1D0
#define EQ_Item__CreateItemTagString_x                             0x8540D0
#define EQ_Item__IsStackable_x                                     0x849410
#define EQ_Item__GetImageNum_x                                     0x84BEB0
#define EQ_Item__CreateItemClient_x                                0x5A0300
#define EQ_Item__GetItemValue_x                                    0x852B20
#define EQ_Item__ValueSellMerchant_x                               0x855B90
#define EQ_Item__IsKeyRingItem_x                                   0x849EF0
#define EQ_Item__CanGoInBag_x                                      0x59F360
#define EQ_Item__GetMaxItemCount_x                                 0x849300
#define EQ_Item__GetHeldItem_x                                     0x84ACD0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8559B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA7B0
#define EQ_LoadingS__Array_x                                       0xC0CC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CEF70
#define EQ_PC__GetAlternateAbilityId_x                             0x85E010
#define EQ_PC__GetCombatAbility_x                                  0x85E0A0
#define EQ_PC__GetCombatAbilityTimer_x                             0x858BF0
#define EQ_PC__GetItemRecastTimer_x                                0x5C8730
#define EQ_PC__HasLoreItem_x                                       0x5C29B0
#define EQ_PC__AlertInventoryChanged_x                             0x5BF370
#define EQ_PC__GetPcZoneClient_x                                   0x5E9710
#define EQ_PC__RemoveMyAffect_x                                    0x5C7B90
#define EQ_PC__GetKeyRingItems_x                                   0x859010
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86BCF0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85FF80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5274F0
#define EQItemList__add_object_x                                   0x554660
#define EQItemList__add_item_x                                     0x527430
#define EQItemList__delete_item_x                                  0x5278E0
#define EQItemList__FreeItemList_x                                 0x5277E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9910

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D4D40
#define EQPlayer__dEQPlayer_x                                      0x5DD500
#define EQPlayer__DoAttack_x                                       0x5EEEC0
#define EQPlayer__EQPlayer_x                                       0x5DFC20
#define EQPlayer__SetNameSpriteState_x                             0x5DA330
#define EQPlayer__SetNameSpriteTint_x                              0x5D6240
#define PlayerBase__HasProperty_j_x                                0x9325E0
#define EQPlayer__IsTargetable_x                                   0x932880
#define EQPlayer__CanSee_x                                         0x932DE0
#define PlayerZoneClient__ChangeHeight_x                           0x5EED80
#define EQPlayer__CanSee1_x                                        0x932ED0
#define PlayerBase__GetVisibilityLineSegment_x                     0x932B70

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E98C0
#define PlayerZoneClient__IsValidTeleport_x                        0x554F00
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2A50


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E3CF0
#define EQPlayerManager__GetSpawnByName_x                          0x5E4150
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E3D20

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A5810
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A5850
#define KeypressHandler__ClearCommandStateArray_x                  0x5A5400
#define KeypressHandler__HandleKeyDown_x                           0x5A3D20
#define KeypressHandler__HandleKeyUp_x                             0x5A4040
#define KeypressHandler__SaveKeymapping_x                          0x5A54D0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x713680
#define MapViewMap__SaveEx_x                                       0x7169B0
#define MapViewMap__SetZoom_x                                      0x7132F0

#define PlayerPointManager__GetAltCurrency_x                       0x871F00

// StringTable 
#define StringTable__getString_x                                   0x86C020

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CC4D0
#define PcZoneClient__RemovePetEffect_x                            0x5C8C00
#define PcZoneClient__HasAlternateAbility_x                        0x5C95A0
#define PcZoneClient__GetCurrentMod_x                              0x45D910
#define PcZoneClient__GetModCap_x                                  0x45B040
#define PcZoneClient__CanEquipItem_x                               0x5C9A80
#define PcZoneClient__GetItemByID_x                                0x5CE2E0
#define PcZoneClient__GetItemByItemClass_x                         0x5CEE90
#define PcZoneClient__RemoveBuffEffect_x                           0x5C7E40

//Doors
#define EQSwitch__UseSwitch_x                                      0x55BFA0

//IconCache
#define IconCache__GetIcon_x                                       0x6B06E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A75B0
#define CContainerMgr__CloseContainer_x                            0x6A7DD0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x774470

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5982A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4B60
#define EQ_Spell__SpellAffects_x                                   0x4F1D40
#define EQ_Spell__SpellAffectBase_x                                0x4F1DB0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B870
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AB10
#define CLootWnd__LootAll_x                                        0x708F70
#define CLootWnd__RequestLootSlot_x                                0x709780
#define EQ_Spell__IsStackable_x                                    0x459060
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4494A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EBA0
#define EQ_Spell__IsSPAStacking_x                                  0x4F18B0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2950
#define EQ_Spell__IsNoRemove_x                                     0x434C30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F18D0

#define __IsResEffectSpell_x                                       0x449530

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87DB00

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BC1D0
#define CTargetWnd__WndNotification_x                              0x7BBCC0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BC3B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C1300

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED410
#define EqSoundManager__PlayScriptMp3_x                            0x4EEEB0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8AC0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EBF00
#define CSidlManager__FindAnimation1_x                             0x8E1190

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1FB0
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1F60
#define CAltAbilityData__GetMaxRank_x                              0x4D68C0

//CTargetRing
#define CTargetRing__Cast_x                                        0x595EE0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459350
#define CharacterBase__CreateItemGlobalIndex_x                     0x475260
#define CharacterBase__CreateItemIndex_x                           0x520B20
#define CharacterBase__GetItemPossession_x                         0x444340
#define CharacterBase__GetItemByGlobalIndex_x                      0x881990
#define CharacterBase__GetEffectId_x                               0x459310

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6903B0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68FB10

//messages
#define msg_spell_worn_off_x                                       0x4FC630
#define msg_new_text_x                                             0x505DB0
#define msgTokenTextParam_x                                        0x5025B0

//SpellManager
#define SpellManager__vftable_x                                    0xACA268
#define SpellManager__SpellManager_x                               0x47E000
#define Spellmanager__LoadTextSpells_x                             0x60CEF0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9368F0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487E00
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EAB0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4491D0
#define ItemGlobalIndex__IsValidIndex_x                            0x458BA0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87F800
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87E740

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x701DD0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AC300
#define CCursorAttachment__Deactivate_x                            0x6AB840

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FDB30
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FDCB0

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x604A50

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C670

//IString
#define IString__Append_x                                          0x47EC30

//Camera
#define CDisplay__cameraType_x                                     0xE707C8
#define EverQuest__Cameras_x                                       0xF32AC8
