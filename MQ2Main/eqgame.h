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
#define __ExpectedVersionDate                                     "Dec  4 2007"
#define __ExpectedVersionTime                                     "11:31:23"
#define __ActualVersionDate                                        0x7152EC
#define __ActualVersionTime                                        0x7152F8

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FAA80
#define __MemChecker1                                              0x660410
#define __MemChecker2                                              0x52E820
#define __MemChecker3                                              0x52E8D0
#define __MemChecker4                                              0x624E60
#define __EncryptPad0                                              0x773108
#define __EncryptPad1                                              0x77CEA0
#define __EncryptPad2                                              0x775680
#define __EncryptPad3                                              0x775A80
#define __EncryptPad4                                              0x77C580

// Direct Input
#define DI8__Main                                                  0x9B88CC
#define DI8__Keyboard                                              0x9B88D0
#define DI8__Mouse                                                 0x9B88D4
#define __AltTimerReady                                            0x94759E
#define __Attack                                                   0x9A4EAA
#define __Autofire                                                 0x9A4EAB
#define __BindList                                                 0x76E2C8
#define __Clicks                                                   0x9462C0
#define __CommandList                                              0x76EAD8
#define __CurrentMapLabel                                          0x9C3A24
#define __CurrentSocial                                            0x76A544
#define __DoAbilityAvailable                                       0x947538
#define __DoAbilityList                                            0x97C9C8
#define __DrawHandler                                              0x9D2CDC
#define __GroupCount                                               0x9267D2
#define __GroupLeader                                              0x926B24
#define __Guilds                                                   0x9284F0
#define __gWorld                                                   0x92842C
#define __HotkeyPage                                               0x9A3DB4
#define __HWnd                                                     0x9B860C
#define __InChatMode                                               0x9461F8
#define __LastTell                                                 0x947E60
#define __LMouseHeldTime                                           0x9462E0
#define __Mouse                                                    0x9B88D8
#define __MouseLook                                                0x94628E
#define __NetStatusToggle                                          0x946290
#define __PCNames                                                  0x9478B8
#define __RangeAttackReady                                         0x94759C
#define __RMouseHeldTime                                           0x9462DC
#define __RunWalkState                                             0x9461FC
#define __ScreenMode                                               0x876130
#define __ScreenX                                                  0x9461B0
#define __ScreenY                                                  0x9461B4
#define __ScreenXMax                                               0x9461B8
#define __ScreenYMax                                               0x9461BC
#define __ServerHost                                               0x92671C
#define __ServerName                                               0x97C988
#define __ShiftKeyDown                                             0x946854
#define __ShowNames                                                0x947790
#define __Socials                                                  0x97CA88


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x940140
#define instEQZoneInfo                                             0x94642C
#define instKeypressHandler                                        0x9A4F94
#define pinstActiveBanker                                          0x9284C4
#define pinstActiveCorpse                                          0x9284C8
#define pinstActiveGMaster                                         0x9284CC
#define pinstActiveMerchant                                        0x9284C0
#define pinstAltAdvManager                                         0x876F80
#define pinstAuraMgr                                               0x781FCC
#define pinstBandageTarget                                         0x9284AC
#define pinstCamActor                                              0x876A70
#define pinstCDBStr                                                0x876120
#define pinstCDisplay                                              0x9284D4
#define pinstCEverQuest                                            0x9B8A50
#define pinstCharData                                              0x928490
#define pinstCharSpawn                                             0x9284B8
#define pinstControlledMissile                                     0x92848C
#define pinstControlledPlayer                                      0x9284B8
#define pinstCSidlManager                                          0x9D24C0
#define pinstCXWndManager                                          0x9D24B8
#define instDynamicZone                                            0x945C00
#define pinstDZMember                                              0x945D10
#define pinstDZTimerInfo                                           0x945D14
#define pinstEQItemList                                            0x928474
#define instEQMisc                                                 0x8760D8
#define pinstEQSoundManager                                        0x876FA4
#define instExpeditionLeader                                       0x945C4A
#define instExpeditionName                                         0x945C8A
#define instGroup                                                  0x9269C8
#define pinstGroup                                                 0x9267CE
#define pinstImeManager                                            0x9D24C4
#define pinstLocalPlayer                                           0x9284A4
#define pinstModelPlayer                                           0x9284D0
#define pinstPCData                                                0x928490
#define pinstSelectedItem                                          0x9C385C
#define pinstSkillMgr                                              0x9B583C
#define pinstSpawnManager                                          0x9B57BC
#define pinstSpellManager                                          0x9B5840
#define pinstSpellSets                                             0x9A3DB8
#define pinstStringTable                                           0x928448
#define pinstSwitchManager                                         0x926418
#define pinstTarget                                                0x9284BC
#define pinstTargetObject                                          0x928494
#define pinstTargetSwitch                                          0x928498
#define pinstTaskMember                                            0x8760B8
#define pinstTrackTarget                                           0x9284B0
#define pinstTradeTarget                                           0x9284A0
#define instTributeActive                                          0x8760FD
#define pinstViewActor                                             0x876A6C
#define pinstWorldData                                             0x928470


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x780500
#define pinstCAudioTriggersWindow                                  0x7804CC
#define pinstCCharacterSelect                                      0x876980
#define pinstCFacePick                                             0x876938
#define pinstCNoteWnd                                              0x87693C
#define pinstCBookWnd                                              0x876940
#define pinstCPetInfoWnd                                           0x876944
#define pinstCTrainWnd                                             0x876948
#define pinstCSkillsWnd                                            0x87694C
#define pinstCSkillsSelectWnd                                      0x876950
#define pinstCCombatSkillSelectWnd                                 0x876954
#define pinstCFriendsWnd                                           0x876958
#define pinstCAuraWnd                                              0x87695C
#define pinstCRespawnWnd                                           0x876960
#define pinstCBandolierWnd                                         0x876964
#define pinstCPotionBeltWnd                                        0x876968
#define pinstCAAWnd                                                0x87696C
#define pinstCGroupSearchFiltersWnd                                0x876970
#define pinstCLoadskinWnd                                          0x876974
#define pinstCAlarmWnd                                             0x876978
#define pinstCMusicPlayerWnd                                       0x87697C
#define pinstCMailWnd                                              0x876984
#define pinstCMailCompositionWnd                                   0x876988
#define pinstCMailAddressBookWnd                                   0x87698C
#define pinstCRaidWnd                                              0x876994
#define pinstCRaidOptionsWnd                                       0x876998
#define pinstCBreathWnd                                            0x87699C
#define pinstCMapViewWnd                                           0x8769A0
#define pinstCMapToolbarWnd                                        0x8769A4
#define pinstCEditLabelWnd                                         0x8769A8
#define pinstCTargetWnd                                            0x8769AC
#define pinstCColorPickerWnd                                       0x8769B0
#define pinstCPlayerWnd                                            0x8769B4
#define pinstCOptionsWnd                                           0x8769B8
#define pinstCBuffWindowNORMAL                                     0x8769BC
#define pinstCBuffWindowSHORT                                      0x8769C0
#define pinstCharacterCreation                                     0x8769C4
#define pinstCCursorAttachment                                     0x8769C8
#define pinstCCastingWnd                                           0x8769CC
#define pinstCCastSpellWnd                                         0x8769D0
#define pinstCSpellBookWnd                                         0x8769D4
#define pinstCInventoryWnd                                         0x8769D8
#define pinstCBankWnd                                              0x8769DC
#define pinstCQuantityWnd                                          0x8769E0
#define pinstCLootWnd                                              0x8769E4
#define pinstCActionsWnd                                           0x8769E8
#define pinstCCombatAbilityWnd                                     0x8769EC
#define pinstCMerchantWnd                                          0x8769F0
#define pinstCTradeWnd                                             0x8769F4
#define pinstCSelectorWnd                                          0x8769F8
#define pinstCBazaarWnd                                            0x8769FC
#define pinstCBazaarSearchWnd                                      0x876A00
#define pinstCGiveWnd                                              0x876A04
#define pinstCTrackingWnd                                          0x876A08
#define pinstCInspectWnd                                           0x876A0C
#define pinstCSocialEditWnd                                        0x876A10
#define pinstCFeedbackWnd                                          0x876A14
#define pinstCBugReportWnd                                         0x876A18
#define pinstCVideoModesWnd                                        0x876A1C
#define pinstCTextEntryWnd                                         0x876A24
#define pinstCFileSelectionWnd                                     0x876A28
#define pinstCCompassWnd                                           0x876A2C
#define pinstCPlayerNotesWnd                                       0x876A30
#define pinstCGemsGameWnd                                          0x876A34
#define pinstCTimeLeftWnd                                          0x876A38
#define pinstCPetitionQWnd                                         0x876A3C
#define pinstCSoulmarkWnd                                          0x876A40
#define pinstCStoryWnd                                             0x876A44
#define pinstCJournalTextWnd                                       0x876A48
#define pinstCJournalCatWnd                                        0x876A4C
#define pinstCBodyTintWnd                                          0x876A50
#define pinstCServerListWnd                                        0x876A54
#define pinstCAvaZoneWnd                                           0x876A58
#define pinstCBlockedBuffWnd                                       0x876A5C
#define pinstCBlockedPetBuffWnd                                    0x876A60
#define pinstCInvSlotMgr                                           0x876A64
#define pinstCContainerMgr                                         0x876A68
#define pinstCAdventureLeaderboardWnd                              0x9C1034
#define pinstCAdventureRequestWnd                                  0x9C1050
#define pinstCAltStorageWnd                                        0x9C10B0
#define pinstCAdventureStatsWnd                                    0x9C106C
#define pinstCBarterMerchantWnd                                    0x9C127C
#define pinstCBarterSearchWnd                                      0x9C1298
#define pinstCBarterWnd                                            0x9C12B4
#define pinstCChatManager                                          0x9C1494
#define pinstCDynamicZoneWnd                                       0x9C158C
#define pinstCEQMainWnd                                            0x9C15FC
#define pinstCFellowshipWnd                                        0x9C1660
#define pinstCFindLocationWnd                                      0x9C1694
#define pinstCGroupSearchWnd                                       0x9C1744
#define pinstCGroupWnd                                             0x9C1760
#define pinstCGuildBankWnd                                         0x9C177C
#define pinstCGuildMgmtWnd                                         0x9C3798
#define pinstCGuildTributeMasterWnd                                0x9C37B8
#define pinstCHotButtonWnd                                         0x9C37D4
#define pinstCHotButtonWnd1                                        0x9C37D4
#define pinstCHotButtonWnd2                                        0x9C37D8
#define pinstCHotButtonWnd3                                        0x9C37DC
#define pinstCHotButtonWnd4                                        0x9C37E0
#define pinstCItemDisplayManager                                   0x9C3890
#define pinstCItemExpTransferWnd                                   0x9C38B0
#define pinstCLeadershipWnd                                        0x9C394C
#define pinstCLFGuildWnd                                           0x9C3968
#define pinstCMIZoneSelectWnd                                      0x9C3A8C
#define pinstCAdventureMerchantWnd                                 0x9C3B84
#define pinstCConfirmationDialog                                   0x9C3BA0
#define pinstCPopupWndManager                                      0x9C3BA0
#define pinstCProgressionSelectionWnd                              0x9C3BD4
#define pinstCPvPLeaderboardWnd                                    0x9C3BF0
#define pinstCPvPStatsWnd                                          0x9C3C0C
#define pinstCSystemInfoDialogBox                                  0x9C3CBC
#define pinstCTargetOfTargetWnd                                    0x9C45AC
#define pinstCTaskSelectWnd                                        0x9C45C8
#define pinstCTaskTemplateSelectWnd                                0x9C45E4
#define pinstCTaskWnd                                              0x9C4600
#define pinstCTipWndOFDAY                                          0x9C467C
#define pinstCTipWndCONTEXT                                        0x9C4680
#define pinstCTitleWnd                                             0x9C469C
#define pinstCTradeskillWnd                                        0x9C46E0
#define pinstCTributeBenefitWnd                                    0x9C472C
#define pinstCTributeMasterWnd                                     0x9C4748
#define pinstCContextMenuManager                                   0x9D251C
#define pinstCVoiceMacroWnd                                        0x9B592C
#define pinstCHtmlWnd                                              0x9B5948


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4B74F0
#define __ConvertItemTags                                          0x4AABC0
#define __ExecuteCmd                                               0x49A200
#define __get_melee_range                                          0x49F450
#define __GetGaugeValueFromEQ                                      0x5F6F50
#define __GetLabelFromEQ                                           0x5F7750
#define __NewUIINI                                                 0x5F6B40
#define __ProcessGameEvents                                        0x4E5ED0
#define DrawNetStatus                                              0x4FD870
#define Util__FastTime                                             0x660A90


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x473BE0
#define AltAdvManager__IsAbilityReady                              0x473C20
#define AltAdvManager__GetAltAbility                               0x473DB0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x544800

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x54E160

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x68C140

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x561730
#define CChatManager__InitContextMenu                              0x561EC0

