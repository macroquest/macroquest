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
#define __ExpectedVersionDate                                     "Mar 31 2008"
#define __ExpectedVersionTime                                     "17:04:46"
#define __ActualVersionDate                                        0x717344
#define __ActualVersionTime                                        0x717350

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FB6A0
#define __MemChecker1                                              0x662A50
#define __MemChecker2                                              0x52F630
#define __MemChecker3                                              0x52F580
#define __MemChecker4                                              0x626E00
#define __EncryptPad0                                              0x771120
#define __EncryptPad1                                              0x77AEB8
#define __EncryptPad2                                              0x773A98
#define __EncryptPad3                                              0x773698
#define __EncryptPad4                                              0x77A598

// Direct Input
#define DI8__Main                                                  0x9B883C
#define DI8__Keyboard                                              0x9B8840
#define DI8__Mouse                                                 0x9B8844
#define __AltTimerReady                                            0x9455BA
#define __Attack                                                   0x9A2EFE
#define __Autofire                                                 0x9A2EFF
#define __BindList                                                 0x76C2C8
#define __Clicks                                                   0x9442D8
#define __CommandList                                              0x76CAD8
#define __CurrentMapLabel                                          0x9E3A58
#define __CurrentSocial                                            0x768544
#define __DoAbilityAvailable                                       0x945554
#define __DoAbilityList                                            0x97AA1C
#define __do_loot                                                  0x4A6060
#define __DrawHandler                                              0x9F2D1C
#define __GroupCount                                               0x9247EA
#define __GroupLeader                                              0x924B3C
#define __Guilds                                                   0x926508
#define __gWorld                                                   0x926444
#define __HotkeyPage                                               0x9A1E08
#define __HWnd                                                     0x9B857C
#define __InChatMode                                               0x944210
#define __LastTell                                                 0x945EB4
#define __LMouseHeldTime                                           0x9442F8
#define __Mouse                                                    0x9B8848
#define __MouseLook                                                0x9442A6
#define __NetStatusToggle                                          0x9442A8
#define __PCNames                                                  0x94590C
#define __RangeAttackReady                                         0x9455B8
#define __RMouseHeldTime                                           0x9442F4
#define __RunWalkState                                             0x944214
#define __ScreenMode                                               0x874150
#define __ScreenX                                                  0x9441C8
#define __ScreenY                                                  0x9441CC
#define __ScreenXMax                                               0x9441D0
#define __ScreenYMax                                               0x9441D4
#define __ServerHost                                               0x924734
#define __ServerName                                               0x97A9DC
#define __ShiftKeyDown                                             0x944870
#define __ShowNames                                                0x9457E4
#define __Socials                                                  0x97AADC


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x93E158
#define instEQZoneInfo                                             0x944444
#define instKeypressHandler                                        0x9A2FE8
#define pinstActiveBanker                                          0x9264DC
#define pinstActiveCorpse                                          0x9264E0
#define pinstActiveGMaster                                         0x9264E4
#define pinstActiveMerchant                                        0x9264D8
#define pinstAltAdvManager                                         0x874FA0
#define pinstAuraMgr                                               0x77FFEC
#define pinstBandageTarget                                         0x9264C4
#define pinstCamActor                                              0x874A90
#define pinstCDBStr                                                0x874140
#define pinstCDisplay                                              0x9264EC
#define pinstCEverQuest                                            0x9B89C0
#define pinstCharData                                              0x9264A8
#define pinstCharSpawn                                             0x9264D0
#define pinstControlledMissile                                     0x9264A4
#define pinstControlledPlayer                                      0x9264D0
#define pinstCSidlManager                                          0x9F2500
#define pinstCXWndManager                                          0x9F24F8
#define instDynamicZone                                            0x943C18
#define pinstDZMember                                              0x943D28
#define pinstDZTimerInfo                                           0x943D2C
#define pinstEQItemList                                            0x92648C
#define instEQMisc                                                 0x8740F8
#define pinstEQSoundManager                                        0x874FC4
#define instExpeditionLeader                                       0x943C62
#define instExpeditionName                                         0x943CA2
#define instGroup                                                  0x9249E0
#define pinstGroup                                                 0x9247E6
#define pinstImeManager                                            0x9F2504
#define pinstLocalPlayer                                           0x9264BC
#define pinstModelPlayer                                           0x9264E8
#define pinstPCData                                                0x9264A8
#define pinstSkillMgr                                              0x9B57AC
#define pinstSpawnManager                                          0x9B572C
#define pinstSpellManager                                          0x9B57B0
#define pinstSpellSets                                             0x9A1E0C
#define pinstStringTable                                           0x926460
#define pinstSwitchManager                                         0x924434
#define pinstTarget                                                0x9264D4
#define pinstTargetObject                                          0x9264AC
#define pinstTargetSwitch                                          0x9264B0
#define pinstTaskMember                                            0x8740D8
#define pinstTrackTarget                                           0x9264C8
#define pinstTradeTarget                                           0x9264B8
#define instTributeActive                                          0x87411D
#define pinstViewActor                                             0x874A8C
#define pinstWorldData                                             0x926488


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x77E520
#define pinstCAudioTriggersWindow                                  0x77E4EC
#define pinstCCharacterSelect                                      0x8749A0
#define pinstCFacePick                                             0x874958
#define pinstCNoteWnd                                              0x87495C
#define pinstCBookWnd                                              0x874960
#define pinstCPetInfoWnd                                           0x874964
#define pinstCTrainWnd                                             0x874968
#define pinstCSkillsWnd                                            0x87496C
#define pinstCSkillsSelectWnd                                      0x874970
#define pinstCCombatSkillSelectWnd                                 0x874974
#define pinstCFriendsWnd                                           0x874978
#define pinstCAuraWnd                                              0x87497C
#define pinstCRespawnWnd                                           0x874980
#define pinstCBandolierWnd                                         0x874984
#define pinstCPotionBeltWnd                                        0x874988
#define pinstCAAWnd                                                0x87498C
#define pinstCGroupSearchFiltersWnd                                0x874990
#define pinstCLoadskinWnd                                          0x874994
#define pinstCAlarmWnd                                             0x874998
#define pinstCMusicPlayerWnd                                       0x87499C
#define pinstCMailWnd                                              0x8749A4
#define pinstCMailCompositionWnd                                   0x8749A8
#define pinstCMailAddressBookWnd                                   0x8749AC
#define pinstCRaidWnd                                              0x8749B4
#define pinstCRaidOptionsWnd                                       0x8749B8
#define pinstCBreathWnd                                            0x8749BC
#define pinstCMapViewWnd                                           0x8749C0
#define pinstCMapToolbarWnd                                        0x8749C4
#define pinstCEditLabelWnd                                         0x8749C8
#define pinstCTargetWnd                                            0x8749CC
#define pinstCColorPickerWnd                                       0x8749D0
#define pinstCPlayerWnd                                            0x8749D4
#define pinstCOptionsWnd                                           0x8749D8
#define pinstCBuffWindowNORMAL                                     0x8749DC
#define pinstCBuffWindowSHORT                                      0x8749E0
#define pinstCharacterCreation                                     0x8749E4
#define pinstCCursorAttachment                                     0x8749E8
#define pinstCCastingWnd                                           0x8749EC
#define pinstCCastSpellWnd                                         0x8749F0
#define pinstCSpellBookWnd                                         0x8749F4
#define pinstCInventoryWnd                                         0x8749F8
#define pinstCBankWnd                                              0x8749FC
#define pinstCQuantityWnd                                          0x874A00
#define pinstCLootWnd                                              0x874A04
#define pinstCActionsWnd                                           0x874A08
#define pinstCCombatAbilityWnd                                     0x874A0C
#define pinstCMerchantWnd                                          0x874A10
#define pinstCTradeWnd                                             0x874A14
#define pinstCSelectorWnd                                          0x874A18
#define pinstCBazaarWnd                                            0x874A1C
#define pinstCBazaarSearchWnd                                      0x874A20
#define pinstCGiveWnd                                              0x874A24
#define pinstCTrackingWnd                                          0x874A28
#define pinstCInspectWnd                                           0x874A2C
#define pinstCSocialEditWnd                                        0x874A30
#define pinstCFeedbackWnd                                          0x874A34
#define pinstCBugReportWnd                                         0x874A38
#define pinstCVideoModesWnd                                        0x874A3C
#define pinstCTextEntryWnd                                         0x874A44
#define pinstCFileSelectionWnd                                     0x874A48
#define pinstCCompassWnd                                           0x874A4C
#define pinstCPlayerNotesWnd                                       0x874A50
#define pinstCGemsGameWnd                                          0x874A54
#define pinstCTimeLeftWnd                                          0x874A58
#define pinstCPetitionQWnd                                         0x874A5C
#define pinstCSoulmarkWnd                                          0x874A60
#define pinstCStoryWnd                                             0x874A64
#define pinstCJournalTextWnd                                       0x874A68
#define pinstCJournalCatWnd                                        0x874A6C
#define pinstCBodyTintWnd                                          0x874A70
#define pinstCServerListWnd                                        0x874A74
#define pinstCAvaZoneWnd                                           0x874A78
#define pinstCBlockedBuffWnd                                       0x874A7C
#define pinstCBlockedPetBuffWnd                                    0x874A80
#define pinstCInvSlotMgr                                           0x874A84
#define pinstCContainerMgr                                         0x874A88
#define pinstCAdventureLeaderboardWnd                              0x9E0FA8
#define pinstCAdventureRequestWnd                                  0x9E0FC4
#define pinstCAltStorageWnd                                        0x9E1024
#define pinstCAdventureStatsWnd                                    0x9E0FE0
#define pinstCBarterMerchantWnd                                    0x9E11F0
#define pinstCBarterSearchWnd                                      0x9E120C
#define pinstCBarterWnd                                            0x9E1228
#define pinstCChatManager                                          0x9E14CC
#define pinstCDynamicZoneWnd                                       0x9E15C4
#define pinstCEQMainWnd                                            0x9E1634
#define pinstCFellowshipWnd                                        0x9E1698
#define pinstCFindLocationWnd                                      0x9E16CC
#define pinstCGroupSearchWnd                                       0x9E177C
#define pinstCGroupWnd                                             0x9E1798
#define pinstCGuildBankWnd                                         0x9E17B4
#define pinstCGuildMgmtWnd                                         0x9E37D0
#define pinstCGuildTributeMasterWnd                                0x9E37F0
#define pinstCHotButtonWnd                                         0x9E380C
#define pinstCHotButtonWnd1                                        0x9E380C
#define pinstCHotButtonWnd2                                        0x9E3810
#define pinstCHotButtonWnd3                                        0x9E3814
#define pinstCHotButtonWnd4                                        0x9E3818
#define pinstCItemDisplayManager                                   0x9E38C4
#define pinstCItemExpTransferWnd                                   0x9E38E4
#define pinstCLeadershipWnd                                        0x9E3980
#define pinstCLFGuildWnd                                           0x9E399C
#define pinstCMIZoneSelectWnd                                      0x9E3AC0
#define pinstCAdventureMerchantWnd                                 0x9E3BB8
#define pinstCConfirmationDialog                                   0x9E3BD4
#define pinstCPopupWndManager                                      0x9E3BD4
#define pinstCProgressionSelectionWnd                              0x9E3C08
#define pinstCPvPLeaderboardWnd                                    0x9E3C24
#define pinstCPvPStatsWnd                                          0x9E3C40
#define pinstCSystemInfoDialogBox                                  0x9E3CF0
#define pinstCTargetOfTargetWnd                                    0x9E45E4
#define pinstCTaskSelectWnd                                        0x9E4600
#define pinstCTaskTemplateSelectWnd                                0x9E461C
#define pinstCTaskWnd                                              0x9E4638
#define pinstCTipWndOFDAY                                          0x9E46B4
#define pinstCTipWndCONTEXT                                        0x9E46B8
#define pinstCTitleWnd                                             0x9E46D4
#define pinstCTradeskillWnd                                        0x9E4718
#define pinstCTributeBenefitWnd                                    0x9E4764
#define pinstCTributeMasterWnd                                     0x9E4780
#define pinstCContextMenuManager                                   0x9F255C
#define pinstCVoiceMacroWnd                                        0x9B589C
#define pinstCHtmlWnd                                              0x9B58B8


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4B8040
#define __ConvertItemTags                                          0x4AB1E0
#define __ExecuteCmd                                               0x49A8B0
#define __get_melee_range                                          0x49FAD0
#define __GetGaugeValueFromEQ                                      0x5F8DB0
#define __GetLabelFromEQ                                           0x5F95B0
#define __NewUIINI                                                 0x5F89A0
#define __ProcessGameEvents                                        0x4E6AD0
#define CrashDetected                                              0x52E2F0
#define DrawNetStatus                                              0x4FE490
#define Util__FastTime                                             0x663160


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x474310
#define AltAdvManager__IsAbilityReady                              0x474350
#define AltAdvManager__GetAltAbility                               0x4744A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x545730

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x54F080

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x68E7B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x562770
#define CChatManager__InitContextMenu                              0x562F00

