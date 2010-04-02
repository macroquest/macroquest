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
#define __ExpectedVersionDate                                     "Feb 21 2008"
#define __ExpectedVersionTime                                     "17:06:55"
#define __ActualVersionDate                                        0x71731C
#define __ActualVersionTime                                        0x717328

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FB110
#define __MemChecker1                                              0x6625F0
#define __MemChecker2                                              0x52EFC0
#define __MemChecker3                                              0x52EF10
#define __MemChecker4                                              0x626B30
#define __EncryptPad0                                              0x771120
#define __EncryptPad1                                              0x77AEB8
#define __EncryptPad2                                              0x773A98
#define __EncryptPad3                                              0x773698
#define __EncryptPad4                                              0x77A598

// Direct Input
#define DI8__Main                                                  0x9B883C
#define DI8__Keyboard                                              0x9B8840
#define DI8__Mouse                                                 0x9B8844
#define __AltTimerReady                                            0x9455BA
#define __Attack                                                   0x9A2EFE
#define __Autofire                                                 0x9A2EFF
#define __BindList                                                 0x76C2C8
#define __Clicks                                                   0x9442D8
#define __CommandList                                              0x76CAD8
#define __CurrentMapLabel                                          0x9E3A58
#define __CurrentSocial                                            0x768544
#define __DoAbilityAvailable                                       0x945554
#define __DoAbilityList                                            0x97AA1C
#define __do_loot                                                  0x4A5DC0
#define __DrawHandler                                              0x9F2D1C
#define __GroupCount                                               0x9247EA
#define __GroupLeader                                              0x924B3C
#define __Guilds                                                   0x926508
#define __gWorld                                                   0x926444
#define __HotkeyPage                                               0x9A1E08
#define __HWnd                                                     0x9B857C
#define __InChatMode                                               0x944210
#define __LastTell                                                 0x945EB4
#define __LMouseHeldTime                                           0x9442F8
#define __Mouse                                                    0x9B8848
#define __MouseLook                                                0x9442A6
#define __NetStatusToggle                                          0x9442A8
#define __PCNames                                                  0x94590C
#define __RangeAttackReady                                         0x9455B8
#define __RMouseHeldTime                                           0x9442F4
#define __RunWalkState                                             0x944214
#define __ScreenMode                                               0x874150
#define __ScreenX                                                  0x9441C8
#define __ScreenY                                                  0x9441CC
#define __ScreenXMax                                               0x9441D0
#define __ScreenYMax                                               0x9441D4
#define __ServerHost                                               0x924734
#define __ServerName                                               0x97A9DC
#define __ShiftKeyDown                                             0x944870
#define __ShowNames                                                0x9457E4
#define __Socials                                                  0x97AADC


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x93E158
#define instEQZoneInfo                                             0x944444
#define instKeypressHandler                                        0x9A2FE8
#define pinstActiveBanker                                          0x9264DC
#define pinstActiveCorpse                                          0x9264E0
#define pinstActiveGMaster                                         0x9264E4
#define pinstActiveMerchant                                        0x9264D8
#define pinstAltAdvManager                                         0x874FA0
#define pinstAuraMgr                                               0x77FFEC
#define pinstBandageTarget                                         0x9264C4
#define pinstCamActor                                              0x874A90
#define pinstCDBStr                                                0x874140
#define pinstCDisplay                                              0x9264EC
#define pinstCEverQuest                                            0x9B89C0
#define pinstCharData                                              0x9264A8
#define pinstCharSpawn                                             0x9264D0
#define pinstControlledMissile                                     0x9264A4
#define pinstControlledPlayer                                      0x9264D0
#define pinstCSidlManager                                          0x9F2500
#define pinstCXWndManager                                          0x9F24F8
#define instDynamicZone                                            0x943C18
#define pinstDZMember                                              0x943D28
#define pinstDZTimerInfo                                           0x943D2C
#define pinstEQItemList                                            0x92648C
#define instEQMisc                                                 0x8740F8
#define pinstEQSoundManager                                        0x874FC4
#define instExpeditionLeader                                       0x943C62
#define instExpeditionName                                         0x943CA2
#define instGroup                                                  0x9249E0
#define pinstGroup                                                 0x9247E6
#define pinstImeManager                                            0x9F2504
#define pinstLocalPlayer                                           0x9264BC
#define pinstModelPlayer                                           0x9264E8
#define pinstPCData                                                0x9264A8
#define pinstSkillMgr                                              0x9B57AC
#define pinstSpawnManager                                          0x9B572C
#define pinstSpellManager                                          0x9B57B0
#define pinstSpellSets                                             0x9A1E0C
#define pinstStringTable                                           0x926460
#define pinstSwitchManager                                         0x924434
#define pinstTarget                                                0x9264D4
#define pinstTargetObject                                          0x9264AC
#define pinstTargetSwitch                                          0x9264B0
#define pinstTaskMember                                            0x8740D8
#define pinstTrackTarget                                           0x9264C8
#define pinstTradeTarget                                           0x9264B8
#define instTributeActive                                          0x87411D
#define pinstViewActor                                             0x874A8C
#define pinstWorldData                                             0x926488


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x77E520
#define pinstCAudioTriggersWindow                                  0x77E4EC
#define pinstCCharacterSelect                                      0x8749A0
#define pinstCFacePick                                             0x874958
#define pinstCNoteWnd                                              0x87495C
#define pinstCBookWnd                                              0x874960
#define pinstCPetInfoWnd                                           0x874964
#define pinstCTrainWnd                                             0x874968
#define pinstCSkillsWnd                                            0x87496C
#define pinstCSkillsSelectWnd                                      0x874970
#define pinstCCombatSkillSelectWnd                                 0x874974
#define pinstCFriendsWnd                                           0x874978
#define pinstCAuraWnd                                              0x87497C
#define pinstCRespawnWnd                                           0x874980
#define pinstCBandolierWnd                                         0x874984
#define pinstCPotionBeltWnd                                        0x874988
#define pinstCAAWnd                                                0x87498C
#define pinstCGroupSearchFiltersWnd                                0x874990
#define pinstCLoadskinWnd                                          0x874994
#define pinstCAlarmWnd                                             0x874998
#define pinstCMusicPlayerWnd                                       0x87499C
#define pinstCMailWnd                                              0x8749A4
#define pinstCMailCompositionWnd                                   0x8749A8
#define pinstCMailAddressBookWnd                                   0x8749AC
#define pinstCRaidWnd                                              0x8749B4
#define pinstCRaidOptionsWnd                                       0x8749B8
#define pinstCBreathWnd                                            0x8749BC
#define pinstCMapViewWnd                                           0x8749C0
#define pinstCMapToolbarWnd                                        0x8749C4
#define pinstCEditLabelWnd                                         0x8749C8
#define pinstCTargetWnd                                            0x8749CC
#define pinstCColorPickerWnd                                       0x8749D0
#define pinstCPlayerWnd                                            0x8749D4
#define pinstCOptionsWnd                                           0x8749D8
#define pinstCBuffWindowNORMAL                                     0x8749DC
#define pinstCBuffWindowSHORT                                      0x8749E0
#define pinstCharacterCreation                                     0x8749E4
#define pinstCCursorAttachment                                     0x8749E8
#define pinstCCastingWnd                                           0x8749EC
#define pinstCCastSpellWnd                                         0x8749F0
#define pinstCSpellBookWnd                                         0x8749F4
#define pinstCInventoryWnd                                         0x8749F8
#define pinstCBankWnd                                              0x8749FC
#define pinstCQuantityWnd                                          0x874A00
#define pinstCLootWnd                                              0x874A04
#define pinstCActionsWnd                                           0x874A08
#define pinstCCombatAbilityWnd                                     0x874A0C
#define pinstCMerchantWnd                                          0x874A10
#define pinstCTradeWnd                                             0x874A14
#define pinstCSelectorWnd                                          0x874A18
#define pinstCBazaarWnd                                            0x874A1C
#define pinstCBazaarSearchWnd                                      0x874A20
#define pinstCGiveWnd                                              0x874A24
#define pinstCTrackingWnd                                          0x874A28
#define pinstCInspectWnd                                           0x874A2C
#define pinstCSocialEditWnd                                        0x874A30
#define pinstCFeedbackWnd                                          0x874A34
#define pinstCBugReportWnd                                         0x874A38
#define pinstCVideoModesWnd                                        0x874A3C
#define pinstCTextEntryWnd                                         0x874A44
#define pinstCFileSelectionWnd                                     0x874A48
#define pinstCCompassWnd                                           0x874A4C
#define pinstCPlayerNotesWnd                                       0x874A50
#define pinstCGemsGameWnd                                          0x874A54
#define pinstCTimeLeftWnd                                          0x874A58
#define pinstCPetitionQWnd                                         0x874A5C
#define pinstCSoulmarkWnd                                          0x874A60
#define pinstCStoryWnd                                             0x874A64
#define pinstCJournalTextWnd                                       0x874A68
#define pinstCJournalCatWnd                                        0x874A6C
#define pinstCBodyTintWnd                                          0x874A70
#define pinstCServerListWnd                                        0x874A74
#define pinstCAvaZoneWnd                                           0x874A78
#define pinstCBlockedBuffWnd                                       0x874A7C
#define pinstCBlockedPetBuffWnd                                    0x874A80
#define pinstCInvSlotMgr                                           0x874A84
#define pinstCContainerMgr                                         0x874A88
#define pinstCAdventureLeaderboardWnd                              0x9E0FA8
#define pinstCAdventureRequestWnd                                  0x9E0FC4
#define pinstCAltStorageWnd                                        0x9E1024
#define pinstCAdventureStatsWnd                                    0x9E0FE0
#define pinstCBarterMerchantWnd                                    0x9E11F0
#define pinstCBarterSearchWnd                                      0x9E120C
#define pinstCBarterWnd                                            0x9E1228
#define pinstCChatManager                                          0x9E14CC
#define pinstCDynamicZoneWnd                                       0x9E15C4
#define pinstCEQMainWnd                                            0x9E1634
#define pinstCFellowshipWnd                                        0x9E1698
#define pinstCFindLocationWnd                                      0x9E16CC
#define pinstCGroupSearchWnd                                       0x9E177C
#define pinstCGroupWnd                                             0x9E1798
#define pinstCGuildBankWnd                                         0x9E17B4
#define pinstCGuildMgmtWnd                                         0x9E37D0
#define pinstCGuildTributeMasterWnd                                0x9E37F0
#define pinstCHotButtonWnd                                         0x9E380C
#define pinstCHotButtonWnd1                                        0x9E380C
#define pinstCHotButtonWnd2                                        0x9E3810
#define pinstCHotButtonWnd3                                        0x9E3814
#define pinstCHotButtonWnd4                                        0x9E3818
#define pinstCItemDisplayManager                                   0x9E38C4
#define pinstCItemExpTransferWnd                                   0x9E38E4
#define pinstCLeadershipWnd                                        0x9E3980
#define pinstCLFGuildWnd                                           0x9E399C
#define pinstCMIZoneSelectWnd                                      0x9E3AC0
#define pinstCAdventureMerchantWnd                                 0x9E3BB8
#define pinstCConfirmationDialog                                   0x9E3BD4
#define pinstCPopupWndManager                                      0x9E3BD4
#define pinstCProgressionSelectionWnd                              0x9E3C08
#define pinstCPvPLeaderboardWnd                                    0x9E3C24
#define pinstCPvPStatsWnd                                          0x9E3C40
#define pinstCSystemInfoDialogBox                                  0x9E3CF0
#define pinstCTargetOfTargetWnd                                    0x9E45E4
#define pinstCTaskSelectWnd                                        0x9E4600
#define pinstCTaskTemplateSelectWnd                                0x9E461C
#define pinstCTaskWnd                                              0x9E4638
#define pinstCTipWndOFDAY                                          0x9E46B4
#define pinstCTipWndCONTEXT                                        0x9E46B8
#define pinstCTitleWnd                                             0x9E46D4
#define pinstCTradeskillWnd                                        0x9E4718
#define pinstCTributeBenefitWnd                                    0x9E4764
#define pinstCTributeMasterWnd                                     0x9E4780
#define pinstCContextMenuManager                                   0x9F255C
#define pinstCVoiceMacroWnd                                        0x9B589C
#define pinstCHtmlWnd                                              0x9B58B8


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4B7DA0
#define __ConvertItemTags                                          0x4AAF40
#define __ExecuteCmd                                               0x49A640
#define __get_melee_range                                          0x49F830
#define __GetGaugeValueFromEQ                                      0x5F8AC0
#define __GetLabelFromEQ                                           0x5F92C0
#define __NewUIINI                                                 0x5F86A0
#define __ProcessGameEvents                                        0x4E6580
#define CrashDetected                                              0x52DC90
#define DrawNetStatus                                              0x4FDEC0
#define Util__FastTime                                             0x662D00


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x473FB0
#define AltAdvManager__IsAbilityReady                              0x473FF0
#define AltAdvManager__GetAltAbility                               0x4741D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x545180

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x54EAE0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x68E480

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x562360
#define CChatManager__InitContextMenu                              0x562AF0

