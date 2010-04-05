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
#define __ExpectedVersionDate                                     "Oct 20 2009"
#define __ExpectedVersionTime                                     "13:52:51"
#define __ActualVersionDate                                        0x7FBD40
#define __ActualVersionTime                                        0x7FBD4C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x507D60
#define __MemChecker1                                              0x6C79F0
#define __MemChecker2                                              0x566D30
#define __MemChecker3                                              0x566C80
#define __MemChecker4                                              0x681CE0
#define __EncryptPad0                                              0x888790
#define __EncryptPad1                                              0x892F68
#define __EncryptPad2                                              0x88B228
#define __EncryptPad3                                              0x88AE28
#define __EncryptPad4                                              0x8925F0
#define __AC1                                                      0x64A4B0
#define __AC2                                                      0x4D34E5
#define __AC3                                                      0x4E72F8
#define __AC4                                                      0x4EB1C8
#define __AC5                                                      0x4F58F8
#define __AC6                                                      0x4F8CCB
#define __AC7                                                      0x4F1E34
#define __AC1_Data                                                 0x7E45B0

// Direct Input
#define DI8__Main                                                  0xAE98B4
#define DI8__Keyboard                                              0xAE98B8
#define DI8__Mouse                                                 0xAE98BC
#define __AltTimerReady                                            0xA741B2
#define __Attack                                                   0xAD3CA6
#define __Autofire                                                 0xAD3CA7
#define __BindList                                                 0x8836D0
#define __Clicks                                                   0xA72EB8
#define __CommandList                                              0x883F50
#define __CurrentMapLabel                                          0xB14AF0
#define __CurrentSocial                                            0x87F6DC
#define __DoAbilityAvailable                                       0xA7414C
#define __DoAbilityList                                            0xAA976C
#define __do_loot                                                  0x4AC680
#define __DrawHandler                                              0xB23F7C
#define __GroupCount                                               0xA6D172
#define __Guilds                                                   0xA72298
#define __gWorld                                                   0xA6EC30
#define __HotkeyPage                                               0xAD0B58
#define __HWnd                                                     0xAE95F0
#define __InChatMode                                               0xA72DF0
#define __LastTell                                                 0xA74AC4
#define __LMouseHeldTime                                           0xA72EE4
#define __Mouse                                                    0xAE98C0
#define __MouseLook                                                0xA72E86
#define __MouseEventTime                                           0xAD3DB8
#define __NetStatusToggle                                          0xA72E89
#define __PCNames                                                  0xA74508
#define __RangeAttackReady                                         0xA741B0
#define __RMouseHeldTime                                           0xA72EE0
#define __RunWalkState                                             0xA72DF4
#define __ScreenMode                                               0x9BCA38
#define __ScreenX                                                  0xA72DA8
#define __ScreenY                                                  0xA72DAC
#define __ScreenXMax                                               0xA72DB0
#define __ScreenYMax                                               0xA72DB4
#define __ServerHost                                               0xA6D0B4
#define __ServerName                                               0xAA972C
#define __ShiftKeyDown                                             0xA73464
#define __ShowNames                                                0xA743E0
#define __Socials                                                  0xAA982C


