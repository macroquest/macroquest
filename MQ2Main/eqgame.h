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
#define __ExpectedVersionDate                                     "Sep 25 2012"
#define __ExpectedVersionTime                                     "07:53:18"
#define __ActualVersionDate                                        0x91D780
#define __ActualVersionTime                                        0x91D78C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x537A40
#define __MemChecker1                                              0x790B20
#define __MemChecker2                                              0x5BF3C0
#define __MemChecker3                                              0x5BF310
#define __MemChecker4                                              0x848070
#define __EncryptPad0                                              0x9F7FF8
#define __EncryptPad1                                              0xA70388
#define __EncryptPad2                                              0xA10D90
#define __EncryptPad3                                              0xA10990
#define __EncryptPad4                                              0xA73BB0
#define __AC1                                                      0x6FFD80
#define __AC2                                                      0x4F3A55
#define __AC3                                                      0x505C58
#define __AC4                                                      0x50B3C4
#define __AC5                                                      0x51729E
#define __AC6                                                      0x51AC5B
#define __AC7                                                      0x512B6B
#define __AC1_Data                                                 0x90258D
// Direct Input
#define DI8__Main                                                  0xCF6F88
#define DI8__Keyboard                                              0xCF6F8C
#define DI8__Mouse                                                 0xCF6F90
#define __AltTimerReady                                            0xBBFAE1
#define __Attack                                                   0xCF2D52
#define __Autofire                                                 0xCF2D53
#define __BindList                                                 0x9DFD18
#define __Clicks                                                   0xC7D024
#define __CommandList                                              0x9E1368
#define __CurrentMapLabel                                          0xE02DC8
#define __CurrentSocial                                            0x9CBEDC
#define __DoAbilityList                                            0xCB3728
#define __do_loot                                                  0x4C7130
#define __DrawHandler                                              0x145FB2C
#define __GroupCount                                               0xC6D9DA
#define __Guilds                                                   0xC6FF70
#define __gWorld                                                   0xC6FE9C
#define __HotkeyPage                                               0xCDC304
#define __HWnd                                                     0xCF6CD8
#define __InChatMode                                               0xC7CF5C
#define __LastTell                                                 0xC7EE30
#define __LMouseHeldTime                                           0xC7D090
#define __Mouse                                                    0xCF6F94
#define __MouseLook                                                0xC7CFF2
#define __MouseEventTime                                           0xCF306C
#define __NetStatusToggle                                          0xC7CFF5
#define __PCNames                                                  0xC7E4B0
#define __RangeAttackReady                                         0xC7E148
#define __RMouseHeldTime                                           0xC7D08C
#define __RunWalkState                                             0xC7CF60
#define __ScreenMode                                               0xBBCE28
#define __ScreenX                                                  0xC7CF10
#define __ScreenY                                                  0xC7CF14
#define __ScreenXMax                                               0xC7CF18
#define __ScreenYMax                                               0xC7CF1C
#define __ServerHost                                               0xC6D91C
#define __ServerName                                               0xCB36E8
#define __ShiftKeyDown                                             0xC7D5E4
#define __ShowNames                                                0xC7E354
#define __Socials                                                  0xCB37E8


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xC79888
#define instEQZoneInfo                                             0xC7D1DC
#define instKeypressHandler                                        0xCF3068
#define pinstActiveBanker                                          0xC6FF44
#define pinstActiveCorpse                                          0xC6FF48
#define pinstActiveGMaster                                         0xC6FF4C
#define pinstActiveMerchant                                        0xC6FF40
#define pinstAltAdvManager                                         0xBBDD70
#define pinstAuraMgr                                               0xA8CFB0
#define pinstBandageTarget                                         0xC6FF2C
#define pinstCamActor                                              0xBBD7E8
#define pinstCDBStr                                                0xBBCE00
#define pinstCDisplay                                              0xC6FF54
#define pinstCEverQuest                                            0xCF7110
#define pinstCharData                                              0xC6FF10
#define pinstCharSpawn                                             0xC6FF38
#define pinstControlledMissile                                     0xC6FF0C
#define pinstControlledPlayer                                      0xC6FF38
#define pinstCSidlManager                                          0x146006C
#define pinstCXWndManager                                          0x1460064
#define instDynamicZone                                            0xC792E0
#define pinstDZMember                                              0xC793F0
#define pinstDZTimerInfo                                           0xC793F4
#define pinstEQItemList                                            0xC6CA50
#define instEQMisc                                                 0xBBCD68
#define pinstEQSoundManager                                        0xBBDDE0
#define instExpeditionLeader                                       0xC7932A
#define instExpeditionName                                         0xC7936A
#define pinstGroup                                                 0xC6D9D6
#define pinstImeManager                                            0x1460070
#define pinstLocalPlayer                                           0xC6FF24
#define pinstMercenaryData                                         0xCF34E8
#define pinstModelPlayer                                           0xC6FF50
#define pinstPCData                                                0xC6FF10
#define pinstSkillMgr                                              0xCF3B18
#define pinstSpawnManager                                          0xCF3788
#define pinstSpellManager                                          0xCF3B90
#define pinstSpellSets                                             0xCEC05C
#define pinstStringTable                                           0xC6FEB8
#define pinstSwitchManager                                         0xC6D5E8
#define pinstTarget                                                0xC6FF3C
#define pinstTargetObject                                          0xC6FF14
#define pinstTargetSwitch                                          0xC6FF18
#define pinstTaskMember                                            0xBBCD30
#define pinstTrackTarget                                           0xC6FF30
#define pinstTradeTarget                                           0xC6FF20
#define instTributeActive                                          0xBBCD8D
#define pinstViewActor                                             0xBBD7E4
#define pinstWorldData                                             0xC6FEF4


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0xA83FF0
#define pinstCAudioTriggersWindow                                  0xA83F88
#define pinstCCharacterSelect                                      0xBBD698
#define pinstCFacePick                                             0xBBD648
#define pinstCNoteWnd                                              0xBBD650
#define pinstCBookWnd                                              0xBBD658
#define pinstCPetInfoWnd                                           0xBBD65C
#define pinstCTrainWnd                                             0xBBD660
#define pinstCSkillsWnd                                            0xBBD664
#define pinstCSkillsSelectWnd                                      0xBBD668
#define pinstCCombatSkillSelectWnd                                 0xBBD66C
#define pinstCFriendsWnd                                           0xBBD670
#define pinstCAuraWnd                                              0xBBD674
#define pinstCRespawnWnd                                           0xBBD678
#define pinstCBandolierWnd                                         0xBBD67C
#define pinstCPotionBeltWnd                                        0xBBD680
#define pinstCAAWnd                                                0xBBD684
#define pinstCGroupSearchFiltersWnd                                0xBBD688
#define pinstCLoadskinWnd                                          0xBBD68C
#define pinstCAlarmWnd                                             0xBBD690
#define pinstCMusicPlayerWnd                                       0xBBD694
#define pinstCMailWnd                                              0xBBD69C
#define pinstCMailCompositionWnd                                   0xBBD6A0
#define pinstCMailAddressBookWnd                                   0xBBD6A4
#define pinstCRaidWnd                                              0xBBD6AC
#define pinstCRaidOptionsWnd                                       0xBBD6B0
#define pinstCBreathWnd                                            0xBBD6B4
#define pinstCMapViewWnd                                           0xBBD6B8
#define pinstCMapToolbarWnd                                        0xBBD6BC
#define pinstCEditLabelWnd                                         0xBBD6C0
#define pinstCTargetWnd                                            0xBBD6C4
#define pinstCColorPickerWnd                                       0xBBD6C8
#define pinstCPlayerWnd                                            0xBBD6CC
#define pinstCOptionsWnd                                           0xBBD6D0
#define pinstCBuffWindowNORMAL                                     0xBBD6D4
#define pinstCBuffWindowSHORT                                      0xBBD6D8
#define pinstCharacterCreation                                     0xBBD6DC
#define pinstCCursorAttachment                                     0xBBD6E0
#define pinstCCastingWnd                                           0xBBD6E4
#define pinstCCastSpellWnd                                         0xBBD6E8
#define pinstCSpellBookWnd                                         0xBBD6EC
#define pinstCInventoryWnd                                         0xBBD6F0
#define pinstCBankWnd                                              0xBBD6F4
#define pinstCQuantityWnd                                          0xBBD6F8
#define pinstCLootWnd                                              0xBBD6FC
#define pinstCActionsWnd                                           0xBBD700
#define pinstCCombatAbilityWnd                                     0xBBD704
#define pinstCMerchantWnd                                          0xBBD708
#define pinstCTradeWnd                                             0xBBD70C
#define pinstCSelectorWnd                                          0xBBD710
#define pinstCBazaarWnd                                            0xBBD714
#define pinstCBazaarSearchWnd                                      0xBBD718
#define pinstCGiveWnd                                              0xBBD734
#define pinstCTrackingWnd                                          0xBBD73C
#define pinstCInspectWnd                                           0xBBD740
#define pinstCSocialEditWnd                                        0xBBD744
#define pinstCFeedbackWnd                                          0xBBD748
#define pinstCBugReportWnd                                         0xBBD74C
#define pinstCVideoModesWnd                                        0xBBD750
#define pinstCTextEntryWnd                                         0xBBD758
#define pinstCFileSelectionWnd                                     0xBBD75C
#define pinstCCompassWnd                                           0xBBD760
#define pinstCPlayerNotesWnd                                       0xBBD764
#define pinstCGemsGameWnd                                          0xBBD768
#define pinstCTimeLeftWnd                                          0xBBD76C
#define pinstCPetitionQWnd                                         0xBBD780
#define pinstCSoulmarkWnd                                          0xBBD784
#define pinstCStoryWnd                                             0xBBD788
#define pinstCJournalTextWnd                                       0xBBD78C
#define pinstCJournalCatWnd                                        0xBBD790
#define pinstCBodyTintWnd                                          0xBBD794
#define pinstCServerListWnd                                        0xBBD798
#define pinstCAvaZoneWnd                                           0xBBD7A0
#define pinstCBlockedBuffWnd                                       0xBBD7A4
#define pinstCBlockedPetBuffWnd                                    0xBBD7A8
#define pinstCInvSlotMgr                                           0xBBD7DC
#define pinstCContainerMgr                                         0xBBD7E0
#define pinstCAdventureLeaderboardWnd                              0xDFF900
#define pinstCAdventureRequestWnd                                  0xDFF8C8
#define pinstCAltStorageWnd                                        0xDFFA08
#define pinstCAdventureStatsWnd                                    0xDFF900
#define pinstCBarterMerchantWnd                                    0xDFFE60
#define pinstCBarterSearchWnd                                      0xDFFE98
#define pinstCBarterWnd                                            0xDFFED0
#define pinstCChatManager                                          0xE002C8
#define pinstCDynamicZoneWnd                                       0xE004B8
#define pinstCEQMainWnd                                            0xE00578
#define pinstCFellowshipWnd                                        0xE004AC
#define pinstCFindLocationWnd                                      0xE006A8
#define pinstCGroupSearchWnd                                       0xE00808
#define pinstCGroupWnd                                             0xE00840
#define pinstCGuildBankWnd                                         0xE00878
#define pinstCGuildMgmtWnd                                         0xE028E8
#define pinstCGuildTributeMasterWnd                                0xE04540
#define pinstCHotButtonWnd                                         0xE0293C
#define pinstCHotButtonWnd1                                        0xE0293C
#define pinstCHotButtonWnd2                                        0xE02940
#define pinstCHotButtonWnd3                                        0xE02944
#define pinstCHotButtonWnd4                                        0xE02984
#define pinstCItemDisplayManager                                   0xE02AB8
#define pinstCItemExpTransferWnd                                   0xE02AF4
#define pinstCLeadershipWnd                                        0xE02C20
#define pinstCLFGuildWnd                                           0xE02C58
#define pinstCMIZoneSelectWnd                                      0xE02EF8
#define pinstCAdventureMerchantWnd                                 0xE031A8
#define pinstCConfirmationDialog                                   0xE031E0
#define pinstCPopupWndManager                                      0xE031E0
#define pinstCProgressionSelectionWnd                              0xE03248
#define pinstCPvPLeaderboardWnd                                    0xE03280
#define pinstCPvPStatsWnd                                          0xE032B8
#define pinstCSystemInfoDialogBox                                  0xE035A0
#define pinstCTargetOfTargetWnd                                    0xE041F0
#define pinstCTaskSelectWnd                                        0xE0345C
#define pinstCTaskTemplateSelectWnd                                0xE04290
#define pinstCTaskWnd                                              0xE042C8
#define pinstCTipWndOFDAY                                          0xE043C0
#define pinstCTipWndCONTEXT                                        0xE043C4
#define pinstCTitleWnd                                             0xE043F8
#define pinstCTradeskillWnd                                        0xE04470
#define pinstCTributeBenefitWnd                                    0xE04508
#define pinstCTributeMasterWnd                                     0xE04540
#define pinstCContextMenuManager                                   0x14600C8
#define pinstCVoiceMacroWnd                                        0xCF3ED8
#define pinstCHtmlWnd                                              0xCF3F50


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4DB870
#define __ConvertItemTags                                          0x4CC850
#define __ExecuteCmd                                               0x4B8350
#define __EQGetTime                                                0x791F50
#define __get_melee_range                                          0x4BE610
#define __GetGaugeValueFromEQ                                      0x6FEB30
#define __GetLabelFromEQ                                           0x6FFD20
#define __GetXTargetType                                           0x77EA60
#define __LoadFrontEnd                                             0x5BE330
#define __NewUIINI                                                 0x6FE6E0
#define __ProcessGameEvents                                        0x513350
#define CrashDetected                                              0x5C0D40
#define DrawNetStatus                                              0x545420
#define Util__FastTime                                             0x7913B0
#define Expansion_HoT                                              0xC7E2B4
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x48A640
#define AltAdvManager__IsAbilityReady                              0x48A6F0
#define AltAdvManager__GetAltAbility                               0x48A910

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x43D420

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5E5860

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5EF6A0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x525940

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x608D70
#define CChatManager__InitContextMenu                              0x6096A0

