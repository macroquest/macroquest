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
#define __ExpectedVersionDate                                     "Jun 14 2011"
#define __ExpectedVersionTime                                     "16:48:12"
#define __ActualVersionDate                                        0x8ABDFC
#define __ActualVersionTime                                        0x8ABE08

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x528480
#define __MemChecker1                                              0x7BC240
#define __MemChecker2                                              0x5A04A0
#define __MemChecker3                                              0x5A03F0
#define __MemChecker4                                              0x7DE220
#define __EncryptPad0                                              0x94DB48
#define __EncryptPad1                                              0x959DA8
#define __EncryptPad2                                              0x9508E0
#define __EncryptPad3                                              0x9504E0
#define __EncryptPad4                                              0x95B850
#define __AC1                                                      0x6BB7B0
#define __AC2                                                      0x4EA3A5
#define __AC3                                                      0x4FCB98
#define __AC4                                                      0x5023D4
#define __AC5                                                      0x50E69C
#define __AC6                                                      0x511DFE
#define __AC7                                                      0x50A2EB
#define __AC1_Data                                                 0x8922CD
// Direct Input
#define DI8__Main                                                  0xBD27CC
#define DI8__Keyboard                                              0xBD27D0
#define DI8__Mouse                                                 0xBD27D4
#define __AltTimerReady                                            0xB567A6
#define __Attack                                                   0xBBA2C2
#define __Autofire                                                 0xBBA2C3
#define __BindList                                                 0x9480A8
#define __Clicks                                                   0xB55450
#define __CommandList                                              0x948A98
#define __CurrentMapLabel                                          0xBFE4D8
#define __CurrentSocial                                            0x9439D8
#define __DoAbilityAvailable                                       0xB56740
#define __DoAbilityList                                            0xB8C1E0
#define __do_loot                                                  0x4BEA90
#define __DrawHandler                                              0x1243BD4
#define __GroupCount                                               0xB4EE22
#define __Guilds                                                   0xB511B0
#define __gWorld                                                   0xB510DC
#define __HotkeyPage                                               0xBB35CC
#define __HWnd                                                     0xBD2508
#define __InChatMode                                               0xB55388
#define __LastTell                                                 0xB570F8
#define __LMouseHeldTime                                           0xB554BC
#define __Mouse                                                    0xBD27D8
#define __MouseLook                                                0xB5541E
#define __MouseEventTime                                           0xBBA574
#define __NetStatusToggle                                          0xB55421
#define __PCNames                                                  0xB56B3C
#define __RangeAttackReady                                         0xB567A4
#define __RMouseHeldTime                                           0xB554B8
#define __RunWalkState                                             0xB5538C
#define __ScreenMode                                               0xA9E358
#define __ScreenX                                                  0xB55340
#define __ScreenY                                                  0xB55344
#define __ScreenXMax                                               0xB55348
#define __ScreenYMax                                               0xB5534C
#define __ServerHost                                               0xB4ED64
#define __ServerName                                               0xB8C1A0
#define __ShiftKeyDown                                             0xB55A4C
#define __ShowNames                                                0xB569E0
#define __Socials                                                  0xB8C2A0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xB51CB8
#define instEQZoneInfo                                             0xB55608
#define instKeypressHandler                                        0xBBA570
#define pinstActiveBanker                                          0xB51184
#define pinstActiveCorpse                                          0xB51188
#define pinstActiveGMaster                                         0xB5118C
#define pinstActiveMerchant                                        0xB51180
#define pinstAltAdvManager                                         0xA9F280
#define pinstAuraMgr                                               0x96E4F0
#define pinstBandageTarget                                         0xB5116C
#define pinstCamActor                                              0xA9ECF8
#define pinstCDBStr                                                0xA9E330
#define pinstCDisplay                                              0xB51194
#define pinstCEverQuest                                            0xBD2950
#define pinstCharData                                              0xB51150
#define pinstCharSpawn                                             0xB51178
#define pinstControlledMissile                                     0xB5114C
#define pinstControlledPlayer                                      0xB51178
#define pinstCSidlManager                                          0x12440A4
#define pinstCXWndManager                                          0x124409C
#define instDynamicZone                                            0xB51710
#define pinstDZMember                                              0xB51820
#define pinstDZTimerInfo                                           0xB51824
#define pinstEQItemList                                            0xB4DEC8
#define instEQMisc                                                 0xA9E2A8
#define pinstEQSoundManager                                        0xA9F2F0
#define instExpeditionLeader                                       0xB5175A
#define instExpeditionName                                         0xB5179A
#define pinstGroup                                                 0xB4EE1E
#define pinstImeManager                                            0x12440A8
#define pinstLocalPlayer                                           0xB51164
#define pinstMercenaryData                                         0xBBA9D8
#define pinstModelPlayer                                           0xB51190
#define pinstPCData                                                0xB51150
#define pinstSkillMgr                                              0xBCF3B0
#define pinstSpawnManager                                          0xBCF048
#define pinstSpellManager                                          0xBCF3F0
#define pinstSpellSets                                             0xBB35D0
#define pinstStringTable                                           0xB510F8
#define pinstSwitchManager                                         0xB4EA30
#define pinstTarget                                                0xB5117C
#define pinstTargetObject                                          0xB51154
#define pinstTargetSwitch                                          0xB51158
#define pinstTaskMember                                            0xA9E270
#define pinstTrackTarget                                           0xB51170
#define pinstTradeTarget                                           0xB51160
#define instTributeActive                                          0xA9E2CD
#define pinstViewActor                                             0xA9ECF4
#define pinstWorldData                                             0xB51134


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x96BC50
#define pinstCAudioTriggersWindow                                  0x96BBE8
#define pinstCCharacterSelect                                      0xA9EBC8
#define pinstCFacePick                                             0xA9EB78
#define pinstCNoteWnd                                              0xA9EB80
#define pinstCBookWnd                                              0xA9EB84
#define pinstCPetInfoWnd                                           0xA9EB88
#define pinstCTrainWnd                                             0xA9EB8C
#define pinstCSkillsWnd                                            0xA9EB90
#define pinstCSkillsSelectWnd                                      0xA9EB94
#define pinstCCombatSkillSelectWnd                                 0xA9EB98
#define pinstCFriendsWnd                                           0xA9EB9C
#define pinstCAuraWnd                                              0xA9EBA0
#define pinstCRespawnWnd                                           0xA9EBA4
#define pinstCBandolierWnd                                         0xA9EBA8
#define pinstCPotionBeltWnd                                        0xA9EBAC
#define pinstCAAWnd                                                0xA9EBB0
#define pinstCGroupSearchFiltersWnd                                0xA9EBB4
#define pinstCLoadskinWnd                                          0xA9EBB8
#define pinstCAlarmWnd                                             0xA9EBBC
#define pinstCMusicPlayerWnd                                       0xA9EBC0
#define pinstCMailWnd                                              0xA9EBCC
#define pinstCMailCompositionWnd                                   0xA9EBD0
#define pinstCMailAddressBookWnd                                   0xA9EBD4
#define pinstCRaidWnd                                              0xA9EBDC
#define pinstCRaidOptionsWnd                                       0xA9EBE0
#define pinstCBreathWnd                                            0xA9EBE4
#define pinstCMapViewWnd                                           0xA9EBE8
#define pinstCMapToolbarWnd                                        0xA9EBEC
#define pinstCEditLabelWnd                                         0xA9EBF0
#define pinstCTargetWnd                                            0xA9EBF4
#define pinstCColorPickerWnd                                       0xA9EBF8
#define pinstCPlayerWnd                                            0xA9EBFC
#define pinstCOptionsWnd                                           0xA9EC00
#define pinstCBuffWindowNORMAL                                     0xA9EC04
#define pinstCBuffWindowSHORT                                      0xA9EC08
#define pinstCharacterCreation                                     0xA9EC0C
#define pinstCCursorAttachment                                     0xA9EC10
#define pinstCCastingWnd                                           0xA9EC14
#define pinstCCastSpellWnd                                         0xA9EC18
#define pinstCSpellBookWnd                                         0xA9EC1C
#define pinstCInventoryWnd                                         0xA9EC20
#define pinstCBankWnd                                              0xA9EC24
#define pinstCQuantityWnd                                          0xA9EC28
#define pinstCLootWnd                                              0xA9EC2C
#define pinstCActionsWnd                                           0xA9EC30
#define pinstCCombatAbilityWnd                                     0xA9EC34
#define pinstCMerchantWnd                                          0xA9EC38
#define pinstCTradeWnd                                             0xA9EC3C
#define pinstCSelectorWnd                                          0xA9EC40
#define pinstCBazaarWnd                                            0xA9EC44
#define pinstCBazaarSearchWnd                                      0xA9EC48
#define pinstCGiveWnd                                              0xA9EC64
#define pinstCTrackingWnd                                          0xA9EC68
#define pinstCInspectWnd                                           0xA9EC6C
#define pinstCSocialEditWnd                                        0xA9EC70
#define pinstCFeedbackWnd                                          0xA9EC74
#define pinstCBugReportWnd                                         0xA9EC78
#define pinstCVideoModesWnd                                        0xA9EC7C
#define pinstCTextEntryWnd                                         0xA9EC84
#define pinstCFileSelectionWnd                                     0xA9EC88
#define pinstCCompassWnd                                           0xA9EC8C
#define pinstCPlayerNotesWnd                                       0xA9EC90
#define pinstCGemsGameWnd                                          0xA9EC94
#define pinstCTimeLeftWnd                                          0xA9EC98
#define pinstCPetitionQWnd                                         0xA9ECAC
#define pinstCSoulmarkWnd                                          0xA9ECB0
#define pinstCStoryWnd                                             0xA9ECB4
#define pinstCJournalTextWnd                                       0xA9ECB8
#define pinstCJournalCatWnd                                        0xA9ECBC
#define pinstCBodyTintWnd                                          0xA9ECC0
#define pinstCServerListWnd                                        0xA9ECC4
#define pinstCAvaZoneWnd                                           0xA9ECCC
#define pinstCBlockedBuffWnd                                       0xA9ECD0
#define pinstCBlockedPetBuffWnd                                    0xA9ECD4
#define pinstCInvSlotMgr                                           0xA9ECEC
#define pinstCContainerMgr                                         0xA9ECF0
#define pinstCAdventureLeaderboardWnd                              0xBFB0A8
#define pinstCAdventureRequestWnd                                  0xBFB070
#define pinstCAltStorageWnd                                        0xBFB120
#define pinstCAdventureStatsWnd                                    0xBFB0A8
#define pinstCBarterMerchantWnd                                    0xBFB578
#define pinstCBarterSearchWnd                                      0xBFB5B0
#define pinstCBarterWnd                                            0xBFB5E8
#define pinstCChatManager                                          0xBFB9E0
#define pinstCDynamicZoneWnd                                       0xBFBBD0
#define pinstCEQMainWnd                                            0xBFBC90
#define pinstCFellowshipWnd                                        0xBFBD58
#define pinstCFindLocationWnd                                      0xBFBDC0
#define pinstCGroupSearchWnd                                       0xBFBF20
#define pinstCGroupWnd                                             0xBFBF58
#define pinstCGuildBankWnd                                         0xBFBF90
#define pinstCGuildMgmtWnd                                         0xBFE000
#define pinstCGuildTributeMasterWnd                                0xBFE038
#define pinstCHotButtonWnd                                         0xBFE088
#define pinstCHotButtonWnd1                                        0xBFE088
#define pinstCHotButtonWnd2                                        0xBFE08C
#define pinstCHotButtonWnd3                                        0xBFE090
#define pinstCHotButtonWnd4                                        0xBFE094
#define pinstCItemDisplayManager                                   0xBFE1D0
#define pinstCItemExpTransferWnd                                   0xBFE20C
#define pinstCLeadershipWnd                                        0xBFE338
#define pinstCLFGuildWnd                                           0xBFE370
#define pinstCMIZoneSelectWnd                                      0xBFE608
#define pinstCAdventureMerchantWnd                                 0xBFE8B8
#define pinstCConfirmationDialog                                   0xBFE8F0
#define pinstCPopupWndManager                                      0xBFE8F0
#define pinstCProgressionSelectionWnd                              0xBFE958
#define pinstCPvPLeaderboardWnd                                    0xBFE990
#define pinstCPvPStatsWnd                                          0xBFE9C8
#define pinstCSystemInfoDialogBox                                  0xBFEC50
#define pinstCTargetOfTargetWnd                                    0xBFF850
#define pinstCTaskSelectWnd                                        0xBFF8B8
#define pinstCTaskTemplateSelectWnd                                0xBFF8F0
#define pinstCTaskWnd                                              0xBFF928
#define pinstCTipWndOFDAY                                          0xBFFAA0
#define pinstCTipWndCONTEXT                                        0xBFFAA4
#define pinstCTitleWnd                                             0xBFFAD8
#define pinstCTradeskillWnd                                        0xBFFB50
#define pinstCTributeBenefitWnd                                    0xBFFBE8
#define pinstCTributeMasterWnd                                     0xBFFC20
#define pinstCContextMenuManager                                   0x1244100
#define pinstCVoiceMacroWnd                                        0xBCF708
#define pinstCHtmlWnd                                              0xBCF780


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D2E50
#define __ConvertItemTags                                          0x4C4260
#define __ExecuteCmd                                               0x4B0060
#define __get_melee_range                                          0x4B6030
#define __GetGaugeValueFromEQ                                      0x6BA630
#define __GetLabelFromEQ                                           0x6BB750
#define __GetXTargetType                                           0x731CA0
#define __LoadFrontEnd                                             0x59F3D0
#define __NewUIINI                                                 0x6BA1F0
#define __ProcessGameEvents                                        0x50AA70
#define CrashDetected                                              0x59F1D0
#define DrawNetStatus                                              0x534A80
#define Util__FastTime                                             0x7BCA40
#define Expansion_HoT                                              0xB56940

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483B80
#define AltAdvManager__IsAbilityReady                              0x483C00
#define AltAdvManager__GetAltAbility                               0x483E40

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x439530

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5BCF70

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C6EA0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x7829C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5DED60
#define CChatManager__InitContextMenu                              0x5DF530

