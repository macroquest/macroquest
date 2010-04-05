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
#define __ExpectedVersionDate                                     "Aug 11 2009"
#define __ExpectedVersionTime                                     "18:06:19"
#define __ActualVersionDate                                        0x7F6CF8
#define __ActualVersionTime                                        0x7F6D04

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x506BB0
#define __MemChecker1                                              0x6C4790
#define __MemChecker2                                              0x5657F0
#define __MemChecker3                                              0x565740
#define __MemChecker4                                              0x67EDA0
#define __EncryptPad0                                              0x882778
#define __EncryptPad1                                              0x88CF50
#define __EncryptPad2                                              0x885210
#define __EncryptPad3                                              0x884E10
#define __EncryptPad4                                              0x88C5D8
#define __AC1                                                      0x6475F0
#define __AC2                                                      0x4D2915
#define __AC3                                                      0x4E62A8
#define __AC4                                                      0x4EA178
#define __AC5                                                      0x4F48A8
#define __AC6                                                      0x4F7CBB
#define __AC7                                                      0x4F0E04
#define __AC1_Data                                                 0x7E07E0 

// Direct Input
#define DI8__Main                                                  0xAE38AC
#define DI8__Keyboard                                              0xAE38B0
#define DI8__Mouse                                                 0xAE38B4
#define __AltTimerReady                                            0xA6E1AA
#define __Attack                                                   0xACDC9E
#define __Autofire                                                 0xACDC9F
#define __BindList                                                 0x87D6D0
#define __Clicks                                                   0xA6CEB0
#define __CommandList                                              0x87DF50
#define __CurrentMapLabel                                          0xB0EAE8
#define __CurrentSocial                                            0x8796DC
#define __DoAbilityAvailable                                       0xA6E144
#define __DoAbilityList                                            0xAA3764
#define __do_loot                                                  0x4ABC40
#define __DrawHandler                                              0xB1DF5C
#define __GroupCount                                               0xA6716A
#define __Guilds                                                   0xA6C290
#define __gWorld                                                   0xA68C28
#define __HotkeyPage                                               0xACAB50
#define __HWnd                                                     0xAE35E8
#define __InChatMode                                               0xA6CDE8
#define __LastTell                                                 0xA6EABC
#define __LMouseHeldTime                                           0xA6CEDC
#define __Mouse                                                    0xAE38B8
#define __MouseLook                                                0xA6CE7E
#define __MouseEventTime                                           0xACDDB0
#define __NetStatusToggle                                          0xA6CE81
#define __PCNames                                                  0xA6E500
#define __RangeAttackReady                                         0xA6E1A8
#define __RMouseHeldTime                                           0xA6CED8
#define __RunWalkState                                             0xA6CDEC
#define __ScreenMode                                               0x9B6A30
#define __ScreenX                                                  0xA6CDA0
#define __ScreenY                                                  0xA6CDA4
#define __ScreenXMax                                               0xA6CDA8
#define __ScreenYMax                                               0xA6CDAC
#define __ServerHost                                               0xA670AC
#define __ServerName                                               0xAA3724
#define __ShiftKeyDown                                             0xA6D45C
#define __ShowNames                                                0xA6E3D8
#define __Socials                                                  0xAA3824


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA68CE8
#define instEQZoneInfo                                             0xA6D028
#define instKeypressHandler                                        0xACDD94
#define pinstActiveBanker                                          0xA68CC0
#define pinstActiveCorpse                                          0xA68CC4
#define pinstActiveGMaster                                         0xA68CC8
#define pinstActiveMerchant                                        0xA68CBC
#define pinstAltAdvManager                                         0x9B7898
#define pinstAuraMgr                                               0x8A02F4
#define pinstBandageTarget                                         0xA68CA8
#define pinstCamActor                                              0x9B7384
#define pinstCDBStr                                                0x9B6A20
#define pinstCDisplay                                              0xA68CD0
#define pinstCEverQuest                                            0xAE3A30
#define pinstCharData                                              0xA68C8C
#define pinstCharSpawn                                             0xA68CB4
#define pinstControlledMissile                                     0xA68C88
#define pinstControlledPlayer                                      0xA68CB4
#define pinstCSidlManager                                          0xB1D6E0
#define pinstCXWndManager                                          0xB1D6D8
#define instDynamicZone                                            0xA6CC70
#define pinstDZMember                                              0xA6CD80
#define pinstDZTimerInfo                                           0xA6CD84
#define pinstEQItemList                                            0xA68C70
#define instEQMisc                                                 0x9B69D8
#define pinstEQSoundManager                                        0x9B78BC
#define instExpeditionLeader                                       0xA6CCBA
#define instExpeditionName                                         0xA6CCFA
#define pinstGroup                                                 0xA67166
#define pinstImeManager                                            0xB1D6E4
#define pinstLocalPlayer                                           0xA68CA0
#define pinstMercenaryData                                         0xACE108
#define pinstModelPlayer                                           0xA68CCC
#define pinstPCData                                                0xA68C8C
#define pinstSkillMgr                                              0xAE06A8
#define pinstSpawnManager                                          0xAE0504
#define pinstSpellManager                                          0xAE06AC
#define pinstSpellSets                                             0xACAB54
#define pinstStringTable                                           0xA68C44
#define pinstSwitchManager                                         0xA66DAC
#define pinstTarget                                                0xA68CB8
#define pinstTargetObject                                          0xA68C90
#define pinstTargetSwitch                                          0xA68C94
#define pinstTaskMember                                            0x9B69B8
#define pinstTrackTarget                                           0xA68CAC
#define pinstTradeTarget                                           0xA68C9C
#define instTributeActive                                          0x9B69FD
#define pinstViewActor                                             0x9B7380
#define pinstWorldData                                             0xA68C6C


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x89DBA4
#define pinstCAudioTriggersWindow                                  0x89DB70
#define pinstCCharacterSelect                                      0x9B728C
#define pinstCFacePick                                             0x9B7240
#define pinstCNoteWnd                                              0x9B7244
#define pinstCBookWnd                                              0x9B7248
#define pinstCPetInfoWnd                                           0x9B724C
#define pinstCTrainWnd                                             0x9B7250
#define pinstCSkillsWnd                                            0x9B7254
#define pinstCSkillsSelectWnd                                      0x9B7258
#define pinstCCombatSkillSelectWnd                                 0x9B725C
#define pinstCFriendsWnd                                           0x9B7260
#define pinstCAuraWnd                                              0x9B7264
#define pinstCRespawnWnd                                           0x9B7268
#define pinstCBandolierWnd                                         0x9B726C
#define pinstCPotionBeltWnd                                        0x9B7270
#define pinstCAAWnd                                                0x9B7274
#define pinstCGroupSearchFiltersWnd                                0x9B7278
#define pinstCLoadskinWnd                                          0x9B727C
#define pinstCAlarmWnd                                             0x9B7280
#define pinstCMusicPlayerWnd                                       0x9B7284
#define pinstCMailWnd                                              0x9B7290
#define pinstCMailCompositionWnd                                   0x9B7294
#define pinstCMailAddressBookWnd                                   0x9B7298
#define pinstCRaidWnd                                              0x9B72A0
#define pinstCRaidOptionsWnd                                       0x9B72A4
#define pinstCBreathWnd                                            0x9B72A8
#define pinstCMapViewWnd                                           0x9B72AC
#define pinstCMapToolbarWnd                                        0x9B72B0
#define pinstCEditLabelWnd                                         0x9B72B4
#define pinstCTargetWnd                                            0x9B72B8
#define pinstCColorPickerWnd                                       0x9B72BC
#define pinstCPlayerWnd                                            0x9B72C0
#define pinstCOptionsWnd                                           0x9B72C4
#define pinstCBuffWindowNORMAL                                     0x9B72C8
#define pinstCBuffWindowSHORT                                      0x9B72CC
#define pinstCharacterCreation                                     0x9B72D0
#define pinstCCursorAttachment                                     0x9B72D4
#define pinstCCastingWnd                                           0x9B72D8
#define pinstCCastSpellWnd                                         0x9B72DC
#define pinstCSpellBookWnd                                         0x9B72E0
#define pinstCInventoryWnd                                         0x9B72E4
#define pinstCBankWnd                                              0x9B72E8
#define pinstCQuantityWnd                                          0x9B72EC
#define pinstCLootWnd                                              0x9B72F0
#define pinstCActionsWnd                                           0x9B72F4
#define pinstCCombatAbilityWnd                                     0x9B72F8
#define pinstCMerchantWnd                                          0x9B72FC
#define pinstCTradeWnd                                             0x9B7300
#define pinstCSelectorWnd                                          0x9B7304
#define pinstCBazaarWnd                                            0x9B7308
#define pinstCBazaarSearchWnd                                      0x9B730C
#define pinstCGiveWnd                                              0x9B7310
#define pinstCTrackingWnd                                          0x9B7314
#define pinstCInspectWnd                                           0x9B7318
#define pinstCSocialEditWnd                                        0x9B731C
#define pinstCFeedbackWnd                                          0x9B7320
#define pinstCBugReportWnd                                         0x9B7324
#define pinstCVideoModesWnd                                        0x9B7328
#define pinstCTextEntryWnd                                         0x9B7330
#define pinstCFileSelectionWnd                                     0x9B7334
#define pinstCCompassWnd                                           0x9B7338
#define pinstCPlayerNotesWnd                                       0x9B733C
#define pinstCGemsGameWnd                                          0x9B7340
#define pinstCTimeLeftWnd                                          0x9B7344
#define pinstCPetitionQWnd                                         0x9B7350
#define pinstCSoulmarkWnd                                          0x9B7354
#define pinstCStoryWnd                                             0x9B7358
#define pinstCJournalTextWnd                                       0x9B735C
#define pinstCJournalCatWnd                                        0x9B7360
#define pinstCBodyTintWnd                                          0x9B7364
#define pinstCServerListWnd                                        0x9B7368
#define pinstCAvaZoneWnd                                           0x9B736C
#define pinstCBlockedBuffWnd                                       0x9B7370
#define pinstCBlockedPetBuffWnd                                    0x9B7374
#define pinstCInvSlotMgr                                           0x9B7378
#define pinstCContainerMgr                                         0x9B737C
#define pinstCAdventureLeaderboardWnd                              0xB0C018
#define pinstCAdventureRequestWnd                                  0xB0C034
#define pinstCAltStorageWnd                                        0xB0C094
#define pinstCAdventureStatsWnd                                    0xB0C050
#define pinstCBarterMerchantWnd                                    0xB0C260
#define pinstCBarterSearchWnd                                      0xB0C27C
#define pinstCBarterWnd                                            0xB0C298
#define pinstCChatManager                                          0xB0C53C
#define pinstCDynamicZoneWnd                                       0xB0C634
#define pinstCEQMainWnd                                            0xB0C6A8
#define pinstCFellowshipWnd                                        0xB0C70C
#define pinstCFindLocationWnd                                      0xB0C740
#define pinstCGroupSearchWnd                                       0xB0C7F0
#define pinstCGroupWnd                                             0xB0C80C
#define pinstCGuildBankWnd                                         0xB0C828
#define pinstCGuildMgmtWnd                                         0xB0E860
#define pinstCGuildTributeMasterWnd                                0xB0E880
#define pinstCHotButtonWnd                                         0xB0E89C
#define pinstCHotButtonWnd1                                        0xB0E89C
#define pinstCHotButtonWnd2                                        0xB0E8A0
#define pinstCHotButtonWnd3                                        0xB0E8A4
#define pinstCHotButtonWnd4                                        0xB0E8A8
#define pinstCItemDisplayManager                                   0xB0E954
#define pinstCItemExpTransferWnd                                   0xB0E974
#define pinstCLeadershipWnd                                        0xB0EA10
#define pinstCLFGuildWnd                                           0xB0EA2C
#define pinstCMIZoneSelectWnd                                      0xB0EB9C
#define pinstCAdventureMerchantWnd                                 0xB0ECAC
#define pinstCConfirmationDialog                                   0xB0ECC8
#define pinstCPopupWndManager                                      0xB0ECC8
#define pinstCProgressionSelectionWnd                              0xB0ECFC
#define pinstCPvPLeaderboardWnd                                    0xB0ED18
#define pinstCPvPStatsWnd                                          0xB0ED34
#define pinstCSystemInfoDialogBox                                  0xB0EDE8
#define pinstCTargetOfTargetWnd                                    0xB0F6F4
#define pinstCTaskSelectWnd                                        0xB0F728
#define pinstCTaskTemplateSelectWnd                                0xB0F744
#define pinstCTaskWnd                                              0xB0F760
#define pinstCTipWndOFDAY                                          0xB0F7DC
#define pinstCTipWndCONTEXT                                        0xB0F7E0
#define pinstCTitleWnd                                             0xB0F7FC
#define pinstCTradeskillWnd                                        0xB0F840
#define pinstCTributeBenefitWnd                                    0xB0F88C
#define pinstCTributeMasterWnd                                     0xB0F8A8
#define pinstCContextMenuManager                                   0xB1D73C
#define pinstCVoiceMacroWnd                                        0xAE089C
#define pinstCHtmlWnd                                              0xAE08E8


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4BF670
#define __ConvertItemTags                                          0x4B1200
#define __ExecuteCmd                                               0x49F6C0
#define __get_melee_range                                          0x4A4D20
#define __GetGaugeValueFromEQ                                      0x646830
#define __GetLabelFromEQ                                           0x647590
#define __LoadFrontEnd                                             0x5646C0
#define __NewUIINI                                                 0x6463C0
#define __ProcessGameEvents                                        0x4F11F0
#define CrashDetected                                              0x5644C0
#define DrawNetStatus                                              0x50F320
#define Util__FastTime                                             0x6C4EA0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x477340
#define AltAdvManager__IsAbilityReady                              0x477380
#define AltAdvManager__GetAltAbility                               0x4775A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x57C880

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5860A0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6F3320

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x59BDE0
#define CChatManager__InitContextMenu                              0x59C580

