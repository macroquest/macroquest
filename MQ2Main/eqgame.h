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
#define __ExpectedVersionDate                                     "Feb 10 2011"
#define __ExpectedVersionTime                                     "16:56:18"
#define __ActualVersionDate                                        0x89CBAC
#define __ActualVersionTime                                        0x89CBB8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x5240D0
#define __MemChecker1                                              0x7AFAE0
#define __MemChecker2                                              0x59A2C0
#define __MemChecker3                                              0x59A210
#define __MemChecker4                                              0x7D17D0
#define __EncryptPad0                                              0x93C5E8
#define __EncryptPad1                                              0x9486D8
#define __EncryptPad2                                              0x93F378
#define __EncryptPad3                                              0x93EF78
#define __EncryptPad4                                              0x94A180
#define __AC1                                                      0x6B30A0
#define __AC2                                                      0x4E6BD5
#define __AC3                                                      0x4F9398
#define __AC4                                                      0x4FE918
#define __AC5                                                      0x50AB3E
#define __AC6                                                      0x50E2AE
#define __AC7                                                      0x5066EB
#define __AC1_Data                                                 0x8844ED
// Direct Input
#define DI8__Main                                                  0xBA68D4
#define DI8__Keyboard                                              0xBA68D8
#define DI8__Mouse                                                 0xBA68DC
#define __AltTimerReady                                            0xB2AFCA
#define __Attack                                                   0xB8EAB6
#define __Autofire                                                 0xB8EAB7
#define __BindList                                                 0x936B98
#define __Clicks                                                   0xB29C78
#define __CommandList                                              0x937588
#define __CurrentMapLabel                                          0xBD1B78
#define __CurrentSocial                                            0x9329F0
#define __DoAbilityAvailable                                       0xB2AF64
#define __DoAbilityList                                            0xB609D4
#define __do_loot                                                  0x4BBB40
#define __DrawHandler                                              0x1D56754
#define __GroupCount                                               0xB23A62
#define __Guilds                                                   0xB259F0
#define __gWorld                                                   0xB2591C
#define __HotkeyPage                                               0xB87DC0
#define __HWnd                                                     0xBA6610
#define __InChatMode                                               0xB29BB0
#define __LastTell                                                 0xB2B8EC
#define __LMouseHeldTime                                           0xB29CE4
#define __Mouse                                                    0xBA68E0
#define __MouseLook                                                0xB29C46
#define __MouseEventTime                                           0xB8EC18
#define __NetStatusToggle                                          0xB29C49
#define __PCNames                                                  0xB2B330
#define __RangeAttackReady                                         0xB2AFC8
#define __RMouseHeldTime                                           0xB29CE0
#define __RunWalkState                                             0xB29BB4
#define __ScreenMode                                               0xA732A0
#define __ScreenX                                                  0xB29B68
#define __ScreenY                                                  0xB29B6C
#define __ScreenXMax                                               0xB29B70
#define __ScreenYMax                                               0xB29B74
#define __ServerHost                                               0xB239A4
#define __ServerName                                               0xB60994
#define __ShiftKeyDown                                             0xB2A274
#define __ShowNames                                                0xB2B200
#define __Socials                                                  0xB60A94


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xB25F50
#define instEQZoneInfo                                             0xB29E30
#define instKeypressHandler                                        0xB8EBFC
#define pinstActiveBanker                                          0xB259C4
#define pinstActiveCorpse                                          0xB259C8
#define pinstActiveGMaster                                         0xB259CC
#define pinstActiveMerchant                                        0xB259C0
#define pinstAltAdvManager                                         0xA74148
#define pinstAuraMgr                                               0x95CB5C
#define pinstBandageTarget                                         0xB259AC
#define pinstCamActor                                              0xA73C38
#define pinstCDBStr                                                0xA73294
#define pinstCDisplay                                              0xB259D4
#define pinstCEverQuest                                            0xBA6A58
#define pinstCharData                                              0xB25990
#define pinstCharSpawn                                             0xB259B8
#define pinstControlledMissile                                     0xB2598C
#define pinstControlledPlayer                                      0xB259B8
#define pinstCSidlManager                                          0x1D56C24
#define pinstCXWndManager                                          0x1D56C1C
#define instDynamicZone                                            0xB295B8
#define pinstDZMember                                              0xB296C8
#define pinstDZTimerInfo                                           0xB296CC
#define pinstEQItemList                                            0xB22C74
#define instEQMisc                                                 0xA73240
#define pinstEQSoundManager                                        0xA7416C
#define instExpeditionLeader                                       0xB29602
#define instExpeditionName                                         0xB29642
#define pinstGroup                                                 0xB23A5E
#define pinstImeManager                                            0x1D56C28
#define pinstLocalPlayer                                           0xB259A4
#define pinstMercenaryData                                         0xB8EF8C
#define pinstModelPlayer                                           0xB259D0
#define pinstPCData                                                0xB25990
#define pinstSkillMgr                                              0xBA3694
#define pinstSpawnManager                                          0xBA3478
#define pinstSpellManager                                          0xBA36A0
#define pinstSpellSets                                             0xB87DC4
#define pinstStringTable                                           0xB25938
#define pinstSwitchManager                                         0xB236A4
#define pinstTarget                                                0xB259BC
#define pinstTargetObject                                          0xB25994
#define pinstTargetSwitch                                          0xB25998
#define pinstTaskMember                                            0xA73220
#define pinstTrackTarget                                           0xB259B0
#define pinstTradeTarget                                           0xB259A0
#define instTributeActive                                          0xA73265
#define pinstViewActor                                             0xA73C34
#define pinstWorldData                                             0xB25974


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x95A420
#define pinstCAudioTriggersWindow                                  0x95A3EC
#define pinstCCharacterSelect                                      0xA73B10
#define pinstCFacePick                                             0xA73AC0
#define pinstCNoteWnd                                              0xA73AC8
#define pinstCBookWnd                                              0xA73ACC
#define pinstCPetInfoWnd                                           0xA73AD0
#define pinstCTrainWnd                                             0xA73AD4
#define pinstCSkillsWnd                                            0xA73AD8
#define pinstCSkillsSelectWnd                                      0xA73ADC
#define pinstCCombatSkillSelectWnd                                 0xA73AE0
#define pinstCFriendsWnd                                           0xA73AE4
#define pinstCAuraWnd                                              0xA73AE8
#define pinstCRespawnWnd                                           0xA73AEC
#define pinstCBandolierWnd                                         0xA73AF0
#define pinstCPotionBeltWnd                                        0xA73AF4
#define pinstCAAWnd                                                0xA73AF8
#define pinstCGroupSearchFiltersWnd                                0xA73AFC
#define pinstCLoadskinWnd                                          0xA73B00
#define pinstCAlarmWnd                                             0xA73B04
#define pinstCMusicPlayerWnd                                       0xA73B08
#define pinstCMailWnd                                              0xA73B14
#define pinstCMailCompositionWnd                                   0xA73B18
#define pinstCMailAddressBookWnd                                   0xA73B1C
#define pinstCRaidWnd                                              0xA73B24
#define pinstCRaidOptionsWnd                                       0xA73B28
#define pinstCBreathWnd                                            0xA73B2C
#define pinstCMapViewWnd                                           0xA73B30
#define pinstCMapToolbarWnd                                        0xA73B34
#define pinstCEditLabelWnd                                         0xA73B38
#define pinstCTargetWnd                                            0xA73B3C
#define pinstCColorPickerWnd                                       0xA73B40
#define pinstCPlayerWnd                                            0xA73B44
#define pinstCOptionsWnd                                           0xA73B48
#define pinstCBuffWindowNORMAL                                     0xA73B4C
#define pinstCBuffWindowSHORT                                      0xA73B50
#define pinstCharacterCreation                                     0xA73B54
#define pinstCCursorAttachment                                     0xA73B58
#define pinstCCastingWnd                                           0xA73B5C
#define pinstCCastSpellWnd                                         0xA73B60
#define pinstCSpellBookWnd                                         0xA73B64
#define pinstCInventoryWnd                                         0xA73B68
#define pinstCBankWnd                                              0xA73B6C
#define pinstCQuantityWnd                                          0xA73B70
#define pinstCLootWnd                                              0xA73B74
#define pinstCActionsWnd                                           0xA73B78
#define pinstCCombatAbilityWnd                                     0xA73B7C
#define pinstCMerchantWnd                                          0xA73B80
#define pinstCTradeWnd                                             0xA73B84
#define pinstCSelectorWnd                                          0xA73B88
#define pinstCBazaarWnd                                            0xA73B8C
#define pinstCBazaarSearchWnd                                      0xA73B90
#define pinstCGiveWnd                                              0xA73BAC
#define pinstCTrackingWnd                                          0xA73BB0
#define pinstCInspectWnd                                           0xA73BB4
#define pinstCSocialEditWnd                                        0xA73BB8
#define pinstCFeedbackWnd                                          0xA73BBC
#define pinstCBugReportWnd                                         0xA73BC0
#define pinstCVideoModesWnd                                        0xA73BC4
#define pinstCTextEntryWnd                                         0xA73BCC
#define pinstCFileSelectionWnd                                     0xA73BD0
#define pinstCCompassWnd                                           0xA73BD4
#define pinstCPlayerNotesWnd                                       0xA73BD8
#define pinstCGemsGameWnd                                          0xA73BDC
#define pinstCTimeLeftWnd                                          0xA73BE0
#define pinstCPetitionQWnd                                         0xA73BF4
#define pinstCSoulmarkWnd                                          0xA73BF8
#define pinstCStoryWnd                                             0xA73BFC
#define pinstCJournalTextWnd                                       0xA73C00
#define pinstCJournalCatWnd                                        0xA73C04
#define pinstCBodyTintWnd                                          0xA73C08
#define pinstCServerListWnd                                        0xA73C0C
#define pinstCAvaZoneWnd                                           0xA73C14
#define pinstCBlockedBuffWnd                                       0xA73C18
#define pinstCBlockedPetBuffWnd                                    0xA73C1C
#define pinstCInvSlotMgr                                           0xA73C2C
#define pinstCContainerMgr                                         0xA73C30
#define pinstCAdventureLeaderboardWnd                              0xBCF090
#define pinstCAdventureRequestWnd                                  0xBCF0AC
#define pinstCAltStorageWnd                                        0xBCF10C
#define pinstCAdventureStatsWnd                                    0xBCF0C8
#define pinstCBarterMerchantWnd                                    0xBCF2D8
#define pinstCBarterSearchWnd                                      0xBCF2F4
#define pinstCBarterWnd                                            0xBCF310
#define pinstCChatManager                                          0xBCF5B4
#define pinstCDynamicZoneWnd                                       0xBCF6AC
#define pinstCEQMainWnd                                            0xBCF720
#define pinstCFellowshipWnd                                        0xBCF784
#define pinstCFindLocationWnd                                      0xBCF7B8
#define pinstCGroupSearchWnd                                       0xBCF868
#define pinstCGroupWnd                                             0xBCF884
#define pinstCGuildBankWnd                                         0xBCF8A0
#define pinstCGuildMgmtWnd                                         0xBD18D8
#define pinstCGuildTributeMasterWnd                                0xBD18F8
#define pinstCHotButtonWnd                                         0xBD192C
#define pinstCHotButtonWnd1                                        0xBD192C
#define pinstCHotButtonWnd2                                        0xBD1930
#define pinstCHotButtonWnd3                                        0xBD1934
#define pinstCHotButtonWnd4                                        0xBD1938
#define pinstCItemDisplayManager                                   0xBD19E4
#define pinstCItemExpTransferWnd                                   0xBD1A04
#define pinstCLeadershipWnd                                        0xBD1AA0
#define pinstCLFGuildWnd                                           0xBD1ABC
#define pinstCMIZoneSelectWnd                                      0xBD1C2C
#define pinstCAdventureMerchantWnd                                 0xBD1D54
#define pinstCConfirmationDialog                                   0xBD1D70
#define pinstCPopupWndManager                                      0xBD1D70
#define pinstCProgressionSelectionWnd                              0xBD1DA4
#define pinstCPvPLeaderboardWnd                                    0xBD1DC0
#define pinstCPvPStatsWnd                                          0xBD1DDC
#define pinstCSystemInfoDialogBox                                  0xBD1F20
#define pinstCTargetOfTargetWnd                                    0xBD2A28
#define pinstCTaskSelectWnd                                        0xBD2A5C
#define pinstCTaskTemplateSelectWnd                                0xBD2A78
#define pinstCTaskWnd                                              0xBD2A94
#define pinstCTipWndOFDAY                                          0xBD2B10
#define pinstCTipWndCONTEXT                                        0xBD2B14
#define pinstCTitleWnd                                             0xBD2B30
#define pinstCTradeskillWnd                                        0xBD2B74
#define pinstCTributeBenefitWnd                                    0xBD2BC0
#define pinstCTributeMasterWnd                                     0xBD2BDC
#define pinstCContextMenuManager                                   0x1D56C80
#define pinstCVoiceMacroWnd                                        0xBA3894
#define pinstCHtmlWnd                                              0xBA38D0


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4CF9F0
#define __ConvertItemTags                                          0x4C11D0
#define __ExecuteCmd                                               0x4AD0B0
#define __get_melee_range                                          0x4B3150
#define __GetGaugeValueFromEQ                                      0x6B1F20
#define __GetLabelFromEQ                                           0x6B3040
#define __GetXTargetType                                           0x728850
#define __LoadFrontEnd                                             0x5991F0
#define __NewUIINI                                                 0x6B1AE0
#define __ProcessGameEvents                                        0x506E60
#define CrashDetected                                              0x598FF0
#define DrawNetStatus                                              0x530640
#define Util__FastTime                                             0x7B0290
#define Expansion_HoT                                              0xB2B160

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x482590
#define AltAdvManager__IsAbilityReady                              0x4825D0
#define AltAdvManager__GetAltAbility                               0x4827F0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x439350

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5B6E80

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C11A0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x776510

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5D8BF0
#define CChatManager__InitContextMenu                              0x5D93C0

