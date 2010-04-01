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
#define __ExpectedVersionDate                                     "Jun 15 2006"
#define __ExpectedVersionTime                                     "11:23:27"
#define __ActualVersionDate                                        0x6A2A84
#define __ActualVersionTime                                        0x6A2A90

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x4D5050
#define __MemChecker2                                              0x500150
#define __MemChecker3                                              0x500200
#define __MemChecker4                                              0x5D3B30
#define __EncryptPad0                                              0x7E3700
#define __EncryptPad2                                              0x7E5840
#define __EncryptPad3                                              0x7E5C40
#define __EncryptPad4                                              0x7EC668

// Direct Input
#define DI8__Main                                                  0x9D7A64
#define DI8__Keyboard                                              0x9D7A68
#define DI8__Mouse                                                 0x9D7A6C

#define __AltTimerReady                                            0x973412
#define __Attack                                                   0x9D4667
#define __BindList                                                 0x7DEB20
#define __Clicks                                                   0x97259C
#define __CommandList                                              0x7DF300
#define __CurrentMapLabel                                          0x9E0B14
#define __CurrentSocial                                            0x6EAF10
#define __DoAbilityAvailable                                       0x9733AC
#define __DoAbilityList                                            0x9AC1B4
#define __DrawHandler                                              0x9ECE94
#define __FriendsList                                              0x9A8F54
#define __GroupCount                                               0x952CF8
#define __GroupLeader                                              0x952E54
#define __Guilds                                                   0x9547E0
#define __gWorld                                                   0x954750
#define __HotkeyPage                                               0x9D35A0
#define __HWnd                                                     0x9D7A0C
#define __IgnoreList                                               0x9AA854
#define __InChatMode                                               0x9724D8
#define __LastTell                                                 0x9746C0
#define __Mouse                                                    0x9D7A70
#define __MouseLook                                                0x97256A
#define __NetStatusToggle                                          0x97256C
#define __PCNames                                                  0x973718
#define __RangeAttackReady                                         0x973410
#define __RunWalkState                                             0x9724DC
#define __ScreenMode                                               0x8A26A8
#define __ScreenX                                                  0x9724A0
#define __ScreenY                                                  0x9724A4
#define __ServerHost                                               0x952C4C
#define __ServerName                                               0x9AC174
#define __ShowNames                                                0x9735F8
#define __SkillDict                                                0x8A33A0
#define __Socials                                                  0x9AC274

////
//Section 1: Vital Offsets
////
#define instCRaid                                                  0x96C430
#define instEQZoneInfo                                             0x972708
#define instKeypressHandler                                        0x9D473C
#define pinstActiveBanker                                          0x9547C0
#define pinstActiveCorpse                                          0x9547C4
#define pinstActiveGMaster                                         0x9547C8
#define pinstActiveMerchant                                        0x9547BC
#define pinstAltAdvManager                                         0x8A3378
#define pinstBandageTarget                                         0x9547A8
#define pinstCamActor                                              0x8A2E68
#define pinstCDBStr                                                0x8A2538
#define pinstCDisplay                                              0x9547D0
#define pinstCEverQuest                                            0x9D7BD8
#define pinstCharData                                              0x954790
#define pinstCharSpawn                                             0x9547B4
#define pinstControlledMissile                                     0x95478C
#define pinstControlledPlayer                                      0x9547B4
#define pinstCSidlManager                                          0x9EC738
#define pinstCXWndManager                                          0x9EC730
#define pinstEQItemList                                            0x954774
#define pinstEQSoundManager                                        0x8A3530
#define instGroup                                                  0x952CF8
#define pinstGroup                                                 0x952CF4
#define pinstImeManager                                            0x9EC73C
#define pinstLocalPlayer                                           0x9547A0
#define pinstModelPlayer                                           0x9547CC
#define pinstPCData                                                0x954790
#define pinstSelectedItem                                          0x9E096C
#define pinstSpawnManager                                          0x9D4A4C
#define pinstSpellManager                                          0x9D4AB4
#define pinstSpellSets                                             0x9D35A4
#define pinstStringTable                                           0x954760
#define pinstSwitchManager                                         0x952948
#define pinstTarget                                                0x9547B8
#define pinstTargetObject                                          0x954794
#define pinstTargetSwitch                                          0x954798
#define pinstTrackTarget                                           0x9547AC
#define pinstTradeTarget                                           0x95479C
#define instTributeActive                                          0x8A2515
#define pinstViewActor                                             0x8A2E64
#define pinstWorldData                                             0x954770
#define pinstDZMember                                              0x972000
#define pinstDZTimerInfo                                           0x972004
#define pinstTaskMember                                            0x8A24D4
#define instExpeditionLeader                                       0x971F3A
#define instExpeditionName                                         0x971F7A
#define pinstDynamicZone                                           0x971EF0


