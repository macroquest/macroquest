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
#define __ExpectedVersionDate                                     "Jan 16 2006" 
#define __ExpectedVersionTime                                     "17:06:44" 
#define __ActualVersionDate                                        0x65181C
#define __ActualVersionTime                                        0x651828

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4AA8C9
#define __MemChecker2                                              0x4CCBAB
#define __MemChecker3                                              0x4CCC38
#define __MemChecker4                                              0x6030F0
#define __EncryptPad0                                              0x7934C8
#define __EncryptPad2                                              0x7955E8
#define __EncryptPad3                                              0x7959E8
#define __EncryptPad4                                              0x79FD10

// Direct Input
#define DI8__Main                                                  0x98B59C
#define DI8__Keyboard                                              0x98B5A0
#define DI8__Mouse                                                 0x98B5A4

#define __AltTimerReady                                            0x926F42
#define __Attack                                                   0x98819B
#define __BindList                                                 0x78E950
#define __Clicks                                                   0x9260E4
#define __CommandList                                              0x78F120
#define __CurrentMapLabel                                          0x99461C
#define __CurrentSocial                                            0x69AD64
#define __DoAbilityAvailable                                       0x926EDC
#define __DoAbilityList                                            0x95FCE8
#define __DrawHandler                                              0x9A0AE4
//#define __EQP_IDArray                                              0x0
#define __FriendsList                                              0x95CA88
#define __GroupCount                                               0x906840
#define __GroupLeader                                              0x90699C
#define __Guilds                                                   0x908328
#define __gWorld                                                   0x908298
#define __HotkeyPage                                               0x9870D4
#define __HWnd                                                     0x98B544
#define __IgnoreList                                               0x95E388
#define __InChatMode                                               0x926020
#define __LastTell                                                 0x9281F4
#define __Mouse                                                    0x98B5A8
#define __MouseLook                                                0x9260B2
#define __NetStatusToggle                                          0x9260B4
#define __PCNames                                                  0x92724C
#define __RangeAttackReady                                         0x926F40
#define __RunWalkState                                             0x926024
#define __ScreenMode                                               0x8561F8
#define __ScreenX                                                  0x925FE8
#define __ScreenY                                                  0x925FEC
#define __ServerHost                                               0x906714
#define __ServerName                                               0x95FCA8
#define __ShowNames                                                0x927134
#define __SkillDict                                                0x856EF0
#define __Socials                                                  0x95FDA8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x91FF78
#define instEQZoneInfo                                             0x926250
#define instKeypressHandler                                        0x988270
#define pinstActiveBanker                                          0x908308
#define pinstActiveCorpse                                          0x90830C
#define pinstActiveGMaster                                         0x908310
#define pinstActiveMerchant                                        0x908304
#define pinstAltAdvManager                                         0x856EC8
#define pinstBandageTarget                                         0x9082F0
#define pinstCamActor                                              0x8569B8
#define pinstCDBStr                                                0x856088
#define pinstCDisplay                                              0x908318
#define pinstCEverQuest                                            0x98B710
#define pinstCharData                                              0x9082D8
#define pinstCharSpawn                                             0x9082FC
#define pinstControlledMissile                                     0x9082D4
#define pinstControlledPlayer                                      0x9082FC
#define pinstCSidlManager                                          0x99FD54
#define pinstCXWndManager                                          0x99FD4C
#define pinstEQItemList                                            0x9082BC
#define pinstEQSoundManager                                        0x857080
#define instGroup                                                  0x906840
#define pinstGroup                                                 0x906988
#define pinstImeManager                                            0x99FD58
#define pinstLocalPlayer                                           0x9082E8
#define pinstModelPlayer                                           0x908314
#define pinstPCData                                                0x9082D8
#define pinstSelectedItem                                          0x994474
#define pinstSpawnManager                                          0x988584
#define pinstSpellManager                                          0x9885EC
#define pinstSpellSets                                             0x9870D8
#define pinstStringTable                                           0x9082A8
#define pinstSwitchManager                                         0x906490
#define pinstTarget                                                0x908300
#define pinstTargetObject                                          0x9082DC
#define pinstTargetSwitch                                          0x9082E0
#define pinstTrackTarget                                           0x9082F4
#define pinstTradeTarget                                           0x9082E4
#define instTributeActive                                          0x856065
#define pinstViewActor                                             0x8569B4
#define pinstWorldData                                             0x9082B8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x7A1E50
#define pinstCCharacterSelect                                      0x85688C
#define pinstCFacePick                                             0x856890
#define pinstCNoteWnd                                              0x856894
#define pinstCHelpWnd                                              0x995208
#define pinstCBookWnd                                              0x856898
#define pinstCPetInfoWnd                                           0x85689C
#define pinstCTrainWnd                                             0x8568A0
#define pinstCSkillsWnd                                            0x8568A4
#define pinstCSkillsSelectWnd                                      0x8568A8
#define pinstCCombatSkillSelectWnd                                 0x8568AC
#define pinstCFriendsWnd                                           0x8568B0
#define pinstCPotionBeltWnd                                        0x8568BC
#define pinstCAAWnd                                                0x8568C0
#define pinstCGroupSearchFiltersWnd                                0x8568C4
#define pinstCLoadskinWnd                                          0x8568C8
#define pinstCAlarmWnd                                             0x8568CC
#define pinstCMusicPlayerWnd                                       0x8568D0
#define pinstCRaidWnd                                              0x8568E0
#define pinstCRaidOptionsWnd                                       0x8568E4
#define pinstCBreathWnd                                            0x8568E8
#define pinstCMapViewWnd                                           0x8568EC
#define pinstCMapToolbarWnd                                        0x8568F0
#define pinstCEditLabelWnd                                         0x8568F4
#define pinstCTargetWnd                                            0x8568F8
#define pinstCHotButtonWnd                                         0x994404
#define pinstCHotButtonWnd1                                        0x994404
#define pinstCHotButtonWnd2                                        0x994408
#define pinstCHotButtonWnd3                                        0x99440C
#define pinstCHotButtonWnd4                                        0x994410
#define pinstCColorPickerWnd                                       0x8568FC
#define pinstCPlayerWnd                                            0x856900
#define pinstCOptionsWnd                                           0x856904
#define pinstCBuffWindowNORMAL                                     0x856908
#define pinstCBuffWindowSHORT                                      0x85690C
#define pinstCharacterCreation                                     0x856910
#define pinstCCursorAttachment                                     0x856914
#define pinstCCastingWnd                                           0x856918
#define pinstCCastSpellWnd                                         0x85691C
#define pinstCSpellBookWnd                                         0x856920
#define pinstCInventoryWnd                                         0x856924
#define pinstCBankWnd                                              0x856928
#define pinstCQuantityWnd                                          0x85692C
#define pinstCLootWnd                                              0x856930
#define pinstCActionsWnd                                           0x856934
#define pinstCCombatAbilityWnd                                     0x856938
#define pinstCMerchantWnd                                          0x85693C
#define pinstCTradeWnd                                             0x856940
#define pinstCSelectorWnd                                          0x856944
#define pinstCBazaarWnd                                            0x856948
#define pinstCBazaarSearchWnd                                      0x85694C
#define pinstCGiveWnd                                              0x856950
#define pinstCTrackingWnd                                          0x856954
#define pinstCInspectWnd                                           0x856958
#define pinstCSocialEditWnd                                        0x85695C
#define pinstCFeedbackWnd                                          0x856960
#define pinstCBugReportWnd                                         0x856964
#define pinstCVideoModesWnd                                        0x856968
#define pinstCTextEntryWnd                                         0x856970
#define pinstCFileSelectionWnd                                     0x856974
#define pinstCCompassWnd                                           0x856978
#define pinstCPlayerNotesWnd                                       0x85697C
#define pinstCGemsGameWnd                                          0x856980
#define pinstCTimeLeftWnd                                          0x856984
#define pinstCPetitionQWnd                                         0x856988
#define pinstCSoulmarkWnd                                          0x85698C
#define pinstCStoryWnd                                             0x856990
#define pinstCJournalTextWnd                                       0x856994
#define pinstCJournalCatWnd                                        0x856998
#define pinstCBodyTintWnd                                          0x85699C
#define pinstCInvSlotMgr                                           0x8569A8
#define pinstCContainerMgr                                         0x8569AC
#define pinstCAdventureLeaderboardWnd                              0x993CD8
#define pinstCAdventureMerchantWnd                                 0x7A1DF0
#define pinstCAdventureRequestWnd                                  0x993CF4
#define pinstCAdventureStatsWnd                                    0x993D10
#define pinstCChatManager                                          0x994104
#define pinstCDynamicZoneWnd                                       0x9941E0
#define pinstCFindLocationWnd                                      0x9942E4
#define pinstCGroupSearchWnd                                       0x994378
#define pinstCGroupWnd                                             0x994394
#define pinstCGuildMgmtWnd                                         0x9943CC
#define pinstCItemDisplayManager                                   0x9944A8
#define pinstCLeadershipWnd                                        0x994544
#define pinstCConfirmationDialog                                   0x994764
#define pinstCPopupWndManager                                      0x994764
#define pinstCSystemInfoDialogBox                                  0x995130
#define pinstCTargetOfTargetWnd                                    0x99514C
#define pinstCTipWndOFDAY                                          0x99523C
#define pinstCTipWndCONTEXT                                        0x995240
#define pinstCTradeskillWnd                                        0x9952A0
#define pinstCTributeBenefitWnd                                    0x9952EC
#define pinstCTributeMasterWnd                                     0x995308
#define pinstCContextMenuManager                                   0x99FD74


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x47A7E0
#define __ConvertItemTags                                          0x471A48
#define __ExecuteCmd                                               0x46624C
#define __get_melee_range                                          0x46A22B
#define __GetGaugeValueFromEQ                                      0x559FCD
#define __GetLabelFromEQ                                           0x55A592
#define __NewUIINI                                                 0x559C7B
#define __ProcessGameEvents                                        0x49D96D
#define __SendMessage                                              0x485008
#define CrashDetected                                              0x4CC867
#define DrawNetStatus                                              0x4ACA73
#define Util__FastTime                                             0x5723B0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x44DEBD
#define AltAdvManager__IsAbilityReady                              0x44DEF3
#define AltAdvManager__GetAltAbility                               0x44E003

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x4DC9CC

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x4E4579

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x5BC060

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x4F2C9D
#define CChatManager__InitContextMenu                              0x4F31FF

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x4F6992

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x59D1C0
#define CComboWnd__Draw                                            0x59D3B0
#define CComboWnd__GetButtonRect                                   0x59D1F0
#define CComboWnd__GetCurChoice                                    0x59D180
#define CComboWnd__GetListRect                                     0x59D650
#define CComboWnd__GetTextRect                                     0x59D240
#define CComboWnd__InsertChoice                                    0x59D6B0
#define CComboWnd__SetColors                                       0x59D110
#define CComboWnd__SetChoice                                       0x59D140

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x4FC1F8
#define CContainerWnd__vftable                                     0x6577D8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x440BF7
#define CDisplay__GetClickedActor                                  0x43EA98
#define CDisplay__GetUserDefinedColor                              0x43E164
#define CDisplay__GetWorldFilePath                                 0x43D906
#define CDisplay__ReloadUI                                         0x44A07D
#define CDisplay__WriteTextHD2                                     0x4420B2

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x4D801A
#define CEditBaseWnd__SetSel                                       0x5BB0C0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x5B8870
#define CEditWnd__GetCharIndexPt                                   0x5B9660
#define CEditWnd__GetDisplayString                                 0x5B8A00
#define CEditWnd__GetHorzOffset                                    0x5B8C70
#define CEditWnd__GetLineForPrintableChar                          0x5B9140
#define CEditWnd__GetSelStartPt                                    0x5B98A0
#define CEditWnd__GetSTMLSafeText                                  0x5B8E00
#define CEditWnd__PointFromPrintableChar                           0x5B9250
#define CEditWnd__SelectableCharFromPoint                          0x5B93C0
#define CEditWnd__SetEditable                                      0x5B8DD0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x488467
#define CEverQuest__DropHeldItemOnGround                           0x48B62B
#define CEverQuest__dsp_chat                                       0x48BFA0
#define CEverQuest__EnterZone                                      0x49C326
#define CEverQuest__GetBodyTypeDesc                                0x486191
#define CEverQuest__GetClassDesc                                   0x485BB4
#define CEverQuest__GetClassThreeLetterCode                        0x48602E
#define CEverQuest__GetDeityDesc                                   0x4864B6
#define CEverQuest__GetRaceDesc                                    0x486496
#define CEverQuest__InterpretCmd                                   0x48C849
#define CEverQuest__LeftClickedOnPlayer                            0x49AC1F
#define CEverQuest__RightClickedOnPlayer                           0x49B06E
#define CEverQuest__SetGameState                                   0x4884E8

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x50478D
#define CGaugeWnd__CalcLinesFillRect                               0x5047E9
#define CGaugeWnd__Draw                                            0x504AE9

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x51483C

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x51AEB3
#define CInvSlotMgr__MoveItem                                      0x51B00E

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x51BE1B

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x521FBE
#define CItemDisplayWnd__SetSpell                                  0x51E0CB

