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
#define __ExpectedVersionDate                                     "Nov 12 2007"
#define __ExpectedVersionTime                                     "16:25:07"
#define __ActualVersionDate                                        0x710428
#define __ActualVersionTime                                        0x710404

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FA760
#define __MemChecker1                                              0x65AD40
#define __MemChecker2                                              0x52E240
#define __MemChecker3                                              0x52E2F0
#define __MemChecker4                                              0x623860
#define __EncryptPad0                                              0x76D108
#define __EncryptPad1                                              0x776EA0
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
#define pinstCEQMainWnd                                            0x9B276C
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
#define __CastRay                                                  0x4B7440
#define __ConvertItemTags                                          0x4AAD30
#define __ExecuteCmd                                               0x49A390
#define __get_melee_range                                          0x49F5C0
#define __GetGaugeValueFromEQ                                      0x5F5910
#define __GetLabelFromEQ                                           0x5F6110
#define __NewUIINI                                                 0x5F5500
#define __ProcessGameEvents                                        0x4E5BD0
//#define CrashDetected                                              0x0
#define DrawNetStatus                                              0x4FD540
#define Util__FastTime                                             0x65B400


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x473D40
#define AltAdvManager__IsAbilityReady                              0x473D80
#define AltAdvManager__GetAltAbility                               0x473F60

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5431C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x54CAB0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x686970

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x560390
#define CChatManager__InitContextMenu                              0x560B20

// CChatService
#define CChatService__GetNumberOfFriends                           0x64BAC0
#define CChatService__GetFriendName                                0x64BAD0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x564C90
#define CChatWindow__WndNotification                               0x5656B0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x66CF40
#define CComboWnd__Draw                                            0x66D0F0
#define CComboWnd__GetCurChoice                                    0x66CEE0
#define CComboWnd__GetListRect                                     0x66D3C0
#define CComboWnd__GetTextRect                                     0x66CF70
#define CComboWnd__InsertChoice                                    0x66D430
#define CComboWnd__SetColors                                       0x66CE70
#define CComboWnd__SetChoice                                       0x66CEA0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x56C040
#define CContainerWnd__vftable                                     0x7163A0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x462FB0
#define CDisplay__GetClickedActor                                  0x460710
#define CDisplay__GetUserDefinedColor                              0x45F890
#define CDisplay__GetWorldFilePath                                 0x45EE00
#define CDisplay__is3dON                                           0x45DF60
#define CDisplay__ReloadUI                                         0x46EB10
#define CDisplay__WriteTextHD2                                     0x4636E0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x53D1B0
#define CEditBaseWnd__SetSel                                       0x691980

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x67AB80
#define CEditWnd__GetCharIndexPt                                   0x67B9D0
#define CEditWnd__GetDisplayString                                 0x67AD10
#define CEditWnd__GetHorzOffset                                    0x67AFB0
#define CEditWnd__GetLineForPrintableChar                          0x67B480
#define CEditWnd__GetSelStartPt                                    0x67BC10
#define CEditWnd__GetSTMLSafeText                                  0x67B140
#define CEditWnd__PointFromPrintableChar                           0x67B590
#define CEditWnd__SelectableCharFromPoint                          0x67B710
#define CEditWnd__SetEditable                                      0x67B110

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4C99A0
#define CEverQuest__DropHeldItemOnGround                           0x4CE2B0
#define CEverQuest__dsp_chat                                       0x4CF130
#define CEverQuest__DoTellWindow                                   0x4CE430
#define CEverQuest__EnterZone                                      0x4E4610
#define CEverQuest__GetBodyTypeDesc                                0x4C6E30
#define CEverQuest__GetClassDesc                                   0x4C6590
#define CEverQuest__GetClassThreeLetterCode                        0x4C6B90
#define CEverQuest__GetDeityDesc                                   0x4C74A0
#define CEverQuest__GetLangDesc                                    0x4C71C0
#define CEverQuest__GetRaceDesc                                    0x4C7470
#define CEverQuest__InterpretCmd                                   0x4CFB60
#define CEverQuest__LeftClickedOnPlayer                            0x4E2E30
#define CEverQuest__LMouseUp                                       0x4E53B0
#define CEverQuest__RightClickedOnPlayer                           0x4E3200
#define CEverQuest__RMouseUp                                       0x4E4C10
#define CEverQuest__SetGameState                                   0x4C9E20
#define CEverQuest__Emote                                          0x4CF300

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5774C0
#define CGaugeWnd__CalcLinesFillRect                               0x577530
#define CGaugeWnd__Draw                                            0x5778C0