// CChatService
#define CChatService__GetNumberOfFriends                           0x71D4D0
#define CChatService__GetFriendName                                0x71D4E0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5DD6F0
#define CChatWindow__Clear                                         0x5DE050
#define CChatWindow__WndNotification                               0x5DE240

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7601C0
#define CComboWnd__Draw                                            0x760390
#define CComboWnd__GetCurChoice                                    0x760080
#define CComboWnd__GetListRect                                     0x760680
#define CComboWnd__GetTextRect                                     0x7601F0
#define CComboWnd__InsertChoice                                    0x7606F0
#define CComboWnd__SetColors                                       0x760010
#define CComboWnd__SetChoice                                       0x760040

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5E7500
#define CContainerWnd__vftable                                     0x8A43D8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x476680
#define CDisplay__GetClickedActor                                  0x46F6C0
#define CDisplay__GetUserDefinedColor                              0x46E0A0
#define CDisplay__GetWorldFilePath                                 0x46D550
#define CDisplay__is3dON                                           0x46C680
#define CDisplay__ReloadUI                                         0x47F6C0
#define CDisplay__WriteTextHD2                                     0x472400

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B0E70
#define CEditBaseWnd__SetSel                                       0x783B10

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7694C0
#define CEditWnd__GetCharIndexPt                                   0x76A480
#define CEditWnd__GetDisplayString                                 0x769650
#define CEditWnd__GetHorzOffset                                    0x7698E0
#define CEditWnd__GetLineForPrintableChar                          0x769F30
#define CEditWnd__GetSelStartPt                                    0x76A6D0
#define CEditWnd__GetSTMLSafeText                                  0x769A80
#define CEditWnd__PointFromPrintableChar                           0x76A040
#define CEditWnd__SelectableCharFromPoint                          0x76A1C0
#define CEditWnd__SetEditable                                      0x769A50

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4E7300
#define CEverQuest__DropHeldItemOnGround                           0x4F4760
#define CEverQuest__dsp_chat                                       0x4ED700
#define CEverQuest__DoTellWindow                                   0x4EBEA0
#define CEverQuest__EnterZone                                      0x4FE8B0
#define CEverQuest__GetBodyTypeDesc                                0x4E4170
#define CEverQuest__GetClassDesc                                   0x4E39B0
#define CEverQuest__GetClassThreeLetterCode                        0x4E3FB0
#define CEverQuest__GetDeityDesc                                   0x4E47E0
#define CEverQuest__GetLangDesc                                    0x4E4500
#define CEverQuest__GetRaceDesc                                    0x4E47B0
#define CEverQuest__InterpretCmd                                   0x4EE260
#define CEverQuest__LeftClickedOnPlayer                            0x500A10
#define CEverQuest__LMouseUp                                       0x5043D0
#define CEverQuest__RightClickedOnPlayer                           0x505530
#define CEverQuest__RMouseUp                                       0x5066B0
#define CEverQuest__SetGameState                                   0x4E7790
#define CEverQuest__Emote                                          0x4ED920

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5F4400
#define CGaugeWnd__CalcLinesFillRect                               0x5F4460
#define CGaugeWnd__Draw                                            0x5F48B0