// CLabel 
#define CLabel__Draw                                               0x52664C

// CListWnd 
#define CListWnd__AddColumn                                        0x59CF20
#define CListWnd__AddColumn1                                       0x59CA50
#define CListWnd__AddLine                                          0x59C5E0
#define CListWnd__AddString                                        0x59C7B0
#define CListWnd__CalculateFirstVisibleLine                        0x599B00
#define CListWnd__CalculateVSBRange                                0x59B640
#define CListWnd__ClearAllSel                                      0x599340
#define CListWnd__CloseAndUpdateEditWindow                         0x59A120
#define CListWnd__Compare                                          0x59A490
#define CListWnd__Draw                                             0x59B350
#define CListWnd__DrawColumnSeparators                             0x59B1D0
#define CListWnd__DrawHeader                                       0x599510
#define CListWnd__DrawItem                                         0x59ABA0
#define CListWnd__DrawLine                                         0x59AF10
#define CListWnd__DrawSeparator                                    0x59B270
#define CListWnd__EnsureVisible                                    0x599B50
#define CListWnd__ExtendSel                                        0x59AAD0
#define CListWnd__GetColumnFlags                                   0x598EE0
#define CListWnd__GetColumnJustification                           0x599050
#define CListWnd__GetColumnMinWidth                                0x598FF0
#define CListWnd__GetColumnWidth                                   0x598F30
#define CListWnd__GetCurSel                                        0x5989A0
#define CListWnd__GetHeaderRect                                    0x598AB0
#define CListWnd__GetItemAtPoint                                   0x599E30
#define CListWnd__GetItemAtPoint1                                  0x599EA0
#define CListWnd__GetItemData                                      0x598C90
#define CListWnd__GetItemHeight                                    0x5998A0
#define CListWnd__GetItemIcon                                      0x598E20
#define CListWnd__GetItemRect                                      0x599C20
#define CListWnd__GetItemText                                      0x598CD0
#define CListWnd__GetSelList                                       0x59C930
#define CListWnd__GetSeparatorRect                                 0x59A3E0
#define CListWnd__IsLineEnabled                                    0x599420
#define CListWnd__RemoveLine                                       0x59C8E0
#define CListWnd__SetColors                                        0x598A20
#define CListWnd__SetColumnJustification                           0x5990A0
#define CListWnd__SetColumnWidth                                   0x598FB0
#define CListWnd__SetCurSel                                        0x5989E0
#define CListWnd__SetItemColor                                     0x59C1B0
#define CListWnd__SetItemData                                      0x5993E0
#define CListWnd__SetItemText                                      0x59C130
#define CListWnd__ShiftColumnSeparator                             0x59AA40
#define CListWnd__Sort                                             0x59CF50
#define CListWnd__ToggleSel                                        0x5992B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x53649A

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x537ABC
#define CMerchantWnd__RequestBuyItem                               0x538A3B
#define CMerchantWnd__RequestSellItem                              0x537CB5
#define CMerchantWnd__SelectBuySellSlot                            0x53879F

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x5B6B90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5A2450
#define CSidlScreenWnd__CalculateVSBRange                          0x5A2390
#define CSidlScreenWnd__ConvertToRes                               0x5A2B90
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x5A33C0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x5A4630
#define CSidlScreenWnd__CSidlScreenWnd2                            0x5A46E0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x5A3EE0
#define CSidlScreenWnd__DrawSidlPiece                              0x5A30E0
#define CSidlScreenWnd__EnableIniStorage                           0x5A2B40
#define CSidlScreenWnd__GetSidlPiece                               0x5A32A0
#define CSidlScreenWnd__Init1                                      0x5A4450
#define CSidlScreenWnd__LoadIniInfo                                0x5A3470
#define CSidlScreenWnd__LoadIniListWnd                             0x5A2D00
#define CSidlScreenWnd__LoadSidlScreen                             0x5A2F40
#define CSidlScreenWnd__SetScreen                                  0x5A3FF0
#define CSidlScreenWnd__StoreIniInfo                               0x5A2690
#define CSidlScreenWnd__WndNotification                            0x5A3040

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x5BDAA0
#define CSliderWnd__SetValue                                       0x5BDC30
#define CSliderWnd__UpdateThumb                                    0x5BDA60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x558473

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x5AD090
#define CStmlWnd__CalculateHSBRange                                0x5A5890
#define CStmlWnd__CalculateVSBRange                                0x5A5830
#define CStmlWnd__CanBreakAtCharacter                              0x5A59D0
#define CStmlWnd__CanGoBackward                                    0x5A5AB0
#define CStmlWnd__FastForwardToEndOfTag                            0x5A6530
#define CStmlWnd__GetNextChar                                      0x5A5EF0
#define CStmlWnd__GetNextTagPiece                                  0x5A6450
#define CStmlWnd__GetSTMLText                                      0x4F6974
#define CStmlWnd__GetThisChar                                      0x5DA710
#define CStmlWnd__GetVisiableText                                  0x5A7680
#define CStmlWnd__InitializeWindowVariables                        0x5A97D0
#define CStmlWnd__MakeStmlColorTag                                 0x5A4ED0
#define CStmlWnd__MakeWndNotificationTag                           0x5A4F70
#define CStmlWnd__StripFirstSTMLLines                              0x5ACE20
#define CStmlWnd__UpdateHistoryString                              0x5A7EE0

