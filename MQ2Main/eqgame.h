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
#define __ExpectedVersionDate                                     "Sep  7 2007"
#define __ExpectedVersionTime                                     "09:11:49"
#define __ActualVersionDate                                        0x6F5E14
#define __ActualVersionTime                                        0x6F5E20

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4EBA30
#define __MemChecker1                                              0x644E60
#define __MemChecker2                                              0x51D130
#define __MemChecker3                                              0x51D1E0
#define __MemChecker4                                              0x60E3E0
#define __EncryptPad0                                              0x752E68
#define __EncryptPad1                                              0x75CB78
#define __EncryptPad2                                              0x7553D0
#define __EncryptPad3                                              0x7557D0
#define __EncryptPad4                                              0x75C290

// Direct Input
#define DI8__Main                                                  0x98AD8C
#define DI8__Keyboard                                              0x98AD90
#define DI8__Mouse                                                 0x98AD94
#define __AltTimerReady                                            0x926C46
#define __Attack                                                   0x98452E
#define __Autofire                                                 0x98452F
#define __BindList                                                 0x74E070
#define __Clicks                                                   0x925D70
#define __CommandList                                              0x74E870
#define __CurrentMapLabel                                          0x995EC4
#define __CurrentSocial                                            0x74A500
#define __DoAbilityAvailable                                       0x926BE0
#define __DoAbilityList                                            0x95C074
#define __DrawHandler                                              0x9A512C
#define __GroupCount                                               0x906490
#define __GroupLeader                                              0x9065EC
#define __Guilds                                                   0x907FB0
#define __gWorld                                                   0x907EF0
#define __HotkeyPage                                               0x983460
#define __HWnd                                                     0x98AD34
#define __InChatMode                                               0x925CA8
#define __LastTell                                                 0x92750C
#define __LMouseHeldTime                                           0x925D90
#define __Mouse                                                    0x98AD98
#define __MouseLook                                                0x925D3E
#define __NetStatusToggle                                          0x925D40
#define __PCNames                                                  0x926F64
#define __RangeAttackReady                                         0x926C44
#define __RMouseHeldTime                                           0x925D8C
#define __RunWalkState                                             0x925CAC
#define __ScreenMode                                               0x855DFC
#define __ScreenX                                                  0x925C70
#define __ScreenY                                                  0x925C74
#define __ScreenXMax                                               0x925C78
#define __ScreenYMax                                               0x925C7C
#define __ServerHost                                               0x9063E4
#define __ServerName                                               0x95C034
#define __ShowNames                                                0x926E38
#define __Socials                                                  0x95C134


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x91FC00
#define instEQZoneInfo                                             0x925EDC
#define instKeypressHandler                                        0x984618
#define pinstActiveBanker                                          0x907F88
#define pinstActiveCorpse                                          0x907F8C
#define pinstActiveGMaster                                         0x907F90
#define pinstActiveMerchant                                        0x907F84
#define pinstAltAdvManager                                         0x856C48
#define pinstAuraMgr                                               0x761C94
#define pinstBandageTarget                                         0x907F70
#define pinstCamActor                                              0x856738
#define pinstCDBStr                                                0x855DE8
#define pinstCDisplay                                              0x907F98
#define pinstCEverQuest                                            0x98AF10
#define pinstCharData                                              0x907F54
#define pinstCharSpawn                                             0x907F7C
#define pinstControlledMissile                                     0x907F50
#define pinstControlledPlayer                                      0x907F7C
#define pinstCSidlManager                                          0x9A497C
#define pinstCXWndManager                                          0x9A4974
#define instDynamicZone                                            0x9256C0
#define pinstDZMember                                              0x9257D0
#define pinstDZTimerInfo                                           0x9257D4
#define pinstEQItemList                                            0x907F38
#define instEQMisc                                                 0x855DA0
#define pinstEQSoundManager                                        0x856C6C
#define instExpeditionLeader                                       0x92570A
#define instExpeditionName                                         0x92574A
#define instGroup                                                  0x906490
#define pinstGroup                                                 0x90648C
#define pinstImeManager                                            0x9A4980
#define pinstLocalPlayer                                           0x907F68
#define pinstModelPlayer                                           0x907F94
#define pinstPCData                                                0x907F54
#define pinstSelectedItem                                          0x995D1C
#define pinstSkillMgr                                              0x987D14
#define pinstSpawnManager                                          0x987C94
#define pinstSpellManager                                          0x987D18
#define pinstSpellSets                                             0x983464
#define pinstStringTable                                           0x907F0C
#define pinstSwitchManager                                         0x9060E0
#define pinstTarget                                                0x907F80
#define pinstTargetObject                                          0x907F58
#define pinstTargetSwitch                                          0x907F5C
#define pinstTaskMember                                            0x855D80
#define pinstTrackTarget                                           0x907F74
#define pinstTradeTarget                                           0x907F64
#define instTributeActive                                          0x855DC5
#define pinstViewActor                                             0x856734
#define pinstWorldData                                             0x907F34


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x7601C8
#define pinstCAudioTriggersWindow                                  0x7601AC
#define pinstCCharacterSelect                                      0x856648
#define pinstCFacePick                                             0x856600
#define pinstCNoteWnd                                              0x856604
#define pinstCBookWnd                                              0x856608
#define pinstCPetInfoWnd                                           0x85660C
#define pinstCTrainWnd                                             0x856610
#define pinstCSkillsWnd                                            0x856614
#define pinstCSkillsSelectWnd                                      0x856618
#define pinstCCombatSkillSelectWnd                                 0x85661C
#define pinstCFriendsWnd                                           0x856620
#define pinstCAuraWnd                                              0x856624
#define pinstCRespawnWnd                                           0x856628
#define pinstCBandolierWnd                                         0x85662C
#define pinstCPotionBeltWnd                                        0x856630
#define pinstCAAWnd                                                0x856634
#define pinstCGroupSearchFiltersWnd                                0x856638
#define pinstCLoadskinWnd                                          0x85663C
#define pinstCAlarmWnd                                             0x856640
#define pinstCMusicPlayerWnd                                       0x856644
#define pinstCMailWnd                                              0x85664C
#define pinstCMailCompositionWnd                                   0x856650
#define pinstCMailAddressBookWnd                                   0x856654
#define pinstCRaidWnd                                              0x85665C
#define pinstCRaidOptionsWnd                                       0x856660
#define pinstCBreathWnd                                            0x856664
#define pinstCMapViewWnd                                           0x856668
#define pinstCMapToolbarWnd                                        0x85666C
#define pinstCEditLabelWnd                                         0x856670
#define pinstCTargetWnd                                            0x856674
#define pinstCColorPickerWnd                                       0x856678
#define pinstCPlayerWnd                                            0x85667C
#define pinstCOptionsWnd                                           0x856680
#define pinstCBuffWindowNORMAL                                     0x856684
#define pinstCBuffWindowSHORT                                      0x856688
#define pinstCharacterCreation                                     0x85668C
#define pinstCCursorAttachment                                     0x856690
#define pinstCCastingWnd                                           0x856694
#define pinstCCastSpellWnd                                         0x856698
#define pinstCSpellBookWnd                                         0x85669C
#define pinstCInventoryWnd                                         0x8566A0
#define pinstCBankWnd                                              0x8566A4
#define pinstCQuantityWnd                                          0x8566A8
#define pinstCLootWnd                                              0x8566AC
#define pinstCActionsWnd                                           0x8566B0
#define pinstCCombatAbilityWnd                                     0x8566B4
#define pinstCMerchantWnd                                          0x8566B8
#define pinstCTradeWnd                                             0x8566BC
#define pinstCSelectorWnd                                          0x8566C0
#define pinstCBazaarWnd                                            0x8566C4
#define pinstCBazaarSearchWnd                                      0x8566C8
#define pinstCGiveWnd                                              0x8566CC
#define pinstCTrackingWnd                                          0x8566D0
#define pinstCInspectWnd                                           0x8566D4
#define pinstCSocialEditWnd                                        0x8566D8
#define pinstCFeedbackWnd                                          0x8566DC
#define pinstCBugReportWnd                                         0x8566E0
#define pinstCVideoModesWnd                                        0x8566E4
#define pinstCTextEntryWnd                                         0x8566EC
#define pinstCFileSelectionWnd                                     0x8566F0
#define pinstCCompassWnd                                           0x8566F4
#define pinstCPlayerNotesWnd                                       0x8566F8
#define pinstCGemsGameWnd                                          0x8566FC
#define pinstCTimeLeftWnd                                          0x856700
#define pinstCPetitionQWnd                                         0x856704
#define pinstCSoulmarkWnd                                          0x856708
#define pinstCStoryWnd                                             0x85670C
#define pinstCJournalTextWnd                                       0x856710
#define pinstCJournalCatWnd                                        0x856714
#define pinstCBodyTintWnd                                          0x856718
#define pinstCServerListWnd                                        0x85671C
#define pinstCAvaZoneWnd                                           0x856720
#define pinstCBlockedBuffWnd                                       0x856724
#define pinstCBlockedPetBuffWnd                                    0x856728
#define pinstCInvSlotMgr                                           0x85672C
#define pinstCContainerMgr                                         0x856730
#define pinstCAdventureLeaderboardWnd                              0x9934F4
#define pinstCAdventureRequestWnd                                  0x993510
#define pinstCAltStorageWnd                                        0x993570
#define pinstCAdventureStatsWnd                                    0x99352C
#define pinstCBarterMerchantWnd                                    0x993724
#define pinstCBarterSearchWnd                                      0x993740
#define pinstCBarterWnd                                            0x99375C
#define pinstCChatManager                                          0x993954
#define pinstCDynamicZoneWnd                                       0x993A4C
#define pinstCEQMainWnd                                            0x993ABC
#define pinstCFellowshipWnd                                        0x993B20
#define pinstCFindLocationWnd                                      0x993B54
#define pinstCGroupSearchWnd                                       0x993C04
#define pinstCGroupWnd                                             0x993C20
#define pinstCGuildBankWnd                                         0x993C3C
#define pinstCGuildMgmtWnd                                         0x995C58
#define pinstCGuildTributeMasterWnd                                0x995C78
#define pinstCHotButtonWnd                                         0x995C94
#define pinstCHotButtonWnd1                                        0x995C94
#define pinstCHotButtonWnd2                                        0x995C98
#define pinstCHotButtonWnd3                                        0x995C9C
#define pinstCHotButtonWnd4                                        0x995CA0
#define pinstCItemDisplayManager                                   0x995D50
#define pinstCItemExpTransferWnd                                   0x995D70
#define pinstCLeadershipWnd                                        0x995DEC
#define pinstCLFGuildWnd                                           0x995E08
#define pinstCMIZoneSelectWnd                                      0x995F2C
#define pinstCAdventureMerchantWnd                                 0x996024
#define pinstCConfirmationDialog                                   0x996040
#define pinstCPopupWndManager                                      0x996040
#define pinstCProgressionSelectionWnd                              0x996074
#define pinstCPvPLeaderboardWnd                                    0x996090
#define pinstCPvPStatsWnd                                          0x9960AC
#define pinstCSystemInfoDialogBox                                  0x996A2C
#define pinstCTargetOfTargetWnd                                    0x996A48
#define pinstCTaskSelectWnd                                        0x996A7C
#define pinstCTaskTemplateSelectWnd                                0x996A98
#define pinstCTaskWnd                                              0x996AB4
#define pinstCTipWndOFDAY                                          0x996B48
#define pinstCTipWndCONTEXT                                        0x996B4C
#define pinstCTitleWnd                                             0x996B68
#define pinstCTradeskillWnd                                        0x996BAC
#define pinstCTributeBenefitWnd                                    0x996BF8
#define pinstCTributeMasterWnd                                     0x996C14
#define pinstCContextMenuManager                                   0x9A4A3C
#define pinstCVoiceMacroWnd                                        0x987DE4
#define pinstCHtmlWnd                                              0x987E00


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4ADFC0
#define __ConvertItemTags                                          0x4A2AB0
#define __ExecuteCmd                                               0x493FD0
#define __get_melee_range                                          0x4990E0
#define __GetGaugeValueFromEQ                                      0x5E0E50
#define __GetLabelFromEQ                                           0x5E1660
#define __NewUIINI                                                 0x5E0A40
#define __ProcessGameEvents                                        0x4D9920
#define __SendMessage                                              0x4BB750
#define CrashDetected                                              0x51C1F0
#define DrawNetStatus                                              0x4EE7A0
#define Util__FastTime                                             0x6454F0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x46EEA0
#define AltAdvManager__IsAbilityReady                              0x46EEE0
#define AltAdvManager__GetAltAbility                               0x46F030

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x532F80

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x53C430

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x661DC0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5504C0
#define CChatManager__InitContextMenu                              0x550C50

