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
#define __ExpectedVersionDate                                     "Aug  9 2011"
#define __ExpectedVersionTime                                     "14:14:43"
#define __ActualVersionDate                                        0x8AEE54
#define __ActualVersionTime                                        0x8AEE60

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x5287D0
#define __MemChecker1                                              0x7BFD50
#define __MemChecker2                                              0x5A1050
#define __MemChecker3                                              0x5A0FA0
#define __MemChecker4                                              0x7E1B00
#define __EncryptPad0                                              0x950B50
#define __EncryptPad1                                              0x95CDB0
#define __EncryptPad2                                              0x9538E8
#define __EncryptPad3                                              0x9534E8
#define __EncryptPad4                                              0x95E858
#define __AC1                                                      0x6BE040
#define __AC2                                                      0x4EA305
#define __AC3                                                      0x4FCB08
#define __AC4                                                      0x5024E4
#define __AC5                                                      0x50E7AC
#define __AC6                                                      0x511F0E
#define __AC7                                                      0x50A40B
#define __AC1_Data                                                 0x895E8D
// Direct Input
#define DI8__Main                                                  0xBC13BC
#define DI8__Keyboard                                              0xBC13C0
#define DI8__Mouse                                                 0xBC13C4
#define __AltTimerReady                                            0xB597A6
#define __Attack                                                   0xBBD2C2
#define __Autofire                                                 0xBBD2C3
#define __BindList                                                 0x94B0A8
#define __Clicks                                                   0xB58450
#define __CommandList                                              0x94BA98
#define __CurrentMapLabel                                          0xBED0C8
#define __CurrentSocial                                            0x9469D8
#define __DoAbilityAvailable                                       0xB59740
#define __DoAbilityList                                            0xB8F1E0
#define __do_loot                                                  0x4BEF40
#define __DrawHandler                                              0x1247AA4
#define __GroupCount                                               0xB51E22
#define __Guilds                                                   0xB541B0
#define __gWorld                                                   0xB540DC
#define __HotkeyPage                                               0xBB65CC
#define __HWnd                                                     0xBC10F8
#define __InChatMode                                               0xB58388
#define __LastTell                                                 0xB5A0F8
#define __LMouseHeldTime                                           0xB584BC
#define __Mouse                                                    0xBC13C8
#define __MouseLook                                                0xB5841E
#define __MouseEventTime                                           0xBBD574
#define __NetStatusToggle                                          0xB58421
#define __PCNames                                                  0xB59B3C
#define __RangeAttackReady                                         0xB597A4
#define __RMouseHeldTime                                           0xB584B8
#define __RunWalkState                                             0xB5838C
#define __ScreenMode                                               0xAA1358
#define __ScreenX                                                  0xB58340
#define __ScreenY                                                  0xB58344
#define __ScreenXMax                                               0xB58348
#define __ScreenYMax                                               0xB5834C
#define __ServerHost                                               0xB51D64
#define __ServerName                                               0xB8F1A0
#define __ShiftKeyDown                                             0xB58A4C
#define __ShowNames                                                0xB599E0
#define __Socials                                                  0xB8F2A0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xB54CB8
#define instEQZoneInfo                                             0xB58608
#define instKeypressHandler                                        0xBBD570
#define pinstActiveBanker                                          0xB54184
#define pinstActiveCorpse                                          0xB54188
#define pinstActiveGMaster                                         0xB5418C
#define pinstActiveMerchant                                        0xB54180
#define pinstAltAdvManager                                         0xAA2280
#define pinstAuraMgr                                               0x9714F0
#define pinstBandageTarget                                         0xB5416C
#define pinstCamActor                                              0xAA1CF8
#define pinstCDBStr                                                0xAA1330
#define pinstCDisplay                                              0xB54194
#define pinstCEverQuest                                            0xBC1540
#define pinstCharData                                              0xB54150
#define pinstCharSpawn                                             0xB54178
#define pinstControlledMissile                                     0xB5414C
#define pinstControlledPlayer                                      0xB54178
#define pinstCSidlManager                                          0x1247F74
#define pinstCXWndManager                                          0x1247F6C
#define instDynamicZone                                            0xB54710
#define pinstDZMember                                              0xB54820
#define pinstDZTimerInfo                                           0xB54824
#define pinstEQItemList                                            0xB50EC8
#define instEQMisc                                                 0xAA12A8
#define pinstEQSoundManager                                        0xAA22F0
#define instExpeditionLeader                                       0xB5475A
#define instExpeditionName                                         0xB5479A
#define pinstGroup                                                 0xB51E1E
#define pinstImeManager                                            0x1247F78
#define pinstLocalPlayer                                           0xB54164
#define pinstMercenaryData                                         0xBBD9D8
#define pinstModelPlayer                                           0xB54190
#define pinstPCData                                                0xB54150
#define pinstSkillMgr                                              0xBBDFA0
#define pinstSpawnManager                                          0xBBDC38
#define pinstSpellManager                                          0xBBDFE0
#define pinstSpellSets                                             0xBB65D0
#define pinstStringTable                                           0xB540F8
#define pinstSwitchManager                                         0xB51A30
#define pinstTarget                                                0xB5417C
#define pinstTargetObject                                          0xB54154
#define pinstTargetSwitch                                          0xB54158
#define pinstTaskMember                                            0xAA1270
#define pinstTrackTarget                                           0xB54170
#define pinstTradeTarget                                           0xB54160
#define instTributeActive                                          0xAA12CD
#define pinstViewActor                                             0xAA1CF4
#define pinstWorldData                                             0xB54134


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x96EC50
#define pinstCAudioTriggersWindow                                  0x96EBE8
#define pinstCCharacterSelect                                      0xAA1BC8
#define pinstCFacePick                                             0xAA1B78
#define pinstCNoteWnd                                              0xAA1B80
#define pinstCBookWnd                                              0xAA1B84
#define pinstCPetInfoWnd                                           0xAA1B88
#define pinstCTrainWnd                                             0xAA1B8C
#define pinstCSkillsWnd                                            0xAA1B90
#define pinstCSkillsSelectWnd                                      0xAA1B94
#define pinstCCombatSkillSelectWnd                                 0xAA1B98
#define pinstCFriendsWnd                                           0xAA1B9C
#define pinstCAuraWnd                                              0xAA1BA0
#define pinstCRespawnWnd                                           0xAA1BA4
#define pinstCBandolierWnd                                         0xAA1BA8
#define pinstCPotionBeltWnd                                        0xAA1BAC
#define pinstCAAWnd                                                0xAA1BB0
#define pinstCGroupSearchFiltersWnd                                0xAA1BB4
#define pinstCLoadskinWnd                                          0xAA1BB8
#define pinstCAlarmWnd                                             0xAA1BBC
#define pinstCMusicPlayerWnd                                       0xAA1BC0
#define pinstCMailWnd                                              0xAA1BCC
#define pinstCMailCompositionWnd                                   0xAA1BD0
#define pinstCMailAddressBookWnd                                   0xAA1BD4
#define pinstCRaidWnd                                              0xAA1BDC
#define pinstCRaidOptionsWnd                                       0xAA1BE0
#define pinstCBreathWnd                                            0xAA1BE4
#define pinstCMapViewWnd                                           0xAA1BE8
#define pinstCMapToolbarWnd                                        0xAA1BEC
#define pinstCEditLabelWnd                                         0xAA1BF0
#define pinstCTargetWnd                                            0xAA1BF4
#define pinstCColorPickerWnd                                       0xAA1BF8
#define pinstCPlayerWnd                                            0xAA1BFC
#define pinstCOptionsWnd                                           0xAA1C00
#define pinstCBuffWindowNORMAL                                     0xAA1C04
#define pinstCBuffWindowSHORT                                      0xAA1C08
#define pinstCharacterCreation                                     0xAA1C0C
#define pinstCCursorAttachment                                     0xAA1C10
#define pinstCCastingWnd                                           0xAA1C14
#define pinstCCastSpellWnd                                         0xAA1C18
#define pinstCSpellBookWnd                                         0xAA1C1C
#define pinstCInventoryWnd                                         0xAA1C20
#define pinstCBankWnd                                              0xAA1C24
#define pinstCQuantityWnd                                          0xAA1C28
#define pinstCLootWnd                                              0xAA1C2C
#define pinstCActionsWnd                                           0xAA1C30
#define pinstCCombatAbilityWnd                                     0xAA1C34
#define pinstCMerchantWnd                                          0xAA1C38
#define pinstCTradeWnd                                             0xAA1C3C
#define pinstCSelectorWnd                                          0xAA1C40
#define pinstCBazaarWnd                                            0xAA1C44
#define pinstCBazaarSearchWnd                                      0xAA1C48
#define pinstCGiveWnd                                              0xAA1C64
#define pinstCTrackingWnd                                          0xAA1C68
#define pinstCInspectWnd                                           0xAA1C6C
#define pinstCSocialEditWnd                                        0xAA1C70
#define pinstCFeedbackWnd                                          0xAA1C74
#define pinstCBugReportWnd                                         0xAA1C78
#define pinstCVideoModesWnd                                        0xAA1C7C
#define pinstCTextEntryWnd                                         0xAA1C84
#define pinstCFileSelectionWnd                                     0xAA1C88
#define pinstCCompassWnd                                           0xAA1C8C
#define pinstCPlayerNotesWnd                                       0xAA1C90
#define pinstCGemsGameWnd                                          0xAA1C94
#define pinstCTimeLeftWnd                                          0xAA1C98
#define pinstCPetitionQWnd                                         0xAA1CAC
#define pinstCSoulmarkWnd                                          0xAA1CB0
#define pinstCStoryWnd                                             0xAA1CB4
#define pinstCJournalTextWnd                                       0xAA1CB8
#define pinstCJournalCatWnd                                        0xAA1CBC
#define pinstCBodyTintWnd                                          0xAA1CC0
#define pinstCServerListWnd                                        0xAA1CC4
#define pinstCAvaZoneWnd                                           0xAA1CCC
#define pinstCBlockedBuffWnd                                       0xAA1CD0
#define pinstCBlockedPetBuffWnd                                    0xAA1CD4
#define pinstCInvSlotMgr                                           0xAA1CEC
#define pinstCContainerMgr                                         0xAA1CF0
#define pinstCAdventureLeaderboardWnd                              0xBE9C98
#define pinstCAdventureRequestWnd                                  0xBE9C60
#define pinstCAltStorageWnd                                        0xBE9D10
#define pinstCAdventureStatsWnd                                    0xBE9C98
#define pinstCBarterMerchantWnd                                    0xBEA168
#define pinstCBarterSearchWnd                                      0xBEA1A0
#define pinstCBarterWnd                                            0xBEA1D8
#define pinstCChatManager                                          0xBEA5D0
#define pinstCDynamicZoneWnd                                       0xBEA7C0
#define pinstCEQMainWnd                                            0xBEA880
#define pinstCFellowshipWnd                                        0xBEA948
#define pinstCFindLocationWnd                                      0xBEA9B0
#define pinstCGroupSearchWnd                                       0xBEAB10
#define pinstCGroupWnd                                             0xBEAB48
#define pinstCGuildBankWnd                                         0xBEAB80
#define pinstCGuildMgmtWnd                                         0xBECBF0
#define pinstCGuildTributeMasterWnd                                0xBECC28
#define pinstCHotButtonWnd                                         0xBECC78
#define pinstCHotButtonWnd1                                        0xBECC78
#define pinstCHotButtonWnd2                                        0xBECC7C
#define pinstCHotButtonWnd3                                        0xBECC80
#define pinstCHotButtonWnd4                                        0xBECC84
#define pinstCItemDisplayManager                                   0xBECDC0
#define pinstCItemExpTransferWnd                                   0xBECDFC
#define pinstCLeadershipWnd                                        0xBECF28
#define pinstCLFGuildWnd                                           0xBECF60
#define pinstCMIZoneSelectWnd                                      0xBED1F8
#define pinstCAdventureMerchantWnd                                 0xBED4A8
#define pinstCConfirmationDialog                                   0xBED4E0
#define pinstCPopupWndManager                                      0xBED4E0
#define pinstCProgressionSelectionWnd                              0xBED548
#define pinstCPvPLeaderboardWnd                                    0xBED580
#define pinstCPvPStatsWnd                                          0xBED5B8
#define pinstCSystemInfoDialogBox                                  0xBED840
#define pinstCTargetOfTargetWnd                                    0xBEE440
#define pinstCTaskSelectWnd                                        0xBEE4A8
#define pinstCTaskTemplateSelectWnd                                0xBEE4E0
#define pinstCTaskWnd                                              0xBEE518
#define pinstCTipWndOFDAY                                          0xBEE690
#define pinstCTipWndCONTEXT                                        0xBEE694
#define pinstCTitleWnd                                             0xBEE6C8
#define pinstCTradeskillWnd                                        0xBEE740
#define pinstCTributeBenefitWnd                                    0xBEE7D8
#define pinstCTributeMasterWnd                                     0xBEE810
#define pinstCContextMenuManager                                   0x1247FD0
#define pinstCVoiceMacroWnd                                        0xBBE2F8
#define pinstCHtmlWnd                                              0xBBE370


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D33A0
#define __ConvertItemTags                                          0x4C4720
#define __ExecuteCmd                                               0x4B0560
#define __get_melee_range                                          0x4B6530
#define __GetGaugeValueFromEQ                                      0x6BCEC0
#define __GetLabelFromEQ                                           0x6BDFE0
#define __GetXTargetType                                           0x734DF0
#define __LoadFrontEnd                                             0x59FF80
#define __NewUIINI                                                 0x6BCA70
#define __ProcessGameEvents                                        0x50AB90
#define CrashDetected                                              0x59FD80
#define DrawNetStatus                                              0x534CA0
#define Util__FastTime                                             0x7C0590
#define Expansion_HoT                                              0xB59940

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483BA0
#define AltAdvManager__IsAbilityReady                              0x483C60
#define AltAdvManager__GetAltAbility                               0x483F60

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x439330

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5BDBF0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C7FB0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x786130

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5DFDE0
#define CChatManager__InitContextMenu                              0x5E05B0

