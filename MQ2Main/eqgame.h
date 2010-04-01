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
#define __ExpectedVersionDate                                     "Dec 12 2006"
#define __ExpectedVersionTime                                     "10:48:48"
#define __ActualVersionDate                                        0x6C3554
#define __ActualVersionTime                                        0x6C3560

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4E0C90
#define __MemChecker1                                              0x5ED1E0
#define __MemChecker2                                              0x510000
#define __MemChecker3                                              0x5100B0
#define __MemChecker4                                              0x5E8480
#define __EncryptPad0                                              0x716768
#define __EncryptPad1                                              0x71FE08
#define __EncryptPad2                                              0x718CA8
#define __EncryptPad3                                              0x7190A8
#define __EncryptPad4                                              0x71F600

// Direct Input
#define DI8__Main                                                  0x90A0EC
#define DI8__Keyboard                                              0x90A0F0
#define DI8__Mouse                                                 0x90A0F4
#define __AltTimerReady                                            0x8A631A
#define __Attack                                                   0x90397E
#define __Autofire                                                 0x90397F
#define __BindList                                                 0x711A18
#define __Clicks                                                   0x8A546C
#define __CommandList                                              0x712208
#define __CurrentMapLabel                                          0x913190
#define __CurrentSocial                                            0x70E4C4
#define __DoAbilityAvailable                                       0x8A62B4
#define __DoAbilityList                                            0x8DB4C4
#define __DrawHandler                                              0x91F5FC
#define __GroupCount                                               0x885BC8
#define __GroupLeader                                              0x885D24
#define __Guilds                                                   0x8876B0
#define __gWorld                                                   0x887620
#define __HotkeyPage                                               0x9028B0
#define __HWnd                                                     0x90A094
#define __InChatMode                                               0x8A53A8
#define __LastTell                                                 0x8A6BCC
#define __Mouse                                                    0x90A0F8
#define __MouseLook                                                0x8A543A
#define __NetStatusToggle                                          0x8A543C
#define __PCNames                                                  0x8A6624
#define __RangeAttackReady                                         0x8A6318
#define __RunWalkState                                             0x8A53AC
#define __ScreenMode                                               0x7D56B0
#define __ScreenX                                                  0x8A5370
#define __ScreenY                                                  0x8A5374
#define __ServerHost                                               0x885B1C
#define __ServerName                                               0x8DB484
#define __ShowNames                                                0x8A6500
#define __Socials                                                  0x8DB584


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x89F300
#define instEQZoneInfo                                             0x8A55D8
#define instKeypressHandler                                        0x903A50
#define pinstActiveBanker                                          0x887690
#define pinstActiveCorpse                                          0x887694
#define pinstActiveGMaster                                         0x887698
#define pinstActiveMerchant                                        0x88768C
#define pinstAltAdvManager                                         0x7D6380
#define pinstAuraInfo                                              0x724FD0
#define pinstBandageTarget                                         0x887678
#define pinstCamActor                                              0x7D5E74
#define pinstCDBStr                                                0x7D5540
#define pinstCDisplay                                              0x8876A0
#define pinstCEverQuest                                            0x90A260
#define pinstCharData                                              0x887660
#define pinstCharSpawn                                             0x887684
#define pinstControlledMissile                                     0x88765C
#define pinstControlledPlayer                                      0x887684
#define pinstCSidlManager                                          0x91EE4C
#define pinstCXWndManager                                          0x91EE44
#define instDynamicZone                                            0x8A4DC0
#define pinstDZMember                                              0x8A4ED0
#define pinstDZTimerInfo                                           0x8A4ED4
#define pinstEQItemList                                            0x887644
#define instEQMisc                                                 0x7D54F8
#define pinstEQSoundManager                                        0x7D63A4
#define instExpeditionLeader                                       0x8A4E0A
#define instExpeditionName                                         0x8A4E4A
#define instGroup                                                  0x885BC8
#define pinstGroup                                                 0x885BC4
#define pinstImeManager                                            0x91EE50
#define pinstLocalPlayer                                           0x887670
#define pinstModelPlayer                                           0x88769C
#define pinstPCData                                                0x887660
#define pinstSelectedItem                                          0x912FE8
#define pinstSkillMgr                                              0x907138
#define pinstSpawnManager                                          0x9070B4
#define pinstSpellManager                                          0x90713C
#define pinstSpellSets                                             0x9028B4
#define pinstStringTable                                           0x887630
#define pinstSwitchManager                                         0x885818
#define pinstTarget                                                0x887688
#define pinstTargetObject                                          0x887664
#define pinstTargetSwitch                                          0x887668
#define pinstTaskMember                                            0x7D54DC
#define pinstTrackTarget                                           0x88767C
#define pinstTradeTarget                                           0x88766C
#define instTributeActive                                          0x7D551D
#define pinstViewActor                                             0x7D5E70
#define pinstWorldData                                             0x887640


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x723508
#define pinstCAudioTriggersWindow                                  0x7234EC
#define pinstCCharacterSelect                                      0x7D5D80
#define pinstCFacePick                                             0x7D5D38
#define pinstCNoteWnd                                              0x7D5D3C
#define pinstCBookWnd                                              0x7D5D40
#define pinstCPetInfoWnd                                           0x7D5D44
#define pinstCTrainWnd                                             0x7D5D48
#define pinstCSkillsWnd                                            0x7D5D4C
#define pinstCSkillsSelectWnd                                      0x7D5D50
#define pinstCCombatSkillSelectWnd                                 0x7D5D54
#define pinstCFriendsWnd                                           0x7D5D58
#define pinstCAuraWnd                                              0x7D5D5C
#define pinstCRespawnWnd                                           0x7D5D60
#define pinstCBandolierWnd                                         0x7D5D64
#define pinstCPotionBeltWnd                                        0x7D5D68
#define pinstCAAWnd                                                0x7D5D6C
#define pinstCGroupSearchFiltersWnd                                0x7D5D70
#define pinstCLoadskinWnd                                          0x7D5D74
#define pinstCAlarmWnd                                             0x7D5D78
#define pinstCMusicPlayerWnd                                       0x7D5D7C
#define pinstCMailWnd                                              0x7D5D84
#define pinstCMailCompositionWnd                                   0x7D5D88
#define pinstCMailAddressBookWnd                                   0x7D5D8C
#define pinstCRaidWnd                                              0x7D5D94
#define pinstCRaidOptionsWnd                                       0x7D5D98
#define pinstCBreathWnd                                            0x7D5D9C
#define pinstCMapViewWnd                                           0x7D5DA0
#define pinstCMapToolbarWnd                                        0x7D5DA4
#define pinstCEditLabelWnd                                         0x7D5DA8
#define pinstCTargetWnd                                            0x7D5DAC
#define pinstCColorPickerWnd                                       0x7D5DB0
#define pinstCPlayerWnd                                            0x7D5DB4
#define pinstCOptionsWnd                                           0x7D5DB8
#define pinstCBuffWindowNORMAL                                     0x7D5DBC
#define pinstCBuffWindowSHORT                                      0x7D5DC0
#define pinstCharacterCreation                                     0x7D5DC4
#define pinstCCursorAttachment                                     0x7D5DC8
#define pinstCCastingWnd                                           0x7D5DCC
#define pinstCCastSpellWnd                                         0x7D5DD0
#define pinstCSpellBookWnd                                         0x7D5DD4
#define pinstCInventoryWnd                                         0x7D5DD8
#define pinstCBankWnd                                              0x7D5DDC
#define pinstCQuantityWnd                                          0x7D5DE0
#define pinstCLootWnd                                              0x7D5DE4
#define pinstCActionsWnd                                           0x7D5DE8
#define pinstCCombatAbilityWnd                                     0x7D5DEC
#define pinstCMerchantWnd                                          0x7D5DF0
#define pinstCTradeWnd                                             0x7D5DF4
#define pinstCSelectorWnd                                          0x7D5DF8
#define pinstCBazaarWnd                                            0x7D5DFC
#define pinstCBazaarSearchWnd                                      0x7D5E00
#define pinstCGiveWnd                                              0x7D5E04
#define pinstCTrackingWnd                                          0x7D5E08
#define pinstCInspectWnd                                           0x7D5E0C
#define pinstCSocialEditWnd                                        0x7D5E10
#define pinstCFeedbackWnd                                          0x7D5E14
#define pinstCBugReportWnd                                         0x7D5E18
#define pinstCVideoModesWnd                                        0x7D5E1C
#define pinstCTextEntryWnd                                         0x7D5E24
#define pinstCFileSelectionWnd                                     0x7D5E28
#define pinstCCompassWnd                                           0x7D5E2C
#define pinstCPlayerNotesWnd                                       0x7D5E30
#define pinstCGemsGameWnd                                          0x7D5E34
#define pinstCTimeLeftWnd                                          0x7D5E38
#define pinstCPetitionQWnd                                         0x7D5E3C
#define pinstCSoulmarkWnd                                          0x7D5E40
#define pinstCStoryWnd                                             0x7D5E44
#define pinstCJournalTextWnd                                       0x7D5E48
#define pinstCJournalCatWnd                                        0x7D5E4C
#define pinstCBodyTintWnd                                          0x7D5E50
#define pinstCServerListWnd                                        0x7D5E54
#define pinstCAvaZoneWnd                                           0x7D5E58
#define pinstCBlockedBuffWnd                                       0x7D5E5C
#define pinstCBlockedPetBuffWnd                                    0x7D5E60
#define pinstCInvSlotMgr                                           0x7D5E64
#define pinstCContainerMgr                                         0x7D5E68
#define pinstCAdventureLeaderboardWnd                              0x91282C
#define pinstCAdventureRequestWnd                                  0x912848
#define pinstCAltStorageWnd                                        0x9128A8
#define pinstCAdventureStatsWnd                                    0x912864
#define pinstCBarterMerchantWnd                                    0x912A5C
#define pinstCBarterSearchWnd                                      0x912A78
#define pinstCBarterWnd                                            0x912A94
#define pinstCChatManager                                          0x912C74
#define pinstCDynamicZoneWnd                                       0x912D50
#define pinstCEQMainWnd                                            0x912DC0
#define pinstCFindLocationWnd                                      0x912E3C
#define pinstCGroupSearchWnd                                       0x912F10
#define pinstCGroupWnd                                             0x912F08
#define pinstCGuildBankWnd                                         0x912F24
#define pinstCGuildMgmtWnd                                         0x912F40
#define pinstCGuildTributeMasterWnd                                0x912F5C
#define pinstCHotButtonWnd                                         0x912F78
#define pinstCHotButtonWnd1                                        0x912F78
#define pinstCHotButtonWnd2                                        0x912F7C
#define pinstCHotButtonWnd3                                        0x912F80
#define pinstCHotButtonWnd4                                        0x912F84
#define pinstCItemDisplayManager                                   0x91301C
#define pinstCItemExpTransferWnd                                   0x91303C
#define pinstCLeadershipWnd                                        0x9130B8
#define pinstCLFGuildWnd                                           0x9130D4
#define pinstCMIZoneSelectWnd                                      0x9131F8
#define pinstCAdventureMerchantWnd                                 0x9132D4
#define pinstCConfirmationDialog                                   0x9132F0
#define pinstCPopupWndManager                                      0x9132F0
#define pinstCProgressionSelectionWnd                              0x913324
#define pinstCPvPLeaderboardWnd                                    0x913340
#define pinstCPvPStatsWnd                                          0x91335C
#define pinstCSystemInfoDialogBox                                  0x913CDC
#define pinstCTargetOfTargetWnd                                    0x913CF8
#define pinstCTaskSelectWnd                                        0x913D2C
#define pinstCTaskTemplateSelectWnd                                0x913D48
#define pinstCTaskWnd                                              0x913D64
#define pinstCTicketCommentWnd                                     0x913D98
#define pinstCHelpWnd                                              0x913DB4
#define pinstCTipWndOFDAY                                          0x913DE8
#define pinstCTipWndCONTEXT                                        0x913DEC
#define pinstCTitleWnd                                             0x913E08
#define pinstCTradeskillWnd                                        0x913E4C
#define pinstCTributeBenefitWnd                                    0x913E98
#define pinstCTributeMasterWnd                                     0x913EB4
#define pinstCContextMenuManager                                   0x91EF0C
#define pinstCVoiceMacroWnd                                        0x907204


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4A5720
#define __ConvertItemTags                                          0x49A3F0
#define __ExecuteCmd                                               0x48BC10
#define __get_melee_range                                          0x490E00
#define __GetGaugeValueFromEQ                                      0x5BF5B0
#define __GetLabelFromEQ                                           0x5BFCE0
#define __NewUIINI                                                 0x5BF1B0
#define __ProcessGameEvents                                        0x4CF6A0
#define __SendMessage                                              0x4B2160
#define CrashDetected                                              0x50FCB0
#define DrawNetStatus                                              0x4E39A0
#define Util__FastTime                                             0x5ED8C0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x46C700
#define AltAdvManager__IsAbilityReady                              0x46C740
#define AltAdvManager__GetAltAbility                               0x46C8C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5240D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x52D4D0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x633480

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x540E90
#define CChatManager__InitContextMenu                              0x541620

