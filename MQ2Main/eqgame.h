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
#define __ExpectedVersionDate                                     "Sep 14 2009"
#define __ExpectedVersionTime                                     "16:27:26"
#define __ActualVersionDate                                        0x7F8D18
#define __ActualVersionTime                                        0x7F8D24

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x5077E0
#define __MemChecker1                                              0x6C5B70
#define __MemChecker2                                              0x566560
#define __MemChecker3                                              0x566610
#define __MemChecker4                                              0x680040
#define __EncryptPad0                                              0x884778
#define __EncryptPad1                                              0x88EF50
#define __EncryptPad2                                              0x887210
#define __EncryptPad3                                              0x886E10
#define __EncryptPad4                                              0x88E5D8
#define __AC1                                                      0x648920
#define __AC2                                                      0x4D31D5
#define __AC3                                                      0x4E6D48
#define __AC4                                                      0x4EAC18
#define __AC5                                                      0x4F5348
#define __AC6                                                      0x4F871B
#define __AC7                                                      0x4F18A4
#define __AC1_Data                                                 0x7E20C0

// Direct Input
#define DI8__Main                                                  0xAE58AC
#define DI8__Keyboard                                              0xAE58B0
#define DI8__Mouse                                                 0xAE58B4
#define __AltTimerReady                                            0xA701AA
#define __Attack                                                   0xACFC9E
#define __Autofire                                                 0xACFC9F
#define __BindList                                                 0x87F6D0
#define __Clicks                                                   0xA6EEB0
#define __CommandList                                              0x87FF50
#define __CurrentMapLabel                                          0xB10AE8
#define __CurrentSocial                                            0x87B6DC
#define __DoAbilityAvailable                                       0xA70144
#define __DoAbilityList                                            0xAA5764
#define __do_loot                                                  0x4AC350
#define __DrawHandler                                              0xB1FF5C
#define __GroupCount                                               0xA6916A
#define __Guilds                                                   0xA6E290
#define __gWorld                                                   0xA6AC28
#define __HotkeyPage                                               0xACCB50
#define __HWnd                                                     0xAE55E8
#define __InChatMode                                               0xA6EDE8
#define __LastTell                                                 0xA70ABC
#define __LMouseHeldTime                                           0xA6EEDC
#define __Mouse                                                    0xAE58B8
#define __MouseLook                                                0xA6EE7E
#define __MouseEventTime                                           0xACFDB0
#define __NetStatusToggle                                          0xA6EE81
#define __PCNames                                                  0xA70500
#define __RangeAttackReady                                         0xA701A8
#define __RMouseHeldTime                                           0xA6EED8
#define __RunWalkState                                             0xA6EDEC
#define __ScreenMode                                               0x9B8A30
#define __ScreenX                                                  0xA6EDA0
#define __ScreenY                                                  0xA6EDA4
#define __ScreenXMax                                               0xA6EDA8
#define __ScreenYMax                                               0xA6EDAC
#define __ServerHost                                               0xA690AC
#define __ServerName                                               0xAA5724
#define __ShiftKeyDown                                             0xA6F45C
#define __ShowNames                                                0xA703D8
#define __Socials                                                  0xAA5824


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA6ACE8
#define instEQZoneInfo                                             0xA6F028
#define instKeypressHandler                                        0xACFD94
#define pinstActiveBanker                                          0xA6ACC0
#define pinstActiveCorpse                                          0xA6ACC4
#define pinstActiveGMaster                                         0xA6ACC8
#define pinstActiveMerchant                                        0xA6ACBC
#define pinstAltAdvManager                                         0x9B9898
#define pinstAuraMgr                                               0x8A22F4
#define pinstBandageTarget                                         0xA6ACA8
#define pinstCamActor                                              0x9B9384
#define pinstCDBStr                                                0x9B8A20
#define pinstCDisplay                                              0xA6ACD0
#define pinstCEverQuest                                            0xAE5A30
#define pinstCharData                                              0xA6AC8C
#define pinstCharSpawn                                             0xA6ACB4
#define pinstControlledMissile                                     0xA6AC88
#define pinstControlledPlayer                                      0xA6ACB4
#define pinstCSidlManager                                          0xB1F6E0
#define pinstCXWndManager                                          0xB1F6D8
#define instDynamicZone                                            0xA6EC70
#define pinstDZMember                                              0xA6ED80
#define pinstDZTimerInfo                                           0xA6ED84
#define pinstEQItemList                                            0xA6AC70
#define instEQMisc                                                 0x9B89D8
#define pinstEQSoundManager                                        0x9B98BC
#define instExpeditionLeader                                       0xA6ECBA
#define instExpeditionName                                         0xA6ECFA
#define pinstGroup                                                 0xA69166
#define pinstImeManager                                            0xB1F6E4
#define pinstLocalPlayer                                           0xA6ACA0
#define pinstMercenaryData                                         0xAD0108
#define pinstModelPlayer                                           0xA6ACCC
#define pinstPCData                                                0xA6AC8C
#define pinstSkillMgr                                              0xAE26A8
#define pinstSpawnManager                                          0xAE2504
#define pinstSpellManager                                          0xAE26AC
#define pinstSpellSets                                             0xACCB54
#define pinstStringTable                                           0xA6AC44
#define pinstSwitchManager                                         0xA68DAC
#define pinstTarget                                                0xA6ACB8
#define pinstTargetObject                                          0xA6AC90
#define pinstTargetSwitch                                          0xA6AC94
#define pinstTaskMember                                            0x9B89B8
#define pinstTrackTarget                                           0xA6ACAC
#define pinstTradeTarget                                           0xA6AC9C
#define instTributeActive                                          0x9B89FD
#define pinstViewActor                                             0x9B9380
#define pinstWorldData                                             0xA6AC6C


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x89FBA4
#define pinstCAudioTriggersWindow                                  0x89FB70
#define pinstCCharacterSelect                                      0x9B928C
#define pinstCFacePick                                             0x9B9240
#define pinstCNoteWnd                                              0x9B9244
#define pinstCBookWnd                                              0x9B9248
#define pinstCPetInfoWnd                                           0x9B924C
#define pinstCTrainWnd                                             0x9B9250
#define pinstCSkillsWnd                                            0x9B9254
#define pinstCSkillsSelectWnd                                      0x9B9258
#define pinstCCombatSkillSelectWnd                                 0x9B925C
#define pinstCFriendsWnd                                           0x9B9260
#define pinstCAuraWnd                                              0x9B9264
#define pinstCRespawnWnd                                           0x9B9268
#define pinstCBandolierWnd                                         0x9B926C
#define pinstCPotionBeltWnd                                        0x9B9270
#define pinstCAAWnd                                                0x9B9274
#define pinstCGroupSearchFiltersWnd                                0x9B9278
#define pinstCLoadskinWnd                                          0x9B927C
#define pinstCAlarmWnd                                             0x9B9280
#define pinstCMusicPlayerWnd                                       0x9B9284
#define pinstCMailWnd                                              0x9B9290
#define pinstCMailCompositionWnd                                   0x9B9294
#define pinstCMailAddressBookWnd                                   0x9B9298
#define pinstCRaidWnd                                              0x9B92A0
#define pinstCRaidOptionsWnd                                       0x9B92A4
#define pinstCBreathWnd                                            0x9B92A8
#define pinstCMapViewWnd                                           0x9B92AC
#define pinstCMapToolbarWnd                                        0x9B92B0
#define pinstCEditLabelWnd                                         0x9B92B4
#define pinstCTargetWnd                                            0x9B92B8
#define pinstCColorPickerWnd                                       0x9B92BC
#define pinstCPlayerWnd                                            0x9B92C0
#define pinstCOptionsWnd                                           0x9B92C4
#define pinstCBuffWindowNORMAL                                     0x9B92C8
#define pinstCBuffWindowSHORT                                      0x9B92CC
#define pinstCharacterCreation                                     0x9B92D0
#define pinstCCursorAttachment                                     0x9B92D4
#define pinstCCastingWnd                                           0x9B92D8
#define pinstCCastSpellWnd                                         0x9B92DC
#define pinstCSpellBookWnd                                         0x9B92E0
#define pinstCInventoryWnd                                         0x9B92E4
#define pinstCBankWnd                                              0x9B92E8
#define pinstCQuantityWnd                                          0x9B92EC
#define pinstCLootWnd                                              0x9B92F0
#define pinstCActionsWnd                                           0x9B92F4
#define pinstCCombatAbilityWnd                                     0x9B92F8
#define pinstCMerchantWnd                                          0x9B92FC
#define pinstCTradeWnd                                             0x9B9300
#define pinstCSelectorWnd                                          0x9B9304
#define pinstCBazaarWnd                                            0x9B9308
#define pinstCBazaarSearchWnd                                      0x9B930C
#define pinstCGiveWnd                                              0x9B9310
#define pinstCTrackingWnd                                          0x9B9314
#define pinstCInspectWnd                                           0x9B9318
#define pinstCSocialEditWnd                                        0x9B931C
#define pinstCFeedbackWnd                                          0x9B9320
#define pinstCBugReportWnd                                         0x9B9324
#define pinstCVideoModesWnd                                        0x9B9328
#define pinstCTextEntryWnd                                         0x9B9330
#define pinstCFileSelectionWnd                                     0x9B9334
#define pinstCCompassWnd                                           0x9B9338
#define pinstCPlayerNotesWnd                                       0x9B933C
#define pinstCGemsGameWnd                                          0x9B9340
#define pinstCTimeLeftWnd                                          0x9B9344
#define pinstCPetitionQWnd                                         0x9B9350
#define pinstCSoulmarkWnd                                          0x9B9354
#define pinstCStoryWnd                                             0x9B9358
#define pinstCJournalTextWnd                                       0x9B935C
#define pinstCJournalCatWnd                                        0x9B9360
#define pinstCBodyTintWnd                                          0x9B9364
#define pinstCServerListWnd                                        0x9B9368
#define pinstCAvaZoneWnd                                           0x9B936C
#define pinstCBlockedBuffWnd                                       0x9B9370
#define pinstCBlockedPetBuffWnd                                    0x9B9374
#define pinstCInvSlotMgr                                           0x9B9378
#define pinstCContainerMgr                                         0x9B937C
#define pinstCAdventureLeaderboardWnd                              0xB0E018
#define pinstCAdventureRequestWnd                                  0xB0E034
#define pinstCAltStorageWnd                                        0xB0E094
#define pinstCAdventureStatsWnd                                    0xB0E050
#define pinstCBarterMerchantWnd                                    0xB0E260
#define pinstCBarterSearchWnd                                      0xB0E27C
#define pinstCBarterWnd                                            0xB0E298
#define pinstCChatManager                                          0xB0E53C
#define pinstCDynamicZoneWnd                                       0xB0E634
#define pinstCEQMainWnd                                            0xB0E6A8
#define pinstCFellowshipWnd                                        0xB0E70C
#define pinstCFindLocationWnd                                      0xB0E740
#define pinstCGroupSearchWnd                                       0xB0E7F0
#define pinstCGroupWnd                                             0xB0E80C
#define pinstCGuildBankWnd                                         0xB0E828
#define pinstCGuildMgmtWnd                                         0xB10860
#define pinstCGuildTributeMasterWnd                                0xB10880
#define pinstCHotButtonWnd                                         0xB1089C
#define pinstCHotButtonWnd1                                        0xB1089C
#define pinstCHotButtonWnd2                                        0xB108A0
#define pinstCHotButtonWnd3                                        0xB108A4
#define pinstCHotButtonWnd4                                        0xB108A8
#define pinstCItemDisplayManager                                   0xB10954
#define pinstCItemExpTransferWnd                                   0xB10974
#define pinstCLeadershipWnd                                        0xB10A10
#define pinstCLFGuildWnd                                           0xB10A2C
#define pinstCMIZoneSelectWnd                                      0xB10B9C
#define pinstCAdventureMerchantWnd                                 0xB10CAC
#define pinstCConfirmationDialog                                   0xB10CC8
#define pinstCPopupWndManager                                      0xB10CC8
#define pinstCProgressionSelectionWnd                              0xB10CFC
#define pinstCPvPLeaderboardWnd                                    0xB10D18
#define pinstCPvPStatsWnd                                          0xB10D34
#define pinstCSystemInfoDialogBox                                  0xB10DE8
#define pinstCTargetOfTargetWnd                                    0xB116F4
#define pinstCTaskSelectWnd                                        0xB11728
#define pinstCTaskTemplateSelectWnd                                0xB11744
#define pinstCTaskWnd                                              0xB11760
#define pinstCTipWndOFDAY                                          0xB117DC
#define pinstCTipWndCONTEXT                                        0xB117E0
#define pinstCTitleWnd                                             0xB117FC
#define pinstCTradeskillWnd                                        0xB11840
#define pinstCTributeBenefitWnd                                    0xB1188C
#define pinstCTributeMasterWnd                                     0xB118A8
#define pinstCContextMenuManager                                   0xB1F73C
#define pinstCVoiceMacroWnd                                        0xAE289C
#define pinstCHtmlWnd                                              0xAE28E8


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4BFD80
#define __ConvertItemTags                                          0x4B1910
#define __ExecuteCmd                                               0x49FDA0
#define __get_melee_range                                          0x4A5430
#define __GetGaugeValueFromEQ                                      0x647B60
#define __GetLabelFromEQ                                           0x6488C0
#define __LoadFrontEnd                                             0x5654E0
#define __NewUIINI                                                 0x6476F0
#define __ProcessGameEvents                                        0x4F1C90
#define CrashDetected                                              0x5652E0
#define DrawNetStatus                                              0x5100E0
#define Util__FastTime                                             0x6C6280


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x477310
#define AltAdvManager__IsAbilityReady                              0x477350
#define AltAdvManager__GetAltAbility                               0x477560

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x57D6C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x586F90

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6F49C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x59D0A0
#define CChatManager__InitContextMenu                              0x59D870

