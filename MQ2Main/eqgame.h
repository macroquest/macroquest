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
#define __ExpectedVersionDate                                     "Apr 19 2011"
#define __ExpectedVersionTime                                     "14:33:40"
#define __ActualVersionDate                                        0x8A9EF4
#define __ActualVersionTime                                        0x8A9F00

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x528180
#define __MemChecker1                                              0x7BB800
#define __MemChecker2                                              0x5A0920
#define __MemChecker3                                              0x5A0870
#define __MemChecker4                                              0x7DD510
#define __EncryptPad0                                              0x94BB48
#define __EncryptPad1                                              0x957D30
#define __EncryptPad2                                              0x94E8E0
#define __EncryptPad3                                              0x94E4E0
#define __EncryptPad4                                              0x9597D8
#define __AC1                                                      0x6BBC10
#define __AC2                                                      0x4E9D65
#define __AC3                                                      0x4FC568
#define __AC4                                                      0x501DB4
#define __AC5                                                      0x50E04C
#define __AC6                                                      0x5117AE
#define __AC7                                                      0x509CAB
#define __AC1_Data                                                 0x8913CD
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
#define __do_loot                                                  0x4BE6E0
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
#define __CastRay                                                  0x4D29A0
#define __ConvertItemTags                                          0x4C3E80
#define __ExecuteCmd                                               0x4AFCE0
#define __get_melee_range                                          0x4B5CB0
#define __GetGaugeValueFromEQ                                      0x6BAA90
#define __GetLabelFromEQ                                           0x6BBBB0
#define __GetXTargetType                                           0x730E80
#define __LoadFrontEnd                                             0x59F840
#define __NewUIINI                                                 0x6BA650
#define __ProcessGameEvents                                        0x50A420
#define CrashDetected                                              0x59F640
#define DrawNetStatus                                              0x5346E0
#define Util__FastTime                                             0x7BC000
#define Expansion_HoT                                              0xB3B3A8

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483CB0
#define AltAdvManager__IsAbilityReady                              0x483D30
#define AltAdvManager__GetAltAbility                               0x483FB0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x439540

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5BD4A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C74D0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x781EB0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5DF420
#define CChatManager__InitContextMenu                              0x5DFBF0

// CChatService
#define CChatService__GetNumberOfFriends                           0x725A20
#define CChatService__GetFriendName                                0x725A30

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5E3F20
#define CChatWindow__Clear                                         0x5E4880
#define CChatWindow__WndNotification                               0x5E4A70

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x76BA70
#define CComboWnd__Draw                                            0x76BC40
#define CComboWnd__GetCurChoice                                    0x76B930
#define CComboWnd__GetListRect                                     0x76BF30
#define CComboWnd__GetTextRect                                     0x76BAA0
#define CComboWnd__InsertChoice                                    0x76BFA0
#define CComboWnd__SetColors                                       0x76B8C0
#define CComboWnd__SetChoice                                       0x76B8F0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5EDCC0
#define CContainerWnd__vftable                                     0x8B1738

// CDisplay 
#define CDisplay__CleanGameUI                                      0x477A80
#define CDisplay__GetClickedActor                                  0x470AA0
#define CDisplay__GetUserDefinedColor                              0x46F480
#define CDisplay__GetWorldFilePath                                 0x46E930
#define CDisplay__is3dON                                           0x46DA60
#define CDisplay__ReloadUI                                         0x480B10
#define CDisplay__WriteTextHD2                                     0x4737F0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B7480
#define CEditBaseWnd__SetSel                                       0x78F730

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x774E30
#define CEditWnd__GetCharIndexPt                                   0x775DF0
#define CEditWnd__GetDisplayString                                 0x774FC0
#define CEditWnd__GetHorzOffset                                    0x775250
#define CEditWnd__GetLineForPrintableChar                          0x7758A0
#define CEditWnd__GetSelStartPt                                    0x776040
#define CEditWnd__GetSTMLSafeText                                  0x7753F0
#define CEditWnd__PointFromPrintableChar                           0x7759B0
#define CEditWnd__SelectableCharFromPoint                          0x775B30
#define CEditWnd__SetEditable                                      0x7753C0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EA490
#define CEverQuest__DropHeldItemOnGround                           0x4F7A20
#define CEverQuest__dsp_chat                                       0x4F08D0
#define CEverQuest__DoTellWindow                                   0x4EF040
#define CEverQuest__EnterZone                                      0x501D40
#define CEverQuest__GetBodyTypeDesc                                0x4E7300
#define CEverQuest__GetClassDesc                                   0x4E6B40
#define CEverQuest__GetClassThreeLetterCode                        0x4E7140
#define CEverQuest__GetDeityDesc                                   0x4E7970
#define CEverQuest__GetLangDesc                                    0x4E7690
#define CEverQuest__GetRaceDesc                                    0x4E7940
#define CEverQuest__InterpretCmd                                   0x4F14E0
#define CEverQuest__LeftClickedOnPlayer                            0x503E20
#define CEverQuest__LMouseUp                                       0x507990
#define CEverQuest__RightClickedOnPlayer                           0x508AF0
#define CEverQuest__RMouseUp                                       0x509C70
#define CEverQuest__SetGameState                                   0x4EA920
#define CEverQuest__Emote                                          0x4F0AF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5FAAD0
#define CGaugeWnd__CalcLinesFillRect                               0x5FAB30
#define CGaugeWnd__Draw                                            0x5FAF80

