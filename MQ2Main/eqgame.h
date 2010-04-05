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
#define __ExpectedVersionDate                                     "Jul 14 2009"
#define __ExpectedVersionTime                                     "18:28:59"
#define __ActualVersionDate                                        0x7F1BC4
#define __ActualVersionTime                                        0x7F1BD0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x504A30
#define __MemChecker1                                              0x6BFFA0
#define __MemChecker2                                              0x563460
#define __MemChecker3                                              0x5633B0
#define __MemChecker4                                              0x67ABB0
#define __EncryptPad0                                              0x87C778
#define __EncryptPad1                                              0x886F48
#define __EncryptPad2                                              0x87F210
#define __EncryptPad3                                              0x87EE10
#define __EncryptPad4                                              0x8865D0
#define __AC1                                                      0x643380
#define __AC2                                                      0x4D14D5
#define __AC3                                                      0x4E4668
#define __AC4                                                      0x4E84F8
#define __AC5                                                      0x4F29D8
#define __AC6                                                      0x4F5CEB
#define __AC7                                                      0x4EEF34
#define __AC1_Data                                                 0x7DAED1

// Direct Input
#define DI8__Main                                                  0xADD88C
#define DI8__Keyboard                                              0xADD890
#define DI8__Mouse                                                 0xADD894
#define __AltTimerReady                                            0xA68196
#define __Attack                                                   0xAC7C82
#define __Autofire                                                 0xAC7C83
#define __BindList                                                 0x8776D0
#define __Clicks                                                   0xA66EA8
#define __CommandList                                              0x877F50
#define __CurrentMapLabel                                          0xB08AC8
#define __CurrentSocial                                            0x8736DC
#define __DoAbilityAvailable                                       0xA68130
#define __DoAbilityList                                            0xA9D748
#define __do_loot                                                  0x4AAEC0
#define __DrawHandler                                              0xB17F24
#define __GroupCount                                               0xA61162
#define __Guilds                                                   0xA66288
#define __gWorld                                                   0xA62C20
#define __HotkeyPage                                               0xAC4B34
#define __HWnd                                                     0xADD5CC
#define __InChatMode                                               0xA66DE0
#define __LastTell                                                 0xA68AA0
#define __LMouseHeldTime                                           0xA66EC8
#define __Mouse                                                    0xADD898
#define __MouseLook                                                0xA66E76
#define __MouseEventTime                                           0xAC7D94
#define __NetStatusToggle                                          0xA66E79
#define __PCNames                                                  0xA684E4
#define __RangeAttackReady                                         0xA68194
#define __RMouseHeldTime                                           0xA66EC4
#define __RunWalkState                                             0xA66DE4
#define __ScreenMode                                               0x9B0A30
#define __ScreenX                                                  0xA66D98
#define __ScreenY                                                  0xA66D9C
#define __ScreenXMax                                               0xA66DA0
#define __ScreenYMax                                               0xA66DA4
#define __ServerHost                                               0xA610A4
#define __ServerName                                               0xA9D708
#define __ShiftKeyDown                                             0xA67448
#define __ShowNames                                                0xA683C0
#define __Socials                                                  0xA9D808


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA62CE0
#define instEQZoneInfo                                             0xA67014
#define instKeypressHandler                                        0xAC7D78
#define pinstActiveBanker                                          0xA62CB8
#define pinstActiveCorpse                                          0xA62CBC
#define pinstActiveGMaster                                         0xA62CC0
#define pinstActiveMerchant                                        0xA62CB4
#define pinstAltAdvManager                                         0x9B1890
#define pinstAuraMgr                                               0x89A2F4
#define pinstBandageTarget                                         0xA62CA0
#define pinstCamActor                                              0x9B1380
#define pinstCDBStr                                                0x9B0A20
#define pinstCDisplay                                              0xA62CC8
#define pinstCEverQuest                                            0xADDA10
#define pinstCharData                                              0xA62C84
#define pinstCharSpawn                                             0xA62CAC
#define pinstControlledMissile                                     0xA62C80
#define pinstControlledPlayer                                      0xA62CAC
#define pinstCSidlManager                                          0xB176A8
#define pinstCXWndManager                                          0xB176A0
#define instDynamicZone                                            0xA66C68
#define pinstDZMember                                              0xA66D78
#define pinstDZTimerInfo                                           0xA66D7C
#define pinstEQItemList                                            0xA62C68
#define instEQMisc                                                 0x9B09D8
#define pinstEQSoundManager                                        0x9B18B4
#define instExpeditionLeader                                       0xA66CB2
#define instExpeditionName                                         0xA66CF2
#define pinstGroup                                                 0xA6115E
#define pinstImeManager                                            0xB176AC
#define pinstLocalPlayer                                           0xA62C98
#define pinstMercenaryData                                         0xAC80F0
#define pinstModelPlayer                                           0xA62CC4
#define pinstPCData                                                0xA62C84
#define pinstSkillMgr                                              0xADA690
#define pinstSpawnManager                                          0xADA4EC
#define pinstSpellManager                                          0xADA694
#define pinstSpellSets                                             0xAC4B38
#define pinstStringTable                                           0xA62C3C
#define pinstSwitchManager                                         0xA60DA4
#define pinstTarget                                                0xA62CB0
#define pinstTargetObject                                          0xA62C88
#define pinstTargetSwitch                                          0xA62C8C
#define pinstTaskMember                                            0x9B09B8
#define pinstTrackTarget                                           0xA62CA4
#define pinstTradeTarget                                           0xA62C94
#define instTributeActive                                          0x9B09FD
#define pinstViewActor                                             0x9B137C
#define pinstWorldData                                             0xA62C64


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x897BA0
#define pinstCAudioTriggersWindow                                  0x897B6C
#define pinstCCharacterSelect                                      0x9B128C
#define pinstCFacePick                                             0x9B1240
#define pinstCNoteWnd                                              0x9B1244
#define pinstCBookWnd                                              0x9B1248
#define pinstCPetInfoWnd                                           0x9B124C
#define pinstCTrainWnd                                             0x9B1250
#define pinstCSkillsWnd                                            0x9B1254
#define pinstCSkillsSelectWnd                                      0x9B1258
#define pinstCCombatSkillSelectWnd                                 0x9B125C
#define pinstCFriendsWnd                                           0x9B1260
#define pinstCAuraWnd                                              0x9B1264
#define pinstCRespawnWnd                                           0x9B1268
#define pinstCBandolierWnd                                         0x9B126C
#define pinstCPotionBeltWnd                                        0x9B1270
#define pinstCAAWnd                                                0x9B1274
#define pinstCGroupSearchFiltersWnd                                0x9B1278
#define pinstCLoadskinWnd                                          0x9B127C
#define pinstCAlarmWnd                                             0x9B1280
#define pinstCMusicPlayerWnd                                       0x9B1284
#define pinstCMailWnd                                              0x9B1290
#define pinstCMailCompositionWnd                                   0x9B1294
#define pinstCMailAddressBookWnd                                   0x9B1298
#define pinstCRaidWnd                                              0x9B12A0
#define pinstCRaidOptionsWnd                                       0x9B12A4
#define pinstCBreathWnd                                            0x9B12A8
#define pinstCMapViewWnd                                           0x9B12AC
#define pinstCMapToolbarWnd                                        0x9B12B0
#define pinstCEditLabelWnd                                         0x9B12B4
#define pinstCTargetWnd                                            0x9B12B8
#define pinstCColorPickerWnd                                       0x9B12BC
#define pinstCPlayerWnd                                            0x9B12C0
#define pinstCOptionsWnd                                           0x9B12C4
#define pinstCBuffWindowNORMAL                                     0x9B12C8
#define pinstCBuffWindowSHORT                                      0x9B12CC
#define pinstCharacterCreation                                     0x9B12D0
#define pinstCCursorAttachment                                     0x9B12D4
#define pinstCCastingWnd                                           0x9B12D8
#define pinstCCastSpellWnd                                         0x9B12DC
#define pinstCSpellBookWnd                                         0x9B12E0
#define pinstCInventoryWnd                                         0x9B12E4
#define pinstCBankWnd                                              0x9B12E8
#define pinstCQuantityWnd                                          0x9B12EC
#define pinstCLootWnd                                              0x9B12F0
#define pinstCActionsWnd                                           0x9B12F4
#define pinstCCombatAbilityWnd                                     0x9B12F8
#define pinstCMerchantWnd                                          0x9B12FC
#define pinstCTradeWnd                                             0x9B1300
#define pinstCSelectorWnd                                          0x9B1304
#define pinstCBazaarWnd                                            0x9B1308
#define pinstCBazaarSearchWnd                                      0x9B130C
#define pinstCGiveWnd                                              0x9B1310
#define pinstCTrackingWnd                                          0x9B1314
#define pinstCInspectWnd                                           0x9B1318
#define pinstCSocialEditWnd                                        0x9B131C
#define pinstCFeedbackWnd                                          0x9B1320
#define pinstCBugReportWnd                                         0x9B1324
#define pinstCVideoModesWnd                                        0x9B1328
#define pinstCTextEntryWnd                                         0x9B1330
#define pinstCFileSelectionWnd                                     0x9B1334
#define pinstCCompassWnd                                           0x9B1338
#define pinstCPlayerNotesWnd                                       0x9B133C
#define pinstCGemsGameWnd                                          0x9B1340
#define pinstCTimeLeftWnd                                          0x9B1344
#define pinstCPetitionQWnd                                         0x9B134C
#define pinstCSoulmarkWnd                                          0x9B1350
#define pinstCStoryWnd                                             0x9B1354
#define pinstCJournalTextWnd                                       0x9B1358
#define pinstCJournalCatWnd                                        0x9B135C
#define pinstCBodyTintWnd                                          0x9B1360
#define pinstCServerListWnd                                        0x9B1364
#define pinstCAvaZoneWnd                                           0x9B1368
#define pinstCBlockedBuffWnd                                       0x9B136C
#define pinstCBlockedPetBuffWnd                                    0x9B1370
#define pinstCInvSlotMgr                                           0x9B1374
#define pinstCContainerMgr                                         0x9B1378
#define pinstCAdventureLeaderboardWnd                              0xB05FF8
#define pinstCAdventureRequestWnd                                  0xB06014
#define pinstCAltStorageWnd                                        0xB06074
#define pinstCAdventureStatsWnd                                    0xB06030
#define pinstCBarterMerchantWnd                                    0xB06240
#define pinstCBarterSearchWnd                                      0xB0625C
#define pinstCBarterWnd                                            0xB06278
#define pinstCChatManager                                          0xB0651C
#define pinstCDynamicZoneWnd                                       0xB06614
#define pinstCEQMainWnd                                            0xB06688
#define pinstCFellowshipWnd                                        0xB066EC
#define pinstCFindLocationWnd                                      0xB06720
#define pinstCGroupSearchWnd                                       0xB067D0
#define pinstCGroupWnd                                             0xB067EC
#define pinstCGuildBankWnd                                         0xB06808
#define pinstCGuildMgmtWnd                                         0xB08840
#define pinstCGuildTributeMasterWnd                                0xB08860
#define pinstCHotButtonWnd                                         0xB0887C
#define pinstCHotButtonWnd1                                        0xB0887C
#define pinstCHotButtonWnd2                                        0xB08880
#define pinstCHotButtonWnd3                                        0xB08884
#define pinstCHotButtonWnd4                                        0xB08888
#define pinstCItemDisplayManager                                   0xB08934
#define pinstCItemExpTransferWnd                                   0xB08954
#define pinstCLeadershipWnd                                        0xB089F0
#define pinstCLFGuildWnd                                           0xB08A0C
#define pinstCMIZoneSelectWnd                                      0xB08B7C
#define pinstCAdventureMerchantWnd                                 0xB08C74
#define pinstCConfirmationDialog                                   0xB08C90
#define pinstCPopupWndManager                                      0xB08C90
#define pinstCProgressionSelectionWnd                              0xB08CC4
#define pinstCPvPLeaderboardWnd                                    0xB08CE0
#define pinstCPvPStatsWnd                                          0xB08CFC
#define pinstCSystemInfoDialogBox                                  0xB08DB0
#define pinstCTargetOfTargetWnd                                    0xB096BC
#define pinstCTaskSelectWnd                                        0xB096F0
#define pinstCTaskTemplateSelectWnd                                0xB0970C
#define pinstCTaskWnd                                              0xB09728
#define pinstCTipWndOFDAY                                          0xB097A4
#define pinstCTipWndCONTEXT                                        0xB097A8
#define pinstCTitleWnd                                             0xB097C4
#define pinstCTradeskillWnd                                        0xB09808
#define pinstCTributeBenefitWnd                                    0xB09854
#define pinstCTributeMasterWnd                                     0xB09870
#define pinstCContextMenuManager                                   0xB17704
#define pinstCVoiceMacroWnd                                        0xADA884
#define pinstCHtmlWnd                                              0xADA8D0


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4BE2C0
#define __ConvertItemTags                                          0x4B0350
#define __ExecuteCmd                                               0x49E960
#define __get_melee_range                                          0x4A3FE0
#define __GetGaugeValueFromEQ                                      0x6425C0
#define __GetLabelFromEQ                                           0x643320
#define __LoadFrontEnd                                             0x562330
#define __NewUIINI                                                 0x642150
#define __ProcessGameEvents                                        0x4EF320
#define CrashDetected                                              0x562130
#define DrawNetStatus                                              0x50D0C0
#define Util__FastTime                                             0x6C06B0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x477260
#define AltAdvManager__IsAbilityReady                              0x4772A0
#define AltAdvManager__GetAltAbility                               0x477570

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x57A1D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5839F0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6EE5C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5996E0
#define CChatManager__InitContextMenu                              0x599E80

