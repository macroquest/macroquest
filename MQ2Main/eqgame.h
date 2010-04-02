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
#define __ExpectedVersionDate                                     "Jan 16 2008"
#define __ExpectedVersionTime                                     "14:00:16"
#define __ActualVersionDate                                        0x7162FC
#define __ActualVersionTime                                        0x716308

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FAD70
#define __MemChecker1                                              0x660D50
#define __MemChecker2                                              0x52EDC0
#define __MemChecker3                                              0x52ED10
#define __MemChecker4                                              0x625AD0
#define __EncryptPad0                                              0x774108
#define __EncryptPad1                                              0x77DEA0
#define __EncryptPad2                                              0x776A80
#define __EncryptPad3                                              0x776680
#define __EncryptPad4                                              0x77D580

// Direct Input
#define DI8__Main                                                  0x9B98CC
#define DI8__Keyboard                                              0x9B98D0
#define DI8__Mouse                                                 0x9B98D4
#define __AltTimerReady                                            0x9485A2
#define __Attack                                                   0x9A5EAE
#define __Autofire                                                 0x9A5EAF
#define __BindList                                                 0x76F2C8
#define __Clicks                                                   0x9472C0
#define __CommandList                                              0x76FAD8
#define __CurrentMapLabel                                          0x9C4AE0
#define __CurrentSocial                                            0x76B544
#define __DoAbilityAvailable                                       0x94853C
#define __DoAbilityList                                            0x97D9CC
#define __do_loot                                                  0x4A5B20
#define __DrawHandler                                              0x9D3D9C
#define __GroupCount                                               0x9277D2
#define __GroupLeader                                              0x927B24
#define __Guilds                                                   0x9294F0
#define __gWorld                                                   0x92942C
#define __HotkeyPage                                               0x9A4DB8
#define __HWnd                                                     0x9B960C
#define __InChatMode                                               0x9471F8
#define __LastTell                                                 0x948E64
#define __LMouseHeldTime                                           0x9472E0
#define __Mouse                                                    0x9B98D8
#define __MouseLook                                                0x94728E
#define __NetStatusToggle                                          0x947290
#define __PCNames                                                  0x9488BC
#define __RangeAttackReady                                         0x9485A0
#define __RMouseHeldTime                                           0x9472DC
#define __RunWalkState                                             0x9471FC
#define __ScreenMode                                               0x877130
#define __ScreenX                                                  0x9471B0
#define __ScreenY                                                  0x9471B4
#define __ScreenXMax                                               0x9471B8
#define __ScreenYMax                                               0x9471BC
#define __ServerHost                                               0x92771C
#define __ServerName                                               0x97D98C
#define __ShiftKeyDown                                             0x947858
#define __ShowNames                                                0x948794
#define __Socials                                                  0x97DA8C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x941140
#define instEQZoneInfo                                             0x94742C
#define instKeypressHandler                                        0x9A5F98
#define pinstActiveBanker                                          0x9294C4
#define pinstActiveCorpse                                          0x9294C8
#define pinstActiveGMaster                                         0x9294CC
#define pinstActiveMerchant                                        0x9294C0
#define pinstAltAdvManager                                         0x877F80
#define pinstAuraMgr                                               0x782FCC
#define pinstBandageTarget                                         0x9294AC
#define pinstCamActor                                              0x877A70
#define pinstCDBStr                                                0x877120
#define pinstCDisplay                                              0x9294D4
#define pinstCEverQuest                                            0x9B9A50
#define pinstCharData                                              0x929490
#define pinstCharSpawn                                             0x9294B8
#define pinstControlledMissile                                     0x92948C
#define pinstControlledPlayer                                      0x9294B8
#define pinstCSidlManager                                          0x9D3580
#define pinstCXWndManager                                          0x9D3578
#define instDynamicZone                                            0x946C00
#define pinstDZMember                                              0x946D10
#define pinstDZTimerInfo                                           0x946D14
#define pinstEQItemList                                            0x929474
#define instEQMisc                                                 0x8770D8
#define pinstEQSoundManager                                        0x877FA4
#define instExpeditionLeader                                       0x946C4A
#define instExpeditionName                                         0x946C8A
#define instGroup                                                  0x9279C8
#define pinstGroup                                                 0x9277CE
#define pinstImeManager                                            0x9D3584
#define pinstLocalPlayer                                           0x9294A4
#define pinstModelPlayer                                           0x9294D0
#define pinstPCData                                                0x929490
#define pinstSkillMgr                                              0x9B683C
#define pinstSpawnManager                                          0x9B67BC
#define pinstSpellManager                                          0x9B6840
#define pinstSpellSets                                             0x9A4DBC
#define pinstStringTable                                           0x929448
#define pinstSwitchManager                                         0x927418
#define pinstTarget                                                0x9294BC
#define pinstTargetObject                                          0x929494
#define pinstTargetSwitch                                          0x929498
#define pinstTaskMember                                            0x8770B8
#define pinstTrackTarget                                           0x9294B0
#define pinstTradeTarget                                           0x9294A0
#define instTributeActive                                          0x8770FD
#define pinstViewActor                                             0x877A6C
#define pinstWorldData                                             0x929470


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x781500
#define pinstCAudioTriggersWindow                                  0x7814CC
#define pinstCCharacterSelect                                      0x877980
#define pinstCFacePick                                             0x877938
#define pinstCNoteWnd                                              0x87793C
#define pinstCBookWnd                                              0x877940
#define pinstCPetInfoWnd                                           0x877944
#define pinstCTrainWnd                                             0x877948
#define pinstCSkillsWnd                                            0x87794C
#define pinstCSkillsSelectWnd                                      0x877950
#define pinstCCombatSkillSelectWnd                                 0x877954
#define pinstCFriendsWnd                                           0x877958
#define pinstCAuraWnd                                              0x87795C
#define pinstCRespawnWnd                                           0x877960
#define pinstCBandolierWnd                                         0x877964
#define pinstCPotionBeltWnd                                        0x877968
#define pinstCAAWnd                                                0x87796C
#define pinstCGroupSearchFiltersWnd                                0x877970
#define pinstCLoadskinWnd                                          0x877974
#define pinstCAlarmWnd                                             0x877978
#define pinstCMusicPlayerWnd                                       0x87797C
#define pinstCMailWnd                                              0x877984
#define pinstCMailCompositionWnd                                   0x877988
#define pinstCMailAddressBookWnd                                   0x87798C
#define pinstCRaidWnd                                              0x877994
#define pinstCRaidOptionsWnd                                       0x877998
#define pinstCBreathWnd                                            0x87799C
#define pinstCMapViewWnd                                           0x8779A0
#define pinstCMapToolbarWnd                                        0x8779A4
#define pinstCEditLabelWnd                                         0x8779A8
#define pinstCTargetWnd                                            0x8779AC
#define pinstCColorPickerWnd                                       0x8779B0
#define pinstCPlayerWnd                                            0x8779B4
#define pinstCOptionsWnd                                           0x8779B8
#define pinstCBuffWindowNORMAL                                     0x8779BC
#define pinstCBuffWindowSHORT                                      0x8779C0
#define pinstCharacterCreation                                     0x8779C4
#define pinstCCursorAttachment                                     0x8779C8
#define pinstCCastingWnd                                           0x8779CC
#define pinstCCastSpellWnd                                         0x8779D0
#define pinstCSpellBookWnd                                         0x8779D4
#define pinstCInventoryWnd                                         0x8779D8
#define pinstCBankWnd                                              0x8779DC
#define pinstCQuantityWnd                                          0x8779E0
#define pinstCLootWnd                                              0x8779E4
#define pinstCActionsWnd                                           0x8779E8
#define pinstCCombatAbilityWnd                                     0x8779EC
#define pinstCMerchantWnd                                          0x8779F0
#define pinstCTradeWnd                                             0x8779F4
#define pinstCSelectorWnd                                          0x8779F8
#define pinstCBazaarWnd                                            0x8779FC
#define pinstCBazaarSearchWnd                                      0x877A00
#define pinstCGiveWnd                                              0x877A04
#define pinstCTrackingWnd                                          0x877A08
#define pinstCInspectWnd                                           0x877A0C
#define pinstCSocialEditWnd                                        0x877A10
#define pinstCFeedbackWnd                                          0x877A14
#define pinstCBugReportWnd                                         0x877A18
#define pinstCVideoModesWnd                                        0x877A1C
#define pinstCTextEntryWnd                                         0x877A24
#define pinstCFileSelectionWnd                                     0x877A28
#define pinstCCompassWnd                                           0x877A2C
#define pinstCPlayerNotesWnd                                       0x877A30
#define pinstCGemsGameWnd                                          0x877A34
#define pinstCTimeLeftWnd                                          0x877A38
#define pinstCPetitionQWnd                                         0x877A3C
#define pinstCSoulmarkWnd                                          0x877A40
#define pinstCStoryWnd                                             0x877A44
#define pinstCJournalTextWnd                                       0x877A48
#define pinstCJournalCatWnd                                        0x877A4C
#define pinstCBodyTintWnd                                          0x877A50
#define pinstCServerListWnd                                        0x877A54
#define pinstCAvaZoneWnd                                           0x877A58
#define pinstCBlockedBuffWnd                                       0x877A5C
#define pinstCBlockedPetBuffWnd                                    0x877A60
#define pinstCInvSlotMgr                                           0x877A64
#define pinstCContainerMgr                                         0x877A68
#define pinstCAdventureLeaderboardWnd                              0x9C2034
#define pinstCAdventureRequestWnd                                  0x9C2050
#define pinstCAltStorageWnd                                        0x9C20B0
#define pinstCAdventureStatsWnd                                    0x9C206C
#define pinstCBarterMerchantWnd                                    0x9C227C
#define pinstCBarterSearchWnd                                      0x9C2298
#define pinstCBarterWnd                                            0x9C22B4
#define pinstCChatManager                                          0x9C2554
#define pinstCDynamicZoneWnd                                       0x9C264C
#define pinstCEQMainWnd                                            0x9C26BC
#define pinstCFellowshipWnd                                        0x9C2720
#define pinstCFindLocationWnd                                      0x9C2754
#define pinstCGroupSearchWnd                                       0x9C2804
#define pinstCGroupWnd                                             0x9C2820
#define pinstCGuildBankWnd                                         0x9C283C
#define pinstCGuildMgmtWnd                                         0x9C4858
#define pinstCGuildTributeMasterWnd                                0x9C4878
#define pinstCHotButtonWnd                                         0x9C4894
#define pinstCHotButtonWnd1                                        0x9C4894
#define pinstCHotButtonWnd2                                        0x9C4898
#define pinstCHotButtonWnd3                                        0x9C489C
#define pinstCHotButtonWnd4                                        0x9C48A0
#define pinstCItemDisplayManager                                   0x9C494C
#define pinstCItemExpTransferWnd                                   0x9C496C
#define pinstCLeadershipWnd                                        0x9C4A08
#define pinstCLFGuildWnd                                           0x9C4A24
#define pinstCMIZoneSelectWnd                                      0x9C4B48
#define pinstCAdventureMerchantWnd                                 0x9C4C40
#define pinstCConfirmationDialog                                   0x9C4C5C
#define pinstCPopupWndManager                                      0x9C4C5C
#define pinstCProgressionSelectionWnd                              0x9C4C90
#define pinstCPvPLeaderboardWnd                                    0x9C4CAC
#define pinstCPvPStatsWnd                                          0x9C4CC8
#define pinstCSystemInfoDialogBox                                  0x9C4D78
#define pinstCTargetOfTargetWnd                                    0x9C566C
#define pinstCTaskSelectWnd                                        0x9C5688
#define pinstCTaskTemplateSelectWnd                                0x9C56A4
#define pinstCTaskWnd                                              0x9C56C0
#define pinstCTipWndOFDAY                                          0x9C573C
#define pinstCTipWndCONTEXT                                        0x9C5740
#define pinstCTitleWnd                                             0x9C575C
#define pinstCTradeskillWnd                                        0x9C57A0
#define pinstCTributeBenefitWnd                                    0x9C57EC
#define pinstCTributeMasterWnd                                     0x9C5808
#define pinstCContextMenuManager                                   0x9D35DC
#define pinstCVoiceMacroWnd                                        0x9B692C
#define pinstCHtmlWnd                                              0x9B6948


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4B7890
#define __ConvertItemTags                                          0x4AAD00
#define __ExecuteCmd                                               0x49A390
#define __get_melee_range                                          0x49F590
#define __GetGaugeValueFromEQ                                      0x5F7AD0
#define __GetLabelFromEQ                                           0x5F82D0
#define __NewUIINI                                                 0x5F76C0
#define __ProcessGameEvents                                        0x4E6200
#define CrashDetected                                              0x52DA90
#define DrawNetStatus                                              0x4FDB20
#define Util__FastTime                                             0x6613D0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x473EB0
#define AltAdvManager__IsAbilityReady                              0x473EF0
#define AltAdvManager__GetAltAbility                               0x474080

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x544C90

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x54E5E0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x68CC10

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x561D40
#define CChatManager__InitContextMenu                              0x5624D0