// CChatService
#define CChatService__GetNumberOfFriends                           0x652F50
#define CChatService__GetFriendName                                0x652F60

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x566C60
#define CChatWindow__WndNotification                               0x567690

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x674A60
#define CComboWnd__Draw                                            0x674C10
#define CComboWnd__GetCurChoice                                    0x674A00
#define CComboWnd__GetListRect                                     0x674EE0
#define CComboWnd__GetTextRect                                     0x674A90
#define CComboWnd__InsertChoice                                    0x674F50
#define CComboWnd__SetColors                                       0x674990
#define CComboWnd__SetChoice                                       0x6749C0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x56DFF0
#define CContainerWnd__vftable                                     0x71DBC8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x463220
#define CDisplay__GetClickedActor                                  0x4608A0
#define CDisplay__GetUserDefinedColor                              0x45FA20
#define CDisplay__GetWorldFilePath                                 0x45EF90
#define CDisplay__is3dON                                           0x45E0F0
#define CDisplay__ReloadUI                                         0x46ED80
#define CDisplay__WriteTextHD2                                     0x463950

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x53F180
#define CEditBaseWnd__SetSel                                       0x699550

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x682620
#define CEditWnd__GetCharIndexPt                                   0x683470
#define CEditWnd__GetDisplayString                                 0x6827B0
#define CEditWnd__GetHorzOffset                                    0x682A50
#define CEditWnd__GetLineForPrintableChar                          0x682F20
#define CEditWnd__GetSelStartPt                                    0x6836B0
#define CEditWnd__GetSTMLSafeText                                  0x682BE0
#define CEditWnd__PointFromPrintableChar                           0x683030
#define CEditWnd__SelectableCharFromPoint                          0x6831B0
#define CEditWnd__SetEditable                                      0x682BB0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4C9F80
#define CEverQuest__DropHeldItemOnGround                           0x4CE980
#define CEverQuest__dsp_chat                                       0x4CF800
#define CEverQuest__DoTellWindow                                   0x4CEB00
#define CEverQuest__EnterZone                                      0x4E4FC0
#define CEverQuest__GetBodyTypeDesc                                0x4C7410
#define CEverQuest__GetClassDesc                                   0x4C6B70
#define CEverQuest__GetClassThreeLetterCode                        0x4C7170
#define CEverQuest__GetDeityDesc                                   0x4C7A80
#define CEverQuest__GetLangDesc                                    0x4C77A0
#define CEverQuest__GetRaceDesc                                    0x4C7A50
#define CEverQuest__InterpretCmd                                   0x4D0230
#define CEverQuest__LeftClickedOnPlayer                            0x4E37E0
#define CEverQuest__LMouseUp                                       0x4E5D60
#define CEverQuest__RightClickedOnPlayer                           0x4E3BB0
#define CEverQuest__RMouseUp                                       0x4E55C0
#define CEverQuest__SetGameState                                   0x4CA400
#define CEverQuest__Emote                                          0x4CF9D0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x579B20
#define CGaugeWnd__CalcLinesFillRect                               0x579B90
#define CGaugeWnd__Draw                                            0x579F20

