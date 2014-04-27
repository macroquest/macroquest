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
#define __ExpectedVersionDate                                     "Mar 21 2012"
#define __ExpectedVersionTime                                     "14:32:08"
#define __ActualVersionDate                                        0x90976C
#define __ActualVersionTime                                        0x909778

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x5355E0
#define __MemChecker1                                              0x813A40
#define __MemChecker2                                              0x5B8100
#define __MemChecker3                                              0x5B8050
#define __MemChecker4                                              0x835CF0
#define __EncryptPad0                                              0x9E14F0
#define __EncryptPad1                                              0xA59EA8
#define __EncryptPad2                                              0x9F99A0
#define __EncryptPad3                                              0x9F95A0
#define __EncryptPad4                                              0xA5B950
#define __AC1                                                      0x6F3E90
#define __AC2                                                      0x4F12F5
#define __AC3                                                      0x503458
#define __AC4                                                      0x508DE4
#define __AC5                                                      0x5151F8
#define __AC6                                                      0x518B2B
#define __AC7                                                      0x510B7B
#define __AC1_Data                                                 0x8EF11D
// Direct Input
#define DI8__Main                                                  0xCDF290
#define DI8__Keyboard                                              0xCDF294
#define DI8__Mouse                                                 0xCDF298
#define __AltTimerReady                                            0xBA7881
#define __Attack                                                   0xCDB092
#define __Autofire                                                 0xCDB093
#define __BindList                                                 0x9C9B58
#define __Clicks                                                   0xC64B84
#define __CommandList                                              0x9CB190
#define __CurrentMapLabel                                          0xD0B0D0
#define __CurrentSocial                                            0x9B5E30
#define __DoAbilityList                                            0xC9BA6C
#define __do_loot                                                  0x4C4E10
#define __DrawHandler                                              0x1367D64
#define __GroupCount                                               0xC55742
#define __Guilds                                                   0xC57AD0
#define __gWorld                                                   0xC579FC
#define __HotkeyPage                                               0xCC4648
#define __HWnd                                                     0xCDEFE0
#define __InChatMode                                               0xC64ABC
#define __LastTell                                                 0xC66984
#define __LMouseHeldTime                                           0xC64BF0
#define __Mouse                                                    0xCDF29C
#define __MouseLook                                                0xC64B52
#define __MouseEventTime                                           0xCDB3AC
#define __NetStatusToggle                                          0xC64B55
#define __PCNames                                                  0xC66008
#define __RangeAttackReady                                         0xC65CA0
#define __RMouseHeldTime                                           0xC64BEC
#define __RunWalkState                                             0xC64AC0
#define __ScreenMode                                               0xBA4BC8
#define __ScreenX                                                  0xC64A70
#define __ScreenY                                                  0xC64A74
#define __ScreenXMax                                               0xC64A78
#define __ScreenYMax                                               0xC64A7C
#define __ServerHost                                               0xC55684
#define __ServerName                                               0xC9BA2C
#define __ShiftKeyDown                                             0xC6513C
#define __ShowNames                                                0xC65EAC
#define __Socials                                                  0xC9BB2C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xC613E8
#define instEQZoneInfo                                             0xC64D38
#define instKeypressHandler                                        0xCDB3A8
#define pinstActiveBanker                                          0xC57AA4
#define pinstActiveCorpse                                          0xC57AA8
#define pinstActiveGMaster                                         0xC57AAC
#define pinstActiveMerchant                                        0xC57AA0
#define pinstAltAdvManager                                         0xBA5B10
#define pinstAuraMgr                                               0xA74D50
#define pinstBandageTarget                                         0xC57A8C
#define pinstCamActor                                              0xBA5584
#define pinstCDBStr                                                0xBA4BA0
#define pinstCDisplay                                              0xC57AB4
#define pinstCEverQuest                                            0xCDF418
#define pinstCharData                                              0xC57A70
#define pinstCharSpawn                                             0xC57A98
#define pinstControlledMissile                                     0xC57A6C
#define pinstControlledPlayer                                      0xC57A98
#define pinstCSidlManager                                          0x13682A4
#define pinstCXWndManager                                          0x136829C
#define instDynamicZone                                            0xC60E40
#define pinstDZMember                                              0xC60F50
#define pinstDZTimerInfo                                           0xC60F54
#define pinstEQItemList                                            0xC547F0
#define instEQMisc                                                 0xBA4B08
#define pinstEQSoundManager                                        0xBA5B80
#define instExpeditionLeader                                       0xC60E8A
#define instExpeditionName                                         0xC60ECA
#define pinstGroup                                                 0xC5573E
#define pinstImeManager                                            0x13682A8
#define pinstLocalPlayer                                           0xC57A84
#define pinstMercenaryData                                         0xCDB828
#define pinstModelPlayer                                           0xC57AB0
#define pinstPCData                                                0xC57A70
#define pinstSkillMgr                                              0xCDBE58
#define pinstSpawnManager                                          0xCDBAC8
#define pinstSpellManager                                          0xCDBE98
#define pinstSpellSets                                             0xCD43A0
#define pinstStringTable                                           0xC57A18
#define pinstSwitchManager                                         0xC55350
#define pinstTarget                                                0xC57A9C
#define pinstTargetObject                                          0xC57A74
#define pinstTargetSwitch                                          0xC57A78
#define pinstTaskMember                                            0xBA4AD0
#define pinstTrackTarget                                           0xC57A90
#define pinstTradeTarget                                           0xC57A80
#define instTributeActive                                          0xBA4B2D
#define pinstViewActor                                             0xBA5580
#define pinstWorldData                                             0xC57A54


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0xA6BD90
#define pinstCAudioTriggersWindow                                  0xA6BD28
#define pinstCCharacterSelect                                      0xBA5438
#define pinstCFacePick                                             0xBA53E8
#define pinstCNoteWnd                                              0xBA53F0
#define pinstCBookWnd                                              0xBA53F8
#define pinstCPetInfoWnd                                           0xBA53FC
#define pinstCTrainWnd                                             0xBA5400
#define pinstCSkillsWnd                                            0xBA5404
#define pinstCSkillsSelectWnd                                      0xBA5408
#define pinstCCombatSkillSelectWnd                                 0xBA540C
#define pinstCFriendsWnd                                           0xBA5410
#define pinstCAuraWnd                                              0xBA5414
#define pinstCRespawnWnd                                           0xBA5418
#define pinstCBandolierWnd                                         0xBA541C
#define pinstCPotionBeltWnd                                        0xBA5420
#define pinstCAAWnd                                                0xBA5424
#define pinstCGroupSearchFiltersWnd                                0xBA5428
#define pinstCLoadskinWnd                                          0xBA542C
#define pinstCAlarmWnd                                             0xBA5430
#define pinstCMusicPlayerWnd                                       0xBA5434
#define pinstCMailWnd                                              0xBA543C
#define pinstCMailCompositionWnd                                   0xBA5440
#define pinstCMailAddressBookWnd                                   0xBA5444
#define pinstCRaidWnd                                              0xBA544C
#define pinstCRaidOptionsWnd                                       0xBA5450
#define pinstCBreathWnd                                            0xBA5454
#define pinstCMapViewWnd                                           0xBA5458
#define pinstCMapToolbarWnd                                        0xBA545C
#define pinstCEditLabelWnd                                         0xBA5460
#define pinstCTargetWnd                                            0xBA5464
#define pinstCColorPickerWnd                                       0xBA5468
#define pinstCPlayerWnd                                            0xBA546C
#define pinstCOptionsWnd                                           0xBA5470
#define pinstCBuffWindowNORMAL                                     0xBA5474
#define pinstCBuffWindowSHORT                                      0xBA5478
#define pinstCharacterCreation                                     0xBA547C
#define pinstCCursorAttachment                                     0xBA5480
#define pinstCCastingWnd                                           0xBA5484
#define pinstCCastSpellWnd                                         0xBA5488
#define pinstCSpellBookWnd                                         0xBA548C
#define pinstCInventoryWnd                                         0xBA5490
#define pinstCBankWnd                                              0xBA5494
#define pinstCQuantityWnd                                          0xBA5498
#define pinstCLootWnd                                              0xBA549C
#define pinstCActionsWnd                                           0xBA54A0
#define pinstCCombatAbilityWnd                                     0xBA54A4
#define pinstCMerchantWnd                                          0xBA54A8
#define pinstCTradeWnd                                             0xBA54AC
#define pinstCSelectorWnd                                          0xBA54B0
#define pinstCBazaarWnd                                            0xBA54B4
#define pinstCBazaarSearchWnd                                      0xBA54B8
#define pinstCGiveWnd                                              0xBA54D4
#define pinstCTrackingWnd                                          0xBA54DC
#define pinstCInspectWnd                                           0xBA54E0
#define pinstCSocialEditWnd                                        0xBA54E4
#define pinstCFeedbackWnd                                          0xBA54E8
#define pinstCBugReportWnd                                         0xBA54EC
#define pinstCVideoModesWnd                                        0xBA54F0
#define pinstCTextEntryWnd                                         0xBA54F8
#define pinstCFileSelectionWnd                                     0xBA54FC
#define pinstCCompassWnd                                           0xBA5500
#define pinstCPlayerNotesWnd                                       0xBA5504
#define pinstCGemsGameWnd                                          0xBA5508
#define pinstCTimeLeftWnd                                          0xBA550C
#define pinstCPetitionQWnd                                         0xBA5520
#define pinstCSoulmarkWnd                                          0xBA5524
#define pinstCStoryWnd                                             0xBA5528
#define pinstCJournalTextWnd                                       0xBA552C
#define pinstCJournalCatWnd                                        0xBA5530
#define pinstCBodyTintWnd                                          0xBA5534
#define pinstCServerListWnd                                        0xBA5538
#define pinstCAvaZoneWnd                                           0xBA5540
#define pinstCBlockedBuffWnd                                       0xBA5544
#define pinstCBlockedPetBuffWnd                                    0xBA5548
#define pinstCInvSlotMgr                                           0xBA5578
#define pinstCContainerMgr                                         0xBA557C
#define pinstCAdventureLeaderboardWnd                              0xD07C08
#define pinstCAdventureRequestWnd                                  0xD07BD0
#define pinstCAltStorageWnd                                        0xD07D10
#define pinstCAdventureStatsWnd                                    0xD07C08
#define pinstCBarterMerchantWnd                                    0xD08168
#define pinstCBarterSearchWnd                                      0xD081A0
#define pinstCBarterWnd                                            0xD081D8
#define pinstCChatManager                                          0xD085D0
#define pinstCDynamicZoneWnd                                       0xD087C0
#define pinstCEQMainWnd                                            0xD08880
#define pinstCFellowshipWnd                                        0xD087B4
#define pinstCFindLocationWnd                                      0xD089B0
#define pinstCGroupSearchWnd                                       0xD08B10
#define pinstCGroupWnd                                             0xD08B48
#define pinstCGuildBankWnd                                         0xD08B80
#define pinstCGuildMgmtWnd                                         0xD0ABF0
#define pinstCGuildTributeMasterWnd                                0xD0C818
#define pinstCHotButtonWnd                                         0xD0AC44
#define pinstCHotButtonWnd1                                        0xD0AC44
#define pinstCHotButtonWnd2                                        0xD0AC48
#define pinstCHotButtonWnd3                                        0xD0AC4C
#define pinstCHotButtonWnd4                                        0xD0AC8C
#define pinstCItemDisplayManager                                   0xD0ADC0
#define pinstCItemExpTransferWnd                                   0xD0ADFC
#define pinstCLeadershipWnd                                        0xD0AF28
#define pinstCLFGuildWnd                                           0xD0AF60
#define pinstCMIZoneSelectWnd                                      0xD0B200
#define pinstCAdventureMerchantWnd                                 0xD0B4B0
#define pinstCConfirmationDialog                                   0xD0B4E8
#define pinstCPopupWndManager                                      0xD0B4E8
#define pinstCProgressionSelectionWnd                              0xD0B550
#define pinstCPvPLeaderboardWnd                                    0xD0B588
#define pinstCPvPStatsWnd                                          0xD0B5C0
#define pinstCSystemInfoDialogBox                                  0xD0B8A8
#define pinstCTargetOfTargetWnd                                    0xD0C4C8
#define pinstCTaskSelectWnd                                        0xD0B764
#define pinstCTaskTemplateSelectWnd                                0xD0C568
#define pinstCTaskWnd                                              0xD0C5A0
#define pinstCTipWndOFDAY                                          0xD0C698
#define pinstCTipWndCONTEXT                                        0xD0C69C
#define pinstCTitleWnd                                             0xD0C6D0
#define pinstCTradeskillWnd                                        0xD0C748
#define pinstCTributeBenefitWnd                                    0xD0C7E0
#define pinstCTributeMasterWnd                                     0xD0C818
#define pinstCContextMenuManager                                   0x1368300
#define pinstCVoiceMacroWnd                                        0xCDC1E0
#define pinstCHtmlWnd                                              0xCDC258


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D95B0
#define __ConvertItemTags                                          0x4CA530
#define __ExecuteCmd                                               0x4B6020
#define __EQGetTime                                                0x814EB0
#define __get_melee_range                                          0x4BC2F0
#define __GetGaugeValueFromEQ                                      0x6F2C40
#define __GetLabelFromEQ                                           0x6F3E30
#define __GetXTargetType                                           0x770C90
#define __LoadFrontEnd                                             0x5B7070
#define __NewUIINI                                                 0x6F27F0
#define __ProcessGameEvents                                        0x511360
#define CrashDetected                                              0x5B6E70
#define DrawNetStatus                                              0x542F60
#define Util__FastTime                                             0x814310
#define Expansion_HoT                                              0xC65E0C
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x489330
#define AltAdvManager__IsAbilityReady                              0x4893E0
#define AltAdvManager__GetAltAbility                               0x489640

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x43CB30

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5DDEA0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5E8200

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x5237A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x601100
#define CChatManager__InitContextMenu                              0x601A30

