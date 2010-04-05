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
#define __ExpectedVersionDate                                     "May 20 2009"
#define __ExpectedVersionTime                                     "15:19:28"
#define __ActualVersionDate                                        0x7E1B84
#define __ActualVersionTime                                        0x7E1B90

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x50C840
#define __MemChecker1                                              0x6B7A70
#define __MemChecker2                                              0x563400
#define __MemChecker3                                              0x563350
#define __MemChecker4                                              0x679C70
#define __EncryptPad0                                              0x867710
#define __EncryptPad1                                              0x871DE8
#define __EncryptPad2                                              0x86A168
#define __EncryptPad3                                              0x869D68
#define __EncryptPad4                                              0x8714B8

// Direct Input
#define DI8__Main                                                  0xAC9594
#define DI8__Keyboard                                              0xAC9598
#define DI8__Mouse                                                 0xAC959C
#define __AltTimerReady                                            0xA53F56
#define __Attack                                                   0xAB39FA
#define __Autofire                                                 0xAB39FB
#define __BindList                                                 0x862688
#define __Clicks                                                   0xA52C68
#define __CommandList                                              0x862EF8
#define __CurrentMapLabel                                          0xAF47D0
#define __CurrentSocial                                            0x85E6A4
#define __DoAbilityAvailable                                       0xA53EF0
#define __DoAbilityList                                            0xA89510
#define __do_loot                                                  0x4B3A90
#define __DrawHandler                                              0xB03C3C
#define __GroupCount                                               0xA4CF22
#define __Guilds                                                   0xA4EAA0
#define __gWorld                                                   0xA4E9E0
#define __HotkeyPage                                               0xAB08FC
#define __HWnd                                                     0xAC92D4
#define __InChatMode                                               0xA52BA0
#define __LastTell                                                 0xA54868
#define __LMouseHeldTime                                           0xA52C88
#define __Mouse                                                    0xAC95A0
#define __MouseLook                                                0xA52C36
#define __MouseEventTime                                           0xAB3B04
#define __NetStatusToggle                                          0xA52C39
#define __PCNames                                                  0xA542AC
#define __RangeAttackReady                                         0xA53F54
#define __RMouseHeldTime                                           0xA52C84
#define __RunWalkState                                             0xA52BA4
#define __ScreenMode                                               0x99C7F0
#define __ScreenX                                                  0xA52B58
#define __ScreenY                                                  0xA52B5C
#define __ScreenXMax                                               0xA52B60
#define __ScreenYMax                                               0xA52B64
#define __ServerHost                                               0xA4CE64
#define __ServerName                                               0xA894D0
#define __ShiftKeyDown                                             0xA53208
#define __ShowNames                                                0xA54180
#define __Socials                                                  0xA895D0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA4F000
#define instEQZoneInfo                                             0xA52DD4
#define instKeypressHandler                                        0xAB3AE8
#define pinstActiveBanker                                          0xA4EA78
#define pinstActiveCorpse                                          0xA4EA7C
#define pinstActiveGMaster                                         0xA4EA80
#define pinstActiveMerchant                                        0xA4EA74
#define pinstAltAdvManager                                         0x99D650
#define pinstAuraMgr                                               0x8860B4
#define pinstBandageTarget                                         0xA4EA60
#define pinstCamActor                                              0x99D140
#define pinstCDBStr                                                0x99C7E0
#define pinstCDisplay                                              0xA4EA88
#define pinstCEverQuest                                            0xAC9718
#define pinstCharData                                              0xA4EA44
#define pinstCharSpawn                                             0xA4EA6C
#define pinstControlledMissile                                     0xA4EA40
#define pinstControlledPlayer                                      0xA4EA6C
#define pinstCSidlManager                                          0xB033C0
#define pinstCXWndManager                                          0xB033B8
#define instDynamicZone                                            0xA525A8
#define pinstDZMember                                              0xA526B8
#define pinstDZTimerInfo                                           0xA526BC
#define pinstEQItemList                                            0xA4EA28
#define instEQMisc                                                 0x99C798
#define pinstEQSoundManager                                        0x99D674
#define instExpeditionLeader                                       0xA525F2
#define instExpeditionName                                         0xA52632
#define pinstGroup                                                 0xA4CF1E
#define pinstImeManager                                            0xB033C4
#define pinstLocalPlayer                                           0xA4EA58
#define pinstMercenaryData                                         0xAB3E60
#define pinstModelPlayer                                           0xA4EA84
#define pinstPCData                                                0xA4EA44
#define pinstSkillMgr                                              0xAC63B4
#define pinstSpawnManager                                          0xAC625C
#define pinstSpellManager                                          0xAC63B8
#define pinstSpellSets                                             0xAB0900
#define pinstStringTable                                           0xA4E9FC
#define pinstSwitchManager                                         0xA4CB64
#define pinstTarget                                                0xA4EA70
#define pinstTargetObject                                          0xA4EA48
#define pinstTargetSwitch                                          0xA4EA4C
#define pinstTaskMember                                            0x99C778
#define pinstTrackTarget                                           0xA4EA64
#define pinstTradeTarget                                           0xA4EA54
#define instTributeActive                                          0x99C7BD
#define pinstViewActor                                             0x99D13C
#define pinstWorldData                                             0xA4EA24


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x883960
#define pinstCAudioTriggersWindow                                  0x88392C
#define pinstCCharacterSelect                                      0x99D04C
#define pinstCFacePick                                             0x99D000
#define pinstCNoteWnd                                              0x99D004
#define pinstCBookWnd                                              0x99D008
#define pinstCPetInfoWnd                                           0x99D00C
#define pinstCTrainWnd                                             0x99D010
#define pinstCSkillsWnd                                            0x99D014
#define pinstCSkillsSelectWnd                                      0x99D018
#define pinstCCombatSkillSelectWnd                                 0x99D01C
#define pinstCFriendsWnd                                           0x99D020
#define pinstCAuraWnd                                              0x99D024
#define pinstCRespawnWnd                                           0x99D028
#define pinstCBandolierWnd                                         0x99D02C
#define pinstCPotionBeltWnd                                        0x99D030
#define pinstCAAWnd                                                0x99D034
#define pinstCGroupSearchFiltersWnd                                0x99D038
#define pinstCLoadskinWnd                                          0x99D03C
#define pinstCAlarmWnd                                             0x99D040
#define pinstCMusicPlayerWnd                                       0x99D044
#define pinstCMailWnd                                              0x99D050
#define pinstCMailCompositionWnd                                   0x99D054
#define pinstCMailAddressBookWnd                                   0x99D058
#define pinstCRaidWnd                                              0x99D060
#define pinstCRaidOptionsWnd                                       0x99D064
#define pinstCBreathWnd                                            0x99D068
#define pinstCMapViewWnd                                           0x99D06C
#define pinstCMapToolbarWnd                                        0x99D070
#define pinstCEditLabelWnd                                         0x99D074
#define pinstCTargetWnd                                            0x99D078
#define pinstCColorPickerWnd                                       0x99D07C
#define pinstCPlayerWnd                                            0x99D080
#define pinstCOptionsWnd                                           0x99D084
#define pinstCBuffWindowNORMAL                                     0x99D088
#define pinstCBuffWindowSHORT                                      0x99D08C
#define pinstCharacterCreation                                     0x99D090
#define pinstCCursorAttachment                                     0x99D094
#define pinstCCastingWnd                                           0x99D098
#define pinstCCastSpellWnd                                         0x99D09C
#define pinstCSpellBookWnd                                         0x99D0A0
#define pinstCInventoryWnd                                         0x99D0A4
#define pinstCBankWnd                                              0x99D0A8
#define pinstCQuantityWnd                                          0x99D0AC
#define pinstCLootWnd                                              0x99D0B0
#define pinstCActionsWnd                                           0x99D0B4
#define pinstCCombatAbilityWnd                                     0x99D0B8
#define pinstCMerchantWnd                                          0x99D0BC
#define pinstCTradeWnd                                             0x99D0C0
#define pinstCSelectorWnd                                          0x99D0C4
#define pinstCBazaarWnd                                            0x99D0C8
#define pinstCBazaarSearchWnd                                      0x99D0CC
#define pinstCGiveWnd                                              0x99D0D0
#define pinstCTrackingWnd                                          0x99D0D4
#define pinstCInspectWnd                                           0x99D0D8
#define pinstCSocialEditWnd                                        0x99D0DC
#define pinstCFeedbackWnd                                          0x99D0E0
#define pinstCBugReportWnd                                         0x99D0E4
#define pinstCVideoModesWnd                                        0x99D0E8
#define pinstCTextEntryWnd                                         0x99D0F0
#define pinstCFileSelectionWnd                                     0x99D0F4
#define pinstCCompassWnd                                           0x99D0F8
#define pinstCPlayerNotesWnd                                       0x99D0FC
#define pinstCGemsGameWnd                                          0x99D100
#define pinstCTimeLeftWnd                                          0x99D104
#define pinstCPetitionQWnd                                         0x99D10C
#define pinstCSoulmarkWnd                                          0x99D110
#define pinstCStoryWnd                                             0x99D114
#define pinstCJournalTextWnd                                       0x99D118
#define pinstCJournalCatWnd                                        0x99D11C
#define pinstCBodyTintWnd                                          0x99D120
#define pinstCServerListWnd                                        0x99D124
#define pinstCAvaZoneWnd                                           0x99D128
#define pinstCBlockedBuffWnd                                       0x99D12C
#define pinstCBlockedPetBuffWnd                                    0x99D130
#define pinstCInvSlotMgr                                           0x99D134
#define pinstCContainerMgr                                         0x99D138
#define pinstCAdventureLeaderboardWnd                              0xAF1D00
#define pinstCAdventureRequestWnd                                  0xAF1D1C
#define pinstCAltStorageWnd                                        0xAF1D7C
#define pinstCAdventureStatsWnd                                    0xAF1D38
#define pinstCBarterMerchantWnd                                    0xAF1F48
#define pinstCBarterSearchWnd                                      0xAF1F64
#define pinstCBarterWnd                                            0xAF1F80
#define pinstCChatManager                                          0xAF2224
#define pinstCDynamicZoneWnd                                       0xAF231C
#define pinstCEQMainWnd                                            0xAF2390
#define pinstCFellowshipWnd                                        0xAF23F4
#define pinstCFindLocationWnd                                      0xAF2428
#define pinstCGroupSearchWnd                                       0xAF24D8
#define pinstCGroupWnd                                             0xAF24F4
#define pinstCGuildBankWnd                                         0xAF2510
#define pinstCGuildMgmtWnd                                         0xAF4548
#define pinstCGuildTributeMasterWnd                                0xAF4568
#define pinstCHotButtonWnd                                         0xAF4584
#define pinstCHotButtonWnd1                                        0xAF4584
#define pinstCHotButtonWnd2                                        0xAF4588
#define pinstCHotButtonWnd3                                        0xAF458C
#define pinstCHotButtonWnd4                                        0xAF4590
#define pinstCItemDisplayManager                                   0xAF463C
#define pinstCItemExpTransferWnd                                   0xAF465C
#define pinstCLeadershipWnd                                        0xAF46F8
#define pinstCLFGuildWnd                                           0xAF4714
#define pinstCMIZoneSelectWnd                                      0xAF4884
#define pinstCAdventureMerchantWnd                                 0xAF497C
#define pinstCConfirmationDialog                                   0xAF4998
#define pinstCPopupWndManager                                      0xAF4998
#define pinstCProgressionSelectionWnd                              0xAF49CC
#define pinstCPvPLeaderboardWnd                                    0xAF49E8
#define pinstCPvPStatsWnd                                          0xAF4A04
#define pinstCSystemInfoDialogBox                                  0xAF4AB8
#define pinstCTargetOfTargetWnd                                    0xAF53C4
#define pinstCTaskSelectWnd                                        0xAF53F8
#define pinstCTaskTemplateSelectWnd                                0xAF5414
#define pinstCTaskWnd                                              0xAF5430
#define pinstCTipWndOFDAY                                          0xAF54AC
#define pinstCTipWndCONTEXT                                        0xAF54B0
#define pinstCTitleWnd                                             0xAF54CC
#define pinstCTradeskillWnd                                        0xAF5510
#define pinstCTributeBenefitWnd                                    0xAF555C
#define pinstCTributeMasterWnd                                     0xAF5578
#define pinstCContextMenuManager                                   0xB0341C
#define pinstCVoiceMacroWnd                                        0xAC659C
#define pinstCHtmlWnd                                              0xAC65D8


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C6E50
#define __ConvertItemTags                                          0x4B8EA0
#define __ExecuteCmd                                               0x4A7520
#define __get_melee_range                                          0x4ACBB0
#define __GetGaugeValueFromEQ                                      0x641DC0
#define __GetLabelFromEQ                                           0x642AE0
#define __NewUIINI                                                 0x6419A0
#define __ProcessGameEvents                                        0x4F70E0
#define CrashDetected                                              0x5620D0
#define DrawNetStatus                                              0x514ED0
#define Util__FastTime                                             0x6B81C0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x480050
#define AltAdvManager__IsAbilityReady                              0x480090
#define AltAdvManager__GetAltAbility                               0x4802B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x579F80

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x583330

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6E6440

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x599290
#define CChatManager__InitContextMenu                              0x599A30

