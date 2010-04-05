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
#define __ExpectedVersionDate                                     "Sep  2 2008"
#define __ExpectedVersionTime                                     "15:04:48"
#define __ActualVersionDate                                        0x74AA2C
#define __ActualVersionTime                                        0x74AA38

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FC3E0
#define __MemChecker1                                              0x68C6D0
#define __MemChecker2                                              0x551F60
#define __MemChecker3                                              0x551EB0
#define __MemChecker4                                              0x64FD40
#define __EncryptPad0                                              0x7A82A8
#define __EncryptPad1                                              0x7B26F8
#define __EncryptPad2                                              0x7AB0E0
#define __EncryptPad3                                              0x7AACE0
#define __EncryptPad4                                              0x7B1DD8

// Direct Input
#define DI8__Main                                                  0xA132BC
#define DI8__Keyboard                                              0xA132C0
#define DI8__Mouse                                                 0xA132C4
#define __AltTimerReady                                            0x99FEFE
#define __Attack                                                   0x9FD84A
#define __Autofire                                                 0x9FD84B
#define __BindList                                                 0x7A3390
#define __Clicks                                                   0x99EC18
#define __CommandList                                              0x7A3BE0
#define __CurrentMapLabel                                          0xA3E4E0
#define __CurrentSocial                                            0x79F5D0
#define __DoAbilityAvailable                                       0x99FE98
#define __DoAbilityList                                            0x9D5368
#define __do_loot                                                  0x4A56D0
#define __DrawHandler                                              0xA4D84C
#define __GroupCount                                               0x97F2CA
#define __Guilds                                                   0x980E48
#define __gWorld                                                   0x980D84
#define __HotkeyPage                                               0x9FC754
#define __HWnd                                                     0xA12FFC
#define __InChatMode                                               0x99EB50
#define __LastTell                                                 0x9A0800
#define __LMouseHeldTime                                           0x99EC38
#define __Mouse                                                    0xA132C8
#define __MouseLook                                                0x99EBE6
#define __NetStatusToggle                                          0x99EBE8
#define __PCNames                                                  0x9A0250
#define __RangeAttackReady                                         0x99FEFC
#define __RMouseHeldTime                                           0x99EC34
#define __RunWalkState                                             0x99EB54
#define __ScreenMode                                               0x8CEBA8
#define __ScreenX                                                  0x99EB08
#define __ScreenY                                                  0x99EB0C
#define __ScreenXMax                                               0x99EB10
#define __ScreenYMax                                               0x99EB14
#define __ServerHost                                               0x97F20C
#define __ServerName                                               0x9D5328
#define __ShiftKeyDown                                             0x99F1B4
#define __ShowNames                                                0x9A0128
#define __Socials                                                  0x9D5428


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x998A98
#define instEQZoneInfo                                             0x99ED84
#define instKeypressHandler                                        0x9FD934
#define pinstActiveBanker                                          0x980E1C
#define pinstActiveCorpse                                          0x980E20
#define pinstActiveGMaster                                         0x980E24
#define pinstActiveMerchant                                        0x980E18
#define pinstAltAdvManager                                         0x8CFA00
#define pinstAuraMgr                                               0x7B846C
#define pinstBandageTarget                                         0x980E04
#define pinstCamActor                                              0x8CF4EC
#define pinstCDBStr                                                0x8CEB98
#define pinstCDisplay                                              0x980E2C
#define pinstCEverQuest                                            0xA13440
#define pinstCharData                                              0x980DE8
#define pinstCharSpawn                                             0x980E10
#define pinstControlledMissile                                     0x980DE4
#define pinstControlledPlayer                                      0x980E10
#define pinstCSidlManager                                          0xA4CFE8
#define pinstCXWndManager                                          0xA4CFE0
#define instDynamicZone                                            0x99E558
#define pinstDZMember                                              0x99E668
#define pinstDZTimerInfo                                           0x99E66C
#define pinstEQItemList                                            0x980DCC
#define instEQMisc                                                 0x8CEB50
#define pinstEQSoundManager                                        0x8CFA24
#define instExpeditionLeader                                       0x99E5A2
#define instExpeditionName                                         0x99E5E2
#define pinstGroup                                                 0x97F2C6
#define pinstImeManager                                            0xA4CFEC
#define pinstLocalPlayer                                           0x980DFC
#define pinstModelPlayer                                           0x980E28
#define pinstPCData                                                0x980DE8
#define pinstSkillMgr                                              0xA10114
#define pinstSpawnManager                                          0xA10094
#define pinstSpellManager                                          0xA10118
#define pinstSpellSets                                             0x9FC758
#define pinstStringTable                                           0x980DA0
#define pinstSwitchManager                                         0x97EF0C
#define pinstTarget                                                0x980E14
#define pinstTargetObject                                          0x980DEC
#define pinstTargetSwitch                                          0x980DF0
#define pinstTaskMember                                            0x8CEB30
#define pinstTrackTarget                                           0x980E08
#define pinstTradeTarget                                           0x980DF8
#define instTributeActive                                          0x8CEB75
#define pinstViewActor                                             0x8CF4E8
#define pinstWorldData                                             0x980DC8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x7B5D20
#define pinstCAudioTriggersWindow                                  0x7B5CEC
#define pinstCCharacterSelect                                      0x8CF3FC
#define pinstCFacePick                                             0x8CF3B0
#define pinstCNoteWnd                                              0x8CF3B4
#define pinstCBookWnd                                              0x8CF3B8
#define pinstCPetInfoWnd                                           0x8CF3BC
#define pinstCTrainWnd                                             0x8CF3C0
#define pinstCSkillsWnd                                            0x8CF3C4
#define pinstCSkillsSelectWnd                                      0x8CF3C8
#define pinstCCombatSkillSelectWnd                                 0x8CF3CC
#define pinstCFriendsWnd                                           0x8CF3D0
#define pinstCAuraWnd                                              0x8CF3D4
#define pinstCRespawnWnd                                           0x8CF3D8
#define pinstCBandolierWnd                                         0x8CF3DC
#define pinstCPotionBeltWnd                                        0x8CF3E0
#define pinstCAAWnd                                                0x8CF3E4
#define pinstCGroupSearchFiltersWnd                                0x8CF3E8
#define pinstCLoadskinWnd                                          0x8CF3EC
#define pinstCAlarmWnd                                             0x8CF3F0
#define pinstCMusicPlayerWnd                                       0x8CF3F4
#define pinstCMailWnd                                              0x8CF400
#define pinstCMailCompositionWnd                                   0x8CF404
#define pinstCMailAddressBookWnd                                   0x8CF408
#define pinstCRaidWnd                                              0x8CF410
#define pinstCRaidOptionsWnd                                       0x8CF414
#define pinstCBreathWnd                                            0x8CF418
#define pinstCMapViewWnd                                           0x8CF41C
#define pinstCMapToolbarWnd                                        0x8CF420
#define pinstCEditLabelWnd                                         0x8CF424
#define pinstCTargetWnd                                            0x8CF428
#define pinstCColorPickerWnd                                       0x8CF42C
#define pinstCPlayerWnd                                            0x8CF430
#define pinstCOptionsWnd                                           0x8CF434
#define pinstCBuffWindowNORMAL                                     0x8CF438
#define pinstCBuffWindowSHORT                                      0x8CF43C
#define pinstCharacterCreation                                     0x8CF440
#define pinstCCursorAttachment                                     0x8CF444
#define pinstCCastingWnd                                           0x8CF448
#define pinstCCastSpellWnd                                         0x8CF44C
#define pinstCSpellBookWnd                                         0x8CF450
#define pinstCInventoryWnd                                         0x8CF454
#define pinstCBankWnd                                              0x8CF458
#define pinstCQuantityWnd                                          0x8CF45C
#define pinstCLootWnd                                              0x8CF460
#define pinstCActionsWnd                                           0x8CF464
#define pinstCCombatAbilityWnd                                     0x8CF468
#define pinstCMerchantWnd                                          0x8CF46C
#define pinstCTradeWnd                                             0x8CF470
#define pinstCSelectorWnd                                          0x8CF474
#define pinstCBazaarWnd                                            0x8CF478
#define pinstCBazaarSearchWnd                                      0x8CF47C
#define pinstCGiveWnd                                              0x8CF480
#define pinstCTrackingWnd                                          0x8CF484
#define pinstCInspectWnd                                           0x8CF488
#define pinstCSocialEditWnd                                        0x8CF48C
#define pinstCFeedbackWnd                                          0x8CF490
#define pinstCBugReportWnd                                         0x8CF494
#define pinstCVideoModesWnd                                        0x8CF498
#define pinstCTextEntryWnd                                         0x8CF4A0
#define pinstCFileSelectionWnd                                     0x8CF4A4
#define pinstCCompassWnd                                           0x8CF4A8
#define pinstCPlayerNotesWnd                                       0x8CF4AC
#define pinstCGemsGameWnd                                          0x8CF4B0
#define pinstCTimeLeftWnd                                          0x8CF4B4
#define pinstCPetitionQWnd                                         0x8CF4B8
#define pinstCSoulmarkWnd                                          0x8CF4BC
#define pinstCStoryWnd                                             0x8CF4C0
#define pinstCJournalTextWnd                                       0x8CF4C4
#define pinstCJournalCatWnd                                        0x8CF4C8
#define pinstCBodyTintWnd                                          0x8CF4CC
#define pinstCServerListWnd                                        0x8CF4D0
#define pinstCAvaZoneWnd                                           0x8CF4D4
#define pinstCBlockedBuffWnd                                       0x8CF4D8
#define pinstCBlockedPetBuffWnd                                    0x8CF4DC
#define pinstCInvSlotMgr                                           0x8CF4E0
#define pinstCContainerMgr                                         0x8CF4E4
#define pinstCAdventureLeaderboardWnd                              0xA3BA28
#define pinstCAdventureRequestWnd                                  0xA3BA44
#define pinstCAltStorageWnd                                        0xA3BAA4
#define pinstCAdventureStatsWnd                                    0xA3BA60
#define pinstCBarterMerchantWnd                                    0xA3BC70
#define pinstCBarterSearchWnd                                      0xA3BC8C
#define pinstCBarterWnd                                            0xA3BCA8
#define pinstCChatManager                                          0xA3BF4C
#define pinstCDynamicZoneWnd                                       0xA3C044
#define pinstCEQMainWnd                                            0xA3C0B8
#define pinstCFellowshipWnd                                        0xA3C11C
#define pinstCFindLocationWnd                                      0xA3C150
#define pinstCGroupSearchWnd                                       0xA3C200
#define pinstCGroupWnd                                             0xA3C21C
#define pinstCGuildBankWnd                                         0xA3C238
#define pinstCGuildMgmtWnd                                         0xA3E258
#define pinstCGuildTributeMasterWnd                                0xA3E278
#define pinstCHotButtonWnd                                         0xA3E294
#define pinstCHotButtonWnd1                                        0xA3E294
#define pinstCHotButtonWnd2                                        0xA3E298
#define pinstCHotButtonWnd3                                        0xA3E29C
#define pinstCHotButtonWnd4                                        0xA3E2A0
#define pinstCItemDisplayManager                                   0xA3E34C
#define pinstCItemExpTransferWnd                                   0xA3E36C
#define pinstCLeadershipWnd                                        0xA3E408
#define pinstCLFGuildWnd                                           0xA3E424
#define pinstCMIZoneSelectWnd                                      0xA3E548
#define pinstCAdventureMerchantWnd                                 0xA3E640
#define pinstCConfirmationDialog                                   0xA3E65C
#define pinstCPopupWndManager                                      0xA3E65C
#define pinstCProgressionSelectionWnd                              0xA3E690
#define pinstCPvPLeaderboardWnd                                    0xA3E6AC
#define pinstCPvPStatsWnd                                          0xA3E6C8
#define pinstCSystemInfoDialogBox                                  0xA3E778
#define pinstCTargetOfTargetWnd                                    0xA3F05C
#define pinstCTaskSelectWnd                                        0xA3F090
#define pinstCTaskTemplateSelectWnd                                0xA3F0AC
#define pinstCTaskWnd                                              0xA3F0C8
#define pinstCTipWndOFDAY                                          0xA3F144
#define pinstCTipWndCONTEXT                                        0xA3F148
#define pinstCTitleWnd                                             0xA3F164
#define pinstCTradeskillWnd                                        0xA3F1A8
#define pinstCTributeBenefitWnd                                    0xA3F1F4
#define pinstCTributeMasterWnd                                     0xA3F210
#define pinstCContextMenuManager                                   0xA4D044
#define pinstCVoiceMacroWnd                                        0xA1031C
#define pinstCHtmlWnd                                              0xA10338


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4B7950
#define __ConvertItemTags                                          0x4AAA80
#define __ExecuteCmd                                               0x499E40
#define __get_melee_range                                          0x49F030
#define __GetGaugeValueFromEQ                                      0x620E70
#define __GetLabelFromEQ                                           0x6216F0
#define __NewUIINI                                                 0x620A50
#define __ProcessGameEvents                                        0x4E6D70
#define CrashDetected                                              0x550C30
#define DrawNetStatus                                              0x4FF1C0
#define Util__FastTime                                             0x68CDE0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x473A50
#define AltAdvManager__IsAbilityReady                              0x473A90
#define AltAdvManager__GetAltAbility                               0x473CB0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x568800

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x571E50

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6B8DC0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5878C0
#define CChatManager__InitContextMenu                              0x588050

