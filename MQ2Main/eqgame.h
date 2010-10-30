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
#define __ExpectedVersionDate                                     "Oct 25 2010"
#define __ExpectedVersionTime                                     "16:06:51"
#define __ActualVersionDate                                        0x8797B0
#define __ActualVersionTime                                        0x8797BC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x525020
#define __MemChecker1                                              0x796C00
#define __MemChecker2                                              0x596400
#define __MemChecker3                                              0x596350
#define __MemChecker4                                              0x7B0C80
#define __EncryptPad0                                              0x90F4E0
#define __EncryptPad1                                              0x91B0E8
#define __EncryptPad2                                              0x912220
#define __EncryptPad3                                              0x911E20
#define __EncryptPad4                                              0x91CB18
#define __AC1                                                      0x6A42A0
#define __AC2                                                      0x4E7FD5
#define __AC3                                                      0x4FA988
#define __AC4                                                      0x4FFCB8
#define __AC5                                                      0x50BE8E
#define __AC6                                                      0x50F5DE
#define __AC7                                                      0x507A5B
#define __AC1_Data                                                 0x86129D

// Direct Input
#define DI8__Main                                                  0xB791DC
#define DI8__Keyboard                                              0xB791E0
#define DI8__Mouse                                                 0xB791E4
#define __AltTimerReady                                            0xAFD942
#define __Attack                                                   0xB61426
#define __Autofire                                                 0xB61427
#define __BindList                                                 0x909AE8
#define __Clicks                                                   0xAFC5F8
#define __CommandList                                              0x90A4B8
#define __CurrentMapLabel                                          0xBA4478
#define __CurrentSocial                                            0x90595C
#define __DoAbilityAvailable                                       0xAFD8DC
#define __DoAbilityList                                            0xB33344
#define __do_loot                                                  0x4BD280
#define __DrawHandler                                              0x1158754
#define __GroupCount                                               0xAF63EA
#define __Guilds                                                   0xAFB9D8
#define __gWorld                                                   0xAF82A4
#define __HotkeyPage                                               0xB5A730
#define __HWnd                                                     0xB78F18
#define __InChatMode                                               0xAFC530
#define __LastTell                                                 0xAFE25C
#define __LMouseHeldTime                                           0xAFC664
#define __Mouse                                                    0xB791E8
#define __MouseLook                                                0xAFC5C6
#define __MouseEventTime                                           0xB61588
#define __NetStatusToggle                                          0xAFC5C9
#define __PCNames                                                  0xAFDCA0
#define __RangeAttackReady                                         0xAFD940
#define __RMouseHeldTime                                           0xAFC660
#define __RunWalkState                                             0xAFC534
#define __ScreenMode                                               0xA45C40
#define __ScreenX                                                  0xAFC4E8
#define __ScreenY                                                  0xAFC4EC
#define __ScreenXMax                                               0xAFC4F0
#define __ScreenYMax                                               0xAFC4F4
#define __ServerHost                                               0xAF632C
#define __ServerName                                               0xB33304
#define __ShiftKeyDown                                             0xAFCBF4
#define __ShowNames                                                0xAFDB74
#define __Socials                                                  0xB33404


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xAF8370
#define instEQZoneInfo                                             0xAFC7B0
#define instKeypressHandler                                        0xB6156C
#define pinstActiveBanker                                          0xAF8348
#define pinstActiveCorpse                                          0xAF834C
#define pinstActiveGMaster                                         0xAF8350
#define pinstActiveMerchant                                        0xAF8344
#define pinstAltAdvManager                                         0xA46AD8
#define pinstAuraMgr                                               0x92F4FC
#define pinstBandageTarget                                         0xAF8330
#define pinstCamActor                                              0xA465C4
#define pinstCDBStr                                                0xA45C34
#define pinstCDisplay                                              0xAF8358
#define pinstCEverQuest                                            0xB79360
#define pinstCharData                                              0xAF8314
#define pinstCharSpawn                                             0xAF833C
#define pinstControlledMissile                                     0xAF8310
#define pinstControlledPlayer                                      0xAF833C
#define pinstCSidlManager                                          0x1158C24
#define pinstCXWndManager                                          0x1158C1C
#define instDynamicZone                                            0xAFC3B8
#define pinstDZMember                                              0xAFC4C8
#define pinstDZTimerInfo                                           0xAFC4CC
#define pinstEQItemList                                            0xAF5600
#define instEQMisc                                                 0xA45BE0
#define pinstEQSoundManager                                        0xA46AFC
#define instExpeditionLeader                                       0xAFC402
#define instExpeditionName                                         0xAFC442
#define pinstGroup                                                 0xAF63E6
#define pinstImeManager                                            0x1158C28
#define pinstLocalPlayer                                           0xAF8328
#define pinstMercenaryData                                         0xB618FC
#define pinstModelPlayer                                           0xAF8354
#define pinstPCData                                                0xAF8314
#define pinstSkillMgr                                              0xB75FCC
#define pinstSpawnManager                                          0xB75DE8
#define pinstSpellManager                                          0xB75FD8
#define pinstSpellSets                                             0xB5A734
#define pinstStringTable                                           0xAF82C0
#define pinstSwitchManager                                         0xAF602C
#define pinstTarget                                                0xAF8340
#define pinstTargetObject                                          0xAF8318
#define pinstTargetSwitch                                          0xAF831C
#define pinstTaskMember                                            0xA45BC0
#define pinstTrackTarget                                           0xAF8334
#define pinstTradeTarget                                           0xAF8324
#define instTributeActive                                          0xA45C11
#define pinstViewActor                                             0xA465C0
#define pinstWorldData                                             0xAF82F8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x92CDC0
#define pinstCAudioTriggersWindow                                  0x92CD8C
#define pinstCCharacterSelect                                      0xA464A8
#define pinstCFacePick                                             0xA46458
#define pinstCNoteWnd                                              0xA46460
#define pinstCBookWnd                                              0xA46464
#define pinstCPetInfoWnd                                           0xA46468
#define pinstCTrainWnd                                             0xA4646C
#define pinstCSkillsWnd                                            0xA46470
#define pinstCSkillsSelectWnd                                      0xA46474
#define pinstCCombatSkillSelectWnd                                 0xA46478
#define pinstCFriendsWnd                                           0xA4647C
#define pinstCAuraWnd                                              0xA46480
#define pinstCRespawnWnd                                           0xA46484
#define pinstCBandolierWnd                                         0xA46488
#define pinstCPotionBeltWnd                                        0xA4648C
#define pinstCAAWnd                                                0xA46490
#define pinstCGroupSearchFiltersWnd                                0xA46494
#define pinstCLoadskinWnd                                          0xA46498
#define pinstCAlarmWnd                                             0xA4649C
#define pinstCMusicPlayerWnd                                       0xA464A0
#define pinstCMailWnd                                              0xA464AC
#define pinstCMailCompositionWnd                                   0xA464B0
#define pinstCMailAddressBookWnd                                   0xA464B4
#define pinstCRaidWnd                                              0xA464BC
#define pinstCRaidOptionsWnd                                       0xA464C0
#define pinstCBreathWnd                                            0xA464C4
#define pinstCMapViewWnd                                           0xA464C8
#define pinstCMapToolbarWnd                                        0xA464CC
#define pinstCEditLabelWnd                                         0xA464D0
#define pinstCTargetWnd                                            0xA464D4
#define pinstCColorPickerWnd                                       0xA464D8
#define pinstCPlayerWnd                                            0xA464DC
#define pinstCOptionsWnd                                           0xA464E0
#define pinstCBuffWindowNORMAL                                     0xA464E4
#define pinstCBuffWindowSHORT                                      0xA464E8
#define pinstCharacterCreation                                     0xA464EC
#define pinstCCursorAttachment                                     0xA464F0
#define pinstCCastingWnd                                           0xA464F4
#define pinstCCastSpellWnd                                         0xA464F8
#define pinstCSpellBookWnd                                         0xA464FC
#define pinstCInventoryWnd                                         0xA46500
#define pinstCBankWnd                                              0xA46504
#define pinstCQuantityWnd                                          0xA46508
#define pinstCLootWnd                                              0xA4650C
#define pinstCActionsWnd                                           0xA46510
#define pinstCCombatAbilityWnd                                     0xA46514
#define pinstCMerchantWnd                                          0xA46518
#define pinstCTradeWnd                                             0xA4651C
#define pinstCSelectorWnd                                          0xA46520
#define pinstCBazaarWnd                                            0xA46524
#define pinstCBazaarSearchWnd                                      0xA46528
#define pinstCGiveWnd                                              0xA46540
#define pinstCTrackingWnd                                          0xA46544
#define pinstCInspectWnd                                           0xA46548
#define pinstCSocialEditWnd                                        0xA4654C
#define pinstCFeedbackWnd                                          0xA46550
#define pinstCBugReportWnd                                         0xA46554
#define pinstCVideoModesWnd                                        0xA46558
#define pinstCTextEntryWnd                                         0xA46560
#define pinstCFileSelectionWnd                                     0xA46564
#define pinstCCompassWnd                                           0xA46568
#define pinstCPlayerNotesWnd                                       0xA4656C
#define pinstCGemsGameWnd                                          0xA46570
#define pinstCTimeLeftWnd                                          0xA46574
#define pinstCPetitionQWnd                                         0xA46588
#define pinstCSoulmarkWnd                                          0xA4658C
#define pinstCStoryWnd                                             0xA46590
#define pinstCJournalTextWnd                                       0xA46594
#define pinstCJournalCatWnd                                        0xA46598
#define pinstCBodyTintWnd                                          0xA4659C
#define pinstCServerListWnd                                        0xA465A0
#define pinstCAvaZoneWnd                                           0xA465A8
#define pinstCBlockedBuffWnd                                       0xA465AC
#define pinstCBlockedPetBuffWnd                                    0xA465B0
#define pinstCInvSlotMgr                                           0xA465B8
#define pinstCContainerMgr                                         0xA465BC
#define pinstCAdventureLeaderboardWnd                              0xBA1990
#define pinstCAdventureRequestWnd                                  0xBA19AC
#define pinstCAltStorageWnd                                        0xBA1A0C
#define pinstCAdventureStatsWnd                                    0xBA19C8
#define pinstCBarterMerchantWnd                                    0xBA1BD8
#define pinstCBarterSearchWnd                                      0xBA1BF4
#define pinstCBarterWnd                                            0xBA1C10
#define pinstCChatManager                                          0xBA1EB4
#define pinstCDynamicZoneWnd                                       0xBA1FAC
#define pinstCEQMainWnd                                            0xBA2020
#define pinstCFellowshipWnd                                        0xBA2084
#define pinstCFindLocationWnd                                      0xBA20B8
#define pinstCGroupSearchWnd                                       0xBA2168
#define pinstCGroupWnd                                             0xBA2184
#define pinstCGuildBankWnd                                         0xBA21A0
#define pinstCGuildMgmtWnd                                         0xBA41D8
#define pinstCGuildTributeMasterWnd                                0xBA41F8
#define pinstCHotButtonWnd                                         0xBA422C
#define pinstCHotButtonWnd1                                        0xBA422C
#define pinstCHotButtonWnd2                                        0xBA4230
#define pinstCHotButtonWnd3                                        0xBA4234
#define pinstCHotButtonWnd4                                        0xBA4238
#define pinstCItemDisplayManager                                   0xBA42E4
#define pinstCItemExpTransferWnd                                   0xBA4304
#define pinstCLeadershipWnd                                        0xBA43A0
#define pinstCLFGuildWnd                                           0xBA43BC
#define pinstCMIZoneSelectWnd                                      0xBA452C
#define pinstCAdventureMerchantWnd                                 0xBA4654
#define pinstCConfirmationDialog                                   0xBA4670
#define pinstCPopupWndManager                                      0xBA4670
#define pinstCProgressionSelectionWnd                              0xBA46A4
#define pinstCPvPLeaderboardWnd                                    0xBA46C0
#define pinstCPvPStatsWnd                                          0xBA46DC
#define pinstCSystemInfoDialogBox                                  0xBA4820
#define pinstCTargetOfTargetWnd                                    0xBA5328
#define pinstCTaskSelectWnd                                        0xBA535C
#define pinstCTaskTemplateSelectWnd                                0xBA5378
#define pinstCTaskWnd                                              0xBA5394
#define pinstCTipWndOFDAY                                          0xBA5410
#define pinstCTipWndCONTEXT                                        0xBA5414
#define pinstCTitleWnd                                             0xBA5430
#define pinstCTradeskillWnd                                        0xBA5474
#define pinstCTributeBenefitWnd                                    0xBA54C0
#define pinstCTributeMasterWnd                                     0xBA54DC
#define pinstCContextMenuManager                                   0x1158C80
#define pinstCVoiceMacroWnd                                        0xB761CC
#define pinstCHtmlWnd                                              0xB76218


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D0EF0
#define __ConvertItemTags                                          0x4C2900
#define __ExecuteCmd                                               0x4AE6C0
#define __get_melee_range                                          0x4B46B0
#define __GetGaugeValueFromEQ                                      0x6A3120
#define __GetLabelFromEQ                                           0x6A4240
#define __GetXTargetType                                           0x716810
#define __LoadFrontEnd                                             0x595320
#define __NewUIINI                                                 0x6A2C40
#define __ProcessGameEvents                                        0x5081D0
#define CrashDetected                                              0x595120
#define DrawNetStatus                                              0x531670
#define Util__FastTime                                             0x7973B0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483730
#define AltAdvManager__IsAbilityReady                              0x483770
#define AltAdvManager__GetAltAbility                               0x483990

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x438E90

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5B2CD0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5BCE00

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x75DA50

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5D4CA0
#define CChatManager__InitContextMenu                              0x5D5470

