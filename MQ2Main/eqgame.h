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
#define __ExpectedVersionDate                                     "Sep 26 2006"
#define __ExpectedVersionTime                                     "15:33:52"
#define __ActualVersionDate                                        0x6C23AC
#define __ActualVersionTime                                        0x6C23B8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x4E0390
#define __MemChecker1                                              0x5EC620
#define __MemChecker2                                              0x50F760
#define __MemChecker3                                              0x50F810
#define __MemChecker4                                              0x5E7870
#define __EncryptPad0                                              0x715748
#define __EncryptPad1                                              0x71EDE8
#define __EncryptPad2                                              0x717C88
#define __EncryptPad3                                              0x718088
#define __EncryptPad4                                              0x71E5E0

// Direct Input
#define DI8__Main                                                  0x905D54
#define DI8__Keyboard                                              0x905D58
#define DI8__Mouse                                                 0x905D5C

#define __AltTimerReady                                            0x8A52D6
#define __Attack                                                   0x90293A
#define __Autofire                                                 0x90293B
#define __BindList                                                 0x710A18
#define __Clicks                                                   0x8A444C
#define __CommandList                                              0x711208
#define __CurrentMapLabel                                          0x90EDF8
#define __CurrentSocial                                            0x70D4C4
#define __DoAbilityAvailable                                       0x8A5270
#define __DoAbilityList                                            0x8DA480
#define __DrawHandler                                              0x91B264
#define __GroupCount                                               0x884BA8
#define __GroupLeader                                              0x884D04
#define __Guilds                                                   0x886690
#define __gWorld                                                   0x886600
#define __HotkeyPage                                               0x90186C
#define __HWnd                                                     0x905CFC
#define __InChatMode                                               0x8A4388
#define __LastTell                                                 0x8A5B88
#define __Mouse                                                    0x905D60
#define __MouseLook                                                0x8A441A
#define __NetStatusToggle                                          0x8A441C
#define __PCNames                                                  0x8A55E0
#define __RangeAttackReady                                         0x8A52D4
#define __RunWalkState                                             0x8A438C
#define __ScreenMode                                               0x7D4690
#define __ScreenX                                                  0x8A4350
#define __ScreenY                                                  0x8A4354
#define __ServerHost                                               0x884AFC
#define __ServerName                                               0x8DA440
#define __ShowNames                                                0x8A54BC
#define __Socials                                                  0x8DA540