// CChatService
#define CChatService__GetNumberOfFriends                           0x6B4220
#define CChatService__GetFriendName                                0x6B4230

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5A1A50
#define CChatWindow__Clear                                         0x5A23D0
#define CChatWindow__WndNotification                               0x5A24B0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6DF0C0
#define CComboWnd__Draw                                            0x6DF270
#define CComboWnd__GetCurChoice                                    0x6DF060
#define CComboWnd__GetListRect                                     0x6DF530
#define CComboWnd__GetTextRect                                     0x6DF0F0
#define CComboWnd__InsertChoice                                    0x6DF5A0
#define CComboWnd__SetColors                                       0x6DEFF0
#define CComboWnd__SetChoice                                       0x6DF020

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A97A0
#define CContainerWnd__vftable                                     0x7FF978

// CDisplay 
#define CDisplay__CleanGameUI                                      0x4662A0
#define CDisplay__GetClickedActor                                  0x463A00
#define CDisplay__GetUserDefinedColor                              0x462B20
#define CDisplay__GetWorldFilePath                                 0x461FB0
#define CDisplay__is3dON                                           0x461120
#define CDisplay__ReloadUI                                         0x4744F0
#define CDisplay__WriteTextHD2                                     0x466A40

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x577640
#define CEditBaseWnd__SetSel                                       0x7005D0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6E7BD0
#define CEditWnd__GetCharIndexPt                                   0x6E8A10
#define CEditWnd__GetDisplayString                                 0x6E7D60
#define CEditWnd__GetHorzOffset                                    0x6E7FF0
#define CEditWnd__GetLineForPrintableChar                          0x6E84C0
#define CEditWnd__GetSelStartPt                                    0x6E8C50
#define CEditWnd__GetSTMLSafeText                                  0x6E8180
#define CEditWnd__PointFromPrintableChar                           0x6E85D0
#define CEditWnd__SelectableCharFromPoint                          0x6E8750
#define CEditWnd__SetEditable                                      0x6E8150

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D38B0
#define CEverQuest__DropHeldItemOnGround                           0x4D7B90
#define CEverQuest__dsp_chat                                       0x4D9340
#define CEverQuest__DoTellWindow                                   0x4D7D10
#define CEverQuest__EnterZone                                      0x4EABB0
#define CEverQuest__GetBodyTypeDesc                                0x4D0AB0
#define CEverQuest__GetClassDesc                                   0x4D02F0
#define CEverQuest__GetClassThreeLetterCode                        0x4D08F0
#define CEverQuest__GetDeityDesc                                   0x4D1120
#define CEverQuest__GetLangDesc                                    0x4D0E40
#define CEverQuest__GetRaceDesc                                    0x4D10F0
#define CEverQuest__InterpretCmd                                   0x4D9D50
#define CEverQuest__LeftClickedOnPlayer                            0x4EC700
#define CEverQuest__LMouseUp                                       0x4EFFE0
#define CEverQuest__RightClickedOnPlayer                           0x4F0880
#define CEverQuest__RMouseUp                                       0x4F1860
#define CEverQuest__SetGameState                                   0x4D3D40
#define CEverQuest__Emote                                          0x4D9560

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5B6170
#define CGaugeWnd__CalcLinesFillRect                               0x5B61D0
#define CGaugeWnd__Draw                                            0x5B65E0

