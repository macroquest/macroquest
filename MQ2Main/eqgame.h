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
#define __ExpectedVersionDate                                     "Nov 10 2009"
#define __ExpectedVersionTime                                     "16:23:17"
#define __ActualVersionDate                                        0x815A50
#define __ActualVersionTime                                        0x815A5C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x510870
#define __MemChecker1                                              0x6DEDA0
#define __MemChecker2                                              0x570500
#define __MemChecker3                                              0x570450
#define __MemChecker4                                              0x693A80
#define __EncryptPad0                                              0x8A6190
#define __EncryptPad1                                              0x8B1298
#define __EncryptPad2                                              0x8A8DC8
#define __EncryptPad3                                              0x8A89C8
#define __EncryptPad4                                              0x8B08D8
#define __AC1                                                      0x65BA40
#define __AC2                                                      0x4D8CD5
#define __AC3                                                      0x4ECD08
#define __AC4                                                      0x4F0BD8
#define __AC5                                                      0x4FB358
#define __AC6                                                      0x4FE7DB
#define __AC7                                                      0x4F7884
#define __AC1_Data                                                 0x7FE560

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
#define __do_loot                                                  0x4B1A90
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
#define __CastRay                                                  0x4C57D0
#define __ConvertItemTags                                          0x4B7110
#define __ExecuteCmd                                               0x4A39A0
#define __get_melee_range                                          0x4A9330
#define __GetGaugeValueFromEQ                                      0x65A940
#define __GetLabelFromEQ                                           0x65B9E0
#define __LoadFrontEnd                                             0x56F3D0
#define __NewUIINI                                                 0x65A4D0
#define __ProcessGameEvents                                        0x4F7C70
#define CrashDetected                                              0x56F1D0
#define DrawNetStatus                                              0x5194D0
#define Util__FastTime                                             0x6DF4B0


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x47AC70
#define AltAdvManager__IsAbilityReady                              0x47ACB0
#define AltAdvManager__GetAltAbility                               0x47AF80

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x58C5E0

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x595AB0

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x70D0A0

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x5ABE90
#define CChatManager__InitContextMenu                              0x5AC660

// CChatService
#define CChatService__GetNumberOfFriends                           0x6C9B00
#define CChatService__GetFriendName                                0x6C9B10

// CChatWindow
#define CChatWindow__CChatWindow                                   0x5B0860
#define CChatWindow__Clear                                         0x5B11D0
#define CChatWindow__WndNotification                               0x5B13F0

// CComboWnd
#define CComboWnd__DeleteAll                                       0x6F7280
#define CComboWnd__Draw                                            0x6F7440
#define CComboWnd__GetCurChoice                                    0x6F7220
#define CComboWnd__GetListRect                                     0x6F7730
#define CComboWnd__GetTextRect                                     0x6F72B0
#define CComboWnd__InsertChoice                                    0x6F77A0
#define CComboWnd__SetColors                                       0x6F71B0
#define CComboWnd__SetChoice                                       0x6F71E0

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x5B8830
#define CContainerWnd__vftable                                     0x81D3A0

// CDisplay
#define CDisplay__CleanGameUI                                      0x46DD90
#define CDisplay__GetClickedActor                                  0x4670F0
#define CDisplay__GetUserDefinedColor                              0x466210
#define CDisplay__GetWorldFilePath                                 0x465680
#define CDisplay__is3dON                                           0x4647C0
#define CDisplay__ReloadUI                                         0x477DF0
#define CDisplay__WriteTextHD2                                     0x469DB0

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x5863F0
#define CEditBaseWnd__SetSel                                       0x719570