// CChatService
#define CChatService__GetNumberOfFriends                           0x70BE90
#define CChatService__GetFriendName                                0x70BEA0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5D9740
#define CChatWindow__Clear                                         0x5DA0A0
#define CChatWindow__WndNotification                               0x5DA290

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x747A70
#define CComboWnd__Draw                                            0x747C30
#define CComboWnd__GetCurChoice                                    0x747930
#define CComboWnd__GetListRect                                     0x747F20
#define CComboWnd__GetTextRect                                     0x747AA0
#define CComboWnd__InsertChoice                                    0x747F90
#define CComboWnd__SetColors                                       0x7478C0
#define CComboWnd__SetChoice                                       0x7478F0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5E2EC0
#define CContainerWnd__vftable                                     0x880EB0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x476100
#define CDisplay__GetClickedActor                                  0x46EFD0
#define CDisplay__GetUserDefinedColor                              0x46DBD0
#define CDisplay__GetWorldFilePath                                 0x46D060
#define CDisplay__is3dON                                           0x46C190
#define CDisplay__ReloadUI                                         0x480930
#define CDisplay__WriteTextHD2                                     0x471E90

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5ACDF0
#define CEditBaseWnd__SetSel                                       0x76B060

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x750A80
#define CEditWnd__GetCharIndexPt                                   0x751A40
#define CEditWnd__GetDisplayString                                 0x750C10
#define CEditWnd__GetHorzOffset                                    0x750EA0
#define CEditWnd__GetLineForPrintableChar                          0x7514F0
#define CEditWnd__GetSelStartPt                                    0x751C90
#define CEditWnd__GetSTMLSafeText                                  0x751040
#define CEditWnd__PointFromPrintableChar                           0x751600
#define CEditWnd__SelectableCharFromPoint                          0x751780
#define CEditWnd__SetEditable                                      0x751010

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4E8700
#define CEverQuest__DropHeldItemOnGround                           0x4F5D70
#define CEverQuest__dsp_chat                                       0x4EEAF0
#define CEverQuest__DoTellWindow                                   0x4ED280
#define CEverQuest__EnterZone                                      0x4FFC50
#define CEverQuest__GetBodyTypeDesc                                0x4E5570
#define CEverQuest__GetClassDesc                                   0x4E4DB0
#define CEverQuest__GetClassThreeLetterCode                        0x4E53B0
#define CEverQuest__GetDeityDesc                                   0x4E5BE0
#define CEverQuest__GetLangDesc                                    0x4E5900
#define CEverQuest__GetRaceDesc                                    0x4E5BB0
#define CEverQuest__InterpretCmd                                   0x4EF650
#define CEverQuest__LeftClickedOnPlayer                            0x501DD0
#define CEverQuest__LMouseUp                                       0x505760
#define CEverQuest__RightClickedOnPlayer                           0x5068B0
#define CEverQuest__RMouseUp                                       0x507A20
#define CEverQuest__SetGameState                                   0x4E8B90
#define CEverQuest__Emote                                          0x4EED10

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5EFDA0
#define CGaugeWnd__CalcLinesFillRect                               0x5EFE00
#define CGaugeWnd__Draw                                            0x5F0250