////
//Section 1: Vital Offsets
////
#define instCRaid                                                  0x89E2E0
#define instEQZoneInfo                                             0x8A45B8
#define instKeypressHandler                                        0x902A0C
#define pinstActiveBanker                                          0x886670
#define pinstActiveCorpse                                          0x886674
#define pinstActiveGMaster                                         0x886678
#define pinstActiveMerchant                                        0x88666C
#define pinstAltAdvManager                                         0x7D5360
#define pinstAuraInfo                                              0x723FB0
#define pinstBandageTarget                                         0x886658
#define pinstCamActor                                              0x7D4E54
#define pinstCDBStr                                                0x7D4520
#define pinstCDisplay                                              0x886680
#define pinstCEverQuest                                            0x905EC8
#define pinstCharData                                              0x886640
#define pinstCharSpawn                                             0x886664
#define pinstControlledMissile                                     0x88663C
#define pinstControlledPlayer                                      0x886664
#define pinstCSidlManager                                          0x91AAB4
#define pinstCXWndManager                                          0x91AAAC
#define pinstDynamicZone                                           0x8A3DA0
#define pinstDZMember                                              0x8A3EB0
#define pinstDZTimerInfo                                           0x8A3EB4
#define pinstEQItemList                                            0x886624
#define instEQMisc                                                 0x7D44D8
#define pinstEQSoundManager                                        0x7D5384
#define instExpeditionLeader                                       0x8A3DEA
#define instExpeditionName                                         0x8A3E2A
#define instGroup                                                  0x884BA8
#define pinstGroup                                                 0x884BA4
#define pinstImeManager                                            0x91AAB8
#define pinstLocalPlayer                                           0x886650
#define pinstModelPlayer                                           0x88667C
#define pinstPCData                                                0x886640
#define pinstSelectedItem                                          0x90EC50
#define pinstSkillMgr                                              0x902DA0
#define pinstSpawnManager                                          0x902D1C
#define pinstSpellManager                                          0x902DA4
#define pinstSpellSets                                             0x901870
#define pinstStringTable                                           0x886610
#define pinstSwitchManager                                         0x8847F8
#define pinstTarget                                                0x886668
#define pinstTargetObject                                          0x886644
#define pinstTargetSwitch                                          0x886648
#define pinstTaskMember                                            0x7D44BC
#define pinstTrackTarget                                           0x88665C
#define pinstTradeTarget                                           0x88664C
#define instTributeActive                                          0x7D44FD
#define pinstViewActor                                             0x7D4E50
#define pinstWorldData                                             0x886620


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                          0x7224E8
#define pinstCAudioTriggersWindow                                  0x7224CC
#define pinstCCharacterSelect                                      0x7D4D60
#define pinstCFacePick                                             0x7D4D18
#define pinstCNoteWnd                                              0x7D4D1C
#define pinstCBookWnd                                              0x7D4D20
#define pinstCPetInfoWnd                                           0x7D4D24
#define pinstCTrainWnd                                             0x7D4D28
#define pinstCSkillsWnd                                            0x7D4D2C
#define pinstCSkillsSelectWnd                                      0x7D4D30
#define pinstCCombatSkillSelectWnd                                 0x7D4D34
#define pinstCFriendsWnd                                           0x7D4D38
#define pinstCAuraWnd                                              0x7D4D3C
#define pinstCRespawnWnd                                           0x7D4D40
#define pinstCBandolierWnd                                         0x7D4D44
#define pinstCPotionBeltWnd                                        0x7D4D48
#define pinstCAAWnd                                                0x7D4D4C
#define pinstCGroupSearchFiltersWnd                                0x7D4D50
#define pinstCLoadskinWnd                                          0x7D4D54
#define pinstCAlarmWnd                                             0x7D4D58
#define pinstCMusicPlayerWnd                                       0x7D4D5C
#define pinstCMailWnd                                              0x7D4D64
#define pinstCMailCompositionWnd                                   0x7D4D68
#define pinstCMailAddressBookWnd                                   0x7D4D6C
#define pinstCRaidWnd                                              0x7D4D74
#define pinstCRaidOptionsWnd                                       0x7D4D78
#define pinstCBreathWnd                                            0x7D4D7C
#define pinstCMapViewWnd                                           0x7D4D80
#define pinstCMapToolbarWnd                                        0x7D4D84
#define pinstCEditLabelWnd                                         0x7D4D88
#define pinstCTargetWnd                                            0x7D4D8C
#define pinstCColorPickerWnd                                       0x7D4D90
#define pinstCPlayerWnd                                            0x7D4D94
#define pinstCOptionsWnd                                           0x7D4D98
#define pinstCBuffWindowNORMAL                                     0x7D4D9C
#define pinstCBuffWindowSHORT                                      0x7D4DA0
#define pinstCharacterCreation                                     0x7D4DA4
#define pinstCCursorAttachment                                     0x7D4DA8
#define pinstCCastingWnd                                           0x7D4DAC
#define pinstCCastSpellWnd                                         0x7D4DB0
#define pinstCSpellBookWnd                                         0x7D4DB4
#define pinstCInventoryWnd                                         0x7D4DB8
#define pinstCBankWnd                                              0x7D4DBC
#define pinstCQuantityWnd                                          0x7D4DC0
#define pinstCLootWnd                                              0x7D4DC4
#define pinstCActionsWnd                                           0x7D4DC8
#define pinstCCombatAbilityWnd                                     0x7D4DCC
#define pinstCMerchantWnd                                          0x7D4DD0
#define pinstCTradeWnd                                             0x7D4DD4
#define pinstCSelectorWnd                                          0x7D4DD8
#define pinstCBazaarWnd                                            0x7D4DDC
#define pinstCBazaarSearchWnd                                      0x7D4DE0
#define pinstCGiveWnd                                              0x7D4DE4
#define pinstCTrackingWnd                                          0x7D4DE8
#define pinstCInspectWnd                                           0x7D4DEC
#define pinstCSocialEditWnd                                        0x7D4DF0
#define pinstCFeedbackWnd                                          0x7D4DF4
#define pinstCBugReportWnd                                         0x7D4DF8
#define pinstCVideoModesWnd                                        0x7D4DFC
#define pinstCTextEntryWnd                                         0x7D4E04
#define pinstCFileSelectionWnd                                     0x7D4E08
#define pinstCCompassWnd                                           0x7D4E0C
#define pinstCPlayerNotesWnd                                       0x7D4E10
#define pinstCGemsGameWnd                                          0x7D4E14
#define pinstCTimeLeftWnd                                          0x7D4E18
#define pinstCPetitionQWnd                                         0x7D4E1C
#define pinstCSoulmarkWnd                                          0x7D4E20
#define pinstCStoryWnd                                             0x7D4E24
#define pinstCJournalTextWnd                                       0x7D4E28
#define pinstCJournalCatWnd                                        0x7D4E2C
#define pinstCBodyTintWnd                                          0x7D4E30
#define pinstCServerListWnd                                        0x7D4E34
#define pinstCAvaZoneWnd                                           0x7D4E38
#define pinstCBlockedBuffWnd                                       0x7D4E3C
#define pinstCBlockedPetBuffWnd                                    0x7D4E40
#define pinstCInvSlotMgr                                           0x7D4E44
#define pinstCContainerMgr                                         0x7D4E48
#define pinstCAdventureLeaderboardWnd                              0x90E494
#define pinstCAdventureRequestWnd                                  0x90E4B0
#define pinstCAltStorageWnd                                        0x90E510
#define pinstCAdventureStatsWnd                                    0x90E4CC
#define pinstCBarterMerchantWnd                                    0x90E6C4
#define pinstCBarterSearchWnd                                      0x90E6E0
#define pinstCBarterWnd                                            0x90E6FC
#define pinstCChatManager                                          0x90E8DC
#define pinstCDynamicZoneWnd                                       0x90E9B8
#define pinstCEQMainWnd                                            0x90EA28
#define pinstCFindLocationWnd                                      0x90EAA4
#define pinstCGroupSearchWnd                                       0x90EB78
#define pinstCGroupWnd                                             0x90EB70
#define pinstCGuildBankWnd                                         0x90EB8C
#define pinstCGuildMgmtWnd                                         0x90EBA8
#define pinstCGuildTributeMasterWnd                                0x90EBC4
#define pinstCHotButtonWnd                                         0x90EBE0
#define pinstCHotButtonWnd1                                        0x90EBE0
#define pinstCHotButtonWnd2                                        0x90EBE4
#define pinstCHotButtonWnd3                                        0x90EBE8
#define pinstCHotButtonWnd4                                        0x90EBEC
#define pinstCItemDisplayManager                                   0x90EC84
#define pinstCItemExpTransferWnd                                   0x90ECA4
#define pinstCLeadershipWnd                                        0x90ED20
#define pinstCLFGuildWnd                                           0x90ED3C
#define pinstCMIZoneSelectWnd                                      0x90EE60
#define pinstCAdventureMerchantWnd                                 0x90EF3C
#define pinstCConfirmationDialog                                   0x90EF58
#define pinstCPopupWndManager                                      0x90EF58
#define pinstCProgressionSelectionWnd                              0x90EF8C
#define pinstCPvPLeaderboardWnd                                    0x90EFA8
#define pinstCPvPStatsWnd                                          0x90EFC4
#define pinstCSystemInfoDialogBox                                  0x90F944
#define pinstCTargetOfTargetWnd                                    0x90F960
#define pinstCTaskSelectWnd                                        0x90F994
#define pinstCTaskTemplateSelectWnd                                0x90F9B0
#define pinstCTaskWnd                                              0x90F9CC
#define pinstCTicketCommentWnd                                     0x90FA00
#define pinstCHelpWnd                                              0x90FA1C
#define pinstCTipWndOFDAY                                          0x90FA50
#define pinstCTipWndCONTEXT                                        0x90FA54
#define pinstCTitleWnd                                             0x90FA70
#define pinstCTradeskillWnd                                        0x90FAB4
#define pinstCTributeBenefitWnd                                    0x90FB00
#define pinstCTributeMasterWnd                                     0x90FB1C
#define pinstCContextMenuManager                                   0x91AB74
#define pinstCVoiceMacroWnd                                        0x902E6C


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                                  0x4A4EC0
#define __ConvertItemTags                                          0x499DE0
#define __ExecuteCmd                                               0x48B5F0
#define __get_melee_range                                          0x490760
#define __GetGaugeValueFromEQ                                      0x5BE9D0
#define __GetLabelFromEQ                                           0x5BF100
#define __NewUIINI                                                 0x5BE5D0
#define __ProcessGameEvents                                        0x4CED20
#define __SendMessage                                              0x4B1880
#define CrashDetected                                              0x50F410
#define DrawNetStatus                                              0x4E30A0
#define Util__FastTime                                             0x5ECD00


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x46C250
#define AltAdvManager__IsAbilityReady                              0x46C290
#define AltAdvManager__GetAltAbility                               0x46C420

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x505AE0

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x52CBA0

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x632100

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x540300
#define CChatManager__InitContextMenu                              0x540A90