// CChatService
#define CChatService__GetNumberOfFriends                           0x6AEC50
#define CChatService__GetFriendName                                0x6AEC60

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x59E060
#define CChatWindow__Clear                                         0x59E9D0
#define CChatWindow__WndNotification                               0x59EAB0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6D9200
#define CComboWnd__Draw                                            0x6D93B0
#define CComboWnd__GetCurChoice                                    0x6D91A0
#define CComboWnd__GetListRect                                     0x6D9670
#define CComboWnd__GetTextRect                                     0x6D9230
#define CComboWnd__InsertChoice                                    0x6D96E0
#define CComboWnd__SetColors                                       0x6D9130
#define CComboWnd__SetChoice                                       0x6D9160

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A5BD0
#define CContainerWnd__vftable                                     0x7F87C8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x465C20
#define CDisplay__GetClickedActor                                  0x463350
#define CDisplay__GetUserDefinedColor                              0x462470
#define CDisplay__GetWorldFilePath                                 0x461970
#define CDisplay__is3dON                                           0x460AE0
#define CDisplay__ReloadUI                                         0x474430
#define CDisplay__WriteTextHD2                                     0x4663A0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5740B0
#define CEditBaseWnd__SetSel                                       0x6F99B0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6E1C90
#define CEditWnd__GetCharIndexPt                                   0x6E2AD0
#define CEditWnd__GetDisplayString                                 0x6E1E20
#define CEditWnd__GetHorzOffset                                    0x6E20B0
#define CEditWnd__GetLineForPrintableChar                          0x6E2580
#define CEditWnd__GetSelStartPt                                    0x6E2D10
#define CEditWnd__GetSTMLSafeText                                  0x6E2240
#define CEditWnd__PointFromPrintableChar                           0x6E2690
#define CEditWnd__SelectableCharFromPoint                          0x6E2810
#define CEditWnd__SetEditable                                      0x6E2210

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D1BB0
#define CEverQuest__DropHeldItemOnGround                           0x4D5C20
#define CEverQuest__dsp_chat                                       0x4D70D0
#define CEverQuest__DoTellWindow                                   0x4D5DA0
#define CEverQuest__EnterZone                                      0x4E8490
#define CEverQuest__GetBodyTypeDesc                                0x4CEE30
#define CEverQuest__GetClassDesc                                   0x4CE670
#define CEverQuest__GetClassThreeLetterCode                        0x4CEC70
#define CEverQuest__GetDeityDesc                                   0x4CF4A0
#define CEverQuest__GetLangDesc                                    0x4CF1C0
#define CEverQuest__GetRaceDesc                                    0x4CF470
#define CEverQuest__InterpretCmd                                   0x4D7B60
#define CEverQuest__LeftClickedOnPlayer                            0x4E9DB0
#define CEverQuest__LMouseUp                                       0x4ED690
#define CEverQuest__RightClickedOnPlayer                           0x4EDF30
#define CEverQuest__RMouseUp                                       0x4EEEF0
#define CEverQuest__SetGameState                                   0x4D2040
#define CEverQuest__Emote                                          0x4D72C0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5B25D0
#define CGaugeWnd__CalcLinesFillRect                               0x5B2630
#define CGaugeWnd__Draw                                            0x5B2A40