// CGuild
#define CGuild__FindMemberByName                                   0x417A30

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5904B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x599900
#define CInvSlotMgr__MoveItem                                      0x599AA0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x59AA00

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5982F0
#define CInvSlot__SliderComplete                                   0x598800

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5A89E0
#define CItemDisplayWnd__SetSpell                                  0x5F6A40

// CLabel 
#define CLabel__Draw                                               0x5AE230

// CListWnd 
#define CListWnd__AddColumn                                        0x6747A0
#define CListWnd__AddColumn1                                       0x674280
#define CListWnd__AddLine                                          0x673E60
#define CListWnd__AddString                                        0x674030
#define CListWnd__CalculateFirstVisibleLine                        0x671190
#define CListWnd__CalculateVSBRange                                0x672E00
#define CListWnd__ClearAllSel                                      0x670900
#define CListWnd__CloseAndUpdateEditWindow                         0x6717B0
#define CListWnd__Compare                                          0x671B60
#define CListWnd__Draw                                             0x672B00
#define CListWnd__DrawColumnSeparators                             0x672970
#define CListWnd__DrawHeader                                       0x670AD0
#define CListWnd__DrawItem                                         0x672270
#define CListWnd__DrawLine                                         0x672620
#define CListWnd__DrawSeparator                                    0x672A10
#define CListWnd__EnsureVisible                                    0x6711E0
#define CListWnd__ExtendSel                                        0x6721A0
#define CListWnd__GetColumnMinWidth                                0x6706A0
#define CListWnd__GetColumnWidth                                   0x6705E0
#define CListWnd__GetCurSel                                        0x670090
#define CListWnd__GetHeaderRect                                    0x6701B0
#define CListWnd__GetItemAtPoint                                   0x6714C0
#define CListWnd__GetItemAtPoint1                                  0x671530
#define CListWnd__GetItemData                                      0x670390
#define CListWnd__GetItemHeight                                    0x670F30
#define CListWnd__GetItemIcon                                      0x670520
#define CListWnd__GetItemRect                                      0x6712B0
#define CListWnd__GetItemText                                      0x6703D0
#define CListWnd__GetSelList                                       0x674160
#define CListWnd__GetSeparatorRect                                 0x671AA0
#define CListWnd__RemoveLine                                       0x674750
#define CListWnd__SetColors                                        0x670110
#define CListWnd__SetColumnJustification                           0x670700
#define CListWnd__SetColumnWidth                                   0x670660
#define CListWnd__SetCurSel                                        0x6700D0
#define CListWnd__SetItemColor                                     0x673A30
#define CListWnd__SetItemData                                      0x6709A0
#define CListWnd__SetItemText                                      0x6739B0
#define CListWnd__ShiftColumnSeparator                             0x672110
#define CListWnd__Sort                                             0x6747D0
#define CListWnd__ToggleSel                                        0x670870

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5C2D20

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C4800
#define CMerchantWnd__RequestBuyItem                               0x5C5B40
#define CMerchantWnd__RequestSellItem                              0x5C4A60
#define CMerchantWnd__SelectBuySellSlot                            0x5C5870

