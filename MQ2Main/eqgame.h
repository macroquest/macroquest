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
#define __ExpectedVersionDate                                     "Feb  5 2008"
#define __ExpectedVersionTime                                     "10:37:00"
#define __ActualVersionDate                                        0x71631C
#define __ActualVersionTime                                        0x716328

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FAD40
#define __MemChecker1                                              0x6619C0
#define __MemChecker2                                              0x52EC60
#define __MemChecker3                                              0x52EBB0
#define __MemChecker4                                              0x625E40
#define __EncryptPad0                                              0x770120
#define __EncryptPad1                                              0x779EB8
#define __EncryptPad2                                              0x772A98
#define __EncryptPad3                                              0x772698
#define __EncryptPad4                                              0x779598

// Direct Input
#define DI8__Main                                                  0x9B783C
#define DI8__Keyboard                                              0x9B7840
#define DI8__Mouse                                                 0x9B7844
#define __AltTimerReady                                            0x9445BA
#define __Attack                                                   0x9A1EFE
#define __Autofire                                                 0x9A1EFF
#define __BindList                                                 0x76B2C8
#define __Clicks                                                   0x9432D8
#define __CommandList                                              0x76BAD8
#define __CurrentMapLabel                                          0x9E2A58
#define __CurrentSocial                                            0x767544
#define __DoAbilityAvailable                                       0x944554
#define __DoAbilityList                                            0x979A1C
#define __do_loot                                                  0x4A5B20
#define __DrawHandler                                              0x9F1D1C
#define __GroupCount                                               0x9237EA
#define __GroupLeader                                              0x923B3C
#define __Guilds                                                   0x925508
#define __gWorld                                                   0x925444
#define __HotkeyPage                                               0x9A0E08
#define __HWnd                                                     0x9B757C
#define __InChatMode                                               0x943210
#define __LastTell                                                 0x944EB4
#define __LMouseHeldTime                                           0x9432F8
#define __Mouse                                                    0x9B7848
#define __MouseLook                                                0x9432A6
#define __NetStatusToggle                                          0x9432A8
#define __PCNames                                                  0x94490C
#define __RangeAttackReady                                         0x9445B8
#define __RMouseHeldTime                                           0x9432F4
#define __RunWalkState                                             0x943214
#define __ScreenMode                                               0x873150
#define __ScreenX                                                  0x9431C8
#define __ScreenY                                                  0x9431CC
#define __ScreenXMax                                               0x9431D0
#define __ScreenYMax                                               0x9431D4
#define __ServerHost                                               0x923734
#define __ServerName                                               0x9799DC
#define __ShiftKeyDown                                             0x943870
#define __ShowNames                                                0x9447E4
#define __Socials                                                  0x979ADC


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x93D158
#define instEQZoneInfo                                             0x943444
#define instKeypressHandler                                        0x9A1FE8
#define pinstActiveBanker                                          0x9254DC
#define pinstActiveCorpse                                          0x9254E0
#define pinstActiveGMaster                                         0x9254E4
#define pinstActiveMerchant                                        0x9254D8
#define pinstAltAdvManager                                         0x873FA0
#define pinstAuraMgr                                               0x77EFEC
#define pinstBandageTarget                                         0x9254C4
#define pinstCamActor                                              0x873A90
#define pinstCDBStr                                                0x873140
#define pinstCDisplay                                              0x9254EC
#define pinstCEverQuest                                            0x9B79C0
#define pinstCharData                                              0x9254A8
#define pinstCharSpawn                                             0x9254D0
#define pinstControlledMissile                                     0x9254A4
#define pinstControlledPlayer                                      0x9254D0
#define pinstCSidlManager                                          0x9F1500
#define pinstCXWndManager                                          0x9F14F8
#define instDynamicZone                                            0x942C18
#define pinstDZMember                                              0x942D28
#define pinstDZTimerInfo                                           0x942D2C
#define pinstEQItemList                                            0x92548C
#define instEQMisc                                                 0x8730F8
#define pinstEQSoundManager                                        0x873FC4
#define instExpeditionLeader                                       0x942C62
#define instExpeditionName                                         0x942CA2
#define instGroup                                                  0x9239E0
#define pinstGroup                                                 0x9237E6
#define pinstImeManager                                            0x9F1504
#define pinstLocalPlayer                                           0x9254BC
#define pinstModelPlayer                                           0x9254E8
#define pinstPCData                                                0x9254A8
#define pinstSkillMgr                                              0x9B47AC
#define pinstSpawnManager                                          0x9B472C
#define pinstSpellManager                                          0x9B47B0
#define pinstSpellSets                                             0x9A0E0C
#define pinstStringTable                                           0x925460
#define pinstSwitchManager                                         0x923434
#define pinstTarget                                                0x9254D4
#define pinstTargetObject                                          0x9254AC
#define pinstTargetSwitch                                          0x9254B0
#define pinstTaskMember                                            0x8730D8
#define pinstTrackTarget                                           0x9254C8
#define pinstTradeTarget                                           0x9254B8
#define instTributeActive                                          0x87311D
#define pinstViewActor                                             0x873A8C
#define pinstWorldData                                             0x925488


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x77D520
#define pinstCAudioTriggersWindow                                  0x77D4EC
#define pinstCCharacterSelect                                      0x8739A0
#define pinstCFacePick                                             0x873958
#define pinstCNoteWnd                                              0x87395C
#define pinstCBookWnd                                              0x873960
#define pinstCPetInfoWnd                                           0x873964
#define pinstCTrainWnd                                             0x873968
#define pinstCSkillsWnd                                            0x87396C
#define pinstCSkillsSelectWnd                                      0x873970
#define pinstCCombatSkillSelectWnd                                 0x873974
#define pinstCFriendsWnd                                           0x873978
#define pinstCAuraWnd                                              0x87397C
#define pinstCRespawnWnd                                           0x873980
#define pinstCBandolierWnd                                         0x873984
#define pinstCPotionBeltWnd                                        0x873988
#define pinstCAAWnd                                                0x87398C
#define pinstCGroupSearchFiltersWnd                                0x873990
#define pinstCLoadskinWnd                                          0x873994
#define pinstCAlarmWnd                                             0x873998
#define pinstCMusicPlayerWnd                                       0x87399C
#define pinstCMailWnd                                              0x8739A4
#define pinstCMailCompositionWnd                                   0x8739A8
#define pinstCMailAddressBookWnd                                   0x8739AC
#define pinstCRaidWnd                                              0x8739B4
#define pinstCRaidOptionsWnd                                       0x8739B8
#define pinstCBreathWnd                                            0x8739BC
#define pinstCMapViewWnd                                           0x8739C0
#define pinstCMapToolbarWnd                                        0x8739C4
#define pinstCEditLabelWnd                                         0x8739C8
#define pinstCTargetWnd                                            0x8739CC
#define pinstCColorPickerWnd                                       0x8739D0
#define pinstCPlayerWnd                                            0x8739D4
#define pinstCOptionsWnd                                           0x8739D8
#define pinstCBuffWindowNORMAL                                     0x8739DC
#define pinstCBuffWindowSHORT                                      0x8739E0
#define pinstCharacterCreation                                     0x8739E4
#define pinstCCursorAttachment                                     0x8739E8
#define pinstCCastingWnd                                           0x8739EC
#define pinstCCastSpellWnd                                         0x8739F0
#define pinstCSpellBookWnd                                         0x8739F4
#define pinstCInventoryWnd                                         0x8739F8
#define pinstCBankWnd                                              0x8739FC
#define pinstCQuantityWnd                                          0x873A00
#define pinstCLootWnd                                              0x873A04
#define pinstCActionsWnd                                           0x873A08
#define pinstCCombatAbilityWnd                                     0x873A0C
#define pinstCMerchantWnd                                          0x873A10
#define pinstCTradeWnd                                             0x873A14
#define pinstCSelectorWnd                                          0x873A18
#define pinstCBazaarWnd                                            0x873A1C
#define pinstCBazaarSearchWnd                                      0x873A20
#define pinstCGiveWnd                                              0x873A24
#define pinstCTrackingWnd                                          0x873A28
#define pinstCInspectWnd                                           0x873A2C
#define pinstCSocialEditWnd                                        0x873A30
#define pinstCFeedbackWnd                                          0x873A34
#define pinstCBugReportWnd                                         0x873A38
#define pinstCVideoModesWnd                                        0x873A3C
#define pinstCTextEntryWnd                                         0x873A44
#define pinstCFileSelectionWnd                                     0x873A48
#define pinstCCompassWnd                                           0x873A4C
#define pinstCPlayerNotesWnd                                       0x873A50
#define pinstCGemsGameWnd                                          0x873A54
#define pinstCTimeLeftWnd                                          0x873A58
#define pinstCPetitionQWnd                                         0x873A5C
#define pinstCSoulmarkWnd                                          0x873A60
#define pinstCStoryWnd                                             0x873A64
#define pinstCJournalTextWnd                                       0x873A68
#define pinstCJournalCatWnd                                        0x873A6C
#define pinstCBodyTintWnd                                          0x873A70
#define pinstCServerListWnd                                        0x873A74
#define pinstCAvaZoneWnd                                           0x873A78
#define pinstCBlockedBuffWnd                                       0x873A7C
#define pinstCBlockedPetBuffWnd                                    0x873A80
#define pinstCInvSlotMgr                                           0x873A84
#define pinstCContainerMgr                                         0x873A88
#define pinstCAdventureLeaderboardWnd                              0x9DFFA8
#define pinstCAdventureRequestWnd                                  0x9DFFC4
#define pinstCAltStorageWnd                                        0x9E0024
#define pinstCAdventureStatsWnd                                    0x9DFFE0
#define pinstCBarterMerchantWnd                                    0x9E01F0
#define pinstCBarterSearchWnd                                      0x9E020C
#define pinstCBarterWnd                                            0x9E0228
#define pinstCChatManager                                          0x9E04CC
#define pinstCDynamicZoneWnd                                       0x9E05C4
#define pinstCEQMainWnd                                            0x9E0634
#define pinstCFellowshipWnd                                        0x9E0698
#define pinstCFindLocationWnd                                      0x9E06CC
#define pinstCGroupSearchWnd                                       0x9E077C
#define pinstCGroupWnd                                             0x9E0798
#define pinstCGuildBankWnd                                         0x9E07B4
#define pinstCGuildMgmtWnd                                         0x9E27D0
#define pinstCGuildTributeMasterWnd                                0x9E27F0
#define pinstCHotButtonWnd                                         0x9E280C
#define pinstCHotButtonWnd1                                        0x9E280C
#define pinstCHotButtonWnd2                                        0x9E2810
#define pinstCHotButtonWnd3                                        0x9E2814
#define pinstCHotButtonWnd4                                        0x9E2818
#define pinstCItemDisplayManager                                   0x9E28C4
#define pinstCItemExpTransferWnd                                   0x9E28E4
#define pinstCLeadershipWnd                                        0x9E2980
#define pinstCLFGuildWnd                                           0x9E299C
#define pinstCMIZoneSelectWnd                                      0x9E2AC0
#define pinstCAdventureMerchantWnd                                 0x9E2BB8
#define pinstCConfirmationDialog                                   0x9E2BD4
#define pinstCPopupWndManager                                      0x9E2BD4
#define pinstCProgressionSelectionWnd                              0x9E2C08
#define pinstCPvPLeaderboardWnd                                    0x9E2C24
#define pinstCPvPStatsWnd                                          0x9E2C40
#define pinstCSystemInfoDialogBox                                  0x9E2CF0
#define pinstCTargetOfTargetWnd                                    0x9E35E4
#define pinstCTaskSelectWnd                                        0x9E3600
#define pinstCTaskTemplateSelectWnd                                0x9E361C
#define pinstCTaskWnd                                              0x9E3638
#define pinstCTipWndOFDAY                                          0x9E36B4
#define pinstCTipWndCONTEXT                                        0x9E36B8
#define pinstCTitleWnd                                             0x9E36D4
#define pinstCTradeskillWnd                                        0x9E3718
#define pinstCTributeBenefitWnd                                    0x9E3764
#define pinstCTributeMasterWnd                                     0x9E3780
#define pinstCContextMenuManager                                   0x9F155C
#define pinstCVoiceMacroWnd                                        0x9B489C
#define pinstCHtmlWnd                                              0x9B48B8


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4B7B00
#define __ConvertItemTags                                          0x4AACA0
#define __ExecuteCmd                                               0x49A380
#define __get_melee_range                                          0x49F590
#define __GetGaugeValueFromEQ                                      0x5F7DF0
#define __GetLabelFromEQ                                           0x5F85F0
#define __NewUIINI                                                 0x5F79E0
#define __ProcessGameEvents                                        0x4E61E0
#define CrashDetected                                              0x52D930
#define DrawNetStatus                                              0x4FDAF0
#define Util__FastTime                                             0x662110


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x473DF0
#define AltAdvManager__IsAbilityReady                              0x473E30
#define AltAdvManager__GetAltAbility                               0x473F80

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x544E40

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x54E790

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x68D710

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x561E10
#define CChatManager__InitContextMenu                              0x5625A0

