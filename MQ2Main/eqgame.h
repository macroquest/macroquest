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
#define __ExpectedVersionDate                                     "Jul 19 2007"
#define __ExpectedVersionTime                                     "14:38:30"
#define __ActualVersionDate                                        0x6EDF24
#define __ActualVersionTime                                        0x6EDF30

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4EE7C0
#define __MemChecker1                                              0x63E220
#define __MemChecker2                                              0x51F470
#define __MemChecker3                                              0x51F520
#define __MemChecker4                                              0x6075E0
#define __EncryptPad0                                              0x747A20
#define __EncryptPad1                                              0x751258
#define __EncryptPad2                                              0x749F80
#define __EncryptPad3                                              0x74A380
#define __EncryptPad4                                              0x750970

// Direct Input
#define DI8__Main                                                  0x97F204
#define DI8__Keyboard                                              0x97F208
#define DI8__Mouse                                                 0x97F20C
#define __AltTimerReady                                            0x91B342
#define __Attack                                                   0x9789BA
#define __Autofire                                                 0x9789BB
#define __BindList                                                 0x742C50
#define __Clicks                                                   0x91A46C
#define __CommandList                                              0x743450
#define __CurrentMapLabel                                          0x98A2D4
#define __CurrentSocial                                            0x73F4DC
#define __DoAbilityAvailable                                       0x91B2DC
#define __DoAbilityList                                            0x950500
#define __DrawHandler                                              0x99912C
#define __GroupCount                                               0x8FAB90
#define __GroupLeader                                              0x8FACEC
#define __Guilds                                                   0x8FC6B0
#define __gWorld                                                   0x8FC5F0
#define __HotkeyPage                                               0x9778EC
#define __HWnd                                                     0x97F1AC
#define __InChatMode                                               0x91A3A8
#define __LastTell                                                 0x91BC08
#define __LMouseHeldTime                                           0x91A48C
#define __Mouse                                                    0x97F210
#define __MouseLook                                                0x91A43A
#define __NetStatusToggle                                          0x91A43C
#define __PCNames                                                  0x91B660
#define __RangeAttackReady                                         0x91B340
#define __RMouseHeldTime                                           0x91A488
#define __RunWalkState                                             0x91A3AC
#define __ScreenMode                                               0x84A660
#define __ScreenX                                                  0x91A370
#define __ScreenY                                                  0x91A374
#define __ScreenXMax                                               0x91A378
#define __ScreenYMax                                               0x91A37C
#define __ServerHost                                               0x8FAAE4
#define __ServerName                                               0x9504C0
#define __ShowNames                                                0x91B534
#define __Socials                                                  0x9505C0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x914300
#define instEQZoneInfo                                             0x91A5D8
#define instKeypressHandler                                        0x978ABC
#define pinstActiveBanker                                          0x8FC688
#define pinstActiveCorpse                                          0x8FC68C
#define pinstActiveGMaster                                         0x8FC690
#define pinstActiveMerchant                                        0x8FC684
#define pinstAltAdvManager                                         0x84B348
#define pinstAuraMgr                                               0x75638C
#define pinstBandageTarget                                         0x8FC670
#define pinstCamActor                                              0x84AE3C
#define pinstCDBStr                                                0x84A4E0
#define pinstCDisplay                                              0x8FC698
#define pinstCEverQuest                                            0x97F384
#define pinstCharData                                              0x8FC654
#define pinstCharSpawn                                             0x8FC67C
#define pinstControlledMissile                                     0x8FC650
#define pinstControlledPlayer                                      0x8FC67C
#define pinstCSidlManager                                          0x998928
#define pinstCXWndManager                                          0x998920
#define instDynamicZone                                            0x919DC0
#define pinstDZMember                                              0x919ED0
#define pinstDZTimerInfo                                           0x919ED4
#define pinstEQItemList                                            0x8FC638
#define instEQMisc                                                 0x84A498
#define pinstEQSoundManager                                        0x84B36C
#define instExpeditionLeader                                       0x919E0A
#define instExpeditionName                                         0x919E4A
#define instGroup                                                  0x8FAB90
#define pinstGroup                                                 0x8FAB8C
#define pinstImeManager                                            0x99892C
#define pinstLocalPlayer                                           0x8FC668
#define pinstModelPlayer                                           0x8FC694
#define pinstPCData                                                0x8FC654
#define pinstSelectedItem                                          0x98A12C
#define pinstSkillMgr                                              0x97C1B8
#define pinstSpawnManager                                          0x97C134
#define pinstSpellManager                                          0x97C1BC
#define pinstSpellSets                                             0x9778F0
#define pinstStringTable                                           0x8FC60C
#define pinstSwitchManager                                         0x8FA7E0
#define pinstTarget                                                0x8FC680
#define pinstTargetObject                                          0x8FC658
#define pinstTargetSwitch                                          0x8FC65C
#define pinstTaskMember                                            0x84A478
#define pinstTrackTarget                                           0x8FC674
#define pinstTradeTarget                                           0x8FC664
#define instTributeActive                                          0x84A4BD
#define pinstViewActor                                             0x84AE38
#define pinstWorldData                                             0x8FC634


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x7548C0
#define pinstCAudioTriggersWindow                                  0x75488C
#define pinstCCharacterSelect                                      0x84AD48
#define pinstCFacePick                                             0x84AD00
#define pinstCNoteWnd                                              0x84AD04
#define pinstCBookWnd                                              0x84AD08
#define pinstCPetInfoWnd                                           0x84AD0C
#define pinstCTrainWnd                                             0x84AD10
#define pinstCSkillsWnd                                            0x84AD14
#define pinstCSkillsSelectWnd                                      0x84AD18
#define pinstCCombatSkillSelectWnd                                 0x84AD1C
#define pinstCFriendsWnd                                           0x84AD20
#define pinstCAuraWnd                                              0x84AD24
#define pinstCRespawnWnd                                           0x84AD28
#define pinstCBandolierWnd                                         0x84AD2C
#define pinstCPotionBeltWnd                                        0x84AD30
#define pinstCAAWnd                                                0x84AD34
#define pinstCGroupSearchFiltersWnd                                0x84AD38
#define pinstCLoadskinWnd                                          0x84AD3C
#define pinstCAlarmWnd                                             0x84AD40
#define pinstCMusicPlayerWnd                                       0x84AD44
#define pinstCMailWnd                                              0x84AD4C
#define pinstCMailCompositionWnd                                   0x84AD50
#define pinstCMailAddressBookWnd                                   0x84AD54
#define pinstCRaidWnd                                              0x84AD5C
#define pinstCRaidOptionsWnd                                       0x84AD60
#define pinstCBreathWnd                                            0x84AD64
#define pinstCMapViewWnd                                           0x84AD68
#define pinstCMapToolbarWnd                                        0x84AD6C
#define pinstCEditLabelWnd                                         0x84AD70
#define pinstCTargetWnd                                            0x84AD74
#define pinstCColorPickerWnd                                       0x84AD78
#define pinstCPlayerWnd                                            0x84AD7C
#define pinstCOptionsWnd                                           0x84AD80
#define pinstCBuffWindowNORMAL                                     0x84AD84
#define pinstCBuffWindowSHORT                                      0x84AD88
#define pinstCharacterCreation                                     0x84AD8C
#define pinstCCursorAttachment                                     0x84AD90
#define pinstCCastingWnd                                           0x84AD94
#define pinstCCastSpellWnd                                         0x84AD98
#define pinstCSpellBookWnd                                         0x84AD9C
#define pinstCInventoryWnd                                         0x84ADA0
#define pinstCBankWnd                                              0x84ADA4
#define pinstCQuantityWnd                                          0x84ADA8
#define pinstCLootWnd                                              0x84ADAC
#define pinstCActionsWnd                                           0x84ADB0
#define pinstCCombatAbilityWnd                                     0x84ADB4
#define pinstCMerchantWnd                                          0x84ADB8
#define pinstCTradeWnd                                             0x84ADBC
#define pinstCSelectorWnd                                          0x84ADC0
#define pinstCBazaarWnd                                            0x84ADC4
#define pinstCBazaarSearchWnd                                      0x84ADC8
#define pinstCGiveWnd                                              0x84ADCC
#define pinstCTrackingWnd                                          0x84ADD0
#define pinstCInspectWnd                                           0x84ADD4
#define pinstCSocialEditWnd                                        0x84ADD8
#define pinstCFeedbackWnd                                          0x84ADDC
#define pinstCBugReportWnd                                         0x84ADE0
#define pinstCVideoModesWnd                                        0x84ADE4
#define pinstCTextEntryWnd                                         0x84ADEC
#define pinstCFileSelectionWnd                                     0x84ADF0
#define pinstCCompassWnd                                           0x84ADF4
#define pinstCPlayerNotesWnd                                       0x84ADF8
#define pinstCGemsGameWnd                                          0x84ADFC
#define pinstCTimeLeftWnd                                          0x84AE00
#define pinstCPetitionQWnd                                         0x84AE04
#define pinstCSoulmarkWnd                                          0x84AE08
#define pinstCStoryWnd                                             0x84AE0C
#define pinstCJournalTextWnd                                       0x84AE10
#define pinstCJournalCatWnd                                        0x84AE14
#define pinstCBodyTintWnd                                          0x84AE18
#define pinstCServerListWnd                                        0x84AE1C
#define pinstCAvaZoneWnd                                           0x84AE20
#define pinstCBlockedBuffWnd                                       0x84AE24
#define pinstCBlockedPetBuffWnd                                    0x84AE28
#define pinstCInvSlotMgr                                           0x84AE2C
#define pinstCContainerMgr                                         0x84AE30
#define pinstCAdventureLeaderboardWnd                              0x987964
#define pinstCAdventureRequestWnd                                  0x987980
#define pinstCAltStorageWnd                                        0x9879E0
#define pinstCAdventureStatsWnd                                    0x98799C
#define pinstCBarterMerchantWnd                                    0x987B94
#define pinstCBarterSearchWnd                                      0x987BB0
#define pinstCBarterWnd                                            0x987BCC
#define pinstCChatManager                                          0x987D94
#define pinstCDynamicZoneWnd                                       0x987E70
#define pinstCEQMainWnd                                            0x987EE0
#define pinstCFellowshipWnd                                        0x987F44
#define pinstCFindLocationWnd                                      0x987F78
#define pinstCGroupSearchWnd                                       0x988028
#define pinstCGroupWnd                                             0x988044
#define pinstCGuildBankWnd                                         0x988060
#define pinstCGuildMgmtWnd                                         0x98A080
#define pinstCGuildTributeMasterWnd                                0x98A0A0
#define pinstCHotButtonWnd                                         0x98A0BC
#define pinstCHotButtonWnd1                                        0x98A0BC
#define pinstCHotButtonWnd2                                        0x98A0C0
#define pinstCHotButtonWnd3                                        0x98A0C4
#define pinstCHotButtonWnd4                                        0x98A0C8
#define pinstCItemDisplayManager                                   0x98A160
#define pinstCItemExpTransferWnd                                   0x98A180
#define pinstCLeadershipWnd                                        0x98A1FC
#define pinstCLFGuildWnd                                           0x98A218
#define pinstCMIZoneSelectWnd                                      0x98A33C
#define pinstCAdventureMerchantWnd                                 0x98A434
#define pinstCConfirmationDialog                                   0x98A450
#define pinstCPopupWndManager                                      0x98A450
#define pinstCProgressionSelectionWnd                              0x98A484
#define pinstCPvPLeaderboardWnd                                    0x98A4A0
#define pinstCPvPStatsWnd                                          0x98A4BC
#define pinstCSystemInfoDialogBox                                  0x98AE24
#define pinstCTargetOfTargetWnd                                    0x98AE40
#define pinstCTaskSelectWnd                                        0x98AE74
#define pinstCTaskTemplateSelectWnd                                0x98AE90
#define pinstCTaskWnd                                              0x98AEAC
#define pinstCTipWndOFDAY                                          0x98AEF8
#define pinstCTipWndCONTEXT                                        0x98AEFC
#define pinstCTitleWnd                                             0x98AF18
#define pinstCTradeskillWnd                                        0x98AF5C
#define pinstCTributeBenefitWnd                                    0x98AFA8
#define pinstCTributeMasterWnd                                     0x98AFC4
#define pinstCContextMenuManager                                   0x998984
#define pinstCVoiceMacroWnd                                        0x97C26C
#define pinstCHtmlWnd                                              0x97C288


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4AFE80
#define __ConvertItemTags                                          0x4A4810
#define __ExecuteCmd                                               0x495E20
#define __get_melee_range                                          0x49AF00
#define __GetGaugeValueFromEQ                                      0x5DDC00
#define __GetLabelFromEQ                                           0x5DE410
#define __NewUIINI                                                 0x5DD7F0
#define __ProcessGameEvents                                        0x4DB5A0
#define __SendMessage                                              0x4BD5E0
#define CrashDetected                                              0x51E570
#define DrawNetStatus                                              0x4F1520
#define Util__FastTime                                             0x63E8B0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x4709D0
#define AltAdvManager__IsAbilityReady                              0x470A10
#define AltAdvManager__GetAltAbility                               0x470BA0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x534A10

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x53DF60

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6690D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x550DD0
#define CChatManager__InitContextMenu                              0x551560

