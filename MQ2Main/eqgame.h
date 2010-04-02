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
#define __ExpectedVersionDate                                     "Oct  3 2007"
#define __ExpectedVersionTime                                     "18:03:11"
#define __ActualVersionDate                                        0x70AF74
#define __ActualVersionTime                                        0x70AF80

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x4F8000
#define __MemChecker1                                              0x658700
#define __MemChecker2                                              0x52A360
#define __MemChecker3                                              0x52A410
#define __MemChecker4                                              0x621CC0
#define __EncryptPad0                                              0x768EB8
#define __EncryptPad1                                              0x772BC8
#define __EncryptPad2                                              0x76B420
#define __EncryptPad3                                              0x76B820
#define __EncryptPad4                                              0x7722E0

// Direct Input
#define DI8__Main                                                  0x9A10DC
#define DI8__Keyboard                                              0x9A10E0
#define DI8__Mouse                                                 0x9A10E4
#define __AltTimerReady                                            0x93CE9A
#define __Attack                                                   0x99A782
#define __Autofire                                                 0x99A783
#define __BindList                                                 0x764090
#define __Clicks                                                   0x93BFC0
#define __CommandList                                              0x764890
#define __CurrentMapLabel                                          0x9AC234
#define __CurrentSocial                                            0x760520
#define __DoAbilityAvailable                                       0x93CE34
#define __DoAbilityList                                            0x9722C8
#define __DrawHandler                                              0x9BB49C
#define __GroupCount                                               0x91C4DA
#define __GroupLeader                                              0x91C82C
#define __Guilds                                                   0x91E1F0
#define __gWorld                                                   0x91E130
#define __HotkeyPage                                               0x9996B4
#define __HWnd                                                     0x9A0E1C
#define __InChatMode                                               0x93BEF8
#define __LastTell                                                 0x93D760
#define __LMouseHeldTime                                           0x93BFE0
#define __Mouse                                                    0x9A10E8
#define __MouseLook                                                0x93BF8E
#define __NetStatusToggle                                          0x93BF90
#define __PCNames                                                  0x93D1B8
#define __RangeAttackReady                                         0x93CE98
#define __RMouseHeldTime                                           0x93BFDC
#define __RunWalkState                                             0x93BEFC
#define __ScreenMode                                               0x86BE38
#define __ScreenX                                                  0x93BEB0
#define __ScreenY                                                  0x93BEB4
#define __ScreenXMax                                               0x93BEB8
#define __ScreenYMax                                               0x93BEBC
#define __ServerHost                                               0x91C424
#define __ServerName                                               0x972288
#define __ShowNames                                                0x93D08C
#define __Socials                                                  0x972388


