#ifdef PRIVATE
#include "eqgame-private.h"
#endif

#define pinstCContextMenuManager                        0x0078FD08
#define pinstCCursorAttachment                          0x006084EC
#define pinstCSocialEditWnd                             0x00608530
#define pinstCInvSlotMgr                                0x00608570
#define pinstCContainerMgr                              0x00608574
#define pinstCChatManager                               0x00784728
#define pinstCConfirmationDialog                        0x00608474
#define pinstCFacePick                                  0x0060847C
#define pinstCItemDisplayMgr                            0x007849AC
#define pinstCSpellDisplayMgr                           0x00784B38
#define pinstCNoteWnd                                   0x00608480
#define pinstCHelpWnd                                   0x00608484
#define pinstCTipWndOFDAY                               0x00785408
#define pinstCTipWndCONTEXT                             0x0078540C
#define pinstCBookWnd                                   0x00608488
#define pinstCFriendsWnd                                0x0060849C
#define pinstCMusicPlayerWnd                            0x006084B0
#define pinstCAlarmWnd                                  0x006084AC
#define pinstCLoadskinWnd                               0x006084A8
#define pinstCPetInfoWnd                                0x0060848C
#define pinstCTrainWnd                                  0x00608490
#define pinstCSkillsWnd                                 0x00608494
#define pinstCSkillsSelectWnd                           0x00608498
#define pinstCAAWnd                                     0x006084A0
#define pinstCGroupWnd                                  0x007848EC
#define pinstCJournalNPCWnd                             0x007853B4
#define pinstCGroupSearchWnd                            0x007848D4
#define pinstCGroupSearchFiltersWnd                     0x006084A4
#define pinstCRaidWnd                                   0x006084B4
#define pinstCRaidOptionsWnd                            0x006084B8
#define pinstCBreathWnd                                 0x006084BC
#define pinstCMapToolbarWnd                             0x006084C4
#define pinstCMapViewWnd                                0x006084C0
#define pinstCEditLabelWnd                              0x006084C8
#define pinstCOptionsWnd                                0x006084DC
#define pinstCBuffWindowSHORT                           0x006084E0
#define pinstCBuffWindowNORMAL                          0x006084E4
#define pinstCTargetWnd                                 0x006084CC
#define pinstCColorPickerWnd                            0x006084D4
#define pinstCHotButtonWnd                              0x006084D0
#define pinstCPlayerWnd                                 0x006084D8
#define pinstCCastingWnd                                0x006084F0
#define pinstCCastSpellWnd                              0x006084F4
#define pinstCSpellBookWnd                              0x006084F8
#define pinstCInventoryWnd                              0x006084FC
#define pinstCBankWnd                                   0x00608500
#define pinstCQuantityWnd                               0x00608504
#define pinstCTextEntryWnd                              0x00608540
#define pinstCFileSelectionWnd                          0x00608544
#define pinstCLootWnd                                   0x00608508
#define pinstCActionsWnd                                0x0060850C
#define pinstCMerchantWnd                               0x00608510
#define pinstCTradeWnd                                  0x00608514
#define pinstCBazaarWnd                                 0x0060851C
#define pinstCBazaarSearchWnd                           0x00608520
#define pinstCGiveWnd                                   0x00608524
#define pinstCSelectorWnd                               0x00608518
#define pinstCTrackingWnd                               0x00608528
#define pinstCInspectWnd                                0x0060852C
#define pinstCFeedbackWnd                               0x00608534
#define pinstCBugReportWnd                              0x00608538
#define pinstCVideoModesWnd                             0x0060853C
#define pinstCCompassWnd                                0x00608548
#define pinstCPlayerNotesWnd                            0x0060854C
#define pinstCGemsGameWnd                               0x00608550
#define pinstCStoryWnd                                  0x00608560
#define pinstCFindLocationWnd                           0x00784858
#define pinstCAdventureRequestWnd                       0x007844C0
#define pinstCAdventureStatsWnd                         0x007844D8
#define pinstCAdventureLeaderboardWnd                   0x00784490
#define pinstCBodyTintWnd                               0x0060856C
#define pinstCGuildMgmtWnd                              0x00784904
#define pinstCJournalTextWnd                            0x00608564
#define pinstCJournalCatWnd                             0x00608568
#define pinstCPetitionQWnd                              0x00608558
#define pinstCSoulmarkWnd                               0x0060855C
#define pinstCTimeLeftWnd                               0x00608554



