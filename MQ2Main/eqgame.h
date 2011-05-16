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
#define __ExpectedVersionDate                                     "May 12 2011"
#define __ExpectedVersionTime                                     "13:57:14"
#define __ActualVersionDate                                        0x8A9EDC
#define __ActualVersionTime                                        0x8A9EE8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x528210
#define __MemChecker1                                              0x7BB940
#define __MemChecker2                                              0x5A0850
#define __MemChecker3                                              0x5A07A0
#define __MemChecker4                                              0x7DD6B0
#define __EncryptPad0                                              0x94BB48
#define __EncryptPad1                                              0x957D38
#define __EncryptPad2                                              0x94E8E0
#define __EncryptPad3                                              0x94E4E0
#define __EncryptPad4                                              0x9597E0
#define __AC1                                                      0x6BBAD0
#define __AC2                                                      0x4E9CF5
#define __AC3                                                      0x4FC548
#define __AC4                                                      0x501D94
#define __AC5                                                      0x50E03C
#define __AC6                                                      0x51179E
#define __AC7                                                      0x509C9B
#define __AC1_Data                                                 0x8914CD
// Direct Input
#define DI8__Main                                                  0xBB7244
#define DI8__Keyboard                                              0xBB7248
#define DI8__Mouse                                                 0xBB724C
#define __AltTimerReady                                            0xB3B20E
#define __Attack                                                   0xB9ED2A
#define __Autofire                                                 0xB9ED2B
#define __BindList                                                 0x9460A8
#define __Clicks                                                   0xB39EB8
#define __CommandList                                              0x946A98
#define __CurrentMapLabel                                          0xBE2F50
#define __CurrentSocial                                            0x9419D8
#define __DoAbilityAvailable                                       0xB3B1A8
#define __DoAbilityList                                            0xB70C48
#define __do_loot                                                  0x4BE650
#define __DrawHandler                                              0x1228604
#define __GroupCount                                               0xB3388A
#define __Guilds                                                   0xB35C18
#define __gWorld                                                   0xB35B44
#define __HotkeyPage                                               0xB98034
#define __HWnd                                                     0xBB6F80
#define __InChatMode                                               0xB39DF0
#define __LastTell                                                 0xB3BB60
#define __LMouseHeldTime                                           0xB39F24
#define __Mouse                                                    0xBB7250
#define __MouseLook                                                0xB39E86
#define __MouseEventTime                                           0xB9EFF4
#define __NetStatusToggle                                          0xB39E89
#define __PCNames                                                  0xB3B5A4
#define __RangeAttackReady                                         0xB3B20C
#define __RMouseHeldTime                                           0xB39F20
#define __RunWalkState                                             0xB39DF4
#define __ScreenMode                                               0xA82DC0
#define __ScreenX                                                  0xB39DA8
#define __ScreenY                                                  0xB39DAC
#define __ScreenXMax                                               0xB39DB0
#define __ScreenYMax                                               0xB39DB4
#define __ServerHost                                               0xB337CC
#define __ServerName                                               0xB70C08
#define __ShiftKeyDown                                             0xB3A4B4
#define __ShowNames                                                0xB3B448
#define __Socials                                                  0xB70D08


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xB36720
#define instEQZoneInfo                                             0xB3A070
#define instKeypressHandler                                        0xB9EFF0
#define pinstActiveBanker                                          0xB35BEC
#define pinstActiveCorpse                                          0xB35BF0
#define pinstActiveGMaster                                         0xB35BF4
#define pinstActiveMerchant                                        0xB35BE8
#define pinstAltAdvManager                                         0xA83CE8
#define pinstAuraMgr                                               0x96C470
#define pinstBandageTarget                                         0xB35BD4
#define pinstCamActor                                              0xA83760
#define pinstCDBStr                                                0xA82D98
#define pinstCDisplay                                              0xB35BFC
#define pinstCEverQuest                                            0xBB73C8
#define pinstCharData                                              0xB35BB8
#define pinstCharSpawn                                             0xB35BE0
#define pinstControlledMissile                                     0xB35BB4
#define pinstControlledPlayer                                      0xB35BE0
#define pinstCSidlManager                                          0x1228AD4
#define pinstCXWndManager                                          0x1228ACC
#define instDynamicZone                                            0xB36178
#define pinstDZMember                                              0xB36288
#define pinstDZTimerInfo                                           0xB3628C
#define pinstEQItemList                                            0xB32930
#define instEQMisc                                                 0xA82D10
#define pinstEQSoundManager                                        0xA83D58
#define instExpeditionLeader                                       0xB361C2
#define instExpeditionName                                         0xB36202
#define pinstGroup                                                 0xB33886
#define pinstImeManager                                            0x1228AD8
#define pinstLocalPlayer                                           0xB35BCC
#define pinstMercenaryData                                         0xB9F458
#define pinstModelPlayer                                           0xB35BF8
#define pinstPCData                                                0xB35BB8
#define pinstSkillMgr                                              0xBB3E28
#define pinstSpawnManager                                          0xBB3AC0
#define pinstSpellManager                                          0xBB3E68
#define pinstSpellSets                                             0xB98038
#define pinstStringTable                                           0xB35B60
#define pinstSwitchManager                                         0xB33498
#define pinstTarget                                                0xB35BE4
#define pinstTargetObject                                          0xB35BBC
#define pinstTargetSwitch                                          0xB35BC0
#define pinstTaskMember                                            0xA82CD8
#define pinstTrackTarget                                           0xB35BD8
#define pinstTradeTarget                                           0xB35BC8
#define instTributeActive                                          0xA82D35
#define pinstViewActor                                             0xA8375C
#define pinstWorldData                                             0xB35B9C


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x969BD0
#define pinstCAudioTriggersWindow                                  0x969B68
#define pinstCCharacterSelect                                      0xA83630
#define pinstCFacePick                                             0xA835E0
#define pinstCNoteWnd                                              0xA835E8
#define pinstCBookWnd                                              0xA835EC
#define pinstCPetInfoWnd                                           0xA835F0
#define pinstCTrainWnd                                             0xA835F4
#define pinstCSkillsWnd                                            0xA835F8
#define pinstCSkillsSelectWnd                                      0xA835FC
#define pinstCCombatSkillSelectWnd                                 0xA83600
#define pinstCFriendsWnd                                           0xA83604
#define pinstCAuraWnd                                              0xA83608
#define pinstCRespawnWnd                                           0xA8360C
#define pinstCBandolierWnd                                         0xA83610
#define pinstCPotionBeltWnd                                        0xA83614
#define pinstCAAWnd                                                0xA83618
#define pinstCGroupSearchFiltersWnd                                0xA8361C
#define pinstCLoadskinWnd                                          0xA83620
#define pinstCAlarmWnd                                             0xA83624
#define pinstCMusicPlayerWnd                                       0xA83628
#define pinstCMailWnd                                              0xA83634
#define pinstCMailCompositionWnd                                   0xA83638
#define pinstCMailAddressBookWnd                                   0xA8363C
#define pinstCRaidWnd                                              0xA83644
#define pinstCRaidOptionsWnd                                       0xA83648
#define pinstCBreathWnd                                            0xA8364C
#define pinstCMapViewWnd                                           0xA83650
#define pinstCMapToolbarWnd                                        0xA83654
#define pinstCEditLabelWnd                                         0xA83658
#define pinstCTargetWnd                                            0xA8365C
#define pinstCColorPickerWnd                                       0xA83660
#define pinstCPlayerWnd                                            0xA83664
#define pinstCOptionsWnd                                           0xA83668
#define pinstCBuffWindowNORMAL                                     0xA8366C
#define pinstCBuffWindowSHORT                                      0xA83670
#define pinstCharacterCreation                                     0xA83674
#define pinstCCursorAttachment                                     0xA83678
#define pinstCCastingWnd                                           0xA8367C
#define pinstCCastSpellWnd                                         0xA83680
#define pinstCSpellBookWnd                                         0xA83684
#define pinstCInventoryWnd                                         0xA83688
#define pinstCBankWnd                                              0xA8368C
#define pinstCQuantityWnd                                          0xA83690
#define pinstCLootWnd                                              0xA83694
#define pinstCActionsWnd                                           0xA83698
#define pinstCCombatAbilityWnd                                     0xA8369C
#define pinstCMerchantWnd                                          0xA836A0
#define pinstCTradeWnd                                             0xA836A4
#define pinstCSelectorWnd                                          0xA836A8
#define pinstCBazaarWnd                                            0xA836AC
#define pinstCBazaarSearchWnd                                      0xA836B0
#define pinstCGiveWnd                                              0xA836CC
#define pinstCTrackingWnd                                          0xA836D0
#define pinstCInspectWnd                                           0xA836D4
#define pinstCSocialEditWnd                                        0xA836D8
#define pinstCFeedbackWnd                                          0xA836DC
#define pinstCBugReportWnd                                         0xA836E0
#define pinstCVideoModesWnd                                        0xA836E4
#define pinstCTextEntryWnd                                         0xA836EC
#define pinstCFileSelectionWnd                                     0xA836F0
#define pinstCCompassWnd                                           0xA836F4
#define pinstCPlayerNotesWnd                                       0xA836F8
#define pinstCGemsGameWnd                                          0xA836FC
#define pinstCTimeLeftWnd                                          0xA83700
#define pinstCPetitionQWnd                                         0xA83714
#define pinstCSoulmarkWnd                                          0xA83718
#define pinstCStoryWnd                                             0xA8371C
#define pinstCJournalTextWnd                                       0xA83720
#define pinstCJournalCatWnd                                        0xA83724
#define pinstCBodyTintWnd                                          0xA83728
#define pinstCServerListWnd                                        0xA8372C
#define pinstCAvaZoneWnd                                           0xA83734
#define pinstCBlockedBuffWnd                                       0xA83738
#define pinstCBlockedPetBuffWnd                                    0xA8373C
#define pinstCInvSlotMgr                                           0xA83754
#define pinstCContainerMgr                                         0xA83758
#define pinstCAdventureLeaderboardWnd                              0xBDFB20
#define pinstCAdventureRequestWnd                                  0xBDFAE8
#define pinstCAltStorageWnd                                        0xBDFB98
#define pinstCAdventureStatsWnd                                    0xBDFB20
#define pinstCBarterMerchantWnd                                    0xBDFFF0
#define pinstCBarterSearchWnd                                      0xBE0028
#define pinstCBarterWnd                                            0xBE0060
#define pinstCChatManager                                          0xBE0458
#define pinstCDynamicZoneWnd                                       0xBE0648
#define pinstCEQMainWnd                                            0xBE0708
#define pinstCFellowshipWnd                                        0xBE07D0
#define pinstCFindLocationWnd                                      0xBE0838
#define pinstCGroupSearchWnd                                       0xBE0998
#define pinstCGroupWnd                                             0xBE09D0
#define pinstCGuildBankWnd                                         0xBE0A08
#define pinstCGuildMgmtWnd                                         0xBE2A78
#define pinstCGuildTributeMasterWnd                                0xBE2AB0
#define pinstCHotButtonWnd                                         0xBE2B00
#define pinstCHotButtonWnd1                                        0xBE2B00
#define pinstCHotButtonWnd2                                        0xBE2B04
#define pinstCHotButtonWnd3                                        0xBE2B08
#define pinstCHotButtonWnd4                                        0xBE2B0C
#define pinstCItemDisplayManager                                   0xBE2C48
#define pinstCItemExpTransferWnd                                   0xBE2C84
#define pinstCLeadershipWnd                                        0xBE2DB0
#define pinstCLFGuildWnd                                           0xBE2DE8
#define pinstCMIZoneSelectWnd                                      0xBE3080
#define pinstCAdventureMerchantWnd                                 0xBE3330
#define pinstCConfirmationDialog                                   0xBE3368
#define pinstCPopupWndManager                                      0xBE3368
#define pinstCProgressionSelectionWnd                              0xBE33D0
#define pinstCPvPLeaderboardWnd                                    0xBE3408
#define pinstCPvPStatsWnd                                          0xBE3440
#define pinstCSystemInfoDialogBox                                  0xBE36C8
#define pinstCTargetOfTargetWnd                                    0xBE42C8
#define pinstCTaskSelectWnd                                        0xBE4330
#define pinstCTaskTemplateSelectWnd                                0xBE4368
#define pinstCTaskWnd                                              0xBE43A0
#define pinstCTipWndOFDAY                                          0xBE44D8
#define pinstCTipWndCONTEXT                                        0xBE44DC
#define pinstCTitleWnd                                             0xBE4510
#define pinstCTradeskillWnd                                        0xBE4588
#define pinstCTributeBenefitWnd                                    0xBE4620
#define pinstCTributeMasterWnd                                     0xBE4658
#define pinstCContextMenuManager                                   0x1228B30
#define pinstCVoiceMacroWnd                                        0xBB4180
#define pinstCHtmlWnd                                              0xBB41F8


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D2910
#define __ConvertItemTags                                          0x4C3DF0
#define __ExecuteCmd                                               0x4AFC80
#define __get_melee_range                                          0x4B5C20
#define __GetGaugeValueFromEQ                                      0x6BA950
#define __GetLabelFromEQ                                           0x6BBA70
#define __GetXTargetType                                           0x730F30
#define __LoadFrontEnd                                             0x59F770
#define __NewUIINI                                                 0x6BA510
#define __ProcessGameEvents                                        0x50A410
#define CrashDetected                                              0x59F570
#define DrawNetStatus                                              0x534880
#define Util__FastTime                                             0x7BC140
#define Expansion_HoT                                              0xB3B3A8

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483BB0
#define AltAdvManager__IsAbilityReady                              0x483CD0
#define AltAdvManager__GetAltAbility                               0x483F10

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x439590

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5BD440

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C74B0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x782000

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5DF470
#define CChatManager__InitContextMenu                              0x5DFC40