// CChatService
#define CChatService__GetNumberOfFriends                           0x62EEE0
#define CChatService__GetFriendName                                0x62EEF0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5556E0
#define CChatWindow__WndNotification                               0x5560E0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6500A0
#define CComboWnd__Draw                                            0x650250
#define CComboWnd__GetCurChoice                                    0x650040
#define CComboWnd__GetListRect                                     0x650530
#define CComboWnd__GetTextRect                                     0x6500D0
#define CComboWnd__InsertChoice                                    0x6505A0
#define CComboWnd__SetColors                                       0x64FFD0
#define CComboWnd__SetChoice                                       0x650000

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x55BDC0
#define CContainerWnd__vftable                                     0x6F4258

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45FD10
#define CDisplay__GetClickedActor                                  0x45D5C0
#define CDisplay__GetUserDefinedColor                              0x45CA20
#define CDisplay__GetWorldFilePath                                 0x45BF90
#define CDisplay__is3dON                                           0x45AB40
#define CDisplay__ReloadUI                                         0x46BCD0
#define CDisplay__WriteTextHD2                                     0x4614D0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x52EC90
#define CEditBaseWnd__SetSel                                       0x673F90

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x65D2C0
#define CEditWnd__GetCharIndexPt                                   0x65E120
#define CEditWnd__GetDisplayString                                 0x65D450
#define CEditWnd__GetHorzOffset                                    0x65D6F0
#define CEditWnd__GetLineForPrintableChar                          0x65DBD0
#define CEditWnd__GetSelStartPt                                    0x65E360
#define CEditWnd__GetSTMLSafeText                                  0x65D890
#define CEditWnd__PointFromPrintableChar                           0x65DCE0
#define CEditWnd__SelectableCharFromPoint                          0x65DE60
#define CEditWnd__SetEditable                                      0x65D860

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4C1770
#define CEverQuest__DropHeldItemOnGround                           0x4C6360
#define CEverQuest__dsp_chat                                       0x4C6FF0
#define CEverQuest__DoTellWindow                                   0x4C6490
#define CEverQuest__EnterZone                                      0x4DA090
#define CEverQuest__GetBodyTypeDesc                                0x4BEE10
#define CEverQuest__GetClassDesc                                   0x4BE570
#define CEverQuest__GetClassThreeLetterCode                        0x4BEB70
#define CEverQuest__GetDeityDesc                                   0x4BF480
#define CEverQuest__GetLangDesc                                    0x4BF1A0
#define CEverQuest__GetRaceDesc                                    0x4BF450
#define CEverQuest__InterpretCmd                                   0x4C7970
#define CEverQuest__LeftClickedOnPlayer                            0x4D8C40
#define CEverQuest__LMouseUp                                       0x4DAE00
#define CEverQuest__RightClickedOnPlayer                           0x4D9010
#define CEverQuest__RMouseUp                                       0x4DA6B0
#define CEverQuest__SetGameState                                   0x4C1840

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x566EB0
#define CGaugeWnd__CalcLinesFillRect                               0x566F20
#define CGaugeWnd__Draw                                            0x5672B0

