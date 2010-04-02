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
#define __ExpectedVersionDate                                     "Dec 11 2007"
#define __ExpectedVersionTime                                     "15:16:09"
#define __ActualVersionDate                                        0x7152EC
#define __ActualVersionTime                                        0x7152F8

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FA9D0
#define __MemChecker1                                              0x660020
#define __MemChecker2                                              0x52E860
#define __MemChecker3                                              0x52E910
#define __MemChecker4                                              0x624D70
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
#define __do_loot                                                  0x4A59A0
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
#define __CastRay                                                  0x4B74B0
#define __ConvertItemTags                                          0x4AAB80
#define __ExecuteCmd                                               0x49A1E0
#define __get_melee_range                                          0x49F410
#define __GetGaugeValueFromEQ                                      0x5F6DC0
#define __GetLabelFromEQ                                           0x5F75C0
#define __NewUIINI                                                 0x5F69B0
#define __ProcessGameEvents                                        0x4E5E40
#define CrashDetected                                              0x52D5E0
#define DrawNetStatus                                              0x4FD7B0
#define Util__FastTime                                             0x6606A0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x473BD0
#define AltAdvManager__IsAbilityReady                              0x473C10
#define AltAdvManager__GetAltAbility                               0x473D60

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x544730

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x54E030

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x68BE80

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x561700
#define CChatManager__InitContextMenu                              0x561E90

// CChatService
#define CChatService__GetNumberOfFriends                           0x650C60
#define CChatService__GetFriendName                                0x650C70

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x566000
#define CChatWindow__WndNotification                               0x566A20

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x672150
#define CComboWnd__Draw                                            0x672300
#define CComboWnd__GetCurChoice                                    0x6720F0
#define CComboWnd__GetListRect                                     0x6725D0
#define CComboWnd__GetTextRect                                     0x672180
#define CComboWnd__InsertChoice                                    0x672640
#define CComboWnd__SetColors                                       0x672080
#define CComboWnd__SetChoice                                       0x6720B0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x56D360
#define CContainerWnd__vftable                                     0x71BBA0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x462E40
#define CDisplay__GetClickedActor                                  0x460580
#define CDisplay__GetUserDefinedColor                              0x45F700
#define CDisplay__GetWorldFilePath                                 0x45EC70
#define CDisplay__is3dON                                           0x45DDD0
#define CDisplay__ReloadUI                                         0x46E9A0
#define CDisplay__WriteTextHD2                                     0x463570

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x53E880
#define CEditBaseWnd__SetSel                                       0x696EB0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x67FEC0
#define CEditWnd__GetCharIndexPt                                   0x680D10
#define CEditWnd__GetDisplayString                                 0x680050
#define CEditWnd__GetHorzOffset                                    0x6802F0
#define CEditWnd__GetLineForPrintableChar                          0x6807C0
#define CEditWnd__GetSelStartPt                                    0x680F50
#define CEditWnd__GetSTMLSafeText                                  0x680480
#define CEditWnd__PointFromPrintableChar                           0x6808D0
#define CEditWnd__SelectableCharFromPoint                          0x680A50
#define CEditWnd__SetEditable                                      0x680450

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4C9930
#define CEverQuest__DropHeldItemOnGround                           0x4CE240
#define CEverQuest__dsp_chat                                       0x4CF0C0
#define CEverQuest__DoTellWindow                                   0x4CE3C0
#define CEverQuest__EnterZone                                      0x4E4880
#define CEverQuest__GetBodyTypeDesc                                0x4C6DC0
#define CEverQuest__GetClassDesc                                   0x4C6520
#define CEverQuest__GetClassThreeLetterCode                        0x4C6B20
#define CEverQuest__GetDeityDesc                                   0x4C7430
#define CEverQuest__GetLangDesc                                    0x4C7150
#define CEverQuest__GetRaceDesc                                    0x4C7400
#define CEverQuest__InterpretCmd                                   0x4CFAF0
#define CEverQuest__LeftClickedOnPlayer                            0x4E30A0
#define CEverQuest__LMouseUp                                       0x4E5620
#define CEverQuest__RightClickedOnPlayer                           0x4E3470
#define CEverQuest__RMouseUp                                       0x4E4E80
#define CEverQuest__SetGameState                                   0x4C9DB0
#define CEverQuest__Emote                                          0x4CF290

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x578900
#define CGaugeWnd__CalcLinesFillRect                               0x578970
#define CGaugeWnd__Draw                                            0x578D00

