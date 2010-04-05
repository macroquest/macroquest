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
#define __ExpectedVersionDate                                     "Feb  9 2010"
#define __ExpectedVersionTime                                     "14:03:12"
#define __ActualVersionDate                                        0x818B68
#define __ActualVersionTime                                        0x818B74

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x511240
#define __MemChecker1                                              0x6E0D20
#define __MemChecker2                                              0x570F80
#define __MemChecker3                                              0x570ED0
#define __MemChecker4                                              0x694E30
#define __EncryptPad0                                              0x8A9190
#define __EncryptPad1                                              0x8B4290
#define __EncryptPad2                                              0x8ABDC8
#define __EncryptPad3                                              0x8AB9C8
#define __EncryptPad4                                              0x8B38D8
#define __AC1                                                      0x65CD60
#define __AC2                                                      0x4D9475
#define __AC3                                                      0x4ED448
#define __AC4                                                      0x4F1318
#define __AC5                                                      0x4FBA88
#define __AC6                                                      0x4FEF0B
#define __AC7                                                      0x4F7FB4
#define __AC1_Data                                                 0x801390

// Direct Input
#define DI8__Main                                                  0xB0ECBC
#define DI8__Keyboard                                              0xB0ECC0
#define DI8__Mouse                                                 0xB0ECC4
#define __AltTimerReady                                            0xA959CE
#define __Attack                                                   0xAF906E
#define __Autofire                                                 0xAF906F
#define __BindList                                                 0x8A3910
#define __Clicks                                                   0xA946C8
#define __CommandList                                              0x8A4260
#define __CurrentMapLabel                                          0xB39F58
#define __CurrentSocial                                            0x89F83C
#define __DoAbilityAvailable                                       0xA95968
#define __DoAbilityList                                            0xACAF8C
#define __do_loot                                                  0x4B2050
#define __DrawHandler                                              0xB4955C
#define __GroupCount                                               0xA8E4C2
#define __Guilds                                                   0xA93AA8
#define __gWorld                                                   0xA90380
#define __HotkeyPage                                               0xAF2378
#define __HWnd                                                     0xB0E9F8
#define __InChatMode                                               0xA94600
#define __LastTell                                                 0xA962E4
#define __LMouseHeldTime                                           0xA946F4
#define __Mouse                                                    0xB0ECC8
#define __MouseLook                                                0xA94696
#define __MouseEventTime                                           0xAF91B0
#define __NetStatusToggle                                          0xA94699
#define __PCNames                                                  0xA95D28
#define __RangeAttackReady                                         0xA959CC
#define __RMouseHeldTime                                           0xA946F0
#define __RunWalkState                                             0xA94604
#define __ScreenMode                                               0x9DDD58
#define __ScreenX                                                  0xA945B8
#define __ScreenY                                                  0xA945BC
#define __ScreenXMax                                               0xA945C0
#define __ScreenYMax                                               0xA945C4
#define __ServerHost                                               0xA8E404
#define __ServerName                                               0xACAF4C
#define __ShiftKeyDown                                             0xA94C80
#define __ShowNames                                                0xA95BFC
#define __Socials                                                  0xACB04C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA90440
#define instEQZoneInfo                                             0xA94840
#define instKeypressHandler                                        0xAF9194
#define pinstActiveBanker                                          0xA90418
#define pinstActiveCorpse                                          0xA9041C
#define pinstActiveGMaster                                         0xA90420
#define pinstActiveMerchant                                        0xA90414
#define pinstAltAdvManager                                         0x9DEBD8
#define pinstAuraMgr                                               0x8C761C
#define pinstBandageTarget                                         0xA90400
#define pinstCamActor                                              0x9DE6C4
#define pinstCDBStr                                                0x9DDD48
#define pinstCDisplay                                              0xA90428
#define pinstCEverQuest                                            0xB0EE40
#define pinstCharData                                              0xA903E4
#define pinstCharSpawn                                             0xA9040C
#define pinstControlledMissile                                     0xA903E0
#define pinstControlledPlayer                                      0xA9040C
#define pinstCSidlManager                                          0xB48CD0
#define pinstCXWndManager                                          0xB48CC8
#define instDynamicZone                                            0xA94488
#define pinstDZMember                                              0xA94598
#define pinstDZTimerInfo                                           0xA9459C
#define pinstEQItemList                                            0xA903C8
#define instEQMisc                                                 0x9DDD00
#define pinstEQSoundManager                                        0x9DEBFC
#define instExpeditionLeader                                       0xA944D2
#define instExpeditionName                                         0xA94512
#define pinstGroup                                                 0xA8E4BE
#define pinstImeManager                                            0xB48CD4
#define pinstLocalPlayer                                           0xA903F8
#define pinstMercenaryData                                         0xAF9508
#define pinstModelPlayer                                           0xA90424
#define pinstPCData                                                0xA903E4
#define pinstSkillMgr                                              0xB0BAAC
#define pinstSpawnManager                                          0xB0B908
#define pinstSpellManager                                          0xB0BAB8
#define pinstSpellSets                                             0xAF237C
#define pinstStringTable                                           0xA9039C
#define pinstSwitchManager                                         0xA8E104
#define pinstTarget                                                0xA90410
#define pinstTargetObject                                          0xA903E8
#define pinstTargetSwitch                                          0xA903EC
#define pinstTaskMember                                            0x9DDCE0
#define pinstTrackTarget                                           0xA90404
#define pinstTradeTarget                                           0xA903F4
#define instTributeActive                                          0x9DDD25
#define pinstViewActor                                             0x9DE6C0
#define pinstWorldData                                             0xA903C4


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x8C4EE4
#define pinstCAudioTriggersWindow                                  0x8C4EB0
#define pinstCCharacterSelect                                      0x9DE5C0
#define pinstCFacePick                                             0x9DE570
#define pinstCNoteWnd                                              0x9DE578
#define pinstCBookWnd                                              0x9DE57C
#define pinstCPetInfoWnd                                           0x9DE580
#define pinstCTrainWnd                                             0x9DE584
#define pinstCSkillsWnd                                            0x9DE588
#define pinstCSkillsSelectWnd                                      0x9DE58C
#define pinstCCombatSkillSelectWnd                                 0x9DE590
#define pinstCFriendsWnd                                           0x9DE594
#define pinstCAuraWnd                                              0x9DE598
#define pinstCRespawnWnd                                           0x9DE59C
#define pinstCBandolierWnd                                         0x9DE5A0
#define pinstCPotionBeltWnd                                        0x9DE5A4
#define pinstCAAWnd                                                0x9DE5A8
#define pinstCGroupSearchFiltersWnd                                0x9DE5AC
#define pinstCLoadskinWnd                                          0x9DE5B0
#define pinstCAlarmWnd                                             0x9DE5B4
#define pinstCMusicPlayerWnd                                       0x9DE5B8
#define pinstCMailWnd                                              0x9DE5C4
#define pinstCMailCompositionWnd                                   0x9DE5C8
#define pinstCMailAddressBookWnd                                   0x9DE5CC
#define pinstCRaidWnd                                              0x9DE5D4
#define pinstCRaidOptionsWnd                                       0x9DE5D8
#define pinstCBreathWnd                                            0x9DE5DC
#define pinstCMapViewWnd                                           0x9DE5E0
#define pinstCMapToolbarWnd                                        0x9DE5E4
#define pinstCEditLabelWnd                                         0x9DE5E8
#define pinstCTargetWnd                                            0x9DE5EC
#define pinstCColorPickerWnd                                       0x9DE5F0
#define pinstCPlayerWnd                                            0x9DE5F4
#define pinstCOptionsWnd                                           0x9DE5F8
#define pinstCBuffWindowNORMAL                                     0x9DE5FC
#define pinstCBuffWindowSHORT                                      0x9DE600
#define pinstCharacterCreation                                     0x9DE604
#define pinstCCursorAttachment                                     0x9DE608
#define pinstCCastingWnd                                           0x9DE60C
#define pinstCCastSpellWnd                                         0x9DE610
#define pinstCSpellBookWnd                                         0x9DE614
#define pinstCInventoryWnd                                         0x9DE618
#define pinstCBankWnd                                              0x9DE61C
#define pinstCQuantityWnd                                          0x9DE620
#define pinstCLootWnd                                              0x9DE624
#define pinstCActionsWnd                                           0x9DE628
#define pinstCCombatAbilityWnd                                     0x9DE62C
#define pinstCMerchantWnd                                          0x9DE630
#define pinstCTradeWnd                                             0x9DE634
#define pinstCSelectorWnd                                          0x9DE638
#define pinstCBazaarWnd                                            0x9DE63C
#define pinstCBazaarSearchWnd                                      0x9DE640
#define pinstCGiveWnd                                              0x9DE644
#define pinstCTrackingWnd                                          0x9DE648
#define pinstCInspectWnd                                           0x9DE64C
#define pinstCSocialEditWnd                                        0x9DE650
#define pinstCFeedbackWnd                                          0x9DE654
#define pinstCBugReportWnd                                         0x9DE658
#define pinstCVideoModesWnd                                        0x9DE65C
#define pinstCTextEntryWnd                                         0x9DE664
#define pinstCFileSelectionWnd                                     0x9DE668
#define pinstCCompassWnd                                           0x9DE66C
#define pinstCPlayerNotesWnd                                       0x9DE670
#define pinstCGemsGameWnd                                          0x9DE674
#define pinstCTimeLeftWnd                                          0x9DE678
#define pinstCPetitionQWnd                                         0x9DE68C
#define pinstCSoulmarkWnd                                          0x9DE690
#define pinstCStoryWnd                                             0x9DE694
#define pinstCJournalTextWnd                                       0x9DE698
#define pinstCJournalCatWnd                                        0x9DE69C
#define pinstCBodyTintWnd                                          0x9DE6A0
#define pinstCServerListWnd                                        0x9DE6A4
#define pinstCAvaZoneWnd                                           0x9DE6AC
#define pinstCBlockedBuffWnd                                       0x9DE6B0
#define pinstCBlockedPetBuffWnd                                    0x9DE6B4
#define pinstCInvSlotMgr                                           0x9DE6B8
#define pinstCContainerMgr                                         0x9DE6BC
#define pinstCAdventureLeaderboardWnd                              0xB37470
#define pinstCAdventureRequestWnd                                  0xB3748C
#define pinstCAltStorageWnd                                        0xB374EC
#define pinstCAdventureStatsWnd                                    0xB374A8
#define pinstCBarterMerchantWnd                                    0xB376B8
#define pinstCBarterSearchWnd                                      0xB376D4
#define pinstCBarterWnd                                            0xB376F0
#define pinstCChatManager                                          0xB37994
#define pinstCDynamicZoneWnd                                       0xB37A8C
#define pinstCEQMainWnd                                            0xB37B00
#define pinstCFellowshipWnd                                        0xB37B64
#define pinstCFindLocationWnd                                      0xB37B98
#define pinstCGroupSearchWnd                                       0xB37C48
#define pinstCGroupWnd                                             0xB37C64
#define pinstCGuildBankWnd                                         0xB37C80
#define pinstCGuildMgmtWnd                                         0xB39CB8
#define pinstCGuildTributeMasterWnd                                0xB39CD8
#define pinstCHotButtonWnd                                         0xB39D0C
#define pinstCHotButtonWnd1                                        0xB39D0C
#define pinstCHotButtonWnd2                                        0xB39D10
#define pinstCHotButtonWnd3                                        0xB39D14
#define pinstCHotButtonWnd4                                        0xB39D18
#define pinstCItemDisplayManager                                   0xB39DC4
#define pinstCItemExpTransferWnd                                   0xB39DE4
#define pinstCLeadershipWnd                                        0xB39E80
#define pinstCLFGuildWnd                                           0xB39E9C
#define pinstCMIZoneSelectWnd                                      0xB3A00C
#define pinstCAdventureMerchantWnd                                 0xB3A11C
#define pinstCConfirmationDialog                                   0xB3A138
#define pinstCPopupWndManager                                      0xB3A138
#define pinstCProgressionSelectionWnd                              0xB3A16C
#define pinstCPvPLeaderboardWnd                                    0xB3A188
#define pinstCPvPStatsWnd                                          0xB3A1A4
#define pinstCSystemInfoDialogBox                                  0xB3A270
#define pinstCTargetOfTargetWnd                                    0xB3AC6C
#define pinstCTaskSelectWnd                                        0xB3ACA0
#define pinstCTaskTemplateSelectWnd                                0xB3ACBC
#define pinstCTaskWnd                                              0xB3ACD8
#define pinstCTipWndOFDAY                                          0xB3AD54
#define pinstCTipWndCONTEXT                                        0xB3AD58
#define pinstCTitleWnd                                             0xB3AD74
#define pinstCTradeskillWnd                                        0xB3ADB8
#define pinstCTributeBenefitWnd                                    0xB3AE04
#define pinstCTributeMasterWnd                                     0xB3AE20
#define pinstCContextMenuManager                                   0xB48D2C
#define pinstCVoiceMacroWnd                                        0xB0BCAC
#define pinstCHtmlWnd                                              0xB0BCF8