// CGuild
#define CGuild__FindMemberByName                                   0x41B9F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x60D630

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x619120
#define CInvSlotMgr__MoveItem                                      0x619530

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x618580
#define CInvSlot__SliderComplete                                   0x6168E0
#define CInvSlot__GetItemBase                                      0x616040

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x61A310

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6AF7E0
#define CItemDisplayWnd__UpdateStrings                             0x61B200

// CLabel 
#define CLabel__Draw                                               0x62F5F0

// CListWnd 
#define CListWnd__AddColumn                                        0x758D20
#define CListWnd__AddColumn1                                       0x758380
#define CListWnd__AddLine                                          0x757F30
#define CListWnd__AddString                                        0x7580D0
#define CListWnd__CalculateFirstVisibleLine                        0x754240
#define CListWnd__CalculateVSBRange                                0x756570
#define CListWnd__ClearAllSel                                      0x753790
#define CListWnd__CloseAndUpdateEditWindow                         0x7575A0
#define CListWnd__Compare                                          0x754C40
#define CListWnd__Draw                                             0x7561B0
#define CListWnd__DrawColumnSeparators                             0x756020
#define CListWnd__DrawHeader                                       0x753A20
#define CListWnd__DrawItem                                         0x755640
#define CListWnd__DrawLine                                         0x755CA0
#define CListWnd__DrawSeparator                                    0x7560C0
#define CListWnd__EnsureVisible                                    0x7543A0
#define CListWnd__ExtendSel                                        0x755560
#define CListWnd__GetColumnMinWidth                                0x753460
#define CListWnd__GetColumnWidth                                   0x7533A0
#define CListWnd__GetCurSel                                        0x752C20
#define CListWnd__GetHeaderRect                                    0x752D80
#define CListWnd__GetItemAtPoint                                   0x754670
#define CListWnd__GetItemAtPoint1                                  0x7546E0
#define CListWnd__GetItemData                                      0x752FA0
#define CListWnd__GetItemHeight                                    0x753EB0
#define CListWnd__GetItemIcon                                      0x753180
#define CListWnd__GetItemRect                                      0x754470
#define CListWnd__GetItemText                                      0x753030
#define CListWnd__GetSelList                                       0x758260
#define CListWnd__GetSeparatorRect                                 0x754B90
#define CListWnd__RemoveLine                                       0x758CD0
#define CListWnd__SetColors                                        0x752CF0
#define CListWnd__SetColumnJustification                           0x753600
#define CListWnd__SetColumnWidth                                   0x753420
#define CListWnd__SetCurSel                                        0x752C60
#define CListWnd__SetItemColor                                     0x757260
#define CListWnd__SetItemData                                      0x753830
#define CListWnd__SetItemText                                      0x757040
#define CListWnd__ShiftColumnSeparator                             0x756EB0
#define CListWnd__Sort                                             0x759460
#define CListWnd__ToggleSel                                        0x753700

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x645550

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x656810
#define CMerchantWnd__RequestBuyItem                               0x65A060
#define CMerchantWnd__RequestSellItem                              0x6790F0
#define CMerchantWnd__SelectBuySellSlot                            0x657AF0