// CChatService
#define CChatService__GetNumberOfFriends                           0x725DF0
#define CChatService__GetFriendName                                0x725E00

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5E3860
#define CChatWindow__Clear                                         0x5E41D0
#define CChatWindow__WndNotification                               0x5E43C0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x76C510
#define CComboWnd__Draw                                            0x76C6E0
#define CComboWnd__GetCurChoice                                    0x76C3D0
#define CComboWnd__GetListRect                                     0x76C9D0
#define CComboWnd__GetTextRect                                     0x76C540
#define CComboWnd__InsertChoice                                    0x76CA40
#define CComboWnd__SetColors                                       0x76C360
#define CComboWnd__SetChoice                                       0x76C390

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5ED620
#define CContainerWnd__vftable                                     0x8B3648

// CDisplay 
#define CDisplay__CleanGameUI                                      0x477980
#define CDisplay__GetClickedActor                                  0x4709C0
#define CDisplay__GetUserDefinedColor                              0x46F3A0
#define CDisplay__GetWorldFilePath                                 0x46E850
#define CDisplay__is3dON                                           0x46D980
#define CDisplay__ReloadUI                                         0x4809E0
#define CDisplay__WriteTextHD2                                     0x4736F0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B6FA0
#define CEditBaseWnd__SetSel                                       0x790240

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7758E0
#define CEditWnd__GetCharIndexPt                                   0x7768A0
#define CEditWnd__GetDisplayString                                 0x775A70
#define CEditWnd__GetHorzOffset                                    0x775D00
#define CEditWnd__GetLineForPrintableChar                          0x776350
#define CEditWnd__GetSelStartPt                                    0x776AF0
#define CEditWnd__GetSTMLSafeText                                  0x775EA0
#define CEditWnd__PointFromPrintableChar                           0x776460
#define CEditWnd__SelectableCharFromPoint                          0x7765E0
#define CEditWnd__SetEditable                                      0x775E70

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EAAD0
#define CEverQuest__DropHeldItemOnGround                           0x4F8050
#define CEverQuest__dsp_chat                                       0x4F0F00
#define CEverQuest__DoTellWindow                                   0x4EF670
#define CEverQuest__EnterZone                                      0x502360
#define CEverQuest__GetBodyTypeDesc                                0x4E7940
#define CEverQuest__GetClassDesc                                   0x4E7180
#define CEverQuest__GetClassThreeLetterCode                        0x4E7780
#define CEverQuest__GetDeityDesc                                   0x4E7FB0
#define CEverQuest__GetLangDesc                                    0x4E7CD0
#define CEverQuest__GetRaceDesc                                    0x4E7F80
#define CEverQuest__InterpretCmd                                   0x4F1B10
#define CEverQuest__LeftClickedOnPlayer                            0x504450
#define CEverQuest__LMouseUp                                       0x507FC0
#define CEverQuest__RightClickedOnPlayer                           0x509120
#define CEverQuest__RMouseUp                                       0x50A2B0
#define CEverQuest__SetGameState                                   0x4EAF60
#define CEverQuest__Emote                                          0x4F1120

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5FA300
#define CGaugeWnd__CalcLinesFillRect                               0x5FA360
#define CGaugeWnd__Draw                                            0x5FA7B0