//// 
// Section 3: Miscellaneous Offsets 
////
#define __AddEqItem                                                0x4A7990
#define __CastRay                                                  0x4C5EB0
#define __ConvertItemTags                                          0x4B76D0
#define __DeleteEqItem                                             0x4A7BF0
#define __ExecuteCmd                                               0x4A3AE0
#define __get_melee_range                                          0x4A96B0
#define __GetGaugeValueFromEQ                                      0x65BC20
#define __GetLabelFromEQ                                           0x65CD00
#define __GetXTargetType                                           0x74F480
#define __LoadFrontEnd                                             0x56FE50
#define __NewUIINI                                                 0x65B7B0
#define __ProcessGameEvents                                        0x4F83A0
#define CrashDetected                                              0x56FC50
#define DrawNetStatus                                              0x519DB0
#define Util__FastTime                                             0x6E1430


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47AE90
#define AltAdvManager__IsAbilityReady                              0x47AED0
#define AltAdvManager__GetAltAbility                               0x47B120

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x58D400

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x596C40

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x70F350

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5ACA70
#define CChatManager__InitContextMenu                              0x5AD240

// CChatService
#define CChatService__GetNumberOfFriends                           0x6CB550
#define CChatService__GetFriendName                                0x6CB560

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5B1440
#define CChatWindow__Clear                                         0x5B1DB0
#define CChatWindow__WndNotification                               0x5B1FA0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6F92F0
#define CComboWnd__Draw                                            0x6F94B0
#define CComboWnd__GetCurChoice                                    0x6F9290
#define CComboWnd__GetListRect                                     0x6F97A0
#define CComboWnd__GetTextRect                                     0x6F9320
#define CComboWnd__InsertChoice                                    0x6F9810
#define CComboWnd__SetColors                                       0x6F9220
#define CComboWnd__SetChoice                                       0x6F9250

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5B9470
#define CContainerWnd__vftable                                     0x820588

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46E020
#define CDisplay__FreeAllItemLists                                 0x4A79C0
#define CDisplay__GetClickedActor                                  0x467360
#define CDisplay__GetUserDefinedColor                              0x466480
#define CDisplay__GetWorldFilePath                                 0x465910
#define CDisplay__is3dON                                           0x464A50
#define CDisplay__ReloadUI                                         0x478090
#define CDisplay__WriteTextHD2                                     0x46A040

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x587420
#define CEditBaseWnd__SetSel                                       0x71BDA0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x702320
#define CEditWnd__GetCharIndexPt                                   0x7032F0
#define CEditWnd__GetDisplayString                                 0x7024C0
#define CEditWnd__GetHorzOffset                                    0x702750
#define CEditWnd__GetLineForPrintableChar                          0x702DA0
#define CEditWnd__GetSelStartPt                                    0x703540
#define CEditWnd__GetSTMLSafeText                                  0x7028F0
#define CEditWnd__PointFromPrintableChar                           0x702EB0
#define CEditWnd__SelectableCharFromPoint                          0x703030
#define CEditWnd__SetEditable                                      0x7028C0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D9B50
#define CEverQuest__DropHeldItemOnGround                           0x4DE0C0
#define CEverQuest__dsp_chat                                       0x4DF810
#define CEverQuest__DoTellWindow                                   0x4DE240
#define CEverQuest__EnterZone                                      0x4F12B0
#define CEverQuest__GetBodyTypeDesc                                0x4D6D50
#define CEverQuest__GetClassDesc                                   0x4D6590
#define CEverQuest__GetClassThreeLetterCode                        0x4D6B90
#define CEverQuest__GetDeityDesc                                   0x4D73C0
#define CEverQuest__GetLangDesc                                    0x4D70E0
#define CEverQuest__GetRaceDesc                                    0x4D7390
#define CEverQuest__InterpretCmd                                   0x4E0370
#define CEverQuest__LeftClickedOnPlayer                            0x4F2E10
#define CEverQuest__LMouseUp                                       0x4F6700
#define CEverQuest__RightClickedOnPlayer                           0x4F6F90
#define CEverQuest__RMouseUp                                       0x4F7F70
#define CEverQuest__SetGameState                                   0x4D9FE0
#define CEverQuest__Emote                                          0x4DFA30

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5C5C70
#define CGaugeWnd__CalcLinesFillRect                               0x5C5CD0
#define CGaugeWnd__Draw                                            0x5C6120