// CGuild
#define CGuild__FindMemberByName                                   0x4180B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5CAB60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5D41D0
#define CInvSlotMgr__MoveItem                                      0x5D4370

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5D3A60
#define CInvSlot__SliderComplete                                   0x5D2BB0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5D5300

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x640320
#define CItemDisplayWnd__UpdateStrings                             0x5D6000

// CLabel 
#define CLabel__Draw                                               0x5E8950

// CListWnd 
#define CListWnd__AddColumn                                        0x6D3A30
#define CListWnd__AddColumn1                                       0x6D34C0
#define CListWnd__AddLine                                          0x6D3000
#define CListWnd__AddString                                        0x6D31F0
#define CListWnd__CalculateFirstVisibleLine                        0x6D02C0
#define CListWnd__CalculateVSBRange                                0x6D2060
#define CListWnd__ClearAllSel                                      0x6CF9F0
#define CListWnd__CloseAndUpdateEditWindow                         0x6D08E5
#define CListWnd__Compare                                          0x6D0C60
#define CListWnd__Draw                                             0x6D1D50
#define CListWnd__DrawColumnSeparators                             0x6D1BC0
#define CListWnd__DrawHeader                                       0x6CFBC0
#define CListWnd__DrawItem                                         0x6D14F0
#define CListWnd__DrawLine                                         0x6D1860
#define CListWnd__DrawSeparator                                    0x6D1C60
#define CListWnd__EnsureVisible                                    0x6D0310
#define CListWnd__ExtendSel                                        0x6D1410
#define CListWnd__GetColumnMinWidth                                0x6CF780
#define CListWnd__GetColumnWidth                                   0x6CF6C0
#define CListWnd__GetCurSel                                        0x6CF0D0
#define CListWnd__GetHeaderRect                                    0x6CF240
#define CListWnd__GetItemAtPoint                                   0x6D05F0
#define CListWnd__GetItemAtPoint1                                  0x6D0660
#define CListWnd__GetItemData                                      0x6CF470
#define CListWnd__GetItemHeight                                    0x6D0050
#define CListWnd__GetItemIcon                                      0x6CF600
#define CListWnd__GetItemRect                                      0x6D03E0
#define CListWnd__GetItemText                                      0x6CF4B0
#define CListWnd__GetSelList                                       0x6D33A0
#define CListWnd__GetSeparatorRect                                 0x6D0BA0
#define CListWnd__RemoveLine                                       0x6D39E0
#define CListWnd__SetColors                                        0x6CF1A0
#define CListWnd__SetColumnJustification                           0x6CF860
#define CListWnd__SetColumnWidth                                   0x6CF740
#define CListWnd__SetCurSel                                        0x6CF110
#define CListWnd__SetItemColor                                     0x6D2C70
#define CListWnd__SetItemData                                      0x6CFA90
#define CListWnd__SetItemText                                      0x6D2BF0
#define CListWnd__ShiftColumnSeparator                             0x6D1380
#define CListWnd__Sort                                             0x6D3A70
#define CListWnd__ToggleSel                                        0x6CF960

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5FDB90

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x6091A0
#define CMerchantWnd__RequestBuyItem                               0x60AA00
#define CMerchantWnd__RequestSellItem                              0x60AE20
#define CMerchantWnd__SelectBuySellSlot                            0x609ED0

