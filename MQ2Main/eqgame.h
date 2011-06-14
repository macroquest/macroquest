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
#define __ExpectedVersionDate                                     "May 24 2011"
#define __ExpectedVersionTime                                     "07:42:55"
#define __ActualVersionDate                                        0x8AADCC
#define __ActualVersionTime                                        0x8AADD8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x528170
#define __MemChecker1                                              0x7BB9E0
#define __MemChecker2                                              0x59FAB0
#define __MemChecker3                                              0x59FA00
#define __MemChecker4                                              0x7DD7B0
#define __EncryptPad0                                              0x94BB48
#define __EncryptPad1                                              0x957DA8
#define __EncryptPad2                                              0x94E8E0
#define __EncryptPad3                                              0x94E4E0
#define __EncryptPad4                                              0x959850
#define __AC1                                                      0x6BB110
#define __AC2                                                      0x4E9C75
#define __AC3                                                      0x4FC568
#define __AC4                                                      0x501DA4
#define __AC5                                                      0x50E05C
#define __AC6                                                      0x5117BE
#define __AC7                                                      0x509CBB
#define __AC1_Data                                                 0x8918DD
// Direct Input
#define DI8__Main                                                  0xBD07CC
#define DI8__Keyboard                                              0xBD07D0
#define DI8__Mouse                                                 0xBD07D4
#define __AltTimerReady                                            0xB5478E
#define __Attack                                                   0xBB82AA
#define __Autofire                                                 0xBB82AB
#define __BindList                                                 0x9460A8
#define __Clicks                                                   0xB53438
#define __CommandList                                              0x946A98
#define __CurrentMapLabel                                          0xBFC4D8
#define __CurrentSocial                                            0x9419D8
#define __DoAbilityAvailable                                       0xB54728
#define __DoAbilityList                                            0xB8A1C8
#define __do_loot                                                  0x4BE850
#define __DrawHandler                                              0x1241BD4
#define __GroupCount                                               0xB4CE0A
#define __Guilds                                                   0xB4F198
#define __gWorld                                                   0xB4F0C4
#define __HotkeyPage                                               0xBB15B4
#define __HWnd                                                     0xBD0508
#define __InChatMode                                               0xB53370
#define __LastTell                                                 0xB550E0
#define __LMouseHeldTime                                           0xB534A4
#define __Mouse                                                    0xBD07D8
#define __MouseLook                                                0xB53406
#define __MouseEventTime                                           0xBB8574
#define __NetStatusToggle                                          0xB53409
#define __PCNames                                                  0xB54B24
#define __RangeAttackReady                                         0xB5478C
#define __RMouseHeldTime                                           0xB534A0
#define __RunWalkState                                             0xB53374
#define __ScreenMode                                               0xA9C340
#define __ScreenX                                                  0xB53328
#define __ScreenY                                                  0xB5332C
#define __ScreenXMax                                               0xB53330
#define __ScreenYMax                                               0xB53334
#define __ServerHost                                               0xB4CD4C
#define __ServerName                                               0xB8A188
#define __ShiftKeyDown                                             0xB53A34
#define __ShowNames                                                0xB549C8
#define __Socials                                                  0xB8A288


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xB4FCA0
#define instEQZoneInfo                                             0xB535F0
#define instKeypressHandler                                        0xBB8570
#define pinstActiveBanker                                          0xB4F16C
#define pinstActiveCorpse                                          0xB4F170
#define pinstActiveGMaster                                         0xB4F174
#define pinstActiveMerchant                                        0xB4F168
#define pinstAltAdvManager                                         0xA9D268
#define pinstAuraMgr                                               0x96C4F0
#define pinstBandageTarget                                         0xB4F154
#define pinstCamActor                                              0xA9CCE0
#define pinstCDBStr                                                0xA9C318
#define pinstCDisplay                                              0xB4F17C
#define pinstCEverQuest                                            0xBD0950
#define pinstCharData                                              0xB4F138
#define pinstCharSpawn                                             0xB4F160
#define pinstControlledMissile                                     0xB4F134
#define pinstControlledPlayer                                      0xB4F160
#define pinstCSidlManager                                          0x12420A4
#define pinstCXWndManager                                          0x124209C
#define instDynamicZone                                            0xB4F6F8
#define pinstDZMember                                              0xB4F808
#define pinstDZTimerInfo                                           0xB4F80C
#define pinstEQItemList                                            0xB4BEB0
#define instEQMisc                                                 0xA9C290
#define pinstEQSoundManager                                        0xA9D2D8
#define instExpeditionLeader                                       0xB4F742
#define instExpeditionName                                         0xB4F782
#define pinstGroup                                                 0xB4CE06
#define pinstImeManager                                            0x12420A8
#define pinstLocalPlayer                                           0xB4F14C
#define pinstMercenaryData                                         0xBB89D8
#define pinstModelPlayer                                           0xB4F178
#define pinstPCData                                                0xB4F138
#define pinstSkillMgr                                              0xBCD3B0
#define pinstSpawnManager                                          0xBCD048
#define pinstSpellManager                                          0xBCD3F0
#define pinstSpellSets                                             0xBB15B8
#define pinstStringTable                                           0xB4F0E0
#define pinstSwitchManager                                         0xB4CA18
#define pinstTarget                                                0xB4F164
#define pinstTargetObject                                          0xB4F13C
#define pinstTargetSwitch                                          0xB4F140
#define pinstTaskMember                                            0xA9C258
#define pinstTrackTarget                                           0xB4F158
#define pinstTradeTarget                                           0xB4F148
#define instTributeActive                                          0xA9C2B5
#define pinstViewActor                                             0xA9CCDC
#define pinstWorldData                                             0xB4F11C


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x969C50
#define pinstCAudioTriggersWindow                                  0x969BE8
#define pinstCCharacterSelect                                      0xA9CBB0
#define pinstCFacePick                                             0xA9CB60
#define pinstCNoteWnd                                              0xA9CB68
#define pinstCBookWnd                                              0xA9CB6C
#define pinstCPetInfoWnd                                           0xA9CB70
#define pinstCTrainWnd                                             0xA9CB74
#define pinstCSkillsWnd                                            0xA9CB78
#define pinstCSkillsSelectWnd                                      0xA9CB7C
#define pinstCCombatSkillSelectWnd                                 0xA9CB80
#define pinstCFriendsWnd                                           0xA9CB84
#define pinstCAuraWnd                                              0xA9CB88
#define pinstCRespawnWnd                                           0xA9CB8C
#define pinstCBandolierWnd                                         0xA9CB90
#define pinstCPotionBeltWnd                                        0xA9CB94
#define pinstCAAWnd                                                0xA9CB98
#define pinstCGroupSearchFiltersWnd                                0xA9CB9C
#define pinstCLoadskinWnd                                          0xA9CBA0
#define pinstCAlarmWnd                                             0xA9CBA4
#define pinstCMusicPlayerWnd                                       0xA9CBA8
#define pinstCMailWnd                                              0xA9CBB4
#define pinstCMailCompositionWnd                                   0xA9CBB8
#define pinstCMailAddressBookWnd                                   0xA9CBBC
#define pinstCRaidWnd                                              0xA9CBC4
#define pinstCRaidOptionsWnd                                       0xA9CBC8
#define pinstCBreathWnd                                            0xA9CBCC
#define pinstCMapViewWnd                                           0xA9CBD0
#define pinstCMapToolbarWnd                                        0xA9CBD4
#define pinstCEditLabelWnd                                         0xA9CBD8
#define pinstCTargetWnd                                            0xA9CBDC
#define pinstCColorPickerWnd                                       0xA9CBE0
#define pinstCPlayerWnd                                            0xA9CBE4
#define pinstCOptionsWnd                                           0xA9CBE8
#define pinstCBuffWindowNORMAL                                     0xA9CBEC
#define pinstCBuffWindowSHORT                                      0xA9CBF0
#define pinstCharacterCreation                                     0xA9CBF4
#define pinstCCursorAttachment                                     0xA9CBF8
#define pinstCCastingWnd                                           0xA9CBFC
#define pinstCCastSpellWnd                                         0xA9CC00
#define pinstCSpellBookWnd                                         0xA9CC04
#define pinstCInventoryWnd                                         0xA9CC08
#define pinstCBankWnd                                              0xA9CC0C
#define pinstCQuantityWnd                                          0xA9CC10
#define pinstCLootWnd                                              0xA9CC14
#define pinstCActionsWnd                                           0xA9CC18
#define pinstCCombatAbilityWnd                                     0xA9CC1C
#define pinstCMerchantWnd                                          0xA9CC20
#define pinstCTradeWnd                                             0xA9CC24
#define pinstCSelectorWnd                                          0xA9CC28
#define pinstCBazaarWnd                                            0xA9CC2C
#define pinstCBazaarSearchWnd                                      0xA9CC30
#define pinstCGiveWnd                                              0xA9CC4C
#define pinstCTrackingWnd                                          0xA9CC50
#define pinstCInspectWnd                                           0xA9CC54
#define pinstCSocialEditWnd                                        0xA9CC58
#define pinstCFeedbackWnd                                          0xA9CC5C
#define pinstCBugReportWnd                                         0xA9CC60
#define pinstCVideoModesWnd                                        0xA9CC64
#define pinstCTextEntryWnd                                         0xA9CC6C
#define pinstCFileSelectionWnd                                     0xA9CC70
#define pinstCCompassWnd                                           0xA9CC74
#define pinstCPlayerNotesWnd                                       0xA9CC78
#define pinstCGemsGameWnd                                          0xA9CC7C
#define pinstCTimeLeftWnd                                          0xA9CC80
#define pinstCPetitionQWnd                                         0xA9CC94
#define pinstCSoulmarkWnd                                          0xA9CC98
#define pinstCStoryWnd                                             0xA9CC9C
#define pinstCJournalTextWnd                                       0xA9CCA0
#define pinstCJournalCatWnd                                        0xA9CCA4
#define pinstCBodyTintWnd                                          0xA9CCA8
#define pinstCServerListWnd                                        0xA9CCAC
#define pinstCAvaZoneWnd                                           0xA9CCB4
#define pinstCBlockedBuffWnd                                       0xA9CCB8
#define pinstCBlockedPetBuffWnd                                    0xA9CCBC
#define pinstCInvSlotMgr                                           0xA9CCD4
#define pinstCContainerMgr                                         0xA9CCD8
#define pinstCAdventureLeaderboardWnd                              0xBF90A8
#define pinstCAdventureRequestWnd                                  0xBF9070
#define pinstCAltStorageWnd                                        0xBF9120
#define pinstCAdventureStatsWnd                                    0xBF90A8
#define pinstCBarterMerchantWnd                                    0xBF9578
#define pinstCBarterSearchWnd                                      0xBF95B0
#define pinstCBarterWnd                                            0xBF95E8
#define pinstCChatManager                                          0xBF99E0
#define pinstCDynamicZoneWnd                                       0xBF9BD0
#define pinstCEQMainWnd                                            0xBF9C90
#define pinstCFellowshipWnd                                        0xBF9D58
#define pinstCFindLocationWnd                                      0xBF9DC0
#define pinstCGroupSearchWnd                                       0xBF9F20
#define pinstCGroupWnd                                             0xBF9F58
#define pinstCGuildBankWnd                                         0xBF9F90
#define pinstCGuildMgmtWnd                                         0xBFC000
#define pinstCGuildTributeMasterWnd                                0xBFC038
#define pinstCHotButtonWnd                                         0xBFC088
#define pinstCHotButtonWnd1                                        0xBFC088
#define pinstCHotButtonWnd2                                        0xBFC08C
#define pinstCHotButtonWnd3                                        0xBFC090
#define pinstCHotButtonWnd4                                        0xBFC094
#define pinstCItemDisplayManager                                   0xBFC1D0
#define pinstCItemExpTransferWnd                                   0xBFC20C
#define pinstCLeadershipWnd                                        0xBFC338
#define pinstCLFGuildWnd                                           0xBFC370
#define pinstCMIZoneSelectWnd                                      0xBFC608
#define pinstCAdventureMerchantWnd                                 0xBFC8B8
#define pinstCConfirmationDialog                                   0xBFC8F0
#define pinstCPopupWndManager                                      0xBFC8F0
#define pinstCProgressionSelectionWnd                              0xBFC958
#define pinstCPvPLeaderboardWnd                                    0xBFC990
#define pinstCPvPStatsWnd                                          0xBFC9C8
#define pinstCSystemInfoDialogBox                                  0xBFCC50
#define pinstCTargetOfTargetWnd                                    0xBFD850
#define pinstCTaskSelectWnd                                        0xBFD8B8
#define pinstCTaskTemplateSelectWnd                                0xBFD8F0
#define pinstCTaskWnd                                              0xBFD928
#define pinstCTipWndOFDAY                                          0xBFDAA0
#define pinstCTipWndCONTEXT                                        0xBFDAA4
#define pinstCTitleWnd                                             0xBFDAD8
#define pinstCTradeskillWnd                                        0xBFDB50
#define pinstCTributeBenefitWnd                                    0xBFDBE8
#define pinstCTributeMasterWnd                                     0xBFDC20
#define pinstCContextMenuManager                                   0x1242100
#define pinstCVoiceMacroWnd                                        0xBCD708
#define pinstCHtmlWnd                                              0xBCD780


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D28C0
#define __ConvertItemTags                                          0x4C4020
#define __ExecuteCmd                                               0x4AFE50
#define __get_melee_range                                          0x4B5DF0
#define __GetGaugeValueFromEQ                                      0x6B9F90
#define __GetLabelFromEQ                                           0x6BB0B0
#define __GetXTargetType                                           0x730A80
#define __LoadFrontEnd                                             0x59E9E0
#define __NewUIINI                                                 0x6B9B50
#define __ProcessGameEvents                                        0x50A430
#define CrashDetected                                              0x59E7E0
#define DrawNetStatus                                              0x5346F0
#define Util__FastTime                                             0x7BC1E0
#define Expansion_HoT                                              0xB54928

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483A20
#define AltAdvManager__IsAbilityReady                              0x483AA0
#define AltAdvManager__GetAltAbility                               0x483D60

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x439500

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5BC4F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C6720

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x7820E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5DE310
#define CChatManager__InitContextMenu                              0x5DEAE0