// CObfuscator
#define CObfuscator__doit                                          0x6ECC70

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x771D40
#define CSidlManager__CreateLabel                                  0x6A86A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5B3010
#define CSidlScreenWnd__CalculateVSBRange                          0x5B2F30
#define CSidlScreenWnd__ConvertToRes                               0x7839F0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7625C0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7636C0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x763770
#define CSidlScreenWnd__dCSidlScreenWnd                            0x762E70
#define CSidlScreenWnd__DrawSidlPiece                              0x762280
#define CSidlScreenWnd__EnableIniStorage                           0x761A40
#define CSidlScreenWnd__GetSidlPiece                               0x762490
#define CSidlScreenWnd__Init1                                      0x763520
#define CSidlScreenWnd__LoadIniInfo                                0x762670
#define CSidlScreenWnd__LoadIniListWnd                             0x761B90
#define CSidlScreenWnd__LoadSidlScreen                             0x7630C0
#define CSidlScreenWnd__StoreIniInfo                               0x761640
#define CSidlScreenWnd__StoreIniVis                                0x7619D0
#define CSidlScreenWnd__WndNotification                            0x7632A0
#define CSidlScreenWnd__GetChildItem                               0x761AA0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x5668C0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7843E0
#define CSliderWnd__SetValue                                       0x7844E0
#define CSliderWnd__SetNumTicks                                    0x784A90

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6AD3F0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x781090
#define CStmlWnd__CalculateHSBRange                                0x7787C0
#define CStmlWnd__CalculateVSBRange                                0x778730
#define CStmlWnd__CanBreakAtCharacter                              0x778920
#define CStmlWnd__FastForwardToEndOfTag                            0x7795F0
#define CStmlWnd__ForceParseNow                                    0x7815C0
#define CStmlWnd__GetNextTagPiece                                  0x779510
#define CStmlWnd__GetSTMLText                                      0x5DD690
#define CStmlWnd__GetThisChar                                      0x7A8F20
#define CStmlWnd__GetVisiableText                                  0x77AA40
#define CStmlWnd__InitializeWindowVariables                        0x77D010
#define CStmlWnd__MakeStmlColorTag                                 0x777650
#define CStmlWnd__MakeWndNotificationTag                           0x7776F0
#define CStmlWnd__SetSTMLText                                      0x77D130
#define CStmlWnd__StripFirstSTMLLines                              0x780D40
#define CStmlWnd__UpdateHistoryString                              0x77B2D0