// CGuild
#define CGuild__FindMemberByName                                   0x41B9A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x613490

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x61EEB0
#define CInvSlotMgr__MoveItem                                      0x61F2C0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x61E360
#define CInvSlot__SliderComplete                                   0x61C750
#define CInvSlot__GetItemBase                                      0x61BEB0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x6200A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6B7EE0
#define CItemDisplayWnd__UpdateStrings                             0x620F90

// CLabel 
#define CLabel__Draw                                               0x6353A0

// CListWnd 
#define CListWnd__AddColumn                                        0x765010
#define CListWnd__AddColumn1                                       0x7646C0
#define CListWnd__AddLine                                          0x764220
#define CListWnd__AddString                                        0x7643C0
#define CListWnd__CalculateFirstVisibleLine                        0x760530
#define CListWnd__CalculateVSBRange                                0x762860
#define CListWnd__ClearAllSel                                      0x75FA80
#define CListWnd__CloseAndUpdateEditWindow                         0x763890
#define CListWnd__Compare                                          0x760F30
#define CListWnd__Draw                                             0x7624A0
#define CListWnd__DrawColumnSeparators                             0x762310
#define CListWnd__DrawHeader                                       0x75FD10
#define CListWnd__DrawItem                                         0x761930
#define CListWnd__DrawLine                                         0x761F90
#define CListWnd__DrawSeparator                                    0x7623B0
#define CListWnd__EnsureVisible                                    0x760690
#define CListWnd__ExtendSel                                        0x761850
#define CListWnd__GetColumnMinWidth                                0x75F750
#define CListWnd__GetColumnWidth                                   0x75F690
#define CListWnd__GetCurSel                                        0x75EF10
#define CListWnd__GetHeaderRect                                    0x75F070
#define CListWnd__GetItemAtPoint                                   0x760960
#define CListWnd__GetItemAtPoint1                                  0x7609D0
#define CListWnd__GetItemData                                      0x75F290
#define CListWnd__GetItemHeight                                    0x7601A0
#define CListWnd__GetItemIcon                                      0x75F470
#define CListWnd__GetItemRect                                      0x760760
#define CListWnd__GetItemText                                      0x75F320
#define CListWnd__GetSelList                                       0x7645A0
#define CListWnd__GetSeparatorRect                                 0x760E80
#define CListWnd__RemoveLine                                       0x764550
#define CListWnd__SetColors                                        0x75EFE0
#define CListWnd__SetColumnJustification                           0x75F8F0
#define CListWnd__SetColumnWidth                                   0x75F710
#define CListWnd__SetCurSel                                        0x75EF50
#define CListWnd__SetItemColor                                     0x763550
#define CListWnd__SetItemData                                      0x75FB20
#define CListWnd__SetItemText                                      0x763330
#define CListWnd__ShiftColumnSeparator                             0x7631A0
#define CListWnd__Sort                                             0x765750
#define CListWnd__ToggleSel                                        0x75F9F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x64B3A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x65D750
#define CMerchantWnd__RequestBuyItem                               0x6610B0
#define CMerchantWnd__RequestSellItem                              0x680F20
#define CMerchantWnd__SelectBuySellSlot                            0x65ECF0