// CChatService
#define CChatService__GetNumberOfFriends                           0x60F6F0
#define CChatService__GetFriendName                                0x60F700

// CChatWindow
#define CChatWindow__CChatWindow                                   0x544BC0

// CComboWnd
#define CComboWnd__DeleteAll                                       0x6282E0
#define CComboWnd__Draw                                            0x628490
#define CComboWnd__GetCurChoice                                    0x628290
#define CComboWnd__GetListRect                                     0x628760
#define CComboWnd__GetTextRect                                     0x628310
#define CComboWnd__InsertChoice                                    0x6287D0
#define CComboWnd__SetColors                                       0x628220
#define CComboWnd__SetChoice                                       0x628250

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x54B1D0
#define CContainerWnd__vftable                                     0x6C8540

// CDisplay
#define CDisplay__CleanGameUI                                      0x45B930
#define CDisplay__GetClickedActor                                  0x459270
#define CDisplay__GetUserDefinedColor                              0x4586E0
#define CDisplay__GetWorldFilePath                                 0x457C90
#define CDisplay__ReloadUI                                         0x467740
#define CDisplay__WriteTextHD2                                     0x45D140

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x51DA50
#define CEditBaseWnd__SetSel                                       0x64A6D0

// CEditWnd
#define CEditWnd__DrawCaret                                        0x647E35
#define CEditWnd__GetCharIndexPt                                   0x648C50
#define CEditWnd__GetDisplayString                                 0x647FB0
#define CEditWnd__GetHorzOffset                                    0x648230
#define CEditWnd__GetLineForPrintableChar                          0x648710
#define CEditWnd__GetSelStartPt                                    0x648EA0
#define CEditWnd__GetSTMLSafeText                                  0x6483D0
#define CEditWnd__PointFromPrintableChar                           0x648820
#define CEditWnd__SelectableCharFromPoint                          0x6489A0
#define CEditWnd__SetEditable                                      0x6483A0

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x4B5930
#define CEverQuest__DropHeldItemOnGround                           0x4BA2D0
#define CEverQuest__dsp_chat                                       0x4BAEB0
#define CEverQuest__EnterZone                                      0x4CD910
#define CEverQuest__GetBodyTypeDesc                                0x4B3090
#define CEverQuest__GetClassDesc                                   0x4B27F0
#define CEverQuest__GetClassThreeLetterCode                        0x4B2DF0
#define CEverQuest__GetDeityDesc                                   0x4B36E0
#define CEverQuest__GetLangDesc                                    0x4B3400
#define CEverQuest__GetRaceDesc                                    0x4B36B0
#define CEverQuest__InterpretCmd                                   0x4BB7C0
#define CEverQuest__LeftClickedOnPlayer                            0x4CC5E0
#define CEverQuest__RightClickedOnPlayer                           0x4CC9A0
#define CEverQuest__SetGameState                                   0x4B5A00

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x554670
#define CGaugeWnd__CalcLinesFillRect                               0x5546E0
#define CGaugeWnd__Draw                                            0x554A70

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x568AC0

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x56FB70
#define CInvSlotMgr__MoveItem                                      0x56FD10

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x570C00

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                                   0x577AA0
#define CItemDisplayWnd__SetSpell                                  0x5BCA60