// CChatService
#define CChatService__GetNumberOfFriends                           0x651A30
#define CChatService__GetFriendName                                0x651A40

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x566640
#define CChatWindow__WndNotification                               0x567070

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x672E60
#define CComboWnd__Draw                                            0x673010
#define CComboWnd__GetCurChoice                                    0x672E00
#define CComboWnd__GetListRect                                     0x6732E0
#define CComboWnd__GetTextRect                                     0x672E90
#define CComboWnd__InsertChoice                                    0x673350
#define CComboWnd__SetColors                                       0x672D90
#define CComboWnd__SetChoice                                       0x672DC0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x56DA20
#define CContainerWnd__vftable                                     0x71CBB0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x4630C0
#define CDisplay__GetClickedActor                                  0x460800
#define CDisplay__GetUserDefinedColor                              0x45F980
#define CDisplay__GetWorldFilePath                                 0x45EEF0
#define CDisplay__is3dON                                           0x45E050
#define CDisplay__ReloadUI                                         0x46EC50
#define CDisplay__WriteTextHD2                                     0x4637F0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x53EDF0
#define CEditBaseWnd__SetSel                                       0x697CA0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x680C10
#define CEditWnd__GetCharIndexPt                                   0x681A60
#define CEditWnd__GetDisplayString                                 0x680DA0
#define CEditWnd__GetHorzOffset                                    0x681040
#define CEditWnd__GetLineForPrintableChar                          0x681510
#define CEditWnd__GetSelStartPt                                    0x681CA0
#define CEditWnd__GetSTMLSafeText                                  0x6811D0
#define CEditWnd__PointFromPrintableChar                           0x681620
#define CEditWnd__SelectableCharFromPoint                          0x6817A0
#define CEditWnd__SetEditable                                      0x6811A0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4C9CF0
#define CEverQuest__DropHeldItemOnGround                           0x4CE600
#define CEverQuest__dsp_chat                                       0x4CF480
#define CEverQuest__DoTellWindow                                   0x4CE780
#define CEverQuest__EnterZone                                      0x4E4C40
#define CEverQuest__GetBodyTypeDesc                                0x4C7180
#define CEverQuest__GetClassDesc                                   0x4C68E0
#define CEverQuest__GetClassThreeLetterCode                        0x4C6EE0
#define CEverQuest__GetDeityDesc                                   0x4C77F0
#define CEverQuest__GetLangDesc                                    0x4C7510
#define CEverQuest__GetRaceDesc                                    0x4C77C0
#define CEverQuest__InterpretCmd                                   0x4CFEB0
#define CEverQuest__LeftClickedOnPlayer                            0x4E3460
#define CEverQuest__LMouseUp                                       0x4E59E0
#define CEverQuest__RightClickedOnPlayer                           0x4E3830
#define CEverQuest__RMouseUp                                       0x4E5240
#define CEverQuest__SetGameState                                   0x4CA170
#define CEverQuest__Emote                                          0x4CF650

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x578F80
#define CGaugeWnd__CalcLinesFillRect                               0x578FF0
#define CGaugeWnd__Draw                                            0x579380