// CTabWnd 
#define CTabWnd__Draw                                              0x785990
#define CTabWnd__DrawCurrentPage                                   0x785260
#define CTabWnd__DrawTab                                           0x785040
#define CTabWnd__GetCurrentPage                                    0x785620
#define CTabWnd__GetPageClientRect                                 0x784CF0
#define CTabWnd__GetPageFromTabIndex                               0x784F70
#define CTabWnd__GetPageInnerRect                                  0x784D50
#define CTabWnd__GetTabInnerRect                                   0x784EF0
#define CTabWnd__GetTabRect                                        0x784DE0
#define CTabWnd__InsertPage                                        0x785C20
#define CTabWnd__SetPage                                           0x785660
#define CTabWnd__SetPageRect                                       0x7858C0
#define CTabWnd__UpdatePage                                        0x785BA0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417FE0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x763AF0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x786820

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x751BC0

// CXRect 
#define CXRect__CenterPoint                                        0x5B66E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x51D8F0
#define CXStr__CXStr1                                              0x6D5B60
#define CXStr__CXStr3                                              0x7AD4F0
#define CXStr__dCXStr                                              0x44E650
#define CXStr__operator_equal1                                     0x7AD6B0
#define CXStr__operator_plus_equal1                                0x7AE740

// CXWnd 
#define CXWnd__BringToTop                                          0x759A50
#define CXWnd__Center                                              0x75EA60
#define CXWnd__ClrFocus                                            0x759870
#define CXWnd__DoAllDrawing                                        0x75F3B0
#define CXWnd__DrawChildren                                        0x75F500
#define CXWnd__DrawColoredRect                                     0x759D50
#define CXWnd__DrawTooltip                                         0x75E990
#define CXWnd__DrawTooltipAtPoint                                  0x75E0C0
#define CXWnd__GetBorderFrame                                      0x75A290
#define CXWnd__GetChildWndAt                                       0x75D530
#define CXWnd__GetClientClipRect                                   0x75A010
#define CXWnd__GetScreenClipRect                                   0x75E580
#define CXWnd__GetScreenRect                                       0x75A3B0
#define CXWnd__GetTooltipRect                                      0x759E60
#define CXWnd__GetWindowTextA                                      0x5A42B0
#define CXWnd__IsActive                                            0x764C20
#define CXWnd__IsDescendantOf                                      0x75A180
#define CXWnd__IsReallyVisible                                     0x75D510
#define CXWnd__IsType                                              0x789620
#define CXWnd__Move                                                0x75CA20
#define CXWnd__Move1                                               0x75CAC0
#define CXWnd__ProcessTransition                                   0x759A00
#define CXWnd__Refade                                              0x759970
#define CXWnd__Resize                                              0x75A480
#define CXWnd__Right                                               0x75E490
#define CXWnd__SetFocus                                            0x75BC20
#define CXWnd__SetKeyTooltip                                       0x75A6D0
#define CXWnd__SetMouseOver                                        0x75E870
#define CXWnd__StartFade                                           0x759A90
#define CXWnd__GetChildItem                                        0x75E7E0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x766210
#define CXWndManager__DrawWindows                                  0x765E90
#define CXWndManager__GetKeyboardFlags                             0x764880
#define CXWndManager__HandleKeyboardMsg                            0x764EF0
#define CXWndManager__RemoveWnd                                    0x764D40