////
//Section 1: Vital Offsets
////
#define instCRaid                                                  0xA6ECF0
#define instEQZoneInfo                                             0xA73030
#define instKeypressHandler                                        0xAD3D9C
#define pinstActiveBanker                                          0xA6ECC8
#define pinstActiveCorpse                                          0xA6ECCC
#define pinstActiveGMaster                                         0xA6ECD0
#define pinstActiveMerchant                                        0xA6ECC4
#define pinstAltAdvManager                                         0x9BD8A0
#define pinstAuraMgr                                               0x8A62FC
#define pinstBandageTarget                                         0xA6ECB0
#define pinstCamActor                                              0x9BD390
#define pinstCDBStr                                                0x9BCA28
#define pinstCDisplay                                              0xA6ECD8
#define pinstCEverQuest                                            0xAE9A38
#define pinstCharData                                              0xA6EC94
#define pinstCharSpawn                                             0xA6ECBC
#define pinstControlledMissile                                     0xA6EC90
#define pinstControlledPlayer                                      0xA6ECBC
#define pinstCSidlManager                                          0xB23700
#define pinstCXWndManager                                          0xB236F8
#define instDynamicZone                                            0xA72C78
#define pinstDZMember                                              0xA72D88
#define pinstDZTimerInfo                                           0xA72D8C
#define pinstEQItemList                                            0xA6EC78
#define instEQMisc                                                 0x9BC9E0
#define pinstEQSoundManager                                        0x9BD8C4
#define instExpeditionLeader                                       0xA72CC2
#define instExpeditionName                                         0xA72D02
#define pinstGroup                                                 0xA6D16E
#define pinstImeManager                                            0xB23704
#define pinstLocalPlayer                                           0xA6ECA8
#define pinstMercenaryData                                         0xAD4110
#define pinstModelPlayer                                           0xA6ECD4
#define pinstPCData                                                0xA6EC94
#define pinstSkillMgr                                              0xAE66B0
#define pinstSpawnManager                                          0xAE650C
#define pinstSpellManager                                          0xAE66B4
#define pinstSpellSets                                             0xAD0B5C
#define pinstStringTable                                           0xA6EC4C
#define pinstSwitchManager                                         0xA6CDB4
#define pinstTarget                                                0xA6ECC0
#define pinstTargetObject                                          0xA6EC98
#define pinstTargetSwitch                                          0xA6EC9C
#define pinstTaskMember                                            0x9BC9C0
#define pinstTrackTarget                                           0xA6ECB4
#define pinstTradeTarget                                           0xA6ECA4
#define instTributeActive                                          0x9BCA05
#define pinstViewActor                                             0x9BD38C
#define pinstWorldData                                             0xA6EC74


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                          0x8A3BC4
#define pinstCAudioTriggersWindow                                  0x8A3B90
#define pinstCCharacterSelect                                      0x9BD294
#define pinstCFacePick                                             0x9BD248
#define pinstCNoteWnd                                              0x9BD24C
#define pinstCBookWnd                                              0x9BD250
#define pinstCPetInfoWnd                                           0x9BD254
#define pinstCTrainWnd                                             0x9BD258
#define pinstCSkillsWnd                                            0x9BD25C
#define pinstCSkillsSelectWnd                                      0x9BD260
#define pinstCCombatSkillSelectWnd                                 0x9BD264
#define pinstCFriendsWnd                                           0x9BD268
#define pinstCAuraWnd                                              0x9BD26C
#define pinstCRespawnWnd                                           0x9BD270
#define pinstCBandolierWnd                                         0x9BD274
#define pinstCPotionBeltWnd                                        0x9BD278
#define pinstCAAWnd                                                0x9BD27C
#define pinstCGroupSearchFiltersWnd                                0x9BD280
#define pinstCLoadskinWnd                                          0x9BD284
#define pinstCAlarmWnd                                             0x9BD288
#define pinstCMusicPlayerWnd                                       0x9BD28C
#define pinstCMailWnd                                              0x9BD298
#define pinstCMailCompositionWnd                                   0x9BD29C
#define pinstCMailAddressBookWnd                                   0x9BD2A0
#define pinstCRaidWnd                                              0x9BD2A8
#define pinstCRaidOptionsWnd                                       0x9BD2AC
#define pinstCBreathWnd                                            0x9BD2B0
#define pinstCMapViewWnd                                           0x9BD2B4
#define pinstCMapToolbarWnd                                        0x9BD2B8
#define pinstCEditLabelWnd                                         0x9BD2BC
#define pinstCTargetWnd                                            0x9BD2C0
#define pinstCColorPickerWnd                                       0x9BD2C4
#define pinstCPlayerWnd                                            0x9BD2C8
#define pinstCOptionsWnd                                           0x9BD2CC
#define pinstCBuffWindowNORMAL                                     0x9BD2D0
#define pinstCBuffWindowSHORT                                      0x9BD2D4
#define pinstCharacterCreation                                     0x9BD2D8
#define pinstCCursorAttachment                                     0x9BD2DC
#define pinstCCastingWnd                                           0x9BD2E0
#define pinstCCastSpellWnd                                         0x9BD2E4
#define pinstCSpellBookWnd                                         0x9BD2E8
#define pinstCInventoryWnd                                         0x9BD2EC
#define pinstCBankWnd                                              0x9BD2F0
#define pinstCQuantityWnd                                          0x9BD2F4
#define pinstCLootWnd                                              0x9BD2F8
#define pinstCActionsWnd                                           0x9BD2FC
#define pinstCCombatAbilityWnd                                     0x9BD300
#define pinstCMerchantWnd                                          0x9BD304
#define pinstCTradeWnd                                             0x9BD308
#define pinstCSelectorWnd                                          0x9BD30C
#define pinstCBazaarWnd                                            0x9BD310
#define pinstCBazaarSearchWnd                                      0x9BD314
#define pinstCGiveWnd                                              0x9BD318
#define pinstCTrackingWnd                                          0x9BD31C
#define pinstCInspectWnd                                           0x9BD320
#define pinstCSocialEditWnd                                        0x9BD324
#define pinstCFeedbackWnd                                          0x9BD328
#define pinstCBugReportWnd                                         0x9BD32C
#define pinstCVideoModesWnd                                        0x9BD330
#define pinstCTextEntryWnd                                         0x9BD338
#define pinstCFileSelectionWnd                                     0x9BD33C
#define pinstCCompassWnd                                           0x9BD340
#define pinstCPlayerNotesWnd                                       0x9BD344
#define pinstCGemsGameWnd                                          0x9BD348
#define pinstCTimeLeftWnd                                          0x9BD34C
#define pinstCPetitionQWnd                                         0x9BD35C
#define pinstCSoulmarkWnd                                          0x9BD360
#define pinstCStoryWnd                                             0x9BD364
#define pinstCJournalTextWnd                                       0x9BD368
#define pinstCJournalCatWnd                                        0x9BD36C
#define pinstCBodyTintWnd                                          0x9BD370
#define pinstCServerListWnd                                        0x9BD374
#define pinstCAvaZoneWnd                                           0x9BD378
#define pinstCBlockedBuffWnd                                       0x9BD37C
#define pinstCBlockedPetBuffWnd                                    0x9BD380
#define pinstCInvSlotMgr                                           0x9BD384
#define pinstCContainerMgr                                         0x9BD388
#define pinstCAdventureLeaderboardWnd                              0xB12020
#define pinstCAdventureRequestWnd                                  0xB1203C
#define pinstCAltStorageWnd                                        0xB1209C
#define pinstCAdventureStatsWnd                                    0xB12058
#define pinstCBarterMerchantWnd                                    0xB12268
#define pinstCBarterSearchWnd                                      0xB12284
#define pinstCBarterWnd                                            0xB122A0
#define pinstCChatManager                                          0xB12544
#define pinstCDynamicZoneWnd                                       0xB1263C
#define pinstCEQMainWnd                                            0xB126B0
#define pinstCFellowshipWnd                                        0xB12714
#define pinstCFindLocationWnd                                      0xB12748
#define pinstCGroupSearchWnd                                       0xB127F8
#define pinstCGroupWnd                                             0xB12814
#define pinstCGuildBankWnd                                         0xB12830
#define pinstCGuildMgmtWnd                                         0xB14868
#define pinstCGuildTributeMasterWnd                                0xB14888
#define pinstCHotButtonWnd                                         0xB148A4
#define pinstCHotButtonWnd1                                        0xB148A4
#define pinstCHotButtonWnd2                                        0xB148A8
#define pinstCHotButtonWnd3                                        0xB148AC
#define pinstCHotButtonWnd4                                        0xB148B0
#define pinstCItemDisplayManager                                   0xB1495C
#define pinstCItemExpTransferWnd                                   0xB1497C
#define pinstCLeadershipWnd                                        0xB14A18
#define pinstCLFGuildWnd                                           0xB14A34
#define pinstCMIZoneSelectWnd                                      0xB14BA4
#define pinstCAdventureMerchantWnd                                 0xB14CB4
#define pinstCConfirmationDialog                                   0xB14CD0
#define pinstCPopupWndManager                                      0xB14CD0
#define pinstCProgressionSelectionWnd                              0xB14D04
#define pinstCPvPLeaderboardWnd                                    0xB14D20
#define pinstCPvPStatsWnd                                          0xB14D3C
#define pinstCSystemInfoDialogBox                                  0xB14E08
#define pinstCTargetOfTargetWnd                                    0xB15714
#define pinstCTaskSelectWnd                                        0xB15748
#define pinstCTaskTemplateSelectWnd                                0xB15764
#define pinstCTaskWnd                                              0xB15780
#define pinstCTipWndOFDAY                                          0xB157FC
#define pinstCTipWndCONTEXT                                        0xB15800
#define pinstCTitleWnd                                             0xB1581C
#define pinstCTradeskillWnd                                        0xB15860
#define pinstCTributeBenefitWnd                                    0xB158AC
#define pinstCTributeMasterWnd                                     0xB158C8
#define pinstCContextMenuManager                                   0xB2375C
#define pinstCVoiceMacroWnd                                        0xAE68A4
#define pinstCHtmlWnd                                              0xAE68F0


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                                  0x4C00C0
#define __ConvertItemTags                                          0x4B1C50
#define __ExecuteCmd                                               0x4A00D0
#define __get_melee_range                                          0x4A5730
#define __GetGaugeValueFromEQ                                      0x6496F0
#define __GetLabelFromEQ                                           0x64A450
#define __LoadFrontEnd                                             0x565C00
#define __NewUIINI                                                 0x649280
#define __ProcessGameEvents                                        0x4F2220
#define CrashDetected                                              0x565A00
#define DrawNetStatus                                              0x510620
#define Util__FastTime                                             0x6C8100


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x477720
#define AltAdvManager__IsAbilityReady                              0x477760
#define AltAdvManager__GetAltAbility                               0x4779B0

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x57DE00

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x587220

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x6F6840

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x59D2E0
#define CChatManager__InitContextMenu                              0x59DAB0

