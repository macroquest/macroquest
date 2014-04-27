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
#define __ExpectedVersionDate                                     "Sep 14 2011"
#define __ExpectedVersionTime                                     "16:54:01"
#define __ActualVersionDate                                        0x8AFE5C
#define __ActualVersionTime                                        0x8AFE68

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x528A00
#define __MemChecker1                                              0x7C0150
#define __MemChecker2                                              0x5A1320
#define __MemChecker3                                              0x5A1270
#define __MemChecker4                                              0x7E1FD0
#define __EncryptPad0                                              0x951B50
#define __EncryptPad1                                              0x95DDB0
#define __EncryptPad2                                              0x9548E8
#define __EncryptPad3                                              0x9544E8
#define __EncryptPad4                                              0x95F858
#define __AC1                                                      0x6BE2C0
#define __AC2                                                      0x4EA485
#define __AC3                                                      0x4FCC58
#define __AC4                                                      0x502634
#define __AC5                                                      0x50E8FC
#define __AC6                                                      0x51205E
#define __AC7                                                      0x50A55B
#define __AC1_Data                                                 0x89639D
// Direct Input
#define DI8__Main                                                  0xBC23BC
#define DI8__Keyboard                                              0xBC23C0
#define DI8__Mouse                                                 0xBC23C4
#define __AltTimerReady                                            0xB5A7A6
#define __Attack                                                   0xBBE2C2
#define __Autofire                                                 0xBBE2C3
#define __BindList                                                 0x94C0A8
#define __Clicks                                                   0xB59450
#define __CommandList                                              0x94CA98
#define __CurrentMapLabel                                          0xBEE0C8
#define __CurrentSocial                                            0x9479D8
#define __DoAbilityAvailable                                       0xB5A740
#define __DoAbilityList                                            0xB901E0
#define __do_loot                                                  0x4BF0F0
#define __DrawHandler                                              0x1248AA4
#define __GroupCount                                               0xB52E22
#define __Guilds                                                   0xB551B0
#define __gWorld                                                   0xB550DC
#define __HotkeyPage                                               0xBB75CC
#define __HWnd                                                     0xBC20F8
#define __InChatMode                                               0xB59388
#define __LastTell                                                 0xB5B0F8
#define __LMouseHeldTime                                           0xB594BC
#define __Mouse                                                    0xBC23C8
#define __MouseLook                                                0xB5941E
#define __MouseEventTime                                           0xBBE574
#define __NetStatusToggle                                          0xB59421
#define __PCNames                                                  0xB5AB3C
#define __RangeAttackReady                                         0xB5A7A4
#define __RMouseHeldTime                                           0xB594B8
#define __RunWalkState                                             0xB5938C
#define __ScreenMode                                               0xAA2358
#define __ScreenX                                                  0xB59340
#define __ScreenY                                                  0xB59344
#define __ScreenXMax                                               0xB59348
#define __ScreenYMax                                               0xB5934C
#define __ServerHost                                               0xB52D64
#define __ServerName                                               0xB901A0
#define __ShiftKeyDown                                             0xB59A4C
#define __ShowNames                                                0xB5A9E0
#define __Socials                                                  0xB902A0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xB55CB8
#define instEQZoneInfo                                             0xB59608
#define instKeypressHandler                                        0xBBE570
#define pinstActiveBanker                                          0xB55184
#define pinstActiveCorpse                                          0xB55188
#define pinstActiveGMaster                                         0xB5518C
#define pinstActiveMerchant                                        0xB55180
#define pinstAltAdvManager                                         0xAA3280
#define pinstAuraMgr                                               0x9724F0
#define pinstBandageTarget                                         0xB5516C
#define pinstCamActor                                              0xAA2CF8
#define pinstCDBStr                                                0xAA2330
#define pinstCDisplay                                              0xB55194
#define pinstCEverQuest                                            0xBC2540
#define pinstCharData                                              0xB55150
#define pinstCharSpawn                                             0xB55178
#define pinstControlledMissile                                     0xB5514C
#define pinstControlledPlayer                                      0xB55178
#define pinstCSidlManager                                          0x1248F74
#define pinstCXWndManager                                          0x1248F6C
#define instDynamicZone                                            0xB55710
#define pinstDZMember                                              0xB55820
#define pinstDZTimerInfo                                           0xB55824
#define pinstEQItemList                                            0xB51EC8
#define instEQMisc                                                 0xAA22A8
#define pinstEQSoundManager                                        0xAA32F0
#define instExpeditionLeader                                       0xB5575A
#define instExpeditionName                                         0xB5579A
#define pinstGroup                                                 0xB52E1E
#define pinstImeManager                                            0x1248F78
#define pinstLocalPlayer                                           0xB55164
#define pinstMercenaryData                                         0xBBE9D8
#define pinstModelPlayer                                           0xB55190
#define pinstPCData                                                0xB55150
#define pinstSkillMgr                                              0xBBEFA0
#define pinstSpawnManager                                          0xBBEC38
#define pinstSpellManager                                          0xBBEFE0
#define pinstSpellSets                                             0xBB75D0
#define pinstStringTable                                           0xB550F8
#define pinstSwitchManager                                         0xB52A30
#define pinstTarget                                                0xB5517C
#define pinstTargetObject                                          0xB55154
#define pinstTargetSwitch                                          0xB55158
#define pinstTaskMember                                            0xAA2270
#define pinstTrackTarget                                           0xB55170
#define pinstTradeTarget                                           0xB55160
#define instTributeActive                                          0xAA22CD
#define pinstViewActor                                             0xAA2CF4
#define pinstWorldData                                             0xB55134


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x96FC50
#define pinstCAudioTriggersWindow                                  0x96FBE8
#define pinstCCharacterSelect                                      0xAA2BC8
#define pinstCFacePick                                             0xAA2B78
#define pinstCNoteWnd                                              0xAA2B80
#define pinstCBookWnd                                              0xAA2B84
#define pinstCPetInfoWnd                                           0xAA2B88
#define pinstCTrainWnd                                             0xAA2B8C
#define pinstCSkillsWnd                                            0xAA2B90
#define pinstCSkillsSelectWnd                                      0xAA2B94
#define pinstCCombatSkillSelectWnd                                 0xAA2B98
#define pinstCFriendsWnd                                           0xAA2B9C
#define pinstCAuraWnd                                              0xAA2BA0
#define pinstCRespawnWnd                                           0xAA2BA4
#define pinstCBandolierWnd                                         0xAA2BA8
#define pinstCPotionBeltWnd                                        0xAA2BAC
#define pinstCAAWnd                                                0xAA2BB0
#define pinstCGroupSearchFiltersWnd                                0xAA2BB4
#define pinstCLoadskinWnd                                          0xAA2BB8
#define pinstCAlarmWnd                                             0xAA2BBC
#define pinstCMusicPlayerWnd                                       0xAA2BC0
#define pinstCMailWnd                                              0xAA2BCC
#define pinstCMailCompositionWnd                                   0xAA2BD0
#define pinstCMailAddressBookWnd                                   0xAA2BD4
#define pinstCRaidWnd                                              0xAA2BDC
#define pinstCRaidOptionsWnd                                       0xAA2BE0
#define pinstCBreathWnd                                            0xAA2BE4
#define pinstCMapViewWnd                                           0xAA2BE8
#define pinstCMapToolbarWnd                                        0xAA2BEC
#define pinstCEditLabelWnd                                         0xAA2BF0
#define pinstCTargetWnd                                            0xAA2BF4
#define pinstCColorPickerWnd                                       0xAA2BF8
#define pinstCPlayerWnd                                            0xAA2BFC
#define pinstCOptionsWnd                                           0xAA2C00
#define pinstCBuffWindowNORMAL                                     0xAA2C04
#define pinstCBuffWindowSHORT                                      0xAA2C08
#define pinstCharacterCreation                                     0xAA2C0C
#define pinstCCursorAttachment                                     0xAA2C10
#define pinstCCastingWnd                                           0xAA2C14
#define pinstCCastSpellWnd                                         0xAA2C18
#define pinstCSpellBookWnd                                         0xAA2C1C
#define pinstCInventoryWnd                                         0xAA2C20
#define pinstCBankWnd                                              0xAA2C24
#define pinstCQuantityWnd                                          0xAA2C28
#define pinstCLootWnd                                              0xAA2C2C
#define pinstCActionsWnd                                           0xAA2C30
#define pinstCCombatAbilityWnd                                     0xAA2C34
#define pinstCMerchantWnd                                          0xAA2C38
#define pinstCTradeWnd                                             0xAA2C3C
#define pinstCSelectorWnd                                          0xAA2C40
#define pinstCBazaarWnd                                            0xAA2C44
#define pinstCBazaarSearchWnd                                      0xAA2C48
#define pinstCGiveWnd                                              0xAA2C64
#define pinstCTrackingWnd                                          0xAA2C68
#define pinstCInspectWnd                                           0xAA2C6C
#define pinstCSocialEditWnd                                        0xAA2C70
#define pinstCFeedbackWnd                                          0xAA2C74
#define pinstCBugReportWnd                                         0xAA2C78
#define pinstCVideoModesWnd                                        0xAA2C7C
#define pinstCTextEntryWnd                                         0xAA2C84
#define pinstCFileSelectionWnd                                     0xAA2C88
#define pinstCCompassWnd                                           0xAA2C8C
#define pinstCPlayerNotesWnd                                       0xAA2C90
#define pinstCGemsGameWnd                                          0xAA2C94
#define pinstCTimeLeftWnd                                          0xAA2C98
#define pinstCPetitionQWnd                                         0xAA2CAC
#define pinstCSoulmarkWnd                                          0xAA2CB0
#define pinstCStoryWnd                                             0xAA2CB4
#define pinstCJournalTextWnd                                       0xAA2CB8
#define pinstCJournalCatWnd                                        0xAA2CBC
#define pinstCBodyTintWnd                                          0xAA2CC0
#define pinstCServerListWnd                                        0xAA2CC4
#define pinstCAvaZoneWnd                                           0xAA2CCC
#define pinstCBlockedBuffWnd                                       0xAA2CD0
#define pinstCBlockedPetBuffWnd                                    0xAA2CD4
#define pinstCInvSlotMgr                                           0xAA2CEC
#define pinstCContainerMgr                                         0xAA2CF0
#define pinstCAdventureLeaderboardWnd                              0xBEAC98
#define pinstCAdventureRequestWnd                                  0xBEAC60
#define pinstCAltStorageWnd                                        0xBEAD10
#define pinstCAdventureStatsWnd                                    0xBEAC98
#define pinstCBarterMerchantWnd                                    0xBEB168
#define pinstCBarterSearchWnd                                      0xBEB1A0
#define pinstCBarterWnd                                            0xBEB1D8
#define pinstCChatManager                                          0xBEB5D0
#define pinstCDynamicZoneWnd                                       0xBEB7C0
#define pinstCEQMainWnd                                            0xBEB880
#define pinstCFellowshipWnd                                        0xBEB948
#define pinstCFindLocationWnd                                      0xBEB9B0
#define pinstCGroupSearchWnd                                       0xBEBB10
#define pinstCGroupWnd                                             0xBEBB48
#define pinstCGuildBankWnd                                         0xBEBB80
#define pinstCGuildMgmtWnd                                         0xBEDBF0
#define pinstCGuildTributeMasterWnd                                0xBEDC28
#define pinstCHotButtonWnd                                         0xBEDC78
#define pinstCHotButtonWnd1                                        0xBEDC78
#define pinstCHotButtonWnd2                                        0xBEDC7C
#define pinstCHotButtonWnd3                                        0xBEDC80
#define pinstCHotButtonWnd4                                        0xBEDC84
#define pinstCItemDisplayManager                                   0xBEDDC0
#define pinstCItemExpTransferWnd                                   0xBEDDFC
#define pinstCLeadershipWnd                                        0xBEDF28
#define pinstCLFGuildWnd                                           0xBEDF60
#define pinstCMIZoneSelectWnd                                      0xBEE1F8
#define pinstCAdventureMerchantWnd                                 0xBEE4A8
#define pinstCConfirmationDialog                                   0xBEE4E0
#define pinstCPopupWndManager                                      0xBEE4E0
#define pinstCProgressionSelectionWnd                              0xBEE548
#define pinstCPvPLeaderboardWnd                                    0xBEE580
#define pinstCPvPStatsWnd                                          0xBEE5B8
#define pinstCSystemInfoDialogBox                                  0xBEE840
#define pinstCTargetOfTargetWnd                                    0xBEF440
#define pinstCTaskSelectWnd                                        0xBEF4A8
#define pinstCTaskTemplateSelectWnd                                0xBEF4E0
#define pinstCTaskWnd                                              0xBEF518
#define pinstCTipWndOFDAY                                          0xBEF690
#define pinstCTipWndCONTEXT                                        0xBEF694
#define pinstCTitleWnd                                             0xBEF6C8
#define pinstCTradeskillWnd                                        0xBEF740
#define pinstCTributeBenefitWnd                                    0xBEF7D8
#define pinstCTributeMasterWnd                                     0xBEF810
#define pinstCContextMenuManager                                   0x1248FD0
#define pinstCVoiceMacroWnd                                        0xBBF2F8
#define pinstCHtmlWnd                                              0xBBF370


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D34E0
#define __ConvertItemTags                                          0x4C48D0
#define __ExecuteCmd                                               0x4B0710
#define __get_melee_range                                          0x4B66E0
#define __GetGaugeValueFromEQ                                      0x6BD140
#define __GetLabelFromEQ                                           0x6BE260
#define __GetXTargetType                                           0x735620
#define __LoadFrontEnd                                             0x5A0250
#define __NewUIINI                                                 0x6BCCF0
#define __ProcessGameEvents                                        0x50ACE0
#define CrashDetected                                              0x5A0050
#define DrawNetStatus                                              0x534E80
#define Util__FastTime                                             0x7C0950
#define Expansion_HoT                                              0xB5A940

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483EB0
#define AltAdvManager__IsAbilityReady                              0x483F30
#define AltAdvManager__GetAltAbility                               0x484170

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x4395E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5BDDF0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C8230

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x7865B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5DFD30
#define CChatManager__InitContextMenu                              0x5E0500