// CChatService
#define CChatService__GetNumberOfFriends                           0x725480
#define CChatService__GetFriendName                                0x725490

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5E2E10
#define CChatWindow__Clear                                         0x5E3770
#define CChatWindow__WndNotification                               0x5E3960

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x76BB10
#define CComboWnd__Draw                                            0x76BCE0
#define CComboWnd__GetCurChoice                                    0x76B9D0
#define CComboWnd__GetListRect                                     0x76BFD0
#define CComboWnd__GetTextRect                                     0x76BB40
#define CComboWnd__InsertChoice                                    0x76C040
#define CComboWnd__SetColors                                       0x76B960
#define CComboWnd__SetChoice                                       0x76B990

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5ECB90
#define CContainerWnd__vftable                                     0x8B2618

// CDisplay 
#define CDisplay__CleanGameUI                                      0x4777F0
#define CDisplay__GetClickedActor                                  0x470830
#define CDisplay__GetUserDefinedColor                              0x46F210
#define CDisplay__GetWorldFilePath                                 0x46E6C0
#define CDisplay__is3dON                                           0x46D7F0
#define CDisplay__ReloadUI                                         0x480870
#define CDisplay__WriteTextHD2                                     0x473560

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B6520
#define CEditBaseWnd__SetSel                                       0x78F940

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x774EE0
#define CEditWnd__GetCharIndexPt                                   0x775EA0
#define CEditWnd__GetDisplayString                                 0x775070
#define CEditWnd__GetHorzOffset                                    0x775300
#define CEditWnd__GetLineForPrintableChar                          0x775950
#define CEditWnd__GetSelStartPt                                    0x7760F0
#define CEditWnd__GetSTMLSafeText                                  0x7754A0
#define CEditWnd__PointFromPrintableChar                           0x775A60
#define CEditWnd__SelectableCharFromPoint                          0x775BE0
#define CEditWnd__SetEditable                                      0x775470

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EA3A0
#define CEverQuest__DropHeldItemOnGround                           0x4F7A20
#define CEverQuest__dsp_chat                                       0x4F08D0
#define CEverQuest__DoTellWindow                                   0x4EF040
#define CEverQuest__EnterZone                                      0x501D30
#define CEverQuest__GetBodyTypeDesc                                0x4E7210
#define CEverQuest__GetClassDesc                                   0x4E6A50
#define CEverQuest__GetClassThreeLetterCode                        0x4E7050
#define CEverQuest__GetDeityDesc                                   0x4E7880
#define CEverQuest__GetLangDesc                                    0x4E75A0
#define CEverQuest__GetRaceDesc                                    0x4E7850
#define CEverQuest__InterpretCmd                                   0x4F14E0
#define CEverQuest__LeftClickedOnPlayer                            0x503E20
#define CEverQuest__LMouseUp                                       0x507990
#define CEverQuest__RightClickedOnPlayer                           0x508AF0
#define CEverQuest__RMouseUp                                       0x509C80
#define CEverQuest__SetGameState                                   0x4EA830
#define CEverQuest__Emote                                          0x4F0AF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5F9A40
#define CGaugeWnd__CalcLinesFillRect                               0x5F9AA0
#define CGaugeWnd__Draw                                            0x5F9EF0

