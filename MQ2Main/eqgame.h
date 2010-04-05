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
#define __ExpectedVersionDate                                     "Oct  6 2008"
#define __ExpectedVersionTime                                     "14:57:03"
#define __ActualVersionDate                                        0x75E8E4
#define __ActualVersionTime                                        0x75E8F0

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FFA30
#define __MemChecker1                                              0x69E920
#define __MemChecker2                                              0x5542D0
#define __MemChecker3                                              0x554220
#define __MemChecker4                                              0x661AC0
#define __EncryptPad0                                              0x7C0360
#define __EncryptPad1                                              0x7CA848
#define __EncryptPad2                                              0x7C2D88
#define __EncryptPad3                                              0x7C2988
#define __EncryptPad4                                              0x7C9F28

// Direct Input
#define DI8__Main                                                  0xA2D56C
#define DI8__Keyboard                                              0xA2D570
#define DI8__Mouse                                                 0xA2D574
#define __AltTimerReady                                            0x9B8052
#define __Attack                                                   0xA17AEA
#define __Autofire                                                 0xA17AEB
#define __BindList                                                 0x7BB3C0
#define __Clicks                                                   0x9B6D68
#define __CommandList                                              0x7BBC20
#define __CurrentMapLabel                                          0xA58790
#define __CurrentSocial                                            0x7B75EC
#define __DoAbilityAvailable                                       0x9B7FEC
#define __DoAbilityList                                            0x9ED600
#define __do_loot                                                  0x4A75C0
#define __DrawHandler                                              0xA67B94
#define __GroupCount                                               0x99741A
#define __Guilds                                                   0x998F98
#define __gWorld                                                   0x998ED4
#define __HotkeyPage                                               0xA149EC
#define __HWnd                                                     0xA2D2AC
#define __InChatMode                                               0x9B6CA0
#define __LastTell                                                 0x9B8958
#define __LMouseHeldTime                                           0x9B6D88
#define __Mouse                                                    0xA2D578
#define __MouseLook                                                0x9B6D36
#define __NetStatusToggle                                          0x9B6D38
#define __PCNames                                                  0x9B83A8
#define __RangeAttackReady                                         0x9B8050
#define __RMouseHeldTime                                           0x9B6D84
#define __RunWalkState                                             0x9B6CA4
#define __ScreenMode                                               0x8E6CF0
#define __ScreenX                                                  0x9B6C58
#define __ScreenY                                                  0x9B6C5C
#define __ScreenXMax                                               0x9B6C60
#define __ScreenYMax                                               0x9B6C64
#define __ServerHost                                               0x99735C
#define __ServerName                                               0x9ED5C0
#define __ShiftKeyDown                                             0x9B7308
#define __ShowNames                                                0x9B827C
#define __Socials                                                  0x9ED6C0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x9B0BE8
#define instEQZoneInfo                                             0x9B6ED4
#define instKeypressHandler                                        0xA17BD8
#define pinstActiveBanker                                          0x998F6C
#define pinstActiveCorpse                                          0x998F70
#define pinstActiveGMaster                                         0x998F74
#define pinstActiveMerchant                                        0x998F68
#define pinstAltAdvManager                                         0x8E7B50
#define pinstAuraMgr                                               0x7D05B4
#define pinstBandageTarget                                         0x998F54
#define pinstCamActor                                              0x8E763C
#define pinstCDBStr                                                0x8E6CE0
#define pinstCDisplay                                              0x998F7C
#define pinstCEverQuest                                            0xA2D6F0
#define pinstCharData                                              0x998F38
#define pinstCharSpawn                                             0x998F60
#define pinstControlledMissile                                     0x998F34
#define pinstControlledPlayer                                      0x998F60
#define pinstCSidlManager                                          0xA67318
#define pinstCXWndManager                                          0xA67310
#define instDynamicZone                                            0x9B66A8
#define pinstDZMember                                              0x9B67B8
#define pinstDZTimerInfo                                           0x9B67BC
#define pinstEQItemList                                            0x998F1C
#define instEQMisc                                                 0x8E6C98
#define pinstEQSoundManager                                        0x8E7B74
#define instExpeditionLeader                                       0x9B66F2
#define instExpeditionName                                         0x9B6732
#define pinstGroup                                                 0x997416
#define pinstImeManager                                            0xA6731C
#define pinstLocalPlayer                                           0x998F4C
#define pinstModelPlayer                                           0x998F78
#define pinstPCData                                                0x998F38
#define pinstSkillMgr                                              0xA2A3E4
#define pinstSpawnManager                                          0xA2A364
#define pinstSpellManager                                          0xA2A3E8
#define pinstSpellSets                                             0xA149F0
#define pinstStringTable                                           0x998EF0
#define pinstSwitchManager                                         0x99705C
#define pinstTarget                                                0x998F64
#define pinstTargetObject                                          0x998F3C
#define pinstTargetSwitch                                          0x998F40
#define pinstTaskMember                                            0x8E6C78
#define pinstTrackTarget                                           0x998F58
#define pinstTradeTarget                                           0x998F48
#define instTributeActive                                          0x8E6CBD
#define pinstViewActor                                             0x8E7638
#define pinstWorldData                                             0x998F18


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x7CDE60
#define pinstCAudioTriggersWindow                                  0x7CDE2C
#define pinstCCharacterSelect                                      0x8E754C
#define pinstCFacePick                                             0x8E7500
#define pinstCNoteWnd                                              0x8E7504
#define pinstCBookWnd                                              0x8E7508
#define pinstCPetInfoWnd                                           0x8E750C
#define pinstCTrainWnd                                             0x8E7510
#define pinstCSkillsWnd                                            0x8E7514
#define pinstCSkillsSelectWnd                                      0x8E7518
#define pinstCCombatSkillSelectWnd                                 0x8E751C
#define pinstCFriendsWnd                                           0x8E7520
#define pinstCAuraWnd                                              0x8E7524
#define pinstCRespawnWnd                                           0x8E7528
#define pinstCBandolierWnd                                         0x8E752C
#define pinstCPotionBeltWnd                                        0x8E7530
#define pinstCAAWnd                                                0x8E7534
#define pinstCGroupSearchFiltersWnd                                0x8E7538
#define pinstCLoadskinWnd                                          0x8E753C
#define pinstCAlarmWnd                                             0x8E7540
#define pinstCMusicPlayerWnd                                       0x8E7544
#define pinstCMailWnd                                              0x8E7550
#define pinstCMailCompositionWnd                                   0x8E7554
#define pinstCMailAddressBookWnd                                   0x8E7558
#define pinstCRaidWnd                                              0x8E7560
#define pinstCRaidOptionsWnd                                       0x8E7564
#define pinstCBreathWnd                                            0x8E7568
#define pinstCMapViewWnd                                           0x8E756C
#define pinstCMapToolbarWnd                                        0x8E7570
#define pinstCEditLabelWnd                                         0x8E7574
#define pinstCTargetWnd                                            0x8E7578
#define pinstCColorPickerWnd                                       0x8E757C
#define pinstCPlayerWnd                                            0x8E7580
#define pinstCOptionsWnd                                           0x8E7584
#define pinstCBuffWindowNORMAL                                     0x8E7588
#define pinstCBuffWindowSHORT                                      0x8E758C
#define pinstCharacterCreation                                     0x8E7590
#define pinstCCursorAttachment                                     0x8E7594
#define pinstCCastingWnd                                           0x8E7598
#define pinstCCastSpellWnd                                         0x8E759C
#define pinstCSpellBookWnd                                         0x8E75A0
#define pinstCInventoryWnd                                         0x8E75A4
#define pinstCBankWnd                                              0x8E75A8
#define pinstCQuantityWnd                                          0x8E75AC
#define pinstCLootWnd                                              0x8E75B0
#define pinstCActionsWnd                                           0x8E75B4
#define pinstCCombatAbilityWnd                                     0x8E75B8
#define pinstCMerchantWnd                                          0x8E75BC
#define pinstCTradeWnd                                             0x8E75C0
#define pinstCSelectorWnd                                          0x8E75C4
#define pinstCBazaarWnd                                            0x8E75C8
#define pinstCBazaarSearchWnd                                      0x8E75CC
#define pinstCGiveWnd                                              0x8E75D0
#define pinstCTrackingWnd                                          0x8E75D4
#define pinstCInspectWnd                                           0x8E75D8
#define pinstCSocialEditWnd                                        0x8E75DC
#define pinstCFeedbackWnd                                          0x8E75E0
#define pinstCBugReportWnd                                         0x8E75E4
#define pinstCVideoModesWnd                                        0x8E75E8
#define pinstCTextEntryWnd                                         0x8E75F0
#define pinstCFileSelectionWnd                                     0x8E75F4
#define pinstCCompassWnd                                           0x8E75F8
#define pinstCPlayerNotesWnd                                       0x8E75FC
#define pinstCGemsGameWnd                                          0x8E7600
#define pinstCTimeLeftWnd                                          0x8E7604
#define pinstCPetitionQWnd                                         0x8E7608
#define pinstCSoulmarkWnd                                          0x8E760C
#define pinstCStoryWnd                                             0x8E7610
#define pinstCJournalTextWnd                                       0x8E7614
#define pinstCJournalCatWnd                                        0x8E7618
#define pinstCBodyTintWnd                                          0x8E761C
#define pinstCServerListWnd                                        0x8E7620
#define pinstCAvaZoneWnd                                           0x8E7624
#define pinstCBlockedBuffWnd                                       0x8E7628
#define pinstCBlockedPetBuffWnd                                    0x8E762C
#define pinstCInvSlotMgr                                           0x8E7630
#define pinstCContainerMgr                                         0x8E7634
#define pinstCAdventureLeaderboardWnd                              0xA55CD8
#define pinstCAdventureRequestWnd                                  0xA55CF4
#define pinstCAltStorageWnd                                        0xA55D54
#define pinstCAdventureStatsWnd                                    0xA55D10
#define pinstCBarterMerchantWnd                                    0xA55F20
#define pinstCBarterSearchWnd                                      0xA55F3C
#define pinstCBarterWnd                                            0xA55F58
#define pinstCChatManager                                          0xA561FC
#define pinstCDynamicZoneWnd                                       0xA562F4
#define pinstCEQMainWnd                                            0xA56368
#define pinstCFellowshipWnd                                        0xA563CC
#define pinstCFindLocationWnd                                      0xA56400
#define pinstCGroupSearchWnd                                       0xA564B0
#define pinstCGroupWnd                                             0xA564CC
#define pinstCGuildBankWnd                                         0xA564E8
#define pinstCGuildMgmtWnd                                         0xA58508
#define pinstCGuildTributeMasterWnd                                0xA58528
#define pinstCHotButtonWnd                                         0xA58544
#define pinstCHotButtonWnd1                                        0xA58544
#define pinstCHotButtonWnd2                                        0xA58548
#define pinstCHotButtonWnd3                                        0xA5854C
#define pinstCHotButtonWnd4                                        0xA58550
#define pinstCItemDisplayManager                                   0xA585FC
#define pinstCItemExpTransferWnd                                   0xA5861C
#define pinstCLeadershipWnd                                        0xA586B8
#define pinstCLFGuildWnd                                           0xA586D4
#define pinstCMIZoneSelectWnd                                      0xA58828
#define pinstCAdventureMerchantWnd                                 0xA58920
#define pinstCConfirmationDialog                                   0xA5893C
#define pinstCPopupWndManager                                      0xA5893C
#define pinstCProgressionSelectionWnd                              0xA58970
#define pinstCPvPLeaderboardWnd                                    0xA5898C
#define pinstCPvPStatsWnd                                          0xA589A8
#define pinstCSystemInfoDialogBox                                  0xA58A58
#define pinstCTargetOfTargetWnd                                    0xA59364
#define pinstCTaskSelectWnd                                        0xA59398
#define pinstCTaskTemplateSelectWnd                                0xA593B4
#define pinstCTaskWnd                                              0xA593D0
#define pinstCTipWndOFDAY                                          0xA5944C
#define pinstCTipWndCONTEXT                                        0xA59450
#define pinstCTitleWnd                                             0xA5946C
#define pinstCTradeskillWnd                                        0xA594B0
#define pinstCTributeBenefitWnd                                    0xA594FC
#define pinstCTributeMasterWnd                                     0xA59518
#define pinstCContextMenuManager                                   0xA67374
#define pinstCVoiceMacroWnd                                        0xA2A5CC
#define pinstCHtmlWnd                                              0xA2A5E8


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4BA0E0
#define __ConvertItemTags                                          0x4AC9D0
#define __ExecuteCmd                                               0x49B970
#define __get_melee_range                                          0x4A0D70
#define __GetGaugeValueFromEQ                                      0x62A460
#define __GetLabelFromEQ                                           0x62AF00
#define __NewUIINI                                                 0x62A040
#define __ProcessGameEvents                                        0x4E9AE0
#define CrashDetected                                              0x552F90
#define DrawNetStatus                                              0x507A20
#define Util__FastTime                                             0x69F030


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x474D20
#define AltAdvManager__IsAbilityReady                              0x474D60
#define AltAdvManager__GetAltAbility                               0x474F40

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x56AF20

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x574200

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6CB1A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x58A090
#define CChatManager__InitContextMenu                              0x58A830

