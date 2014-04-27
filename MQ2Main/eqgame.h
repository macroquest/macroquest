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
#define __ExpectedVersionDate                                     "Apr 11 2012"
#define __ExpectedVersionTime                                     "15:35:58"
#define __ActualVersionDate                                        0x90B76C
#define __ActualVersionTime                                        0x90B778

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x535B40
#define __MemChecker1                                              0x815000
#define __MemChecker2                                              0x5B8630
#define __MemChecker3                                              0x5B8580
#define __MemChecker4                                              0x8372C0
#define __EncryptPad0                                              0x9E34F0
#define __EncryptPad1                                              0xA5BEA8
#define __EncryptPad2                                              0x9FB9A0
#define __EncryptPad3                                              0x9FB5A0
#define __EncryptPad4                                              0xA5D950
#define __AC1                                                      0x6F47C0
#define __AC2                                                      0x4F1855
#define __AC3                                                      0x5039D8
#define __AC4                                                      0x509364
#define __AC5                                                      0x515778
#define __AC6                                                      0x5190AB
#define __AC7                                                      0x5110FB
#define __AC1_Data                                                 0x8F07FD
// Direct Input
#define DI8__Main                                                  0xCE1290
#define DI8__Keyboard                                              0xCE1294
#define DI8__Mouse                                                 0xCE1298
#define __AltTimerReady                                            0xBA9881
#define __Attack                                                   0xCDD092
#define __Autofire                                                 0xCDD093
#define __BindList                                                 0x9CBB58
#define __Clicks                                                   0xC66B84
#define __CommandList                                              0x9CD190
#define __CurrentMapLabel                                          0xD0D0D0
#define __CurrentSocial                                            0x9B7E30
#define __DoAbilityList                                            0xC9DA6C
#define __do_loot                                                  0x4C5360
#define __DrawHandler                                              0x1369D64
#define __GroupCount                                               0xC57742
#define __Guilds                                                   0xC59AD0
#define __gWorld                                                   0xC599FC
#define __HotkeyPage                                               0xCC6648
#define __HWnd                                                     0xCE0FE0
#define __InChatMode                                               0xC66ABC
#define __LastTell                                                 0xC68984
#define __LMouseHeldTime                                           0xC66BF0
#define __Mouse                                                    0xCE129C
#define __MouseLook                                                0xC66B52
#define __MouseEventTime                                           0xCDD3AC
#define __NetStatusToggle                                          0xC66B55
#define __PCNames                                                  0xC68008
#define __RangeAttackReady                                         0xC67CA0
#define __RMouseHeldTime                                           0xC66BEC
#define __RunWalkState                                             0xC66AC0
#define __ScreenMode                                               0xBA6BC8
#define __ScreenX                                                  0xC66A70
#define __ScreenY                                                  0xC66A74
#define __ScreenXMax                                               0xC66A78
#define __ScreenYMax                                               0xC66A7C
#define __ServerHost                                               0xC57684
#define __ServerName                                               0xC9DA2C
#define __ShiftKeyDown                                             0xC6713C
#define __ShowNames                                                0xC67EAC
#define __Socials                                                  0xC9DB2C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xC633E8
#define instEQZoneInfo                                             0xC66D38
#define instKeypressHandler                                        0xCDD3A8
#define pinstActiveBanker                                          0xC59AA4
#define pinstActiveCorpse                                          0xC59AA8
#define pinstActiveGMaster                                         0xC59AAC
#define pinstActiveMerchant                                        0xC59AA0
#define pinstAltAdvManager                                         0xBA7B10
#define pinstAuraMgr                                               0xA76D50
#define pinstBandageTarget                                         0xC59A8C
#define pinstCamActor                                              0xBA7584
#define pinstCDBStr                                                0xBA6BA0
#define pinstCDisplay                                              0xC59AB4
#define pinstCEverQuest                                            0xCE1418
#define pinstCharData                                              0xC59A70
#define pinstCharSpawn                                             0xC59A98
#define pinstControlledMissile                                     0xC59A6C
#define pinstControlledPlayer                                      0xC59A98
#define pinstCSidlManager                                          0x136A2A4
#define pinstCXWndManager                                          0x136A29C
#define instDynamicZone                                            0xC62E40
#define pinstDZMember                                              0xC62F50
#define pinstDZTimerInfo                                           0xC62F54
#define pinstEQItemList                                            0xC567F0
#define instEQMisc                                                 0xBA6B08
#define pinstEQSoundManager                                        0xBA7B80
#define instExpeditionLeader                                       0xC62E8A
#define instExpeditionName                                         0xC62ECA
#define pinstGroup                                                 0xC5773E
#define pinstImeManager                                            0x136A2A8
#define pinstLocalPlayer                                           0xC59A84
#define pinstMercenaryData                                         0xCDD828
#define pinstModelPlayer                                           0xC59AB0
#define pinstPCData                                                0xC59A70
#define pinstSkillMgr                                              0xCDDE58
#define pinstSpawnManager                                          0xCDDAC8
#define pinstSpellManager                                          0xCDDE98
#define pinstSpellSets                                             0xCD63A0
#define pinstStringTable                                           0xC59A18
#define pinstSwitchManager                                         0xC57350
#define pinstTarget                                                0xC59A9C
#define pinstTargetObject                                          0xC59A74
#define pinstTargetSwitch                                          0xC59A78
#define pinstTaskMember                                            0xBA6AD0
#define pinstTrackTarget                                           0xC59A90
#define pinstTradeTarget                                           0xC59A80
#define instTributeActive                                          0xBA6B2D
#define pinstViewActor                                             0xBA7580
#define pinstWorldData                                             0xC59A54


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0xA6DD90
#define pinstCAudioTriggersWindow                                  0xA6DD28
#define pinstCCharacterSelect                                      0xBA7438
#define pinstCFacePick                                             0xBA73E8
#define pinstCNoteWnd                                              0xBA73F0
#define pinstCBookWnd                                              0xBA73F8
#define pinstCPetInfoWnd                                           0xBA73FC
#define pinstCTrainWnd                                             0xBA7400
#define pinstCSkillsWnd                                            0xBA7404
#define pinstCSkillsSelectWnd                                      0xBA7408
#define pinstCCombatSkillSelectWnd                                 0xBA740C
#define pinstCFriendsWnd                                           0xBA7410
#define pinstCAuraWnd                                              0xBA7414
#define pinstCRespawnWnd                                           0xBA7418
#define pinstCBandolierWnd                                         0xBA741C
#define pinstCPotionBeltWnd                                        0xBA7420
#define pinstCAAWnd                                                0xBA7424
#define pinstCGroupSearchFiltersWnd                                0xBA7428
#define pinstCLoadskinWnd                                          0xBA742C
#define pinstCAlarmWnd                                             0xBA7430
#define pinstCMusicPlayerWnd                                       0xBA7434
#define pinstCMailWnd                                              0xBA743C
#define pinstCMailCompositionWnd                                   0xBA7440
#define pinstCMailAddressBookWnd                                   0xBA7444
#define pinstCRaidWnd                                              0xBA744C
#define pinstCRaidOptionsWnd                                       0xBA7450
#define pinstCBreathWnd                                            0xBA7454
#define pinstCMapViewWnd                                           0xBA7458
#define pinstCMapToolbarWnd                                        0xBA745C
#define pinstCEditLabelWnd                                         0xBA7460
#define pinstCTargetWnd                                            0xBA7464
#define pinstCColorPickerWnd                                       0xBA7468
#define pinstCPlayerWnd                                            0xBA746C
#define pinstCOptionsWnd                                           0xBA7470
#define pinstCBuffWindowNORMAL                                     0xBA7474
#define pinstCBuffWindowSHORT                                      0xBA7478
#define pinstCharacterCreation                                     0xBA747C
#define pinstCCursorAttachment                                     0xBA7480
#define pinstCCastingWnd                                           0xBA7484
#define pinstCCastSpellWnd                                         0xBA7488
#define pinstCSpellBookWnd                                         0xBA748C
#define pinstCInventoryWnd                                         0xBA7490
#define pinstCBankWnd                                              0xBA7494
#define pinstCQuantityWnd                                          0xBA7498
#define pinstCLootWnd                                              0xBA749C
#define pinstCActionsWnd                                           0xBA74A0
#define pinstCCombatAbilityWnd                                     0xBA74A4
#define pinstCMerchantWnd                                          0xBA74A8
#define pinstCTradeWnd                                             0xBA74AC
#define pinstCSelectorWnd                                          0xBA74B0
#define pinstCBazaarWnd                                            0xBA74B4
#define pinstCBazaarSearchWnd                                      0xBA74B8
#define pinstCGiveWnd                                              0xBA74D4
#define pinstCTrackingWnd                                          0xBA74DC
#define pinstCInspectWnd                                           0xBA74E0
#define pinstCSocialEditWnd                                        0xBA74E4
#define pinstCFeedbackWnd                                          0xBA74E8
#define pinstCBugReportWnd                                         0xBA74EC
#define pinstCVideoModesWnd                                        0xBA74F0
#define pinstCTextEntryWnd                                         0xBA74F8
#define pinstCFileSelectionWnd                                     0xBA74FC
#define pinstCCompassWnd                                           0xBA7500
#define pinstCPlayerNotesWnd                                       0xBA7504
#define pinstCGemsGameWnd                                          0xBA7508
#define pinstCTimeLeftWnd                                          0xBA750C
#define pinstCPetitionQWnd                                         0xBA7520
#define pinstCSoulmarkWnd                                          0xBA7524
#define pinstCStoryWnd                                             0xBA7528
#define pinstCJournalTextWnd                                       0xBA752C
#define pinstCJournalCatWnd                                        0xBA7530
#define pinstCBodyTintWnd                                          0xBA7534
#define pinstCServerListWnd                                        0xBA7538
#define pinstCAvaZoneWnd                                           0xBA7540
#define pinstCBlockedBuffWnd                                       0xBA7544
#define pinstCBlockedPetBuffWnd                                    0xBA7548
#define pinstCInvSlotMgr                                           0xBA7578
#define pinstCContainerMgr                                         0xBA757C
#define pinstCAdventureLeaderboardWnd                              0xD09C08
#define pinstCAdventureRequestWnd                                  0xD09BD0
#define pinstCAltStorageWnd                                        0xD09D10
#define pinstCAdventureStatsWnd                                    0xD09C08
#define pinstCBarterMerchantWnd                                    0xD0A168
#define pinstCBarterSearchWnd                                      0xD0A1A0
#define pinstCBarterWnd                                            0xD0A1D8
#define pinstCChatManager                                          0xD0A5D0
#define pinstCDynamicZoneWnd                                       0xD0A7C0
#define pinstCEQMainWnd                                            0xD0A880
#define pinstCFellowshipWnd                                        0xD0A7B4
#define pinstCFindLocationWnd                                      0xD0A9B0
#define pinstCGroupSearchWnd                                       0xD0AB10
#define pinstCGroupWnd                                             0xD0AB48
#define pinstCGuildBankWnd                                         0xD0AB80
#define pinstCGuildMgmtWnd                                         0xD0CBF0
#define pinstCGuildTributeMasterWnd                                0xD0E818
#define pinstCHotButtonWnd                                         0xD0CC44
#define pinstCHotButtonWnd1                                        0xD0CC44
#define pinstCHotButtonWnd2                                        0xD0CC48
#define pinstCHotButtonWnd3                                        0xD0CC4C
#define pinstCHotButtonWnd4                                        0xD0CC8C
#define pinstCItemDisplayManager                                   0xD0CDC0
#define pinstCItemExpTransferWnd                                   0xD0CDFC
#define pinstCLeadershipWnd                                        0xD0CF28
#define pinstCLFGuildWnd                                           0xD0CF60
#define pinstCMIZoneSelectWnd                                      0xD0D200
#define pinstCAdventureMerchantWnd                                 0xD0D4B0
#define pinstCConfirmationDialog                                   0xD0D4E8
#define pinstCPopupWndManager                                      0xD0D4E8
#define pinstCProgressionSelectionWnd                              0xD0D550
#define pinstCPvPLeaderboardWnd                                    0xD0D588
#define pinstCPvPStatsWnd                                          0xD0D5C0
#define pinstCSystemInfoDialogBox                                  0xD0D8A8
#define pinstCTargetOfTargetWnd                                    0xD0E4C8
#define pinstCTaskSelectWnd                                        0xD0D764
#define pinstCTaskTemplateSelectWnd                                0xD0E568
#define pinstCTaskWnd                                              0xD0E5A0
#define pinstCTipWndOFDAY                                          0xD0E698
#define pinstCTipWndCONTEXT                                        0xD0E69C
#define pinstCTitleWnd                                             0xD0E6D0
#define pinstCTradeskillWnd                                        0xD0E748
#define pinstCTributeBenefitWnd                                    0xD0E7E0
#define pinstCTributeMasterWnd                                     0xD0E818
#define pinstCContextMenuManager                                   0x136A300
#define pinstCVoiceMacroWnd                                        0xCDE1E0
#define pinstCHtmlWnd                                              0xCDE258


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D9AB0
#define __ConvertItemTags                                          0x4CAA80
#define __ExecuteCmd                                               0x4B6570
#define __EQGetTime                                                0x816430
#define __get_melee_range                                          0x4BC840
#define __GetGaugeValueFromEQ                                      0x6F3570
#define __GetLabelFromEQ                                           0x6F4760
#define __GetXTargetType                                           0x771F20
#define __LoadFrontEnd                                             0x5B75A0
#define __NewUIINI                                                 0x6F3120
#define __ProcessGameEvents                                        0x5118E0
#define CrashDetected                                              0x5B73A0
#define DrawNetStatus                                              0x5435B0
#define Util__FastTime                                             0x815890
#define Expansion_HoT                                              0xC67E0C
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x489900
#define AltAdvManager__IsAbilityReady                              0x4899E0
#define AltAdvManager__GetAltAbility                               0x489C40

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x43CCE0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5DE4A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5E8230

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x523D10

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x601800
#define CChatManager__InitContextMenu                              0x602130