// CChatService
#define CChatService__GetNumberOfFriends                           0x725A30
#define CChatService__GetFriendName                                0x725A40

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5E3F70
#define CChatWindow__Clear                                         0x5E48D0
#define CChatWindow__WndNotification                               0x5E4AC0

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
#define CContainerWnd__HandleCombine                               0x5EDCE0
#define CContainerWnd__vftable                                     0x8B1720

// CDisplay 
#define CDisplay__CleanGameUI                                      0x4779C0
#define CDisplay__GetClickedActor                                  0x4709D0
#define CDisplay__GetUserDefinedColor                              0x46F3B0
#define CDisplay__GetWorldFilePath                                 0x46E860
#define CDisplay__is3dON                                           0x46D990
#define CDisplay__ReloadUI                                         0x480A10
#define CDisplay__WriteTextHD2                                     0x473730

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B7420
#define CEditBaseWnd__SetSel                                       0x78F8C0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x774ED0
#define CEditWnd__GetCharIndexPt                                   0x775E90
#define CEditWnd__GetDisplayString                                 0x775060
#define CEditWnd__GetHorzOffset                                    0x7752F0
#define CEditWnd__GetLineForPrintableChar                          0x775940
#define CEditWnd__GetSelStartPt                                    0x7760E0
#define CEditWnd__GetSTMLSafeText                                  0x775490
#define CEditWnd__PointFromPrintableChar                           0x775A50
#define CEditWnd__SelectableCharFromPoint                          0x775BD0
#define CEditWnd__SetEditable                                      0x775460

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EA420
#define CEverQuest__DropHeldItemOnGround                           0x4F7A00
#define CEverQuest__dsp_chat                                       0x4F08B0
#define CEverQuest__DoTellWindow                                   0x4EEFD0
#define CEverQuest__EnterZone                                      0x501D20
#define CEverQuest__GetBodyTypeDesc                                0x4E7290
#define CEverQuest__GetClassDesc                                   0x4E6AD0
#define CEverQuest__GetClassThreeLetterCode                        0x4E70D0
#define CEverQuest__GetDeityDesc                                   0x4E7900
#define CEverQuest__GetLangDesc                                    0x4E7620
#define CEverQuest__GetRaceDesc                                    0x4E78D0
#define CEverQuest__InterpretCmd                                   0x4F14C0
#define CEverQuest__LeftClickedOnPlayer                            0x503E00
#define CEverQuest__LMouseUp                                       0x507980
#define CEverQuest__RightClickedOnPlayer                           0x508AE0
#define CEverQuest__RMouseUp                                       0x509C60
#define CEverQuest__SetGameState                                   0x4EA8B0
#define CEverQuest__Emote                                          0x4F0AD0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5FAAC0
#define CGaugeWnd__CalcLinesFillRect                               0x5FAB20
#define CGaugeWnd__Draw                                            0x5FAF70