// CTabWnd 
#define CTabWnd__Draw                                              0x5BD550
#define CTabWnd__DrawCurrentPage                                   0x5BD010
#define CTabWnd__DrawTab                                           0x5BCE10
#define CTabWnd__GetCurrentPage                                    0x5BD2A0
#define CTabWnd__GetCurrentTabIndex                                0x5BCAD0
#define CTabWnd__GetNumTabs                                        0x5BCAC0
#define CTabWnd__GetPageClientRect                                 0x5BCAE0
#define CTabWnd__GetPageFromTabIndex                               0x5BCD60
#define CTabWnd__GetPageInnerRect                                  0x5BCB40
#define CTabWnd__GetTabInnerRect                                   0x5BCCE0
#define CTabWnd__GetTabRect                                        0x5BCBF0
#define CTabWnd__IndexInBounds                                     0x5BCBD0
#define CTabWnd__InsertPage                                        0x5BD750
#define CTabWnd__SetPage                                           0x5BD2B0
#define CTabWnd__SetPageRect                                       0x5BD4A0
#define CTabWnd__UpdatePage                                        0x5BD6D0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x40CE9C

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x5A4A60

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x5C3E60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x598750

// CXRect 
#define CXRect__CenterPoint                                        0x4DC1CC

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x40CAD5
#define CXStr__CXStr1                                              0x4C2EA3
#define CXStr__CXStr3                                              0x573990
#define CXStr__dCXStr                                              0x44E5DF
#define CXStr__operator_equal1                                     0x573B50
#define CXStr__operator_plus_equal1                                0x574990

