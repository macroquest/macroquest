/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include "Common.h"
#include "Containers.h"
#include "CXStr.h"
#include "Items.h"
#include "PlayerClient.h"
#include "Spells.h"
#include "EQData.h"

// This is the home of all things related to what used to be called CHARINFO and
// CHARINFO2 plus a few extra things until they find a home of their own.
//
// Class hierarchies:
//
// CHARINFO:
//   PcClient -> PcZoneClient -> PcBase, CharacterZoneClient, [SomeOtherClass]
//   PcBase -> CharacterBase
//   CharacterZoneClient -> CharacterBase
//
// CHARINFO2
//   PcProfile -> BaseProfile

#define USE_NEW_CHARINFO       0
#define USE_NEW_PCPROFILE      0

constexpr int MAX_BLOCKED_SPELLS = 40;
constexpr int MAX_BLOCKED_SPELLS_PET = 40;

namespace eqlib {

class BaseProfile;
class CharacterBase;
class CharacterZoneClient;
class HateListEntry;
class PcBase;
class PcClient;
class PcProfile;
class PcZoneClient;
class ProfileBase;
class ProfileList;

//============================================================================
// Enums
//============================================================================

enum EAreaCorner
{
	eAC_None = -1,
	eAC_TopLeftCorner,
	eAC_TopRightCorner,
	eAC_BottomLeftCorner,
	eAC_BottomRightCorner,
};

enum ELockoutCharacterReason
{
	LCR_AllowNormalPlay,
	LCR_InvalidWornItem,
	LCR_Something,
};

enum eProfileListType
{
	ePLT_Regular,
	cPLT_MonsterMission
};

enum eXTSlotStatus
{
	eXTSlotEmpty,
	eXTSlotCurrentZone,
	eXTSlotDifferentZone,
	eXTSlotUnknown
};

enum eProfileType
{
	ePTMain,
	ePTAlt,
	ePTMonsterMission,
	ePTUnknown
};

class CharacterPropertyHash : public HashTable<int>
{
public:
};

//============================================================================
// Structs
//============================================================================

struct [[offsetcomments]] CombatAbilityTimer : public TListNode<CombatAbilityTimer>
{
/*0x0c*/ int32_t  SpellGroup;
/*0x10*/ uint32_t ExpireTimer;
/*0x14*/
};

struct [[offsetcomments]] AssociatedNPCSaveStringNode
{
/*0x0000*/ char SaveString[0x2000];              // 0x1000 in older clients
/*0x2000*/ AssociatedNPCSaveStringNode* pNext;
/*0x2004*/
};

struct [[offsetcomments]] BandolierItemInfo
{
/*0x00*/ int ItemID;
/*0x04*/ int IconID;
/*0x08*/ char Name[0x40];
/*0x48*/
};

struct [[offsetcomments]] BandolierSet
{
/*0x000*/ char Name[0x20];
/*0x020*/ BandolierItemInfo Items[MAX_BANDOLIER_SLOTS];            // 0x120 = 0x48 * 4
/*0x140*/
};

struct [[offsetcomments]] AALIST
{
/*0x00*/ DWORD AAIndex;
/*0x04*/ DWORD PointsSpent;
/*0x08*/ DWORD ChargeSpent;            // charges spent in the last 10 min?
/*0x0c*/
};
using PAALIST [[deprecated]] = AALIST;

struct [[offsetcomments]] ALCHEMYBONUSSKILLDATA
{
	FORCE_SYMBOLS;

/*0x00*/ int SkillID;
/*0x04*/ int BonusPoints;
/*0x08*/
};

struct [[offsetcomments]] BenefitSelection
{
/*0x00*/ int BenefitID;
/*0x04*/ int BenefitTier;
/*0x08*/
};

class [[offsetcomments]] ProfileList
{
public:
/*0x00*/ eProfileListType ListType;
/*0x04*/ BaseProfile* pFirst;
/*0x08*/ BaseProfile* pLast;
/*0x0c*/ ProfileList* pNext;
/*0x10*/ ProfileList* pPrev;
/*0x14*/
};

class [[offsetcomments]] CProfileManager
{
	// has no vftable
public:
/*0x00*/ ProfileList* pFirst;
/*0x04*/ eProfileListType CurProfileList;
/*0x08*/

	const ProfileList* GetCurrentProfileList() const
	{
		ProfileList* pWalk = pFirst;
		while (pWalk != nullptr)
		{
			if (pWalk->ListType == CurProfileList)
			{
				return pWalk;
			}

			pWalk = pWalk->pNext;
		}
		return nullptr;
	}

	const BaseProfile* GetCurrentProfile() const
	{
		const ProfileList* pList = GetCurrentProfileList();
		if (pList != nullptr)
		{
			return pList->pFirst;
		}
		return nullptr;
	}
};

// size 34 i think in eqgame dated mar 23 2015 but i have no address for it atm
struct [[offsetcomments]] GROUPMEMBER
{
/*0x00*/ void*  vftable;
/*0x04*/ CXStr  Name;
/*0x08*/ short  Type;
/*0x0c*/ CXStr  pOwner;                // name of mercenary's owner
/*0x10*/ DWORD  Level;
/*0x14*/ BYTE   Offline;               // 1 if groupmember is offline
/*0x15*/ BYTE   Unknown0x15[8];
/*0x1d*/ BYTE   MainTank;
/*0x1e*/ BYTE   MainAssist;
/*0x1f*/ BYTE   Puller;
/*0x20*/ BYTE   MarkNpc;
/*0x21*/ BYTE   MasterLooter;
/*0x22*/ BYTE   Unknown0x22[0x2];
/*0x24*/ DWORD  Roles;                 // (Roles & 0x1) = MainTank, 0x2 = MainAssist, 0x4 = Puller 0x8 = Mark NPC 0x10 = Master Looter
/*0x28*/ BYTE   Unknown0x28[0x8];
/*0x30*/ SPAWNINFO* pSpawn;
/*0x34*/

	// Compat wrapper for pName
	__declspec(property(get = getPName)) CXStr* pName;

	[[deprecated("Use Name instead of pName")]]
	inline CXStr* getPName() { return &Name; }

	__declspec(property(get = getMercenary)) BYTE Mercenary;

