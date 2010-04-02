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
#define __ExpectedVersionDate                                     "May 21 2008"
#define __ExpectedVersionTime                                     "16:59:02"
#define __ActualVersionDate                                        0x71B344
#define __ActualVersionTime                                        0x71B350

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FB580
#define __MemChecker1                                              0x665A40
#define __MemChecker2                                              0x530570
#define __MemChecker3                                              0x5304C0
#define __MemChecker4                                              0x629F50
#define __EncryptPad0                                              0x776120
#define __EncryptPad1                                              0x77FEB8
#define __EncryptPad2                                              0x778A98
#define __EncryptPad3                                              0x778698
#define __EncryptPad4                                              0x77F598

// Direct Input
#define DI8__Main                                                  0x9BE4F4
#define DI8__Keyboard                                              0x9BE4F8
#define DI8__Mouse                                                 0x9BE4FC
#define __AltTimerReady                                            0x94B272
#define __Attack                                                   0x9A8BB6
#define __Autofire                                                 0x9A8BB7
#define __BindList                                                 0x7712C8
#define __Clicks                                                   0x949F90
#define __CommandList                                              0x771AD8
#define __CurrentMapLabel                                          0x9E9710
#define __CurrentSocial                                            0x76D544
#define __DoAbilityAvailable                                       0x94B20C
#define __DoAbilityList                                            0x9806D4
#define __do_loot                                                  0x4A5490
#define __DrawHandler                                              0x9F89FC
#define __GroupCount                                               0x92A4A2
#define __GroupLeader                                              0x92A7F4
#define __Guilds                                                   0x92C1C0
#define __gWorld                                                   0x92C0FC
#define __HotkeyPage                                               0x9A7AC0
#define __HWnd                                                     0x9BE234
#define __InChatMode                                               0x949EC8
#define __LastTell                                                 0x94BB6C
#define __LMouseHeldTime                                           0x949FB0
#define __Mouse                                                    0x9BE500
#define __MouseLook                                                0x949F5E
#define __NetStatusToggle                                          0x949F60
#define __PCNames                                                  0x94B5C4
#define __RangeAttackReady                                         0x94B270
#define __RMouseHeldTime                                           0x949FAC
#define __RunWalkState                                             0x949ECC
#define __ScreenMode                                               0x879DD0
#define __ScreenX                                                  0x949E80
#define __ScreenY                                                  0x949E84
#define __ScreenXMax                                               0x949E88
#define __ScreenYMax                                               0x949E8C
#define __ServerHost                                               0x92A3EC
#define __ServerName                                               0x980694
#define __ShiftKeyDown                                             0x94A528
#define __ShowNames                                                0x94B49C
#define __Socials                                                  0x980794


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x943E10
#define instEQZoneInfo                                             0x94A0FC
#define instKeypressHandler                                        0x9A8CA0
#define pinstActiveBanker                                          0x92C194
#define pinstActiveCorpse                                          0x92C198
#define pinstActiveGMaster                                         0x92C19C
#define pinstActiveMerchant                                        0x92C190
#define pinstAltAdvManager                                         0x87AC20
#define pinstAuraMgr                                               0x785C6C
#define pinstBandageTarget                                         0x92C17C
#define pinstCamActor                                              0x87A710
#define pinstCDBStr                                                0x879DC0
#define pinstCDisplay                                              0x92C1A4
#define pinstCEverQuest                                            0x9BE678
#define pinstCharData                                              0x92C160
#define pinstCharSpawn                                             0x92C188
#define pinstControlledMissile                                     0x92C15C
#define pinstControlledPlayer                                      0x92C188
#define pinstCSidlManager                                          0x9F81C8
#define pinstCXWndManager                                          0x9F81C0
#define instDynamicZone                                            0x9498D0
#define pinstDZMember                                              0x9499E0
#define pinstDZTimerInfo                                           0x9499E4
#define pinstEQItemList                                            0x92C144
#define instEQMisc                                                 0x879D78
#define pinstEQSoundManager                                        0x87AC44
#define instExpeditionLeader                                       0x94991A
#define instExpeditionName                                         0x94995A
#define instGroup                                                  0x92A698
#define pinstGroup                                                 0x92A49E
#define pinstImeManager                                            0x9F81CC
#define pinstLocalPlayer                                           0x92C174
#define pinstModelPlayer                                           0x92C1A0
#define pinstPCData                                                0x92C160
#define pinstSkillMgr                                              0x9BB464
#define pinstSpawnManager                                          0x9BB3E4
#define pinstSpellManager                                          0x9BB468
#define pinstSpellSets                                             0x9A7AC4
#define pinstStringTable                                           0x92C118
#define pinstSwitchManager                                         0x92A0EC
#define pinstTarget                                                0x92C18C
#define pinstTargetObject                                          0x92C164
#define pinstTargetSwitch                                          0x92C168
#define pinstTaskMember                                            0x879D58
#define pinstTrackTarget                                           0x92C180
#define pinstTradeTarget                                           0x92C170
#define instTributeActive                                          0x879D9D
#define pinstViewActor                                             0x87A70C
#define pinstWorldData                                             0x92C140


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x783520
#define pinstCAudioTriggersWindow                                  0x7834EC
#define pinstCCharacterSelect                                      0x87A620
#define pinstCFacePick                                             0x87A5D8
#define pinstCNoteWnd                                              0x87A5DC
#define pinstCBookWnd                                              0x87A5E0
#define pinstCPetInfoWnd                                           0x87A5E4
#define pinstCTrainWnd                                             0x87A5E8
#define pinstCSkillsWnd                                            0x87A5EC
#define pinstCSkillsSelectWnd                                      0x87A5F0
#define pinstCCombatSkillSelectWnd                                 0x87A5F4
#define pinstCFriendsWnd                                           0x87A5F8
#define pinstCAuraWnd                                              0x87A5FC
#define pinstCRespawnWnd                                           0x87A600
#define pinstCBandolierWnd                                         0x87A604
#define pinstCPotionBeltWnd                                        0x87A608
#define pinstCAAWnd                                                0x87A60C
#define pinstCGroupSearchFiltersWnd                                0x87A610
#define pinstCLoadskinWnd                                          0x87A614
#define pinstCAlarmWnd                                             0x87A618
#define pinstCMusicPlayerWnd                                       0x87A61C
#define pinstCMailWnd                                              0x87A624
#define pinstCMailCompositionWnd                                   0x87A628
#define pinstCMailAddressBookWnd                                   0x87A62C
#define pinstCRaidWnd                                              0x87A634
#define pinstCRaidOptionsWnd                                       0x87A638
#define pinstCBreathWnd                                            0x87A63C
#define pinstCMapViewWnd                                           0x87A640
#define pinstCMapToolbarWnd                                        0x87A644
#define pinstCEditLabelWnd                                         0x87A648
#define pinstCTargetWnd                                            0x87A64C
#define pinstCColorPickerWnd                                       0x87A650
#define pinstCPlayerWnd                                            0x87A654
#define pinstCOptionsWnd                                           0x87A658
#define pinstCBuffWindowNORMAL                                     0x87A65C
#define pinstCBuffWindowSHORT                                      0x87A660
#define pinstCharacterCreation                                     0x87A664
#define pinstCCursorAttachment                                     0x87A668
#define pinstCCastingWnd                                           0x87A66C
#define pinstCCastSpellWnd                                         0x87A670
#define pinstCSpellBookWnd                                         0x87A674
#define pinstCInventoryWnd                                         0x87A678
#define pinstCBankWnd                                              0x87A67C
#define pinstCQuantityWnd                                          0x87A680
#define pinstCLootWnd                                              0x87A684
#define pinstCActionsWnd                                           0x87A688
#define pinstCCombatAbilityWnd                                     0x87A68C
#define pinstCMerchantWnd                                          0x87A690
#define pinstCTradeWnd                                             0x87A694
#define pinstCSelectorWnd                                          0x87A698
#define pinstCBazaarWnd                                            0x87A69C
#define pinstCBazaarSearchWnd                                      0x87A6A0
#define pinstCGiveWnd                                              0x87A6A4
#define pinstCTrackingWnd                                          0x87A6A8
#define pinstCInspectWnd                                           0x87A6AC
#define pinstCSocialEditWnd                                        0x87A6B0
#define pinstCFeedbackWnd                                          0x87A6B4
#define pinstCBugReportWnd                                         0x87A6B8
#define pinstCVideoModesWnd                                        0x87A6BC
#define pinstCTextEntryWnd                                         0x87A6C4
#define pinstCFileSelectionWnd                                     0x87A6C8
#define pinstCCompassWnd                                           0x87A6CC
#define pinstCPlayerNotesWnd                                       0x87A6D0
#define pinstCGemsGameWnd                                          0x87A6D4
#define pinstCTimeLeftWnd                                          0x87A6D8
#define pinstCPetitionQWnd                                         0x87A6DC
#define pinstCSoulmarkWnd                                          0x87A6E0
#define pinstCStoryWnd                                             0x87A6E4
#define pinstCJournalTextWnd                                       0x87A6E8
#define pinstCJournalCatWnd                                        0x87A6EC
#define pinstCBodyTintWnd                                          0x87A6F0
#define pinstCServerListWnd                                        0x87A6F4
#define pinstCAvaZoneWnd                                           0x87A6F8
#define pinstCBlockedBuffWnd                                       0x87A6FC
#define pinstCBlockedPetBuffWnd                                    0x87A700
#define pinstCInvSlotMgr                                           0x87A704
#define pinstCContainerMgr                                         0x87A708
#define pinstCAdventureLeaderboardWnd                              0x9E6C60
#define pinstCAdventureRequestWnd                                  0x9E6C7C
#define pinstCAltStorageWnd                                        0x9E6CDC
#define pinstCAdventureStatsWnd                                    0x9E6C98
#define pinstCBarterMerchantWnd                                    0x9E6EA8
#define pinstCBarterSearchWnd                                      0x9E6EC4
#define pinstCBarterWnd                                            0x9E6EE0
#define pinstCChatManager                                          0x9E7184
#define pinstCDynamicZoneWnd                                       0x9E727C
#define pinstCEQMainWnd                                            0x9E72EC
#define pinstCFellowshipWnd                                        0x9E7350
#define pinstCFindLocationWnd                                      0x9E7384
#define pinstCGroupSearchWnd                                       0x9E7434
#define pinstCGroupWnd                                             0x9E7450
#define pinstCGuildBankWnd                                         0x9E746C
#define pinstCGuildMgmtWnd                                         0x9E9488
#define pinstCGuildTributeMasterWnd                                0x9E94A8
#define pinstCHotButtonWnd                                         0x9E94C4
#define pinstCHotButtonWnd1                                        0x9E94C4
#define pinstCHotButtonWnd2                                        0x9E94C8
#define pinstCHotButtonWnd3                                        0x9E94CC
#define pinstCHotButtonWnd4                                        0x9E94D0
#define pinstCItemDisplayManager                                   0x9E957C
#define pinstCItemExpTransferWnd                                   0x9E959C
#define pinstCLeadershipWnd                                        0x9E9638
#define pinstCLFGuildWnd                                           0x9E9654
#define pinstCMIZoneSelectWnd                                      0x9E9778
#define pinstCAdventureMerchantWnd                                 0x9E9870
#define pinstCConfirmationDialog                                   0x9E988C
#define pinstCPopupWndManager                                      0x9E988C
#define pinstCProgressionSelectionWnd                              0x9E98C0
#define pinstCPvPLeaderboardWnd                                    0x9E98DC
#define pinstCPvPStatsWnd                                          0x9E98F8
#define pinstCSystemInfoDialogBox                                  0x9E99A8
#define pinstCTargetOfTargetWnd                                    0x9EA29C
#define pinstCTaskSelectWnd                                        0x9EA2B8
#define pinstCTaskTemplateSelectWnd                                0x9EA2D4
#define pinstCTaskWnd                                              0x9EA2F0
#define pinstCTipWndOFDAY                                          0x9EA36C
#define pinstCTipWndCONTEXT                                        0x9EA370
#define pinstCTitleWnd                                             0x9EA38C
#define pinstCTradeskillWnd                                        0x9EA3D0
#define pinstCTributeBenefitWnd                                    0x9EA41C
#define pinstCTributeMasterWnd                                     0x9EA438
#define pinstCContextMenuManager                                   0x9F8224
#define pinstCVoiceMacroWnd                                        0x9BB554
#define pinstCHtmlWnd                                              0x9BB570


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4B7530
#define __ConvertItemTags                                          0x4AA800
#define __ExecuteCmd                                               0x499D30
#define __get_melee_range                                          0x49EF00
#define __GetGaugeValueFromEQ                                      0x5FB7D0
#define __GetLabelFromEQ                                           0x5FBFE0
#define __NewUIINI                                                 0x5FB3C0
#define __ProcessGameEvents                                        0x4E6820
#define CrashDetected                                              0x52F240
#define DrawNetStatus                                              0x4FE330
#define Util__FastTime                                             0x666190


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x473980
#define AltAdvManager__IsAbilityReady                              0x4739C0
#define AltAdvManager__GetAltAbility                               0x473BD0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x546790

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x54FEE0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x691950

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x564BE0
#define CChatManager__InitContextMenu                              0x565370