// CGuild
#define CGuild__FindMemberByName                                   0x418210

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5CE720

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5D7DA0
#define CInvSlotMgr__MoveItem                                      0x5D7F40

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5D7630
#define CInvSlot__SliderComplete                                   0x5D6770

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5D8EE0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6457B0
#define CItemDisplayWnd__UpdateStrings                             0x5D9BE0

// CLabel 
#define CLabel__Draw                                               0x5EC4D0

// CListWnd 
#define CListWnd__AddColumn                                        0x6D98F0
#define CListWnd__AddColumn1                                       0x6D93D0
#define CListWnd__AddLine                                          0x6D8EA0
#define CListWnd__AddString                                        0x6D90A0
#define CListWnd__CalculateFirstVisibleLine                        0x6D60A0
#define CListWnd__CalculateVSBRange                                0x6D7ED0
#define CListWnd__ClearAllSel                                      0x6D5760
#define CListWnd__CloseAndUpdateEditWindow                         0x6D6715
#define CListWnd__Compare                                          0x6D6A90
#define CListWnd__Draw                                             0x6D7BB0
#define CListWnd__DrawColumnSeparators                             0x6D7A20
#define CListWnd__DrawHeader                                       0x6D5970
#define CListWnd__DrawItem                                         0x6D7320
#define CListWnd__DrawLine                                         0x6D76C0
#define CListWnd__DrawSeparator                                    0x6D7AC0
#define CListWnd__EnsureVisible                                    0x6D6130
#define CListWnd__ExtendSel                                        0x6D7240
#define CListWnd__GetColumnMinWidth                                0x6D54F0
#define CListWnd__GetColumnWidth                                   0x6D5430
#define CListWnd__GetCurSel                                        0x6D4E70
#define CListWnd__GetHeaderRect                                    0x6D4FE0
#define CListWnd__GetItemAtPoint                                   0x6D6420
#define CListWnd__GetItemAtPoint1                                  0x6D6490
#define CListWnd__GetItemData                                      0x6D51E0
#define CListWnd__GetItemHeight                                    0x6D5E00
#define CListWnd__GetItemIcon                                      0x6D5370
#define CListWnd__GetItemRect                                      0x6D6200
#define CListWnd__GetItemText                                      0x6D5220
#define CListWnd__GetSelList                                       0x6D92B0
#define CListWnd__GetSeparatorRect                                 0x6D69D0
#define CListWnd__RemoveLine                                       0x6D9260
#define CListWnd__SetColors                                        0x6D4F40
#define CListWnd__SetColumnJustification                           0x6D55D0
#define CListWnd__SetColumnWidth                                   0x6D54B0
#define CListWnd__SetCurSel                                        0x6D4EB0
#define CListWnd__SetItemColor                                     0x6D8AF0
#define CListWnd__SetItemData                                      0x6D5800
#define CListWnd__SetItemText                                      0x6D8A70
#define CListWnd__ShiftColumnSeparator                             0x6D71B0
#define CListWnd__Sort                                             0x6D9930
#define CListWnd__ToggleSel                                        0x6D56D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x601C40

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x60D4F0
#define CMerchantWnd__RequestBuyItem                               0x60ED60
#define CMerchantWnd__RequestSellItem                              0x60F180
#define CMerchantWnd__SelectBuySellSlot                            0x60E220

