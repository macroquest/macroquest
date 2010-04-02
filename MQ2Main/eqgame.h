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
#define __ExpectedVersionDate                                     "Oct 29 2007"
#define __ExpectedVersionTime                                     "13:20:30"
#define __ActualVersionDate                                        0x70DFE4
#define __ActualVersionTime                                        0x70DFF0

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4F8130
#define __MemChecker1                                              0x659EA0
#define __MemChecker2                                              0x52B5B0
#define __MemChecker3                                              0x52B660
#define __MemChecker4                                              0x622FD0
#define __EncryptPad0                                              0x76BEB8
#define __EncryptPad1                                              0x775C08
#define __EncryptPad2                                              0x76E420
#define __EncryptPad3                                              0x76E820
#define __EncryptPad4                                              0x7752E0

// Direct Input
#define DI8__Main                                                  0x9A4124
#define DI8__Keyboard                                              0x9A4128
#define DI8__Mouse                                                 0x9A412C
#define __AltTimerReady                                            0x93FEDA
#define __Attack                                                   0x99D7C2
#define __Autofire                                                 0x99D7C3
#define __BindList                                                 0x767090
#define __Clicks                                                   0x93F000
#define __CommandList                                              0x767890
#define __CurrentMapLabel                                          0x9AF27C
#define __CurrentSocial                                            0x763520
#define __DoAbilityAvailable                                       0x93FE74
#define __DoAbilityList                                            0x975308
#define __DrawHandler                                              0x9BE524
#define __GroupCount                                               0x91F51A
#define __GroupLeader                                              0x91F86C
#define __Guilds                                                   0x921230
#define __gWorld                                                   0x921170
#define __HotkeyPage                                               0x99C6F4
#define __HWnd                                                     0x9A3E64
#define __InChatMode                                               0x93EF38
#define __LastTell                                                 0x9407A0
#define __LMouseHeldTime                                           0x93F020
#define __Mouse                                                    0x9A4130
#define __MouseLook                                                0x93EFCE
#define __NetStatusToggle                                          0x93EFD0
#define __PCNames                                                  0x9401F8
#define __RangeAttackReady                                         0x93FED8
#define __RMouseHeldTime                                           0x93F01C
#define __RunWalkState                                             0x93EF3C
#define __ScreenMode                                               0x86EE78
#define __ScreenX                                                  0x93EEF0
#define __ScreenY                                                  0x93EEF4
#define __ScreenXMax                                               0x93EEF8
#define __ScreenYMax                                               0x93EEFC
#define __ServerHost                                               0x91F464
#define __ServerName                                               0x9752C8
#define __ShowNames                                                0x9400CC
#define __Socials                                                  0x9753C8


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x938E80
#define instEQZoneInfo                                             0x93F16C
#define instKeypressHandler                                        0x99D8AC
#define pinstActiveBanker                                          0x921208
#define pinstActiveCorpse                                          0x92120C
#define pinstActiveGMaster                                         0x921210
#define pinstActiveMerchant                                        0x921204
#define pinstAltAdvManager                                         0x86FCC8
#define pinstAuraMgr                                               0x77AD14
#define pinstBandageTarget                                         0x9211F0
#define pinstCamActor                                              0x86F7B8
#define pinstCDBStr                                                0x86EE68
#define pinstCDisplay                                              0x921218
#define pinstCEverQuest                                            0x9A42A8
#define pinstCharData                                              0x9211D4
#define pinstCharSpawn                                             0x9211FC
#define pinstControlledMissile                                     0x9211D0
#define pinstControlledPlayer                                      0x9211FC
#define pinstCSidlManager                                          0x9BDD5C
#define pinstCXWndManager                                          0x9BDD54
#define instDynamicZone                                            0x93E940
#define pinstDZMember                                              0x93EA50
#define pinstDZTimerInfo                                           0x93EA54
#define pinstEQItemList                                            0x9211B8
#define instEQMisc                                                 0x86EE20
#define pinstEQSoundManager                                        0x86FCEC
#define instExpeditionLeader                                       0x93E98A
#define instExpeditionName                                         0x93E9CA
#define instGroup                                                  0x91F51A
#define pinstGroup                                                 0x91F516
#define pinstImeManager                                            0x9BDD60
#define pinstLocalPlayer                                           0x9211E8
#define pinstModelPlayer                                           0x921214
#define pinstPCData                                                0x9211D4
#define pinstSelectedItem                                          0x9AF0B4
#define pinstSkillMgr                                              0x9A1094
#define pinstSpawnManager                                          0x9A1014
#define pinstSpellManager                                          0x9A1098
#define pinstSpellSets                                             0x99C6F8
#define pinstStringTable                                           0x92118C
#define pinstSwitchManager                                         0x91F160
#define pinstTarget                                                0x921200
#define pinstTargetObject                                          0x9211D8
#define pinstTargetSwitch                                          0x9211DC
#define pinstTaskMember                                            0x86EE00
#define pinstTrackTarget                                           0x9211F4
#define pinstTradeTarget                                           0x9211E4
#define instTributeActive                                          0x86EE45
#define pinstViewActor                                             0x86F7B4
#define pinstWorldData                                             0x9211B4


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x779248
#define pinstCAudioTriggersWindow                                  0x77922C
#define pinstCCharacterSelect                                      0x86F6C8
#define pinstCFacePick                                             0x86F680
#define pinstCNoteWnd                                              0x86F684
#define pinstCBookWnd                                              0x86F688
#define pinstCPetInfoWnd                                           0x86F68C
#define pinstCTrainWnd                                             0x86F690
#define pinstCSkillsWnd                                            0x86F694
#define pinstCSkillsSelectWnd                                      0x86F698
#define pinstCCombatSkillSelectWnd                                 0x86F69C
#define pinstCFriendsWnd                                           0x86F6A0
#define pinstCAuraWnd                                              0x86F6A4
#define pinstCRespawnWnd                                           0x86F6A8
#define pinstCBandolierWnd                                         0x86F6AC
#define pinstCPotionBeltWnd                                        0x86F6B0
#define pinstCAAWnd                                                0x86F6B4
#define pinstCGroupSearchFiltersWnd                                0x86F6B8
#define pinstCLoadskinWnd                                          0x86F6BC
#define pinstCAlarmWnd                                             0x86F6C0
#define pinstCMusicPlayerWnd                                       0x86F6C4
#define pinstCMailWnd                                              0x86F6CC
#define pinstCMailCompositionWnd                                   0x86F6D0
#define pinstCMailAddressBookWnd                                   0x86F6D4
#define pinstCRaidWnd                                              0x86F6DC
#define pinstCRaidOptionsWnd                                       0x86F6E0
#define pinstCBreathWnd                                            0x86F6E4
#define pinstCMapViewWnd                                           0x86F6E8
#define pinstCMapToolbarWnd                                        0x86F6EC
#define pinstCEditLabelWnd                                         0x86F6F0
#define pinstCTargetWnd                                            0x86F6F4
#define pinstCColorPickerWnd                                       0x86F6F8
#define pinstCPlayerWnd                                            0x86F6FC
#define pinstCOptionsWnd                                           0x86F700
#define pinstCBuffWindowNORMAL                                     0x86F704
#define pinstCBuffWindowSHORT                                      0x86F708
#define pinstCharacterCreation                                     0x86F70C
#define pinstCCursorAttachment                                     0x86F710
#define pinstCCastingWnd                                           0x86F714
#define pinstCCastSpellWnd                                         0x86F718
#define pinstCSpellBookWnd                                         0x86F71C
#define pinstCInventoryWnd                                         0x86F720
#define pinstCBankWnd                                              0x86F724
#define pinstCQuantityWnd                                          0x86F728
#define pinstCLootWnd                                              0x86F72C
#define pinstCActionsWnd                                           0x86F730
#define pinstCCombatAbilityWnd                                     0x86F734
#define pinstCMerchantWnd                                          0x86F738
#define pinstCTradeWnd                                             0x86F73C
#define pinstCSelectorWnd                                          0x86F740
#define pinstCBazaarWnd                                            0x86F744
#define pinstCBazaarSearchWnd                                      0x86F748
#define pinstCGiveWnd                                              0x86F74C
#define pinstCTrackingWnd                                          0x86F750
#define pinstCInspectWnd                                           0x86F754
#define pinstCSocialEditWnd                                        0x86F758
#define pinstCFeedbackWnd                                          0x86F75C
#define pinstCBugReportWnd                                         0x86F760
#define pinstCVideoModesWnd                                        0x86F764
#define pinstCTextEntryWnd                                         0x86F76C
#define pinstCFileSelectionWnd                                     0x86F770
#define pinstCCompassWnd                                           0x86F774
#define pinstCPlayerNotesWnd                                       0x86F778
#define pinstCGemsGameWnd                                          0x86F77C
#define pinstCTimeLeftWnd                                          0x86F780
#define pinstCPetitionQWnd                                         0x86F784
#define pinstCSoulmarkWnd                                          0x86F788
#define pinstCStoryWnd                                             0x86F78C
#define pinstCJournalTextWnd                                       0x86F790
#define pinstCJournalCatWnd                                        0x86F794
#define pinstCBodyTintWnd                                          0x86F798
#define pinstCServerListWnd                                        0x86F79C
#define pinstCAvaZoneWnd                                           0x86F7A0
#define pinstCBlockedBuffWnd                                       0x86F7A4
#define pinstCBlockedPetBuffWnd                                    0x86F7A8
#define pinstCInvSlotMgr                                           0x86F7AC
#define pinstCContainerMgr                                         0x86F7B0
#define pinstCAdventureLeaderboardWnd                              0x9AC88C
#define pinstCAdventureRequestWnd                                  0x9AC8A8
#define pinstCAltStorageWnd                                        0x9AC908
#define pinstCAdventureStatsWnd                                    0x9AC8C4
#define pinstCBarterMerchantWnd                                    0x9ACABC
#define pinstCBarterSearchWnd                                      0x9ACAD8
#define pinstCBarterWnd                                            0x9ACAF4
#define pinstCChatManager                                          0x9ACCEC
#define pinstCDynamicZoneWnd                                       0x9ACDE4
#define pinstCEQMainWnd                                            0x9ACA88
#define pinstCFellowshipWnd                                        0x9ACEB8
#define pinstCFindLocationWnd                                      0x9ACEEC
#define pinstCGroupSearchWnd                                       0x9ACF9C
#define pinstCGroupWnd                                             0x9ACFB8
#define pinstCGuildBankWnd                                         0x9ACFD4
#define pinstCGuildMgmtWnd                                         0x9AEFF0
#define pinstCGuildTributeMasterWnd                                0x9AF010
#define pinstCHotButtonWnd                                         0x9AF02C
#define pinstCHotButtonWnd1                                        0x9AF02C
#define pinstCHotButtonWnd2                                        0x9AF030
#define pinstCHotButtonWnd3                                        0x9AF034
#define pinstCHotButtonWnd4                                        0x9AF038
#define pinstCItemDisplayManager                                   0x9AF0E8
#define pinstCItemExpTransferWnd                                   0x9AF108
#define pinstCLeadershipWnd                                        0x9AF1A4
#define pinstCLFGuildWnd                                           0x9AF1C0
#define pinstCMIZoneSelectWnd                                      0x9AF2E4
#define pinstCAdventureMerchantWnd                                 0x9AF3DC
#define pinstCConfirmationDialog                                   0x9AF3F8
#define pinstCPopupWndManager                                      0x9AF3F8
#define pinstCProgressionSelectionWnd                              0x9AF42C
#define pinstCPvPLeaderboardWnd                                    0x9AF448
#define pinstCPvPStatsWnd                                          0x9AF464
#define pinstCSystemInfoDialogBox                                  0x9AFDE4
#define pinstCTargetOfTargetWnd                                    0x9AFE18
#define pinstCTaskSelectWnd                                        0x9AFE34
#define pinstCTaskTemplateSelectWnd                                0x9AFE50
#define pinstCTaskWnd                                              0x9AFE6C
#define pinstCTipWndOFDAY                                          0x9AFEE8
#define pinstCTipWndCONTEXT                                        0x9AFEEC
#define pinstCTitleWnd                                             0x9AFF08
#define pinstCTradeskillWnd                                        0x9AFF4C
#define pinstCTributeBenefitWnd                                    0x9AFF98
#define pinstCTributeMasterWnd                                     0x9AFFB4
#define pinstCContextMenuManager                                   0x9BDE1C
#define pinstCVoiceMacroWnd                                        0x9A1184
#define pinstCHtmlWnd                                              0x9A11A0


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4B55C0
#define __ConvertItemTags                                          0x4A8C60
#define __ExecuteCmd                                               0x4982B0
#define __get_melee_range                                          0x49D4E0
#define __GetGaugeValueFromEQ                                      0x5F4D40
#define __GetLabelFromEQ                                           0x5F5550
#define __NewUIINI                                                 0x5F4930
#define __ProcessGameEvents                                        0x4E3BC0
#define CrashDetected                                              0x52A550
#define DrawNetStatus                                              0x4FAF50
#define Util__FastTime                                             0x65A4F0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x471C60
#define AltAdvManager__IsAbilityReady                              0x471CA0
#define AltAdvManager__GetAltAbility                               0x471E20

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x541970

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x54B2B0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x677010

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x55FD00
#define CChatManager__InitContextMenu                              0x560490