// CXWnd 
#define CXWnd__BringToTop                                          0x59DE80
#define CXWnd__Center                                              0x5A1280
#define CXWnd__ClrFocus                                            0x59DBD0
#define CXWnd__DoAllDrawing                                        0x5A1E70
#define CXWnd__DrawChildren                                        0x5A1FA0
#define CXWnd__DrawColoredRect                                     0x59E0E0
#define CXWnd__DrawTooltip                                         0x5A1D90
#define CXWnd__DrawTooltipAtPoint                                  0x5A10F0
#define CXWnd__GetBorderFrame                                      0x59E590
#define CXWnd__GetChildWndAt                                       0x5A0D00
#define CXWnd__GetClientClipRect                                   0x59E4C0
#define CXWnd__GetFirstChildWnd                                    0x59DF10
#define CXWnd__GetNextChildWnd                                     0x5A0CE0
#define CXWnd__GetNextSib                                          0x59DF30
#define CXWnd__GetScreenClipRect                                   0x5A1510
#define CXWnd__GetScreenRect                                       0x59E760
#define CXWnd__GetTooltipRect                                      0x59E330
#define CXWnd__GetWindowTextA                                      0x4D245C
#define CXWnd__IsActive                                            0x59E530
#define CXWnd__IsDescendantOf                                      0x59E540
#define CXWnd__IsReallyVisible                                     0x5A0CC0
#define CXWnd__IsType                                              0x5A1E10
#define CXWnd__Move                                                0x5A0870
#define CXWnd__Move1                                               0x5A0900
#define CXWnd__ProcessTransition                                   0x59DE40
#define CXWnd__Refade                                              0x59DC70
#define CXWnd__Resize                                              0x5A1650
#define CXWnd__Right                                               0x5A13F0
#define CXWnd__SetFirstChildPointer                                0x59E9B0
#define CXWnd__SetFocus                                            0x59FBF0
#define CXWnd__SetKeyTooltip                                       0x59E9F0
#define CXWnd__SetMouseOver                                        0x59E9D0
#define CXWnd__SetNextSibPointer                                   0x59E9C0
#define CXWnd__StartFade                                           0x59DEA0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x5B0360
#define CXWndManager__DrawWindows                                  0x5B0030
#define CXWndManager__GetFirstChildWnd                             0x5AF940
#define CXWndManager__GetKeyboardFlags                             0x5AED40
#define CXWndManager__HandleKeyboardMsg                            0x5AF210
#define CXWndManager__RemoveWnd                                    0x5AF120

