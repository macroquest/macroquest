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
#define __ExpectedVersionDate                                     "Nov 19 2007"
#define __ExpectedVersionTime                                     "15:37:04"
#define __ActualVersionDate                                        0x710428
#define __ActualVersionTime                                        0x710404

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FA900
#define __MemChecker1                                              0x65AFD0
#define __MemChecker2                                              0x52E5E0
#define __MemChecker3                                              0x52E690
#define __MemChecker4                                              0x623B00
#define __EncryptPad0                                              0x76D108
#define __EncryptPad1                                              0x776E98
#define __EncryptPad2                                              0x76F680
#define __EncryptPad3                                              0x76FA80
#define __EncryptPad4                                              0x776578

// Direct Input
#define DI8__Main                                                  0x9B24CC
#define DI8__Keyboard                                              0x9B24D0
#define DI8__Mouse                                                 0x9B24D4
#define __AltTimerReady                                            0x94119E
#define __Attack                                                   0x99EAAA
#define __Autofire                                                 0x99EAAB
#define __BindList                                                 0x7682C8
#define __Clicks                                                   0x9402C0
#define __CommandList                                              0x768AD8
#define __CurrentMapLabel                                          0x9B50E4
#define __CurrentSocial                                            0x764544
#define __DoAbilityAvailable                                       0x941138
#define __DoAbilityList                                            0x9765C8
#define __DrawHandler                                              0x9C438C
#define __GroupCount                                               0x9207D2
#define __GroupLeader                                              0x920B24
#define __Guilds                                                   0x9224F0
#define __gWorld                                                   0x92242C
#define __HotkeyPage                                               0x99D9B4
#define __HWnd                                                     0x9B220C
#define __InChatMode                                               0x9401F8
#define __LastTell                                                 0x941A60
#define __LMouseHeldTime                                           0x9402E0
#define __Mouse                                                    0x9B24D8
#define __MouseLook                                                0x94028E
#define __NetStatusToggle                                          0x940290
#define __PCNames                                                  0x9414B8
#define __RangeAttackReady                                         0x94119C
#define __RMouseHeldTime                                           0x9402DC
#define __RunWalkState                                             0x9401FC
#define __ScreenMode                                               0x870130
#define __ScreenX                                                  0x9401B0
#define __ScreenY                                                  0x9401B4
#define __ScreenXMax                                               0x9401B8
#define __ScreenYMax                                               0x9401BC
#define __ServerHost                                               0x92071C
#define __ServerName                                               0x976588
#define __ShiftKeyDown                                             0x940854
#define __ShowNames                                                0x941390
#define __Socials                                                  0x976688


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x93A140
#define instEQZoneInfo                                             0x94042C
#define instKeypressHandler                                        0x99EB94
#define pinstActiveBanker                                          0x9224C4
#define pinstActiveCorpse                                          0x9224C8
#define pinstActiveGMaster                                         0x9224CC
#define pinstActiveMerchant                                        0x9224C0
#define pinstAltAdvManager                                         0x870F80
#define pinstAuraMgr                                               0x77BFCC
#define pinstBandageTarget                                         0x9224AC
#define pinstCamActor                                              0x870A70
#define pinstCDBStr                                                0x870120
#define pinstCDisplay                                              0x9224D4
#define pinstCEverQuest                                            0x9B2650
#define pinstCharData                                              0x922490
#define pinstCharSpawn                                             0x9224B8
#define pinstControlledMissile                                     0x92248C
#define pinstControlledPlayer                                      0x9224B8
#define pinstCSidlManager                                          0x9C3B70
#define pinstCXWndManager                                          0x9C3B68
#define instDynamicZone                                            0x93FC00
#define pinstDZMember                                              0x93FD10
#define pinstDZTimerInfo                                           0x93FD14
#define pinstEQItemList                                            0x922474
#define instEQMisc                                                 0x8700D8
#define pinstEQSoundManager                                        0x870FA4
#define instExpeditionLeader                                       0x93FC4A
#define instExpeditionName                                         0x93FC8A
#define instGroup                                                  0x9209C8
#define pinstGroup                                                 0x9207CE
#define pinstImeManager                                            0x9C3B74
#define pinstLocalPlayer                                           0x9224A4
#define pinstModelPlayer                                           0x9224D0
#define pinstPCData                                                0x922490
#define pinstSelectedItem                                          0x9B4F1C
#define pinstSkillMgr                                              0x9AF43C
#define pinstSpawnManager                                          0x9AF3BC
#define pinstSpellManager                                          0x9AF440
#define pinstSpellSets                                             0x99D9B8
#define pinstStringTable                                           0x922448
#define pinstSwitchManager                                         0x920418
#define pinstTarget                                                0x9224BC
#define pinstTargetObject                                          0x922494
#define pinstTargetSwitch                                          0x922498
#define pinstTaskMember                                            0x8700B8
#define pinstTrackTarget                                           0x9224B0
#define pinstTradeTarget                                           0x9224A0
#define instTributeActive                                          0x8700FD
#define pinstViewActor                                             0x870A6C
#define pinstWorldData                                             0x922470


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x77A500
#define pinstCAudioTriggersWindow                                  0x77A4CC
#define pinstCCharacterSelect                                      0x870980
#define pinstCFacePick                                             0x870938
#define pinstCNoteWnd                                              0x87093C
#define pinstCBookWnd                                              0x870940
#define pinstCPetInfoWnd                                           0x870944
#define pinstCTrainWnd                                             0x870948
#define pinstCSkillsWnd                                            0x87094C
#define pinstCSkillsSelectWnd                                      0x870950
#define pinstCCombatSkillSelectWnd                                 0x870954
#define pinstCFriendsWnd                                           0x870958
#define pinstCAuraWnd                                              0x87095C
#define pinstCRespawnWnd                                           0x870960
#define pinstCBandolierWnd                                         0x870964
#define pinstCPotionBeltWnd                                        0x870968
#define pinstCAAWnd                                                0x87096C
#define pinstCGroupSearchFiltersWnd                                0x870970
#define pinstCLoadskinWnd                                          0x870974
#define pinstCAlarmWnd                                             0x870978
#define pinstCMusicPlayerWnd                                       0x87097C
#define pinstCMailWnd                                              0x870984
#define pinstCMailCompositionWnd                                   0x870988
#define pinstCMailAddressBookWnd                                   0x87098C
#define pinstCRaidWnd                                              0x870994
#define pinstCRaidOptionsWnd                                       0x870998
#define pinstCBreathWnd                                            0x87099C
#define pinstCMapViewWnd                                           0x8709A0
#define pinstCMapToolbarWnd                                        0x8709A4
#define pinstCEditLabelWnd                                         0x8709A8
#define pinstCTargetWnd                                            0x8709AC
#define pinstCColorPickerWnd                                       0x8709B0
#define pinstCPlayerWnd                                            0x8709B4
#define pinstCOptionsWnd                                           0x8709B8
#define pinstCBuffWindowNORMAL                                     0x8709BC
#define pinstCBuffWindowSHORT                                      0x8709C0
#define pinstCharacterCreation                                     0x8709C4
#define pinstCCursorAttachment                                     0x8709C8
#define pinstCCastingWnd                                           0x8709CC
#define pinstCCastSpellWnd                                         0x8709D0
#define pinstCSpellBookWnd                                         0x8709D4
#define pinstCInventoryWnd                                         0x8709D8
#define pinstCBankWnd                                              0x8709DC
#define pinstCQuantityWnd                                          0x8709E0
#define pinstCLootWnd                                              0x8709E4
#define pinstCActionsWnd                                           0x8709E8
#define pinstCCombatAbilityWnd                                     0x8709EC
#define pinstCMerchantWnd                                          0x8709F0
#define pinstCTradeWnd                                             0x8709F4
#define pinstCSelectorWnd                                          0x8709F8
#define pinstCBazaarWnd                                            0x8709FC
#define pinstCBazaarSearchWnd                                      0x870A00
#define pinstCGiveWnd                                              0x870A04
#define pinstCTrackingWnd                                          0x870A08
#define pinstCInspectWnd                                           0x870A0C
#define pinstCSocialEditWnd                                        0x870A10
#define pinstCFeedbackWnd                                          0x870A14
#define pinstCBugReportWnd                                         0x870A18
#define pinstCVideoModesWnd                                        0x870A1C
#define pinstCTextEntryWnd                                         0x870A24
#define pinstCFileSelectionWnd                                     0x870A28
#define pinstCCompassWnd                                           0x870A2C
#define pinstCPlayerNotesWnd                                       0x870A30
#define pinstCGemsGameWnd                                          0x870A34
#define pinstCTimeLeftWnd                                          0x870A38
#define pinstCPetitionQWnd                                         0x870A3C
#define pinstCSoulmarkWnd                                          0x870A40
#define pinstCStoryWnd                                             0x870A44
#define pinstCJournalTextWnd                                       0x870A48
#define pinstCJournalCatWnd                                        0x870A4C
#define pinstCBodyTintWnd                                          0x870A50
#define pinstCServerListWnd                                        0x870A54
#define pinstCAvaZoneWnd                                           0x870A58
#define pinstCBlockedBuffWnd                                       0x870A5C
#define pinstCBlockedPetBuffWnd                                    0x870A60
#define pinstCInvSlotMgr                                           0x870A64
#define pinstCContainerMgr                                         0x870A68
#define pinstCAdventureLeaderboardWnd                              0x9B26F4
#define pinstCAdventureRequestWnd                                  0x9B2710
#define pinstCAltStorageWnd                                        0x9B2770
#define pinstCAdventureStatsWnd                                    0x9B272C
#define pinstCBarterMerchantWnd                                    0x9B293C
#define pinstCBarterSearchWnd                                      0x9B2958
#define pinstCBarterWnd                                            0x9B2974
#define pinstCChatManager                                          0x9B2B54
#define pinstCDynamicZoneWnd                                       0x9B2C4C
#define pinstCEQMainWnd                                            0x9B2CBC
#define pinstCFellowshipWnd                                        0x9B2D20
#define pinstCFindLocationWnd                                      0x9B2D54
#define pinstCGroupSearchWnd                                       0x9B2E04
#define pinstCGroupWnd                                             0x9B2E20
#define pinstCGuildBankWnd                                         0x9B2E3C
#define pinstCGuildMgmtWnd                                         0x9B4E58
#define pinstCGuildTributeMasterWnd                                0x9B4E78
#define pinstCHotButtonWnd                                         0x9B4E94
#define pinstCHotButtonWnd1                                        0x9B4E94
#define pinstCHotButtonWnd2                                        0x9B4E98
#define pinstCHotButtonWnd3                                        0x9B4E9C
#define pinstCHotButtonWnd4                                        0x9B4EA0
#define pinstCItemDisplayManager                                   0x9B4F50
#define pinstCItemExpTransferWnd                                   0x9B4F70
#define pinstCLeadershipWnd                                        0x9B500C
#define pinstCLFGuildWnd                                           0x9B5028
#define pinstCMIZoneSelectWnd                                      0x9B514C
#define pinstCAdventureMerchantWnd                                 0x9B5244
#define pinstCConfirmationDialog                                   0x9B5260
#define pinstCPopupWndManager                                      0x9B5260
#define pinstCProgressionSelectionWnd                              0x9B5294
#define pinstCPvPLeaderboardWnd                                    0x9B52B0
#define pinstCPvPStatsWnd                                          0x9B52CC
#define pinstCSystemInfoDialogBox                                  0x9B537C
#define pinstCTargetOfTargetWnd                                    0x9B5C6C
#define pinstCTaskSelectWnd                                        0x9B5C88
#define pinstCTaskTemplateSelectWnd                                0x9B5CA4
#define pinstCTaskWnd                                              0x9B5CC0
#define pinstCTipWndOFDAY                                          0x9B5D3C
#define pinstCTipWndCONTEXT                                        0x9B5D40
#define pinstCTitleWnd                                             0x9B5D5C
#define pinstCTradeskillWnd                                        0x9B5DA0
#define pinstCTributeBenefitWnd                                    0x9B5DEC
#define pinstCTributeMasterWnd                                     0x9B5E08
#define pinstCContextMenuManager                                   0x9C3BCC
#define pinstCVoiceMacroWnd                                        0x9AF52C
#define pinstCHtmlWnd                                              0x9AF548


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4B7630
#define __ConvertItemTags                                          0x4AAD00
#define __ExecuteCmd                                               0x49A330
#define __get_melee_range                                          0x49F590
#define __GetGaugeValueFromEQ                                      0x5F5B40
#define __GetLabelFromEQ                                           0x5F6340
#define __NewUIINI                                                 0x5F5730
#define __ProcessGameEvents                                        0x4E5CE0
#define DrawNetStatus                                              0x4FD730
#define Util__FastTime                                             0x65B690


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x473D20
#define AltAdvManager__IsAbilityReady                              0x473D60
#define AltAdvManager__GetAltAbility                               0x473EF0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5434E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x54CDE0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x686D20

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x560430
#define CChatManager__InitContextMenu                              0x560BC0