// CGuild
#define CGuild__FindMemberByName                                   0x41AF10

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5DECB0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5E8390
#define CInvSlotMgr__MoveItem                                      0x5E8530

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5E7C20
#define CInvSlot__SliderComplete                                   0x5E6D30

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5E94E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x659650
#define CItemDisplayWnd__UpdateStrings                             0x5EA190

// CLabel 
#define CLabel__Draw                                               0x5FC850

// CListWnd 
#define CListWnd__AddColumn                                        0x6F2D10
#define CListWnd__AddColumn1                                       0x6F2790
#define CListWnd__AddLine                                          0x6F2300
#define CListWnd__AddString                                        0x6F24A0
#define CListWnd__CalculateFirstVisibleLine                        0x6EEFC0
#define CListWnd__CalculateVSBRange                                0x6F11E0
#define CListWnd__ClearAllSel                                      0x6EE510
#define CListWnd__CloseAndUpdateEditWindow                         0x6EF640
#define CListWnd__Compare                                          0x6EF9E0
#define CListWnd__Draw                                             0x6F0E60
#define CListWnd__DrawColumnSeparators                             0x6F0CD0
#define CListWnd__DrawHeader                                       0x6EE7A0
#define CListWnd__DrawItem                                         0x6F02F0
#define CListWnd__DrawLine                                         0x6F0940
#define CListWnd__DrawSeparator                                    0x6F0D70
#define CListWnd__EnsureVisible                                    0x6EF050
#define CListWnd__ExtendSel                                        0x6F0210
#define CListWnd__GetColumnMinWidth                                0x6EE2A0
#define CListWnd__GetColumnWidth                                   0x6EE1E0
#define CListWnd__GetCurSel                                        0x6EDC00
#define CListWnd__GetHeaderRect                                    0x6EDD90
#define CListWnd__GetItemAtPoint                                   0x6EF350
#define CListWnd__GetItemAtPoint1                                  0x6EF3C0
#define CListWnd__GetItemData                                      0x6EDF90
#define CListWnd__GetItemHeight                                    0x6EEC30
#define CListWnd__GetItemIcon                                      0x6EE120
#define CListWnd__GetItemRect                                      0x6EF130
#define CListWnd__GetItemText                                      0x6EDFD0
#define CListWnd__GetSelList                                       0x6F2670
#define CListWnd__GetSeparatorRect                                 0x6EF920
#define CListWnd__RemoveLine                                       0x6F2CC0
#define CListWnd__SetColors                                        0x6EDCF0
#define CListWnd__SetColumnJustification                           0x6EE380
#define CListWnd__SetColumnWidth                                   0x6EE260
#define CListWnd__SetCurSel                                        0x6EDC40
#define CListWnd__SetItemColor                                     0x6F1E90
#define CListWnd__SetItemData                                      0x6EE5B0
#define CListWnd__SetItemText                                      0x6F1E10
#define CListWnd__ShiftColumnSeparator                             0x6F0120
#define CListWnd__Sort                                             0x6F2D50
#define CListWnd__ToggleSel                                        0x6EE480

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x6120C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x61E110
#define CMerchantWnd__RequestBuyItem                               0x620050
#define CMerchantWnd__RequestSellItem                              0x620470
#define CMerchantWnd__SelectBuySellSlot                            0x61F4E0