// CChatService
#define CChatService__GetNumberOfFriends                           0x653260
#define CChatService__GetFriendName                                0x653270

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x567070
#define CChatWindow__WndNotification                               0x567AA0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x674D00
#define CComboWnd__Draw                                            0x674EB0
#define CComboWnd__GetCurChoice                                    0x674CA0
#define CComboWnd__GetListRect                                     0x675180
#define CComboWnd__GetTextRect                                     0x674D30
#define CComboWnd__InsertChoice                                    0x6751F0
#define CComboWnd__SetColors                                       0x674C30
#define CComboWnd__SetChoice                                       0x674C60

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x56E3D0
#define CContainerWnd__vftable                                     0x71DBF8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x463590
#define CDisplay__GetClickedActor                                  0x460C00
#define CDisplay__GetUserDefinedColor                              0x45FD80
#define CDisplay__GetWorldFilePath                                 0x45F2F0
#define CDisplay__is3dON                                           0x45E450
#define CDisplay__ReloadUI                                         0x46F0F0
#define CDisplay__WriteTextHD2                                     0x463CC0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x53F7D0
#define CEditBaseWnd__SetSel                                       0x699890

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x682980
#define CEditWnd__GetCharIndexPt                                   0x6837D0
#define CEditWnd__GetDisplayString                                 0x682B10
#define CEditWnd__GetHorzOffset                                    0x682DB0
#define CEditWnd__GetLineForPrintableChar                          0x683280
#define CEditWnd__GetSelStartPt                                    0x683A10
#define CEditWnd__GetSTMLSafeText                                  0x682F40
#define CEditWnd__PointFromPrintableChar                           0x683390
#define CEditWnd__SelectableCharFromPoint                          0x683510
#define CEditWnd__SetEditable                                      0x682F10

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4CA5C0
#define CEverQuest__DropHeldItemOnGround                           0x4CEED0
#define CEverQuest__dsp_chat                                       0x4CFD50
#define CEverQuest__DoTellWindow                                   0x4CF050
#define CEverQuest__EnterZone                                      0x4E5510
#define CEverQuest__GetBodyTypeDesc                                0x4C7A50
#define CEverQuest__GetClassDesc                                   0x4C71B0
#define CEverQuest__GetClassThreeLetterCode                        0x4C77B0
#define CEverQuest__GetDeityDesc                                   0x4C80C0
#define CEverQuest__GetLangDesc                                    0x4C7DE0
#define CEverQuest__GetRaceDesc                                    0x4C8090
#define CEverQuest__InterpretCmd                                   0x4D0780
#define CEverQuest__LeftClickedOnPlayer                            0x4E3D30
#define CEverQuest__LMouseUp                                       0x4E62B0
#define CEverQuest__RightClickedOnPlayer                           0x4E4100
#define CEverQuest__RMouseUp                                       0x4E5B10
#define CEverQuest__SetGameState                                   0x4CAA40
#define CEverQuest__Emote                                          0x4CFF20

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x579F00
#define CGaugeWnd__CalcLinesFillRect                               0x579F70
#define CGaugeWnd__Draw                                            0x57A300