// CChatService
#define CChatService__GetNumberOfFriends                           0x656390
#define CChatService__GetFriendName                                0x6563A0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5694E0
#define CChatWindow__WndNotification                               0x569ED0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x677D50
#define CComboWnd__Draw                                            0x677F00
#define CComboWnd__GetCurChoice                                    0x677CF0
#define CComboWnd__GetListRect                                     0x6781C0
#define CComboWnd__GetTextRect                                     0x677D80
#define CComboWnd__InsertChoice                                    0x678230
#define CComboWnd__SetColors                                       0x677C80
#define CComboWnd__SetChoice                                       0x677CB0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x570850
#define CContainerWnd__vftable                                     0x721C78

// CDisplay 
#define CDisplay__CleanGameUI                                      0x462B90
#define CDisplay__GetClickedActor                                  0x4602E0
#define CDisplay__GetUserDefinedColor                              0x45F460
#define CDisplay__GetWorldFilePath                                 0x45E9D0
#define CDisplay__is3dON                                           0x45DB30
#define CDisplay__ReloadUI                                         0x46E700
#define CDisplay__WriteTextHD2                                     0x463280

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5407D0
#define CEditBaseWnd__SetSel                                       0x69C920

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x685B10
#define CEditWnd__GetCharIndexPt                                   0x686970
#define CEditWnd__GetDisplayString                                 0x685CB0
#define CEditWnd__GetHorzOffset                                    0x685F40
#define CEditWnd__GetLineForPrintableChar                          0x686420
#define CEditWnd__GetSelStartPt                                    0x686BB0
#define CEditWnd__GetSTMLSafeText                                  0x6860E0
#define CEditWnd__PointFromPrintableChar                           0x686530
#define CEditWnd__SelectableCharFromPoint                          0x6866B0
#define CEditWnd__SetEditable                                      0x6860B0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4CA9D0
#define CEverQuest__DropHeldItemOnGround                           0x4CEC50
#define CEverQuest__dsp_chat                                       0x4D0130
#define CEverQuest__DoTellWindow                                   0x4CEDD0
#define CEverQuest__EnterZone                                      0x4E5200
#define CEverQuest__GetBodyTypeDesc                                0x4C7E50
#define CEverQuest__GetClassDesc                                   0x4C75B0
#define CEverQuest__GetClassThreeLetterCode                        0x4C7BB0
#define CEverQuest__GetDeityDesc                                   0x4C84C0
#define CEverQuest__GetLangDesc                                    0x4C81E0
#define CEverQuest__GetRaceDesc                                    0x4C8490
#define CEverQuest__InterpretCmd                                   0x4D0B60
#define CEverQuest__LeftClickedOnPlayer                            0x4E3A20
#define CEverQuest__LMouseUp                                       0x4E6000
#define CEverQuest__RightClickedOnPlayer                           0x4E3DF0
#define CEverQuest__RMouseUp                                       0x4E5800
#define CEverQuest__SetGameState                                   0x4CAE50
#define CEverQuest__Emote                                          0x4D0300

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x57CCC0
#define CGaugeWnd__CalcLinesFillRect                               0x57CD30
#define CGaugeWnd__Draw                                            0x57D0B0