// CChatService
#define CChatService__GetNumberOfFriends                           0x6A80A0
#define CChatService__GetFriendName                                0x6A80B0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x59DC10
#define CChatWindow__Clear                                         0x59E580
#define CChatWindow__WndNotification                               0x59E660

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6D0CA0
#define CComboWnd__Draw                                            0x6D0E50
#define CComboWnd__GetCurChoice                                    0x6D0C40
#define CComboWnd__GetListRect                                     0x6D1110
#define CComboWnd__GetTextRect                                     0x6D0CD0
#define CComboWnd__InsertChoice                                    0x6D1180
#define CComboWnd__SetColors                                       0x6D0BD0
#define CComboWnd__SetChoice                                       0x6D0C00

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A5620
#define CContainerWnd__vftable                                     0x7E8738

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46EA60
#define CDisplay__GetClickedActor                                  0x46C180
#define CDisplay__GetUserDefinedColor                              0x46B2A0
#define CDisplay__GetWorldFilePath                                 0x46A7A0
#define CDisplay__is3dON                                           0x469910
#define CDisplay__ReloadUI                                         0x47D220
#define CDisplay__WriteTextHD2                                     0x46F1F0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x573F90
#define CEditBaseWnd__SetSel                                       0x6F1810

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6D9860
#define CEditWnd__GetCharIndexPt                                   0x6DA6A0
#define CEditWnd__GetDisplayString                                 0x6D99F0
#define CEditWnd__GetHorzOffset                                    0x6D9C80
#define CEditWnd__GetLineForPrintableChar                          0x6DA150
#define CEditWnd__GetSelStartPt                                    0x6DA8E0
#define CEditWnd__GetSTMLSafeText                                  0x6D9E10
#define CEditWnd__PointFromPrintableChar                           0x6DA260
#define CEditWnd__SelectableCharFromPoint                          0x6DA3E0
#define CEditWnd__SetEditable                                      0x6D9DE0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4DA690
#define CEverQuest__DropHeldItemOnGround                           0x4DE700
#define CEverQuest__dsp_chat                                       0x4DFBB0
#define CEverQuest__DoTellWindow                                   0x4DE880
#define CEverQuest__EnterZone                                      0x4F0390
#define CEverQuest__GetBodyTypeDesc                                0x4D7910
#define CEverQuest__GetClassDesc                                   0x4D7150
#define CEverQuest__GetClassThreeLetterCode                        0x4D7750
#define CEverQuest__GetDeityDesc                                   0x4D7F80
#define CEverQuest__GetLangDesc                                    0x4D7CA0
#define CEverQuest__GetRaceDesc                                    0x4D7F50
#define CEverQuest__InterpretCmd                                   0x4E0640
#define CEverQuest__LeftClickedOnPlayer                            0x4F1CA0
#define CEverQuest__LMouseUp                                       0x4F5580
#define CEverQuest__RightClickedOnPlayer                           0x4F5D90
#define CEverQuest__RMouseUp                                       0x4F6CB0
#define CEverQuest__SetGameState                                   0x4DAB20
#define CEverQuest__Emote                                          0x4DFDA0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5B2050
#define CGaugeWnd__CalcLinesFillRect                               0x5B20B0
#define CGaugeWnd__Draw                                            0x5B24C0

