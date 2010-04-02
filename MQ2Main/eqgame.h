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
#define __ExpectedVersionDate                                     "Jan 15 2007"
#define __ExpectedVersionTime                                     "11:12:58"
#define __ActualVersionDate                                        0x6C3554
#define __ActualVersionTime                                        0x6C3560

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4E0A30
#define __MemChecker1                                              0x5ECF80
#define __MemChecker2                                              0x50FE20
#define __MemChecker3                                              0x50FED0
#define __MemChecker4                                              0x5E80E0
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
#define pinstAuraMgr                                               0x724FD0
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
#define __CastRay                                                  0x4A5490
#define __ConvertItemTags                                          0x49A160
#define __ExecuteCmd                                               0x48B990
#define __get_melee_range                                          0x490B70
#define __GetGaugeValueFromEQ                                      0x5BF2F0
#define __GetLabelFromEQ                                           0x5BFA20
#define __NewUIINI                                                 0x5BEEF0
#define __ProcessGameEvents                                        0x4CF380
#define __SendMessage                                              0x4B1E80
#define CrashDetected                                              0x50FAD0
#define DrawNetStatus                                              0x4E3790
#define Util__FastTime                                             0x5ED660


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x46C5E0
#define AltAdvManager__IsAbilityReady                              0x46C620
#define AltAdvManager__GetAltAbility                               0x46C770

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x523DB0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x52D1B0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6334E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x540AD0
#define CChatManager__InitContextMenu                              0x541260

// CChatService
#define CChatService__GetNumberOfFriends                           0x610810
#define CChatService__GetFriendName                                0x610820

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x545390

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6294A0
#define CComboWnd__Draw                                            0x629650
#define CComboWnd__GetCurChoice                                    0x629450
#define CComboWnd__GetListRect                                     0x629920
#define CComboWnd__GetTextRect                                     0x6294D0
#define CComboWnd__InsertChoice                                    0x629990
#define CComboWnd__SetColors                                       0x6293E0
#define CComboWnd__SetChoice                                       0x629410

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x54B970
#define CContainerWnd__vftable                                     0x6C96E8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45BCF0
#define CDisplay__GetClickedActor                                  0x4595C0
#define CDisplay__GetUserDefinedColor                              0x458A30
#define CDisplay__GetWorldFilePath                                 0x457FE0
#define CDisplay__ReloadUI                                         0x467A80
#define CDisplay__WriteTextHD2                                     0x45D500

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x51E110
#define CEditBaseWnd__SetSel                                       0x64BA00

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x649150
#define CEditWnd__GetCharIndexPt                                   0x649F80
#define CEditWnd__GetDisplayString                                 0x6492E0
#define CEditWnd__GetHorzOffset                                    0x649560
#define CEditWnd__GetLineForPrintableChar                          0x649A40
#define CEditWnd__GetSelStartPt                                    0x64A1D0
#define CEditWnd__GetSTMLSafeText                                  0x649700
#define CEditWnd__PointFromPrintableChar                           0x649B50
#define CEditWnd__SelectableCharFromPoint                          0x649CD0
#define CEditWnd__SetEditable                                      0x6496D0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4B5F30
#define CEverQuest__DropHeldItemOnGround                           0x4BA8D0
#define CEverQuest__dsp_chat                                       0x4BB4B0
#define CEverQuest__EnterZone                                      0x4CDF70
#define CEverQuest__GetBodyTypeDesc                                0x4B3690
#define CEverQuest__GetClassDesc                                   0x4B2DF0
#define CEverQuest__GetClassThreeLetterCode                        0x4B33F0
#define CEverQuest__GetDeityDesc                                   0x4B3CE0
#define CEverQuest__GetLangDesc                                    0x4B3A00
#define CEverQuest__GetRaceDesc                                    0x4B3CB0
#define CEverQuest__InterpretCmd                                   0x4BBDC0
#define CEverQuest__LeftClickedOnPlayer                            0x4CCC40
#define CEverQuest__RightClickedOnPlayer                           0x4CD000
#define CEverQuest__SetGameState                                   0x4B6000

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x554E90
#define CGaugeWnd__CalcLinesFillRect                               0x554F00
#define CGaugeWnd__Draw                                            0x555290

