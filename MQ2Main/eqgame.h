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
#define __ExpectedVersionDate                                     "Oct 11 2011"
#define __ExpectedVersionTime                                     "15:40:12"
#define __ActualVersionDate                                        0x8B4FAC
#define __ActualVersionTime                                        0x8B4FB8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x5288E0
#define __MemChecker1                                              0x7C5B70
#define __MemChecker2                                              0x5A1BD0
#define __MemChecker3                                              0x5A1B20
#define __MemChecker4                                              0x7E7B40
#define __EncryptPad0                                              0x957BA0
#define __EncryptPad1                                              0x963E80
#define __EncryptPad2                                              0x95A968
#define __EncryptPad3                                              0x95A568
#define __EncryptPad4                                              0x965928
#define __AC1                                                      0x6BF960
#define __AC2                                                      0x4EA415
#define __AC3                                                      0x4FCBC8
#define __AC4                                                      0x5025C4
#define __AC5                                                      0x50E8AC
#define __AC6                                                      0x51206E
#define __AC7                                                      0x50A50B
#define __AC1_Data                                                 0x89C32D
// Direct Input
#define DI8__Main                                                  0xBC84E4
#define DI8__Keyboard                                              0xBC84E8
#define DI8__Mouse                                                 0xBC84EC
#define __AltTimerReady                                            0xB6088A
#define __Attack                                                   0xBC43A6
#define __Autofire                                                 0xBC43A7
#define __BindList                                                 0x9520D8
#define __Clicks                                                   0xB5F530
#define __CommandList                                              0x952AD8
#define __CurrentMapLabel                                          0xBF41F0
#define __CurrentSocial                                            0x94D9EC
#define __DoAbilityAvailable                                       0xB60824
#define __DoAbilityList                                            0xB962C4
#define __do_loot                                                  0x4BEFD0
#define __DrawHandler                                              0x124EBCC
#define __GroupCount                                               0xB58F02
#define __Guilds                                                   0xB5B290
#define __gWorld                                                   0xB5B1BC
#define __HotkeyPage                                               0xBBD6B0
#define __HWnd                                                     0xBC8220
#define __InChatMode                                               0xB5F468
#define __LastTell                                                 0xB611DC
#define __LMouseHeldTime                                           0xB5F59C
#define __Mouse                                                    0xBC84F0
#define __MouseLook                                                0xB5F4FE
#define __MouseEventTime                                           0xBC465C
#define __NetStatusToggle                                          0xB5F501
#define __PCNames                                                  0xB60C20
#define __RangeAttackReady                                         0xB60888
#define __RMouseHeldTime                                           0xB5F598
#define __RunWalkState                                             0xB5F46C
#define __ScreenMode                                               0xAA8438
#define __ScreenX                                                  0xB5F420
#define __ScreenY                                                  0xB5F424
#define __ScreenXMax                                               0xB5F428
#define __ScreenYMax                                               0xB5F42C
#define __ServerHost                                               0xB58E44
#define __ServerName                                               0xB96284
#define __ShiftKeyDown                                             0xB5FB2C
#define __ShowNames                                                0xB60AC4
#define __Socials                                                  0xB96384


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xB5BD98
#define instEQZoneInfo                                             0xB5F6E8
#define instKeypressHandler                                        0xBC4658
#define pinstActiveBanker                                          0xB5B264
#define pinstActiveCorpse                                          0xB5B268
#define pinstActiveGMaster                                         0xB5B26C
#define pinstActiveMerchant                                        0xB5B260
#define pinstAltAdvManager                                         0xAA9360
#define pinstAuraMgr                                               0x9785D0
#define pinstBandageTarget                                         0xB5B24C
#define pinstCamActor                                              0xAA8DD8
#define pinstCDBStr                                                0xAA8410
#define pinstCDisplay                                              0xB5B274
#define pinstCEverQuest                                            0xBC8668
#define pinstCharData                                              0xB5B230
#define pinstCharSpawn                                             0xB5B258
#define pinstControlledMissile                                     0xB5B22C
#define pinstControlledPlayer                                      0xB5B258
#define pinstCSidlManager                                          0x124F09C
#define pinstCXWndManager                                          0x124F094
#define instDynamicZone                                            0xB5B7F0
#define pinstDZMember                                              0xB5B900
#define pinstDZTimerInfo                                           0xB5B904
#define pinstEQItemList                                            0xB57FA8
#define instEQMisc                                                 0xAA8388
#define pinstEQSoundManager                                        0xAA93D0
#define instExpeditionLeader                                       0xB5B83A
#define instExpeditionName                                         0xB5B87A
#define pinstGroup                                                 0xB58EFE
#define pinstImeManager                                            0x124F0A0
#define pinstLocalPlayer                                           0xB5B244
#define pinstMercenaryData                                         0xBC4AC0
#define pinstModelPlayer                                           0xB5B270
#define pinstPCData                                                0xB5B230
#define pinstSkillMgr                                              0xBC50C8
#define pinstSpawnManager                                          0xBC4D60
#define pinstSpellManager                                          0xBC5108
#define pinstSpellSets                                             0xBBD6B4
#define pinstStringTable                                           0xB5B1D8
#define pinstSwitchManager                                         0xB58B10
#define pinstTarget                                                0xB5B25C
#define pinstTargetObject                                          0xB5B234
#define pinstTargetSwitch                                          0xB5B238
#define pinstTaskMember                                            0xAA8350
#define pinstTrackTarget                                           0xB5B250
#define pinstTradeTarget                                           0xB5B240
#define instTributeActive                                          0xAA83AD
#define pinstViewActor                                             0xAA8DD4
#define pinstWorldData                                             0xB5B214


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x975D30
#define pinstCAudioTriggersWindow                                  0x975CC8
#define pinstCCharacterSelect                                      0xAA8CA8
#define pinstCFacePick                                             0xAA8C58
#define pinstCNoteWnd                                              0xAA8C60
#define pinstCBookWnd                                              0xAA8C64
#define pinstCPetInfoWnd                                           0xAA8C68
#define pinstCTrainWnd                                             0xAA8C6C
#define pinstCSkillsWnd                                            0xAA8C70
#define pinstCSkillsSelectWnd                                      0xAA8C74
#define pinstCCombatSkillSelectWnd                                 0xAA8C78
#define pinstCFriendsWnd                                           0xAA8C7C
#define pinstCAuraWnd                                              0xAA8C80
#define pinstCRespawnWnd                                           0xAA8C84
#define pinstCBandolierWnd                                         0xAA8C88
#define pinstCPotionBeltWnd                                        0xAA8C8C
#define pinstCAAWnd                                                0xAA8C90
#define pinstCGroupSearchFiltersWnd                                0xAA8C94
#define pinstCLoadskinWnd                                          0xAA8C98
#define pinstCAlarmWnd                                             0xAA8C9C
#define pinstCMusicPlayerWnd                                       0xAA8CA0
#define pinstCMailWnd                                              0xAA8CAC
#define pinstCMailCompositionWnd                                   0xAA8CB0
#define pinstCMailAddressBookWnd                                   0xAA8CB4
#define pinstCRaidWnd                                              0xAA8CBC
#define pinstCRaidOptionsWnd                                       0xAA8CC0
#define pinstCBreathWnd                                            0xAA8CC4
#define pinstCMapViewWnd                                           0xAA8CC8
#define pinstCMapToolbarWnd                                        0xAA8CCC
#define pinstCEditLabelWnd                                         0xAA8CD0
#define pinstCTargetWnd                                            0xAA8CD4
#define pinstCColorPickerWnd                                       0xAA8CD8
#define pinstCPlayerWnd                                            0xAA8CDC
#define pinstCOptionsWnd                                           0xAA8CE0
#define pinstCBuffWindowNORMAL                                     0xAA8CE4
#define pinstCBuffWindowSHORT                                      0xAA8CE8
#define pinstCharacterCreation                                     0xAA8CEC
#define pinstCCursorAttachment                                     0xAA8CF0
#define pinstCCastingWnd                                           0xAA8CF4
#define pinstCCastSpellWnd                                         0xAA8CF8
#define pinstCSpellBookWnd                                         0xAA8CFC
#define pinstCInventoryWnd                                         0xAA8D00
#define pinstCBankWnd                                              0xAA8D04
#define pinstCQuantityWnd                                          0xAA8D08
#define pinstCLootWnd                                              0xAA8D0C
#define pinstCActionsWnd                                           0xAA8D10
#define pinstCCombatAbilityWnd                                     0xAA8D14
#define pinstCMerchantWnd                                          0xAA8D18
#define pinstCTradeWnd                                             0xAA8D1C
#define pinstCSelectorWnd                                          0xAA8D20
#define pinstCBazaarWnd                                            0xAA8D24
#define pinstCBazaarSearchWnd                                      0xAA8D28
#define pinstCGiveWnd                                              0xAA8D44
#define pinstCTrackingWnd                                          0xAA8D48
#define pinstCInspectWnd                                           0xAA8D4C
#define pinstCSocialEditWnd                                        0xAA8D50
#define pinstCFeedbackWnd                                          0xAA8D54
#define pinstCBugReportWnd                                         0xAA8D58
#define pinstCVideoModesWnd                                        0xAA8D5C
#define pinstCTextEntryWnd                                         0xAA8D64
#define pinstCFileSelectionWnd                                     0xAA8D68
#define pinstCCompassWnd                                           0xAA8D6C
#define pinstCPlayerNotesWnd                                       0xAA8D70
#define pinstCGemsGameWnd                                          0xAA8D74
#define pinstCTimeLeftWnd                                          0xAA8D78
#define pinstCPetitionQWnd                                         0xAA8D8C
#define pinstCSoulmarkWnd                                          0xAA8D90
#define pinstCStoryWnd                                             0xAA8D94
#define pinstCJournalTextWnd                                       0xAA8D98
#define pinstCJournalCatWnd                                        0xAA8D9C
#define pinstCBodyTintWnd                                          0xAA8DA0
#define pinstCServerListWnd                                        0xAA8DA4
#define pinstCAvaZoneWnd                                           0xAA8DAC
#define pinstCBlockedBuffWnd                                       0xAA8DB0
#define pinstCBlockedPetBuffWnd                                    0xAA8DB4
#define pinstCInvSlotMgr                                           0xAA8DCC
#define pinstCContainerMgr                                         0xAA8DD0
#define pinstCAdventureLeaderboardWnd                              0xBF0DC0
#define pinstCAdventureRequestWnd                                  0xBF0D88
#define pinstCAltStorageWnd                                        0xBF0E38
#define pinstCAdventureStatsWnd                                    0xBF0DC0
#define pinstCBarterMerchantWnd                                    0xBF1290
#define pinstCBarterSearchWnd                                      0xBF12C8
#define pinstCBarterWnd                                            0xBF1300
#define pinstCChatManager                                          0xBF16F8
#define pinstCDynamicZoneWnd                                       0xBF18E8
#define pinstCEQMainWnd                                            0xBF19A8
#define pinstCFellowshipWnd                                        0xBF1A70
#define pinstCFindLocationWnd                                      0xBF1AD8
#define pinstCGroupSearchWnd                                       0xBF1C38
#define pinstCGroupWnd                                             0xBF1C70
#define pinstCGuildBankWnd                                         0xBF1CA8
#define pinstCGuildMgmtWnd                                         0xBF3D18
#define pinstCGuildTributeMasterWnd                                0xBF3D50
#define pinstCHotButtonWnd                                         0xBF3DA0
#define pinstCHotButtonWnd1                                        0xBF3DA0
#define pinstCHotButtonWnd2                                        0xBF3DA4
#define pinstCHotButtonWnd3                                        0xBF3DA8
#define pinstCHotButtonWnd4                                        0xBF3DAC
#define pinstCItemDisplayManager                                   0xBF3EE8
#define pinstCItemExpTransferWnd                                   0xBF3F24
#define pinstCLeadershipWnd                                        0xBF4050
#define pinstCLFGuildWnd                                           0xBF4088
#define pinstCMIZoneSelectWnd                                      0xBF4320
#define pinstCAdventureMerchantWnd                                 0xBF45D0
#define pinstCConfirmationDialog                                   0xBF4608
#define pinstCPopupWndManager                                      0xBF4608
#define pinstCProgressionSelectionWnd                              0xBF4670
#define pinstCPvPLeaderboardWnd                                    0xBF46A8
#define pinstCPvPStatsWnd                                          0xBF46E0
#define pinstCSystemInfoDialogBox                                  0xBF4968
#define pinstCTargetOfTargetWnd                                    0xBF5568
#define pinstCTaskSelectWnd                                        0xBF55D0
#define pinstCTaskTemplateSelectWnd                                0xBF5608
#define pinstCTaskWnd                                              0xBF5640
#define pinstCTipWndOFDAY                                          0xBF57B8
#define pinstCTipWndCONTEXT                                        0xBF57BC
#define pinstCTitleWnd                                             0xBF57F0
#define pinstCTradeskillWnd                                        0xBF5868
#define pinstCTributeBenefitWnd                                    0xBF5900
#define pinstCTributeMasterWnd                                     0xBF5938
#define pinstCContextMenuManager                                   0x124F0F8
#define pinstCVoiceMacroWnd                                        0xBC5420
#define pinstCHtmlWnd                                              0xBC5498


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D33F0
#define __ConvertItemTags                                          0x4C47B0
#define __ExecuteCmd                                               0x4B07C0
#define __get_melee_range                                          0x4B65A0
#define __GetGaugeValueFromEQ                                      0x6BE710
#define __GetLabelFromEQ                                           0x6BF900
#define __GetXTargetType                                           0x736FE0
#define __LoadFrontEnd                                             0x5A0B00
#define __NewUIINI                                                 0x6BE2C0
#define __ProcessGameEvents                                        0x50AC90
#define CrashDetected                                              0x5A0900
#define DrawNetStatus                                              0x534F50
#define Util__FastTime                                             0x7C63B0
#define Expansion_HoT                                              0xB60A24

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483EE0
#define AltAdvManager__IsAbilityReady                              0x483F60
#define AltAdvManager__GetAltAbility                               0x4841A0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x439700

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5BE6E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C88F0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x78C060

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5E0790
#define CChatManager__InitContextMenu                              0x5E0F60

