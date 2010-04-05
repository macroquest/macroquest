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
#define __ExpectedVersionDate                                     "Aug 18 2009"
#define __ExpectedVersionTime                                     "17:35:50"
#define __ActualVersionDate                                        0x7F6D30
#define __ActualVersionTime                                        0x7F6D3C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x506DC0
#define __MemChecker1                                              0x6C4550
#define __MemChecker2                                              0x565940
#define __MemChecker3                                              0x565890
#define __MemChecker4                                              0x67EC20
#define __EncryptPad0                                              0x882778
#define __EncryptPad1                                              0x88CF50
#define __EncryptPad2                                              0x885210
#define __EncryptPad3                                              0x884E10
#define __EncryptPad4                                              0x88C5D8
#define __AC1                                                      0x647450
#define __AC2                                                      0x4D2A45
#define __AC3                                                      0x4E6488
#define __AC4                                                      0x4EA358
#define __AC5                                                      0x4F4A88
#define __AC6                                                      0x4F7E5B
#define __AC7                                                      0x4F0FE4
#define __AC1_Data                                                 0x7E07D0

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
#define __do_loot                                                  0x4ABD50
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
#define __CastRay                                                  0x4BF780
#define __ConvertItemTags                                          0x4B1310
#define __ExecuteCmd                                               0x49F820
#define __get_melee_range                                          0x4A4E30
#define __GetGaugeValueFromEQ                                      0x646690
#define __GetLabelFromEQ                                           0x6473F0
#define __LoadFrontEnd                                             0x564810
#define __NewUIINI                                                 0x646220
#define __ProcessGameEvents                                        0x4F13D0
#define CrashDetected                                              0x564610
#define DrawNetStatus                                              0x50F530
#define Util__FastTime                                             0x6C4C60


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x4773D0
#define AltAdvManager__IsAbilityReady                              0x477410
#define AltAdvManager__GetAltAbility                               0x477690

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x57C990

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x586180

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6F3140

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x59BD90
#define CChatManager__InitContextMenu                              0x59C560

// CChatService
#define CChatService__GetNumberOfFriends                           0x6B2C30
#define CChatService__GetFriendName                                0x6B2C40

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5A0740
#define CChatWindow__Clear                                         0x5A10B0
#define CChatWindow__WndNotification                               0x5A1190

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6DD9F0
#define CComboWnd__Draw                                            0x6DDBA0
#define CComboWnd__GetCurChoice                                    0x6DD990
#define CComboWnd__GetListRect                                     0x6DDE60
#define CComboWnd__GetTextRect                                     0x6DDA20
#define CComboWnd__InsertChoice                                    0x6DDED0
#define CComboWnd__SetColors                                       0x6DD920
#define CComboWnd__SetChoice                                       0x6DD950

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A84D0
#define CContainerWnd__vftable                                     0x7FD990

// CDisplay 
#define CDisplay__CleanGameUI                                      0x466360
#define CDisplay__GetClickedActor                                  0x463A80
#define CDisplay__GetUserDefinedColor                              0x462BA0
#define CDisplay__GetWorldFilePath                                 0x462030
#define CDisplay__is3dON                                           0x4611A0
#define CDisplay__ReloadUI                                         0x4745C0
#define CDisplay__WriteTextHD2                                     0x466B00

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x576970
#define CEditBaseWnd__SetSel                                       0x6FEDA0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6E65B0
#define CEditWnd__GetCharIndexPt                                   0x6E73F0
#define CEditWnd__GetDisplayString                                 0x6E6740
#define CEditWnd__GetHorzOffset                                    0x6E69D0
#define CEditWnd__GetLineForPrintableChar                          0x6E6EA0
#define CEditWnd__GetSelStartPt                                    0x6E7630
#define CEditWnd__GetSTMLSafeText                                  0x6E6B60
#define CEditWnd__PointFromPrintableChar                           0x6E6FB0
#define CEditWnd__SelectableCharFromPoint                          0x6E7130
#define CEditWnd__SetEditable                                      0x6E6B30

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D3120
#define CEverQuest__DropHeldItemOnGround                           0x4D7450
#define CEverQuest__dsp_chat                                       0x4D8C00
#define CEverQuest__DoTellWindow                                   0x4D75D0
#define CEverQuest__EnterZone                                      0x4EA2F0
#define CEverQuest__GetBodyTypeDesc                                0x4D0320
#define CEverQuest__GetClassDesc                                   0x4CFB60
#define CEverQuest__GetClassThreeLetterCode                        0x4D0160
#define CEverQuest__GetDeityDesc                                   0x4D0990
#define CEverQuest__GetLangDesc                                    0x4D06B0
#define CEverQuest__GetRaceDesc                                    0x4D0960
#define CEverQuest__InterpretCmd                                   0x4D9610
#define CEverQuest__LeftClickedOnPlayer                            0x4EBE40
#define CEverQuest__LMouseUp                                       0x4EF720
#define CEverQuest__RightClickedOnPlayer                           0x4EFFC0
#define CEverQuest__RMouseUp                                       0x4F0FA0
#define CEverQuest__SetGameState                                   0x4D35B0
#define CEverQuest__Emote                                          0x4D8E20

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5B4EE0
#define CGaugeWnd__CalcLinesFillRect                               0x5B4F40
#define CGaugeWnd__Draw                                            0x5B5350