// CChatService
#define CChatService__GetNumberOfFriends                           0x768CA0
#define CChatService__GetFriendName                                0x768CB0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x606EF0
#define CChatWindow__Clear                                         0x606AA0
#define CChatWindow__WndNotification                               0x607300

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7C4DB0
#define CComboWnd__Draw                                            0x7C4F70
#define CComboWnd__GetCurChoice                                    0x7C4BD0
#define CComboWnd__GetListRect                                     0x7C5250
#define CComboWnd__GetTextRect                                     0x7C4DE0
#define CComboWnd__InsertChoice                                    0x7C52C0
#define CComboWnd__SetColors                                       0x7C4B60
#define CComboWnd__SetChoice                                       0x7C4B90

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x610760
#define CContainerWnd__vftable                                     0x9141B0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x47D170
#define CDisplay__GetClickedActor                                  0x475D60
#define CDisplay__GetUserDefinedColor                              0x474690
#define CDisplay__GetWorldFilePath                                 0x473BB0
#define CDisplay__is3dON                                           0x472CB0
#define CDisplay__ReloadUI                                         0x4867E0
#define CDisplay__WriteTextHD2                                     0x478E50

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5D60C0
#define CEditBaseWnd__SetSel                                       0x7E5640

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7CE450
#define CEditWnd__GetCharIndexPt                                   0x7CF420
#define CEditWnd__GetDisplayString                                 0x7CE5F0
#define CEditWnd__GetHorzOffset                                    0x7CE880
#define CEditWnd__GetLineForPrintableChar                          0x7CEED0
#define CEditWnd__GetSelStartPt                                    0x7CF660
#define CEditWnd__GetSTMLSafeText                                  0x7CEA20
#define CEditWnd__PointFromPrintableChar                           0x7CEFE0
#define CEditWnd__SelectableCharFromPoint                          0x7CF160
#define CEditWnd__SetEditable                                      0x7CE9F0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4F1FA0
#define CEverQuest__DropHeldItemOnGround                           0x4FEE90
#define CEverQuest__dsp_chat                                       0x4F8220
#define CEverQuest__DoTellWindow                                   0x4F69B0
#define CEverQuest__EnterZone                                      0x5092F0
#define CEverQuest__GetBodyTypeDesc                                0x4EEDA0
#define CEverQuest__GetClassDesc                                   0x4EE5E0
#define CEverQuest__GetClassThreeLetterCode                        0x4EEBE0
#define CEverQuest__GetDeityDesc                                   0x4EF450
#define CEverQuest__GetLangDesc                                    0x4EF130
#define CEverQuest__GetRaceDesc                                    0x4EF420
#define CEverQuest__InterpretCmd                                   0x4F8D30
#define CEverQuest__LeftClickedOnPlayer                            0x50B390
#define CEverQuest__LMouseUp                                       0x50EF80
#define CEverQuest__RightClickedOnPlayer                           0x5100E0
#define CEverQuest__RMouseUp                                       0x5110C0
#define CEverQuest__SetGameState                                   0x4F2430
#define CEverQuest__Emote                                          0x4F8440

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x61E720
#define CGaugeWnd__CalcLinesFillRect                               0x61E780
#define CGaugeWnd__Draw                                            0x61EBD0