// CGuild
#define CGuild__FindMemberByName                                   0x417BE0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x590820

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x599C70
#define CInvSlotMgr__MoveItem                                      0x599E10

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x598660
#define CInvSlot__SliderComplete                                   0x598B70

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5A8D60
#define CItemDisplayWnd__SetSpell                                  0x5F6D40

// CLabel 
#define CLabel__Draw                                               0x5AE5B0

// CListWnd 
#define CListWnd__AddColumn                                        0x674A40
#define CListWnd__AddColumn1                                       0x674580
#define CListWnd__AddLine                                          0x674110
#define CListWnd__AddString                                        0x6742E0
#define CListWnd__CalculateFirstVisibleLine                        0x671440
#define CListWnd__CalculateVSBRange                                0x6730B0
#define CListWnd__ClearAllSel                                      0x670BB0
#define CListWnd__CloseAndUpdateEditWindow                         0x671A60
#define CListWnd__Compare                                          0x671E10
#define CListWnd__Draw                                             0x672DB0
#define CListWnd__DrawColumnSeparators                             0x672C20
#define CListWnd__DrawHeader                                       0x670D80
#define CListWnd__DrawItem                                         0x672520
#define CListWnd__DrawLine                                         0x6728D0
#define CListWnd__DrawSeparator                                    0x672CC0
#define CListWnd__EnsureVisible                                    0x671490
#define CListWnd__ExtendSel                                        0x672450
#define CListWnd__GetColumnMinWidth                                0x670950
#define CListWnd__GetColumnWidth                                   0x670890
#define CListWnd__GetCurSel                                        0x670360
#define CListWnd__GetHeaderRect                                    0x670460
#define CListWnd__GetItemAtPoint                                   0x671770
#define CListWnd__GetItemAtPoint1                                  0x6717E0
#define CListWnd__GetItemData                                      0x670640
#define CListWnd__GetItemHeight                                    0x6711E0
#define CListWnd__GetItemIcon                                      0x6707D0
#define CListWnd__GetItemRect                                      0x671560
#define CListWnd__GetItemText                                      0x670680
#define CListWnd__GetSelList                                       0x674460
#define CListWnd__GetSeparatorRect                                 0x671D50
#define CListWnd__RemoveLine                                       0x674410
#define CListWnd__SetColors                                        0x6703C0
#define CListWnd__SetColumnJustification                           0x6709B0
#define CListWnd__SetColumnWidth                                   0x670910
#define CListWnd__SetCurSel                                        0x6703A0
#define CListWnd__SetItemColor                                     0x673CE0
#define CListWnd__SetItemData                                      0x670C50
#define CListWnd__SetItemText                                      0x673C60
#define CListWnd__ShiftColumnSeparator                             0x6723C0
#define CListWnd__Sort                                             0x674A70
#define CListWnd__ToggleSel                                        0x670B20

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5C30A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C4B80
#define CMerchantWnd__RequestBuyItem                               0x5C5EC0
#define CMerchantWnd__RequestSellItem                              0x5C4DE0
#define CMerchantWnd__SelectBuySellSlot                            0x5C5BF0