// CDBStr
#define CDBStr__GetString                                          0x43B672

// EQ_Character 
#define EQ_Character__CastSpell                                    0x416C84
#define EQ_Character__Cur_HP                                       0x41C8AF
#define EQ_Character__GetAACastingTimeModifier                     0x412F92
#define EQ_Character__GetCharInfo2                                 0x5ECF80
#define EQ_Character__GetFocusCastingTimeModifier                  0x412487
#define EQ_Character__Max_Endurance                                0x41B66E
#define EQ_Character__Max_HP                                       0x41B554
#define EQ_Character__Max_Mana                                     0x4B076B
#define EQ_Character__doCombatAbility                              0x4AF6AE

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4A5BFA
#define EQ_Item__GetItemLinkHash                                   0x5E4520
#define EQ_Item__IsStackable                                       0x5ED4D0

// EQ_LoadingS 
#define EQ_LoadingS__WriteTextHD                                   0x44E655

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4B2951
#define EQ_PC__GetAltAbilityIndex                                  0x5F1660
#define EQ_PC__GetCombatAbility                                    0x5F1750
#define EQ_PC__GetCombatAbilityTimer                               0x5F1800
#define EQ_PC__GetItemTimerValue                                   0x4AEF2A

// EQItemList 
#define EQItemList__dEQItemList                                    0x469016
#define EQItemList__EQItemList                                     0x468F9A

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4B6B2C
#define EQPlayer__dEQPlayer                                        0x4B96BF
#define EQPlayer__DoAttack                                         0x4C2440
#define EQPlayer__EQPlayer                                         0x4BB589
#define EQPlayer__SetNameSpriteState                               0x4B8379
#define EQPlayer__SetNameSpriteTint                                0x4B6B94

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4BC191

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4A7469
#define KeypressHandler__AttachKeyToEqCommand                      0x4A7436
#define KeypressHandler__ClearCommandStateArray                    0x4A7280
#define KeypressHandler__HandleKeyDown                             0x4A60DB
#define KeypressHandler__HandleKeyUp                               0x4A6352
#define KeypressHandler__SaveKeymapping                            0x4A7306

// MapViewMap 
#define MapViewMap__Clear                                          0x532C00
#define MapViewMap__SaveEx                                         0x5333BD

// StringTable 
#define StringTable__getString                                     0x5E06A0