// CObfuscator
#define CObfuscator__doit                                          0x68F0F0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6F0050
#define CSidlManager__CreateLabel                                  0x63E7A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6E0CB0
#define CSidlScreenWnd__CalculateVSBRange                          0x6F63B0
#define CSidlScreenWnd__ConvertToRes                               0x7004B0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6E1130
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6E2200
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6E22B0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6E19D0
#define CSidlScreenWnd__DrawSidlPiece                              0x6E0E00
#define CSidlScreenWnd__EnableIniStorage                           0x6E09A0
#define CSidlScreenWnd__GetSidlPiece                               0x6E1000
#define CSidlScreenWnd__Init1                                      0x6E2070
#define CSidlScreenWnd__LoadIniInfo                                0x6E11E0
#define CSidlScreenWnd__LoadIniListWnd                             0x6E0AF0
#define CSidlScreenWnd__LoadSidlScreen                             0x6E1C20
#define CSidlScreenWnd__StoreIniInfo                               0x6E05B0
#define CSidlScreenWnd__WndNotification                            0x6E1DF0
#define CSidlScreenWnd__GetChildItem                               0x6E0A00

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x533210

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x701A00
#define CSliderWnd__SetValue                                       0x701B00
#define CSliderWnd__SetNumTicks                                    0x702070

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x643540

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6FE710
#define CStmlWnd__CalculateVSBRange                                0x6F63B0
#define CStmlWnd__CanBreakAtCharacter                              0x6F64F0
#define CStmlWnd__FastForwardToEndOfTag                            0x6F7140
#define CStmlWnd__ForceParseNow                                    0x6FEBB0
#define CStmlWnd__GetNextTagPiece                                  0x6F7060
#define CStmlWnd__GetSTMLText                                      0x5A19F0
#define CStmlWnd__GetThisChar                                      0x724130
#define CStmlWnd__GetVisiableText                                  0x6F8510
#define CStmlWnd__InitializeWindowVariables                        0x6FA780
#define CStmlWnd__MakeStmlColorTag                                 0x6F5630
#define CStmlWnd__MakeWndNotificationTag                           0x6F56D0
#define CStmlWnd__SetSTMLText                                      0x6FA8B0
#define CStmlWnd__StripFirstSTMLLines                              0x6FE4A0
#define CStmlWnd__UpdateHistoryString                              0x6F8D80

