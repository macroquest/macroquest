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
#define __ExpectedVersionDate                                     "Nov  9 2010"
#define __ExpectedVersionTime                                     "15:35:53"
#define __ActualVersionDate                                        0x87A8F0
#define __ActualVersionTime                                        0x87A8FC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x525280
#define __MemChecker1                                              0x7972D0
#define __MemChecker2                                              0x5965E0
#define __MemChecker3                                              0x596530
#define __MemChecker4                                              0x7B1330
#define __EncryptPad0                                              0x910538
#define __EncryptPad1                                              0x91C1F8
#define __EncryptPad2                                              0x9132A0
#define __EncryptPad3                                              0x912EA0
#define __EncryptPad4                                              0x91DC28
#define __AC1                                                      0x6A4B50
#define __AC2                                                      0x4E81C5
#define __AC3                                                      0x4FAB38
#define __AC4                                                      0x4FFE68
#define __AC5                                                      0x50C00E
#define __AC6                                                      0x50F75E
#define __AC7                                                      0x507BDB
#define __AC1_Data                                                 0x861ADD

// Direct Input
#define DI8__Main                                                  0xB7A2E4
#define DI8__Keyboard                                              0xB7A2E8
#define DI8__Mouse                                                 0xB7A2EC
#define __AltTimerReady                                            0xAFEA4A
#define __Attack                                                   0xB6252E
#define __Autofire                                                 0xB6252F
#define __BindList                                                 0x90AB10
#define __Clicks                                                   0xAFD700
#define __CommandList                                              0x90B4F0
#define __CurrentMapLabel                                          0xBA5580
#define __CurrentSocial                                            0x906978
#define __DoAbilityAvailable                                       0xAFE9E4
#define __DoAbilityList                                            0xB3444C
#define __do_loot                                                  0x4BD2C0
#define __DrawHandler                                              0x115985C
#define __GroupCount                                               0xAF74F2
#define __Guilds                                                   0xAFCAE0
#define __gWorld                                                   0xAF93AC
#define __HotkeyPage                                               0xB5B838
#define __HWnd                                                     0xB7A020
#define __InChatMode                                               0xAFD638
#define __LastTell                                                 0xAFF364
#define __LMouseHeldTime                                           0xAFD76C
#define __Mouse                                                    0xB7A2F0
#define __MouseLook                                                0xAFD6CE
#define __MouseEventTime                                           0xB62690
#define __NetStatusToggle                                          0xAFD6D1
#define __PCNames                                                  0xAFEDA8
#define __RangeAttackReady                                         0xAFEA48
#define __RMouseHeldTime                                           0xAFD768
#define __RunWalkState                                             0xAFD63C
#define __ScreenMode                                               0xA46D40
#define __ScreenX                                                  0xAFD5F0
#define __ScreenY                                                  0xAFD5F4
#define __ScreenXMax                                               0xAFD5F8
#define __ScreenYMax                                               0xAFD5FC
#define __ServerHost                                               0xAF7434
#define __ServerName                                               0xB3440C
#define __ShiftKeyDown                                             0xAFDCFC
#define __ShowNames                                                0xAFEC7C
#define __Socials                                                  0xB3450C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xAF9478
#define instEQZoneInfo                                             0xAFD8B8
#define instKeypressHandler                                        0xB62674
#define pinstActiveBanker                                          0xAF9450
#define pinstActiveCorpse                                          0xAF9454
#define pinstActiveGMaster                                         0xAF9458
#define pinstActiveMerchant                                        0xAF944C
#define pinstAltAdvManager                                         0xA47BD8
#define pinstAuraMgr                                               0x9305FC
#define pinstBandageTarget                                         0xAF9438
#define pinstCamActor                                              0xA476C4
#define pinstCDBStr                                                0xA46D34
#define pinstCDisplay                                              0xAF9460
#define pinstCEverQuest                                            0xB7A468
#define pinstCharData                                              0xAF941C
#define pinstCharSpawn                                             0xAF9444
#define pinstControlledMissile                                     0xAF9418
#define pinstControlledPlayer                                      0xAF9444
#define pinstCSidlManager                                          0x1159D2C
#define pinstCXWndManager                                          0x1159D24
#define instDynamicZone                                            0xAFD4C0
#define pinstDZMember                                              0xAFD5D0
#define pinstDZTimerInfo                                           0xAFD5D4
#define pinstEQItemList                                            0xAF6704
#define instEQMisc                                                 0xA46CE0
#define pinstEQSoundManager                                        0xA47BFC
#define instExpeditionLeader                                       0xAFD50A
#define instExpeditionName                                         0xAFD54A
#define pinstGroup                                                 0xAF74EE
#define pinstImeManager                                            0x1159D30
#define pinstLocalPlayer                                           0xAF9430
#define pinstMercenaryData                                         0xB62A04
#define pinstModelPlayer                                           0xAF945C
#define pinstPCData                                                0xAF941C
#define pinstSkillMgr                                              0xB770D4
#define pinstSpawnManager                                          0xB76EF0
#define pinstSpellManager                                          0xB770E0
#define pinstSpellSets                                             0xB5B83C
#define pinstStringTable                                           0xAF93C8
#define pinstSwitchManager                                         0xAF7134
#define pinstTarget                                                0xAF9448
#define pinstTargetObject                                          0xAF9420
#define pinstTargetSwitch                                          0xAF9424
#define pinstTaskMember                                            0xA46CC0
#define pinstTrackTarget                                           0xAF943C
#define pinstTradeTarget                                           0xAF942C
#define instTributeActive                                          0xA46D05
#define pinstViewActor                                             0xA476C0
#define pinstWorldData                                             0xAF9400


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x92DEC0
#define pinstCAudioTriggersWindow                                  0x92DE8C
#define pinstCCharacterSelect                                      0xA475A8
#define pinstCFacePick                                             0xA47558
#define pinstCNoteWnd                                              0xA47560
#define pinstCBookWnd                                              0xA47564
#define pinstCPetInfoWnd                                           0xA47568
#define pinstCTrainWnd                                             0xA4756C
#define pinstCSkillsWnd                                            0xA47570
#define pinstCSkillsSelectWnd                                      0xA47574
#define pinstCCombatSkillSelectWnd                                 0xA47578
#define pinstCFriendsWnd                                           0xA4757C
#define pinstCAuraWnd                                              0xA47580
#define pinstCRespawnWnd                                           0xA47584
#define pinstCBandolierWnd                                         0xA47588
#define pinstCPotionBeltWnd                                        0xA4758C
#define pinstCAAWnd                                                0xA47590
#define pinstCGroupSearchFiltersWnd                                0xA47594
#define pinstCLoadskinWnd                                          0xA47598
#define pinstCAlarmWnd                                             0xA4759C
#define pinstCMusicPlayerWnd                                       0xA475A0
#define pinstCMailWnd                                              0xA475AC
#define pinstCMailCompositionWnd                                   0xA475B0
#define pinstCMailAddressBookWnd                                   0xA475B4
#define pinstCRaidWnd                                              0xA475BC
#define pinstCRaidOptionsWnd                                       0xA475C0
#define pinstCBreathWnd                                            0xA475C4
#define pinstCMapViewWnd                                           0xA475C8
#define pinstCMapToolbarWnd                                        0xA475CC
#define pinstCEditLabelWnd                                         0xA475D0
#define pinstCTargetWnd                                            0xA475D4
#define pinstCColorPickerWnd                                       0xA475D8
#define pinstCPlayerWnd                                            0xA475DC
#define pinstCOptionsWnd                                           0xA475E0
#define pinstCBuffWindowNORMAL                                     0xA475E4
#define pinstCBuffWindowSHORT                                      0xA475E8
#define pinstCharacterCreation                                     0xA475EC
#define pinstCCursorAttachment                                     0xA475F0
#define pinstCCastingWnd                                           0xA475F4
#define pinstCCastSpellWnd                                         0xA475F8
#define pinstCSpellBookWnd                                         0xA475FC
#define pinstCInventoryWnd                                         0xA47600
#define pinstCBankWnd                                              0xA47604
#define pinstCQuantityWnd                                          0xA47608
#define pinstCLootWnd                                              0xA4760C
#define pinstCActionsWnd                                           0xA47610
#define pinstCCombatAbilityWnd                                     0xA47614
#define pinstCMerchantWnd                                          0xA47618
#define pinstCTradeWnd                                             0xA4761C
#define pinstCSelectorWnd                                          0xA47620
#define pinstCBazaarWnd                                            0xA47624
#define pinstCBazaarSearchWnd                                      0xA47628
#define pinstCGiveWnd                                              0xA47640
#define pinstCTrackingWnd                                          0xA47644
#define pinstCInspectWnd                                           0xA47648
#define pinstCSocialEditWnd                                        0xA4764C
#define pinstCFeedbackWnd                                          0xA47650
#define pinstCBugReportWnd                                         0xA47654
#define pinstCVideoModesWnd                                        0xA47658
#define pinstCTextEntryWnd                                         0xA47660
#define pinstCFileSelectionWnd                                     0xA47664
#define pinstCCompassWnd                                           0xA47668
#define pinstCPlayerNotesWnd                                       0xA4766C
#define pinstCGemsGameWnd                                          0xA47670
#define pinstCTimeLeftWnd                                          0xA47674
#define pinstCPetitionQWnd                                         0xA47688
#define pinstCSoulmarkWnd                                          0xA4768C
#define pinstCStoryWnd                                             0xA47690
#define pinstCJournalTextWnd                                       0xA47694
#define pinstCJournalCatWnd                                        0xA47698
#define pinstCBodyTintWnd                                          0xA4769C
#define pinstCServerListWnd                                        0xA476A0
#define pinstCAvaZoneWnd                                           0xA476A8
#define pinstCBlockedBuffWnd                                       0xA476AC
#define pinstCBlockedPetBuffWnd                                    0xA476B0
#define pinstCInvSlotMgr                                           0xA476B8
#define pinstCContainerMgr                                         0xA476BC
#define pinstCAdventureLeaderboardWnd                              0xBA2A98
#define pinstCAdventureRequestWnd                                  0xBA2AB4
#define pinstCAltStorageWnd                                        0xBA2B14
#define pinstCAdventureStatsWnd                                    0xBA2AD0
#define pinstCBarterMerchantWnd                                    0xBA2CE0
#define pinstCBarterSearchWnd                                      0xBA2CFC
#define pinstCBarterWnd                                            0xBA2D18
#define pinstCChatManager                                          0xBA2FBC
#define pinstCDynamicZoneWnd                                       0xBA30B4
#define pinstCEQMainWnd                                            0xBA3128
#define pinstCFellowshipWnd                                        0xBA318C
#define pinstCFindLocationWnd                                      0xBA31C0
#define pinstCGroupSearchWnd                                       0xBA3270
#define pinstCGroupWnd                                             0xBA328C
#define pinstCGuildBankWnd                                         0xBA32A8
#define pinstCGuildMgmtWnd                                         0xBA52E0
#define pinstCGuildTributeMasterWnd                                0xBA5300
#define pinstCHotButtonWnd                                         0xBA5334
#define pinstCHotButtonWnd1                                        0xBA5334
#define pinstCHotButtonWnd2                                        0xBA5338
#define pinstCHotButtonWnd3                                        0xBA533C
#define pinstCHotButtonWnd4                                        0xBA5340
#define pinstCItemDisplayManager                                   0xBA53EC
#define pinstCItemExpTransferWnd                                   0xBA540C
#define pinstCLeadershipWnd                                        0xBA54A8
#define pinstCLFGuildWnd                                           0xBA54C4
#define pinstCMIZoneSelectWnd                                      0xBA5634
#define pinstCAdventureMerchantWnd                                 0xBA575C
#define pinstCConfirmationDialog                                   0xBA5778
#define pinstCPopupWndManager                                      0xBA5778
#define pinstCProgressionSelectionWnd                              0xBA57AC
#define pinstCPvPLeaderboardWnd                                    0xBA57C8
#define pinstCPvPStatsWnd                                          0xBA57E4
#define pinstCSystemInfoDialogBox                                  0xBA5928
#define pinstCTargetOfTargetWnd                                    0xBA6430
#define pinstCTaskSelectWnd                                        0xBA6464
#define pinstCTaskTemplateSelectWnd                                0xBA6480
#define pinstCTaskWnd                                              0xBA649C
#define pinstCTipWndOFDAY                                          0xBA6518
#define pinstCTipWndCONTEXT                                        0xBA651C
#define pinstCTitleWnd                                             0xBA6538
#define pinstCTradeskillWnd                                        0xBA657C
#define pinstCTributeBenefitWnd                                    0xBA65C8
#define pinstCTributeMasterWnd                                     0xBA65E4
#define pinstCContextMenuManager                                   0x1159D88
#define pinstCVoiceMacroWnd                                        0xB772D4
#define pinstCHtmlWnd                                              0xB77320


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D0F30
#define __ConvertItemTags                                          0x4C2940
#define __ExecuteCmd                                               0x4AE6E0
#define __get_melee_range                                          0x4B46F0
#define __GetGaugeValueFromEQ                                      0x6A39D0
#define __GetLabelFromEQ                                           0x6A4AF0
#define __GetXTargetType                                           0x7171A0
#define __LoadFrontEnd                                             0x595510
#define __NewUIINI                                                 0x6A34F0
#define __ProcessGameEvents                                        0x508350
#define CrashDetected                                              0x595310
#define DrawNetStatus                                              0x531990
#define Util__FastTime                                             0x797A80


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483BE0
#define AltAdvManager__IsAbilityReady                              0x483C20
#define AltAdvManager__GetAltAbility                               0x483EF0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x439110

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5B2EE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5BCE80

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x75E230

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5D4EE0
#define CChatManager__InitContextMenu                              0x5D56B0

