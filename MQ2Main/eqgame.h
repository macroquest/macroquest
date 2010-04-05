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
#define __ExpectedVersionDate                                     "Nov 18 2009"
#define __ExpectedVersionTime                                     "14:08:20"
#define __ActualVersionDate                                        0x815A50
#define __ActualVersionTime                                        0x815A5C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x5107A0
#define __MemChecker1                                              0x6DEAA0
#define __MemChecker2                                              0x570490
#define __MemChecker3                                              0x5703E0
#define __MemChecker4                                              0x693880
#define __EncryptPad0                                              0x8A6190
#define __EncryptPad1                                              0x8B1298
#define __EncryptPad2                                              0x8A8DC8
#define __EncryptPad3                                              0x8A89C8
#define __EncryptPad4                                              0x8B08D8
#define __AC1                                                      0x65B9A0
#define __AC2                                                      0x4D8C45
#define __AC3                                                      0x4ECC28
#define __AC4                                                      0x4F0AF8
#define __AC5                                                      0x4FB248
#define __AC6                                                      0x4FE6CB
#define __AC7                                                      0x4F7774
#define __AC1_Data                                                 0x7FE5D0

// Direct Input
#define DI8__Main                                                  0xB0BBFC
#define DI8__Keyboard                                              0xB0BC00
#define DI8__Mouse                                                 0xB0BC04
#define __AltTimerReady                                            0xA9290A
#define __Attack                                                   0xAF5FAA
#define __Autofire                                                 0xAF5FAB
#define __BindList                                                 0x8A0910
#define __Clicks                                                   0xA91608
#define __CommandList                                              0x8A1260
#define __CurrentMapLabel                                          0xB36E98
#define __CurrentSocial                                            0x89C83C
#define __DoAbilityAvailable                                       0xA928A4
#define __DoAbilityList                                            0xAC7EC8
#define __do_loot                                                  0x4B1900
#define __DrawHandler                                              0xB4649C
#define __GroupCount                                               0xA8B4C2
#define __Guilds                                                   0xA909E8
#define __gWorld                                                   0xA8D380
#define __HotkeyPage                                               0xAEF2B4
#define __HWnd                                                     0xB0B938
#define __InChatMode                                               0xA91540
#define __LastTell                                                 0xA93220
#define __LMouseHeldTime                                           0xA91634
#define __Mouse                                                    0xB0BC08
#define __MouseLook                                                0xA915D6
#define __MouseEventTime                                           0xAF60EC
#define __NetStatusToggle                                          0xA915D9
#define __PCNames                                                  0xA92C64
#define __RangeAttackReady                                         0xA92908
#define __RMouseHeldTime                                           0xA91630
#define __RunWalkState                                             0xA91544
#define __ScreenMode                                               0x9DAD58
#define __ScreenX                                                  0xA914F8
#define __ScreenY                                                  0xA914FC
#define __ScreenXMax                                               0xA91500
#define __ScreenYMax                                               0xA91504
#define __ServerHost                                               0xA8B404
#define __ServerName                                               0xAC7E88
#define __ShiftKeyDown                                             0xA91BBC
#define __ShowNames                                                0xA92B38
#define __Socials                                                  0xAC7F88


