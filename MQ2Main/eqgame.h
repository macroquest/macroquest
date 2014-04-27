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
#define __ExpectedVersionDate                                     "Sep 24 2012"
#define __ExpectedVersionTime                                     "11:38:04"
#define __ActualVersionDate                                        0x91D780
#define __ActualVersionTime                                        0x91D78C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x537D10
#define __MemChecker1                                              0x825950
#define __MemChecker2                                              0x5BF370
#define __MemChecker3                                              0x5BF2C0
#define __MemChecker4                                              0x848190
#define __EncryptPad0                                              0x9F7FF8
#define __EncryptPad1                                              0xA72108
#define __EncryptPad2                                              0xA10D90
#define __EncryptPad3                                              0xA10990
#define __EncryptPad4                                              0xA73BB0
#define __AC1                                                      0x6FFD50
#define __AC2                                                      0x4F3C85
#define __AC3                                                      0x505EB8
#define __AC4                                                      0x50B624
#define __AC5                                                      0x5174FE
#define __AC6                                                      0x51AEBB
#define __AC7                                                      0x512DCB
#define __AC1_Data                                                 0x90256D
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
#define __do_loot                                                  0x4C7230
#define __DrawHandler                                              0x145FA94
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
#define pinstCSidlManager                                          0x145FFD4
#define pinstCXWndManager                                          0x145FFCC
#define instDynamicZone                                            0xC792E0
#define pinstDZMember                                              0xC793F0
#define pinstDZTimerInfo                                           0xC793F4
#define pinstEQItemList                                            0xC6CA50
#define instEQMisc                                                 0xBBCD68
#define pinstEQSoundManager                                        0xBBDDE0
#define instExpeditionLeader                                       0xC7932A
#define instExpeditionName                                         0xC7936A
#define pinstGroup                                                 0xC6D9D6
#define pinstImeManager                                            0x145FFD8
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
#define pinstCContextMenuManager                                   0x1460030
#define pinstCVoiceMacroWnd                                        0xCF3ED8
#define pinstCHtmlWnd                                              0xCF3F50


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4DB9D0
#define __ConvertItemTags                                          0x4CC950
#define __ExecuteCmd                                               0x4B8450
#define __EQGetTime                                                0x826D70
#define __get_melee_range                                          0x4BE710
#define __GetGaugeValueFromEQ                                      0x6FEB00
#define __GetLabelFromEQ                                           0x6FFCF0
#define __GetXTargetType                                           0x77E930
#define __LoadFrontEnd                                             0x5BE2E0
#define __NewUIINI                                                 0x6FE6B0
#define __ProcessGameEvents                                        0x5135B0
#define CrashDetected                                              0x5C0CF0
#define DrawNetStatus                                              0x545660
#define Util__FastTime                                             0x826220
#define Expansion_HoT                                              0xC7E2B4
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x48A5E0
#define AltAdvManager__IsAbilityReady                              0x48A6E0
#define AltAdvManager__GetAltAbility                               0x48A9F0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x43D3D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5E5720

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5EFCC0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x525BA0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x608C60
#define CChatManager__InitContextMenu                              0x609590

// CChatService
#define CChatService__GetNumberOfFriends                           0x774BA0
#define CChatService__GetFriendName                                0x774BB0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x60E350
#define CChatWindow__Clear                                         0x60DF00
#define CChatWindow__WndNotification                               0x60E760

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7D5530
#define CComboWnd__Draw                                            0x7D56F0
#define CComboWnd__GetCurChoice                                    0x7D5350
#define CComboWnd__GetListRect                                     0x7D59D0
#define CComboWnd__GetTextRect                                     0x7D5560
#define CComboWnd__InsertChoice                                    0x7D5A40
#define CComboWnd__SetColors                                       0x7D52E0
#define CComboWnd__SetChoice                                       0x7D5310

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x6166A0
#define CContainerWnd__vftable                                     0x9261E0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x47DD50
#define CDisplay__GetClickedActor                                  0x476800
#define CDisplay__GetUserDefinedColor                              0x4750F0
#define CDisplay__GetWorldFilePath                                 0x474610
#define CDisplay__is3dON                                           0x473710
#define CDisplay__ReloadUI                                         0x4874E0
#define CDisplay__WriteTextHD2                                     0x479880

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5DD180
#define CEditBaseWnd__SetSel                                       0x7F5F30

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7DEBD0
#define CEditWnd__GetCharIndexPt                                   0x7DFBA0
#define CEditWnd__GetDisplayString                                 0x7DED70
#define CEditWnd__GetHorzOffset                                    0x7DF000
#define CEditWnd__GetLineForPrintableChar                          0x7DF650
#define CEditWnd__GetSelStartPt                                    0x7DFDE0
#define CEditWnd__GetSTMLSafeText                                  0x7DF1A0
#define CEditWnd__PointFromPrintableChar                           0x7DF760
#define CEditWnd__SelectableCharFromPoint                          0x7DF8E0
#define CEditWnd__SetEditable                                      0x7DF170

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4F43D0
#define CEverQuest__DropHeldItemOnGround                           0x501370
#define CEverQuest__dsp_chat                                       0x4FA700
#define CEverQuest__DoTellWindow                                   0x4F8DF0
#define CEverQuest__EnterZone                                      0x50B7B0
#define CEverQuest__GetBodyTypeDesc                                0x4F11D0
#define CEverQuest__GetClassDesc                                   0x4F0A10
#define CEverQuest__GetClassThreeLetterCode                        0x4F1010
#define CEverQuest__GetDeityDesc                                   0x4F1880
#define CEverQuest__GetLangDesc                                    0x4F1560
#define CEverQuest__GetRaceDesc                                    0x4F1850
#define CEverQuest__InterpretCmd                                   0x4FB210
#define CEverQuest__LeftClickedOnPlayer                            0x50D4C0
#define CEverQuest__LMouseUp                                       0x510BE0
#define CEverQuest__RightClickedOnPlayer                           0x511DB0
#define CEverQuest__RMouseUp                                       0x512D90
#define CEverQuest__SetGameState                                   0x4F4860
#define CEverQuest__Emote                                          0x4FA920

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x624410
#define CGaugeWnd__CalcLinesFillRect                               0x624470
#define CGaugeWnd__Draw                                            0x6248C0