// CChatService
#define CChatService__GetNumberOfFriends                           0x72AEE0
#define CChatService__GetFriendName                                0x72AEF0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5E52C0
#define CChatWindow__Clear                                         0x5E5C10
#define CChatWindow__WndNotification                               0x5E5DF0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x775C30
#define CComboWnd__Draw                                            0x775DF0
#define CComboWnd__GetCurChoice                                    0x775AF0
#define CComboWnd__GetListRect                                     0x7760C0
#define CComboWnd__GetTextRect                                     0x775C60
#define CComboWnd__InsertChoice                                    0x776130
#define CComboWnd__SetColors                                       0x775A80
#define CComboWnd__SetChoice                                       0x775AB0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5EF020
#define CContainerWnd__vftable                                     0x8BC7F8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x477C60
#define CDisplay__GetClickedActor                                  0x470C40
#define CDisplay__GetUserDefinedColor                              0x46F620
#define CDisplay__GetWorldFilePath                                 0x46EAD0
#define CDisplay__is3dON                                           0x46DC00
#define CDisplay__ReloadUI                                         0x480D30
#define CDisplay__WriteTextHD2                                     0x473970

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B8730
#define CEditBaseWnd__SetSel                                       0x7998F0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x77F060
#define CEditWnd__GetCharIndexPt                                   0x77FFF0
#define CEditWnd__GetDisplayString                                 0x77F1F0
#define CEditWnd__GetHorzOffset                                    0x77F480
#define CEditWnd__GetLineForPrintableChar                          0x77FAC0
#define CEditWnd__GetSelStartPt                                    0x780230
#define CEditWnd__GetSTMLSafeText                                  0x77F610
#define CEditWnd__PointFromPrintableChar                           0x77FBD0
#define CEditWnd__SelectableCharFromPoint                          0x77FD40
#define CEditWnd__SetEditable                                      0x77F5E0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EAB40
#define CEverQuest__DropHeldItemOnGround                           0x4F8080
#define CEverQuest__dsp_chat                                       0x4F0F60
#define CEverQuest__DoTellWindow                                   0x4EF6D0
#define CEverQuest__EnterZone                                      0x502550
#define CEverQuest__GetBodyTypeDesc                                0x4E7970
#define CEverQuest__GetClassDesc                                   0x4E71B0
#define CEverQuest__GetClassThreeLetterCode                        0x4E77B0
#define CEverQuest__GetDeityDesc                                   0x4E8020
#define CEverQuest__GetLangDesc                                    0x4E7D00
#define CEverQuest__GetRaceDesc                                    0x4E7FF0
#define CEverQuest__InterpretCmd                                   0x4F1B40
#define CEverQuest__LeftClickedOnPlayer                            0x504650
#define CEverQuest__LMouseUp                                       0x5081E0
#define CEverQuest__RightClickedOnPlayer                           0x509340
#define CEverQuest__RMouseUp                                       0x50A4D0
#define CEverQuest__SetGameState                                   0x4EAFD0
#define CEverQuest__Emote                                          0x4F1180

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5FC360
#define CGaugeWnd__CalcLinesFillRect                               0x5FC3C0
#define CGaugeWnd__Draw                                            0x5FC810