////
//Section 1: Vital Offsets
////
#define instCRaid                                                  0xA8D440
#define instEQZoneInfo                                             0xA91780
#define instKeypressHandler                                        0xAF60D0
#define pinstActiveBanker                                          0xA8D418
#define pinstActiveCorpse                                          0xA8D41C
#define pinstActiveGMaster                                         0xA8D420
#define pinstActiveMerchant                                        0xA8D414
#define pinstAltAdvManager                                         0x9DBBD8
#define pinstAuraMgr                                               0x8C461C
#define pinstBandageTarget                                         0xA8D400
#define pinstCamActor                                              0x9DB6C4
#define pinstCDBStr                                                0x9DAD48
#define pinstCDisplay                                              0xA8D428
#define pinstCEverQuest                                            0xB0BD80
#define pinstCharData                                              0xA8D3E4
#define pinstCharSpawn                                             0xA8D40C
#define pinstControlledMissile                                     0xA8D3E0
#define pinstControlledPlayer                                      0xA8D40C
#define pinstCSidlManager                                          0xB45C10
#define pinstCXWndManager                                          0xB45C08
#define instDynamicZone                                            0xA913C8
#define pinstDZMember                                              0xA914D8
#define pinstDZTimerInfo                                           0xA914DC
#define pinstEQItemList                                            0xA8D3C8
#define instEQMisc                                                 0x9DAD00
#define pinstEQSoundManager                                        0x9DBBFC
#define instExpeditionLeader                                       0xA91412
#define instExpeditionName                                         0xA91452
#define pinstGroup                                                 0xA8B4BE
#define pinstImeManager                                            0xB45C14
#define pinstLocalPlayer                                           0xA8D3F8
#define pinstMercenaryData                                         0xAF6448
#define pinstModelPlayer                                           0xA8D424
#define pinstPCData                                                0xA8D3E4
#define pinstSkillMgr                                              0xB089EC
#define pinstSpawnManager                                          0xB08848
#define pinstSpellManager                                          0xB089F8
#define pinstSpellSets                                             0xAEF2B8
#define pinstStringTable                                           0xA8D39C
#define pinstSwitchManager                                         0xA8B104
#define pinstTarget                                                0xA8D410
#define pinstTargetObject                                          0xA8D3E8
#define pinstTargetSwitch                                          0xA8D3EC
#define pinstTaskMember                                            0x9DACE0
#define pinstTrackTarget                                           0xA8D404
#define pinstTradeTarget                                           0xA8D3F4
#define instTributeActive                                          0x9DAD25
#define pinstViewActor                                             0x9DB6C0
#define pinstWorldData                                             0xA8D3C4


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                          0x8C1EE4
#define pinstCAudioTriggersWindow                                  0x8C1EB0
#define pinstCCharacterSelect                                      0x9DB5C0
#define pinstCFacePick                                             0x9DB570
#define pinstCNoteWnd                                              0x9DB578
#define pinstCBookWnd                                              0x9DB57C
#define pinstCPetInfoWnd                                           0x9DB580
#define pinstCTrainWnd                                             0x9DB584
#define pinstCSkillsWnd                                            0x9DB588
#define pinstCSkillsSelectWnd                                      0x9DB58C
#define pinstCCombatSkillSelectWnd                                 0x9DB590
#define pinstCFriendsWnd                                           0x9DB594
#define pinstCAuraWnd                                              0x9DB598
#define pinstCRespawnWnd                                           0x9DB59C
#define pinstCBandolierWnd                                         0x9DB5A0
#define pinstCPotionBeltWnd                                        0x9DB5A4
#define pinstCAAWnd                                                0x9DB5A8
#define pinstCGroupSearchFiltersWnd                                0x9DB5AC
#define pinstCLoadskinWnd                                          0x9DB5B0
#define pinstCAlarmWnd                                             0x9DB5B4
#define pinstCMusicPlayerWnd                                       0x9DB5B8
#define pinstCMailWnd                                              0x9DB5C4
#define pinstCMailCompositionWnd                                   0x9DB5C8
#define pinstCMailAddressBookWnd                                   0x9DB5CC
#define pinstCRaidWnd                                              0x9DB5D4
#define pinstCRaidOptionsWnd                                       0x9DB5D8
#define pinstCBreathWnd                                            0x9DB5DC
#define pinstCMapViewWnd                                           0x9DB5E0
#define pinstCMapToolbarWnd                                        0x9DB5E4
#define pinstCEditLabelWnd                                         0x9DB5E8
#define pinstCTargetWnd                                            0x9DB5EC
#define pinstCColorPickerWnd                                       0x9DB5F0
#define pinstCPlayerWnd                                            0x9DB5F4
#define pinstCOptionsWnd                                           0x9DB5F8
#define pinstCBuffWindowNORMAL                                     0x9DB5FC
#define pinstCBuffWindowSHORT                                      0x9DB600
#define pinstCharacterCreation                                     0x9DB604
#define pinstCCursorAttachment                                     0x9DB608
#define pinstCCastingWnd                                           0x9DB60C
#define pinstCCastSpellWnd                                         0x9DB610
#define pinstCSpellBookWnd                                         0x9DB614
#define pinstCInventoryWnd                                         0x9DB618
#define pinstCBankWnd                                              0x9DB61C
#define pinstCQuantityWnd                                          0x9DB620
#define pinstCLootWnd                                              0x9DB624
#define pinstCActionsWnd                                           0x9DB628
#define pinstCCombatAbilityWnd                                     0x9DB62C
#define pinstCMerchantWnd                                          0x9DB630
#define pinstCTradeWnd                                             0x9DB634
#define pinstCSelectorWnd                                          0x9DB638
#define pinstCBazaarWnd                                            0x9DB63C
#define pinstCBazaarSearchWnd                                      0x9DB640
#define pinstCGiveWnd                                              0x9DB644
#define pinstCTrackingWnd                                          0x9DB648
#define pinstCInspectWnd                                           0x9DB64C
#define pinstCSocialEditWnd                                        0x9DB650
#define pinstCFeedbackWnd                                          0x9DB654
#define pinstCBugReportWnd                                         0x9DB658
#define pinstCVideoModesWnd                                        0x9DB65C
#define pinstCTextEntryWnd                                         0x9DB664
#define pinstCFileSelectionWnd                                     0x9DB668
#define pinstCCompassWnd                                           0x9DB66C
#define pinstCPlayerNotesWnd                                       0x9DB670
#define pinstCGemsGameWnd                                          0x9DB674
#define pinstCTimeLeftWnd                                          0x9DB678
#define pinstCPetitionQWnd                                         0x9DB68C
#define pinstCSoulmarkWnd                                          0x9DB690
#define pinstCStoryWnd                                             0x9DB694
#define pinstCJournalTextWnd                                       0x9DB698
#define pinstCJournalCatWnd                                        0x9DB69C
#define pinstCBodyTintWnd                                          0x9DB6A0
#define pinstCServerListWnd                                        0x9DB6A4
#define pinstCAvaZoneWnd                                           0x9DB6AC
#define pinstCBlockedBuffWnd                                       0x9DB6B0
#define pinstCBlockedPetBuffWnd                                    0x9DB6B4
#define pinstCInvSlotMgr                                           0x9DB6B8
#define pinstCContainerMgr                                         0x9DB6BC
#define pinstCAdventureLeaderboardWnd                              0xB343B0
#define pinstCAdventureRequestWnd                                  0xB343CC
#define pinstCAltStorageWnd                                        0xB3442C
#define pinstCAdventureStatsWnd                                    0xB343E8
#define pinstCBarterMerchantWnd                                    0xB345F8
#define pinstCBarterSearchWnd                                      0xB34614
#define pinstCBarterWnd                                            0xB34630
#define pinstCChatManager                                          0xB348D4
#define pinstCDynamicZoneWnd                                       0xB349CC
#define pinstCEQMainWnd                                            0xB34A40
#define pinstCFellowshipWnd                                        0xB34AA4
#define pinstCFindLocationWnd                                      0xB34AD8
#define pinstCGroupSearchWnd                                       0xB34B88
#define pinstCGroupWnd                                             0xB34BA4
#define pinstCGuildBankWnd                                         0xB34BC0
#define pinstCGuildMgmtWnd                                         0xB36BF8
#define pinstCGuildTributeMasterWnd                                0xB36C18
#define pinstCHotButtonWnd                                         0xB36C4C
#define pinstCHotButtonWnd1                                        0xB36C4C
#define pinstCHotButtonWnd2                                        0xB36C50
#define pinstCHotButtonWnd3                                        0xB36C54
#define pinstCHotButtonWnd4                                        0xB36C58
#define pinstCItemDisplayManager                                   0xB36D04
#define pinstCItemExpTransferWnd                                   0xB36D24
#define pinstCLeadershipWnd                                        0xB36DC0
#define pinstCLFGuildWnd                                           0xB36DDC
#define pinstCMIZoneSelectWnd                                      0xB36F4C
#define pinstCAdventureMerchantWnd                                 0xB3705C
#define pinstCConfirmationDialog                                   0xB37078
#define pinstCPopupWndManager                                      0xB37078
#define pinstCProgressionSelectionWnd                              0xB370AC
#define pinstCPvPLeaderboardWnd                                    0xB370C8
#define pinstCPvPStatsWnd                                          0xB370E4
#define pinstCSystemInfoDialogBox                                  0xB371B0
#define pinstCTargetOfTargetWnd                                    0xB37BAC
#define pinstCTaskSelectWnd                                        0xB37BE0
#define pinstCTaskTemplateSelectWnd                                0xB37BFC
#define pinstCTaskWnd                                              0xB37C18
#define pinstCTipWndOFDAY                                          0xB37C94
#define pinstCTipWndCONTEXT                                        0xB37C98
#define pinstCTitleWnd                                             0xB37CB4
#define pinstCTradeskillWnd                                        0xB37CF8
#define pinstCTributeBenefitWnd                                    0xB37D44
#define pinstCTributeMasterWnd                                     0xB37D60
#define pinstCContextMenuManager                                   0xB45C6C
#define pinstCVoiceMacroWnd                                        0xB08BEC
#define pinstCHtmlWnd                                              0xB08C38


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                                  0x4C5640
#define __ConvertItemTags                                          0x4B6F80
#define __ExecuteCmd                                               0x4A3890
#define __get_melee_range                                          0x4A91A0
#define __GetGaugeValueFromEQ                                      0x65A8A0
#define __GetLabelFromEQ                                           0x65B940
#define __LoadFrontEnd                                             0x56F360
#define __NewUIINI                                                 0x65A430
#define __ProcessGameEvents                                        0x4F7B60
#define CrashDetected                                              0x56F160
#define DrawNetStatus                                              0x519310
#define Util__FastTime                                             0x6DF1F0


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x47AC00
#define AltAdvManager__IsAbilityReady                              0x47AC40
#define AltAdvManager__GetAltAbility                               0x47AE20

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x58C4B0

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x595CD0

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x70D0B0

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x5ABBB0
#define CChatManager__InitContextMenu                              0x5AC380