// CChatService
#define CChatService__GetNumberOfFriends                           0x6109D0
#define CChatService__GetFriendName                                0x6109E0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x545750

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6294C0
#define CComboWnd__Draw                                            0x629670
#define CComboWnd__GetCurChoice                                    0x629470
#define CComboWnd__GetListRect                                     0x629940
#define CComboWnd__GetTextRect                                     0x6294F0
#define CComboWnd__InsertChoice                                    0x6299B0
#define CComboWnd__SetColors                                       0x629400
#define CComboWnd__SetChoice                                       0x629430

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x54BD00
#define CContainerWnd__vftable                                     0x6C96E8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45BE10
#define CDisplay__GetClickedActor                                  0x459750
#define CDisplay__GetUserDefinedColor                              0x458BC0
#define CDisplay__GetWorldFilePath                                 0x458170
#define CDisplay__ReloadUI                                         0x467BD0
#define CDisplay__WriteTextHD2                                     0x45D620

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x51E320
#define CEditBaseWnd__SetSel                                       0x64BA70

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6491C0
#define CEditWnd__GetCharIndexPt                                   0x649FF0
#define CEditWnd__GetDisplayString                                 0x649350
#define CEditWnd__GetHorzOffset                                    0x6495D0
#define CEditWnd__GetLineForPrintableChar                          0x649AB0
#define CEditWnd__GetSelStartPt                                    0x64A240
#define CEditWnd__GetSTMLSafeText                                  0x649770
#define CEditWnd__PointFromPrintableChar                           0x649BC0
#define CEditWnd__SelectableCharFromPoint                          0x649D40
#define CEditWnd__SetEditable                                      0x649740

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4B6250
#define CEverQuest__DropHeldItemOnGround                           0x4BABF0
#define CEverQuest__dsp_chat                                       0x4BB7D0
#define CEverQuest__EnterZone                                      0x4CE290
#define CEverQuest__GetBodyTypeDesc                                0x4B39B0
#define CEverQuest__GetClassDesc                                   0x4B3110
#define CEverQuest__GetClassThreeLetterCode                        0x4B3710
#define CEverQuest__GetDeityDesc                                   0x4B4000
#define CEverQuest__GetLangDesc                                    0x4B3D20
#define CEverQuest__GetRaceDesc                                    0x4B3FD0
#define CEverQuest__InterpretCmd                                   0x4BC0E0
#define CEverQuest__LeftClickedOnPlayer                            0x4CCF60
#define CEverQuest__RightClickedOnPlayer                           0x4CD320
#define CEverQuest__SetGameState                                   0x4B6320

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x555250
#define CGaugeWnd__CalcLinesFillRect                               0x5552C0
#define CGaugeWnd__Draw                                            0x555650

