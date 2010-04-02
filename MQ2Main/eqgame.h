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
#define __ExpectedVersionDate                                     "May 16 2007"
#define __ExpectedVersionTime                                     "12:50:25"
#define __ActualVersionDate                                        0x6D9DEC
#define __ActualVersionTime                                        0x6D9DF8

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4E7990
#define __MemChecker1                                              0x62ACB0
#define __MemChecker2                                              0x517D50
#define __MemChecker3                                              0x517E00
#define __MemChecker4                                              0x5F7F20
#define __EncryptPad0                                              0x733A20
#define __EncryptPad1                                              0x73D258
#define __EncryptPad2                                              0x735F80
#define __EncryptPad3                                              0x736380
#define __EncryptPad4                                              0x73C970

// Direct Input
#define DI8__Main                                                  0x96B184
#define DI8__Keyboard                                              0x96B188
#define DI8__Mouse                                                 0x96B18C
#define __AltTimerReady                                            0x907342
#define __Attack                                                   0x9649BA
#define __Autofire                                                 0x9649BB
#define __BindList                                                 0x72EC50
#define __Clicks                                                   0x90646C
#define __CommandList                                              0x72F450
#define __CurrentMapLabel                                          0x97624C
#define __CurrentSocial                                            0x72B4DC
#define __DoAbilityAvailable                                       0x9072DC
#define __DoAbilityList                                            0x93C500
#define __DrawHandler                                              0x9850A4
#define __GroupCount                                               0x8E6B90
#define __GroupLeader                                              0x8E6CEC
#define __Guilds                                                   0x8E86B0
#define __gWorld                                                   0x8E85F0
#define __HotkeyPage                                               0x9638EC
#define __HWnd                                                     0x96B130
#define __InChatMode                                               0x9063A8
#define __LastTell                                                 0x907C08
#define __Mouse                                                    0x96B190
#define __MouseLook                                                0x90643A
#define __NetStatusToggle                                          0x90643C
#define __PCNames                                                  0x907660
#define __RangeAttackReady                                         0x907340
#define __RunWalkState                                             0x9063AC
#define __ScreenMode                                               0x836660
#define __ScreenX                                                  0x906370
#define __ScreenY                                                  0x906374
#define __ServerHost                                               0x8E6AE4
#define __ServerName                                               0x93C4C0
#define __ShowNames                                                0x907534
#define __Socials                                                  0x93C5C0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x900300
#define instEQZoneInfo                                             0x9065D8
#define instKeypressHandler                                        0x964ABC
#define pinstActiveBanker                                          0x8E8688
#define pinstActiveCorpse                                          0x8E868C
#define pinstActiveGMaster                                         0x8E8690
#define pinstActiveMerchant                                        0x8E8684
#define pinstAltAdvManager                                         0x837348
#define pinstAuraMgr                                               0x74238C
#define pinstBandageTarget                                         0x8E8670
#define pinstCamActor                                              0x836E3C
#define pinstCDBStr                                                0x8364E0
#define pinstCDisplay                                              0x8E8698
#define pinstCEverQuest                                            0x96B2F8
#define pinstCharData                                              0x8E8654
#define pinstCharSpawn                                             0x8E867C
#define pinstControlledMissile                                     0x8E8650
#define pinstControlledPlayer                                      0x8E867C
#define pinstCSidlManager                                          0x9848A0
#define pinstCXWndManager                                          0x984898
#define instDynamicZone                                            0x905DC0
#define pinstDZMember                                              0x905ED0
#define pinstDZTimerInfo                                           0x905ED4
#define pinstEQItemList                                            0x8E8638
#define instEQMisc                                                 0x836498
#define pinstEQSoundManager                                        0x83736C
#define instExpeditionLeader                                       0x905E0A
#define instExpeditionName                                         0x905E4A
#define instGroup                                                  0x8E6B90
#define pinstGroup                                                 0x8E6B8C
#define pinstImeManager                                            0x9848A4
#define pinstLocalPlayer                                           0x8E8668
#define pinstModelPlayer                                           0x8E8694
#define pinstPCData                                                0x8E8654
#define pinstSelectedItem                                          0x9760A4
#define pinstSkillMgr                                              0x9681B8
#define pinstSpawnManager                                          0x968134
#define pinstSpellManager                                          0x9681BC
#define pinstSpellSets                                             0x9638F0
#define pinstStringTable                                           0x8E860C
#define pinstSwitchManager                                         0x8E67E0
#define pinstTarget                                                0x8E8680
#define pinstTargetObject                                          0x8E8658
#define pinstTargetSwitch                                          0x8E865C
#define pinstTaskMember                                            0x836478
#define pinstTrackTarget                                           0x8E8674
#define pinstTradeTarget                                           0x8E8664
#define instTributeActive                                          0x8364BD
#define pinstViewActor                                             0x836E38
#define pinstWorldData                                             0x8E8634


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x7408C0
#define pinstCAudioTriggersWindow                                  0x74088C
#define pinstCCharacterSelect                                      0x836D48
#define pinstCFacePick                                             0x836D00
#define pinstCNoteWnd                                              0x836D04
#define pinstCBookWnd                                              0x836D08
#define pinstCPetInfoWnd                                           0x836D0C
#define pinstCTrainWnd                                             0x836D10
#define pinstCSkillsWnd                                            0x836D14
#define pinstCSkillsSelectWnd                                      0x836D18
#define pinstCCombatSkillSelectWnd                                 0x836D1C
#define pinstCFriendsWnd                                           0x836D20
#define pinstCAuraWnd                                              0x836D24
#define pinstCRespawnWnd                                           0x836D28
#define pinstCBandolierWnd                                         0x836D2C
#define pinstCPotionBeltWnd                                        0x836D30
#define pinstCAAWnd                                                0x836D34
#define pinstCGroupSearchFiltersWnd                                0x836D38
#define pinstCLoadskinWnd                                          0x836D3C
#define pinstCAlarmWnd                                             0x836D40
#define pinstCMusicPlayerWnd                                       0x836D44
#define pinstCMailWnd                                              0x836D4C
#define pinstCMailCompositionWnd                                   0x836D50
#define pinstCMailAddressBookWnd                                   0x836D54
#define pinstCRaidWnd                                              0x836D5C
#define pinstCRaidOptionsWnd                                       0x836D60
#define pinstCBreathWnd                                            0x836D64
#define pinstCMapViewWnd                                           0x836D68
#define pinstCMapToolbarWnd                                        0x836D6C
#define pinstCEditLabelWnd                                         0x836D70
#define pinstCTargetWnd                                            0x836D74
#define pinstCColorPickerWnd                                       0x836D78
#define pinstCPlayerWnd                                            0x836D7C
#define pinstCOptionsWnd                                           0x836D80
#define pinstCBuffWindowNORMAL                                     0x836D84
#define pinstCBuffWindowSHORT                                      0x836D88
#define pinstCharacterCreation                                     0x836D8C
#define pinstCCursorAttachment                                     0x836D90
#define pinstCCastingWnd                                           0x836D94
#define pinstCCastSpellWnd                                         0x836D98
#define pinstCSpellBookWnd                                         0x836D9C
#define pinstCInventoryWnd                                         0x836DA0
#define pinstCBankWnd                                              0x836DA4
#define pinstCQuantityWnd                                          0x836DA8
#define pinstCLootWnd                                              0x836DAC
#define pinstCActionsWnd                                           0x836DB0
#define pinstCCombatAbilityWnd                                     0x836DB4
#define pinstCMerchantWnd                                          0x836DB8
#define pinstCTradeWnd                                             0x836DBC
#define pinstCSelectorWnd                                          0x836DC0
#define pinstCBazaarWnd                                            0x836DC4
#define pinstCBazaarSearchWnd                                      0x836DC8
#define pinstCGiveWnd                                              0x836DCC
#define pinstCTrackingWnd                                          0x836DD0
#define pinstCInspectWnd                                           0x836DD4
#define pinstCSocialEditWnd                                        0x836DD8
#define pinstCFeedbackWnd                                          0x836DDC
#define pinstCBugReportWnd                                         0x836DE0
#define pinstCVideoModesWnd                                        0x836DE4
#define pinstCTextEntryWnd                                         0x836DEC
#define pinstCFileSelectionWnd                                     0x836DF0
#define pinstCCompassWnd                                           0x836DF4
#define pinstCPlayerNotesWnd                                       0x836DF8
#define pinstCGemsGameWnd                                          0x836DFC
#define pinstCTimeLeftWnd                                          0x836E00
#define pinstCPetitionQWnd                                         0x836E04
#define pinstCSoulmarkWnd                                          0x836E08
#define pinstCStoryWnd                                             0x836E0C
#define pinstCJournalTextWnd                                       0x836E10
#define pinstCJournalCatWnd                                        0x836E14
#define pinstCBodyTintWnd                                          0x836E18
#define pinstCServerListWnd                                        0x836E1C
#define pinstCAvaZoneWnd                                           0x836E20
#define pinstCBlockedBuffWnd                                       0x836E24
#define pinstCBlockedPetBuffWnd                                    0x836E28
#define pinstCInvSlotMgr                                           0x836E2C
#define pinstCContainerMgr                                         0x836E30
#define pinstCAdventureLeaderboardWnd                              0x9738DC
#define pinstCAdventureRequestWnd                                  0x9738F8
#define pinstCAltStorageWnd                                        0x973958
#define pinstCAdventureStatsWnd                                    0x973914
#define pinstCBarterMerchantWnd                                    0x973B0C
#define pinstCBarterSearchWnd                                      0x973B28
#define pinstCBarterWnd                                            0x973B44
#define pinstCChatManager                                          0x973D0C
#define pinstCDynamicZoneWnd                                       0x973DE8
#define pinstCEQMainWnd                                            0x973E58
#define pinstCFellowshipWnd                                        0x973EBC
#define pinstCFindLocationWnd                                      0x973EF0
#define pinstCGroupSearchWnd                                       0x973FC4
#define pinstCGroupWnd                                             0x973FBC
#define pinstCGuildBankWnd                                         0x973FD8
#define pinstCGuildMgmtWnd                                         0x975FF8
#define pinstCGuildTributeMasterWnd                                0x976018
#define pinstCHotButtonWnd                                         0x976034
#define pinstCHotButtonWnd1                                        0x976034
#define pinstCHotButtonWnd2                                        0x976038
#define pinstCHotButtonWnd3                                        0x97603C
#define pinstCHotButtonWnd4                                        0x976040
#define pinstCItemDisplayManager                                   0x9760D8
#define pinstCItemExpTransferWnd                                   0x9760F8
#define pinstCLeadershipWnd                                        0x976174
#define pinstCLFGuildWnd                                           0x976190
#define pinstCMIZoneSelectWnd                                      0x9762B4
#define pinstCAdventureMerchantWnd                                 0x9763AC
#define pinstCConfirmationDialog                                   0x9763C8
#define pinstCPopupWndManager                                      0x9763C8
#define pinstCProgressionSelectionWnd                              0x9763FC
#define pinstCPvPLeaderboardWnd                                    0x976418
#define pinstCPvPStatsWnd                                          0x976434
#define pinstCSystemInfoDialogBox                                  0x976D9C
#define pinstCTargetOfTargetWnd                                    0x976DB8
#define pinstCTaskSelectWnd                                        0x976DEC
#define pinstCTaskTemplateSelectWnd                                0x976E08
#define pinstCTaskWnd                                              0x976E24
#define pinstCTipWndOFDAY                                          0x976E70
#define pinstCTipWndCONTEXT                                        0x976E74
#define pinstCTitleWnd                                             0x976E90
#define pinstCTradeskillWnd                                        0x976ED4
#define pinstCTributeBenefitWnd                                    0x976F20
#define pinstCTributeMasterWnd                                     0x976F3C
#define pinstCContextMenuManager                                   0x9848FC
#define pinstCVoiceMacroWnd                                        0x96826C
#define pinstCHtmlWnd                                              0x968288


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4A92D0
#define __ConvertItemTags                                          0x49DD20
#define __ExecuteCmd                                               0x48F4A0
#define __get_melee_range                                          0x494500
#define __GetGaugeValueFromEQ                                      0x5CE980
#define __GetLabelFromEQ                                           0x5CF180
#define __NewUIINI                                                 0x5CE580
#define __ProcessGameEvents                                        0x4D4800
#define __SendMessage                                              0x4B6A50
#define CrashDetected                                              0x516F50
#define DrawNetStatus                                              0x4EA6D0
#define Util__FastTime                                             0x62B340


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x46F400
#define AltAdvManager__IsAbilityReady                              0x46F440
#define AltAdvManager__GetAltAbility                               0x46F5C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x52C3E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x535850

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x655A90

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5487A0
#define CChatManager__InitContextMenu                              0x548F30