// CChatService
#define CChatService__GetNumberOfFriends                           0x6C99A0
#define CChatService__GetFriendName                                0x6C99B0

// CChatWindow
#define CChatWindow__CChatWindow                                   0x5B0580
#define CChatWindow__Clear                                         0x5B0EF0
#define CChatWindow__WndNotification                               0x5B1110

// CComboWnd
#define CComboWnd__DeleteAll                                       0x6F6FF0
#define CComboWnd__Draw                                            0x6F71B0
#define CComboWnd__GetCurChoice                                    0x6F6F90
#define CComboWnd__GetListRect                                     0x6F74A0
#define CComboWnd__GetTextRect                                     0x6F7020
#define CComboWnd__InsertChoice                                    0x6F7510
#define CComboWnd__SetColors                                       0x6F6F20
#define CComboWnd__SetChoice                                       0x6F6F50

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x5B84D0
#define CContainerWnd__vftable                                     0x81D3A0

// CDisplay
#define CDisplay__CleanGameUI                                      0x46DDA0
#define CDisplay__GetClickedActor                                  0x467100
#define CDisplay__GetUserDefinedColor                              0x466220
#define CDisplay__GetWorldFilePath                                 0x465690
#define CDisplay__is3dON                                           0x4647D0
#define CDisplay__ReloadUI                                         0x477E00
#define CDisplay__WriteTextHD2                                     0x469DC0

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x586420
#define CEditBaseWnd__SetSel                                       0x7195F0

