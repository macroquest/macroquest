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
#define __ExpectedVersionDate                                     "Apr 12 2011"
#define __ExpectedVersionTime                                     "11:06:38"
#define __ActualVersionDate                                        0x8A9EF4
#define __ActualVersionTime                                        0x8A9F00

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x527EA0
#define __MemChecker1                                              0x7BB8E0
#define __MemChecker2                                              0x5A0760
#define __MemChecker3                                              0x5A06B0
#define __MemChecker4                                              0x7DD540
#define __EncryptPad0                                              0x94BB48
#define __EncryptPad1                                              0x957D30
#define __EncryptPad2                                              0x94E8E0
#define __EncryptPad3                                              0x94E4E0
#define __EncryptPad4                                              0x9597D8
#define __AC1                                                      0x6BB780
#define __AC2                                                      0x4E99F5
#define __AC3                                                      0x4FC238
#define __AC4                                                      0x501A84
#define __AC5                                                      0x50DD1C
#define __AC6                                                      0x51147E
#define __AC7                                                      0x50997B
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
#define __do_loot                                                  0x4BE440
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
#define __CastRay                                                  0x4D26B0
#define __ConvertItemTags                                          0x4C3BE0
#define __ExecuteCmd                                               0x4AFA40
#define __get_melee_range                                          0x4B5A10
#define __GetGaugeValueFromEQ                                      0x6BA600
#define __GetLabelFromEQ                                           0x6BB720
#define __GetXTargetType                                           0x730C80
#define __LoadFrontEnd                                             0x59F690
#define __NewUIINI                                                 0x6BA1C0
#define __ProcessGameEvents                                        0x50A0F0
#define CrashDetected                                              0x59F490
#define DrawNetStatus                                              0x534380
#define Util__FastTime                                             0x7BC0E0
#define Expansion_HoT                                              0xB3B3A8

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x4838E0
#define AltAdvManager__IsAbilityReady                              0x4839F0
#define AltAdvManager__GetAltAbility                               0x483C30

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x439470

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5BD2D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C75F0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x781F90

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5DF070
#define CChatManager__InitContextMenu                              0x5DF840

// CChatService
#define CChatService__GetNumberOfFriends                           0x725870
#define CChatService__GetFriendName                                0x725880

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5E3B70
#define CChatWindow__Clear                                         0x5E44D0
#define CChatWindow__WndNotification                               0x5E46C0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x76BA00
#define CComboWnd__Draw                                            0x76BBD0
#define CComboWnd__GetCurChoice                                    0x76B8C0
#define CComboWnd__GetListRect                                     0x76BEC0
#define CComboWnd__GetTextRect                                     0x76BA30
#define CComboWnd__InsertChoice                                    0x76BF30
#define CComboWnd__SetColors                                       0x76B850
#define CComboWnd__SetChoice                                       0x76B880

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5ED9D0
#define CContainerWnd__vftable                                     0x8B1738

// CDisplay 
#define CDisplay__CleanGameUI                                      0x4776F0
#define CDisplay__GetClickedActor                                  0x470750
#define CDisplay__GetUserDefinedColor                              0x46F130
#define CDisplay__GetWorldFilePath                                 0x46E5E0
#define CDisplay__is3dON                                           0x46D710
#define CDisplay__ReloadUI                                         0x480740
#define CDisplay__WriteTextHD2                                     0x473460

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B72C0
#define CEditBaseWnd__SetSel                                       0x78F820

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x774DF0
#define CEditWnd__GetCharIndexPt                                   0x775DB0
#define CEditWnd__GetDisplayString                                 0x774F80
#define CEditWnd__GetHorzOffset                                    0x775210
#define CEditWnd__GetLineForPrintableChar                          0x775860
#define CEditWnd__GetSelStartPt                                    0x776000
#define CEditWnd__GetSTMLSafeText                                  0x7753B0
#define CEditWnd__PointFromPrintableChar                           0x775970
#define CEditWnd__SelectableCharFromPoint                          0x775AF0
#define CEditWnd__SetEditable                                      0x775380

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EA120
#define CEverQuest__DropHeldItemOnGround                           0x4F76F0
#define CEverQuest__dsp_chat                                       0x4F05A0
#define CEverQuest__DoTellWindow                                   0x4EECC0
#define CEverQuest__EnterZone                                      0x501A10
#define CEverQuest__GetBodyTypeDesc                                0x4E6F90
#define CEverQuest__GetClassDesc                                   0x4E67D0
#define CEverQuest__GetClassThreeLetterCode                        0x4E6DD0
#define CEverQuest__GetDeityDesc                                   0x4E7600
#define CEverQuest__GetLangDesc                                    0x4E7320
#define CEverQuest__GetRaceDesc                                    0x4E75D0
#define CEverQuest__InterpretCmd                                   0x4F11B0
#define CEverQuest__LeftClickedOnPlayer                            0x503AF0
#define CEverQuest__LMouseUp                                       0x507660
#define CEverQuest__RightClickedOnPlayer                           0x5087C0
#define CEverQuest__RMouseUp                                       0x509940
#define CEverQuest__SetGameState                                   0x4EA5B0
#define CEverQuest__Emote                                          0x4F07C0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5FA7D0
#define CGaugeWnd__CalcLinesFillRect                               0x5FA830
#define CGaugeWnd__Draw                                            0x5FAC80

