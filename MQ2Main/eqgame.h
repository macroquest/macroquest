#ifdef PRIVATE
#include "eqgame-private.h"
#endif

#define pinstCContextMenuManager                                0x79CD5C
#define pinstCCursorAttachment                                  0x615EA0
#define pinstCSocialEditWnd                                     0x615EE8
#define pinstCContainerMgr                                      0x615F2C
#define pinstCChatManager                                       0x7916D8
#define pinstCConfirmationDialog                                0x615E24
#define pinstCFacePick                                          0x615E2C
#define pinstCInvSlotMgr                                        0x615F28
#define pinstCPopupWndManager                                   0x791B14
#define pinstCNoteWnd                                           0x615E30
#define pinstCHelpWnd                                           0x615E34
#define pinstCTipWndOFDAY                                       0x7923E8
#define pinstCTipWndCONTEXT                                     0x7923EC
#define pinstCBookWnd                                           0x615E38
#define pinstCFriendsWnd                                        0x615E50
#define pinstCMusicPlayerWnd                                    0x615E64
#define pinstCAlarmWnd                                          0x615E60
#define pinstCLoadskinWnd                                       0x615E5C
#define pinstCPetInfoWnd                                        0x615E3C
#define pinstCTrainWnd                                          0x615E40
#define pinstCSkillsWnd                                         0x615E44
#define pinstCSkillsSelectWnd                                   0x615E48
#define pinstCCombatSkillSelectWnd                              0x615E4C
#define pinstCAAWnd                                             0x615E54
#define pinstCGroupWnd                                          0x7918B0
#define pinstCSystemInfoDialogBox                               0x792394
#define pinstCGroupSearchWnd                                    0x791898
#define pinstCGroupSearchFiltersWnd                             0x615E58
#define pinstCRaidWnd                                           0x615E68
#define pinstCRaidOptionsWnd                                    0x615E6C
#define pinstCBreathWnd                                         0x615E70
#define pinstCMapToolbarWnd                                     0x615E78
#define pinstCMapViewWnd                                        0x615E74
#define pinstCEditLabelWnd                                      0x615E7C
#define pinstCOptionsWnd                                        0x615E90
#define pinstCBuffWindowSHORT                                   0x615E94
#define pinstCBuffWindowNORMAL                                  0x615E98
#define pinstCTargetWnd                                         0x615E80
#define pinstCColorPickerWnd                                    0x615E88
#define pinstCHotButtonWnd                                      0x615E84
#define pinstCPlayerWnd                                         0x615E8C
#define pinstCCastingWnd                                        0x615EA4
#define pinstCCastSpellWnd                                      0x615EA8
#define pinstCSpellBookWnd                                      0x615EAC
#define pinstCInventoryWnd                                      0x615EB0
#define pinstCBankWnd                                           0x615EB4
#define pinstCQuantityWnd                                       0x615EB8
#define pinstCTextEntryWnd                                      0x615EF8
#define pinstCFileSelectionWnd                                  0x615EFC
#define pinstCLootWnd                                           0x615EBC
#define pinstCActionsWnd                                        0x615EC0
#define pinstCCombatAbilityWnd                                  0x615EC4
#define pinstCMerchantWnd                                       0x615EC8
#define pinstCTradeWnd                                          0x615ECC
#define pinstCBazaarWnd                                         0x615ED4
#define pinstCBazaarSearchWnd                                   0x615ED8
#define pinstCGiveWnd                                           0x615EDC
#define pinstCSelectorWnd                                       0x615ED0
#define pinstCTrackingWnd                                       0x615EE0
#define pinstCInspectWnd                                        0x615EE4
#define pinstCFeedbackWnd                                       0x615EEC
#define pinstCBugReportWnd                                      0x615EF0
#define pinstCVideoModesWnd                                     0x615EF4
#define pinstCCompassWnd                                        0x615F00
#define pinstCPlayerNotesWnd                                    0x615F04
#define pinstCGemsGameWnd                                       0x615F08
#define pinstCStoryWnd                                          0x615F18
#define pinstCFindLocationWnd                                   0x79181C
#define pinstCAdventureRequestWnd                               0x791470
#define pinstCAdventureMerchantWnd                              0x791458
#define pinstCAdventureStatsWnd                                 0x791488
#define pinstCAdventureLeaderboardWnd                           0x791440
#define pinstCLeadershipWindow                                  0x7919C4
#define pinstCBodyTintWnd                                       0x615F24
#define pinstCGuildMgmtWnd                                      0x7918C8
#define pinstCJournalTextWnd                                    0x615F1C
#define pinstCJournalCatWnd                                     0x615F20
#define pinstCTributeBenefitWnd                                 0x792458
#define pinstCTributeMasterWnd                                  0x792470
#define pinstCPetitionQWnd                                      0x615F10
#define pinstCSoulmarkWnd                                       0x615F14
#define pinstCTimeLeftWnd                                       0x615F0C