// CGuild
#define CGuild__FindMemberByName                                   0x417390

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x57CDF0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x584A10
#define CInvSlotMgr__MoveItem                                      0x584BB0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x585AB0

// CInvSLot
#define CInvSlot__SliderComplete                                   0x583980

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x593780
#define CItemDisplayWnd__SetSpell                                  0x5DBB20

// CLabel 
#define CLabel__Draw                                               0x598EA0

// CListWnd 
#define CListWnd__AddColumn                                        0x64FDE0
#define CListWnd__AddColumn1                                       0x64F910
#define CListWnd__AddLine                                          0x64F4A0
#define CListWnd__AddString                                        0x64F670
#define CListWnd__CalculateFirstVisibleLine                        0x64C7D0
#define CListWnd__CalculateVSBRange                                0x64E440
#define CListWnd__ClearAllSel                                      0x64BF40
#define CListWnd__CloseAndUpdateEditWindow                         0x64CDE0
#define CListWnd__Compare                                          0x64D190
#define CListWnd__Draw                                             0x64E140
#define CListWnd__DrawColumnSeparators                             0x64DFB0
#define CListWnd__DrawHeader                                       0x64C110
#define CListWnd__DrawItem                                         0x64D8A0
#define CListWnd__DrawLine                                         0x64DC50
#define CListWnd__DrawSeparator                                    0x64E050
#define CListWnd__EnsureVisible                                    0x64C820
#define CListWnd__ExtendSel                                        0x64D7D0
#define CListWnd__GetColumnMinWidth                                0x64BCE0
#define CListWnd__GetColumnWidth                                   0x64BC20
#define CListWnd__GetCurSel                                        0x64B700
#define CListWnd__GetHeaderRect                                    0x64B7F0
#define CListWnd__GetItemAtPoint                                   0x64CAF0
#define CListWnd__GetItemAtPoint1                                  0x64CB60
#define CListWnd__GetItemData                                      0x64B9D0
#define CListWnd__GetItemHeight                                    0x64C570
#define CListWnd__GetItemIcon                                      0x64BB60
#define CListWnd__GetItemRect                                      0x64C8E0
#define CListWnd__GetItemText                                      0x64BA10
#define CListWnd__GetSelList                                       0x64F7F0
#define CListWnd__GetSeparatorRect                                 0x64D0D0
#define CListWnd__RemoveLine                                       0x64F7A0
#define CListWnd__SetColors                                        0x64B760
#define CListWnd__SetColumnJustification                           0x64BD40
#define CListWnd__SetColumnWidth                                   0x64BCA0
#define CListWnd__SetCurSel                                        0x64B740
#define CListWnd__SetItemColor                                     0x64F070
#define CListWnd__SetItemData                                      0x64BFE0
#define CListWnd__SetItemText                                      0x64EFF0
#define CListWnd__ShiftColumnSeparator                             0x64D740
#define CListWnd__Sort                                             0x64FE10
#define CListWnd__ToggleSel                                        0x64BEB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5ABD90

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5AD780
#define CMerchantWnd__RequestBuyItem                               0x5AEA00
#define CMerchantWnd__RequestSellItem                              0x5AD9E0
#define CMerchantWnd__SelectBuySellSlot                            0x5AE740

