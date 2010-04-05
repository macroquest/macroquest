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
#include "eqgame-private.h" 
#endif

#define __ClientName                                              "eqgame" 
#define __ExpectedVersionDate                                     "Oct 28 2008"
#define __ExpectedVersionTime                                     "16:02:47"
#define __ActualVersionDate                                        0x75FA94
#define __ActualVersionTime                                        0x75FAA0

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FFA80
#define __MemChecker1                                              0x69FB60
#define __MemChecker2                                              0x554B20
#define __MemChecker3                                              0x554BD0
#define __MemChecker4                                              0x662B50
#define __EncryptPad0                                              0x7C1360
#define __EncryptPad1                                              0x7CB848
#define __EncryptPad2                                              0x7C3D88
#define __EncryptPad3                                              0x7C3988
#define __EncryptPad4                                              0x7CAF28

// Direct Input
#define DI8__Main                                                  0xA2E56C
#define DI8__Keyboard                                              0xA2E570
#define DI8__Mouse                                                 0xA2E574
#define __AltTimerReady                                            0x9B9052
#define __Attack                                                   0xA18AEE
#define __Autofire                                                 0xA18AEF
#define __BindList                                                 0x7BC3C0
#define __Clicks                                                   0x9B7D68
#define __CommandList                                              0x7BCC20
#define __CurrentMapLabel                                          0xA59790
#define __CurrentSocial                                            0x7B85EC
#define __DoAbilityAvailable                                       0x9B8FEC
#define __DoAbilityList                                            0x9EE604
#define __do_loot                                                  0x4A75A0
#define __DrawHandler                                              0xA68B94
#define __GroupCount                                               0x99841A
#define __Guilds                                                   0x999F98
#define __gWorld                                                   0x999ED4
#define __HotkeyPage                                               0xA159F0
#define __HWnd                                                     0xA2E2AC
#define __InChatMode                                               0x9B7CA0
#define __LastTell                                                 0x9B995C
#define __LMouseHeldTime                                           0x9B7D88
#define __Mouse                                                    0xA2E578
#define __MouseLook                                                0x9B7D36
#define __NetStatusToggle                                          0x9B7D38
#define __PCNames                                                  0x9B93A8
#define __RangeAttackReady                                         0x9B9050
#define __RMouseHeldTime                                           0x9B7D84
#define __RunWalkState                                             0x9B7CA4
#define __ScreenMode                                               0x8E7CF0
#define __ScreenX                                                  0x9B7C58
#define __ScreenY                                                  0x9B7C5C
#define __ScreenXMax                                               0x9B7C60
#define __ScreenYMax                                               0x9B7C64
#define __ServerHost                                               0x99835C
#define __ServerName                                               0x9EE5C4
#define __ShiftKeyDown                                             0x9B8308
#define __ShowNames                                                0x9B927C
#define __Socials                                                  0x9EE6C4


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x9B1BE8
#define instEQZoneInfo                                             0x9B7ED4
#define instKeypressHandler                                        0xA18BDC
#define pinstActiveBanker                                          0x999F6C
#define pinstActiveCorpse                                          0x999F70
#define pinstActiveGMaster                                         0x999F74
#define pinstActiveMerchant                                        0x999F68
#define pinstAltAdvManager                                         0x8E8B50
#define pinstAuraMgr                                               0x7D15B4
#define pinstBandageTarget                                         0x999F54
#define pinstCamActor                                              0x8E863C
#define pinstCDBStr                                                0x8E7CE0
#define pinstCDisplay                                              0x999F7C
#define pinstCEverQuest                                            0xA2E6F0
#define pinstCharData                                              0x999F38
#define pinstCharSpawn                                             0x999F60
#define pinstControlledMissile                                     0x999F34
#define pinstControlledPlayer                                      0x999F60
#define pinstCSidlManager                                          0xA68318
#define pinstCXWndManager                                          0xA68310
#define instDynamicZone                                            0x9B76A8
#define pinstDZMember                                              0x9B77B8
#define pinstDZTimerInfo                                           0x9B77BC
#define pinstEQItemList                                            0x999F1C
#define instEQMisc                                                 0x8E7C98
#define pinstEQSoundManager                                        0x8E8B74
#define instExpeditionLeader                                       0x9B76F2
#define instExpeditionName                                         0x9B7732
#define pinstGroup                                                 0x998416
#define pinstImeManager                                            0xA6831C
#define pinstLocalPlayer                                           0x999F4C
#define pinstModelPlayer                                           0x999F78
#define pinstPCData                                                0x999F38
#define pinstSkillMgr                                              0xA2B3E4
#define pinstSpawnManager                                          0xA2B364
#define pinstSpellManager                                          0xA2B3E8
#define pinstSpellSets                                             0xA159F4
#define pinstStringTable                                           0x999EF0
#define pinstSwitchManager                                         0x99805C
#define pinstTarget                                                0x999F64
#define pinstTargetObject                                          0x999F3C
#define pinstTargetSwitch                                          0x999F40
#define pinstTaskMember                                            0x8E7C78
#define pinstTrackTarget                                           0x999F58
#define pinstTradeTarget                                           0x999F48
#define instTributeActive                                          0x8E7CBD
#define pinstViewActor                                             0x8E8638
#define pinstWorldData                                             0x999F18


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x7CEE60
#define pinstCAudioTriggersWindow                                  0x7CEE2C
#define pinstCCharacterSelect                                      0x8E854C
#define pinstCFacePick                                             0x8E8500
#define pinstCNoteWnd                                              0x8E8504
#define pinstCBookWnd                                              0x8E8508
#define pinstCPetInfoWnd                                           0x8E850C
#define pinstCTrainWnd                                             0x8E8510
#define pinstCSkillsWnd                                            0x8E8514
#define pinstCSkillsSelectWnd                                      0x8E8518
#define pinstCCombatSkillSelectWnd                                 0x8E851C
#define pinstCFriendsWnd                                           0x8E8520
#define pinstCAuraWnd                                              0x8E8524
#define pinstCRespawnWnd                                           0x8E8528
#define pinstCBandolierWnd                                         0x8E852C
#define pinstCPotionBeltWnd                                        0x8E8530
#define pinstCAAWnd                                                0x8E8534
#define pinstCGroupSearchFiltersWnd                                0x8E8538
#define pinstCLoadskinWnd                                          0x8E853C
#define pinstCAlarmWnd                                             0x8E8540
#define pinstCMusicPlayerWnd                                       0x8E8544
#define pinstCMailWnd                                              0x8E8550
#define pinstCMailCompositionWnd                                   0x8E8554
#define pinstCMailAddressBookWnd                                   0x8E8558
#define pinstCRaidWnd                                              0x8E8560
#define pinstCRaidOptionsWnd                                       0x8E8564
#define pinstCBreathWnd                                            0x8E8568
#define pinstCMapViewWnd                                           0x8E856C
#define pinstCMapToolbarWnd                                        0x8E8570
#define pinstCEditLabelWnd                                         0x8E8574
#define pinstCTargetWnd                                            0x8E8578
#define pinstCColorPickerWnd                                       0x8E857C
#define pinstCPlayerWnd                                            0x8E8580
#define pinstCOptionsWnd                                           0x8E8584
#define pinstCBuffWindowNORMAL                                     0x8E8588
#define pinstCBuffWindowSHORT                                      0x8E858C
#define pinstCharacterCreation                                     0x8E8590
#define pinstCCursorAttachment                                     0x8E8594
#define pinstCCastingWnd                                           0x8E8598
#define pinstCCastSpellWnd                                         0x8E859C
#define pinstCSpellBookWnd                                         0x8E85A0
#define pinstCInventoryWnd                                         0x8E85A4
#define pinstCBankWnd                                              0x8E85A8
#define pinstCQuantityWnd                                          0x8E85AC
#define pinstCLootWnd                                              0x8E85B0
#define pinstCActionsWnd                                           0x8E85B4
#define pinstCCombatAbilityWnd                                     0x8E85B8
#define pinstCMerchantWnd                                          0x8E85BC
#define pinstCTradeWnd                                             0x8E85C0
#define pinstCSelectorWnd                                          0x8E85C4
#define pinstCBazaarWnd                                            0x8E85C8
#define pinstCBazaarSearchWnd                                      0x8E85CC
#define pinstCGiveWnd                                              0x8E85D0
#define pinstCTrackingWnd                                          0x8E85D4
#define pinstCInspectWnd                                           0x8E85D8
#define pinstCSocialEditWnd                                        0x8E85DC
#define pinstCFeedbackWnd                                          0x8E85E0
#define pinstCBugReportWnd                                         0x8E85E4
#define pinstCVideoModesWnd                                        0x8E85E8
#define pinstCTextEntryWnd                                         0x8E85F0
#define pinstCFileSelectionWnd                                     0x8E85F4
#define pinstCCompassWnd                                           0x8E85F8
#define pinstCPlayerNotesWnd                                       0x8E85FC
#define pinstCGemsGameWnd                                          0x8E8600
#define pinstCTimeLeftWnd                                          0x8E8604
#define pinstCPetitionQWnd                                         0x8E8608
#define pinstCSoulmarkWnd                                          0x8E860C
#define pinstCStoryWnd                                             0x8E8610
#define pinstCJournalTextWnd                                       0x8E8614
#define pinstCJournalCatWnd                                        0x8E8618
#define pinstCBodyTintWnd                                          0x8E861C
#define pinstCServerListWnd                                        0x8E8620
#define pinstCAvaZoneWnd                                           0x8E8624
#define pinstCBlockedBuffWnd                                       0x8E8628
#define pinstCBlockedPetBuffWnd                                    0x8E862C
#define pinstCInvSlotMgr                                           0x8E8630
#define pinstCContainerMgr                                         0x8E8634
#define pinstCAdventureLeaderboardWnd                              0xA56CD8
#define pinstCAdventureRequestWnd                                  0xA56CF4
#define pinstCAltStorageWnd                                        0xA56D54
#define pinstCAdventureStatsWnd                                    0xA56D10
#define pinstCBarterMerchantWnd                                    0xA56F20
#define pinstCBarterSearchWnd                                      0xA56F3C
#define pinstCBarterWnd                                            0xA56F58
#define pinstCChatManager                                          0xA571FC
#define pinstCDynamicZoneWnd                                       0xA572F4
#define pinstCEQMainWnd                                            0xA57368
#define pinstCFellowshipWnd                                        0xA573CC
#define pinstCFindLocationWnd                                      0xA57400
#define pinstCGroupSearchWnd                                       0xA574B0
#define pinstCGroupWnd                                             0xA574CC
#define pinstCGuildBankWnd                                         0xA574E8
#define pinstCGuildMgmtWnd                                         0xA59508
#define pinstCGuildTributeMasterWnd                                0xA59528
#define pinstCHotButtonWnd                                         0xA59544
#define pinstCHotButtonWnd1                                        0xA59544
#define pinstCHotButtonWnd2                                        0xA59548
#define pinstCHotButtonWnd3                                        0xA5954C
#define pinstCHotButtonWnd4                                        0xA59550
#define pinstCItemDisplayManager                                   0xA595FC
#define pinstCItemExpTransferWnd                                   0xA5961C
#define pinstCLeadershipWnd                                        0xA596B8
#define pinstCLFGuildWnd                                           0xA596D4
#define pinstCMIZoneSelectWnd                                      0xA59828
#define pinstCAdventureMerchantWnd                                 0xA59920
#define pinstCConfirmationDialog                                   0xA5993C
#define pinstCPopupWndManager                                      0xA5993C
#define pinstCProgressionSelectionWnd                              0xA59970
#define pinstCPvPLeaderboardWnd                                    0xA5998C
#define pinstCPvPStatsWnd                                          0xA599A8
#define pinstCSystemInfoDialogBox                                  0xA59A58
#define pinstCTargetOfTargetWnd                                    0xA5A364
#define pinstCTaskSelectWnd                                        0xA5A398
#define pinstCTaskTemplateSelectWnd                                0xA5A3B4
#define pinstCTaskWnd                                              0xA5A3D0
#define pinstCTipWndOFDAY                                          0xA5A44C
#define pinstCTipWndCONTEXT                                        0xA5A450
#define pinstCTitleWnd                                             0xA5A46C
#define pinstCTradeskillWnd                                        0xA5A4B0
#define pinstCTributeBenefitWnd                                    0xA5A4FC
#define pinstCTributeMasterWnd                                     0xA5A518
#define pinstCContextMenuManager                                   0xA68374
#define pinstCVoiceMacroWnd                                        0xA2B5CC
#define pinstCHtmlWnd                                              0xA2B5E8


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4BA150
#define __ConvertItemTags                                          0x4AC9C0
#define __ExecuteCmd                                               0x49B970
#define __get_melee_range                                          0x4A0D50
#define __GetGaugeValueFromEQ                                      0x62B120
#define __GetLabelFromEQ                                           0x62BDA0
#define __NewUIINI                                                 0x62AD00
#define __ProcessGameEvents                                        0x4E9B60
#define CrashDetected                                              0x5538A0
#define DrawNetStatus                                              0x508070
#define Util__FastTime                                             0x6A0270


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x474BB0
#define AltAdvManager__IsAbilityReady                              0x474BF0
#define AltAdvManager__GetAltAbility                               0x474E40

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x56B850

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x574C20

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6CC5C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x58AD40
#define CChatManager__InitContextMenu                              0x58B4E0