// CObfuscator
#define CObfuscator__doit                                          0x63A210

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x68A3B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x541200
#define CSidlScreenWnd__CalculateVSBRange                          0x67A790
#define CSidlScreenWnd__ConvertToRes                               0x699770
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x67C0C0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x67CEF0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x67CFA0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x67C940
#define CSidlScreenWnd__DrawSidlPiece                              0x67BDA0
#define CSidlScreenWnd__EnableIniStorage                           0x67B8A0
#define CSidlScreenWnd__GetSidlPiece                               0x67BFA0
#define CSidlScreenWnd__Init1                                      0x67CD60
#define CSidlScreenWnd__LoadIniInfo                                0x67C170
#define CSidlScreenWnd__LoadIniListWnd                             0x67B9F0
#define CSidlScreenWnd__LoadSidlScreen                             0x67BBB0
#define CSidlScreenWnd__StoreIniInfo                               0x67B4B0
#define CSidlScreenWnd__WndNotification                            0x67BD00

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x51F250

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x41E810
#define CSliderWnd__SetValue                                       0x69A550
#define CSliderWnd__SetNumTicks                                    0x69AA80

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5F59D0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x697A20
#define CStmlWnd__CalculateVSBRange                                0x68FD70
#define CStmlWnd__CanBreakAtCharacter                              0x68FEB0
#define CStmlWnd__FastForwardToEndOfTag                            0x690A10
#define CStmlWnd__ForceParseNow                                    0x697E80
#define CStmlWnd__GetNextTagPiece                                  0x690930
#define CStmlWnd__GetSTMLText                                      0x567010
#define CStmlWnd__GetThisChar                                      0x6B7D60
#define CStmlWnd__GetVisiableText                                  0x691C50
#define CStmlWnd__InitializeWindowVariables                        0x693DB0
#define CStmlWnd__MakeStmlColorTag                                 0x68F410
#define CStmlWnd__MakeWndNotificationTag                           0x68F4B0
#define CStmlWnd__SetSTMLText                                      0x693ED0
#define CStmlWnd__StripFirstSTMLLines                              0x6977B0
#define CStmlWnd__UpdateHistoryString                              0x6924B0