// CGuild
#define CGuild__FindMemberByName                                   0x417CE0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x58F830

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x598D10
#define CInvSlotMgr__MoveItem                                      0x598EB0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x599E10

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x597700
#define CInvSlot__SliderComplete                                   0x597C10

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5A7B90
#define CItemDisplayWnd__SetSpell                                  0x5F59D0

// CLabel 
#define CLabel__Draw                                               0x5AD3F0

// CListWnd 
#define CListWnd__AddColumn                                        0x672BA0
#define CListWnd__AddColumn1                                       0x672690
#define CListWnd__AddLine                                          0x672270
#define CListWnd__AddString                                        0x672440
#define CListWnd__CalculateFirstVisibleLine                        0x66F5A0
#define CListWnd__CalculateVSBRange                                0x671210
#define CListWnd__ClearAllSel                                      0x66ED10
#define CListWnd__CloseAndUpdateEditWindow                         0x66FBC0
#define CListWnd__Compare                                          0x66FF70
#define CListWnd__Draw                                             0x670F10
#define CListWnd__DrawColumnSeparators                             0x670D80
#define CListWnd__DrawHeader                                       0x66EEE0
#define CListWnd__DrawItem                                         0x670680
#define CListWnd__DrawLine                                         0x670A30
#define CListWnd__DrawSeparator                                    0x670E20
#define CListWnd__EnsureVisible                                    0x66F5F0
#define CListWnd__ExtendSel                                        0x6705B0
#define CListWnd__GetColumnMinWidth                                0x66EAB0
#define CListWnd__GetColumnWidth                                   0x66E9F0
#define CListWnd__GetCurSel                                        0x66E4C0
#define CListWnd__GetHeaderRect                                    0x66E5C0
#define CListWnd__GetItemAtPoint                                   0x66F8D0
#define CListWnd__GetItemAtPoint1                                  0x66F940
#define CListWnd__GetItemData                                      0x66E7A0
#define CListWnd__GetItemHeight                                    0x66F340
#define CListWnd__GetItemIcon                                      0x66E930
#define CListWnd__GetItemRect                                      0x66F6C0
#define CListWnd__GetItemText                                      0x66E7E0
#define CListWnd__GetSelList                                       0x672570
#define CListWnd__GetSeparatorRect                                 0x66FEB0
#define CListWnd__RemoveLine                                       0x672B50
#define CListWnd__SetColors                                        0x66E520
#define CListWnd__SetColumnJustification                           0x66EB10
#define CListWnd__SetColumnWidth                                   0x66EA70
#define CListWnd__SetCurSel                                        0x66E500
#define CListWnd__SetItemColor                                     0x671E40
#define CListWnd__SetItemData                                      0x66EDB0
#define CListWnd__SetItemText                                      0x671DC0
#define CListWnd__ShiftColumnSeparator                             0x670520
#define CListWnd__Sort                                             0x672BD0
#define CListWnd__ToggleSel                                        0x66EC80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5C1EB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C3990
#define CMerchantWnd__RequestBuyItem                               0x5C4CD0
#define CMerchantWnd__RequestSellItem                              0x5C3BF0
#define CMerchantWnd__SelectBuySellSlot                            0x5C4A00