// CGuild
#define CGuild__FindMemberByName                                   0x41BA80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x613CC0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x61F6A0
#define CInvSlotMgr__MoveItem                                      0x61FAB0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x61EB50
#define CInvSlot__SliderComplete                                   0x61CF40
#define CInvSlot__GetItemBase                                      0x61C6A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x620890

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6B8220
#define CItemDisplayWnd__UpdateStrings                             0x621780

// CLabel 
#define CLabel__Draw                                               0x635B80

// CListWnd 
#define CListWnd__AddColumn                                        0x764610
#define CListWnd__AddColumn1                                       0x763CC0
#define CListWnd__AddLine                                          0x763820
#define CListWnd__AddString                                        0x7639C0
#define CListWnd__CalculateFirstVisibleLine                        0x75FB30
#define CListWnd__CalculateVSBRange                                0x761E60
#define CListWnd__ClearAllSel                                      0x75F080
#define CListWnd__CloseAndUpdateEditWindow                         0x762E90
#define CListWnd__Compare                                          0x760530
#define CListWnd__Draw                                             0x761AA0
#define CListWnd__DrawColumnSeparators                             0x761910
#define CListWnd__DrawHeader                                       0x75F310
#define CListWnd__DrawItem                                         0x760F30
#define CListWnd__DrawLine                                         0x761590
#define CListWnd__DrawSeparator                                    0x7619B0
#define CListWnd__EnsureVisible                                    0x75FC90
#define CListWnd__ExtendSel                                        0x760E50
#define CListWnd__GetColumnMinWidth                                0x75ED50
#define CListWnd__GetColumnWidth                                   0x75EC90
#define CListWnd__GetCurSel                                        0x75E510
#define CListWnd__GetHeaderRect                                    0x75E670
#define CListWnd__GetItemAtPoint                                   0x75FF60
#define CListWnd__GetItemAtPoint1                                  0x75FFD0
#define CListWnd__GetItemData                                      0x75E890
#define CListWnd__GetItemHeight                                    0x75F7A0
#define CListWnd__GetItemIcon                                      0x75EA70
#define CListWnd__GetItemRect                                      0x75FD60
#define CListWnd__GetItemText                                      0x75E920
#define CListWnd__GetSelList                                       0x763BA0
#define CListWnd__GetSeparatorRect                                 0x760480
#define CListWnd__RemoveLine                                       0x763B50
#define CListWnd__SetColors                                        0x75E5E0
#define CListWnd__SetColumnJustification                           0x75EEF0
#define CListWnd__SetColumnWidth                                   0x75ED10
#define CListWnd__SetCurSel                                        0x75E550
#define CListWnd__SetItemColor                                     0x762B50
#define CListWnd__SetItemData                                      0x75F120
#define CListWnd__SetItemText                                      0x762930
#define CListWnd__ShiftColumnSeparator                             0x7627A0
#define CListWnd__Sort                                             0x764D50
#define CListWnd__ToggleSel                                        0x75EFF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x64BB80

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x65D820
#define CMerchantWnd__RequestBuyItem                               0x661180
#define CMerchantWnd__RequestSellItem                              0x681370
#define CMerchantWnd__SelectBuySellSlot                            0x65EDC0