// CChatService
#define CChatService__GetNumberOfFriends                           0x67CFD0
#define CChatService__GetFriendName                                0x67CFE0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x58C1D0
#define CChatWindow__WndNotification                               0x58CC00

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x69E8F0
#define CComboWnd__Draw                                            0x69EAA0
#define CComboWnd__GetCurChoice                                    0x69E890
#define CComboWnd__GetListRect                                     0x69ED70
#define CComboWnd__GetTextRect                                     0x69E920
#define CComboWnd__InsertChoice                                    0x69EDE0
#define CComboWnd__SetColors                                       0x69E820
#define CComboWnd__SetChoice                                       0x69E850

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x593850
#define CContainerWnd__vftable                                     0x751570

// CDisplay 
#define CDisplay__CleanGameUI                                      0x462BB0
#define CDisplay__GetClickedActor                                  0x4602D0
#define CDisplay__GetUserDefinedColor                              0x45F450
#define CDisplay__GetWorldFilePath                                 0x45E9C0
#define CDisplay__is3dON                                           0x45DB20
#define CDisplay__ReloadUI                                         0x46E800
#define CDisplay__WriteTextHD2                                     0x463310

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x562940
#define CEditBaseWnd__SetSel                                       0x6C3DE0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6AC860
#define CEditWnd__GetCharIndexPt                                   0x6AD6B0
#define CEditWnd__GetDisplayString                                 0x6AC9F0
#define CEditWnd__GetHorzOffset                                    0x6ACC80
#define CEditWnd__GetLineForPrintableChar                          0x6AD160
#define CEditWnd__GetSelStartPt                                    0x6AD900
#define CEditWnd__GetSTMLSafeText                                  0x6ACE20
#define CEditWnd__PointFromPrintableChar                           0x6AD270
#define CEditWnd__SelectableCharFromPoint                          0x6AD3F0
#define CEditWnd__SetEditable                                      0x6ACDF0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4CAD60
#define CEverQuest__DropHeldItemOnGround                           0x4CF020
#define CEverQuest__dsp_chat                                       0x4D0500
#define CEverQuest__DoTellWindow                                   0x4CF1A0
#define CEverQuest__EnterZone                                      0x4E5780
#define CEverQuest__GetBodyTypeDesc                                0x4C8170
#define CEverQuest__GetClassDesc                                   0x4C78D0
#define CEverQuest__GetClassThreeLetterCode                        0x4C7ED0
#define CEverQuest__GetDeityDesc                                   0x4C87E0
#define CEverQuest__GetLangDesc                                    0x4C8500
#define CEverQuest__GetRaceDesc                                    0x4C87B0
#define CEverQuest__InterpretCmd                                   0x4D0F40
#define CEverQuest__LeftClickedOnPlayer                            0x4E3FC0
#define CEverQuest__LMouseUp                                       0x4E6550
#define CEverQuest__RightClickedOnPlayer                           0x4E4390
#define CEverQuest__RMouseUp                                       0x4E5D80
#define CEverQuest__SetGameState                                   0x4CB1E0
#define CEverQuest__Emote                                          0x4D06D0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5A0450
#define CGaugeWnd__CalcLinesFillRect                               0x5A04B0
#define CGaugeWnd__Draw                                            0x5A0810