// CChatService
#define CChatService__GetNumberOfFriends                           0x650FA0
#define CChatService__GetFriendName                                0x650FB0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x566030
#define CChatWindow__WndNotification                               0x566A50

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x672470
#define CComboWnd__Draw                                            0x672620
#define CComboWnd__GetCurChoice                                    0x672410
#define CComboWnd__GetListRect                                     0x6728F0
#define CComboWnd__GetTextRect                                     0x6724A0
#define CComboWnd__InsertChoice                                    0x672960
#define CComboWnd__SetColors                                       0x6723A0
#define CComboWnd__SetChoice                                       0x6723D0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x56D620
#define CContainerWnd__vftable                                     0x71BBA0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x462E60
#define CDisplay__GetClickedActor                                  0x460590
#define CDisplay__GetUserDefinedColor                              0x45F710
#define CDisplay__GetWorldFilePath                                 0x45EC80
#define CDisplay__is3dON                                           0x45DDE0
#define CDisplay__ReloadUI                                         0x46E9C0
#define CDisplay__WriteTextHD2                                     0x463590

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x53E890
#define CEditBaseWnd__SetSel                                       0x6971A0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x680130
#define CEditWnd__GetCharIndexPt                                   0x680F80
#define CEditWnd__GetDisplayString                                 0x6802C0
#define CEditWnd__GetHorzOffset                                    0x680560
#define CEditWnd__GetLineForPrintableChar                          0x680A30
#define CEditWnd__GetSelStartPt                                    0x6811C0
#define CEditWnd__GetSTMLSafeText                                  0x6806F0
#define CEditWnd__PointFromPrintableChar                           0x680B40
#define CEditWnd__SelectableCharFromPoint                          0x680CC0
#define CEditWnd__SetEditable                                      0x6806C0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4C99C0
#define CEverQuest__DropHeldItemOnGround                           0x4CE2D0
#define CEverQuest__dsp_chat                                       0x4CF150
#define CEverQuest__DoTellWindow                                   0x4CE450
#define CEverQuest__EnterZone                                      0x4E4910
#define CEverQuest__GetBodyTypeDesc                                0x4C6E50
#define CEverQuest__GetClassDesc                                   0x4C65B0
#define CEverQuest__GetClassThreeLetterCode                        0x4C6BB0
#define CEverQuest__GetDeityDesc                                   0x4C74C0
#define CEverQuest__GetLangDesc                                    0x4C71E0
#define CEverQuest__GetRaceDesc                                    0x4C7490
#define CEverQuest__InterpretCmd                                   0x4CFB80
#define CEverQuest__LeftClickedOnPlayer                            0x4E3130
#define CEverQuest__LMouseUp                                       0x4E56B0
#define CEverQuest__RightClickedOnPlayer                           0x4E3500
#define CEverQuest__RMouseUp                                       0x4E4F10
#define CEverQuest__SetGameState                                   0x4C9E40
#define CEverQuest__Emote                                          0x4CF320

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x578B00
#define CGaugeWnd__CalcLinesFillRect                               0x578B70
#define CGaugeWnd__Draw                                            0x578F00