// CObfuscator
#define CObfuscator__doit                                          0x639F60

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x68A0A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x540C80
#define CSidlScreenWnd__CalculateVSBRange                          0x540BC0
#define CSidlScreenWnd__ConvertToRes                               0x699430
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x67BD60
#define CSidlScreenWnd__CSidlScreenWnd1                            0x67CB90
#define CSidlScreenWnd__CSidlScreenWnd2                            0x67CC40
#define CSidlScreenWnd__dCSidlScreenWnd                            0x67C5E0
#define CSidlScreenWnd__DrawSidlPiece                              0x67BA40
#define CSidlScreenWnd__EnableIniStorage                           0x67B540
#define CSidlScreenWnd__GetSidlPiece                               0x67BC40
#define CSidlScreenWnd__Init1                                      0x67CA00
#define CSidlScreenWnd__LoadIniInfo                                0x67BE10
#define CSidlScreenWnd__LoadIniListWnd                             0x67B690
#define CSidlScreenWnd__LoadSidlScreen                             0x67B850
#define CSidlScreenWnd__StoreIniInfo                               0x67B150
#define CSidlScreenWnd__WndNotification                            0x67B9A0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x51ECC0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x41E660
#define CSliderWnd__SetValue                                       0x69A200
#define CSliderWnd__SetNumTicks                                    0x69A730

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5F5680

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6976B0
#define CStmlWnd__CalculateVSBRange                                0x68FA50
#define CStmlWnd__CanBreakAtCharacter                              0x68FB90
#define CStmlWnd__FastForwardToEndOfTag                            0x6906A0
#define CStmlWnd__ForceParseNow                                    0x697B10
#define CStmlWnd__GetNextTagPiece                                  0x6905C0
#define CStmlWnd__GetSTMLText                                      0x566C00
#define CStmlWnd__GetThisChar                                      0x6B7990
#define CStmlWnd__GetVisiableText                                  0x6918E0
#define CStmlWnd__InitializeWindowVariables                        0x693A40
#define CStmlWnd__MakeStmlColorTag                                 0x68F0F0
#define CStmlWnd__MakeWndNotificationTag                           0x68F190
#define CStmlWnd__SetSTMLText                                      0x693B60
#define CStmlWnd__StripFirstSTMLLines                              0x697440
#define CStmlWnd__UpdateHistoryString                              0x692140