// CGuild
#define CGuild__FindMemberByName                                   0x41D210

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x63E900

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x648C20
#define CInvSlotMgr__MoveItem                                      0x6498D0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x6482B0
#define CInvSlot__SliderComplete                                   0x646670
#define CInvSlot__GetItemBase                                      0x645CF0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x64A630

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6FC0C0
#define CItemDisplayWnd__UpdateStrings                             0x64B680

// CLabel 
#define CLabel__Draw                                               0x662950

// CListWnd 
#define CListWnd__AddColumn                                        0x7CB040
#define CListWnd__AddColumn1                                       0x7CA6C0
#define CListWnd__AddLine                                          0x7CA220
#define CListWnd__AddString                                        0x7CA3C0
#define CListWnd__CalculateFirstVisibleLine                        0x7C6490
#define CListWnd__CalculateVSBRange                                0x7C8890
#define CListWnd__ClearAllSel                                      0x7C59E0
#define CListWnd__CloseAndUpdateEditWindow                         0x7C9890
#define CListWnd__Compare                                          0x7C6F30
#define CListWnd__Draw                                             0x7C84D0
#define CListWnd__DrawColumnSeparators                             0x7C8360
#define CListWnd__DrawHeader                                       0x7C5C70
#define CListWnd__DrawItem                                         0x7C7930
#define CListWnd__DrawLine                                         0x7C8020
#define CListWnd__DrawSeparator                                    0x7C8400
#define CListWnd__EnsureVisible                                    0x7C65F0
#define CListWnd__ExtendSel                                        0x7C7850
#define CListWnd__GetColumnMinWidth                                0x7C56B0
#define CListWnd__GetColumnWidth                                   0x7C55F0
#define CListWnd__GetCurSel                                        0x7C4DB0
#define CListWnd__GetHeaderRect                                    0x7C4F10
#define CListWnd__GetItemAtPoint                                   0x7C68C0
#define CListWnd__GetItemAtPoint1                                  0x7C6930
#define CListWnd__GetItemData                                      0x7C51F0
#define CListWnd__GetItemHeight                                    0x7C6100
#define CListWnd__GetItemIcon                                      0x7C53D0
#define CListWnd__GetItemRect                                      0x7C66C0
#define CListWnd__GetItemText                                      0x7C5280
#define CListWnd__GetSelList                                       0x7CA5A0
#define CListWnd__GetSeparatorRect                                 0x7C6E80
#define CListWnd__RemoveLine                                       0x7CA550
#define CListWnd__SetColors                                        0x7C4E80
#define CListWnd__SetColumnJustification                           0x7C5850
#define CListWnd__SetColumnWidth                                   0x7C5670
#define CListWnd__SetCurSel                                        0x7C4DF0
#define CListWnd__SetItemColor                                     0x7C9540
#define CListWnd__SetItemData                                      0x7C5A80
#define CListWnd__SetItemText                                      0x7C9370
#define CListWnd__ShiftColumnSeparator                             0x7C91E0
#define CListWnd__Sort                                             0x7CB7A0
#define CListWnd__ToggleSel                                        0x7C5950

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x67B3E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x697630
#define CMerchantWnd__RequestBuyItem                               0x69D790
#define CMerchantWnd__RequestSellItem                              0x6BFD40
#define CMerchantWnd__SelectBuySellSlot                            0x6978E0