// CGuild
#define CGuild__FindMemberByName                                   0x4156D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x569370

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x570430
#define CInvSlotMgr__MoveItem                                      0x5705D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5714C0

// CInvSLot
#define CInvSlot__SliderComplete                                   0x56F470

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5784B0
#define CItemDisplayWnd__SetSpell                                  0x5BD420

// CLabel 
#define CLabel__Draw                                               0x57D970

// CListWnd 
#define CListWnd__AddColumn                                        0x6291D0
#define CListWnd__AddColumn1                                       0x628D10
#define CListWnd__AddLine                                          0x6288A0
#define CListWnd__AddString                                        0x628A70
#define CListWnd__CalculateFirstVisibleLine                        0x625B90
#define CListWnd__CalculateVSBRange                                0x627830
#define CListWnd__ClearAllSel                                      0x6252E0
#define CListWnd__CloseAndUpdateEditWindow                         0x6261D0
#define CListWnd__Compare                                          0x626580
#define CListWnd__Draw                                             0x627520
#define CListWnd__DrawColumnSeparators                             0x627390
#define CListWnd__DrawHeader                                       0x6254B0
#define CListWnd__DrawItem                                         0x626C90
#define CListWnd__DrawLine                                         0x627040
#define CListWnd__DrawSeparator                                    0x627040
#define CListWnd__EnsureVisible                                    0x625BE0
#define CListWnd__ExtendSel                                        0x626BC0
#define CListWnd__GetColumnMinWidth                                0x625080
#define CListWnd__GetColumnWidth                                   0x624FC0
#define CListWnd__GetCurSel                                        0x624AA0
#define CListWnd__GetHeaderRect                                    0x624B90
#define CListWnd__GetItemAtPoint                                   0x625EE0
#define CListWnd__GetItemAtPoint1                                  0x625F50
#define CListWnd__GetItemData                                      0x624D70
#define CListWnd__GetItemHeight                                    0x625920
#define CListWnd__GetItemIcon                                      0x624F00
#define CListWnd__GetItemRect                                      0x625CC0
#define CListWnd__GetItemText                                      0x624DB0
#define CListWnd__GetSelList                                       0x628BF0
#define CListWnd__GetSeparatorRect                                 0x6264C0
#define CListWnd__RemoveLine                                       0x628BA0
#define CListWnd__SetColors                                        0x624B00
#define CListWnd__SetColumnJustification                           0x6250E0
#define CListWnd__SetColumnWidth                                   0x625040
#define CListWnd__SetCurSel                                        0x624AE0
#define CListWnd__SetItemColor                                     0x628470
#define CListWnd__SetItemData                                      0x625380
#define CListWnd__SetItemText                                      0x6283F0
#define CListWnd__ShiftColumnSeparator                             0x626B30
#define CListWnd__Sort                                             0x629200
#define CListWnd__ToggleSel                                        0x625250

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x58FF40

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x591910
#define CMerchantWnd__RequestBuyItem                               0x592A90
#define CMerchantWnd__RequestSellItem                              0x591B70
#define CMerchantWnd__SelectBuySellSlot                            0x592790

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x638030

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x62EA30
#define CSidlScreenWnd__CalculateVSBRange                          0x62E970
#define CSidlScreenWnd__ConvertToRes                               0x62F170
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x62F9F0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x630CC0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x630D70
#define CSidlScreenWnd__dCSidlScreenWnd                            0x630570
#define CSidlScreenWnd__DrawSidlPiece                              0x62F710
#define CSidlScreenWnd__EnableIniStorage                           0x62F120
#define CSidlScreenWnd__GetSidlPiece                               0x62F8D0
#define CSidlScreenWnd__Init1                                      0x630AD0
#define CSidlScreenWnd__LoadIniInfo                                0x62FAA0
#define CSidlScreenWnd__LoadIniListWnd                             0x62F2D0
#define CSidlScreenWnd__LoadSidlScreen                             0x62F540
#define CSidlScreenWnd__StoreIniInfo                               0x62EC60
#define CSidlScreenWnd__WndNotification                            0x62F670