////
//Section 1: Vital Offsets
////
#define instCRaid                                                  0x935E40
#define instEQZoneInfo                                             0x93C12C
#define instKeypressHandler                                        0x99A86C
#define pinstActiveBanker                                          0x91E1C8
#define pinstActiveCorpse                                          0x91E1CC
#define pinstActiveGMaster                                         0x91E1D0
#define pinstActiveMerchant                                        0x91E1C4
#define pinstAltAdvManager                                         0x86CC88
#define pinstAuraMgr                                               0x777CD4
#define pinstBandageTarget                                         0x91E1B0
#define pinstCamActor                                              0x86C778
#define pinstCDBStr                                                0x86BE28
#define pinstCDisplay                                              0x91E1D8
#define pinstCEverQuest                                            0x9A1260
#define pinstCharData                                              0x91E194
#define pinstCharSpawn                                             0x91E1BC
#define pinstControlledMissile                                     0x91E190
#define pinstControlledPlayer                                      0x91E1BC
#define pinstCSidlManager                                          0x9BACD4
#define pinstCXWndManager                                          0x9BACCC
#define instDynamicZone                                            0x93B900
#define pinstDZMember                                              0x93BA10
#define pinstDZTimerInfo                                           0x93BA14
#define pinstEQItemList                                            0x91E178
#define instEQMisc                                                 0x86BDE0
#define pinstEQSoundManager                                        0x86CCAC
#define instExpeditionLeader                                       0x93B94A
#define instExpeditionName                                         0x93B98A
#define instGroup                                                  0x91C6D0
#define pinstGroup                                                 0x91C4D6
#define pinstImeManager                                            0x9BACD8
#define pinstLocalPlayer                                           0x91E1A8
#define pinstModelPlayer                                           0x91E1D4
#define pinstPCData                                                0x91E194
#define pinstSelectedItem                                          0x9AC06C
#define pinstSkillMgr                                              0x99E054
#define pinstSpawnManager                                          0x99DFD4
#define pinstSpellManager                                          0x99E058
#define pinstSpellSets                                             0x9996B8
#define pinstStringTable                                           0x91E14C
#define pinstSwitchManager                                         0x91C120
#define pinstTarget                                                0x91E1C0
#define pinstTargetObject                                          0x91E198
#define pinstTargetSwitch                                          0x91E19C
#define pinstTaskMember                                            0x86BDC0
#define pinstTrackTarget                                           0x91E1B4
#define pinstTradeTarget                                           0x91E1A4
#define instTributeActive                                          0x86BE05
#define pinstViewActor                                             0x86C774
#define pinstWorldData                                             0x91E174


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                          0x776208
#define pinstCAudioTriggersWindow                                  0x7761EC
#define pinstCCharacterSelect                                      0x86C688
#define pinstCFacePick                                             0x86C640
#define pinstCNoteWnd                                              0x86C644
#define pinstCBookWnd                                              0x86C648
#define pinstCPetInfoWnd                                           0x86C64C
#define pinstCTrainWnd                                             0x86C650
#define pinstCSkillsWnd                                            0x86C654
#define pinstCSkillsSelectWnd                                      0x86C658
#define pinstCCombatSkillSelectWnd                                 0x86C65C
#define pinstCFriendsWnd                                           0x86C660
#define pinstCAuraWnd                                              0x86C664
#define pinstCRespawnWnd                                           0x86C668
#define pinstCBandolierWnd                                         0x86C66C
#define pinstCPotionBeltWnd                                        0x86C670
#define pinstCAAWnd                                                0x86C674
#define pinstCGroupSearchFiltersWnd                                0x86C678
#define pinstCLoadskinWnd                                          0x86C67C
#define pinstCAlarmWnd                                             0x86C680
#define pinstCMusicPlayerWnd                                       0x86C684
#define pinstCMailWnd                                              0x86C68C
#define pinstCMailCompositionWnd                                   0x86C690
#define pinstCMailAddressBookWnd                                   0x86C694
#define pinstCRaidWnd                                              0x86C69C
#define pinstCRaidOptionsWnd                                       0x86C6A0
#define pinstCBreathWnd                                            0x86C6A4
#define pinstCMapViewWnd                                           0x86C6A8
#define pinstCMapToolbarWnd                                        0x86C6AC
#define pinstCEditLabelWnd                                         0x86C6B0
#define pinstCTargetWnd                                            0x86C6B4
#define pinstCColorPickerWnd                                       0x86C6B8
#define pinstCPlayerWnd                                            0x86C6BC
#define pinstCOptionsWnd                                           0x86C6C0
#define pinstCBuffWindowNORMAL                                     0x86C6C4
#define pinstCBuffWindowSHORT                                      0x86C6C8
#define pinstCharacterCreation                                     0x86C6CC
#define pinstCCursorAttachment                                     0x86C6D0
#define pinstCCastingWnd                                           0x86C6D4
#define pinstCCastSpellWnd                                         0x86C6D8
#define pinstCSpellBookWnd                                         0x86C6DC
#define pinstCInventoryWnd                                         0x86C6E0
#define pinstCBankWnd                                              0x86C6E4
#define pinstCQuantityWnd                                          0x86C6E8
#define pinstCLootWnd                                              0x86C6EC
#define pinstCActionsWnd                                           0x86C6F0
#define pinstCCombatAbilityWnd                                     0x86C6F4
#define pinstCMerchantWnd                                          0x86C6F8
#define pinstCTradeWnd                                             0x86C6FC
#define pinstCSelectorWnd                                          0x86C700
#define pinstCBazaarWnd                                            0x86C704
#define pinstCBazaarSearchWnd                                      0x86C708
#define pinstCGiveWnd                                              0x86C70C
#define pinstCTrackingWnd                                          0x86C710
#define pinstCInspectWnd                                           0x86C714
#define pinstCSocialEditWnd                                        0x86C718
#define pinstCFeedbackWnd                                          0x86C71C
#define pinstCBugReportWnd                                         0x86C720
#define pinstCVideoModesWnd                                        0x86C724
#define pinstCTextEntryWnd                                         0x86C72C
#define pinstCFileSelectionWnd                                     0x86C730
#define pinstCCompassWnd                                           0x86C734
#define pinstCPlayerNotesWnd                                       0x86C738
#define pinstCGemsGameWnd                                          0x86C73C
#define pinstCTimeLeftWnd                                          0x86C740
#define pinstCPetitionQWnd                                         0x86C744
#define pinstCSoulmarkWnd                                          0x86C748
#define pinstCStoryWnd                                             0x86C74C
#define pinstCJournalTextWnd                                       0x86C750
#define pinstCJournalCatWnd                                        0x86C754
#define pinstCBodyTintWnd                                          0x86C758
#define pinstCServerListWnd                                        0x86C75C
#define pinstCAvaZoneWnd                                           0x86C760
#define pinstCBlockedBuffWnd                                       0x86C764
#define pinstCBlockedPetBuffWnd                                    0x86C768
#define pinstCInvSlotMgr                                           0x86C76C
#define pinstCContainerMgr                                         0x86C770
#define pinstCAdventureLeaderboardWnd                              0x9A9844
#define pinstCAdventureRequestWnd                                  0x9A9860
#define pinstCAltStorageWnd                                        0x9A98C0
#define pinstCAdventureStatsWnd                                    0x9A987C
#define pinstCBarterMerchantWnd                                    0x9A9A74
#define pinstCBarterSearchWnd                                      0x9A9A90
#define pinstCBarterWnd                                            0x9A9AAC
#define pinstCChatManager                                          0x9A9CA4
#define pinstCDynamicZoneWnd                                       0x9A9D9C
#define pinstCEQMainWnd                                            0x9A9A40
#define pinstCFellowshipWnd                                        0x9A9E70
#define pinstCFindLocationWnd                                      0x9A9EA4
#define pinstCGroupSearchWnd                                       0x9A9F54
#define pinstCGroupWnd                                             0x9A9F70
#define pinstCGuildBankWnd                                         0x9A9F8C
#define pinstCGuildMgmtWnd                                         0x9ABFA8
#define pinstCGuildTributeMasterWnd                                0x9ABFC8
#define pinstCHotButtonWnd                                         0x9ABFE4
#define pinstCHotButtonWnd1                                        0x9ABFE4
#define pinstCHotButtonWnd2                                        0x9ABFE8
#define pinstCHotButtonWnd3                                        0x9ABFEC
#define pinstCHotButtonWnd4                                        0x9ABFF0
#define pinstCItemDisplayManager                                   0x9AC0A0
#define pinstCItemExpTransferWnd                                   0x9AC0C0
#define pinstCLeadershipWnd                                        0x9AC15C
#define pinstCLFGuildWnd                                           0x9AC178
#define pinstCMIZoneSelectWnd                                      0x9AC29C
#define pinstCAdventureMerchantWnd                                 0x9AC394
#define pinstCConfirmationDialog                                   0x9AC3B0
#define pinstCPopupWndManager                                      0x9AC3B0
#define pinstCProgressionSelectionWnd                              0x9AC3E4
#define pinstCPvPLeaderboardWnd                                    0x9AC400
#define pinstCPvPStatsWnd                                          0x9AC41C
#define pinstCSystemInfoDialogBox                                  0x9ACD9C
#define pinstCTargetOfTargetWnd                                    0x9ACDD0
#define pinstCTaskSelectWnd                                        0x9ACDEC
#define pinstCTaskTemplateSelectWnd                                0x9ACE08
#define pinstCTaskWnd                                              0x9ACE24
#define pinstCTipWndOFDAY                                          0x9ACEA0
#define pinstCTipWndCONTEXT                                        0x9ACEA4
#define pinstCTitleWnd                                             0x9ACEC0
#define pinstCTradeskillWnd                                        0x9ACF04
#define pinstCTributeBenefitWnd                                    0x9ACF50
#define pinstCTributeMasterWnd                                     0x9ACF6C
#define pinstCContextMenuManager                                   0x9BAD94
#define pinstCVoiceMacroWnd                                        0x99E13C
#define pinstCHtmlWnd                                              0x99E158


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                                  0x4B55F0
#define __ConvertItemTags                                          0x4A8C90
#define __ExecuteCmd                                               0x498310
#define __get_melee_range                                          0x49D510
#define __GetGaugeValueFromEQ                                      0x5F3A40
#define __GetLabelFromEQ                                           0x5F4250
#define __NewUIINI                                                 0x5F3630
#define __ProcessGameEvents                                        0x4E3B10
#define CrashDetected                                              0x529300
#define DrawNetStatus                                              0x4FADE0
#define Util__FastTime                                             0x658D50


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x472030
#define AltAdvManager__IsAbilityReady                              0x472070
#define AltAdvManager__GetAltAbility                               0x4721C0

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x5407B0

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x54A0F0

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x6758F0

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x55EB60
#define CChatManager__InitContextMenu                              0x55F2F0