// CObfuscator
#define CObfuscator__doit                                          0x630550

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x664CF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x530560
#define CSidlScreenWnd__CalculateVSBRange                          0x655730
#define CSidlScreenWnd__ConvertToRes                               0x655E81
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x656680
#define CSidlScreenWnd__CSidlScreenWnd1                            0x657940
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6579F0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6571F0
#define CSidlScreenWnd__DrawSidlPiece                              0x656360
#define CSidlScreenWnd__EnableIniStorage                           0x655E20
#define CSidlScreenWnd__GetSidlPiece                               0x656560
#define CSidlScreenWnd__Init1                                      0x657750
#define CSidlScreenWnd__LoadIniInfo                                0x656730
#define CSidlScreenWnd__LoadIniListWnd                             0x655FD0
#define CSidlScreenWnd__LoadSidlScreen                             0x656190
#define CSidlScreenWnd__StoreIniInfo                               0x655960
#define CSidlScreenWnd__WndNotification                            0x6562C0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x512D40

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x675D90
#define CSliderWnd__SetValue                                       0x675E90
#define CSliderWnd__SetNumTicks                                    0x6763D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5DA880

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6722B0
#define CStmlWnd__CalculateVSBRange                                0x66A640
#define CStmlWnd__CanBreakAtCharacter                              0x66A780
#define CStmlWnd__FastForwardToEndOfTag                            0x66B290
#define CStmlWnd__GetNextTagPiece                                  0x66B1B0
#define CStmlWnd__GetSTMLText                                      0x555680
#define CStmlWnd__GetThisChar                                      0x692160
#define CStmlWnd__GetVisiableText                                  0x66C4B0
#define CStmlWnd__InitializeWindowVariables                        0x66E610
#define CStmlWnd__MakeStmlColorTag                                 0x669D20
#define CStmlWnd__MakeWndNotificationTag                           0x669DC0
#define CStmlWnd__StripFirstSTMLLines                              0x672030
#define CStmlWnd__UpdateHistoryString                              0x66CD10

