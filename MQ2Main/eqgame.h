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
#define __ExpectedVersionDate                                     "Jun 26 2006" 
#define __ExpectedVersionTime                                     "13:10:48" 
#define __ActualVersionDate                                        0x6A2AFC
#define __ActualVersionTime                                        0x6A2B08

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x4D5080
#define __MemChecker2                                              0x500180
#define __MemChecker3                                              0x500230
#define __MemChecker4                                              0x5D3B00
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
#define __Autofire                                                 0x9D4668
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
#define __CastRay                                                  0x49B940
#define __ConvertItemTags                                          0x490B50
#define __ExecuteCmd                                               0x482510
#define __get_melee_range                                          0x4875E0
#define __GetGaugeValueFromEQ                                      0x5AB000
#define __GetLabelFromEQ                                           0x5AB6B0
#define __NewUIINI                                                 0x5AAC00
#define __ProcessGameEvents                                        0x4C3FF0
#define __SendMessage                                              0x4A77C0
#define CrashDetected                                              0x4FFE50
#define DrawNetStatus                                              0x4D7D10
#define Util__FastTime                                             0x5D90A0


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x464A80
#define AltAdvManager__IsAbilityReady                              0x464AC0
#define AltAdvManager__GetAltAbility                               0x464C10

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x4F6650

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x51D280

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x62E180

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x5300B0
#define CChatManager__InitContextMenu                              0x5307F0

// CChatWindow
#define CChatWindow__CChatWindow                                   0x534900

// CComboWnd
#define CComboWnd__DeleteAll                                       0x60D0F0
#define CComboWnd__Draw                                            0x60D2A0
//#define CComboWnd__GetButtonRect                                   0x0
#define CComboWnd__GetCurChoice                                    0x60D0A0
#define CComboWnd__GetListRect                                     0x60D590
#define CComboWnd__GetTextRect                                     0x60D120
#define CComboWnd__InsertChoice                                    0x60D600
#define CComboWnd__SetColors                                       0x60D030
#define CComboWnd__SetChoice                                       0x60D060

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x53AF10
#define CContainerWnd__vftable                                     0x6A8D38

// CDisplay
#define CDisplay__CleanGameUI                                      0x454F30
#define CDisplay__GetClickedActor                                  0x452890
#define CDisplay__GetUserDefinedColor                              0x451D00
#define CDisplay__GetWorldFilePath                                 0x451350
#define CDisplay__ReloadUI                                         0x4602E0
#define CDisplay__WriteTextHD2                                     0x456690

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x50E110
#define CEditBaseWnd__SetSel                                       0x62D200

// CEditWnd
#define CEditWnd__DrawCaret                                        0x61A180
#define CEditWnd__GetCharIndexPt                                   0x61AFA0
#define CEditWnd__GetDisplayString                                 0x61A310
#define CEditWnd__GetHorzOffset                                    0x61A580
#define CEditWnd__GetLineForPrintableChar                          0x61AA60
#define CEditWnd__GetSelStartPt                                    0x61B1E0
#define CEditWnd__GetSTMLSafeText                                  0x61A720
#define CEditWnd__PointFromPrintableChar                           0x61AB70
#define CEditWnd__SelectableCharFromPoint                          0x61ACF0
#define CEditWnd__SetEditable                                      0x61A6F0

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x4ABC60
#define CEverQuest__DropHeldItemOnGround                           0x4AF760
#define CEverQuest__dsp_chat                                       0x4B0310
#define CEverQuest__EnterZone                                      0x4C2BC0
#define CEverQuest__GetBodyTypeDesc                                0x4A9050
#define CEverQuest__GetClassDesc                                   0x4A87B0
#define CEverQuest__GetClassThreeLetterCode                        0x4A8DB0
#define CEverQuest__GetDeityDesc                                   0x4A95A0
#define CEverQuest__GetLangDesc                                    0x4A92C0
#define CEverQuest__GetRaceDesc                                    0x4A9570
#define CEverQuest__InterpretCmd                                   0x4B0C20
#define CEverQuest__LeftClickedOnPlayer                            0x4C1830
#define CEverQuest__RightClickedOnPlayer                           0x4C1C40
#define CEverQuest__SetGameState                                   0x4ABCA0

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x545C90
#define CGaugeWnd__CalcLinesFillRect                               0x545D00
#define CGaugeWnd__Draw                                            0x546090

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x559690

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x560CC0
#define CInvSlotMgr__MoveItem                                      0x560E60

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x561D70

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                                   0x568B40
#define CItemDisplayWnd__SetSpell                                  0x564760

