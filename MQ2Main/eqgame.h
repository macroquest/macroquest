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
#define __ExpectedVersionDate                                     "Nov 14 2005" 
#define __ExpectedVersionTime                                     "08:38:18" 
#define __ActualVersionDate                                        0x64F24C
#define __ActualVersionTime                                        0x64F258

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x4B73F6
#define __MemChecker2                                              0x4CD3EE
#define __MemChecker3                                              0x4CD47B
#define __MemChecker4                                              0x601E70
#define __EncryptPad0                                              0x790418
#define __EncryptPad2                                              0x792540
#define __EncryptPad3                                              0x792940
#define __EncryptPad4                                              0x79C810

// Direct Input
#define DI8__Main                                                  0x98AEFC
#define DI8__Keyboard                                              0x98AF00
#define DI8__Mouse                                                 0x98AF04

#define __AltTimerReady                                            0x9268F2
#define __Attack                                                   0x987B47
#define __BindList                                                 0x78B908
#define __Clicks                                                   0x925AF4
#define __CommandList                                              0x78C0C8
#define __CurrentMapLabel                                          0x993F7C
#define __CurrentSocial                                            0x696D8C
#define __DoAbilityAvailable                                       0x92688C
#define __DoAbilityList                                            0x95F694
#define __DrawHandler                                              0x9A05E4
#define __EQP_IDArray                                              0x902F50
#define __FriendsList                                              0x95C434
#define __GroupCount                                               0x906248
#define __GroupLeader                                              0x9063A4
#define __Guilds                                                   0x907D38
#define __gWorld                                                   0x907CA0
#define __HotkeyPage                                               0x986A80
#define __HWnd                                                     0x9259F0
#define __IgnoreList                                               0x95DD34
#define __InChatMode                                               0x925A30
#define __LastTell                                                 0x927BA0
#define __Mouse                                                    0x98AF08
#define __MouseLook                                                0x925AC2
#define __NetStatusToggle                                          0x925AC4
#define __PCNames                                                  0x926BF8
#define __RangeAttackReady                                         0x9268F0
#define __RunWalkState                                             0x925A34
#define __ScreenMode                                               0x852508
#define __ScreenX                                                  0x9259F8
#define __ScreenY                                                  0x9259FC
#define __ServerHost                                               0x906104
#define __ServerName                                               0x95F654
#define __ShowNames                                                0x926AE0
#define __SkillDict                                                0x853200
#define __Socials                                                  0x95F754

