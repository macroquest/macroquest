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
#define __ExpectedVersionDate                                     "Oct 20 2008"
#define __ExpectedVersionTime                                     "01:35:22"
#define __ActualVersionDate                                        0x75FAA4
#define __ActualVersionTime                                        0x75FAB0

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FFC40
#define __MemChecker1                                              0x69FD60
#define __MemChecker2                                              0x554C00
#define __MemChecker3                                              0x554B50
#define __MemChecker4                                              0x662E90
#define __EncryptPad0                                              0x7C1360
#define __EncryptPad1                                              0x7CB848
#define __EncryptPad2                                              0x7C3D88
#define __EncryptPad3                                              0x7C3988
#define __EncryptPad4                                              0x7CAF28

// Direct Input
#define DI8__Main                                                  0xA2E56C
#define DI8__Keyboard                                              0xA2E570
#define DI8__Mouse                                                 0xA2E574
#define __AltTimerReady                                            0x9B9052
#define __Attack                                                   0xA18AEE
#define __Autofire                                                 0xA18AEF
#define __BindList                                                 0x7BC3C0
#define __Clicks                                                   0x9B7D68
#define __CommandList                                              0x7BCC20
#define __CurrentMapLabel                                          0xA59790
#define __CurrentSocial                                            0x7B85EC
#define __DoAbilityAvailable                                       0x9B8FEC
#define __DoAbilityList                                            0x9EE604
#define __do_loot                                                  0x4A7760
#define __DrawHandler                                              0xA68B94
#define __GroupCount                                               0x99841A
#define __Guilds                                                   0x999F98
#define __gWorld                                                   0x999ED4
#define __HotkeyPage                                               0xA159F0
#define __HWnd                                                     0xA2E2AC
#define __InChatMode                                               0x9B7CA0
#define __LastTell                                                 0x9B995C
#define __LMouseHeldTime                                           0x9B7D88
#define __Mouse                                                    0xA2E578
#define __MouseLook                                                0x9B7D36
#define __NetStatusToggle                                          0x9B7D38
#define __PCNames                                                  0x9B93A8
#define __RangeAttackReady                                         0x9B9050
#define __RMouseHeldTime                                           0x9B7D84
#define __RunWalkState                                             0x9B7CA4
#define __ScreenMode                                               0x8E7CF0
#define __ScreenX                                                  0x9B7C58
#define __ScreenY                                                  0x9B7C5C
#define __ScreenXMax                                               0x9B7C60
#define __ScreenYMax                                               0x9B7C64
#define __ServerHost                                               0x99835C
#define __ServerName                                               0x9EE5C4
#define __ShiftKeyDown                                             0x9B8308
#define __ShowNames                                                0x9B927C
#define __Socials                                                  0x9EE6C4


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x9B1BE8
#define instEQZoneInfo                                             0x9B7ED4
#define instKeypressHandler                                        0xA18BDC
#define pinstActiveBanker                                          0x999F6C
#define pinstActiveCorpse                                          0x999F70
#define pinstActiveGMaster                                         0x999F74
#define pinstActiveMerchant                                        0x999F68
#define pinstAltAdvManager                                         0x8E8B50
#define pinstAuraMgr                                               0x7D15B4
#define pinstBandageTarget                                         0x999F54
#define pinstCamActor                                              0x8E863C
#define pinstCDBStr                                                0x8E7CE0
#define pinstCDisplay                                              0x999F7C
#define pinstCEverQuest                                            0xA2E6F0
#define pinstCharData                                              0x999F38
#define pinstCharSpawn                                             0x999F60
#define pinstControlledMissile                                     0x999F34
#define pinstControlledPlayer                                      0x999F60
#define pinstCSidlManager                                          0xA68318
#define pinstCXWndManager                                          0xA68310
#define instDynamicZone                                            0x9B76A8
#define pinstDZMember                                              0x9B77B8
#define pinstDZTimerInfo                                           0x9B77BC
#define pinstEQItemList                                            0x999F1C
#define instEQMisc                                                 0x8E7C98
#define pinstEQSoundManager                                        0x8E8B74
#define instExpeditionLeader                                       0x9B76F2
#define instExpeditionName                                         0x9B7732
#define pinstGroup                                                 0x998416
#define pinstImeManager                                            0xA6831C
#define pinstLocalPlayer                                           0x999F4C
#define pinstModelPlayer                                           0x999F78
#define pinstPCData                                                0x999F38
#define pinstSkillMgr                                              0xA2B3E4
#define pinstSpawnManager                                          0xA2B364
#define pinstSpellManager                                          0xA2B3E8
#define pinstSpellSets                                             0xA159F4
#define pinstStringTable                                           0x999EF0
#define pinstSwitchManager                                         0x99805C
#define pinstTarget                                                0x999F64
#define pinstTargetObject                                          0x999F3C
#define pinstTargetSwitch                                          0x999F40
#define pinstTaskMember                                            0x8E7C78
#define pinstTrackTarget                                           0x999F58
#define pinstTradeTarget                                           0x999F48
#define instTributeActive                                          0x8E7CBD
#define pinstViewActor                                             0x8E8638
#define pinstWorldData                                             0x999F18


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x7CEE60
#define pinstCAudioTriggersWindow                                  0x7CEE2C
#define pinstCCharacterSelect                                      0x8E854C
#define pinstCFacePick                                             0x8E8500
#define pinstCNoteWnd                                              0x8E8504
#define pinstCBookWnd                                              0x8E8508
#define pinstCPetInfoWnd                                           0x8E850C
#define pinstCTrainWnd                                             0x8E8510
#define pinstCSkillsWnd                                            0x8E8514
#define pinstCSkillsSelectWnd                                      0x8E8518
#define pinstCCombatSkillSelectWnd                                 0x8E851C
#define pinstCFriendsWnd                                           0x8E8520
#define pinstCAuraWnd                                              0x8E8524
#define pinstCRespawnWnd                                           0x8E8528
#define pinstCBandolierWnd                                         0x8E852C
#define pinstCPotionBeltWnd                                        0x8E8530
#define pinstCAAWnd                                                0x8E8534
#define pinstCGroupSearchFiltersWnd                                0x8E8538
#define pinstCLoadskinWnd                                          0x8E853C
#define pinstCAlarmWnd                                             0x8E8540
#define pinstCMusicPlayerWnd                                       0x8E8544
#define pinstCMailWnd                                              0x8E8550
#define pinstCMailCompositionWnd                                   0x8E8554
#define pinstCMailAddressBookWnd                                   0x8E8558
#define pinstCRaidWnd                                              0x8E8560
#define pinstCRaidOptionsWnd                                       0x8E8564
#define pinstCBreathWnd                                            0x8E8568
#define pinstCMapViewWnd                                           0x8E856C
#define pinstCMapToolbarWnd                                        0x8E8570
#define pinstCEditLabelWnd                                         0x8E8574
#define pinstCTargetWnd                                            0x8E8578
#define pinstCColorPickerWnd                                       0x8E857C
#define pinstCPlayerWnd                                            0x8E8580
#define pinstCOptionsWnd                                           0x8E8584
#define pinstCBuffWindowNORMAL                                     0x8E8588
#define pinstCBuffWindowSHORT                                      0x8E858C
#define pinstCharacterCreation                                     0x8E8590
#define pinstCCursorAttachment                                     0x8E8594
#define pinstCCastingWnd                                           0x8E8598
#define pinstCCastSpellWnd                                         0x8E859C
#define pinstCSpellBookWnd                                         0x8E85A0
#define pinstCInventoryWnd                                         0x8E85A4
#define pinstCBankWnd                                              0x8E85A8
#define pinstCQuantityWnd                                          0x8E85AC
#define pinstCLootWnd                                              0x8E85B0
#define pinstCActionsWnd                                           0x8E85B4
#define pinstCCombatAbilityWnd                                     0x8E85B8
#define pinstCMerchantWnd                                          0x8E85BC
#define pinstCTradeWnd                                             0x8E85C0
#define pinstCSelectorWnd                                          0x8E85C4
#define pinstCBazaarWnd                                            0x8E85C8
#define pinstCBazaarSearchWnd                                      0x8E85CC
#define pinstCGiveWnd                                              0x8E85D0
#define pinstCTrackingWnd                                          0x8E85D4
#define pinstCInspectWnd                                           0x8E85D8
#define pinstCSocialEditWnd                                        0x8E85DC
#define pinstCFeedbackWnd                                          0x8E85E0
#define pinstCBugReportWnd                                         0x8E85E4
#define pinstCVideoModesWnd                                        0x8E85E8
#define pinstCTextEntryWnd                                         0x8E85F0
#define pinstCFileSelectionWnd                                     0x8E85F4
#define pinstCCompassWnd                                           0x8E85F8
#define pinstCPlayerNotesWnd                                       0x8E85FC
#define pinstCGemsGameWnd                                          0x8E8600
#define pinstCTimeLeftWnd                                          0x8E8604
#define pinstCPetitionQWnd                                         0x8E8608
#define pinstCSoulmarkWnd                                          0x8E860C
#define pinstCStoryWnd                                             0x8E8610
#define pinstCJournalTextWnd                                       0x8E8614
#define pinstCJournalCatWnd                                        0x8E8618
#define pinstCBodyTintWnd                                          0x8E861C
#define pinstCServerListWnd                                        0x8E8620
#define pinstCAvaZoneWnd                                           0x8E8624
#define pinstCBlockedBuffWnd                                       0x8E8628
#define pinstCBlockedPetBuffWnd                                    0x8E862C
#define pinstCInvSlotMgr                                           0x8E8630
#define pinstCContainerMgr                                         0x8E8634
#define pinstCAdventureLeaderboardWnd                              0xA56CD8
#define pinstCAdventureRequestWnd                                  0xA56CF4
#define pinstCAltStorageWnd                                        0xA56D54
#define pinstCAdventureStatsWnd                                    0xA56D10
#define pinstCBarterMerchantWnd                                    0xA56F20
#define pinstCBarterSearchWnd                                      0xA56F3C
#define pinstCBarterWnd                                            0xA56F58
#define pinstCChatManager                                          0xA571FC
#define pinstCDynamicZoneWnd                                       0xA572F4
#define pinstCEQMainWnd                                            0xA57368
#define pinstCFellowshipWnd                                        0xA573CC
#define pinstCFindLocationWnd                                      0xA57400
#define pinstCGroupSearchWnd                                       0xA574B0
#define pinstCGroupWnd                                             0xA574CC
#define pinstCGuildBankWnd                                         0xA574E8
#define pinstCGuildMgmtWnd                                         0xA59508
#define pinstCGuildTributeMasterWnd                                0xA59528
#define pinstCHotButtonWnd                                         0xA59544
#define pinstCHotButtonWnd1                                        0xA59544
#define pinstCHotButtonWnd2                                        0xA59548
#define pinstCHotButtonWnd3                                        0xA5954C
#define pinstCHotButtonWnd4                                        0xA59550
#define pinstCItemDisplayManager                                   0xA595FC
#define pinstCItemExpTransferWnd                                   0xA5961C
#define pinstCLeadershipWnd                                        0xA596B8
#define pinstCLFGuildWnd                                           0xA596D4
#define pinstCMIZoneSelectWnd                                      0xA59828
#define pinstCAdventureMerchantWnd                                 0xA59920
#define pinstCConfirmationDialog                                   0xA5993C
#define pinstCPopupWndManager                                      0xA5993C
#define pinstCProgressionSelectionWnd                              0xA59970
#define pinstCPvPLeaderboardWnd                                    0xA5998C
#define pinstCPvPStatsWnd                                          0xA599A8
#define pinstCSystemInfoDialogBox                                  0xA59A58
#define pinstCTargetOfTargetWnd                                    0xA5A364
#define pinstCTaskSelectWnd                                        0xA5A398
#define pinstCTaskTemplateSelectWnd                                0xA5A3B4
#define pinstCTaskWnd                                              0xA5A3D0
#define pinstCTipWndOFDAY                                          0xA5A44C
#define pinstCTipWndCONTEXT                                        0xA5A450
#define pinstCTitleWnd                                             0xA5A46C
#define pinstCTradeskillWnd                                        0xA5A4B0
#define pinstCTributeBenefitWnd                                    0xA5A4FC
#define pinstCTributeMasterWnd                                     0xA5A518
#define pinstCContextMenuManager                                   0xA68374
#define pinstCVoiceMacroWnd                                        0xA2B5CC
#define pinstCHtmlWnd                                              0xA2B5E8


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4BA310
#define __ConvertItemTags                                          0x4ACB80
#define __ExecuteCmd                                               0x49BAC0
#define __get_melee_range                                          0x4A0F10
#define __GetGaugeValueFromEQ                                      0x62B680
#define __GetLabelFromEQ                                           0x62C120
#define __NewUIINI                                                 0x62B260
#define __ProcessGameEvents                                        0x4E9D00
#define CrashDetected                                              0x5538D0
#define DrawNetStatus                                              0x5082B0
#define Util__FastTime                                             0x6A0470


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x474D00
#define AltAdvManager__IsAbilityReady                              0x474D40
#define AltAdvManager__GetAltAbility                               0x474F90

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x56B870

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x574A30

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6CC7B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x58AC60
#define CChatManager__InitContextMenu                              0x58B400