// CObfuscator
#define CObfuscator__doit                                          0x748060

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7E7620
#define CSidlManager__CreateLabel                                  0x6F3BF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5E13E0
#define CSidlScreenWnd__CalculateVSBRange                          0x5E1300
#define CSidlScreenWnd__ConvertToRes                               0x7F5E10
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7D7B80
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7D8DC0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x7D8E70
#define CSidlScreenWnd__dCSidlScreenWnd                            0x7D8550
#define CSidlScreenWnd__DrawSidlPiece                              0x7D7620
#define CSidlScreenWnd__EnableIniStorage                           0x7D6DE0
#define CSidlScreenWnd__GetSidlPiece                               0x7D7840
#define CSidlScreenWnd__Init1                                      0x7D8C10
#define CSidlScreenWnd__LoadIniInfo                                0x7D7C40
#define CSidlScreenWnd__LoadIniListWnd                             0x7D6F30
#define CSidlScreenWnd__LoadSidlScreen                             0x7D87B0
#define CSidlScreenWnd__StoreIniInfo                               0x7D69B0
#define CSidlScreenWnd__StoreIniVis                                0x7D6D70
#define CSidlScreenWnd__WndNotification                            0x7D8A00
#define CSidlScreenWnd__GetChildItem                               0x7D6E40

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x5865E0
#define CSkillMgr__GetSkillCap                                     0x586650

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x538070
#define CSliderWnd__SetValue                                       0x7FE0B0
#define CSliderWnd__SetNumTicks                                    0x7FE660

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6F9D50

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7F3280
#define CStmlWnd__CalculateHSBRange                                0x7EA840
#define CStmlWnd__CalculateVSBRange                                0x7EA8D0
#define CStmlWnd__CanBreakAtCharacter                              0x7EAA40
#define CStmlWnd__FastForwardToEndOfTag                            0x7EB730
#define CStmlWnd__ForceParseNow                                    0x7F3870
#define CStmlWnd__GetNextTagPiece                                  0x7EB650
#define CStmlWnd__GetSTMLText                                      0x60D7A0
#define CStmlWnd__GetThisChar                                      0x81EA90
#define CStmlWnd__GetVisiableText                                  0x7ECB90
#define CStmlWnd__InitializeWindowVariables                        0x7EF180
#define CStmlWnd__MakeStmlColorTag                                 0x7E9760
#define CStmlWnd__MakeWndNotificationTag                           0x7E9800
#define CStmlWnd__SetSTMLText                                      0x7EF2B0
#define CStmlWnd__StripFirstSTMLLines                              0x7F2F20
#define CStmlWnd__UpdateHistoryString                              0x7ED430

// CTabWnd 
#define CTabWnd__Draw                                              0x7F9BC0
#define CTabWnd__DrawCurrentPage                                   0x7F9440
#define CTabWnd__DrawTab                                           0x7F9210
#define CTabWnd__GetCurrentPage                                    0x7F9800
#define CTabWnd__GetPageClientRect                                 0x7F8EC0
#define CTabWnd__GetPageFromTabIndex                               0x7F9140
#define CTabWnd__GetPageInnerRect                                  0x7F8F20
#define CTabWnd__GetTabInnerRect                                   0x7F90C0
#define CTabWnd__GetTabRect                                        0x7F8FB0
#define CTabWnd__InsertPage                                        0x7F9E50
#define CTabWnd__SetPage                                           0x7F9840
#define CTabWnd__SetPageRect                                       0x7F9AF0
#define CTabWnd__UpdatePage                                        0x7F9DD0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x419480

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7D91F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7F7070

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x7C3C70

// CXRect 
#define CXRect__CenterPoint                                        0x524CC0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x530670
#define CXStr__CXStr1                                              0x7BD270
#define CXStr__CXStr3                                              0x8230B0
#define CXStr__dCXStr                                              0x401720
#define CXStr__operator_equal                                      0x823220
#define CXStr__operator_equal1                                     0x823270
#define CXStr__operator_plus_equal1                                0x824380