// CChatService
#define CChatService__GetNumberOfFriends                           0x652320
#define CChatService__GetFriendName                                0x652330

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x566710
#define CChatWindow__WndNotification                               0x567140

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x673C30
#define CComboWnd__Draw                                            0x673DE0
#define CComboWnd__GetCurChoice                                    0x673BD0
#define CComboWnd__GetListRect                                     0x6740B0
#define CComboWnd__GetTextRect                                     0x673C60
#define CComboWnd__InsertChoice                                    0x674120
#define CComboWnd__SetColors                                       0x673B60
#define CComboWnd__SetChoice                                       0x673B90

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x56DBE0
#define CContainerWnd__vftable                                     0x71CBC8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x463030
#define CDisplay__GetClickedActor                                  0x460780
#define CDisplay__GetUserDefinedColor                              0x45F900
#define CDisplay__GetWorldFilePath                                 0x45EE70
#define CDisplay__is3dON                                           0x45DFD0
#define CDisplay__ReloadUI                                         0x46EB90
#define CDisplay__WriteTextHD2                                     0x463760

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x53EE30
#define CEditBaseWnd__SetSel                                       0x6987E0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x681860
#define CEditWnd__GetCharIndexPt                                   0x6826B0
#define CEditWnd__GetDisplayString                                 0x6819F0
#define CEditWnd__GetHorzOffset                                    0x681C90
#define CEditWnd__GetLineForPrintableChar                          0x682160
#define CEditWnd__GetSelStartPt                                    0x6828F0
#define CEditWnd__GetSTMLSafeText                                  0x681E20
#define CEditWnd__PointFromPrintableChar                           0x682270
#define CEditWnd__SelectableCharFromPoint                          0x6823F0
#define CEditWnd__SetEditable                                      0x681DF0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4C9CD0
#define CEverQuest__DropHeldItemOnGround                           0x4CE5E0
#define CEverQuest__dsp_chat                                       0x4CF460
#define CEverQuest__DoTellWindow                                   0x4CE760
#define CEverQuest__EnterZone                                      0x4E4C20
#define CEverQuest__GetBodyTypeDesc                                0x4C7160
#define CEverQuest__GetClassDesc                                   0x4C68C0
#define CEverQuest__GetClassThreeLetterCode                        0x4C6EC0
#define CEverQuest__GetDeityDesc                                   0x4C77D0
#define CEverQuest__GetLangDesc                                    0x4C74F0
#define CEverQuest__GetRaceDesc                                    0x4C77A0
#define CEverQuest__InterpretCmd                                   0x4CFE90
#define CEverQuest__LeftClickedOnPlayer                            0x4E3440
#define CEverQuest__LMouseUp                                       0x4E59C0
#define CEverQuest__RightClickedOnPlayer                           0x4E3810
#define CEverQuest__RMouseUp                                       0x4E5220
#define CEverQuest__SetGameState                                   0x4CA150
#define CEverQuest__Emote                                          0x4CF630

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5791A0
#define CGaugeWnd__CalcLinesFillRect                               0x579210
#define CGaugeWnd__Draw                                            0x5795A0