/*
#define pinstCContextMenuManager                        0x0079cd5c 
#define pinstCCursorAttachment                          0x00615ea0 
#define pinstCSocialEditWnd                             0x00615ee8 
#define pinstCInvSlotMgr                                0x00615f28 
#define pinstCContainerMgr                              0x00615f2c 
#define pinstCChatManager                               0x007916d8 
#define pinstCConfirmationDialog                        0x00615e28 
#define pinstCFacePick                                  0x00615e2c 
#define pinstCItemDisplayMgr                            0x00791970 
#define pinstCSpellDisplayMgr                           0x00791b14 
#define pinstCNoteWnd                                   0x00615e30 
#define pinstCHelpWnd                                   0x00615e34 
#define pinstCTipWndOFDAY                               0x007923e8 
#define pinstCTipWndCONTEXT                             0x007923ec 
#define pinstCBookWnd                                   0x00615e38 
#define pinstCFriendsWnd                                0x00615e50 
#define pinstCMusicPlayerWnd                            0x00615e64 
#define pinstCAlarmWnd                                  0x00615e60 
#define pinstCLoadskinWnd                               0x00615e5c 
#define pinstCPetInfoWnd                                0x00615e3c 
#define pinstCTrainWnd                                  0x00615e40 
#define pinstCSkillsWnd                                 0x00615e44 
#define pinstCSkillsSelectWnd                           0x00615e48 
#define pinstCAAWnd                                     0x00615e50 
#define pinstCGroupWnd                                  0x007918b0 
#define pinstCJournalNPCWnd                             0x00792394 
#define pinstCGroupSearchWnd                            0x00791898 
#define pinstCGroupSearchFiltersWnd                     0x00651e58 
#define pinstCRaidWnd                                   0x00615e68 
#define pinstCRaidOptionsWnd                            0x00615e6c 
#define pinstCBreathWnd                                 0x00615e70 
#define pinstCMapToolbarWnd                             0x00615e78 
#define pinstCMapViewWnd                                0x00615e74 
#define pinstCEditLabelWnd                              0x00615e7c 
#define pinstCOptionsWnd                                0x00615e90 
#define pinstCBuffWindowSHORT                           0x00615e94 
#define pinstCBuffWindowNORMAL                          0x00615e98 
#define pinstCTargetWnd                                 0x00615e80 
#define pinstCColorPickerWnd                            0x00615e88 
#define pinstCHotButtonWnd                              0x00615e84 
#define pinstCPlayerWnd                                 0x00615e8c 
#define pinstCCastingWnd                                0x00615ea4 
#define pinstCCastSpellWnd                              0x00615ea8 
#define pinstCSpellBookWnd                              0x00615eac 
#define pinstCInventoryWnd                              0x00615eb0 
#define pinstCBankWnd                                   0x00615eb4 
#define pinstCQuantityWnd                               0x00615eb8 
#define pinstCTextEntryWnd                              0x00615ef8 
#define pinstCFileSelectionWnd                          0x00615efc 
#define pinstCLootWnd                                   0x00615ebc 
#define pinstCActionsWnd                                0x00615ec0 
#define pinstCMerchantWnd                               0x00615ec8 
#define pinstCTradeWnd                                  0x00615ecc 
#define pinstCBazaarWnd                                 0x00615ed4 
#define pinstCBazaarSearchWnd                           0x00615ed8 
#define pinstCGiveWnd                                   0x00615edc 
#define pinstCSelectorWnd                               0x00615ed0 
#define pinstCTrackingWnd                               0x00615ee0 
#define pinstCInspectWnd                                0x00615ee4 
#define pinstCFeedbackWnd                               0x00615eec 
#define pinstCBugReportWnd                              0x00615ef0 
#define pinstCVideoModesWnd                             0x00615ef4 
#define pinstCCompassWnd                                0x00615f00 
#define pinstCPlayerNotesWnd                            0x00615f04 
#define pinstCGemsGameWnd                               0x00615f08 
#define pinstCStoryWnd                                  0x00615f18 
#define pinstCFindLocationWnd                           0x0079181c 
#define pinstCAdventureRequestWnd                       0x00791470 
#define pinstCAdventureStatsWnd                         0x00791488 
#define pinstCAdventureLeaderboardWnd                   0x00791440 
#define pinstCBodyTintWnd                               0x00615f24 
#define pinstCGuildMgmtWnd                              0x007918c8 
#define pinstCJournalTextWnd                            0x00615f1c 
#define pinstCJournalCatWnd                             0x00615f20 
#define pinstCPetitionQWnd                              0x00615f10 
#define pinstCSoulmarkWnd                               0x00615f14 
#define pinstCTimeLeftWnd                               0x00615f0c 
/**/