// CGuild
#define CGuild__FindMemberByName                                   0x4180D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5B7340

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5C07E0
#define CInvSlotMgr__MoveItem                                      0x5C0980

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5BF1B0
#define CInvSlot__SliderComplete                                   0x5BF6C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5CF6B0
#define CItemDisplayWnd__SetSpell                                  0x61EB00

// CLabel 
#define CLabel__Draw                                               0x5D4F70

// CListWnd 
#define CListWnd__AddColumn                                        0x69E630
#define CListWnd__AddColumn1                                       0x69E120
#define CListWnd__AddLine                                          0x69DCF0
#define CListWnd__AddString                                        0x69DEC0
#define CListWnd__CalculateFirstVisibleLine                        0x69B040
#define CListWnd__CalculateVSBRange                                0x69CCB0
#define CListWnd__ClearAllSel                                      0x69A780
#define CListWnd__CloseAndUpdateEditWindow                         0x69B670
#define CListWnd__Compare                                          0x69BA00
#define CListWnd__Draw                                             0x69C9A0
#define CListWnd__DrawColumnSeparators                             0x69C810
#define CListWnd__DrawHeader                                       0x69A950
#define CListWnd__DrawItem                                         0x69C100
#define CListWnd__DrawLine                                         0x69C4B0
#define CListWnd__DrawSeparator                                    0x69C8B0
#define CListWnd__EnsureVisible                                    0x69B090
#define CListWnd__ExtendSel                                        0x69C030
#define CListWnd__GetColumnMinWidth                                0x69A590
#define CListWnd__GetColumnWidth                                   0x69A4D0
#define CListWnd__GetCurSel                                        0x699FB0
#define CListWnd__GetHeaderRect                                    0x69A0A0
#define CListWnd__GetItemAtPoint                                   0x69B390
#define CListWnd__GetItemAtPoint1                                  0x69B400
#define CListWnd__GetItemData                                      0x69A280
#define CListWnd__GetItemHeight                                    0x69ADE0
#define CListWnd__GetItemIcon                                      0x69A410
#define CListWnd__GetItemRect                                      0x69B170
#define CListWnd__GetItemText                                      0x69A2C0
#define CListWnd__GetSelList                                       0x69E000
#define CListWnd__GetSeparatorRect                                 0x69B940
#define CListWnd__RemoveLine                                       0x69E5E0
#define CListWnd__SetColors                                        0x69A010
#define CListWnd__SetColumnJustification                           0x69A5F0
#define CListWnd__SetColumnWidth                                   0x69A550
#define CListWnd__SetCurSel                                        0x699FF0
#define CListWnd__SetItemColor                                     0x69D8C0
#define CListWnd__SetItemData                                      0x69A820
#define CListWnd__SetItemText                                      0x69D840
#define CListWnd__ShiftColumnSeparator                             0x69BFA0
#define CListWnd__Sort                                             0x69E660
#define CListWnd__ToggleSel                                        0x69A6F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5E9DB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5EB8B0
#define CMerchantWnd__RequestBuyItem                               0x5ECC40
#define CMerchantWnd__RequestSellItem                              0x5EBB10
#define CMerchantWnd__SelectBuySellSlot                            0x5EC970