// CGuild
#define CGuild__FindMemberByName                                   0x41B9B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x6139B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x61F3D0
#define CInvSlotMgr__MoveItem                                      0x61F7E0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x61E880
#define CInvSlot__SliderComplete                                   0x61CC70
#define CInvSlot__GetItemBase                                      0x61C3D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x6205C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6B7ED0
#define CItemDisplayWnd__UpdateStrings                             0x6214B0

// CLabel 
#define CLabel__Draw                                               0x6358C0

// CListWnd 
#define CListWnd__AddColumn                                        0x764500
#define CListWnd__AddColumn1                                       0x763B60
#define CListWnd__AddLine                                          0x763710
#define CListWnd__AddString                                        0x7638B0
#define CListWnd__CalculateFirstVisibleLine                        0x75FA20
#define CListWnd__CalculateVSBRange                                0x761D50
#define CListWnd__ClearAllSel                                      0x75EF70
#define CListWnd__CloseAndUpdateEditWindow                         0x762D80
#define CListWnd__Compare                                          0x760420
#define CListWnd__Draw                                             0x761990
#define CListWnd__DrawColumnSeparators                             0x761800
#define CListWnd__DrawHeader                                       0x75F200
#define CListWnd__DrawItem                                         0x760E20
#define CListWnd__DrawLine                                         0x761480
#define CListWnd__DrawSeparator                                    0x7618A0
#define CListWnd__EnsureVisible                                    0x75FB80
#define CListWnd__ExtendSel                                        0x760D40
#define CListWnd__GetColumnMinWidth                                0x75EC40
#define CListWnd__GetColumnWidth                                   0x75EB80
#define CListWnd__GetCurSel                                        0x75E400
#define CListWnd__GetHeaderRect                                    0x75E560
#define CListWnd__GetItemAtPoint                                   0x75FE50
#define CListWnd__GetItemAtPoint1                                  0x75FEC0
#define CListWnd__GetItemData                                      0x75E780
#define CListWnd__GetItemHeight                                    0x75F690
#define CListWnd__GetItemIcon                                      0x75E960
#define CListWnd__GetItemRect                                      0x75FC50
#define CListWnd__GetItemText                                      0x75E810
#define CListWnd__GetSelList                                       0x763A40
#define CListWnd__GetSeparatorRect                                 0x760370
#define CListWnd__RemoveLine                                       0x7644B0
#define CListWnd__SetColors                                        0x75E4D0
#define CListWnd__SetColumnJustification                           0x75EDE0
#define CListWnd__SetColumnWidth                                   0x75EC00
#define CListWnd__SetCurSel                                        0x75E440
#define CListWnd__SetItemColor                                     0x762A40
#define CListWnd__SetItemData                                      0x75F010
#define CListWnd__SetItemText                                      0x762820
#define CListWnd__ShiftColumnSeparator                             0x762690
#define CListWnd__Sort                                             0x764C40
#define CListWnd__ToggleSel                                        0x75EEE0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x64B8F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x65D590
#define CMerchantWnd__RequestBuyItem                               0x660EF0
#define CMerchantWnd__RequestSellItem                              0x6810E0
#define CMerchantWnd__SelectBuySellSlot                            0x65EB30