#define pinstCSidlManager           0x0079cd40 
#define pinstCDisplay               0x0072b7cc 
#define pinstCEverQuest               0x00788de0 
#define pinstPCData               0x0072b7a8 
#define pinstCharData               0x0072b7a8 
#define pinstCharSpawn                 0x0072b7a0 
#define pinstSpawnList               0x0072b768 
#define pinstSpawnListTail            0x0072b78c 
#define pinstWorldData               0x0072b764 
#define pinstSpellManager            0x0078583c 
#define pinstActiveMerchant          0x0072b7b8 
#define pinstSelectedItem            0x00791944 
#define pinstGroup               0x00729e38 
#define pinstTarget               0x0072b7ac 
#define pinstSwitchManager            0x006c8f5c 
#define pinstEQItemList                0x0072b76c 
#define pinstSpellSets               0x0072956c 

#define instEQZoneInfo               0x006c91dc 


// Static functions
#define DrawNetStatus                            0x4AC857 
#define CrashDetected							 0x4BCA27

// EQ_LoadingS
#define EQ_LoadingS__WriteTextHD				 0x4314D4

// CEverQuest 
#define CEverQuest__dsp_chat                     0x497105 
#define CEverQuest__ClickedPlayer                0x492D89
#define CEverQuest__EnterZone                    0x497F51
#define CEverQuest__InterpretCmd                 0x4A1D74
#define CEverQuest__RightClickedOnPlayer         0x49DC53
#define CEverQuest__LeftClickedOnPlayer          0x4A3F40
#define CEverQuest__GetRaceDesc                  0x48CF19
#define CEverQuest__GetClassDesc                 0x48C6B7
#define CEverQuest__GetDeityDesc                 0x48E597
#define CEverQuest__GetBodyTypeDesc              0x48CC11
#define CEverQuest__SetGameState                 0x492EF0

// EQ_Character 
#define EQ_Character__Max_Mana                   0x41CEF2
#define EQ_Character__Max_HP                     0x41CCF1
#define EQ_Character__Cur_HP                     0x420987
#define EQ_Character__GetFocusCastingTimeModifier 0x427E9C
#define EQ_Character__GetAACastingTimeModifier   0x428206
#define EQ_Character__CastSpell                  0x42BBEC

// CXStr 
#define CXStr__CXStr                             0x401046
#define CXStr__CXStr1				             0x5066F5 
#define CXStr__CXStr3                            0x591BC0
#define CXStr__dCXStr							     0x401070
#define CXStr__operator_plus_equal1              0x592C50
#define CXStr__operator_equal1                   0x591D80

// CStmlWnd 
#define CStmlWnd__AppendSTML                     0x56C720

// CChatWindow 
#define CChatWindow__CChatWindow                 0x4DA9CC
#define CChatWindow__dCChatWindow                0x4B2C4E

// CChatManager 
#define CChatManager__InitContextMenu            0x4D7EF4
#define CChatManager__GetRGBAFromIndex           0x4D7590

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot				 0x4F46F1

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                 0x4F7068
#define CItemDisplayWnd__SetSpell				 0x4F6677

// CLabel 
#define CLabel__Draw                             0x4FCE5D

// CDisplay 
#define CDisplay__ReloadUI                       0x417ECD
#define CDisplay__CleanGameUI                    0x4113AE
#define CDisplay__GetClickedActor                0x40D1AC
#define CDisplay__WriteTextHD2                   0x411D68 
#define CDisplay__GetWorldFilePath				 0x40B894