	[[deprecated("Use Type instead of Mercenary")]]
	inline BYTE getMercenary() { return (BYTE)Type; }
};
using PGROUPMEMBER [[deprecated]] = GROUPMEMBER*;


struct [[offsetcomments]] GROUPINFO
{
/*0x00*/ void* vftable;
/*0x04*/ GROUPMEMBER* pMember[MAX_GROUP_SIZE];
/*0x1c*/ GROUPMEMBER* pLeader;
/*0x20*/
};
using PGROUPINFO [[deprecated]] = GROUPINFO*;


// size 0x4c 12-25-09 - ieatacid
struct [[offsetcomments]] XTARGETSLOT
{
/*0x00*/ DWORD  xTargetType;
/*0x04*/ eXTSlotStatus  XTargetSlotStatus;
/*0x08*/ uint32_t SpawnID;
/*0x0c*/ char   Name[0x40];
/*0x4c*/
};
using PXTARGETSLOT = XTARGETSLOT*;

constexpr int MAX_EXTENDED_TARGETS = 23;

class [[offsetcomments]] ExtendedTargetList
{
public:
/*0x00*/ void*                      vftable;
/*0x04*/ ArrayClass<XTARGETSLOT>    XTargetSlots;     // max is 23
/*0x14*/ bool                       bAutoAddHaters;
/*0x18*/
};

class [[offsetcomments]] ExtendedTargetListClient : public ExtendedTargetList
{
	FORCE_SYMBOLS;

public:
/*0x18*/ int CurrentSlot;
/*0x1c*/ int ContextSlot;
/*0x20*/
};

struct [[offsetcomments]] MailItemData
{
/*0x00*/ UINT   SendTime;
/*0x04*/ CXStr  SenderName;
/*0x08*/ CXStr  Note;
/*0x0c*/
};

struct [[offsetcomments]] PCAdventureThemeStats
{
/*0x00*/ int SucceededNormal;
/*0x04*/ int FailedNormal;
/*0x08*/ int SucceededHard;
/*0x0c*/ int FailedHard;
/*0x10*/ int AdventureTotalPointsEarned;
/*0x14*/
};

struct [[offsetcomments]] PCAdventureData
{
/*0x00*/ int AdventureLastAdventureDefinitionSeen[5];
/*0x14*/ UINT AdventureLastAdventureDefinitionSeenTime[5];
/*0x28*/ int AdventureActiveAdventureId;
/*0x2c*/ int AdventureActiveAdventureTheme;
/*0x30*/ int AdventureActiveAdventureRisk;
/*0x34*/ int AdventureSafeReturnZoneId;
/*0x38*/ float AdventureSafeReturnX;
/*0x3c*/ float AdventureSafeReturnY;
/*0x40*/ float AdventureSafeReturnZ;
/*0x44*/ int AdventureStatAccepted;
/*0x48*/ int AdventureStatRejected;
/*0x4c*/ int AdventureStatEntered;
/*0x50*/ int AdventureStatFailedEnter;
/*0x54*/ int AdventurePointsAvailable;
/*0x58*/ int AdventurePointsAvailableMax;
/*0x5c*/ UINT AdventureLastSuccessTime;
/*0x60*/ PCAdventureThemeStats ThemeStats[6];
/*0xd8*/
};

struct [[offsetcomments]] PCTaskStatus
{
/*0x00*/ int TaskID;
/*0x04*/ int MovingStartTime;
/*0x08*/ int InitialStartTime;
/*0x0c*/ bool ElementActive[0x14];
/*0x20*/ int CurrentCounts[0x14];
/*0x70*/
};

struct [[offsetcomments]] MonsterMissionTemplate
{
/*0x00*/ int  TemplateID;
/*0x04*/ int  Min;
/*0x08*/ int  Max;
/*0x0c*/ int  NumSelected;
/*0x10*/ bool CanSelect;
/*0x11*/ char TemplateName[0x40];
/*0x54*/
};

struct [[offsetcomments]] PCSharedTaskData
{
/*0x00*/ int  ActiveSharedTaskID;
/*0x04*/ bool bIsMonsterMission;
/*0x08*/ PCTaskStatus Status;                              // size 0x70
/*0x78*/ ArrayClass<MonsterMissionTemplate> Templates;  // size is 0x10
/*0x88*/ float RewardAdjustment;
/*0x8c*/
};

struct [[offsetcomments]] TaskTimerData
{
/*0x00*/ int GroupID;
/*0x04*/ int TimerSeconds;
/*0x08*/ UINT TimerExpiration;
/*0x0c*/ int TimerType;
/*0x10*/ int OrigTaskID;
/*0x14*/ TaskTimerData *pNext;
/*0x18*/
};

class [[offsetcomments]] PendingReward
{
	FORCE_SYMBOLS;

public:
/*0x00*/ void* vfTable;
/*0x04*/ int   ID;
/*0x08*/ int   SetID;
/*0x0c*/ float RewardAdjustment;
/*0x10*/ char  RewardTitle[0x80];
/*0x90*/
};

class [[offsetcomments]] PendingRewardList : public DoublyLinkedList<PendingReward*>
{
public:
/*0x20*/ int NextUID;
/*0x24*/ int MaxPending;
/*0x28*/ int ZoneMaxPending;
/*0x2c*/
};

struct [[offsetcomments]] Point
{
/*0x00*/ UINT PointType;
/*0x04*/ UINT PointSubtype;
/*0x08*/ UINT CurrentCount;
/*0x0c*/ UINT TotalEver;
/*0x10*/
};

struct [[offsetcomments]] PointNamesEntry
{
/*0x00*/ UINT PointTypeId;
/*0x04*/ UINT PointSubtypeId;
/*0x08*/ int  DBStringId;
/*0x0c*/ int  PointItemId;
/*0x10*/ int  ImageId;
/*0x14*/ int  MaxStackSize;
/*0x18*/ bool bStationCashRelated;
/*0x1c*/
};

class [[offsetcomments]] PointSystemBase
{
public:
/*0x00*/ void* vfTable;
/*0x04*/ ArrayClass<PointNamesEntry*> PointNameEntries;
/*0x14*/
};

class [[offsetcomments]] CPlayerPointManager
{
public:
	EQLIB_OBJECT unsigned long GetAltCurrency(unsigned long, unsigned long b = 1);

/*0x00*/ void* vfTable;
/*0x04*/ ArrayClass<Point*> Points;
/*0x14*/
};
using PlayerPointManager = CPlayerPointManager;

struct [[offsetcomments]] ProgressionExperience
{
/*0x00*/ int ProgressionID;
/*0x08*/ double ProgressionExp;
/*0x10*/
};

struct [[offsetcomments]] PCCompletedQuest
{
/*0x00*/ int QuestID;
/*0x04*/ int ElementBitmask;
/*0x08*/ UINT TimeCompleted;
/*0x0c*/
};

struct [[offsetcomments]] PCQuestHistoryData
{
/*0x000*/ PCCompletedQuest Quests[0x32];                   // size 0xc * 0x32 = 0x258
/*0x258*/
};

struct [[offsetcomments]] PvPKill
{
/*0x00*/ char VictimName[0x40];
/*0x40*/ int VictimLevel;
/*0x44*/ DWORD VictimRace;
/*0x48*/ DWORD VictimClass;
/*0x4c*/ int ZoneID;
/*0x50*/ long Lastkilltime;
/*0x54*/ int PointsEarned;
/*0x58*/
};

struct [[offsetcomments]] PvPDeath
{
/*0x00*/ char KillerName[0x40];
/*0x40*/ int KillerLevel;
/*0x44*/ DWORD KillerRace;
/*0x48*/ DWORD KillerClass;
/*0x4c*/ int ZoneID;
/*0x50*/ long LastDeathTime;
/*0x54*/ int PointsLost;
/*0x58*/
};

struct PvPKill24HourData : public PvPKill
{
	//nothing here?
};

struct [[offsetcomments]] RaidData
{
/*0x00*/ int MainAssists[3];
/*0x0c*/ char MainAssistNames[3][0x40];
/*0xcc*/ int MainMarkers[3];
/*0xd8*/ int MasterLooter;
/*0xdc*/
};

struct [[offsetcomments]] TradeskillRecipeCount
{
	FORCE_SYMBOLS;

/*0x00*/ int SkillID;
/*0x04*/ int RecipeCount;
/*0x08*/
};

struct [[offsetcomments]] WorldLocation
{
/*0x00*/ DWORD ZoneBoundID;
/*0x04*/ float ZoneBoundY;
/*0x08*/ float ZoneBoundX;
/*0x0c*/ float ZoneBoundZ;
/*0x10*/ float ZoneBoundHeading;
/*0x14*/
};


class [[offsetcomments]] StatCounter
{
public:
/*0x00*/ UINT Value;
/*0x04*/
};

class [[offsetcomments]] StatElapsedTime
{
public:
/*0x00*/ UINT StartTick;
/*0x04*/ UINT ElapsedTotal;
/*0x08*/ bool bCurrentState;
/*0x0c*/
};

class [[offsetcomments]] PCStatistics
{
public:
	enum eStatisticType
	{
		S_TotalExpEarned,
		S_GroupExpEarned,
		S_ExpRaidEarned,
		S_ExpSoloEarned,
		S_NonExpKills,
		S_ExpKills,
		S_ZonesVisited,
		S_ChatShouts,
		S_ChatOOCs,
		S_ChatSays,
		S_ChatGroup,
		S_ChatTells,
		S_Deaths,
		S_Resurrections,
		S_PlatEarned,
		S_TradeskillCombines,
		S_Forages,
		S_Quests,
		S_LastStat,
	};

/*0x000*/ StatElapsedTime StatTimeSession;                 // size 0xc
/*0x00c*/ StatElapsedTime StatTimeLFG;
/*0x018*/ StatElapsedTime StatTimeGrouped;
/*0x024*/ StatElapsedTime StatTimeSolo;
/*0x030*/ StatElapsedTime StatTimeRaid;
/*0x03c*/ StatElapsedTime StatTimeInBazaar;
/*0x048*/ StatCounter Statistics[S_LastStat];              // size is 0x48
/*0x090*/ UINT LastUpdateTime;
/*0x094*/ char PlayerName[0x40];
/*0x0d4*/ char PlayerStationID[0x20];
/*0x0f4*/ int PlayerLevel;
/*0x0f8*/ DWORD PlayerRace;
/*0x0fc*/ DWORD PlayerClass;
/*0x100*/ UINT UniquePlayerID;
/*0x104*/
};

class [[offsetcomments]] GroupMemberStats
{
public:
	enum eStatisticType
	{
		S_Mez,
		S_Root,
		S_Charmed,
		S_Stunned,
		S_Slowed,
		S_FirstAgro,
		S_DmgMelee,
		S_DmgRanged,
		S_DmgSpell,
		S_DmgDot,
		S_DmgPet,
		S_DmgTaken,
		S_DmgHealed,
		S_ExpTotalEarned,
		S_Deaths,
		S_ExpKills,
		S_NonExpKills,
		S_ManaUsed,
		S_EnduranceUsed,
		S_LastStat,
	};

/*0x000*/ char         PlayerName[0x40];
/*0x040*/ int          PlayerLevel;
/*0x044*/ int          PlayerRace;
/*0x048*/ int          PlayerClass;
/*0x04c*/ UINT         UniquePlayerId;
/*0x050*/ UINT         LastMemberUpdateTime;
/*0x054*/ CXStr        StationID;
/*0x058*/ int          PlayerGuild;
/*0x05c*/ TSafeArrayStatic<int, NUM_LONG_BUFFS>     BuffIDs;
/*0x104*/ TSafeArrayStatic<StatCounter, S_LastStat> Statistics;
/*0x150*/
};

struct [[offsetcomments]] ClaimData
{
/*0x00*/ int FeatureID;
/*0x04*/ int Count;
/*0x08*/
};

class [[offsetcomments]] ClaimDataCollection
{
public:
/*0x00*/ ArrayClass<ClaimData> ClaimData;
/*0x10*/
};

class [[offsetcomments]] MercenaryAbilityInfo
{
public:
/*0x00*/ int Index;
/*0x04*/ int Cost;
/*0x08*/
};

struct [[offsetcomments]] CompletedAchievementData
{
/*0x00*/ int AchievementID;
/*0x04*/ UINT CompletedTimestamp;
/*0x08*/ int CompletedVersion;
/*0x0c*/
};

enum eAchievementSubReqType
{
	eASCRT_Invalid,
	eASCRT_Requirement,
	eASCRT_KillNpcRaceMat,
	eASCRT_RightClickItem,
	eASCRT_KillNpc,
	eASCRT_Count,
};

struct [[offsetcomments]] AchievementSubComponentCountData
{
/*0x00*/ int AchievementID;
/*0x04*/ int ComponentID;
/*0x08*/ int RequirementID;
/*0x0c*/ eAchievementSubReqType SubReqType;
/*0x10*/ int Count;
/*0x14*/
};

//============================================================================
// CHARINFO a.k.a. PcClient
//============================================================================

struct CHARINFOOLD;
struct CHARINFONEW;

#ifdef NEWCHARINFO
using CHARINFO = CHARINFONEW;
using PCHARINFO [[deprecated]] = CHARINFONEW*;
#else
using CHARINFO = CHARINFOOLD;
using PCHARINFO /*[[deprecated]]*/ = CHARINFOOLD*;
#endif

// these are just virtual base tables
struct [[offsetcomments]] CI_INFO
{
/*0x00*/ DWORD   minus8;
/*0x04*/ DWORD   stuff_offset;
/*0x08*/ DWORD   Unknown0x8;    // 2000
/*0x0c*/ DWORD   Unknown0xc;    // 2500
/*0x10*/ DWORD   Unknown0x10;   // 3000
/*0x14*/ DWORD   Unknown0x14;   // 4000
/*0x18*/ DWORD   Unknown0x18;   // 10000
/*0x1c*/
};

struct [[offsetcomments]] EQC_INFO
{
/*0x00*/ DWORD   minus4;
/*0x04*/ DWORD   stuff_offset;
/*0x08*/
};

//aStartingLoad
#define CHARINFO_Size 0x2B78 //in Nov 01 2018 beta (see 5D7008) - eqmule
/*0x1c4c*/ //ItemIndex	StatKeyRingItemIndex[3];//0xe46 confirmed
//this thing here is an abomination, todo: fix it once and for all.
// its like a frankenstruct mixing in PcBase etc.
struct [[offsetcomments]] CHARINFOOLD
{
/*0x0000*/ void*                                         vtable1;
/*0x0004*/ void*                                         punknown;
/*0x0008*/ CI_INFO*                                      charinfo_info;
/*0x000c*/ void*                                         vftablealso;
/*0x0010*/ TSafeArrayStatic<int, 0xa>                    RecentTasks;
/*0x0038*/ TSafeArrayStatic<PCTaskStatus, 1>             Tasks;
/*0x00a8*/ TSafeArrayStatic<PCTaskStatus, 0x1d>          Quests;
/*0x0d58*/ TSafeArrayStatic<BYTE, 0x320>                 BitFlags;
/*0x1078*/ TSafeArrayStatic<BenefitSelection, 5>         ActiveTributeBenefits;          // size 0x28 8 * 5
/*0x10a0*/ TSafeArrayStatic<BenefitSelection, 0xa>       ActiveTrophyTributeBenefits;
/*0x10f0*/ TSafeArrayStatic<BYTE, 0x320>                 BitFlags2;
/*0x1410*/ int                                           pBankArraySize;
/*0x1414*/ int                                           pBankArraySpec;
/*0x1418*/ BANKARRAY*                                    pBankArray;
/*0x141c*/ DWORD                                         NumBankSlots;                   // how many bank slots we have
/*0x1420*/ BYTE                                          Unknown0x1420[0x14];
/*0x1434*/ SHAREDBANKARRAY*                              pSharedBankArray;
/*0x1438*/ DWORD                                         NumSharedSlots;                 // how many sharedbank slots we have
/*0x143c*/ BYTE                                          Unknown0x143c[0x4c];
/*0x1488*/ MERCEQUIPMENT*                                pMercEquipment;
/*0x148c*/ DWORD                                         NumMercEquipSlots;              // how many pMercEquipment slots we have
/*0x1490*/ BYTE                                          Unknown0x1490[0xc];
/*0x149c*/ DWORD                                         KeyRing1;                       // always 0x7d
/*0x14a0*/ DWORD                                         eMount;                         // always eItemContainerMountKeyRingItems (27)
/*0x14a4*/ KEYRINGARRAY*                                 pMountsArray;
/*0x14a8*/ BYTE                                          Unknown0x14a8[0x10];
/*0x14b8*/ DWORD                                         KeyRing2;                       // always 0x7d
/*0x14bc*/ DWORD                                         eIllusion;                      // always eItemContainerIllusionKeyRingItems (29)
/*0x14c0*/ KEYRINGARRAY*                                 pIllusionsArray;
/*0x14c4*/ BYTE                                          Unknown0x14c4[0x10];
/*0x14d4*/ DWORD                                         KeyRing3;                       // always 0x7d
/*0x14d8*/ DWORD                                         eFamiliar;                      // always eItemContainerViewModFamiliarKeyRingItems (31)
/*0x14dc*/ KEYRINGARRAY*                                 pFamiliarArray;
/*0x14e0*/ BYTE                                          Unknown0x14e0[0x10];
/*0x14f0*/ DWORD                                         KeyRing4;
/*0x14f4*/ DWORD                                         eHeroForge;                     // always eItemContainerViewModHeroForgeKeyRingItems (35?)
/*0x14f8*/ KEYRINGARRAY*                                 pHeroForgeArray;
/*0x14fc*/ BYTE                                          Unknown0x14fc[0xe4];
/*0x15e0*/ int64_t                                       GuildID;                        // GuildID_0
/*0x15e8*/ int64_t                                       FellowshipID;
/*0x15f0*/ FELLOWSHIPINFO*                               pFellowship;
/*0x15f4*/ bool                                          GuildShowSprite;
/*0x15f8*/ UINT                                          CreationTime;                   // CharCreationTime
/*0x15fc*/ UINT                                          AccountCreationTime;
/*0x1600*/ UINT                                          LastPlayedTime;
/*0x1604*/ DWORD                                         MinutesPlayed;
/*0x1608*/ BYTE                                          Anonymous;
/*0x1609*/ bool                                          bGM;
/*0x160a*/ bool                                          bGMStealth;
/*0x160c*/ DWORD                                         AAExp;                          // Post60Exp
/*0x1610*/ BYTE                                          NobilityRank;
/*0x1611*/ BYTE                                          PercentEXPtoAA;
/*0x1614*/ int                                           AirSupply;
/*0x1618*/ int                                           SerialNum;
/*0x161c*/ bool                                          bNewCharacter;
/*0x1620*/ int                                           TasksAssigned;
/*0x1624*/ int                                           TasksCompleted;
/*0x1628*/ long                                          TaskRequestTimer;
/*0x162c*/ unsigned int                                  UniquePlayerID;
/*0x1630*/ WorldLocation                                 DynamicZoneSafeReturnLocation;  // size 0x14
/*0x1644*/ DynamicZoneTimerData*                         pDZTimerRoot;
/*0x1648*/ DWORD                                         TributeTimer;
/*0x164c*/ DWORD                                         BenefitTimer;
/*0x1650*/ int64_t                                       CareerFavor;
/*0x1658*/ int64_t                                       CurrFavor;
/*0x1660*/ BYTE                                          Unknown0x1648[0xFC];
/*0x175c*/ int                                           RadiantCrystals;
/*0x1760*/ int                                           GoodTotalPointsEarned;
/*0x1764*/ int                                           EbonCrystals;
/*0x1768*/ BYTE                                          Unknown0x1768[0x710];
/*0x1e78*/ int64_t                                       Exp;                            // confirmed jun 12 2017 test
/*0x1e80*/ int                                           DaysEntitled;
/*0x1e84*/ int                                           SpentVeteranRewards;
/*0x1e88*/ bool                                          bVeteranRewardEntitled;
/*0x1e89*/ bool                                          bAutoConsentGroup;
/*0x1e8a*/ bool                                          bAutoConsentRaid;
/*0x1e8b*/ bool                                          bAutoConsentGuild;
/*0x1e8c*/ bool                                          bPrivateForEqPlayers;
/*0x1e90*/ long                                          AchievementFilesModificationTime;
/*0x1e94*/ char                                          StationID[0x20];
/*0x1eb8*/ EqGuid                                        Guid;                           // size 8 so it MUST start at a int64 sized address.. i.e. 0 or 8
/*0x1ec0*/ bool                                          bBetaBuffed;
/*0x1ec4*/ int                                           Unknown0x1ec4;
/*0x1ec8*/ int                                           StartingCity;
/*0x1ecc*/ int                                           MainLevel;
/*0x1ed0*/ bool	                                         bShowHelm;
/*0x1ed8*/ int64_t                                       LastTestCopyTime;
/*0x1ee0*/ CPlayerPointManager                           PointManager;                   // size 0x14
/*0x1ef4*/ PointSystemBase                               PointSystem;                    // size 0x14
/*0x1f08*/ UINT                                          LoyaltyVelocity;
/*0x1f0c*/ UINT                                          LoyaltyTokens;
/*0x1f10*/ bool                                          bHasLoyaltyInfo;
/*0x1f14*/ ArrayClass<int>                               OwnedRealEstates;
/*0x1f24*/ ArrayClass<int>                               OwnedItemRealEstates;
/*0x1f34*/ ArrayClass<int>                               ArchivedRealEstates;
/*0x1f44*/ char                                          OverridePetName[0x40];
/*0x1f84*/ bool                                          bCanRequestPetNameChange;
/*0x1f85*/ char                                          OverrideFamiliarName[0x40];
/*0x1fc5*/ bool                                          bCanRequestFamiliarNameChange;
/*0x1fc8*/ CXStr                                         OverrideMercName[0xb];
/*0x1ff4*/ bool                                          bCanRequestMercNameChange;
/*0x1ff8*/ PendingRewardList                             PendingRewards;                 // size 0x2c
/*0x2024*/ UINT                                          DowntimeReductionTime;
/*0x2028*/ UINT                                          DowntimeTimerStart;
/*0x202c*/ float                                         ActivityValue;
/*0x2030*/ UINT                                          NextItemId;
/*0x2034*/ CXStr                                         SharedBank;
/*0x2038*/ CXStr                                         BankBuffer;
/*0x203c*/ CXStr                                         LimboBuffer;
/*0x2040*/ CXStr                                         MercenaryBuffer;
/*0x2044*/ CXStr                                         KeyRingBuffer[4];
/*0x2054*/ CXStr                                         AltStorageBuffer;
/*0x2058*/ CXStr                                         ItemOverflow;
/*0x205c*/ UINT                                          AltStorageTimestamp;
/*0x2060*/ ELockoutCharacterReason                       LCR;
/*0x2064*/ HashTable<ProgressionExperience>              ProgressionExp;                 // size 0x10
/*0x2074*/ CXStr                                         ArchivedStorageBuffer;
/*0x2078*/ CXStr                                         MailItemsBuffer;
/*0x207c*/ CXStr                                         MailItemsDataBuffer;
/*0x2080*/ int                                           MailItemsOverCapWarningCount;
/*0x2084*/ ItemIndex                                     StatKeyRingItemIndex[4];        // size 0x12
/*0x209c*/ BYTE                                          UseAdvancedLooting;             // 0x1ff2 confirmed jun 12 2017 test               //0=off 1=on
/*0x209d*/ BYTE                                          MasterLootCandidate;            // 0=off 1=on
/*0x209e*/ BYTE                                          Unknown0x209e[0x2b6];
/*0x2354*/ DWORD                                         Krono;                          // confirmed jun 12 2017 test
/*0x2358*/ DWORD                                         CursorKrono;
/*0x235c*/ BYTE                                          Unknown0x235c[0x4];
/*0x2360*/ int64_t                                       MercAAExp;                      // divide this with 3.30f and you get the percent - eqmule
/*0x2368*/ DWORD                                         MercAAPoints;                   // number of unspent merc AA points
/*0x236c*/ DWORD                                         MercAAPointsSpent;              // number of spent merc AA points
/*0x2370*/ BYTE                                          Unknown0x2370[0x48];
/*0x23b8*/ int64_t                                       Vitality;
/*0x23c0*/ int                                           AAVitality;
/*0x23c4*/ int                                           Unknown0x23c4;
/*0x23c8*/ int                                           FPStuff[0x1e];
/********************* PcBase End **********************/
/************ CharacterZoneClient Begin ****************/
/*0x2440*/ void*                                         vtable2;                        // vtable2_0 below aTimeIsDAndCanU (its really PcClient_CharacterZoneClient_vfTable
/*0x2444*/ EQC_INFO*                                     eqc_info;
/*0x2448*/ SPAWNINFO*                                    pSpawn;                         // pSpawn_0
/*0x244c*/ bool                                          bUpdateStuff;
/*0x244d*/ bool                                          bZoningStatProcessing;
/*0x2450*/ DWORD                                         ArmorClassBonus;                // vtable2+10
/*0x2454*/ DWORD                                         CurrWeight;                     // vtable2+14
/*0x2458*/ int                                           LastHitPointSendPercent;
/*0x245c*/ int                                           LastManaPointSendPercent;
/*0x2460*/ int                                           LastEndurancePointSendPercent;
/*0x2464*/ int                                           HPBonus;                        // vtable2+24
/*0x2468*/ int                                           ManaBonus;                      // vtable2+28
/*0x246c*/ int                                           EnduranceBonus;                 // vtable2+2c
/*0x2470*/ int                                           EnduranceCostPerSecond;
/*0x2474*/ int                                           CombatEffectsBonus;             // vtable2+34 Combat Effects in UI
/*0x2478*/ int                                           ShieldingBonus;                 // vtable2+38 Melee Shielding in UI
/*0x247c*/ int                                           SpellShieldBonus;               // vtable2+3c Spell Shielding in UI
/*0x2480*/ int                                           AvoidanceBonus;                 // vtable2+40 Avoidance in UI
/*0x2484*/ int                                           AccuracyBonus;                  // vtable2+44 Accuracy in UI
/*0x2488*/ int                                           StunResistBonus;                // vtable2+48 Stun Resist in UI
/*0x248c*/ int                                           StrikeThroughBonus;             // vtable2+4c Strike Through in UI
/*0x2490*/ int                                           DoTShieldBonus;                 // vtable2+50 Dot Shielding in UI
/*0x2494*/ int                                           DamageShieldMitigationBonus;    // vtable2+54 Damage Shield Mitig in UI
/*0x2498*/ int                                           DamageShieldBonus;              // vtable2+58 Damage Shielding in UI
/*0x249c*/ TSafeArrayStatic<int, 9>                      ItemSkillMinDamageMod;          // size 0x24
/*0x24c0*/ TSafeArrayStatic<int, 9>                      SkillMinDamageModBonus;         // size 0x24
/*0x24e4*/ DWORD                                         HeroicSTRBonus;                 // vtable2+a4
/*0x24e8*/ DWORD                                         HeroicINTBonus;                 // vtable2+a8
/*0x24ec*/ DWORD                                         HeroicWISBonus;                 // vtable2+ac
/*0x24f0*/ DWORD                                         HeroicAGIBonus;                 // vtable2+b0
/*0x24f4*/ DWORD                                         HeroicDEXBonus;                 // vtable2+b4
/*0x24f8*/ DWORD                                         HeroicSTABonus;                 // vtable2+b8
/*0x24fc*/ DWORD                                         HeroicCHABonus;                 // vtable2+bc
/*0x2500*/ DWORD                                         HealAmountBonus;                // vtable2+d8
/*0x2504*/ DWORD                                         SpellDamageBonus;               // vtable2+dc
/*0x2508*/ int                                           ItemHealAmountDotMod;
/*0x250c*/ int                                           ItemSpellDamageDotMod;
/*0x2510*/ DWORD                                         ClairvoyanceBonus;              // vtable2+e8
/*0x2514*/ DWORD                                         AttackBonus;                    // vtable2+ec
/*0x2518*/ DWORD                                         HPRegenBonus;                   // vtable2+f0
/*0x251c*/ DWORD                                         ManaRegenBonus;                 // vtable2+f4
/*0x2520*/ DWORD                                         EnduranceRegenBonus;            // vtable2+f8
/*0x2524*/ DWORD                                         AttackSpeed;                    // vtable2+fc
/*0x2528*/ int                                           NoBuffItemHitpointAdjustment;
/*0x252c*/ int                                           NoBuffItemManaAdjustment;
/*0x2530*/ int                                           NoBuffItemEnduranceAdjustment;
/*0x2534*/ int                                           NoBuffItemBaseChanceProc;
/*0x2538*/ int                                           NoBuffItemMinDamageMod;
/*0x253c*/ int                                           NoBuffItemInnateSpellRune;
/*0x2540*/ int                                           NoBuffItemAvoidance;
/*0x2544*/ int                                           NoBuffItemToHit;
/*0x2548*/ int                                           NoBuffItemResistStunChance;
/*0x254c*/ int                                           NoBuffItemDotShieldingEffect;
/*0x2550*/ int                                           NoBuffItemStrikeThroughChance;
/*0x2554*/ int                                           NoBuffItemAttack;
/*0x2558*/ int                                           NoBuffItemHitPointRegen;
/*0x255c*/ int                                           NoBuffItemManaRegen;
/*0x2560*/ int                                           NoBuffItemEnduranceRegen;
/*0x2564*/ int                                           NoBuffItemDamageShield;
/*0x2568*/ int                                           NoBuffItemDamageShieldMitigation;
/*0x256c*/ int                                           NoBuffItemHaste;
/*0x2570*/ TSafeArrayStatic<int, 9>                      NoBuffItemSkillMinDamageMod;    // size 0x24
/*0x2594*/ bool                                          bOutputHpRegen;
/*0x2595*/ bool                                          bInvulnerable;
/*0x2596*/ bool                                          bOnAVehicle;                    // 0x2420 + 0x156 see 4D94E8 in jun 11 2018 test
/*0x2598*/ SpellCache                                    spellCache;                     // size 0x58
/*0x25f0*/ HashListSet<int, 0x80>                        DoomEffectsBySlot;              // size 0x10 + (0x80 * 4)
/*0x2800*/ UINT                                          LastHitEval;
/*********************** CharacterZoneClient End ***********************/
/******************* PcZoneClient Begine ******************/
/*0x2804*/ void*                                         PcZoneClient_vfTable;           // see 61A04C jun 11 test 2018
/*0x2808*/ TSafeArrayStatic<unsigned long, 3>            Flags;                          // size 0xc
/*0x2814*/ uint32_t                                      TransfersReceived;
/*0x2818*/ int                                           LastLanguageSpoken;
/*0x281c*/ int                                           CurPowerSourceDrain;
/*0x2820*/ EQList<ALCHEMYBONUSSKILLDATA*>                AlchemyBaseSkillBonusList;
/*0x2830*/ UINT                                          MomentumBalance;
/*0x2834*/ UINT                                          LoyaltyRewardBalance;
/******************* PcZoneClient End ******************/
/******************* PCClient Begin ************************/
/*0x2838*/ ExtendedTargetList*                           pXTargetMgr;
/*0x283c*/ DWORD                                         InCombat;
/*0x2840*/ DWORD                                         Downtime;
/*0x2844*/ DWORD                                         DowntimeStamp;
/*0x2848*/ bool                                          bOverrideAvatarProximity;
/*0x284c*/ GROUPINFO*                                    pGroupInfo;
/*0x2850*/ bool                                          bIAmCreatingGroup;
/*0x2854*/ VeArray<VePointer<CONTENTS*>>                 ItemsPendingID;                 // size 0xc
/*0x2860*/ int                                           ParcelStatus;                   // eParcelStatus
/*0x2864*/ int                                           SubscriptionDays;               // 24BC for sure see 7A6C40 in may 11 2018 live exe
/*0x2868*/ short                                         BaseKeyRingSlots[4];
/*0x2870*/ bool                                          bPickZoneFewest;                // for sure see 4A424A in may 11 2018 live exe
/*0x2874*/ int                                           Unknown0x2874;
/*0x2878*/ int                                           Unknown0x2878;
/******************* PCClient End ************************/
/******************* CharacterBase Begin ************************/
/*0x287c*/ void*                                         CharacterBase_vftable;
/*0x2880*/ CProfileManager                               ProfileManager;
/*0x2888*/ BYTE                                          languages[0x20];
/*0x28a8*/ float                                         X;
/*0x28ac*/ float                                         Y;
/*0x28b0*/ float                                         Z;
/*0x28b4*/ float                                         Heading;
/*0x28b8*/ char                                          Name[0x40];                     // CharBaseBegin+44
/*0x28f8*/ char                                          Lastname[0x20];                 // CharBaseBegin+84
/*0x2918*/ TSafeString<0x80>                             Title;
/*0x2998*/ TSafeString<0x40>                             VehicleName;
/*0x29d8*/ BYTE                                          Stunned;                        // CharBaseBegin+104
/*0x29d9*/ BYTE                                          Unknown0x29a9[0x3];
/*0x29dc*/ WORD                                          zoneId;                         // CharBaseBegin+108 Zone_0
/*0x29de*/ WORD                                          instance;
/*0x29e0*/ BYTE                                          standstate;                     // CharBaseBegin+10c
/*0x29e4*/ RaidData                                      raidData;                       // size 0xdc
/*0x2ac0*/ DWORD                                         ExpansionFlags;                 // CharBaseBegin+464
/*0x2ac4*/ bool                                          bSuperPKILL;
/*0x2ac5*/ bool                                          bUnclone;
/*0x2ac6*/ bool                                          bDead;
/*0x2ac8*/ int                                           LD_Timer;
/*0x2acc*/ int                                           SpellInterruptCount;
/*0x2ad0*/ bool                                          bAutoSplit;
/*0x2ad1*/ bool                                          bTellsOff;
/*0x2ad2*/ bool                                          bGmInvis;
/*0x2ad4*/ int                                           KillMe;
/*0x2ad8*/ bool                                          CheaterLdFlag;                  // likely this is int SoulMarkCount instead.
/*0x2ad9*/ bool                                          NoRent;
/*0x2ada*/ bool                                          Corpse;
/*0x2adb*/ bool                                          ClientGmFlagSet;
/*0x2adc*/ DWORD                                         BankSharedPlat;                 // 31e4 CharBaseBegin+488
/*0x2ae0*/ DWORD                                         BankSharedGold;                 // CharBaseBegin+48c
/*0x2ae4*/ DWORD                                         BankSharedSilver;               // CharBaseBegin+490
/*0x2ae8*/ DWORD                                         BankSharedCopper;               // CharBaseBegin+494
/*0x2aec*/ DWORD                                         BankPlat;                       // CharBaseBegin+498
/*0x2af0*/ DWORD                                         BankGold;                       // CharBaseBegin+49c
/*0x2af4*/ DWORD                                         BankSilver;                     // CharBaseBegin+4a0
/*0x2af8*/ DWORD                                         BankCopper;                     // CharBaseBegin+4a4
/*0x2afc*/ int                                           STR;                            // CharBaseBegin+4a8
/*0x2b00*/ int                                           STA;                            // CharBaseBegin+4ac
/*0x2b04*/ int                                           CHA;                            // CharBaseBegin+4b0
/*0x2b08*/ int                                           DEX;                            // CharBaseBegin+4b4
/*0x2b0c*/ int                                           INT;                            // CharBaseBegin+4b8
/*0x2b10*/ int                                           AGI;                            // CharBaseBegin+4bc
/*0x2b14*/ int                                           WIS;                            // CharBaseBegin+4c0
/*0x2b18*/ int                                           LCK;                            // CharBaseBegin+4c4
/*0x2b1c*/ int                                           SavePoison;                     // CharBaseBegin+4c8
/*0x2b20*/ int                                           SaveMagic;                      // CharBaseBegin+4cc
/*0x2b24*/ int                                           SaveDisease;                    // CharBaseBegin+4d0
/*0x2b28*/ int                                           SaveCorruption;                 // CharBaseBegin+4d4
/*0x2b2c*/ int                                           SaveFire;                       // CharBaseBegin+4d8
/*0x2b30*/ int                                           SaveCold;                       // CharBaseBegin+4dc
/*0x2b34*/ int                                           SavePhysical;                   // CharBaseBegin+4e0
/*0x2b38*/ int                                           UncappedStr;
/*0x2b3c*/ int                                           UncappedSta;
/*0x2b40*/ int                                           UncappedCha;
/*0x2b44*/ int                                           UncappedDex;
/*0x2b48*/ int                                           UncappedInt;
/*0x2b4c*/ int                                           UncappedAgi;
/*0x2b50*/ int                                           UncappedWis;
/*0x2b54*/ int                                           UncappedResistPoison;
/*0x2b58*/ int                                           UncappedResistMagic;
/*0x2b5c*/ int                                           UncappedResistDisease;
/*0x2b60*/ int                                           UncappedResistCorruption;
/*0x2b64*/ int                                           UncappedResistFire;
/*0x2b68*/ int                                           UncappedResistCold;
/*0x2b6c*/ int                                           UncappedResistPhysical;
/*0x2b70*/ int                                           NoBuffStr;
/*0x2b74*/ int                                           NoBuffSta;
/*0x2b78*/ int                                           NoBuffCha;
/*0x2b7c*/ int                                           NoBuffDex;
/*0x2b80*/ int                                           NoBuffInt;
/*0x2b84*/ int                                           NoBuffAgi;
/*0x2b88*/ int                                           NoBuffWis;
/*0x2b8c*/ int                                           NoBuffResistPoison;
/*0x2b90*/ int                                           NoBuffResistMagic;
/*0x2b94*/ int                                           NoBuffResistDisease;
/*0x2b98*/ int                                           NoBuffResistCorruption;
/*0x2b9c*/ int                                           NoBuffResistFire;
/*0x2ba0*/ int                                           NoBuffResistCold;
/*0x2ba4*/ int                                           NoBuffResistPhysical;
/*0x2ba8*/
};

struct [[offsetcomments]] CHARINFONEW
{
/*********************** PcBase Begin ************************/
/*0x0000*/ void*                                         vtable1;
/*0x0004*/ void*                                         punknown;
/*0x0008*/ CI_INFO*                                      charinfo_info;
/*0x000c*/ void*                                         vftablealso;
/*0x0010*/ TSafeArrayStatic<int, 0xa>                    RecentTasks;
/*0x0038*/ TSafeArrayStatic<PCTaskStatus, 1>             Tasks;
/*0x00a8*/ TSafeArrayStatic<PCTaskStatus, 0x1d>          Quests;
/*0x0d58*/ TSafeArrayStatic<BYTE, 0x320>                 BitFlags;
/*0x1078*/ TSafeArrayStatic<BenefitSelection, 5>         ActiveTributeBenefits;          // size 0x28 8 * 5
/*0x10a0*/ TSafeArrayStatic<BenefitSelection, 0xa>       ActiveTrophyTributeBenefits;
/*0x10f0*/ TSafeArrayStatic<BYTE, 0x320>                 BitFlags2;
/*0x1410*/ ItemBaseContainer                             BankItems;                      // size 0x1c pBankArray
/*0x142c*/ ItemBaseContainer                             SharedBankItems;
/*0x1448*/ ItemBaseContainer                             OverflowBufferItems;
/*0x1464*/ ItemBaseContainer                             LimboBufferItems;
/*0x1480*/ ItemBaseContainer                             MercenaryItems;
/*0x149c*/ ItemBaseContainer                             MountKeyRingItems;
/*0x14b8*/ ItemBaseContainer                             IllusionKeyRingItems;
/*0x14d4*/ ItemBaseContainer                             FamiliarKeyRingItems;
/*0x14f0*/ ItemBaseContainer                             HeroForgeKeyRingItems;
/*0x150c*/ ItemBaseContainer                             AltStorageItems;
/*0x1528*/ ItemBaseContainer                             ArchivedDeletedItems;
/*0x1544*/ ItemBaseContainer                             MailItems;
/*0x1560*/ HashTable<MailItemData, EqItemGuid, ResizePolicyNoShrink> MailItemsData;      // size 0x10
/*0x1570*/ TSafeArrayStatic<UINT, 1>                     RecentMoves;
/*0x1574*/ HashTable<DynamicZoneData>                    CurrentDynamicZones;
/*0x1584*/ HashTable<int>                                LearnedRecipes;
/*0x1594*/ EQList<TradeskillRecipeCount*>                QualifyingRecipeCounts;
/*0x15a4*/ HashTable<int>                                NonrepeatableQuests;
/*0x15b4*/ HashTable<int>                                CompletedTasks;
/*0x15c4*/ HashTable<int>                                CompletedQuests;
/*0x15d4*/ UINT                                          AlchemyTimestamp;
/*0x15d8*/ bool                                          bGoHomeOverride;
/*0x15d9*/ bool                                          bSomethingHome;
/*0x15dc*/ DWORD                                         LoginTime;                      // next must start on 8 align
/*0x15e0*/ int64_t                                       GuildID;                        // GuildID_0
/*0x15e8*/ int64_t                                       FellowshipID;
/*0x15f0*/ FELLOWSHIPINFO*                               pFellowship;
/*0x15f4*/ bool                                          GuildShowSprite;
/*0x15f8*/ UINT                                          CreationTime;                   // CharCreationTime
/*0x15fc*/ UINT                                          AccountCreationTime;
/*0x1600*/ UINT                                          LastPlayedTime;
/*0x1604*/ DWORD                                         MinutesPlayed;
/*0x1608*/ BYTE                                          Anonymous;
/*0x1609*/ bool                                          bGM;
/*0x160a*/ bool                                          bGMStealth;
/*0x160c*/ DWORD                                         AAExp;                          // Post60Exp
/*0x1610*/ BYTE                                          NobilityRank;
/*0x1611*/ BYTE                                          PercentEXPtoAA;
/*0x1614*/ int                                           AirSupply;
/*0x1618*/ int                                           SerialNum;
/*0x161c*/ bool                                          bNewCharacter;
/*0x1620*/ int                                           TasksAssigned;
/*0x1624*/ int                                           TasksCompleted;
/*0x1628*/ long                                          TaskRequestTimer;
/*0x162c*/ unsigned int                                  UniquePlayerID;
/*0x1630*/ WorldLocation                                 DynamicZoneSafeReturnLocation;  // size 0x14
/*0x1644*/ DynamicZoneTimerData*                         pDZTimerRoot;
/*0x1648*/ DWORD                                         TributeTimer;
/*0x164c*/ DWORD                                         BenefitTimer;
/*0x1650*/ int64_t                                       CareerFavor;
/*0x1658*/ int64_t                                       CurrFavor;
/*0x1660*/ bool                                          bBenefitsActive;
/*0x1661*/ bool                                          bTrophyBenefitsActive;
/*0x1662*/ bool                                          bHasResetStartingCity;
/*0x1663*/ bool                                          bIsHeadStartCharacter;
/*0x1664*/ int                                           PvPKills;
/*0x1668*/ int                                           PvPDeaths;
/*0x166c*/ int                                           PvPCurrentPoints;
/*0x1670*/ int                                           PvPTotalPointsEarned;
/*0x1674*/ int                                           PvPKillStreak;
/*0x1678*/ int                                           PvPDeathStreak;
/*0x167c*/ int                                           PvPCurrentStreak;
/*0x1680*/ PvPKill                                       LastKill;                       // size 0x58
/*0x16d8*/ PvPDeath                                      LastDeath;                      // size 0x58
/*0x1730*/ HashTable<PvPKill24HourData>                  PvPLast24HoursKillHash;         // for sure see 5843D0
/*0x1740*/ int                                           PvPInfamyLevel;
/*0x1744*/ int                                           PvPVitality;
/*0x1748*/ UINT                                          PvPLastInfamyTime;
/*0x174c*/ int                                           LastLastNameChange;
/*0x1750*/ int                                           LastNameChangePriv;
/*0x1754*/ UINT                                          PvPLastVitalityTime;
/*0x1758*/ bool                                          bKeepItemsOnDeath;
/*0x1759*/ bool                                          bResetSpecializationSkills;
/*0x175c*/ DWORD                                         RadiantCrystals;                // GoodPointsAvailable
/*0x1760*/ int                                           GoodTotalPointsEarned;
/*0x1764*/ DWORD                                         EbonCrystals;                   // EvilPointsAvailable
/*0x1768*/ int                                           EvilTotalPointsEarned;
/*0x176c*/ bool                                          bCanRequestNameChange;
/*0x176d*/ bool                                          bCanRequestNameChange2;
/*0x176e*/ bool                                          bCanRequestServerTransfer;
/*0x176f*/ bool                                          bIsCopied;
/*0x1770*/ int                                           ServerTransferGrantTime;
/*0x1774*/ bool                                          bCanRequestRaceChange;
/*0x1778*/ UINT                                          LastAAResetTime;
/*0x177c*/ UINT                                          LastMercAAResetTime;
/*0x1780*/ DWORD                                         NewZoneID;                      // EQZoneIndex
/*0x1784*/ int                                           NewAreaID;
/*0x1788*/ int                                           eNewAreaCorner;                 // EAreaCorner
/*0x178c*/ DWORD                                         PreviousZoneID;                 // EQZoneIndex
/*0x1790*/ int                                           RealEstateZoneID;
/*0x1794*/ char                                          ServerCreated[0x20];
/*0x17b4*/ PCAdventureData                               AdventureData;                  // size 0x0d8
/*0x188c*/ PCSharedTaskData                              SharedTaskData;                 // size 0x8c
/*0x1918*/ TaskTimerData*                                pTaskTimerData;
/*0x191c*/ PCQuestHistoryData                            QuestHistoryData;               // size 0x258
/*0x1b74*/ PCStatistics                                  PcStatistics;                   // size 0x104 i think
/*0x1c78*/ GroupMemberStats                              GroupStats;                     // size 0x150 i think
/*0x1dc8*/ BYTE                                          Unknown0x1Db0[0x9c];
/*0x1e64*/ bool                                          bIsLfg;
/*0x1e68*/ int64_t                                       RaidId;                         // could be int
/*0x1e70*/ int64_t                                       GroupID;
/*0x1e78*/ int64_t                                       Exp;                            // confirmed jun 12 2017 test
/*0x1e80*/ int                                           DaysEntitled;
/*0x1e84*/ int                                           SpentVeteranRewards;
/*0x1e88*/ bool                                          bVeteranRewardEntitled;
/*0x1e89*/ bool                                          bAutoConsentGroup;
/*0x1e8a*/ bool                                          bAutoConsentRaid;
/*0x1e8b*/ bool                                          bAutoConsentGuild;
/*0x1e8c*/ bool                                          bPrivateForEqPlayers;
/*0x1e90*/ long                                          AchievementFilesModificationTime;
/*0x1e94*/ char                                          StationID[0x20];
/*0x1eb8*/ EqGuid                                        Guid;                           // size 8 so it MUST start at a int64 sized address.. i.e. 0 or 8
/*0x1ec0*/ bool                                          bBetaBuffed;
/*0x1ec4*/ int                                           Unknown0x1eac;
/*0x1ec8*/ int                                           StartingCity;
/*0x1ecc*/ int                                           MainLevel;
/*0x1ed0*/ bool	                                         bShowHelm;
/*0x1ed8*/ int64_t                                       LastTestCopyTime;
/*0x1ee0*/ CPlayerPointManager                           PointManager;                   // size 0x14
/*0x1ef4*/ PointSystemBase                               PointSystem;                    // size 0x14
/*0x1f08*/ UINT                                          LoyaltyVelocity;
/*0x1f0c*/ UINT                                          LoyaltyTokens;
/*0x1f10*/ bool                                          bHasLoyaltyInfo;
/*0x1f14*/ ArrayClass<int>                               OwnedRealEstates;
/*0x1f24*/ ArrayClass<int>                               OwnedItemRealEstates;
/*0x1f34*/ ArrayClass<int>                               ArchivedRealEstates;
/*0x1f44*/ char                                          OverridePetName[0x40];
/*0x1f84*/ bool                                          bCanRequestPetNameChange;
/*0x1f85*/ char                                          OverrideFamiliarName[0x40];
/*0x1fc5*/ bool                                          bCanRequestFamiliarNameChange;
/*0x1fc8*/ CXStr                                         OverrideMercName[0xb];
/*0x1ff4*/ bool                                          bCanRequestMercNameChange;
/*0x1ff8*/ PendingRewardList                             PendingRewards;                 // size 0x2c
/*0x2024*/ UINT                                          DowntimeReductionTime;
/*0x2028*/ UINT                                          DowntimeTimerStart;
/*0x202c*/ float                                         ActivityValue;
/*0x2030*/ UINT                                          NextItemId;
/*0x2034*/ CXStr                                         SharedBank;
/*0x2038*/ CXStr                                         BankBuffer;
/*0x203c*/ CXStr                                         LimboBuffer;
/*0x2040*/ CXStr                                         MercenaryBuffer;
/*0x2044*/ CXStr                                         KeyRingBuffer[4];
/*0x2054*/ CXStr                                         AltStorageBuffer;
/*0x2058*/ CXStr                                         ItemOverflow;
/*0x205c*/ UINT                                          AltStorageTimestamp;
/*0x2060*/ ELockoutCharacterReason                       LCR;
/*0x2064*/ HashTable<ProgressionExperience>              ProgressionExp;                 // size 0x10
/*0x2074*/ CXStr                                         ArchivedStorageBuffer;
/*0x2078*/ CXStr                                         MailItemsBuffer;
/*0x207c*/ CXStr                                         MailItemsDataBuffer;
/*0x2080*/ int                                           MailItemsOverCapWarningCount;
/*0x2084*/ ItemIndex                                     StatKeyRingItemIndex[4];
/*0x209c*/ bool                                          UseAdvancedLooting;             // 0x1ff2 confirmed jun 12 2017 test               //0=off 1=on
/*0x209d*/ bool                                          MasterLootCandidate;            // 0=off 1=on
/*0x209e*/ bool                                          bIsCorrupted;
/*0x20a0*/ char*                                         pCorruptionReport;
/*0x20a4*/ TString<0x100>                                InspectText;
/*0x21a4*/ HashTable<int>                                BlockedSpellsHash;
/*0x21b4*/ int                                           BlockedSpell[MAX_BLOCKED_SPELLS];
/*0x2254*/ HashTable<int>                                BlockedPetSpellsHash;
/*0x2264*/ int                                           BlockedPetSpell[MAX_BLOCKED_SPELLS_PET];
/*0x2304*/ ClaimDataCollection                           ConsumableFeatures;
/*0x2314*/ bool                                          bGrantItemsRegistered;
/*0x2318*/ uint64_t                                      CreatedGuildID;
/*0x2320*/ UINT                                          GuildCreateTime;
/*0x2324*/ CXStr                                         GuildCreateCharacter;
/*0x2328*/ bool                                          bInventoryUnserialized;
/*0x2329*/ bool                                          bAltStorageUnserialized;
/*0x232a*/ bool                                          bArchivedStorageUnserialized;
/*0x232b*/ bool                                          bMailUnserialized;
/*0x232c*/ bool                                          bPendingInventorySerialization;
/*0x2330*/ CXStr                                         BuyLines;
/*0x2334*/ ArrayClass<CXStr>                             OfflineTraderSoldItems;
/*0x2344*/ ArrayClass<CXStr>                             OfflineBuyerBoughtItems;
/*0x2354*/ DWORD                                         Krono;                          // confirmed jun 12 2017 test
/*0x2358*/ DWORD                                         CursorKrono;
/*0x235c*/ BYTE                                          Unknown0x233c[0x4];
/*0x2360*/ int64_t                                       MercAAExp;                      // divide this with 3.30f and you get the percent - eqmule
/*0x2368*/ DWORD                                         MercAAPoints;                   // number of unspent merc AA points
/*0x236c*/ DWORD                                         MercAAPointsSpent;              // number of spent merc AA points
/*0x2370*/ ArrayClass<MercenaryAbilityInfo*>             MercenaryAbilities;
/*0x2380*/ HashTable<CompletedAchievementData, int, ResizePolicyNoShrink>         CompletedAchievements;
/*0x2390*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> CompletedEventBasedSubComponents;
/*0x23a0*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> OpenEventBasedSubComponents;
/*0x23b0*/ int                                           LastFellowshipJoin;
/*0x23b8*/ int64_t                                       Vitality;
/*0x23c0*/ int                                           AAVitality;
/*0x23c4*/ int                                           Unknown0x23a4;
/*0x23c8*/ int                                           FPStuff[0x1e];
/********************* PcBase End **********************/
/************ CharacterZoneClient Begin ****************/
/*0x2440*/ void*                                         PcClient_CharacterZoneClient_vfTable; // see 61FB6A Nov 02 2018 beta
/*0x2444*/ EQC_INFO*                                     eqc_info;
/*0x2448*/ SPAWNINFO*                                    pSpawn;                         // pSpawn_0
/*0x244c*/ bool                                          bUpdateStuff;
/*0x244d*/ bool                                          bZoningStatProcessing;
/*0x2450*/ DWORD                                         ArmorClassBonus;                // vtable2+10
/*0x2454*/ DWORD                                         CurrWeight;                     // vtable2+14
/*0x2458*/ int                                           LastHitPointSendPercent;
/*0x245c*/ int                                           LastManaPointSendPercent;
/*0x2460*/ int                                           LastEndurancePointSendPercent;
/*0x2464*/ DWORD                                         HPBonus;                        // vtable2+24
/*0x2468*/ DWORD                                         ManaBonus;                      // vtable2+28
/*0x246c*/ DWORD                                         EnduranceBonus;                 // vtable2+2c
/*0x2470*/ int                                           EnduranceCostPerSecond;
/*0x2474*/ DWORD                                         CombatEffectsBonus;             // vtable2+34 Combat Effects in UI
/*0x2478*/ DWORD                                         ShieldingBonus;                 // vtable2+38 Melee Shielding in UI
/*0x247c*/ DWORD                                         SpellShieldBonus;               // vtable2+3c Spell Shielding in UI
/*0x2480*/ DWORD                                         AvoidanceBonus;                 // vtable2+40 Avoidance in UI
/*0x2484*/ DWORD                                         AccuracyBonus;                  // vtable2+44 Accuracy in UI
/*0x2488*/ DWORD                                         StunResistBonus;                // vtable2+48 Stun Resist in UI
/*0x248c*/ DWORD                                         StrikeThroughBonus;             // vtable2+4c Strike Through in UI
/*0x2490*/ DWORD                                         DoTShieldBonus;                 // vtable2+50 Dot Shielding in UI
/*0x2494*/ DWORD                                         DamageShieldMitigationBonus;    // vtable2+54 Damage Shield Mitig in UI
/*0x2498*/ DWORD                                         DamageShieldBonus;              // vtable2+58 Damage Shielding in UI
/*0x249c*/ TSafeArrayStatic<int, 9>                      ItemSkillMinDamageMod;          // size 0x24
/*0x24c0*/ TSafeArrayStatic<int, 9>                      SkillMinDamageModBonus;         // size 0x24
/*0x24e4*/ DWORD                                         HeroicSTRBonus;                 // vtable2+a4
/*0x24e8*/ DWORD                                         HeroicINTBonus;                 // vtable2+a8
/*0x24ec*/ DWORD                                         HeroicWISBonus;                 // vtable2+ac
/*0x24f0*/ DWORD                                         HeroicAGIBonus;                 // vtable2+b0
/*0x24f4*/ DWORD                                         HeroicDEXBonus;                 // vtable2+b4
/*0x24f8*/ DWORD                                         HeroicSTABonus;                 // vtable2+b8
/*0x24fc*/ DWORD                                         HeroicCHABonus;                 // vtable2+bc
/*0x2500*/ DWORD                                         HealAmountBonus;                // vtable2+d8
/*0x2504*/ DWORD                                         SpellDamageBonus;               // vtable2+dc
/*0x2508*/ int                                           ItemHealAmountDotMod;
/*0x250c*/ int                                           ItemSpellDamageDotMod;
/*0x2510*/ DWORD                                         ClairvoyanceBonus;              // vtable2+e8
/*0x2514*/ DWORD                                         AttackBonus;                    // vtable2+ec
/*0x2518*/ DWORD                                         HPRegenBonus;                   // vtable2+f0
/*0x251c*/ DWORD                                         ManaRegenBonus;                 // vtable2+f4
/*0x2520*/ DWORD                                         EnduranceRegenBonus;            // vtable2+f8
/*0x2524*/ DWORD                                         AttackSpeed;                    // vtable2+fc
/*0x2528*/ int                                           NoBuffItemHitpointAdjustment;
/*0x252c*/ int                                           NoBuffItemManaAdjustment;
/*0x2530*/ int                                           NoBuffItemEnduranceAdjustment;
/*0x2534*/ int                                           NoBuffItemBaseChanceProc;
/*0x2538*/ int                                           NoBuffItemMinDamageMod;
/*0x253c*/ int                                           NoBuffItemInnateSpellRune;
/*0x2540*/ int                                           NoBuffItemAvoidance;
/*0x2544*/ int                                           NoBuffItemToHit;
/*0x2548*/ int                                           NoBuffItemResistStunChance;
/*0x254c*/ int                                           NoBuffItemDotShieldingEffect;
/*0x2550*/ int                                           NoBuffItemStrikeThroughChance;
/*0x2554*/ int                                           NoBuffItemAttack;
/*0x2558*/ int                                           NoBuffItemHitPointRegen;
/*0x255c*/ int                                           NoBuffItemManaRegen;
/*0x2560*/ int                                           NoBuffItemEnduranceRegen;
/*0x2564*/ int                                           NoBuffItemDamageShield;
/*0x2568*/ int                                           NoBuffItemDamageShieldMitigation;
/*0x256c*/ int                                           NoBuffItemHaste;
/*0x2570*/ TSafeArrayStatic<int, 9>                      NoBuffItemSkillMinDamageMod;    // size 0x24
/*0x2594*/ bool                                          bOutputHpRegen;
/*0x2595*/ bool                                          bInvulnerable;
/*0x2596*/ bool                                          bOnAVehicle;                    // 0x2420 + 0x156 see 4D94E8 in jun 11 2018 test
/*0x2598*/ SpellCache                                    spellCache;                     // size 0x58
/*0x25f0*/ HashListSet<int, 0x80>                        DoomEffectsBySlot;              // size 0x10 + (0x80 * 4)
/*0x2800*/ UINT                                          LastHitEval;
/*********************** CharacterZoneClient End ***********************/
/******************* PcZoneClient Begin ******************/
/*0x2804*/ void*                                         PcZoneClient_vfTable;           // see 61A04C jun 11 test 2018
/*0x2808*/ TSafeArrayStatic<unsigned long, 3>            Flags;                          // size 0xc
/*0x2814*/ uint32_t                                      TransfersReceived;
/*0x2818*/ int                                           LastLanguageSpoken;
/*0x281c*/ int                                           CurPowerSourceDrain;
/*0x2820*/ EQList<ALCHEMYBONUSSKILLDATA*>                AlchemyBaseSkillBonusList;
/*0x2830*/ UINT                                          MomentumBalance;
/*0x2834*/ UINT                                          LoyaltyRewardBalance;
/******************* PcZoneClient End ******************/
/******************* PCClient Begin ************************/
/*0x2838*/ ExtendedTargetList*                           pXTargetMgr;
/*0x283c*/ DWORD                                         InCombat;
/*0x2840*/ DWORD                                         Downtime;
/*0x2844*/ DWORD                                         DowntimeStamp;
/*0x2848*/ bool                                          bOverrideAvatarProximity;
/*0x284c*/ GROUPINFO*                                    pGroupInfo;
/*0x2850*/ bool                                          bIAmCreatingGroup;
/*0x2854*/ VeArray<VePointer<CONTENTS*>>                 ItemsPendingID;                 // size 0xc
/*0x2860*/ int                                           ParcelStatus;                   // eParcelStatus
/*0x2864*/ int                                           SubscriptionDays;               // 24BC for sure see 7A6C40 in may 11 2018 live exe
/*0x2868*/ short                                         BaseKeyRingSlots[4];
/*0x2870*/ bool                                          bPickZoneFewest;                // for sure see 4A424A in may 11 2018 live exe
/*0x2874*/ int                                           Unknown0x2874;
/*0x2878*/ int                                           Unknown0x2878;
/******************* PCClient End ************************/
/******************* CharacterBase Begin ************************/
/*0x287c*/ void*                                         CharacterBase_vftable;
/*0x2880*/ CProfileManager                               ProfileManager;
/*0x2888*/ TSafeArrayStatic<BYTE, 0x20>                  languages;
/*0x28a8*/ float                                         X;
/*0x28ac*/ float                                         Y;
/*0x28b0*/ float                                         Z;
/*0x28b4*/ float                                         Heading;
/*0x28b8*/ char                                          Name[0x40];                     // CharBaseBegin+44
/*0x28f8*/ char                                          Lastname[0x20];                 // CharBaseBegin+84
/*0x2918*/ TSafeString<0x80>                             Title;
/*0x2998*/ TSafeString<0x40>                             VehicleName;
/*0x29d8*/ BYTE                                          Stunned;                        // CharBaseBegin+104
/*0x29d9*/ BYTE                                          Unknown0x29a9[0x3];
/*0x29dc*/ uint16_t                                      zoneId;                         // CharBaseBegin+108 Zone_0
/*0x29de*/ uint16_t                                      instance;
/*0x29e0*/ BYTE                                          standstate;                     // CharBaseBegin+10c
/*0x29e4*/ RaidData                                      raidData;                       // size 0xdc
/*0x2ac0*/ DWORD                                         ExpansionFlags;                 // CharBaseBegin+464
/*0x2ac4*/ bool                                          bSuperPKILL;
/*0x2ac5*/ bool                                          bUnclone;
/*0x2ac6*/ bool                                          bDead;
/*0x2ac8*/ int                                           LD_Timer;
/*0x2acc*/ int                                           SpellInterruptCount;
/*0x2ad0*/ bool                                          bAutoSplit;
/*0x2ad1*/ bool                                          bTellsOff;
/*0x2ad2*/ bool                                          bGmInvis;
/*0x2ad4*/ int                                           KillMe;
/*0x2ad8*/ bool                                          CheaterLdFlag;                  // likely this is int SoulMarkCount instead.
/*0x2ad9*/ bool                                          NoRent;
/*0x2ada*/ bool                                          Corpse;
/*0x2adb*/ bool                                          ClientGmFlagSet;
/*0x2adc*/ DWORD                                         BankSharedPlat;                 // 31e4 CharBaseBegin+488
/*0x2ae0*/ DWORD                                         BankSharedGold;                 // CharBaseBegin+48c
/*0x2ae4*/ DWORD                                         BankSharedSilver;               // CharBaseBegin+490
/*0x2ae8*/ DWORD                                         BankSharedCopper;               // CharBaseBegin+494
/*0x2aec*/ DWORD                                         BankPlat;                       // CharBaseBegin+498
/*0x2af0*/ DWORD                                         BankGold;                       // CharBaseBegin+49c
/*0x2af4*/ DWORD                                         BankSilver;                     // CharBaseBegin+4a0
/*0x2af8*/ DWORD                                         BankCopper;                     // CharBaseBegin+4a4
/*0x2afc*/ int                                           STR;                            // CharBaseBegin+4a8
/*0x2b00*/ int                                           STA;                            // CharBaseBegin+4ac
/*0x2b04*/ int                                           CHA;                            // CharBaseBegin+4b0
/*0x2b08*/ int                                           DEX;                            // CharBaseBegin+4b4
/*0x2b0c*/ int                                           INT;                            // CharBaseBegin+4b8
/*0x2b10*/ int                                           AGI;                            // CharBaseBegin+4bc
/*0x2b14*/ int                                           WIS;                            // CharBaseBegin+4c0
/*0x2b18*/ int                                           LCK;                            // CharBaseBegin+4c4
/*0x2b1c*/ int                                           SavePoison;                     // CharBaseBegin+4c8
/*0x2b20*/ int                                           SaveMagic;                      // CharBaseBegin+4cc
/*0x2b24*/ int                                           SaveDisease;                    // CharBaseBegin+4d0
/*0x2b28*/ int                                           SaveCorruption;                 // CharBaseBegin+4d4
/*0x2b2c*/ int                                           SaveFire;                       // CharBaseBegin+4d8
/*0x2b30*/ int                                           SaveCold;                       // CharBaseBegin+4dc
/*0x2b34*/ int                                           SavePhysical;                   // CharBaseBegin+4e0
/*0x2b38*/ int                                           UncappedStr;
/*0x2b3c*/ int                                           UncappedSta;
/*0x2b40*/ int                                           UncappedCha;
/*0x2b44*/ int                                           UncappedDex;
/*0x2b48*/ int                                           UncappedInt;
/*0x2b4c*/ int                                           UncappedAgi;
/*0x2b50*/ int                                           UncappedWis;
/*0x2b54*/ int                                           UncappedResistPoison;
/*0x2b58*/ int                                           UncappedResistMagic;
/*0x2b5c*/ int                                           UncappedResistDisease;
/*0x2b60*/ int                                           UncappedResistCorruption;
/*0x2b64*/ int                                           UncappedResistFire;
/*0x2b68*/ int                                           UncappedResistCold;
/*0x2b6c*/ int                                           UncappedResistPhysical;
/*0x2b70*/ int                                           NoBuffStr;
/*0x2b74*/ int                                           NoBuffSta;
/*0x2b78*/ int                                           NoBuffCha;
/*0x2b7c*/ int                                           NoBuffDex;
/*0x2b80*/ int                                           NoBuffInt;
/*0x2b84*/ int                                           NoBuffAgi;
/*0x2b88*/ int                                           NoBuffWis;
/*0x2b8c*/ int                                           NoBuffResistPoison;
/*0x2b90*/ int                                           NoBuffResistMagic;
/*0x2b94*/ int                                           NoBuffResistDisease;
/*0x2b98*/ int                                           NoBuffResistCorruption;
/*0x2b9c*/ int                                           NoBuffResistFire;
/*0x2ba0*/ int                                           NoBuffResistCold;
/*0x2ba4*/ int                                           NoBuffResistPhysical;
/*0x2ba8*/
};

//============================================================================
// CHARINFO2 a.k.a. PcProfile
//============================================================================

#if !USE_NEW_PCPROFILE
//aSdeityD CharInfo2__CharInfo2
#define CHARINFO2_Size 0xAE68 // Jul 08 2019 test (see 8A2EB9) - eqmule

struct [[offsetcomments]] CHARINFO2
{
/******************************** BaseProfile Start ********************************/
/*0x0000*/ BYTE                                            Unknown0x0000[0x10];
/*0x0010*/ DWORD                                           BaseProfile;
/*0x0014*/ BYTE                                            Unknown0x0014[0x8];
/*0x001c*/ INVENTORYARRAY*                                 pInventoryArray;
/*0x0020*/ BYTE                                            Unknown0x0020[0x48];
/*0x0068*/ SPELLBUFF                                       Buff[NUM_LONG_BUFFS];                   // EQ_Affect size is 0x68 * 0x2a = 0x1110
/*0x1178*/ SPELLBUFF                                       ShortBuff[NUM_SHORT_BUFFS];             // EQ_Affect size is 0x68 * 0x37 = 0x1658
/*0x27d0*/ int                                             SpellBook[NUM_BOOK_SLOTS];
/*0x36d0*/ DWORD                                           MemorizedSpells[0x12];
/*0x3718*/ DWORD                                           Skill[NUM_SKILLS];
/*0x38a8*/ DWORD                                           InnateSkill[0x19];
/*0x390c*/ TSafeArrayStatic<ArmorProperties, 9>            ArmorProps;                             // size 0xb4
/*0x39c0*/ TSafeArrayStatic<DWORD, 9>                      CharacterTint;                          // size 0x24
/*0x39e4*/ BYTE                                            Gender;
/*0x39e8*/ DWORD                                           Race;
/*0x39ec*/ DWORD                                           Class;
/*0x39f0*/ HashTable<int>                                  properties;
/*0x3a00*/ DWORD                                           Level;
/*0x3a04*/ DWORD                                           Mana;
/*0x3a08*/ DWORD                                           Endurance;
/*0x3a10*/ int64_t                                         BaseHP;
/*0x3a18*/ DWORD                                           BaseSTR;
/*0x3a1c*/ DWORD                                           BaseSTA;
/*0x3a20*/ DWORD                                           BaseCHA;
/*0x3a24*/ DWORD                                           BaseDEX;
/*0x3a28*/ DWORD                                           BaseINT;
/*0x3a2c*/ DWORD                                           BaseAGI;
/*0x3a30*/ DWORD                                           BaseWIS;
/*0x3a34*/ BYTE                                            Face;
/*0x3a38*/ DWORD                                           Plat;
/*0x3a3c*/ DWORD                                           Gold;
/*0x3a40*/ DWORD                                           Silver;
/*0x3a44*/ DWORD                                           Copper;
/*0x3a48*/ DWORD                                           CursorPlat;
/*0x3a4c*/ DWORD                                           CursorGold;
/*0x3a50*/ DWORD                                           CursorSilver;
/*0x3a54*/ DWORD                                           CursorCopper;
/*0x3a58*/ int                                             _max_allowed_spell_slots;
/*0x3a5c*/ int                                             practices;
/*0x3a60*/ int                                             height;
/*0x3a64*/ int                                             width;
/*0x3a68*/ int                                             length;
/*0x3a6c*/ int                                             view_height;
/*0x3a70*/ char                                            texture_type;
/*0x3a71*/ char                                            m_armorMat;
/*0x3a72*/ char                                            m_armorVariation;
/*0x3a73*/ char                                            headType;
/*0x3a74*/ char                                            caneditface;
/*0x3a78*/ int                                             DisciplineTimer;
/*0x3a7c*/ UINT                                            MendTimer;
/*0x3a80*/ int                                             ForageTimer;
/*0x3a84*/ int                                             thirstlevel;
/*0x3a88*/ int                                             hungerlevel;
/*0x3a8c*/ int                                             PotionCount;
/*0x3a90*/ int                                             profileType;                            // enum PT_Main = 0, PT_Alt, PT_MonsterMission, PT_TypeUnknown
/*0x3a94*/ int                                             Shrouded;                               // templateId
/*0x3a98*/ int                                             systemId;
/*0x3a9c*/ int                                             designId;
/*0x3aa0*/ int                                             InventorySlotBitmask;
/*0x3aa4*/ UINT                                            CurrentProgressionID;
/*0x3aa8*/ BYTE                                            Unknown0x3c28[0x54];
/*0x3afc*/ int                                             ParentId;
/*0x3b00*/ int                                             TattooIndex;
/*0x3b04*/ int                                             FacialAttachmentIndex;
/******************************** BaseProfile End ********************************/
/******************************** PcProfile Start ********************************/
/*0x3b08*/ TSafeArrayStatic<WorldLocation, 5>              BoundLocations;                         // size 0x64 home_zone
/*0x3b6c*/ TSafeArrayStatic<ArmorProperties, 0x16>         ArmorType;
/*0x3d24*/ TSafeArrayStatic<AALIST, AA_CHAR_MAX_REAL>      AAList;                                 // AlternateAbilities
/*0x4b34*/ TSafeArrayStatic<DWORD, 0x9>                    BodyColor;
/*0x4b58*/ TSafeArrayStatic<int, 0x800>                    FactionTable;                           // factiontable
/*0x6b58*/ TSafeArrayStatic<int, NUM_COMBAT_ABILITIES>     CombatAbilities;                        // KnownCombatAbilities
/*0x7008*/ TSafeArrayStatic<UINT, 0xF>                     SpellRecastTimer;                       // spell_used
/*0x7044*/ TSafeArrayStatic<UINT, 0x19>                    CombatAbilityTimers;                    // fs
/*0x70a8*/ TList<CombatAbilityTimer>                       CombatAbilityTimersList;                // size 8 for sure CombatAbilityTimersAddl
/*0x70b0*/ TSafeArrayStatic<UINT, 0x19>                    LinkedSpellTimers;                      // for sure, we used to call thius CombatAbilityTimes...
/*0x7114*/ TSafeArrayStatic<UINT, 0x64>                    ItemRecastTimers;                       // for sure
/*0x72a4*/ TSafeArrayStatic<UINT, 0x64>                    AATimers;                               // for sure
/*0x7434*/ TSafeArrayStatic<BandolierSet, 0x14>            Bandolier;                              // size 0x1900 = 0x140 * 0x14 for sure see 8DE476 Jan 04 2019 test
/*0x8d34*/ TSafeArrayStatic<BenefitSelection, 5>           ActiveTributeBenefits;                  // size 0x28 = 8 * 5 for sure see 8DE437 Jan 04 2019 test
/*0x8d5c*/ TSafeArrayStatic<BenefitSelection, 0xa>         ActiveTrophyTributeBenefits;            // size 0x50 = 8 * 0xa
/*0x8dac*/ ItemBaseContainer                               GuildTributeBenefitItems;               // size 0x1c for sure see 8C9D9C in 21 Sep 2018
/*0x8dc8*/ ItemBaseContainer                               GuildTrophyTributeBenefitItems;         // size 0x1c
/*0x8de4*/ ArrayClass<CXStr>                               MercenarySaveStrings;                   // size 0x10
/*0x8df4*/ AssociatedNPCSaveStringNode*                    PetSaveString;                          // for sure
/*0x8df8*/ DWORD                                           Deity;                                  // fs see 8DE504 Jan 04 2019 test
/*0x8dfc*/ bool                                            bPVPFlag;
/*0x8dfd*/ BYTE                                            HighestLevel;
/*0x8e00*/ DWORD                                           Drunkenness;                            // inebriation
/*0x8e04*/ BYTE                                            HairColor;
/*0x8e05*/ BYTE                                            BeardColor;
/*0x8e08*/ int                                             NpcTintIndex;
/*0x8e0c*/ BYTE                                            LeftEye;
/*0x8e0d*/ BYTE                                            RightEye;
/*0x8e0e*/ BYTE                                            Hair;
/*0x8e0f*/ BYTE                                            Beard;
/*0x8e10*/ BYTE                                            OldFace;
/*0x8e14*/ DWORD                                           AAPoints;
/*0x8e18*/ char                                            PocketPetSaveString[0x2000];            // 0x1000 in older clients
/*0xae18*/ CXStr                                           ItemBuffer;
/*0xae1c*/ UINT                                            LastShield;
/*0xae20*/ bool                                            bSneak;
/*0xae21*/ bool                                            bHide;
/*0xae24*/ DWORD                                           AAPointsSpent;
/*0xae28*/ DWORD                                           AAPointsAssigned[6];                    // none, general, arch, class, special, focus, merc
/*0xae40*/ void*                                           pPetData;                               // PetObjectData todo fill in
/*0xae44*/ DWORD                                           PrimActor;
/*0xae48*/ DWORD                                           SecdActor;
/*0xae4c*/ bool                                            bUseTemplateFaction;
/*0xae50*/ DWORD                                           TitlePrefixID;
/*0xae54*/ DWORD                                           TitleSuffixID;
/*0xae58*/ bool                                            bAreHandsMagic;
/*0xae5c*/ DWORD                                           SoleEnabledZoneID;
/*0xae60*/ DWORD                                           NewBodyTint;
/*0xae64*/ DWORD                                           CurrentMercenaryIndex;
/*0xae68*/
/******************************** PcProfile End ********************************/
};
using PCHARINFO2 [[deprecated]] = CHARINFO2*;

#if !defined(NEWCHARINFO)
struct [[offsetcomments]] CI2_INFO
{
	FORCE_SYMBOLS;

/*0x00*/ eProfileListType ListType;
/*0x04*/ CHARINFO2* pCharInfo2;
/*0x08*/ CHARINFO2* pLast;
/*0x0c*/ CHARINFO2* pNext;
/*0x10*/ CHARINFO2* pPrev;
/*0x14*/
};
using PCI2_INFO = CI2_INFO*;

#endif // !defined(NEWCHARINFO)

#endif // USE_NEW_PCPROFILE

//============================================================================
// EQ_PC
//============================================================================

struct [[offsetcomments]] ItemContainingRealEstate
{
	FORCE_SYMBOLS;

/*0x00*/ int                RealEstateID;
/*0x04*/ ItemGlobalIndex    ItemLocation;
/*0x10*/
};

//============================================================================
// ProfileManager
//============================================================================

class ProfileManager
{
public:
	EQLIB_OBJECT BaseProfile* GetCurrentProfile();
};

//============================================================================
// BaseProfile
//============================================================================

class [[offsetcomments]] BaseProfile
{
public:
	EQLIB_OBJECT VePointer<CONTENTS> GetItemPossession(const ItemIndex& index) const;

/*0x0000*/ BYTE                                            Unknown0x0000[0x10];
/*0x0010*/ DWORD                                           BaseProfile;
/*0x0014*/ BYTE                                            Unknown0x0014[0x8];
/*0x001c*/ INVENTORYARRAY*                                 pInventoryArray;                        // This is a VePointer
/*0x0020*/ BYTE                                            Unknown0x0020[0x48];
/*0x0068*/ SPELLBUFF                                       Buff[NUM_LONG_BUFFS];                   // EQ_Affect size is 0x68 * 0x2a = 0x1110
/*0x1178*/ SPELLBUFF                                       ShortBuff[NUM_SHORT_BUFFS];             // EQ_Affect size is 0x68 * 0x37 = 0x1658
/*0x27d0*/ int                                             SpellBook[NUM_BOOK_SLOTS];
/*0x36d0*/ DWORD                                           MemorizedSpells[MAX_MEMORIZED_SPELLS];
/*0x3718*/ DWORD                                           Skill[NUM_SKILLS];
/*0x38a8*/ DWORD                                           InnateSkill[NUM_INNATE];
/*0x390c*/ TSafeArrayStatic<ArmorProperties, 9>            ArmorProps;                             // size 0xb4
/*0x39c0*/ TSafeArrayStatic<DWORD, 9>                      CharacterTint;                          // size 0x24
/*0x39e4*/ BYTE                                            Gender;
/*0x39e8*/ DWORD                                           Race;
/*0x39ec*/ int                                             Class;
/*0x39f0*/ HashTable<int>                                  properties;
/*0x3a00*/ DWORD                                           Level;
/*0x3a04*/ DWORD                                           Mana;
/*0x3a08*/ DWORD                                           Endurance;
/*0x3a10*/ int64_t                                         BaseHP;
/*0x3a18*/ DWORD                                           BaseSTR;
/*0x3a1c*/ DWORD                                           BaseSTA;
/*0x3a20*/ DWORD                                           BaseCHA;
/*0x3a24*/ DWORD                                           BaseDEX;
/*0x3a28*/ DWORD                                           BaseINT;
/*0x3a2c*/ DWORD                                           BaseAGI;
/*0x3a30*/ DWORD                                           BaseWIS;
/*0x3a34*/ BYTE                                            Face;
/*0x3a38*/ DWORD                                           Plat;
/*0x3a3c*/ DWORD                                           Gold;
/*0x3a40*/ DWORD                                           Silver;
/*0x3a44*/ DWORD                                           Copper;
/*0x3a48*/ DWORD                                           CursorPlat;
/*0x3a4c*/ DWORD                                           CursorGold;
/*0x3a50*/ DWORD                                           CursorSilver;
/*0x3a54*/ DWORD                                           CursorCopper;
/*0x3a58*/ int                                             _max_allowed_spell_slots;
/*0x3a5c*/ int                                             practices;
/*0x3a60*/ int                                             height;
/*0x3a64*/ int                                             width;
/*0x3a68*/ int                                             length;
/*0x3a6c*/ int                                             view_height;
/*0x3a70*/ char                                            texture_type;
/*0x3a71*/ char                                            m_armorMat;
/*0x3a72*/ char                                            m_armorVariation;
/*0x3a73*/ char                                            headType;
/*0x3a74*/ char                                            caneditface;
/*0x3a78*/ int                                             DisciplineTimer;
/*0x3a7c*/ UINT                                            MendTimer;
/*0x3a80*/ int                                             ForageTimer;
/*0x3a84*/ int                                             thirstlevel;
/*0x3a88*/ int                                             hungerlevel;
/*0x3a8c*/ int                                             PotionCount;
/*0x3a90*/ int                                             profileType;                            // enum PT_Main = 0, PT_Alt, PT_MonsterMission, PT_TypeUnknown
/*0x3a94*/ int                                             Shrouded;                               // templateId
/*0x3a98*/ int                                             systemId;
/*0x3a9c*/ int                                             designId;
/*0x3aa0*/ int                                             InventorySlotBitmask;
/*0x3aa4*/ UINT                                            CurrentProgressionID;
/*0x3aa8*/ BYTE                                            Unknown0x3c28[0x54];
/*0x3afc*/ int                                             ParentId;
/*0x3b00*/ int                                             TattooIndex;
/*0x3b04*/ int                                             FacialAttachmentIndex;
/*0x3b08*/
};

//============================================================================
// PcProfile
//============================================================================

constexpr int MAX_BANDOLIER_ITEMS = 20;

class [[offsetcomments]] PcProfile : public BaseProfile
{
public:
/*0x3b08*/ TSafeArrayStatic<WorldLocation, 5>              BoundLocations;                         // size 0x64 home_zone
/*0x3b6c*/ TSafeArrayStatic<ArmorProperties, 0x16>         ArmorType;
/*0x3d24*/ TSafeArrayStatic<AALIST, AA_CHAR_MAX_REAL>      AAList;                                 // AlternateAbilities
/*0x4b34*/ TSafeArrayStatic<DWORD, 0x9>                    BodyColor;
/*0x4b58*/ TSafeArrayStatic<int, 0x800>                    FactionTable;                           // factiontable
/*0x6b58*/ TSafeArrayStatic<int, NUM_COMBAT_ABILITIES>     CombatAbilities;                        // KnownCombatAbilities
/*0x7008*/ TSafeArrayStatic<UINT, 0xF>                     SpellRecastTimer;                       // spell_used
/*0x7044*/ TSafeArrayStatic<UINT, 0x19>                    CombatAbilityTimers;                    // fs
/*0x70a8*/ TList<CombatAbilityTimer>                       CombatAbilityTimersList;                // size 8 for sure CombatAbilityTimersAddl
/*0x70b0*/ TSafeArrayStatic<UINT, 0x19>                    LinkedSpellTimers;                      // for sure, we used to call thius CombatAbilityTimes...
/*0x7114*/ TSafeArrayStatic<UINT, 0x64>                    ItemRecastTimers;                       // for sure
/*0x72a4*/ TSafeArrayStatic<UINT, 0x64>                    AATimers;                               // for sure
/*0x7434*/ TSafeArrayStatic<BandolierSet, MAX_BANDOLIER_ITEMS> Bandolier;                              // size 0x1900 = 0x140 * 0x14 for sure see 8DE476 Jan 04 2019 test
/*0x8d34*/ TSafeArrayStatic<BenefitSelection, 5>           ActiveTributeBenefits;                  // size 0x28 = 8 * 5 for sure see 8DE437 Jan 04 2019 test
/*0x8d5c*/ TSafeArrayStatic<BenefitSelection, 0xa>         ActiveTrophyTributeBenefits;            // size 0x50 = 8 * 0xa
/*0x8dac*/ ItemBaseContainer                               GuildTributeBenefitItems;               // size 0x1c for sure see 8C9D9C in 21 Sep 2018
/*0x8dc8*/ ItemBaseContainer                               GuildTrophyTributeBenefitItems;         // size 0x1c
/*0x8de4*/ ArrayClass<CXStr>                               MercenarySaveStrings;                   // size 0x10
/*0x8df4*/ AssociatedNPCSaveStringNode*                    PetSaveString;                          // for sure
/*0x8df8*/ DWORD                                           Deity;                                  // fs see 8DE504 Jan 04 2019 test
/*0x8dfc*/ bool                                            bPVPFlag;
/*0x8dfd*/ BYTE                                            HighestLevel;
/*0x8e00*/ DWORD                                           Drunkenness;                            // inebriation
/*0x8e04*/ BYTE                                            HairColor;
/*0x8e05*/ BYTE                                            BeardColor;
/*0x8e08*/ int                                             NpcTintIndex;
/*0x8e0c*/ BYTE                                            LeftEye;
/*0x8e0d*/ BYTE                                            RightEye;
/*0x8e0e*/ BYTE                                            Hair;
/*0x8e0f*/ BYTE                                            Beard;
/*0x8e10*/ BYTE                                            OldFace;
/*0x8e14*/ DWORD                                           AAPoints;
/*0x8e18*/ char                                            PocketPetSaveString[0x2000];            // 0x1000 in older clients
/*0xae18*/ CXStr                                           ItemBuffer;
/*0xae1c*/ UINT                                            LastShield;
/*0xae20*/ bool                                            bSneak;
/*0xae21*/ bool                                            bHide;
/*0xae24*/ DWORD                                           AAPointsSpent;
/*0xae28*/ DWORD                                           AAPointsAssigned[6];                    // none, general, arch, class, special, focus, merc
/*0xae40*/ void*                                           pPetData;                               // PetObjectData todo fill in
/*0xae44*/ DWORD                                           PrimActor;
/*0xae48*/ DWORD                                           SecdActor;
/*0xae4c*/ bool                                            bUseTemplateFaction;
/*0xae50*/ DWORD                                           TitlePrefixID;
/*0xae54*/ DWORD                                           TitleSuffixID;
/*0xae58*/ bool                                            bAreHandsMagic;
/*0xae5c*/ DWORD                                           SoleEnabledZoneID;
/*0xae60*/ DWORD                                           NewBodyTint;
/*0xae64*/ DWORD                                           CurrentMercenaryIndex;
/*0xae68*/