// CChatService
#define CChatService__GetNumberOfFriends                           0x68F110
#define CChatService__GetFriendName                                0x68F120

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x58EA30
#define CChatWindow__WndNotification                               0x58F480

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6B0AA0
#define CComboWnd__Draw                                            0x6B0C50
#define CComboWnd__GetCurChoice                                    0x6B0A40
#define CComboWnd__GetListRect                                     0x6B0F20
#define CComboWnd__GetTextRect                                     0x6B0AD0
#define CComboWnd__InsertChoice                                    0x6B0F90
#define CComboWnd__SetColors                                       0x6B09D0
#define CComboWnd__SetChoice                                       0x6B0A00

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5960D0
#define CContainerWnd__vftable                                     0x7654E8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x463A60
#define CDisplay__GetClickedActor                                  0x4610F0
#define CDisplay__GetUserDefinedColor                              0x460210
#define CDisplay__GetWorldFilePath                                 0x45F760
#define CDisplay__is3dON                                           0x45E8C0
#define CDisplay__ReloadUI                                         0x471F40
#define CDisplay__WriteTextHD2                                     0x4641D0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x564E20
#define CEditBaseWnd__SetSel                                       0x6D61F0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6BE840
#define CEditWnd__GetCharIndexPt                                   0x6BF690
#define CEditWnd__GetDisplayString                                 0x6BE9D0
#define CEditWnd__GetHorzOffset                                    0x6BEC60
#define CEditWnd__GetLineForPrintableChar                          0x6BF140
#define CEditWnd__GetSelStartPt                                    0x6BF8E0
#define CEditWnd__GetSTMLSafeText                                  0x6BEE00
#define CEditWnd__PointFromPrintableChar                           0x6BF250
#define CEditWnd__SelectableCharFromPoint                          0x6BF3D0
#define CEditWnd__SetEditable                                      0x6BEDD0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4CD640
#define CEverQuest__DropHeldItemOnGround                           0x4D19B0
#define CEverQuest__dsp_chat                                       0x4D2ED0
#define CEverQuest__DoTellWindow                                   0x4D1B30
#define CEverQuest__EnterZone                                      0x4E84F0
#define CEverQuest__GetBodyTypeDesc                                0x4CAA40
#define CEverQuest__GetClassDesc                                   0x4CA1A0
#define CEverQuest__GetClassThreeLetterCode                        0x4CA7A0
#define CEverQuest__GetDeityDesc                                   0x4CB0B0
#define CEverQuest__GetLangDesc                                    0x4CADD0
#define CEverQuest__GetRaceDesc                                    0x4CB080
#define CEverQuest__InterpretCmd                                   0x4D3940
#define CEverQuest__LeftClickedOnPlayer                            0x4E6CC0
#define CEverQuest__LMouseUp                                       0x4E92C0
#define CEverQuest__RightClickedOnPlayer                           0x4E7090
#define CEverQuest__RMouseUp                                       0x4E8AF0
#define CEverQuest__SetGameState                                   0x4CDAC0
#define CEverQuest__Emote                                          0x4D30D0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5A2C40
#define CGaugeWnd__CalcLinesFillRect                               0x5A2CA0
#define CGaugeWnd__Draw                                            0x5A30B0