// CChatService
#define CChatService__GetNumberOfFriends                           0x6B2E40
#define CChatService__GetFriendName                                0x6B2E50

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5A0760
#define CChatWindow__Clear                                         0x5A10D0
#define CChatWindow__WndNotification                               0x5A11B0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6DDE50
#define CComboWnd__Draw                                            0x6DE000
#define CComboWnd__GetCurChoice                                    0x6DDDF0
#define CComboWnd__GetListRect                                     0x6DE2C0
#define CComboWnd__GetTextRect                                     0x6DDE80
#define CComboWnd__InsertChoice                                    0x6DE330
#define CComboWnd__SetColors                                       0x6DDD80
#define CComboWnd__SetChoice                                       0x6DDDB0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A8450
#define CContainerWnd__vftable                                     0x7FD930

// CDisplay 
#define CDisplay__CleanGameUI                                      0x465EC0
#define CDisplay__GetClickedActor                                  0x4635E0
#define CDisplay__GetUserDefinedColor                              0x462700
#define CDisplay__GetWorldFilePath                                 0x461C00
#define CDisplay__is3dON                                           0x460D70
#define CDisplay__ReloadUI                                         0x474480
#define CDisplay__WriteTextHD2                                     0x466620

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5767F0
#define CEditBaseWnd__SetSel                                       0x6FEED0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6E6990
#define CEditWnd__GetCharIndexPt                                   0x6E77D0
#define CEditWnd__GetDisplayString                                 0x6E6B20
#define CEditWnd__GetHorzOffset                                    0x6E6DB0
#define CEditWnd__GetLineForPrintableChar                          0x6E7280
#define CEditWnd__GetSelStartPt                                    0x6E7A10
#define CEditWnd__GetSTMLSafeText                                  0x6E6F40
#define CEditWnd__PointFromPrintableChar                           0x6E7390
#define CEditWnd__SelectableCharFromPoint                          0x6E7510
#define CEditWnd__SetEditable                                      0x6E6F10

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D2FF0
#define CEverQuest__DropHeldItemOnGround                           0x4D7320
#define CEverQuest__dsp_chat                                       0x4D8A20
#define CEverQuest__DoTellWindow                                   0x4D74A0
#define CEverQuest__EnterZone                                      0x4EA110
#define CEverQuest__GetBodyTypeDesc                                0x4D01F0
#define CEverQuest__GetClassDesc                                   0x4CFA30
#define CEverQuest__GetClassThreeLetterCode                        0x4D0030
#define CEverQuest__GetDeityDesc                                   0x4D0860
#define CEverQuest__GetLangDesc                                    0x4D0580
#define CEverQuest__GetRaceDesc                                    0x4D0830
#define CEverQuest__InterpretCmd                                   0x4D9430
#define CEverQuest__LeftClickedOnPlayer                            0x4EBC60
#define CEverQuest__LMouseUp                                       0x4EF540
#define CEverQuest__RightClickedOnPlayer                           0x4EFDE0
#define CEverQuest__RMouseUp                                       0x4F0DC0
#define CEverQuest__SetGameState                                   0x4D3480
#define CEverQuest__Emote                                          0x4D8C40

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5B4E70
#define CGaugeWnd__CalcLinesFillRect                               0x5B4ED0
#define CGaugeWnd__Draw                                            0x5B52E0