// CGuild
#define CGuild__FindMemberByName                                   0x417A80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x58F0C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x598540
#define CInvSlotMgr__MoveItem                                      0x5986E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x599670

// CInvSLot
#define CInvSlot__SliderComplete                                   0x597450

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5A7470
#define CItemDisplayWnd__SetSpell                                  0x5F4C50

// CLabel 
#define CLabel__Draw                                               0x5ACD50

// CListWnd 
#define CListWnd__AddColumn                                        0x671E90
#define CListWnd__AddColumn1                                       0x671980
#define CListWnd__AddLine                                          0x671560
#define CListWnd__AddString                                        0x671730
#define CListWnd__CalculateFirstVisibleLine                        0x66E890
#define CListWnd__CalculateVSBRange                                0x670500
#define CListWnd__ClearAllSel                                      0x66E010
#define CListWnd__CloseAndUpdateEditWindow                         0x66EEB0
#define CListWnd__Compare                                          0x66F260
#define CListWnd__Draw                                             0x670200
#define CListWnd__DrawColumnSeparators                             0x670070
#define CListWnd__DrawHeader                                       0x66E1E0
#define CListWnd__DrawItem                                         0x66F970
#define CListWnd__DrawLine                                         0x66FD20
#define CListWnd__DrawSeparator                                    0x670110
#define CListWnd__EnsureVisible                                    0x66E8E0
#define CListWnd__ExtendSel                                        0x66F8A0
#define CListWnd__GetColumnMinWidth                                0x66DDB0
#define CListWnd__GetColumnWidth                                   0x66DCF0
#define CListWnd__GetCurSel                                        0x66D7C0
#define CListWnd__GetHeaderRect                                    0x66D8C0
#define CListWnd__GetItemAtPoint                                   0x66EBC0
#define CListWnd__GetItemAtPoint1                                  0x66EC30
#define CListWnd__GetItemData                                      0x66DAA0
#define CListWnd__GetItemHeight                                    0x66E640
#define CListWnd__GetItemIcon                                      0x66DC30
#define CListWnd__GetItemRect                                      0x66E9B0
#define CListWnd__GetItemText                                      0x66DAE0
#define CListWnd__GetSelList                                       0x671860
#define CListWnd__GetSeparatorRect                                 0x66F1A0
#define CListWnd__RemoveLine                                       0x671E40
#define CListWnd__SetColors                                        0x66D820
#define CListWnd__SetColumnJustification                           0x66DE10
#define CListWnd__SetColumnWidth                                   0x66DD70
#define CListWnd__SetCurSel                                        0x66D800
#define CListWnd__SetItemColor                                     0x671130
#define CListWnd__SetItemData                                      0x66E0B0
#define CListWnd__SetItemText                                      0x6710B0
#define CListWnd__ShiftColumnSeparator                             0x66F810
#define CListWnd__Sort                                             0x671EC0
#define CListWnd__ToggleSel                                        0x66DF80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5C1300

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C2DE0
#define CMerchantWnd__RequestBuyItem                               0x5C4120
#define CMerchantWnd__RequestSellItem                              0x5C3030
#define CMerchantWnd__SelectBuySellSlot                            0x5C3E60