// CEditWnd
#define CEditWnd__DrawCaret                                        0x7000B0
#define CEditWnd__GetCharIndexPt                                   0x701080
#define CEditWnd__GetDisplayString                                 0x700250
#define CEditWnd__GetHorzOffset                                    0x7004E0
#define CEditWnd__GetLineForPrintableChar                          0x700B30
#define CEditWnd__GetSelStartPt                                    0x7012D0
#define CEditWnd__GetSTMLSafeText                                  0x700680
#define CEditWnd__PointFromPrintableChar                           0x700C40
#define CEditWnd__SelectableCharFromPoint                          0x700DC0
#define CEditWnd__SetEditable                                      0x700650

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x4D93B0
#define CEverQuest__DropHeldItemOnGround                           0x4DD920
#define CEverQuest__dsp_chat                                       0x4DF0D0
#define CEverQuest__DoTellWindow                                   0x4DDAA0
#define CEverQuest__EnterZone                                      0x4F0B70
#define CEverQuest__GetBodyTypeDesc                                0x4D65B0
#define CEverQuest__GetClassDesc                                   0x4D5DF0
#define CEverQuest__GetClassThreeLetterCode                        0x4D63F0
#define CEverQuest__GetDeityDesc                                   0x4D6C20
#define CEverQuest__GetLangDesc                                    0x4D6940
#define CEverQuest__GetRaceDesc                                    0x4D6BF0
#define CEverQuest__InterpretCmd                                   0x4DFC30
#define CEverQuest__LeftClickedOnPlayer                            0x4F26D0
#define CEverQuest__LMouseUp                                       0x4F5FC0
#define CEverQuest__RightClickedOnPlayer                           0x4F6860
#define CEverQuest__RMouseUp                                       0x4F7840
#define CEverQuest__SetGameState                                   0x4D9840
#define CEverQuest__Emote                                          0x4DF2F0

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x5C50D0
#define CGaugeWnd__CalcLinesFillRect                               0x5C5130
#define CGaugeWnd__Draw                                            0x5C5570

// CGuild
#define CGuild__FindMemberByName                                   0x41B1B0

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x5DDDF0

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x5E7430
#define CInvSlotMgr__MoveItem                                      0x5E75D0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5E6CC0
#define CInvSlot__SliderComplete                                   0x5E5E00

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5E8570

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell                                  0x658390
#define CItemDisplayWnd__UpdateStrings                             0x5E9220

// CLabel
#define CLabel__Draw                                               0x5FB8B0

// CListWnd
#define CListWnd__AddColumn                                        0x6F0220
#define CListWnd__AddColumn1                                       0x6EFCA0
#define CListWnd__AddLine                                          0x6EF810
#define CListWnd__AddString                                        0x6EF9B0
#define CListWnd__CalculateFirstVisibleLine                        0x6EC400
#define CListWnd__CalculateVSBRange                                0x6EE760
#define CListWnd__ClearAllSel                                      0x6EB910
#define CListWnd__CloseAndUpdateEditWindow                         0x6ECB90
#define CListWnd__Compare                                          0x6ECF30
#define CListWnd__Draw                                             0x6EE3E0
#define CListWnd__DrawColumnSeparators                             0x6EE250
#define CListWnd__DrawHeader                                       0x6EBBE0
#define CListWnd__DrawItem                                         0x6ED880
#define CListWnd__DrawLine                                         0x6EDEE0
#define CListWnd__DrawSeparator                                    0x6EE2F0
#define CListWnd__EnsureVisible                                    0x6EC490
#define CListWnd__ExtendSel                                        0x6ED7A0
#define CListWnd__GetColumnMinWidth                                0x6EB6A0
#define CListWnd__GetColumnWidth                                   0x6EB5D0
#define CListWnd__GetCurSel                                        0x6EAFE0
#define CListWnd__GetHeaderRect                                    0x6EB150
#define CListWnd__GetItemAtPoint                                   0x6EC840
#define CListWnd__GetItemAtPoint1                                  0x6EC8B0
#define CListWnd__GetItemData                                      0x6EB380
#define CListWnd__GetItemHeight                                    0x6EC0A0
#define CListWnd__GetItemIcon                                      0x6EB510
#define CListWnd__GetItemRect                                      0x6EC570
#define CListWnd__GetItemText                                      0x6EB3C0
#define CListWnd__GetSelList                                       0x6EFB80
#define CListWnd__GetSeparatorRect                                 0x6ECE70
#define CListWnd__RemoveLine                                       0x6F01D0
#define CListWnd__SetColors                                        0x6EB0B0
#define CListWnd__SetColumnJustification                           0x6EB780
#define CListWnd__SetColumnWidth                                   0x6EB660
#define CListWnd__SetCurSel                                        0x6EB020
#define CListWnd__SetItemColor                                     0x6EF420
#define CListWnd__SetItemData                                      0x6EB9B0
#define CListWnd__SetItemText                                      0x6EF3A0
#define CListWnd__ShiftColumnSeparator                             0x6ED6A0
#define CListWnd__Sort                                             0x6F0260
#define CListWnd__ToggleSel                                        0x6EB880

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x611050

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x61CFE0
#define CMerchantWnd__RequestBuyItem                               0x61EF20
#define CMerchantWnd__RequestSellItem                              0x61F340
#define CMerchantWnd__SelectBuySellSlot                            0x61E3B0