// CTabWnd 
#define CTabWnd__Draw                                              0x69B8A0
#define CTabWnd__DrawCurrentPage                                   0x69B220
#define CTabWnd__DrawTab                                           0x69B000
#define CTabWnd__GetCurrentPage                                    0x69B520
#define CTabWnd__GetPageClientRect                                 0x69ACD0
#define CTabWnd__GetPageFromTabIndex                               0x69AF30
#define CTabWnd__GetPageInnerRect                                  0x69AD30
#define CTabWnd__GetTabInnerRect                                   0x69AEB0
#define CTabWnd__GetTabRect                                        0x69ADC0
#define CTabWnd__IndexInBounds                                     0x69AFCD
#define CTabWnd__InsertPage                                        0x69BAC0
#define CTabWnd__SetPage                                           0x69B560
#define CTabWnd__SetPageRect                                       0x69B7D0
#define CTabWnd__UpdatePage                                        0x69BA40

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x414110

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x67D300

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6A0E00

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6700D0

// CXRect 
#define CXRect__CenterPoint                                        0x544E90

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4F5750
#define CXStr__CXStr1                                              0x66B0B0
#define CXStr__CXStr3                                              0x664860
#define CXStr__dCXStr                                              0x4F5AE0
#define CXStr__operator_equal1                                     0x664A20
#define CXStr__operator_plus_equal1                                0x665920