// CGuild
#define CGuild__FindMemberByName                                   0x417DF0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x593550

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x59C990
#define CInvSlotMgr__MoveItem                                      0x59CB30

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x59B360
#define CInvSlot__SliderComplete                                   0x59B870

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5AB9B0
#define CItemDisplayWnd__SetSpell                                  0x5F9740

// CLabel 
#define CLabel__Draw                                               0x5B12B0

// CListWnd 
#define CListWnd__AddColumn                                        0x677A90
#define CListWnd__AddColumn1                                       0x6775D0
#define CListWnd__AddLine                                          0x677160
#define CListWnd__AddString                                        0x677330
#define CListWnd__CalculateFirstVisibleLine                        0x674520
#define CListWnd__CalculateVSBRange                                0x676130
#define CListWnd__ClearAllSel                                      0x673C70
#define CListWnd__CloseAndUpdateEditWindow                         0x674B20
#define CListWnd__Compare                                          0x674EB0
#define CListWnd__Draw                                             0x675E30
#define CListWnd__DrawColumnSeparators                             0x675CA0
#define CListWnd__DrawHeader                                       0x673E40
#define CListWnd__DrawItem                                         0x6755B0
#define CListWnd__DrawLine                                         0x675950
#define CListWnd__DrawSeparator                                    0x675D40
#define CListWnd__EnsureVisible                                    0x674570
#define CListWnd__ExtendSel                                        0x6754E0
#define CListWnd__GetColumnMinWidth                                0x673A10
#define CListWnd__GetColumnWidth                                   0x673950
#define CListWnd__GetCurSel                                        0x673400
#define CListWnd__GetHeaderRect                                    0x673520
#define CListWnd__GetItemAtPoint                                   0x674840
#define CListWnd__GetItemAtPoint1                                  0x6748B0
#define CListWnd__GetItemData                                      0x673700
#define CListWnd__GetItemHeight                                    0x6742B0
#define CListWnd__GetItemIcon                                      0x673890
#define CListWnd__GetItemRect                                      0x674630
#define CListWnd__GetItemText                                      0x673740
#define CListWnd__GetSelList                                       0x6774B0
#define CListWnd__GetSeparatorRect                                 0x674DF0
#define CListWnd__RemoveLine                                       0x677460
#define CListWnd__SetColors                                        0x673480
#define CListWnd__SetColumnJustification                           0x673A70
#define CListWnd__SetColumnWidth                                   0x6739D0
#define CListWnd__SetCurSel                                        0x673440
#define CListWnd__SetItemColor                                     0x676D30
#define CListWnd__SetItemData                                      0x673D10
#define CListWnd__SetItemText                                      0x676CB0
#define CListWnd__ShiftColumnSeparator                             0x675450
#define CListWnd__Sort                                             0x677AC0
#define CListWnd__ToggleSel                                        0x673BE0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5C5FE0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C7AC0
#define CMerchantWnd__RequestBuyItem                               0x5C8DF0
#define CMerchantWnd__RequestSellItem                              0x5C7D10
#define CMerchantWnd__SelectBuySellSlot                            0x5C8B20

