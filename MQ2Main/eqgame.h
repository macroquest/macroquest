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
#define __ExpectedVersionDate                                     "Jun 11 2009"
#define __ExpectedVersionTime                                     "14:28:00"
#define __ActualVersionDate                                        0x7E2B94
#define __ActualVersionTime                                        0x7E2BA0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x50D3C0
#define __MemChecker1                                              0x6B8BF0
#define __MemChecker2                                              0x564250
#define __MemChecker3                                              0x5641A0
#define __MemChecker4                                              0x67AAE0
#define __EncryptPad0                                              0x868710
#define __EncryptPad1                                              0x872DE8
#define __EncryptPad2                                              0x86B168
#define __EncryptPad3                                              0x86AD68
#define __EncryptPad4                                              0x8724B8
#define __AC1                                                      0x643B40
#define __AC2                                                      0x4DA105
#define __AC3                                                      0x4ED2B8
#define __AC4                                                      0x4F1048
#define __AC5                                                      0x4FB3C8
#define __AC6                                                      0x4FE67B
#define __AC7                                                      0x4F7944
#define __AC1_Data                                                 0x7CC4BA

// Direct Input
#define DI8__Main                                                  0xACA594
#define DI8__Keyboard                                              0xACA598
#define DI8__Mouse                                                 0xACA59C
#define __AltTimerReady                                            0xA54F56
#define __Attack                                                   0xAB49FA
#define __Autofire                                                 0xAB49FB
#define __BindList                                                 0x863688
#define __Clicks                                                   0xA53C68
#define __CommandList                                              0x863EF8
#define __CurrentMapLabel                                          0xAF57D0
#define __CurrentSocial                                            0x85F6A4
#define __DoAbilityAvailable                                       0xA54EF0
#define __DoAbilityList                                            0xA8A510
#define __do_loot                                                  0x4B3B70
#define __DrawHandler                                              0xB04C3C
#define __GroupCount                                               0xA4DF22
#define __Guilds                                                   0xA4FAA0
#define __gWorld                                                   0xA4F9E0
#define __HotkeyPage                                               0xAB18FC
#define __HWnd                                                     0xACA2D4
#define __InChatMode                                               0xA53BA0
#define __LastTell                                                 0xA55868
#define __LMouseHeldTime                                           0xA53C88
#define __Mouse                                                    0xACA5A0
#define __MouseLook                                                0xA53C36
#define __MouseEventTime                                           0xAB4B04
#define __NetStatusToggle                                          0xA53C39
#define __PCNames                                                  0xA552AC
#define __RangeAttackReady                                         0xA54F54
#define __RMouseHeldTime                                           0xA53C84
#define __RunWalkState                                             0xA53BA4
#define __ScreenMode                                               0x99D7F0
#define __ScreenX                                                  0xA53B58
#define __ScreenY                                                  0xA53B5C
#define __ScreenXMax                                               0xA53B60
#define __ScreenYMax                                               0xA53B64
#define __ServerHost                                               0xA4DE64
#define __ServerName                                               0xA8A4D0
#define __ShiftKeyDown                                             0xA54208
#define __ShowNames                                                0xA55180
#define __Socials                                                  0xA8A5D0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA50000
#define instEQZoneInfo                                             0xA53DD4
#define instKeypressHandler                                        0xAB4AE8
#define pinstActiveBanker                                          0xA4FA78
#define pinstActiveCorpse                                          0xA4FA7C
#define pinstActiveGMaster                                         0xA4FA80
#define pinstActiveMerchant                                        0xA4FA74
#define pinstAltAdvManager                                         0x99E650
#define pinstAuraMgr                                               0x8870B4
#define pinstBandageTarget                                         0xA4FA60
#define pinstCamActor                                              0x99E140
#define pinstCDBStr                                                0x99D7E0
#define pinstCDisplay                                              0xA4FA88
#define pinstCEverQuest                                            0xACA718
#define pinstCharData                                              0xA4FA44
#define pinstCharSpawn                                             0xA4FA6C
#define pinstControlledMissile                                     0xA4FA40
#define pinstControlledPlayer                                      0xA4FA6C
#define pinstCSidlManager                                          0xB043C0
#define pinstCXWndManager                                          0xB043B8
#define instDynamicZone                                            0xA535A8
#define pinstDZMember                                              0xA536B8
#define pinstDZTimerInfo                                           0xA536BC
#define pinstEQItemList                                            0xA4FA28
#define instEQMisc                                                 0x99D798
#define pinstEQSoundManager                                        0x99E674
#define instExpeditionLeader                                       0xA535F2
#define instExpeditionName                                         0xA53632
#define pinstGroup                                                 0xA4DF1E
#define pinstImeManager                                            0xB043C4
#define pinstLocalPlayer                                           0xA4FA58
#define pinstMercenaryData                                         0xAB4E60
#define pinstModelPlayer                                           0xA4FA84
#define pinstPCData                                                0xA4FA44
#define pinstSkillMgr                                              0xAC73B4
#define pinstSpawnManager                                          0xAC725C
#define pinstSpellManager                                          0xAC73B8
#define pinstSpellSets                                             0xAB1900
#define pinstStringTable                                           0xA4F9FC
#define pinstSwitchManager                                         0xA4DB64
#define pinstTarget                                                0xA4FA70
#define pinstTargetObject                                          0xA4FA48
#define pinstTargetSwitch                                          0xA4FA4C
#define pinstTaskMember                                            0x99D778
#define pinstTrackTarget                                           0xA4FA64
#define pinstTradeTarget                                           0xA4FA54
#define instTributeActive                                          0x99D7BD
#define pinstViewActor                                             0x99E13C
#define pinstWorldData                                             0xA4FA24


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x884960
#define pinstCAudioTriggersWindow                                  0x88492C
#define pinstCCharacterSelect                                      0x99E04C
#define pinstCFacePick                                             0x99E000
#define pinstCNoteWnd                                              0x99E004
#define pinstCBookWnd                                              0x99E008
#define pinstCPetInfoWnd                                           0x99E00C
#define pinstCTrainWnd                                             0x99E010
#define pinstCSkillsWnd                                            0x99E014
#define pinstCSkillsSelectWnd                                      0x99E018
#define pinstCCombatSkillSelectWnd                                 0x99E01C
#define pinstCFriendsWnd                                           0x99E020
#define pinstCAuraWnd                                              0x99E024
#define pinstCRespawnWnd                                           0x99E028
#define pinstCBandolierWnd                                         0x99E02C
#define pinstCPotionBeltWnd                                        0x99E030
#define pinstCAAWnd                                                0x99E034
#define pinstCGroupSearchFiltersWnd                                0x99E038
#define pinstCLoadskinWnd                                          0x99E03C
#define pinstCAlarmWnd                                             0x99E040
#define pinstCMusicPlayerWnd                                       0x99E044
#define pinstCMailWnd                                              0x99E050
#define pinstCMailCompositionWnd                                   0x99E054
#define pinstCMailAddressBookWnd                                   0x99E058
#define pinstCRaidWnd                                              0x99E060
#define pinstCRaidOptionsWnd                                       0x99E064
#define pinstCBreathWnd                                            0x99E068
#define pinstCMapViewWnd                                           0x99E06C
#define pinstCMapToolbarWnd                                        0x99E070
#define pinstCEditLabelWnd                                         0x99E074
#define pinstCTargetWnd                                            0x99E078
#define pinstCColorPickerWnd                                       0x99E07C
#define pinstCPlayerWnd                                            0x99E080
#define pinstCOptionsWnd                                           0x99E084
#define pinstCBuffWindowNORMAL                                     0x99E088
#define pinstCBuffWindowSHORT                                      0x99E08C
#define pinstCharacterCreation                                     0x99E090
#define pinstCCursorAttachment                                     0x99E094
#define pinstCCastingWnd                                           0x99E098
#define pinstCCastSpellWnd                                         0x99E09C
#define pinstCSpellBookWnd                                         0x99E0A0
#define pinstCInventoryWnd                                         0x99E0A4
#define pinstCBankWnd                                              0x99E0A8
#define pinstCQuantityWnd                                          0x99E0AC
#define pinstCLootWnd                                              0x99E0B0
#define pinstCActionsWnd                                           0x99E0B4
#define pinstCCombatAbilityWnd                                     0x99E0B8
#define pinstCMerchantWnd                                          0x99E0BC
#define pinstCTradeWnd                                             0x99E0C0
#define pinstCSelectorWnd                                          0x99E0C4
#define pinstCBazaarWnd                                            0x99E0C8
#define pinstCBazaarSearchWnd                                      0x99E0CC
#define pinstCGiveWnd                                              0x99E0D0
#define pinstCTrackingWnd                                          0x99E0D4
#define pinstCInspectWnd                                           0x99E0D8
#define pinstCSocialEditWnd                                        0x99E0DC
#define pinstCFeedbackWnd                                          0x99E0E0
#define pinstCBugReportWnd                                         0x99E0E4
#define pinstCVideoModesWnd                                        0x99E0E8
#define pinstCTextEntryWnd                                         0x99E0F0
#define pinstCFileSelectionWnd                                     0x99E0F4
#define pinstCCompassWnd                                           0x99E0F8
#define pinstCPlayerNotesWnd                                       0x99E0FC
#define pinstCGemsGameWnd                                          0x99E100
#define pinstCTimeLeftWnd                                          0x99E104
#define pinstCPetitionQWnd                                         0x99E10C
#define pinstCSoulmarkWnd                                          0x99E110
#define pinstCStoryWnd                                             0x99E114
#define pinstCJournalTextWnd                                       0x99E118
#define pinstCJournalCatWnd                                        0x99E11C
#define pinstCBodyTintWnd                                          0x99E120
#define pinstCServerListWnd                                        0x99E124
#define pinstCAvaZoneWnd                                           0x99E128
#define pinstCBlockedBuffWnd                                       0x99E12C
#define pinstCBlockedPetBuffWnd                                    0x99E130
#define pinstCInvSlotMgr                                           0x99E134
#define pinstCContainerMgr                                         0x99E138
#define pinstCAdventureLeaderboardWnd                              0xAF2D00
#define pinstCAdventureRequestWnd                                  0xAF2D1C
#define pinstCAltStorageWnd                                        0xAF2D7C
#define pinstCAdventureStatsWnd                                    0xAF2D38
#define pinstCBarterMerchantWnd                                    0xAF2F48
#define pinstCBarterSearchWnd                                      0xAF2F64
#define pinstCBarterWnd                                            0xAF2F80
#define pinstCChatManager                                          0xAF3224
#define pinstCDynamicZoneWnd                                       0xAF331C
#define pinstCEQMainWnd                                            0xAF3390
#define pinstCFellowshipWnd                                        0xAF33F4
#define pinstCFindLocationWnd                                      0xAF3428
#define pinstCGroupSearchWnd                                       0xAF34D8
#define pinstCGroupWnd                                             0xAF34F4
#define pinstCGuildBankWnd                                         0xAF3510
#define pinstCGuildMgmtWnd                                         0xAF5548
#define pinstCGuildTributeMasterWnd                                0xAF5568
#define pinstCHotButtonWnd                                         0xAF5584
#define pinstCHotButtonWnd1                                        0xAF5584
#define pinstCHotButtonWnd2                                        0xAF5588
#define pinstCHotButtonWnd3                                        0xAF558C
#define pinstCHotButtonWnd4                                        0xAF5590
#define pinstCItemDisplayManager                                   0xAF563C
#define pinstCItemExpTransferWnd                                   0xAF565C
#define pinstCLeadershipWnd                                        0xAF56F8
#define pinstCLFGuildWnd                                           0xAF5714
#define pinstCMIZoneSelectWnd                                      0xAF5884
#define pinstCAdventureMerchantWnd                                 0xAF597C
#define pinstCConfirmationDialog                                   0xAF5998
#define pinstCPopupWndManager                                      0xAF5998
#define pinstCProgressionSelectionWnd                              0xAF59CC
#define pinstCPvPLeaderboardWnd                                    0xAF59E8
#define pinstCPvPStatsWnd                                          0xAF5A04
#define pinstCSystemInfoDialogBox                                  0xAF5AB8
#define pinstCTargetOfTargetWnd                                    0xAF63C4
#define pinstCTaskSelectWnd                                        0xAF63F8
#define pinstCTaskTemplateSelectWnd                                0xAF6414
#define pinstCTaskWnd                                              0xAF6430
#define pinstCTipWndOFDAY                                          0xAF64AC
#define pinstCTipWndCONTEXT                                        0xAF64B0
#define pinstCTitleWnd                                             0xAF64CC
#define pinstCTradeskillWnd                                        0xAF6510
#define pinstCTributeBenefitWnd                                    0xAF655C
#define pinstCTributeMasterWnd                                     0xAF6578
#define pinstCContextMenuManager                                   0xB0441C
#define pinstCVoiceMacroWnd                                        0xAC759C
#define pinstCHtmlWnd                                              0xAC75D8


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C6EC0
#define __ConvertItemTags                                          0x4B8F80
#define __ExecuteCmd                                               0x4A7680
#define __get_melee_range                                          0x4ACC90
#define __GetGaugeValueFromEQ                                      0x642D80
#define __GetLabelFromEQ                                           0x643AE0
#define __NewUIINI                                                 0x642910
#define __ProcessGameEvents                                        0x4F7D30
#define CrashDetected                                              0x562F20
#define DrawNetStatus                                              0x515AB0
#define Util__FastTime                                             0x6B9300


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x480230
#define AltAdvManager__IsAbilityReady                              0x480270
#define AltAdvManager__GetAltAbility                               0x480480

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x57AE70

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x584750

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6E7550

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x59A1D0
#define CChatManager__InitContextMenu                              0x59A970