// CGuild
#define CGuild__FindMemberByName                                   0x418120

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5BACC0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5C4220
#define CInvSlotMgr__MoveItem                                      0x5C43C0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5C2BE0
#define CInvSlot__SliderComplete                                   0x5C30F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5D3050
#define CItemDisplayWnd__SetSpell                                  0x627E10

// CLabel 
#define CLabel__Draw                                               0x5D8960

// CListWnd 
#define CListWnd__AddColumn                                        0x6B07E0
#define CListWnd__AddColumn1                                       0x6B0300
#define CListWnd__AddLine                                          0x6AFDE0
#define CListWnd__AddString                                        0x6AFFE0
#define CListWnd__CalculateFirstVisibleLine                        0x6AD1C0
#define CListWnd__CalculateVSBRange                                0x6AEE20
#define CListWnd__ClearAllSel                                      0x6AC8F0
#define CListWnd__CloseAndUpdateEditWindow                         0x6AD7F0
#define CListWnd__Compare                                          0x6ADB90
#define CListWnd__Draw                                             0x6AEB10
#define CListWnd__DrawColumnSeparators                             0x6AE980
#define CListWnd__DrawHeader                                       0x6ACAC0
#define CListWnd__DrawItem                                         0x6AE2A0
#define CListWnd__DrawLine                                         0x6AE620
#define CListWnd__DrawSeparator                                    0x6AEA20
#define CListWnd__EnsureVisible                                    0x6AD210
#define CListWnd__ExtendSel                                        0x6AE1C0
#define CListWnd__GetColumnMinWidth                                0x6AC700
#define CListWnd__GetColumnWidth                                   0x6AC640
#define CListWnd__GetCurSel                                        0x6AC120
#define CListWnd__GetHeaderRect                                    0x6AC210
#define CListWnd__GetItemAtPoint                                   0x6AD510
#define CListWnd__GetItemAtPoint1                                  0x6AD580
#define CListWnd__GetItemData                                      0x6AC3F0
#define CListWnd__GetItemHeight                                    0x6ACF50
#define CListWnd__GetItemIcon                                      0x6AC580
#define CListWnd__GetItemRect                                      0x6AD2F0
#define CListWnd__GetItemText                                      0x6AC430
#define CListWnd__GetSelList                                       0x6B01E0
#define CListWnd__GetSeparatorRect                                 0x6ADAD0
#define CListWnd__RemoveLine                                       0x6B0190
#define CListWnd__SetColors                                        0x6AC180
#define CListWnd__SetColumnJustification                           0x6AC760
#define CListWnd__SetColumnWidth                                   0x6AC6C0
#define CListWnd__SetCurSel                                        0x6AC160
#define CListWnd__SetItemColor                                     0x6AFA50
#define CListWnd__SetItemData                                      0x6AC990
#define CListWnd__SetItemText                                      0x6AF9D0
#define CListWnd__ShiftColumnSeparator                             0x6AE130
#define CListWnd__Sort                                             0x6B0810
#define CListWnd__ToggleSel                                        0x6AC860

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5EDA70

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5F3BF0
#define CMerchantWnd__RequestBuyItem                               0x5F4F80
#define CMerchantWnd__RequestSellItem                              0x5F3E50
#define CMerchantWnd__SelectBuySellSlot                            0x5F4CB0