// CChatService
#define CChatService__GetNumberOfFriends                           0x728EA0
#define CChatService__GetFriendName                                0x728EB0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5E4910
#define CChatWindow__Clear                                         0x5E5260
#define CChatWindow__WndNotification                               0x5E5440

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x76FAE0
#define CComboWnd__Draw                                            0x76FCA0
#define CComboWnd__GetCurChoice                                    0x76F9A0
#define CComboWnd__GetListRect                                     0x76FF70
#define CComboWnd__GetTextRect                                     0x76FB10
#define CComboWnd__InsertChoice                                    0x76FFE0
#define CComboWnd__SetColors                                       0x76F930
#define CComboWnd__SetChoice                                       0x76F960

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5EE620
#define CContainerWnd__vftable                                     0x8B66A0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x477920
#define CDisplay__GetClickedActor                                  0x470990
#define CDisplay__GetUserDefinedColor                              0x46F370
#define CDisplay__GetWorldFilePath                                 0x46E820
#define CDisplay__is3dON                                           0x46D950
#define CDisplay__ReloadUI                                         0x4809F0
#define CDisplay__WriteTextHD2                                     0x473690

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B7B60
#define CEditBaseWnd__SetSel                                       0x7939E0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x778F90
#define CEditWnd__GetCharIndexPt                                   0x779F20
#define CEditWnd__GetDisplayString                                 0x779120
#define CEditWnd__GetHorzOffset                                    0x7793B0
#define CEditWnd__GetLineForPrintableChar                          0x7799F0
#define CEditWnd__GetSelStartPt                                    0x77A160
#define CEditWnd__GetSTMLSafeText                                  0x779540
#define CEditWnd__PointFromPrintableChar                           0x779B00
#define CEditWnd__SelectableCharFromPoint                          0x779C70
#define CEditWnd__SetEditable                                      0x779510

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EAA30
#define CEverQuest__DropHeldItemOnGround                           0x4F7FC0
#define CEverQuest__dsp_chat                                       0x4F0E70
#define CEverQuest__DoTellWindow                                   0x4EF5E0
#define CEverQuest__EnterZone                                      0x502470
#define CEverQuest__GetBodyTypeDesc                                0x4E78A0
#define CEverQuest__GetClassDesc                                   0x4E70E0
#define CEverQuest__GetClassThreeLetterCode                        0x4E76E0
#define CEverQuest__GetDeityDesc                                   0x4E7F10
#define CEverQuest__GetLangDesc                                    0x4E7C30
#define CEverQuest__GetRaceDesc                                    0x4E7EE0
#define CEverQuest__InterpretCmd                                   0x4F1A80
#define CEverQuest__LeftClickedOnPlayer                            0x504570
#define CEverQuest__LMouseUp                                       0x5080F0
#define CEverQuest__RightClickedOnPlayer                           0x509250
#define CEverQuest__RMouseUp                                       0x50A3D0
#define CEverQuest__SetGameState                                   0x4EAEC0
#define CEverQuest__Emote                                          0x4F1090

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5FB720
#define CGaugeWnd__CalcLinesFillRect                               0x5FB780
#define CGaugeWnd__Draw                                            0x5FBBD0