////
//Section 1: Vital Offsets
////
#define instCRaid                                                  0x91F988
#define instEQZoneInfo                                             0x925C60
#define instKeypressHandler                                        0x987C1C
#define pinstActiveBanker                                          0x907D14
#define pinstActiveCorpse                                          0x907D18
#define pinstActiveGMaster                                         0x907D1C
#define pinstActiveMerchant                                        0x907D10
#define pinstAltAdvManager                                         0x8531D8
#define pinstBandageTarget                                         0x907CEC
#define pinstCamActor                                              0x852CC8
#define pinstCDBStr                                                0x852398
#define pinstCDisplay                                              0x907D24
#define pinstCEverQuest                                            0x98B070
#define pinstCharData                                              0x907D00
#define pinstCharSpawn                                             0x907CF8
#define pinstControlledMissile                                     0x907CFC
#define pinstControlledPlayer                                      0x907CF8
#define pinstCSidlManager                                          0x99F674
#define pinstCXWndManager                                          0x99F66C
#define pinstEQItemList                                            0x907CC8
#define pinstEQSoundManager                                        0x853390
#define instGroup                                                  0x906248
#define pinstGroup                                                 0x906390
#define pinstImeManager                                            0x99F678
#define pinstLocalPlayer                                           0x907CE4
#define pinstModelPlayer                                           0x907D20
#define pinstPCData                                                0x907D00
#define pinstSelectedItem                                          0x993DD4
#define pinstSpawnList                                             0x907CC4
#define pinstSpellManager                                          0x987F48
#define pinstSpellSets                                             0x986A84
#define pinstStringTable                                           0x907CB0
#define pinstSwitchManager                                         0x905E84
#define pinstTarget                                                0x907D04
#define pinstTargetObject                                          0x907D08
#define pinstTargetSwitch                                          0x907D0C
#define pinstTrackTarget                                           0x907CF0
#define pinstTradeTarget                                           0x907CE0
#define instTributeActive                                          0x852375
#define pinstViewActor                                             0x852CC4
#define pinstWorldData                                             0x907CC0


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                          0x79E164
#define pinstCCharacterSelect                                      0x852B9C
#define pinstCFacePick                                             0x852BA0
#define pinstCNoteWnd                                              0x852BA4
#define pinstCHelpWnd                                              0x994B28
#define pinstCBookWnd                                              0x852BA8
#define pinstCPetInfoWnd                                           0x852BAC
#define pinstCTrainWnd                                             0x852BB0
#define pinstCSkillsWnd                                            0x852BB4
#define pinstCSkillsSelectWnd                                      0x852BB8
#define pinstCCombatSkillSelectWnd                                 0x852BBC
#define pinstCFriendsWnd                                           0x852BC0
#define pinstCAAWnd                                                0x852BD0
#define pinstCGroupSearchFiltersWnd                                0x852BD4
#define pinstCLoadskinWnd                                          0x852BD8
#define pinstCAlarmWnd                                             0x852BDC
#define pinstCMusicPlayerWnd                                       0x852BE0
#define pinstCRaidWnd                                              0x852BF0
#define pinstCRaidOptionsWnd                                       0x852BF4
#define pinstCBreathWnd                                            0x852BF8
#define pinstCMapViewWnd                                           0x852BFC
#define pinstCMapToolbarWnd                                        0x852C00
#define pinstCEditLabelWnd                                         0x852C04
#define pinstCTargetWnd                                            0x852C08
#define pinstCHotButtonWnd                                         0x993D64
#define pinstCHotButtonWnd1                                        0x993D64
#define pinstCHotButtonWnd2                                        0x993D68
#define pinstCHotButtonWnd3                                        0x993D6C
#define pinstCHotButtonWnd4                                        0x993D70
#define pinstCColorPickerWnd                                       0x852C0C
#define pinstCPlayerWnd                                            0x852C10
#define pinstCOptionsWnd                                           0x852C14
#define pinstCBuffWindowNORMAL                                     0x852C18
#define pinstCBuffWindowSHORT                                      0x852C1C
#define pinstCharacterCreation                                     0x852C20
#define pinstCCursorAttachment                                     0x852C24
#define pinstCCastingWnd                                           0x852C28
#define pinstCCastSpellWnd                                         0x852C2C
#define pinstCSpellBookWnd                                         0x852C30
#define pinstCInventoryWnd                                         0x852C34
#define pinstCBankWnd                                              0x852C38
#define pinstCQuantityWnd                                          0x852C3C
#define pinstCLootWnd                                              0x852C40
#define pinstCActionsWnd                                           0x852C44
#define pinstCCombatAbilityWnd                                     0x852C48
#define pinstCMerchantWnd                                          0x852C4C
#define pinstCTradeWnd                                             0x852C50
#define pinstCSelectorWnd                                          0x852C54
#define pinstCBazaarWnd                                            0x852C58
#define pinstCBazaarSearchWnd                                      0x852C5C
#define pinstCGiveWnd                                              0x852C60
#define pinstCTrackingWnd                                          0x852C64
#define pinstCInspectWnd                                           0x852C68
#define pinstCSocialEditWnd                                        0x852C6C
#define pinstCFeedbackWnd                                          0x852C70
#define pinstCBugReportWnd                                         0x852C74
#define pinstCVideoModesWnd                                        0x852C78
#define pinstCTextEntryWnd                                         0x852C80
#define pinstCFileSelectionWnd                                     0x852C84
#define pinstCCompassWnd                                           0x852C88
#define pinstCPlayerNotesWnd                                       0x852C8C
#define pinstCGemsGameWnd                                          0x852C90
#define pinstCTimeLeftWnd                                          0x852C94
#define pinstCPetitionQWnd                                         0x852C98
#define pinstCSoulmarkWnd                                          0x852C9C
#define pinstCStoryWnd                                             0x852CA0
#define pinstCJournalTextWnd                                       0x852CA4
#define pinstCJournalCatWnd                                        0x852CA8
#define pinstCBodyTintWnd                                          0x852CAC
#define pinstCInvSlotMgr                                           0x852CB8
#define pinstCContainerMgr                                         0x852CBC
#define pinstCAdventureLeaderboardWnd                              0x993638
#define pinstCAdventureMerchantWnd                                 0x79E104
#define pinstCAdventureRequestWnd                                  0x993654
#define pinstCAdventureStatsWnd                                    0x993670
#define pinstCChatManager                                          0x993A64
#define pinstCDynamicZoneWnd                                       0x993B40
#define pinstCFindLocationWnd                                      0x993C44
#define pinstCGroupSearchWnd                                       0x993CD8
#define pinstCGroupWnd                                             0x993CF4
#define pinstCGuildMgmtWnd                                         0x993D2C
#define pinstCItemDisplayManager                                   0x993E08
#define pinstCLeadershipWnd                                        0x993EA4
#define pinstCConfirmationDialog                                   0x9940C4
#define pinstCPopupWndManager                                      0x9940C4
#define pinstCSystemInfoDialogBox                                  0x994A50
#define pinstCTargetOfTargetWnd                                    0x994A6C
#define pinstCTipWndOFDAY                                          0x994B5C
#define pinstCTipWndCONTEXT                                        0x994B60
#define pinstCTradeskillWnd                                        0x994BC0
#define pinstCTributeBenefitWnd                                    0x994C0C
#define pinstCTributeMasterWnd                                     0x994C28
#define pinstCContextMenuManager                                   0x99F694


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                                  0x476928
#define __ConvertItemTags                                          0x46DC2E
#define __ExecuteCmd                                               0x462193
#define __get_melee_range                                          0x46611B
#define __GetGaugeValueFromEQ                                      0x55A735
#define __GetLabelFromEQ                                           0x55AD2D
//#define __LoadSplashScreen                                         0x0
#define __NewUIINI                                                 0x55A3BE
#define __ProcessGameEvents                                        0x4AA442
#define __SendMessage                                              0x491AFB
#define CrashDetected                                              0x4CD0AA
#define DrawNetStatus                                              0x4B95BB
#define Util__FastTime                                             0x577B00


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x44831C
#define AltAdvManager__IsAbilityReady                              0x448350
#define AltAdvManager__GetAltAbility                               0x448488

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x4DD1D6

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x4E4F55

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x5BBDF0

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x4F35D3
#define CChatManager__InitContextMenu                              0x4F3B35