// CLabel
#define CLabel__Draw                                               0x57CF60

// CListWnd
#define CListWnd__AddColumn                                        0x628030
#define CListWnd__AddColumn1                                       0x627B60
#define CListWnd__AddLine                                          0x6276F0
#define CListWnd__AddString                                        0x6278C0
#define CListWnd__CalculateFirstVisibleLine                        0x6249E0
#define CListWnd__CalculateVSBRange                                0x626680
#define CListWnd__ClearAllSel                                      0x624130
#define CListWnd__CloseAndUpdateEditWindow                         0x625020
#define CListWnd__Compare                                          0x6253D0
#define CListWnd__Draw                                             0x626370
#define CListWnd__DrawColumnSeparators                             0x6261E0
#define CListWnd__DrawHeader                                       0x624300
#define CListWnd__DrawItem                                         0x625AE0
#define CListWnd__DrawLine                                         0x625E90
#define CListWnd__DrawSeparator                                    0x625E90
#define CListWnd__EnsureVisible                                    0x624A30
#define CListWnd__ExtendSel                                        0x625A10
#define CListWnd__GetColumnMinWidth                                0x623ED0
#define CListWnd__GetColumnWidth                                   0x623E10
#define CListWnd__GetCurSel                                        0x6238F0
#define CListWnd__GetHeaderRect                                    0x6239E0
#define CListWnd__GetItemAtPoint                                   0x624D30
#define CListWnd__GetItemAtPoint1                                  0x624DA0
#define CListWnd__GetItemData                                      0x623BC0
#define CListWnd__GetItemHeight                                    0x624770
#define CListWnd__GetItemIcon                                      0x623D50
#define CListWnd__GetItemRect                                      0x624B10
#define CListWnd__GetItemText                                      0x623C00
#define CListWnd__GetSelList                                       0x627A40
#define CListWnd__GetSeparatorRect                                 0x625310
#define CListWnd__RemoveLine                                       0x6279F0
#define CListWnd__SetColors                                        0x623950
#define CListWnd__SetColumnJustification                           0x623F30
#define CListWnd__SetColumnWidth                                   0x623E90
#define CListWnd__SetCurSel                                        0x623930
#define CListWnd__SetItemColor                                     0x6272C0
#define CListWnd__SetItemData                                      0x6241D0
#define CListWnd__SetItemText                                      0x627240
#define CListWnd__ShiftColumnSeparator                             0x625980
#define CListWnd__Sort                                             0x628060
#define CListWnd__ToggleSel                                        0x6240A0

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x58F510

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x590EE0
#define CMerchantWnd__RequestBuyItem                               0x592060
#define CMerchantWnd__RequestSellItem                              0x591140
#define CMerchantWnd__SelectBuySellSlot                            0x591D60

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x636BE0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x51F3D0
#define CSidlScreenWnd__CalculateVSBRange                          0x62D7E0
#define CSidlScreenWnd__ConvertToRes                               0x62DF30
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x62E700
#define CSidlScreenWnd__CSidlScreenWnd1                            0x62F9D0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x62FA80
#define CSidlScreenWnd__dCSidlScreenWnd                            0x62F280
#define CSidlScreenWnd__DrawSidlPiece                              0x62E420
#define CSidlScreenWnd__EnableIniStorage                           0x62DEE0
#define CSidlScreenWnd__GetSidlPiece                               0x62E5E0
#define CSidlScreenWnd__Init1                                      0x62F7E0
#define CSidlScreenWnd__LoadIniInfo                                0x62E7B0
#define CSidlScreenWnd__LoadIniListWnd                             0x62E090
#define CSidlScreenWnd__LoadSidlScreen                             0x62E250
#define CSidlScreenWnd__StoreIniInfo                               0x62DA20
#define CSidlScreenWnd__WndNotification                            0x62E380