// CXWnd 
#define CXWnd__BringToTop                                          0x675A30
#define CXWnd__Center                                              0x679600
#define CXWnd__ClrFocus                                            0x675760
#define CXWnd__DoAllDrawing                                        0x67A080
#define CXWnd__DrawChildren                                        0x67A1B0
#define CXWnd__DrawColoredRect                                     0x675CE0
#define CXWnd__DrawTooltip                                         0x679FA0
#define CXWnd__DrawTooltipAtPoint                                  0x6793E0
#define CXWnd__GetBorderFrame                                      0x6761D0
#define CXWnd__GetChildWndAt                                       0x678E70
#define CXWnd__GetClientClipRect                                   0x676100
#define CXWnd__GetFirstChildWnd                                    0x675AE0
#define CXWnd__GetNextChildWnd                                     0x678E30
#define CXWnd__GetNextSib                                          0x675B00
#define CXWnd__GetScreenClipRect                                   0x679820
#define CXWnd__GetScreenRect                                       0x676380
#define CXWnd__GetTooltipRect                                      0x675F30
#define CXWnd__GetWindowTextA                                      0x538960
#define CXWnd__IsActive                                            0x67E410
#define CXWnd__IsDescendantOf                                      0x676180
#define CXWnd__IsReallyVisible                                     0x678E10
#define CXWnd__IsType                                              0x69C980
#define CXWnd__Move                                                0x678920
#define CXWnd__Move1                                               0x6789B0
#define CXWnd__ProcessTransition                                   0x675A00
#define CXWnd__Refade                                              0x675810
#define CXWnd__Resize                                              0x676440
#define CXWnd__Right                                               0x679760
#define CXWnd__SetFirstChildPointer                                0x676640
#define CXWnd__SetFocus                                            0x6779D0
#define CXWnd__SetKeyTooltip                                       0x6766B0
#define CXWnd__SetMouseOver                                        0x676680
#define CXWnd__SetNextSibPointer                                   0x676660
#define CXWnd__StartFade                                           0x675A50

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x67F860
#define CXWndManager__DrawWindows                                  0x67F4A0
#define CXWndManager__GetFirstChildWnd                             0x67EDB0
#define CXWndManager__GetKeyboardFlags                             0x67E0C0
#define CXWndManager__HandleKeyboardMsg                            0x67E600
#define CXWndManager__RemoveWnd                                    0x67E520