// CChatService
#define CChatService__GetNumberOfFriends                           0x635CA0
#define CChatService__GetFriendName                                0x635CB0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x554DC0
#define CChatWindow__WndNotification                               0x5557E0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x656FE0
#define CComboWnd__Draw                                            0x657190
#define CComboWnd__GetCurChoice                                    0x656F80
#define CComboWnd__GetListRect                                     0x657460
#define CComboWnd__GetTextRect                                     0x657010
#define CComboWnd__InsertChoice                                    0x6574D0
#define CComboWnd__SetColors                                       0x656F10
#define CComboWnd__SetChoice                                       0x656F40

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x55C040
#define CContainerWnd__vftable                                     0x6FC898

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45E450
#define CDisplay__GetClickedActor                                  0x45BC80
#define CDisplay__GetUserDefinedColor                              0x45B110
#define CDisplay__GetWorldFilePath                                 0x45A680
#define CDisplay__is3dON                                           0x459810
#define CDisplay__ReloadUI                                         0x46A150
#define CDisplay__WriteTextHD2                                     0x45EB50

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x52CD30
#define CEditBaseWnd__SetSel                                       0x67A6B0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x677D50
#define CEditWnd__GetCharIndexPt                                   0x678BA0
#define CEditWnd__GetDisplayString                                 0x677EE0
#define CEditWnd__GetHorzOffset                                    0x678180
#define CEditWnd__GetLineForPrintableChar                          0x678650
#define CEditWnd__GetSelStartPt                                    0x678DE0
#define CEditWnd__GetSTMLSafeText                                  0x678310
#define CEditWnd__PointFromPrintableChar                           0x678760
#define CEditWnd__SelectableCharFromPoint                          0x6788E0
#define CEditWnd__SetEditable                                      0x6782E0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4BF910
#define CEverQuest__DropHeldItemOnGround                           0x4C44D0
#define CEverQuest__dsp_chat                                       0x4C5160
#define CEverQuest__DoTellWindow                                   0x4C4600
#define CEverQuest__EnterZone                                      0x4D8410
#define CEverQuest__GetBodyTypeDesc                                0x4BCFB0
#define CEverQuest__GetClassDesc                                   0x4BC710
#define CEverQuest__GetClassThreeLetterCode                        0x4BCD10
#define CEverQuest__GetDeityDesc                                   0x4BD620
#define CEverQuest__GetLangDesc                                    0x4BD340
#define CEverQuest__GetRaceDesc                                    0x4BD5F0
#define CEverQuest__InterpretCmd                                   0x4C5AE0
#define CEverQuest__LeftClickedOnPlayer                            0x4D6FC0
#define CEverQuest__LMouseUp                                       0x4D9180
#define CEverQuest__RightClickedOnPlayer                           0x4D7390
#define CEverQuest__RMouseUp                                       0x4D8A30
#define CEverQuest__SetGameState                                   0x4BF9E0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5670D0
#define CGaugeWnd__CalcLinesFillRect                               0x567140
#define CGaugeWnd__Draw                                            0x5674D0