// CObfuscator
#define CObfuscator__doit                                          0x6331D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x68D560
#define CSidlManager__CreateLabel                                  0x5F2D00

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5422B0
#define CSidlScreenWnd__CalculateVSBRange                          0x542200
#define CSidlScreenWnd__ConvertToRes                               0x69C800
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x67F280
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6800C0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x680170
#define CSidlScreenWnd__dCSidlScreenWnd                            0x67FB10
#define CSidlScreenWnd__DrawSidlPiece                              0x67EF60
#define CSidlScreenWnd__EnableIniStorage                           0x67E9C0
#define CSidlScreenWnd__GetSidlPiece                               0x67F160
#define CSidlScreenWnd__Init1                                      0x67FF30
#define CSidlScreenWnd__LoadIniInfo                                0x67F330
#define CSidlScreenWnd__LoadIniListWnd                             0x67EB10
#define CSidlScreenWnd__LoadSidlScreen                             0x67ED80
#define CSidlScreenWnd__StoreIniInfo                               0x67E5D0
#define CSidlScreenWnd__WndNotification                            0x67EEC0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x51FE70

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x69D510
#define CSliderWnd__SetValue                                       0x69D610
#define CSliderWnd__SetNumTicks                                    0x69DB80

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5F83E0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x69AAF0
#define CStmlWnd__CalculateVSBRange                                0x676130
#define CStmlWnd__CanBreakAtCharacter                              0x692F90
#define CStmlWnd__FastForwardToEndOfTag                            0x693AE0
#define CStmlWnd__ForceParseNow                                    0x69AF40
#define CStmlWnd__GetNextTagPiece                                  0x693A00
#define CStmlWnd__GetSTMLText                                      0x569480
#define CStmlWnd__GetThisChar                                      0x6BAF50
#define CStmlWnd__GetVisiableText                                  0x694D20
#define CStmlWnd__InitializeWindowVariables                        0x696E60
#define CStmlWnd__MakeStmlColorTag                                 0x692550
#define CStmlWnd__MakeWndNotificationTag                           0x6925F0
#define CStmlWnd__SetSTMLText                                      0x696F70
#define CStmlWnd__StripFirstSTMLLines                              0x69A880
#define CStmlWnd__UpdateHistoryString                              0x695580