// CGuild
#define CGuild__FindMemberByName                                   0x4183B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5CD550

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5D6B90
#define CInvSlotMgr__MoveItem                                      0x5D6D30

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5D6420
#define CInvSlot__SliderComplete                                   0x5D5560

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5D7CD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x644340
#define CItemDisplayWnd__UpdateStrings                             0x5D89D0

// CLabel 
#define CLabel__Draw                                               0x5EB290

// CListWnd 
#define CListWnd__AddColumn                                        0x6D8220
#define CListWnd__AddColumn1                                       0x6D7D00
#define CListWnd__AddLine                                          0x6D77D0
#define CListWnd__AddString                                        0x6D79D0
#define CListWnd__CalculateFirstVisibleLine                        0x6D49D0
#define CListWnd__CalculateVSBRange                                0x6D6800
#define CListWnd__ClearAllSel                                      0x6D4090
#define CListWnd__CloseAndUpdateEditWindow                         0x6D5045
#define CListWnd__Compare                                          0x6D53C0
#define CListWnd__Draw                                             0x6D64E0
#define CListWnd__DrawColumnSeparators                             0x6D6350
#define CListWnd__DrawHeader                                       0x6D42A0
#define CListWnd__DrawItem                                         0x6D5C50
#define CListWnd__DrawLine                                         0x6D5FF0
#define CListWnd__DrawSeparator                                    0x6D63F0
#define CListWnd__EnsureVisible                                    0x6D4A60
#define CListWnd__ExtendSel                                        0x6D5B70
#define CListWnd__GetColumnMinWidth                                0x6D3E20
#define CListWnd__GetColumnWidth                                   0x6D3D60
#define CListWnd__GetCurSel                                        0x6D37A0
#define CListWnd__GetHeaderRect                                    0x6D3910
#define CListWnd__GetItemAtPoint                                   0x6D4D50
#define CListWnd__GetItemAtPoint1                                  0x6D4DC0
#define CListWnd__GetItemData                                      0x6D3B10
#define CListWnd__GetItemHeight                                    0x6D4730
#define CListWnd__GetItemIcon                                      0x6D3CA0
#define CListWnd__GetItemRect                                      0x6D4B30
#define CListWnd__GetItemText                                      0x6D3B50
#define CListWnd__GetSelList                                       0x6D7BE0
#define CListWnd__GetSeparatorRect                                 0x6D5300
#define CListWnd__RemoveLine                                       0x6D7B90
#define CListWnd__SetColors                                        0x6D3870
#define CListWnd__SetColumnJustification                           0x6D3F00
#define CListWnd__SetColumnWidth                                   0x6D3DE0
#define CListWnd__SetCurSel                                        0x6D37E0
#define CListWnd__SetItemColor                                     0x6D7420
#define CListWnd__SetItemData                                      0x6D4130
#define CListWnd__SetItemText                                      0x6D73A0
#define CListWnd__ShiftColumnSeparator                             0x6D5AE0
#define CListWnd__Sort                                             0x6D8260
#define CListWnd__ToggleSel                                        0x6D4000

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x6009F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x60C1E0
#define CMerchantWnd__RequestBuyItem                               0x60DA50
#define CMerchantWnd__RequestSellItem                              0x60DE70
#define CMerchantWnd__SelectBuySellSlot                            0x60CF10