// CChatService
#define CChatService__GetNumberOfFriends                           0x6B5FB0
#define CChatService__GetFriendName                                0x6B5FC0

// CChatWindow
#define CChatWindow__CChatWindow                                   0x5A1C90
#define CChatWindow__Clear                                         0x5A2600
#define CChatWindow__WndNotification                               0x5A26E0

// CComboWnd
#define CComboWnd__DeleteAll                                       0x6E0F70
#define CComboWnd__Draw                                            0x6E1120
#define CComboWnd__GetCurChoice                                    0x6E0F10
#define CComboWnd__GetListRect                                     0x6E13E0
#define CComboWnd__GetTextRect                                     0x6E0FA0
#define CComboWnd__InsertChoice                                    0x6E1450
#define CComboWnd__SetColors                                       0x6E0EA0
#define CComboWnd__SetChoice                                       0x6E0ED0

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x5A99D0
#define CContainerWnd__vftable                                     0x8029A0

// CDisplay
#define CDisplay__CleanGameUI                                      0x466650
#define CDisplay__GetClickedActor                                  0x463D80
#define CDisplay__GetUserDefinedColor                              0x462EA0
#define CDisplay__GetWorldFilePath                                 0x462310
#define CDisplay__is3dON                                           0x461480
#define CDisplay__ReloadUI                                         0x4748F0
#define CDisplay__WriteTextHD2                                     0x466DF0

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x577D70
#define CEditBaseWnd__SetSel                                       0x7026E0