// CChatService
#define CChatService__GetNumberOfFriends                           0x767A30
#define CChatService__GetFriendName                                0x767A40

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x606800
#define CChatWindow__Clear                                         0x6063B0
#define CChatWindow__WndNotification                               0x606C10

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7C3BF0
#define CComboWnd__Draw                                            0x7C3DB0
#define CComboWnd__GetCurChoice                                    0x7C3A10
#define CComboWnd__GetListRect                                     0x7C4090
#define CComboWnd__GetTextRect                                     0x7C3C20
#define CComboWnd__InsertChoice                                    0x7C4100
#define CComboWnd__SetColors                                       0x7C39A0
#define CComboWnd__SetChoice                                       0x7C39D0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x610020
#define CContainerWnd__vftable                                     0x9121B0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x47CC30
#define CDisplay__GetClickedActor                                  0x475870
#define CDisplay__GetUserDefinedColor                              0x4741A0
#define CDisplay__GetWorldFilePath                                 0x4736C0
#define CDisplay__is3dON                                           0x4727C0
#define CDisplay__ReloadUI                                         0x486220
#define CDisplay__WriteTextHD2                                     0x478910

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5D5A90
#define CEditBaseWnd__SetSel                                       0x7E44A0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7CD290
#define CEditWnd__GetCharIndexPt                                   0x7CE260
#define CEditWnd__GetDisplayString                                 0x7CD430
#define CEditWnd__GetHorzOffset                                    0x7CD6C0
#define CEditWnd__GetLineForPrintableChar                          0x7CDD10
#define CEditWnd__GetSelStartPt                                    0x7CE4A0
#define CEditWnd__GetSTMLSafeText                                  0x7CD860
#define CEditWnd__PointFromPrintableChar                           0x7CDE20
#define CEditWnd__SelectableCharFromPoint                          0x7CDFA0
#define CEditWnd__SetEditable                                      0x7CD830

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4F1A40
#define CEverQuest__DropHeldItemOnGround                           0x4FE910
#define CEverQuest__dsp_chat                                       0x4F7CA0
#define CEverQuest__DoTellWindow                                   0x4F6430
#define CEverQuest__EnterZone                                      0x508D70
#define CEverQuest__GetBodyTypeDesc                                0x4EE840
#define CEverQuest__GetClassDesc                                   0x4EE080
#define CEverQuest__GetClassThreeLetterCode                        0x4EE680
#define CEverQuest__GetDeityDesc                                   0x4EEEF0
#define CEverQuest__GetLangDesc                                    0x4EEBD0
#define CEverQuest__GetRaceDesc                                    0x4EEEC0
#define CEverQuest__InterpretCmd                                   0x4F87B0
#define CEverQuest__LeftClickedOnPlayer                            0x50AE10
#define CEverQuest__LMouseUp                                       0x50EA00
#define CEverQuest__RightClickedOnPlayer                           0x50FB60
#define CEverQuest__RMouseUp                                       0x510B40
#define CEverQuest__SetGameState                                   0x4F1ED0
#define CEverQuest__Emote                                          0x4F7EC0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x61DF30
#define CGaugeWnd__CalcLinesFillRect                               0x61DF90
#define CGaugeWnd__Draw                                            0x61E3E0