// CObfuscator
#define CObfuscator__doit                                          0x689C30

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6E9FD0
#define CSidlManager__CreateLabel                                  0x639330

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5761F0
#define CSidlScreenWnd__CalculateVSBRange                          0x6EFB90
#define CSidlScreenWnd__ConvertToRes                               0x6F9890
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6DB1C0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6DC290
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6DC340
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6DBA60
#define CSidlScreenWnd__DrawSidlPiece                              0x6DAE90
#define CSidlScreenWnd__EnableIniStorage                           0x6DAAE0
#define CSidlScreenWnd__GetSidlPiece                               0x6DB090
#define CSidlScreenWnd__Init1                                      0x6DC100
#define CSidlScreenWnd__LoadIniInfo                                0x6DB270
#define CSidlScreenWnd__LoadIniListWnd                             0x6DAC30
#define CSidlScreenWnd__LoadSidlScreen                             0x6DBCB0
#define CSidlScreenWnd__StoreIniInfo                               0x6DA6F0
#define CSidlScreenWnd__WndNotification                            0x6DBE80
#define CSidlScreenWnd__GetChildItem                               0x6DAB40

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x5301B0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6FAD40
#define CSliderWnd__SetValue                                       0x6FAE40
#define CSliderWnd__SetNumTicks                                    0x6FB3B0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x63E0B0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6F7B10
#define CStmlWnd__CalculateVSBRange                                0x6EFB90
#define CStmlWnd__CanBreakAtCharacter                              0x6EFCD0
#define CStmlWnd__FastForwardToEndOfTag                            0x6F0840
#define CStmlWnd__ForceParseNow                                    0x6F7F90
#define CStmlWnd__GetNextTagPiece                                  0x6F0760
#define CStmlWnd__GetSTMLText                                      0x59E000
#define CStmlWnd__GetThisChar                                      0x71D5A0
#define CStmlWnd__GetVisiableText                                  0x6F1A60
#define CStmlWnd__InitializeWindowVariables                        0x6F3C30
#define CStmlWnd__MakeStmlColorTag                                 0x6EF230
#define CStmlWnd__MakeWndNotificationTag                           0x6EF2D0
#define CStmlWnd__SetSTMLText                                      0x6F3D60
#define CStmlWnd__StripFirstSTMLLines                              0x6F78A0
#define CStmlWnd__UpdateHistoryString                              0x6F22D0