// CChatService
#define CChatService__GetNumberOfFriends                           0x690570
#define CChatService__GetFriendName                                0x690580

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x58F600
#define CChatWindow__WndNotification                               0x590050

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6B21E0
#define CComboWnd__Draw                                            0x6B2390
#define CComboWnd__GetCurChoice                                    0x6B2180
#define CComboWnd__GetListRect                                     0x6B2660
#define CComboWnd__GetTextRect                                     0x6B2210
#define CComboWnd__InsertChoice                                    0x6B26D0
#define CComboWnd__SetColors                                       0x6B2110
#define CComboWnd__SetChoice                                       0x6B2140

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x596D40
#define CContainerWnd__vftable                                     0x7666A8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x463A20
#define CDisplay__GetClickedActor                                  0x461180
#define CDisplay__GetUserDefinedColor                              0x4602A0
#define CDisplay__GetWorldFilePath                                 0x45F7F0
#define CDisplay__is3dON                                           0x45E950
#define CDisplay__ReloadUI                                         0x471F20
#define CDisplay__WriteTextHD2                                     0x464190

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x565740
#define CEditBaseWnd__SetSel                                       0x6D7800

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6BFF90
#define CEditWnd__GetCharIndexPt                                   0x6C0DE0
#define CEditWnd__GetDisplayString                                 0x6C0120
#define CEditWnd__GetHorzOffset                                    0x6C03B0
#define CEditWnd__GetLineForPrintableChar                          0x6C0890
#define CEditWnd__GetSelStartPt                                    0x6C1030
#define CEditWnd__GetSTMLSafeText                                  0x6C0550
#define CEditWnd__PointFromPrintableChar                           0x6C09A0
#define CEditWnd__SelectableCharFromPoint                          0x6C0B20
#define CEditWnd__SetEditable                                      0x6C0520

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4CD6F0
#define CEverQuest__DropHeldItemOnGround                           0x4D1B70
#define CEverQuest__dsp_chat                                       0x4D3090
#define CEverQuest__DoTellWindow                                   0x4D1CF0
#define CEverQuest__EnterZone                                      0x4E8710
#define CEverQuest__GetBodyTypeDesc                                0x4CAAF0
#define CEverQuest__GetClassDesc                                   0x4CA250
#define CEverQuest__GetClassThreeLetterCode                        0x4CA850
#define CEverQuest__GetDeityDesc                                   0x4CB160
#define CEverQuest__GetLangDesc                                    0x4CAE80
#define CEverQuest__GetRaceDesc                                    0x4CB130
#define CEverQuest__InterpretCmd                                   0x4D3B00
#define CEverQuest__LeftClickedOnPlayer                            0x4E6EB0
#define CEverQuest__LMouseUp                                       0x4E94E0
#define CEverQuest__RightClickedOnPlayer                           0x4E7280
#define CEverQuest__RMouseUp                                       0x4E8D10
#define CEverQuest__SetGameState                                   0x4CDB70
#define CEverQuest__Emote                                          0x4D3290

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5A3900
#define CGaugeWnd__CalcLinesFillRect                               0x5A3960
#define CGaugeWnd__Draw                                            0x5A3D70