// CChatService
#define CChatService__GetNumberOfFriends                           0x64AD90
#define CChatService__GetFriendName                                0x64ADA0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x564600
#define CChatWindow__WndNotification                               0x565020

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x66BFD0
#define CComboWnd__Draw                                            0x66C180
#define CComboWnd__GetCurChoice                                    0x66BF70
#define CComboWnd__GetListRect                                     0x66C450
#define CComboWnd__GetTextRect                                     0x66C000
#define CComboWnd__InsertChoice                                    0x66C4C0
#define CComboWnd__SetColors                                       0x66BF00
#define CComboWnd__SetChoice                                       0x66BF30

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x56BAC0
#define CContainerWnd__vftable                                     0x714A68

// CDisplay 
#define CDisplay__CleanGameUI                                      0x460C80
#define CDisplay__GetClickedActor                                  0x45E4C0
#define CDisplay__GetUserDefinedColor                              0x45D950
#define CDisplay__GetWorldFilePath                                 0x45CEC0
#define CDisplay__is3dON                                           0x45C040
#define CDisplay__ReloadUI                                         0x46CAC0
#define CDisplay__WriteTextHD2                                     0x461380

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x53B510
#define CEditBaseWnd__SetSel                                       0x68FA70

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x68CFE0
#define CEditWnd__GetCharIndexPt                                   0x68DE30
#define CEditWnd__GetDisplayString                                 0x68D170
#define CEditWnd__GetHorzOffset                                    0x68D410
#define CEditWnd__GetLineForPrintableChar                          0x68D8E0
#define CEditWnd__GetSelStartPt                                    0x68E070
#define CEditWnd__GetSTMLSafeText                                  0x68D5A0
#define CEditWnd__PointFromPrintableChar                           0x68D9F0
#define CEditWnd__SelectableCharFromPoint                          0x68DB70
#define CEditWnd__SetEditable                                      0x68D570

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4C7A40
#define CEverQuest__DropHeldItemOnGround                           0x4CC380
#define CEverQuest__dsp_chat                                       0x4CD200
#define CEverQuest__DoTellWindow                                   0x4CC500
#define CEverQuest__EnterZone                                      0x4E2620
#define CEverQuest__GetBodyTypeDesc                                0x4C4B10
#define CEverQuest__GetClassDesc                                   0x4C4270
#define CEverQuest__GetClassThreeLetterCode                        0x4C4870
#define CEverQuest__GetDeityDesc                                   0x4C5180
#define CEverQuest__GetLangDesc                                    0x4C4EA0
#define CEverQuest__GetRaceDesc                                    0x4C5150
#define CEverQuest__InterpretCmd                                   0x4CDC30
#define CEverQuest__LeftClickedOnPlayer                            0x4E0E60
#define CEverQuest__LMouseUp                                       0x4E33A0
#define CEverQuest__RightClickedOnPlayer                           0x4E1230
#define CEverQuest__RMouseUp                                       0x4E2C20
#define CEverQuest__SetGameState                                   0x4C7EC0
#define CEverQuest__Emote                                          0x4CD3D0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x576F80
#define CGaugeWnd__CalcLinesFillRect                               0x576FF0
#define CGaugeWnd__Draw                                            0x577380