// CObfuscator
#define CObfuscator__doit                                          0x6F6630

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x77D760
#define CSidlManager__CreateLabel                                  0x6B10C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5B95C0
#define CSidlScreenWnd__CalculateVSBRange                          0x5B94E0
#define CSidlScreenWnd__ConvertToRes                               0x78F7A0
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
#define CSkillMgr__GetSkillCap                                     0x56C980

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7901A0
#define CSliderWnd__SetValue                                       0x7902A0
#define CSliderWnd__SetNumTicks                                    0x790850

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6B5E20

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x78CE30
#define CStmlWnd__CalculateHSBRange                                0x784520
#define CStmlWnd__CalculateVSBRange                                0x784490
#define CStmlWnd__CanBreakAtCharacter                              0x784690
#define CStmlWnd__FastForwardToEndOfTag                            0x785370
#define CStmlWnd__ForceParseNow                                    0x78D360
#define CStmlWnd__GetNextTagPiece                                  0x785290
#define CStmlWnd__GetSTMLText                                      0x5E3F10
#define CStmlWnd__GetThisChar                                      0x7B4D80
#define CStmlWnd__GetVisiableText                                  0x7867E0
#define CStmlWnd__InitializeWindowVariables                        0x788DB0
#define CStmlWnd__MakeStmlColorTag                                 0x783390
#define CStmlWnd__MakeWndNotificationTag                           0x783430
#define CStmlWnd__SetSTMLText                                      0x788ED0
#define CStmlWnd__StripFirstSTMLLines                              0x78CAE0
#define CStmlWnd__UpdateHistoryString                              0x787070