// CChatService
#define CChatService__GetNumberOfFriends                           0x729590
#define CChatService__GetFriendName                                0x7295A0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5E4860
#define CChatWindow__Clear                                         0x5E51B0
#define CChatWindow__WndNotification                               0x5E5390

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x770270
#define CComboWnd__Draw                                            0x770430
#define CComboWnd__GetCurChoice                                    0x770130
#define CComboWnd__GetListRect                                     0x770700
#define CComboWnd__GetTextRect                                     0x7702A0
#define CComboWnd__InsertChoice                                    0x770770
#define CComboWnd__SetColors                                       0x7700C0
#define CComboWnd__SetChoice                                       0x7700F0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5EE670
#define CContainerWnd__vftable                                     0x8B76A8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x477C50
#define CDisplay__GetClickedActor                                  0x470C90
#define CDisplay__GetUserDefinedColor                              0x46F670
#define CDisplay__GetWorldFilePath                                 0x46EB20
#define CDisplay__is3dON                                           0x46DC50
#define CDisplay__ReloadUI                                         0x480CE0
#define CDisplay__WriteTextHD2                                     0x4739C0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B7E30
#define CEditBaseWnd__SetSel                                       0x793E60

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7796A0
#define CEditWnd__GetCharIndexPt                                   0x77A630
#define CEditWnd__GetDisplayString                                 0x779830
#define CEditWnd__GetHorzOffset                                    0x779AC0
#define CEditWnd__GetLineForPrintableChar                          0x77A100
#define CEditWnd__GetSelStartPt                                    0x77A870
#define CEditWnd__GetSTMLSafeText                                  0x779C50
#define CEditWnd__PointFromPrintableChar                           0x77A210
#define CEditWnd__SelectableCharFromPoint                          0x77A380
#define CEditWnd__SetEditable                                      0x779C20

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EABB0
#define CEverQuest__DropHeldItemOnGround                           0x4F8110
#define CEverQuest__dsp_chat                                       0x4F0FF0
#define CEverQuest__DoTellWindow                                   0x4EF760
#define CEverQuest__EnterZone                                      0x5025C0
#define CEverQuest__GetBodyTypeDesc                                0x4E79E0
#define CEverQuest__GetClassDesc                                   0x4E7220
#define CEverQuest__GetClassThreeLetterCode                        0x4E7820
#define CEverQuest__GetDeityDesc                                   0x4E8090
#define CEverQuest__GetLangDesc                                    0x4E7D70
#define CEverQuest__GetRaceDesc                                    0x4E8060
#define CEverQuest__InterpretCmd                                   0x4F1BD0
#define CEverQuest__LeftClickedOnPlayer                            0x5046C0
#define CEverQuest__LMouseUp                                       0x508240
#define CEverQuest__RightClickedOnPlayer                           0x5093A0
#define CEverQuest__RMouseUp                                       0x50A520
#define CEverQuest__SetGameState                                   0x4EB040
#define CEverQuest__Emote                                          0x4F1210

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5FB7B0
#define CGaugeWnd__CalcLinesFillRect                               0x5FB810
#define CGaugeWnd__Draw                                            0x5FBC60