// CGuild
#define CGuild__FindMemberByName                                   0x41B880

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x608F60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x614270
#define CInvSlotMgr__MoveItem                                      0x614680

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x613720
#define CInvSlot__SliderComplete                                   0x6121E0
#define CInvSlot__GetItemBase                                      0x611940

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x615330

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6A09D0
#define CItemDisplayWnd__UpdateStrings                             0x616200

// CLabel 
#define CLabel__Draw                                               0x62A4A0

// CListWnd 
#define CListWnd__AddColumn                                        0x740740
#define CListWnd__AddColumn1                                       0x73FDB0
#define CListWnd__AddLine                                          0x73F960
#define CListWnd__AddString                                        0x73FB00
#define CListWnd__CalculateFirstVisibleLine                        0x73BC70
#define CListWnd__CalculateVSBRange                                0x73DFA0
#define CListWnd__ClearAllSel                                      0x73B1C0
#define CListWnd__CloseAndUpdateEditWindow                         0x73EFD0
#define CListWnd__Compare                                          0x73C670
#define CListWnd__Draw                                             0x73DBE0
#define CListWnd__DrawColumnSeparators                             0x73DA50
#define CListWnd__DrawHeader                                       0x73B450
#define CListWnd__DrawItem                                         0x73D070
#define CListWnd__DrawLine                                         0x73D6D0
#define CListWnd__DrawSeparator                                    0x73DAF0
#define CListWnd__EnsureVisible                                    0x73BDD0
#define CListWnd__ExtendSel                                        0x73CF90
#define CListWnd__GetColumnMinWidth                                0x73AE90
#define CListWnd__GetColumnWidth                                   0x73ADD0
#define CListWnd__GetCurSel                                        0x73A620
#define CListWnd__GetHeaderRect                                    0x73A780
#define CListWnd__GetItemAtPoint                                   0x73C0A0
#define CListWnd__GetItemAtPoint1                                  0x73C110
#define CListWnd__GetItemData                                      0x73A9D0
#define CListWnd__GetItemHeight                                    0x73B8E0
#define CListWnd__GetItemIcon                                      0x73ABB0
#define CListWnd__GetItemRect                                      0x73BEA0
#define CListWnd__GetItemText                                      0x73AA60
#define CListWnd__GetSelList                                       0x73FC90
#define CListWnd__GetSeparatorRect                                 0x73C5C0
#define CListWnd__RemoveLine                                       0x7406F0
#define CListWnd__SetColors                                        0x73A6F0
#define CListWnd__SetColumnJustification                           0x73B030
#define CListWnd__SetColumnWidth                                   0x73AE50
#define CListWnd__SetCurSel                                        0x73A660
#define CListWnd__SetItemColor                                     0x73EC90
#define CListWnd__SetItemData                                      0x73B260
#define CListWnd__SetItemText                                      0x73EA70
#define CListWnd__ShiftColumnSeparator                             0x73E8E0
#define CListWnd__Sort                                             0x740E80
#define CListWnd__ToggleSel                                        0x73B130

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x640430

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x6511B0
#define CMerchantWnd__RequestBuyItem                               0x654A70
#define CMerchantWnd__RequestSellItem                              0x673920
#define CMerchantWnd__SelectBuySellSlot                            0x6524D0