// CChatService
#define CChatService__GetNumberOfFriends                           0x64BC30
#define CChatService__GetFriendName                                0x64BC40

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x564D30
#define CChatWindow__WndNotification                               0x565750

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x66D290
#define CComboWnd__Draw                                            0x66D440
#define CComboWnd__GetCurChoice                                    0x66D230
#define CComboWnd__GetListRect                                     0x66D710
#define CComboWnd__GetTextRect                                     0x66D2C0
#define CComboWnd__InsertChoice                                    0x66D780
#define CComboWnd__SetColors                                       0x66D1C0
#define CComboWnd__SetChoice                                       0x66D1F0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x56C200
#define CContainerWnd__vftable                                     0x7163A0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x462F70
#define CDisplay__GetClickedActor                                  0x4606C0
#define CDisplay__GetUserDefinedColor                              0x45F840
#define CDisplay__GetWorldFilePath                                 0x45EDB0
#define CDisplay__is3dON                                           0x45DF10
#define CDisplay__ReloadUI                                         0x46EAD0
#define CDisplay__WriteTextHD2                                     0x4636A0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x53D560
#define CEditBaseWnd__SetSel                                       0x691D70

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x67AF30
#define CEditWnd__GetCharIndexPt                                   0x67BD80
#define CEditWnd__GetDisplayString                                 0x67B0C0
#define CEditWnd__GetHorzOffset                                    0x67B360
#define CEditWnd__GetLineForPrintableChar                          0x67B830
#define CEditWnd__GetSelStartPt                                    0x67BFC0
#define CEditWnd__GetSTMLSafeText                                  0x67B4F0
#define CEditWnd__PointFromPrintableChar                           0x67B940
#define CEditWnd__SelectableCharFromPoint                          0x67BAC0
#define CEditWnd__SetEditable                                      0x67B4C0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4C9AB0
#define CEverQuest__DropHeldItemOnGround                           0x4CE3C0
#define CEverQuest__dsp_chat                                       0x4CF240
#define CEverQuest__DoTellWindow                                   0x4CE540
#define CEverQuest__EnterZone                                      0x4E4720
#define CEverQuest__GetBodyTypeDesc                                0x4C6F40
#define CEverQuest__GetClassDesc                                   0x4C66A0
#define CEverQuest__GetClassThreeLetterCode                        0x4C6CA0
#define CEverQuest__GetDeityDesc                                   0x4C75B0
#define CEverQuest__GetLangDesc                                    0x4C72D0
#define CEverQuest__GetRaceDesc                                    0x4C7580
#define CEverQuest__InterpretCmd                                   0x4CFC70
#define CEverQuest__LeftClickedOnPlayer                            0x4E2F40
#define CEverQuest__LMouseUp                                       0x4E54C0
#define CEverQuest__RightClickedOnPlayer                           0x4E3310
#define CEverQuest__RMouseUp                                       0x4E4D20
#define CEverQuest__SetGameState                                   0x4C9F30
#define CEverQuest__Emote                                          0x4CF410

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5776F0
#define CGaugeWnd__CalcLinesFillRect                               0x577760
#define CGaugeWnd__Draw                                            0x577AF0