// CChatService
#define CChatService__GetNumberOfFriends                           0x6A91E0
#define CChatService__GetFriendName                                0x6A91F0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x59EB50
#define CChatWindow__Clear                                         0x59F4D0
#define CChatWindow__WndNotification                               0x59F5B0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6D20B0
#define CComboWnd__Draw                                            0x6D2260
#define CComboWnd__GetCurChoice                                    0x6D2050
#define CComboWnd__GetListRect                                     0x6D2520
#define CComboWnd__GetTextRect                                     0x6D20E0
#define CComboWnd__InsertChoice                                    0x6D2590
#define CComboWnd__SetColors                                       0x6D1FE0
#define CComboWnd__SetChoice                                       0x6D2010

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A65C0
#define CContainerWnd__vftable                                     0x7E9748

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46EC10
#define CDisplay__GetClickedActor                                  0x46C340
#define CDisplay__GetUserDefinedColor                              0x46B460
#define CDisplay__GetWorldFilePath                                 0x46A960
#define CDisplay__is3dON                                           0x469AD0
#define CDisplay__ReloadUI                                         0x47D400
#define CDisplay__WriteTextHD2                                     0x46F390

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x574E50
#define CEditBaseWnd__SetSel                                       0x6F2960

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6DAC40
#define CEditWnd__GetCharIndexPt                                   0x6DBA80
#define CEditWnd__GetDisplayString                                 0x6DADD0
#define CEditWnd__GetHorzOffset                                    0x6DB060
#define CEditWnd__GetLineForPrintableChar                          0x6DB530
#define CEditWnd__GetSelStartPt                                    0x6DBCC0
#define CEditWnd__GetSTMLSafeText                                  0x6DB1F0
#define CEditWnd__PointFromPrintableChar                           0x6DB640
#define CEditWnd__SelectableCharFromPoint                          0x6DB7C0
#define CEditWnd__SetEditable                                      0x6DB1C0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4DA7E0
#define CEverQuest__DropHeldItemOnGround                           0x4DE8A0
#define CEverQuest__dsp_chat                                       0x4DFD50
#define CEverQuest__DoTellWindow                                   0x4DEA20
#define CEverQuest__EnterZone                                      0x4F0FE0
#define CEverQuest__GetBodyTypeDesc                                0x4D7A60
#define CEverQuest__GetClassDesc                                   0x4D72A0
#define CEverQuest__GetClassThreeLetterCode                        0x4D78A0
#define CEverQuest__GetDeityDesc                                   0x4D80D0
#define CEverQuest__GetLangDesc                                    0x4D7DF0
#define CEverQuest__GetRaceDesc                                    0x4D80A0
#define CEverQuest__InterpretCmd                                   0x4E07E0
#define CEverQuest__LeftClickedOnPlayer                            0x4F28F0
#define CEverQuest__LMouseUp                                       0x4F61D0
#define CEverQuest__RightClickedOnPlayer                           0x4F69E0
#define CEverQuest__RMouseUp                                       0x4F7900
#define CEverQuest__SetGameState                                   0x4DAC70
#define CEverQuest__Emote                                          0x4DFF40

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5B3130
#define CGaugeWnd__CalcLinesFillRect                               0x5B3190
#define CGaugeWnd__Draw                                            0x5B35A0