// CGuild
#define CGuild__FindMemberByName                                   0x41BB40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x6149D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x620230
#define CInvSlotMgr__MoveItem                                      0x620640

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x61F6E0
#define CInvSlot__SliderComplete                                   0x61DAC0
#define CInvSlot__GetItemBase                                      0x61D220

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x621420

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6BAA10
#define CItemDisplayWnd__UpdateStrings                             0x622310

// CLabel 
#define CLabel__Draw                                               0x636710

// CListWnd 
#define CListWnd__AddColumn                                        0x768EA0
#define CListWnd__AddColumn1                                       0x768560
#define CListWnd__AddLine                                          0x7680C0
#define CListWnd__AddString                                        0x768260
#define CListWnd__CalculateFirstVisibleLine                        0x764400
#define CListWnd__CalculateVSBRange                                0x766710
#define CListWnd__ClearAllSel                                      0x763960
#define CListWnd__CloseAndUpdateEditWindow                         0x767730
#define CListWnd__Compare                                          0x764DE0
#define CListWnd__Draw                                             0x766350
#define CListWnd__DrawColumnSeparators                             0x7661C0
#define CListWnd__DrawHeader                                       0x763BF0
#define CListWnd__DrawItem                                         0x7657E0
#define CListWnd__DrawLine                                         0x765E40
#define CListWnd__DrawSeparator                                    0x766260
#define CListWnd__EnsureVisible                                    0x764550
#define CListWnd__ExtendSel                                        0x765700
#define CListWnd__GetColumnMinWidth                                0x763630
#define CListWnd__GetColumnWidth                                   0x763570
#define CListWnd__GetCurSel                                        0x762DE0
#define CListWnd__GetHeaderRect                                    0x762F50
#define CListWnd__GetItemAtPoint                                   0x764810
#define CListWnd__GetItemAtPoint1                                  0x764880
#define CListWnd__GetItemData                                      0x763170
#define CListWnd__GetItemHeight                                    0x764080
#define CListWnd__GetItemIcon                                      0x763350
#define CListWnd__GetItemRect                                      0x764610
#define CListWnd__GetItemText                                      0x763200
#define CListWnd__GetSelList                                       0x768440
#define CListWnd__GetSeparatorRect                                 0x764D30
#define CListWnd__RemoveLine                                       0x7683F0
#define CListWnd__SetColors                                        0x762EB0
#define CListWnd__SetColumnJustification                           0x7637D0
#define CListWnd__SetColumnWidth                                   0x7635F0
#define CListWnd__SetCurSel                                        0x762E20
#define CListWnd__SetItemColor                                     0x7673F0
#define CListWnd__SetItemData                                      0x763A00
#define CListWnd__SetItemText                                      0x7671D0
#define CListWnd__ShiftColumnSeparator                             0x767040
#define CListWnd__Sort                                             0x7695E0
#define CListWnd__ToggleSel                                        0x7638D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x64C660

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x65FAA0
#define CMerchantWnd__RequestBuyItem                               0x6633F0
#define CMerchantWnd__RequestSellItem                              0x683850
#define CMerchantWnd__SelectBuySellSlot                            0x661030