// CChatService
#define CChatService__GetNumberOfFriends                           0x774B70
#define CChatService__GetFriendName                                0x774B80

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x60E470
#define CChatWindow__Clear                                         0x60E020
#define CChatWindow__WndNotification                               0x60E880

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7DF460
#define CComboWnd__Draw                                            0x7DF620
#define CComboWnd__GetCurChoice                                    0x7DF280
#define CComboWnd__GetListRect                                     0x7DF900
#define CComboWnd__GetTextRect                                     0x7DF490
#define CComboWnd__InsertChoice                                    0x7DF970
#define CComboWnd__SetColors                                       0x7DF210
#define CComboWnd__SetChoice                                       0x7DF240

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x616780
#define CContainerWnd__vftable                                     0x9261E0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x47DD10
#define CDisplay__GetClickedActor                                  0x476790
#define CDisplay__GetUserDefinedColor                              0x475080
#define CDisplay__GetWorldFilePath                                 0x4745A0
#define CDisplay__is3dON                                           0x4736A0
#define CDisplay__ReloadUI                                         0x487540
#define CDisplay__WriteTextHD2                                     0x479840

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5DD220
#define CEditBaseWnd__SetSel                                       0x7FFEB0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7E8B00
#define CEditWnd__GetCharIndexPt                                   0x7E9AD0
#define CEditWnd__GetDisplayString                                 0x7E8CA0
#define CEditWnd__GetHorzOffset                                    0x7E8F30
#define CEditWnd__GetLineForPrintableChar                          0x7E9580
#define CEditWnd__GetSelStartPt                                    0x7E9D10
#define CEditWnd__GetSTMLSafeText                                  0x7E90D0
#define CEditWnd__PointFromPrintableChar                           0x7E9690
#define CEditWnd__SelectableCharFromPoint                          0x7E9810
#define CEditWnd__SetEditable                                      0x7E90A0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4F41A0
#define CEverQuest__DropHeldItemOnGround                           0x501110
#define CEverQuest__dsp_chat                                       0x4FA4A0
#define CEverQuest__DoTellWindow                                   0x4F8B90
#define CEverQuest__EnterZone                                      0x50B550
#define CEverQuest__GetBodyTypeDesc                                0x4F0FA0
#define CEverQuest__GetClassDesc                                   0x4F07E0
#define CEverQuest__GetClassThreeLetterCode                        0x4F0DE0
#define CEverQuest__GetDeityDesc                                   0x4F1650
#define CEverQuest__GetLangDesc                                    0x4F1330
#define CEverQuest__GetRaceDesc                                    0x4F1620
#define CEverQuest__InterpretCmd                                   0x4FAFB0
#define CEverQuest__LeftClickedOnPlayer                            0x50D260
#define CEverQuest__LMouseUp                                       0x510980
#define CEverQuest__RightClickedOnPlayer                           0x511B50
#define CEverQuest__RMouseUp                                       0x512B30
#define CEverQuest__SetGameState                                   0x4F4630
#define CEverQuest__Emote                                          0x4FA6C0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x624500
#define CGaugeWnd__CalcLinesFillRect                               0x624560
#define CGaugeWnd__Draw                                            0x6249B0