// CObfuscator
#define CObfuscator__doit                                          0x66AD60

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6C69E0
#define CSidlManager__CreateLabel                                  0x620DC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x566F50
#define CSidlScreenWnd__CalculateVSBRange                          0x6CC720
#define CSidlScreenWnd__ConvertToRes                               0x6D60D0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6B7DC0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6B8E60
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6B8F10
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6B8650
#define CSidlScreenWnd__DrawSidlPiece                              0x6B7AA0
#define CSidlScreenWnd__EnableIniStorage                           0x6B76F0
#define CSidlScreenWnd__GetSidlPiece                               0x6B7CA0
#define CSidlScreenWnd__Init1                                      0x6B8CC0
#define CSidlScreenWnd__LoadIniInfo                                0x6B7E70
#define CSidlScreenWnd__LoadIniListWnd                             0x6B7840
#define CSidlScreenWnd__LoadSidlScreen                             0x6B8890
#define CSidlScreenWnd__StoreIniInfo                               0x6B7300
#define CSidlScreenWnd__WndNotification                            0x6B8A40
#define CSidlScreenWnd__GetChildItem                               0x6B7750

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x529D10

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6D7590
#define CSliderWnd__SetValue                                       0x6D7690
#define CSliderWnd__SetNumTicks                                    0x6D7C10

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x626570

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6D43A0
#define CStmlWnd__CalculateVSBRange                                0x6CC720
#define CStmlWnd__CanBreakAtCharacter                              0x6CC860
#define CStmlWnd__FastForwardToEndOfTag                            0x6CD370
#define CStmlWnd__ForceParseNow                                    0x6D47F0
#define CStmlWnd__GetNextTagPiece                                  0x6CD290
#define CStmlWnd__GetSTMLText                                      0x58E9D0
#define CStmlWnd__GetThisChar                                      0x6F8570
#define CStmlWnd__GetVisiableText                                  0x6CE5A0
#define CStmlWnd__InitializeWindowVariables                        0x6D06E0
#define CStmlWnd__MakeStmlColorTag                                 0x6CBE20
#define CStmlWnd__MakeWndNotificationTag                           0x6CBEC0
#define CStmlWnd__SetSTMLText                                      0x6D0800
#define CStmlWnd__StripFirstSTMLLines                              0x6D4120
#define CStmlWnd__UpdateHistoryString                              0x6CEE00