// CLabel
#define CLabel__Draw                                               0x56DF70

// CListWnd
#define CListWnd__AddColumn                                        0x60CE20
#define CListWnd__AddColumn1                                       0x60C900
#define CListWnd__AddLine                                          0x60C4E0
#define CListWnd__AddString                                        0x60C6B0
#define CListWnd__CalculateFirstVisibleLine                        0x609810
#define CListWnd__CalculateVSBRange                                0x60B490
#define CListWnd__ClearAllSel                                      0x608FA0
#define CListWnd__CloseAndUpdateEditWindow                         0x609E40
#define CListWnd__Compare                                          0x60A1F0
#define CListWnd__Draw                                             0x60AD90
#define CListWnd__DrawColumnSeparators                             0x60B000
#define CListWnd__DrawHeader                                       0x609130
#define CListWnd__DrawItem                                         0x60A900
#define CListWnd__DrawLine                                         0x60ACB0
#define CListWnd__DrawSeparator                                    0x60ACB0
#define CListWnd__EnsureVisible                                    0x609860
#define CListWnd__ExtendSel                                        0x60A830
//#define CListWnd__GetColumnFlags                                   0x0
//#define CListWnd__GetColumnJustification                           0x0
#define CListWnd__GetColumnMinWidth                                0x608D40
#define CListWnd__GetColumnWidth                                   0x608C80
#define CListWnd__GetCurSel                                        0x608760
#define CListWnd__GetHeaderRect                                    0x608850
#define CListWnd__GetItemAtPoint                                   0x609B50
#define CListWnd__GetItemAtPoint1                                  0x609BC0
#define CListWnd__GetItemData                                      0x608A30
#define CListWnd__GetItemHeight                                    0x6095A0
#define CListWnd__GetItemIcon                                      0x608BC0
#define CListWnd__GetItemRect                                      0x609940
#define CListWnd__GetItemText                                      0x608A70
#define CListWnd__GetSelList                                       0x60C7E0
#define CListWnd__GetSeparatorRect                                 0x60A130
//#define CListWnd__IsLineEnabled                                    0x0
#define CListWnd__RemoveLine                                       0x60CDD0
#define CListWnd__SetColors                                        0x6087C0
#define CListWnd__SetColumnJustification                           0x608DA0
#define CListWnd__SetColumnWidth                                   0x608D00
#define CListWnd__SetCurSel                                        0x6087A0
#define CListWnd__SetItemColor                                     0x60C0B0
#define CListWnd__SetItemData                                      0x609040
#define CListWnd__SetItemText                                      0x60C030
#define CListWnd__ShiftColumnSeparator                             0x60A7A0
#define CListWnd__Sort                                             0x60CE50
#define CListWnd__ToggleSel                                        0x608F10

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x580240

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x581C30
#define CMerchantWnd__RequestBuyItem                               0x582DA0
#define CMerchantWnd__RequestSellItem                              0x581E90
#define CMerchantWnd__SelectBuySellSlot                            0x582AA0

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x621AB0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x50FA80
#define CSidlScreenWnd__CalculateVSBRange                          0x612700
#define CSidlScreenWnd__ConvertToRes                               0x612E60
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6136C0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x614980
#define CSidlScreenWnd__CSidlScreenWnd2                            0x614A30
#define CSidlScreenWnd__dCSidlScreenWnd                            0x614240
#define CSidlScreenWnd__DrawSidlPiece                              0x6133E0
#define CSidlScreenWnd__EnableIniStorage                           0x612E10
#define CSidlScreenWnd__GetSidlPiece                               0x6135A0
#define CSidlScreenWnd__Init1                                      0x6147A0
#define CSidlScreenWnd__LoadIniInfo                                0x613770
#define CSidlScreenWnd__LoadIniListWnd                             0x612FD0
#define CSidlScreenWnd__LoadSidlScreen                             0x613210
//#define CSidlScreenWnd__SetScreen                                  0x0
#define CSidlScreenWnd__StoreIniInfo                               0x612940
#define CSidlScreenWnd__WndNotification                            0x613340