// CGuild
#define CGuild__FindMemberByName                                   0x41B8D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x614900

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x620330
#define CInvSlotMgr__MoveItem                                      0x620740

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x61F7E0
#define CInvSlot__SliderComplete                                   0x61DBD0
#define CInvSlot__GetItemBase                                      0x61D330

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x621520

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6BA780
#define CItemDisplayWnd__UpdateStrings                             0x622410

// CLabel 
#define CLabel__Draw                                               0x636840

// CListWnd 
#define CListWnd__AddColumn                                        0x768700
#define CListWnd__AddColumn1                                       0x767DC0
#define CListWnd__AddLine                                          0x767920
#define CListWnd__AddString                                        0x767AC0
#define CListWnd__CalculateFirstVisibleLine                        0x763C60
#define CListWnd__CalculateVSBRange                                0x765F70
#define CListWnd__ClearAllSel                                      0x7631C0
#define CListWnd__CloseAndUpdateEditWindow                         0x766F90
#define CListWnd__Compare                                          0x764640
#define CListWnd__Draw                                             0x765BB0
#define CListWnd__DrawColumnSeparators                             0x765A20
#define CListWnd__DrawHeader                                       0x763450
#define CListWnd__DrawItem                                         0x765040
#define CListWnd__DrawLine                                         0x7656A0
#define CListWnd__DrawSeparator                                    0x765AC0
#define CListWnd__EnsureVisible                                    0x763DB0
#define CListWnd__ExtendSel                                        0x764F60
#define CListWnd__GetColumnMinWidth                                0x762E90
#define CListWnd__GetColumnWidth                                   0x762DD0
#define CListWnd__GetCurSel                                        0x762640
#define CListWnd__GetHeaderRect                                    0x7627B0
#define CListWnd__GetItemAtPoint                                   0x764070
#define CListWnd__GetItemAtPoint1                                  0x7640E0
#define CListWnd__GetItemData                                      0x7629D0
#define CListWnd__GetItemHeight                                    0x7638E0
#define CListWnd__GetItemIcon                                      0x762BB0
#define CListWnd__GetItemRect                                      0x763E70
#define CListWnd__GetItemText                                      0x762A60
#define CListWnd__GetSelList                                       0x767CA0
#define CListWnd__GetSeparatorRect                                 0x764590
#define CListWnd__RemoveLine                                       0x767C50
#define CListWnd__SetColors                                        0x762710
#define CListWnd__SetColumnJustification                           0x763030
#define CListWnd__SetColumnWidth                                   0x762E50
#define CListWnd__SetCurSel                                        0x762680
#define CListWnd__SetItemColor                                     0x766C50
#define CListWnd__SetItemData                                      0x763260
#define CListWnd__SetItemText                                      0x766A30
#define CListWnd__ShiftColumnSeparator                             0x7668A0
#define CListWnd__Sort                                             0x768E40
#define CListWnd__ToggleSel                                        0x763130

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x64C820

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x65FBA0
#define CMerchantWnd__RequestBuyItem                               0x6634F0
#define CMerchantWnd__RequestSellItem                              0x6838B0
#define CMerchantWnd__SelectBuySellSlot                            0x661130