// CGuild
#define CGuild__FindMemberByName                                   0x417B70

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x58F9E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x598E00
#define CInvSlotMgr__MoveItem                                      0x598FA0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x599F00

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5977F0
#define CInvSlot__SliderComplete                                   0x597D00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5A7C80
#define CItemDisplayWnd__SetSpell                                  0x5F5C50

// CLabel 
#define CLabel__Draw                                               0x5AD510

// CListWnd 
#define CListWnd__AddColumn                                        0x673970
#define CListWnd__AddColumn1                                       0x673450
#define CListWnd__AddLine                                          0x673030
#define CListWnd__AddString                                        0x673200
#define CListWnd__CalculateFirstVisibleLine                        0x670360
#define CListWnd__CalculateVSBRange                                0x671FD0
#define CListWnd__ClearAllSel                                      0x66FAD0
#define CListWnd__CloseAndUpdateEditWindow                         0x670980
#define CListWnd__Compare                                          0x670D30
#define CListWnd__Draw                                             0x671CD0
#define CListWnd__DrawColumnSeparators                             0x671B40
#define CListWnd__DrawHeader                                       0x66FCA0
#define CListWnd__DrawItem                                         0x671440
#define CListWnd__DrawLine                                         0x6717F0
#define CListWnd__DrawSeparator                                    0x671BE0
#define CListWnd__EnsureVisible                                    0x6703B0
#define CListWnd__ExtendSel                                        0x671370
#define CListWnd__GetColumnMinWidth                                0x66F870
#define CListWnd__GetColumnWidth                                   0x66F7B0
#define CListWnd__GetCurSel                                        0x66F280
#define CListWnd__GetHeaderRect                                    0x66F380
#define CListWnd__GetItemAtPoint                                   0x670690
#define CListWnd__GetItemAtPoint1                                  0x670700
#define CListWnd__GetItemData                                      0x66F560
#define CListWnd__GetItemHeight                                    0x670100
#define CListWnd__GetItemIcon                                      0x66F6F0
#define CListWnd__GetItemRect                                      0x670480
#define CListWnd__GetItemText                                      0x66F5A0
#define CListWnd__GetSelList                                       0x673330
#define CListWnd__GetSeparatorRect                                 0x670C70
#define CListWnd__RemoveLine                                       0x673920
#define CListWnd__SetColors                                        0x66F2E0
#define CListWnd__SetColumnJustification                           0x66F8D0
#define CListWnd__SetColumnWidth                                   0x66F830
#define CListWnd__SetCurSel                                        0x66F2C0
#define CListWnd__SetItemColor                                     0x672C00
#define CListWnd__SetItemData                                      0x66FB70
#define CListWnd__SetItemText                                      0x672B80
#define CListWnd__ShiftColumnSeparator                             0x6712E0
#define CListWnd__Sort                                             0x6739A0
#define CListWnd__ToggleSel                                        0x66FA40

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5C1FF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C3AD0
#define CMerchantWnd__RequestBuyItem                               0x5C4E10
#define CMerchantWnd__RequestSellItem                              0x5C3D30
#define CMerchantWnd__SelectBuySellSlot                            0x5C4B40