// CGuild
#define CGuild__FindMemberByName                                   0x4214B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5CA690

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5D3CB0
#define CInvSlotMgr__MoveItem                                      0x5D3E50

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5D3550
#define CInvSlot__SliderComplete                                   0x5D26B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5E2A30
#define CItemDisplayWnd__SetSpell                                  0x63FA80

// CLabel 
#define CLabel__Draw                                               0x5E8320

// CListWnd 
#define CListWnd__AddColumn                                        0x6CB4C0
#define CListWnd__AddColumn1                                       0x6CAFA0
#define CListWnd__AddLine                                          0x6CAA90
#define CListWnd__AddString                                        0x6CAC80
#define CListWnd__CalculateFirstVisibleLine                        0x6C7D50
#define CListWnd__CalculateVSBRange                                0x6C9AF0
#define CListWnd__ClearAllSel                                      0x6C7480
#define CListWnd__CloseAndUpdateEditWindow                         0x6C8375
#define CListWnd__Compare                                          0x6C86F0
#define CListWnd__Draw                                             0x6C97E0
#define CListWnd__DrawColumnSeparators                             0x6C9650
#define CListWnd__DrawHeader                                       0x6C7650
#define CListWnd__DrawItem                                         0x6C8F80
#define CListWnd__DrawLine                                         0x6C92F0
#define CListWnd__DrawSeparator                                    0x6C96F0
#define CListWnd__EnsureVisible                                    0x6C7DA0
#define CListWnd__ExtendSel                                        0x6C8EA0
#define CListWnd__GetColumnMinWidth                                0x6C7210
#define CListWnd__GetColumnWidth                                   0x6C7150
#define CListWnd__GetCurSel                                        0x6C6B60
#define CListWnd__GetHeaderRect                                    0x6C6CD0
#define CListWnd__GetItemAtPoint                                   0x6C8080
#define CListWnd__GetItemAtPoint1                                  0x6C80F0
#define CListWnd__GetItemData                                      0x6C6F00
#define CListWnd__GetItemHeight                                    0x6C7AE0
#define CListWnd__GetItemIcon                                      0x6C7090
#define CListWnd__GetItemRect                                      0x6C7E70
#define CListWnd__GetItemText                                      0x6C6F40
#define CListWnd__GetSelList                                       0x6CAE80
#define CListWnd__GetSeparatorRect                                 0x6C8630
#define CListWnd__RemoveLine                                       0x6CAE30
#define CListWnd__SetColors                                        0x6C6C30
#define CListWnd__SetColumnJustification                           0x6C72F0
#define CListWnd__SetColumnWidth                                   0x6C71D0
#define CListWnd__SetCurSel                                        0x6C6BA0
#define CListWnd__SetItemColor                                     0x6CA700
#define CListWnd__SetItemData                                      0x6C7520
#define CListWnd__SetItemText                                      0x6CA680
#define CListWnd__ShiftColumnSeparator                             0x6C8E10
#define CListWnd__Sort                                             0x6CB500
#define CListWnd__ToggleSel                                        0x6C73F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5FD520

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x608910
#define CMerchantWnd__RequestBuyItem                               0x60A170
#define CMerchantWnd__RequestSellItem                              0x60A570
#define CMerchantWnd__SelectBuySellSlot                            0x609640