// CGuild
#define CGuild__FindMemberByName                                   0x415900

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5696C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x570780
#define CInvSlotMgr__MoveItem                                      0x570920

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x571810

// CInvSLot
#define CInvSlot__SliderComplete                                   0x56F7C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x578690
#define CItemDisplayWnd__SetSpell                                  0x5BD5E0

// CLabel 
#define CLabel__Draw                                               0x57DB90

// CListWnd 
#define CListWnd__AddColumn                                        0x629210
#define CListWnd__AddColumn1                                       0x628D50
#define CListWnd__AddLine                                          0x6288E0
#define CListWnd__AddString                                        0x628AB0
#define CListWnd__CalculateFirstVisibleLine                        0x625BD0
#define CListWnd__CalculateVSBRange                                0x627870
#define CListWnd__ClearAllSel                                      0x625320
#define CListWnd__CloseAndUpdateEditWindow                         0x626210
#define CListWnd__Compare                                          0x6265C0
#define CListWnd__Draw                                             0x627560
#define CListWnd__DrawColumnSeparators                             0x6273D0
#define CListWnd__DrawHeader                                       0x6254F0
#define CListWnd__DrawItem                                         0x626CD0
#define CListWnd__DrawLine                                         0x627080
#define CListWnd__DrawSeparator                                    0x627080
#define CListWnd__EnsureVisible                                    0x625C20
#define CListWnd__ExtendSel                                        0x626C00
#define CListWnd__GetColumnMinWidth                                0x6250C0
#define CListWnd__GetColumnWidth                                   0x625000
#define CListWnd__GetCurSel                                        0x624AE0
#define CListWnd__GetHeaderRect                                    0x624BD0
#define CListWnd__GetItemAtPoint                                   0x625F20
#define CListWnd__GetItemAtPoint1                                  0x625F90
#define CListWnd__GetItemData                                      0x624DB0
#define CListWnd__GetItemHeight                                    0x625960
#define CListWnd__GetItemIcon                                      0x624F40
#define CListWnd__GetItemRect                                      0x625D00
#define CListWnd__GetItemText                                      0x624DF0
#define CListWnd__GetSelList                                       0x628C30
#define CListWnd__GetSeparatorRect                                 0x626500
#define CListWnd__RemoveLine                                       0x628BE0
#define CListWnd__SetColors                                        0x624B40
#define CListWnd__SetColumnJustification                           0x625120
#define CListWnd__SetColumnWidth                                   0x625080
#define CListWnd__SetCurSel                                        0x624B20
#define CListWnd__SetItemColor                                     0x6284B0
#define CListWnd__SetItemData                                      0x6253C0
#define CListWnd__SetItemText                                      0x628430
#define CListWnd__ShiftColumnSeparator                             0x626B70
#define CListWnd__Sort                                             0x629240
#define CListWnd__ToggleSel                                        0x625290

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x590160

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x591B30
#define CMerchantWnd__RequestBuyItem                               0x592CB0
#define CMerchantWnd__RequestSellItem                              0x591D90
#define CMerchantWnd__SelectBuySellSlot                            0x5929B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x637FA0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x51FCA0
#define CSidlScreenWnd__CalculateVSBRange                          0x62E990
#define CSidlScreenWnd__ConvertToRes                               0x62F0E0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x62F8B0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x630BB0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x630C60
#define CSidlScreenWnd__dCSidlScreenWnd                            0x630460
#define CSidlScreenWnd__DrawSidlPiece                              0x62F5D0
#define CSidlScreenWnd__EnableIniStorage                           0x62F090
#define CSidlScreenWnd__GetSidlPiece                               0x62F790
#define CSidlScreenWnd__Init1                                      0x6309C0
#define CSidlScreenWnd__LoadIniInfo                                0x62F960
#define CSidlScreenWnd__LoadIniListWnd                             0x62F240
#define CSidlScreenWnd__LoadSidlScreen                             0x62F400
#define CSidlScreenWnd__StoreIniInfo                               0x62EBD0
#define CSidlScreenWnd__WndNotification                            0x62F530