// CObfuscator
#define CObfuscator__doit                                          0x6A5560

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x70AB50
#define CSidlManager__CreateLabel                                  0x652600

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6FB020
#define CSidlScreenWnd__CalculateVSBRange                          0x6FAF40
#define CSidlScreenWnd__ConvertToRes                               0x71BC80
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6FB4F0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6FC5E0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6FC690
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6FBD90
#define CSidlScreenWnd__DrawSidlPiece                              0x6FB1B0
#define CSidlScreenWnd__EnableIniStorage                           0x6FAC30
#define CSidlScreenWnd__GetSidlPiece                               0x6FB3C0
#define CSidlScreenWnd__Init1                                      0x6FC440
#define CSidlScreenWnd__LoadIniInfo                                0x6FB5B0
#define CSidlScreenWnd__LoadIniListWnd                             0x6FAD80
#define CSidlScreenWnd__LoadSidlScreen                             0x6FBFE0
#define CSidlScreenWnd__StoreIniInfo                               0x6FA840
#define CSidlScreenWnd__StoreIniVis                                0x6FABC0
#define CSidlScreenWnd__WndNotification                            0x6FC1C0
#define CSidlScreenWnd__GetChildItem                               0x6FAC90

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x53DA40

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x71D230
#define CSliderWnd__SetValue                                       0x71D330
#define CSliderWnd__SetNumTicks                                    0x71D8E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6573C0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x719E60
#define CStmlWnd__CalculateHSBRange                                0x7115E0
#define CStmlWnd__CalculateVSBRange                                0x711550
#define CStmlWnd__CanBreakAtCharacter                              0x711760
#define CStmlWnd__FastForwardToEndOfTag                            0x712440
#define CStmlWnd__ForceParseNow                                    0x71A360
#define CStmlWnd__GetNextTagPiece                                  0x712360
#define CStmlWnd__GetSTMLText                                      0x5B13E0
#define CStmlWnd__GetThisChar                                      0x7411E0
#define CStmlWnd__GetVisiableText                                  0x713880
#define CStmlWnd__InitializeWindowVariables                        0x715DE0
#define CStmlWnd__MakeStmlColorTag                                 0x710470
#define CStmlWnd__MakeWndNotificationTag                           0x710510
#define CStmlWnd__SetSTMLText                                      0x715F00
#define CStmlWnd__StripFirstSTMLLines                              0x719B00
#define CStmlWnd__UpdateHistoryString                              0x714110