// CChatService
#define CChatService__GetNumberOfFriends                           0x6902C0
#define CChatService__GetFriendName                                0x6902D0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x58F6E0
#define CChatWindow__WndNotification                               0x590130

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6B1F30
#define CComboWnd__Draw                                            0x6B20E0
#define CComboWnd__GetCurChoice                                    0x6B1ED0
#define CComboWnd__GetListRect                                     0x6B23B0
#define CComboWnd__GetTextRect                                     0x6B1F60
#define CComboWnd__InsertChoice                                    0x6B2420
#define CComboWnd__SetColors                                       0x6B1E60
#define CComboWnd__SetChoice                                       0x6B1E90

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x596C10
#define CContainerWnd__vftable                                     0x766698

// CDisplay 
#define CDisplay__CleanGameUI                                      0x463860
#define CDisplay__GetClickedActor                                  0x460FB0
#define CDisplay__GetUserDefinedColor                              0x4600D0
#define CDisplay__GetWorldFilePath                                 0x45F620
#define CDisplay__is3dON                                           0x45E780
#define CDisplay__ReloadUI                                         0x471DD0
#define CDisplay__WriteTextHD2                                     0x463FD0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x565720
#define CEditBaseWnd__SetSel                                       0x6D75F0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6BFDF0
#define CEditWnd__GetCharIndexPt                                   0x6C0C40
#define CEditWnd__GetDisplayString                                 0x6BFF80
#define CEditWnd__GetHorzOffset                                    0x6C0210
#define CEditWnd__GetLineForPrintableChar                          0x6C06F0
#define CEditWnd__GetSelStartPt                                    0x6C0E90
#define CEditWnd__GetSTMLSafeText                                  0x6C03B0
#define CEditWnd__PointFromPrintableChar                           0x6C0800
#define CEditWnd__SelectableCharFromPoint                          0x6C0980
#define CEditWnd__SetEditable                                      0x6C0380

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4CD640
#define CEverQuest__DropHeldItemOnGround                           0x4D19D0
#define CEverQuest__dsp_chat                                       0x4D2EF0
#define CEverQuest__DoTellWindow                                   0x4D1B50
#define CEverQuest__EnterZone                                      0x4E8570
#define CEverQuest__GetBodyTypeDesc                                0x4CAA40
#define CEverQuest__GetClassDesc                                   0x4CA1A0
#define CEverQuest__GetClassThreeLetterCode                        0x4CA7A0
#define CEverQuest__GetDeityDesc                                   0x4CB0B0
#define CEverQuest__GetLangDesc                                    0x4CADD0
#define CEverQuest__GetRaceDesc                                    0x4CB080
#define CEverQuest__InterpretCmd                                   0x4D3960
#define CEverQuest__LeftClickedOnPlayer                            0x4E6D10
#define CEverQuest__LMouseUp                                       0x4E9340
#define CEverQuest__RightClickedOnPlayer                           0x4E70E0
#define CEverQuest__RMouseUp                                       0x4E8B70
#define CEverQuest__SetGameState                                   0x4CDAC0
#define CEverQuest__Emote                                          0x4D30F0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5A3780
#define CGaugeWnd__CalcLinesFillRect                               0x5A37E0
#define CGaugeWnd__Draw                                            0x5A3BF0