// CGuild
#define CGuild__FindMemberByName                                   0x421420

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5CB770

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5D4DD0
#define CInvSlotMgr__MoveItem                                      0x5D4F70

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5D4670
#define CInvSlot__SliderComplete                                   0x5D37D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5E3BB0
#define CItemDisplayWnd__SetSpell                                  0x640A50

// CLabel 
#define CLabel__Draw                                               0x5E9480

// CListWnd 
#define CListWnd__AddColumn                                        0x6CC860
#define CListWnd__AddColumn1                                       0x6CC2F0
#define CListWnd__AddLine                                          0x6CBE30
#define CListWnd__AddString                                        0x6CC020
#define CListWnd__CalculateFirstVisibleLine                        0x6C90F0
#define CListWnd__CalculateVSBRange                                0x6CAE90
#define CListWnd__ClearAllSel                                      0x6C8820
#define CListWnd__CloseAndUpdateEditWindow                         0x6C9715
#define CListWnd__Compare                                          0x6C9A90
#define CListWnd__Draw                                             0x6CAB80
#define CListWnd__DrawColumnSeparators                             0x6CA9F0
#define CListWnd__DrawHeader                                       0x6C89F0
#define CListWnd__DrawItem                                         0x6CA320
#define CListWnd__DrawLine                                         0x6CA690
#define CListWnd__DrawSeparator                                    0x6CAA90
#define CListWnd__EnsureVisible                                    0x6C9140
#define CListWnd__ExtendSel                                        0x6CA240
#define CListWnd__GetColumnMinWidth                                0x6C85B0
#define CListWnd__GetColumnWidth                                   0x6C84F0
#define CListWnd__GetCurSel                                        0x6C7F00
#define CListWnd__GetHeaderRect                                    0x6C8070
#define CListWnd__GetItemAtPoint                                   0x6C9420
#define CListWnd__GetItemAtPoint1                                  0x6C9490
#define CListWnd__GetItemData                                      0x6C82A0
#define CListWnd__GetItemHeight                                    0x6C8E80
#define CListWnd__GetItemIcon                                      0x6C8430
#define CListWnd__GetItemRect                                      0x6C9210
#define CListWnd__GetItemText                                      0x6C82E0
#define CListWnd__GetSelList                                       0x6CC1D0
#define CListWnd__GetSeparatorRect                                 0x6C99D0
#define CListWnd__RemoveLine                                       0x6CC810
#define CListWnd__SetColors                                        0x6C7FD0
#define CListWnd__SetColumnJustification                           0x6C8690
#define CListWnd__SetColumnWidth                                   0x6C8570
#define CListWnd__SetCurSel                                        0x6C7F40
#define CListWnd__SetItemColor                                     0x6CBAA0
#define CListWnd__SetItemData                                      0x6C88C0
#define CListWnd__SetItemText                                      0x6CBA20
#define CListWnd__ShiftColumnSeparator                             0x6CA1B0
#define CListWnd__Sort                                             0x6CC8A0
#define CListWnd__ToggleSel                                        0x6C8790

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5FE6B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x609A20
#define CMerchantWnd__RequestBuyItem                               0x60B280
#define CMerchantWnd__RequestSellItem                              0x60B680
#define CMerchantWnd__SelectBuySellSlot                            0x60A750