// CEditWnd
#define CEditWnd__DrawCaret                                        0x700030
#define CEditWnd__GetCharIndexPt                                   0x701000
#define CEditWnd__GetDisplayString                                 0x7001D0
#define CEditWnd__GetHorzOffset                                    0x700460
#define CEditWnd__GetLineForPrintableChar                          0x700AB0
#define CEditWnd__GetSelStartPt                                    0x701250
#define CEditWnd__GetSTMLSafeText                                  0x700600
#define CEditWnd__PointFromPrintableChar                           0x700BC0
#define CEditWnd__SelectableCharFromPoint                          0x700D40
#define CEditWnd__SetEditable                                      0x7005D0

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x4D9320
#define CEverQuest__DropHeldItemOnGround                           0x4DD890
#define CEverQuest__dsp_chat                                       0x4DEFF0
#define CEverQuest__DoTellWindow                                   0x4DDA10
#define CEverQuest__EnterZone                                      0x4F0A90
#define CEverQuest__GetBodyTypeDesc                                0x4D6520
#define CEverQuest__GetClassDesc                                   0x4D5D60
#define CEverQuest__GetClassThreeLetterCode                        0x4D6360
#define CEverQuest__GetDeityDesc                                   0x4D6B90
#define CEverQuest__GetLangDesc                                    0x4D68B0
#define CEverQuest__GetRaceDesc                                    0x4D6B60
#define CEverQuest__InterpretCmd                                   0x4DFB50
#define CEverQuest__LeftClickedOnPlayer                            0x4F25C0
#define CEverQuest__LMouseUp                                       0x4F5EB0
#define CEverQuest__RightClickedOnPlayer                           0x4F6750
#define CEverQuest__RMouseUp                                       0x4F7730
#define CEverQuest__SetGameState                                   0x4D97B0
#define CEverQuest__Emote                                          0x4DF210

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x5C4D70
#define CGaugeWnd__CalcLinesFillRect                               0x5C4DD0
#define CGaugeWnd__Draw                                            0x5C5220