// CObfuscator
#define CObfuscator__doit                                          0x6A3B70

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x708970
#define CSidlManager__CreateLabel                                  0x651330

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x588570
#define CSidlScreenWnd__CalculateVSBRange                          0x588490
#define CSidlScreenWnd__ConvertToRes                               0x719450
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6F9280
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6FA3A0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6FA450
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6F9B50
#define CSidlScreenWnd__DrawSidlPiece                              0x6F8F40
#define CSidlScreenWnd__EnableIniStorage                           0x6F8B80
#define CSidlScreenWnd__GetSidlPiece                               0x6F9150
#define CSidlScreenWnd__Init1                                      0x6FA200
#define CSidlScreenWnd__LoadIniInfo                                0x6F9340
#define CSidlScreenWnd__LoadIniListWnd                             0x6F8CD0
#define CSidlScreenWnd__LoadSidlScreen                             0x6F9DA0
#define CSidlScreenWnd__StoreIniInfo                               0x6F8790
#define CSidlScreenWnd__StoreIniVis                                0x6F8B10
#define CSidlScreenWnd__WndNotification                            0x6F9F80
#define CSidlScreenWnd__GetChildItem                               0x6F8BE0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x53CFF0

// CSliderWnd
#define CSliderWnd__GetValue                                       0x71A9A0
#define CSliderWnd__SetValue                                       0x71AAA0
#define CSliderWnd__SetNumTicks                                    0x71B050

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x6560F0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7176F0
#define CStmlWnd__CalculateVSBRange                                0x70F2A0
#define CStmlWnd__CanBreakAtCharacter                              0x70F4B0
#define CStmlWnd__FastForwardToEndOfTag                            0x710100
#define CStmlWnd__ForceParseNow                                    0x717B40
#define CStmlWnd__GetNextTagPiece                                  0x710020
#define CStmlWnd__GetSTMLText                                      0x5B0800
#define CStmlWnd__GetThisChar                                      0x73E6B0
#define CStmlWnd__GetVisiableText                                  0x7114C0
#define CStmlWnd__InitializeWindowVariables                        0x713750
#define CStmlWnd__MakeStmlColorTag                                 0x70E1C0
#define CStmlWnd__MakeWndNotificationTag                           0x70E260
#define CStmlWnd__SetSTMLText                                      0x713870
#define CStmlWnd__StripFirstSTMLLines                              0x717470
#define CStmlWnd__UpdateHistoryString                              0x711D20

// CTabWnd
#define CTabWnd__Draw                                              0x71BE70
#define CTabWnd__DrawCurrentPage                                   0x71B800
#define CTabWnd__DrawTab                                           0x71B5E0
#define CTabWnd__GetCurrentPage                                    0x71BB00
#define CTabWnd__GetPageClientRect                                 0x71B2B0
#define CTabWnd__GetPageFromTabIndex                               0x71B510
#define CTabWnd__GetPageInnerRect                                  0x71B310
#define CTabWnd__GetTabInnerRect                                   0x71B490
#define CTabWnd__GetTabRect                                        0x71B3A0
#define CTabWnd__InsertPage                                        0x71C100
#define CTabWnd__SetPage                                           0x71BB40
#define CTabWnd__SetPageRect                                       0x71BDA0
#define CTabWnd__UpdatePage                                        0x71C080

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x417780

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6FA7D0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x71CD10

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x6EACD0

// CXRect
#define CXRect__CenterPoint                                        0x58BC60

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x50A330
#define CXStr__CXStr1                                              0x679490
#define CXStr__CXStr3                                              0x6DC7B0
#define CXStr__dCXStr                                              0x64CA10
#define CXStr__operator_equal1                                     0x6DC970
#define CXStr__operator_plus_equal1                                0x6DD9B0

