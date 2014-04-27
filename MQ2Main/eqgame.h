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
#define __ExpectedVersionDate                                     "May 11 2012"
#define __ExpectedVersionTime                                     "16:15:10"
#define __ActualVersionDate                                        0x90B784
#define __ActualVersionTime                                        0x90B790

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x5359E0
#define __MemChecker1                                              0x8152E0
#define __MemChecker2                                              0x5B8790
#define __MemChecker3                                              0x5B86E0
#define __MemChecker4                                              0x837850
#define __EncryptPad0                                              0x9E34F0
#define __EncryptPad1                                              0xA5BEA0
#define __EncryptPad2                                              0x9FB9A0
#define __EncryptPad3                                              0x9FB5A0
#define __EncryptPad4                                              0xA5D948
#define __AC1                                                      0x6F4750
#define __AC2                                                      0x4F1745
#define __AC3                                                      0x5038D8
#define __AC4                                                      0x509264
#define __AC5                                                      0x515678
#define __AC6                                                      0x518FAB
#define __AC7                                                      0x510FFB
#define __AC1_Data                                                 0x8F0E0D
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
#define __do_loot                                                  0x4C53A0
#define __DrawHandler                                              0x1369D6C
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
#define pinstCSidlManager                                          0x136A2AC
#define pinstCXWndManager                                          0x136A2A4
#define instDynamicZone                                            0xC62E40
#define pinstDZMember                                              0xC62F50
#define pinstDZTimerInfo                                           0xC62F54
#define pinstEQItemList                                            0xC567F0
#define instEQMisc                                                 0xBA6B08
#define pinstEQSoundManager                                        0xBA7B80
#define instExpeditionLeader                                       0xC62E8A
#define instExpeditionName                                         0xC62ECA
#define pinstGroup                                                 0xC5773E
#define pinstImeManager                                            0x136A2B0
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
#define pinstCContextMenuManager                                   0x136A308
#define pinstCVoiceMacroWnd                                        0xCDE1E0
#define pinstCHtmlWnd                                              0xCDE258


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D9AA0
#define __ConvertItemTags                                          0x4CAAC0
#define __ExecuteCmd                                               0x4B65E0
#define __EQGetTime                                                0x816700
#define __get_melee_range                                          0x4BC880
#define __GetGaugeValueFromEQ                                      0x6F3500
#define __GetLabelFromEQ                                           0x6F46F0
#define __GetXTargetType                                           0x7720F0
#define __LoadFrontEnd                                             0x5B7700
#define __NewUIINI                                                 0x6F30B0
#define __ProcessGameEvents                                        0x5117E0
#define CrashDetected                                              0x5B7500
#define DrawNetStatus                                              0x5434B0
#define Util__FastTime                                             0x815BB0
#define Expansion_HoT                                              0xC67E0C
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x489AB0
#define AltAdvManager__IsAbilityReady                              0x489B60
#define AltAdvManager__GetAltAbility                               0x489D80

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x43CD30

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5DE340

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5E8030

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x523C70

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x601660
#define CChatManager__InitContextMenu                              0x601F90

// CChatService
#define CChatService__GetNumberOfFriends                           0x768C00
#define CChatService__GetFriendName                                0x768C10

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x606D60
#define CChatWindow__Clear                                         0x606910
#define CChatWindow__WndNotification                               0x607170

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7C5040
#define CComboWnd__Draw                                            0x7C5200
#define CComboWnd__GetCurChoice                                    0x7C4E60
#define CComboWnd__GetListRect                                     0x7C54E0
#define CComboWnd__GetTextRect                                     0x7C5070
#define CComboWnd__InsertChoice                                    0x7C5550
#define CComboWnd__SetColors                                       0x7C4DF0
#define CComboWnd__SetChoice                                       0x7C4E20

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x6105A0
#define CContainerWnd__vftable                                     0x9141C8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x47D370
#define CDisplay__GetClickedActor                                  0x475CE0
#define CDisplay__GetUserDefinedColor                              0x474610
#define CDisplay__GetWorldFilePath                                 0x473B30
#define CDisplay__is3dON                                           0x472C30
#define CDisplay__ReloadUI                                         0x486990
#define CDisplay__WriteTextHD2                                     0x478E70

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5D5F70
#define CEditBaseWnd__SetSel                                       0x7E5990

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7CE6E0
#define CEditWnd__GetCharIndexPt                                   0x7CF6B0
#define CEditWnd__GetDisplayString                                 0x7CE880
#define CEditWnd__GetHorzOffset                                    0x7CEB10
#define CEditWnd__GetLineForPrintableChar                          0x7CF160
#define CEditWnd__GetSelStartPt                                    0x7CF8F0
#define CEditWnd__GetSTMLSafeText                                  0x7CECB0
#define CEditWnd__PointFromPrintableChar                           0x7CF270
#define CEditWnd__SelectableCharFromPoint                          0x7CF3F0
#define CEditWnd__SetEditable                                      0x7CEC80

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4F1E90
#define CEverQuest__DropHeldItemOnGround                           0x4FED90
#define CEverQuest__dsp_chat                                       0x4F8120
#define CEverQuest__DoTellWindow                                   0x4F68B0
#define CEverQuest__EnterZone                                      0x5091F0
#define CEverQuest__GetBodyTypeDesc                                0x4EEC90
#define CEverQuest__GetClassDesc                                   0x4EE4D0
#define CEverQuest__GetClassThreeLetterCode                        0x4EEAD0
#define CEverQuest__GetDeityDesc                                   0x4EF340
#define CEverQuest__GetLangDesc                                    0x4EF020
#define CEverQuest__GetRaceDesc                                    0x4EF310
#define CEverQuest__InterpretCmd                                   0x4F8C30
#define CEverQuest__LeftClickedOnPlayer                            0x50B290
#define CEverQuest__LMouseUp                                       0x50EE80
#define CEverQuest__RightClickedOnPlayer                           0x50FFE0
#define CEverQuest__RMouseUp                                       0x510FC0
#define CEverQuest__SetGameState                                   0x4F2320
#define CEverQuest__Emote                                          0x4F8340

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x61E620
#define CGaugeWnd__CalcLinesFillRect                               0x61E680
#define CGaugeWnd__Draw                                            0x61EAD0