// CObfuscator
#define CObfuscator__doit                                          0x638EA0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x688780

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x678980
#define CSidlScreenWnd__CalculateVSBRange                          0x6788C0
#define CSidlScreenWnd__ConvertToRes                               0x697B80
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x67A2A0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x67B0D0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x67B180
#define CSidlScreenWnd__dCSidlScreenWnd                            0x67AB20
#define CSidlScreenWnd__DrawSidlPiece                              0x679F80
#define CSidlScreenWnd__EnableIniStorage                           0x679A80
#define CSidlScreenWnd__GetSidlPiece                               0x67A180
#define CSidlScreenWnd__Init1                                      0x67AF40
#define CSidlScreenWnd__LoadIniInfo                                0x67A350
#define CSidlScreenWnd__LoadIniListWnd                             0x679BD0
#define CSidlScreenWnd__LoadSidlScreen                             0x679D90
#define CSidlScreenWnd__StoreIniInfo                               0x679690
#define CSidlScreenWnd__WndNotification                            0x679EE0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x51EA50

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x41E860
#define CSliderWnd__SetValue                                       0x698950
#define CSliderWnd__SetNumTicks                                    0x698E80

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5F4660

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x695E30
#define CStmlWnd__CalculateVSBRange                                0x68E1D0
#define CStmlWnd__CanBreakAtCharacter                              0x68E310
#define CStmlWnd__FastForwardToEndOfTag                            0x68EE20
#define CStmlWnd__ForceParseNow                                    0x696290
#define CStmlWnd__GetNextTagPiece                                  0x68ED40
#define CStmlWnd__GetSTMLText                                      0x5665E0
#define CStmlWnd__GetThisChar                                      0x6B6110
#define CStmlWnd__GetVisiableText                                  0x690060
#define CStmlWnd__InitializeWindowVariables                        0x6921C0
#define CStmlWnd__MakeStmlColorTag                                 0x68D870
#define CStmlWnd__MakeWndNotificationTag                           0x68D910
#define CStmlWnd__SetSTMLText                                      0x6922E0
#define CStmlWnd__StripFirstSTMLLines                              0x695BC0
#define CStmlWnd__UpdateHistoryString                              0x6908C0