	// force symbols for this struct
	EQLIB_OBJECT void dummy() {}
};

#if USE_NEW_PCPROFILE
using CHARINFO2 [[deprecated]] = PcProfile;
using PCHARINFO2 [[deprecated]] = PcProfile*;
#endif

//============================================================================
// CharacterBase
//============================================================================

// ItemBaseContainer::CheckDepthOptions
enum GILocationOption
{
	Bag_Or_Base,
	Socket
};

class [[offsetcomments]] CharacterBase
{
public:
/*0x000*/ void*                       CharacterBase_vftable;
/*0x004*/ CProfileManager             ProfileManager;
/*0x00c*/ TSafeArrayStatic<BYTE, 0x20> languages;
/*0x02c*/ float                       X;
/*0x030*/ float                       Y;
/*0x034*/ float                       Z;
/*0x038*/ float                       Heading;
/*0x03c*/ TSafeString<0x40>           Name;
/*0x07c*/ TSafeString<0x20>           Lastname;
/*0x09c*/ TSafeString<0x80>           Title;
/*0x11c*/ TSafeString<0x40>           VehicleName;
/*0x15c*/ char                        Stunned;                      // well status really
/*0x160*/ EQZoneIndex                 zoneId;
/*0x164*/ BYTE                        standstate;
/*0x168*/ RaidData                    raidData;
/*0x244*/ int                         ExpansionFlags;
/*0x248*/ bool                        bSuperPKILL;
/*0x249*/ bool                        bUnclone;
/*0x24a*/ bool                        bDead;
/*0x24c*/ int                         LD_Timer;
/*0x250*/ int                         SpellInterruptCount;
/*0x254*/ bool                        bAutoSplit;
/*0x255*/ bool                        bTellsOff;
/*0x256*/ bool                        bGmInvis;
/*0x258*/ int                         KillMe;
/*0x25c*/ bool                        CheaterLdFlag;                // likely this is int SoulMarkCount instead.
/*0x25d*/ bool                        NoRent;
/*0x25e*/ bool                        Corpse;
/*0x25f*/ bool                        ClientGmFlagSet;
/*0x260*/ int                         BankSharedPlat;               // 31e4 CharBaseBegin+488
/*0x264*/ int                         BankSharedGold;               // CharBaseBegin+48c
/*0x268*/ int                         BankSharedSilver;             // CharBaseBegin+490
/*0x26c*/ int                         BankSharedCopper;             // CharBaseBegin+494
/*0x270*/ int                         BankPlat;                     // CharBaseBegin+498
/*0x274*/ int                         BankGold;                     // CharBaseBegin+49c
/*0x278*/ int                         BankSilver;                   // CharBaseBegin+4a0
/*0x27c*/ int                         BankCopper;                   // CharBaseBegin+4a4
/*0x280*/ int                         STR;                          // CharBaseBegin+4a8
/*0x284*/ int                         STA;                          // CharBaseBegin+4ac
/*0x288*/ int                         CHA;                          // CharBaseBegin+4b0
/*0x28c*/ int                         DEX;                          // CharBaseBegin+4b4
/*0x290*/ int                         INT;                          // CharBaseBegin+4b8
/*0x294*/ int                         AGI;                          // CharBaseBegin+4bc
/*0x298*/ int                         WIS;                          // CharBaseBegin+4c0
/*0x29c*/ int                         SavePoison;                   // CharBaseBegin+4c4
/*0x2a0*/ int                         SaveMagic;                    // CharBaseBegin+4c8
/*0x2a4*/ int                         SaveDisease;                  // CharBaseBegin+4cc
/*0x2a8*/ int                         SaveCorruption;               // CharBaseBegin+4d0
/*0x2ac*/ int                         SaveFire;                     // CharBaseBegin+4d4
/*0x2b0*/ int                         SaveCold;                     // CharBaseBegin+4d8
/*0x2b4*/ int                         SavePhysical;
/*0x2b8*/ int                         UncappedStr;
/*0x2bc*/ int                         UncappedSta;
/*0x2c0*/ int                         UncappedCha;
/*0x2c4*/ int                         UncappedDex;
/*0x2c8*/ int                         UncappedInt;
/*0x2cc*/ int                         UncappedAgi;
/*0x2d0*/ int                         UncappedWis;
/*0x2d4*/ int                         UncappedResistPoison;
/*0x2d8*/ int                         UncappedResistMagic;
/*0x2dc*/ int                         UncappedResistDisease;
/*0x2e0*/ int                         UncappedResistCorruption;
/*0x2e4*/ int                         UncappedResistFire;
/*0x2e8*/ int                         UncappedResistCold;
/*0x2ec*/ int                         UncappedResistPhysical;
/*0x2f0*/ int                         NoBuffStr;
/*0x2f4*/ int                         NoBuffSta;
/*0x2f8*/ int                         NoBuffCha;
/*0x2fc*/ int                         NoBuffDex;
/*0x300*/ int                         NoBuffInt;
/*0x304*/ int                         NoBuffAgi;
/*0x308*/ int                         NoBuffWis;
/*0x30c*/ int                         NoBuffResistPoison;
/*0x310*/ int                         NoBuffResistMagic;
/*0x314*/ int                         NoBuffResistDisease;
/*0x318*/ int                         NoBuffResistCorruption;
/*0x31c*/ int                         NoBuffResistFire;
/*0x320*/ int                         NoBuffResistCold;
/*0x324*/ int                         NoBuffResistPhysical;
/*0x328*/

