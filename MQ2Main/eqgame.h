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
#define __ExpectedVersionDate                                     "Oct 11 2010"
#define __ExpectedVersionTime                                     "14:40:36"
#define __ActualVersionDate                                        0x8787B0
#define __ActualVersionTime                                        0x8787BC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x524EB0
#define __MemChecker1                                              0x795EB0
#define __MemChecker2                                              0x5960D0
#define __MemChecker3                                              0x596020
#define __MemChecker4                                              0x7AFE30
#define __EncryptPad0                                              0x90E4E0
#define __EncryptPad1                                              0x91A0E8
#define __EncryptPad2                                              0x911220
#define __EncryptPad3                                              0x910E20
#define __EncryptPad4                                              0x91BB18
#define __AC1                                                      0x6A3A40
#define __AC2                                                      0x4E7EA5
#define __AC3                                                      0x4FA868
#define __AC4                                                      0x4FFB98
#define __AC5                                                      0x50BC5C
#define __AC6                                                      0x50F3AE
#define __AC7                                                      0x50786B
#define __AC1_Data                                                 0x86046D

// Direct Input
#define DI8__Main                                                  0xB77D9C
#define DI8__Keyboard                                              0xB77DA0
#define DI8__Mouse                                                 0xB77DA4
#define __AltTimerReady                                            0xAFC93E
#define __Attack                                                   0xB5FFE2
#define __Autofire                                                 0xB5FFE3
#define __BindList                                                 0x908AE8
#define __Clicks                                                   0xAFB5F8
#define __CommandList                                              0x9094B8
#define __CurrentMapLabel                                          0xBA3038
#define __CurrentSocial                                            0x90495C
#define __DoAbilityAvailable                                       0xAFC8D8
#define __DoAbilityList                                            0xB31F00
#define __do_loot                                                  0x4BD110
#define __DrawHandler                                              0x1157314
#define __GroupCount                                               0xAF53EA
#define __Guilds                                                   0xAFA9D8
#define __gWorld                                                   0xAF72A4
#define __HotkeyPage                                               0xB592EC
#define __HWnd                                                     0xB77AD8
#define __InChatMode                                               0xAFB530
#define __LastTell                                                 0xAFD258
#define __LMouseHeldTime                                           0xAFB664
#define __Mouse                                                    0xB77DA8
#define __MouseLook                                                0xAFB5C6
#define __MouseEventTime                                           0xB60144
#define __NetStatusToggle                                          0xAFB5C9
#define __PCNames                                                  0xAFCC9C
#define __RangeAttackReady                                         0xAFC93C
#define __RMouseHeldTime                                           0xAFB660
#define __RunWalkState                                             0xAFB534
#define __ScreenMode                                               0xA44C40
#define __ScreenX                                                  0xAFB4E8
#define __ScreenY                                                  0xAFB4EC
#define __ScreenXMax                                               0xAFB4F0
#define __ScreenYMax                                               0xAFB4F4
#define __ServerHost                                               0xAF532C
#define __ServerName                                               0xB31EC0
#define __ShiftKeyDown                                             0xAFBBF0
#define __ShowNames                                                0xAFCB70
#define __Socials                                                  0xB31FC0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xAF7370
#define instEQZoneInfo                                             0xAFB7B0
#define instKeypressHandler                                        0xB60128
#define pinstActiveBanker                                          0xAF7348
#define pinstActiveCorpse                                          0xAF734C
#define pinstActiveGMaster                                         0xAF7350
#define pinstActiveMerchant                                        0xAF7344
#define pinstAltAdvManager                                         0xA45AD8
#define pinstAuraMgr                                               0x92E4FC
#define pinstBandageTarget                                         0xAF7330
#define pinstCamActor                                              0xA455C4
#define pinstCDBStr                                                0xA44C34
#define pinstCDisplay                                              0xAF7358
#define pinstCEverQuest                                            0xB77F20
#define pinstCharData                                              0xAF7314
#define pinstCharSpawn                                             0xAF733C
#define pinstControlledMissile                                     0xAF7310
#define pinstControlledPlayer                                      0xAF733C
#define pinstCSidlManager                                          0x11577E4
#define pinstCXWndManager                                          0x11577DC
#define instDynamicZone                                            0xAFB3B8
#define pinstDZMember                                              0xAFB4C8
#define pinstDZTimerInfo                                           0xAFB4CC
#define pinstEQItemList                                            0xAF4600
#define instEQMisc                                                 0xA44BE0
#define pinstEQSoundManager                                        0xA45AFC
#define instExpeditionLeader                                       0xAFB402
#define instExpeditionName                                         0xAFB442
#define pinstGroup                                                 0xAF53E6
#define pinstImeManager                                            0x11577E8
#define pinstLocalPlayer                                           0xAF7328
#define pinstMercenaryData                                         0xB604BC
#define pinstModelPlayer                                           0xAF7354
#define pinstPCData                                                0xAF7314
#define pinstSkillMgr                                              0xB74B8C
#define pinstSpawnManager                                          0xB749A8
#define pinstSpellManager                                          0xB74B98
#define pinstSpellSets                                             0xB592F0
#define pinstStringTable                                           0xAF72C0
#define pinstSwitchManager                                         0xAF502C
#define pinstTarget                                                0xAF7340
#define pinstTargetObject                                          0xAF7318
#define pinstTargetSwitch                                          0xAF731C
#define pinstTaskMember                                            0xA44BC0
#define pinstTrackTarget                                           0xAF7334
#define pinstTradeTarget                                           0xAF7324
#define instTributeActive                                          0xA44C11
#define pinstViewActor                                             0xA455C0
#define pinstWorldData                                             0xAF72F8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x92BDC0
#define pinstCAudioTriggersWindow                                  0x92BD8C
#define pinstCCharacterSelect                                      0xA454A8
#define pinstCFacePick                                             0xA45458
#define pinstCNoteWnd                                              0xA45460
#define pinstCBookWnd                                              0xA45464
#define pinstCPetInfoWnd                                           0xA45468
#define pinstCTrainWnd                                             0xA4546C
#define pinstCSkillsWnd                                            0xA45470
#define pinstCSkillsSelectWnd                                      0xA45474
#define pinstCCombatSkillSelectWnd                                 0xA45478
#define pinstCFriendsWnd                                           0xA4547C
#define pinstCAuraWnd                                              0xA45480
#define pinstCRespawnWnd                                           0xA45484
#define pinstCBandolierWnd                                         0xA45488
#define pinstCPotionBeltWnd                                        0xA4548C
#define pinstCAAWnd                                                0xA45490
#define pinstCGroupSearchFiltersWnd                                0xA45494
#define pinstCLoadskinWnd                                          0xA45498
#define pinstCAlarmWnd                                             0xA4549C
#define pinstCMusicPlayerWnd                                       0xA454A0
#define pinstCMailWnd                                              0xA454AC
#define pinstCMailCompositionWnd                                   0xA454B0
#define pinstCMailAddressBookWnd                                   0xA454B4
#define pinstCRaidWnd                                              0xA454BC
#define pinstCRaidOptionsWnd                                       0xA454C0
#define pinstCBreathWnd                                            0xA454C4
#define pinstCMapViewWnd                                           0xA454C8
#define pinstCMapToolbarWnd                                        0xA454CC
#define pinstCEditLabelWnd                                         0xA454D0
#define pinstCTargetWnd                                            0xA454D4
#define pinstCColorPickerWnd                                       0xA454D8
#define pinstCPlayerWnd                                            0xA454DC
#define pinstCOptionsWnd                                           0xA454E0
#define pinstCBuffWindowNORMAL                                     0xA454E4
#define pinstCBuffWindowSHORT                                      0xA454E8
#define pinstCharacterCreation                                     0xA454EC
#define pinstCCursorAttachment                                     0xA454F0
#define pinstCCastingWnd                                           0xA454F4
#define pinstCCastSpellWnd                                         0xA454F8
#define pinstCSpellBookWnd                                         0xA454FC
#define pinstCInventoryWnd                                         0xA45500
#define pinstCBankWnd                                              0xA45504
#define pinstCQuantityWnd                                          0xA45508
#define pinstCLootWnd                                              0xA4550C
#define pinstCActionsWnd                                           0xA45510
#define pinstCCombatAbilityWnd                                     0xA45514
#define pinstCMerchantWnd                                          0xA45518
#define pinstCTradeWnd                                             0xA4551C
#define pinstCSelectorWnd                                          0xA45520
#define pinstCBazaarWnd                                            0xA45524
#define pinstCBazaarSearchWnd                                      0xA45528
#define pinstCGiveWnd                                              0xA45540
#define pinstCTrackingWnd                                          0xA45544
#define pinstCInspectWnd                                           0xA45548
#define pinstCSocialEditWnd                                        0xA4554C
#define pinstCFeedbackWnd                                          0xA45550
#define pinstCBugReportWnd                                         0xA45554
#define pinstCVideoModesWnd                                        0xA45558
#define pinstCTextEntryWnd                                         0xA45560
#define pinstCFileSelectionWnd                                     0xA45564
#define pinstCCompassWnd                                           0xA45568
#define pinstCPlayerNotesWnd                                       0xA4556C
#define pinstCGemsGameWnd                                          0xA45570
#define pinstCTimeLeftWnd                                          0xA45574
#define pinstCPetitionQWnd                                         0xA45588
#define pinstCSoulmarkWnd                                          0xA4558C
#define pinstCStoryWnd                                             0xA45590
#define pinstCJournalTextWnd                                       0xA45594
#define pinstCJournalCatWnd                                        0xA45598
#define pinstCBodyTintWnd                                          0xA4559C
#define pinstCServerListWnd                                        0xA455A0
#define pinstCAvaZoneWnd                                           0xA455A8
#define pinstCBlockedBuffWnd                                       0xA455AC
#define pinstCBlockedPetBuffWnd                                    0xA455B0
#define pinstCInvSlotMgr                                           0xA455B8
#define pinstCContainerMgr                                         0xA455BC
#define pinstCAdventureLeaderboardWnd                              0xBA0550
#define pinstCAdventureRequestWnd                                  0xBA056C
#define pinstCAltStorageWnd                                        0xBA05CC
#define pinstCAdventureStatsWnd                                    0xBA0588
#define pinstCBarterMerchantWnd                                    0xBA0798
#define pinstCBarterSearchWnd                                      0xBA07B4
#define pinstCBarterWnd                                            0xBA07D0
#define pinstCChatManager                                          0xBA0A74
#define pinstCDynamicZoneWnd                                       0xBA0B6C
#define pinstCEQMainWnd                                            0xBA0BE0
#define pinstCFellowshipWnd                                        0xBA0C44
#define pinstCFindLocationWnd                                      0xBA0C78
#define pinstCGroupSearchWnd                                       0xBA0D28
#define pinstCGroupWnd                                             0xBA0D44
#define pinstCGuildBankWnd                                         0xBA0D60
#define pinstCGuildMgmtWnd                                         0xBA2D98
#define pinstCGuildTributeMasterWnd                                0xBA2DB8
#define pinstCHotButtonWnd                                         0xBA2DEC
#define pinstCHotButtonWnd1                                        0xBA2DEC
#define pinstCHotButtonWnd2                                        0xBA2DF0
#define pinstCHotButtonWnd3                                        0xBA2DF4
#define pinstCHotButtonWnd4                                        0xBA2DF8
#define pinstCItemDisplayManager                                   0xBA2EA4
#define pinstCItemExpTransferWnd                                   0xBA2EC4
#define pinstCLeadershipWnd                                        0xBA2F60
#define pinstCLFGuildWnd                                           0xBA2F7C
#define pinstCMIZoneSelectWnd                                      0xBA30EC
#define pinstCAdventureMerchantWnd                                 0xBA3214
#define pinstCConfirmationDialog                                   0xBA3230
#define pinstCPopupWndManager                                      0xBA3230
#define pinstCProgressionSelectionWnd                              0xBA3264
#define pinstCPvPLeaderboardWnd                                    0xBA3280
#define pinstCPvPStatsWnd                                          0xBA329C
#define pinstCSystemInfoDialogBox                                  0xBA33E0
#define pinstCTargetOfTargetWnd                                    0xBA3EE8
#define pinstCTaskSelectWnd                                        0xBA3F1C
#define pinstCTaskTemplateSelectWnd                                0xBA3F38
#define pinstCTaskWnd                                              0xBA3F54
#define pinstCTipWndOFDAY                                          0xBA3FD0
#define pinstCTipWndCONTEXT                                        0xBA3FD4
#define pinstCTitleWnd                                             0xBA3FF0
#define pinstCTradeskillWnd                                        0xBA4034
#define pinstCTributeBenefitWnd                                    0xBA4080
#define pinstCTributeMasterWnd                                     0xBA409C
#define pinstCContextMenuManager                                   0x1157840
#define pinstCVoiceMacroWnd                                        0xB74D8C
#define pinstCHtmlWnd                                              0xB74DD8


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D0D80
#define __ConvertItemTags                                          0x4C2790
#define __ExecuteCmd                                               0x4AE560
#define __get_melee_range                                          0x4B4540
#define __GetGaugeValueFromEQ                                      0x6A28C0
#define __GetLabelFromEQ                                           0x6A39E0
#define __GetXTargetType                                           0x715E40
#define __LoadFrontEnd                                             0x595000
#define __NewUIINI                                                 0x6A23E0
#define __ProcessGameEvents                                        0x507FE0
#define CrashDetected                                              0x594E00
#define DrawNetStatus                                              0x5313A0
#define Util__FastTime                                             0x796620


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483610
#define AltAdvManager__IsAbilityReady                              0x483650
#define AltAdvManager__GetAltAbility                               0x4838B0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x438E10

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5B28F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5BC6E0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x75CE20

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5D4A40
#define CChatManager__InitContextMenu                              0x5D5210