// CObfuscator
#define CObfuscator__doit                                          0x6DBEA0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7592B0
#define CSidlManager__CreateLabel                                  0x6997E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5AEEA0
#define CSidlScreenWnd__CalculateVSBRange                          0x749760
#define CSidlScreenWnd__ConvertToRes                               0x76AF40
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x749C30
#define CSidlScreenWnd__CSidlScreenWnd1                            0x74AD20
#define CSidlScreenWnd__CSidlScreenWnd2                            0x74ADD0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x74A4E0
#define CSidlScreenWnd__DrawSidlPiece                              0x7498F0
#define CSidlScreenWnd__EnableIniStorage                           0x7492E0
#define CSidlScreenWnd__GetSidlPiece                               0x749B00
#define CSidlScreenWnd__Init1                                      0x74AB80
#define CSidlScreenWnd__LoadIniInfo                                0x749CE0
#define CSidlScreenWnd__LoadIniListWnd                             0x749430
#define CSidlScreenWnd__LoadSidlScreen                             0x74A730
#define CSidlScreenWnd__StoreIniInfo                               0x748EE0
#define CSidlScreenWnd__StoreIniVis                                0x749270
#define CSidlScreenWnd__WndNotification                            0x74A900
#define CSidlScreenWnd__GetChildItem                               0x749340

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x562CD0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x76B930
#define CSliderWnd__SetValue                                       0x76BA30
#define CSliderWnd__SetNumTicks                                    0x76BFE0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x69E5C0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7685C0
#define CStmlWnd__CalculateHSBRange                                0x75FCE0
#define CStmlWnd__CalculateVSBRange                                0x75FC50
#define CStmlWnd__CanBreakAtCharacter                              0x75FE50
#define CStmlWnd__FastForwardToEndOfTag                            0x760B20
#define CStmlWnd__ForceParseNow                                    0x768AF0
#define CStmlWnd__GetNextTagPiece                                  0x760A40
#define CStmlWnd__GetSTMLText                                      0x5D96E0
#define CStmlWnd__GetThisChar                                      0x790000
#define CStmlWnd__GetVisiableText                                  0x761F70
#define CStmlWnd__InitializeWindowVariables                        0x764540
#define CStmlWnd__MakeStmlColorTag                                 0x75EB70
#define CStmlWnd__MakeWndNotificationTag                           0x75EC10
#define CStmlWnd__SetSTMLText                                      0x764660
#define CStmlWnd__StripFirstSTMLLines                              0x768270
#define CStmlWnd__UpdateHistoryString                              0x762800