// CGuild
#define CGuild__FindMemberByName                                   0x41D200

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x63E9E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x648D20
#define CInvSlotMgr__MoveItem                                      0x6499D0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x6483B0
#define CInvSlot__SliderComplete                                   0x646770
#define CInvSlot__GetItemBase                                      0x645DF0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x64A730

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6FC0E0
#define CItemDisplayWnd__UpdateStrings                             0x64B780

// CLabel 
#define CLabel__Draw                                               0x662A20

// CListWnd 
#define CListWnd__AddColumn                                        0x7D4D90
#define CListWnd__AddColumn1                                       0x7D43C0
#define CListWnd__AddLine                                          0x7D3F70
#define CListWnd__AddString                                        0x7D4110
#define CListWnd__CalculateFirstVisibleLine                        0x7D01E0
#define CListWnd__CalculateVSBRange                                0x7D25E0
#define CListWnd__ClearAllSel                                      0x7CF730
#define CListWnd__CloseAndUpdateEditWindow                         0x7D35E0
#define CListWnd__Compare                                          0x7D0C80
#define CListWnd__Draw                                             0x7D2220
#define CListWnd__DrawColumnSeparators                             0x7D20B0
#define CListWnd__DrawHeader                                       0x7CF9C0
#define CListWnd__DrawItem                                         0x7D1680
#define CListWnd__DrawLine                                         0x7D1D70
#define CListWnd__DrawSeparator                                    0x7D2150
#define CListWnd__EnsureVisible                                    0x7D0340
#define CListWnd__ExtendSel                                        0x7D15A0
#define CListWnd__GetColumnMinWidth                                0x7CF400
#define CListWnd__GetColumnWidth                                   0x7CF340
#define CListWnd__GetCurSel                                        0x7CEB00
#define CListWnd__GetHeaderRect                                    0x7CEC60
#define CListWnd__GetItemAtPoint                                   0x7D0610
#define CListWnd__GetItemAtPoint1                                  0x7D0680
#define CListWnd__GetItemData                                      0x7CEF40
#define CListWnd__GetItemHeight                                    0x7CFE50
#define CListWnd__GetItemIcon                                      0x7CF120
#define CListWnd__GetItemRect                                      0x7D0410
#define CListWnd__GetItemText                                      0x7CEFD0
#define CListWnd__GetSelList                                       0x7D42A0
#define CListWnd__GetSeparatorRect                                 0x7D0BD0
#define CListWnd__RemoveLine                                       0x7D4D40
#define CListWnd__SetColors                                        0x7CEBD0
#define CListWnd__SetColumnJustification                           0x7CF5A0
#define CListWnd__SetColumnWidth                                   0x7CF3C0
#define CListWnd__SetCurSel                                        0x7CEB40
#define CListWnd__SetItemColor                                     0x7D3290
#define CListWnd__SetItemData                                      0x7CF7D0
#define CListWnd__SetItemText                                      0x7D30C0
#define CListWnd__ShiftColumnSeparator                             0x7D2F30
#define CListWnd__Sort                                             0x7D54F0
#define CListWnd__ToggleSel                                        0x7CF6A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x67B4C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x697620
#define CMerchantWnd__RequestBuyItem                               0x69D780
#define CMerchantWnd__RequestSellItem                              0x6BFD20
#define CMerchantWnd__SelectBuySellSlot                            0x6978D0