// CTabWnd 
#define CTabWnd__Draw                                              0x6FC1C0
#define CTabWnd__DrawCurrentPage                                   0x6FBB60
#define CTabWnd__DrawTab                                           0x6FB940
#define CTabWnd__GetCurrentPage                                    0x6FBE60
#define CTabWnd__GetPageClientRect                                 0x6FB610
#define CTabWnd__GetPageFromTabIndex                               0x6FB870
#define CTabWnd__GetPageInnerRect                                  0x6FB670
#define CTabWnd__GetTabInnerRect                                   0x6FB7F0
#define CTabWnd__GetTabRect                                        0x6FB700
#define CTabWnd__InsertPage                                        0x6FC430
#define CTabWnd__SetPage                                           0x6FBEA0
#define CTabWnd__SetPageRect                                       0x6FC0F0
#define CTabWnd__UpdatePage                                        0x6FC3B0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x414670

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6DC6A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x700780

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6CEDC0

// CXRect 
#define CXRect__CenterPoint                                        0x579860

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412AF0
#define CXStr__CXStr1                                              0x403580
#define CXStr__CXStr3                                              0x6C1D30
#define CXStr__dCXStr                                              0x406650
#define CXStr__operator_equal1                                     0x6C1EF0
#define CXStr__operator_plus_equal1                                0x6C2DF0