////
//Section 2:  UI Related Offsets
////
//#define pinstCAdventureMerchantWnd                                 0x801ED0
#define pinstCTextOverlay                                          0x7F0568
#define pinstCAudioTriggersWindow                                  0x7F0534
//                                                                   0x803988
#define pinstCCharacterSelect                                      0x8A2D30
#define pinstCFacePick                                             0x8A2D34
#define pinstCNoteWnd                                              0x8A2D38
#define pinstCBookWnd                                              0x8A2D3C
#define pinstCPetInfoWnd                                           0x8A2D40
#define pinstCTrainWnd                                             0x8A2D44
#define pinstCSkillsWnd                                            0x8A2D48
#define pinstCSkillsSelectWnd                                      0x8A2D4C
#define pinstCCombatSkillSelectWnd                                 0x8A2D50
#define pinstCFriendsWnd                                           0x8A2D54
#define pinstCAuraWnd                                              0x8A2D58
#define pinstCRespawnWnd                                           0x8A2D5C
#define pinstCBandolierWnd                                         0x8A2D60
#define pinstCPotionBeltWnd                                        0x8A2D64
#define pinstCAAWnd                                                0x8A2D68
#define pinstCGroupSearchFiltersWnd                                0x8A2D6C
#define pinstCLoadskinWnd                                          0x8A2D70
#define pinstCAlarmWnd                                             0x8A2D74
#define pinstCMusicPlayerWnd                                       0x8A2D78
#define pinstCMailWnd                                              0x8A2D7C
#define pinstCMailCompositionWnd                                   0x8A2D80
#define pinstCMailAddressBookWnd                                   0x8A2D84
#define pinstCRaidWnd                                              0x8A2D88
#define pinstCRaidOptionsWnd                                       0x8A2D8C
#define pinstCBreathWnd                                            0x8A2D90
#define pinstCMapViewWnd                                           0x8A2D94
#define pinstCMapToolbarWnd                                        0x8A2D98
#define pinstCEditLabelWnd                                         0x8A2D9C
#define pinstCTargetWnd                                            0x8A2DA0
#define pinstCColorPickerWnd                                       0x8A2DA4
#define pinstCPlayerWnd                                            0x8A2DA8
#define pinstCOptionsWnd                                           0x8A2DAC
#define pinstCBuffWindowNORMAL                                     0x8A2DB0
#define pinstCBuffWindowSHORT                                      0x8A2DB4
#define pinstCharacterCreation                                     0x8A2DB8
#define pinstCCursorAttachment                                     0x8A2DBC
#define pinstCCastingWnd                                           0x8A2DC0
#define pinstCCastSpellWnd                                         0x8A2DC4
#define pinstCSpellBookWnd                                         0x8A2DC8
#define pinstCInventoryWnd                                         0x8A2DCC
#define pinstCBankWnd                                              0x8A2DD0
#define pinstCQuantityWnd                                          0x8A2DD4
#define pinstCLootWnd                                              0x8A2DD8
#define pinstCActionsWnd                                           0x8A2DDC
#define pinstCCombatAbilityWnd                                     0x8A2DE0
#define pinstCMerchantWnd                                          0x8A2DE4
#define pinstCTradeWnd                                             0x8A2DE8
#define pinstCSelectorWnd                                          0x8A2DEC
#define pinstCBazaarWnd                                            0x8A2DF0
#define pinstCBazaarSearchWnd                                      0x8A2DF4
#define pinstCGiveWnd                                              0x8A2DF8
#define pinstCTrackingWnd                                          0x8A2DFC
#define pinstCInspectWnd                                           0x8A2E00
#define pinstCSocialEditWnd                                        0x8A2E04
#define pinstCFeedbackWnd                                          0x8A2E08
#define pinstCBugReportWnd                                         0x8A2E0C
#define pinstCVideoModesWnd                                        0x8A2E10
#define pinstCTextEntryWnd                                         0x8A2E18
#define pinstCFileSelectionWnd                                     0x8A2E1C
#define pinstCCompassWnd                                           0x8A2E20
#define pinstCPlayerNotesWnd                                       0x8A2E24
#define pinstCGemsGameWnd                                          0x8A2E28
#define pinstCTimeLeftWnd                                          0x8A2E2C
#define pinstCPetitionQWnd                                         0x8A2E30
#define pinstCSoulmarkWnd                                          0x8A2E34
#define pinstCStoryWnd                                             0x8A2E38
#define pinstCJournalTextWnd                                       0x8A2E3C
#define pinstCJournalCatWnd                                        0x8A2E40
#define pinstCBodyTintWnd                                          0x8A2E44
#define pinstCServerListWnd                                        0x8A2E48
#define pinstCAvaZoneWnd                                           0x8A2E4C
#define pinstCBlockedBuffWnd                                       0x8A2E50
#define pinstCBlockedPetBuffWnd                                    0x8A2E54
#define pinstCInvSlotMgr                                           0x8A2E58
#define pinstCContainerMgr                                         0x8A2E5C
//                                                                   0x9E6074
//                                                                   0x9E60AC
//                                                                   0x9E6450
#define pinstCAdventureLeaderboardWnd                              0x9E01A4
#define pinstCAdventureRequestWnd                                  0x9E01C0
#define pinstCAltStorageWnd                                        0x9E0220
#define pinstCAdventureStatsWnd                                    0x9E01DC
#define pinstCBarterMerchantWnd                                    0x9E03D4
#define pinstCBarterSearchWnd                                      0x9E03F0
#define pinstCBarterWnd                                            0x9E040C
//                                                                   0x9F1F40
#define pinstCChatManager                                          0x9E05FC
#define pinstCDynamicZoneWnd                                       0x9E06D8
#define pinstCEQMainWnd                                            0x9E0748
#define pinstCFindLocationWnd                                      0x9E07DC
#define pinstCGroupSearchWnd                                       0x9E0894
#define pinstCGroupWnd                                             0x9E088C
#define pinstCGuildBankWnd                                         0x9E08A8
#define pinstCGuildMgmtWnd                                         0x9E08C4
#define pinstCGuildTributeMasterWnd                                0x9E08E0
#define pinstCHotButtonWnd                                         0x9E08FC
#define pinstCHotButtonWnd1                                        0x9E08FC
#define pinstCHotButtonWnd2                                        0x9E0900
#define pinstCHotButtonWnd3                                        0x9E0904
#define pinstCHotButtonWnd4                                        0x9E0908
#define pinstCItemDisplayManager                                   0x9E09A0
#define pinstCItemExpTransferWnd                                   0x9E09C0
#define pinstCLeadershipWnd                                        0x9E0A3C
#define pinstCLFGuildWnd                                           0x9E0A58
#define pinstCMIZoneSelectWnd                                      0x9E0B7C
#define pinstCAdventureMerchantWnd                                 0x9E0C40
#define pinstCConfirmationDialog                                   0x9E0C5C
#define pinstCPopupWndManager                                      0x9E0C5C
#define pinstCProgressionSelectionWnd                              0x9E0C90
#define pinstCPvPLeaderboardWnd                                    0x9E0CAC
#define pinstCPvPStatsWnd                                          0x9E0CC8
//                                                                   0x9F2744
#define pinstCSystemInfoDialogBox                                  0x9E1628
#define pinstCTargetOfTargetWnd                                    0x9E1644
#define pinstCTaskSelectWnd                                        0x9E1678
#define pinstCTaskTemplateSelectWnd                                0x9E1694
#define pinstCTaskWnd                                              0x9E16B0
#define pinstCTicketCommentWnd                                     0x9E16E4
#define pinstCHelpWnd                                              0x9E1700
#define pinstCTipWndOFDAY                                          0x9E1734
#define pinstCTipWndCONTEXT                                        0x9E1738
#define pinstCTitleWnd                                             0x9E1754
#define pinstCTradeskillWnd                                        0x9E1798
#define pinstCTributeBenefitWnd                                    0x9E17E4
#define pinstCTributeMasterWnd                                     0x9E1800
#define pinstCContextMenuManager                                   0x9EC794
#define pinstCVoiceMacroWnd                                        0x9D4B7C


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                                  0x49B910
#define __ConvertItemTags                                          0x490B20
#define __ExecuteCmd                                               0x4824E0
#define __get_melee_range                                          0x4875B0
#define __GetGaugeValueFromEQ                                      0x5AB030
#define __GetLabelFromEQ                                           0x5AB6E0
#define __NewUIINI                                                 0x5AAC30
#define __ProcessGameEvents                                        0x4C3FC0
#define __SendMessage                                              0x4A7790
#define CrashDetected                                              0x4FFE20
#define DrawNetStatus                                              0x4D7CE0
#define Util__FastTime                                             0x5D90D0


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x464B00
#define AltAdvManager__IsAbilityReady                              0x464B40
#define AltAdvManager__GetAltAbility                               0x464C90

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x4F6620

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x51D260

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x62E1B0

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x5300B0
#define CChatManager__InitContextMenu                              0x5307F0