// CTabWnd 
#define CTabWnd__Draw                                              0x76CED0
#define CTabWnd__DrawCurrentPage                                   0x76C7B0
#define CTabWnd__DrawTab                                           0x76C590
#define CTabWnd__GetCurrentPage                                    0x76CB70
#define CTabWnd__GetPageClientRect                                 0x76C240
#define CTabWnd__GetPageFromTabIndex                               0x76C4C0
#define CTabWnd__GetPageInnerRect                                  0x76C2A0
#define CTabWnd__GetTabInnerRect                                   0x76C440
#define CTabWnd__GetTabRect                                        0x76C330
#define CTabWnd__InsertPage                                        0x76D160
#define CTabWnd__SetPage                                           0x76CBB0
#define CTabWnd__SetPageRect                                       0x76CE00
#define CTabWnd__UpdatePage                                        0x76D0E0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417E60

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x74B150

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x76DD70

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x7395C0

// CXRect 
#define CXRect__CenterPoint                                        0x5B2560

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x416040
#define CXStr__CXStr1                                              0x770310
#define CXStr__CXStr3                                              0x794610
#define CXStr__dCXStr                                              0x4016D0
#define CXStr__operator_equal1                                     0x7947D0
#define CXStr__operator_plus_equal1                                0x795860

// CXWnd 
#define CXWnd__BringToTop                                          0x741460
#define CXWnd__Center                                              0x7462F0
#define CXWnd__ClrFocus                                            0x741290
#define CXWnd__DoAllDrawing                                        0x746C70
#define CXWnd__DrawChildren                                        0x746DC0
#define CXWnd__DrawColoredRect                                     0x741750
#define CXWnd__DrawTooltip                                         0x746220
#define CXWnd__DrawTooltipAtPoint                                  0x745570
#define CXWnd__GetBorderFrame                                      0x741C00
#define CXWnd__GetChildWndAt                                       0x7449F0
#define CXWnd__GetClientClipRect                                   0x741A10
#define CXWnd__GetScreenClipRect                                   0x745A30
#define CXWnd__GetScreenRect                                       0x741D20
#define CXWnd__GetTooltipRect                                      0x741860
#define CXWnd__GetWindowTextA                                      0x5A03E0
#define CXWnd__IsActive                                            0x74C280
#define CXWnd__IsDescendantOf                                      0x741AF0
#define CXWnd__IsReallyVisible                                     0x7449D0
#define CXWnd__IsType                                              0x770B80
#define CXWnd__Move                                                0x744120
#define CXWnd__Move1                                               0x745F80
#define CXWnd__ProcessTransition                                   0x741410
#define CXWnd__Refade                                              0x741390
#define CXWnd__Resize                                              0x741DF0
#define CXWnd__Right                                               0x745940
#define CXWnd__SetFocus                                            0x743530
#define CXWnd__SetKeyTooltip                                       0x741FE0
#define CXWnd__SetMouseOver                                        0x745CD0
#define CXWnd__StartFade                                           0x741490
#define CXWnd__GetChildItem                                        0x745C40

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x74D7E0
#define CXWndManager__DrawWindows                                  0x74D460
#define CXWndManager__GetKeyboardFlags                             0x74BEE0
#define CXWndManager__HandleKeyboardMsg                            0x74C550
#define CXWndManager__RemoveWnd                                    0x74C3A0