// CGuild
#define CGuild__FindMemberByName                                   0x415C00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x57CE70

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5860A0
#define CInvSlotMgr__MoveItem                                      0x586240

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x587160

// CInvSLot
#define CInvSlot__SliderComplete                                   0x585010

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x594D60
#define CItemDisplayWnd__SetSpell                                  0x5DED70

// CLabel 
#define CLabel__Draw                                               0x59A3A0

// CListWnd 
#define CListWnd__AddColumn                                        0x656D20
#define CListWnd__AddColumn1                                       0x656810
#define CListWnd__AddLine                                          0x6563F0
#define CListWnd__AddString                                        0x6565C0
#define CListWnd__CalculateFirstVisibleLine                        0x653720
#define CListWnd__CalculateVSBRange                                0x655390
#define CListWnd__ClearAllSel                                      0x652EA0
#define CListWnd__CloseAndUpdateEditWindow                         0x653D40
#define CListWnd__Compare                                          0x6540F0
#define CListWnd__Draw                                             0x655090
#define CListWnd__DrawColumnSeparators                             0x654F00
#define CListWnd__DrawHeader                                       0x653070
#define CListWnd__DrawItem                                         0x654800
#define CListWnd__DrawLine                                         0x654BB0
#define CListWnd__DrawSeparator                                    0x654FA0
#define CListWnd__EnsureVisible                                    0x653770
#define CListWnd__ExtendSel                                        0x654730
#define CListWnd__GetColumnMinWidth                                0x652C40
#define CListWnd__GetColumnWidth                                   0x652B80
#define CListWnd__GetCurSel                                        0x652630
#define CListWnd__GetHeaderRect                                    0x652750
#define CListWnd__GetItemAtPoint                                   0x653A50
#define CListWnd__GetItemAtPoint1                                  0x653AC0
#define CListWnd__GetItemData                                      0x652930
#define CListWnd__GetItemHeight                                    0x6534D0
#define CListWnd__GetItemIcon                                      0x652AC0
#define CListWnd__GetItemRect                                      0x653840
#define CListWnd__GetItemText                                      0x652970
#define CListWnd__GetSelList                                       0x6566F0
#define CListWnd__GetSeparatorRect                                 0x654030
#define CListWnd__RemoveLine                                       0x656CD0
#define CListWnd__SetColors                                        0x6526B0
#define CListWnd__SetColumnJustification                           0x652CA0
#define CListWnd__SetColumnWidth                                   0x652C00
#define CListWnd__SetCurSel                                        0x652670
#define CListWnd__SetItemColor                                     0x655FC0
#define CListWnd__SetItemData                                      0x652F40
#define CListWnd__SetItemText                                      0x655F40
#define CListWnd__ShiftColumnSeparator                             0x6546A0
#define CListWnd__Sort                                             0x656D50
#define CListWnd__ToggleSel                                        0x652E10

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5AD1F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5AEBC0
#define CMerchantWnd__RequestBuyItem                               0x5AFE60
#define CMerchantWnd__RequestSellItem                              0x5AEE10
#define CMerchantWnd__SelectBuySellSlot                            0x5AFBA0