// CChatService
#define CChatService__GetNumberOfFriends                           0x70B210
#define CChatService__GetFriendName                                0x70B220

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5D94E0
#define CChatWindow__Clear                                         0x5D9E40
#define CChatWindow__WndNotification                               0x5DA030

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x746E30
#define CComboWnd__Draw                                            0x746FF0
#define CComboWnd__GetCurChoice                                    0x746CF0
#define CComboWnd__GetListRect                                     0x7472E0
#define CComboWnd__GetTextRect                                     0x746E60
#define CComboWnd__InsertChoice                                    0x747350
#define CComboWnd__SetColors                                       0x746C80
#define CComboWnd__SetChoice                                       0x746CB0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5E2B40
#define CContainerWnd__vftable                                     0x87FEB0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x476060
#define CDisplay__GetClickedActor                                  0x46EF80
#define CDisplay__GetUserDefinedColor                              0x46DB80
#define CDisplay__GetWorldFilePath                                 0x46D010
#define CDisplay__is3dON                                           0x46C140
#define CDisplay__ReloadUI                                         0x480790
#define CDisplay__WriteTextHD2                                     0x471DF0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5ACA00
#define CEditBaseWnd__SetSel                                       0x76A410

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x74FE80
#define CEditWnd__GetCharIndexPt                                   0x750E40
#define CEditWnd__GetDisplayString                                 0x750010
#define CEditWnd__GetHorzOffset                                    0x7502A0
#define CEditWnd__GetLineForPrintableChar                          0x7508F0
#define CEditWnd__GetSelStartPt                                    0x751090
#define CEditWnd__GetSTMLSafeText                                  0x750440
#define CEditWnd__PointFromPrintableChar                           0x750A00
#define CEditWnd__SelectableCharFromPoint                          0x750B80
#define CEditWnd__SetEditable                                      0x750410

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4E85D0
#define CEverQuest__DropHeldItemOnGround                           0x4F5C50
#define CEverQuest__dsp_chat                                       0x4EE9D0
#define CEverQuest__DoTellWindow                                   0x4ED160
#define CEverQuest__EnterZone                                      0x4FFB30
#define CEverQuest__GetBodyTypeDesc                                0x4E5440
#define CEverQuest__GetClassDesc                                   0x4E4C80
#define CEverQuest__GetClassThreeLetterCode                        0x4E5280
#define CEverQuest__GetDeityDesc                                   0x4E5AB0
#define CEverQuest__GetLangDesc                                    0x4E57D0
#define CEverQuest__GetRaceDesc                                    0x4E5A80
#define CEverQuest__InterpretCmd                                   0x4EF530
#define CEverQuest__LeftClickedOnPlayer                            0x501C80
#define CEverQuest__LMouseUp                                       0x507830
#define CEverQuest__RightClickedOnPlayer                           0x5066C0
#define CEverQuest__RMouseUp                                       0x507830
#define CEverQuest__SetGameState                                   0x4E8A60
#define CEverQuest__Emote                                          0x4EEBF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5EF7C0
#define CGaugeWnd__CalcLinesFillRect                               0x5EF820
#define CGaugeWnd__Draw                                            0x5EFC70

