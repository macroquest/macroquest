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
#define __ExpectedVersionDate                                     "Feb 20 2007"
#define __ExpectedVersionTime                                     "10:32:00"
#define __ActualVersionDate                                        0x6CD654
#define __ActualVersionTime                                        0x6CD660

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4E1F10
#define __MemChecker1                                              0x5F2A10
#define __MemChecker2                                              0x510DA0
#define __MemChecker3                                              0x510E50
#define __MemChecker4                                              0x5EDCA0
#define __EncryptPad0                                              0x721788
#define __EncryptPad1                                              0x72AE98
#define __EncryptPad2                                              0x723CD8
#define __EncryptPad3                                              0x7240D8
#define __EncryptPad4                                              0x72A690

// Direct Input
#define DI8__Main                                                  0x958D7C
#define DI8__Keyboard                                              0x958D80
#define DI8__Mouse                                                 0x958D84
#define __AltTimerReady                                            0x8F4FBA
#define __Attack                                                   0x95262A
#define __Autofire                                                 0x95262B
#define __BindList                                                 0x71CA18
#define __Clicks                                                   0x8F40E4
#define __CommandList                                              0x71D208
#define __CurrentMapLabel                                          0x963E44
#define __CurrentSocial                                            0x7194B8
#define __DoAbilityAvailable                                       0x8F4F54
#define __DoAbilityList                                            0x92A170
#define __DrawHandler                                              0x972A9C
#define __GroupCount                                               0x8D4838
#define __GroupLeader                                              0x8D4994
#define __Guilds                                                   0x8D6328
#define __gWorld                                                   0x8D6290
#define __HotkeyPage                                               0x95155C
#define __HWnd                                                     0x958D24
#define __InChatMode                                               0x8F4020
#define __LastTell                                                 0x8F5878
#define __Mouse                                                    0x958D88
#define __MouseLook                                                0x8F40B2
#define __NetStatusToggle                                          0x8F40B4
#define __PCNames                                                  0x8F52D0
#define __RangeAttackReady                                         0x8F4FB8
#define __RunWalkState                                             0x8F4024
#define __ScreenMode                                               0x824320
#define __ScreenX                                                  0x8F3FE8
#define __ScreenY                                                  0x8F3FEC
#define __ServerHost                                               0x8D478C
#define __ServerName                                               0x92A130
#define __ShowNames                                                0x8F51A8
#define __Socials                                                  0x92A230


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x8EDF78
#define instEQZoneInfo                                             0x8F4250
#define instKeypressHandler                                        0x9526FC
#define pinstActiveBanker                                          0x8D6308
#define pinstActiveCorpse                                          0x8D630C
#define pinstActiveGMaster                                         0x8D6310
#define pinstActiveMerchant                                        0x8D6304
#define pinstAltAdvManager                                         0x824FF0
#define pinstAuraMgr                                               0x730050
#define pinstBandageTarget                                         0x8D62F0
#define pinstCamActor                                              0x824AE4
#define pinstCDBStr                                                0x8241A0
#define pinstCDisplay                                              0x8D6318
#define pinstCEverQuest                                            0x958EF0
#define pinstCharData                                              0x8D62D8
#define pinstCharSpawn                                             0x8D62FC
#define pinstControlledMissile                                     0x8D62D4
#define pinstControlledPlayer                                      0x8D62FC
#define pinstCSidlManager                                          0x9722EC
#define pinstCXWndManager                                          0x9722E4
#define instDynamicZone                                            0x8F3A38
#define pinstDZMember                                              0x8F3B48
#define pinstDZTimerInfo                                           0x8F3B4C
#define pinstEQItemList                                            0x8D62BC
#define instEQMisc                                                 0x824158
#define pinstEQSoundManager                                        0x825014
#define instExpeditionLeader                                       0x8F3A82
#define instExpeditionName                                         0x8F3AC2
#define instGroup                                                  0x8D4838
#define pinstGroup                                                 0x8D4834
#define pinstImeManager                                            0x9722F0
#define pinstLocalPlayer                                           0x8D62E8
#define pinstModelPlayer                                           0x8D6314
#define pinstPCData                                                0x8D62D8
#define pinstSelectedItem                                          0x963C9C
#define pinstSkillMgr                                              0x955DE0
#define pinstSpawnManager                                          0x955D5C
#define pinstSpellManager                                          0x955DE4
#define pinstSpellSets                                             0x951560
#define pinstStringTable                                           0x8D62A0
#define pinstSwitchManager                                         0x8D4488
#define pinstTarget                                                0x8D6300
#define pinstTargetObject                                          0x8D62DC
#define pinstTargetSwitch                                          0x8D62E0
#define pinstTaskMember                                            0x824138
#define pinstTrackTarget                                           0x8D62F4
#define pinstTradeTarget                                           0x8D62E4
#define instTributeActive                                          0x82417D
#define pinstViewActor                                             0x824AE0
#define pinstWorldData                                             0x8D62B8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x72E588
#define pinstCAudioTriggersWindow                                  0x72E56C
#define pinstCCharacterSelect                                      0x8249F0
#define pinstCFacePick                                             0x8249A8
#define pinstCNoteWnd                                              0x8249AC
#define pinstCBookWnd                                              0x8249B0
#define pinstCPetInfoWnd                                           0x8249B4
#define pinstCTrainWnd                                             0x8249B8
#define pinstCSkillsWnd                                            0x8249BC
#define pinstCSkillsSelectWnd                                      0x8249C0
#define pinstCCombatSkillSelectWnd                                 0x8249C4
#define pinstCFriendsWnd                                           0x8249C8
#define pinstCAuraWnd                                              0x8249CC
#define pinstCRespawnWnd                                           0x8249D0
#define pinstCBandolierWnd                                         0x8249D4
#define pinstCPotionBeltWnd                                        0x8249D8
#define pinstCAAWnd                                                0x8249DC
#define pinstCGroupSearchFiltersWnd                                0x8249E0
#define pinstCLoadskinWnd                                          0x8249E4
#define pinstCAlarmWnd                                             0x8249E8
#define pinstCMusicPlayerWnd                                       0x8249EC
#define pinstCMailWnd                                              0x8249F4
#define pinstCMailCompositionWnd                                   0x8249F8
#define pinstCMailAddressBookWnd                                   0x8249FC
#define pinstCRaidWnd                                              0x824A04
#define pinstCRaidOptionsWnd                                       0x824A08
#define pinstCBreathWnd                                            0x824A0C
#define pinstCMapViewWnd                                           0x824A10
#define pinstCMapToolbarWnd                                        0x824A14
#define pinstCEditLabelWnd                                         0x824A18
#define pinstCTargetWnd                                            0x824A1C
#define pinstCColorPickerWnd                                       0x824A20
#define pinstCPlayerWnd                                            0x824A24
#define pinstCOptionsWnd                                           0x824A28
#define pinstCBuffWindowNORMAL                                     0x824A2C
#define pinstCBuffWindowSHORT                                      0x824A30
#define pinstCharacterCreation                                     0x824A34
#define pinstCCursorAttachment                                     0x824A38
#define pinstCCastingWnd                                           0x824A3C
#define pinstCCastSpellWnd                                         0x824A40
#define pinstCSpellBookWnd                                         0x824A44
#define pinstCInventoryWnd                                         0x824A48
#define pinstCBankWnd                                              0x824A4C
#define pinstCQuantityWnd                                          0x824A50
#define pinstCLootWnd                                              0x824A54
#define pinstCActionsWnd                                           0x824A58
#define pinstCCombatAbilityWnd                                     0x824A5C
#define pinstCMerchantWnd                                          0x824A60
#define pinstCTradeWnd                                             0x824A64
#define pinstCSelectorWnd                                          0x824A68
#define pinstCBazaarWnd                                            0x824A6C
#define pinstCBazaarSearchWnd                                      0x824A70
#define pinstCGiveWnd                                              0x824A74
#define pinstCTrackingWnd                                          0x824A78
#define pinstCInspectWnd                                           0x824A7C
#define pinstCSocialEditWnd                                        0x824A80
#define pinstCFeedbackWnd                                          0x824A84
#define pinstCBugReportWnd                                         0x824A88
#define pinstCVideoModesWnd                                        0x824A8C
#define pinstCTextEntryWnd                                         0x824A94
#define pinstCFileSelectionWnd                                     0x824A98
#define pinstCCompassWnd                                           0x824A9C
#define pinstCPlayerNotesWnd                                       0x824AA0
#define pinstCGemsGameWnd                                          0x824AA4
#define pinstCTimeLeftWnd                                          0x824AA8
#define pinstCPetitionQWnd                                         0x824AAC
#define pinstCSoulmarkWnd                                          0x824AB0
#define pinstCStoryWnd                                             0x824AB4
#define pinstCJournalTextWnd                                       0x824AB8
#define pinstCJournalCatWnd                                        0x824ABC
#define pinstCBodyTintWnd                                          0x824AC0
#define pinstCServerListWnd                                        0x824AC4
#define pinstCAvaZoneWnd                                           0x824AC8
#define pinstCBlockedBuffWnd                                       0x824ACC
#define pinstCBlockedPetBuffWnd                                    0x824AD0
#define pinstCInvSlotMgr                                           0x824AD4
#define pinstCContainerMgr                                         0x824AD8
#define pinstCAdventureLeaderboardWnd                              0x9614BC
#define pinstCAdventureRequestWnd                                  0x9614D8
#define pinstCAltStorageWnd                                        0x961538
#define pinstCAdventureStatsWnd                                    0x9614F4
#define pinstCBarterMerchantWnd                                    0x9616EC
#define pinstCBarterSearchWnd                                      0x961708
#define pinstCBarterWnd                                            0x961724
#define pinstCChatManager                                          0x961904
#define pinstCDynamicZoneWnd                                       0x9619E0
#define pinstCEQMainWnd                                            0x961A50
#define pinstCFellowshipWnd                                        0x961AB4
#define pinstCFindLocationWnd                                      0x961AE8
#define pinstCGroupSearchWnd                                       0x961BBC
#define pinstCGroupWnd                                             0x961BB4
#define pinstCGuildBankWnd                                         0x961BD0
#define pinstCGuildMgmtWnd                                         0x963BF0
#define pinstCGuildTributeMasterWnd                                0x963C10
#define pinstCHotButtonWnd                                         0x963C2C
#define pinstCHotButtonWnd1                                        0x963C2C
#define pinstCHotButtonWnd2                                        0x963C30
#define pinstCHotButtonWnd3                                        0x963C34
#define pinstCHotButtonWnd4                                        0x963C38
#define pinstCItemDisplayManager                                   0x963CD0
#define pinstCItemExpTransferWnd                                   0x963CF0
#define pinstCLeadershipWnd                                        0x963D6C
#define pinstCLFGuildWnd                                           0x963D88
#define pinstCMIZoneSelectWnd                                      0x963EAC
#define pinstCAdventureMerchantWnd                                 0x963FA4
#define pinstCConfirmationDialog                                   0x963FC0
#define pinstCPopupWndManager                                      0x963FC0
#define pinstCProgressionSelectionWnd                              0x963FF4
#define pinstCPvPLeaderboardWnd                                    0x964010
#define pinstCPvPStatsWnd                                          0x96402C
#define pinstCSystemInfoDialogBox                                  0x9649AC
#define pinstCTargetOfTargetWnd                                    0x9649C8
#define pinstCTaskSelectWnd                                        0x9649FC
#define pinstCTaskTemplateSelectWnd                                0x964A18
#define pinstCTaskWnd                                              0x964A34
#define pinstCTipWndOFDAY                                          0x964A80
#define pinstCTipWndCONTEXT                                        0x964A84
#define pinstCTitleWnd                                             0x964AA0
#define pinstCTradeskillWnd                                        0x964AE4
#define pinstCTributeBenefitWnd                                    0x964B30
#define pinstCTributeMasterWnd                                     0x964B4C
#define pinstCContextMenuManager                                   0x9723AC
#define pinstCVoiceMacroWnd                                        0x955E94


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4A5BB0
#define __ConvertItemTags                                          0x49A880
#define __ExecuteCmd                                               0x48C250
#define __get_melee_range                                          0x491300
#define __GetGaugeValueFromEQ                                      0x5C8130
#define __GetLabelFromEQ                                           0x5C8860
#define __NewUIINI                                                 0x5C7D20
#define __ProcessGameEvents                                        0x4D07D0
#define __SendMessage                                              0x4B30F0
#define CrashDetected                                              0x510A50
#define DrawNetStatus                                              0x4E4C50
#define Util__FastTime                                             0x5F30F0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x46CD10
#define AltAdvManager__IsAbilityReady                              0x46CD50
#define AltAdvManager__GetAltAbility                               0x46CF40

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x524E60

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x52E2A0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x63C5B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5420F0
#define CChatManager__InitContextMenu                              0x542880