// CGuild
#define CGuild__FindMemberByName                                   0x4181C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5BB960

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5C4EB0
#define CInvSlotMgr__MoveItem                                      0x5C5050

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5C3870
#define CInvSlot__SliderComplete                                   0x5C3D80

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5D3CD0
#define CItemDisplayWnd__SetSpell                                  0x629070

// CLabel 
#define CLabel__Draw                                               0x5D95B0

// CListWnd 
#define CListWnd__AddColumn                                        0x6B1F20
#define CListWnd__AddColumn1                                       0x6B19F0
#define CListWnd__AddLine                                          0x6B1520
#define CListWnd__AddString                                        0x6B1720
#define CListWnd__CalculateFirstVisibleLine                        0x6AE900
#define CListWnd__CalculateVSBRange                                0x6B0560
#define CListWnd__ClearAllSel                                      0x6AE030
#define CListWnd__CloseAndUpdateEditWindow                         0x6AEF30
#define CListWnd__Compare                                          0x6AF2D0
#define CListWnd__Draw                                             0x6B0250
#define CListWnd__DrawColumnSeparators                             0x6B00C0
#define CListWnd__DrawHeader                                       0x6AE200
#define CListWnd__DrawItem                                         0x6AF9E0
#define CListWnd__DrawLine                                         0x6AFD60
#define CListWnd__DrawSeparator                                    0x6B0160
#define CListWnd__EnsureVisible                                    0x6AE950
#define CListWnd__ExtendSel                                        0x6AF900
#define CListWnd__GetColumnMinWidth                                0x6ADE40
#define CListWnd__GetColumnWidth                                   0x6ADD80
#define CListWnd__GetCurSel                                        0x6AD860
#define CListWnd__GetHeaderRect                                    0x6AD950
#define CListWnd__GetItemAtPoint                                   0x6AEC50
#define CListWnd__GetItemAtPoint1                                  0x6AECC0
#define CListWnd__GetItemData                                      0x6ADB30
#define CListWnd__GetItemHeight                                    0x6AE690
#define CListWnd__GetItemIcon                                      0x6ADCC0
#define CListWnd__GetItemRect                                      0x6AEA30
#define CListWnd__GetItemText                                      0x6ADB70
#define CListWnd__GetSelList                                       0x6B18D0
#define CListWnd__GetSeparatorRect                                 0x6AF210
#define CListWnd__RemoveLine                                       0x6B1ED0
#define CListWnd__SetColors                                        0x6AD8C0
#define CListWnd__SetColumnJustification                           0x6ADEA0
#define CListWnd__SetColumnWidth                                   0x6ADE00
#define CListWnd__SetCurSel                                        0x6AD8A0
#define CListWnd__SetItemColor                                     0x6B1190
#define CListWnd__SetItemData                                      0x6AE0D0
#define CListWnd__SetItemText                                      0x6B1110
#define CListWnd__ShiftColumnSeparator                             0x6AF870
#define CListWnd__Sort                                             0x6B1F50
#define CListWnd__ToggleSel                                        0x6ADFA0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5EE6B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5F4830
#define CMerchantWnd__RequestBuyItem                               0x5F5BC0
#define CMerchantWnd__RequestSellItem                              0x5F4A90
#define CMerchantWnd__SelectBuySellSlot                            0x5F58F0