// CTabWnd 
#define CTabWnd__Draw                                              0x675610
#define CTabWnd__DrawCurrentPage                                   0x675000
#define CTabWnd__DrawTab                                           0x674DE0
#define CTabWnd__GetCurrentPage                                    0x675280
#define CTabWnd__GetPageClientRect                                 0x674AB0
#define CTabWnd__GetPageFromTabIndex                               0x674D10
#define CTabWnd__GetPageInnerRect                                  0x674B10
#define CTabWnd__GetTabInnerRect                                   0x674C90
#define CTabWnd__GetTabRect                                        0x674BA0
#define CTabWnd__IndexInBounds                                     0x674DAD
#define CTabWnd__InsertPage                                        0x675830
#define CTabWnd__SetPage                                           0x6752C0
#define CTabWnd__SetPageRect                                       0x675540
#define CTabWnd__UpdatePage                                        0x6757B0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x413F40

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x657D50

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x67B4B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x64B470

// CXRect 
#define CXRect__CenterPoint                                        0x534170

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412360
#define CXStr__CXStr1                                              0x5B4600
#define CXStr__CXStr3                                              0x63FFA0
#define CXStr__dCXStr                                              0x510990
#define CXStr__operator_equal1                                     0x640160
#define CXStr__operator_plus_equal1                                0x641050