// CGuild
#define CGuild__FindMemberByName                                   0x41B810

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x608A50

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x613D00
#define CInvSlotMgr__MoveItem                                      0x614110

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x6131B0
#define CInvSlot__SliderComplete                                   0x611C70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x614DC0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6A0170
#define CItemDisplayWnd__UpdateStrings                             0x615C90

// CLabel 
#define CLabel__Draw                                               0x629E60

// CListWnd 
#define CListWnd__AddColumn                                        0x73FB60
#define CListWnd__AddColumn1                                       0x73F220
#define CListWnd__AddLine                                          0x73ED80
#define CListWnd__AddString                                        0x73EF20
#define CListWnd__CalculateFirstVisibleLine                        0x73B090
#define CListWnd__CalculateVSBRange                                0x73D3C0
#define CListWnd__ClearAllSel                                      0x73A5E0
#define CListWnd__CloseAndUpdateEditWindow                         0x73E3F0
#define CListWnd__Compare                                          0x73BA90
#define CListWnd__Draw                                             0x73D000
#define CListWnd__DrawColumnSeparators                             0x73CE70
#define CListWnd__DrawHeader                                       0x73A870
#define CListWnd__DrawItem                                         0x73C490
#define CListWnd__DrawLine                                         0x73CAF0
#define CListWnd__DrawSeparator                                    0x73CF10
#define CListWnd__EnsureVisible                                    0x73B1F0
#define CListWnd__ExtendSel                                        0x73C3B0
#define CListWnd__GetColumnMinWidth                                0x73A2B0
#define CListWnd__GetColumnWidth                                   0x73A1F0
#define CListWnd__GetCurSel                                        0x739A70
#define CListWnd__GetHeaderRect                                    0x739BD0
#define CListWnd__GetItemAtPoint                                   0x73B4C0
#define CListWnd__GetItemAtPoint1                                  0x73B530
#define CListWnd__GetItemData                                      0x739DF0
#define CListWnd__GetItemHeight                                    0x73AD00
#define CListWnd__GetItemIcon                                      0x739FD0
#define CListWnd__GetItemRect                                      0x73B2C0
#define CListWnd__GetItemText                                      0x739E80
#define CListWnd__GetSelList                                       0x73F100
#define CListWnd__GetSeparatorRect                                 0x73B9E0
#define CListWnd__RemoveLine                                       0x73F0B0
#define CListWnd__SetColors                                        0x739B40
#define CListWnd__SetColumnJustification                           0x73A450
#define CListWnd__SetColumnWidth                                   0x73A270
#define CListWnd__SetCurSel                                        0x739AB0
#define CListWnd__SetItemColor                                     0x73E0B0
#define CListWnd__SetItemData                                      0x73A680
#define CListWnd__SetItemText                                      0x73DE90
#define CListWnd__ShiftColumnSeparator                             0x73DD00
#define CListWnd__Sort                                             0x7402A0
#define CListWnd__ToggleSel                                        0x73A550

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x63FDE0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x650BB0
#define CMerchantWnd__RequestBuyItem                               0x654470
#define CMerchantWnd__RequestSellItem                              0x673340
#define CMerchantWnd__SelectBuySellSlot                            0x651ED0