// CObfuscator
#define CObfuscator__doit                                          0x66C220

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6C8160
#define CSidlManager__CreateLabel                                  0x622090

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x567880
#define CSidlScreenWnd__CalculateVSBRange                          0x6CDD50
#define CSidlScreenWnd__ConvertToRes                               0x6D76E0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6B9510
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6BA5B0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6BA660
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6B9DA0
#define CSidlScreenWnd__DrawSidlPiece                              0x6B91F0
#define CSidlScreenWnd__EnableIniStorage                           0x6B8E40
#define CSidlScreenWnd__GetSidlPiece                               0x6B93F0
#define CSidlScreenWnd__Init1                                      0x6BA410
#define CSidlScreenWnd__LoadIniInfo                                0x6B95C0
#define CSidlScreenWnd__LoadIniListWnd                             0x6B8F90
#define CSidlScreenWnd__LoadSidlScreen                             0x6B9FE0
#define CSidlScreenWnd__StoreIniInfo                               0x6B8A50
#define CSidlScreenWnd__WndNotification                            0x6BA190
#define CSidlScreenWnd__GetChildItem                               0x6B8EA0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x52A6F0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6D8BE0
#define CSliderWnd__SetValue                                       0x6D8CE0
#define CSliderWnd__SetNumTicks                                    0x6D9260

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6277E0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6D59A0
#define CStmlWnd__CalculateVSBRange                                0x6CDD50
#define CStmlWnd__CanBreakAtCharacter                              0x6CDE90
#define CStmlWnd__FastForwardToEndOfTag                            0x6CE990
#define CStmlWnd__ForceParseNow                                    0x6D5DF0
#define CStmlWnd__GetNextTagPiece                                  0x6CE8B0
#define CStmlWnd__GetSTMLText                                      0x58F5A0
#define CStmlWnd__GetThisChar                                      0x6F9AE0
#define CStmlWnd__GetVisiableText                                  0x6CFBA0
#define CStmlWnd__InitializeWindowVariables                        0x6D1CE0
#define CStmlWnd__MakeStmlColorTag                                 0x6CD430
#define CStmlWnd__MakeWndNotificationTag                           0x6CD4D0
#define CStmlWnd__SetSTMLText                                      0x6D1E00
#define CStmlWnd__StripFirstSTMLLines                              0x6D5720
#define CStmlWnd__UpdateHistoryString                              0x6D0400