// CObfuscator
#define CObfuscator__doit                                          0x6832B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6E1C40
#define CSidlManager__CreateLabel                                  0x6389B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6D2940
#define CSidlScreenWnd__CalculateVSBRange                          0x6E7A00
#define CSidlScreenWnd__ConvertToRes                               0x6F16F0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6D2DC0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6D3E90
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6D3F40
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6D3660
#define CSidlScreenWnd__DrawSidlPiece                              0x6D2A90
#define CSidlScreenWnd__EnableIniStorage                           0x6D2580
#define CSidlScreenWnd__GetSidlPiece                               0x6D2C90
#define CSidlScreenWnd__Init1                                      0x6D3D00
#define CSidlScreenWnd__LoadIniInfo                                0x6D2E70
#define CSidlScreenWnd__LoadIniListWnd                             0x6D26D0
#define CSidlScreenWnd__LoadSidlScreen                             0x6D38B0
#define CSidlScreenWnd__StoreIniInfo                               0x6D2190
#define CSidlScreenWnd__WndNotification                            0x6D3A80
#define CSidlScreenWnd__GetChildItem                               0x6D25E0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x5376F0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6F2B90
#define CSliderWnd__SetValue                                       0x6F2C90
#define CSliderWnd__SetNumTicks                                    0x6F3200

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x63D820

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6EF980
#define CStmlWnd__CalculateVSBRange                                0x6E7A00
#define CStmlWnd__CanBreakAtCharacter                              0x6E7B40
#define CStmlWnd__FastForwardToEndOfTag                            0x6E86B0
#define CStmlWnd__ForceParseNow                                    0x6EFE00
#define CStmlWnd__GetNextTagPiece                                  0x6E85D0
#define CStmlWnd__GetSTMLText                                      0x59DBB0
#define CStmlWnd__GetThisChar                                      0x715330
#define CStmlWnd__GetVisiableText                                  0x6E98D0
#define CStmlWnd__InitializeWindowVariables                        0x6EBAA0
#define CStmlWnd__MakeStmlColorTag                                 0x6E70A0
#define CStmlWnd__MakeWndNotificationTag                           0x6E7140
#define CStmlWnd__SetSTMLText                                      0x6EBBD0
#define CStmlWnd__StripFirstSTMLLines                              0x6EF710
#define CStmlWnd__UpdateHistoryString                              0x6EA140