// CGuild
#define CGuild__FindMemberByName                                   0x4180E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5CD4E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5D6B40
#define CInvSlotMgr__MoveItem                                      0x5D6CE0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5D63D0
#define CInvSlot__SliderComplete                                   0x5D5510

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5D7C80

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x644540
#define CItemDisplayWnd__UpdateStrings                             0x5D8980

// CLabel 
#define CLabel__Draw                                               0x5EB390

// CListWnd 
#define CListWnd__AddColumn                                        0x6D8660
#define CListWnd__AddColumn1                                       0x6D80F0
#define CListWnd__AddLine                                          0x6D7C10
#define CListWnd__AddString                                        0x6D7E10
#define CListWnd__CalculateFirstVisibleLine                        0x6D4E10
#define CListWnd__CalculateVSBRange                                0x6D6C40
#define CListWnd__ClearAllSel                                      0x6D44D0
#define CListWnd__CloseAndUpdateEditWindow                         0x6D5485
#define CListWnd__Compare                                          0x6D5800
#define CListWnd__Draw                                             0x6D6920
#define CListWnd__DrawColumnSeparators                             0x6D6790
#define CListWnd__DrawHeader                                       0x6D46E0
#define CListWnd__DrawItem                                         0x6D6090
#define CListWnd__DrawLine                                         0x6D6430
#define CListWnd__DrawSeparator                                    0x6D6830
#define CListWnd__EnsureVisible                                    0x6D4EA0
#define CListWnd__ExtendSel                                        0x6D5FB0
#define CListWnd__GetColumnMinWidth                                0x6D4260
#define CListWnd__GetColumnWidth                                   0x6D41A0
#define CListWnd__GetCurSel                                        0x6D3BE0
#define CListWnd__GetHeaderRect                                    0x6D3D50
#define CListWnd__GetItemAtPoint                                   0x6D5190
#define CListWnd__GetItemAtPoint1                                  0x6D5200
#define CListWnd__GetItemData                                      0x6D3F50
#define CListWnd__GetItemHeight                                    0x6D4B70
#define CListWnd__GetItemIcon                                      0x6D40E0
#define CListWnd__GetItemRect                                      0x6D4F70
#define CListWnd__GetItemText                                      0x6D3F90
#define CListWnd__GetSelList                                       0x6D7FD0
#define CListWnd__GetSeparatorRect                                 0x6D5740
#define CListWnd__RemoveLine                                       0x6D8610
#define CListWnd__SetColors                                        0x6D3CB0
#define CListWnd__SetColumnJustification                           0x6D4340
#define CListWnd__SetColumnWidth                                   0x6D4220
#define CListWnd__SetCurSel                                        0x6D3C20
#define CListWnd__SetItemColor                                     0x6D7860
#define CListWnd__SetItemData                                      0x6D4570
#define CListWnd__SetItemText                                      0x6D77E0
#define CListWnd__ShiftColumnSeparator                             0x6D5F20
#define CListWnd__Sort                                             0x6D86A0
#define CListWnd__ToggleSel                                        0x6D4440

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x600B30

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x60C330
#define CMerchantWnd__RequestBuyItem                               0x60DBA0
#define CMerchantWnd__RequestSellItem                              0x60DFC0
#define CMerchantWnd__SelectBuySellSlot                            0x60D060