// CObfuscator
#define CObfuscator__doit                                          0x637360

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6669C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x52E680
#define CSidlScreenWnd__CalculateVSBRange                          0x65C9A0
#define CSidlScreenWnd__ConvertToRes                               0x65D181
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x65DA30
#define CSidlScreenWnd__CSidlScreenWnd1                            0x65F1A0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x65F250
#define CSidlScreenWnd__dCSidlScreenWnd                            0x65EA50
#define CSidlScreenWnd__DrawSidlPiece                              0x65D710
#define CSidlScreenWnd__EnableIniStorage                           0x65D120
#define CSidlScreenWnd__GetSidlPiece                               0x65D910
#define CSidlScreenWnd__Init1                                      0x65EFC0
#define CSidlScreenWnd__LoadIniInfo                                0x65DE40
#define CSidlScreenWnd__LoadIniListWnd                             0x65D2D0
#define CSidlScreenWnd__LoadSidlScreen                             0x65D540
#define CSidlScreenWnd__StoreIniInfo                               0x65E5E0
#define CSidlScreenWnd__WndNotification                            0x65D670

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x50E4D0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x67B270
#define CSliderWnd__SetValue                                       0x67B370
#define CSliderWnd__SetNumTicks                                    0x67B8A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5DDAF0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x670E00
#define CStmlWnd__CalculateVSBRange                                0x6691E0
#define CStmlWnd__CanBreakAtCharacter                              0x669320
#define CStmlWnd__FastForwardToEndOfTag                            0x669E30
#define CStmlWnd__GetNextTagPiece                                  0x669D50
#define CStmlWnd__GetSTMLText                                      0x554D60
#define CStmlWnd__GetThisChar                                      0x699AC0
#define CStmlWnd__GetVisiableText                                  0x66B040
#define CStmlWnd__InitializeWindowVariables                        0x66D190
#define CStmlWnd__MakeStmlColorTag                                 0x668880
#define CStmlWnd__MakeWndNotificationTag                           0x668920
#define CStmlWnd__StripFirstSTMLLines                              0x670B90
#define CStmlWnd__UpdateHistoryString                              0x66B890