// CChatService
#define CChatService__GetNumberOfFriends                           0x649760
#define CChatService__GetFriendName                                0x649770

// CChatWindow
#define CChatWindow__CChatWindow                                   0x563460
#define CChatWindow__WndNotification                               0x563E80

// CComboWnd
#define CComboWnd__DeleteAll                                       0x66A960
#define CComboWnd__Draw                                            0x66AB10
#define CComboWnd__GetCurChoice                                    0x66A900
#define CComboWnd__GetListRect                                     0x66ADE0
#define CComboWnd__GetTextRect                                     0x66A990
#define CComboWnd__InsertChoice                                    0x66AE50
#define CComboWnd__SetColors                                       0x66A890
#define CComboWnd__SetChoice                                       0x66A8C0

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x56A8F0
#define CContainerWnd__vftable                                     0x7119F8

// CDisplay
#define CDisplay__CleanGameUI                                      0x461050
#define CDisplay__GetClickedActor                                  0x45E8A0
#define CDisplay__GetUserDefinedColor                              0x45DD30
#define CDisplay__GetWorldFilePath                                 0x45D2A0
#define CDisplay__is3dON                                           0x45C420
#define CDisplay__ReloadUI                                         0x46CE90
#define CDisplay__WriteTextHD2                                     0x461750

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x53A2C0
#define CEditBaseWnd__SetSel                                       0x68E2D0