// CChatService
#define CChatService__GetNumberOfFriends                           0x70C700
#define CChatService__GetFriendName                                0x70C710

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5D9980
#define CChatWindow__Clear                                         0x5DA2E0
#define CChatWindow__WndNotification                               0x5DA4D0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7481E0
#define CComboWnd__Draw                                            0x7483A0
#define CComboWnd__GetCurChoice                                    0x7480A0
#define CComboWnd__GetListRect                                     0x748690
#define CComboWnd__GetTextRect                                     0x748210
#define CComboWnd__InsertChoice                                    0x748700
#define CComboWnd__SetColors                                       0x748030
#define CComboWnd__SetChoice                                       0x748060

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5E3650
#define CContainerWnd__vftable                                     0x881FF0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x4764D0
#define CDisplay__GetClickedActor                                  0x46F350
#define CDisplay__GetUserDefinedColor                              0x46DE10
#define CDisplay__GetWorldFilePath                                 0x46D2A0
#define CDisplay__is3dON                                           0x46C3D0
#define CDisplay__ReloadUI                                         0x480D60
#define CDisplay__WriteTextHD2                                     0x472260

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5ACFE0
#define CEditBaseWnd__SetSel                                       0x76B840

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x751260
#define CEditWnd__GetCharIndexPt                                   0x752220
#define CEditWnd__GetDisplayString                                 0x7513F0
#define CEditWnd__GetHorzOffset                                    0x751680
#define CEditWnd__GetLineForPrintableChar                          0x751CD0
#define CEditWnd__GetSelStartPt                                    0x752470
#define CEditWnd__GetSTMLSafeText                                  0x751820
#define CEditWnd__PointFromPrintableChar                           0x751DE0
#define CEditWnd__SelectableCharFromPoint                          0x751F60
#define CEditWnd__SetEditable                                      0x7517F0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4E88F0
#define CEverQuest__DropHeldItemOnGround                           0x4F5F20
#define CEverQuest__dsp_chat                                       0x4EECA0
#define CEverQuest__DoTellWindow                                   0x4ED470
#define CEverQuest__EnterZone                                      0x4FFE00
#define CEverQuest__GetBodyTypeDesc                                0x4E5760
#define CEverQuest__GetClassDesc                                   0x4E4FA0
#define CEverQuest__GetClassThreeLetterCode                        0x4E55A0
#define CEverQuest__GetDeityDesc                                   0x4E5DD0
#define CEverQuest__GetLangDesc                                    0x4E5AF0
#define CEverQuest__GetRaceDesc                                    0x4E5DA0
#define CEverQuest__InterpretCmd                                   0x4EF800
#define CEverQuest__LeftClickedOnPlayer                            0x501F50
#define CEverQuest__LMouseUp                                       0x5058E0
#define CEverQuest__RightClickedOnPlayer                           0x506A30
#define CEverQuest__RMouseUp                                       0x507BA0
#define CEverQuest__SetGameState                                   0x4E8D80
#define CEverQuest__Emote                                          0x4EEEC0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5F0560
#define CGaugeWnd__CalcLinesFillRect                               0x5F05C0
#define CGaugeWnd__Draw                                            0x5F0A10