// CTabWnd 
#define CTabWnd__Draw                                              0x69B550
#define CTabWnd__DrawCurrentPage                                   0x69AED0
#define CTabWnd__DrawTab                                           0x69ACB0
#define CTabWnd__GetCurrentPage                                    0x69B1D0
#define CTabWnd__GetPageClientRect                                 0x69A980
#define CTabWnd__GetPageFromTabIndex                               0x69ABE0
#define CTabWnd__GetPageInnerRect                                  0x69A9E0
#define CTabWnd__GetTabInnerRect                                   0x69AB60
#define CTabWnd__GetTabRect                                        0x69AA70
#define CTabWnd__IndexInBounds                                     0x69AC7D
#define CTabWnd__InsertPage                                        0x69B770
#define CTabWnd__SetPage                                           0x69B210
#define CTabWnd__SetPageRect                                       0x69B480
#define CTabWnd__UpdatePage                                        0x69B6F0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x413F60

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x67CFA0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6A0AB0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x66FE00

// CXRect 
#define CXRect__CenterPoint                                        0x5448E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4F51C0
#define CXStr__CXStr1                                              0x403580
#define CXStr__CXStr3                                              0x664450
#define CXStr__dCXStr                                              0x474A40
#define CXStr__operator_equal1                                     0x664610
#define CXStr__operator_plus_equal1                                0x665510