// CTabWnd 
#define CTabWnd__Draw                                              0x702E80
#define CTabWnd__DrawCurrentPage                                   0x702820
#define CTabWnd__DrawTab                                           0x702600
#define CTabWnd__GetCurrentPage                                    0x702B20
#define CTabWnd__GetPageClientRect                                 0x7022D0
#define CTabWnd__GetPageFromTabIndex                               0x702530
#define CTabWnd__GetPageInnerRect                                  0x702330
#define CTabWnd__GetTabInnerRect                                   0x7024B0
#define CTabWnd__GetTabRect                                        0x7023C0
#define CTabWnd__InsertPage                                        0x7030F0
#define CTabWnd__SetPage                                           0x702B60
#define CTabWnd__SetPageRect                                       0x702DB0
#define CTabWnd__UpdatePage                                        0x703070

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4147B0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6E2610

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x707450

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6D4B60

// CXRect 
#define CXRect__CenterPoint                                        0x57CD40

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x501280
#define CXStr__CXStr1                                              0x703BE0
#define CXStr__CXStr3                                              0x6C7950
#define CXStr__dCXStr                                              0x406730
#define CXStr__operator_equal1                                     0x6C7B10
#define CXStr__operator_plus_equal1                                0x6C8B50

// CXWnd 
#define CXWnd__BringToTop                                          0x6DA010
#define CXWnd__Center                                              0x6DDA50
#define CXWnd__ClrFocus                                            0x6D9D30
#define CXWnd__DoAllDrawing                                        0x6DE860
#define CXWnd__DrawChildren                                        0x6DE990
#define CXWnd__DrawColoredRect                                     0x6DA290
#define CXWnd__DrawTooltip                                         0x6DE680
#define CXWnd__DrawTooltipAtPoint                                  0x6DD810
#define CXWnd__GetBorderFrame                                      0x6DA770
#define CXWnd__GetChildWndAt                                       0x6DD350
#define CXWnd__GetClientClipRect                                   0x6DA680
#define CXWnd__GetScreenClipRect                                   0x6DDC70
#define CXWnd__GetScreenRect                                       0x6DA910
#define CXWnd__GetTooltipRect                                      0x6DA4E0
#define CXWnd__GetWindowTextA                                      0x5700C0
#define CXWnd__IsActive                                            0x6E3720
#define CXWnd__IsDescendantOf                                      0x6DA700
#define CXWnd__IsReallyVisible                                     0x6DD330
#define CXWnd__IsType                                              0x7042F0
#define CXWnd__Move                                                0x6DCF10
#define CXWnd__Move1                                               0x6DE4E0
#define CXWnd__ProcessTransition                                   0x6D9FD0
#define CXWnd__Refade                                              0x6D9DE0
#define CXWnd__Resize                                              0x6DA9E0
#define CXWnd__Right                                               0x6DDBB0
#define CXWnd__SetFocus                                            0x6DC140
#define CXWnd__SetKeyTooltip                                       0x6DABF0
#define CXWnd__SetMouseOver                                        0x6DABC0
#define CXWnd__StartFade                                           0x6DA050
#define CXWnd__GetChildItem                                        0x6DDE30

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6E4B20
#define CXWndManager__DrawWindows                                  0x6E4730
#define CXWndManager__GetKeyboardFlags                             0x6E33D0
#define CXWndManager__HandleKeyboardMsg                            0x6E3920
#define CXWndManager__RemoveWnd                                    0x6E3840