// CObfuscator
#define CObfuscator__doit                                          0x6DB410

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x758740
#define CSidlManager__CreateLabel                                  0x699010

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x748AF0
#define CSidlScreenWnd__CalculateVSBRange                          0x5AEAB0
#define CSidlScreenWnd__ConvertToRes                               0x76A2F0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x748FB0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x74A0A0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x74A150
#define CSidlScreenWnd__dCSidlScreenWnd                            0x749860
#define CSidlScreenWnd__DrawSidlPiece                              0x748C70
#define CSidlScreenWnd__EnableIniStorage                           0x7487E0
#define CSidlScreenWnd__GetSidlPiece                               0x748E80
#define CSidlScreenWnd__Init1                                      0x749F00
#define CSidlScreenWnd__LoadIniInfo                                0x749060
#define CSidlScreenWnd__LoadIniListWnd                             0x748930
#define CSidlScreenWnd__LoadSidlScreen                             0x749AB0
#define CSidlScreenWnd__StoreIniInfo                               0x7483E0
#define CSidlScreenWnd__StoreIniVis                                0x748770
#define CSidlScreenWnd__WndNotification                            0x749C80
#define CSidlScreenWnd__GetChildItem                               0x748840

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x562820

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x76ACF0
#define CSliderWnd__SetValue                                       0x76ADF0
#define CSliderWnd__SetNumTicks                                    0x76B3A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x69DD60

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x767980
#define CStmlWnd__CalculateHSBRange                                0x75F0B0
#define CStmlWnd__CalculateVSBRange                                0x75F020
#define CStmlWnd__CanBreakAtCharacter                              0x75F210
#define CStmlWnd__FastForwardToEndOfTag                            0x75FEE0
#define CStmlWnd__ForceParseNow                                    0x767EB0
#define CStmlWnd__GetNextTagPiece                                  0x75FE00
#define CStmlWnd__GetSTMLText                                      0x5D9480
#define CStmlWnd__GetThisChar                                      0x78F300
#define CStmlWnd__GetVisiableText                                  0x761330
#define CStmlWnd__InitializeWindowVariables                        0x763900
#define CStmlWnd__MakeStmlColorTag                                 0x75DF40
#define CStmlWnd__MakeWndNotificationTag                           0x75DFE0
#define CStmlWnd__SetSTMLText                                      0x763A20
#define CStmlWnd__StripFirstSTMLLines                              0x767630
#define CStmlWnd__UpdateHistoryString                              0x761BC0