// CChatWindow
#define CChatWindow__CChatWindow                                   0x534900

// CComboWnd
#define CComboWnd__DeleteAll                                       0x60D120
#define CComboWnd__Draw                                            0x60D2D0
//#define CComboWnd__GetButtonRect                                   0x0
#define CComboWnd__GetCurChoice                                    0x60D0D0
#define CComboWnd__GetListRect                                     0x60D5C0
#define CComboWnd__GetTextRect                                     0x60D150
#define CComboWnd__InsertChoice                                    0x60D630
#define CComboWnd__SetColors                                       0x60D060
#define CComboWnd__SetChoice                                       0x60D090

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x53AF10
#define CContainerWnd__vftable                                     0x6A8CC0

// CDisplay
#define CDisplay__CleanGameUI                                      0x454FA0
#define CDisplay__GetClickedActor                                  0x452900
#define CDisplay__GetUserDefinedColor                              0x451D70
#define CDisplay__GetWorldFilePath                                 0x4513C0
#define CDisplay__ReloadUI                                         0x460360
#define CDisplay__WriteTextHD2                                     0x456700

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x50E0E0
#define CEditBaseWnd__SetSel                                       0x62D230

// CEditWnd
#define CEditWnd__DrawCaret                                        0x61A1B0
#define CEditWnd__GetCharIndexPt                                   0x61AFD0
#define CEditWnd__GetDisplayString                                 0x61A340
#define CEditWnd__GetHorzOffset                                    0x61A5B0
#define CEditWnd__GetLineForPrintableChar                          0x61AA90
#define CEditWnd__GetSelStartPt                                    0x61B210
#define CEditWnd__GetSTMLSafeText                                  0x61A750
#define CEditWnd__PointFromPrintableChar                           0x61ABA0
#define CEditWnd__SelectableCharFromPoint                          0x61AD20
#define CEditWnd__SetEditable                                      0x61A720

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x4ABC30
#define CEverQuest__DropHeldItemOnGround                           0x4AF730
#define CEverQuest__dsp_chat                                       0x4B02E0
#define CEverQuest__EnterZone                                      0x4C2B90
#define CEverQuest__GetBodyTypeDesc                                0x4A9020
#define CEverQuest__GetClassDesc                                   0x4A8780
#define CEverQuest__GetClassThreeLetterCode                        0x4A8D80
#define CEverQuest__GetDeityDesc                                   0x4A9570
#define CEverQuest__GetRaceDesc                                    0x4A9540
#define CEverQuest__InterpretCmd                                   0x4B0BF0
#define CEverQuest__LeftClickedOnPlayer                            0x4C1800
#define CEverQuest__RightClickedOnPlayer                           0x4C1C10
#define CEverQuest__SetGameState                                   0x4ABC70

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x545C90
#define CGaugeWnd__CalcLinesFillRect                               0x545D00
#define CGaugeWnd__Draw                                            0x546090

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x559690

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x560CD0
#define CInvSlotMgr__MoveItem                                      0x560E70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x561D80

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                                   0x568B50
#define CItemDisplayWnd__SetSpell                                  0x564770