// CObfuscator
#define CObfuscator__doit                                          0x6F6510

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x77D690
#define CSidlManager__CreateLabel                                  0x6B0D60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5B9460
#define CSidlScreenWnd__CalculateVSBRange                          0x5B9380
#define CSidlScreenWnd__ConvertToRes                               0x78F700
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x76DFB0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x76F040
#define CSidlScreenWnd__CSidlScreenWnd2                            0x76F0F0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x76E860
#define CSidlScreenWnd__DrawSidlPiece                              0x76DA80
#define CSidlScreenWnd__EnableIniStorage                           0x76D240
#define CSidlScreenWnd__GetSidlPiece                               0x76DC90
#define CSidlScreenWnd__Init1                                      0x76EEA0
#define CSidlScreenWnd__LoadIniInfo                                0x76E060
#define CSidlScreenWnd__LoadIniListWnd                             0x76D390
#define CSidlScreenWnd__LoadSidlScreen                             0x76EAB0
#define CSidlScreenWnd__StoreIniInfo                               0x76CE40
#define CSidlScreenWnd__StoreIniVis                                0x76D1D0
#define CSidlScreenWnd__WndNotification                            0x76EC90
#define CSidlScreenWnd__GetChildItem                               0x76D2A0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x56C4C0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7900F0
#define CSliderWnd__SetValue                                       0x7901F0
#define CSliderWnd__SetNumTicks                                    0x7907A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6B5AE0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x78CD70
#define CStmlWnd__CalculateHSBRange                                0x784490
#define CStmlWnd__CalculateVSBRange                                0x784400
#define CStmlWnd__CanBreakAtCharacter                              0x784600
#define CStmlWnd__FastForwardToEndOfTag                            0x7852D0
#define CStmlWnd__ForceParseNow                                    0x78D2A0
#define CStmlWnd__GetNextTagPiece                                  0x7851F0
#define CStmlWnd__GetSTMLText                                      0x5E3B10
#define CStmlWnd__GetThisChar                                      0x7B4D20
#define CStmlWnd__GetVisiableText                                  0x786720
#define CStmlWnd__InitializeWindowVariables                        0x788CF0
#define CStmlWnd__MakeStmlColorTag                                 0x783320
#define CStmlWnd__MakeWndNotificationTag                           0x7833C0
#define CStmlWnd__SetSTMLText                                      0x788E10
#define CStmlWnd__StripFirstSTMLLines                              0x78CA20
#define CStmlWnd__UpdateHistoryString                              0x786FB0

// CTabWnd 
#define CTabWnd__Draw                                              0x7916A0
#define CTabWnd__DrawCurrentPage                                   0x790F70
#define CTabWnd__DrawTab                                           0x790D50
#define CTabWnd__GetCurrentPage                                    0x791330
#define CTabWnd__GetPageClientRect                                 0x790A00
#define CTabWnd__GetPageFromTabIndex                               0x790C80
#define CTabWnd__GetPageInnerRect                                  0x790A60
#define CTabWnd__GetTabInnerRect                                   0x790C00
#define CTabWnd__GetTabRect                                        0x790AF0
#define CTabWnd__InsertPage                                        0x791930
#define CTabWnd__SetPage                                           0x791370
#define CTabWnd__SetPageRect                                       0x7915D0
#define CTabWnd__UpdatePage                                        0x7918B0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417F60

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x76F470

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x792530

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x75D2C0

// CXRect 
#define CXRect__CenterPoint                                        0x5BCB30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x416090
#define CXStr__CXStr1                                              0x7CC0B0
#define CXStr__CXStr3                                              0x7B92F0
#define CXStr__dCXStr                                              0x401020
#define CXStr__operator_equal                                      0x7B9460
#define CXStr__operator_equal1                                     0x7B94B0
#define CXStr__operator_plus_equal1                                0x7BA540