// CTabWnd 
#define CTabWnd__Draw                                              0x6F4010
#define CTabWnd__DrawCurrentPage                                   0x6F39B0
#define CTabWnd__DrawTab                                           0x6F3790
#define CTabWnd__GetCurrentPage                                    0x6F3CB0
#define CTabWnd__GetPageClientRect                                 0x6F3460
#define CTabWnd__GetPageFromTabIndex                               0x6F36C0
#define CTabWnd__GetPageInnerRect                                  0x6F34C0
#define CTabWnd__GetTabInnerRect                                   0x6F3640
#define CTabWnd__GetTabRect                                        0x6F3550
#define CTabWnd__InsertPage                                        0x6F4280
#define CTabWnd__SetPage                                           0x6F3CF0
#define CTabWnd__SetPageRect                                       0x6F3F40
#define CTabWnd__UpdatePage                                        0x6F4200

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x41DAA0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6D42A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6F85D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6C6850

// CXRect 
#define CXRect__CenterPoint                                        0x579610

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x506340
#define CXStr__CXStr1                                              0x6C04C0
#define CXStr__CXStr3                                              0x6B9840
#define CXStr__dCXStr                                              0x46D170
#define CXStr__operator_equal1                                     0x6B9A00
#define CXStr__operator_plus_equal1                                0x6BA900