// CDBStr
#define CDBStr__GetString                                          0x46AA60

// EQ_Character 
#define EQ_Character__CastRay                                      0x6F9D90
#define EQ_Character__CastSpell                                    0x42FCA0
#define EQ_Character__Cur_HP                                       0x438B50
#define EQ_Character__GetAACastingTimeModifier                     0x4250D0
#define EQ_Character__GetCharInfo2                                 0x6F8BC0
#define EQ_Character__GetFocusCastingTimeModifier                  0x420800
#define EQ_Character__GetFocusRangeModifier                        0x4209E0
#define EQ_Character__Max_Endurance                                0x539510
#define EQ_Character__Max_HP                                       0x4338A0
#define EQ_Character__Max_Mana                                     0x539340
#define EQ_Character__doCombatAbility                              0x5381A0
#define EQ_Character__UseSkill                                     0x4474B0
#define EQ_Character__GetConLevel                                  0x533A50

// EQ_Item 
#define EQ_Item__CanDrop                                           0x519440
#define EQ_Item__GetItemLinkHash                                   0x6E8520
#define EQ_Item__IsStackable                                       0x6DC910

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x484860
#define EQ_LoadingS__Array                                         0x907EB8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x53D080
#define EQ_PC__GetAltAbilityIndex                                  0x6EE710
#define EQ_PC__GetCombatAbility                                    0x6EE7A0
#define EQ_PC__GetCombatAbilityTimer                               0x6EE850
#define EQ_PC__GetItemTimerValue                                   0x537FD0
#define EQ_PC__HasLoreItem                                         0x6F7720