// CObfuscator
#define CObfuscator__doit                                          0x639200

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6892F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x540920
#define CSidlScreenWnd__CalculateVSBRange                          0x540860
#define CSidlScreenWnd__ConvertToRes                               0x6986C0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x67AF20
#define CSidlScreenWnd__CSidlScreenWnd1                            0x67BD50
#define CSidlScreenWnd__CSidlScreenWnd2                            0x67BE00
#define CSidlScreenWnd__dCSidlScreenWnd                            0x67B7A0
#define CSidlScreenWnd__DrawSidlPiece                              0x67AC00
#define CSidlScreenWnd__EnableIniStorage                           0x67A700
#define CSidlScreenWnd__GetSidlPiece                               0x67AE00
#define CSidlScreenWnd__Init1                                      0x67BBC0
#define CSidlScreenWnd__LoadIniInfo                                0x67AFD0
#define CSidlScreenWnd__LoadIniListWnd                             0x67A850
#define CSidlScreenWnd__LoadSidlScreen                             0x67AA10
#define CSidlScreenWnd__StoreIniInfo                               0x67A310
#define CSidlScreenWnd__WndNotification                            0x67AB60

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x51E8C0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x41E770
#define CSliderWnd__SetValue                                       0x699490
#define CSliderWnd__SetNumTicks                                    0x6999C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5F48E0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x696950
#define CStmlWnd__CalculateVSBRange                                0x68ECF0
#define CStmlWnd__CanBreakAtCharacter                              0x68EE30
#define CStmlWnd__FastForwardToEndOfTag                            0x68F940
#define CStmlWnd__ForceParseNow                                    0x696DB0
#define CStmlWnd__GetNextTagPiece                                  0x68F860
#define CStmlWnd__GetSTMLText                                      0x5666B0
#define CStmlWnd__GetThisChar                                      0x6B6C50
#define CStmlWnd__GetVisiableText                                  0x690B80
#define CStmlWnd__InitializeWindowVariables                        0x692CE0
#define CStmlWnd__MakeStmlColorTag                                 0x68E370
#define CStmlWnd__MakeWndNotificationTag                           0x68E410
#define CStmlWnd__SetSTMLText                                      0x692E00
#define CStmlWnd__StripFirstSTMLLines                              0x6966E0
#define CStmlWnd__UpdateHistoryString                              0x6913E0