// CTabWnd 
#define CTabWnd__Draw                                              0x71E730
#define CTabWnd__DrawCurrentPage                                   0x71E090
#define CTabWnd__DrawTab                                           0x71DE70
#define CTabWnd__GetCurrentPage                                    0x71E3C0
#define CTabWnd__GetPageClientRect                                 0x71DB40
#define CTabWnd__GetPageFromTabIndex                               0x71DDA0
#define CTabWnd__GetPageInnerRect                                  0x71DBA0
#define CTabWnd__GetTabInnerRect                                   0x71DD20
#define CTabWnd__GetTabRect                                        0x71DC30
#define CTabWnd__InsertPage                                        0x71E9C0
#define CTabWnd__SetPage                                           0x71E400
#define CTabWnd__SetPageRect                                       0x71E660
#define CTabWnd__UpdatePage                                        0x71E940

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417500

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6FCA10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x71F5D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6ECE10

// CXRect 
#define CXRect__CenterPoint                                        0x58CA80

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x415860
#define CXStr__CXStr1                                              0x721B80
#define CXStr__CXStr3                                              0x6DE730
#define CXStr__dCXStr                                              0x50AFF0
#define CXStr__operator_equal1                                     0x6DE8F0
#define CXStr__operator_plus_equal1                                0x6DF930