// CGuild
#define CGuild__FindMemberByName                                   0x418100

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5BB770

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5C4CC0
#define CInvSlotMgr__MoveItem                                      0x5C4E60

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5C3680
#define CInvSlot__SliderComplete                                   0x5C3B90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5D3BE0
#define CItemDisplayWnd__SetSpell                                  0x628ED0

// CLabel 
#define CLabel__Draw                                               0x5D94C0

// CListWnd 
#define CListWnd__AddColumn                                        0x6B1C70
#define CListWnd__AddColumn1                                       0x6B1740
#define CListWnd__AddLine                                          0x6B1270
#define CListWnd__AddString                                        0x6B1470
#define CListWnd__CalculateFirstVisibleLine                        0x6AE650
#define CListWnd__CalculateVSBRange                                0x6B02B0
#define CListWnd__ClearAllSel                                      0x6ADD80
#define CListWnd__CloseAndUpdateEditWindow                         0x6AEC80
#define CListWnd__Compare                                          0x6AF020
#define CListWnd__Draw                                             0x6AFFA0
#define CListWnd__DrawColumnSeparators                             0x6AFE10
#define CListWnd__DrawHeader                                       0x6ADF50
#define CListWnd__DrawItem                                         0x6AF730
#define CListWnd__DrawLine                                         0x6AFAB0
#define CListWnd__DrawSeparator                                    0x6AFEB0
#define CListWnd__EnsureVisible                                    0x6AE6A0
#define CListWnd__ExtendSel                                        0x6AF650
#define CListWnd__GetColumnMinWidth                                0x6ADB90
#define CListWnd__GetColumnWidth                                   0x6ADAD0
#define CListWnd__GetCurSel                                        0x6AD590
#define CListWnd__GetHeaderRect                                    0x6AD6A0
#define CListWnd__GetItemAtPoint                                   0x6AE9A0
#define CListWnd__GetItemAtPoint1                                  0x6AEA10
#define CListWnd__GetItemData                                      0x6AD880
#define CListWnd__GetItemHeight                                    0x6AE3E0
#define CListWnd__GetItemIcon                                      0x6ADA10
#define CListWnd__GetItemRect                                      0x6AE780
#define CListWnd__GetItemText                                      0x6AD8C0
#define CListWnd__GetSelList                                       0x6B1620
#define CListWnd__GetSeparatorRect                                 0x6AEF60
#define CListWnd__RemoveLine                                       0x6B1C20
#define CListWnd__SetColors                                        0x6AD610
#define CListWnd__SetColumnJustification                           0x6ADBF0
#define CListWnd__SetColumnWidth                                   0x6ADB50
#define CListWnd__SetCurSel                                        0x6AD5D0
#define CListWnd__SetItemColor                                     0x6B0EE0
#define CListWnd__SetItemData                                      0x6ADE20
#define CListWnd__SetItemText                                      0x6B0E60
#define CListWnd__ShiftColumnSeparator                             0x6AF5C0
#define CListWnd__Sort                                             0x6B1CA0
#define CListWnd__ToggleSel                                        0x6ADCF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5EE5C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5F46E0
#define CMerchantWnd__RequestBuyItem                               0x5F5A70
#define CMerchantWnd__RequestSellItem                              0x5F4940
#define CMerchantWnd__SelectBuySellSlot                            0x5F57A0