// CEditWnd
#define CEditWnd__DrawCaret                                        0x68B840
#define CEditWnd__GetCharIndexPt                                   0x68C690
#define CEditWnd__GetDisplayString                                 0x68B9D0
#define CEditWnd__GetHorzOffset                                    0x68BC70
#define CEditWnd__GetLineForPrintableChar                          0x68C140
#define CEditWnd__GetSelStartPt                                    0x68C8D0
#define CEditWnd__GetSTMLSafeText                                  0x68BE00
#define CEditWnd__PointFromPrintableChar                           0x68C250
#define CEditWnd__SelectableCharFromPoint                          0x68C3D0
#define CEditWnd__SetEditable                                      0x68BDD0

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x4C79C0
#define CEverQuest__DropHeldItemOnGround                           0x4CC300
#define CEverQuest__dsp_chat                                       0x4CD180
#define CEverQuest__DoTellWindow                                   0x4CC480
#define CEverQuest__EnterZone                                      0x4E2570
#define CEverQuest__GetBodyTypeDesc                                0x4C4A90
#define CEverQuest__GetClassDesc                                   0x4C41F0
#define CEverQuest__GetClassThreeLetterCode                        0x4C47F0
#define CEverQuest__GetDeityDesc                                   0x4C5100
#define CEverQuest__GetLangDesc                                    0x4C4E20
#define CEverQuest__GetRaceDesc                                    0x4C50D0
#define CEverQuest__InterpretCmd                                   0x4CDBB0
#define CEverQuest__LeftClickedOnPlayer                            0x4E0DB0
#define CEverQuest__LMouseUp                                       0x4E32F0
#define CEverQuest__RightClickedOnPlayer                           0x4E1180
#define CEverQuest__RMouseUp                                       0x4E2B70
#define CEverQuest__SetGameState                                   0x4C7E40
#define CEverQuest__Emote                                          0x4CD350

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x575D60
#define CGaugeWnd__CalcLinesFillRect                               0x575DD0
#define CGaugeWnd__Draw                                            0x576160