// CGuild
#define CGuild__FindMemberByName                                   0x41B230

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x5DDA50

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x5E7090
#define CInvSlotMgr__MoveItem                                      0x5E7230

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5E6920
#define CInvSlot__SliderComplete                                   0x5E5A60

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5E81D0

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell                                  0x6582F0
#define CItemDisplayWnd__UpdateStrings                             0x5E8E80

// CLabel
#define CLabel__Draw                                               0x5FB4F0

// CListWnd
#define CListWnd__AddColumn                                        0x6EFF30
#define CListWnd__AddColumn1                                       0x6EFA00
#define CListWnd__AddLine                                          0x6EF520
#define CListWnd__AddString                                        0x6EF6C0
#define CListWnd__CalculateFirstVisibleLine                        0x6EC100
#define CListWnd__CalculateVSBRange                                0x6EE470
#define CListWnd__ClearAllSel                                      0x6EB610
#define CListWnd__CloseAndUpdateEditWindow                         0x6EC890
#define CListWnd__Compare                                          0x6ECC30
#define CListWnd__Draw                                             0x6EE0F0
#define CListWnd__DrawColumnSeparators                             0x6EDF60
#define CListWnd__DrawHeader                                       0x6EB8E0
#define CListWnd__DrawItem                                         0x6ED580
#define CListWnd__DrawLine                                         0x6EDBF0
#define CListWnd__DrawSeparator                                    0x6EE000
#define CListWnd__EnsureVisible                                    0x6EC190
#define CListWnd__ExtendSel                                        0x6ED4A0
#define CListWnd__GetColumnMinWidth                                0x6EB3A0
#define CListWnd__GetColumnWidth                                   0x6EB2D0
#define CListWnd__GetCurSel                                        0x6EACE0
#define CListWnd__GetHeaderRect                                    0x6EAE50
#define CListWnd__GetItemAtPoint                                   0x6EC540
#define CListWnd__GetItemAtPoint1                                  0x6EC5B0
#define CListWnd__GetItemData                                      0x6EB080
#define CListWnd__GetItemHeight                                    0x6EBDA0
#define CListWnd__GetItemIcon                                      0x6EB210
#define CListWnd__GetItemRect                                      0x6EC270
#define CListWnd__GetItemText                                      0x6EB0C0
#define CListWnd__GetSelList                                       0x6EF8E0
#define CListWnd__GetSeparatorRect                                 0x6ECB70
#define CListWnd__RemoveLine                                       0x6EF890
#define CListWnd__SetColors                                        0x6EADB0
#define CListWnd__SetColumnJustification                           0x6EB480
#define CListWnd__SetColumnWidth                                   0x6EB360
#define CListWnd__SetCurSel                                        0x6EAD20
#define CListWnd__SetItemColor                                     0x6EF130
#define CListWnd__SetItemData                                      0x6EB6B0
#define CListWnd__SetItemText                                      0x6EF0B0
#define CListWnd__ShiftColumnSeparator                             0x6ED3A0
#define CListWnd__Sort                                             0x6EFF70
#define CListWnd__ToggleSel                                        0x6EB580

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x610D10

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x61CD10
#define CMerchantWnd__RequestBuyItem                               0x61EC50
#define CMerchantWnd__RequestSellItem                              0x61F070
#define CMerchantWnd__SelectBuySellSlot                            0x61E0E0