// CChatService
#define CChatService__GetNumberOfFriends                           0x61C440
#define CChatService__GetFriendName                                0x61C450

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x54D0B0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x63CB90
#define CComboWnd__Draw                                            0x63CD40
#define CComboWnd__GetCurChoice                                    0x63CB40
#define CComboWnd__GetListRect                                     0x63D020
#define CComboWnd__GetTextRect                                     0x63CBC0
#define CComboWnd__InsertChoice                                    0x63D090
#define CComboWnd__SetColors                                       0x63CAD0
#define CComboWnd__SetChoice                                       0x63CB00

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x553700
#define CContainerWnd__vftable                                     0x6E0080

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45E950
#define CDisplay__GetClickedActor                                  0x45C200
#define CDisplay__GetUserDefinedColor                              0x45B670
#define CDisplay__GetWorldFilePath                                 0x45AC20
#define CDisplay__is3dON                                           0x459830
#define CDisplay__ReloadUI                                         0x46A730
#define CDisplay__WriteTextHD2                                     0x460120

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x526670
#define CEditBaseWnd__SetSel                                       0x660930

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x649D50
#define CEditWnd__GetCharIndexPt                                   0x64AB90
#define CEditWnd__GetDisplayString                                 0x649EE0
#define CEditWnd__GetHorzOffset                                    0x64A160
#define CEditWnd__GetLineForPrintableChar                          0x64A640
#define CEditWnd__GetSelStartPt                                    0x64ADD0
#define CEditWnd__GetSTMLSafeText                                  0x64A300
#define CEditWnd__PointFromPrintableChar                           0x64A750
#define CEditWnd__SelectableCharFromPoint                          0x64A8D0
#define CEditWnd__SetEditable                                      0x64A2D0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4BAB80
#define CEverQuest__DropHeldItemOnGround                           0x4BF730
#define CEverQuest__dsp_chat                                       0x4C03B0
#define CEverQuest__EnterZone                                      0x4D3310
#define CEverQuest__GetBodyTypeDesc                                0x4B8280
#define CEverQuest__GetClassDesc                                   0x4B79E0
#define CEverQuest__GetClassThreeLetterCode                        0x4B7FE0
#define CEverQuest__GetDeityDesc                                   0x4B88D0
#define CEverQuest__GetLangDesc                                    0x4B85F0
#define CEverQuest__GetRaceDesc                                    0x4B88A0
#define CEverQuest__InterpretCmd                                   0x4C0D10
#define CEverQuest__LeftClickedOnPlayer                            0x4D1F00
#define CEverQuest__RightClickedOnPlayer                           0x4D22C0
#define CEverQuest__SetGameState                                   0x4BAC50

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x55E720
#define CGaugeWnd__CalcLinesFillRect                               0x55E790
#define CGaugeWnd__Draw                                            0x55EB20