// CXWnd 
#define CXWnd__BringToTop                                          0x765220
#define CXWnd__Center                                              0x76A2A0
#define CXWnd__ClrFocus                                            0x765050
#define CXWnd__DoAllDrawing                                        0x76ABF0
#define CXWnd__DrawChildren                                        0x76AD40
#define CXWnd__DrawColoredRect                                     0x765510
#define CXWnd__DrawTooltip                                         0x76A1D0
#define CXWnd__DrawTooltipAtPoint                                  0x7698D0
#define CXWnd__GetBorderFrame                                      0x765A50
#define CXWnd__GetChildWndAt                                       0x768D40
#define CXWnd__GetClientClipRect                                   0x7657D0
#define CXWnd__GetScreenClipRect                                   0x769E10
#define CXWnd__GetScreenRect                                       0x765B70
#define CXWnd__GetTooltipRect                                      0x765620
#define CXWnd__GetWindowTextA                                      0x5AA760
#define CXWnd__IsActive                                            0x7705A0
#define CXWnd__IsDescendantOf                                      0x765940
#define CXWnd__IsReallyVisible                                     0x768D20
#define CXWnd__IsType                                              0x7953E0
#define CXWnd__Move                                                0x768230
#define CXWnd__Move1                                               0x7682D0
#define CXWnd__ProcessTransition                                   0x7651D0
#define CXWnd__Refade                                              0x765150
#define CXWnd__Resize                                              0x765C40
#define CXWnd__Right                                               0x769D20
#define CXWnd__SetFocus                                            0x767430
#define CXWnd__SetKeyTooltip                                       0x765E90
#define CXWnd__SetMouseOver                                        0x76A0B0
#define CXWnd__StartFade                                           0x765260
#define CXWnd__GetChildItem                                        0x76A020

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x771B40
#define CXWndManager__DrawWindows                                  0x7717C0
#define CXWndManager__GetKeyboardFlags                             0x770200
#define CXWndManager__HandleKeyboardMsg                            0x770870
#define CXWndManager__RemoveWnd                                    0x7706C0

// CDBStr
#define CDBStr__GetString                                          0x46BF70

// EQ_Character 
#define EQ_Character__CastRay                                      0x713370
#define EQ_Character__CastSpell                                    0x430310
#define EQ_Character__Cur_HP                                       0x439130
#define EQ_Character__GetAACastingTimeModifier                     0x4252D0
#define EQ_Character__GetCharInfo2                                 0x712100
#define EQ_Character__GetFocusCastingTimeModifier                  0x420A60
#define EQ_Character__GetFocusRangeModifier                        0x420C30
#define EQ_Character__Max_Endurance                                0x53C5F0
#define EQ_Character__Max_HP                                       0x4340F0
#define EQ_Character__Max_Mana                                     0x53C3F0
#define EQ_Character__doCombatAbility                              0x53B270
#define EQ_Character__UseSkill                                     0x4479C0
#define EQ_Character__GetConLevel                                  0x535FE0
#define EQ_Character__IsExpansionFlag                              0x40D860
#define EQ_Character__TotalEffect                                  0x429800

// EQ_Item 
#define EQ_Item__CanDrop                                           0x51B2B0
#define EQ_Item__CreateItemTagString                               0x7013C0
#define EQ_Item__IsStackable                                       0x6F6B90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x484CE0
#define EQ_LoadingS__Array                                         0x944468

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x5405D0
#define EQ_PC__GetAltAbilityIndex                                  0x707250
#define EQ_PC__GetCombatAbility                                    0x7072E0
#define EQ_PC__GetCombatAbilityTimer                               0x707390
#define EQ_PC__GetItemTimerValue                                   0x53B090
#define EQ_PC__HasLoreItem                                         0x710C50

// EQItemList 
#define EQItemList__EQItemList                                     0x4B3D00
#define EQItemList__add_item                                       0x4B3C90
#define EQItemList__delete_item                                    0x4B40B0
#define EQItemList__FreeItemList                                   0x4B3FE0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46B760

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5450B0
#define EQPlayer__dEQPlayer                                        0x549B00
#define EQPlayer__DoAttack                                         0x55A7E0
#define EQPlayer__EQPlayer                                         0x54F330
#define EQPlayer__SetNameSpriteState                               0x5474C0
#define EQPlayer__SetNameSpriteTint                                0x545120
#define EQPlayer__IsBodyType_j                                     0x712C30
#define EQPlayer__IsTargetable                                     0x712EF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x550600
#define EQPlayerManager__GetSpawnByName                            0x5508F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x521110
#define KeypressHandler__AttachKeyToEqCommand                      0x521150
#define KeypressHandler__ClearCommandStateArray                    0x520F20
#define KeypressHandler__HandleKeyDown                             0x51F990
#define KeypressHandler__HandleKeyUp                               0x51FCA0
#define KeypressHandler__SaveKeymapping                            0x520FF0

// MapViewMap 
#define MapViewMap__Clear                                          0x646F90
#define MapViewMap__SaveEx                                         0x647960

#define PlayerPointManager__GetAltCurrency                         0x702700

// StringTable 
#define StringTable__getString                                     0x6F6790

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x53E2B0