	EQLIB_OBJECT unsigned int GetEffectId(int index);

	EQLIB_OBJECT LONG GetMemorizedSpell(int gem);             // 0-0xf this func returns the spellid for whatever is in the gem

	EQLIB_OBJECT ItemGlobalIndex CreateItemGlobalIndex(int Slot0, int Slot1 = -1, int Slot2 = -1);
	EQLIB_OBJECT ItemIndex CreateItemIndex(int Slot0, int Slot1 = -1, int Slot2 = -1);

	EQLIB_OBJECT const BaseProfile& GetCurrentBaseProfile() const
	{
		return *ProfileManager.GetCurrentProfile();
	}

	EQLIB_OBJECT BYTE GetLanguageSkill(int) const;
	EQLIB_OBJECT VePointer<CONTENTS> GetItemByGlobalIndex(const ItemGlobalIndex& GlobalIndex) const;
	EQLIB_OBJECT VePointer<CONTENTS> GetItemByGlobalIndex(const ItemGlobalIndex& GlobalIndex, GILocationOption Option) const;
	EQLIB_OBJECT VePointer<CONTENTS> GetItemPossession(const ItemIndex& lIndex) const;
};

class [[offsetcomments(0x2418)]] CharacterZoneClient : virtual public CharacterBase
{
	/*0x2418*/ virtual void vftableph() {};
public:
	union {
/*0x2420*/ PlayerClient*               me;                 // just here for comparing the 2, todo: fix
/*0x2420*/ SPAWNINFO*                  me2;
	};
/*0x2424*/ bool                        bUpdateStuff;
/*0x2425*/ bool                        bZoningStatProcessing;
/*0x2428*/ DWORD                       ArmorClassBonus;              // vtable2+10
/*0x242c*/ DWORD                       CurrWeight;                   // vtable2+14
/*0x2430*/ int                         LastHitPointSendPercent;
/*0x2434*/ int                         LastManaPointSendPercent;
/*0x2438*/ int                         LastEndurancePointSendPercent;
/*0x243c*/ DWORD                       HPBonus;                      // vtable2+24
/*0x2440*/ DWORD                       ManaBonus;                    // vtable2+28
/*0x2444*/ DWORD                       EnduranceBonus;               // vtable2+2c
/*0x2448*/ BYTE                        Unknown0x2450[0x4];
/*0x244c*/ DWORD                       CombatEffectsBonus;           // vtable2+34 Combat Effects in UI
/*0x2450*/ DWORD                       ShieldingBonus;               // vtable2+38 Melee Shielding in UI
/*0x2454*/ DWORD                       SpellShieldBonus;             // vtable2+3c Spell Shielding in UI
/*0x2458*/ DWORD                       AvoidanceBonus;               // vtable2+40 Avoidance in UI
/*0x245c*/ DWORD                       AccuracyBonus;                // vtable2+44 Accuracy in UI
/*0x2460*/ DWORD                       StunResistBonus;              // vtable2+48 Stun Resist in UI
/*0x2464*/ DWORD                       StrikeThroughBonus;           // vtable2+4c Strike Through in UI
/*0x2468*/ DWORD                       DoTShieldBonus;               // vtable2+50 Dot Shielding in UI
/*0x246c*/ DWORD                       DamageShieldMitigationBonus;  // vtable2+54 Damage Shield Mitig in UI
/*0x2470*/ DWORD                       DamageShieldBonus;            // vtable2+58 Damage Shielding in UI
/*0x2474*/ TSafeArrayStatic<int, 9>    ItemSkillMinDamageMod;
/*0x2498*/ TSafeArrayStatic<int, 9>    SkillMinDamageModBonus;
/*0x24bc*/ DWORD                       HeroicSTRBonus;               // vtable2+a4
/*0x24c0*/ DWORD                       HeroicINTBonus;               // vtable2+a8
/*0x24c4*/ DWORD                       HeroicWISBonus;               // vtable2+ac
/*0x24c8*/ DWORD                       HeroicAGIBonus;               // vtable2+b0
/*0x24cc*/ DWORD                       HeroicDEXBonus;               // vtable2+b4
/*0x24d0*/ DWORD                       HeroicSTABonus;               // vtable2+b8
/*0x24d4*/ DWORD                       HeroicCHABonus;               // vtable2+bc
/*0x24d8*/ DWORD                       HealAmountBonus;              // vtable2+d8
/*0x24dc*/ DWORD                       SpellDamageBonus;             // vtable2+dc
/*0x24e0*/ int                         ItemHealAmountDotMod;
/*0x24e4*/ int                         ItemSpellDamageDotMod;
/*0x24e8*/ DWORD                       ClairvoyanceBonus;            // vtable2+e8
/*0x24ec*/ DWORD                       AttackBonus;                  // vtable2+ec
/*0x24f0*/ DWORD                       HPRegenBonus;                 // vtable2+f0
/*0x24f4*/ DWORD                       ManaRegenBonus;               // vtable2+f4
/*0x24f8*/ DWORD                       EnduranceRegenBonus;          // vtable2+f8
/*0x24fc*/ DWORD                       AttackSpeed;                  // vtable2+fc
/*0x2500*/ int                         NoBuffItemHitpointAdjustment;
/*0x2504*/ int                         NoBuffItemManaAdjustment;
/*0x2508*/ int                         NoBuffItemEnduranceAdjustment;
/*0x250c*/ int                         NoBuffItemBaseChanceProc;
/*0x2510*/ int                         NoBuffItemMinDamageMod;
/*0x2514*/ int                         NoBuffItemInnateSpellRune;
/*0x2518*/ int                         NoBuffItemAvoidance;
/*0x251c*/ int                         NoBuffItemToHit;
/*0x2520*/ int                         NoBuffItemResistStunChance;
/*0x2524*/ int                         NoBuffItemDotShieldingEffect;
/*0x2528*/ int                         NoBuffItemStrikeThroughChance;
/*0x252c*/ int                         NoBuffItemAttack;
/*0x2530*/ int                         NoBuffItemHitPointRegen;
/*0x2534*/ int                         NoBuffItemManaRegen;
/*0x2538*/ int                         NoBuffItemEnduranceRegen;
/*0x253c*/ int                         NoBuffItemDamageShield;
/*0x2540*/ int                         NoBuffItemDamageShieldMitigation;
/*0x2544*/ int                         NoBuffItemHaste;
/*0x2548*/ TSafeArrayStatic<int, 9>    NoBuffItemSkillMinDamageMod;  // size 0x24
/*0x256c*/ bool                        bOutputHpRegen;
/*0x256d*/ bool                        bInvulnerable;
/*0x256e*/ bool                        bOnAVehicle;
/*0x2570*/ SpellCache                  spellCache;                   // size 0x58
/*0x25c8*/ HashListSet<int, 0x80>      DoomEffectsBySlot;            // size 0x10 + (0x80* 4)
/*0x27d8*/ UINT                        LastHitEval;
/*0x27dc*/