// CObfuscator
#define CObfuscator__doit                                          0x66BE60

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6C7FC0
#define CSidlManager__CreateLabel                                  0x621EF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6B8EA0
#define CSidlScreenWnd__CalculateVSBRange                          0x6CDB40
#define CSidlScreenWnd__ConvertToRes                               0x6D74D0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6B92F0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6BA390
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6BA440
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6B9B80
#define CSidlScreenWnd__DrawSidlPiece                              0x6B8FD0
#define CSidlScreenWnd__EnableIniStorage                           0x6B8B90
#define CSidlScreenWnd__GetSidlPiece                               0x6B91D0
#define CSidlScreenWnd__Init1                                      0x6BA1F0
#define CSidlScreenWnd__LoadIniInfo                                0x6B93A0
#define CSidlScreenWnd__LoadIniListWnd                             0x6B8CE0
#define CSidlScreenWnd__LoadSidlScreen                             0x6B9DC0
#define CSidlScreenWnd__StoreIniInfo                               0x6B87A0
#define CSidlScreenWnd__WndNotification                            0x6B9F70
#define CSidlScreenWnd__GetChildItem                               0x6B8BF0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x52A430

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6D89E0
#define CSliderWnd__SetValue                                       0x6D8AE0
#define CSliderWnd__SetNumTicks                                    0x6D9060

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6275F0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6D5790
#define CStmlWnd__CalculateVSBRange                                0x6CDB40
#define CStmlWnd__CanBreakAtCharacter                              0x6CDC80
#define CStmlWnd__FastForwardToEndOfTag                            0x6CE780
#define CStmlWnd__ForceParseNow                                    0x6D5BE0
#define CStmlWnd__GetNextTagPiece                                  0x6CE6A0
#define CStmlWnd__GetSTMLText                                      0x58F680
#define CStmlWnd__GetThisChar                                      0x6F9900
#define CStmlWnd__GetVisiableText                                  0x6CF990
#define CStmlWnd__InitializeWindowVariables                        0x6D1AD0
#define CStmlWnd__MakeStmlColorTag                                 0x6CD240
#define CStmlWnd__MakeWndNotificationTag                           0x6CD2E0
#define CStmlWnd__SetSTMLText                                      0x6D1BF0
#define CStmlWnd__StripFirstSTMLLines                              0x6D5510
#define CStmlWnd__UpdateHistoryString                              0x6D01F0