// CGuild
#define CGuild__FindMemberByName                                   0x41B9A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x6097D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x614BE0
#define CInvSlotMgr__MoveItem                                      0x614FF0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x614080
#define CInvSlot__SliderComplete                                   0x612A50
#define CInvSlot__GetItemBase                                      0x6121B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x615CF0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6A1280
#define CItemDisplayWnd__UpdateStrings                             0x616BC0

// CLabel 
#define CLabel__Draw                                               0x62ADC0

// CListWnd 
#define CListWnd__AddColumn                                        0x740EA0
#define CListWnd__AddColumn1                                       0x740510
#define CListWnd__AddLine                                          0x7400C0
#define CListWnd__AddString                                        0x740260
#define CListWnd__CalculateFirstVisibleLine                        0x73C3D0
#define CListWnd__CalculateVSBRange                                0x73E700
#define CListWnd__ClearAllSel                                      0x73B920
#define CListWnd__CloseAndUpdateEditWindow                         0x73F730
#define CListWnd__Compare                                          0x73CDD0
#define CListWnd__Draw                                             0x73E340
#define CListWnd__DrawColumnSeparators                             0x73E1B0
#define CListWnd__DrawHeader                                       0x73BBB0
#define CListWnd__DrawItem                                         0x73D7D0
#define CListWnd__DrawLine                                         0x73DE30
#define CListWnd__DrawSeparator                                    0x73E250
#define CListWnd__EnsureVisible                                    0x73C530
#define CListWnd__ExtendSel                                        0x73D6F0
#define CListWnd__GetColumnMinWidth                                0x73B5F0
#define CListWnd__GetColumnWidth                                   0x73B530
#define CListWnd__GetCurSel                                        0x73AD80
#define CListWnd__GetHeaderRect                                    0x73AEE0
#define CListWnd__GetItemAtPoint                                   0x73C800
#define CListWnd__GetItemAtPoint1                                  0x73C870
#define CListWnd__GetItemData                                      0x73B130
#define CListWnd__GetItemHeight                                    0x73C040
#define CListWnd__GetItemIcon                                      0x73B310
#define CListWnd__GetItemRect                                      0x73C600
#define CListWnd__GetItemText                                      0x73B1C0
#define CListWnd__GetSelList                                       0x7403F0
#define CListWnd__GetSeparatorRect                                 0x73CD20
#define CListWnd__RemoveLine                                       0x740E50
#define CListWnd__SetColors                                        0x73AE50
#define CListWnd__SetColumnJustification                           0x73B790
#define CListWnd__SetColumnWidth                                   0x73B5B0
#define CListWnd__SetCurSel                                        0x73ADC0
#define CListWnd__SetItemColor                                     0x73F3F0
#define CListWnd__SetItemData                                      0x73B9C0
#define CListWnd__SetItemText                                      0x73F1D0
#define CListWnd__ShiftColumnSeparator                             0x73F040
#define CListWnd__Sort                                             0x7415E0
#define CListWnd__ToggleSel                                        0x73B890

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x640D10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x651B00
#define CMerchantWnd__RequestBuyItem                               0x6553C0
#define CMerchantWnd__RequestSellItem                              0x6742F0
#define CMerchantWnd__SelectBuySellSlot                            0x652E20