// CGuild
#define CGuild__FindMemberByName                                   0x4179E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x58DF40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5973A0
#define CInvSlotMgr__MoveItem                                      0x597540

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5984C0

// CInvSLot
#define CInvSlot__SliderComplete                                   0x5962B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5A62F0
#define CItemDisplayWnd__SetSpell                                  0x5F3A00

// CLabel 
#define CLabel__Draw                                               0x5ABB20

// CListWnd 
#define CListWnd__AddColumn                                        0x66CFD0
#define CListWnd__AddColumn1                                       0x66CB10
#define CListWnd__AddLine                                          0x66C6A0
#define CListWnd__AddString                                        0x66C870
#define CListWnd__CalculateFirstVisibleLine                        0x6699D0
#define CListWnd__CalculateVSBRange                                0x66B640
#define CListWnd__ClearAllSel                                      0x669150
#define CListWnd__CloseAndUpdateEditWindow                         0x669FF0
#define CListWnd__Compare                                          0x66A3A0
#define CListWnd__Draw                                             0x66B340
#define CListWnd__DrawColumnSeparators                             0x66B1B0
#define CListWnd__DrawHeader                                       0x669320
#define CListWnd__DrawItem                                         0x66AAB0
#define CListWnd__DrawLine                                         0x66AE60
#define CListWnd__DrawSeparator                                    0x66B250
#define CListWnd__EnsureVisible                                    0x669A20
#define CListWnd__ExtendSel                                        0x66A9E0
#define CListWnd__GetColumnMinWidth                                0x668EF0
#define CListWnd__GetColumnWidth                                   0x668E30
#define CListWnd__GetCurSel                                        0x668900
#define CListWnd__GetHeaderRect                                    0x668A00
#define CListWnd__GetItemAtPoint                                   0x669D00
#define CListWnd__GetItemAtPoint1                                  0x669D70
#define CListWnd__GetItemData                                      0x668BE0
#define CListWnd__GetItemHeight                                    0x669780
#define CListWnd__GetItemIcon                                      0x668D70
#define CListWnd__GetItemRect                                      0x669AF0
#define CListWnd__GetItemText                                      0x668C20
#define CListWnd__GetSelList                                       0x66C9F0
#define CListWnd__GetSeparatorRect                                 0x66A2E0
#define CListWnd__RemoveLine                                       0x66C9A0
#define CListWnd__SetColors                                        0x668960
#define CListWnd__SetColumnJustification                           0x668F50
#define CListWnd__SetColumnWidth                                   0x668EB0
#define CListWnd__SetCurSel                                        0x668940
#define CListWnd__SetItemColor                                     0x66C270
#define CListWnd__SetItemData                                      0x6691F0
#define CListWnd__SetItemText                                      0x66C1F0
#define CListWnd__ShiftColumnSeparator                             0x66A950
#define CListWnd__Sort                                             0x66D000
#define CListWnd__ToggleSel                                        0x6690C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5C00F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C1BD0
#define CMerchantWnd__RequestBuyItem                               0x5C2F10
#define CMerchantWnd__RequestSellItem                              0x5C1E20
#define CMerchantWnd__SelectBuySellSlot                            0x5C2C50