// CObfuscator
#define CObfuscator__doit                                          0x6F9120

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x781E90
#define CSidlManager__CreateLabel                                  0x6B3770

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5B9FC0
#define CSidlScreenWnd__CalculateVSBRange                          0x5B9EF0
#define CSidlScreenWnd__ConvertToRes                               0x793D40
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7727E0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x773900
#define CSidlScreenWnd__CSidlScreenWnd2                            0x7739B0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x773120
#define CSidlScreenWnd__DrawSidlPiece                              0x7722B0
#define CSidlScreenWnd__EnableIniStorage                           0x771AA0
#define CSidlScreenWnd__GetSidlPiece                               0x7724C0
#define CSidlScreenWnd__Init1                                      0x773760
#define CSidlScreenWnd__LoadIniInfo                                0x772890
#define CSidlScreenWnd__LoadIniListWnd                             0x771BF0
#define CSidlScreenWnd__LoadSidlScreen                             0x773370
#define CSidlScreenWnd__StoreIniInfo                               0x7716A0
#define CSidlScreenWnd__StoreIniVis                                0x771A30
#define CSidlScreenWnd__WndNotification                            0x773550
#define CSidlScreenWnd__GetChildItem                               0x771B00

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x56D270

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x794730
#define CSliderWnd__SetValue                                       0x794830
#define CSliderWnd__SetNumTicks                                    0x794DE0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6B8630

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7913E0
#define CStmlWnd__CalculateHSBRange                                0x788A30
#define CStmlWnd__CalculateVSBRange                                0x788AB0
#define CStmlWnd__CanBreakAtCharacter                              0x788C30
#define CStmlWnd__FastForwardToEndOfTag                            0x789950
#define CStmlWnd__ForceParseNow                                    0x791910
#define CStmlWnd__GetNextTagPiece                                  0x789870
#define CStmlWnd__GetSTMLText                                      0x5E4800
#define CStmlWnd__GetThisChar                                      0x7B9360
#define CStmlWnd__GetVisiableText                                  0x78ADB0
#define CStmlWnd__InitializeWindowVariables                        0x78D380
#define CStmlWnd__MakeStmlColorTag                                 0x787950
#define CStmlWnd__MakeWndNotificationTag                           0x7879F0
#define CStmlWnd__SetSTMLText                                      0x78D4A0
#define CStmlWnd__StripFirstSTMLLines                              0x791090
#define CStmlWnd__UpdateHistoryString                              0x78B640