// CObfuscator
#define CObfuscator__doit                                          0x6DC480

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x759A50
#define CSidlManager__CreateLabel                                  0x69A0E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x749ED0
#define CSidlScreenWnd__CalculateVSBRange                          0x5AF0A0
#define CSidlScreenWnd__ConvertToRes                               0x76B720
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x74A390
#define CSidlScreenWnd__CSidlScreenWnd1                            0x74B480
#define CSidlScreenWnd__CSidlScreenWnd2                            0x74B530
#define CSidlScreenWnd__dCSidlScreenWnd                            0x74AC40
#define CSidlScreenWnd__DrawSidlPiece                              0x74A050
#define CSidlScreenWnd__EnableIniStorage                           0x749A50
#define CSidlScreenWnd__GetSidlPiece                               0x74A260
#define CSidlScreenWnd__Init1                                      0x74B2E0
#define CSidlScreenWnd__LoadIniInfo                                0x74A440
#define CSidlScreenWnd__LoadIniListWnd                             0x749BA0
#define CSidlScreenWnd__LoadSidlScreen                             0x74AE90
#define CSidlScreenWnd__StoreIniInfo                               0x749650
#define CSidlScreenWnd__StoreIniVis                                0x7499E0
#define CSidlScreenWnd__WndNotification                            0x74B060
#define CSidlScreenWnd__GetChildItem                               0x749AB0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x562EA0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x76C110
#define CSliderWnd__SetValue                                       0x76C210
#define CSliderWnd__SetNumTicks                                    0x76C7C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x69EE70

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x768DB0
#define CStmlWnd__CalculateHSBRange                                0x7604C0
#define CStmlWnd__CalculateVSBRange                                0x760430
#define CStmlWnd__CanBreakAtCharacter                              0x760630
#define CStmlWnd__FastForwardToEndOfTag                            0x761310
#define CStmlWnd__ForceParseNow                                    0x7692E0
#define CStmlWnd__GetNextTagPiece                                  0x761230
#define CStmlWnd__GetSTMLText                                      0x5D9920
#define CStmlWnd__GetThisChar                                      0x790720
#define CStmlWnd__GetVisiableText                                  0x762760
#define CStmlWnd__InitializeWindowVariables                        0x764D30
#define CStmlWnd__MakeStmlColorTag                                 0x75F350
#define CStmlWnd__MakeWndNotificationTag                           0x75F3F0
#define CStmlWnd__SetSTMLText                                      0x764E50
#define CStmlWnd__StripFirstSTMLLines                              0x768A60
#define CStmlWnd__UpdateHistoryString                              0x762FF0