// CEditWnd
#define CEditWnd__DrawCaret                                        0x6E9B00
#define CEditWnd__GetCharIndexPt                                   0x6EA940
#define CEditWnd__GetDisplayString                                 0x6E9C90
#define CEditWnd__GetHorzOffset                                    0x6E9F20
#define CEditWnd__GetLineForPrintableChar                          0x6EA3F0
#define CEditWnd__GetSelStartPt                                    0x6EAB80
#define CEditWnd__GetSTMLSafeText                                  0x6EA0B0
#define CEditWnd__PointFromPrintableChar                           0x6EA500
#define CEditWnd__SelectableCharFromPoint                          0x6EA680
#define CEditWnd__SetEditable                                      0x6EA080

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x4D3BC0
#define CEverQuest__DropHeldItemOnGround                           0x4D80A0
#define CEverQuest__dsp_chat                                       0x4D9800
#define CEverQuest__DoTellWindow                                   0x4D8220
#define CEverQuest__EnterZone                                      0x4EB160
#define CEverQuest__GetBodyTypeDesc                                0x4D0DC0
#define CEverQuest__GetClassDesc                                   0x4D0600
#define CEverQuest__GetClassThreeLetterCode                        0x4D0C00
#define CEverQuest__GetDeityDesc                                   0x4D1430
#define CEverQuest__GetLangDesc                                    0x4D1150
#define CEverQuest__GetRaceDesc                                    0x4D1400
#define CEverQuest__InterpretCmd                                   0x4DA210
#define CEverQuest__LeftClickedOnPlayer                            0x4ECC90
#define CEverQuest__LMouseUp                                       0x4F0570
#define CEverQuest__RightClickedOnPlayer                           0x4F0E10
#define CEverQuest__RMouseUp                                       0x4F1DF0
#define CEverQuest__SetGameState                                   0x4D4050
#define CEverQuest__Emote                                          0x4D9A20

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x5B63D0
#define CGaugeWnd__CalcLinesFillRect                               0x5B6430
#define CGaugeWnd__Draw                                            0x5B6840