// EQ_Item
#define EQ_Item__GetItemLinkHash                 0x430F37 

// CBankWnd 
#define CBankWnd__GetNumBankSlots                0x4C7611

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg        0x4C9BB1

// CMerchantWnd 
#define CMerchantWnd__SelectBuySellSlot          0x505062
#define CMerchantWnd__RequestBuyItem             0x50497D
#define CMerchantWnd__RequestSellItem            0x504B76
#define CMerchantWnd__DisplayBuyOrSellPrice		 0x5047BE

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet               0x515E39 

// MapViewMap 
#define MapViewMap__SaveEx                       0x4FFE91
#define EQ_PC__DestroyHeldItemOrMoney            0x434211

// CSidlScreenWnd 
#define CSidlScreenWnd__CSidlScreenWnd1          0x547080
#define CSidlScreenWnd__dCSidlScreenWnd          0x546720 
#define CSidlScreenWnd__CreateChildrenFromSidl   0x545AA0
#define CSidlScreenWnd__GetChildItem             0x545370 
#define CSidlScreenWnd__WndNotification          0x545620
#define CSidlScreenWnd__CalculateHSBRange        0x544B40
#define CSidlScreenWnd__CalculateVSBRange        0x544C00
#define CSidlScreenWnd__ConvertToRes             0x5452F0
#define CSidlScreenWnd__CSidlScreenWnd2          0x547170
#define CSidlScreenWnd__DrawBackground           0x5468B0
#define CSidlScreenWnd__DrawSidlPiece            0x5456C0
#define CSidlScreenWnd__EnableIniStorage         0x5452A0
#define CSidlScreenWnd__GetSidlPiece             0x545960
#define CSidlScreenWnd__HandleRButtonDown        0x5453E0
#define CSidlScreenWnd__Init1                    0x546DD0
#define CSidlScreenWnd__LoadIniInfo              0x545B50
#define CSidlScreenWnd__LoadIniListWnd           0x546480
#define CSidlScreenWnd__LoadSidlScreen           0x545550
#define CSidlScreenWnd__OnResize                 0x544CB0
#define CSidlScreenWnd__SetScreen                0x546840
#define CSidlScreenWnd__StoreIniInfo             0x544E30
#define CSidlScreenWnd__StoreIniListWnd          0x546530

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1   0x561890

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead             0x552E70