// CObfuscator
#define CObfuscator__doit                                          0x6F8D00

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7817E0
#define CSidlManager__CreateLabel                                  0x6B3610

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5B9DC0
#define CSidlScreenWnd__CalculateVSBRange                          0x5B9CF0
#define CSidlScreenWnd__ConvertToRes                               0x7938C0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x772050
#define CSidlScreenWnd__CSidlScreenWnd1                            0x773170
#define CSidlScreenWnd__CSidlScreenWnd2                            0x773220
#define CSidlScreenWnd__dCSidlScreenWnd                            0x772990
#define CSidlScreenWnd__DrawSidlPiece                              0x771B20
#define CSidlScreenWnd__EnableIniStorage                           0x771310
#define CSidlScreenWnd__GetSidlPiece                               0x771D30
#define CSidlScreenWnd__Init1                                      0x772FD0
#define CSidlScreenWnd__LoadIniInfo                                0x772100
#define CSidlScreenWnd__LoadIniListWnd                             0x771460
#define CSidlScreenWnd__LoadSidlScreen                             0x772BE0
#define CSidlScreenWnd__StoreIniInfo                               0x770F10
#define CSidlScreenWnd__StoreIniVis                                0x7712A0
#define CSidlScreenWnd__WndNotification                            0x772DC0
#define CSidlScreenWnd__GetChildItem                               0x771370

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x56CFC0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7943B0
#define CSliderWnd__SetValue                                       0x7944B0
#define CSliderWnd__SetNumTicks                                    0x794A60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6B8390

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x790F50
#define CStmlWnd__CalculateHSBRange                                0x7885B0
#define CStmlWnd__CalculateVSBRange                                0x788630
#define CStmlWnd__CanBreakAtCharacter                              0x7887B0
#define CStmlWnd__FastForwardToEndOfTag                            0x7894E0
#define CStmlWnd__ForceParseNow                                    0x791480
#define CStmlWnd__GetNextTagPiece                                  0x789400
#define CStmlWnd__GetSTMLText                                      0x5E48B0
#define CStmlWnd__GetThisChar                                      0x7B8F60
#define CStmlWnd__GetVisiableText                                  0x78A920
#define CStmlWnd__InitializeWindowVariables                        0x78CEF0
#define CStmlWnd__MakeStmlColorTag                                 0x7874D0
#define CStmlWnd__MakeWndNotificationTag                           0x787570
#define CStmlWnd__SetSTMLText                                      0x78D010
#define CStmlWnd__StripFirstSTMLLines                              0x790C00
#define CStmlWnd__UpdateHistoryString                              0x78B1B0