// CXWnd 
#define CXWnd__BringToTop                                          0x6CBBF0
#define CXWnd__Center                                              0x6CF680
#define CXWnd__ClrFocus                                            0x6CB900
#define CXWnd__DoAllDrawing                                        0x6D0440
#define CXWnd__DrawChildren                                        0x6D0570
#define CXWnd__DrawColoredRect                                     0x6CBE70
#define CXWnd__DrawTooltip                                         0x6D0260
#define CXWnd__DrawTooltipAtPoint                                  0x6CF440
#define CXWnd__GetBorderFrame                                      0x6CC350
#define CXWnd__GetChildWndAt                                       0x6CEF80
#define CXWnd__GetClientClipRect                                   0x6CC260
#define CXWnd__GetScreenClipRect                                   0x6CF8A0
#define CXWnd__GetScreenRect                                       0x6CC4F0
#define CXWnd__GetTooltipRect                                      0x6CC0C0
#define CXWnd__GetWindowTextA                                      0x56CCF0
#define CXWnd__IsActive                                            0x6D53B0
#define CXWnd__IsDescendantOf                                      0x6CC2E0
#define CXWnd__IsReallyVisible                                     0x6CEF60
#define CXWnd__IsType                                              0x6F5470
#define CXWnd__Move                                                0x6CEB40
#define CXWnd__Move1                                               0x6D00C0
#define CXWnd__ProcessTransition                                   0x6CBBB0
#define CXWnd__Refade                                              0x6CB9B0
#define CXWnd__Resize                                              0x6CC5C0
#define CXWnd__Right                                               0x6CF7E0
#define CXWnd__SetFocus                                            0x6CDD70
#define CXWnd__SetKeyTooltip                                       0x6CC7D0
#define CXWnd__SetMouseOver                                        0x6CC7A0
#define CXWnd__StartFade                                           0x6CBC30
#define CXWnd__GetChildItem                                        0x6CFA10

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6D67B0
#define CXWndManager__DrawWindows                                  0x6D63C0
#define CXWndManager__GetKeyboardFlags                             0x6D5060
#define CXWndManager__HandleKeyboardMsg                            0x6D55B0
#define CXWndManager__RemoveWnd                                    0x6D54D0