// CDBStr
#define CDBStr__GetString                                          0x46AF10

// EQ_Character 
#define EQ_Character__CastRay                                      0x70B0B0
#define EQ_Character__CastSpell                                    0x430260
#define EQ_Character__Cur_HP                                       0x439010
#define EQ_Character__GetAACastingTimeModifier                     0x425380
#define EQ_Character__GetCharInfo2                                 0x709DF0
#define EQ_Character__GetFocusCastingTimeModifier                  0x420A90
#define EQ_Character__GetFocusRangeModifier                        0x420C60
#define EQ_Character__Max_Endurance                                0x538810
#define EQ_Character__Max_HP                                       0x433FE0
#define EQ_Character__Max_Mana                                     0x538610
#define EQ_Character__doCombatAbility                              0x537480
#define EQ_Character__UseSkill                                     0x447860
#define EQ_Character__GetConLevel                                  0x532280
#define EQ_Character__IsExpansionFlag                              0x40D920
#define EQ_Character__TotalEffect                                  0x4297E0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5181F0
#define EQ_Item__CreateItemTagString                               0x6F9BB0
#define EQ_Item__IsStackable                                       0x6ED6F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4836C0
#define EQ_LoadingS__Array                                         0x934F58

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x53C780
#define EQ_PC__GetAltAbilityIndex                                  0x6FF8A0
#define EQ_PC__GetCombatAbility                                    0x6FF930
#define EQ_PC__GetCombatAbilityTimer                               0x6FF9E0
#define EQ_PC__GetItemTimerValue                                   0x5372A0
#define EQ_PC__HasLoreItem                                         0x708950