// CTabWnd 
#define CTabWnd__Draw                                              0x699C20
#define CTabWnd__DrawCurrentPage                                   0x699620
#define CTabWnd__DrawTab                                           0x699400
#define CTabWnd__GetCurrentPage                                    0x6998A0
#define CTabWnd__GetPageClientRect                                 0x6990D0
#define CTabWnd__GetPageFromTabIndex                               0x699330
#define CTabWnd__GetPageInnerRect                                  0x699130
#define CTabWnd__GetTabInnerRect                                   0x6992B0
#define CTabWnd__GetTabRect                                        0x6991C0
#define CTabWnd__IndexInBounds                                     0x6993CD
#define CTabWnd__InsertPage                                        0x699E40
#define CTabWnd__SetPage                                           0x6998E0
#define CTabWnd__SetPageRect                                       0x699B50
#define CTabWnd__UpdatePage                                        0x699DC0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x414210

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x67B4E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x69F180

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x66E230

// CXRect 
#define CXRect__CenterPoint                                        0x5443F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4124A0
#define CXStr__CXStr1                                              0x5CADD0
#define CXStr__CXStr3                                              0x662B10
#define CXStr__dCXStr                                              0x4065A0
#define CXStr__operator_equal1                                     0x662CD0
#define CXStr__operator_plus_equal1                                0x663BC0