// CObfuscator
#define CObfuscator__doit                                          0x6332A0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x682960

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x53EF90
#define CSidlScreenWnd__CalculateVSBRange                          0x672D50
#define CSidlScreenWnd__ConvertToRes                               0x691C50
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x674660
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6754B0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x675560
#define CSidlScreenWnd__dCSidlScreenWnd                            0x674F00
#define CSidlScreenWnd__DrawSidlPiece                              0x674340
#define CSidlScreenWnd__EnableIniStorage                           0x673E60
#define CSidlScreenWnd__GetSidlPiece                               0x674540
#define CSidlScreenWnd__Init1                                      0x675320
#define CSidlScreenWnd__LoadIniInfo                                0x674710
#define CSidlScreenWnd__LoadIniListWnd                             0x673FA0
#define CSidlScreenWnd__LoadSidlScreen                             0x674160
#define CSidlScreenWnd__StoreIniInfo                               0x673A70
#define CSidlScreenWnd__WndNotification                            0x6742A0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x51E470

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x42B590
#define CSliderWnd__SetValue                                       0x692A30
#define CSliderWnd__SetNumTicks                                    0x692F60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5F2690

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x68FF20
#define CStmlWnd__CalculateVSBRange                                0x6882E0
#define CStmlWnd__CanBreakAtCharacter                              0x688420
#define CStmlWnd__FastForwardToEndOfTag                            0x688F30
#define CStmlWnd__GetNextTagPiece                                  0x688E50
#define CStmlWnd__GetSTMLText                                      0x564CD0
#define CStmlWnd__GetThisChar                                      0x6B0270
#define CStmlWnd__GetVisiableText                                  0x68A160
#define CStmlWnd__InitializeWindowVariables                        0x68C2B0
#define CStmlWnd__MakeStmlColorTag                                 0x687960
#define CStmlWnd__MakeWndNotificationTag                           0x687A00
#define CStmlWnd__StripFirstSTMLLines                              0x68FCB0
#define CStmlWnd__UpdateHistoryString                              0x68A9B0