// CGuild
#define CGuild__FindMemberByName                                   0x4183E0

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x5CE9B0

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x5D8060
#define CInvSlotMgr__MoveItem                                      0x5D8200

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5D78F0
#define CInvSlot__SliderComplete                                   0x5D6A30

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5D91A0

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell                                  0x647390
#define CItemDisplayWnd__UpdateStrings                             0x5D9EA0

// CLabel
#define CLabel__Draw                                               0x5EC730

// CListWnd
#define CListWnd__AddColumn                                        0x6DB790
#define CListWnd__AddColumn1                                       0x6DB220
#define CListWnd__AddLine                                          0x6DAD40
#define CListWnd__AddString                                        0x6DAF40
#define CListWnd__CalculateFirstVisibleLine                        0x6D7F40
#define CListWnd__CalculateVSBRange                                0x6D9D70
#define CListWnd__ClearAllSel                                      0x6D7600
#define CListWnd__CloseAndUpdateEditWindow                         0x6D85A0
#define CListWnd__Compare                                          0x6D8930
#define CListWnd__Draw                                             0x6D9A50
#define CListWnd__DrawColumnSeparators                             0x6D98C0
#define CListWnd__DrawHeader                                       0x6D7810
#define CListWnd__DrawItem                                         0x6D91C0
#define CListWnd__DrawLine                                         0x6D9560
#define CListWnd__DrawSeparator                                    0x6D9960
#define CListWnd__EnsureVisible                                    0x6D7FD0
#define CListWnd__ExtendSel                                        0x6D90E0
#define CListWnd__GetColumnMinWidth                                0x6D7390
#define CListWnd__GetColumnWidth                                   0x6D72D0
#define CListWnd__GetCurSel                                        0x6D6D10
#define CListWnd__GetHeaderRect                                    0x6D6E80
#define CListWnd__GetItemAtPoint                                   0x6D82C0
#define CListWnd__GetItemAtPoint1                                  0x6D8330
#define CListWnd__GetItemData                                      0x6D7080
#define CListWnd__GetItemHeight                                    0x6D7CA0
#define CListWnd__GetItemIcon                                      0x6D7210
#define CListWnd__GetItemRect                                      0x6D80A0
#define CListWnd__GetItemText                                      0x6D70C0
#define CListWnd__GetSelList                                       0x6DB100
#define CListWnd__GetSeparatorRect                                 0x6D8870
#define CListWnd__RemoveLine                                       0x6DB740
#define CListWnd__SetColors                                        0x6D6DE0
#define CListWnd__SetColumnJustification                           0x6D7470
#define CListWnd__SetColumnWidth                                   0x6D7350
#define CListWnd__SetCurSel                                        0x6D6D50
#define CListWnd__SetItemColor                                     0x6DA990
#define CListWnd__SetItemData                                      0x6D76A0
#define CListWnd__SetItemText                                      0x6DA910
#define CListWnd__ShiftColumnSeparator                             0x6D9050
#define CListWnd__Sort                                             0x6DB7D0
#define CListWnd__ToggleSel                                        0x6D7570

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x601EB0

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x60D670
#define CMerchantWnd__RequestBuyItem                               0x60EEE0
#define CMerchantWnd__RequestSellItem                              0x60F300
#define CMerchantWnd__SelectBuySellSlot                            0x60E3A0