// CObfuscator
#define CObfuscator__doit                                          0x747FD0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7F15B0
#define CSidlManager__CreateLabel                                  0x6F3BF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5E1530
#define CSidlScreenWnd__CalculateVSBRange                          0x5E1450
#define CSidlScreenWnd__ConvertToRes                               0x7FFD90
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7E1AB0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7E2CF0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x7E2DA0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x7E2480
#define CSidlScreenWnd__DrawSidlPiece                              0x7E1550
#define CSidlScreenWnd__EnableIniStorage                           0x7E0D10
#define CSidlScreenWnd__GetSidlPiece                               0x7E1770
#define CSidlScreenWnd__Init1                                      0x7E2B40
#define CSidlScreenWnd__LoadIniInfo                                0x7E1B70
#define CSidlScreenWnd__LoadIniListWnd                             0x7E0E60
#define CSidlScreenWnd__LoadSidlScreen                             0x7E26E0
#define CSidlScreenWnd__StoreIniInfo                               0x7E08E0
#define CSidlScreenWnd__StoreIniVis                                0x7E0CA0
#define CSidlScreenWnd__WndNotification                            0x7E2930
#define CSidlScreenWnd__GetChildItem                               0x7E0D70

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x5866C0
#define CSkillMgr__GetSkillCap                                     0x586730

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x537DF0
#define CSliderWnd__SetValue                                       0x808020
#define CSliderWnd__SetNumTicks                                    0x8085D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6F9D60

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7FD200
#define CStmlWnd__CalculateHSBRange                                0x7F47C0
#define CStmlWnd__CalculateVSBRange                                0x7F4850
#define CStmlWnd__CanBreakAtCharacter                              0x7F49D0
#define CStmlWnd__FastForwardToEndOfTag                            0x7F56B0
#define CStmlWnd__ForceParseNow                                    0x7FD7F0
#define CStmlWnd__GetNextTagPiece                                  0x7F55D0
#define CStmlWnd__GetSTMLText                                      0x60D8B0
#define CStmlWnd__GetThisChar                                      0x8288F0
#define CStmlWnd__GetVisiableText                                  0x7F6B10
#define CStmlWnd__InitializeWindowVariables                        0x7F9100
#define CStmlWnd__MakeStmlColorTag                                 0x7F36E0
#define CStmlWnd__MakeWndNotificationTag                           0x7F3780
#define CStmlWnd__SetSTMLText                                      0x7F9230
#define CStmlWnd__StripFirstSTMLLines                              0x7FCEA0
#define CStmlWnd__UpdateHistoryString                              0x7F73B0