// CTabWnd 
#define CTabWnd__Draw                                              0x76C210
#define CTabWnd__DrawCurrentPage                                   0x76BB70
#define CTabWnd__DrawTab                                           0x76B950
#define CTabWnd__GetCurrentPage                                    0x76BEB0
#define CTabWnd__GetPageClientRect                                 0x76B600
#define CTabWnd__GetPageFromTabIndex                               0x76B880
#define CTabWnd__GetPageInnerRect                                  0x76B660
#define CTabWnd__GetTabInnerRect                                   0x76B800
#define CTabWnd__GetTabRect                                        0x76B6F0
#define CTabWnd__InsertPage                                        0x76C4A0
#define CTabWnd__SetPage                                           0x76BEF0
#define CTabWnd__SetPageRect                                       0x76C140
#define CTabWnd__UpdatePage                                        0x76C420

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417DF0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x74A4D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x76D100

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x738A10

// CXRect 
#define CXRect__CenterPoint                                        0x5B2180

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x51E6C0
#define CXStr__CXStr1                                              0x7325B0
#define CXStr__CXStr3                                              0x7938C0
#define CXStr__dCXStr                                              0x45F000
#define CXStr__operator_equal1                                     0x793A80
#define CXStr__operator_plus_equal1                                0x794B10