// CXWnd 
#define CXWnd__BringToTop                                          0x650DA0
#define CXWnd__Center                                              0x654500
#define CXWnd__ClrFocus                                            0x650AC0
#define CXWnd__DoAllDrawing                                        0x655180
#define CXWnd__DrawChildren                                        0x6552B0
#define CXWnd__DrawColoredRect                                     0x651000
#define CXWnd__DrawTooltip                                         0x6550A0
#define CXWnd__DrawTooltipAtPoint                                  0x6542E0
#define CXWnd__GetBorderFrame                                      0x6514C0
#define CXWnd__GetChildWndAt                                       0x653DE0
#define CXWnd__GetClientClipRect                                   0x651400
#define CXWnd__GetFirstChildWnd                                    0x650E40
#define CXWnd__GetNextChildWnd                                     0x653DA0
#define CXWnd__GetNextSib                                          0x650E60
#define CXWnd__GetScreenClipRect                                   0x6546F0
#define CXWnd__GetScreenRect                                       0x6516A0
#define CXWnd__GetTooltipRect                                      0x651230
#define CXWnd__GetWindowTextA                                      0x4E6870
#define CXWnd__IsActive                                            0x658E30
#define CXWnd__IsDescendantOf                                      0x651470
#define CXWnd__IsReallyVisible                                     0x653D80
#define CXWnd__IsType                                              0x6771E0
#define CXWnd__Move                                                0x6538B0
#define CXWnd__Move1                                               0x653950
#define CXWnd__ProcessTransition                                   0x650D70
#define CXWnd__Refade                                              0x650B70
#define CXWnd__Resize                                              0x654830
#define CXWnd__Right                                               0x654640
#define CXWnd__SetFirstChildPointer                                0x6518F0
#define CXWnd__SetFocus                                            0x652BE0
#define CXWnd__SetKeyTooltip                                       0x651960
#define CXWnd__SetMouseOver                                        0x651930
#define CXWnd__SetNextSibPointer                                   0x651910
#define CXWnd__StartFade                                           0x650DC0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x65A300
#define CXWndManager__DrawWindows                                  0x659F40
#define CXWndManager__GetFirstChildWnd                             0x6597D0
#define CXWndManager__GetKeyboardFlags                             0x658B10
#define CXWndManager__HandleKeyboardMsg                            0x659020
#define CXWndManager__RemoveWnd                                    0x658F40