// CChatService
#define CChatService__GetNumberOfFriends                           0x617B70
#define CChatService__GetFriendName                                0x617B80

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x546A00

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x631E20
#define CComboWnd__Draw                                            0x631FD0
#define CComboWnd__GetCurChoice                                    0x631DD0
#define CComboWnd__GetListRect                                     0x6322B0
#define CComboWnd__GetTextRect                                     0x631E50
#define CComboWnd__InsertChoice                                    0x632320
#define CComboWnd__SetColors                                       0x631D60
#define CComboWnd__SetChoice                                       0x631D90

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x54D040
#define CContainerWnd__vftable                                     0x6D3898

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45C460
#define CDisplay__GetClickedActor                                  0x459D00
#define CDisplay__GetUserDefinedColor                              0x459170
#define CDisplay__GetWorldFilePath                                 0x458720
#define CDisplay__ReloadUI                                         0x4681E0
#define CDisplay__WriteTextHD2                                     0x45DC00

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x51F060
#define CEditBaseWnd__SetSel                                       0x654B00

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6521F0
#define CEditWnd__GetCharIndexPt                                   0x653040
#define CEditWnd__GetDisplayString                                 0x652380
#define CEditWnd__GetHorzOffset                                    0x652600
#define CEditWnd__GetLineForPrintableChar                          0x652AF0
#define CEditWnd__GetSelStartPt                                    0x653290
#define CEditWnd__GetSTMLSafeText                                  0x6527A0
#define CEditWnd__PointFromPrintableChar                           0x652C00
#define CEditWnd__SelectableCharFromPoint                          0x652D80
#define CEditWnd__SetEditable                                      0x652770

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4B7180
#define CEverQuest__DropHeldItemOnGround                           0x4BBAD0
#define CEverQuest__dsp_chat                                       0x4BC6B0
#define CEverQuest__EnterZone                                      0x4CF3C0
#define CEverQuest__GetBodyTypeDesc                                0x4B48F0
#define CEverQuest__GetClassDesc                                   0x4B4050
#define CEverQuest__GetClassThreeLetterCode                        0x4B4650
#define CEverQuest__GetDeityDesc                                   0x4B4F40
#define CEverQuest__GetLangDesc                                    0x4B4C60
#define CEverQuest__GetRaceDesc                                    0x4B4F10
#define CEverQuest__InterpretCmd                                   0x4BCFC0
#define CEverQuest__LeftClickedOnPlayer                            0x4CDF80
#define CEverQuest__RightClickedOnPlayer                           0x4CE340
#define CEverQuest__SetGameState                                   0x4B7250

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x558010
#define CGaugeWnd__CalcLinesFillRect                               0x558080
#define CGaugeWnd__Draw                                            0x558410