// CGuild
#define CGuild__FindMemberByName                                   0x417260

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x574580

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x57C150
#define CInvSlotMgr__MoveItem                                      0x57C2F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x57D1F0

// CInvSLot
#define CInvSlot__SliderComplete                                   0x57B0D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x584830
#define CItemDisplayWnd__SetSpell                                  0x5CC960

// CLabel 
#define CLabel__Draw                                               0x589E70

// CListWnd 
#define CListWnd__AddColumn                                        0x63C8E0
#define CListWnd__AddColumn1                                       0x63C410
#define CListWnd__AddLine                                          0x63BFA0
#define CListWnd__AddString                                        0x63C170
#define CListWnd__CalculateFirstVisibleLine                        0x6392D0
#define CListWnd__CalculateVSBRange                                0x63AF40
#define CListWnd__ClearAllSel                                      0x638A40
#define CListWnd__CloseAndUpdateEditWindow                         0x6398E0
#define CListWnd__Compare                                          0x639C90
#define CListWnd__Draw                                             0x63AC40
#define CListWnd__DrawColumnSeparators                             0x63AAB0
#define CListWnd__DrawHeader                                       0x638C10
#define CListWnd__DrawItem                                         0x63A3A0
#define CListWnd__DrawLine                                         0x63A750
#define CListWnd__DrawSeparator                                    0x63AB50
#define CListWnd__EnsureVisible                                    0x639320
#define CListWnd__ExtendSel                                        0x63A2D0
#define CListWnd__GetColumnMinWidth                                0x6387E0
#define CListWnd__GetColumnWidth                                   0x638720
#define CListWnd__GetCurSel                                        0x638200
#define CListWnd__GetHeaderRect                                    0x6382F0
#define CListWnd__GetItemAtPoint                                   0x6395F0
#define CListWnd__GetItemAtPoint1                                  0x639660
#define CListWnd__GetItemData                                      0x6384D0
#define CListWnd__GetItemHeight                                    0x639070
#define CListWnd__GetItemIcon                                      0x638660
#define CListWnd__GetItemRect                                      0x6393E0
#define CListWnd__GetItemText                                      0x638510
#define CListWnd__GetSelList                                       0x63C2F0
#define CListWnd__GetSeparatorRect                                 0x639BD0
#define CListWnd__RemoveLine                                       0x63C2A0
#define CListWnd__SetColors                                        0x638260
#define CListWnd__SetColumnJustification                           0x638840
#define CListWnd__SetColumnWidth                                   0x6387A0
#define CListWnd__SetCurSel                                        0x638240
#define CListWnd__SetItemColor                                     0x63BB70
#define CListWnd__SetItemData                                      0x638AE0
#define CListWnd__SetItemText                                      0x63BAF0
#define CListWnd__ShiftColumnSeparator                             0x63A240
#define CListWnd__Sort                                             0x63C910
#define CListWnd__ToggleSel                                        0x6389B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x59CC20

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x59E600
#define CMerchantWnd__RequestBuyItem                               0x59F890
#define CMerchantWnd__RequestSellItem                              0x59E860
#define CMerchantWnd__SelectBuySellSlot                            0x59F5D0