	EQLIB_OBJECT CharacterZoneClient();
	EQLIB_OBJECT int CalcAffectChange(const EQ_Spell* spell, BYTE casterLevel, BYTE affextIndex, const EQ_Affect* theAffect, int EffectIndex = 0, PlayerZoneClient* pCaster = NULL, bool overrideChangeVal = false, int ChangeVal = -1, bool bCap = true);
	EQLIB_OBJECT int CalcAffectChangeGeneric(const EQ_Spell* spell, BYTE casterLevel, BYTE affextIndex, const EQ_Affect* theAffect, int EffectIndex, bool bCap = true);
	EQLIB_OBJECT void MakeMeVisible(int, bool);
	EQLIB_OBJECT int GetItemCountWorn(int);
	EQLIB_OBJECT int GetItemCountInInventory(int);
	EQLIB_OBJECT int GetCursorItemCount(int);
	EQLIB_OBJECT bool HasSkill(int);
	EQLIB_OBJECT EQ_Affect* FindAffectSlot(int SpellID, SPAWNINFO* Caster, int* slindex, bool bJustTest, int CasterLevel = -1, EQ_Affect* BuffArray = nullptr, int BuffArraySize = 0, bool bFailAltAbilities = true);
	EQLIB_OBJECT EQ_Affect* FindAffectSlotMine(int SpellID, SPAWNINFO* Caster, int* slindex, bool bJustTest, int CasterLevel = -1, EQ_Affect* BuffArray = nullptr, int BuffArraySize = 0, bool bFailAltAbilities = true);
	EQLIB_OBJECT bool IsStackBlocked(const EQ_Spell* pSpell, SPAWNINFO* pCaster, EQ_Affect* pEffecs = NULL, int EffectsSize = 0, bool bMessageOn = false);
	EQLIB_OBJECT int BardCastBard(const EQ_Spell* pSpell, signed int caster_class) const;
	EQLIB_OBJECT unsigned char GetMaxEffects() const;
	EQLIB_OBJECT EQ_Affect& GetEffect(int) const;
	EQLIB_OBJECT int GetOpenEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill, int Index = -1);
	EQLIB_OBJECT int GetFirstEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill);
	EQLIB_OBJECT int GetLastEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill, bool bIsDisplay = false);
	EQLIB_OBJECT const int GetFocusReuseMod(const EQ_Spell* pSpell, VePointer<CONTENTS>& pOutItem);
	EQLIB_OBJECT bool FindItemByGuid(const EqItemGuid& ItemGuid, int* pos_slot, int* con_slot);
	EQLIB_OBJECT BYTE FindItemByRecord(int ItemNumber, int* pos_slot, int* con_slot, bool bReverseLookup);

	// From EQ_Character1
	EQLIB_OBJECT int GetEnduranceRegen(bool bIncItemsAndBuffs, bool bCombat);
	EQLIB_OBJECT int GetHPRegen(bool bIncItemsAndBuffs, bool* bIsBleeding/*no you shouldnt set this, its an OUT value.*/, bool bCombat);
	EQLIB_OBJECT int GetManaRegen(bool bIncItemsAndBuffs, bool bCombat);
	EQLIB_OBJECT int Cur_HP(int Spawntype/*PC = 0 NPC=1 and so on*/, bool bCapAtMax = true);
	EQLIB_OBJECT int Max_Endurance(bool bCapAtMax = true);
	EQLIB_OBJECT int Max_HP(int SpawnType, bool bCapAtMax = true);
	EQLIB_OBJECT int Max_Mana(bool bCapAtMax = true);
	EQLIB_OBJECT const int GetCastingTimeModifier(const EQ_Spell* pSpell);//used to get aa modifiers
	EQLIB_OBJECT const int GetFocusCastingTimeModifier(const EQ_Spell* pSpell, VePointer<CONTENTS>& pItemOut, bool bEvalOnly = false);
	// int const GetFocusCastingTimeModifier(class EQ_Spell const*, class EQ_Equipment**, int);
	EQLIB_OBJECT unsigned char CastSpell(unsigned char gemid, int spellid, EQ_Item** ppItem, const ItemGlobalIndex& itemLoc, ItemSpellTypes slot, unsigned char spell_loc, int arg7, int arg8, int arg9, bool arg10);
	EQLIB_OBJECT void SetEffectId(unsigned char, unsigned int);
	EQLIB_OBJECT void StopSpellCast(unsigned char);
	EQLIB_OBJECT void StopSpellCast(unsigned char, int);
	EQLIB_OBJECT void StunMe(unsigned int, bool, bool, bool);
	EQLIB_OBJECT void UnStunMe();
	EQLIB_OBJECT void UseSkill(unsigned char skill, PlayerZoneClient* Target, bool bAuto = false);
	EQLIB_OBJECT const int GetFocusRangeModifier(const EQ_Spell* pSpell, VePointer<CONTENTS>& pItemOut);
	EQLIB_OBJECT int IsExpansionFlag(int); // CharacterBase
	EQLIB_OBJECT int TotalEffect(int spaID, bool bIncludeItems = true, int subindex = 0, bool bIncludeAA = true, bool bincludeBuffs = true);
	EQLIB_OBJECT int GetAdjustedSkill(int);
	EQLIB_OBJECT int GetBaseSkill(int);
	EQLIB_OBJECT bool CanUseItem(CONTENTS** pItem, bool bUseRequiredLvl, bool bOutput);

	// From EQ_Character
	EQLIB_OBJECT bool DoesSpellMatchFocusFilters(EQ_Spell const*, EQ_Spell const*);
	EQLIB_OBJECT bool IsSpellTooPowerfull(EQ_Spell*, CharacterZoneClient*);
	EQLIB_OBJECT bool CanUseMemorizedSpellSlot(int gem);
	EQLIB_OBJECT bool IsValidAffect(int);
	EQLIB_OBJECT char* Class(int);
	EQLIB_OBJECT char* KunarkClass(int, int, int, bool);
	EQLIB_OBJECT char* Race(int);
	EQLIB_OBJECT EQ_Affect& GetEffect(int);
	EQLIB_OBJECT EQ_Affect* GetPCSpellAffect(int theaffect, int* slotnum, int* spaslot = NULL) const;
	EQLIB_OBJECT EQ_Equipment* GetFocusItem(EQ_Spell const*, int);
	EQLIB_OBJECT EQ_Spell* GetFocusEffect(EQ_Spell const*, int);
	EQLIB_OBJECT PlayerClient* FindClosest(int, int, int, int, int);
	EQLIB_OBJECT PlayerClient* GetMyPetPlayer();
	EQLIB_OBJECT float encum_factor();
	EQLIB_OBJECT int ac(bool);
	EQLIB_OBJECT int Agi();
	EQLIB_OBJECT int AntiTwinkAdj(EQ_Equipment*, int, int);
	EQLIB_OBJECT int ApplyDamage(int, EQMissileHitinfo*, bool, HateListEntry*, bool);
	EQLIB_OBJECT int ApplyFatigue(int);
	EQLIB_OBJECT int AutoEat(unsigned char);
	EQLIB_OBJECT int BaneDamage(EQ_Equipment*);
	//EQLIB_OBJECT int BardCastBard(EQ_Spell const*, int) const;
	EQLIB_OBJECT int basesave_cold();
	EQLIB_OBJECT int basesave_disease();
	EQLIB_OBJECT int basesave_fire();
	EQLIB_OBJECT int basesave_magic();
	EQLIB_OBJECT int basesave_poison();
	EQLIB_OBJECT int CalculateBardSongMod(int);
	EQLIB_OBJECT int CapStat(int, int);
	EQLIB_OBJECT int Cha();
	EQLIB_OBJECT int CheckFoodAndWater();
	EQLIB_OBJECT int compute_defense();
	EQLIB_OBJECT int compute_tohit(unsigned char);
	EQLIB_OBJECT int cur_encumbrance();
	EQLIB_OBJECT int Cur_Mana(bool bCapAtMax = true);
	EQLIB_OBJECT int defense_agility_bonus();
	EQLIB_OBJECT int Dex();
	EQLIB_OBJECT int ElementResistDmg(EQ_Equipment*, int);
	EQLIB_OBJECT int eqspa_change_form(EQ_Spell*, int, int, EQ_Affect*);
	EQLIB_OBJECT int eqspa_hp(unsigned int, EQ_Affect*, int, EQ_Spell*);
	EQLIB_OBJECT int GetBardInstrumentMod(int);
	EQLIB_OBJECT int GetClassACBonus(int);
	EQLIB_OBJECT int GetFirstEffectSlot(bool);
	EQLIB_OBJECT int GetHPFromStamina(int);
	EQLIB_OBJECT int GetIndexSkillMinDamageMod(int);
	EQLIB_OBJECT int GetLastEffectSlot(bool);
	EQLIB_OBJECT int GetOpenEffectSlot(bool, int);
	EQLIB_OBJECT int HasInnateSkill(unsigned char, int);
	EQLIB_OBJECT int HasSkill(unsigned char);
	EQLIB_OBJECT int HasSpell(int);
	EQLIB_OBJECT int IHaveSkill(unsigned char);
	EQLIB_OBJECT int InSpecialBindSpot(PlayerZoneClient*);
	EQLIB_OBJECT int Int();
	EQLIB_OBJECT int IsMage();
	EQLIB_OBJECT int IsSpecialBazaarSpot(PlayerZoneClient*);
	EQLIB_OBJECT int IsSpellcaster();
	EQLIB_OBJECT int ItemSpellAffects(int);
	EQLIB_OBJECT int max_encumbrance();
	EQLIB_OBJECT int NoBashMe(int);
	EQLIB_OBJECT int NoMezMe(int, PlayerZoneClient*, EQ_Spell*);
	EQLIB_OBJECT int offense(unsigned char);
	EQLIB_OBJECT int ProcessAffects();
	EQLIB_OBJECT int save_bash(int);
	EQLIB_OBJECT int save_cold();
	EQLIB_OBJECT int save_disease();
	EQLIB_OBJECT int save_fire();
	EQLIB_OBJECT int save_magic();
	EQLIB_OBJECT int save_poison();
	EQLIB_OBJECT int SetLocalVar(char*, int);
	EQLIB_OBJECT int Skill(int);
	EQLIB_OBJECT int SpellDuration(EQ_Spell const*, unsigned char, unsigned char);
	EQLIB_OBJECT int Sta();
	EQLIB_OBJECT int Str();
	EQLIB_OBJECT int TakeFallDamage(float);
	EQLIB_OBJECT int TotalSpellAffects(unsigned char, bool, int*);
	EQLIB_OBJECT int Wis();
	EQLIB_OBJECT int const GetFocusConserveRegChance(const EQ_Spell*, EQ_Equipment**);
	EQLIB_OBJECT long TotalOnPerson();
	EQLIB_OBJECT static int normal_to_special(int);
	EQLIB_OBJECT unsigned char BarbarianCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char BaseAttr(int, unsigned char);
	EQLIB_OBJECT unsigned char CanDoubleAttack(PlayerZoneClient*, unsigned char);
	EQLIB_OBJECT unsigned char CanIBreathe();
	EQLIB_OBJECT unsigned char CanISeeInvis();
	EQLIB_OBJECT unsigned char CanMedOnHorse();
	EQLIB_OBJECT unsigned char CanSecondaryAttack(PlayerZoneClient*);
	EQLIB_OBJECT unsigned char CanWorship(int, int, unsigned char);
	EQLIB_OBJECT unsigned char CastingRequirementsMet(int);
	EQLIB_OBJECT unsigned char CheckClass(int, int);
	EQLIB_OBJECT unsigned char CityCanStart(int, int, int, int);
	EQLIB_OBJECT unsigned char ClassMin(int, int, unsigned char);
	EQLIB_OBJECT unsigned char DarkElfCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char DwarfCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char ElfCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char EruditeCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char ExpendItemCharge(int, int);
	EQLIB_OBJECT unsigned char FindItemByClass(int, int*, int*);
	EQLIB_OBJECT unsigned char FindItemQty(int, int);
	EQLIB_OBJECT unsigned char FroglockCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char GetSkillBaseDamage(unsigned char, PlayerZoneClient*);
	EQLIB_OBJECT unsigned char GnomeCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char HalfElfCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char HalflingCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char HighElfCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char HumanCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char IksarCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char IsSpellAffectingPC(int, int);
	EQLIB_OBJECT unsigned char LaunchSpell(unsigned char, int, EQ_Item**);
	EQLIB_OBJECT unsigned char OgreCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char SpellFizzled(unsigned char, EQ_Spell*);
	EQLIB_OBJECT unsigned char TrollCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char VahShirCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT void CalcFoodDrinkBonus(int);
	EQLIB_OBJECT void DoFishingEvent();
	EQLIB_OBJECT void DoIntimidationEvent();
	EQLIB_OBJECT void DoLight(unsigned char);
	EQLIB_OBJECT void DoMeditation();
	EQLIB_OBJECT void DoPassageOfTime();
	EQLIB_OBJECT void EQ_CharacterResetAllMembers();
	EQLIB_OBJECT void EQSPA_Feign_Death(int);
	EQLIB_OBJECT void eqspa_levitation();
	EQLIB_OBJECT void eqspa_locate_corpse();
	EQLIB_OBJECT void eqspa_movement_rate(int);
	EQLIB_OBJECT void HandleSpecialPCAffects(int);
	EQLIB_OBJECT void HitBySpell(EQMissileHitinfo*);
	EQLIB_OBJECT void IAmDead(EQMissileHitinfo*, int);
	EQLIB_OBJECT void InitInnates(unsigned int, unsigned int);
	EQLIB_OBJECT void InitMyLanguages();
	EQLIB_OBJECT void InitSkills(unsigned char, unsigned int);
	EQLIB_OBJECT void ItemSold(long);
	EQLIB_OBJECT void ModifyCurHP(int64_t modification, PlayerZoneClient* resposibleplayer, int skilltype);
	EQLIB_OBJECT void NotifyPCAffectChange(int, int);
	EQLIB_OBJECT void ProcessAllStats();
	EQLIB_OBJECT void ProcessEnvironment();
	EQLIB_OBJECT void ProcessHungerandThirst(unsigned int);
	EQLIB_OBJECT void RemovePCAffect(EQ_Affect*);
	EQLIB_OBJECT void RemovePCAffectex(EQ_Affect*, int);
	EQLIB_OBJECT void ResetCur_HP(int);
	EQLIB_OBJECT void UpdateMyVisibleStatus();
	EQLIB_OBJECT bool DoCombatAbility(int spellID, int dummy = 1);

	// private from EQ_Character
	EQLIB_OBJECT int GetCachEQSPA(int);
	EQLIB_OBJECT void ReCachItemEffects();
	EQLIB_OBJECT void ReCachSpellEffects();
};