// CTabWnd 
#define CTabWnd__Draw                                              0x67C640
#define CTabWnd__DrawCurrentPage                                   0x67C040
#define CTabWnd__DrawTab                                           0x67BE20
#define CTabWnd__GetCurrentPage                                    0x67C2C0
#define CTabWnd__GetPageClientRect                                 0x67BAF0
#define CTabWnd__GetPageFromTabIndex                               0x67BD50
#define CTabWnd__GetPageInnerRect                                  0x67BB50
#define CTabWnd__GetTabInnerRect                                   0x67BCD0
#define CTabWnd__GetTabRect                                        0x67BBE0
#define CTabWnd__IndexInBounds                                     0x67BDED
#define CTabWnd__InsertPage                                        0x67C860
#define CTabWnd__SetPage                                           0x67C300
#define CTabWnd__SetPageRect                                       0x67C570
#define CTabWnd__UpdatePage                                        0x67C7E0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x412790

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x65F5B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x682D50

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6523A0

// CXRect 
#define CXRect__CenterPoint                                        0x5326D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412330
#define CXStr__CXStr1                                              0x403580
#define CXStr__CXStr3                                              0x646BE0
#define CXStr__dCXStr                                              0x403590
#define CXStr__operator_equal1                                     0x646DA0
#define CXStr__operator_plus_equal1                                0x647C90