// CObfuscator
#define CObfuscator__doit                                          0x68DBF0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6EEA90
#define CSidlManager__CreateLabel                                  0x63D330

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6DF690
#define CSidlScreenWnd__CalculateVSBRange                          0x6F4B20
#define CSidlScreenWnd__ConvertToRes                               0x6FEC80
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6DFB10
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6E0BE0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6E0C90
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6E03B0
#define CSidlScreenWnd__DrawSidlPiece                              0x6DF7E0
#define CSidlScreenWnd__EnableIniStorage                           0x6DF2D0
#define CSidlScreenWnd__GetSidlPiece                               0x6DF9E0
#define CSidlScreenWnd__Init1                                      0x6E0A50
#define CSidlScreenWnd__LoadIniInfo                                0x6DFBC0
#define CSidlScreenWnd__LoadIniListWnd                             0x6DF420
#define CSidlScreenWnd__LoadSidlScreen                             0x6E0600
#define CSidlScreenWnd__StoreIniInfo                               0x6DEEE0
#define CSidlScreenWnd__WndNotification                            0x6E07D0
#define CSidlScreenWnd__GetChildItem                               0x6DF330

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x5326C0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7001E0
#define CSliderWnd__SetValue                                       0x7002E0
#define CSliderWnd__SetNumTicks                                    0x700850

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6420D0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6FCEF0
#define CStmlWnd__CalculateVSBRange                                0x6F4B20
#define CStmlWnd__CanBreakAtCharacter                              0x6F4C60
#define CStmlWnd__FastForwardToEndOfTag                            0x6F5900
#define CStmlWnd__ForceParseNow                                    0x6FD390
#define CStmlWnd__GetNextTagPiece                                  0x6F5820
#define CStmlWnd__GetSTMLText                                      0x5A06E0
#define CStmlWnd__GetThisChar                                      0x722970
#define CStmlWnd__GetVisiableText                                  0x6F6CF0
#define CStmlWnd__InitializeWindowVariables                        0x6F8F60
#define CStmlWnd__MakeStmlColorTag                                 0x6F3DA0
#define CStmlWnd__MakeWndNotificationTag                           0x6F3E40
#define CStmlWnd__SetSTMLText                                      0x6F9090
#define CStmlWnd__StripFirstSTMLLines                              0x6FCC80
#define CStmlWnd__UpdateHistoryString                              0x6F7560

// CTabWnd 
#define CTabWnd__Draw                                              0x701660
#define CTabWnd__DrawCurrentPage                                   0x701000
#define CTabWnd__DrawTab                                           0x700DE0
#define CTabWnd__GetCurrentPage                                    0x701300
#define CTabWnd__GetPageClientRect                                 0x700AB0
#define CTabWnd__GetPageFromTabIndex                               0x700D10
#define CTabWnd__GetPageInnerRect                                  0x700B10
#define CTabWnd__GetTabInnerRect                                   0x700C90
#define CTabWnd__GetTabRect                                        0x700BA0
#define CTabWnd__InsertPage                                        0x7018D0
#define CTabWnd__SetPage                                           0x701340
#define CTabWnd__SetPageRect                                       0x701590
#define CTabWnd__UpdatePage                                        0x701850

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x414950

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6E0FF0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x705C20

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6D3490

// CXRect 
#define CXRect__CenterPoint                                        0x57C010

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412C10
#define CXStr__CXStr1                                              0x6CD100
#define CXStr__CXStr3                                              0x6C6380
#define CXStr__dCXStr                                              0x6452B0
#define CXStr__operator_equal1                                     0x6C6540
#define CXStr__operator_plus_equal1                                0x6C7580