// CXWnd 
#define CXWnd__BringToTop                                          0x6F3330
#define CXWnd__Center                                              0x6F7B20
#define CXWnd__ClrFocus                                            0x6F3150
#define CXWnd__DoAllDrawing                                        0x6F89C0
#define CXWnd__DrawChildren                                        0x6F8B10
#define CXWnd__DrawColoredRect                                     0x6F3610
#define CXWnd__DrawTooltip                                         0x6F8810
#define CXWnd__DrawTooltipAtPoint                                  0x6F78D0
#define CXWnd__GetBorderFrame                                      0x6F3A50
#define CXWnd__GetChildWndAt                                       0x6F7100
#define CXWnd__GetClientClipRect                                   0x6F38D0
#define CXWnd__GetScreenClipRect                                   0x6F7D40
#define CXWnd__GetScreenRect                                       0x6F3BE0
#define CXWnd__GetTooltipRect                                      0x6F3720
#define CXWnd__GetWindowTextA                                      0x57ACD0
#define CXWnd__IsActive                                            0x6FDB80
#define CXWnd__IsDescendantOf                                      0x6F3980
#define CXWnd__IsReallyVisible                                     0x6F70E0
#define CXWnd__IsType                                              0x722440
#define CXWnd__Move                                                0x6F68A0
#define CXWnd__Move1                                               0x6F85F0
#define CXWnd__ProcessTransition                                   0x6F32E0
#define CXWnd__Refade                                              0x6F3260
#define CXWnd__Resize                                              0x6F3CB0
#define CXWnd__Right                                               0x6F7C80
#define CXWnd__SetFocus                                            0x6F5470
#define CXWnd__SetKeyTooltip                                       0x6F3E90
#define CXWnd__SetMouseOver                                        0x6F8020
#define CXWnd__StartFade                                           0x6F3370
#define CXWnd__GetChildItem                                        0x6F7FA0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6FF0D0
#define CXWndManager__DrawWindows                                  0x6FED50
#define CXWndManager__GetKeyboardFlags                             0x6FD7D0
#define CXWndManager__HandleKeyboardMsg                            0x6FDE50
#define CXWndManager__RemoveWnd                                    0x6FDCA0