// CTabWnd 
#define CTabWnd__Draw                                              0x6D9DF0
#define CTabWnd__DrawCurrentPage                                   0x6D9800
#define CTabWnd__DrawTab                                           0x6D95E0
#define CTabWnd__GetCurrentPage                                    0x6D9A80
#define CTabWnd__GetPageClientRect                                 0x6D92B0
#define CTabWnd__GetPageFromTabIndex                               0x6D9510
#define CTabWnd__GetPageInnerRect                                  0x6D9310
#define CTabWnd__GetTabInnerRect                                   0x6D9490
#define CTabWnd__GetTabRect                                        0x6D93A0
#define CTabWnd__IndexInBounds                                     0x6D95AD
#define CTabWnd__InsertPage                                        0x6DA060
#define CTabWnd__SetPage                                           0x6D9AC0
#define CTabWnd__SetPageRect                                       0x6D9D20
#define CTabWnd__UpdatePage                                        0x6D9FE0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4145F0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6BA7A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6E1600

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6AD300

// CXRect 
#define CXRect__CenterPoint                                        0x56AEE0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4F9690
#define CXStr__CXStr1                                              0x6A6F70
#define CXStr__CXStr3                                              0x6A19C0
#define CXStr__dCXStr                                              0x403580
#define CXStr__operator_equal1                                     0x6A1B80
#define CXStr__operator_plus_equal1                                0x6A2A80