// CObfuscator
#define CObfuscator__doit                                          0x684260

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6E3020
#define CSidlManager__CreateLabel                                  0x639A70

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x576E70
#define CSidlScreenWnd__CalculateVSBRange                          0x6E8B10
#define CSidlScreenWnd__ConvertToRes                               0x6F2840
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6D4120
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6D51F0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6D52A0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6D49C0
#define CSidlScreenWnd__DrawSidlPiece                              0x6D3DF0
#define CSidlScreenWnd__EnableIniStorage                           0x6D3990
#define CSidlScreenWnd__GetSidlPiece                               0x6D3FF0
#define CSidlScreenWnd__Init1                                      0x6D5060
#define CSidlScreenWnd__LoadIniInfo                                0x6D41D0
#define CSidlScreenWnd__LoadIniListWnd                             0x6D3AE0
#define CSidlScreenWnd__LoadSidlScreen                             0x6D4C10
#define CSidlScreenWnd__StoreIniInfo                               0x6D35A0
#define CSidlScreenWnd__WndNotification                            0x6D4DE0
#define CSidlScreenWnd__GetChildItem                               0x6D39F0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x538390

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6F3D00
#define CSliderWnd__SetValue                                       0x6F3E10
#define CSliderWnd__SetNumTicks                                    0x6F4380

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x63E7F0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6F0AB0
#define CStmlWnd__CalculateVSBRange                                0x6E8B10
#define CStmlWnd__CanBreakAtCharacter                              0x6E8C50
#define CStmlWnd__FastForwardToEndOfTag                            0x6E97C0
#define CStmlWnd__ForceParseNow                                    0x6F0F30
#define CStmlWnd__GetNextTagPiece                                  0x6E96E0
#define CStmlWnd__GetSTMLText                                      0x59EAF0
#define CStmlWnd__GetThisChar                                      0x7163B0
#define CStmlWnd__GetVisiableText                                  0x6EAA00
#define CStmlWnd__InitializeWindowVariables                        0x6ECBD0
#define CStmlWnd__MakeStmlColorTag                                 0x6E81B0
#define CStmlWnd__MakeWndNotificationTag                           0x6E8250
#define CStmlWnd__SetSTMLText                                      0x6ECD00
#define CStmlWnd__StripFirstSTMLLines                              0x6F0840
#define CStmlWnd__UpdateHistoryString                              0x6EB270