// CGuild
#define CGuild__FindMemberByName                                   0x416220

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x58D710

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x596B70
#define CInvSlotMgr__MoveItem                                      0x596D10

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x597C90

// CInvSLot
#define CInvSlot__SliderComplete                                   0x595A80

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5A5A10
#define CItemDisplayWnd__SetSpell                                  0x5F2C00

// CLabel 
#define CLabel__Draw                                               0x5AB310

// CListWnd 
#define CListWnd__AddColumn                                        0x66BD10
#define CListWnd__AddColumn1                                       0x66B840
#define CListWnd__AddLine                                          0x66B3D0
#define CListWnd__AddString                                        0x66B5A0
#define CListWnd__CalculateFirstVisibleLine                        0x668700
#define CListWnd__CalculateVSBRange                                0x66A370
#define CListWnd__ClearAllSel                                      0x667E80
#define CListWnd__CloseAndUpdateEditWindow                         0x668D20
#define CListWnd__Compare                                          0x6690D0
#define CListWnd__Draw                                             0x66A070
#define CListWnd__DrawColumnSeparators                             0x669EE0
#define CListWnd__DrawHeader                                       0x668050
#define CListWnd__DrawItem                                         0x6697E0
#define CListWnd__DrawLine                                         0x669B90
#define CListWnd__DrawSeparator                                    0x669F80
#define CListWnd__EnsureVisible                                    0x668750
#define CListWnd__ExtendSel                                        0x669710
#define CListWnd__GetColumnMinWidth                                0x667C20
#define CListWnd__GetColumnWidth                                   0x667B60
#define CListWnd__GetCurSel                                        0x667630
#define CListWnd__GetHeaderRect                                    0x667730
#define CListWnd__GetItemAtPoint                                   0x668A30
#define CListWnd__GetItemAtPoint1                                  0x668AA0
#define CListWnd__GetItemData                                      0x667910
#define CListWnd__GetItemHeight                                    0x6684B0
#define CListWnd__GetItemIcon                                      0x667AA0
#define CListWnd__GetItemRect                                      0x668820
#define CListWnd__GetItemText                                      0x667950
#define CListWnd__GetSelList                                       0x66B720
#define CListWnd__GetSeparatorRect                                 0x669010
#define CListWnd__RemoveLine                                       0x66B6D0
#define CListWnd__SetColors                                        0x667690
#define CListWnd__SetColumnJustification                           0x667C80
#define CListWnd__SetColumnWidth                                   0x667BE0
#define CListWnd__SetCurSel                                        0x667670
#define CListWnd__SetItemColor                                     0x66AFA0
#define CListWnd__SetItemData                                      0x667F20
#define CListWnd__SetItemText                                      0x66AF20
#define CListWnd__ShiftColumnSeparator                             0x669680
#define CListWnd__Sort                                             0x66BD40
#define CListWnd__ToggleSel                                        0x667DF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5BF1D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C0CA0
#define CMerchantWnd__RequestBuyItem                               0x5C1FE0
#define CMerchantWnd__RequestSellItem                              0x5C0EF0
#define CMerchantWnd__SelectBuySellSlot                            0x5C1D20