// CXWnd 
#define CXWnd__BringToTop                                          0x673B90
#define CXWnd__Center                                              0x677730
#define CXWnd__ClrFocus                                            0x6738C0
#define CXWnd__DoAllDrawing                                        0x6781B0
#define CXWnd__DrawChildren                                        0x6782E0
#define CXWnd__DrawColoredRect                                     0x673E30
#define CXWnd__DrawTooltip                                         0x6780D0
#define CXWnd__DrawTooltipAtPoint                                  0x677510
#define CXWnd__GetBorderFrame                                      0x674320
#define CXWnd__GetChildWndAt                                       0x676FA0
#define CXWnd__GetClientClipRect                                   0x674250
#define CXWnd__GetFirstChildWnd                                    0x673C30
#define CXWnd__GetNextChildWnd                                     0x676F60
#define CXWnd__GetNextSib                                          0x673C50
#define CXWnd__GetScreenClipRect                                   0x677950
#define CXWnd__GetScreenRect                                       0x6744D0
#define CXWnd__GetTooltipRect                                      0x674080
#define CXWnd__GetWindowTextA                                      0x537F70
#define CXWnd__IsActive                                            0x67C5F0
#define CXWnd__IsDescendantOf                                      0x6742D0
#define CXWnd__IsReallyVisible                                     0x676F40
#define CXWnd__IsType                                              0x69AD00
#define CXWnd__Move                                                0x676A50
#define CXWnd__Move1                                               0x676AE0
#define CXWnd__ProcessTransition                                   0x673B60
#define CXWnd__Refade                                              0x673970
#define CXWnd__Resize                                              0x674590
#define CXWnd__Right                                               0x677890
#define CXWnd__SetFirstChildPointer                                0x674770
#define CXWnd__SetFocus                                            0x675B00
#define CXWnd__SetKeyTooltip                                       0x6747E0
#define CXWnd__SetMouseOver                                        0x6747B0
#define CXWnd__SetNextSibPointer                                   0x674790
#define CXWnd__StartFade                                           0x673BB0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x67DAF0
#define CXWndManager__DrawWindows                                  0x67D730
#define CXWndManager__GetFirstChildWnd                             0x67CF90
#define CXWndManager__GetKeyboardFlags                             0x67C2A0
#define CXWndManager__HandleKeyboardMsg                            0x67C7E0
#define CXWndManager__RemoveWnd                                    0x67C700