// CGuild
#define CGuild__FindMemberByName                                   0x41CDD0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x638C60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x643040
#define CInvSlotMgr__MoveItem                                      0x643CF0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x6426C0
#define CInvSlot__SliderComplete                                   0x6409B0
#define CInvSlot__GetItemBase                                      0x640040

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x644A40

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6F0B30
#define CItemDisplayWnd__UpdateStrings                             0x645A80

// CLabel 
#define CLabel__Draw                                               0x65A1E0

// CListWnd 
#define CListWnd__AddColumn                                        0x7BA6A0
#define CListWnd__AddColumn1                                       0x7B9CD0
#define CListWnd__AddLine                                          0x7B9880
#define CListWnd__AddString                                        0x7B9A20
#define CListWnd__CalculateFirstVisibleLine                        0x7B5AF0
#define CListWnd__CalculateVSBRange                                0x7B7EF0
#define CListWnd__ClearAllSel                                      0x7B5040
#define CListWnd__CloseAndUpdateEditWindow                         0x7B8EF0
#define CListWnd__Compare                                          0x7B6590
#define CListWnd__Draw                                             0x7B7B30
#define CListWnd__DrawColumnSeparators                             0x7B79C0
#define CListWnd__DrawHeader                                       0x7B52D0
#define CListWnd__DrawItem                                         0x7B6F90
#define CListWnd__DrawLine                                         0x7B7680
#define CListWnd__DrawSeparator                                    0x7B7A60
#define CListWnd__EnsureVisible                                    0x7B5C50
#define CListWnd__ExtendSel                                        0x7B6EB0
#define CListWnd__GetColumnMinWidth                                0x7B4D10
#define CListWnd__GetColumnWidth                                   0x7B4C50
#define CListWnd__GetCurSel                                        0x7B43F0
#define CListWnd__GetHeaderRect                                    0x7B4570
#define CListWnd__GetItemAtPoint                                   0x7B5F20
#define CListWnd__GetItemAtPoint1                                  0x7B5F90
#define CListWnd__GetItemData                                      0x7B4850
#define CListWnd__GetItemHeight                                    0x7B5760
#define CListWnd__GetItemIcon                                      0x7B4A30
#define CListWnd__GetItemRect                                      0x7B5D20
#define CListWnd__GetItemText                                      0x7B48E0
#define CListWnd__GetSelList                                       0x7B9BB0
#define CListWnd__GetSeparatorRect                                 0x7B64E0
#define CListWnd__RemoveLine                                       0x7BA650
#define CListWnd__SetColors                                        0x7B44E0
#define CListWnd__SetColumnJustification                           0x7B4EB0
#define CListWnd__SetColumnWidth                                   0x7B4CD0
#define CListWnd__SetCurSel                                        0x7B4430
#define CListWnd__SetItemColor                                     0x7B8BA0
#define CListWnd__SetItemData                                      0x7B50E0
#define CListWnd__SetItemText                                      0x7B89D0
#define CListWnd__ShiftColumnSeparator                             0x7B8840
#define CListWnd__Sort                                             0x7BAE00
#define CListWnd__ToggleSel                                        0x7B4FB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x672C60

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x68E0B0
#define CMerchantWnd__RequestBuyItem                               0x6942E0
#define CMerchantWnd__RequestSellItem                              0x6B5960
#define CMerchantWnd__SelectBuySellSlot                            0x68E360