// CTabWnd 
#define CTabWnd__Draw                                              0x795CE0
#define CTabWnd__DrawCurrentPage                                   0x7955B0
#define CTabWnd__DrawTab                                           0x795390
#define CTabWnd__GetCurrentPage                                    0x795970
#define CTabWnd__GetPageClientRect                                 0x795040
#define CTabWnd__GetPageFromTabIndex                               0x7952C0
#define CTabWnd__GetPageInnerRect                                  0x7950A0
#define CTabWnd__GetTabInnerRect                                   0x795240
#define CTabWnd__GetTabRect                                        0x795130
#define CTabWnd__InsertPage                                        0x795F70
#define CTabWnd__SetPage                                           0x7959B0
#define CTabWnd__SetPageRect                                       0x795C10
#define CTabWnd__UpdatePage                                        0x795EF0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x418120

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x773D30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x796B60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x761D80

// CXRect 
#define CXRect__CenterPoint                                        0x535800

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x416270
#define CXStr__CXStr1                                              0x401410
#define CXStr__CXStr3                                              0x7BD930
#define CXStr__dCXStr                                              0x44EA00
#define CXStr__operator_equal                                      0x7BDAA0
#define CXStr__operator_equal1                                     0x7BDAF0
#define CXStr__operator_plus_equal1                                0x7BEB80