// CTabWnd 
#define CTabWnd__Draw                                              0x6F5110
#define CTabWnd__DrawCurrentPage                                   0x6F4B30
#define CTabWnd__DrawTab                                           0x6F4910
#define CTabWnd__GetCurrentPage                                    0x6F4DB0
#define CTabWnd__GetPageClientRect                                 0x6F45E0
#define CTabWnd__GetPageFromTabIndex                               0x6F4840
#define CTabWnd__GetPageInnerRect                                  0x6F4640
#define CTabWnd__GetTabInnerRect                                   0x6F47C0
#define CTabWnd__GetTabRect                                        0x6F46D0
#define CTabWnd__InsertPage                                        0x6F5380
#define CTabWnd__SetPage                                           0x6F4DF0
#define CTabWnd__SetPageRect                                       0x6F5040
#define CTabWnd__UpdatePage                                        0x6F5300

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x41DA10

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6D5600

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6F96D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6C7BF0

// CXRect 
#define CXRect__CenterPoint                                        0x57A500

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x41BCC0
#define CXStr__CXStr1                                              0x6C2BD0
#define CXStr__CXStr3                                              0x6BA9D0
#define CXStr__dCXStr                                              0x6CC9F0
#define CXStr__operator_equal1                                     0x6BAB90
#define CXStr__operator_plus_equal1                                0x6BBA90