// CXWnd 
#define CXWnd__BringToTop                                          0x6B2CC0
#define CXWnd__Center                                              0x6B65E0
#define CXWnd__ClrFocus                                            0x6B29A0
#define CXWnd__DoAllDrawing                                        0x6B7350
#define CXWnd__DrawChildren                                        0x6B7480
#define CXWnd__DrawColoredRect                                     0x6B2F30
#define CXWnd__DrawTooltip                                         0x6B7180
#define CXWnd__DrawTooltipAtPoint                                  0x6B6390
#define CXWnd__GetBorderFrame                                      0x6B33B0
#define CXWnd__GetChildWndAt                                       0x6B5EC0
#define CXWnd__GetClientClipRect                                   0x6B32F0
#define CXWnd__GetScreenClipRect                                   0x6B6800
#define CXWnd__GetScreenRect                                       0x6B35C0
#define CXWnd__GetTooltipRect                                      0x6B3150
#define CXWnd__GetWindowTextA                                      0x55E490
#define CXWnd__IsActive                                            0x6BB8D0
#define CXWnd__IsDescendantOf                                      0x6B3360
#define CXWnd__IsReallyVisible                                     0x6B5EA0
#define CXWnd__IsType                                              0x6DB210
#define CXWnd__Move                                                0x6B5AC0
#define CXWnd__Move1                                               0x6B6FE0
#define CXWnd__ProcessTransition                                   0x6B2C80
#define CXWnd__Refade                                              0x6B2A50
#define CXWnd__Resize                                              0x6B3680
#define CXWnd__Right                                               0x6B6740
#define CXWnd__SetFocus                                            0x6B4CA0
#define CXWnd__SetKeyTooltip                                       0x6B3890
#define CXWnd__SetMouseOver                                        0x6B3860
#define CXWnd__StartFade                                           0x6B2D00
#define CXWnd__GetChildItem                                        0x6B6990

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6BCD60
#define CXWndManager__DrawWindows                                  0x6BC970
#define CXWndManager__GetKeyboardFlags                             0x6BB560
#define CXWndManager__HandleKeyboardMsg                            0x6BBAD0
#define CXWndManager__RemoveWnd                                    0x6BB9F0