// CObfuscator
#define CObfuscator__doit                                          0x61DAB0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6516A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x527F30
#define CSidlScreenWnd__CalculateVSBRange                          0x642240
#define CSidlScreenWnd__ConvertToRes                               0x642991
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x643190
#define CSidlScreenWnd__CSidlScreenWnd1                            0x644450
#define CSidlScreenWnd__CSidlScreenWnd2                            0x644500
#define CSidlScreenWnd__dCSidlScreenWnd                            0x643D00
#define CSidlScreenWnd__DrawSidlPiece                              0x642E70
#define CSidlScreenWnd__EnableIniStorage                           0x642930
#define CSidlScreenWnd__GetSidlPiece                               0x643070
#define CSidlScreenWnd__Init1                                      0x644260
#define CSidlScreenWnd__LoadIniInfo                                0x643240
#define CSidlScreenWnd__LoadIniListWnd                             0x642AE0
#define CSidlScreenWnd__LoadSidlScreen                             0x642CA0
#define CSidlScreenWnd__StoreIniInfo                               0x642470
#define CSidlScreenWnd__WndNotification                            0x642DD0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x50B8D0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6627B0
#define CSliderWnd__SetValue                                       0x6628B0
#define CSliderWnd__SetNumTicks                                    0x662DF0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5CB6B0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x65EC40
#define CStmlWnd__CalculateVSBRange                                0x656FE0
#define CStmlWnd__CanBreakAtCharacter                              0x657120
#define CStmlWnd__FastForwardToEndOfTag                            0x657C20
#define CStmlWnd__GetNextTagPiece                                  0x657B40
#define CStmlWnd__GetSTMLText                                      0x54D050
#define CStmlWnd__GetThisChar                                      0x67EB90
#define CStmlWnd__GetVisiableText                                  0x658E40
#define CStmlWnd__InitializeWindowVariables                        0x65AFA0
#define CStmlWnd__MakeStmlColorTag                                 0x6566E0
#define CStmlWnd__MakeWndNotificationTag                           0x656780
#define CStmlWnd__StripFirstSTMLLines                              0x65E9C0
#define CStmlWnd__UpdateHistoryString                              0x6596A0