// CGuild
#define CGuild__FindMemberByName                                   0x41B9D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x612C90

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x61E6B0
#define CInvSlotMgr__MoveItem                                      0x61EAC0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x61DB60
#define CInvSlot__SliderComplete                                   0x61BF50
#define CInvSlot__GetItemBase                                      0x61B6B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x61F8A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6B7870
#define CItemDisplayWnd__UpdateStrings                             0x620790

// CLabel 
#define CLabel__Draw                                               0x634BA0

// CListWnd 
#define CListWnd__AddColumn                                        0x764600
#define CListWnd__AddColumn1                                       0x763CB0
#define CListWnd__AddLine                                          0x763810
#define CListWnd__AddString                                        0x7639B0
#define CListWnd__CalculateFirstVisibleLine                        0x75FB20
#define CListWnd__CalculateVSBRange                                0x761E50
#define CListWnd__ClearAllSel                                      0x75F070
#define CListWnd__CloseAndUpdateEditWindow                         0x762E80
#define CListWnd__Compare                                          0x760520
#define CListWnd__Draw                                             0x761A90
#define CListWnd__DrawColumnSeparators                             0x761900
#define CListWnd__DrawHeader                                       0x75F300
#define CListWnd__DrawItem                                         0x760F20
#define CListWnd__DrawLine                                         0x761580
#define CListWnd__DrawSeparator                                    0x7619A0
#define CListWnd__EnsureVisible                                    0x75FC80
#define CListWnd__ExtendSel                                        0x760E40
#define CListWnd__GetColumnMinWidth                                0x75ED40
#define CListWnd__GetColumnWidth                                   0x75EC80
#define CListWnd__GetCurSel                                        0x75E500
#define CListWnd__GetHeaderRect                                    0x75E660
#define CListWnd__GetItemAtPoint                                   0x75FF50
#define CListWnd__GetItemAtPoint1                                  0x75FFC0
#define CListWnd__GetItemData                                      0x75E880
#define CListWnd__GetItemHeight                                    0x75F790
#define CListWnd__GetItemIcon                                      0x75EA60
#define CListWnd__GetItemRect                                      0x75FD50
#define CListWnd__GetItemText                                      0x75E910
#define CListWnd__GetSelList                                       0x763B90
#define CListWnd__GetSeparatorRect                                 0x760470
#define CListWnd__RemoveLine                                       0x763B40
#define CListWnd__SetColors                                        0x75E5D0
#define CListWnd__SetColumnJustification                           0x75EEE0
#define CListWnd__SetColumnWidth                                   0x75ED00
#define CListWnd__SetCurSel                                        0x75E540
#define CListWnd__SetItemColor                                     0x762B40
#define CListWnd__SetItemData                                      0x75F110
#define CListWnd__SetItemText                                      0x762920
#define CListWnd__ShiftColumnSeparator                             0x762790
#define CListWnd__Sort                                             0x764D40
#define CListWnd__ToggleSel                                        0x75EFE0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x64AB40

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x65CDC0
#define CMerchantWnd__RequestBuyItem                               0x660720
#define CMerchantWnd__RequestSellItem                              0x680560
#define CMerchantWnd__SelectBuySellSlot                            0x65E360