// CGuild
#define CGuild__FindMemberByName                                   0x416250

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x58C540

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x5959E0
#define CInvSlotMgr__MoveItem                                      0x595B80

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x596B00

// CInvSLot
#define CInvSlot__SliderComplete                                   0x5948E0

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                                   0x5A4850
#define CItemDisplayWnd__SetSpell                                  0x5F18F0

// CLabel
#define CLabel__Draw                                               0x5AA090

// CListWnd
#define CListWnd__AddColumn                                        0x66A6A0
#define CListWnd__AddColumn1                                       0x66A1E0
#define CListWnd__AddLine                                          0x669D70
#define CListWnd__AddString                                        0x669F40
#define CListWnd__CalculateFirstVisibleLine                        0x6670A0
#define CListWnd__CalculateVSBRange                                0x668D10
#define CListWnd__ClearAllSel                                      0x666820
#define CListWnd__CloseAndUpdateEditWindow                         0x6676C0
#define CListWnd__Compare                                          0x667A70
#define CListWnd__Draw                                             0x668A10
#define CListWnd__DrawColumnSeparators                             0x668880
#define CListWnd__DrawHeader                                       0x6669F0
#define CListWnd__DrawItem                                         0x668180
#define CListWnd__DrawLine                                         0x668530
#define CListWnd__DrawSeparator                                    0x668920
#define CListWnd__EnsureVisible                                    0x6670F0
#define CListWnd__ExtendSel                                        0x6680B0
#define CListWnd__GetColumnMinWidth                                0x6665C0
#define CListWnd__GetColumnWidth                                   0x666500
#define CListWnd__GetCurSel                                        0x665FD0
#define CListWnd__GetHeaderRect                                    0x6660D0
#define CListWnd__GetItemAtPoint                                   0x6673D0
#define CListWnd__GetItemAtPoint1                                  0x667440
#define CListWnd__GetItemData                                      0x6662B0
#define CListWnd__GetItemHeight                                    0x666E50
#define CListWnd__GetItemIcon                                      0x666440
#define CListWnd__GetItemRect                                      0x6671C0
#define CListWnd__GetItemText                                      0x6662F0
#define CListWnd__GetSelList                                       0x66A0C0
#define CListWnd__GetSeparatorRect                                 0x6679B0
#define CListWnd__RemoveLine                                       0x66A070
#define CListWnd__SetColors                                        0x666030
#define CListWnd__SetColumnJustification                           0x666620
#define CListWnd__SetColumnWidth                                   0x666580
#define CListWnd__SetCurSel                                        0x666010
#define CListWnd__SetItemColor                                     0x669940
#define CListWnd__SetItemData                                      0x6668C0
#define CListWnd__SetItemText                                      0x6698C0
#define CListWnd__ShiftColumnSeparator                             0x668020
#define CListWnd__Sort                                             0x66A6D0
#define CListWnd__ToggleSel                                        0x666790

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x5BDF30

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5BF9F0
#define CMerchantWnd__RequestBuyItem                               0x5C0D40
#define CMerchantWnd__RequestSellItem                              0x5BFC40
#define CMerchantWnd__SelectBuySellSlot                            0x5C0A80