// CTabWnd 
#define CTabWnd__Draw                                              0x795960
#define CTabWnd__DrawCurrentPage                                   0x795230
#define CTabWnd__DrawTab                                           0x795010
#define CTabWnd__GetCurrentPage                                    0x7955F0
#define CTabWnd__GetPageClientRect                                 0x794CC0
#define CTabWnd__GetPageFromTabIndex                               0x794F40
#define CTabWnd__GetPageInnerRect                                  0x794D20
#define CTabWnd__GetTabInnerRect                                   0x794EC0
#define CTabWnd__GetTabRect                                        0x794DB0
#define CTabWnd__InsertPage                                        0x795BF0
#define CTabWnd__SetPage                                           0x795630
#define CTabWnd__SetPageRect                                       0x795890
#define CTabWnd__UpdatePage                                        0x795B70

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417EA0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7735A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7967F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x761540

// CXRect 
#define CXRect__CenterPoint                                        0x535620

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x522000
#define CXStr__CXStr1                                              0x75B0E0
#define CXStr__CXStr3                                              0x7BD530
#define CXStr__dCXStr                                              0x4601F0
#define CXStr__operator_equal                                      0x7BD6A0
#define CXStr__operator_equal1                                     0x7BD6F0
#define CXStr__operator_plus_equal1                                0x7BE780