// CTabWnd 
#define CTabWnd__Draw                                              0x6D8A20
#define CTabWnd__DrawCurrentPage                                   0x6D83B0
#define CTabWnd__DrawTab                                           0x6D8190
#define CTabWnd__GetCurrentPage                                    0x6D86B0
#define CTabWnd__GetPageClientRect                                 0x6D7E60
#define CTabWnd__GetPageFromTabIndex                               0x6D80C0
#define CTabWnd__GetPageInnerRect                                  0x6D7EC0
#define CTabWnd__GetTabInnerRect                                   0x6D8040
#define CTabWnd__GetTabRect                                        0x6D7F50
#define CTabWnd__IndexInBounds                                     0x6D815D
#define CTabWnd__InsertPage                                        0x6D8C90
#define CTabWnd__SetPage                                           0x6D86F0
#define CTabWnd__SetPageRect                                       0x6D8950
#define CTabWnd__UpdatePage                                        0x6D8C10

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x414610

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6B9270

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6E0190

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6ABE90

// CXRect 
#define CXRect__CenterPoint                                        0x56A5B0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4128C0
#define CXStr__CXStr1                                              0x6A6E70
#define CXStr__CXStr3                                              0x6A0780
#define CXStr__dCXStr                                              0x4531B0
#define CXStr__operator_equal1                                     0x6A0940
#define CXStr__operator_plus_equal1                                0x6A1840