// CXWnd 
#define CXWnd__BringToTop                                          0x6D4150
#define CXWnd__Center                                              0x6D7BE0
#define CXWnd__ClrFocus                                            0x6D3E70
#define CXWnd__DoAllDrawing                                        0x6D89A0
#define CXWnd__DrawChildren                                        0x6D8AD0
#define CXWnd__DrawColoredRect                                     0x6D43D0
#define CXWnd__DrawTooltip                                         0x6D87C0
#define CXWnd__DrawTooltipAtPoint                                  0x6D79A0
#define CXWnd__GetBorderFrame                                      0x6D48B0
#define CXWnd__GetChildWndAt                                       0x6D74E0
#define CXWnd__GetClientClipRect                                   0x6D47C0
#define CXWnd__GetScreenClipRect                                   0x6D7E00
#define CXWnd__GetScreenRect                                       0x6D4A50
#define CXWnd__GetTooltipRect                                      0x6D4620
#define CXWnd__GetWindowTextA                                      0x56CE00
#define CXWnd__IsActive                                            0x6DD7B0
#define CXWnd__IsDescendantOf                                      0x6D4840
#define CXWnd__IsReallyVisible                                     0x6D74C0
#define CXWnd__IsType                                              0x6FD640
#define CXWnd__Move                                                0x6D70A0
#define CXWnd__Move1                                               0x6D8620
#define CXWnd__ProcessTransition                                   0x6D4110
#define CXWnd__Refade                                              0x6D3F20
#define CXWnd__Resize                                              0x6D4B20
#define CXWnd__Right                                               0x6D7D40
#define CXWnd__SetFocus                                            0x6D62D0
#define CXWnd__SetKeyTooltip                                       0x6D4D30
#define CXWnd__SetMouseOver                                        0x6D4D00
#define CXWnd__StartFade                                           0x6D4190
#define CXWnd__GetChildItem                                        0x6D7F70

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6DEBE0
#define CXWndManager__DrawWindows                                  0x6DE7F0
#define CXWndManager__GetKeyboardFlags                             0x6DD460
#define CXWndManager__HandleKeyboardMsg                            0x6DD9B0
#define CXWndManager__RemoveWnd                                    0x6DD8D0