// CTabWnd 
#define CTabWnd__Draw                                              0x69A760
#define CTabWnd__DrawCurrentPage                                   0x69A160
#define CTabWnd__DrawTab                                           0x699F40
#define CTabWnd__GetCurrentPage                                    0x69A3E0
#define CTabWnd__GetPageClientRect                                 0x699C10
#define CTabWnd__GetPageFromTabIndex                               0x699E70
#define CTabWnd__GetPageInnerRect                                  0x699C70
#define CTabWnd__GetTabInnerRect                                   0x699DF0
#define CTabWnd__GetTabRect                                        0x699D00
#define CTabWnd__IndexInBounds                                     0x699F0D
#define CTabWnd__InsertPage                                        0x69A980
#define CTabWnd__SetPage                                           0x69A420
#define CTabWnd__SetPageRect                                       0x69A690
#define CTabWnd__UpdatePage                                        0x69A900

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4140A0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x67C160

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x69FCD0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x66EFF0

// CXRect 
#define CXRect__CenterPoint                                        0x5445A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412410
#define CXStr__CXStr1                                              0x403580
#define CXStr__CXStr3                                              0x663810
#define CXStr__dCXStr                                              0x5F6890
#define CXStr__operator_equal1                                     0x6639D0
#define CXStr__operator_plus_equal1                                0x6648D0