// CSkillMgr
#define CSkillMgr__GetSkillCap                                    0x504880

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x64D880
#define CSliderWnd__SetValue                                       0x64D980
#define CSliderWnd__SetNumTicks                                    0x64DEC0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5BC180

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6424C0
#define CStmlWnd__CalculateHSBRange                                0x63A840
#define CStmlWnd__CalculateVSBRange                                0x63A7E0
#define CStmlWnd__CanBreakAtCharacter                              0x63A980
#define CStmlWnd__CanGoBackward                                    0x63AA40
#define CStmlWnd__FastForwardToEndOfTag                            0x63B490
#define CStmlWnd__GetNextTagPiece                                  0x63B3B0
#define CStmlWnd__GetSTMLText                                      0x545330
#define CStmlWnd__GetThisChar                                      0x669970
#define CStmlWnd__GetVisiableText                                  0x63C6D0
#define CStmlWnd__InitializeWindowVariables                        0x63E820
#define CStmlWnd__MakeStmlColorTag                                 0x639EE0
#define CStmlWnd__MakeWndNotificationTag                           0x639F80
#define CStmlWnd__StripFirstSTMLLines                              0x642240
#define CStmlWnd__UpdateHistoryString                              0x63CF30

// CTabWnd 
#define CTabWnd__Draw                                              0x64D120
#define CTabWnd__DrawCurrentPage                                   0x64CA60
#define CTabWnd__DrawTab                                           0x64C840
#define CTabWnd__GetCurrentPage                                    0x64CD90
#define CTabWnd__GetPageClientRect                                 0x64C510
#define CTabWnd__GetPageFromTabIndex                               0x64C770
#define CTabWnd__GetPageInnerRect                                  0x64C570
#define CTabWnd__GetTabInnerRect                                   0x64C6F0
#define CTabWnd__GetTabRect                                        0x64C600
#define CTabWnd__IndexInBounds                                     0x64C80D
#define CTabWnd__InsertPage                                        0x64D340
#define CTabWnd__SetPage                                           0x64CDD0
#define CTabWnd__SetPageRect                                       0x64D050
#define CTabWnd__UpdatePage                                        0x64D2C0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4124A0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6310D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x653D30

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x624830

// CXRect 
#define CXRect__CenterPoint                                        0x523570

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412040
#define CXStr__CXStr1                                              0x5001B0
#define CXStr__CXStr3                                              0x5EED60
#define CXStr__dCXStr                                              0x629350
#define CXStr__operator_equal1                                     0x5EEF20
#define CXStr__operator_plus_equal1                                0x5EFE10