// CDBStr
#define CDBStr__GetString                                          0x45C960

// EQ_Character 
#define EQ_Character__CastRay                                      0x6C2100
#define EQ_Character__CastSpell                                    0x4252B0
#define EQ_Character__Cur_HP                                       0x431CC0
#define EQ_Character__GetAACastingTimeModifier                     0x41FB90
#define EQ_Character__GetCharInfo2                                 0x644200
#define EQ_Character__GetFocusCastingTimeModifier                  0x41B820
#define EQ_Character__GetFocusRangeModifier                        0x41B950
#define EQ_Character__Max_Endurance                                0x42D050
#define EQ_Character__Max_HP                                       0x42CED0
#define EQ_Character__Max_Mana                                     0x5030A0
#define EQ_Character__doCombatAbility                              0x501D60
#define EQ_Character__UseSkill                                     0x437DA0
#define EQ_Character__GetConLevel                                  0x4FEEE0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F2B90
#define EQ_Item__GetItemLinkHash                                   0x638560
#define EQ_Item__IsStackable                                       0x62F480

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x474FD0
#define EQ_LoadingS__Array                                         0x76D7D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x506250
#define EQ_PC__GetAltAbilityIndex                                  0x63D2F0
#define EQ_PC__GetCombatAbility                                    0x63D380
#define EQ_PC__GetCombatAbilityTimer                               0x63D430
#define EQ_PC__GetItemTimerValue                                   0x500CC0
#define EQ_PC__HasLoreItem                                         0x5046B0

// EQItemList 
#define EQItemList__dEQItemList                                    0x49DCC0
#define EQItemList__EQItemList                                     0x49DC10

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45C350

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50B120
#define EQPlayer__dEQPlayer                                        0x50F910
#define EQPlayer__DoAttack                                         0x51B500
#define EQPlayer__EQPlayer                                         0x5125E0
#define EQPlayer__SetNameSpriteState                               0x50D890
#define EQPlayer__SetNameSpriteTint                                0x50B190
#define EQPlayer__IsBodyType_j                                     0x6C1AE0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x513510

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F47A0
#define KeypressHandler__AttachKeyToEqCommand                      0x4F47E0
#define KeypressHandler__ClearCommandStateArray                    0x4F45B0
#define KeypressHandler__HandleKeyDown                             0x4F3190
#define KeypressHandler__HandleKeyUp                               0x4F3490
#define KeypressHandler__SaveKeymapping                            0x4F4680

// MapViewMap 
#define MapViewMap__Clear                                          0x5BDED0
#define MapViewMap__SaveEx                                         0x5BE8A0

#define OtherCharData__GetAltCurrency                              0x65A0C0

// StringTable 
#define StringTable__getString                                     0x62EE60