// CXWnd
#define CXWnd__BringToTop                                          0x6F12C0
#define CXWnd__Center                                              0x6F5B00
#define CXWnd__ClrFocus                                            0x6F10E0
#define CXWnd__DoAllDrawing                                        0x6F6950
#define CXWnd__DrawChildren                                        0x6F6AA0
#define CXWnd__DrawColoredRect                                     0x6F15A0
#define CXWnd__DrawTooltip                                         0x6F67A0
#define CXWnd__DrawTooltipAtPoint                                  0x6F58B0
#define CXWnd__GetBorderFrame                                      0x6F19E0
#define CXWnd__GetChildWndAt                                       0x6F50E0
#define CXWnd__GetClientClipRect                                   0x6F1860
#define CXWnd__GetScreenClipRect                                   0x6F5D20
#define CXWnd__GetScreenRect                                       0x6F1B70
#define CXWnd__GetTooltipRect                                      0x6F16B0
#define CXWnd__GetWindowTextA                                      0x57A1A0
#define CXWnd__IsActive                                            0x6FB940
#define CXWnd__IsDescendantOf                                      0x6F1910
#define CXWnd__IsReallyVisible                                     0x6F50C0
#define CXWnd__IsType                                              0x71FB10
#define CXWnd__Move                                                0x6F4880
#define CXWnd__Move1                                               0x6F6580
#define CXWnd__ProcessTransition                                   0x6F1270
#define CXWnd__Refade                                              0x6F11F0
#define CXWnd__Resize                                              0x6F1C40
#define CXWnd__Right                                               0x6F5C60
#define CXWnd__SetFocus                                            0x6F3450
#define CXWnd__SetKeyTooltip                                       0x6F1E20
#define CXWnd__SetMouseOver                                        0x6F5FB0
#define CXWnd__StartFade                                           0x6F1300
#define CXWnd__GetChildItem                                        0x6F5F30

// CXWndManager
#define CXWndManager__DrawCursor                                   0x6FCE60
#define CXWndManager__DrawWindows                                  0x6FCAE0
#define CXWndManager__GetKeyboardFlags                             0x6FB590
#define CXWndManager__HandleKeyboardMsg                            0x6FBC10
#define CXWndManager__RemoveWnd                                    0x6FBA60

// CDBStr
#define CDBStr__GetString                                          0x4630F0

// EQ_Character
#define EQ_Character__CastRay                                      0x74A780
#define EQ_Character__CastSpell                                    0x42DEB0
#define EQ_Character__Cur_HP                                       0x4370E0
#define EQ_Character__GetAACastingTimeModifier                     0x423D90
#define EQ_Character__GetCharInfo2                                 0x6BAB60
#define EQ_Character__GetFocusCastingTimeModifier                  0x41F5D0
#define EQ_Character__GetFocusRangeModifier                        0x41F710
#define EQ_Character__Max_Endurance                                0x51F920
#define EQ_Character__Max_HP                                       0x4322C0
#define EQ_Character__Max_Mana                                     0x51F750
#define EQ_Character__doCombatAbility                              0x51E660
#define EQ_Character__UseSkill                                     0x441050
#define EQ_Character__GetConLevel                                  0x51A980

// EQ_Item
#define EQ_Item__CanDrop                                           0x5080D0
#define EQ_Item__GetItemLinkHash                                   0x6AD620
#define EQ_Item__IsStackable                                       0x6A4450

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar                                0x47BE50
#define EQ_LoadingS__Array                                         0x89ED78

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x5227A0
#define EQ_PC__GetAltAbilityIndex                                  0x6B2810
#define EQ_PC__GetCombatAbility                                    0x6B28A0
#define EQ_PC__GetCombatAbilityTimer                               0x6B2950
#define EQ_PC__GetItemTimerValue                                   0x51D590
#define EQ_PC__HasLoreItem                                         0x520C70

// EQItemList
#define EQItemList__dEQItemList                                    0x4A7850
#define EQItemList__EQItemList                                     0x4A77A0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x462A50

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x527180
#define EQPlayer__dEQPlayer                                        0x52B340
#define EQPlayer__DoAttack                                         0x5392E0
#define EQPlayer__EQPlayer                                         0x52F0D0
#define EQPlayer__SetNameSpriteState                               0x529290
#define EQPlayer__SetNameSpriteTint                                0x5271F0
#define EQPlayer__IsBodyType_j                                     0x74A090
#define EQPlayer__IsTargetable                                     0x74A220

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x530280
#define EQPlayerManager__GetSpawnByName                            0x530560

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x509D50
#define KeypressHandler__AttachKeyToEqCommand                      0x509D90
#define KeypressHandler__ClearCommandStateArray                    0x509B60
#define KeypressHandler__HandleKeyDown                             0x5086E0
#define KeypressHandler__HandleKeyUp                               0x5089F0
#define KeypressHandler__SaveKeymapping                            0x509C30

// MapViewMap
#define MapViewMap__Clear                                          0x60C6F0
#define MapViewMap__SaveEx                                         0x60D0C0

#define OtherCharData__GetAltCurrency                              0x6D23E0

// StringTable
#define StringTable__getString                                     0x6A3DF0