// CTabWnd 
#define CTabWnd__Draw                                              0x6DA070
#define CTabWnd__DrawCurrentPage                                   0x6D9A00
#define CTabWnd__DrawTab                                           0x6D97E0
#define CTabWnd__GetCurrentPage                                    0x6D9D00
#define CTabWnd__GetPageClientRect                                 0x6D94B0
#define CTabWnd__GetPageFromTabIndex                               0x6D9710
#define CTabWnd__GetPageInnerRect                                  0x6D9510
#define CTabWnd__GetTabInnerRect                                   0x6D9690
#define CTabWnd__GetTabRect                                        0x6D95A0
#define CTabWnd__IndexInBounds                                     0x6D97AD
#define CTabWnd__InsertPage                                        0x6DA2E0
#define CTabWnd__SetPage                                           0x6D9D40
#define CTabWnd__SetPageRect                                       0x6D9FA0
#define CTabWnd__UpdatePage                                        0x6DA260

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4146B0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6BA9C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6E17E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6AD5D0

// CXRect 
#define CXRect__CenterPoint                                        0x56AF00

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4F9830
#define CXStr__CXStr1                                              0x6A7240
#define CXStr__CXStr3                                              0x6A1B70
#define CXStr__dCXStr                                              0x403580
#define CXStr__operator_equal1                                     0x6A1D30
#define CXStr__operator_plus_equal1                                0x6A2C30