// CSliderWnd
#define CSliderWnd__GetValue                                       0x62FE10
#define CSliderWnd__SetValue                                       0x62FF10
#define CSliderWnd__SetNumTicks                                    0x630450

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x5A8D30

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x62BEA0
#define CStmlWnd__CalculateHSBRange                                0x624240
#define CStmlWnd__CalculateVSBRange                                0x6241E0
#define CStmlWnd__CanBreakAtCharacter                              0x624380
#define CStmlWnd__CanGoBackward                                    0x624440
#define CStmlWnd__FastForwardToEndOfTag                            0x624E90
//#define CStmlWnd__GetNextChar                                      0x0
#define CStmlWnd__GetNextTagPiece                                  0x624DB0
#define CStmlWnd__GetSTMLText                                      0x5348A0
#define CStmlWnd__GetThisChar                                      0x64ADC0
#define CStmlWnd__GetVisiableText                                  0x6260B0
#define CStmlWnd__InitializeWindowVariables                        0x628210
#define CStmlWnd__MakeStmlColorTag                                 0x6238E0
#define CStmlWnd__MakeWndNotificationTag                           0x623980
#define CStmlWnd__StripFirstSTMLLines                              0x62BC30
#define CStmlWnd__UpdateHistoryString                              0x626910

// CTabWnd
#define CTabWnd__Draw                                              0x62F840
#define CTabWnd__DrawCurrentPage                                   0x62F1C0
#define CTabWnd__DrawTab                                           0x62EFA0
#define CTabWnd__GetCurrentPage                                    0x62F4C0
//#define CTabWnd__GetCurrentTabIndex                                0x0
//#define CTabWnd__GetNumTabs                                        0x0
#define CTabWnd__GetPageClientRect                                 0x62EC70
#define CTabWnd__GetPageFromTabIndex                               0x62EED0
#define CTabWnd__GetPageInnerRect                                  0x62ECD0
#define CTabWnd__GetTabInnerRect                                   0x62EE50
#define CTabWnd__GetTabRect                                        0x62ED60
#define CTabWnd__IndexInBounds                                     0x62EF6D
#define CTabWnd__InsertPage                                        0x62FA60
#define CTabWnd__SetPage                                           0x62F500
#define CTabWnd__SetPageRect                                       0x62F770
#define CTabWnd__UpdatePage                                        0x62F9E0

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x4122E0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x614D90

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x635260

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x6084F0

// CXRect
#define CXRect__CenterPoint                                        0x513690

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x4106C0
#define CXStr__CXStr1                                              0x585DE0
#define CXStr__CXStr3                                              0x5DA660
#define CXStr__dCXStr                                              0x60CFA0
#define CXStr__operator_equal1                                     0x5DA820
#define CXStr__operator_plus_equal1                                0x5DB660