// CGuild
#define CGuild__FindMemberByName                                   0x41B980

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x613CD0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x61F6B0
#define CInvSlotMgr__MoveItem                                      0x61FAC0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x61EB60
#define CInvSlot__SliderComplete                                   0x61CF50
#define CInvSlot__GetItemBase                                      0x61C6B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x6208A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6B8360
#define CItemDisplayWnd__UpdateStrings                             0x621790

// CLabel 
#define CLabel__Draw                                               0x635B90

// CListWnd 
#define CListWnd__AddColumn                                        0x764570
#define CListWnd__AddColumn1                                       0x763C20
#define CListWnd__AddLine                                          0x763780
#define CListWnd__AddString                                        0x763920
#define CListWnd__CalculateFirstVisibleLine                        0x75FA90
#define CListWnd__CalculateVSBRange                                0x761DC0
#define CListWnd__ClearAllSel                                      0x75EFE0
#define CListWnd__CloseAndUpdateEditWindow                         0x762DF0
#define CListWnd__Compare                                          0x760490
#define CListWnd__Draw                                             0x761A00
#define CListWnd__DrawColumnSeparators                             0x761870
#define CListWnd__DrawHeader                                       0x75F270
#define CListWnd__DrawItem                                         0x760E90
#define CListWnd__DrawLine                                         0x7614F0
#define CListWnd__DrawSeparator                                    0x761910
#define CListWnd__EnsureVisible                                    0x75FBF0
#define CListWnd__ExtendSel                                        0x760DB0
#define CListWnd__GetColumnMinWidth                                0x75ECB0
#define CListWnd__GetColumnWidth                                   0x75EBF0
#define CListWnd__GetCurSel                                        0x75E420
#define CListWnd__GetHeaderRect                                    0x75E5A0
#define CListWnd__GetItemAtPoint                                   0x75FEC0
#define CListWnd__GetItemAtPoint1                                  0x75FF30
#define CListWnd__GetItemData                                      0x75E7F0
#define CListWnd__GetItemHeight                                    0x75F700
#define CListWnd__GetItemIcon                                      0x75E9D0
#define CListWnd__GetItemRect                                      0x75FCC0
#define CListWnd__GetItemText                                      0x75E880
#define CListWnd__GetSelList                                       0x763B00
#define CListWnd__GetSeparatorRect                                 0x7603E0
#define CListWnd__RemoveLine                                       0x763AB0
#define CListWnd__SetColors                                        0x75E510
#define CListWnd__SetColumnJustification                           0x75EE50
#define CListWnd__SetColumnWidth                                   0x75EC70
#define CListWnd__SetCurSel                                        0x75E460
#define CListWnd__SetItemColor                                     0x762AB0
#define CListWnd__SetItemData                                      0x75F080
#define CListWnd__SetItemText                                      0x762890
#define CListWnd__ShiftColumnSeparator                             0x762700
#define CListWnd__Sort                                             0x764CB0
#define CListWnd__ToggleSel                                        0x75EF50

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x64BB90

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x65D820
#define CMerchantWnd__RequestBuyItem                               0x661180
#define CMerchantWnd__RequestSellItem                              0x681340
#define CMerchantWnd__SelectBuySellSlot                            0x65EDC0