using EQ_Character [[deprecated("Use CharacterZoneClient (or PcClient) instead")]] = CharacterZoneClient;
using EQ_Character1 [[deprecated("Use CharacterZoneClient instead")]] = CharacterZoneClient;

// work in progres
class [[offsetcomments]] PcBase : virtual public CharacterBase
{
public:
/*0x0008*/ // void*    vfTable_CharacterZoneClient;
/*0x0008*/ // void*    vfTable_CharacterBase;
/*0x000C*/ // void*    vfTable_PcBase;
// last one changed
/*0x000C*/ virtual void vftableph() {};

/*0x0010*/ TSafeArrayStatic<int, 0xa>            RecentTasks;
/*0x0038*/ TSafeArrayStatic<PCTaskStatus, 1>     Tasks;
/*0x00a8*/ TSafeArrayStatic<PCTaskStatus, 0x1d>  Quests;
/*0x0d58*/ TSafeArrayStatic<BYTE, 6400 / 8>      BitFlags;
/*0x1078*/ TSafeArrayStatic<BenefitSelection, 5> ActiveTributeBenefits;
/*0x10a0*/ TSafeArrayStatic<BenefitSelection, 10> ActiveTrophyTributeBenefits;
/*0x10f0*/ TSafeArrayStatic<BYTE, 0x320>         BitFlags2;
/*0x1410*/ ItemBaseContainer                     BankItems;
/*0x142c*/ ItemBaseContainer                     SharedBankItems;
/*0x1448*/ ItemBaseContainer                     OverflowBufferItems;
/*0x1464*/ ItemBaseContainer                     LimboBufferItems;
/*0x1480*/ ItemBaseContainer                     MercenaryItems;
/*0x149c*/ ItemBaseContainer                     MountKeyRingItems;
/*0x14b8*/ ItemBaseContainer                     IllusionKeyRingItems;
/*0x14d4*/ ItemBaseContainer                     FamiliarKeyRingItems;
/*0x14f0*/ ItemBaseContainer                     HeroForgeKeyRingItems;
/*0x150c*/ ItemBaseContainer                     AltStorageItems;
/*0x1528*/ ItemBaseContainer                     ArchivedDeletedItems;
/*0x1544*/ ItemBaseContainer                     MailItems;
/*0x1560*/ HashTable<MailItemData, EqItemGuid, ResizePolicyNoShrink> MailItemsData;
/*0x1570*/ TSafeArrayStatic<UINT, 1>             RecentMoves;
//fine to this point
/*0x1574*/ HashTable<DynamicZoneData>            CurrentDynamicZones;
/*0x1584*/ HashTable<int>                        LearnedRecipes;
/*0x1594*/ EQList<TradeskillRecipeCount*>        QualifyingRecipeCounts;
/*0x15a4*/ HashTable<int>                        NonrepeatableQuests;
/*0x15b4*/ HashTable<int>                        CompletedTasks;
/*0x15c4*/ HashTable<int>                        CompletedTasks2;
/*0x15d4*/ UINT                                  AlchemyTimestamp;
/*0x15d8*/ bool                                  bWhat;
/*0x15d9*/ bool                                  bSomethingHome;
/*0x15dc*/ DWORD                                 LoginTime;
/*0x15e0*/ EqGuid                                GuildID;                      // GuildID_0
/*0x15e8*/ EqGuid                                FellowshipID;
/*0x15f0*/ FELLOWSHIPINFO*                       pFellowship;
/*0x15f4*/ bool                                  GuildShowSprite;
/*0x15f8*/ UINT                                  CreationTime;
/*0x15fc*/ UINT                                  AccountCreationTime;
/*0x1600*/ UINT                                  LastPlayedTime;
/*0x1604*/ DWORD                                 MinutesPlayed;
/*0x1608*/ BYTE                                  Anonymous;
/*0x1609*/ bool                                  bGM;
/*0x160a*/ bool                                  bGMStealth;
/*0x160c*/ DWORD                                 AAExp;
/*0x1610*/ BYTE                                  NobilityRank;
/*0x1611*/ BYTE                                  PercentEXPtoAA;
/*0x1614*/ int                                   AirSupply;
/*0x1618*/ int                                   SerialNum;
/*0x161c*/ bool                                  bNewCharacter;
/*0x1620*/ int                                   TasksAssigned;
/*0x1624*/ int                                   TasksCompleted;
/*0x1628*/ long                                  TaskRequestTimer;
/*0x162c*/ unsigned int                          UniquePlayerID;
/*0x1630*/ WorldLocation                         DynamicZoneSafeReturnLocation;
/*0x1644*/ DynamicZoneTimerData*                 pDZTimerRoot;
/*0x1648*/ DWORD                                 TributeTimer;
/*0x164c*/ DWORD                                 BenefitTimer;
/*0x1650*/ int64_t                               CareerFavor;
/*0x1658*/ int64_t                               CurrFavor;