// CObfuscator
#define CObfuscator__doit                                          0x6F66C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x77E180
#define CSidlManager__CreateLabel                                  0x6B0D70

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5B9140
#define CSidlScreenWnd__CalculateVSBRange                          0x5B9060
#define CSidlScreenWnd__ConvertToRes                               0x790120
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x76EAC0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x76FB50
#define CSidlScreenWnd__CSidlScreenWnd2                            0x76FC00
#define CSidlScreenWnd__dCSidlScreenWnd                            0x76F370
#define CSidlScreenWnd__DrawSidlPiece                              0x76E590
#define CSidlScreenWnd__EnableIniStorage                           0x76DD50
#define CSidlScreenWnd__GetSidlPiece                               0x76E7A0
#define CSidlScreenWnd__Init1                                      0x76F9B0
#define CSidlScreenWnd__LoadIniInfo                                0x76EB70
#define CSidlScreenWnd__LoadIniListWnd                             0x76DEA0
#define CSidlScreenWnd__LoadSidlScreen                             0x76F5C0
#define CSidlScreenWnd__StoreIniInfo                               0x76D950
#define CSidlScreenWnd__StoreIniVis                                0x76DCE0
#define CSidlScreenWnd__WndNotification                            0x76F7A0
#define CSidlScreenWnd__GetChildItem                               0x76DDB0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x56C440

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x790B10
#define CSliderWnd__SetValue                                       0x790C10
#define CSliderWnd__SetNumTicks                                    0x7911C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6B5AF0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x78D7B0
#define CStmlWnd__CalculateHSBRange                                0x784EC0
#define CStmlWnd__CalculateVSBRange                                0x784E30
#define CStmlWnd__CanBreakAtCharacter                              0x785030
#define CStmlWnd__FastForwardToEndOfTag                            0x785D10
#define CStmlWnd__ForceParseNow                                    0x78DCE0
#define CStmlWnd__GetNextTagPiece                                  0x785C30
#define CStmlWnd__GetSTMLText                                      0x5E3800
#define CStmlWnd__GetThisChar                                      0x7B5680
#define CStmlWnd__GetVisiableText                                  0x787160
#define CStmlWnd__InitializeWindowVariables                        0x789730
#define CStmlWnd__MakeStmlColorTag                                 0x783D50
#define CStmlWnd__MakeWndNotificationTag                           0x783DF0
#define CStmlWnd__SetSTMLText                                      0x789850
#define CStmlWnd__StripFirstSTMLLines                              0x78D460
#define CStmlWnd__UpdateHistoryString                              0x7879F0