// CObfuscator
#define CObfuscator__doit                                          0x658FB0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6B4750
#define CSidlManager__CreateLabel                                  0x617C10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6A59D0
#define CSidlScreenWnd__CalculateVSBRange                          0x6BA310
#define CSidlScreenWnd__ConvertToRes                               0x6C3CC0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6A5E20
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6A6EC0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6A6F70
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6A66B0
#define CSidlScreenWnd__DrawSidlPiece                              0x6A5B00
#define CSidlScreenWnd__EnableIniStorage                           0x6A5560
#define CSidlScreenWnd__GetSidlPiece                               0x6A5D00
#define CSidlScreenWnd__Init1                                      0x6A6D20
#define CSidlScreenWnd__LoadIniInfo                                0x6A5ED0
#define CSidlScreenWnd__LoadIniListWnd                             0x6A56B0
#define CSidlScreenWnd__LoadSidlScreen                             0x6A68F0
#define CSidlScreenWnd__StoreIniInfo                               0x6A5170
#define CSidlScreenWnd__WndNotification                            0x6A6AA0
#define CSidlScreenWnd__GetChildItem                               0x6A55C0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x521370

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6C4EB0
#define CSliderWnd__SetValue                                       0x6C4FB0
#define CSliderWnd__SetNumTicks                                    0x6C5530

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x61D2E0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6C1F60
#define CStmlWnd__CalculateVSBRange                                0x6BA310
#define CStmlWnd__CanBreakAtCharacter                              0x6BA450
#define CStmlWnd__FastForwardToEndOfTag                            0x6BAF50
#define CStmlWnd__ForceParseNow                                    0x6C23B0
#define CStmlWnd__GetNextTagPiece                                  0x6BAE70
#define CStmlWnd__GetSTMLText                                      0x58C170
#define CStmlWnd__GetThisChar                                      0x6E5530
#define CStmlWnd__GetVisiableText                                  0x6BC160
#define CStmlWnd__InitializeWindowVariables                        0x6BE2A0
#define CStmlWnd__MakeStmlColorTag                                 0x6B9A10
#define CStmlWnd__MakeWndNotificationTag                           0x6B9AB0
#define CStmlWnd__SetSTMLText                                      0x6BE3C0
#define CStmlWnd__StripFirstSTMLLines                              0x6C1CE0
#define CStmlWnd__UpdateHistoryString                              0x6BC9C0