// CObfuscator
#define CObfuscator__doit                                          0x6F5DC0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x77D850
#define CSidlManager__CreateLabel                                  0x6B06F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5B86C0
#define CSidlScreenWnd__CalculateVSBRange                          0x5B85E0
#define CSidlScreenWnd__ConvertToRes                               0x78F820
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x76E0C0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x76F150
#define CSidlScreenWnd__CSidlScreenWnd2                            0x76F200
#define CSidlScreenWnd__dCSidlScreenWnd                            0x76E970
#define CSidlScreenWnd__DrawSidlPiece                              0x76DB90
#define CSidlScreenWnd__EnableIniStorage                           0x76D350
#define CSidlScreenWnd__GetSidlPiece                               0x76DDA0
#define CSidlScreenWnd__Init1                                      0x76EFB0
#define CSidlScreenWnd__LoadIniInfo                                0x76E170
#define CSidlScreenWnd__LoadIniListWnd                             0x76D4A0
#define CSidlScreenWnd__LoadSidlScreen                             0x76EBC0
#define CSidlScreenWnd__StoreIniInfo                               0x76CF50
#define CSidlScreenWnd__StoreIniVis                                0x76D2E0
#define CSidlScreenWnd__WndNotification                            0x76EDA0
#define CSidlScreenWnd__GetChildItem                               0x76D3B0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x56B920

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x790210
#define CSliderWnd__SetValue                                       0x790310
#define CSliderWnd__SetNumTicks                                    0x7908C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6B5470

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x78CEB0
#define CStmlWnd__CalculateHSBRange                                0x7845E0
#define CStmlWnd__CalculateVSBRange                                0x784550
#define CStmlWnd__CanBreakAtCharacter                              0x784740
#define CStmlWnd__FastForwardToEndOfTag                            0x785410
#define CStmlWnd__ForceParseNow                                    0x78D3E0
#define CStmlWnd__GetNextTagPiece                                  0x785330
#define CStmlWnd__GetSTMLText                                      0x5E2DB0
#define CStmlWnd__GetThisChar                                      0x7B4E20
#define CStmlWnd__GetVisiableText                                  0x786860
#define CStmlWnd__InitializeWindowVariables                        0x788E30
#define CStmlWnd__MakeStmlColorTag                                 0x783470
#define CStmlWnd__MakeWndNotificationTag                           0x783510
#define CStmlWnd__SetSTMLText                                      0x788F50
#define CStmlWnd__StripFirstSTMLLines                              0x78CB60
#define CStmlWnd__UpdateHistoryString                              0x7870F0