// CXWnd
#define CXWnd__BringToTop                                          0x60DE10
#define CXWnd__Center                                              0x6114B0
#define CXWnd__ClrFocus                                            0x60DB10
#define CXWnd__DoAllDrawing                                        0x612170
#define CXWnd__DrawChildren                                        0x6122A0
#define CXWnd__DrawColoredRect                                     0x60E070
#define CXWnd__DrawTooltip                                         0x6120F0
#define CXWnd__DrawTooltipAtPoint                                  0x611310
#define CXWnd__GetBorderFrame                                      0x60E510
#define CXWnd__GetChildWndAt                                       0x610E10
#define CXWnd__GetClientClipRect                                   0x60E440
#define CXWnd__GetFirstChildWnd                                    0x60DEB0
#define CXWnd__GetNextChildWnd                                     0x610DD0
#define CXWnd__GetNextSib                                          0x60DED0
#define CXWnd__GetScreenClipRect                                   0x611740
#define CXWnd__GetScreenRect                                       0x60E6B0
#define CXWnd__GetTooltipRect                                      0x60E2B0
#define CXWnd__GetWindowTextA                                      0x507460
#define CXWnd__IsActive                                            0x615E40
#define CXWnd__IsDescendantOf                                      0x60E4C0
#define CXWnd__IsReallyVisible                                     0x610DB0
#define CXWnd__IsType                                              0x631000
#define CXWnd__Move                                                0x6108C0
#define CXWnd__Move1                                               0x610960
#define CXWnd__ProcessTransition                                   0x60DDE0
#define CXWnd__Refade                                              0x60DBC0
#define CXWnd__Resize                                              0x611880
#define CXWnd__Right                                               0x611620
#define CXWnd__SetFirstChildPointer                                0x60E920
#define CXWnd__SetFocus                                            0x60FC10
#define CXWnd__SetKeyTooltip                                       0x60E980
#define CXWnd__SetMouseOver                                        0x60E950
#define CXWnd__SetNextSibPointer                                   0x60E930
#define CXWnd__StartFade                                           0x60DE30

// CXWndManager
#define CXWndManager__DrawCursor                                   0x617200
#define CXWndManager__DrawWindows                                  0x616EC0
#define CXWndManager__GetFirstChildWnd                             0x6167E0
#define CXWndManager__GetKeyboardFlags                             0x615B50
#define CXWndManager__HandleKeyboardMsg                            0x616030
#define CXWndManager__RemoveWnd                                    0x615F50

// CDBStr
#define CDBStr__GetString                                          0x44E970

// EQ_Character
#define EQ_Character__CastRay                                      0x657580
#define EQ_Character__CastSpell                                    0x41E630
#define EQ_Character__Cur_HP                                       0x425880
#define EQ_Character__GetAACastingTimeModifier                     0x4197B0
#define EQ_Character__GetCharInfo2                                 0x5ED970
#define EQ_Character__GetFocusCastingTimeModifier                  0x418A50
#define EQ_Character__Max_Endurance                                0x4241F0
#define EQ_Character__Max_HP                                       0x4240A0
#define EQ_Character__Max_Mana                                     0x4DC640
#define EQ_Character__doCombatAbility                              0x4DB4D0
#define EQ_Character__UseSkill                                     0x430ED0

// EQ_Item
#define EQ_Item__CanDrop                                           0x4CF1E0
#define EQ_Item__GetItemLinkHash                                   0x5E2DD0
#define EQ_Item__IsStackable                                       0x5EDE30

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar                                0x465AE0
#define EQ_LoadingS__Array                                         0x6EDC20

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x4DF3A0
#define EQ_PC__GetAltAbilityIndex                                  0x5E70C0
#define EQ_PC__GetCombatAbility                                    0x5E71B0
#define EQ_PC__GetCombatAbilityTimer                               0x5E7260
#define EQ_PC__GetItemTimerValue                                   0x4DAAF0

// EQItemList
#define EQItemList__dEQItemList                                    0x485E50
#define EQItemList__EQItemList                                     0x485DB0

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x4E38E0
#define EQPlayer__dEQPlayer                                        0x4E76C0
#define EQPlayer__DoAttack                                         0x4F2490
#define EQPlayer__EQPlayer                                         0x4E9A50
#define EQPlayer__SetNameSpriteState                               0x4E5A90
#define EQPlayer__SetNameSpriteTint                                0x4E3950

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4EA710

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4D0FA0
#define KeypressHandler__AttachKeyToEqCommand                      0x4D0FE0
#define KeypressHandler__ClearCommandStateArray                    0x4D0DB0
#define KeypressHandler__HandleKeyDown                             0x4CFA10
#define KeypressHandler__HandleKeyUp                               0x4CFD10
#define KeypressHandler__SaveKeymapping                            0x4D0E80

// MapViewMap
#define MapViewMap__Clear                                          0x57C260
#define MapViewMap__SaveEx                                         0x57CC30

// StringTable
#define StringTable__getString                                     0x5DECC0