// CXWnd
#define CXWnd__Bottom                            0x54ADB0
#define CXWnd__BringToTop                        0x547630
#define CXWnd__Center                            0x54AE00
#define CXWnd__ClrFocus                          0x547570
#define CXWnd__Deactivate                        0x544E20
#define CXWnd__DoAllDrawing                      0x54B860
#define CXWnd__DrawBackground                    0x54AB30
#define CXWnd__DrawChildren                      0x54BA10
#define CXWnd__DrawCloseBox                      0x5495D0
#define CXWnd__DrawColoredRect                   0x547840
#define CXWnd__DrawCursor                        0x5475E0
#define CXWnd__DrawHScrollbar                    0x549D10
#define CXWnd__DrawLasso                         0x54A9F0
#define CXWnd__DrawMinimizeBox                   0x549410
#define CXWnd__DrawNC                            0x54B4E0
#define CXWnd__DrawTileBox                       0x5494F0
#define CXWnd__DrawTitleBar                      0x5496B0
#define CXWnd__DrawTooltip                       0x54B780
#define CXWnd__DrawTooltipAtPoint                0x54ABE0
#define CXWnd__DrawVScrollbar                    0x549910
#define CXWnd__GetBorderFrame                    0x547C90
#define CXWnd__GetChildWndAt                     0x54A850
#define CXWnd__GetClientClipRect                 0x547BE0
#define CXWnd__GetClientRect                     0x403D02
#define CXWnd__GetCloseBoxTemplate               0x547CF0
#define CXWnd__GetCursorToDisplay                0x547700
#define CXWnd__GetDragDropCursor                 0x547B90
#define CXWnd__GetFirstChildWnd                  0x5476C0
#define CXWnd__GetHitTestRect                    0x548680
#define CXWnd__GetInnerRect                      0x403CFD
#define CXWnd__GetMinimizeBoxTemplate            0x547D20
#define CXWnd__GetMinimizedRect                  0x54A3C0
#define CXWnd__GetMinSize                        0x403D34
#define CXWnd__GetNextChildWnd                   0x54A830
#define CXWnd__GetNextSib                        0x5476E0
#define CXWnd__GetScreenClipRect                 0x54B020
#define CXWnd__GetScreenRect                     0x547E60
#define CXWnd__GetTileBoxTemplate                0x547D40
#define CXWnd__GetTooltip                        0x5475C0
#define CXWnd__GetTooltipRect                    0x547A50
#define CXWnd__GetUntileSize                     0x403CE3
#define CXWnd__GetWindowTextA                    0x4C2086
#define CXWnd__GetXMLTooltip                     0x5473B0
#define CXWnd__HitTest                           0x54A8D0
#define CXWnd__IsActive                          0x547C50
#define CXWnd__IsDescendantOf                    0x547C60
#define CXWnd__IsReallyVisible                   0x547690
#define CXWnd__IsType                            0x54B800
#define CXWnd__IsValid                           0x403CBC
#define CXWnd__Left                              0x54AF80
#define CXWnd__Move                              0x54A230
#define CXWnd__Move1                             0x54A2C0
#define CXWnd__PostDraw                          0x4F219C
#define CXWnd__ProcessTransition                 0x54A410
#define CXWnd__QueryClickStickDropOK             0x547BA0
#define CXWnd__QueryDropOK                       0x547B50
#define CXWnd__Refade                            0x547610
#define CXWnd__RequestDockInfo                   0x548600
#define CXWnd__Resize                            0x54B150
#define CXWnd__Right                             0x54AED0
#define CXWnd__SetAttributesFromSidl             0x54B090
#define CXWnd__SetFirstChildPointer              0x5480B0
#define CXWnd__SetFocus                          0x549300
#define CXWnd__SetKeyTooltip                     0x5480F0
#define CXWnd__SetMouseOver                      0x5480D0
#define CXWnd__SetNextSibPointer                 0x5480C0
#define CXWnd__SetVScrollPos                     0x547A10
#define CXWnd__StartFade                         0x547650

// CSliderWnd
#define CSliderWnd__GetValue                     0x576A50
#define CSliderWnd__SetValue                     0x576C30
#define CSliderWnd__UpdateThumb                  0x576A30

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                0x4C70EA
#define CEditBaseWnd__SetSel                     0x56D1D0

// CComboWnd
#define CComboWnd__DeleteAll                     0x572170
#define CComboWnd__Draw                          0x572370
#define CComboWnd__GetButtonRect                 0x5721A0
#define CComboWnd__GetCurChoice                  0x572130
#define CComboWnd__GetListRect                   0x572760
#define CComboWnd__GetTextRect                   0x572200
#define CComboWnd__HitTest                       0x4CDDB0
#define CComboWnd__InsertChoice                  0x5727C0
#define CComboWnd__SetColors					 0x572100
// CListWnd
#define CListWnd__AddLine                        0x556DD0
#define CListWnd__AddString                      0x556F50
#define CListWnd__CalculateFirstVisibleLine      0x554410
#define CListWnd__CalculateLineHeights           0x5543B0
#define CListWnd__CalculateVSBRange              0x555F80
#define CListWnd__ClearAllSel                    0x553C40
#define CListWnd__CloseAndUpdateEditWindow       0x554A10
#define CListWnd__Compare                        0x554D50
#define CListWnd__Draw                           0x555BE0
#define CListWnd__DrawBackground                 0x5533D0
#define CListWnd__DrawColumnSeparators           0x567AB0
#define CListWnd__DrawHeader                     0x555B10
#define CListWnd__DrawItem                       0x555542
#define CListWnd__DrawLine                       0x5557B0
#define CListWnd__DrawSeparator                  0x518E9E
#define CListWnd__EnsureVisible                  0x554460
#define CListWnd__ExtendSel                      0x555390
#define CListWnd__GetColumnFlags                 0x553710
#define CListWnd__GetColumnMinWidth              0x553840
#define CListWnd__GetColumnWidth                 0x553770
#define CListWnd__GetCurSel                      0x553550
#define CListWnd__GetCursorToDisplay             0x553460
#define CListWnd__GetHeaderRect                  0x553390
#define CListWnd__GetItemAtPoint                 0x554710
#define CListWnd__GetItemAtPoint1                0x554780
#define CListWnd__GetItemData                    0x553590
#define CListWnd__GetItemHeight                  0x554240
#define CListWnd__GetItemIcon                    0x553650
#define CListWnd__GetItemRect                    0x554530
#define CListWnd__GetItemText                    0x5535D0
#define CListWnd__GetSelList                     0x5570F0
#define CListWnd__GetSeparatorRect               0x554CA0
#define CListWnd__IsLineEnabled                  0x553D30
#define CListWnd__SetColors                      0x553300
#define CListWnd__SetColumnWidth                 0x5537F0
#define CListWnd__SetCurSel                      0x553B60
#define CListWnd__SetItemColor                   0x556A10
#define CListWnd__SetItemData                    0x553CF0
#define CListWnd__SetItemText                    0x556950
#define CListWnd__SetVScrollPos                  0x554EF0
#define CListWnd__ShiftColumnSeparator           0x555300
#define CListWnd__Sort                           0x5632F0
#define CListWnd__ToggleSel                      0x553B80