// CTabWnd 
#define CTabWnd__Draw                                              0x662030
#define CTabWnd__DrawCurrentPage                                   0x6619A0
#define CTabWnd__DrawTab                                           0x661780
#define CTabWnd__GetCurrentPage                                    0x661CA0
#define CTabWnd__GetPageClientRect                                 0x661450
#define CTabWnd__GetPageFromTabIndex                               0x6616B0
#define CTabWnd__GetPageInnerRect                                  0x6614B0
#define CTabWnd__GetTabInnerRect                                   0x661630
#define CTabWnd__GetTabRect                                        0x661540
#define CTabWnd__IndexInBounds                                     0x66174D
#define CTabWnd__InsertPage                                        0x662250
#define CTabWnd__SetPage                                           0x661CE0
#define CTabWnd__SetPageRect                                       0x661F60
#define CTabWnd__UpdatePage                                        0x6621D0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x413E70

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x644860

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x667EF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x637F70

// CXRect 
#define CXRect__CenterPoint                                        0x52BBA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4122A0
#define CXStr__CXStr1                                              0x631680
#define CXStr__CXStr3                                              0x62C9F0
#define CXStr__dCXStr                                              0x4065B0
#define CXStr__operator_equal1                                     0x62CBB0
#define CXStr__operator_plus_equal1                                0x62DAA0