// CTabWnd 
#define CTabWnd__Draw                                              0x803B20
#define CTabWnd__DrawCurrentPage                                   0x8033A0
#define CTabWnd__DrawTab                                           0x803170
#define CTabWnd__GetCurrentPage                                    0x803760
#define CTabWnd__GetPageClientRect                                 0x802E20
#define CTabWnd__GetPageFromTabIndex                               0x8030A0
#define CTabWnd__GetPageInnerRect                                  0x802E80
#define CTabWnd__GetTabInnerRect                                   0x803020
#define CTabWnd__GetTabRect                                        0x802F10
#define CTabWnd__InsertPage                                        0x803DB0
#define CTabWnd__SetPage                                           0x8037A0
#define CTabWnd__SetPageRect                                       0x803A50
#define CTabWnd__UpdatePage                                        0x803D30

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x419460

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7E3120

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x800FD0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x7CD980

// CXRect 
#define CXRect__CenterPoint                                        0x524A60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x5303A0
#define CXStr__CXStr1                                              0x401420
#define CXStr__CXStr3                                              0x78E280
#define CXStr__dCXStr                                              0x6EE530
#define CXStr__operator_equal                                      0x78E3F0
#define CXStr__operator_equal1                                     0x78E440
#define CXStr__operator_plus_equal1                                0x78F550