// CTabWnd 
#define CTabWnd__Draw                                              0x7917C0
#define CTabWnd__DrawCurrentPage                                   0x791090
#define CTabWnd__DrawTab                                           0x790E70
#define CTabWnd__GetCurrentPage                                    0x791450
#define CTabWnd__GetPageClientRect                                 0x790B20
#define CTabWnd__GetPageFromTabIndex                               0x790DA0
#define CTabWnd__GetPageInnerRect                                  0x790B80
#define CTabWnd__GetTabInnerRect                                   0x790D20
#define CTabWnd__GetTabRect                                        0x790C10
#define CTabWnd__InsertPage                                        0x791A50
#define CTabWnd__SetPage                                           0x791490
#define CTabWnd__SetPageRect                                       0x7916F0
#define CTabWnd__UpdatePage                                        0x7919D0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417F70

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x76F580

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x792650

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x75D400

// CXRect 
#define CXRect__CenterPoint                                        0x535070

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x416230
#define CXStr__CXStr1                                              0x758310
#define CXStr__CXStr3                                              0x7B93F0
#define CXStr__dCXStr                                              0x521CA0
#define CXStr__operator_equal                                      0x7B9560
#define CXStr__operator_equal1                                     0x7B95B0
#define CXStr__operator_plus_equal1                                0x7BA640