// CLabel
#define CLabel__Draw                                               0x56DF80

// CListWnd
#define CListWnd__AddColumn                                        0x60CE50
#define CListWnd__AddColumn1                                       0x60C930
#define CListWnd__AddLine                                          0x60C510
#define CListWnd__AddString                                        0x60C6E0
#define CListWnd__CalculateFirstVisibleLine                        0x609840
#define CListWnd__CalculateVSBRange                                0x60B4C0
#define CListWnd__ClearAllSel                                      0x608FD0
#define CListWnd__CloseAndUpdateEditWindow                         0x609E70
#define CListWnd__Compare                                          0x60A220
#define CListWnd__Draw                                             0x60ADC0
#define CListWnd__DrawColumnSeparators                             0x60B030
#define CListWnd__DrawHeader                                       0x609160
#define CListWnd__DrawItem                                         0x60A930
#define CListWnd__DrawLine                                         0x60ACE0
#define CListWnd__DrawSeparator                                    0x60ACE0
#define CListWnd__EnsureVisible                                    0x609890
#define CListWnd__ExtendSel                                        0x60A860
//#define CListWnd__GetColumnFlags                                   0x0
//#define CListWnd__GetColumnJustification                           0x0
#define CListWnd__GetColumnMinWidth                                0x608D70
#define CListWnd__GetColumnWidth                                   0x608CB0
#define CListWnd__GetCurSel                                        0x608790
#define CListWnd__GetHeaderRect                                    0x608880
#define CListWnd__GetItemAtPoint                                   0x609B80
#define CListWnd__GetItemAtPoint1                                  0x609BF0
#define CListWnd__GetItemData                                      0x608A60
#define CListWnd__GetItemHeight                                    0x6095D0
#define CListWnd__GetItemIcon                                      0x608BF0
#define CListWnd__GetItemRect                                      0x609970
#define CListWnd__GetItemText                                      0x608AA0
#define CListWnd__GetSelList                                       0x60C810
#define CListWnd__GetSeparatorRect                                 0x60A160
//#define CListWnd__IsLineEnabled                                    0x0
#define CListWnd__RemoveLine                                       0x60CE00
#define CListWnd__SetColors                                        0x6087F0
#define CListWnd__SetColumnJustification                           0x608DD0
#define CListWnd__SetColumnWidth                                   0x608D30
#define CListWnd__SetCurSel                                        0x6087D0
#define CListWnd__SetItemColor                                     0x60C0E0
#define CListWnd__SetItemData                                      0x609070
#define CListWnd__SetItemText                                      0x60C060
#define CListWnd__ShiftColumnSeparator                             0x60A7D0
#define CListWnd__Sort                                             0x60CE80
#define CListWnd__ToggleSel                                        0x608F40

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x580250

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x581C40
#define CMerchantWnd__RequestBuyItem                               0x582DB0
#define CMerchantWnd__RequestSellItem                              0x581EA0
#define CMerchantWnd__SelectBuySellSlot                            0x582AB0

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x621AE0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x50FA50
#define CSidlScreenWnd__CalculateVSBRange                          0x612730
#define CSidlScreenWnd__ConvertToRes                               0x612E90
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6136F0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6149B0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x614A60
#define CSidlScreenWnd__dCSidlScreenWnd                            0x614270
#define CSidlScreenWnd__DrawSidlPiece                              0x613410
#define CSidlScreenWnd__EnableIniStorage                           0x612E40
#define CSidlScreenWnd__GetSidlPiece                               0x6135D0
#define CSidlScreenWnd__Init1                                      0x6147D0
#define CSidlScreenWnd__LoadIniInfo                                0x6137A0
#define CSidlScreenWnd__LoadIniListWnd                             0x613000
#define CSidlScreenWnd__LoadSidlScreen                             0x613240
//#define CSidlScreenWnd__SetScreen                                  0x0
#define CSidlScreenWnd__StoreIniInfo                               0x612970
#define CSidlScreenWnd__WndNotification                            0x613370