// CXWnd 
#define CXWnd__BringToTop                                          0x7D8430
#define CXWnd__Center                                              0x7DDDE0
#define CXWnd__ClrFocus                                            0x7D8260
#define CXWnd__DoAllDrawing                                        0x7DDC70
#define CXWnd__DrawChildren                                        0x7DDDB0
#define CXWnd__DrawColoredRect                                     0x7D8750
#define CXWnd__DrawTooltip                                         0x7D8940
#define CXWnd__DrawTooltipAtPoint                                  0x7DCEE0
#define CXWnd__GetBorderFrame                                      0x7D8D60
#define CXWnd__GetChildWndAt                                       0x7DC0D0
#define CXWnd__GetClientClipRect                                   0x7D8AE0
#define CXWnd__GetScreenClipRect                                   0x7DD410
#define CXWnd__GetScreenRect                                       0x7D8E90
#define CXWnd__GetTooltipRect                                      0x7D8860
#define CXWnd__GetWindowTextA                                      0x5245E0
#define CXWnd__IsActive                                            0x7E4260
#define CXWnd__IsDescendantOf                                      0x7D8C50
#define CXWnd__IsReallyVisible                                     0x7DC0B0
#define CXWnd__IsType                                              0x805390
#define CXWnd__Move                                                0x7DB820
#define CXWnd__Move1                                               0x7DD940
#define CXWnd__ProcessTransition                                   0x7D83E0
#define CXWnd__Refade                                              0x7D8360
#define CXWnd__Resize                                              0x7D8F60
#define CXWnd__Right                                               0x7DD320
#define CXWnd__SetFocus                                            0x7DA990
#define CXWnd__SetKeyTooltip                                       0x7D91B0
#define CXWnd__SetMouseOver                                        0x7DD730
#define CXWnd__StartFade                                           0x7D8470
#define CXWnd__GetChildItem                                        0x7DD670

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x7E57C0
#define CXWndManager__DrawWindows                                  0x7E5440
#define CXWndManager__GetKeyboardFlags                             0x7E3EB0
#define CXWndManager__HandleKeyboardMsg                            0x7E4530
#define CXWndManager__RemoveWnd                                    0x7E4380