// CChatWindow
#define CChatWindow__CChatWindow                                   0x4F72C8

// CComboWnd
#define CComboWnd__DeleteAll                                       0x59CFD0
#define CComboWnd__Draw                                            0x59D1C0
#define CComboWnd__GetButtonRect                                   0x59D000
#define CComboWnd__GetCurChoice                                    0x59CF90
#define CComboWnd__GetListRect                                     0x59D460
#define CComboWnd__GetTextRect                                     0x59D050
#define CComboWnd__InsertChoice                                    0x59D4C0
#define CComboWnd__SetColors                                       0x59CF20
#define CComboWnd__SetChoice                                       0x59CF50

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x4FCB32
#define CContainerWnd__vftable                                     0x655218

// CDisplay
#define CDisplay__CleanGameUI                                      0x43B6D2
#define CDisplay__GetClickedActor                                  0x439DAF
#define CDisplay__GetUserDefinedColor                              0x43932C
#define CDisplay__GetWorldFilePath                                 0x438ADC
#define CDisplay__ReloadUI                                         0x444548
#define CDisplay__WriteTextHD2                                     0x43CB6C

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x4D8866
#define CEditBaseWnd__SetSel                                       0x5BAE50

// CEditWnd
#define CEditWnd__DrawCaret                                        0x5B8600
#define CEditWnd__GetCharIndexPt                                   0x5B93F0
#define CEditWnd__GetDisplayString                                 0x5B8790
#define CEditWnd__GetHorzOffset                                    0x5B8A00
#define CEditWnd__GetLineForPrintableChar                          0x5B8ED0
#define CEditWnd__GetSelStartPt                                    0x5B9630
#define CEditWnd__GetSTMLSafeText                                  0x5B8B90
#define CEditWnd__PointFromPrintableChar                           0x5B8FE0
#define CEditWnd__SelectableCharFromPoint                          0x5B9150
#define CEditWnd__SetEditable                                      0x5B8B60

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x4952AB
#define CEverQuest__DropHeldItemOnGround                           0x4982B2
#define CEverQuest__dsp_chat                                       0x498A84
#define CEverQuest__EnterZone                                      0x4A8DDB
#define CEverQuest__GetBodyTypeDesc                                0x492C79
#define CEverQuest__GetClassDesc                                   0x49269C
#define CEverQuest__GetClassThreeLetterCode                        0x492B16
#define CEverQuest__GetDeityDesc                                   0x492F9E
#define CEverQuest__GetRaceDesc                                    0x492F7E
#define CEverQuest__InterpretCmd                                   0x499336
#define CEverQuest__LeftClickedOnPlayer                            0x4A76CC
#define CEverQuest__RightClickedOnPlayer                           0x4A7B14
#define CEverQuest__SetGameState                                   0x495323

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x50509C
#define CGaugeWnd__CalcLinesFillRect                               0x5050F8
#define CGaugeWnd__Draw                                            0x5053F8

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x5151F0

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x51B88D
#define CInvSlotMgr__MoveItem                                      0x51B9E8

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                                   0x522856
#define CItemDisplayWnd__SetSpell                                  0x51EA65