// CGuild
#define CGuild__FindMemberByName                                   0x417970

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x58F300

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x598790
#define CInvSlotMgr__MoveItem                                      0x598930

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5998C0

// CInvSLot
#define CInvSlot__SliderComplete                                   0x5976A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5A75F0
#define CItemDisplayWnd__SetSpell                                  0x5F4DE0

// CLabel 
#define CLabel__Draw                                               0x5ACE50

// CListWnd 
#define CListWnd__AddColumn                                        0x6721B0
#define CListWnd__AddColumn1                                       0x671CF0
#define CListWnd__AddLine                                          0x671880
#define CListWnd__AddString                                        0x671A50
#define CListWnd__CalculateFirstVisibleLine                        0x66EBB0
#define CListWnd__CalculateVSBRange                                0x670820
#define CListWnd__ClearAllSel                                      0x66E330
#define CListWnd__CloseAndUpdateEditWindow                         0x66F1D0
#define CListWnd__Compare                                          0x66F580
#define CListWnd__Draw                                             0x670520
#define CListWnd__DrawColumnSeparators                             0x670390
#define CListWnd__DrawHeader                                       0x66E500
#define CListWnd__DrawItem                                         0x66FC90
#define CListWnd__DrawLine                                         0x670040
#define CListWnd__DrawSeparator                                    0x670430
#define CListWnd__EnsureVisible                                    0x66EC00
#define CListWnd__ExtendSel                                        0x66FBC0
#define CListWnd__GetColumnMinWidth                                0x66E0D0
#define CListWnd__GetColumnWidth                                   0x66E010
#define CListWnd__GetCurSel                                        0x66DAE0
#define CListWnd__GetHeaderRect                                    0x66DBE0
#define CListWnd__GetItemAtPoint                                   0x66EEE0
#define CListWnd__GetItemAtPoint1                                  0x66EF50
#define CListWnd__GetItemData                                      0x66DDC0
#define CListWnd__GetItemHeight                                    0x66E960
#define CListWnd__GetItemIcon                                      0x66DF50
#define CListWnd__GetItemRect                                      0x66ECD0
#define CListWnd__GetItemText                                      0x66DE00
#define CListWnd__GetSelList                                       0x671BD0
#define CListWnd__GetSeparatorRect                                 0x66F4C0
#define CListWnd__RemoveLine                                       0x671B80
#define CListWnd__SetColors                                        0x66DB40
#define CListWnd__SetColumnJustification                           0x66E130
#define CListWnd__SetColumnWidth                                   0x66E090
#define CListWnd__SetCurSel                                        0x66DB20
#define CListWnd__SetItemColor                                     0x671450
#define CListWnd__SetItemData                                      0x66E3D0
#define CListWnd__SetItemText                                      0x6713D0
#define CListWnd__ShiftColumnSeparator                             0x66FB30
#define CListWnd__Sort                                             0x6721E0
#define CListWnd__ToggleSel                                        0x66E2A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5C1420

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C2F00
#define CMerchantWnd__RequestBuyItem                               0x5C4240
#define CMerchantWnd__RequestSellItem                              0x5C3150
#define CMerchantWnd__SelectBuySellSlot                            0x5C3F80