// CXWnd 
#define CXWnd__BringToTop                                          0x769440
#define CXWnd__Center                                              0x76E430
#define CXWnd__ClrFocus                                            0x769250
#define CXWnd__DoAllDrawing                                        0x76ED50
#define CXWnd__DrawChildren                                        0x76EE90
#define CXWnd__DrawColoredRect                                     0x769720
#define CXWnd__DrawTooltip                                         0x76E360
#define CXWnd__DrawTooltipAtPoint                                  0x76DA40
#define CXWnd__GetBorderFrame                                      0x769C10
#define CXWnd__GetChildWndAt                                       0x76CF00
#define CXWnd__GetClientClipRect                                   0x7699E0
#define CXWnd__GetScreenClipRect                                   0x76DF70
#define CXWnd__GetScreenRect                                       0x769D50
#define CXWnd__GetTooltipRect                                      0x769830
#define CXWnd__GetWindowTextA                                      0x5AB030
#define CXWnd__IsActive                                            0x7746D0
#define CXWnd__IsDescendantOf                                      0x769B40
#define CXWnd__IsReallyVisible                                     0x76CEE0
#define CXWnd__IsType                                              0x799650
#define CXWnd__Move                                                0x76C3A0
#define CXWnd__Move1                                               0x76C460
#define CXWnd__ProcessTransition                                   0x7693F0
#define CXWnd__Refade                                              0x769360
#define CXWnd__Resize                                              0x769E10
#define CXWnd__Right                                               0x76DE80
#define CXWnd__SetFocus                                            0x76B5D0
#define CXWnd__SetKeyTooltip                                       0x76A060
#define CXWnd__SetMouseOver                                        0x76E250
#define CXWnd__StartFade                                           0x769480
#define CXWnd__GetChildItem                                        0x76E1C0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x775CC0
#define CXWndManager__DrawWindows                                  0x775940
#define CXWndManager__GetKeyboardFlags                             0x774330
#define CXWndManager__HandleKeyboardMsg                            0x7749A0
#define CXWndManager__RemoveWnd                                    0x7747F0