// CTabWnd 
#define CTabWnd__Draw                                              0x69E980
#define CTabWnd__DrawCurrentPage                                   0x69E320
#define CTabWnd__DrawTab                                           0x69E100
#define CTabWnd__GetCurrentPage                                    0x69E620
#define CTabWnd__GetPageClientRect                                 0x69DDD0
#define CTabWnd__GetPageFromTabIndex                               0x69E030
#define CTabWnd__GetPageInnerRect                                  0x69DE30
#define CTabWnd__GetTabInnerRect                                   0x69DFB0
#define CTabWnd__GetTabRect                                        0x69DEC0
#define CTabWnd__IndexInBounds                                     0x69E0CD
#define CTabWnd__InsertPage                                        0x69EBA0
#define CTabWnd__SetPage                                           0x69E660
#define CTabWnd__SetPageRect                                       0x69E8B0
#define CTabWnd__UpdatePage                                        0x69EB20

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4142E0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6804D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6A40A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x673170

// CXRect 
#define CXRect__CenterPoint                                        0x545EF0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4F5550
#define CXStr__CXStr1                                              0x66E150
#define CXStr__CXStr3                                              0x667890
#define CXStr__dCXStr                                              0x406660
#define CXStr__operator_equal1                                     0x667A50
#define CXStr__operator_plus_equal1                                0x668950