// CXWnd 
#define CXWnd__BringToTop                                          0x740880
#define CXWnd__Center                                              0x7456B0
#define CXWnd__ClrFocus                                            0x7406B0
#define CXWnd__DoAllDrawing                                        0x746030
#define CXWnd__DrawChildren                                        0x746180
#define CXWnd__DrawColoredRect                                     0x740B70
#define CXWnd__DrawTooltip                                         0x7455E0
#define CXWnd__DrawTooltipAtPoint                                  0x744940
#define CXWnd__GetBorderFrame                                      0x741020
#define CXWnd__GetChildWndAt                                       0x743DC0
#define CXWnd__GetClientClipRect                                   0x740E30
#define CXWnd__GetScreenClipRect                                   0x744DA0
#define CXWnd__GetScreenRect                                       0x741140
#define CXWnd__GetTooltipRect                                      0x740C80
#define CXWnd__GetWindowTextA                                      0x59FFB0
#define CXWnd__IsActive                                            0x74B600
#define CXWnd__IsDescendantOf                                      0x740F10
#define CXWnd__IsReallyVisible                                     0x743DA0
#define CXWnd__IsType                                              0x76FF00
#define CXWnd__Move                                                0x7434F0
#define CXWnd__Move1                                               0x745340
#define CXWnd__ProcessTransition                                   0x740830
#define CXWnd__Refade                                              0x7407B0
#define CXWnd__Resize                                              0x741210
#define CXWnd__Right                                               0x744CE0
#define CXWnd__SetFocus                                            0x742900
#define CXWnd__SetKeyTooltip                                       0x741400
#define CXWnd__SetMouseOver                                        0x745090
#define CXWnd__StartFade                                           0x7408C0
#define CXWnd__GetChildItem                                        0x745000

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x74CBE0
#define CXWndManager__DrawWindows                                  0x74C860
#define CXWndManager__GetKeyboardFlags                             0x74B260
#define CXWndManager__HandleKeyboardMsg                            0x74B8D0
#define CXWndManager__RemoveWnd                                    0x74B720