// CObfuscator
#define CObfuscator__doit                                          0x68DE70

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6EEDD0
#define CSidlManager__CreateLabel                                  0x63D440

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5788A0
#define CSidlScreenWnd__CalculateVSBRange                          0x6F4D00
#define CSidlScreenWnd__ConvertToRes                               0x6FEDB0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6DFEC0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6E0F90
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6E1040
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6E0760
#define CSidlScreenWnd__DrawSidlPiece                              0x6DFB90
#define CSidlScreenWnd__EnableIniStorage                           0x6DF730
#define CSidlScreenWnd__GetSidlPiece                               0x6DFD90
#define CSidlScreenWnd__Init1                                      0x6E0E00
#define CSidlScreenWnd__LoadIniInfo                                0x6DFF70
#define CSidlScreenWnd__LoadIniListWnd                             0x6DF880
#define CSidlScreenWnd__LoadSidlScreen                             0x6E09B0
#define CSidlScreenWnd__StoreIniInfo                               0x6DF340
#define CSidlScreenWnd__WndNotification                            0x6E0B80
#define CSidlScreenWnd__GetChildItem                               0x6DF790

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x532440

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x700300
#define CSliderWnd__SetValue                                       0x700400
#define CSliderWnd__SetNumTicks                                    0x700970

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6422D0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6FCFF0
#define CStmlWnd__CalculateVSBRange                                0x6F4D00
#define CStmlWnd__CanBreakAtCharacter                              0x6F4E40
#define CStmlWnd__FastForwardToEndOfTag                            0x6F5AD0
#define CStmlWnd__ForceParseNow                                    0x6FD490
#define CStmlWnd__GetNextTagPiece                                  0x6F59F0
#define CStmlWnd__GetSTMLText                                      0x5A0700
#define CStmlWnd__GetThisChar                                      0x7229F0
#define CStmlWnd__GetVisiableText                                  0x6F6EA0
#define CStmlWnd__InitializeWindowVariables                        0x6F9110
#define CStmlWnd__MakeStmlColorTag                                 0x6F3F80
#define CStmlWnd__MakeWndNotificationTag                           0x6F4020
#define CStmlWnd__SetSTMLText                                      0x6F9240
#define CStmlWnd__StripFirstSTMLLines                              0x6FCD80
#define CStmlWnd__UpdateHistoryString                              0x6F7710