// CGuild
#define CGuild__FindMemberByName                                   0x41BA30

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x615560

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x620E80
#define CInvSlotMgr__MoveItem                                      0x621290

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x620330
#define CInvSlot__SliderComplete                                   0x61E710
#define CInvSlot__GetItemBase                                      0x61DE70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x622070

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6BBFE0
#define CItemDisplayWnd__UpdateStrings                             0x622F60

// CLabel 
#define CLabel__Draw                                               0x637370

// CListWnd 
#define CListWnd__AddColumn                                        0x76E860
#define CListWnd__AddColumn1                                       0x76DED0
#define CListWnd__AddLine                                          0x76DA80
#define CListWnd__AddString                                        0x76DC20
#define CListWnd__CalculateFirstVisibleLine                        0x769DC0
#define CListWnd__CalculateVSBRange                                0x76C0D0
#define CListWnd__ClearAllSel                                      0x769320
#define CListWnd__CloseAndUpdateEditWindow                         0x76D0F0
#define CListWnd__Compare                                          0x76A7A0
#define CListWnd__Draw                                             0x76BD10
#define CListWnd__DrawColumnSeparators                             0x76BB80
#define CListWnd__DrawHeader                                       0x7695B0
#define CListWnd__DrawItem                                         0x76B1A0
#define CListWnd__DrawLine                                         0x76B800
#define CListWnd__DrawSeparator                                    0x76BC20
#define CListWnd__EnsureVisible                                    0x769F10
#define CListWnd__ExtendSel                                        0x76B0C0
#define CListWnd__GetColumnMinWidth                                0x768FF0
#define CListWnd__GetColumnWidth                                   0x768F30
#define CListWnd__GetCurSel                                        0x7687A0
#define CListWnd__GetHeaderRect                                    0x768910
#define CListWnd__GetItemAtPoint                                   0x76A1D0
#define CListWnd__GetItemAtPoint1                                  0x76A240
#define CListWnd__GetItemData                                      0x768B30
#define CListWnd__GetItemHeight                                    0x769A40
#define CListWnd__GetItemIcon                                      0x768D10
#define CListWnd__GetItemRect                                      0x769FD0
#define CListWnd__GetItemText                                      0x768BC0
#define CListWnd__GetSelList                                       0x76DDB0
#define CListWnd__GetSeparatorRect                                 0x76A6F0
#define CListWnd__RemoveLine                                       0x76E810
#define CListWnd__SetColors                                        0x768870
#define CListWnd__SetColumnJustification                           0x769190
#define CListWnd__SetColumnWidth                                   0x768FB0
#define CListWnd__SetCurSel                                        0x7687E0
#define CListWnd__SetItemColor                                     0x76CDB0
#define CListWnd__SetItemData                                      0x7693C0
#define CListWnd__SetItemText                                      0x76CB90
#define CListWnd__ShiftColumnSeparator                             0x76CA00
#define CListWnd__Sort                                             0x76EFA0
#define CListWnd__ToggleSel                                        0x769290

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x64D2F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x661120
#define CMerchantWnd__RequestBuyItem                               0x664A70
#define CMerchantWnd__RequestSellItem                              0x684F50
#define CMerchantWnd__SelectBuySellSlot                            0x6626B0