// CGuild
#define CGuild__FindMemberByName                                   0x41CD70

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x638B20

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x642F10
#define CInvSlotMgr__MoveItem                                      0x643BC0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x642590
#define CInvSlot__SliderComplete                                   0x640880
#define CInvSlot__GetItemBase                                      0x63FF10

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x644910

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6F0AB0
#define CItemDisplayWnd__UpdateStrings                             0x645950

// CLabel 
#define CLabel__Draw                                               0x65A0B0

// CListWnd 
#define CListWnd__AddColumn                                        0x7BA9B0
#define CListWnd__AddColumn1                                       0x7B9FE0
#define CListWnd__AddLine                                          0x7B9B90
#define CListWnd__AddString                                        0x7B9D30
#define CListWnd__CalculateFirstVisibleLine                        0x7B5E00
#define CListWnd__CalculateVSBRange                                0x7B8200
#define CListWnd__ClearAllSel                                      0x7B5350
#define CListWnd__CloseAndUpdateEditWindow                         0x7B9200
#define CListWnd__Compare                                          0x7B68A0
#define CListWnd__Draw                                             0x7B7E40
#define CListWnd__DrawColumnSeparators                             0x7B7CD0
#define CListWnd__DrawHeader                                       0x7B55E0
#define CListWnd__DrawItem                                         0x7B72A0
#define CListWnd__DrawLine                                         0x7B7990
#define CListWnd__DrawSeparator                                    0x7B7D70
#define CListWnd__EnsureVisible                                    0x7B5F60
#define CListWnd__ExtendSel                                        0x7B71C0
#define CListWnd__GetColumnMinWidth                                0x7B5020
#define CListWnd__GetColumnWidth                                   0x7B4F60
#define CListWnd__GetCurSel                                        0x7B4720
#define CListWnd__GetHeaderRect                                    0x7B4880
#define CListWnd__GetItemAtPoint                                   0x7B6230
#define CListWnd__GetItemAtPoint1                                  0x7B62A0
#define CListWnd__GetItemData                                      0x7B4B60
#define CListWnd__GetItemHeight                                    0x7B5A70
#define CListWnd__GetItemIcon                                      0x7B4D40
#define CListWnd__GetItemRect                                      0x7B6030
#define CListWnd__GetItemText                                      0x7B4BF0
#define CListWnd__GetSelList                                       0x7B9EC0
#define CListWnd__GetSeparatorRect                                 0x7B67F0
#define CListWnd__RemoveLine                                       0x7BA960
#define CListWnd__SetColors                                        0x7B47F0
#define CListWnd__SetColumnJustification                           0x7B51C0
#define CListWnd__SetColumnWidth                                   0x7B4FE0
#define CListWnd__SetCurSel                                        0x7B4760
#define CListWnd__SetItemColor                                     0x7B8EB0
#define CListWnd__SetItemData                                      0x7B53F0
#define CListWnd__SetItemText                                      0x7B8CE0
#define CListWnd__ShiftColumnSeparator                             0x7B8B50
#define CListWnd__Sort                                             0x7BB110
#define CListWnd__ToggleSel                                        0x7B52C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x672B00

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x68E040
#define CMerchantWnd__RequestBuyItem                               0x694270
#define CMerchantWnd__RequestSellItem                              0x6B58E0
#define CMerchantWnd__SelectBuySellSlot                            0x68E2F0