// CTabWnd 
#define CTabWnd__Draw                                              0x7920C0
#define CTabWnd__DrawCurrentPage                                   0x791990
#define CTabWnd__DrawTab                                           0x791770
#define CTabWnd__GetCurrentPage                                    0x791D50
#define CTabWnd__GetPageClientRect                                 0x791420
#define CTabWnd__GetPageFromTabIndex                               0x7916A0
#define CTabWnd__GetPageInnerRect                                  0x791480
#define CTabWnd__GetTabInnerRect                                   0x791620
#define CTabWnd__GetTabRect                                        0x791510
#define CTabWnd__InsertPage                                        0x792350
#define CTabWnd__SetPage                                           0x791D90
#define CTabWnd__SetPageRect                                       0x791FF0
#define CTabWnd__UpdatePage                                        0x7922D0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417F60

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x76FF80

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x792F60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x75DE10

// CXRect 
#define CXRect__CenterPoint                                        0x5353F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x416170
#define CXStr__CXStr1                                              0x41E130
#define CXStr__CXStr3                                              0x7B9C50
#define CXStr__dCXStr                                              0x6B8C90
#define CXStr__operator_equal                                      0x7B9DC0
#define CXStr__operator_equal1                                     0x7B9E10
#define CXStr__operator_plus_equal1                                0x7BAEA0