// CSkillMgr
#define CSkillMgr__GetSkillCap                                    0x504080

// CSliderWnd
#define CSliderWnd__GetValue                                       0x64C4A0
#define CSliderWnd__SetValue                                       0x64C5A0
#define CSliderWnd__SetNumTicks                                    0x64CAE0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x5BB7C0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x641040
#define CStmlWnd__CalculateHSBRange                                0x6393F0
#define CStmlWnd__CalculateVSBRange                                0x639390
#define CStmlWnd__CanBreakAtCharacter                              0x639530
#define CStmlWnd__CanGoBackward                                    0x6395E0
#define CStmlWnd__FastForwardToEndOfTag                            0x63A030
#define CStmlWnd__GetNextTagPiece                                  0x639F50
#define CStmlWnd__GetSTMLText                                      0x544B60
#define CStmlWnd__GetThisChar                                      0x668610
#define CStmlWnd__GetVisiableText                                  0x63B250
#define CStmlWnd__InitializeWindowVariables                        0x63D3A0
#define CStmlWnd__MakeStmlColorTag                                 0x638A70
#define CStmlWnd__MakeWndNotificationTag                           0x638B10
#define CStmlWnd__StripFirstSTMLLines                              0x640DC0
#define CStmlWnd__UpdateHistoryString                              0x63BAB0