// CLabel
#define CLabel__Draw                                               0x526EB8

// CListWnd
#define CListWnd__AddColumn                                        0x59CD30
#define CListWnd__AddColumn1                                       0x59C860
#define CListWnd__AddLine                                          0x59C3F0
#define CListWnd__AddString                                        0x59C5C0
#define CListWnd__CalculateFirstVisibleLine                        0x599930
#define CListWnd__CalculateVSBRange                                0x59B470
#define CListWnd__ClearAllSel                                      0x599170
#define CListWnd__CloseAndUpdateEditWindow                         0x599F50
#define CListWnd__Compare                                          0x59A2C0
#define CListWnd__Draw                                             0x59B180
#define CListWnd__DrawColumnSeparators                             0x59B000
#define CListWnd__DrawHeader                                       0x599340
#define CListWnd__DrawItem                                         0x59A9D0
#define CListWnd__DrawLine                                         0x59AD40
#define CListWnd__DrawSeparator                                    0x59B0A0
#define CListWnd__EnsureVisible                                    0x599980
#define CListWnd__ExtendSel                                        0x59A900
#define CListWnd__GetColumnFlags                                   0x598D10
#define CListWnd__GetColumnJustification                           0x598E80
#define CListWnd__GetColumnMinWidth                                0x598E20
#define CListWnd__GetColumnWidth                                   0x598D60
#define CListWnd__GetCurSel                                        0x5987F0
#define CListWnd__GetHeaderRect                                    0x5988E0
#define CListWnd__GetItemAtPoint                                   0x599C60
#define CListWnd__GetItemAtPoint1                                  0x599CD0
#define CListWnd__GetItemData                                      0x598AC0
#define CListWnd__GetItemHeight                                    0x5996D0
#define CListWnd__GetItemIcon                                      0x598C50
#define CListWnd__GetItemRect                                      0x599A50
#define CListWnd__GetItemText                                      0x598B00
#define CListWnd__GetSelList                                       0x59C740
#define CListWnd__GetSeparatorRect                                 0x59A210
#define CListWnd__IsLineEnabled                                    0x599250
#define CListWnd__RemoveLine                                       0x59C6F0
#define CListWnd__SetColors                                        0x598850
#define CListWnd__SetColumnJustification                           0x598ED0
#define CListWnd__SetColumnWidth                                   0x598DE0
#define CListWnd__SetCurSel                                        0x598830
#define CListWnd__SetItemColor                                     0x59BFD0
#define CListWnd__SetItemData                                      0x599210
#define CListWnd__SetItemText                                      0x59BF50
#define CListWnd__ShiftColumnSeparator                             0x59A870
#define CListWnd__Sort                                             0x59CD60
#define CListWnd__ToggleSel                                        0x5990E0

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x536CFD

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x53832B
#define CMerchantWnd__RequestBuyItem                               0x5392BD
#define CMerchantWnd__RequestSellItem                              0x53852A
#define CMerchantWnd__SelectBuySellSlot                            0x539021

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x5B6930

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x5A2260
#define CSidlScreenWnd__CalculateVSBRange                          0x5A21A0
#define CSidlScreenWnd__ConvertToRes                               0x5A29A0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x5A31C0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x5A4430
#define CSidlScreenWnd__CSidlScreenWnd2                            0x5A44E0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x5A3CE0
#define CSidlScreenWnd__DrawSidlPiece                              0x5A2EE0
#define CSidlScreenWnd__EnableIniStorage                           0x5A2950
#define CSidlScreenWnd__GetSidlPiece                               0x5A30A0
#define CSidlScreenWnd__Init1                                      0x5A4250
#define CSidlScreenWnd__LoadIniInfo                                0x5A3270
#define CSidlScreenWnd__LoadIniListWnd                             0x5A2B00
#define CSidlScreenWnd__LoadSidlScreen                             0x5A2D40
#define CSidlScreenWnd__SetScreen                                  0x5A3DF0
#define CSidlScreenWnd__StoreIniInfo                               0x5A24A0
#define CSidlScreenWnd__WndNotification                            0x5A2E40