// CDBStr
#define CDBStr__GetString                                          0x4633A0

// EQ_Character 
#define EQ_Character__CastRay                                      0x74D2B0
#define EQ_Character__CastSpell                                    0x42DB90
#define EQ_Character__Cur_HP                                       0x436DC0
#define EQ_Character__GetAACastingTimeModifier                     0x423A90
#define EQ_Character__GetCharInfo2                                 0x6BC550
#define EQ_Character__GetFocusCastingTimeModifier                  0x41F2E0
#define EQ_Character__GetFocusRangeModifier                        0x41F420
#define EQ_Character__Max_Endurance                                0x520210
#define EQ_Character__Max_HP                                       0x431FA0
#define EQ_Character__Max_Mana                                     0x520040
#define EQ_Character__doCombatAbility                              0x51EF50
#define EQ_Character__UseSkill                                     0x440D50
#define EQ_Character__GetConLevel                                  0x51B270

// EQ_Item 
#define EQ_Item__CanDrop                                           0x508A20
#define EQ_Item__GetItemLinkHash                                   0x6AF010
#define EQ_Item__IsStackable                                       0x6A5E40

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47BFF0
#define EQ_LoadingS__Array                                         0x8A1D78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x5230B0
#define EQ_PC__GetAltAbilityIndex                                  0x6B4200
#define EQ_PC__GetCombatAbility                                    0x6B4290
#define EQ_PC__GetCombatAbilityTimer                               0x6B4340
#define EQ_PC__GetItemTimerValue                                   0x51DEA0
#define EQ_PC__HasLoreItem                                         0x521560

// EQItemList 
//#define EQItemList__dEQItemList                                    0x0
#define EQItemList__EQItemList                                     0x4A78E0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x462D00

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x527A70
#define EQPlayer__dEQPlayer                                        0x52BC30
#define EQPlayer__DoAttack                                         0x539BF0
#define EQPlayer__EQPlayer                                         0x52F990
#define EQPlayer__SetNameSpriteState                               0x529B80
#define EQPlayer__SetNameSpriteTint                                0x527AE0
#define EQPlayer__IsBodyType_j                                     0x74CBC0
#define EQPlayer__IsTargetable                                     0x74CD50

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x530B40
#define EQPlayerManager__GetSpawnByName                            0x530E20

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x50A6D0
#define KeypressHandler__AttachKeyToEqCommand                      0x50A710
#define KeypressHandler__ClearCommandStateArray                    0x50A4E0
#define KeypressHandler__HandleKeyDown                             0x509060
#define KeypressHandler__HandleKeyUp                               0x509370
#define KeypressHandler__SaveKeymapping                            0x50A5B0

// MapViewMap 
#define MapViewMap__Clear                                          0x60D760
#define MapViewMap__SaveEx                                         0x60E130

#define OtherCharData__GetAltCurrency                              0x6D4250

// StringTable 
#define StringTable__getString                                     0x6A57E0