// CTabWnd
#define CTabWnd__Draw                                              0x64BD40
#define CTabWnd__DrawCurrentPage                                   0x64B730
#define CTabWnd__DrawTab                                           0x64B510
#define CTabWnd__GetCurrentPage                                    0x64B9B0
#define CTabWnd__GetPageClientRect                                 0x64B1E0
#define CTabWnd__GetPageFromTabIndex                               0x64B440
#define CTabWnd__GetPageInnerRect                                  0x64B240
#define CTabWnd__GetTabInnerRect                                   0x64B3C0
#define CTabWnd__GetTabRect                                        0x64B2D0
#define CTabWnd__IndexInBounds                                     0x64B4DD
#define CTabWnd__InsertPage                                        0x64BF60
#define CTabWnd__SetPage                                           0x64B9F0
#define CTabWnd__SetPageRect                                       0x64BC70
#define CTabWnd__UpdatePage                                        0x64BEE0

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x412570

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x62FDE0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x652950

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x623680

// CXRect
#define CXRect__CenterPoint                                        0x522F70

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x412110
#define CXStr__CXStr1                                              0x5950B0
#define CXStr__CXStr3                                              0x5EE400
#define CXStr__dCXStr                                              0x44C060
#define CXStr__operator_equal1                                     0x5EE5C0
#define CXStr__operator_plus_equal1                                0x5EF4B0

// CXWnd
#define CXWnd__BringToTop                                          0x628FD0
#define CXWnd__Center                                              0x62C5B0
#define CXWnd__ClrFocus                                            0x628CF0
#define CXWnd__DoAllDrawing                                        0x62D260
#define CXWnd__DrawChildren                                        0x62D390
#define CXWnd__DrawColoredRect                                     0x629230
#define CXWnd__DrawTooltip                                         0x62D190
#define CXWnd__DrawTooltipAtPoint                                  0x62C410
#define CXWnd__GetBorderFrame                                      0x6296B0
#define CXWnd__GetChildWndAt                                       0x62BF30
#define CXWnd__GetClientClipRect                                   0x6295F0
#define CXWnd__GetFirstChildWnd                                    0x629060
#define CXWnd__GetNextChildWnd                                     0x62BEF0
#define CXWnd__GetNextSib                                          0x629080
#define CXWnd__GetScreenClipRect                                   0x62C7D0
#define CXWnd__GetScreenRect                                       0x629860
#define CXWnd__GetTooltipRect                                      0x629470
#define CXWnd__GetWindowTextA                                      0x516C00
#define CXWnd__IsActive                                            0x642FD0
#define CXWnd__IsDescendantOf                                      0x629660
#define CXWnd__IsReallyVisible                                     0x62BED0
#define CXWnd__IsType                                              0x64D6B0
#define CXWnd__Move                                                0x62BA10
#define CXWnd__Move1                                               0x62BAB0
#define CXWnd__ProcessTransition                                   0x628F90
#define CXWnd__Refade                                              0x628D90
#define CXWnd__Resize                                              0x62C910
#define CXWnd__Right                                               0x62C720
#define CXWnd__SetFirstChildPointer                                0x629AD0
#define CXWnd__SetFocus                                            0x62AD80
#define CXWnd__SetKeyTooltip                                       0x629B40
#define CXWnd__SetMouseOver                                        0x629B10
#define CXWnd__SetNextSibPointer                                   0x629AF0
#define CXWnd__StartFade                                           0x628FF0