// CTabWnd 
#define CTabWnd__Draw                                              0x701780
#define CTabWnd__DrawCurrentPage                                   0x701120
#define CTabWnd__DrawTab                                           0x700F00
#define CTabWnd__GetCurrentPage                                    0x701420
#define CTabWnd__GetPageClientRect                                 0x700BD0
#define CTabWnd__GetPageFromTabIndex                               0x700E30
#define CTabWnd__GetPageInnerRect                                  0x700C30
#define CTabWnd__GetTabInnerRect                                   0x700DB0
#define CTabWnd__GetTabRect                                        0x700CC0
#define CTabWnd__InsertPage                                        0x7019F0
#define CTabWnd__SetPage                                           0x701460
#define CTabWnd__SetPageRect                                       0x7016B0
#define CTabWnd__UpdatePage                                        0x701970

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4146A0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6E13A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x705D40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6D38D0

// CXRect 
#define CXRect__CenterPoint                                        0x57BF00

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412A40
#define CXStr__CXStr1                                              0x6CE8B0
#define CXStr__CXStr3                                              0x6C6570
#define CXStr__dCXStr                                              0x5B4BC0
#define CXStr__operator_equal1                                     0x6C6730
#define CXStr__operator_plus_equal1                                0x6C7770

// CXWnd 
#define CXWnd__BringToTop                                          0x6D8D90
#define CXWnd__Center                                              0x6DC830
#define CXWnd__ClrFocus                                            0x6D8AA0
#define CXWnd__DoAllDrawing                                        0x6DD5F0
#define CXWnd__DrawChildren                                        0x6DD720
#define CXWnd__DrawColoredRect                                     0x6D9020
#define CXWnd__DrawTooltip                                         0x6DD410
#define CXWnd__DrawTooltipAtPoint                                  0x6DC5F0
#define CXWnd__GetBorderFrame                                      0x6D9500
#define CXWnd__GetChildWndAt                                       0x6DC130
#define CXWnd__GetClientClipRect                                   0x6D9410
#define CXWnd__GetScreenClipRect                                   0x6DCA50
#define CXWnd__GetScreenRect                                       0x6D96A0
#define CXWnd__GetTooltipRect                                      0x6D9270
#define CXWnd__GetWindowTextA                                      0x56F280
#define CXWnd__IsActive                                            0x6E24B0
#define CXWnd__IsDescendantOf                                      0x6D9490
#define CXWnd__IsReallyVisible                                     0x6DC110
#define CXWnd__IsType                                              0x702BE0
#define CXWnd__Move                                                0x6DBCF0
#define CXWnd__Move1                                               0x6DD270
#define CXWnd__ProcessTransition                                   0x6D8D50
#define CXWnd__Refade                                              0x6D8B50
#define CXWnd__Resize                                              0x6D9770
#define CXWnd__Right                                               0x6DC990
#define CXWnd__SetFocus                                            0x6DAF20
#define CXWnd__SetKeyTooltip                                       0x6D9980
#define CXWnd__SetMouseOver                                        0x6D9950
#define CXWnd__StartFade                                           0x6D8DD0
#define CXWnd__GetChildItem                                        0x6DCBC0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6E38E0
#define CXWndManager__DrawWindows                                  0x6E34F0
#define CXWndManager__GetKeyboardFlags                             0x6E2160
#define CXWndManager__HandleKeyboardMsg                            0x6E26B0
#define CXWndManager__RemoveWnd                                    0x6E25D0