// EQItemList 
#define EQItemList__EQItemList                                     0x4B13A0
#define EQItemList__add_item                                       0x4B1330
#define EQItemList__delete_item                                    0x4B1750
#define EQItemList__FreeItemList                                   0x4B1680

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46A6E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x541210
#define EQPlayer__dEQPlayer                                        0x545B70
#define EQPlayer__DoAttack                                         0x556820
#define EQPlayer__EQPlayer                                         0x54B390
#define EQPlayer__SetNameSpriteState                               0x543620
#define EQPlayer__SetNameSpriteTint                                0x541280
#define EQPlayer__IsBodyType_j                                     0x70A980
#define EQPlayer__IsTargetable                                     0x70AB50

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x54C650
#define EQPlayerManager__GetSpawnByName                            0x54C9F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x51D310
#define KeypressHandler__AttachKeyToEqCommand                      0x51D350
#define KeypressHandler__ClearCommandStateArray                    0x51D120
#define KeypressHandler__HandleKeyDown                             0x51BB90
#define KeypressHandler__HandleKeyUp                               0x51BEA0
#define KeypressHandler__SaveKeymapping                            0x51D1F0

// MapViewMap 
#define MapViewMap__Clear                                          0x640BF0
#define MapViewMap__SaveEx                                         0x6415C0

#define PlayerPointManager__GetAltCurrency                         0x6FB000

// StringTable 
#define StringTable__getString                                     0x6ECEF0