// CXWnd 
#define CXWnd__BringToTop                                          0x6B1820
#define CXWnd__Center                                              0x6B5140
#define CXWnd__ClrFocus                                            0x6B1510
#define CXWnd__DoAllDrawing                                        0x6B5EB0
#define CXWnd__DrawChildren                                        0x6B5FE0
#define CXWnd__DrawColoredRect                                     0x6B1A90
#define CXWnd__DrawTooltip                                         0x6B5CE0
#define CXWnd__DrawTooltipAtPoint                                  0x6B4EF0
#define CXWnd__GetBorderFrame                                      0x6B1F10
#define CXWnd__GetChildWndAt                                       0x6B4A20
#define CXWnd__GetClientClipRect                                   0x6B1E50
#define CXWnd__GetScreenClipRect                                   0x6B5360
#define CXWnd__GetScreenRect                                       0x6B2120
#define CXWnd__GetTooltipRect                                      0x6B1CB0
#define CXWnd__GetWindowTextA                                      0x55DB90
#define CXWnd__IsActive                                            0x6BA3A0
#define CXWnd__IsDescendantOf                                      0x6B1EC0
#define CXWnd__IsReallyVisible                                     0x6B4A00
#define CXWnd__IsType                                              0x6D9EA0
#define CXWnd__Move                                                0x6B4620
#define CXWnd__Move1                                               0x6B5B40
#define CXWnd__ProcessTransition                                   0x6B17E0
#define CXWnd__Refade                                              0x6B15C0
#define CXWnd__Resize                                              0x6B21E0
#define CXWnd__Right                                               0x6B52A0
#define CXWnd__SetFocus                                            0x6B3800
#define CXWnd__SetKeyTooltip                                       0x6B23F0
#define CXWnd__SetMouseOver                                        0x6B23C0
#define CXWnd__StartFade                                           0x6B1860
#define CXWnd__GetChildItem                                        0x6B54F0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6BB7B0
#define CXWndManager__DrawWindows                                  0x6BB3C0
#define CXWndManager__GetKeyboardFlags                             0x6BA030
#define CXWndManager__HandleKeyboardMsg                            0x6BA5A0
#define CXWndManager__RemoveWnd                                    0x6BA4C0