// CDBStr
#define CDBStr__GetString                                          0x45F6D0

// EQ_Character 
#define EQ_Character__CastRay                                      0x72E950
#define EQ_Character__CastSpell                                    0x42AA80
#define EQ_Character__Cur_HP                                       0x434180
#define EQ_Character__GetAACastingTimeModifier                     0x420A30
#define EQ_Character__GetCharInfo2                                 0x6A3F90
#define EQ_Character__GetFocusCastingTimeModifier                  0x41C3E0
#define EQ_Character__GetFocusRangeModifier                        0x41C520
#define EQ_Character__Max_Endurance                                0x515470
#define EQ_Character__Max_HP                                       0x42F080
#define EQ_Character__Max_Mana                                     0x5152A0
#define EQ_Character__doCombatAbility                              0x5141B0
#define EQ_Character__UseSkill                                     0x43D930
#define EQ_Character__GetConLevel                                  0x510770

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4FE450
#define EQ_Item__GetItemLinkHash                                   0x6978D0
#define EQ_Item__IsStackable                                       0x68E750

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x478470
#define EQ_LoadingS__Array                                         0x87BBA0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x5182E0
#define EQ_PC__GetAltAbilityIndex                                  0x69C330
#define EQ_PC__GetCombatAbility                                    0x69C3C0
#define EQ_PC__GetCombatAbilityTimer                               0x69C470
#define EQ_PC__GetItemTimerValue                                   0x513100
#define EQ_PC__HasLoreItem                                         0x5167B0