// CObfuscator
#define CObfuscator__doit                                          0x6A3A40

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x708870
#define CSidlManager__CreateLabel                                  0x651240

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x6F8CE0
#define CSidlScreenWnd__CalculateVSBRange                          0x6F8C00
#define CSidlScreenWnd__ConvertToRes                               0x7194D0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6F91B0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6FA2A0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6FA350
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6F9A50
#define CSidlScreenWnd__DrawSidlPiece                              0x6F8E70
#define CSidlScreenWnd__EnableIniStorage                           0x6F88F0
#define CSidlScreenWnd__GetSidlPiece                               0x6F9080
#define CSidlScreenWnd__Init1                                      0x6FA100
#define CSidlScreenWnd__LoadIniInfo                                0x6F9270
#define CSidlScreenWnd__LoadIniListWnd                             0x6F8A40
#define CSidlScreenWnd__LoadSidlScreen                             0x6F9CA0
#define CSidlScreenWnd__StoreIniInfo                               0x6F8500
#define CSidlScreenWnd__StoreIniVis                                0x6F8880
#define CSidlScreenWnd__WndNotification                            0x6F9E80
#define CSidlScreenWnd__GetChildItem                               0x6F8950

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x53CF40

// CSliderWnd
#define CSliderWnd__GetValue                                       0x71AA20
#define CSliderWnd__SetValue                                       0x71AB20
#define CSliderWnd__SetNumTicks                                    0x71B0D0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x656050

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x717750
#define CStmlWnd__CalculateVSBRange                                0x70F340
#define CStmlWnd__CanBreakAtCharacter                              0x70F4C0
#define CStmlWnd__FastForwardToEndOfTag                            0x710160
#define CStmlWnd__ForceParseNow                                    0x717BA0
#define CStmlWnd__GetNextTagPiece                                  0x710080
#define CStmlWnd__GetSTMLText                                      0x5B0520
#define CStmlWnd__GetThisChar                                      0x73E6A0
#define CStmlWnd__GetVisiableText                                  0x711520
#define CStmlWnd__InitializeWindowVariables                        0x7137B0
#define CStmlWnd__MakeStmlColorTag                                 0x70E1D0
#define CStmlWnd__MakeWndNotificationTag                           0x70E270
#define CStmlWnd__SetSTMLText                                      0x7138D0
#define CStmlWnd__StripFirstSTMLLines                              0x7174D0
#define CStmlWnd__UpdateHistoryString                              0x711D80

// CTabWnd
#define CTabWnd__Draw                                              0x71BE70
#define CTabWnd__DrawCurrentPage                                   0x71B880
#define CTabWnd__DrawTab                                           0x71B660
#define CTabWnd__GetCurrentPage                                    0x71BB00
#define CTabWnd__GetPageClientRect                                 0x71B330
#define CTabWnd__GetPageFromTabIndex                               0x71B590
#define CTabWnd__GetPageInnerRect                                  0x71B390
#define CTabWnd__GetTabInnerRect                                   0x71B510
#define CTabWnd__GetTabRect                                        0x71B420
#define CTabWnd__InsertPage                                        0x71C100
#define CTabWnd__SetPage                                           0x71BB40
#define CTabWnd__SetPageRect                                       0x71BDA0
#define CTabWnd__UpdatePage                                        0x71C080

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x417800

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6FA6D0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x71CD10

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x6EA9D0

// CXRect
#define CXRect__CenterPoint                                        0x58BB30

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x50A220
#define CXStr__CXStr1                                              0x6794E0
#define CXStr__CXStr3                                              0x6DC4B0
#define CXStr__dCXStr                                              0x625BE0
#define CXStr__operator_equal1                                     0x6DC670
#define CXStr__operator_plus_equal1                                0x6DD6B0