// CXWnd 
#define CXWnd__BringToTop                                          0x657D50
#define CXWnd__Center                                              0x65B910
#define CXWnd__ClrFocus                                            0x657A40
#define CXWnd__DoAllDrawing                                        0x65C3A0
#define CXWnd__DrawChildren                                        0x65C4D0
#define CXWnd__DrawColoredRect                                     0x657FF0
#define CXWnd__DrawTooltip                                         0x65C2C0
#define CXWnd__DrawTooltipAtPoint                                  0x65B6F0
#define CXWnd__GetBorderFrame                                      0x6584C0
#define CXWnd__GetChildWndAt                                       0x65B190
#define CXWnd__GetClientClipRect                                   0x6583F0
#define CXWnd__GetFirstChildWnd                                    0x657DF0
#define CXWnd__GetNextChildWnd                                     0x65B150
#define CXWnd__GetNextSib                                          0x657E10
#define CXWnd__GetScreenClipRect                                   0x65BB30
#define CXWnd__GetScreenRect                                       0x658670
#define CXWnd__GetTooltipRect                                      0x658220
#define CXWnd__GetWindowTextA                                      0x525F40
#define CXWnd__IsActive                                            0x672E30
#define CXWnd__IsDescendantOf                                      0x658470
#define CXWnd__IsReallyVisible                                     0x65B130
#define CXWnd__IsType                                              0x67D720
#define CXWnd__Move                                                0x65ABF0
#define CXWnd__Move1                                               0x65AC90
#define CXWnd__ProcessTransition                                   0x657D20
#define CXWnd__Refade                                              0x657AF0
#define CXWnd__Resize                                              0x658740
#define CXWnd__Right                                               0x65BA70
#define CXWnd__SetFirstChildPointer                                0x658940
#define CXWnd__SetFocus                                            0x659C70
#define CXWnd__SetKeyTooltip                                       0x6589A0
#define CXWnd__SetMouseOver                                        0x658970
#define CXWnd__SetNextSibPointer                                   0x658960
#define CXWnd__StartFade                                           0x657D70

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6742F0
#define CXWndManager__DrawWindows                                  0x673F30
#define CXWndManager__GetFirstChildWnd                             0x6737C0
#define CXWndManager__GetKeyboardFlags                             0x672AF0
#define CXWndManager__HandleKeyboardMsg                            0x673020
#define CXWndManager__RemoveWnd                                    0x672F40