// CGuild
#define CGuild__FindMemberByName                                   0x415800

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x56DE90

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x575900
#define CInvSlotMgr__MoveItem                                      0x575AA0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5769B0

// CInvSLot
#define CInvSlot__SliderComplete                                   0x574910

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x57DE30
#define CItemDisplayWnd__SetSpell                                  0x5C6040

// CLabel 
#define CLabel__Draw                                               0x583310

// CListWnd 
#define CListWnd__AddColumn                                        0x631B70
#define CListWnd__AddColumn1                                       0x631660
#define CListWnd__AddLine                                          0x631240
#define CListWnd__AddString                                        0x631410
#define CListWnd__CalculateFirstVisibleLine                        0x62E520
#define CListWnd__CalculateVSBRange                                0x6301D0
#define CListWnd__ClearAllSel                                      0x62DC90
#define CListWnd__CloseAndUpdateEditWindow                         0x62EB60
#define CListWnd__Compare                                          0x62EF10
#define CListWnd__Draw                                             0x62FEC0
#define CListWnd__DrawColumnSeparators                             0x62FD30
#define CListWnd__DrawHeader                                       0x62DE60
#define CListWnd__DrawItem                                         0x62F620
#define CListWnd__DrawLine                                         0x62FA71
#define CListWnd__DrawSeparator                                    0x62FA71
#define CListWnd__EnsureVisible                                    0x62E570
#define CListWnd__ExtendSel                                        0x62F550
#define CListWnd__GetColumnMinWidth                                0x62DA30
#define CListWnd__GetColumnWidth                                   0x62D970
#define CListWnd__GetCurSel                                        0x62D430
#define CListWnd__GetHeaderRect                                    0x62D540
#define CListWnd__GetItemAtPoint                                   0x62E870
#define CListWnd__GetItemAtPoint1                                  0x62E8E0
#define CListWnd__GetItemData                                      0x62D720
#define CListWnd__GetItemHeight                                    0x62E2C0
#define CListWnd__GetItemIcon                                      0x62D8B0
#define CListWnd__GetItemRect                                      0x62E650
#define CListWnd__GetItemText                                      0x62D760
#define CListWnd__GetSelList                                       0x631540
#define CListWnd__GetSeparatorRect                                 0x62EE50
#define CListWnd__RemoveLine                                       0x631B20
#define CListWnd__SetColors                                        0x62D4B0
#define CListWnd__SetColumnJustification                           0x62DA90
#define CListWnd__SetColumnWidth                                   0x62D9F0
#define CListWnd__SetCurSel                                        0x62D470
#define CListWnd__SetItemColor                                     0x630E10
#define CListWnd__SetItemData                                      0x62DD30
#define CListWnd__SetItemText                                      0x630D90
#define CListWnd__ShiftColumnSeparator                             0x62F4C0
#define CListWnd__Sort                                             0x631BA0
#define CListWnd__ToggleSel                                        0x62DC00

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5960F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x597AC0
#define CMerchantWnd__RequestBuyItem                               0x598C90
#define CMerchantWnd__RequestSellItem                              0x597D20
#define CMerchantWnd__SelectBuySellSlot                            0x5989D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6410C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5209E0
#define CSidlScreenWnd__CalculateVSBRange                          0x6375A0
#define CSidlScreenWnd__ConvertToRes                               0x637CF0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x638510
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6397D0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x639880
#define CSidlScreenWnd__dCSidlScreenWnd                            0x639080
#define CSidlScreenWnd__DrawSidlPiece                              0x6381F0
#define CSidlScreenWnd__EnableIniStorage                           0x637CA0
#define CSidlScreenWnd__GetSidlPiece                               0x6383F0
#define CSidlScreenWnd__Init1                                      0x6395E0
#define CSidlScreenWnd__LoadIniInfo                                0x6385C0
#define CSidlScreenWnd__LoadIniListWnd                             0x637E60
#define CSidlScreenWnd__LoadSidlScreen                             0x638020
#define CSidlScreenWnd__StoreIniInfo                               0x6377E0
#define CSidlScreenWnd__WndNotification                            0x638150

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x506060

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x656980
#define CSliderWnd__SetValue                                       0x656A80
#define CSliderWnd__SetNumTicks                                    0x656FC0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5C4DA0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x64B4A0
#define CStmlWnd__CalculateVSBRange                                0x643840
#define CStmlWnd__CanBreakAtCharacter                              0x643980
#define CStmlWnd__FastForwardToEndOfTag                            0x644480
#define CStmlWnd__GetNextTagPiece                                  0x6443A0
#define CStmlWnd__GetSTMLText                                      0x5469A0
#define CStmlWnd__GetThisChar                                      0x673A80
#define CStmlWnd__GetVisiableText                                  0x645690
#define CStmlWnd__InitializeWindowVariables                        0x6477E0
#define CStmlWnd__MakeStmlColorTag                                 0x642F40
#define CStmlWnd__MakeWndNotificationTag                           0x642FE0
#define CStmlWnd__StripFirstSTMLLines                              0x64B220
#define CStmlWnd__UpdateHistoryString                              0x645EE0