// CXWnd 
#define CXWnd__BringToTop                                          0x765D30
#define CXWnd__Center                                              0x76ADB0
#define CXWnd__ClrFocus                                            0x765B60
#define CXWnd__DoAllDrawing                                        0x76B700
#define CXWnd__DrawChildren                                        0x76B850
#define CXWnd__DrawColoredRect                                     0x766010
#define CXWnd__DrawTooltip                                         0x76ACE0
#define CXWnd__DrawTooltipAtPoint                                  0x76A380
#define CXWnd__GetBorderFrame                                      0x766550
#define CXWnd__GetChildWndAt                                       0x7697F0
#define CXWnd__GetClientClipRect                                   0x7662D0
#define CXWnd__GetScreenClipRect                                   0x76A8D0
#define CXWnd__GetScreenRect                                       0x766670
#define CXWnd__GetTooltipRect                                      0x766120
#define CXWnd__GetWindowTextA                                      0x5AA4E0
#define CXWnd__IsActive                                            0x7710B0
#define CXWnd__IsDescendantOf                                      0x766440
#define CXWnd__IsReallyVisible                                     0x7697D0
#define CXWnd__IsType                                              0x795D70
#define CXWnd__Move                                                0x768CE0
#define CXWnd__Move1                                               0x768D80
#define CXWnd__ProcessTransition                                   0x765CE0
#define CXWnd__Refade                                              0x765C60
#define CXWnd__Resize                                              0x766740
#define CXWnd__Right                                               0x76A7E0
#define CXWnd__SetFocus                                            0x767EE0
#define CXWnd__SetKeyTooltip                                       0x766990
#define CXWnd__SetMouseOver                                        0x76ABC0
#define CXWnd__StartFade                                           0x765D60
#define CXWnd__GetChildItem                                        0x76AB30

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x772620
#define CXWndManager__DrawWindows                                  0x7722A0
#define CXWndManager__GetKeyboardFlags                             0x770D10
#define CXWndManager__HandleKeyboardMsg                            0x771380
#define CXWndManager__RemoveWnd                                    0x7711D0