// CDBStr
#define CDBStr__GetString                                          0x45D0D0

// EQ_Character 
#define EQ_Character__CastRay                                      0x705970
#define EQ_Character__CastSpell                                    0x4259A0
#define EQ_Character__Cur_HP                                       0x4326F0
#define EQ_Character__GetAACastingTimeModifier                     0x4200A0
#define EQ_Character__GetCharInfo2                                 0x681C90
#define EQ_Character__GetFocusCastingTimeModifier                  0x41BCA0
#define EQ_Character__GetFocusRangeModifier                        0x41BDE0
#define EQ_Character__Max_Endurance                                0x50C600
#define EQ_Character__Max_HP                                       0x42D850
#define EQ_Character__Max_Mana                                     0x50E000
#define EQ_Character__doCombatAbility                              0x50CF30
#define EQ_Character__UseSkill                                     0x4384F0
#define EQ_Character__GetConLevel                                  0x509470

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F7360
#define EQ_Item__GetItemLinkHash                                   0x675970
#define EQ_Item__IsStackable                                       0x66C740

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x475D10
#define EQ_LoadingS__Array                                         0x7BA8A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x510F20
#define EQ_PC__GetAltAbilityIndex                                  0x67A200
#define EQ_PC__GetCombatAbility                                    0x67A290
#define EQ_PC__GetCombatAbilityTimer                               0x67A340
#define EQ_PC__GetItemTimerValue                                   0x50BE00
#define EQ_PC__HasLoreItem                                         0x50F3F0

// EQItemList 
#define EQItemList__dEQItemList                                    0x49F4B0
#define EQItemList__EQItemList                                     0x49F400

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45CA80

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x515720
#define EQPlayer__dEQPlayer                                        0x5196F0
#define EQPlayer__DoAttack                                         0x526690
#define EQPlayer__EQPlayer                                         0x51D360
#define EQPlayer__SetNameSpriteState                               0x5176C0
#define EQPlayer__SetNameSpriteTint                                0x515790
#define EQPlayer__IsBodyType_j                                     0x705340

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x51E420
#define EQPlayerManager__GetSpawnByName                            0x51E680

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F9000
#define KeypressHandler__AttachKeyToEqCommand                      0x4F9040
#define KeypressHandler__ClearCommandStateArray                    0x4F8E10
#define KeypressHandler__HandleKeyDown                             0x4F79C0
#define KeypressHandler__HandleKeyUp                               0x4F7CD0
#define KeypressHandler__SaveKeymapping                            0x4F8EE0

// MapViewMap 
#define MapViewMap__Clear                                          0x5E9C90
#define MapViewMap__SaveEx                                         0x5EA660

#define OtherCharData__GetAltCurrency                              0x698950

// StringTable 
#define StringTable__getString                                     0x66C0E0