// EQItemList 
#define EQItemList__EQItemList                                     0x4B2880
#define EQItemList__add_item                                       0x4B2810
#define EQItemList__delete_item                                    0x4B2C30
#define EQItemList__FreeItemList                                   0x4B2B60

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46A270

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x541A20
#define EQPlayer__dEQPlayer                                        0x546350
#define EQPlayer__DoAttack                                         0x556F10
#define EQPlayer__EQPlayer                                         0x54BB30
#define EQPlayer__SetNameSpriteState                               0x543E30
#define EQPlayer__SetNameSpriteTint                                0x541A90
#define EQPlayer__IsBodyType_j                                     0x6F9690
#define EQPlayer__IsTargetable                                     0x6F9830

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x54CDD0
#define EQPlayerManager__GetSpawnByName                            0x54D1F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x51E2D0
#define KeypressHandler__AttachKeyToEqCommand                      0x51E310
#define KeypressHandler__ClearCommandStateArray                    0x51E0E0
#define KeypressHandler__HandleKeyDown                             0x51CBB0
#define KeypressHandler__HandleKeyUp                               0x51CEC0
#define KeypressHandler__SaveKeymapping                            0x51E1B0

// MapViewMap 
#define MapViewMap__Clear                                          0x63BAD0
#define MapViewMap__SaveEx                                         0x63C4A0

#define PlayerPointManager__GetAltCurrency                         0x6E9D60

// StringTable 
#define StringTable__getString                                     0x6DC120