// CObfuscator
#define CObfuscator__doit                                          0x6382A0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x687B70

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x677F30
#define CSidlScreenWnd__CalculateVSBRange                          0x5402C0
#define CSidlScreenWnd__ConvertToRes                               0x697080
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x679830
#define CSidlScreenWnd__CSidlScreenWnd1                            0x67A680
#define CSidlScreenWnd__CSidlScreenWnd2                            0x67A730
#define CSidlScreenWnd__dCSidlScreenWnd                            0x67A0D0
#define CSidlScreenWnd__DrawSidlPiece                              0x679510
#define CSidlScreenWnd__EnableIniStorage                           0x679030
#define CSidlScreenWnd__GetSidlPiece                               0x679710
#define CSidlScreenWnd__Init1                                      0x67A4F0
#define CSidlScreenWnd__LoadIniInfo                                0x6798E0
#define CSidlScreenWnd__LoadIniListWnd                             0x679170
#define CSidlScreenWnd__LoadSidlScreen                             0x679330
#define CSidlScreenWnd__StoreIniInfo                               0x678C40
#define CSidlScreenWnd__WndNotification                            0x679470

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x51E5B0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x42B590
#define CSliderWnd__SetValue                                       0x697E50
#define CSliderWnd__SetNumTicks                                    0x698380

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5F3A70

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x695320
#define CStmlWnd__CalculateVSBRange                                0x68D6E0
#define CStmlWnd__CanBreakAtCharacter                              0x68D820
#define CStmlWnd__FastForwardToEndOfTag                            0x68E330
#define CStmlWnd__GetNextTagPiece                                  0x68E250
#define CStmlWnd__GetSTMLText                                      0x565FD0
#define CStmlWnd__GetThisChar                                      0x6B5790
#define CStmlWnd__GetVisiableText                                  0x68F560
#define CStmlWnd__InitializeWindowVariables                        0x6916B0
#define CStmlWnd__MakeStmlColorTag                                 0x68CD80
#define CStmlWnd__MakeWndNotificationTag                           0x68CE20
#define CStmlWnd__StripFirstSTMLLines                              0x6950B0
#define CStmlWnd__UpdateHistoryString                              0x68FDB0