// CObfuscator
#define CObfuscator__doit                                          0x6FA720

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7878B0
#define CSidlManager__CreateLabel                                  0x6B4E10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5BA8C0
#define CSidlScreenWnd__CalculateVSBRange                          0x5BA7F0
#define CSidlScreenWnd__ConvertToRes                               0x7997D0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7781A0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7792C0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x779370
#define CSidlScreenWnd__dCSidlScreenWnd                            0x778AE0
#define CSidlScreenWnd__DrawSidlPiece                              0x777C70
#define CSidlScreenWnd__EnableIniStorage                           0x777460
#define CSidlScreenWnd__GetSidlPiece                               0x777E80
#define CSidlScreenWnd__Init1                                      0x779120
#define CSidlScreenWnd__LoadIniInfo                                0x778250
#define CSidlScreenWnd__LoadIniListWnd                             0x7775B0
#define CSidlScreenWnd__LoadSidlScreen                             0x778D30
#define CSidlScreenWnd__StoreIniInfo                               0x777060
#define CSidlScreenWnd__StoreIniVis                                0x7773F0
#define CSidlScreenWnd__WndNotification                            0x778F10
#define CSidlScreenWnd__GetChildItem                               0x7774C0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x56DA20

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x79A1D0
#define CSliderWnd__SetValue                                       0x79A2D0
#define CSliderWnd__SetNumTicks                                    0x79A880

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6B9C00

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x796E50
#define CStmlWnd__CalculateHSBRange                                0x78E500
#define CStmlWnd__CalculateVSBRange                                0x78E580
#define CStmlWnd__CanBreakAtCharacter                              0x78E700
#define CStmlWnd__FastForwardToEndOfTag                            0x78F3E0
#define CStmlWnd__ForceParseNow                                    0x797380
#define CStmlWnd__GetNextTagPiece                                  0x78F300
#define CStmlWnd__GetSTMLText                                      0x5E5260
#define CStmlWnd__GetThisChar                                      0x7BED80
#define CStmlWnd__GetVisiableText                                  0x790820
#define CStmlWnd__InitializeWindowVariables                        0x792DF0
#define CStmlWnd__MakeStmlColorTag                                 0x78D400
#define CStmlWnd__MakeWndNotificationTag                           0x78D4A0
#define CStmlWnd__SetSTMLText                                      0x792F10
#define CStmlWnd__StripFirstSTMLLines                              0x796B00
#define CStmlWnd__UpdateHistoryString                              0x7910B0