// CGuild
#define CGuild__FindMemberByName                                   0x41CDB0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x638500

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x6428F0
#define CInvSlotMgr__MoveItem                                      0x6435A0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x641F70
#define CInvSlot__SliderComplete                                   0x640260
#define CInvSlot__GetItemBase                                      0x63F910

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x644300

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6F0200
#define CItemDisplayWnd__UpdateStrings                             0x645340

// CLabel 
#define CLabel__Draw                                               0x659920

// CListWnd 
#define CListWnd__AddColumn                                        0x7B9610
#define CListWnd__AddColumn1                                       0x7B8C70
#define CListWnd__AddLine                                          0x7B8820
#define CListWnd__AddString                                        0x7B89C0
#define CListWnd__CalculateFirstVisibleLine                        0x7B4A90
#define CListWnd__CalculateVSBRange                                0x7B6E90
#define CListWnd__ClearAllSel                                      0x7B3F90
#define CListWnd__CloseAndUpdateEditWindow                         0x7B7E90
#define CListWnd__Compare                                          0x7B5530
#define CListWnd__Draw                                             0x7B6AD0
#define CListWnd__DrawColumnSeparators                             0x7B6960
#define CListWnd__DrawHeader                                       0x7B4270
#define CListWnd__DrawItem                                         0x7B5F30
#define CListWnd__DrawLine                                         0x7B6620
#define CListWnd__DrawSeparator                                    0x7B6A00
#define CListWnd__EnsureVisible                                    0x7B4BF0
#define CListWnd__ExtendSel                                        0x7B5E50
#define CListWnd__GetColumnMinWidth                                0x7B3C60
#define CListWnd__GetColumnWidth                                   0x7B3BA0
#define CListWnd__GetCurSel                                        0x7B3360
#define CListWnd__GetHeaderRect                                    0x7B34C0
#define CListWnd__GetItemAtPoint                                   0x7B4EC0
#define CListWnd__GetItemAtPoint1                                  0x7B4F30
#define CListWnd__GetItemData                                      0x7B37A0
#define CListWnd__GetItemHeight                                    0x7B4700
#define CListWnd__GetItemIcon                                      0x7B3980
#define CListWnd__GetItemRect                                      0x7B4CC0
#define CListWnd__GetItemText                                      0x7B3830
#define CListWnd__GetSelList                                       0x7B8B50
#define CListWnd__GetSeparatorRect                                 0x7B5480
#define CListWnd__RemoveLine                                       0x7B95C0
#define CListWnd__SetColors                                        0x7B3430
#define CListWnd__SetColumnJustification                           0x7B3E00
#define CListWnd__SetColumnWidth                                   0x7B3C20
#define CListWnd__SetCurSel                                        0x7B33A0
#define CListWnd__SetItemColor                                     0x7B7B40
#define CListWnd__SetItemData                                      0x7B4030
#define CListWnd__SetItemText                                      0x7B7970
#define CListWnd__ShiftColumnSeparator                             0x7B77E0
#define CListWnd__Sort                                             0x7B9D50
#define CListWnd__ToggleSel                                        0x7B3F00

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x6723D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x68D7F0
#define CMerchantWnd__RequestBuyItem                               0x693940
#define CMerchantWnd__RequestSellItem                              0x6B4FF0
#define CMerchantWnd__SelectBuySellSlot                            0x68DAA0