// CObfuscator
#define CObfuscator__doit                                          0x6381A0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x687A40

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x677CF0
#define CSidlScreenWnd__CalculateVSBRange                          0x677C30
#define CSidlScreenWnd__ConvertToRes                               0x696D90
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6795F0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x67A440
#define CSidlScreenWnd__CSidlScreenWnd2                            0x67A4F0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x679E90
#define CSidlScreenWnd__DrawSidlPiece                              0x6792D0
#define CSidlScreenWnd__EnableIniStorage                           0x678DF0
#define CSidlScreenWnd__GetSidlPiece                               0x6794D0
#define CSidlScreenWnd__Init1                                      0x67A2B0
#define CSidlScreenWnd__LoadIniInfo                                0x6796A0
#define CSidlScreenWnd__LoadIniListWnd                             0x678F30
#define CSidlScreenWnd__LoadSidlScreen                             0x6790F0
#define CSidlScreenWnd__StoreIniInfo                               0x678A00
#define CSidlScreenWnd__WndNotification                            0x679230

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x51E4D0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x42B630
#define CSliderWnd__SetValue                                       0x697B60
#define CSliderWnd__SetNumTicks                                    0x698090

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5F38E0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x695060
#define CStmlWnd__CalculateVSBRange                                0x68D420
#define CStmlWnd__CanBreakAtCharacter                              0x68D560
#define CStmlWnd__FastForwardToEndOfTag                            0x68E070
#define CStmlWnd__GetNextTagPiece                                  0x68DF90
#define CStmlWnd__GetSTMLText                                      0x565FA0
#define CStmlWnd__GetThisChar                                      0x6B5460
#define CStmlWnd__GetVisiableText                                  0x68F2A0
#define CStmlWnd__InitializeWindowVariables                        0x6913F0
#define CStmlWnd__MakeStmlColorTag                                 0x68CAC0
#define CStmlWnd__MakeWndNotificationTag                           0x68CB60
#define CStmlWnd__StripFirstSTMLLines                              0x694DF0
#define CStmlWnd__UpdateHistoryString                              0x68FAF0
#define CStmlWnd__SetSTMLText                                      0x691510
#define CStmlWnd__ForceParseNow                                    0x6954c0


// CTabWnd 
#define CTabWnd__Draw                                              0x698EB0
#define CTabWnd__DrawCurrentPage                                   0x698830
#define CTabWnd__DrawTab                                           0x698610
#define CTabWnd__GetCurrentPage                                    0x698B30
#define CTabWnd__GetPageClientRect                                 0x6982E0
#define CTabWnd__GetPageFromTabIndex                               0x698540
#define CTabWnd__GetPageInnerRect                                  0x698340
#define CTabWnd__GetTabInnerRect                                   0x6984C0
#define CTabWnd__GetTabRect                                        0x6983D0
#define CTabWnd__IndexInBounds                                     0x6985DD
#define CTabWnd__InsertPage                                        0x6990D0
#define CTabWnd__SetPage                                           0x698B70
#define CTabWnd__SetPageRect                                       0x698DE0
#define CTabWnd__UpdatePage                                        0x699050

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x414000

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x67A850

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x69E440

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x66D530

// CXRect 
#define CXRect__CenterPoint                                        0x543E80

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412340
#define CXStr__CXStr1                                              0x666C50
#define CXStr__CXStr3                                              0x661DE0
#define CXStr__dCXStr                                              0x5EA960
#define CXStr__operator_equal1                                     0x661FA0
#define CXStr__operator_plus_equal1                                0x662E90