// CObfuscator
#define CObfuscator__doit                                          0x632720

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x67BC50

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x53CFF0
#define CSidlScreenWnd__CalculateVSBRange                          0x671AB0
#define CSidlScreenWnd__ConvertToRes                               0x68F950
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6733C0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x674180
#define CSidlScreenWnd__CSidlScreenWnd2                            0x674230
#define CSidlScreenWnd__dCSidlScreenWnd                            0x673BD0
#define CSidlScreenWnd__DrawSidlPiece                              0x6730A0
#define CSidlScreenWnd__EnableIniStorage                           0x672BC0
#define CSidlScreenWnd__GetSidlPiece                               0x6732A0
#define CSidlScreenWnd__Init1                                      0x673FF0
#define CSidlScreenWnd__LoadIniInfo                                0x673470
#define CSidlScreenWnd__LoadIniListWnd                             0x672D00
#define CSidlScreenWnd__LoadSidlScreen                             0x672EC0
#define CSidlScreenWnd__StoreIniInfo                               0x6727D0
#define CSidlScreenWnd__WndNotification                            0x673000

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x51B600

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x429250
#define CSliderWnd__SetValue                                       0x690720
#define CSliderWnd__SetNumTicks                                    0x690C50

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5F1890

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x686090
#define CStmlWnd__CalculateVSBRange                                0x67E470
#define CStmlWnd__CanBreakAtCharacter                              0x67E5B0
#define CStmlWnd__FastForwardToEndOfTag                            0x67F0C0
#define CStmlWnd__GetNextTagPiece                                  0x67EFE0
#define CStmlWnd__GetSTMLText                                      0x5645A0
#define CStmlWnd__GetThisChar                                      0x6AEFA0
#define CStmlWnd__GetVisiableText                                  0x6802D0
#define CStmlWnd__InitializeWindowVariables                        0x682420
#define CStmlWnd__MakeStmlColorTag                                 0x67DB10
#define CStmlWnd__MakeWndNotificationTag                           0x67DBB0
#define CStmlWnd__StripFirstSTMLLines                              0x685E20
#define CStmlWnd__UpdateHistoryString                              0x680B20