// CObfuscator
#define CObfuscator__doit                                          0x631330

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x67A490

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x53BE40
#define CSidlScreenWnd__CalculateVSBRange                          0x53BD80
#define CSidlScreenWnd__ConvertToRes                               0x68E1B0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x671CA0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x672A90
#define CSidlScreenWnd__CSidlScreenWnd2                            0x672B40
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6724E0
#define CSidlScreenWnd__DrawSidlPiece                              0x671980
#define CSidlScreenWnd__EnableIniStorage                           0x6714A0
#define CSidlScreenWnd__GetSidlPiece                               0x671B80
#define CSidlScreenWnd__Init1                                      0x672900
#define CSidlScreenWnd__LoadIniInfo                                0x671D50
#define CSidlScreenWnd__LoadIniListWnd                             0x6715E0
#define CSidlScreenWnd__LoadSidlScreen                             0x6717A0
#define CSidlScreenWnd__StoreIniInfo                               0x6710B0
#define CSidlScreenWnd__WndNotification                            0x6718E0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x51B4B0

// CSliderWnd
#define CSliderWnd__GetValue                                       0x68EEA0
#define CSliderWnd__SetValue                                       0x68EFA0
#define CSliderWnd__SetNumTicks                                    0x68F4D0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x5F0580

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x684900
#define CStmlWnd__CalculateVSBRange                                0x67CCD0
#define CStmlWnd__CanBreakAtCharacter                              0x67CE10
#define CStmlWnd__FastForwardToEndOfTag                            0x67D910
#define CStmlWnd__GetNextTagPiece                                  0x67D830
#define CStmlWnd__GetSTMLText                                      0x563400
#define CStmlWnd__GetThisChar                                      0x6AD860
#define CStmlWnd__GetVisiableText                                  0x67EB40
#define CStmlWnd__InitializeWindowVariables                        0x680C90
#define CStmlWnd__MakeStmlColorTag                                 0x67C350
#define CStmlWnd__MakeWndNotificationTag                           0x67C3F0
#define CStmlWnd__StripFirstSTMLLines                              0x684690
#define CStmlWnd__UpdateHistoryString                              0x67F390

// CTabWnd
#define CTabWnd__Draw                                              0x690270
#define CTabWnd__DrawCurrentPage                                   0x68FC70
#define CTabWnd__DrawTab                                           0x68FA50
#define CTabWnd__GetCurrentPage                                    0x68FEF0
#define CTabWnd__GetPageClientRect                                 0x68F720
#define CTabWnd__GetPageFromTabIndex                               0x68F980
#define CTabWnd__GetPageInnerRect                                  0x68F780
#define CTabWnd__GetTabInnerRect                                   0x68F900
#define CTabWnd__GetTabRect                                        0x68F810
#define CTabWnd__IndexInBounds                                     0x68FA1D
#define CTabWnd__InsertPage                                        0x690490
#define CTabWnd__SetPage                                           0x68FF30
#define CTabWnd__SetPageRect                                       0x6901A0
#define CTabWnd__UpdatePage                                        0x690410

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x4127C0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x672EA0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x6969B0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x665D40

// CXRect
#define CXRect__CenterPoint                                        0x53FF00

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x412360
#define CXStr__CXStr1                                              0x660D20
#define CXStr__CXStr3                                              0x65A490
#define CXStr__dCXStr                                              0x472A30
#define CXStr__operator_equal1                                     0x65A650
#define CXStr__operator_plus_equal1                                0x65B540

// CXWnd
#define CXWnd__BringToTop                                          0x66B6E0
#define CXWnd__Center                                              0x66F2A0
#define CXWnd__ClrFocus                                            0x66B3C0
#define CXWnd__DoAllDrawing                                        0x66FD30
#define CXWnd__DrawChildren                                        0x66FE60
#define CXWnd__DrawColoredRect                                     0x66B980
#define CXWnd__DrawTooltip                                         0x66FC50
#define CXWnd__DrawTooltipAtPoint                                  0x66F080
#define CXWnd__GetBorderFrame                                      0x66BE50
#define CXWnd__GetChildWndAt                                       0x66EB20
#define CXWnd__GetClientClipRect                                   0x66BD80
#define CXWnd__GetFirstChildWnd                                    0x66B780
#define CXWnd__GetNextChildWnd                                     0x66EAE0
#define CXWnd__GetNextSib                                          0x66B7A0
#define CXWnd__GetScreenClipRect                                   0x66F4C0
#define CXWnd__GetScreenRect                                       0x66C000
#define CXWnd__GetTooltipRect                                      0x66BBB0
#define CXWnd__GetWindowTextA                                      0x533430
#define CXWnd__IsActive                                            0x686940
#define CXWnd__IsDescendantOf                                      0x66BE00
#define CXWnd__IsReallyVisible                                     0x66EAC0
#define CXWnd__IsType                                              0x6913B0
#define CXWnd__Move                                                0x66E580
#define CXWnd__Move1                                               0x66E620
#define CXWnd__ProcessTransition                                   0x66B6B0
#define CXWnd__Refade                                              0x66B470
#define CXWnd__Resize                                              0x66C0D0
#define CXWnd__Right                                               0x66F400
#define CXWnd__SetFirstChildPointer                                0x66C2D0
#define CXWnd__SetFocus                                            0x66D600
#define CXWnd__SetKeyTooltip                                       0x66C330
#define CXWnd__SetMouseOver                                        0x66C300
#define CXWnd__SetNextSibPointer                                   0x66C2F0
#define CXWnd__StartFade                                           0x66B700