// CTabWnd 
#define CTabWnd__Draw                                              0x6C6550
#define CTabWnd__DrawCurrentPage                                   0x6C5EE0
#define CTabWnd__DrawTab                                           0x6C5CC0
#define CTabWnd__GetCurrentPage                                    0x6C61E0
#define CTabWnd__GetPageClientRect                                 0x6C5990
#define CTabWnd__GetPageFromTabIndex                               0x6C5BF0
#define CTabWnd__GetPageInnerRect                                  0x6C59F0
#define CTabWnd__GetTabInnerRect                                   0x6C5B70
#define CTabWnd__GetTabRect                                        0x6C5A80
#define CTabWnd__IndexInBounds                                     0x6C5C8D
#define CTabWnd__InsertPage                                        0x6C6770
#define CTabWnd__SetPage                                           0x6C6220
#define CTabWnd__SetPageRect                                       0x6C6480
#define CTabWnd__UpdatePage                                        0x6C66F0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4145D0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6A72D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6CC180

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x699D20

// CXRect 
#define CXRect__CenterPoint                                        0x567F50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412930
#define CXStr__CXStr1                                              0x51E4A0
#define CXStr__CXStr3                                              0x68E530
#define CXStr__dCXStr                                              0x6C7220
#define CXStr__operator_equal1                                     0x68E6F0
#define CXStr__operator_plus_equal1                                0x68F5F0