// CXWnd 
#define CXWnd__BringToTop                                          0x672EC0
#define CXWnd__Center                                              0x676A80
#define CXWnd__ClrFocus                                            0x672BB0
#define CXWnd__DoAllDrawing                                        0x677510
#define CXWnd__DrawChildren                                        0x677640
#define CXWnd__DrawColoredRect                                     0x673160
#define CXWnd__DrawTooltip                                         0x677430
#define CXWnd__DrawTooltipAtPoint                                  0x676860
#define CXWnd__GetBorderFrame                                      0x673630
#define CXWnd__GetChildWndAt                                       0x676300
#define CXWnd__GetClientClipRect                                   0x673560
#define CXWnd__GetFirstChildWnd                                    0x672F60
#define CXWnd__GetNextChildWnd                                     0x6762C0
#define CXWnd__GetNextSib                                          0x672F80
#define CXWnd__GetScreenClipRect                                   0x676CA0
#define CXWnd__GetScreenRect                                       0x6737E0
#define CXWnd__GetTooltipRect                                      0x673390
#define CXWnd__GetWindowTextA                                      0x537AA0
#define CXWnd__IsActive                                            0x67B950
#define CXWnd__IsDescendantOf                                      0x6735E0
#define CXWnd__IsReallyVisible                                     0x6762A0
#define CXWnd__IsType                                              0x699F90
#define CXWnd__Move                                                0x675D60
#define CXWnd__Move1                                               0x675E00
#define CXWnd__ProcessTransition                                   0x672E90
#define CXWnd__Refade                                              0x672C60
#define CXWnd__Resize                                              0x6738B0
#define CXWnd__Right                                               0x676BE0
#define CXWnd__SetFirstChildPointer                                0x673AB0
#define CXWnd__SetFocus                                            0x674DE0
#define CXWnd__SetKeyTooltip                                       0x673B10
#define CXWnd__SetMouseOver                                        0x673AE0
#define CXWnd__SetNextSibPointer                                   0x673AD0
#define CXWnd__StartFade                                           0x672EE0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x67CD90
#define CXWndManager__DrawWindows                                  0x67C9D0
#define CXWndManager__GetFirstChildWnd                             0x67C2E0
#define CXWndManager__GetKeyboardFlags                             0x67B610
#define CXWndManager__HandleKeyboardMsg                            0x67BB40
#define CXWndManager__RemoveWnd                                    0x67BA60

// CDBStr
#define CDBStr__GetString                                          0x45C6B0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6C13D0
#define EQ_Character__CastSpell                                    0x425080
#define EQ_Character__Cur_HP                                       0x431A40
#define EQ_Character__GetAACastingTimeModifier                     0x41F930
#define EQ_Character__GetCharInfo2                                 0x643420
#define EQ_Character__GetFocusCastingTimeModifier                  0x41B5C0
#define EQ_Character__GetFocusRangeModifier                        0x41B6F0
#define EQ_Character__Max_Endurance                                0x42CDD0
#define EQ_Character__Max_HP                                       0x42CC50
#define EQ_Character__Max_Mana                                     0x502BF0
#define EQ_Character__doCombatAbility                              0x501A30
#define EQ_Character__UseSkill                                     0x437B50
#define EQ_Character__GetConLevel                                  0x4FEB90

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F27D0
#define EQ_Item__GetItemLinkHash                                   0x637850
#define EQ_Item__IsStackable                                       0x62E700

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x474CB0
#define EQ_LoadingS__Array                                         0x76C7D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x505DB0
#define EQ_PC__GetAltAbilityIndex                                  0x63C520
#define EQ_PC__GetCombatAbility                                    0x63C5B0
#define EQ_PC__GetCombatAbilityTimer                               0x63C660
#define EQ_PC__GetItemTimerValue                                   0x500970
#define EQ_PC__HasLoreItem                                         0x504210

// EQItemList 
#define EQItemList__dEQItemList                                    0x49DB20
#define EQItemList__EQItemList                                     0x49DA70

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45C070

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50AC80
#define EQPlayer__dEQPlayer                                        0x50F440
#define EQPlayer__DoAttack                                         0x51B040
#define EQPlayer__EQPlayer                                         0x5120D0
#define EQPlayer__SetNameSpriteState                               0x50D3B0
#define EQPlayer__SetNameSpriteTint                                0x50ACF0
#define EQPlayer__IsBodyType_j                                     0x6C0DB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x512FF0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F43D0
#define KeypressHandler__AttachKeyToEqCommand                      0x4F4410
#define KeypressHandler__ClearCommandStateArray                    0x4F41E0
#define KeypressHandler__HandleKeyDown                             0x4F2DC0
#define KeypressHandler__HandleKeyUp                               0x4F30C0
#define KeypressHandler__SaveKeymapping                            0x4F42B0

// MapViewMap 
#define MapViewMap__Clear                                          0x5BD310
#define MapViewMap__SaveEx                                         0x5BDCE0

#define OtherCharData__GetAltCurrency                              0x659360

// StringTable 
#define StringTable__getString                                     0x62E0E0