// CEditWnd
#define CEditWnd__DrawCaret                      0x572C00
#define CEditWnd__DrawMultiline                  0x5842C0
#define CEditWnd__GetCaretPt                     0x5744F0
#define CEditWnd__GetCharIndexPt                 0x573A40
#define CEditWnd__GetDisplayString               0x562C50
#define CEditWnd__GetHorzOffset                  0x58AD80
#define CEditWnd__GetLineForPrintableChar        0x5734F0
#define CEditWnd__GetSelEndPt                    0x573C80
#define CEditWnd__GetSelStartPt                  0x573C60
#define CEditWnd__GetSTMLSafeText                0x5731B0
#define CEditWnd__PointFromPrintableChar         0x573600
#define CEditWnd__SelectableCharFromPoint        0x57D340
#define CEditWnd__SetEditable                    0x573180
#define CEditWnd__SetWindowTextA                 0x57C510

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                  0x4E5D31
#define CGaugeWnd__CalcLinesFillRect             0x4E5D8D
#define CGaugeWnd__Draw                          0x4E608D
#define CGaugeWnd__SetAttributesFromSidl         0x516CF3

// CStmlWnd
#define CStmlWnd__CalculateHSBRange              0x5641C0
#define CStmlWnd__CalculateVSBRange              0x564160
#define CStmlWnd__CanBreakAtCharacter            0x564300
#define CStmlWnd__CanGoBackward                  0x564380
#define CStmlWnd__FastForwardPastSpaces          0x564D30
#define CStmlWnd__FastForwardToEndOfTag          0x565090
#define CStmlWnd__GetCursorToDisplay             0x567AE0
#define CStmlWnd__GetNextChar                    0x5647B0
#define CStmlWnd__GetNextTagPiece                0x564EA0
#define CStmlWnd__GetSTMLText                    0x4DA9AE
#define CStmlWnd__GetThisChar                    0x564020
#define CStmlWnd__GetVisiableText                0x519689
#define CStmlWnd__InitializeTempVariables        0x563FD0
#define CStmlWnd__InitializeWindowVariables      0x5685F0
#define CStmlWnd__MakeStmlColorTag               0x5637D0
#define CStmlWnd__MakeWndNotificationTag         0x563870
#define CStmlWnd__StripFirstSTMLLines            0x56C4A0
#define CStmlWnd__UpdateHistoryString            0x563670

// CTabWnd
#define CTabWnd__Draw                            0x571E50
#define CTabWnd__DrawCurrentPage                 0x571940
#define CTabWnd__DrawTab                         0x5716C0
#define CTabWnd__GetCurrentPage                  0x571270
#define CTabWnd__GetCurrentTabIndex              0x571040
#define CTabWnd__GetNumTabs                      0x571140
#define CTabWnd__GetPageClientRect               0x571050
#define CTabWnd__GetPageFromTabIndex             0x571170
#define CTabWnd__GetPageInnerRect                0x5710B0
#define CTabWnd__GetTabInnerRect                 0x571380
#define CTabWnd__GetTabRect                      0x571280
#define CTabWnd__IndexInBounds                   0x571150
#define CTabWnd__InsertPage                      0x571D40
#define CTabWnd__SetPage                         0x571420
#define CTabWnd__SetPageRect                     0x571530
#define CTabWnd__UpdatePage                      0x5715E0