// CSliderWnd
#define CSliderWnd__GetValue                                       0x5BD840
#define CSliderWnd__SetValue                                       0x5BD9C0
#define CSliderWnd__UpdateThumb                                    0x5BD800

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x558B74

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x5ACEA0
#define CStmlWnd__CalculateHSBRange                                0x5A56B0
#define CStmlWnd__CalculateVSBRange                                0x5A5650
#define CStmlWnd__CanBreakAtCharacter                              0x5A57F0
#define CStmlWnd__CanGoBackward                                    0x5A58D0
#define CStmlWnd__FastForwardToEndOfTag                            0x5A6350
#define CStmlWnd__GetNextChar                                      0x5A5D10
#define CStmlWnd__GetNextTagPiece                                  0x5A6270
#define CStmlWnd__GetSTMLText                                      0x4F72AA
#define CStmlWnd__GetThisChar                                      0x5DA690
#define CStmlWnd__GetVisiableText                                  0x5A7490
#define CStmlWnd__InitializeWindowVariables                        0x5A95E0
#define CStmlWnd__MakeStmlColorTag                                 0x5A4CD0
#define CStmlWnd__MakeWndNotificationTag                           0x5A4D70
#define CStmlWnd__StripFirstSTMLLines                              0x5ACC30
#define CStmlWnd__UpdateHistoryString                              0x5A7CF0

// CTabWnd
#define CTabWnd__Draw                                              0x5BD2F0
#define CTabWnd__DrawCurrentPage                                   0x5BCDB0
#define CTabWnd__DrawTab                                           0x5BCBB0
#define CTabWnd__GetCurrentPage                                    0x5BD040
#define CTabWnd__GetCurrentTabIndex                                0x5BC870
#define CTabWnd__GetNumTabs                                        0x5BC860
#define CTabWnd__GetPageClientRect                                 0x5BC880
#define CTabWnd__GetPageFromTabIndex                               0x5BCB00
#define CTabWnd__GetPageInnerRect                                  0x5BC8E0
#define CTabWnd__GetTabInnerRect                                   0x5BCA80
#define CTabWnd__GetTabRect                                        0x5BC990
#define CTabWnd__IndexInBounds                                     0x5BC970
#define CTabWnd__InsertPage                                        0x5BD4F0
#define CTabWnd__SetPage                                           0x5BD050
#define CTabWnd__SetPageRect                                       0x5BD240
#define CTabWnd__UpdatePage                                        0x5BD470

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x4081EF

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x5A4860

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x5C3DB0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x5985A0

// CXRect
#define CXRect__CenterPoint                                        0x4DC9D2

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x407E28
#define CXStr__CXStr1                                              0x4013E2
#define CXStr__CXStr3                                              0x572B40
#define CXStr__dCXStr                                              0x4013E8
#define CXStr__operator_equal1                                     0x572D00
#define CXStr__operator_plus_equal1                                0x573B40