// CXWnd 
#define CXWnd__BringToTop                                          0x765320
#define CXWnd__Center                                              0x76A3B0
#define CXWnd__ClrFocus                                            0x765150
#define CXWnd__DoAllDrawing                                        0x76AD00
#define CXWnd__DrawChildren                                        0x76AE50
#define CXWnd__DrawColoredRect                                     0x765610
#define CXWnd__DrawTooltip                                         0x76A2E0
#define CXWnd__DrawTooltipAtPoint                                  0x769980
#define CXWnd__GetBorderFrame                                      0x765B50
#define CXWnd__GetChildWndAt                                       0x768DF0
#define CXWnd__GetClientClipRect                                   0x7658D0
#define CXWnd__GetScreenClipRect                                   0x769ED0
#define CXWnd__GetScreenRect                                       0x765C70
#define CXWnd__GetTooltipRect                                      0x765720
#define CXWnd__GetWindowTextA                                      0x5A9A80
#define CXWnd__IsActive                                            0x7706B0
#define CXWnd__IsDescendantOf                                      0x765A40
#define CXWnd__IsReallyVisible                                     0x768DD0
#define CXWnd__IsType                                              0x7954D0
#define CXWnd__Move                                                0x7682E0
#define CXWnd__Move1                                               0x768380
#define CXWnd__ProcessTransition                                   0x7652D0
#define CXWnd__Refade                                              0x765250
#define CXWnd__Resize                                              0x765D40
#define CXWnd__Right                                               0x769DE0
#define CXWnd__SetFocus                                            0x7674E0
#define CXWnd__SetKeyTooltip                                       0x765F90
#define CXWnd__SetMouseOver                                        0x76A1C0
#define CXWnd__StartFade                                           0x765360
#define CXWnd__GetChildItem                                        0x76A130

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x771C20
#define CXWndManager__DrawWindows                                  0x7718A0
#define CXWndManager__GetKeyboardFlags                             0x770310
#define CXWndManager__HandleKeyboardMsg                            0x770980
#define CXWndManager__RemoveWnd                                    0x7707D0