// CXWnd 
#define CXWnd__BringToTop                                          0x6CCFA0
#define CXWnd__Center                                              0x6D0A30
#define CXWnd__ClrFocus                                            0x6CCCC0
#define CXWnd__DoAllDrawing                                        0x6D1850
#define CXWnd__DrawChildren                                        0x6D1980
#define CXWnd__DrawColoredRect                                     0x6CD220
#define CXWnd__DrawTooltip                                         0x6D1610
#define CXWnd__DrawTooltipAtPoint                                  0x6D07F0
#define CXWnd__GetBorderFrame                                      0x6CD700
#define CXWnd__GetChildWndAt                                       0x6D0330
#define CXWnd__GetClientClipRect                                   0x6CD610
#define CXWnd__GetScreenClipRect                                   0x6D0C50
#define CXWnd__GetScreenRect                                       0x6CD8A0
#define CXWnd__GetTooltipRect                                      0x6CD470
#define CXWnd__GetWindowTextA                                      0x56DB90
#define CXWnd__IsActive                                            0x6D6710
#define CXWnd__IsDescendantOf                                      0x6CD690
#define CXWnd__IsReallyVisible                                     0x6D0310
#define CXWnd__IsType                                              0x6F6570
#define CXWnd__Move                                                0x6CFEF0
#define CXWnd__Move1                                               0x6D1470
#define CXWnd__ProcessTransition                                   0x6CCF60
#define CXWnd__Refade                                              0x6CCD70
#define CXWnd__Resize                                              0x6CD970
#define CXWnd__Right                                               0x6D0B90
#define CXWnd__SetFocus                                            0x6CF120
#define CXWnd__SetKeyTooltip                                       0x6CDB80
#define CXWnd__SetMouseOver                                        0x6CDB50
#define CXWnd__StartFade                                           0x6CCFE0
#define CXWnd__GetChildItem                                        0x6D0DC0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6D7B90
#define CXWndManager__DrawWindows                                  0x6D77A0
#define CXWndManager__GetKeyboardFlags                             0x6D63C0
#define CXWndManager__HandleKeyboardMsg                            0x6D6910
#define CXWndManager__RemoveWnd                                    0x6D6830