// CXWnd 
#define CXWnd__BringToTop                                          0x63D880
#define CXWnd__Center                                              0x640F90
#define CXWnd__ClrFocus                                            0x63D5B0
#define CXWnd__DoAllDrawing                                        0x641C40
#define CXWnd__DrawChildren                                        0x641D70
#define CXWnd__DrawColoredRect                                     0x63DAE0
#define CXWnd__DrawTooltip                                         0x641B60
#define CXWnd__DrawTooltipAtPoint                                  0x640DE0
#define CXWnd__GetBorderFrame                                      0x63E020
#define CXWnd__GetChildWndAt                                       0x6408E0
#define CXWnd__GetClientClipRect                                   0x63DEE0
#define CXWnd__GetFirstChildWnd                                    0x63D920
#define CXWnd__GetNextChildWnd                                     0x6408A0
#define CXWnd__GetNextSib                                          0x63D940
#define CXWnd__GetScreenClipRect                                   0x6411B0
#define CXWnd__GetScreenRect                                       0x63E180
#define CXWnd__GetTooltipRect                                      0x63DD10
#define CXWnd__GetWindowTextA                                      0x4DFAA0
#define CXWnd__IsActive                                            0x645940
#define CXWnd__IsDescendantOf                                      0x63DF50
#define CXWnd__IsReallyVisible                                     0x640880
#define CXWnd__IsType                                              0x663C60
#define CXWnd__Move                                                0x6403B0
#define CXWnd__Move1                                               0x640450
#define CXWnd__ProcessTransition                                   0x63D850
#define CXWnd__Refade                                              0x63D660
#define CXWnd__Resize                                              0x6412F0
#define CXWnd__Right                                               0x641100
#define CXWnd__SetFirstChildPointer                                0x63E3F0
#define CXWnd__SetFocus                                            0x63F6E0
#define CXWnd__SetKeyTooltip                                       0x63E460
#define CXWnd__SetMouseOver                                        0x63E430
#define CXWnd__SetNextSibPointer                                   0x63E410
#define CXWnd__StartFade                                           0x63D8A0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x646D90
#define CXWndManager__DrawWindows                                  0x6469D0
#define CXWndManager__GetFirstChildWnd                             0x6462E0
#define CXWndManager__GetKeyboardFlags                             0x645620
#define CXWndManager__HandleKeyboardMsg                            0x645B30
#define CXWndManager__RemoveWnd                                    0x645A50