// CDBStr
#define CDBStr__GetString                                          0x45FA60

// EQ_Character 
#define EQ_Character__CastRay                                      0x730210
#define EQ_Character__CastSpell                                    0x42ACD0
#define EQ_Character__Cur_HP                                       0x4344C0
#define EQ_Character__GetAACastingTimeModifier                     0x420B60
#define EQ_Character__GetCharInfo2                                 0x6A5370
#define EQ_Character__GetFocusCastingTimeModifier                  0x41C4E0
#define EQ_Character__GetFocusRangeModifier                        0x41C620
#define EQ_Character__Max_Endurance                                0x516240
#define EQ_Character__Max_HP                                       0x42F2D0
#define EQ_Character__Max_Mana                                     0x516070
#define EQ_Character__doCombatAbility                              0x514F80
#define EQ_Character__UseSkill                                     0x43DC00
#define EQ_Character__GetConLevel                                  0x511540

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4FF020
#define EQ_Item__GetItemLinkHash                                   0x698BA0
#define EQ_Item__IsStackable                                       0x68F9D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x478440
#define EQ_LoadingS__Array                                         0x87DBA0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x5190B0
#define EQ_PC__GetAltAbilityIndex                                  0x69D680
#define EQ_PC__GetCombatAbility                                    0x69D710
#define EQ_PC__GetCombatAbilityTimer                               0x69D7C0
#define EQ_PC__GetItemTimerValue                                   0x513ED0
#define EQ_PC__HasLoreItem                                         0x517580