// CObfuscator
#define CObfuscator__doit                                          0x73C1C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7D6E70
#define CSidlManager__CreateLabel                                  0x6E9260

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5DA160
#define CSidlScreenWnd__CalculateVSBRange                          0x5DA080
#define CSidlScreenWnd__ConvertToRes                               0x7E5520
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7C7400
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7C8640
#define CSidlScreenWnd__CSidlScreenWnd2                            0x7C86F0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x7C7DD0
#define CSidlScreenWnd__DrawSidlPiece                              0x7C6EA0
#define CSidlScreenWnd__EnableIniStorage                           0x7C6660
#define CSidlScreenWnd__GetSidlPiece                               0x7C70C0
#define CSidlScreenWnd__Init1                                      0x7C8490
#define CSidlScreenWnd__LoadIniInfo                                0x7C74C0
#define CSidlScreenWnd__LoadIniListWnd                             0x7C67B0
#define CSidlScreenWnd__LoadSidlScreen                             0x7C8030
#define CSidlScreenWnd__StoreIniInfo                               0x7C6230
#define CSidlScreenWnd__StoreIniVis                                0x7C65F0
#define CSidlScreenWnd__WndNotification                            0x7C8280
#define CSidlScreenWnd__GetChildItem                               0x7C66C0

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x581530
#define CSkillMgr__GetSkillCap                                     0x5815A0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7ED6C0
#define CSliderWnd__SetValue                                       0x7ED7C0
#define CSliderWnd__SetNumTicks                                    0x7EDD70

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6EE7D0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7E2AB0
#define CStmlWnd__CalculateHSBRange                                0x7DA070
#define CStmlWnd__CalculateVSBRange                                0x7DA100
#define CStmlWnd__CanBreakAtCharacter                              0x7DA270
#define CStmlWnd__FastForwardToEndOfTag                            0x7DAF60
#define CStmlWnd__ForceParseNow                                    0x7E30A0
#define CStmlWnd__GetNextTagPiece                                  0x7DAE80
#define CStmlWnd__GetSTMLText                                      0x606340
#define CStmlWnd__GetThisChar                                      0x80E140
#define CStmlWnd__GetVisiableText                                  0x7DC3C0
#define CStmlWnd__InitializeWindowVariables                        0x7DE9B0
#define CStmlWnd__MakeStmlColorTag                                 0x7D8F90
#define CStmlWnd__MakeWndNotificationTag                           0x7D9030
#define CStmlWnd__SetSTMLText                                      0x7DEAE0
#define CStmlWnd__StripFirstSTMLLines                              0x7E2750
#define CStmlWnd__UpdateHistoryString                              0x7DCC60