// CTabWnd 
#define CTabWnd__Draw                                              0x6919F0
#define CTabWnd__DrawCurrentPage                                   0x6913F0
#define CTabWnd__DrawTab                                           0x6911D0
#define CTabWnd__GetCurrentPage                                    0x691670
#define CTabWnd__GetPageClientRect                                 0x690EA0
#define CTabWnd__GetPageFromTabIndex                               0x691100
#define CTabWnd__GetPageInnerRect                                  0x690F00
#define CTabWnd__GetTabInnerRect                                   0x691080
#define CTabWnd__GetTabRect                                        0x690F90
#define CTabWnd__IndexInBounds                                     0x69119D
#define CTabWnd__InsertPage                                        0x691C10
#define CTabWnd__SetPage                                           0x6916B0
#define CTabWnd__SetPageRect                                       0x691920
#define CTabWnd__UpdatePage                                        0x691B90

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x412790

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x674590

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x698110

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6673A0

// CXRect 
#define CXRect__CenterPoint                                        0x5410C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412330
#define CXStr__CXStr1                                              0x403580
#define CXStr__CXStr3                                              0x65BC30
#define CXStr__dCXStr                                              0x66C780
#define CXStr__operator_equal1                                     0x65BDF0
#define CXStr__operator_plus_equal1                                0x65CCE0