// CXWnd
#define CXWnd__BringToTop                                          0x59DC80
#define CXWnd__Center                                              0x5A1090
#define CXWnd__ClrFocus                                            0x59D9C0
#define CXWnd__DoAllDrawing                                        0x5A1C80
#define CXWnd__DrawChildren                                        0x5A1DB0
#define CXWnd__DrawColoredRect                                     0x59DEF0
#define CXWnd__DrawTooltipAtPoint                                  0x5A0F00
#define CXWnd__GetBorderFrame                                      0x59E3A0
#define CXWnd__GetChildWndAt                                       0x5A0B10
#define CXWnd__GetClientClipRect                                   0x59E2D0
#define CXWnd__GetFirstChildWnd                                    0x59DD10
#define CXWnd__GetNextChildWnd                                     0x5A0AF0
#define CXWnd__GetNextSib                                          0x59DD30
#define CXWnd__GetScreenClipRect                                   0x5A1320
#define CXWnd__GetScreenRect                                       0x59E570
#define CXWnd__GetTooltipRect                                      0x59E140
#define CXWnd__GetWindowTextA                                      0x4D2C81
#define CXWnd__IsActive                                            0x59E340
#define CXWnd__IsDescendantOf                                      0x59E350
#define CXWnd__IsReallyVisible                                     0x5A0AD0
#define CXWnd__IsType                                              0x5A1C20
#define CXWnd__Move                                                0x5A0680
#define CXWnd__Move1                                               0x5A0710
#define CXWnd__ProcessTransition                                   0x59DC40
#define CXWnd__Refade                                              0x59DA70
#define CXWnd__Resize                                              0x5A1460
#define CXWnd__Right                                               0x5A1200
#define CXWnd__SetFirstChildPointer                                0x59E7C0
#define CXWnd__SetFocus                                            0x59FA00
#define CXWnd__SetKeyTooltip                                       0x59E800
#define CXWnd__SetMouseOver                                        0x59E7E0
#define CXWnd__SetNextSibPointer                                   0x59E7D0
#define CXWnd__StartFade                                           0x59DCA0

// CXWndManager
#define CXWndManager__DrawCursor                                   0x5B01A0
#define CXWndManager__DrawWindows                                  0x5AFE70
#define CXWndManager__GetFirstChildWnd                             0x5AF780
#define CXWndManager__GetKeyboardFlags                             0x5AEB80
#define CXWndManager__HandleKeyboardMsg                            0x5AF050
#define CXWndManager__RemoveWnd                                    0x5AEF60

// CDBStr
#define CDBStr__GetString                                          0x435DA2

// EQ_Character
#define EQ_Character__CastSpell                                    0x4120A7
#define EQ_Character__Cur_HP                                       0x418001
#define EQ_Character__GetAACastingTimeModifier                     0x40E40F
#define EQ_Character__GetCharInfo2                                 0x5ECE70
#define EQ_Character__GetFocusCastingTimeModifier                  0x40D7A0
#define EQ_Character__Max_Endurance                                0x416BB4
#define EQ_Character__Max_HP                                       0x416ACD
#define EQ_Character__Max_Mana                                     0x4BCC41
#define EQ_Character__doCombatAbility                              0x4BBB82

// EQ_Item
#define EQ_Item__CanDrop                                           0x4B26D5
#define EQ_Item__GetItemLinkHash                                   0x5E4460
#define EQ_Item__IsStackable                                       0x5ED3B0

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD                                   0x448ADE

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x4BEDF5
#define EQ_PC__GetItemTimerValue                                   0x4BB408

// EQItemList
#define EQItemList__dEQItemList                                    0x464EE1
#define EQItemList__EQItemList                                     0x464E65

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x47B160
#define EQPlayer__dEQPlayer                                        0x4850D5
#define EQPlayer__DoAttack                                         0x48309E
#define EQPlayer__EQPlayer                                         0x4857C3
#define EQPlayer__SetNameSpriteState                               0x47D69F
#define EQPlayer__SetNameSpriteTint                                0x47B1CC

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4B3F46
#define KeypressHandler__AttachKeyToEqCommand                      0x4B3F13
#define KeypressHandler__ClearCommandStateArray                    0x4B3D5B
#define KeypressHandler__HandleKeyDown                             0x4B2BB6
#define KeypressHandler__HandleKeyUp                               0x4B2E2D
#define KeypressHandler__SaveKeymapping                            0x4B3DE3

// MapViewMap
#define MapViewMap__Clear                                          0x533463
#define MapViewMap__SaveEx                                         0x533C20

// StringTable
#define StringTable__getString                                     0x5E0620