// CTabWnd 
#define CTabWnd__Draw                                              0x656200
#define CTabWnd__DrawCurrentPage                                   0x655B70
#define CTabWnd__DrawTab                                           0x655950
#define CTabWnd__GetCurrentPage                                    0x655E70
#define CTabWnd__GetPageClientRect                                 0x655620
#define CTabWnd__GetPageFromTabIndex                               0x655880
#define CTabWnd__GetPageInnerRect                                  0x655680
#define CTabWnd__GetTabInnerRect                                   0x655800
#define CTabWnd__GetTabRect                                        0x655710
#define CTabWnd__IndexInBounds                                     0x65591D
#define CTabWnd__InsertPage                                        0x656420
#define CTabWnd__SetPage                                           0x655EB0
#define CTabWnd__SetPageRect                                       0x656130
#define CTabWnd__UpdatePage                                        0x6563A0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x412540

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x639BE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x65D1D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x62D1A0

// CXRect 
#define CXRect__CenterPoint                                        0x524610

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4120E0
#define CXStr__CXStr1                                              0x501920
#define CXStr__CXStr3                                              0x5F47A0
#define CXStr__dCXStr                                              0x403580
#define CXStr__operator_equal1                                     0x5F4960
#define CXStr__operator_plus_equal1                                0x5F5850