// CXWndManager
#define CXWndManager__DrawCursor                                   0x687E00
#define CXWndManager__DrawWindows                                  0x687A40
#define CXWndManager__GetFirstChildWnd                             0x6872D0
#define CXWndManager__GetKeyboardFlags                             0x686600
#define CXWndManager__HandleKeyboardMsg                            0x686B30
#define CXWndManager__RemoveWnd                                    0x686A50

// CDBStr
#define CDBStr__GetString                                          0x45ACC0

// EQ_Character
#define EQ_Character__CastRay                                      0x6B96E0
#define EQ_Character__CastSpell                                    0x422CC0
#define EQ_Character__Cur_HP                                       0x42A920
#define EQ_Character__GetAACastingTimeModifier                     0x41DD80
#define EQ_Character__GetCharInfo2                                 0x631A70
#define EQ_Character__GetFocusCastingTimeModifier                  0x419D60
#define EQ_Character__GetFocusRangeModifier                        0x419E90
#define EQ_Character__Max_Endurance                                0x429510
#define EQ_Character__Max_HP                                       0x4293C0
#define EQ_Character__Max_Mana                                     0x5000D0
#define EQ_Character__doCombatAbility                              0x4FEF50
#define EQ_Character__UseSkill                                     0x436870
#define EQ_Character__GetConLevel                                  0x4FC1C0

// EQ_Item
#define EQ_Item__CanDrop                                           0x4F0340
#define EQ_Item__GetItemLinkHash                                   0x630990
#define EQ_Item__IsStackable                                       0x6277F0

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar                                0x473120
#define EQ_LoadingS__Array                                         0x7625A0

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x503240
#define EQ_PC__GetAltAbilityIndex                                  0x6368C0
#define EQ_PC__GetCombatAbility                                    0x636950
#define EQ_PC__GetCombatAbilityTimer                               0x636A00
#define EQ_PC__GetItemTimerValue                                   0x4FDF70
#define EQ_PC__HasLoreItem                                         0x501690

// EQItemList
#define EQItemList__dEQItemList                                    0x49BC70
#define EQItemList__EQItemList                                     0x49BBC0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45A590

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x507EE0
#define EQPlayer__dEQPlayer                                        0x50C640
#define EQPlayer__DoAttack                                         0x517FF0
#define EQPlayer__EQPlayer                                         0x50F1A0
#define EQPlayer__SetNameSpriteState                               0x50A6F0
#define EQPlayer__SetNameSpriteTint                                0x507F50
#define EQPlayer__IsBodyType_j                                     0x6B90E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x510130

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F1F20
#define KeypressHandler__AttachKeyToEqCommand                      0x4F1F60
#define KeypressHandler__ClearCommandStateArray                    0x4F1D30
#define KeypressHandler__HandleKeyDown                             0x4F0930
#define KeypressHandler__HandleKeyUp                               0x4F0C30
#define KeypressHandler__SaveKeymapping                            0x4F1E00

// MapViewMap
#define MapViewMap__Clear                                          0x5B9F40
#define MapViewMap__SaveEx                                         0x5BA910

#define OtherCharData__GetAltCurrency                              0x651AA0

// StringTable
#define StringTable__getString                                     0x627180 