// CTabWnd 
#define CTabWnd__Draw                                              0x7E92B0
#define CTabWnd__DrawCurrentPage                                   0x7E8B30
#define CTabWnd__DrawTab                                           0x7E8900
#define CTabWnd__GetCurrentPage                                    0x7E8EF0
#define CTabWnd__GetPageClientRect                                 0x7E85B0
#define CTabWnd__GetPageFromTabIndex                               0x7E8830
#define CTabWnd__GetPageInnerRect                                  0x7E8610
#define CTabWnd__GetTabInnerRect                                   0x7E87B0
#define CTabWnd__GetTabRect                                        0x7E86A0
#define CTabWnd__InsertPage                                        0x7E9540
#define CTabWnd__SetPage                                           0x7E8F30
#define CTabWnd__SetPageRect                                       0x7E91E0
#define CTabWnd__UpdatePage                                        0x7E94C0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x419310

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7C8A70

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7E6760

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x7B3350

// CXRect 
#define CXRect__CenterPoint                                        0x522E30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x52E680
#define CXStr__CXStr1                                              0x825C40
#define CXStr__CXStr3                                              0x812760
#define CXStr__dCXStr                                              0x477020
#define CXStr__operator_equal                                      0x8128D0
#define CXStr__operator_equal1                                     0x812920
#define CXStr__operator_plus_equal1                                0x813A30