// CTabWnd 
#define CTabWnd__Draw                                              0x6991A0
#define CTabWnd__DrawCurrentPage                                   0x698B20
#define CTabWnd__DrawTab                                           0x698900
#define CTabWnd__GetCurrentPage                                    0x698E20
#define CTabWnd__GetPageClientRect                                 0x6985D0
#define CTabWnd__GetPageFromTabIndex                               0x698830
#define CTabWnd__GetPageInnerRect                                  0x698630
#define CTabWnd__GetTabInnerRect                                   0x6987B0
#define CTabWnd__GetTabRect                                        0x6986C0
#define CTabWnd__IndexInBounds                                     0x6988CD
#define CTabWnd__InsertPage                                        0x6993C0
#define CTabWnd__SetPage                                           0x698E60
#define CTabWnd__SetPageRect                                       0x6990D0
#define CTabWnd__UpdatePage                                        0x699340

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x413EF0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x67AA90

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x69E710

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x66D850

// CXRect 
#define CXRect__CenterPoint                                        0x543F50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4F4AE0
#define CXStr__CXStr1                                              0x6674B0
#define CXStr__CXStr3                                              0x662180
#define CXStr__dCXStr                                              0x5EAAF0
#define CXStr__operator_equal1                                     0x662340
#define CXStr__operator_plus_equal1                                0x663230