// CObfuscator
#define CObfuscator__doit                                          0x73B040

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7D5CB0
#define CSidlManager__CreateLabel                                  0x6E88F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5D9B60
#define CSidlScreenWnd__CalculateVSBRange                          0x5D9A80
#define CSidlScreenWnd__ConvertToRes                               0x7E4380
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7C6240
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7C7480
#define CSidlScreenWnd__CSidlScreenWnd2                            0x7C7530
#define CSidlScreenWnd__dCSidlScreenWnd                            0x7C6C10
#define CSidlScreenWnd__DrawSidlPiece                              0x7C5CE0
#define CSidlScreenWnd__EnableIniStorage                           0x7C54A0
#define CSidlScreenWnd__GetSidlPiece                               0x7C5F00
#define CSidlScreenWnd__Init1                                      0x7C72D0
#define CSidlScreenWnd__LoadIniInfo                                0x7C6300
#define CSidlScreenWnd__LoadIniListWnd                             0x7C55F0
#define CSidlScreenWnd__LoadSidlScreen                             0x7C6E70
#define CSidlScreenWnd__StoreIniInfo                               0x7C5070
#define CSidlScreenWnd__StoreIniVis                                0x7C5430
#define CSidlScreenWnd__WndNotification                            0x7C70C0
#define CSidlScreenWnd__GetChildItem                               0x7C5500

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x580D20
#define CSkillMgr__GetSkillCap                                     0x580D90

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x535950
#define CSliderWnd__SetValue                                       0x7EC670
#define CSliderWnd__SetNumTicks                                    0x7ECC20

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6EDE80

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7E1920
#define CStmlWnd__CalculateHSBRange                                0x7D8EC0
#define CStmlWnd__CalculateVSBRange                                0x7D8F50
#define CStmlWnd__CanBreakAtCharacter                              0x7D90C0
#define CStmlWnd__FastForwardToEndOfTag                            0x7D9DD0
#define CStmlWnd__ForceParseNow                                    0x7E1F10
#define CStmlWnd__GetNextTagPiece                                  0x7D9CF0
#define CStmlWnd__GetSTMLText                                      0x605C40
#define CStmlWnd__GetThisChar                                      0x80CB80
#define CStmlWnd__GetVisiableText                                  0x7DB230
#define CStmlWnd__InitializeWindowVariables                        0x7DD820
#define CStmlWnd__MakeStmlColorTag                                 0x7D7DE0
#define CStmlWnd__MakeWndNotificationTag                           0x7D7E80
#define CStmlWnd__SetSTMLText                                      0x7DD950
#define CStmlWnd__StripFirstSTMLLines                              0x7E15C0
#define CStmlWnd__UpdateHistoryString                              0x7DBAD0