// CDBStr
#define CDBStr__GetString                                          0x4580B0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6A56E0
#define EQ_Character__CastSpell                                    0x4221B0
#define EQ_Character__Cur_HP                                       0x429C10
#define EQ_Character__GetAACastingTimeModifier                     0x41D350
#define EQ_Character__GetCharInfo2                                 0x61DF20
#define EQ_Character__GetFocusCastingTimeModifier                  0x419380
#define EQ_Character__GetFocusRangeModifier                        0x4194B0
#define EQ_Character__Max_Endurance                                0x4288F0
#define EQ_Character__Max_HP                                       0x4287A0
#define EQ_Character__Max_Mana                                     0x4F3850
#define EQ_Character__doCombatAbility                              0x4F26D0
#define EQ_Character__UseSkill                                     0x435670
#define EQ_Character__GetConLevel                                  0x4EFB80

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4E55B0
#define EQ_Item__GetItemLinkHash                                   0x61D0C0
#define EQ_Item__IsStackable                                       0x613F20

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x46FF10
#define EQ_LoadingS__Array                                         0x74C580

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4F6780
#define EQ_PC__GetAltAbilityIndex                                  0x622E20
#define EQ_PC__GetCombatAbility                                    0x622EB0
#define EQ_PC__GetCombatAbilityTimer                               0x622F60
#define EQ_PC__GetItemTimerValue                                   0x4F1930
#define EQ_PC__HasLoreItem                                         0x4F4DA0

// EQItemList 
#define EQItemList__dEQItemList                                    0x497930
#define EQItemList__EQItemList                                     0x497880

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x4579F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4FB2A0
#define EQPlayer__dEQPlayer                                        0x4FF980
#define EQPlayer__DoAttack                                         0x50B080
#define EQPlayer__EQPlayer                                         0x502110
#define EQPlayer__SetNameSpriteState                               0x4FD9F0
#define EQPlayer__SetNameSpriteTint                                0x4FB310
#define EQPlayer__IsBodyType_j                                     0x6A50E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5030A0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4E7190
#define KeypressHandler__AttachKeyToEqCommand                      0x4E71D0
#define KeypressHandler__ClearCommandStateArray                    0x4E6FA0
#define KeypressHandler__HandleKeyDown                             0x4E5BA0
#define KeypressHandler__HandleKeyUp                               0x4E5EA0
#define KeypressHandler__SaveKeymapping                            0x4E7070

// MapViewMap 
#define MapViewMap__Clear                                          0x5A9200
#define MapViewMap__SaveEx                                         0x5A9BD0

#define OtherCharData__GetAltCurrency                              0x63E210

// StringTable 
#define StringTable__getString                                     0x6138B0