// CXWnd
#define CXWnd__BringToTop                                          0x6F0FD0
#define CXWnd__Center                                              0x6F5810
#define CXWnd__ClrFocus                                            0x6F0DF0
#define CXWnd__DoAllDrawing                                        0x6F66C0
#define CXWnd__DrawChildren                                        0x6F6810
#define CXWnd__DrawColoredRect                                     0x6F12B0
#define CXWnd__DrawTooltip                                         0x6F64B0
#define CXWnd__DrawTooltipAtPoint                                  0x6F55C0
#define CXWnd__GetBorderFrame                                      0x6F16F0
#define CXWnd__GetChildWndAt                                       0x6F4DF0
#define CXWnd__GetClientClipRect                                   0x6F1570
#define CXWnd__GetScreenClipRect                                   0x6F5A30
#define CXWnd__GetScreenRect                                       0x6F1880
#define CXWnd__GetTooltipRect                                      0x6F13C0
#define CXWnd__GetWindowTextA                                      0x57A130
#define CXWnd__IsActive                                            0x6FB840
#define CXWnd__IsDescendantOf                                      0x6F1620
#define CXWnd__IsReallyVisible                                     0x6F4DD0
#define CXWnd__IsType                                              0x71FB00
#define CXWnd__Move                                                0x6F4590
#define CXWnd__Move1                                               0x6F6290
#define CXWnd__ProcessTransition                                   0x6F0F80
#define CXWnd__Refade                                              0x6F0F00
#define CXWnd__Resize                                              0x6F1950
#define CXWnd__Right                                               0x6F5970
#define CXWnd__SetFocus                                            0x6F3160
#define CXWnd__SetKeyTooltip                                       0x6F1B30
#define CXWnd__SetMouseOver                                        0x6F5CC0
#define CXWnd__StartFade                                           0x6F1010
#define CXWnd__GetChildItem                                        0x6F5C40

// CXWndManager
#define CXWndManager__DrawCursor                                   0x6FCDE0
#define CXWndManager__DrawWindows                                  0x6FCA60
#define CXWndManager__GetKeyboardFlags                             0x6FB490
#define CXWndManager__HandleKeyboardMsg                            0x6FBB10
#define CXWndManager__RemoveWnd                                    0x6FB960

// CDBStr
#define CDBStr__GetString                                          0x463120

// EQ_Character
#define EQ_Character__CastRay                                      0x74A7D0
#define EQ_Character__CastSpell                                    0x42DF30
#define EQ_Character__Cur_HP                                       0x437120
#define EQ_Character__GetAACastingTimeModifier                     0x423DF0
#define EQ_Character__GetCharInfo2                                 0x6BA9E0
#define EQ_Character__GetFocusCastingTimeModifier                  0x41F670
#define EQ_Character__GetFocusRangeModifier                        0x41F7B0
#define EQ_Character__Max_Endurance                                0x51F760
#define EQ_Character__Max_HP                                       0x432340
#define EQ_Character__Max_Mana                                     0x51F590
#define EQ_Character__doCombatAbility                              0x51E4A0
#define EQ_Character__UseSkill                                     0x441090
#define EQ_Character__GetConLevel                                  0x51A7C0

// EQ_Item
#define EQ_Item__CanDrop                                           0x507FC0
#define EQ_Item__GetItemLinkHash                                   0x6AD4F0
#define EQ_Item__IsStackable                                       0x6A4320

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar                                0x47BCF0
#define EQ_LoadingS__Array                                         0x89ED78

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x5225E0
#define EQ_PC__GetAltAbilityIndex                                  0x6B2690
#define EQ_PC__GetCombatAbility                                    0x6B2720
#define EQ_PC__GetCombatAbilityTimer                               0x6B27D0
#define EQ_PC__GetItemTimerValue                                   0x51D3D0
#define EQ_PC__HasLoreItem                                         0x520AB0

// EQItemList
#define EQItemList__dEQItemList                                    0x4A7740
#define EQItemList__EQItemList                                     0x4A7690

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x462A80

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x526F90
#define EQPlayer__dEQPlayer                                        0x52B270
#define EQPlayer__DoAttack                                         0x539180
#define EQPlayer__EQPlayer                                         0x52F000
#define EQPlayer__SetNameSpriteState                               0x5290F0
#define EQPlayer__SetNameSpriteTint                                0x527000
#define EQPlayer__IsBodyType_j                                     0x74A0E0
#define EQPlayer__IsTargetable                                     0x74A270

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5301B0
#define EQPlayerManager__GetSpawnByName                            0x530490

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x509C40
#define KeypressHandler__AttachKeyToEqCommand                      0x509C80
#define KeypressHandler__ClearCommandStateArray                    0x509A50
#define KeypressHandler__HandleKeyDown                             0x5085D0
#define KeypressHandler__HandleKeyUp                               0x5088E0
#define KeypressHandler__SaveKeymapping                            0x509B20

// MapViewMap
#define MapViewMap__Clear                                          0x60C3B0
#define MapViewMap__SaveEx                                         0x60CD80

#define OtherCharData__GetAltCurrency                              0x6D2190

// StringTable
#define StringTable__getString                                     0x6A3CC0