// CXWnd 
#define CXWnd__BringToTop                                          0x6B2F70
#define CXWnd__Center                                              0x6B6890
#define CXWnd__ClrFocus                                            0x6B2C50
#define CXWnd__DoAllDrawing                                        0x6B7600
#define CXWnd__DrawChildren                                        0x6B7730
#define CXWnd__DrawColoredRect                                     0x6B31E0
#define CXWnd__DrawTooltip                                         0x6B7430
#define CXWnd__DrawTooltipAtPoint                                  0x6B6640
#define CXWnd__GetBorderFrame                                      0x6B3660
#define CXWnd__GetChildWndAt                                       0x6B6170
#define CXWnd__GetClientClipRect                                   0x6B35A0
#define CXWnd__GetScreenClipRect                                   0x6B6AB0
#define CXWnd__GetScreenRect                                       0x6B3870
#define CXWnd__GetTooltipRect                                      0x6B3400
#define CXWnd__GetWindowTextA                                      0x55E4B0
#define CXWnd__IsActive                                            0x6BBAF0
#define CXWnd__IsDescendantOf                                      0x6B3610
#define CXWnd__IsReallyVisible                                     0x6B6150
#define CXWnd__IsType                                              0x6DB490
#define CXWnd__Move                                                0x6B5D70
#define CXWnd__Move1                                               0x6B7290
#define CXWnd__ProcessTransition                                   0x6B2F30
#define CXWnd__Refade                                              0x6B2D00
#define CXWnd__Resize                                              0x6B3930
#define CXWnd__Right                                               0x6B69F0
#define CXWnd__SetFocus                                            0x6B4F50
#define CXWnd__SetKeyTooltip                                       0x6B3B40
#define CXWnd__SetMouseOver                                        0x6B3B10
#define CXWnd__StartFade                                           0x6B2FB0
#define CXWnd__GetChildItem                                        0x6B6C40

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6BCF00
#define CXWndManager__DrawWindows                                  0x6BCB10
#define CXWndManager__GetKeyboardFlags                             0x6BB780
#define CXWndManager__HandleKeyboardMsg                            0x6BBCF0
#define CXWndManager__RemoveWnd                                    0x6BBC10