// CDBStr
#define CDBStr__GetString                                          0x471C20

// EQ_Character 
#define EQ_Character__CastRay                                      0x761B40
#define EQ_Character__CastSpell                                    0x433780
#define EQ_Character__Cur_HP                                       0x43D0C0
#define EQ_Character__GetAACastingTimeModifier                     0x428330
#define EQ_Character__GetCharInfo2                                 0x75FE80
#define EQ_Character__GetFocusCastingTimeModifier                  0x422F30
#define EQ_Character__GetFocusRangeModifier                        0x423100
#define EQ_Character__Max_Endurance                                0x552D00
#define EQ_Character__Max_HP                                       0x437770
#define EQ_Character__Max_Mana                                     0x552B00
#define EQ_Character__doCombatAbility                              0x5518F0
#define EQ_Character__UseSkill                                     0x44CC70
#define EQ_Character__GetConLevel                                  0x548BE0
#define EQ_Character__IsExpansionFlag                              0x40DE50
#define EQ_Character__TotalEffect                                  0x42CBE0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x52A140
#define EQ_Item__CreateItemTagString                               0x746110
#define EQ_Item__IsStackable                                       0x73A3E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x48BC00
#define EQ_LoadingS__Array                                         0x9DAA50

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x556920
#define EQ_PC__GetAltAbilityIndex                                  0x751300
#define EQ_PC__GetCombatAbility                                    0x751390
#define EQ_PC__GetCombatAbilityTimer                               0x751440
#define EQ_PC__GetItemTimerValue                                   0x551660
#define EQ_PC__HasLoreItem                                         0x550130

// EQItemList 
#define EQItemList__EQItemList                                     0x4BC960
#define EQItemList__add_item                                       0x4BC8F0
#define EQItemList__delete_item                                    0x4BCD10
#define EQItemList__FreeItemList                                   0x4BCC40

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x4711B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x55BAF0
#define EQPlayer__dEQPlayer                                        0x560780
#define EQPlayer__DoAttack                                         0x5728F0
#define EQPlayer__EQPlayer                                         0x566AA0
#define EQPlayer__SetNameSpriteState                               0x55DFD0
#define EQPlayer__SetNameSpriteTint                                0x55BB60
#define EQPlayer__IsBodyType_j                                     0x7613E0
#define EQPlayer__IsTargetable                                     0x7616B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x568040
#define EQPlayerManager__GetSpawnByName                            0x5682D0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x52FD10
#define KeypressHandler__AttachKeyToEqCommand                      0x52FD50
#define KeypressHandler__ClearCommandStateArray                    0x52FB20
#define KeypressHandler__HandleKeyDown                             0x52E4B0
#define KeypressHandler__HandleKeyUp                               0x52E7C0
#define KeypressHandler__SaveKeymapping                            0x52FBF0

// MapViewMap 
#define MapViewMap__Clear                                          0x6746F0
#define MapViewMap__SaveEx                                         0x677DA0

#define PlayerPointManager__GetAltCurrency                         0x74BC50

// StringTable 
#define StringTable__getString                                     0x748250

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x555030