// CSliderWnd
#define CSliderWnd__GetValue                                       0x62FE40
#define CSliderWnd__SetValue                                       0x62FF40
#define CSliderWnd__SetNumTicks                                    0x630480

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x5A8D60

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x62BED0
#define CStmlWnd__CalculateHSBRange                                0x624270
#define CStmlWnd__CalculateVSBRange                                0x624210
#define CStmlWnd__CanBreakAtCharacter                              0x6243B0
#define CStmlWnd__CanGoBackward                                    0x624470
#define CStmlWnd__FastForwardToEndOfTag                            0x624EC0
//#define CStmlWnd__GetNextChar                                      0x0
#define CStmlWnd__GetNextTagPiece                                  0x624DE0
#define CStmlWnd__GetSTMLText                                      0x5348A0
#define CStmlWnd__GetThisChar                                      0x64ADF0
#define CStmlWnd__GetVisiableText                                  0x6260E0
#define CStmlWnd__InitializeWindowVariables                        0x628240
#define CStmlWnd__MakeStmlColorTag                                 0x623910
#define CStmlWnd__MakeWndNotificationTag                           0x6239B0
#define CStmlWnd__StripFirstSTMLLines                              0x62BC60
#define CStmlWnd__UpdateHistoryString                              0x626940

// CTabWnd
#define CTabWnd__Draw                                              0x62F870
#define CTabWnd__DrawCurrentPage                                   0x62F1F0
#define CTabWnd__DrawTab                                           0x62EFD0
#define CTabWnd__GetCurrentPage                                    0x62F4F0
//#define CTabWnd__GetCurrentTabIndex                                0x0
//#define CTabWnd__GetNumTabs                                        0x0
#define CTabWnd__GetPageClientRect                                 0x62ECA0
#define CTabWnd__GetPageFromTabIndex                               0x62EF00
#define CTabWnd__GetPageInnerRect                                  0x62ED00
#define CTabWnd__GetTabInnerRect                                   0x62EE80
#define CTabWnd__GetTabRect                                        0x62ED90
#define CTabWnd__IndexInBounds                                     0x62EF9D
#define CTabWnd__InsertPage                                        0x62FA90
#define CTabWnd__SetPage                                           0x62F530
#define CTabWnd__SetPageRect                                       0x62F7A0
#define CTabWnd__UpdatePage                                        0x62FA10

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x4122E0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x614DC0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x635290

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x608520