// CDBStr
#define CDBStr__GetString                                          0x45CD50

// EQ_Character 
#define EQ_Character__CastRay                                      0x6C3C40
#define EQ_Character__CastSpell                                    0x425330
#define EQ_Character__Cur_HP                                       0x431F00
#define EQ_Character__GetAACastingTimeModifier                     0x41FB90
#define EQ_Character__GetCharInfo2                                 0x645650
#define EQ_Character__GetFocusCastingTimeModifier                  0x41B7B0
#define EQ_Character__GetFocusRangeModifier                        0x41B8E0
#define EQ_Character__Max_Endurance                                0x42D280
#define EQ_Character__Max_HP                                       0x42D100
#define EQ_Character__Max_Mana                                     0x503A10
#define EQ_Character__doCombatAbility                              0x5026D0
#define EQ_Character__UseSkill                                     0x437FF0
#define EQ_Character__GetConLevel                                  0x4FF850

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F34B0
#define EQ_Item__GetItemLinkHash                                   0x6398D0
#define EQ_Item__IsStackable                                       0x6307A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4753F0
#define EQ_LoadingS__Array                                         0x76A7D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x506BC0
#define EQ_PC__GetAltAbilityIndex                                  0x63E750
#define EQ_PC__GetCombatAbility                                    0x63E7E0
#define EQ_PC__GetCombatAbilityTimer                               0x63E890
#define EQ_PC__GetItemTimerValue                                   0x501630
#define EQ_PC__HasLoreItem                                         0x505020

// EQItemList 
#define EQItemList__dEQItemList                                    0x49E1E0
#define EQItemList__EQItemList                                     0x49E130

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45C740

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50BAB0
#define EQPlayer__dEQPlayer                                        0x510280
#define EQPlayer__DoAttack                                         0x51BD70
#define EQPlayer__EQPlayer                                         0x512F50
#define EQPlayer__SetNameSpriteState                               0x50E1F0
#define EQPlayer__SetNameSpriteTint                                0x50BB20
#define EQPlayer__IsBodyType_j                                     0x6C3600

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x513ED0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F50C0
#define KeypressHandler__AttachKeyToEqCommand                      0x4F5100
#define KeypressHandler__ClearCommandStateArray                    0x4F4ED0
#define KeypressHandler__HandleKeyDown                             0x4F3AB0
#define KeypressHandler__HandleKeyUp                               0x4F3DB0
#define KeypressHandler__SaveKeymapping                            0x4F4FA0

// MapViewMap 
#define MapViewMap__Clear                                          0x5BF0C0
#define MapViewMap__SaveEx                                         0x5BFA90

#define OtherCharData__GetAltCurrency                              0x65BA40

// StringTable 
#define StringTable__getString                                     0x630170