// CSkillMgr
#define CSkillMgr__GetSkillCap                                    0x504AB0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x64D840
#define CSliderWnd__SetValue                                       0x64D940
#define CSliderWnd__SetNumTicks                                    0x64DE80

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5BC340

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x642410
#define CStmlWnd__CalculateHSBRange                                0x63A7A0
#define CStmlWnd__CalculateVSBRange                                0x63A740
#define CStmlWnd__CanBreakAtCharacter                              0x63A8E0
#define CStmlWnd__CanGoBackward                                    0x63A990
#define CStmlWnd__FastForwardToEndOfTag                            0x63B3E0
#define CStmlWnd__GetNextTagPiece                                  0x63B300
#define CStmlWnd__GetSTMLText                                      0x5456F0
#define CStmlWnd__GetThisChar                                      0x669900
#define CStmlWnd__GetVisiableText                                  0x63C620
#define CStmlWnd__InitializeWindowVariables                        0x63E770
#define CStmlWnd__MakeStmlColorTag                                 0x639E20
#define CStmlWnd__MakeWndNotificationTag                           0x639EC0
#define CStmlWnd__StripFirstSTMLLines                              0x642190
#define CStmlWnd__UpdateHistoryString                              0x63CE80

// CTabWnd 
#define CTabWnd__Draw                                              0x64D0E0
#define CTabWnd__DrawCurrentPage                                   0x64CAD0
#define CTabWnd__DrawTab                                           0x64C8B0
#define CTabWnd__GetCurrentPage                                    0x64CD50
#define CTabWnd__GetPageClientRect                                 0x64C580
#define CTabWnd__GetPageFromTabIndex                               0x64C7E0
#define CTabWnd__GetPageInnerRect                                  0x64C5E0
#define CTabWnd__GetTabInnerRect                                   0x64C760
#define CTabWnd__GetTabRect                                        0x64C670
#define CTabWnd__IndexInBounds                                     0x64C87D
#define CTabWnd__InsertPage                                        0x64D300
#define CTabWnd__SetPage                                           0x64CD90
#define CTabWnd__SetPageRect                                       0x64D010
#define CTabWnd__UpdatePage                                        0x64D280

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x412640

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x630FC0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x653D10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x624870