// CXWnd 
#define CXWnd__BringToTop                                          0x6757A0
#define CXWnd__Center                                              0x679360
#define CXWnd__ClrFocus                                            0x6754C0
#define CXWnd__DoAllDrawing                                        0x679DE0
#define CXWnd__DrawChildren                                        0x679F10
#define CXWnd__DrawColoredRect                                     0x675A40
#define CXWnd__DrawTooltip                                         0x679D00
#define CXWnd__DrawTooltipAtPoint                                  0x679140
#define CXWnd__GetBorderFrame                                      0x675F30
#define CXWnd__GetChildWndAt                                       0x678BD0
#define CXWnd__GetClientClipRect                                   0x675E60
#define CXWnd__GetFirstChildWnd                                    0x675840
#define CXWnd__GetNextChildWnd                                     0x678B90
#define CXWnd__GetNextSib                                          0x675860
#define CXWnd__GetScreenClipRect                                   0x679580
#define CXWnd__GetScreenRect                                       0x6760E0
#define CXWnd__GetTooltipRect                                      0x675C90
#define CXWnd__GetWindowTextA                                      0x538300
#define CXWnd__IsActive                                            0x67E0B0
#define CXWnd__IsDescendantOf                                      0x675EE0
#define CXWnd__IsReallyVisible                                     0x678B70
#define CXWnd__IsType                                              0x69C6A0
#define CXWnd__Move                                                0x678680
#define CXWnd__Move1                                               0x678710
#define CXWnd__ProcessTransition                                   0x675770
#define CXWnd__Refade                                              0x675570
#define CXWnd__Resize                                              0x6761A0
#define CXWnd__Right                                               0x6794C0
#define CXWnd__SetFirstChildPointer                                0x6763A0
#define CXWnd__SetFocus                                            0x677730
#define CXWnd__SetKeyTooltip                                       0x676410
#define CXWnd__SetMouseOver                                        0x6763E0
#define CXWnd__SetNextSibPointer                                   0x6763C0
#define CXWnd__StartFade                                           0x6757C0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x67F500
#define CXWndManager__DrawWindows                                  0x67F140
#define CXWndManager__GetFirstChildWnd                             0x67EA50
#define CXWndManager__GetKeyboardFlags                             0x67DD60
#define CXWndManager__HandleKeyboardMsg                            0x67E2A0
#define CXWndManager__RemoveWnd                                    0x67E1C0