// CXWnd 
#define CXWnd__BringToTop                                          0x6D8940
#define CXWnd__Center                                              0x6DC380
#define CXWnd__ClrFocus                                            0x6D8660
#define CXWnd__DoAllDrawing                                        0x6DD190
#define CXWnd__DrawChildren                                        0x6DD2C0
#define CXWnd__DrawColoredRect                                     0x6D8BC0
#define CXWnd__DrawTooltip                                         0x6DCFB0
#define CXWnd__DrawTooltipAtPoint                                  0x6DC140
#define CXWnd__GetBorderFrame                                      0x6D90A0
#define CXWnd__GetChildWndAt                                       0x6DBC80
#define CXWnd__GetClientClipRect                                   0x6D8FB0
#define CXWnd__GetScreenClipRect                                   0x6DC5A0
#define CXWnd__GetScreenRect                                       0x6D9240
#define CXWnd__GetTooltipRect                                      0x6D8E10
#define CXWnd__GetWindowTextA                                      0x56F410
#define CXWnd__IsActive                                            0x6E2100
#define CXWnd__IsDescendantOf                                      0x6D9030
#define CXWnd__IsReallyVisible                                     0x6DBC60
#define CXWnd__IsType                                              0x702B50
#define CXWnd__Move                                                0x6DB840
#define CXWnd__Move1                                               0x6DCE10
#define CXWnd__ProcessTransition                                   0x6D8900
#define CXWnd__Refade                                              0x6D8710
#define CXWnd__Resize                                              0x6D9310
#define CXWnd__Right                                               0x6DC4E0
#define CXWnd__SetFocus                                            0x6DAA70
#define CXWnd__SetKeyTooltip                                       0x6D9520
#define CXWnd__SetMouseOver                                        0x6D94F0
#define CXWnd__StartFade                                           0x6D8980
#define CXWnd__GetChildItem                                        0x6DC760

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6E3500
#define CXWndManager__DrawWindows                                  0x6E3110
#define CXWndManager__GetKeyboardFlags                             0x6E1DB0
#define CXWndManager__HandleKeyboardMsg                            0x6E2300
#define CXWndManager__RemoveWnd                                    0x6E2220

// CDBStr
#define CDBStr__GetString                                          0x45FB00

// EQ_Character 
#define EQ_Character__CastRay                                      0x72EA90
#define EQ_Character__CastSpell                                    0x42AD30
#define EQ_Character__Cur_HP                                       0x434430
#define EQ_Character__GetAACastingTimeModifier                     0x420CD0
#define EQ_Character__GetCharInfo2                                 0x6A3D80
#define EQ_Character__GetFocusCastingTimeModifier                  0x41C660
#define EQ_Character__GetFocusRangeModifier                        0x41C7A0
#define EQ_Character__Max_Endurance                                0x515680
#define EQ_Character__Max_HP                                       0x42F330
#define EQ_Character__Max_Mana                                     0x5154B0
#define EQ_Character__doCombatAbility                              0x5143C0
#define EQ_Character__UseSkill                                     0x43DBE0
#define EQ_Character__GetConLevel                                  0x510980

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4FE620
#define EQ_Item__GetItemLinkHash                                   0x6976A0
#define EQ_Item__IsStackable                                       0x68E4D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x478560
#define EQ_LoadingS__Array                                         0x87BBA0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x5184F0
#define EQ_PC__GetAltAbilityIndex                                  0x69C100
#define EQ_PC__GetCombatAbility                                    0x69C190
#define EQ_PC__GetCombatAbilityTimer                               0x69C240
#define EQ_PC__GetItemTimerValue                                   0x513310
#define EQ_PC__HasLoreItem                                         0x5169C0

// EQItemList 
#define EQItemList__dEQItemList                                    0x4A3410
#define EQItemList__EQItemList                                     0x4A3360

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45F450

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x51CD40
#define EQPlayer__dEQPlayer                                        0x520DC0
#define EQPlayer__DoAttack                                         0x52E830
#define EQPlayer__EQPlayer                                         0x524B20
#define EQPlayer__SetNameSpriteState                               0x51ED30
#define EQPlayer__SetNameSpriteTint                                0x51CDB0
#define EQPlayer__IsBodyType_j                                     0x72E3A0
#define EQPlayer__IsTargetable                                     0x72E530

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x525C80
#define EQPlayerManager__GetSpawnByName                            0x525F60

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x5002A0
#define KeypressHandler__AttachKeyToEqCommand                      0x5002E0
#define KeypressHandler__ClearCommandStateArray                    0x5000B0
#define KeypressHandler__HandleKeyDown                             0x4FEC30
#define KeypressHandler__HandleKeyUp                               0x4FEF40
#define KeypressHandler__SaveKeymapping                            0x500180

// MapViewMap 
#define MapViewMap__Clear                                          0x5FC0C0
#define MapViewMap__SaveEx                                         0x5FCA90

#define OtherCharData__GetAltCurrency                              0x6BB3F0

// StringTable 
#define StringTable__getString                                     0x68DE70