// CObfuscator
#define CObfuscator__doit                                          0x6F66D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x77D670
#define CSidlManager__CreateLabel                                  0x6B1200

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5B9620
#define CSidlScreenWnd__CalculateVSBRange                          0x5B9540
#define CSidlScreenWnd__ConvertToRes                               0x78F610
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x76E020
#define CSidlScreenWnd__CSidlScreenWnd1                            0x76F0B0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x76F160
#define CSidlScreenWnd__dCSidlScreenWnd                            0x76E8D0
#define CSidlScreenWnd__DrawSidlPiece                              0x76DAF0
#define CSidlScreenWnd__EnableIniStorage                           0x76D2B0
#define CSidlScreenWnd__GetSidlPiece                               0x76DD00
#define CSidlScreenWnd__Init1                                      0x76EF10
#define CSidlScreenWnd__LoadIniInfo                                0x76E0D0
#define CSidlScreenWnd__LoadIniListWnd                             0x76D400
#define CSidlScreenWnd__LoadSidlScreen                             0x76EB20
#define CSidlScreenWnd__StoreIniInfo                               0x76CEB0
#define CSidlScreenWnd__StoreIniVis                                0x76D240
#define CSidlScreenWnd__WndNotification                            0x76ED00
#define CSidlScreenWnd__GetChildItem                               0x76D310

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x56C900

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x790010
#define CSliderWnd__SetValue                                       0x790110
#define CSliderWnd__SetNumTicks                                    0x7906C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6B5F60

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x78CC80
#define CStmlWnd__CalculateHSBRange                                0x7843B0
#define CStmlWnd__CalculateVSBRange                                0x784320
#define CStmlWnd__CanBreakAtCharacter                              0x784510
#define CStmlWnd__FastForwardToEndOfTag                            0x7851E0
#define CStmlWnd__ForceParseNow                                    0x78D1B0
#define CStmlWnd__GetNextTagPiece                                  0x785100
#define CStmlWnd__GetSTMLText                                      0x5E3EC0
#define CStmlWnd__GetThisChar                                      0x7B4C40
#define CStmlWnd__GetVisiableText                                  0x786630
#define CStmlWnd__InitializeWindowVariables                        0x788C00
#define CStmlWnd__MakeStmlColorTag                                 0x783240
#define CStmlWnd__MakeWndNotificationTag                           0x7832E0
#define CStmlWnd__SetSTMLText                                      0x788D20
#define CStmlWnd__StripFirstSTMLLines                              0x78C930
#define CStmlWnd__UpdateHistoryString                              0x786EC0

// CTabWnd 
#define CTabWnd__Draw                                              0x7915C0
#define CTabWnd__DrawCurrentPage                                   0x790E90
#define CTabWnd__DrawTab                                           0x790C70
#define CTabWnd__GetCurrentPage                                    0x791250
#define CTabWnd__GetPageClientRect                                 0x790920
#define CTabWnd__GetPageFromTabIndex                               0x790BA0
#define CTabWnd__GetPageInnerRect                                  0x790980
#define CTabWnd__GetTabInnerRect                                   0x790B20
#define CTabWnd__GetTabRect                                        0x790A10
#define CTabWnd__InsertPage                                        0x791850
#define CTabWnd__SetPage                                           0x791290
#define CTabWnd__SetPageRect                                       0x7914F0
#define CTabWnd__UpdatePage                                        0x7917D0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417F40

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x76F4E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x792460

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x75D380

// CXRect 
#define CXRect__CenterPoint                                        0x5BCD00

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x416150
#define CXStr__CXStr1                                              0x794A20
#define CXStr__CXStr3                                              0x7B9210
#define CXStr__dCXStr                                              0x471B70
#define CXStr__operator_equal                                      0x7B9380
#define CXStr__operator_equal1                                     0x7B93D0
#define CXStr__operator_plus_equal1                                0x7BA460