// CXWnd 
#define CXWnd__BringToTop                                          0x6731E0
#define CXWnd__Center                                              0x676D80
#define CXWnd__ClrFocus                                            0x672ED0
#define CXWnd__DoAllDrawing                                        0x677810
#define CXWnd__DrawChildren                                        0x677940
#define CXWnd__DrawColoredRect                                     0x673480
#define CXWnd__DrawTooltip                                         0x677730
#define CXWnd__DrawTooltipAtPoint                                  0x676B60
#define CXWnd__GetBorderFrame                                      0x673950
#define CXWnd__GetChildWndAt                                       0x676600
#define CXWnd__GetClientClipRect                                   0x673880
#define CXWnd__GetFirstChildWnd                                    0x673280
#define CXWnd__GetNextChildWnd                                     0x6765C0
#define CXWnd__GetNextSib                                          0x6732A0
#define CXWnd__GetScreenClipRect                                   0x676FA0
#define CXWnd__GetScreenRect                                       0x673B00
#define CXWnd__GetTooltipRect                                      0x6736B0
#define CXWnd__GetWindowTextA                                      0x537A80
#define CXWnd__IsActive                                            0x67BB90
#define CXWnd__IsDescendantOf                                      0x673900
#define CXWnd__IsReallyVisible                                     0x6765A0
#define CXWnd__IsType                                              0x69A280
#define CXWnd__Move                                                0x676060
#define CXWnd__Move1                                               0x676100
#define CXWnd__ProcessTransition                                   0x6731B0
#define CXWnd__Refade                                              0x672F80
#define CXWnd__Resize                                              0x673BD0
#define CXWnd__Right                                               0x676EE0
#define CXWnd__SetFirstChildPointer                                0x673DB0
#define CXWnd__SetFocus                                            0x6750E0
#define CXWnd__SetKeyTooltip                                       0x673E10
#define CXWnd__SetMouseOver                                        0x673DE0
#define CXWnd__SetNextSibPointer                                   0x673DD0
#define CXWnd__StartFade                                           0x673200

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x67D000
#define CXWndManager__DrawWindows                                  0x67CC40
#define CXWndManager__GetFirstChildWnd                             0x67C520
#define CXWndManager__GetKeyboardFlags                             0x67B850
#define CXWndManager__HandleKeyboardMsg                            0x67BD80
#define CXWndManager__RemoveWnd                                    0x67BCA0