// CDBStr
#define CDBStr__GetString                                          0x45C9E0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6C3850
#define EQ_Character__CastSpell                                    0x425140
#define EQ_Character__Cur_HP                                       0x431D00
#define EQ_Character__GetAACastingTimeModifier                     0x41F9A0
#define EQ_Character__GetCharInfo2                                 0x645350
#define EQ_Character__GetFocusCastingTimeModifier                  0x41B610
#define EQ_Character__GetFocusRangeModifier                        0x41B740
#define EQ_Character__Max_Endurance                                0x42D080
#define EQ_Character__Max_HP                                       0x42CF00
#define EQ_Character__Max_Mana                                     0x503450
#define EQ_Character__doCombatAbility                              0x502110
#define EQ_Character__UseSkill                                     0x437DF0
#define EQ_Character__GetConLevel                                  0x4FF290

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F2F20
#define EQ_Item__GetItemLinkHash                                   0x639620
#define EQ_Item__IsStackable                                       0x6304F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x475140
#define EQ_LoadingS__Array                                         0x76A7D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x506600
#define EQ_PC__GetAltAbilityIndex                                  0x63E450
#define EQ_PC__GetCombatAbility                                    0x63E4E0
#define EQ_PC__GetCombatAbilityTimer                               0x63E590
#define EQ_PC__GetItemTimerValue                                   0x501070
#define EQ_PC__HasLoreItem                                         0x504A60

// EQItemList 
#define EQItemList__dEQItemList                                    0x49DF70
#define EQItemList__EQItemList                                     0x49DEC0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45C3D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50B4E0
#define EQPlayer__dEQPlayer                                        0x50FC80
#define EQPlayer__DoAttack                                         0x51B740
#define EQPlayer__EQPlayer                                         0x512980
#define EQPlayer__SetNameSpriteState                               0x50DC00
#define EQPlayer__SetNameSpriteTint                                0x50B550
#define EQPlayer__IsBodyType_j                                     0x6C3210

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5138C0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F4B30
#define KeypressHandler__AttachKeyToEqCommand                      0x4F4B70
#define KeypressHandler__ClearCommandStateArray                    0x4F4940
#define KeypressHandler__HandleKeyDown                             0x4F3520
#define KeypressHandler__HandleKeyUp                               0x4F3820
#define KeypressHandler__SaveKeymapping                            0x4F4A10

// MapViewMap 
#define MapViewMap__Clear                                          0x5BED40
#define MapViewMap__SaveEx                                         0x5BF710

#define OtherCharData__GetAltCurrency                              0x65B620

// StringTable 
#define StringTable__getString                                     0x62FEC0