// CTabWnd 
#define CTabWnd__Draw                                              0x79B780
#define CTabWnd__DrawCurrentPage                                   0x79B050
#define CTabWnd__DrawTab                                           0x79AE30
#define CTabWnd__GetCurrentPage                                    0x79B410
#define CTabWnd__GetPageClientRect                                 0x79AAE0
#define CTabWnd__GetPageFromTabIndex                               0x79AD60
#define CTabWnd__GetPageInnerRect                                  0x79AB40
#define CTabWnd__GetTabInnerRect                                   0x79ACE0
#define CTabWnd__GetTabRect                                        0x79ABD0
#define CTabWnd__InsertPage                                        0x79BA10
#define CTabWnd__SetPage                                           0x79B450
#define CTabWnd__SetPageRect                                       0x79B6B0
#define CTabWnd__UpdatePage                                        0x79B990

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417FE0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7796F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x79C600

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x767660

// CXRect 
#define CXRect__CenterPoint                                        0x5358C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x522130
#define CXStr__CXStr1                                              0x41E210
#define CXStr__CXStr3                                              0x7C3350
#define CXStr__dCXStr                                              0x5224A0
#define CXStr__operator_equal                                      0x7C34C0
#define CXStr__operator_equal1                                     0x7C3510
#define CXStr__operator_plus_equal1                                0x7C45A0