// CTabWnd 
#define CTabWnd__Draw                                              0x76D630
#define CTabWnd__DrawCurrentPage                                   0x76CF90
#define CTabWnd__DrawTab                                           0x76CD70
#define CTabWnd__GetCurrentPage                                    0x76D2D0
#define CTabWnd__GetPageClientRect                                 0x76CA20
#define CTabWnd__GetPageFromTabIndex                               0x76CCA0
#define CTabWnd__GetPageInnerRect                                  0x76CA80
#define CTabWnd__GetTabInnerRect                                   0x76CC20
#define CTabWnd__GetTabRect                                        0x76CB10
#define CTabWnd__InsertPage                                        0x76D8C0
#define CTabWnd__SetPage                                           0x76D310
#define CTabWnd__SetPageRect                                       0x76D560
#define CTabWnd__UpdatePage                                        0x76D840

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417F50

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x74B8B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x76E4D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x739C80

// CXRect 
#define CXRect__CenterPoint                                        0x5B2770

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x51EAF0
#define CXStr__CXStr1                                              0x401410
#define CXStr__CXStr3                                              0x794CE0
#define CXStr__dCXStr                                              0x470500
#define CXStr__operator_equal1                                     0x794EA0
#define CXStr__operator_plus_equal1                                0x795F30