// CTabWnd 
#define CTabWnd__Draw                                              0x693DB0
#define CTabWnd__DrawCurrentPage                                   0x693700
#define CTabWnd__DrawTab                                           0x6934E0
#define CTabWnd__GetCurrentPage                                    0x693A30
#define CTabWnd__GetPageClientRect                                 0x6931B0
#define CTabWnd__GetPageFromTabIndex                               0x693410
#define CTabWnd__GetPageInnerRect                                  0x693210
#define CTabWnd__GetTabInnerRect                                   0x693390
#define CTabWnd__GetTabRect                                        0x6932A0
#define CTabWnd__IndexInBounds                                     0x6934AD
#define CTabWnd__InsertPage                                        0x693FD0
#define CTabWnd__SetPage                                           0x693A70
#define CTabWnd__SetPageRect                                       0x693CE0
#define CTabWnd__UpdatePage                                        0x693F50

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x413F60

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6758C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x699320

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x668670

// CXRect 
#define CXRect__CenterPoint                                        0x542C30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4122D0
#define CXStr__CXStr1                                              0x403580
#define CXStr__CXStr3                                              0x65CD80
#define CXStr__dCXStr                                              0x4F4C90
#define CXStr__operator_equal1                                     0x65CF40
#define CXStr__operator_plus_equal1                                0x65DE30