// CTabWnd 
#define CTabWnd__Draw                                              0x7E8160
#define CTabWnd__DrawCurrentPage                                   0x7E79E0
#define CTabWnd__DrawTab                                           0x7E77B0
#define CTabWnd__GetCurrentPage                                    0x7E7DA0
#define CTabWnd__GetPageClientRect                                 0x7E7460
#define CTabWnd__GetPageFromTabIndex                               0x7E76E0
#define CTabWnd__GetPageInnerRect                                  0x7E74C0
#define CTabWnd__GetTabInnerRect                                   0x7E7660
#define CTabWnd__GetTabRect                                        0x7E7550
#define CTabWnd__InsertPage                                        0x7E83F0
#define CTabWnd__SetPage                                           0x7E7DE0
#define CTabWnd__SetPageRect                                       0x7E8090
#define CTabWnd__UpdatePage                                        0x7E8370

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x419310

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7C78B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7E5610

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x7B21F0

// CXRect 
#define CXRect__CenterPoint                                        0x5228C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x52E100
#define CXStr__CXStr1                                              0x69C300
#define CXStr__CXStr3                                              0x8111A0
#define CXStr__dCXStr                                              0x7D9360
#define CXStr__operator_equal                                      0x811310
#define CXStr__operator_equal1                                     0x811360
#define CXStr__operator_plus_equal1                                0x812470