// CXWnd 
#define CXWnd__BringToTop                                          0x765290
#define CXWnd__Center                                              0x76A310
#define CXWnd__ClrFocus                                            0x7650C0
#define CXWnd__DoAllDrawing                                        0x76AC60
#define CXWnd__DrawChildren                                        0x76ADB0
#define CXWnd__DrawColoredRect                                     0x765580
#define CXWnd__DrawTooltip                                         0x76A240
#define CXWnd__DrawTooltipAtPoint                                  0x769940
#define CXWnd__GetBorderFrame                                      0x765AC0
#define CXWnd__GetChildWndAt                                       0x768DB0
#define CXWnd__GetClientClipRect                                   0x765840
#define CXWnd__GetScreenClipRect                                   0x769E80
#define CXWnd__GetScreenRect                                       0x765BE0
#define CXWnd__GetTooltipRect                                      0x765690
#define CXWnd__GetWindowTextA                                      0x5AA8F0
#define CXWnd__IsActive                                            0x770610
#define CXWnd__IsDescendantOf                                      0x7659B0
#define CXWnd__IsReallyVisible                                     0x768D90
#define CXWnd__IsType                                              0x795290
#define CXWnd__Move                                                0x7682A0
#define CXWnd__Move1                                               0x768340
#define CXWnd__ProcessTransition                                   0x765240
#define CXWnd__Refade                                              0x7651C0
#define CXWnd__Resize                                              0x765CB0
#define CXWnd__Right                                               0x769D90
#define CXWnd__SetFocus                                            0x7674A0
#define CXWnd__SetKeyTooltip                                       0x765F00
#define CXWnd__SetMouseOver                                        0x76A120
#define CXWnd__StartFade                                           0x7652D0
#define CXWnd__GetChildItem                                        0x76A090

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x771B80
#define CXWndManager__DrawWindows                                  0x771800
#define CXWndManager__GetKeyboardFlags                             0x770270
#define CXWndManager__HandleKeyboardMsg                            0x7708E0
#define CXWndManager__RemoveWnd                                    0x770730

// CDBStr
#define CDBStr__GetString                                          0x46C2C0

// EQ_Character 
#define EQ_Character__CastRay                                      0x7134D0
#define EQ_Character__CastSpell                                    0x4303F0
#define EQ_Character__Cur_HP                                       0x439200
#define EQ_Character__GetAACastingTimeModifier                     0x425390
#define EQ_Character__GetCharInfo2                                 0x712180
#define EQ_Character__GetFocusCastingTimeModifier                  0x420AF0
#define EQ_Character__GetFocusRangeModifier                        0x420CC0
#define EQ_Character__Max_Endurance                                0x53C950
#define EQ_Character__Max_HP                                       0x4341C0
#define EQ_Character__Max_Mana                                     0x53C750
#define EQ_Character__doCombatAbility                              0x53B5D0
#define EQ_Character__UseSkill                                     0x447A90
#define EQ_Character__GetConLevel                                  0x536310
#define EQ_Character__IsExpansionFlag                              0x40D8A0
#define EQ_Character__TotalEffect                                  0x4298E0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x51B570
#define EQ_Item__CreateItemTagString                               0x701750
#define EQ_Item__IsStackable                                       0x6F6D50

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x485060
#define EQ_LoadingS__Array                                         0x944468

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x540930
#define EQ_PC__GetAltAbilityIndex                                  0x7072E0
#define EQ_PC__GetCombatAbility                                    0x707370
#define EQ_PC__GetCombatAbilityTimer                               0x707420
#define EQ_PC__GetItemTimerValue                                   0x53B3F0
#define EQ_PC__HasLoreItem                                         0x710CE0

// EQItemList 
#define EQItemList__EQItemList                                     0x4B3FA0
#define EQItemList__add_item                                       0x4B3F30
#define EQItemList__delete_item                                    0x4B4350
#define EQItemList__FreeItemList                                   0x4B4280

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46BAB0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x545410
#define EQPlayer__dEQPlayer                                        0x549E70
#define EQPlayer__DoAttack                                         0x55AB30
#define EQPlayer__EQPlayer                                         0x54F6A0
#define EQPlayer__SetNameSpriteState                               0x547820
#define EQPlayer__SetNameSpriteTint                                0x545480
#define EQPlayer__IsBodyType_j                                     0x712D90
#define EQPlayer__IsTargetable                                     0x713050

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x550970
#define EQPlayerManager__GetSpawnByName                            0x550C60

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x521390
#define KeypressHandler__AttachKeyToEqCommand                      0x5213D0
#define KeypressHandler__ClearCommandStateArray                    0x5211A0
#define KeypressHandler__HandleKeyDown                             0x51FC10
#define KeypressHandler__HandleKeyUp                               0x51FF20
#define KeypressHandler__SaveKeymapping                            0x521270

// MapViewMap 
#define MapViewMap__Clear                                          0x647230
#define MapViewMap__SaveEx                                         0x647C00

#define PlayerPointManager__GetAltCurrency                         0x702870

// StringTable 
#define StringTable__getString                                     0x6F6950

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x53E610