// EQItemList 
#define EQItemList__dEQItemList                                    0x4A3990
#define EQItemList__EQItemList                                     0x4A38E0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45F3F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x51D920
#define EQPlayer__dEQPlayer                                        0x5219A0
#define EQPlayer__DoAttack                                         0x52F3F0
#define EQPlayer__EQPlayer                                         0x5256E0
#define EQPlayer__SetNameSpriteState                               0x51F910
#define EQPlayer__SetNameSpriteTint                                0x51D990
#define EQPlayer__IsBodyType_j                                     0x72FB20
#define EQPlayer__IsTargetable                                     0x72FCB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x526840
#define EQPlayerManager__GetSpawnByName                            0x526B20

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x500CA0
#define KeypressHandler__AttachKeyToEqCommand                      0x500CE0
#define KeypressHandler__ClearCommandStateArray                    0x500AB0
#define KeypressHandler__HandleKeyDown                             0x4FF630
#define KeypressHandler__HandleKeyUp                               0x4FF940
#define KeypressHandler__SaveKeymapping                            0x500B80

// MapViewMap 
#define MapViewMap__Clear                                          0x5FD310
#define MapViewMap__SaveEx                                         0x5FDCE0

#define OtherCharData__GetAltCurrency                              0x6BC960

// StringTable 
#define StringTable__getString                                     0x68F370