// CXWnd 
#define CXWnd__BringToTop                                          0x66E000
#define CXWnd__Center                                              0x671BA0
#define CXWnd__ClrFocus                                            0x66DCF0
#define CXWnd__DoAllDrawing                                        0x672630
#define CXWnd__DrawChildren                                        0x672760
#define CXWnd__DrawColoredRect                                     0x66E2A0
#define CXWnd__DrawTooltip                                         0x672550
#define CXWnd__DrawTooltipAtPoint                                  0x671980
#define CXWnd__GetBorderFrame                                      0x66E770
#define CXWnd__GetChildWndAt                                       0x671420
#define CXWnd__GetClientClipRect                                   0x66E6A0
#define CXWnd__GetFirstChildWnd                                    0x66E0A0
#define CXWnd__GetNextChildWnd                                     0x6713E0
#define CXWnd__GetNextSib                                          0x66E0C0
#define CXWnd__GetScreenClipRect                                   0x671DC0
#define CXWnd__GetScreenRect                                       0x66E920
#define CXWnd__GetTooltipRect                                      0x66E4D0
#define CXWnd__GetWindowTextA                                      0x536780
#define CXWnd__IsActive                                            0x6769C0
#define CXWnd__IsDescendantOf                                      0x66E720
#define CXWnd__IsReallyVisible                                     0x6713C0
#define CXWnd__IsType                                              0x694F10
#define CXWnd__Move                                                0x670E80
#define CXWnd__Move1                                               0x670F20
#define CXWnd__ProcessTransition                                   0x66DFD0
#define CXWnd__Refade                                              0x66DDA0
#define CXWnd__Resize                                              0x66E9F0
#define CXWnd__Right                                               0x671D00
#define CXWnd__SetFirstChildPointer                                0x66EBD0
#define CXWnd__SetFocus                                            0x66FF00
#define CXWnd__SetKeyTooltip                                       0x66EC30
#define CXWnd__SetMouseOver                                        0x66EC00
#define CXWnd__SetNextSibPointer                                   0x66EBF0
#define CXWnd__StartFade                                           0x66E020

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x677E00
#define CXWndManager__DrawWindows                                  0x677A40
#define CXWndManager__GetFirstChildWnd                             0x677350
#define CXWndManager__GetKeyboardFlags                             0x676680
#define CXWndManager__HandleKeyboardMsg                            0x676BB0
#define CXWndManager__RemoveWnd                                    0x676AD0