	// Below needs checking
/*0x1660*/ bool                                  bBenefitsActive;
/*0x1661*/ bool                                  bTrophyBenefitsActive;
/*0x1662*/ bool                                  bHasResetStartingCity;
/*0x1663*/ bool                                  bIsHeadStartCharacter;
/*0x1664*/ int                                   PvPKills;
/*0x1668*/ int                                   PvPDeaths;
/*0x166c*/ int                                   PvPCurrentPoints;
/*0x1670*/ int                                   PvPTotalPointsEarned;
/*0x1674*/ int                                   PvPKillStreak;
/*0x1678*/ int                                   PvPDeathStreak;
/*0x167c*/ int                                   PvPCurrentStreak;
/*0x1680*/ PvPKill                               LastKill;
/*0x16d8*/ PvPDeath                              LastDeath;
/*0x1730*/ HashTable<PvPKill24HourData>          PvPLast24HoursKillHash;
/*0x1740*/ int                                   PvPInfamyLevel;
/*0x1744*/ int                                   PvPVitality;
/*0x1748*/ UINT                                  PvPLastInfamyTime;
/*0x174c*/ int                                   LastLastNameChange;
/*0x1750*/ int                                   LastNameChangePriv;
/*0x1754*/ UINT                                  PvPLastVitalityTime;
/*0x1758*/ bool                                  bKeepItemsOnDeath;
/*0x1759*/ bool                                  bResetSpecializationSkills;
/*0x175c*/ int                                   CharityPointsAvailable;
/*0x1760*/ int                                   CharityTotalPointsEarned;
/*0x1764*/ int                                   GoodPointsAvailable;
/*0x1768*/ int                                   GoodTotalPointsEarned;
/*0x176c*/ int                                   EvilPointsAvailable;
/*0x1770*/ int                                   EvilTotalPointsEarned;
/*0x1774*/ bool                                  bCanRequestNameChange;
/*0x1775*/ bool                                  bCanRequestNameChange2;
/*0x1776*/ bool                                  bCanRequestServerTransfer;
/*0x1777*/ bool                                  bIsCopied;
/*0x1778*/ int                                   ServerTransferGrantTime;
/*0x177c*/ bool                                  bCanRequestRaceChange;
/*0x1780*/ UINT                                  LastAAResetTime;
/*0x1784*/ UINT                                  LastMercAAResetTime;
/*0x1788*/ EQZoneIndex                           NewZoneID;
/*0x178c*/ int                                   NewAreaID;
/*0x1790*/ EAreaCorner                           eNewAreaCorner;
/*0x1794*/ EQZoneIndex                           PreviousZoneID;
/*0x1798*/ int                                   RealEstateZoneID;
/*0x179c*/ char                                  ServerCreated[0x20];
/*0x17bc*/ PCAdventureData                       AdventureData;
/*0x1894*/ PCSharedTaskData                      SharedTaskData;
/*0x1920*/ TaskTimerData*                        pTaskTimerData;
/*0x1924*/ PCQuestHistoryData                    QuestHistoryData;
/*0x1b7c*/ PCStatistics                          PcStatistics;
/*0x1c80*/ GroupMemberStats                      GroupStats;
/*0x1dd0*/ bool                                  bIsLfg;
/*0x1dd8*/ EqGuid                                RaidId;
/*0x1de0*/ EqGuid                                GroupID;
/*0x1de8*/ char                                  UnknownPadding[0x90];
	// End of things that need checking
	
/*0x1e78*/ int64_t                               Exp;
/*0x1e80*/ int                                   DaysEntitled;
/*0x1e84*/ int                                   SpentVeteranRewards;
/*0x1e88*/ bool                                  bVeteranRewardEntitled;
/*0x1e89*/ bool                                  bAutoConsentGroup;
/*0x1e8a*/ bool                                  bAutoConsentRaid;
/*0x1e8b*/ bool                                  bAutoConsentGuild;
/*0x1e8c*/ bool                                  bPrivateForEqPlayers;
/*0x1e90*/ long                                  AchievementFilesModificationTime;
/*0x1e94*/ char                                  StationID[0x20];
/*0x1eb8*/ EqGuid                                Guid;
/*0x1ec0*/ bool                                  bBetaBuffed;
/*0x1ec4*/ int                                   Unknown0x1ad4;
/*0x1ec8*/ int                                   StartingCity;
/*0x1ecc*/ int                                   MainLevel;
/*0x1ed0*/ bool                                  bShowHelm;
/*0x1ed8*/ int64_t                               LastTestCopyTime;
/*0x1ee0*/ CPlayerPointManager                   PointManager;
/*0x1ef4*/ PointSystemBase                       PointSystem;
/*0x1f08*/ UINT                                  LoyaltyVelocity;
/*0x1f0c*/ UINT                                  LoyaltyTokens;
/*0x1f10*/ bool                                  bHasLoyaltyInfo;
/*0x1f14*/ ArrayClass<int>                       OwnedRealEstates;
/*0x1f24*/ ArrayClass<int>                       OwnedItemRealEstates;
/*0x1f34*/ ArrayClass<int>                       ArchivedRealEstates;
/*0x1f44*/ char                                  OverridePetName[0x40];
/*0x1f84*/ bool                                  bCanRequestPetNameChange;
/*0x1f85*/ char                                  OverrideFamiliarName[0x40];
/*0x1fc5*/ bool                                  bCanRequestFamiliarNameChange;
/*0x1fc8*/ CXStr                                 OverrideMercName[0xb];
/*0x1ff4*/ bool                                  bCanRequestMercNameChange;
/*0x1ff8*/ PendingRewardList                     PendingRewards;
/*0x2024*/ UINT                                  DowntimeReductionTime;
/*0x2028*/ UINT                                  DowntimeTimerStart;
/*0x202c*/ float                                 ActivityValue;
/*0x2030*/ UINT                                  NextItemId;
/*0x2034*/ CXStr                                 SharedBank;
/*0x2038*/ CXStr                                 BankBuffer;
/*0x203c*/ CXStr                                 OverflowBuffer;
/*0x2040*/ CXStr                                 LimboBuffer;
/*0x2044*/ CXStr                                 MercenaryBuffer;
/*0x2048*/ CXStr                                 KeyRingBuffer[4];
/*0x2058*/ CXStr                                 AltStorageBuffer;
/*0x205c*/ UINT                                  AltStorageTimestamp;
/*0x2060*/ ELockoutCharacterReason               LCR;
/*0x2064*/ HashTable<ProgressionExperience>      ProgressionExp;
/*0x2074*/ CXStr                                 ArchivedStorageBuffer;
/*0x2078*/ CXStr                                 MailItemsBuffer;
/*0x207c*/ CXStr                                 MailItemsDataBuffer;
/*0x2080*/ int                                   MailItemsOverCapWarningCount;
/*0x2084*/ ItemIndex                             StatKeyRingItemIndex[4];
/*0x209c*/ bool                                  UseAdvancedLooting;
/*0x209d*/ bool                                  MasterLootCandidate;
/*0x209e*/ bool                                  bIsCorrupted;
/*0x20a0*/ char*                                 pCorruptionReport;
/*0x20a4*/ TString<0x100>                        InspectText;
/*0x21a4*/ HashTable<int>                        BlockedSpellsHash;
/*0x21b4*/ int                                   BlockedSpell[MAX_BLOCKED_SPELLS];
/*0x2254*/ HashTable<int>                        BlockedPetSpellsHash;
/*0x2264*/ int                                   BlockedPetSpell[MAX_BLOCKED_SPELLS_PET];
/*0x2304*/ ClaimDataCollection                   ConsumableFeatures;
/*0x2314*/ bool                                  bGrantItemsRegistered;
/*0x2318*/ uint64_t                              CreatedGuildID;
/*0x2320*/ UINT                                  GuildCreateTime;
/*0x2324*/ CXStr                                 GuildCreateCharacter;
/*0x2328*/ bool                                  bInventoryUnserialized;
/*0x2329*/ bool                                  bAltStorageUnserialized;
/*0x232a*/ bool                                  bArchivedStorageUnserialized;
/*0x232b*/ bool                                  bMailUnserialized;
/*0x232c*/ bool                                  bPendingInventorySerialization;
/*0x2330*/ CXStr                                 BuyLines;
/*0x2334*/ ArrayClass<CXStr>                     OfflineTraderSoldItems;
/*0x2344*/ ArrayClass<CXStr>                     OfflineBuyerBoughtItems;
/*0x2354*/ UINT                                  Krono;
/*0x2358*/ UINT                                  CursorKrono;
/*0x2360*/ int64_t                               MercAAExp;                    // divide this with 3.30f and you get the percent
/*0x2368*/ DWORD                                 MercAAPoints;                 // number of unspent merc AA points
/*0x236c*/ DWORD                                 MercAAPointsSpent;            // number of spent merc AA points
/*0x2370*/ ArrayClass<MercenaryAbilityInfo*>     MercenaryAbilities;
/*0x2380*/ HashTable<CompletedAchievementData, int, ResizePolicyNoShrink>         CompletedAchievements;
/*0x2390*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> CompletedEventBasedSubComponents;
/*0x23a0*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> OpenEventBasedSubComponents;
/*0x23b0*/ int                                   LastFellowshipJoin;
/*0x23b8*/ int64_t                               Vitality;
/*0x23c0*/ int                                   AAVitality;
/*0x23c4*/ int                                   Unknown0x1ffc;
/*0x23c8*/ int                                   FPStuff[0x1e];
/*0x2440*/ //CharacterZoneClient