// CTabWnd 
#define CTabWnd__Draw                                              0x791750
#define CTabWnd__DrawCurrentPage                                   0x791020
#define CTabWnd__DrawTab                                           0x790E00
#define CTabWnd__GetCurrentPage                                    0x7913E0
#define CTabWnd__GetPageClientRect                                 0x790AB0
#define CTabWnd__GetPageFromTabIndex                               0x790D30
#define CTabWnd__GetPageInnerRect                                  0x790B10
#define CTabWnd__GetTabInnerRect                                   0x790CB0
#define CTabWnd__GetTabRect                                        0x790BA0
#define CTabWnd__InsertPage                                        0x7919E0
#define CTabWnd__SetPage                                           0x791420
#define CTabWnd__SetPageRect                                       0x791680
#define CTabWnd__UpdatePage                                        0x791960

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x418070

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x76F580

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7925F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x75D4B0

// CXRect 
#define CXRect__CenterPoint                                        0x5BCCA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x416280
#define CXStr__CXStr1                                              0x794BB0
#define CXStr__CXStr3                                              0x7B9350
#define CXStr__dCXStr                                              0x66A230
#define CXStr__operator_equal                                      0x7B94C0
#define CXStr__operator_equal1                                     0x7B9510
#define CXStr__operator_plus_equal1                                0x7BA5A0