// CXWnd 
#define CXWnd__BringToTop                                          0x769BD0
#define CXWnd__Center                                              0x76EBC0
#define CXWnd__ClrFocus                                            0x7699F0
#define CXWnd__DoAllDrawing                                        0x76F4E0
#define CXWnd__DrawChildren                                        0x76F620
#define CXWnd__DrawColoredRect                                     0x769EB0
#define CXWnd__DrawTooltip                                         0x76EAF0
#define CXWnd__DrawTooltipAtPoint                                  0x76E220
#define CXWnd__GetBorderFrame                                      0x76A3A0
#define CXWnd__GetChildWndAt                                       0x76D6E0
#define CXWnd__GetClientClipRect                                   0x76A170
#define CXWnd__GetScreenClipRect                                   0x76E750
#define CXWnd__GetScreenRect                                       0x76A4E0
#define CXWnd__GetTooltipRect                                      0x769FC0
#define CXWnd__GetWindowTextA                                      0x5AB340
#define CXWnd__IsActive                                            0x774E60
#define CXWnd__IsDescendantOf                                      0x76A2D0
#define CXWnd__IsReallyVisible                                     0x76D6C0
#define CXWnd__IsType                                              0x799970
#define CXWnd__Move                                                0x76CB80
#define CXWnd__Move1                                               0x76CC40
#define CXWnd__ProcessTransition                                   0x769B80
#define CXWnd__Refade                                              0x769B00
#define CXWnd__Resize                                              0x76A5A0
#define CXWnd__Right                                               0x76E660
#define CXWnd__SetFocus                                            0x76BDB0
#define CXWnd__SetKeyTooltip                                       0x76A7F0
#define CXWnd__SetMouseOver                                        0x76E9E0
#define CXWnd__StartFade                                           0x769C10
#define CXWnd__GetChildItem                                        0x76E950

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x7763D0
#define CXWndManager__DrawWindows                                  0x776050
#define CXWndManager__GetKeyboardFlags                             0x774AC0
#define CXWndManager__HandleKeyboardMsg                            0x775130
#define CXWndManager__RemoveWnd                                    0x774F80