// CDBStr
#define CDBStr__GetString                                          0x45C6D0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6C1840
#define EQ_Character__CastSpell                                    0x424FC0
#define EQ_Character__Cur_HP                                       0x4319B0
#define EQ_Character__GetAACastingTimeModifier                     0x41F870
#define EQ_Character__GetCharInfo2                                 0x643770
#define EQ_Character__GetFocusCastingTimeModifier                  0x41B4F0
#define EQ_Character__GetFocusRangeModifier                        0x41B620
#define EQ_Character__Max_Endurance                                0x42CD40
#define EQ_Character__Max_HP                                       0x42CBC0
#define EQ_Character__Max_Mana                                     0x502CB0
#define EQ_Character__doCombatAbility                              0x501AF0
#define EQ_Character__UseSkill                                     0x437AC0
#define EQ_Character__GetConLevel                                  0x4FEC50

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F2850
#define EQ_Item__GetItemLinkHash                                   0x637900
#define EQ_Item__IsStackable                                       0x62E7B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x474D00
#define EQ_LoadingS__Array                                         0x76C7D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x505E70
#define EQ_PC__GetAltAbilityIndex                                  0x63C870
#define EQ_PC__GetCombatAbility                                    0x63C900
#define EQ_PC__GetCombatAbilityTimer                               0x63C9B0
#define EQ_PC__GetItemTimerValue                                   0x500A30
#define EQ_PC__HasLoreItem                                         0x5042D0

// EQItemList 
#define EQItemList__dEQItemList                                    0x49DB40
#define EQItemList__EQItemList                                     0x49DA90

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45C090

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50AD30
#define EQPlayer__dEQPlayer                                        0x50F4C0
#define EQPlayer__DoAttack                                         0x51B0C0
#define EQPlayer__EQPlayer                                         0x5121A0
#define EQPlayer__SetNameSpriteState                               0x50D430
#define EQPlayer__SetNameSpriteTint                                0x50ADA0
#define EQPlayer__IsBodyType_j                                     0x6C1220

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5130C0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F4450
#define KeypressHandler__AttachKeyToEqCommand                      0x4F4490
#define KeypressHandler__ClearCommandStateArray                    0x4F4260
#define KeypressHandler__HandleKeyDown                             0x4F2E40
#define KeypressHandler__HandleKeyUp                               0x4F3140
#define KeypressHandler__SaveKeymapping                            0x4F4330

// MapViewMap 
#define MapViewMap__Clear                                          0x5BD430
#define MapViewMap__SaveEx                                         0x5BDE00

#define OtherCharData__GetAltCurrency                              0x659760

// StringTable 
#define StringTable__getString                                     0x62E1A0