// CDBStr
#define CDBStr__GetString                                          0x4581C0

// EQ_Character 
#define EQ_Character__CastRay                                      0x68A4B0
#define EQ_Character__CastSpell                                    0x423510
#define EQ_Character__Cur_HP                                       0x42A9D0
#define EQ_Character__GetAACastingTimeModifier                     0x41E2C0
#define EQ_Character__GetCharInfo2                                 0x60ECD0
#define EQ_Character__GetFocusCastingTimeModifier                  0x41A970
#define EQ_Character__GetFocusRangeModifier                        0x41AAA0
#define EQ_Character__Max_Endurance                                0x4297E0
#define EQ_Character__Max_HP                                       0x429690
#define EQ_Character__Max_Mana                                     0x4EF670
#define EQ_Character__doCombatAbility                              0x4EE4F0
#define EQ_Character__UseSkill                                     0x435E90
#define EQ_Character__GetConLevel                                  0x4EBAA0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4E15D0
#define EQ_Item__GetItemLinkHash                                   0x603820
#define EQ_Item__IsStackable                                       0x5FDA50

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4705B0
#define EQ_LoadingS__Array                                         0x72D160

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4F2590
#define EQ_PC__GetAltAbilityIndex                                  0x608040
#define EQ_PC__GetCombatAbility                                    0x6080D0
#define EQ_PC__GetCombatAbilityTimer                               0x608180
#define EQ_PC__GetItemTimerValue                                   0x4ED820
#define EQ_PC__HasLoreItem                                         0x4F0BB0

// EQItemList 
#define EQItemList__dEQItemList                                    0x492D70
#define EQItemList__EQItemList                                     0x492CC0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x457C40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4F6F70
#define EQPlayer__dEQPlayer                                        0x4FB3A0
#define EQPlayer__DoAttack                                         0x5067F0
#define EQPlayer__EQPlayer                                         0x4FDAE0
#define EQPlayer__SetNameSpriteState                               0x4F9650
#define EQPlayer__SetNameSpriteTint                                0x4F6FE0
#define EQPlayer__IsBodyType_j                                     0x689EE0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4FE8E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4E3160
#define KeypressHandler__AttachKeyToEqCommand                      0x4E31A0
#define KeypressHandler__ClearCommandStateArray                    0x4E2F70
#define KeypressHandler__HandleKeyDown                             0x4E1B80
#define KeypressHandler__HandleKeyUp                               0x4E1E80
#define KeypressHandler__SaveKeymapping                            0x4E3040

// MapViewMap 
#define MapViewMap__Clear                                          0x598C60
#define MapViewMap__SaveEx                                         0x599630

// StringTable 
#define StringTable__getString                                     0x5FD460