// CXWnd 
#define CXWnd__BringToTop                                          0x674960
#define CXWnd__Center                                              0x678520
#define CXWnd__ClrFocus                                            0x674690
#define CXWnd__DoAllDrawing                                        0x678FA0
#define CXWnd__DrawChildren                                        0x6790D0
#define CXWnd__DrawColoredRect                                     0x674C00
#define CXWnd__DrawTooltip                                         0x678EC0
#define CXWnd__DrawTooltipAtPoint                                  0x678300
#define CXWnd__GetBorderFrame                                      0x6750F0
#define CXWnd__GetChildWndAt                                       0x677D90
#define CXWnd__GetClientClipRect                                   0x675020
#define CXWnd__GetFirstChildWnd                                    0x674A00
#define CXWnd__GetNextChildWnd                                     0x677D50
#define CXWnd__GetNextSib                                          0x674A20
#define CXWnd__GetScreenClipRect                                   0x678740
#define CXWnd__GetScreenRect                                       0x6752A0
#define CXWnd__GetTooltipRect                                      0x674E50
#define CXWnd__GetWindowTextA                                      0x537FA0
#define CXWnd__IsActive                                            0x67D270
#define CXWnd__IsDescendantOf                                      0x6750A0
#define CXWnd__IsReallyVisible                                     0x677D30
#define CXWnd__IsType                                              0x69B850
#define CXWnd__Move                                                0x677840
#define CXWnd__Move1                                               0x6778D0
#define CXWnd__ProcessTransition                                   0x674930
#define CXWnd__Refade                                              0x674740
#define CXWnd__Resize                                              0x675360
#define CXWnd__Right                                               0x678680
#define CXWnd__SetFirstChildPointer                                0x675560
#define CXWnd__SetFocus                                            0x6768F0
#define CXWnd__SetKeyTooltip                                       0x6755D0
#define CXWnd__SetMouseOver                                        0x6755A0
#define CXWnd__SetNextSibPointer                                   0x675580
#define CXWnd__StartFade                                           0x674980

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x67E740
#define CXWndManager__DrawWindows                                  0x67E380
#define CXWndManager__GetFirstChildWnd                             0x67DC10
#define CXWndManager__GetKeyboardFlags                             0x67CF20
#define CXWndManager__HandleKeyboardMsg                            0x67D460
#define CXWndManager__RemoveWnd                                    0x67D380