// CXRect
#define CXRect__CenterPoint                                        0x513660

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x4106C0
#define CXStr__CXStr1                                              0x585DF0
#define CXStr__CXStr3                                              0x5DA690
#define CXStr__dCXStr                                              0x60CFD0
#define CXStr__operator_equal1                                     0x5DA850
#define CXStr__operator_plus_equal1                                0x5DB690

// CXWnd
#define CXWnd__BringToTop                                          0x60DE40
#define CXWnd__Center                                              0x6114E0
#define CXWnd__ClrFocus                                            0x60DB40
#define CXWnd__DoAllDrawing                                        0x6121A0
#define CXWnd__DrawChildren                                        0x6122D0
#define CXWnd__DrawColoredRect                                     0x60E0A0
#define CXWnd__DrawTooltip                                         0x612120
#define CXWnd__DrawTooltipAtPoint                                  0x611340
#define CXWnd__GetBorderFrame                                      0x60E540
#define CXWnd__GetChildWndAt                                       0x610E40
#define CXWnd__GetClientClipRect                                   0x60E470
#define CXWnd__GetFirstChildWnd                                    0x60DEE0
#define CXWnd__GetNextChildWnd                                     0x610E00
#define CXWnd__GetNextSib                                          0x60DF00
#define CXWnd__GetScreenClipRect                                   0x611770
#define CXWnd__GetScreenRect                                       0x60E6E0
#define CXWnd__GetTooltipRect                                      0x60E2E0
#define CXWnd__GetWindowTextA                                      0x507430
#define CXWnd__IsActive                                            0x615E70
#define CXWnd__IsDescendantOf                                      0x60E4F0
#define CXWnd__IsReallyVisible                                     0x610DE0
#define CXWnd__IsType                                              0x631030
#define CXWnd__Move                                                0x6108F0
#define CXWnd__Move1                                               0x610990
#define CXWnd__ProcessTransition                                   0x60DE10
#define CXWnd__Refade                                              0x60DBF0
#define CXWnd__Resize                                              0x6118B0
#define CXWnd__Right                                               0x611650
#define CXWnd__SetFirstChildPointer                                0x60E950
#define CXWnd__SetFocus                                            0x60FC40
#define CXWnd__SetKeyTooltip                                       0x60E9B0
#define CXWnd__SetMouseOver                                        0x60E980
#define CXWnd__SetNextSibPointer                                   0x60E960
#define CXWnd__StartFade                                           0x60DE60