// CXWnd 
#define CXWnd__BringToTop                                          0x7BDD80
#define CXWnd__Center                                              0x7C3730
#define CXWnd__ClrFocus                                            0x7BDBC0
#define CXWnd__DoAllDrawing                                        0x7C35C0
#define CXWnd__DrawChildren                                        0x7C3700
#define CXWnd__DrawColoredRect                                     0x7BE0A0
#define CXWnd__DrawTooltip                                         0x7BE290
#define CXWnd__DrawTooltipAtPoint                                  0x7C2830
#define CXWnd__GetBorderFrame                                      0x7BE6B0
#define CXWnd__GetChildWndAt                                       0x7C1A20
#define CXWnd__GetClientClipRect                                   0x7BE430
#define CXWnd__GetScreenClipRect                                   0x7C2D60
#define CXWnd__GetScreenRect                                       0x7BE7E0
#define CXWnd__GetTooltipRect                                      0x7BE1B0
#define CXWnd__GetWindowTextA                                      0x5229B0
#define CXWnd__IsActive                                            0x7C9BB0
#define CXWnd__IsDescendantOf                                      0x7BE5A0
#define CXWnd__IsReallyVisible                                     0x7C1A00
#define CXWnd__IsType                                              0x7EAB80
#define CXWnd__Move                                                0x7C1170
#define CXWnd__Move1                                               0x7C3290
#define CXWnd__ProcessTransition                                   0x7BDD30
#define CXWnd__Refade                                              0x7BDCC0
#define CXWnd__Resize                                              0x7BE8B0
#define CXWnd__Right                                               0x7C2C70
#define CXWnd__SetFocus                                            0x7C02E0
#define CXWnd__SetKeyTooltip                                       0x7BEB00
#define CXWnd__SetMouseOver                                        0x7C3080
#define CXWnd__StartFade                                           0x7BDDC0
#define CXWnd__GetChildItem                                        0x7C2FC0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x7CB110
#define CXWndManager__DrawWindows                                  0x7CAD90
#define CXWndManager__GetKeyboardFlags                             0x7C9800
#define CXWndManager__HandleKeyboardMsg                            0x7C9E80
#define CXWndManager__RemoveWnd                                    0x7C9CD0