// CDBStr
#define CDBStr__GetString                                          0x45F430

// EQ_Character 
#define EQ_Character__CastRay                                      0x729670
#define EQ_Character__CastSpell                                    0x42AAA0
#define EQ_Character__Cur_HP                                       0x4341A0
#define EQ_Character__GetAACastingTimeModifier                     0x420A10
#define EQ_Character__GetCharInfo2                                 0x69FDA0
#define EQ_Character__GetFocusCastingTimeModifier                  0x41C3D0
#define EQ_Character__GetFocusRangeModifier                        0x41C510
#define EQ_Character__Max_Endurance                                0x513210
#define EQ_Character__Max_HP                                       0x42F0A0
#define EQ_Character__Max_Mana                                     0x513040
#define EQ_Character__doCombatAbility                              0x511F50
#define EQ_Character__UseSkill                                     0x43D930
#define EQ_Character__GetConLevel                                  0x50E4F0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4FC370
#define EQ_Item__GetItemLinkHash                                   0x6936D0
#define EQ_Item__IsStackable                                       0x68A510

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x478440
#define EQ_LoadingS__Array                                         0x875BA0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x516080
#define EQ_PC__GetAltAbilityIndex                                  0x698190
#define EQ_PC__GetCombatAbility                                    0x698220
#define EQ_PC__GetCombatAbilityTimer                               0x6982D0
#define EQ_PC__GetItemTimerValue                                   0x510E80
#define EQ_PC__HasLoreItem                                         0x514550

// EQItemList 
#define EQItemList__dEQItemList                                    0x4A2540
#define EQItemList__EQItemList                                     0x4A2490

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45EDC0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x51A8D0
#define EQPlayer__dEQPlayer                                        0x51E980
#define EQPlayer__DoAttack                                         0x52C360
#define EQPlayer__EQPlayer                                         0x5226C0
#define EQPlayer__SetNameSpriteState                               0x51C8F0
#define EQPlayer__SetNameSpriteTint                                0x51A940
#define EQPlayer__IsBodyType_j                                     0x728F80
#define EQPlayer__IsTargetable                                     0x729110

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5237D0
#define EQPlayerManager__GetSpawnByName                            0x523AB0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4FE040
#define KeypressHandler__AttachKeyToEqCommand                      0x4FE080
#define KeypressHandler__ClearCommandStateArray                    0x4FDE50
#define KeypressHandler__HandleKeyDown                             0x4FC9D0
#define KeypressHandler__HandleKeyUp                               0x4FCCE0
#define KeypressHandler__SaveKeymapping                            0x4FDF20

// MapViewMap 
#define MapViewMap__Clear                                          0x5F9260
#define MapViewMap__SaveEx                                         0x5F9C30

#define OtherCharData__GetAltCurrency                              0x6B73F0

// StringTable 
#define StringTable__getString                                     0x689EB0