// CXWnd 
#define CXWnd__BringToTop                                          0x7BCBB0
#define CXWnd__Center                                              0x7C2570
#define CXWnd__ClrFocus                                            0x7BC9F0
#define CXWnd__DoAllDrawing                                        0x7C2400
#define CXWnd__DrawChildren                                        0x7C2540
#define CXWnd__DrawColoredRect                                     0x7BCED0
#define CXWnd__DrawTooltip                                         0x7BD0C0
#define CXWnd__DrawTooltipAtPoint                                  0x7C1670
#define CXWnd__GetBorderFrame                                      0x7BD4E0
#define CXWnd__GetChildWndAt                                       0x7C0860
#define CXWnd__GetClientClipRect                                   0x7BD260
#define CXWnd__GetScreenClipRect                                   0x7C1BA0
#define CXWnd__GetScreenRect                                       0x7BD610
#define CXWnd__GetTooltipRect                                      0x7BCFE0
#define CXWnd__GetWindowTextA                                      0x522440
#define CXWnd__IsActive                                            0x7C89F0
#define CXWnd__IsDescendantOf                                      0x7BD3D0
#define CXWnd__IsReallyVisible                                     0x7C0840
#define CXWnd__IsType                                              0x7E99B0
#define CXWnd__Move                                                0x7BFFB0
#define CXWnd__Move1                                               0x7C20D0
#define CXWnd__ProcessTransition                                   0x7BCB60
#define CXWnd__Refade                                              0x7BCAF0
#define CXWnd__Resize                                              0x7BD6E0
#define CXWnd__Right                                               0x7C1AB0
#define CXWnd__SetFocus                                            0x7BF120
#define CXWnd__SetKeyTooltip                                       0x7BD940
#define CXWnd__SetMouseOver                                        0x7C1EC0
#define CXWnd__StartFade                                           0x7BCBF0
#define CXWnd__GetChildItem                                        0x7C1E00

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x7C9F50
#define CXWndManager__DrawWindows                                  0x7C9BD0
#define CXWndManager__GetKeyboardFlags                             0x7C8640
#define CXWndManager__HandleKeyboardMsg                            0x7C8CC0
#define CXWndManager__RemoveWnd                                    0x7C8B10