// CXWnd 
#define CXWnd__BringToTop                                          0x66CD60
#define CXWnd__Center                                              0x670900
#define CXWnd__ClrFocus                                            0x66CA50
#define CXWnd__DoAllDrawing                                        0x671390
#define CXWnd__DrawChildren                                        0x6714C0
#define CXWnd__DrawColoredRect                                     0x66D000
#define CXWnd__DrawTooltip                                         0x6712B0
#define CXWnd__DrawTooltipAtPoint                                  0x6706E0
#define CXWnd__GetBorderFrame                                      0x66D4D0
#define CXWnd__GetChildWndAt                                       0x670180
#define CXWnd__GetClientClipRect                                   0x66D400
#define CXWnd__GetFirstChildWnd                                    0x66CE00
#define CXWnd__GetNextChildWnd                                     0x670140
#define CXWnd__GetNextSib                                          0x66CE20
#define CXWnd__GetScreenClipRect                                   0x670B20
#define CXWnd__GetScreenRect                                       0x66D680
#define CXWnd__GetTooltipRect                                      0x66D230
#define CXWnd__GetWindowTextA                                      0x534680
#define CXWnd__IsActive                                            0x6880E0
#define CXWnd__IsDescendantOf                                      0x66D480
#define CXWnd__IsReallyVisible                                     0x670120
#define CXWnd__IsType                                              0x692AE0
#define CXWnd__Move                                                0x66FBE0
#define CXWnd__Move1                                               0x66FC80
#define CXWnd__ProcessTransition                                   0x66CD30
#define CXWnd__Refade                                              0x66CB00
#define CXWnd__Resize                                              0x66D750
#define CXWnd__Right                                               0x670A60
#define CXWnd__SetFirstChildPointer                                0x66D930
#define CXWnd__SetFocus                                            0x66EC60
#define CXWnd__SetKeyTooltip                                       0x66D990
#define CXWnd__SetMouseOver                                        0x66D960
#define CXWnd__SetNextSibPointer                                   0x66D950
#define CXWnd__StartFade                                           0x66CD80

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6895A0
#define CXWndManager__DrawWindows                                  0x6891E0
#define CXWndManager__GetFirstChildWnd                             0x688A70
#define CXWndManager__GetKeyboardFlags                             0x687DA0
#define CXWndManager__HandleKeyboardMsg                            0x6882D0
#define CXWndManager__RemoveWnd                                    0x6881F0