// CXWnd 
#define CXWnd__BringToTop                                          0x741BD0
#define CXWnd__Center                                              0x746A60
#define CXWnd__ClrFocus                                            0x7419F0
#define CXWnd__DoAllDrawing                                        0x7473E0
#define CXWnd__DrawChildren                                        0x747530
#define CXWnd__DrawColoredRect                                     0x741EC0
#define CXWnd__DrawTooltip                                         0x746990
#define CXWnd__DrawTooltipAtPoint                                  0x745C90
#define CXWnd__GetBorderFrame                                      0x742370
#define CXWnd__GetChildWndAt                                       0x745110
#define CXWnd__GetClientClipRect                                   0x742180
#define CXWnd__GetScreenClipRect                                   0x746150
#define CXWnd__GetScreenRect                                       0x742490
#define CXWnd__GetTooltipRect                                      0x741FD0
#define CXWnd__GetWindowTextA                                      0x5A0590
#define CXWnd__IsActive                                            0x74C9E0
#define CXWnd__IsDescendantOf                                      0x742260
#define CXWnd__IsReallyVisible                                     0x7450F0
#define CXWnd__IsType                                              0x7712D0
#define CXWnd__Move                                                0x744840
#define CXWnd__Move1                                               0x7466F0
#define CXWnd__ProcessTransition                                   0x741B80
#define CXWnd__Refade                                              0x741AF0
#define CXWnd__Resize                                              0x742560
#define CXWnd__Right                                               0x746060
#define CXWnd__SetFocus                                            0x743C50
#define CXWnd__SetKeyTooltip                                       0x742750
#define CXWnd__SetMouseOver                                        0x746440
#define CXWnd__StartFade                                           0x741C10
#define CXWnd__GetChildItem                                        0x7463B0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x74DFC0
#define CXWndManager__DrawWindows                                  0x74DC40
#define CXWndManager__GetKeyboardFlags                             0x74C640
#define CXWndManager__HandleKeyboardMsg                            0x74CCB0
#define CXWndManager__RemoveWnd                                    0x74CB00