// CXWndManager
#define CXWndManager__DrawCursor                                   0x6444D0
#define CXWndManager__DrawWindows                                  0x6441A0
#define CXWndManager__GetFirstChildWnd                             0x643A10
#define CXWndManager__GetKeyboardFlags                             0x642CC0
#define CXWndManager__HandleKeyboardMsg                            0x643270
#define CXWndManager__RemoveWnd                                    0x643190

// CDBStr
#define CDBStr__GetString                                          0x455250

// EQ_Character
#define EQ_Character__CastRay                                      0x673BD0
#define EQ_Character__CastSpell                                    0x421740
#define EQ_Character__Cur_HP                                       0x428A70
#define EQ_Character__GetAACastingTimeModifier                     0x41C630
#define EQ_Character__GetCharInfo2                                 0x5F82C0
#define EQ_Character__GetFocusCastingTimeModifier                  0x418D70
#define EQ_Character__Max_Endurance                                0x427930
#define EQ_Character__Max_HP                                       0x4277E0
#define EQ_Character__Max_Mana                                     0x4E7F50
#define EQ_Character__doCombatAbility                              0x4E6DD0
#define EQ_Character__UseSkill                                     0x433E30
#define EQ_Character__GetConLevel                                  0x4E4450

// EQ_Item
#define EQ_Item__CanDrop                                           0x4D9D30
#define EQ_Item__GetItemLinkHash                                   0x5F7470
#define EQ_Item__IsStackable                                       0x5F8770

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar                                0x46D310
#define EQ_LoadingS__Array                                         0x70EF30

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x4EACE0
#define EQ_PC__GetAltAbilityIndex                                  0x5FCDD0
#define EQ_PC__GetCombatAbility                                    0x5FCF10
#define EQ_PC__GetCombatAbilityTimer                               0x5FCFC0
#define EQ_PC__GetItemTimerValue                                   0x4E61D0

// EQItemList
#define EQItemList__dEQItemList                                    0x48EF80
#define EQItemList__EQItemList                                     0x48EED0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x454BD0

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x4EF610
#define EQPlayer__dEQPlayer                                        0x4F39D0
#define EQPlayer__DoAttack                                         0x4FEDF0
#define EQPlayer__EQPlayer                                         0x4F6080
#define EQPlayer__SetNameSpriteState                               0x4F1C10
#define EQPlayer__SetNameSpriteTint                                0x4EF680
#define EQPlayer__IsBodyType_j                                     0x673980

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4F6E80

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4DBBB0
#define KeypressHandler__AttachKeyToEqCommand                      0x4DBBF0
#define KeypressHandler__ClearCommandStateArray                    0x4DB9C0
#define KeypressHandler__HandleKeyDown                             0x4DA5F0
#define KeypressHandler__HandleKeyUp                               0x4DA8F0
#define KeypressHandler__SaveKeymapping                            0x4DBA90

// MapViewMap
#define MapViewMap__Clear                                          0x58B550
#define MapViewMap__SaveEx                                         0x58BF20

// StringTable
#define StringTable__getString                                     0x5F3150