// CObfuscator
#define CObfuscator__doit                                          0x73C250

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7D71D0
#define CSidlManager__CreateLabel                                  0x6E9170

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5DA000
#define CSidlScreenWnd__CalculateVSBRange                          0x5D9F20
#define CSidlScreenWnd__ConvertToRes                               0x7E5870
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7C7690
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7C88D0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x7C8980
#define CSidlScreenWnd__dCSidlScreenWnd                            0x7C8060
#define CSidlScreenWnd__DrawSidlPiece                              0x7C7130
#define CSidlScreenWnd__EnableIniStorage                           0x7C68F0
#define CSidlScreenWnd__GetSidlPiece                               0x7C7350
#define CSidlScreenWnd__Init1                                      0x7C8720
#define CSidlScreenWnd__LoadIniInfo                                0x7C7750
#define CSidlScreenWnd__LoadIniListWnd                             0x7C6A40
#define CSidlScreenWnd__LoadSidlScreen                             0x7C82C0
#define CSidlScreenWnd__StoreIniInfo                               0x7C64C0
#define CSidlScreenWnd__StoreIniVis                                0x7C6880
#define CSidlScreenWnd__WndNotification                            0x7C8510
#define CSidlScreenWnd__GetChildItem                               0x7C6950

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x5814B0
#define CSkillMgr__GetSkillCap                                     0x581520

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x535DB0
#define CSliderWnd__SetValue                                       0x7EDB30
#define CSliderWnd__SetNumTicks                                    0x7EE0E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6EE750

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7E2E10
#define CStmlWnd__CalculateHSBRange                                0x7DA3C0
#define CStmlWnd__CalculateVSBRange                                0x7DA450
#define CStmlWnd__CanBreakAtCharacter                              0x7DA5D0
#define CStmlWnd__FastForwardToEndOfTag                            0x7DB2C0
#define CStmlWnd__ForceParseNow                                    0x7E3400
#define CStmlWnd__GetNextTagPiece                                  0x7DB1E0
#define CStmlWnd__GetSTMLText                                      0x6061A0
#define CStmlWnd__GetThisChar                                      0x80E420
#define CStmlWnd__GetVisiableText                                  0x7DC720
#define CStmlWnd__InitializeWindowVariables                        0x7DED10
#define CStmlWnd__MakeStmlColorTag                                 0x7D92E0
#define CStmlWnd__MakeWndNotificationTag                           0x7D9380
#define CStmlWnd__SetSTMLText                                      0x7DEE40
#define CStmlWnd__StripFirstSTMLLines                              0x7E2AB0
#define CStmlWnd__UpdateHistoryString                              0x7DCFC0

// CTabWnd 
#define CTabWnd__Draw                                              0x7E9640
#define CTabWnd__DrawCurrentPage                                   0x7E8EC0
#define CTabWnd__DrawTab                                           0x7E8C90
#define CTabWnd__GetCurrentPage                                    0x7E9280
#define CTabWnd__GetPageClientRect                                 0x7E8940
#define CTabWnd__GetPageFromTabIndex                               0x7E8BC0
#define CTabWnd__GetPageInnerRect                                  0x7E89A0
#define CTabWnd__GetTabInnerRect                                   0x7E8B40
#define CTabWnd__GetTabRect                                        0x7E8A30
#define CTabWnd__InsertPage                                        0x7E98D0
#define CTabWnd__SetPage                                           0x7E92C0
#define CTabWnd__SetPageRect                                       0x7E9570
#define CTabWnd__UpdatePage                                        0x7E9850

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4192D0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7C8D00

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7E6AF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x7B35E0

// CXRect 
#define CXRect__CenterPoint                                        0x522D90

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x52E490
#define CXStr__CXStr1                                              0x7AE4F0
#define CXStr__CXStr3                                              0x812A40
#define CXStr__dCXStr                                              0x52E8F0
#define CXStr__operator_equal                                      0x812BB0
#define CXStr__operator_equal1                                     0x812C00
#define CXStr__operator_plus_equal1                                0x813D10