// CXWnd 
#define CXWnd__BringToTop                                          0x62A180
#define CXWnd__Center                                              0x62D740
#define CXWnd__ClrFocus                                            0x629EB0
#define CXWnd__DoAllDrawing                                        0x62E3F0
#define CXWnd__DrawChildren                                        0x62E520
#define CXWnd__DrawColoredRect                                     0x62A3E0
#define CXWnd__DrawTooltip                                         0x62E320
#define CXWnd__DrawTooltipAtPoint                                  0x62D5A0
#define CXWnd__GetBorderFrame                                      0x62A860
#define CXWnd__GetChildWndAt                                       0x62D0C0
#define CXWnd__GetClientClipRect                                   0x62A7A0
#define CXWnd__GetFirstChildWnd                                    0x62A210
#define CXWnd__GetNextChildWnd                                     0x62D080
#define CXWnd__GetNextSib                                          0x62A230
#define CXWnd__GetScreenClipRect                                   0x62D960
#define CXWnd__GetScreenRect                                       0x62AA10
#define CXWnd__GetTooltipRect                                      0x62A620
#define CXWnd__GetWindowTextA                                      0x5172E0
#define CXWnd__IsActive                                            0x644460
#define CXWnd__IsDescendantOf                                      0x62A810
#define CXWnd__IsReallyVisible                                     0x62D060
#define CXWnd__IsType                                              0x64EAA0
#define CXWnd__Move                                                0x62CBA0
#define CXWnd__Move1                                               0x62CC40
#define CXWnd__ProcessTransition                                   0x62A140
#define CXWnd__Refade                                              0x629F50
#define CXWnd__Resize                                              0x62DAA0
#define CXWnd__Right                                               0x62D8B0
#define CXWnd__SetFirstChildPointer                                0x62AC60
#define CXWnd__SetFocus                                            0x62BF10
#define CXWnd__SetKeyTooltip                                       0x62ACD0
#define CXWnd__SetMouseOver                                        0x62ACA0
#define CXWnd__SetNextSibPointer                                   0x62AC80
#define CXWnd__StartFade                                           0x62A1A0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x645800
#define CXWndManager__DrawWindows                                  0x6454D0
#define CXWndManager__GetFirstChildWnd                             0x644DF0
#define CXWndManager__GetKeyboardFlags                             0x644140
#define CXWndManager__HandleKeyboardMsg                            0x644650
#define CXWndManager__RemoveWnd                                    0x644570

// CDBStr
#define CDBStr__GetString                                          0x4555A0

// EQ_Character 
#define EQ_Character__CastRay                                      0x674EA0
#define EQ_Character__CastSpell                                    0x4217E0
#define EQ_Character__Cur_HP                                       0x428B40
#define EQ_Character__GetAACastingTimeModifier                     0x41C6D0
#define EQ_Character__GetCharInfo2                                 0x5F8D20
#define EQ_Character__GetFocusCastingTimeModifier                  0x418D70
#define EQ_Character__GetFocusRangeModifier                        0x418EA0
#define EQ_Character__Max_Endurance                                0x4279F0
#define EQ_Character__Max_HP                                       0x4278A0
#define EQ_Character__Max_Mana                                     0x4E8740
#define EQ_Character__doCombatAbility                              0x4E75C0
#define EQ_Character__UseSkill                                     0x433DA0
#define EQ_Character__GetConLevel                                  0x4E4B30

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4DA3D0
#define EQ_Item__GetItemLinkHash                                   0x5F7EE0
#define EQ_Item__IsStackable                                       0x5F41A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x46D660
#define EQ_LoadingS__Array                                         0x70FF30

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4EB5C0
#define EQ_PC__GetAltAbilityIndex                                  0x5FDC30
#define EQ_PC__GetCombatAbility                                    0x5FDD70
#define EQ_PC__GetCombatAbilityTimer                               0x5FDE20
#define EQ_PC__GetItemTimerValue                                   0x4E68D0
#define EQ_PC__HasLoreItem                                         0x4E9C00

// EQItemList 
#define EQItemList__dEQItemList                                    0x48F320
#define EQItemList__EQItemList                                     0x48F270

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x455010

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4EFF10
#define EQPlayer__dEQPlayer                                        0x4F4220
#define EQPlayer__DoAttack                                         0x4FF520
#define EQPlayer__EQPlayer                                         0x4F68D0
#define EQPlayer__SetNameSpriteState                               0x4F2510
#define EQPlayer__SetNameSpriteTint                                0x4EFF80
#define EQPlayer__IsBodyType_j                                     0x674C50

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4F76D0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4DC250
#define KeypressHandler__AttachKeyToEqCommand                      0x4DC290
#define KeypressHandler__ClearCommandStateArray                    0x4DC060
#define KeypressHandler__HandleKeyDown                             0x4DAC90
#define KeypressHandler__HandleKeyUp                               0x4DAF90
#define KeypressHandler__SaveKeymapping                            0x4DC130

// MapViewMap 
#define MapViewMap__Clear                                          0x58BF80
#define MapViewMap__SaveEx                                         0x58C950

// StringTable 
#define StringTable__getString                                     0x5F3A00