// CDBStr
#define CDBStr__GetString                                          0x45D290

// EQ_Character 
#define EQ_Character__CastRay                                      0x705AD0
#define EQ_Character__CastSpell                                    0x425A40
#define EQ_Character__Cur_HP                                       0x432830
#define EQ_Character__GetAACastingTimeModifier                     0x420140
#define EQ_Character__GetCharInfo2                                 0x681FB0
#define EQ_Character__GetFocusCastingTimeModifier                  0x41BD20
#define EQ_Character__GetFocusRangeModifier                        0x41BE60
#define EQ_Character__Max_Endurance                                0x50C810
#define EQ_Character__Max_HP                                       0x42D8F0
#define EQ_Character__Max_Mana                                     0x50E210
#define EQ_Character__doCombatAbility                              0x50D140
#define EQ_Character__UseSkill                                     0x438630
#define EQ_Character__GetConLevel                                  0x5096B0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F7500
#define EQ_Item__GetItemLinkHash                                   0x675D30
#define EQ_Item__IsStackable                                       0x66CB00

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x475E60
#define EQ_LoadingS__Array                                         0x7BA8A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x511130
#define EQ_PC__GetAltAbilityIndex                                  0x67A520
#define EQ_PC__GetCombatAbility                                    0x67A5B0
#define EQ_PC__GetCombatAbilityTimer                               0x67A660
#define EQ_PC__GetItemTimerValue                                   0x50C010
#define EQ_PC__HasLoreItem                                         0x50F600

// EQItemList 
#define EQItemList__dEQItemList                                    0x49F5F0
#define EQItemList__EQItemList                                     0x49F540

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45CC40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x515930
#define EQPlayer__dEQPlayer                                        0x5199D0
#define EQPlayer__DoAttack                                         0x5268F0
#define EQPlayer__EQPlayer                                         0x51D640
#define EQPlayer__SetNameSpriteState                               0x5178D0
#define EQPlayer__SetNameSpriteTint                                0x5159A0
#define EQPlayer__IsBodyType_j                                     0x7054A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x51E700
#define EQPlayerManager__GetSpawnByName                            0x51E8E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F91A0
#define KeypressHandler__AttachKeyToEqCommand                      0x4F91E0
#define KeypressHandler__ClearCommandStateArray                    0x4F8FB0
#define KeypressHandler__HandleKeyDown                             0x4F7B60
#define KeypressHandler__HandleKeyUp                               0x4F7E70
#define KeypressHandler__SaveKeymapping                            0x4F9080

// MapViewMap 
#define MapViewMap__Clear                                          0x5E9D80
#define MapViewMap__SaveEx                                         0x5EA750

#define OtherCharData__GetAltCurrency                              0x698C40

// StringTable 
#define StringTable__getString                                     0x66C4A0