	PcProfile* GetCurrentPcProfile()
	{
		return (PcProfile*)& GetCurrentBaseProfile();
	}
};

class DebugText
{
public:
	EQLIB_OBJECT virtual void SendDebugText(const char* text, int color);
};

class [[offsetcomments]] PcZoneClient : public PcBase, public CharacterZoneClient, public DebugText
{
public:
/*0x2808*/ TSafeArrayStatic<unsigned long, 3> Flags;
/*0x2814*/ uint32_t    TransfersReceived;
/*0x2818*/ int         LastLanguageSpoken;
/*0x281c*/ int         CurPowerSourceDrain;
/*0x2820*/ EQList<ALCHEMYBONUSSKILLDATA*> AlchemyBaseSkillBonusList;
/*0x2830*/ UINT        MomentumBalance;
/*0x2834*/ UINT        LoyaltyRewardBalance;
/*0x2838*/

	EQLIB_OBJECT int GetPcSkillLimit(int);
	EQLIB_OBJECT bool HasCombatAbility(int);
	EQLIB_OBJECT void RemovePetEffect(int);
	EQLIB_OBJECT bool CanEquipItem(CONTENTS** pCont, int slotid, bool bOutputDebug, bool bUseRequiredLevel);
	EQLIB_OBJECT bool HasAlternateAbility(int aaindex, int*, bool, bool);
	EQLIB_OBJECT int GetCurrentMod(int index);
	EQLIB_OBJECT int GetModCap(int index, bool bToggle = false);
	EQLIB_OBJECT void RemoveBuffEffect(int Index, int SpawnID);
	EQLIB_OBJECT CONTENTS** GetItemByID(CONTENTS** contOut, int itemid, ItemIndex* itemindex = nullptr);
	EQLIB_OBJECT CONTENTS** GetItemByItemClass(CONTENTS** contOut, int itemclass, ItemIndex* itemindex = nullptr);
	EQLIB_OBJECT void BandolierSwap(int index);
	EQLIB_OBJECT UINT GetLinkedSpellReuseTimer(int index);
};

class [[offsetcomments]] PcClient : public PcZoneClient
{
	// has a vftable but we get it from PcZoneClient
public:
	EQLIB_OBJECT PcClient();

/*0x2838*/ BYTE Filler[0x3C];
/*0x2874*/

	// Formerly in EQ_Character
	EQLIB_OBJECT unsigned long GetConLevel(const PlayerClient*);

	// TODO: Methods from EQ_PC: The ones we use need to be validated. Not all of them live in PcClient.
	// but it may not matter.
	EQLIB_OBJECT int BitchCanTrain(int, int, int);
	EQLIB_OBJECT int CheckDupLoreItems();
	EQLIB_OBJECT int checkLang(int);
	EQLIB_OBJECT int CostToTrain(int, float, int);
	EQLIB_OBJECT int DelLoreItemDup(int, int, int, EQ_Item*);
	// GetAlternateAbilityId checked on May 1 2016 only reason why it looks like it takes 2 args(which it doesnt) is cause it pushes another which is meant for AltAdvManager__GetAAById_x see 43BBB7 in eqgame 21 apr 2016 live for an example.
	EQLIB_OBJECT int GetAlternateAbilityId(int);
	EQLIB_OBJECT int GetArmorType(int);
	EQLIB_OBJECT int GetCombatAbility(int);
	EQLIB_OBJECT PcZoneClient* GetPcZoneClient() const;
	EQLIB_OBJECT int HandleMoney(long);
	EQLIB_OBJECT int IsAGroupMember(char*);
	EQLIB_OBJECT int MaxAirSupply();
	EQLIB_OBJECT int numInParty();
	EQLIB_OBJECT unsigned char AtSkillLimit(int);
	EQLIB_OBJECT unsigned char RemoveMyAffect(int);
	EQLIB_OBJECT unsigned long GetArmorTint(int);
	EQLIB_OBJECT unsigned long GetBodyTint(int);
	EQLIB_OBJECT void CheckForGroupChanges();
	EQLIB_OBJECT void CheckForLanguageImprovement(unsigned char, unsigned char);
	EQLIB_OBJECT void CheckSkillImprove(int, float);
	EQLIB_OBJECT void ClearSharedVault();
	EQLIB_OBJECT void DestroyHeldItemOrMoney();
	EQLIB_OBJECT void DetermineQuestExpGained(int);
	EQLIB_OBJECT void EmptyPossessionSlots();
	EQLIB_OBJECT void InitializeNewPCVariables(int);
	EQLIB_OBJECT void InitPlayerStart(unsigned int, unsigned char, int);
	EQLIB_OBJECT void PrepareForRepop(int);
	EQLIB_OBJECT void ProcessAirSupply();
	EQLIB_OBJECT void ProcessFatigue();
	EQLIB_OBJECT void RefitNewbieEQ();
	EQLIB_OBJECT void RefreshMe(int);
	EQLIB_OBJECT void SetAltAbilityIndex(int, int);
	EQLIB_OBJECT void SetArmorTint(int, unsigned long);
	EQLIB_OBJECT void SetArmorType(int, int);
	EQLIB_OBJECT void SetFatigue(int);
	EQLIB_OBJECT void UnpackMyNetPC(char*, int);
	EQLIB_OBJECT void AlertInventoryChanged();
	EQLIB_OBJECT unsigned long GetCombatAbilityTimer(int, int);
	EQLIB_OBJECT unsigned long GetItemRecastTimer(EQ_Item* item, ItemSpellTypes etype);
	EQLIB_OBJECT bool HasLoreItem(EQ_Item*, int, int, int, int);
	EQLIB_OBJECT void GetItemContainedRealEstateIds(ArrayClass<ItemContainingRealEstate>& Out, bool bCurrentProfileOnly = false, bool bIncludeAltStorage = true, bool bIncludeArchived = true);
	EQLIB_OBJECT void GetNonArchivedOwnedRealEstates(ArrayClass<int>& output);
};
using EQ_PC [[deprecated("Use PcClient instead")]] = PcZoneClient;

} // namespace