// CDBStr
#define CDBStr__GetString                                          0x45C7F0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6BC280
#define EQ_Character__CastSpell                                    0x424FE0
#define EQ_Character__Cur_HP                                       0x4319B0
#define EQ_Character__GetAACastingTimeModifier                     0x41F890
#define EQ_Character__GetCharInfo2                                 0x63E430
#define EQ_Character__GetFocusCastingTimeModifier                  0x41B560
#define EQ_Character__GetFocusRangeModifier                        0x41B690
#define EQ_Character__Max_Endurance                                0x42CD40
#define EQ_Character__Max_HP                                       0x42CBC0
#define EQ_Character__Max_Mana                                     0x502B50
#define EQ_Character__doCombatAbility                              0x501990
#define EQ_Character__UseSkill                                     0x437AC0
#define EQ_Character__GetConLevel                                  0x4FEB00

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F26C0
#define EQ_Item__GetItemLinkHash                                   0x632900
#define EQ_Item__IsStackable                                       0x6297C0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x474E40
#define EQ_LoadingS__Array                                         0x7667D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x505D20
#define EQ_PC__GetAltAbilityIndex                                  0x637610
#define EQ_PC__GetCombatAbility                                    0x6376A0
#define EQ_PC__GetCombatAbilityTimer                               0x637750
#define EQ_PC__GetItemTimerValue                                   0x5008E0
#define EQ_PC__HasLoreItem                                         0x504170

// EQItemList 
#define EQItemList__dEQItemList                                    0x49DC70
#define EQItemList__EQItemList                                     0x49DBC0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45C1B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50ABB0
#define EQPlayer__dEQPlayer                                        0x50F340
#define EQPlayer__DoAttack                                         0x51AFC0
#define EQPlayer__EQPlayer                                         0x512020
#define EQPlayer__SetNameSpriteState                               0x50D2B0
#define EQPlayer__SetNameSpriteTint                                0x50AC20
#define EQPlayer__IsBodyType_j                                     0x6BBC60

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x512FB0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F42C0
#define KeypressHandler__AttachKeyToEqCommand                      0x4F4300
#define KeypressHandler__ClearCommandStateArray                    0x4F40D0
#define KeypressHandler__HandleKeyDown                             0x4F2CB0
#define KeypressHandler__HandleKeyUp                               0x4F2FB0
#define KeypressHandler__SaveKeymapping                            0x4F41A0

// MapViewMap 
#define MapViewMap__Clear                                          0x5BC100
#define MapViewMap__SaveEx                                         0x5BCAD0

#define OtherCharData__GetAltCurrency                              0x654310

// StringTable 
#define StringTable__getString                                     0x629100