// CDBStr
#define CDBStr__GetString                                          0x45C890

// EQ_Character 
#define EQ_Character__CastRay                                      0x6C2B50
#define EQ_Character__CastSpell                                    0x4251E0
#define EQ_Character__Cur_HP                                       0x431BC0
#define EQ_Character__GetAACastingTimeModifier                     0x41FAC0
#define EQ_Character__GetCharInfo2                                 0x644730
#define EQ_Character__GetFocusCastingTimeModifier                  0x41B700
#define EQ_Character__GetFocusRangeModifier                        0x41B830
#define EQ_Character__Max_Endurance                                0x42CF50
#define EQ_Character__Max_HP                                       0x42CDD0
#define EQ_Character__Max_Mana                                     0x503080
#define EQ_Character__doCombatAbility                              0x501D40
#define EQ_Character__UseSkill                                     0x437CA0
#define EQ_Character__GetConLevel                                  0x4FEEC0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F2B60
#define EQ_Item__GetItemLinkHash                                   0x6388C0
#define EQ_Item__IsStackable                                       0x62F7E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x474ED0
#define EQ_LoadingS__Array                                         0x7697D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x506230
#define EQ_PC__GetAltAbilityIndex                                  0x63D830
#define EQ_PC__GetCombatAbility                                    0x63D8C0
#define EQ_PC__GetCombatAbilityTimer                               0x63D970
#define EQ_PC__GetItemTimerValue                                   0x500CA0
#define EQ_PC__HasLoreItem                                         0x504690

// EQItemList 
#define EQItemList__dEQItemList                                    0x49DCB0
#define EQItemList__EQItemList                                     0x49DC00

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45C230

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50B0E0
#define EQPlayer__dEQPlayer                                        0x50F8A0
#define EQPlayer__DoAttack                                         0x51B3A0
#define EQPlayer__EQPlayer                                         0x512550
#define EQPlayer__SetNameSpriteState                               0x50D820
#define EQPlayer__SetNameSpriteTint                                0x50B150
#define EQPlayer__IsBodyType_j                                     0x6C2510

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x513480

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F4770
#define KeypressHandler__AttachKeyToEqCommand                      0x4F47B0
#define KeypressHandler__ClearCommandStateArray                    0x4F4580
#define KeypressHandler__HandleKeyDown                             0x4F3160
#define KeypressHandler__HandleKeyUp                               0x4F3460
#define KeypressHandler__SaveKeymapping                            0x4F4650

// MapViewMap 
#define MapViewMap__Clear                                          0x5BE010
#define MapViewMap__SaveEx                                         0x5BE9E0

#define OtherCharData__GetAltCurrency                              0x65A9C0

// StringTable 
#define StringTable__getString                                     0x62F1B0