// CXWnd 
#define CXWnd__BringToTop                                          0x76F590
#define CXWnd__Center                                              0x774580
#define CXWnd__ClrFocus                                            0x76F3B0
#define CXWnd__DoAllDrawing                                        0x774EA0
#define CXWnd__DrawChildren                                        0x774FE0
#define CXWnd__DrawColoredRect                                     0x76F870
#define CXWnd__DrawTooltip                                         0x7744B0
#define CXWnd__DrawTooltipAtPoint                                  0x773B90
#define CXWnd__GetBorderFrame                                      0x76FD60
#define CXWnd__GetChildWndAt                                       0x773050
#define CXWnd__GetClientClipRect                                   0x76FB30
#define CXWnd__GetScreenClipRect                                   0x7740C0
#define CXWnd__GetScreenRect                                       0x76FEA0
#define CXWnd__GetTooltipRect                                      0x76F980
#define CXWnd__GetWindowTextA                                      0x5ABBB0
#define CXWnd__IsActive                                            0x77A820
#define CXWnd__IsDescendantOf                                      0x76FC90
#define CXWnd__IsReallyVisible                                     0x773030
#define CXWnd__IsType                                              0x79F3F0
#define CXWnd__Move                                                0x7724F0
#define CXWnd__Move1                                               0x7725B0
#define CXWnd__ProcessTransition                                   0x76F540
#define CXWnd__Refade                                              0x76F4C0
#define CXWnd__Resize                                              0x76FF60
#define CXWnd__Right                                               0x773FD0
#define CXWnd__SetFocus                                            0x771720
#define CXWnd__SetKeyTooltip                                       0x7701B0
#define CXWnd__SetMouseOver                                        0x7743A0
#define CXWnd__StartFade                                           0x76F5D0
#define CXWnd__GetChildItem                                        0x774310

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x77BD90
#define CXWndManager__DrawWindows                                  0x77BA10
#define CXWndManager__GetKeyboardFlags                             0x77A480
#define CXWndManager__HandleKeyboardMsg                            0x77AAF0
#define CXWndManager__RemoveWnd                                    0x77A940