// CXWndManager
#define CXWndManager__DrawCursor                                   0x617230
#define CXWndManager__DrawWindows                                  0x616EF0
#define CXWndManager__GetFirstChildWnd                             0x616810
#define CXWndManager__GetKeyboardFlags                             0x615B80
#define CXWndManager__HandleKeyboardMsg                            0x616060
#define CXWndManager__RemoveWnd                                    0x615F80

// CDBStr
#define CDBStr__GetString                                          0x44E9E0

// EQ_Character
#define EQ_Character__CastRay                                      0x6575B0
#define EQ_Character__CastSpell                                    0x41E6A0
#define EQ_Character__Cur_HP                                       0x4258F0
#define EQ_Character__GetAACastingTimeModifier                     0x4197B0
#define EQ_Character__GetCharInfo2                                 0x5ED9A0
#define EQ_Character__GetFocusCastingTimeModifier                  0x418A50
#define EQ_Character__Max_Endurance                                0x424260
#define EQ_Character__Max_HP                                       0x424110
#define EQ_Character__Max_Mana                                     0x4DC610
#define EQ_Character__doCombatAbility                              0x4DB4A0
#define EQ_Character__UseSkill                                     0x430F40

// EQ_Item
#define EQ_Item__CanDrop                                           0x4CF1B0
#define EQ_Item__GetItemLinkHash                                   0x5E2E00
#define EQ_Item__IsStackable                                       0x5EDE60

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar                                0x465B60
#define EQ_LoadingS__Array                                         0x6EDC20

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x4DF370
#define EQ_PC__GetAltAbilityIndex                                  0x5E70F0
#define EQ_PC__GetCombatAbility                                    0x5E71E0
#define EQ_PC__GetCombatAbilityTimer                               0x5E7290
#define EQ_PC__GetItemTimerValue                                   0x4DAAC0

// EQItemList
#define EQItemList__dEQItemList                                    0x485E20
#define EQItemList__EQItemList                                     0x485D80

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x4E38B0
#define EQPlayer__dEQPlayer                                        0x4E7690
#define EQPlayer__DoAttack                                         0x4F2460
#define EQPlayer__EQPlayer                                         0x4E9A20
#define EQPlayer__SetNameSpriteState                               0x4E5A60
#define EQPlayer__SetNameSpriteTint                                0x4E3920

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4EA6E0

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4D0F70
#define KeypressHandler__AttachKeyToEqCommand                      0x4D0FB0
#define KeypressHandler__ClearCommandStateArray                    0x4D0D80
#define KeypressHandler__HandleKeyDown                             0x4CF9E0
#define KeypressHandler__HandleKeyUp                               0x4CFCE0
#define KeypressHandler__SaveKeymapping                            0x4D0E50

// MapViewMap
#define MapViewMap__Clear                                          0x57C270
#define MapViewMap__SaveEx                                         0x57CC40

// StringTable
#define StringTable__getString                                     0x5DECF0