// CDBStr
#define CDBStr__GetString                                          0x46C4B0

// EQ_Character 
#define EQ_Character__CastRay                                      0x716EC0
#define EQ_Character__CastSpell                                    0x430480
#define EQ_Character__Cur_HP                                       0x4392A0
#define EQ_Character__GetAACastingTimeModifier                     0x4254C0
#define EQ_Character__GetCharInfo2                                 0x715C60
#define EQ_Character__GetFocusCastingTimeModifier                  0x420C20
#define EQ_Character__GetFocusRangeModifier                        0x420DF0
#define EQ_Character__Max_Endurance                                0x53D910
#define EQ_Character__Max_HP                                       0x434260
#define EQ_Character__Max_Mana                                     0x53D710
#define EQ_Character__doCombatAbility                              0x53C590
#define EQ_Character__UseSkill                                     0x447B40
#define EQ_Character__GetConLevel                                  0x5376F0
#define EQ_Character__IsExpansionFlag                              0x40D8F0
#define EQ_Character__TotalEffect                                  0x429A00

// EQ_Item 
#define EQ_Item__CanDrop                                           0x51C190
#define EQ_Item__CreateItemTagString                               0x7043D0
#define EQ_Item__IsStackable                                       0x6F97A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x485220
#define EQ_LoadingS__Array                                         0x94A468

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x540DE0
#define EQ_PC__GetAltAbilityIndex                                  0x70AAE0
#define EQ_PC__GetCombatAbility                                    0x70AB70
#define EQ_PC__GetCombatAbilityTimer                               0x70AC20
#define EQ_PC__GetItemTimerValue                                   0x53C3B0
#define EQ_PC__HasLoreItem                                         0x7147B0

// EQItemList 
#define EQItemList__EQItemList                                     0x4B49B0
#define EQItemList__add_item                                       0x4B4940
#define EQItemList__delete_item                                    0x4B4D60
#define EQItemList__FreeItemList                                   0x4B4C90

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46BBB0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5459B0
#define EQPlayer__dEQPlayer                                        0x54A500
#define EQPlayer__DoAttack                                         0x55B430
#define EQPlayer__EQPlayer                                         0x54FE70
#define EQPlayer__SetNameSpriteState                               0x547E70
#define EQPlayer__SetNameSpriteTint                                0x545A20
#define EQPlayer__IsBodyType_j                                     0x716780
#define EQPlayer__IsTargetable                                     0x716A40

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x551140
#define EQPlayerManager__GetSpawnByName                            0x5513D0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x521C50
#define KeypressHandler__AttachKeyToEqCommand                      0x521C90
#define KeypressHandler__ClearCommandStateArray                    0x521A60
#define KeypressHandler__HandleKeyDown                             0x520460
#define KeypressHandler__HandleKeyUp                               0x520770
#define KeypressHandler__SaveKeymapping                            0x521B30

// MapViewMap 
#define MapViewMap__Clear                                          0x647CE0
#define MapViewMap__SaveEx                                         0x6486B0

#define PlayerPointManager__GetAltCurrency                         0x705560

// StringTable 
#define StringTable__getString                                     0x6F93A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x53F5D0