// CXWnd 
#define CXWnd__BringToTop                                          0x7CE4F0
#define CXWnd__Center                                              0x7D3EB0
#define CXWnd__ClrFocus                                            0x7CE330
#define CXWnd__DoAllDrawing                                        0x7D3D40
#define CXWnd__DrawChildren                                        0x7D3E80
#define CXWnd__DrawColoredRect                                     0x7CE820
#define CXWnd__DrawTooltip                                         0x7CEA10
#define CXWnd__DrawTooltipAtPoint                                  0x7D2FB0
#define CXWnd__GetBorderFrame                                      0x7CEE30
#define CXWnd__GetChildWndAt                                       0x7D21A0
#define CXWnd__GetClientClipRect                                   0x7CEBB0
#define CXWnd__GetScreenClipRect                                   0x7D34E0
#define CXWnd__GetScreenRect                                       0x7CEF60
#define CXWnd__GetTooltipRect                                      0x7CE930
#define CXWnd__GetWindowTextA                                      0x524840
#define CXWnd__IsActive                                            0x7DA330
#define CXWnd__IsDescendantOf                                      0x7CED20
#define CXWnd__IsReallyVisible                                     0x7D2180
#define CXWnd__IsType                                              0x7FB450
#define CXWnd__Move                                                0x7D18F0
#define CXWnd__Move1                                               0x7D3A10
#define CXWnd__ProcessTransition                                   0x7CE4A0
#define CXWnd__Refade                                              0x7CE430
#define CXWnd__Resize                                              0x7CF030
#define CXWnd__Right                                               0x7D33F0
#define CXWnd__SetFocus                                            0x7D0A60
#define CXWnd__SetKeyTooltip                                       0x7CF280
#define CXWnd__SetMouseOver                                        0x7D3800
#define CXWnd__StartFade                                           0x7CE530
#define CXWnd__GetChildItem                                        0x7D3740

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x7DB890
#define CXWndManager__DrawWindows                                  0x7DB510
#define CXWndManager__GetKeyboardFlags                             0x7D9F80
#define CXWndManager__HandleKeyboardMsg                            0x7DA600
#define CXWndManager__RemoveWnd                                    0x7DA450

// CDBStr
#define CDBStr__GetString                                          0x471CB0

// EQ_Character 
#define EQ_Character__CastRay                                      0x761B60
#define EQ_Character__CastSpell                                    0x433740
#define EQ_Character__Cur_HP                                       0x43D070
#define EQ_Character__GetAACastingTimeModifier                     0x4282F0
#define EQ_Character__GetCharInfo2                                 0x75FEC0
#define EQ_Character__GetFocusCastingTimeModifier                  0x422F10
#define EQ_Character__GetFocusRangeModifier                        0x4230E0
#define EQ_Character__Max_Endurance                                0x552F80
#define EQ_Character__Max_HP                                       0x437720
#define EQ_Character__Max_Mana                                     0x552D80
#define EQ_Character__doCombatAbility                              0x551B70
#define EQ_Character__UseSkill                                     0x44CC20
#define EQ_Character__GetConLevel                                  0x548E30
#define EQ_Character__IsExpansionFlag                              0x40DE80
#define EQ_Character__TotalEffect                                  0x42CBA0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x52A370
#define EQ_Item__CreateItemTagString                               0x7460B0
#define EQ_Item__IsStackable                                       0x73A3D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x48BCE0
#define EQ_LoadingS__Array                                         0x9DAA50

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x556BA0
#define EQ_PC__GetAltAbilityIndex                                  0x751320
#define EQ_PC__GetCombatAbility                                    0x7513B0
#define EQ_PC__GetCombatAbilityTimer                               0x751460
#define EQ_PC__GetItemTimerValue                                   0x5518E0
#define EQ_PC__HasLoreItem                                         0x5503B0

// EQItemList 
#define EQItemList__EQItemList                                     0x4BCA60
#define EQItemList__add_item                                       0x4BC9F0
#define EQItemList__delete_item                                    0x4BCE10
#define EQItemList__FreeItemList                                   0x4BCD40

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x471260

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x55BD60
#define EQPlayer__dEQPlayer                                        0x5609E0
#define EQPlayer__DoAttack                                         0x572B40
#define EQPlayer__EQPlayer                                         0x566D00
#define EQPlayer__SetNameSpriteState                               0x55E240
#define EQPlayer__SetNameSpriteTint                                0x55BDD0
#define EQPlayer__IsBodyType_j                                     0x761400
#define EQPlayer__IsTargetable                                     0x7616D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5682A0
#define EQPlayerManager__GetSpawnByName                            0x568530

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x52FFE0
#define KeypressHandler__AttachKeyToEqCommand                      0x530020
#define KeypressHandler__ClearCommandStateArray                    0x52FDF0
#define KeypressHandler__HandleKeyDown                             0x52E780
#define KeypressHandler__HandleKeyUp                               0x52EA90
#define KeypressHandler__SaveKeymapping                            0x52FEC0

// MapViewMap 
#define MapViewMap__Clear                                          0x674610
#define MapViewMap__SaveEx                                         0x677CC0

#define PlayerPointManager__GetAltCurrency                         0x74BC00

// StringTable 
#define StringTable__getString                                     0x7482E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x5552B0