// CXWnd 
#define CXWnd__BringToTop                                          0x69F640
#define CXWnd__Center                                              0x6A2FD0
#define CXWnd__ClrFocus                                            0x69F360
#define CXWnd__DoAllDrawing                                        0x6A3C90
#define CXWnd__DrawChildren                                        0x6A3DC0
#define CXWnd__DrawColoredRect                                     0x69F8D0
#define CXWnd__DrawTooltip                                         0x6A3B20
#define CXWnd__DrawTooltipAtPoint                                  0x6A2DA0
#define CXWnd__GetBorderFrame                                      0x69FD70
#define CXWnd__GetChildWndAt                                       0x6A28D0
#define CXWnd__GetClientClipRect                                   0x69FCB0
#define CXWnd__GetScreenClipRect                                   0x6A31F0
#define CXWnd__GetScreenRect                                       0x69FF80
#define CXWnd__GetTooltipRect                                      0x69FAF0
#define CXWnd__GetWindowTextA                                      0x55B760
#define CXWnd__IsActive                                            0x6A8400
#define CXWnd__IsDescendantOf                                      0x69FD20
#define CXWnd__IsReallyVisible                                     0x6A28B0
#define CXWnd__IsType                                              0x6C79C0
#define CXWnd__Move                                                0x6A24D0
#define CXWnd__Move1                                               0x6A3980
#define CXWnd__ProcessTransition                                   0x69F600
#define CXWnd__Refade                                              0x69F3D0
#define CXWnd__Resize                                              0x6A0040
#define CXWnd__Right                                               0x6A3130
#define CXWnd__SetFocus                                            0x6A16B0
#define CXWnd__SetKeyTooltip                                       0x6A0250
#define CXWnd__SetMouseOver                                        0x6A0220
#define CXWnd__StartFade                                           0x69F680
#define CXWnd__GetChildItem                                        0x6A3330

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6A97D0
#define CXWndManager__DrawWindows                                  0x6A9410
#define CXWndManager__GetKeyboardFlags                             0x6A8090
#define CXWndManager__HandleKeyboardMsg                            0x6A8600
#define CXWndManager__RemoveWnd                                    0x6A8520