// CDBStr
#define CDBStr__GetString                                          0x45A8E0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6BADF0
#define EQ_Character__CastSpell                                    0x422CD0
#define EQ_Character__Cur_HP                                       0x42A970
#define EQ_Character__GetAACastingTimeModifier                     0x41DD90
#define EQ_Character__GetCharInfo2                                 0x632E60
#define EQ_Character__GetFocusCastingTimeModifier                  0x419D20
#define EQ_Character__GetFocusRangeModifier                        0x419E50
#define EQ_Character__Max_Endurance                                0x429560
#define EQ_Character__Max_HP                                       0x429410
#define EQ_Character__Max_Mana                                     0x500220
#define EQ_Character__doCombatAbility                              0x4FF0A0
#define EQ_Character__UseSkill                                     0x4368C0
#define EQ_Character__GetConLevel                                  0x4FC310

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F04B0
#define EQ_Item__GetItemLinkHash                                   0x631D80
#define EQ_Item__IsStackable                                       0x628BE0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x472D60
#define EQ_LoadingS__Array                                         0x7655A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x503390
#define EQ_PC__GetAltAbilityIndex                                  0x637EB0
#define EQ_PC__GetCombatAbility                                    0x637F40
#define EQ_PC__GetCombatAbilityTimer                               0x637FF0
#define EQ_PC__GetItemTimerValue                                   0x4FE0C0
#define EQ_PC__HasLoreItem                                         0x5017E0

// EQItemList 
#define EQItemList__dEQItemList                                    0x49BC10
#define EQItemList__EQItemList                                     0x49BB60

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45A2F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x508030
#define EQPlayer__dEQPlayer                                        0x50C780
#define EQPlayer__DoAttack                                         0x518170
#define EQPlayer__EQPlayer                                         0x50F320
#define EQPlayer__SetNameSpriteState                               0x50A840
#define EQPlayer__SetNameSpriteTint                                0x5080A0
#define EQPlayer__IsBodyType_j                                     0x6BA7E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5102B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F2090
#define KeypressHandler__AttachKeyToEqCommand                      0x4F20D0
#define KeypressHandler__ClearCommandStateArray                    0x4F1EA0
#define KeypressHandler__HandleKeyDown                             0x4F0AA0
#define KeypressHandler__HandleKeyUp                               0x4F0DA0
#define KeypressHandler__SaveKeymapping                            0x4F1F70

// MapViewMap 
#define MapViewMap__Clear                                          0x5BB1E0
#define MapViewMap__SaveEx                                         0x5BBBB0

#define OtherCharData__GetAltCurrency                              0x653250

// StringTable 
#define StringTable__getString                                     0x628570