// CXRect 
#define CXRect__CenterPoint                                        0x523890

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4121E0
#define CXStr__CXStr1                                              0x61DF80
#define CXStr__CXStr3                                              0x5EEFC0
#define CXStr__dCXStr                                              0x502490
#define CXStr__operator_equal1                                     0x5EF180
#define CXStr__operator_plus_equal1                                0x5F0070

// CXWnd 
#define CXWnd__BringToTop                                          0x62A1A0
#define CXWnd__Center                                              0x62D760
#define CXWnd__ClrFocus                                            0x629ED0
#define CXWnd__DoAllDrawing                                        0x62E410
#define CXWnd__DrawChildren                                        0x62E540
#define CXWnd__DrawColoredRect                                     0x62A400
#define CXWnd__DrawTooltip                                         0x62E340
#define CXWnd__DrawTooltipAtPoint                                  0x62D5C0
#define CXWnd__GetBorderFrame                                      0x62A880
#define CXWnd__GetChildWndAt                                       0x62D0E0
#define CXWnd__GetClientClipRect                                   0x62A7C0
#define CXWnd__GetFirstChildWnd                                    0x62A230
#define CXWnd__GetNextChildWnd                                     0x62D0A0
#define CXWnd__GetNextSib                                          0x62A250
#define CXWnd__GetScreenClipRect                                   0x62D980
#define CXWnd__GetScreenRect                                       0x62AA30
#define CXWnd__GetTooltipRect                                      0x62A640
#define CXWnd__GetWindowTextA                                      0x5174C0
#define CXWnd__IsActive                                            0x6443B0
#define CXWnd__IsDescendantOf                                      0x62A830
#define CXWnd__IsReallyVisible                                     0x62D080
#define CXWnd__IsType                                              0x64EA50
#define CXWnd__Move                                                0x62CBC0
#define CXWnd__Move1                                               0x62CC60
#define CXWnd__ProcessTransition                                   0x62A160
#define CXWnd__Refade                                              0x629F70
#define CXWnd__Resize                                              0x62DAC0
#define CXWnd__Right                                               0x62D8D0
#define CXWnd__SetFirstChildPointer                                0x62AC80
#define CXWnd__SetFocus                                            0x62BF30
#define CXWnd__SetKeyTooltip                                       0x62ACF0
#define CXWnd__SetMouseOver                                        0x62ACC0
#define CXWnd__SetNextSibPointer                                   0x62ACA0
#define CXWnd__StartFade                                           0x62A1C0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x645880
#define CXWndManager__DrawWindows                                  0x645550
#define CXWndManager__GetFirstChildWnd                             0x644DF0
#define CXWndManager__GetKeyboardFlags                             0x6440A0
#define CXWndManager__HandleKeyboardMsg                            0x644650
#define CXWndManager__RemoveWnd                                    0x644570