// CDBStr
#define CDBStr__GetString                                          0x46A9F0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6F9020
#define EQ_Character__CastSpell                                    0x42FC00
#define EQ_Character__Cur_HP                                       0x438AD0
#define EQ_Character__GetAACastingTimeModifier                     0x425040
#define EQ_Character__GetCharInfo2                                 0x6F7E50
#define EQ_Character__GetFocusCastingTimeModifier                  0x420780
#define EQ_Character__GetFocusRangeModifier                        0x420960
#define EQ_Character__Max_Endurance                                0x539260
#define EQ_Character__Max_HP                                       0x433820
#define EQ_Character__Max_Mana                                     0x539090
#define EQ_Character__doCombatAbility                              0x537EF0
#define EQ_Character__UseSkill                                     0x447430
#define EQ_Character__GetConLevel                                  0x533780

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5191E0
#define EQ_Item__GetItemLinkHash                                   0x6E7810
#define EQ_Item__IsStackable                                       0x6DBE80

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x484780
#define EQ_LoadingS__Array                                         0x906EB8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x53CDD0
#define EQ_PC__GetAltAbilityIndex                                  0x6ED990
#define EQ_PC__GetCombatAbility                                    0x6EDA20
#define EQ_PC__GetCombatAbilityTimer                               0x6EDAD0
#define EQ_PC__GetItemTimerValue                                   0x537D20
#define EQ_PC__HasLoreItem                                         0x6F69A0

// EQItemList 
#define EQItemList__EQItemList                                     0x4B2720
#define EQItemList__add_item                                       0x4B26B0
#define EQItemList__delete_item                                    0x4B2AD0
#define EQItemList__FreeItemList                                   0x4B2A00

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46A200

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x541770
#define EQPlayer__dEQPlayer                                        0x5460A0
#define EQPlayer__DoAttack                                         0x556B70
#define EQPlayer__EQPlayer                                         0x54B8B0
#define EQPlayer__SetNameSpriteState                               0x543B80
#define EQPlayer__SetNameSpriteTint                                0x5417E0
#define EQPlayer__IsBodyType_j                                     0x6F8920
#define EQPlayer__IsTargetable                                     0x6F8AC0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x54CB50
#define EQPlayerManager__GetSpawnByName                            0x54CEF0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x51E0E0
#define KeypressHandler__AttachKeyToEqCommand                      0x51E120
#define KeypressHandler__ClearCommandStateArray                    0x51DEF0
#define KeypressHandler__HandleKeyDown                             0x51C9C0
#define KeypressHandler__HandleKeyUp                               0x51CCD0
#define KeypressHandler__SaveKeymapping                            0x51DFC0

// MapViewMap 
#define MapViewMap__Clear                                          0x63B480
#define MapViewMap__SaveEx                                         0x63BE50

#define PlayerPointManager__GetAltCurrency                         0x6E8F90

// StringTable 
#define StringTable__getString                                     0x6DB690