// CDBStr
#define CDBStr__GetString                                          0x46C1E0

// EQ_Character 
#define EQ_Character__CastRay                                      0x7137F0
#define EQ_Character__CastSpell                                    0x4303B0
#define EQ_Character__Cur_HP                                       0x4391F0
#define EQ_Character__GetAACastingTimeModifier                     0x425360
#define EQ_Character__GetCharInfo2                                 0x712590
#define EQ_Character__GetFocusCastingTimeModifier                  0x420AB0
#define EQ_Character__GetFocusRangeModifier                        0x420C80
#define EQ_Character__Max_Endurance                                0x53CC70
#define EQ_Character__Max_HP                                       0x4341B0
#define EQ_Character__Max_Mana                                     0x53CA70
#define EQ_Character__doCombatAbility                              0x53B8F0
#define EQ_Character__UseSkill                                     0x447A80
#define EQ_Character__GetConLevel                                  0x5368D0
#define EQ_Character__IsExpansionFlag                              0x40D8B0
#define EQ_Character__TotalEffect                                  0x4298A0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x51BBF0
#define EQ_Item__CreateItemTagString                               0x701960
#define EQ_Item__IsStackable                                       0x6F6D40

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x484EF0
#define EQ_LoadingS__Array                                         0x946468

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x5401A0
#define EQ_PC__GetAltAbilityIndex                                  0x7076E0
#define EQ_PC__GetCombatAbility                                    0x707770
#define EQ_PC__GetCombatAbilityTimer                               0x707820
#define EQ_PC__GetItemTimerValue                                   0x53B710
#define EQ_PC__HasLoreItem                                         0x7110F0

// EQItemList 
#define EQItemList__EQItemList                                     0x4B4320
#define EQItemList__add_item                                       0x4B42B0
#define EQItemList__delete_item                                    0x4B46D0
#define EQItemList__FreeItemList                                   0x4B4600

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46B9D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x544D70
#define EQPlayer__dEQPlayer                                        0x5497E0
#define EQPlayer__DoAttack                                         0x55A650
#define EQPlayer__EQPlayer                                         0x54F090
#define EQPlayer__SetNameSpriteState                               0x5471A0
#define EQPlayer__SetNameSpriteTint                                0x544DE0
#define EQPlayer__IsBodyType_j                                     0x7130B0
#define EQPlayer__IsTargetable                                     0x713370

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x550370
#define EQPlayerManager__GetSpawnByName                            0x550600

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x5216B0
#define KeypressHandler__AttachKeyToEqCommand                      0x5216F0
#define KeypressHandler__ClearCommandStateArray                    0x5214C0
#define KeypressHandler__HandleKeyDown                             0x51FEC0
#define KeypressHandler__HandleKeyUp                               0x5201D0
#define KeypressHandler__SaveKeymapping                            0x521590

// MapViewMap 
#define MapViewMap__Clear                                          0x646A40
#define MapViewMap__SaveEx                                         0x647410

#define PlayerPointManager__GetAltCurrency                         0x702AF0

// StringTable 
#define StringTable__getString                                     0x6F6940

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x53E930