// CDBStr
#define CDBStr__GetString                                          0x46C180

// EQ_Character 
#define EQ_Character__CastRay                                      0x7167D0
#define EQ_Character__CastSpell                                    0x4301D0
#define EQ_Character__Cur_HP                                       0x438FF0
#define EQ_Character__GetAACastingTimeModifier                     0x425210
#define EQ_Character__GetCharInfo2                                 0x715570
#define EQ_Character__GetFocusCastingTimeModifier                  0x420980
#define EQ_Character__GetFocusRangeModifier                        0x420B50
#define EQ_Character__Max_Endurance                                0x53D6D0
#define EQ_Character__Max_HP                                       0x433FB0
#define EQ_Character__Max_Mana                                     0x53D4D0
#define EQ_Character__doCombatAbility                              0x53C350
#define EQ_Character__UseSkill                                     0x447880
#define EQ_Character__GetConLevel                                  0x5374F0
#define EQ_Character__IsExpansionFlag                              0x40D8A0
#define EQ_Character__TotalEffect                                  0x429750

// EQ_Item 
#define EQ_Item__CanDrop                                           0x51BF60
#define EQ_Item__CreateItemTagString                               0x703FA0
#define EQ_Item__IsStackable                                       0x6F9380

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x485020
#define EQ_LoadingS__Array                                         0x949468

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x540C00
#define EQ_PC__GetAltAbilityIndex                                  0x70A4F0
#define EQ_PC__GetCombatAbility                                    0x70A580
#define EQ_PC__GetCombatAbilityTimer                               0x70A630
#define EQ_PC__GetItemTimerValue                                   0x53C170
#define EQ_PC__HasLoreItem                                         0x7140C0

// EQItemList 
#define EQItemList__EQItemList                                     0x4B4800
#define EQItemList__add_item                                       0x4B4790
#define EQItemList__delete_item                                    0x4B4BB0
#define EQItemList__FreeItemList                                   0x4B4AE0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46B970

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5457E0
#define EQPlayer__dEQPlayer                                        0x54A2D0
#define EQPlayer__DoAttack                                         0x55B100
#define EQPlayer__EQPlayer                                         0x54FB80
#define EQPlayer__SetNameSpriteState                               0x547C50
#define EQPlayer__SetNameSpriteTint                                0x545850
#define EQPlayer__IsBodyType_j                                     0x716090
#define EQPlayer__IsTargetable                                     0x716350

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x550E50
#define EQPlayerManager__GetSpawnByName                            0x5510E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x521A20
#define KeypressHandler__AttachKeyToEqCommand                      0x521A60
#define KeypressHandler__ClearCommandStateArray                    0x521830
#define KeypressHandler__HandleKeyDown                             0x520230
#define KeypressHandler__HandleKeyUp                               0x520540
#define KeypressHandler__SaveKeymapping                            0x521900

// MapViewMap 
#define MapViewMap__Clear                                          0x647EA0
#define MapViewMap__SaveEx                                         0x648870

#define PlayerPointManager__GetAltCurrency                         0x705130

// StringTable 
#define StringTable__getString                                     0x6F8F80

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x53F390