// CXWnd 
#define CXWnd__BringToTop                                          0x632B70
#define CXWnd__Center                                              0x6362D0
#define CXWnd__ClrFocus                                            0x632850
#define CXWnd__DoAllDrawing                                        0x636F80
#define CXWnd__DrawChildren                                        0x6370B0
#define CXWnd__DrawColoredRect                                     0x632DE0
#define CXWnd__DrawTooltip                                         0x636EB0
#define CXWnd__DrawTooltipAtPoint                                  0x636110
#define CXWnd__GetBorderFrame                                      0x633320
#define CXWnd__GetChildWndAt                                       0x635C00
#define CXWnd__GetClientClipRect                                   0x6331D0
#define CXWnd__GetFirstChildWnd                                    0x632C10
#define CXWnd__GetNextChildWnd                                     0x635BC0
#define CXWnd__GetNextSib                                          0x632C30
#define CXWnd__GetScreenClipRect                                   0x6364F0
#define CXWnd__GetScreenRect                                       0x633480
#define CXWnd__GetTooltipRect                                      0x633000
#define CXWnd__GetWindowTextA                                      0x518200
#define CXWnd__IsActive                                            0x64D440
#define CXWnd__IsDescendantOf                                      0x633250
#define CXWnd__IsReallyVisible                                     0x635BA0
#define CXWnd__IsType                                              0x657E30
#define CXWnd__Move                                                0x6356B0
#define CXWnd__Move1                                               0x635750
#define CXWnd__ProcessTransition                                   0x632B40
#define CXWnd__Refade                                              0x632900
#define CXWnd__Resize                                              0x636630
#define CXWnd__Right                                               0x636440
#define CXWnd__SetFirstChildPointer                                0x6336F0
#define CXWnd__SetFocus                                            0x634A00
#define CXWnd__SetKeyTooltip                                       0x633760
#define CXWnd__SetMouseOver                                        0x633730
#define CXWnd__SetNextSibPointer                                   0x633710
#define CXWnd__StartFade                                           0x632B90

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x64E890
#define CXWndManager__DrawWindows                                  0x64E4D0
#define CXWndManager__GetFirstChildWnd                             0x64DDE0
#define CXWndManager__GetKeyboardFlags                             0x64D120
#define CXWndManager__HandleKeyboardMsg                            0x64D630
#define CXWndManager__RemoveWnd                                    0x64D550