// CGuild
#define CGuild__FindMemberByName                                   0x417A20

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x58DCC0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x597140
#define CInvSlotMgr__MoveItem                                      0x5972E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x598260

// CInvSLot
#define CInvSlot__SliderComplete                                   0x596050

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5A6090
#define CItemDisplayWnd__SetSpell                                  0x5F38B0

// CLabel 
#define CLabel__Draw                                               0x5AB970

// CListWnd 
#define CListWnd__AddColumn                                        0x66CC80
#define CListWnd__AddColumn1                                       0x66C7C0
#define CListWnd__AddLine                                          0x66C350
#define CListWnd__AddString                                        0x66C520
#define CListWnd__CalculateFirstVisibleLine                        0x669680
#define CListWnd__CalculateVSBRange                                0x66B2F0
#define CListWnd__ClearAllSel                                      0x668E00
#define CListWnd__CloseAndUpdateEditWindow                         0x669CA0
#define CListWnd__Compare                                          0x66A050
#define CListWnd__Draw                                             0x66AFF0
#define CListWnd__DrawColumnSeparators                             0x66AE60
#define CListWnd__DrawHeader                                       0x668FD0
#define CListWnd__DrawItem                                         0x66A760
#define CListWnd__DrawLine                                         0x66AB10
#define CListWnd__DrawSeparator                                    0x66AF00
#define CListWnd__EnsureVisible                                    0x6696D0
#define CListWnd__ExtendSel                                        0x66A690
#define CListWnd__GetColumnMinWidth                                0x668BA0
#define CListWnd__GetColumnWidth                                   0x668AE0
#define CListWnd__GetCurSel                                        0x6685B0
#define CListWnd__GetHeaderRect                                    0x6686B0
#define CListWnd__GetItemAtPoint                                   0x6699B0
#define CListWnd__GetItemAtPoint1                                  0x669A20
#define CListWnd__GetItemData                                      0x668890
#define CListWnd__GetItemHeight                                    0x669430
#define CListWnd__GetItemIcon                                      0x668A20
#define CListWnd__GetItemRect                                      0x6697A0
#define CListWnd__GetItemText                                      0x6688D0
#define CListWnd__GetSelList                                       0x66C6A0
#define CListWnd__GetSeparatorRect                                 0x669F90
#define CListWnd__RemoveLine                                       0x66C650
#define CListWnd__SetColors                                        0x668610
#define CListWnd__SetColumnJustification                           0x668C00
#define CListWnd__SetColumnWidth                                   0x668B60
#define CListWnd__SetCurSel                                        0x6685F0
#define CListWnd__SetItemColor                                     0x66BF20
#define CListWnd__SetItemData                                      0x668EA0
#define CListWnd__SetItemText                                      0x66BEA0
#define CListWnd__ShiftColumnSeparator                             0x66A600
#define CListWnd__Sort                                             0x66CCB0
#define CListWnd__ToggleSel                                        0x668D70

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5BFF30

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C1A10
#define CMerchantWnd__RequestBuyItem                               0x5C2D50
#define CMerchantWnd__RequestSellItem                              0x5C1C60
#define CMerchantWnd__SelectBuySellSlot                            0x5C2A90