// CDBStr
#define CDBStr__GetString                                          0x459470

// EQ_Character 
#define EQ_Character__CastRay                                      0x69DC40
#define EQ_Character__CastSpell                                    0x4238D0
#define EQ_Character__Cur_HP                                       0x42B330
#define EQ_Character__GetAACastingTimeModifier                     0x41EA70
#define EQ_Character__GetCharInfo2                                 0x621910
#define EQ_Character__GetFocusCastingTimeModifier                  0x41AAD0
#define EQ_Character__GetFocusRangeModifier                        0x41AC00
#define EQ_Character__Max_Endurance                                0x42A010
#define EQ_Character__Max_HP                                       0x429EC0
#define EQ_Character__Max_Mana                                     0x4F65A0
#define EQ_Character__doCombatAbility                              0x4F5420
#define EQ_Character__UseSkill                                     0x436D90
#define EQ_Character__GetConLevel                                  0x4F28E0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4E83A0
#define EQ_Item__GetItemLinkHash                                   0x616410
#define EQ_Item__IsStackable                                       0x60D220

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x471A70
#define EQ_LoadingS__Array                                         0x741160

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4F94D0
#define EQ_PC__GetAltAbilityIndex                                  0x61ACC0
#define EQ_PC__GetCombatAbility                                    0x61AD50
#define EQ_PC__GetCombatAbilityTimer                               0x61AE00
#define EQ_PC__GetItemTimerValue                                   0x4F4680
#define EQ_PC__HasLoreItem                                         0x4F7AF0

// EQItemList 
#define EQItemList__dEQItemList                                    0x499720
#define EQItemList__EQItemList                                     0x499670

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x458EF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4FE000
#define EQPlayer__dEQPlayer                                        0x5025D0
#define EQPlayer__DoAttack                                         0x50DCB0
#define EQPlayer__EQPlayer                                         0x504D80
#define EQPlayer__SetNameSpriteState                               0x500710
#define EQPlayer__SetNameSpriteTint                                0x4FE070
#define EQPlayer__IsBodyType_j                                     0x69D640

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x505D10

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4E9F70
#define KeypressHandler__AttachKeyToEqCommand                      0x4E9FB0
#define KeypressHandler__ClearCommandStateArray                    0x4E9D80
#define KeypressHandler__HandleKeyDown                             0x4E8990
#define KeypressHandler__HandleKeyUp                               0x4E8C90
#define KeypressHandler__SaveKeymapping                            0x4E9E50

// MapViewMap 
#define MapViewMap__Clear                                          0x5A7DB0
#define MapViewMap__SaveEx                                         0x5A8780

#define OtherCharData__GetAltCurrency                              0x6375D0

// StringTable 
#define StringTable__getString                                     0x60CBC0