// CXWnd 
#define CXWnd__BringToTop                                          0x765330
#define CXWnd__Center                                              0x76A3B0
#define CXWnd__ClrFocus                                            0x765160
#define CXWnd__DoAllDrawing                                        0x76AD00
#define CXWnd__DrawChildren                                        0x76AE50
#define CXWnd__DrawColoredRect                                     0x765620
#define CXWnd__DrawTooltip                                         0x76A2E0
#define CXWnd__DrawTooltipAtPoint                                  0x769990
#define CXWnd__GetBorderFrame                                      0x765B60
#define CXWnd__GetChildWndAt                                       0x768E00
#define CXWnd__GetClientClipRect                                   0x7658E0
#define CXWnd__GetScreenClipRect                                   0x769ED0
#define CXWnd__GetScreenRect                                       0x765C80
#define CXWnd__GetTooltipRect                                      0x765730
#define CXWnd__GetWindowTextA                                      0x5AA850
#define CXWnd__IsActive                                            0x7706B0
#define CXWnd__IsDescendantOf                                      0x765A50
#define CXWnd__IsReallyVisible                                     0x768DE0
#define CXWnd__IsType                                              0x795410
#define CXWnd__Move                                                0x7682F0
#define CXWnd__Move1                                               0x768390
#define CXWnd__ProcessTransition                                   0x7652E0
#define CXWnd__Refade                                              0x765260
#define CXWnd__Resize                                              0x765D50
#define CXWnd__Right                                               0x769DE0
#define CXWnd__SetFocus                                            0x7674F0
#define CXWnd__SetKeyTooltip                                       0x765FA0
#define CXWnd__SetMouseOver                                        0x76A1C0
#define CXWnd__StartFade                                           0x765370
#define CXWnd__GetChildItem                                        0x76A130

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x771C20
#define CXWndManager__DrawWindows                                  0x7718A0
#define CXWndManager__GetKeyboardFlags                             0x770310
#define CXWndManager__HandleKeyboardMsg                            0x770980
#define CXWndManager__RemoveWnd                                    0x7707D0