// CXWnd 
#define CXWnd__BringToTop                                          0x678AB0
#define CXWnd__Center                                              0x67C790
#define CXWnd__ClrFocus                                            0x6787A0
#define CXWnd__DoAllDrawing                                        0x67D230
#define CXWnd__DrawChildren                                        0x67D360
#define CXWnd__DrawColoredRect                                     0x678D30
#define CXWnd__DrawTooltip                                         0x67D150
#define CXWnd__DrawTooltipAtPoint                                  0x67C560
#define CXWnd__GetBorderFrame                                      0x6791F0
#define CXWnd__GetChildWndAt                                       0x67C000
#define CXWnd__GetClientClipRect                                   0x679120
#define CXWnd__GetFirstChildWnd                                    0x678B50
#define CXWnd__GetNextChildWnd                                     0x67BFC0
#define CXWnd__GetNextSib                                          0x678B70
#define CXWnd__GetScreenClipRect                                   0x67C9B0
#define CXWnd__GetScreenRect                                       0x6793B0
#define CXWnd__GetTooltipRect                                      0x678F50
#define CXWnd__GetWindowTextA                                      0x5398A0
#define CXWnd__IsActive                                            0x6815D0
#define CXWnd__IsDescendantOf                                      0x6791A0
#define CXWnd__IsReallyVisible                                     0x67BFA0
#define CXWnd__IsType                                              0x69FA90
#define CXWnd__Move                                                0x67BA50
#define CXWnd__Move1                                               0x67BAF0
#define CXWnd__ProcessTransition                                   0x678A70
#define CXWnd__Refade                                              0x678850
#define CXWnd__Resize                                              0x679480
#define CXWnd__Right                                               0x67C8F0
#define CXWnd__SetFirstChildPointer                                0x679640
#define CXWnd__SetFocus                                            0x67AAC0
#define CXWnd__SetKeyTooltip                                       0x6796B0
#define CXWnd__SetMouseOver                                        0x679680
#define CXWnd__SetNextSibPointer                                   0x679660
#define CXWnd__StartFade                                           0x678AD0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x682A40
#define CXWndManager__DrawWindows                                  0x682680
#define CXWndManager__GetFirstChildWnd                             0x681F70
#define CXWndManager__GetKeyboardFlags                             0x681290
#define CXWndManager__HandleKeyboardMsg                            0x6817C0
#define CXWndManager__RemoveWnd                                    0x6816E0