// CDBStr
#define CDBStr__GetString                                          0x455C90

// EQ_Character 
#define EQ_Character__CastRay                                      0x67F480
#define EQ_Character__CastSpell                                    0x4218D0
#define EQ_Character__Cur_HP                                       0x428C70
#define EQ_Character__GetAACastingTimeModifier                     0x41C840
#define EQ_Character__GetCharInfo2                                 0x5FFFD0
#define EQ_Character__GetFocusCastingTimeModifier                  0x418EE0
#define EQ_Character__GetFocusRangeModifier                        0x419010
#define EQ_Character__Max_Endurance                                0x427AF0
#define EQ_Character__Max_HP                                       0x4279A0
#define EQ_Character__Max_Mana                                     0x4E9C00
#define EQ_Character__doCombatAbility                              0x4E8A80
#define EQ_Character__UseSkill                                     0x434010
#define EQ_Character__GetConLevel                                  0x4E6030

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4DB860
#define EQ_Item__GetItemLinkHash                                   0x5FF230
#define EQ_Item__IsStackable                                       0x5F9C00

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x46DE60
#define EQ_LoadingS__Array                                         0x71AF30

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4ECAA0
#define EQ_PC__GetAltAbilityIndex                                  0x604DF0
#define EQ_PC__GetCombatAbility                                    0x604E80
#define EQ_PC__GetCombatAbilityTimer                               0x604F30
#define EQ_PC__GetItemTimerValue                                   0x4E7DE0
#define EQ_PC__HasLoreItem                                         0x4EB0E0

// EQItemList 
#define EQItemList__dEQItemList                                    0x48FB30
#define EQItemList__EQItemList                                     0x48FA80

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x455760

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4F1450
#define EQPlayer__dEQPlayer                                        0x4F5820
#define EQPlayer__DoAttack                                         0x500C60
#define EQPlayer__EQPlayer                                         0x4F7F20
#define EQPlayer__SetNameSpriteState                               0x4F3AD0
#define EQPlayer__SetNameSpriteTint                                0x4F14C0
#define EQPlayer__IsBodyType_j                                     0x67EEB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4F8D20

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4DD730
#define KeypressHandler__AttachKeyToEqCommand                      0x4DD770
#define KeypressHandler__ClearCommandStateArray                    0x4DD540
#define KeypressHandler__HandleKeyDown                             0x4DC150
#define KeypressHandler__HandleKeyUp                               0x4DC450
#define KeypressHandler__SaveKeymapping                            0x4DD610

// MapViewMap 
#define MapViewMap__Clear                                          0x592120
#define MapViewMap__SaveEx                                         0x592AF0

// StringTable 
#define StringTable__getString                                     0x5F9430