#define pinstCDisplay               0x0071E8E4
#define pinstCEverQuest               0x0077BE30   // UNCHANGED !?
#define pinstPCData               0x0071E8C0
#define pinstCharData               0x0071E8C0
#define pinstCharSpawn                        0x0071E8B8
#define pinstSpawnList               0x0071E880
#define pinstSpawnListTail            0x0071E8A4
#define pinstWorldData               0x0071E87C
#define pinstSpellManager            0x0077888C
#define pinstActiveMerchant                   0x0071E8D0
#define pinstSelectedItem            0x00784980
#define pinstGroup               0x0071CF50
#define pinstTarget               0x0071E8C4
#define pinstSwitchManager            0x006BB5AC
#define pinstEQItemList                0x0071E884
#define pinstSpellSets               0x0071BB98

#define instEQZoneInfo               0x006BB82C
#define DrawNetStatus               0x004A9FAF

// CEverQuest
#define CEverQuest__dsp_chat            0x00495480
#define CEverQuest__ClickedPlayer         0x00490D6B
#define CEverQuest__EnterZone            0x00496252
#define CEverQuest__InterpretCmd         0x0049FFDB
#define CEverQuest__RightClickedOnPlayer      0x0049BF5A
#define   CEverQuest__LeftClickedOnPlayer         0x004A203F
#define   CEverQuest__GetRaceDesc            0x0048AEFD
#define   CEverQuest__GetClassDesc         0x0048A6B3
#define CEverQuest__GetDeityDesc         0x0048C57B
#define CEverQuest__GetBodyTypeDesc         0x0048ABF5
#define CEverQuest__SetGameState         0x00490ED2

// EQ_Character
#define EQ_Character__Max_Mana            0x0041AA79
#define EQ_Character__Max_HP            0x0041A910
#define EQ_Character__Cur_HP                         0x0041E5E1
#define EQ_Character__GetFocusCastingTimeModifier    0x00425736
#define EQ_Character__GetAACastingTimeModifier      0x00425AA2
#define EQ_Character__CastSpell            0x00429781

// CXStr
#define CXStr__CXStr               0x0040104C
#define CXStr__CXStr1               0x00401046
#define CXStr__CXStr3               0x00587490
#define CXStr__dCXStr               0x004C4B45
#define CXStr__operator_plus_equal1         0x00588520
#define   CXStr__operator_equal1            0x00587650

// CStmlWnd
#define CStmlWnd__AppendSTML            0x0055F860

// CChatWindow
#define CChatWindow__CChatWindow         0x004D7E43
#define CChatWindow__dCChatWindow         0x004D862D

// CChatManager
#define CChatManager__InitContextMenu         0x004D536B
#define CChatManager__GetRGBAFromIndex         0x004D4A33


// CItemDisplayWnd
#define CItemDisplayWnd__SetItem         0x004F325B

// CLabel
#define CLabel__Draw               0x004F906E

// CDisplay
#define CDisplay__CleanGameUI            0x0040FC96
#define CDisplay__GetClickedActor         0x0040BB72
#define CDisplay__WriteTextHD2            0x004105CC
#define EQ_Item__GetItemLinkHash         0x0042EDDC

// CBankWnd
#define CBankWnd__GetNumBankSlots         0x004C4CCE

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg   0x004C726E

// CMerchantWnd
#define CMerchantWnd__SelectBuySellSlot         0x00500262
#define CMerchantWnd__RequestBuyItem         0x004FFB7D
#define CMerchantWnd__RequestSellItem         0x004FFD76

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet         0x0051096D

// MapViewMap
#define MapViewMap__SaveEx            0x004FB09D
#define EQ_PC__DestroyHeldItemOrMoney         0x00431D74