// CDBStr
#define CDBStr__GetString                                          0x45C490

// EQ_Character 
#define EQ_Character__CastRay                                      0x6C6F40
#define EQ_Character__CastSpell                                    0x4252D0
#define EQ_Character__Cur_HP                                       0x431A60
#define EQ_Character__GetAACastingTimeModifier                     0x41FCB0
#define EQ_Character__GetCharInfo2                                 0x6487E0
#define EQ_Character__GetFocusCastingTimeModifier                  0x41B940
#define EQ_Character__GetFocusRangeModifier                        0x41BA70
#define EQ_Character__Max_Endurance                                0x42D060
#define EQ_Character__Max_HP                                       0x42CEE0
#define EQ_Character__Max_Mana                                     0x504470
#define EQ_Character__doCombatAbility                              0x503130
#define EQ_Character__UseSkill                                     0x437B50
#define EQ_Character__GetConLevel                                  0x4FF7F0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F32B0
#define EQ_Item__GetItemLinkHash                                   0x63CBB0
#define EQ_Item__IsStackable                                       0x633A80

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x474A90
#define EQ_LoadingS__Array                                         0x76F7D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x5074B0
#define EQ_PC__GetAltAbilityIndex                                  0x6414F0
#define EQ_PC__GetCombatAbility                                    0x641580
#define EQ_PC__GetCombatAbilityTimer                               0x641630
#define EQ_PC__GetItemTimerValue                                   0x502080
#define EQ_PC__HasLoreItem                                         0x505910

// EQItemList 
#define EQItemList__dEQItemList                                    0x49D610
#define EQItemList__EQItemList                                     0x49D560

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45BE00

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50BC40
#define EQPlayer__dEQPlayer                                        0x50FB40
#define EQPlayer__DoAttack                                         0x51C9A0
#define EQPlayer__EQPlayer                                         0x513770
#define EQPlayer__SetNameSpriteState                               0x50DB30
#define EQPlayer__SetNameSpriteTint                                0x50BCB0
#define EQPlayer__IsBodyType_j                                     0x6C6910

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x514800

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F4EC0
#define KeypressHandler__AttachKeyToEqCommand                      0x4F4F00
#define KeypressHandler__ClearCommandStateArray                    0x4F4CD0
#define KeypressHandler__HandleKeyDown                             0x4F38B0
#define KeypressHandler__HandleKeyUp                               0x4F3BB0
#define KeypressHandler__SaveKeymapping                            0x4F4DA0

// MapViewMap 
#define MapViewMap__Clear                                          0x5C16D0
#define MapViewMap__SaveEx                                         0x5C20A0

#define OtherCharData__GetAltCurrency                              0x65EA60

// StringTable 
#define StringTable__getString                                     0x633450