// CDBStr
#define CDBStr__GetString                                          0x455720

// EQ_Character 
#define EQ_Character__CastRay                                      0x674F30
#define EQ_Character__CastSpell                                    0x421A50
#define EQ_Character__Cur_HP                                       0x428D90
#define EQ_Character__GetAACastingTimeModifier                     0x41C940
#define EQ_Character__GetCharInfo2                                 0x5F8F70
#define EQ_Character__GetFocusCastingTimeModifier                  0x418FE0
#define EQ_Character__GetFocusRangeModifier                        0x419110
#define EQ_Character__Max_Endurance                                0x427C40
#define EQ_Character__Max_HP                                       0x427AF0
#define EQ_Character__Max_Mana                                     0x4E8970
#define EQ_Character__doCombatAbility                              0x4E77F0
#define EQ_Character__UseSkill                                     0x434000
#define EQ_Character__GetConLevel                                  0x4E4D50

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4DA6C0
#define EQ_Item__GetItemLinkHash                                   0x5F8130
#define EQ_Item__IsStackable                                       0x5F43E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x46D7B0
#define EQ_LoadingS__Array                                         0x70FF30

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4EB7F0
#define EQ_PC__GetAltAbilityIndex                                  0x5FDDF0
#define EQ_PC__GetCombatAbility                                    0x5FDF30
#define EQ_PC__GetCombatAbilityTimer                               0x5FDFE0
#define EQ_PC__GetItemTimerValue                                   0x4E6AF0
#define EQ_PC__HasLoreItem                                         0x4E9E30

// EQItemList 
#define EQItemList__dEQItemList                                    0x48F5A0
#define EQItemList__EQItemList                                     0x48F4F0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x455190

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4F0110
#define EQPlayer__dEQPlayer                                        0x4F44E0
#define EQPlayer__DoAttack                                         0x4FF7E0
#define EQPlayer__EQPlayer                                         0x4F6BB0
#define EQPlayer__SetNameSpriteState                               0x4F2710
#define EQPlayer__SetNameSpriteTint                                0x4F0180
#define EQPlayer__IsBodyType_j                                     0x674CE0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4F79B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4DC4B0
#define KeypressHandler__AttachKeyToEqCommand                      0x4DC4F0
#define KeypressHandler__ClearCommandStateArray                    0x4DC2C0
#define KeypressHandler__HandleKeyDown                             0x4DAEF0
#define KeypressHandler__HandleKeyUp                               0x4DB1F0
#define KeypressHandler__SaveKeymapping                            0x4DC390

// MapViewMap 
#define MapViewMap__Clear                                          0x58C1A0
#define MapViewMap__SaveEx                                         0x58CB70

// StringTable 
#define StringTable__getString                                     0x5F3C30