// CObfuscator
#define CObfuscator__doit                                          0x633080

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x682660

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x53ECA0
#define CSidlScreenWnd__CalculateVSBRange                          0x53EBE0
#define CSidlScreenWnd__ConvertToRes                               0x691860
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x674280
#define CSidlScreenWnd__CSidlScreenWnd1                            0x675100
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6751B0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x674B50
#define CSidlScreenWnd__DrawSidlPiece                              0x673F60
#define CSidlScreenWnd__EnableIniStorage                           0x673A80
#define CSidlScreenWnd__GetSidlPiece                               0x674160
#define CSidlScreenWnd__Init1                                      0x674F70
#define CSidlScreenWnd__LoadIniInfo                                0x674330
#define CSidlScreenWnd__LoadIniListWnd                             0x673BC0
#define CSidlScreenWnd__LoadSidlScreen                             0x673D80
#define CSidlScreenWnd__StoreIniInfo                               0x673690
#define CSidlScreenWnd__WndNotification                            0x673EC0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x51E150

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x692550
#define CSliderWnd__SetValue                                       0x692650
#define CSliderWnd__SetNumTicks                                    0x692B80

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5F2540

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x68FB20
#define CStmlWnd__CalculateVSBRange                                0x687F10
#define CStmlWnd__CanBreakAtCharacter                              0x688050
#define CStmlWnd__FastForwardToEndOfTag                            0x688B50
#define CStmlWnd__GetNextTagPiece                                  0x688A70
#define CStmlWnd__GetSTMLText                                      0x564C30
#define CStmlWnd__GetThisChar                                      0x6AFFC0
#define CStmlWnd__GetVisiableText                                  0x689D60
#define CStmlWnd__InitializeWindowVariables                        0x68BEB0
#define CStmlWnd__MakeStmlColorTag                                 0x6875B0
#define CStmlWnd__MakeWndNotificationTag                           0x687650
#define CStmlWnd__StripFirstSTMLLines                              0x68F8B0
#define CStmlWnd__UpdateHistoryString                              0x68A5B0

// CTabWnd 
#define CTabWnd__Draw                                              0x6939A0
#define CTabWnd__DrawCurrentPage                                   0x693320
#define CTabWnd__DrawTab                                           0x693100
#define CTabWnd__GetCurrentPage                                    0x693620
#define CTabWnd__GetPageClientRect                                 0x692DD0
#define CTabWnd__GetPageFromTabIndex                               0x693030
#define CTabWnd__GetPageInnerRect                                  0x692E30
#define CTabWnd__GetTabInnerRect                                   0x692FB0
#define CTabWnd__GetTabRect                                        0x692EC0
#define CTabWnd__IndexInBounds                                     0x6930CD
#define CTabWnd__InsertPage                                        0x693BC0
#define CTabWnd__SetPage                                           0x693660
#define CTabWnd__SetPageRect                                       0x6938D0
#define CTabWnd__UpdatePage                                        0x693B40

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x413FA0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x675510

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x698F80

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x668320

// CXRect 
#define CXRect__CenterPoint                                        0x542910

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412480
#define CXStr__CXStr1                                              0x51BA90
#define CXStr__CXStr3                                              0x65CAF0
#define CXStr__dCXStr                                              0x441C60
#define CXStr__operator_equal1                                     0x65CCB0
#define CXStr__operator_plus_equal1                                0x65DBA0