// CDBStr
#define CDBStr__GetString                                          0x46C070

// EQ_Character 
#define EQ_Character__CastRay                                      0x712DB0
#define EQ_Character__CastSpell                                    0x4303B0
#define EQ_Character__Cur_HP                                       0x4391C0
#define EQ_Character__GetAACastingTimeModifier                     0x425360
#define EQ_Character__GetCharInfo2                                 0x711B50
#define EQ_Character__GetFocusCastingTimeModifier                  0x420AE0
#define EQ_Character__GetFocusRangeModifier                        0x420CB0
#define EQ_Character__Max_Endurance                                0x53C780
#define EQ_Character__Max_HP                                       0x434180
#define EQ_Character__Max_Mana                                     0x53C580
#define EQ_Character__doCombatAbility                              0x53B400
#define EQ_Character__UseSkill                                     0x447A50
#define EQ_Character__GetConLevel                                  0x5363B0
#define EQ_Character__IsExpansionFlag                              0x40D920
#define EQ_Character__TotalEffect                                  0x4298A0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x51B5A0
#define EQ_Item__CreateItemTagString                               0x701010
#define EQ_Item__IsStackable                                       0x6F6440

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x484E10
#define EQ_LoadingS__Array                                         0x944468

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x53FCB0
#define EQ_PC__GetAltAbilityIndex                                  0x706CA0
#define EQ_PC__GetCombatAbility                                    0x706D30
#define EQ_PC__GetCombatAbilityTimer                               0x706DE0
#define EQ_PC__GetItemTimerValue                                   0x53B220
#define EQ_PC__HasLoreItem                                         0x7106A0

// EQItemList 
#define EQItemList__EQItemList                                     0x4B4110
#define EQItemList__add_item                                       0x4B40A0
#define EQItemList__delete_item                                    0x4B44C0
#define EQItemList__FreeItemList                                   0x4B43F0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46B860

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5447C0
#define EQPlayer__dEQPlayer                                        0x549270
#define EQPlayer__DoAttack                                         0x559FB0
#define EQPlayer__EQPlayer                                         0x54EB10
#define EQPlayer__SetNameSpriteState                               0x546C20
#define EQPlayer__SetNameSpriteTint                                0x544830
#define EQPlayer__IsBodyType_j                                     0x712670
#define EQPlayer__IsTargetable                                     0x712930

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x54FDE0
#define EQPlayerManager__GetSpawnByName                            0x550070

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x521380
#define KeypressHandler__AttachKeyToEqCommand                      0x5213C0
#define KeypressHandler__ClearCommandStateArray                    0x521190
#define KeypressHandler__HandleKeyDown                             0x51FC00
#define KeypressHandler__HandleKeyUp                               0x51FF10
#define KeypressHandler__SaveKeymapping                            0x521260

// MapViewMap 
#define MapViewMap__Clear                                          0x6461E0
#define MapViewMap__SaveEx                                         0x646BB0

#define PlayerPointManager__GetAltCurrency                         0x7021A0

// StringTable 
#define StringTable__getString                                     0x6F6040

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x53E440