// CDBStr
#define CDBStr__GetString                                          0x46C450

// EQ_Character 
#define EQ_Character__CastRay                                      0x718650
#define EQ_Character__CastSpell                                    0x430580
#define EQ_Character__Cur_HP                                       0x4393C0
#define EQ_Character__GetAACastingTimeModifier                     0x425430
#define EQ_Character__GetCharInfo2                                 0x717360
#define EQ_Character__GetFocusCastingTimeModifier                  0x420B60
#define EQ_Character__GetFocusRangeModifier                        0x420D30
#define EQ_Character__Max_Endurance                                0x53D9A0
#define EQ_Character__Max_HP                                       0x434380
#define EQ_Character__Max_Mana                                     0x53D7A0
#define EQ_Character__doCombatAbility                              0x53C620
#define EQ_Character__UseSkill                                     0x447C80
#define EQ_Character__GetConLevel                                  0x5377B0
#define EQ_Character__IsExpansionFlag                              0x40D9A0
#define EQ_Character__TotalEffect                                  0x429A90

// EQ_Item 
#define EQ_Item__CanDrop                                           0x51C0C0
#define EQ_Item__CreateItemTagString                               0x7059E0
#define EQ_Item__IsStackable                                       0x6FADA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x485250
#define EQ_LoadingS__Array                                         0x950490

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x540F30
#define EQ_PC__GetAltAbilityIndex                                  0x70C1E0
#define EQ_PC__GetCombatAbility                                    0x70C270
#define EQ_PC__GetCombatAbilityTimer                               0x70C320
#define EQ_PC__GetItemTimerValue                                   0x53C440
#define EQ_PC__HasLoreItem                                         0x715EB0

// EQItemList 
#define EQItemList__EQItemList                                     0x4B4A70
#define EQItemList__add_item                                       0x4B4A00
#define EQItemList__delete_item                                    0x4B4E20
#define EQItemList__FreeItemList                                   0x4B4D50

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46BC40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5460A0
#define EQPlayer__dEQPlayer                                        0x54AC50
#define EQPlayer__DoAttack                                         0x55BD20
#define EQPlayer__EQPlayer                                         0x550600
#define EQPlayer__SetNameSpriteState                               0x5485A0
#define EQPlayer__SetNameSpriteTint                                0x546110
#define EQPlayer__IsBodyType_j                                     0x717EF0
#define EQPlayer__IsTargetable                                     0x7181C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x551900
#define EQPlayerManager__GetSpawnByName                            0x551B90

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x521B50
#define KeypressHandler__AttachKeyToEqCommand                      0x521B90
#define KeypressHandler__ClearCommandStateArray                    0x521960
#define KeypressHandler__HandleKeyDown                             0x520340
#define KeypressHandler__HandleKeyUp                               0x520650
#define KeypressHandler__SaveKeymapping                            0x521A30

// MapViewMap 
#define MapViewMap__Clear                                          0x648970
#define MapViewMap__SaveEx                                         0x649340

#define PlayerPointManager__GetAltCurrency                         0x706B70

// StringTable 
#define StringTable__getString                                     0x6FA9A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x53F720