// CObfuscator
#define CObfuscator__doit                                          0x690D10

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x6F1FB0
#define CSidlManager__CreateLabel                                  0x640380

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x579E10
#define CSidlScreenWnd__CalculateVSBRange                          0x6F84D0
#define CSidlScreenWnd__ConvertToRes                               0x7025C0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6E2FE0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6E40B0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6E4160
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6E3880
#define CSidlScreenWnd__DrawSidlPiece                              0x6E2CB0
#define CSidlScreenWnd__EnableIniStorage                           0x6E2850
#define CSidlScreenWnd__GetSidlPiece                               0x6E2EB0
#define CSidlScreenWnd__Init1                                      0x6E3F20
#define CSidlScreenWnd__LoadIniInfo                                0x6E3090
#define CSidlScreenWnd__LoadIniListWnd                             0x6E29A0
#define CSidlScreenWnd__LoadSidlScreen                             0x6E3AD0
#define CSidlScreenWnd__StoreIniInfo                               0x6E2460
#define CSidlScreenWnd__WndNotification                            0x6E3CA0
#define CSidlScreenWnd__GetChildItem                               0x6E28B0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x5337C0

// CSliderWnd
#define CSliderWnd__GetValue                                       0x703B10
#define CSliderWnd__SetValue                                       0x703C10
#define CSliderWnd__SetNumTicks                                    0x704180

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x645120

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x700830
#define CStmlWnd__CalculateVSBRange                                0x6F84D0
#define CStmlWnd__CanBreakAtCharacter                              0x6F8610
#define CStmlWnd__FastForwardToEndOfTag                            0x6F9260
#define CStmlWnd__ForceParseNow                                    0x700CD0
#define CStmlWnd__GetNextTagPiece                                  0x6F9180
#define CStmlWnd__GetSTMLText                                      0x5A1C30
#define CStmlWnd__GetThisChar                                      0x726170
#define CStmlWnd__GetVisiableText                                  0x6FA630
#define CStmlWnd__InitializeWindowVariables                        0x6FC8A0
#define CStmlWnd__MakeStmlColorTag                                 0x6F74A0
#define CStmlWnd__MakeWndNotificationTag                           0x6F7540
#define CStmlWnd__SetSTMLText                                      0x6FC9D0
#define CStmlWnd__StripFirstSTMLLines                              0x7005C0
#define CStmlWnd__UpdateHistoryString                              0x6FAEA0

// CTabWnd
#define CTabWnd__Draw                                              0x704F10
#define CTabWnd__DrawCurrentPage                                   0x704930
#define CTabWnd__DrawTab                                           0x704710
#define CTabWnd__GetCurrentPage                                    0x704BB0
#define CTabWnd__GetPageClientRect                                 0x7043E0
#define CTabWnd__GetPageFromTabIndex                               0x704640
#define CTabWnd__GetPageInnerRect                                  0x704440
#define CTabWnd__GetTabInnerRect                                   0x7045C0
#define CTabWnd__GetTabRect                                        0x7044D0
#define CTabWnd__InsertPage                                        0x705180
#define CTabWnd__SetPage                                           0x704BF0
#define CTabWnd__SetPageRect                                       0x704E40
#define CTabWnd__UpdatePage                                        0x705100

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x414990

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6E44C0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x7094D0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x6D6A00

// CXRect
#define CXRect__CenterPoint                                        0x57D480

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x501880
#define CXStr__CXStr1                                              0x4035F0
#define CXStr__CXStr3                                              0x6C97D0
#define CXStr__dCXStr                                              0x501BF0
#define CXStr__operator_equal1                                     0x6C9990
#define CXStr__operator_plus_equal1                                0x6CA9D0