// CDBStr
#define CDBStr__GetString                                          0x46ACA0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6FA4D0
#define EQ_Character__CastSpell                                    0x42FEF0
#define EQ_Character__Cur_HP                                       0x438DD0
#define EQ_Character__GetAACastingTimeModifier                     0x425300
#define EQ_Character__GetCharInfo2                                 0x6F9310
#define EQ_Character__GetFocusCastingTimeModifier                  0x420A00
#define EQ_Character__GetFocusRangeModifier                        0x420BE0
#define EQ_Character__Max_Endurance                                0x539850
#define EQ_Character__Max_HP                                       0x433B20
#define EQ_Character__Max_Mana                                     0x539680
#define EQ_Character__doCombatAbility                              0x5384E0
#define EQ_Character__UseSkill                                     0x447730
#define EQ_Character__GetConLevel                                  0x533D70

// EQ_Item 
#define EQ_Item__CanDrop                                           0x519630
#define EQ_Item__CreateItemTagString                               0x6E8B80
#define EQ_Item__IsStackable                                       0x6DCEF0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x484DC0
#define EQ_LoadingS__Array                                         0x908ED8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x53D3C0
#define EQ_PC__GetAltAbilityIndex                                  0x6EEE60
#define EQ_PC__GetCombatAbility                                    0x6EEEF0
#define EQ_PC__GetCombatAbilityTimer                               0x6EEFA0
#define EQ_PC__GetItemTimerValue                                   0x538310
#define EQ_PC__HasLoreItem                                         0x6F7E70

// EQItemList 
#define EQItemList__EQItemList                                     0x4B2920
#define EQItemList__add_item                                       0x4B28B0
#define EQItemList__delete_item                                    0x4B2CD0
#define EQItemList__FreeItemList                                   0x4B2C00

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46A4B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x541D50
#define EQPlayer__dEQPlayer                                        0x5466A0
#define EQPlayer__DoAttack                                         0x5571A0
#define EQPlayer__EQPlayer                                         0x54BEB0
#define EQPlayer__SetNameSpriteState                               0x544160
#define EQPlayer__SetNameSpriteTint                                0x541DC0
#define EQPlayer__IsBodyType_j                                     0x6F9DD0
#define EQPlayer__IsTargetable                                     0x6F9F70

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x54D150
#define EQPlayerManager__GetSpawnByName                            0x54D4F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x51E510
#define KeypressHandler__AttachKeyToEqCommand                      0x51E550
#define KeypressHandler__ClearCommandStateArray                    0x51E320
#define KeypressHandler__HandleKeyDown                             0x51CDB0
#define KeypressHandler__HandleKeyUp                               0x51D0C0
#define KeypressHandler__SaveKeymapping                            0x51E3F0

// MapViewMap 
#define MapViewMap__Clear                                          0x63C3B0
#define MapViewMap__SaveEx                                         0x63CD80

#define PlayerPointManager__GetAltCurrency                         0x6EA3C0

// StringTable 
#define StringTable__getString                                     0x6DC700