// CDBStr
#define CDBStr__GetString                                          0x45D220

// EQ_Character 
#define EQ_Character__CastRay                                      0x7046C0
#define EQ_Character__CastSpell                                    0x4259D0
#define EQ_Character__Cur_HP                                       0x432790
#define EQ_Character__GetAACastingTimeModifier                     0x4200F0
#define EQ_Character__GetCharInfo2                                 0x680AF0
#define EQ_Character__GetFocusCastingTimeModifier                  0x41BCC0
#define EQ_Character__GetFocusRangeModifier                        0x41BE00
#define EQ_Character__Max_Endurance                                0x50BF80
#define EQ_Character__Max_HP                                       0x42D850
#define EQ_Character__Max_Mana                                     0x50D920
#define EQ_Character__doCombatAbility                              0x50C8B0
#define EQ_Character__UseSkill                                     0x438590
#define EQ_Character__GetConLevel                                  0x508E30

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F7340
#define EQ_Item__GetItemLinkHash                                   0x674870
#define EQ_Item__IsStackable                                       0x66B640

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x475E10
#define EQ_LoadingS__Array                                         0x7B98A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x510840
#define EQ_PC__GetAltAbilityIndex                                  0x679060
#define EQ_PC__GetCombatAbility                                    0x6790F0
#define EQ_PC__GetCombatAbilityTimer                               0x6791A0
#define EQ_PC__GetItemTimerValue                                   0x50B790
#define EQ_PC__HasLoreItem                                         0x50ED10

// EQItemList 
#define EQItemList__dEQItemList                                    0x49F4A0
#define EQItemList__EQItemList                                     0x49F3F0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45CBD0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x515020
#define EQPlayer__dEQPlayer                                        0x519000
#define EQPlayer__DoAttack                                         0x525F30
#define EQPlayer__EQPlayer                                         0x51CCB0
#define EQPlayer__SetNameSpriteState                               0x516FC0
#define EQPlayer__SetNameSpriteTint                                0x515090
#define EQPlayer__IsBodyType_j                                     0x704090

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x51DD70
#define EQPlayerManager__GetSpawnByName                            0x51DF50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F8FE0
#define KeypressHandler__AttachKeyToEqCommand                      0x4F9020
#define KeypressHandler__ClearCommandStateArray                    0x4F8DF0
#define KeypressHandler__HandleKeyDown                             0x4F79A0
#define KeypressHandler__HandleKeyUp                               0x4F7CB0
#define KeypressHandler__SaveKeymapping                            0x4F8EC0

// MapViewMap 
#define MapViewMap__Clear                                          0x5E9140
#define MapViewMap__SaveEx                                         0x5E9B10

#define OtherCharData__GetAltCurrency                              0x697810

// StringTable 
#define StringTable__getString                                     0x66AFE0