// CXWnd
#define CXWnd__BringToTop                                          0x6DBEC0
#define CXWnd__Center                                              0x6DF900
#define CXWnd__ClrFocus                                            0x6DBBD0
#define CXWnd__DoAllDrawing                                        0x6E0710
#define CXWnd__DrawChildren                                        0x6E0840
#define CXWnd__DrawColoredRect                                     0x6DC140
#define CXWnd__DrawTooltip                                         0x6E0530
#define CXWnd__DrawTooltipAtPoint                                  0x6DF6C0
#define CXWnd__GetBorderFrame                                      0x6DC620
#define CXWnd__GetChildWndAt                                       0x6DF200
#define CXWnd__GetClientClipRect                                   0x6DC530
#define CXWnd__GetScreenClipRect                                   0x6DFB20
#define CXWnd__GetScreenRect                                       0x6DC7C0
#define CXWnd__GetTooltipRect                                      0x6DC390
#define CXWnd__GetWindowTextA                                      0x5707F0
#define CXWnd__IsActive                                            0x6E55D0
#define CXWnd__IsDescendantOf                                      0x6DC5B0
#define CXWnd__IsReallyVisible                                     0x6DF1E0
#define CXWnd__IsType                                              0x706380
#define CXWnd__Move                                                0x6DEDC0
#define CXWnd__Move1                                               0x6E0390
#define CXWnd__ProcessTransition                                   0x6DBE80
#define CXWnd__Refade                                              0x6DBC80
#define CXWnd__Resize                                              0x6DC890
#define CXWnd__Right                                               0x6DFA60
#define CXWnd__SetFocus                                            0x6DDFF0
#define CXWnd__SetKeyTooltip                                       0x6DCAA0
#define CXWnd__SetMouseOver                                        0x6DCA70
#define CXWnd__StartFade                                           0x6DBF00
#define CXWnd__GetChildItem                                        0x6DFCE0

// CXWndManager
#define CXWndManager__DrawCursor                                   0x6E6A50
#define CXWndManager__DrawWindows                                  0x6E6660
#define CXWndManager__GetKeyboardFlags                             0x6E5280
#define CXWndManager__HandleKeyboardMsg                            0x6E57D0
#define CXWndManager__RemoveWnd                                    0x6E56F0

// CDBStr
#define CDBStr__GetString                                          0x45FDF0

// EQ_Character
#define EQ_Character__CastRay                                      0x732220
#define EQ_Character__CastSpell                                    0x42AED0
#define EQ_Character__Cur_HP                                       0x4346E0
#define EQ_Character__GetAACastingTimeModifier                     0x420E00
#define EQ_Character__GetCharInfo2                                 0x6A7060
#define EQ_Character__GetFocusCastingTimeModifier                  0x41C690
#define EQ_Character__GetFocusRangeModifier                        0x41C7D0
#define EQ_Character__Max_Endurance                                0x516780
#define EQ_Character__Max_HP                                       0x42F560
#define EQ_Character__Max_Mana                                     0x5165B0
#define EQ_Character__doCombatAbility                              0x5154C0
#define EQ_Character__UseSkill                                     0x43DEA0
#define EQ_Character__GetConLevel                                  0x511A70

// EQ_Item
#define EQ_Item__CanDrop                                           0x4FF620
#define EQ_Item__GetItemLinkHash                                   0x69A7C0
#define EQ_Item__IsStackable                                       0x6915F0

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar                                0x478880
#define EQ_LoadingS__Array                                         0x881BA0

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x519600
#define EQ_PC__GetAltAbilityIndex                                  0x69F330
#define EQ_PC__GetCombatAbility                                    0x69F3C0
#define EQ_PC__GetCombatAbilityTimer                               0x69F470
#define EQ_PC__GetItemTimerValue                                   0x514400
#define EQ_PC__HasLoreItem                                         0x517AD0

// EQItemList
#define EQItemList__dEQItemList                                    0x4A3CC0
#define EQItemList__EQItemList                                     0x4A3C10

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45F750

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x51DE80
#define EQPlayer__dEQPlayer                                        0x521FD0
#define EQPlayer__DoAttack                                         0x52FA90
#define EQPlayer__EQPlayer                                         0x525D10
#define EQPlayer__SetNameSpriteState                               0x51FE70
#define EQPlayer__SetNameSpriteTint                                0x51DEF0
#define EQPlayer__IsBodyType_j                                     0x731B30
#define EQPlayer__IsTargetable                                     0x731CC0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x526EB0
#define EQPlayerManager__GetSpawnByName                            0x5271F0

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x5012A0
#define KeypressHandler__AttachKeyToEqCommand                      0x5012E0
#define KeypressHandler__ClearCommandStateArray                    0x5010B0
#define KeypressHandler__HandleKeyDown                             0x4FFC30
#define KeypressHandler__HandleKeyUp                               0x4FFF40
#define KeypressHandler__SaveKeymapping                            0x501180

// MapViewMap
#define MapViewMap__Clear                                          0x5FD580
#define MapViewMap__SaveEx                                         0x5FDF50

#define OtherCharData__GetAltCurrency                              0x6BE790

// StringTable
#define StringTable__getString                                     0x690F90