// CDBStr
#define CDBStr__GetString                                          0x470E00

// EQ_Character 
#define EQ_Character__CastRay                                      0x754CA0
#define EQ_Character__CastSpell                                    0x433000
#define EQ_Character__Cur_HP                                       0x43C7D0
#define EQ_Character__GetAACastingTimeModifier                     0x427C80
#define EQ_Character__GetCharInfo2                                 0x753120
#define EQ_Character__GetFocusCastingTimeModifier                  0x422A60
#define EQ_Character__GetFocusRangeModifier                        0x422C30
#define EQ_Character__Max_Endurance                                0x54E4E0
#define EQ_Character__Max_HP                                       0x437040
#define EQ_Character__Max_Mana                                     0x54E2E0
#define EQ_Character__doCombatAbility                              0x54D0D0
#define EQ_Character__UseSkill                                     0x44C2B0
#define EQ_Character__GetConLevel                                  0x546630
#define EQ_Character__IsExpansionFlag                              0x40DCF0
#define EQ_Character__TotalEffect                                  0x42C460

// EQ_Item 
#define EQ_Item__CanDrop                                           0x527F50
#define EQ_Item__CreateItemTagString                               0x7391A0
#define EQ_Item__IsStackable                                       0x72E430

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x48A930
#define EQ_LoadingS__Array                                         0x9C48D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x551DA0
#define EQ_PC__GetAltAbilityIndex                                  0x744570
#define EQ_PC__GetCombatAbility                                    0x744600
#define EQ_PC__GetCombatAbilityTimer                               0x7446B0
#define EQ_PC__GetItemTimerValue                                   0x54CE40
#define EQ_PC__HasLoreItem                                         0x54B920

// EQItemList 
#define EQItemList__EQItemList                                     0x4BA630
#define EQItemList__add_item                                       0x4BA5C0
#define EQItemList__delete_item                                    0x4BA9E0
#define EQItemList__FreeItemList                                   0x4BA910

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x4703C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x556EA0
#define EQPlayer__dEQPlayer                                        0x55BA80
#define EQPlayer__DoAttack                                         0x56D1E0
#define EQPlayer__EQPlayer                                         0x5615C0
#define EQPlayer__SetNameSpriteState                               0x559370
#define EQPlayer__SetNameSpriteTint                                0x556F10
#define EQPlayer__IsBodyType_j                                     0x754540
#define EQPlayer__IsTargetable                                     0x754810

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x562980
#define EQPlayerManager__GetSpawnByName                            0x562C10

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x52DA70
#define KeypressHandler__AttachKeyToEqCommand                      0x52DAB0
#define KeypressHandler__ClearCommandStateArray                    0x52D880
#define KeypressHandler__HandleKeyDown                             0x52C220
#define KeypressHandler__HandleKeyUp                               0x52C530
#define KeypressHandler__SaveKeymapping                            0x52D950

// MapViewMap 
#define MapViewMap__Clear                                          0x66B620
#define MapViewMap__SaveEx                                         0x66ECD0

#define PlayerPointManager__GetAltCurrency                         0x73EB30

// StringTable 
#define StringTable__getString                                     0x73B2C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x550670