// CXWnd 
#define CXWnd__BringToTop                                          0x7BE010
#define CXWnd__Center                                              0x7C39C0
#define CXWnd__ClrFocus                                            0x7BDE40
#define CXWnd__DoAllDrawing                                        0x7C3850
#define CXWnd__DrawChildren                                        0x7C3990
#define CXWnd__DrawColoredRect                                     0x7BE330
#define CXWnd__DrawTooltip                                         0x7BE520
#define CXWnd__DrawTooltipAtPoint                                  0x7C2AC0
#define CXWnd__GetBorderFrame                                      0x7BE940
#define CXWnd__GetChildWndAt                                       0x7C1CB0
#define CXWnd__GetClientClipRect                                   0x7BE6C0
#define CXWnd__GetScreenClipRect                                   0x7C2FF0
#define CXWnd__GetScreenRect                                       0x7BEA70
#define CXWnd__GetTooltipRect                                      0x7BE440
#define CXWnd__GetWindowTextA                                      0x522910
#define CXWnd__IsActive                                            0x7C9E40
#define CXWnd__IsDescendantOf                                      0x7BE830
#define CXWnd__IsReallyVisible                                     0x7C1C90
#define CXWnd__IsType                                              0x7EAF40
#define CXWnd__Move                                                0x7C1400
#define CXWnd__Move1                                               0x7C3520
#define CXWnd__ProcessTransition                                   0x7BDFC0
#define CXWnd__Refade                                              0x7BDF40
#define CXWnd__Resize                                              0x7BEB40
#define CXWnd__Right                                               0x7C2F00
#define CXWnd__SetFocus                                            0x7C0570
#define CXWnd__SetKeyTooltip                                       0x7BED90
#define CXWnd__SetMouseOver                                        0x7C3310
#define CXWnd__StartFade                                           0x7BE050
#define CXWnd__GetChildItem                                        0x7C3250

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x7CB3A0
#define CXWndManager__DrawWindows                                  0x7CB020
#define CXWndManager__GetKeyboardFlags                             0x7C9A90
#define CXWndManager__HandleKeyboardMsg                            0x7CA110
#define CXWndManager__RemoveWnd                                    0x7C9F60

// CDBStr
#define CDBStr__GetString                                          0x471240

// EQ_Character 
#define EQ_Character__CastRay                                      0x755CC0
#define EQ_Character__CastSpell                                    0x433060
#define EQ_Character__Cur_HP                                       0x43C9D0
#define EQ_Character__GetAACastingTimeModifier                     0x427C40
#define EQ_Character__GetCharInfo2                                 0x754040
#define EQ_Character__GetFocusCastingTimeModifier                  0x422990
#define EQ_Character__GetFocusRangeModifier                        0x422B60
#define EQ_Character__Max_Endurance                                0x54EB00
#define EQ_Character__Max_HP                                       0x437080
#define EQ_Character__Max_Mana                                     0x54E900
#define EQ_Character__doCombatAbility                              0x54D6F0
#define EQ_Character__UseSkill                                     0x44C6F0
#define EQ_Character__GetConLevel                                  0x546C30
#define EQ_Character__IsExpansionFlag                              0x40DC60
#define EQ_Character__TotalEffect                                  0x42C4C0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x528390
#define EQ_Item__CreateItemTagString                               0x73A380
#define EQ_Item__IsStackable                                       0x72ECF0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x48B070
#define EQ_LoadingS__Array                                         0x9C68D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x5523D0
#define EQ_PC__GetAltAbilityIndex                                  0x7454E0
#define EQ_PC__GetCombatAbility                                    0x745570
#define EQ_PC__GetCombatAbilityTimer                               0x745620
#define EQ_PC__GetItemTimerValue                                   0x54D460
#define EQ_PC__HasLoreItem                                         0x54BF40

// EQItemList 
#define EQItemList__EQItemList                                     0x4BABF0
#define EQItemList__add_item                                       0x4BAB80
#define EQItemList__delete_item                                    0x4BAFA0
#define EQItemList__FreeItemList                                   0x4BAED0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x470800

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x557500
#define EQPlayer__dEQPlayer                                        0x55C0E0
#define EQPlayer__DoAttack                                         0x56D8C0
#define EQPlayer__EQPlayer                                         0x561C20
#define EQPlayer__SetNameSpriteState                               0x5599D0
#define EQPlayer__SetNameSpriteTint                                0x557570
#define EQPlayer__IsBodyType_j                                     0x755560
#define EQPlayer__IsTargetable                                     0x755830

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x562FE0
#define EQPlayerManager__GetSpawnByName                            0x563270

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x52DE00
#define KeypressHandler__AttachKeyToEqCommand                      0x52DE40
#define KeypressHandler__ClearCommandStateArray                    0x52DC10
#define KeypressHandler__HandleKeyDown                             0x52C5B0
#define KeypressHandler__HandleKeyUp                               0x52C8C0
#define KeypressHandler__SaveKeymapping                            0x52DCE0

// MapViewMap 
#define MapViewMap__Clear                                          0x66BD50
#define MapViewMap__SaveEx                                         0x66F400

#define PlayerPointManager__GetAltCurrency                         0x73FC80

// StringTable 
#define StringTable__getString                                     0x73C4D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x550C90