// CDBStr
#define CDBStr__GetString                                          0x471300

// EQ_Character 
#define EQ_Character__CastRay                                      0x755EA0
#define EQ_Character__CastSpell                                    0x433050
#define EQ_Character__Cur_HP                                       0x43C980
#define EQ_Character__GetAACastingTimeModifier                     0x427C50
#define EQ_Character__GetCharInfo2                                 0x754230
#define EQ_Character__GetFocusCastingTimeModifier                  0x4229F0
#define EQ_Character__GetFocusRangeModifier                        0x422BC0
#define EQ_Character__Max_Endurance                                0x54EB80
#define EQ_Character__Max_HP                                       0x437050
#define EQ_Character__Max_Mana                                     0x54E980
#define EQ_Character__doCombatAbility                              0x54D770
#define EQ_Character__UseSkill                                     0x44C6B0
#define EQ_Character__GetConLevel                                  0x546C70
#define EQ_Character__IsExpansionFlag                              0x40DCE0
#define EQ_Character__TotalEffect                                  0x42C4B0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5284B0
#define EQ_Item__CreateItemTagString                               0x73A250
#define EQ_Item__IsStackable                                       0x72EC50

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x48AF30
#define EQ_LoadingS__Array                                         0x9C68D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x552450
#define EQ_PC__GetAltAbilityIndex                                  0x7456B0
#define EQ_PC__GetCombatAbility                                    0x745740
#define EQ_PC__GetCombatAbilityTimer                               0x7457F0
#define EQ_PC__GetItemTimerValue                                   0x54D4E0
#define EQ_PC__HasLoreItem                                         0x54BFB0

// EQItemList 
#define EQItemList__EQItemList                                     0x4BAB80
#define EQItemList__add_item                                       0x4BAB10
#define EQItemList__delete_item                                    0x4BAF30
#define EQItemList__FreeItemList                                   0x4BAE60

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x4708C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x557530
#define EQPlayer__dEQPlayer                                        0x55C150
#define EQPlayer__DoAttack                                         0x56D8F0
#define EQPlayer__EQPlayer                                         0x561C90
#define EQPlayer__SetNameSpriteState                               0x559A50
#define EQPlayer__SetNameSpriteTint                                0x5575A0
#define EQPlayer__IsBodyType_j                                     0x755740
#define EQPlayer__IsTargetable                                     0x755A10

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x563050
#define EQPlayerManager__GetSpawnByName                            0x5632E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x52DFF0
#define KeypressHandler__AttachKeyToEqCommand                      0x52E030
#define KeypressHandler__ClearCommandStateArray                    0x52DE00
#define KeypressHandler__HandleKeyDown                             0x52C7A0
#define KeypressHandler__HandleKeyUp                               0x52CAB0
#define KeypressHandler__SaveKeymapping                            0x52DED0

// MapViewMap 
#define MapViewMap__Clear                                          0x66BEB0
#define MapViewMap__SaveEx                                         0x66F560

#define PlayerPointManager__GetAltCurrency                         0x73FCB0

// StringTable 
#define StringTable__getString                                     0x73C440

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x550D10