// CXWnd 
#define CXWnd__BringToTop                                          0x66DCC0
#define CXWnd__Center                                              0x671880
#define CXWnd__ClrFocus                                            0x66D9A0
#define CXWnd__DoAllDrawing                                        0x672310
#define CXWnd__DrawChildren                                        0x672440
#define CXWnd__DrawColoredRect                                     0x66DF60
#define CXWnd__DrawTooltip                                         0x672230
#define CXWnd__DrawTooltipAtPoint                                  0x671660
#define CXWnd__GetBorderFrame                                      0x66E430
#define CXWnd__GetChildWndAt                                       0x671100
#define CXWnd__GetClientClipRect                                   0x66E360
#define CXWnd__GetFirstChildWnd                                    0x66DD60
#define CXWnd__GetNextChildWnd                                     0x6710C0
#define CXWnd__GetNextSib                                          0x66DD80
#define CXWnd__GetScreenClipRect                                   0x671AA0
#define CXWnd__GetScreenRect                                       0x66E5E0
#define CXWnd__GetTooltipRect                                      0x66E190
#define CXWnd__GetWindowTextA                                      0x5363B0
#define CXWnd__IsActive                                            0x676610
#define CXWnd__IsDescendantOf                                      0x66E3E0
#define CXWnd__IsReallyVisible                                     0x6710A0
#define CXWnd__IsType                                              0x694A80
#define CXWnd__Move                                                0x670B60
#define CXWnd__Move1                                               0x670C00
#define CXWnd__ProcessTransition                                   0x66DC90
#define CXWnd__Refade                                              0x66DA50
#define CXWnd__Resize                                              0x66E6B0
#define CXWnd__Right                                               0x6719E0
#define CXWnd__SetFirstChildPointer                                0x66E8B0
#define CXWnd__SetFocus                                            0x66FBE0
#define CXWnd__SetKeyTooltip                                       0x66E910
#define CXWnd__SetMouseOver                                        0x66E8E0
#define CXWnd__SetNextSibPointer                                   0x66E8D0
#define CXWnd__StartFade                                           0x66DCE0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x677A50
#define CXWndManager__DrawWindows                                  0x677690
#define CXWndManager__GetFirstChildWnd                             0x676FA0
#define CXWndManager__GetKeyboardFlags                             0x6762D0
#define CXWndManager__HandleKeyboardMsg                            0x676800
#define CXWndManager__RemoveWnd                                    0x676720

// CDBStr
#define CDBStr__GetString                                          0x45C820

// EQ_Character 
#define EQ_Character__CastRay                                      0x6BC040
#define EQ_Character__CastSpell                                    0x425040
#define EQ_Character__Cur_HP                                       0x431A30
#define EQ_Character__GetAACastingTimeModifier                     0x41F8F0
#define EQ_Character__GetCharInfo2                                 0x63E2B0
#define EQ_Character__GetFocusCastingTimeModifier                  0x41B5A0
#define EQ_Character__GetFocusRangeModifier                        0x41B6D0
#define EQ_Character__Max_Endurance                                0x42CDC0
#define EQ_Character__Max_HP                                       0x42CC40
#define EQ_Character__Max_Mana                                     0x502960
#define EQ_Character__doCombatAbility                              0x5017A0
#define EQ_Character__UseSkill                                     0x437B40
#define EQ_Character__GetConLevel                                  0x4FE910

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F2560
#define EQ_Item__GetItemLinkHash                                   0x6326E0
#define EQ_Item__IsStackable                                       0x6295A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x474EB0
#define EQ_LoadingS__Array                                         0x7667D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x505B30
#define EQ_PC__GetAltAbilityIndex                                  0x637490
#define EQ_PC__GetCombatAbility                                    0x637520
#define EQ_PC__GetCombatAbilityTimer                               0x6375D0
#define EQ_PC__GetItemTimerValue                                   0x5006F0
#define EQ_PC__HasLoreItem                                         0x503F80

// EQItemList 
#define EQItemList__dEQItemList                                    0x49DCD0
#define EQItemList__EQItemList                                     0x49DC20

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45C1E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50A9A0
#define EQPlayer__dEQPlayer                                        0x50F130
#define EQPlayer__DoAttack                                         0x51ACC0
#define EQPlayer__EQPlayer                                         0x511D10
#define EQPlayer__SetNameSpriteState                               0x50D0A0
#define EQPlayer__SetNameSpriteTint                                0x50AA10
#define EQPlayer__IsBodyType_j                                     0x6BBA20

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x512CA0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F4160
#define KeypressHandler__AttachKeyToEqCommand                      0x4F41A0
#define KeypressHandler__ClearCommandStateArray                    0x4F3F70
#define KeypressHandler__HandleKeyDown                             0x4F2B50
#define KeypressHandler__HandleKeyUp                               0x4F2E50
#define KeypressHandler__SaveKeymapping                            0x4F4040

// MapViewMap 
#define MapViewMap__Clear                                          0x5BBF40
#define MapViewMap__SaveEx                                         0x5BC910

#define OtherCharData__GetAltCurrency                              0x654080

// StringTable 
#define StringTable__getString                                     0x628EF0