// CDBStr
#define CDBStr__GetString                                          0x468270

// EQ_Character 
#define EQ_Character__CastRay                                      0x721550
#define EQ_Character__CastSpell                                    0x433A30
#define EQ_Character__Cur_HP                                       0x43D0D0
#define EQ_Character__GetAACastingTimeModifier                     0x429D60
#define EQ_Character__GetCharInfo2                                 0x699240
#define EQ_Character__GetFocusCastingTimeModifier                  0x4257D0
#define EQ_Character__GetFocusRangeModifier                        0x425910
#define EQ_Character__Max_Endurance                                0x51B030
#define EQ_Character__Max_HP                                       0x437FD0
#define EQ_Character__Max_Mana                                     0x51AE60
#define EQ_Character__doCombatAbility                              0x519D70
#define EQ_Character__UseSkill                                     0x448880
#define EQ_Character__GetConLevel                                  0x516320

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5040C0
#define EQ_Item__GetItemLinkHash                                   0x68CD50
#define EQ_Item__IsStackable                                       0x683B90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x481190
#define EQ_LoadingS__Array                                         0x860B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x51DEA0
#define EQ_PC__GetAltAbilityIndex                                  0x691640
#define EQ_PC__GetCombatAbility                                    0x6916D0
#define EQ_PC__GetCombatAbilityTimer                               0x691780
#define EQ_PC__GetItemTimerValue                                   0x518CB0
#define EQ_PC__HasLoreItem                                         0x51C370

// EQItemList 
#define EQItemList__dEQItemList                                    0x4AB110
#define EQItemList__EQItemList                                     0x4AB060

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x467C30

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x522710
#define EQPlayer__dEQPlayer                                        0x526780
#define EQPlayer__DoAttack                                         0x5339B0
#define EQPlayer__EQPlayer                                         0x52A460
#define EQPlayer__SetNameSpriteState                               0x5246E0
#define EQPlayer__SetNameSpriteTint                                0x522780
#define EQPlayer__IsBodyType_j                                     0x720E60
#define EQPlayer__IsTargetable                                     0x720FF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x52B540
#define EQPlayerManager__GetSpawnByName                            0x52B8A0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x505D60
#define KeypressHandler__AttachKeyToEqCommand                      0x505DA0
#define KeypressHandler__ClearCommandStateArray                    0x505B70
#define KeypressHandler__HandleKeyDown                             0x504720
#define KeypressHandler__HandleKeyUp                               0x504A30
#define KeypressHandler__SaveKeymapping                            0x505C40

// MapViewMap 
#define MapViewMap__Clear                                          0x5F8BF0
#define MapViewMap__SaveEx                                         0x5F95C0

#define OtherCharData__GetAltCurrency                              0x6B0870

// StringTable 
#define StringTable__getString                                     0x683530