// EQItemList 
#define EQItemList__dEQItemList                                    0x4A32B0
#define EQItemList__EQItemList                                     0x4A3200

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45F020

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x51CB50
#define EQPlayer__dEQPlayer                                        0x520BD0
#define EQPlayer__DoAttack                                         0x52E620
#define EQPlayer__EQPlayer                                         0x524910
#define EQPlayer__SetNameSpriteState                               0x51EB40
#define EQPlayer__SetNameSpriteTint                                0x51CBC0
#define EQPlayer__IsBodyType_j                                     0x72E260
#define EQPlayer__IsTargetable                                     0x72E3F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x525A70
#define EQPlayerManager__GetSpawnByName                            0x525D50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x5000D0
#define KeypressHandler__AttachKeyToEqCommand                      0x500110
#define KeypressHandler__ClearCommandStateArray                    0x4FFEE0
#define KeypressHandler__HandleKeyDown                             0x4FEA60
#define KeypressHandler__HandleKeyUp                               0x4FED70
#define KeypressHandler__SaveKeymapping                            0x4FFFB0

// MapViewMap 
#define MapViewMap__Clear                                          0x5FC200
#define MapViewMap__SaveEx                                         0x5FCBD0

#define OtherCharData__GetAltCurrency                              0x6BB630

// StringTable 
#define StringTable__getString                                     0x68E0F0