// CDBStr
#define CDBStr__GetString                                          0x45C4A0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6F1540
#define EQ_Character__CastSpell                                    0x4255E0
#define EQ_Character__Cur_HP                                       0x431E00
#define EQ_Character__GetAACastingTimeModifier                     0x41FFC0
#define EQ_Character__GetCharInfo2                                 0x66F000
#define EQ_Character__GetFocusCastingTimeModifier                  0x41BC00
#define EQ_Character__GetFocusRangeModifier                        0x41BD40
#define EQ_Character__Max_Endurance                                0x42D380
#define EQ_Character__Max_HP                                       0x42D200
#define EQ_Character__Max_Mana                                     0x505110
#define EQ_Character__doCombatAbility                              0x503DD0
#define EQ_Character__UseSkill                                     0x437B90
#define EQ_Character__GetConLevel                                  0x500580

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F4050
#define EQ_Item__GetItemLinkHash                                   0x662AC0
#define EQ_Item__IsStackable                                       0x659890

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x474B70
#define EQ_LoadingS__Array                                         0x7A1878

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x508060
#define EQ_PC__GetAltAbilityIndex                                  0x667420
#define EQ_PC__GetCombatAbility                                    0x6674B0
#define EQ_PC__GetCombatAbilityTimer                               0x667560
#define EQ_PC__GetItemTimerValue                                   0x502DB0
#define EQ_PC__HasLoreItem                                         0x506530

// EQItemList 
#define EQItemList__dEQItemList                                    0x49D8E0
#define EQItemList__EQItemList                                     0x49D830

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45BE10

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50C7F0
#define EQPlayer__dEQPlayer                                        0x510790
#define EQPlayer__DoAttack                                         0x51D630
#define EQPlayer__EQPlayer                                         0x5143D0
#define EQPlayer__SetNameSpriteState                               0x50E760
#define EQPlayer__SetNameSpriteTint                                0x50C860
#define EQPlayer__IsBodyType_j                                     0x6F0F10

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x515490
#define EQPlayerManager__GetSpawnByName                            0x515670

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F5CD0
#define KeypressHandler__AttachKeyToEqCommand                      0x4F5D10
#define KeypressHandler__ClearCommandStateArray                    0x4F5AE0
#define KeypressHandler__HandleKeyDown                             0x4F46B0
#define KeypressHandler__HandleKeyUp                               0x4F49B0
#define KeypressHandler__SaveKeymapping                            0x4F5BB0

// MapViewMap 
#define MapViewMap__Clear                                          0x5E5480
#define MapViewMap__SaveEx                                         0x5E5E50

#define OtherCharData__GetAltCurrency                              0x6856A0

// StringTable 
#define StringTable__getString                                     0x659230