// CDBStr
#define CDBStr__GetString                                          0x46C220

// EQ_Character 
#define EQ_Character__CastRay                                      0x713500
#define EQ_Character__CastSpell                                    0x430420
#define EQ_Character__Cur_HP                                       0x439250
#define EQ_Character__GetAACastingTimeModifier                     0x4253E0
#define EQ_Character__GetCharInfo2                                 0x712160
#define EQ_Character__GetFocusCastingTimeModifier                  0x420B70
#define EQ_Character__GetFocusRangeModifier                        0x420D40
#define EQ_Character__Max_Endurance                                0x53CB30
#define EQ_Character__Max_HP                                       0x434210
#define EQ_Character__Max_Mana                                     0x53C930
#define EQ_Character__doCombatAbility                              0x53B7B0
#define EQ_Character__UseSkill                                     0x447AE0
#define EQ_Character__GetConLevel                                  0x5364B0
#define EQ_Character__IsExpansionFlag                              0x40D9A0
#define EQ_Character__TotalEffect                                  0x429910

// EQ_Item 
#define EQ_Item__CanDrop                                           0x51B640
#define EQ_Item__CreateItemTagString                               0x7016B0
#define EQ_Item__IsStackable                                       0x6F6CB0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x484FC0
#define EQ_LoadingS__Array                                         0x944468

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x540B10
#define EQ_PC__GetAltAbilityIndex                                  0x7072C0
#define EQ_PC__GetCombatAbility                                    0x707350
#define EQ_PC__GetCombatAbilityTimer                               0x707400
#define EQ_PC__GetItemTimerValue                                   0x53B5D0
#define EQ_PC__HasLoreItem                                         0x710CC0

// EQItemList 
#define EQItemList__EQItemList                                     0x4B3F40
#define EQItemList__add_item                                       0x4B3ED0
#define EQItemList__delete_item                                    0x4B42F0
#define EQItemList__FreeItemList                                   0x4B4220

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46B9F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5455F0
#define EQPlayer__dEQPlayer                                        0x54A040
#define EQPlayer__DoAttack                                         0x55AD10
#define EQPlayer__EQPlayer                                         0x54F870
#define EQPlayer__SetNameSpriteState                               0x547A00
#define EQPlayer__SetNameSpriteTint                                0x545660
#define EQPlayer__IsBodyType_j                                     0x712DC0
#define EQPlayer__IsTargetable                                     0x713080

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x550B40
#define EQPlayerManager__GetSpawnByName                            0x550DD0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x521400
#define KeypressHandler__AttachKeyToEqCommand                      0x521440
#define KeypressHandler__ClearCommandStateArray                    0x521210
#define KeypressHandler__HandleKeyDown                             0x51FC80
#define KeypressHandler__HandleKeyUp                               0x51FF90
#define KeypressHandler__SaveKeymapping                            0x5212E0

// MapViewMap 
#define MapViewMap__Clear                                          0x647220
#define MapViewMap__SaveEx                                         0x647BF0

#define PlayerPointManager__GetAltCurrency                         0x7027D0

// StringTable 
#define StringTable__getString                                     0x6F68B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x53E7F0