// CDBStr
#define CDBStr__GetString                                          0x468440

// EQ_Character 
#define EQ_Character__CastRay                                      0x722490
#define EQ_Character__CastSpell                                    0x433D40
#define EQ_Character__Cur_HP                                       0x43D370
#define EQ_Character__GetAACastingTimeModifier                     0x429E10
#define EQ_Character__GetCharInfo2                                 0x69A360
#define EQ_Character__GetFocusCastingTimeModifier                  0x425790
#define EQ_Character__GetFocusRangeModifier                        0x4258D0
#define EQ_Character__Max_Endurance                                0x51BBF0
#define EQ_Character__Max_HP                                       0x438270
#define EQ_Character__Max_Mana                                     0x51BA20
#define EQ_Character__doCombatAbility                              0x51A930
#define EQ_Character__UseSkill                                     0x448B20
#define EQ_Character__GetConLevel                                  0x516EF0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x504D30
#define EQ_Item__GetItemLinkHash                                   0x68DD00
#define EQ_Item__IsStackable                                       0x684B40

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x481350
#define EQ_LoadingS__Array                                         0x861B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x51EA60
#define EQ_PC__GetAltAbilityIndex                                  0x692760
#define EQ_PC__GetCombatAbility                                    0x6927F0
#define EQ_PC__GetCombatAbilityTimer                               0x6928A0
#define EQ_PC__GetItemTimerValue                                   0x519880
#define EQ_PC__HasLoreItem                                         0x51CF30

// EQItemList 
#define EQItemList__dEQItemList                                    0x4AB260
#define EQItemList__EQItemList                                     0x4AB1B0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x467DF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5232C0
#define EQPlayer__dEQPlayer                                        0x527310
#define EQPlayer__DoAttack                                         0x5344B0
#define EQPlayer__EQPlayer                                         0x52AFB0
#define EQPlayer__SetNameSpriteState                               0x525290
#define EQPlayer__SetNameSpriteTint                                0x523330
#define EQPlayer__IsBodyType_j                                     0x721DA0
#define EQPlayer__IsTargetable                                     0x721F30

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x52C090
#define EQPlayerManager__GetSpawnByName                            0x52C370

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x5069D0
#define KeypressHandler__AttachKeyToEqCommand                      0x506A10
#define KeypressHandler__ClearCommandStateArray                    0x5067E0
#define KeypressHandler__HandleKeyDown                             0x505390
#define KeypressHandler__HandleKeyUp                               0x5056A0
#define KeypressHandler__SaveKeymapping                            0x5068B0

// MapViewMap 
#define MapViewMap__Clear                                          0x5F9D80
#define MapViewMap__SaveEx                                         0x5FA750

#define OtherCharData__GetAltCurrency                              0x6B19E0

// StringTable 
#define StringTable__getString                                     0x6844E0
