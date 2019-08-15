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

struct CombatAbilityTimer : public TListNode<CombatAbilityTimer>
{
	int32_t  SpellGroup;
	uint32_t ExpireTimer;
};

struct AssociatedNPCSaveStringNode
{
/*0x0000*/ char SaveString[0x2000];              // 0x1000 in older clients
/*0x2000*/ AssociatedNPCSaveStringNode* pNext;
/*0x2004*/
};

struct BandolierItemInfo
{
/*0x00*/ int ItemID;
/*0x04*/ int IconID;
/*0x08*/ char Name[0x40];
/*0x48*/
};

struct BandolierSet
{
/*0x000*/ char Name[0x20];
/*0x020*/ BandolierItemInfo Items[4];            // 0x120 = 0x48 * 4
/*0x140*/
};

struct AALIST
{
/*0x00*/ DWORD AAIndex;
/*0x04*/ DWORD PointsSpent;
/*0x08*/ DWORD ChargeSpent;            // charges spent in the last 10 min?
/*0x0c*/
};
using PAALIST [[deprecated]] = AALIST;

struct ALCHEMYBONUSSKILLDATA
{
	int SkillID;
	int BonusPoints;
};

struct BenefitSelection
{
/*0x00*/ int BenefitID;
/*0x04*/ int BenefitTier;
/*0x08*/
};

class ProfileList
{
public:
/*0x00*/ eProfileListType ListType;
/*0x04*/ BaseProfile* pFirst;
/*0x08*/ BaseProfile* pLast;
/*0x0c*/ ProfileList* pNext;
/*0x10*/ ProfileList* pPrev;
/*0x14*/
};

class CProfileManager
{
	// has no vftable
public:
/*0x00*/ ProfileList* pFirst;
/*0x04*/ eProfileListType CurProfileList;
/*0x08*/

	inline const ProfileList* GetCurrentProfileList() const
	{
		ProfileList* pWalk = pFirst;
		while (pWalk != NULL)
		{
			if (pWalk->ListType == CurProfileList)
			{
				return pWalk;
			}

			pWalk = pWalk->pNext;
		}
		return NULL;
	}

	inline const BaseProfile* GetCurrentProfile() const
	{
		const ProfileList* pList = GetCurrentProfileList();
		if (pList != NULL)
		{
			return pList->pFirst;
		}
		return NULL;
	}
};

enum eDynamicZoneType
{
	eDZT_Unknown,
	eDZT_Expedition,
	eDZT_Tutorial,
	eDZT_Task,
	eDZT_Mission,
	eDZT_Quest
};

struct DynamicZoneData
{
/*0x00*/ int                DynamicZoneID;
/*0x04*/ int                SetID;
/*0x08*/ eDynamicZoneType   Type;
/*0x0c*/
};

struct DynamicZoneTimerData
{
/*0x00*/ int                   DataSetID;
/*0x04*/ UINT                  TimerExpiration;
/*0x08*/ int                   EventID;
/*0x0c*/ int                   DynamicZoneID;
/*0x10*/ DynamicZoneTimerData* pNext;
/*0x14*/
};

// size 34 i think in eqgame dated mar 23 2015 but i have no address for it atm
struct GROUPMEMBER
{
/*0x00*/ void*  vftable;
/*0x04*/ CXStr  Name;
/*0x08*/ BYTE   Mercenary;
/*0x09*/ BYTE   Unknown0x9[0x3];
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
};
using PGROUPMEMBER [[deprecated]] = GROUPMEMBER*;

struct GROUPINFO
{
/*0x00*/ void* vftable;
/*0x04*/ GROUPMEMBER* pMember[0x6];
/*0x1c*/ GROUPMEMBER* pLeader;
/*0x20*/
};
using PGROUPINFO [[deprecated]] = GROUPINFO*;


// size 0x4c 12-25-09 - ieatacid
struct XTARGETSLOT
{
/*0x00*/ DWORD  xTargetType;
/*0x04*/ eXTSlotStatus  XTargetSlotStatus;
/*0x08*/ DWORD  SpawnID;
/*0x0c*/ char   Name[0x40];
/*0x4c*/
};
using PXTARGETSLOT = XTARGETSLOT*;

class ExtendedTargetList
{
public:
	void*                      vftable;
	ArrayClass_RO<XTARGETSLOT> XTargetSlots;     // max is 23
	bool                       bAutoAddHaters;
};

class ExtendedTargetListClient : public ExtendedTargetList
{
public:
	int CurrentSlot;
	int ContextSlot;
};

struct MailItemData
{
/*0x00*/ UINT   SendTime;
/*0x04*/ CXStr  SenderName;
/*0x08*/ CXStr  Note;
/*0x0c*/
};

struct PCAdventureThemeStats
{
/*0x00*/ int SucceededNormal;
/*0x04*/ int FailedNormal;
/*0x08*/ int SucceededHard;
/*0x0c*/ int FailedHard;
/*0x10*/ int AdventureTotalPointsEarned;
/*0x14*/
};

struct PCAdventureData
{
/*0x000*/ int AdventureLastAdventureDefinitionSeen[5];
/*0x014*/ UINT AdventureLastAdventureDefinitionSeenTime[5];
/*0x028*/ int AdventureActiveAdventureId;
/*0x02c*/ int AdventureActiveAdventureTheme;
/*0x030*/ int AdventureActiveAdventureRisk;
/*0x034*/ int AdventureSafeReturnZoneId;
/*0x038*/ float AdventureSafeReturnX;
/*0x03c*/ float AdventureSafeReturnY;
/*0x040*/ float AdventureSafeReturnZ;
/*0x044*/ int AdventureStatAccepted;
/*0x048*/ int AdventureStatRejected;
/*0x04c*/ int AdventureStatEntered;
/*0x050*/ int AdventureStatFailedEnter;
/*0x054*/ int AdventurePointsAvailable;
/*0x058*/ int AdventurePointsAvailableMax;
/*0x05c*/ UINT AdventureLastSuccessTime;
/*0x060*/ PCAdventureThemeStats ThemeStats[6];
/*0x0d8*/
};

struct PCTaskStatus
{
/*0x00*/ int TaskID;
/*0x04*/ int MovingStartTime;
/*0x08*/ int InitialStartTime;
/*0x0c*/ bool ElementActive[0x14];
/*0x20*/ int CurrentCounts[0x14];
/*0x70*/
};

struct MonsterMissionTemplate
{
/*0x00*/ int  TemplateID;
/*0x04*/ int  Min;
/*0x08*/ int  Max;
/*0x0c*/ int  NumSelected;
/*0x10*/ bool CanSelect;
/*0x14*/ char TemplateName[0x40];
/*0x54*/
};

struct PCSharedTaskData
{
/*0x00*/ int  ActiveSharedTaskID;
/*0x04*/ bool bIsMonsterMission;
/*0x08*/ PCTaskStatus Status;                              // size 0x70
/*0x78*/ ArrayClass<MonsterMissionTemplate> Templates;  // size is 0x10
/*0x88*/ float RewardAdjustment;
/*0x8c*/
};

struct TaskTimerData
{
/*0x00*/ int GroupID;
/*0x04*/ int TimerSeconds;
/*0x08*/ UINT TimerExpiration;
/*0x0c*/ int TimerType;
/*0x10*/ int OrigTaskID;
/*0x14*/ TaskTimerData *pNext;
/*0x18*/
};

class PendingReward
{
public:
/*0x00*/ void* vfTable;
/*0x04*/ int   ID;
/*0x08*/ int   SetID;
/*0x0c*/ float RewardAdjustment;
/*0x10*/ char  RewardTitle[0x80];
/*0x90*/
};

class PendingRewardList : public DoublyLinkedList<PendingReward*>
{
public:
/*0x20*/ int NextUID;
/*0x24*/ int MaxPending;
/*0x28*/ int ZoneMaxPending;
/*0x2c*/
};

struct Point
{
	UINT PointType;
	UINT PointSubtype;
	UINT CurrentCount;
	UINT TotalEver;
};

struct PointNamesEntry
{
	UINT PointTypeId;
	UINT PointSubtypeId;
	int  DBStringId;
	int  PointItemId;
	int  ImageId;
	int  MaxStackSize;
	bool bStationCashRelated;
};

class PointSystemBase
{
public:
/*0x00*/ void* vfTable;
/*0x04*/ ArrayClass_RO<PointNamesEntry*> PointNameEntries;
/*0x14*/
};

class CPlayerPointManager
{
public:
	/*0x00*/ void* vfTable;
	/*0x04*/ ArrayClass<Point*> Points;
	/*0x14*/
};

struct ProgressionExperience
{
/*0x00*/ int ProgressionID;
/*0x08*/ double ProgressionExp;
/*0x10*/
};

struct PCCompletedQuest
{
/*0x00*/ int QuestID;
/*0x04*/ int ElementBitmask;
/*0x08*/ UINT TimeCompleted;
/*0x0c*/
};

struct PCQuestHistoryData
{
/*0x000*/ PCCompletedQuest Quests[0x32];                   // size 0xc * 0x32 = 0x258
/*0x258*/
};

struct PvPKill
{
/*0x00*/ CHAR VictimName[0x40];
/*0x40*/ int VictimLevel;
/*0x44*/ DWORD VictimRace;
/*0x48*/ DWORD VictimClass;
/*0x4c*/ int ZoneID;
/*0x50*/ long Lastkilltime;
/*0x54*/ int PointsEarned;
/*0x58*/
};

struct PvPDeath
{
/*0x00*/ CHAR KillerName[0x40];
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

struct RaidData
{
/*0x00*/ int MainAssists[3];
/*0x0c*/ char MainAssistNames[3][0x40];
/*0xcc*/ int MainMarkers[3];
/*0xd8*/ int MasterLooter;
/*0xdc*/
};

struct TradeskillRecipeCount
{
/*0x00*/ int SkillID;
/*0x04*/ int RecipeCount;
/*0x08*/
};

struct WorldLocation
{
/*0x00*/ DWORD ZoneBoundID;
/*0x04*/ float ZoneBoundY;
/*0x08*/ float ZoneBoundX;
/*0x0c*/ float ZoneBoundZ;
/*0x10*/ float ZoneBoundHeading;
/*0x14*/
};


class StatCounter
{
public:
/*0x00*/ UINT Value;
/*0x04*/
};

class StatElapsedTime
{
public:
/*0x00*/ UINT StartTick;
/*0x04*/ UINT ElapsedTotal;
/*0x08*/ bool bCurrentState;
/*0x0c*/
};

class PCStatistics
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
/*0x094*/ CHAR PlayerName[0x40];
/*0x0d4*/ CHAR PlayerStationID[0x20];
/*0x0f4*/ int PlayerLevel;
/*0x0f8*/ DWORD PlayerRace;
/*0x0fc*/ DWORD PlayerClass;
/*0x100*/ UINT UniquePlayerID;
/*0x104*/
};

class GroupMemberStats
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

/*0x000*/ CHAR         PlayerName[0x40];
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

struct ClaimData
{
/*0x00*/ int FeatureID;
/*0x04*/ int Count;
/*0x08*/
};

class ClaimDataCollection
{
public:
/*0x00*/ ArrayClass<ClaimData> ClaimData;
/*0x10*/
};

class MercenaryAbilityInfo
{
public:
/*0x00*/ int Index;
/*0x04*/ int Cost;
/*0x08*/
};

struct CompletedAchievementData
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

struct AchievementSubComponentCountData
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
using PCHARINFONEW [[deprecated]] = CHARINFONEW*;
#endif

// these are just virtual base tables
struct CI_INFO {
/* 0x0000 */    DWORD   minus8;
/* 0x0004 */    DWORD   stuff_offset;
/* 0x0008 */    DWORD   Unknown0x8;    // 2000
/* 0x000c */    DWORD   Unknown0xc;    // 2500
/* 0x0010 */    DWORD   Unknown0x10;   // 3000
/* 0x0014 */    DWORD   Unknown0x14;   // 4000
/* 0x0018 */    DWORD   Unknown0x18;   // 10000
};

struct EQC_INFO {
/* 0x0000 */    DWORD   minus4;
/* 0x0004 */    DWORD   stuff_offset;
};

//aStartingLoad
#define CHARINFO_Size 0x2B78 //in Nov 01 2018 beta (see 5D7008) - eqmule
/*0x1c4c*/ //ItemIndex	StatKeyRingItemIndex[3];//0xe46 confirmed
//this thing here is an abomination, todo: fix it once and for all.
// its like a frankenstruct mixing in PcBase etc. 
struct CHARINFOOLD
{
/*0x0000*/ void*                                         vtable1;
/*0x0004*/ void*                                         punknown;
/*0x0008*/ CI_INFO*                                      charinfo_info;
/*0x000c*/ void*                                         vftablealso;
/*0x0010*/ TSafeArrayStatic<int, 0xa>                    RecentTasks;
/*0x0038*/ TSafeArrayStatic<PCTaskStatus, 1>             Tasks;
/*0x00A8*/ TSafeArrayStatic<PCTaskStatus, 0x1d>          Quests;
/*0x0D58*/ TSafeArrayStatic<BYTE, 0x320>                 BitFlags;
/*0x1078*/ TSafeArrayStatic<BenefitSelection, 5>         ActiveTributeBenefits;          // size 0x28 8 * 5
/*0x10A0*/ TSafeArrayStatic<BenefitSelection, 0xa>       ActiveTrophyTributeBenefits;
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
/*0x14e0*/ BYTE                                          Unknown0x14e0[0xe8];
/*0x15c8*/ int64_t                                       GuildID;                        // GuildID_0
/*0x15d0*/ int64_t                                       FellowshipID;
/*0x15d8*/ FELLOWSHIPINFO*                               pFellowship;
/*0x15dc*/ bool                                          GuildShowSprite;
/*0x15e0*/ UINT                                          CreationTime;                   // CharCreationTime
/*0x15e4*/ UINT                                          AccountCreationTime;
/*0x15e8*/ UINT                                          LastPlayedTime;
/*0x15ec*/ DWORD                                         MinutesPlayed;
/*0x15f0*/ BYTE                                          Anonymous;
/*0x15f1*/ bool                                          bGM;
/*0x15f2*/ bool                                          bGMStealth;
/*0x15f4*/ DWORD                                         AAExp;                          // Post60Exp
/*0x15f8*/ BYTE                                          NobilityRank;
/*0x15f9*/ BYTE                                          PercentEXPtoAA;
/*0x15fc*/ int                                           AirSupply;
/*0x1600*/ int                                           SerialNum;
/*0x1604*/ bool                                          bNewCharacter;
/*0x1608*/ int                                           TasksAssigned;
/*0x160c*/ int                                           TasksCompleted;
/*0x1610*/ long                                          TaskRequestTimer;
/*0x1614*/ unsigned int                                  UniquePlayerID;
/*0x1618*/ WorldLocation                                 DynamicZoneSafeReturnLocation;  // size 0x14
/*0x162c*/ DynamicZoneTimerData*                         pDZTimerRoot;
/*0x1630*/ DWORD                                         TributeTimer;
/*0x1634*/ DWORD                                         BenefitTimer;
/*0x1638*/ int64_t                                       CareerFavor;
/*0x1640*/ int64_t                                       CurrFavor;
/*0x1648*/ BYTE                                          Unknown0x1648[0xFC];
/*0x1744*/ DWORD                                         RadiantCrystals;
/*0x1748*/ BYTE                                          Unknown0x1748[0x4];
/*0x174c*/ DWORD                                         EbonCrystals;
/*0x1750*/ BYTE                                          Unknown0x1750[0x710];
/*0x1e60*/ int64_t                                       Exp;                            // confirmed jun 12 2017 test
/*0x1e68*/ int                                           DaysEntitled;
/*0x1e6c*/ int                                           SpentVeteranRewards;
/*0x1e70*/ bool                                          bVeteranRewardEntitled;
/*0x1e71*/ bool                                          bAutoConsentGroup;
/*0x1e72*/ bool                                          bAutoConsentRaid;
/*0x1e73*/ bool                                          bAutoConsentGuild;
/*0x1e74*/ bool                                          bPrivateForEqPlayers;
/*0x1e78*/ long                                          AchievementFilesModificationTime;
/*0x1e7c*/ char                                          StationID[0x20];
/*0x1ea0*/ EqGuid                                        Guid;                           // size 8 so it MUST start at a int64 sized address.. i.e. 0 or 8
/*0x1ea8*/ bool                                          bBetaBuffed;
/*0x1eac*/ int                                           Unknown0x1eac;
/*0x1eb0*/ int                                           StartingCity;
/*0x1eb4*/ int                                           MainLevel;
/*0x1eb8*/ bool	                                         bShowHelm;
/*0x1ec0*/ int64_t                                       LastTestCopyTime;
/*0x1ec8*/ CPlayerPointManager                           PointManager;                   // size 0x14
/*0x1edc*/ PointSystemBase                               PointSystem;                    // size 0x14
/*0x1ef0*/ UINT                                          LoyaltyVelocity;
/*0x1ef4*/ UINT                                          LoyaltyTokens;
/*0x1ef8*/ bool                                          bHasLoyaltyInfo;
/*0x1efc*/ ArrayClass<int>                               OwnedRealEstates;
/*0x1f0c*/ ArrayClass<int>                               OwnedItemRealEstates;
/*0x1f1c*/ ArrayClass<int>                               ArchivedRealEstates;
/*0x1f2c*/ CHAR                                          OverridePetName[0x40];
/*0x1f6c*/ bool                                          bCanRequestPetNameChange;
/*0x1f6d*/ CHAR                                          OverrideFamiliarName[0x40];
/*0x1fad*/ bool                                          bCanRequestFamiliarNameChange;
/*0x1fb0*/ CXStr                                         OverrideMercName[0xb];
/*0x1Fdc*/ bool                                          bCanRequestMercNameChange;
/*0x1Fe0*/ PendingRewardList                             PendingRewards;                 // size 0x2c
/*0x200c*/ UINT                                          DowntimeReductionTime;
/*0x2010*/ UINT                                          DowntimeTimerStart;
/*0x2014*/ float                                         ActivityValue;
/*0x2018*/ UINT                                          NextItemId;
/*0x201c*/ CXStr                                         SharedBank;
/*0x2020*/ CXStr                                         BankBuffer;
/*0x2024*/ CXStr                                         LimboBuffer;
/*0x2028*/ CXStr                                         MercenaryBuffer;
/*0x202c*/ CXStr                                         KeyRingBuffer[3];
/*0x2038*/ CXStr                                         AltStorageBuffer;
/*0x203c*/ CXStr                                         ItemOverflow;
/*0x2040*/ UINT                                          AltStorageTimestamp;
/*0x2044*/ ELockoutCharacterReason                       LCR;
/*0x2048*/ HashTable<ProgressionExperience>              ProgressionExp;                 // size 0x10
/*0x2058*/ CXStr                                         ArchivedStorageBuffer;
/*0x205c*/ CXStr                                         MailItemsBuffer;
/*0x2060*/ CXStr                                         MailItemsDataBuffer;
/*0x2064*/ int                                           MailItemsOverCapWarningCount;
/*0x2068*/ ItemIndex                                     StatKeyRingItemIndex[3];        // size 0x12
/*0x207a*/ BYTE                                          UseAdvancedLooting;             // 0x1ff2 confirmed jun 12 2017 test               //0=off 1=on
/*0x207b*/ BYTE                                          MasterLootCandidate;            // 0=off 1=on
/*0x207c*/ BYTE                                          Unknown0x207c[0x2b8];
/*0x2334*/ DWORD                                         Krono;                          // confirmed jun 12 2017 test
/*0x2338*/ DWORD                                         CursorKrono;
/*0x233c*/ BYTE                                          Unknown0x233c[0x4];
/*0x2340*/ int64_t                                       MercAAExp;                      // divide this with 3.30f and you get the percent - eqmule
/*0x2348*/ DWORD                                         MercAAPoints;                   // number of unspent merc AA points
/*0x234c*/ DWORD                                         MercAAPointsSpent;              // number of spent merc AA points
/*0x2350*/ BYTE                                          Unknown0x2350[0x48];
/*0x2398*/ int64_t                                       Vitality;
/*0x23a0*/ int                                           AAVitality;
/*0x23a4*/ int                                           Unknown0x23a4;
/*0x23a8*/ int                                           FPStuff[0x1c];
/*0x2418*/
/********************* PcBase End **********************/
/************ CharacterZoneClient Begin ****************/
/*0x2418*/ void*                                         vtable2;                        // vtable2_0 below aTimeIsDAndCanU (its really PcClient_CharacterZoneClient_vfTable
/*0x241c*/ EQC_INFO*                                     eqc_info;
/*0x2420*/ SPAWNINFO*                                    pSpawn;                         // pSpawn_0
/*0x2424*/ bool                                          bUpdateStuff;
/*0x2425*/ bool                                          bZoningStatProcessing;
/*0x2428*/ DWORD                                         ArmorClassBonus;                // vtable2+10
/*0x242c*/ DWORD                                         CurrWeight;                     // vtable2+14
/*0x2430*/ int                                           LastHitPointSendPercent;
/*0x2434*/ int                                           LastManaPointSendPercent;
/*0x2438*/ int                                           LastEndurancePointSendPercent;
/*0x243c*/ DWORD                                         HPBonus;                        // vtable2+24
/*0x2440*/ DWORD                                         ManaBonus;                      // vtable2+28
/*0x2444*/ DWORD                                         EnduranceBonus;                 // vtable2+2c
/*0x2448*/ int                                           EnduranceCostPerSecond;
/*0x244c*/ DWORD                                         CombatEffectsBonus;             // vtable2+34 Combat Effects in UI
/*0x2450*/ DWORD                                         ShieldingBonus;                 // vtable2+38 Melee Shielding in UI
/*0x2454*/ DWORD                                         SpellShieldBonus;               // vtable2+3c Spell Shielding in UI
/*0x2458*/ DWORD                                         AvoidanceBonus;                 // vtable2+40 Avoidance in UI
/*0x245c*/ DWORD                                         AccuracyBonus;                  // vtable2+44 Accuracy in UI
/*0x2460*/ DWORD                                         StunResistBonus;                // vtable2+48 Stun Resist in UI
/*0x2464*/ DWORD                                         StrikeThroughBonus;             // vtable2+4c Strike Through in UI
/*0x2468*/ DWORD                                         DoTShieldBonus;                 // vtable2+50 Dot Shielding in UI
/*0x246c*/ DWORD                                         DamageShieldMitigationBonus;    // vtable2+54 Damage Shield Mitig in UI
/*0x2470*/ DWORD                                         DamageShieldBonus;              // vtable2+58 Damage Shielding in UI
/*0x2474*/ TSafeArrayStatic<int, 9>                      ItemSkillMinDamageMod;          // size 0x24
/*0x2498*/ TSafeArrayStatic<int, 9>                      SkillMinDamageModBonus;         // size 0x24
/*0x24bc*/ DWORD                                         HeroicSTRBonus;                 // vtable2+a4
/*0x24c0*/ DWORD                                         HeroicINTBonus;                 // vtable2+a8
/*0x24c4*/ DWORD                                         HeroicWISBonus;                 // vtable2+ac
/*0x24c8*/ DWORD                                         HeroicAGIBonus;                 // vtable2+b0
/*0x24cc*/ DWORD                                         HeroicDEXBonus;                 // vtable2+b4
/*0x24d0*/ DWORD                                         HeroicSTABonus;                 // vtable2+b8
/*0x24d4*/ DWORD                                         HeroicCHABonus;                 // vtable2+bc
/*0x24d8*/ DWORD                                         HealAmountBonus;                // vtable2+d8
/*0x24dc*/ DWORD                                         SpellDamageBonus;               // vtable2+dc
/*0x24e0*/ int                                           ItemHealAmountDotMod;
/*0x24e4*/ int                                           ItemSpellDamageDotMod;
/*0x24e8*/ DWORD                                         ClairvoyanceBonus;              // vtable2+e8
/*0x24ec*/ DWORD                                         AttackBonus;                    // vtable2+ec
/*0x24f0*/ DWORD                                         HPRegenBonus;                   // vtable2+f0
/*0x24f4*/ DWORD                                         ManaRegenBonus;                 // vtable2+f4
/*0x24f8*/ DWORD                                         EnduranceRegenBonus;            // vtable2+f8
/*0x24fc*/ DWORD                                         AttackSpeed;                    // vtable2+fc
/*0x2500*/ int                                           NoBuffItemHitpointAdjustment;
/*0x2504*/ int                                           NoBuffItemManaAdjustment;
/*0x2508*/ int                                           NoBuffItemEnduranceAdjustment;
/*0x250c*/ int                                           NoBuffItemBaseChanceProc;
/*0x2510*/ int                                           NoBuffItemMinDamageMod;
/*0x2514*/ int                                           NoBuffItemInnateSpellRune;
/*0x2518*/ int                                           NoBuffItemAvoidance;
/*0x251c*/ int                                           NoBuffItemToHit;
/*0x2520*/ int                                           NoBuffItemResistStunChance;
/*0x2524*/ int                                           NoBuffItemDotShieldingEffect;
/*0x2528*/ int                                           NoBuffItemStrikeThroughChance;
/*0x252c*/ int                                           NoBuffItemAttack;
/*0x2530*/ int                                           NoBuffItemHitPointRegen;
/*0x2534*/ int                                           NoBuffItemManaRegen;
/*0x2538*/ int                                           NoBuffItemEnduranceRegen;
/*0x253c*/ int                                           NoBuffItemDamageShield;
/*0x2540*/ int                                           NoBuffItemDamageShieldMitigation;
/*0x2544*/ int                                           NoBuffItemHaste;
/*0x2548*/ TSafeArrayStatic<int, 9>                      NoBuffItemSkillMinDamageMod;    // size 0x24
/*0x256c*/ bool                                          bOutputHpRegen;
/*0x256d*/ bool                                          bInvulnerable;
/*0x256e*/ bool                                          bOnAVehicle;                    // 0x2420 + 0x156 see 4D94E8 in jun 11 2018 test
/*0x2570*/ SpellCache                                    spellCache;                     // size 0x58
/*0x25c8*/ HashListSet<int, 0x80>                        DoomEffectsBySlot;              // size 0x10 + (0x80 * 4)
/*0x27d8*/ UINT                                          LastHitEval;
/*0x27dc*/
/*********************** CharacterZoneClient End ***********************/
/******************* PcZoneClient Begine ******************/
/*0x27dc*/ void*                                         PcZoneClient_vfTable;           // see 61A04C jun 11 test 2018
/*0x27e0*/ TSafeArrayStatic<unsigned long, 3>            Flags;                          // size 0xc
/*0x27ec*/ uint32_t                                      TransfersReceived;
/*0x27f0*/ int                                           LastLanguageSpoken;
/*0x27f4*/ int                                           CurPowerSourceDrain;
/*0x27f8*/ EQList<ALCHEMYBONUSSKILLDATA*>                AlchemyBaseSkillBonusList;
/*0x2808*/ UINT                                          MomentumBalance;
/*0x280c*/ UINT                                          LoyaltyRewardBalance;
/*0x2810*/
/******************* PcZoneClient End ******************/
/******************* PCClient Begin ************************/
/*0x2810*/ ExtendedTargetList*                           pXTargetMgr;
/*0x2814*/ DWORD                                         InCombat;
/*0x2818*/ DWORD                                         Downtime;
/*0x281c*/ DWORD                                         DowntimeStamp;
/*0x2820*/ bool                                          bOverrideAvatarProximity;
/*0x2824*/ GROUPINFO*                                    pGroupInfo;
/*0x2828*/ bool                                          bIAmCreatingGroup;
/*0x282c*/ VeArray<VePointer<CONTENTS*>>                 ItemsPendingID;                 // size 0xc
/*0x2838*/ int                                           ParcelStatus;                   // eParcelStatus
/*0x283c*/ int                                           SubscriptionDays;               // 24BC for sure see 7A6C40 in may 11 2018 live exe
/*0x2840*/ short                                         BaseKeyRingSlots[3];
/*0x2846*/ bool                                          bPickZoneFewest;                // for sure see 4A424A in may 11 2018 live exe
/*0x2848*/ int                                           Unknown0x2848;
/*0x284c*/
/******************* PCClient End ************************/
/*0x284c*/ void*                                         CharacterBase_vftable;
/*0x2850*/ CProfileManager                               ProfileManager;
/*0x2858*/ BYTE                                          languages[0x20];  
/*0x2878*/ float                                         X;
/*0x287c*/ float                                         Y;
/*0x2880*/ float                                         Z;
/*0x2884*/ float                                         Heading;
/*0x2888*/ CHAR                                          Name[0x40];                     // CharBaseBegin+44
/*0x28c8*/ CHAR                                          Lastname[0x20];                 // CharBaseBegin+84
/*0x28e8*/ TSafeString<0x80>                             Title;
/*0x2968*/ TSafeString<0x40>                             VehicleName;
/*0x29a8*/ BYTE                                          Stunned;                        // CharBaseBegin+104
/*0x29a9*/ BYTE                                          Unknown0x29a9[0x3];
/*0x29ac*/ WORD                                          zoneId;                         // CharBaseBegin+108 Zone_0
/*0x29ae*/ WORD                                          instance;
/*0x29b0*/ BYTE                                          standstate;                     // CharBaseBegin+10c
/*0x29b4*/ RaidData                                      raidData;                       // size 0xdc
/*0x2a90*/ DWORD                                         ExpansionFlags;                 // CharBaseBegin+464
/*0x2a94*/ bool                                          bSuperPKILL;
/*0x2a95*/ bool                                          bUnclone;
/*0x2a96*/ bool                                          bDead;
/*0x2a98*/ int                                           LD_Timer;
/*0x2a9c*/ int                                           SpellInterruptCount;
/*0x2aa0*/ bool                                          bAutoSplit;
/*0x2aa1*/ bool                                          bTellsOff;
/*0x2aa2*/ bool                                          bGmInvis;
/*0x2aa4*/ int                                           KillMe;
/*0x2aa8*/ bool                                          CheaterLdFlag;                  // likely this is int SoulMarkCount instead.
/*0x2aa9*/ bool                                          NoRent;
/*0x2aaa*/ bool                                          Corpse;
/*0x2aab*/ bool                                          ClientGmFlagSet;
/*0x2aac*/ DWORD                                         BankSharedPlat;                 // 31e4 CharBaseBegin+488
/*0x2ab0*/ DWORD                                         BankSharedGold;                 // CharBaseBegin+48c
/*0x2ab4*/ DWORD                                         BankSharedSilver;               // CharBaseBegin+490
/*0x2ab8*/ DWORD                                         BankSharedCopper;               // CharBaseBegin+494
/*0x2abc*/ DWORD                                         BankPlat;                       // CharBaseBegin+498
/*0x2ac0*/ DWORD                                         BankGold;                       // CharBaseBegin+49c
/*0x2ac4*/ DWORD                                         BankSilver;                     // CharBaseBegin+4a0
/*0x2ac8*/ DWORD                                         BankCopper;                     // CharBaseBegin+4a4
/*0x2acc*/ DWORD                                         STR;                            // CharBaseBegin+4a8
/*0x2ad0*/ DWORD                                         STA;                            // CharBaseBegin+4ac
/*0x2ad4*/ DWORD                                         CHA;                            // CharBaseBegin+4b0
/*0x2ad8*/ DWORD                                         DEX;                            // CharBaseBegin+4b4
/*0x2adc*/ DWORD                                         INT;                            // CharBaseBegin+4b8
/*0x2ae0*/ DWORD                                         AGI;                            // CharBaseBegin+4bc
/*0x2ae4*/ DWORD                                         WIS;                            // CharBaseBegin+4c0
/*0x2ae8*/ DWORD                                         LCK;                            // CharBaseBegin+4c4
/*0x2aec*/ DWORD                                         SavePoison;                     // CharBaseBegin+4c8
/*0x2af0*/ DWORD                                         SaveMagic;                      // CharBaseBegin+4cc
/*0x2af4*/ DWORD                                         SaveDisease;                    // CharBaseBegin+4d0
/*0x2af8*/ DWORD                                         SaveCorruption;                 // CharBaseBegin+4d4
/*0x2afc*/ DWORD                                         SaveFire;                       // CharBaseBegin+4d8
/*0x2b00*/ DWORD                                         SaveCold;                       // CharBaseBegin+4dc
/*0x2b04*/ DWORD                                         SavePhysical;                   // CharBaseBegin+4e0
/*0x2b08*/ int                                           UncappedStr;
/*0x2b0c*/ int                                           UncappedSta;
/*0x2b10*/ int                                           UncappedCha;
/*0x2b14*/ int                                           UncappedDex;
/*0x2b18*/ int                                           UncappedInt;
/*0x2b1c*/ int                                           UncappedAgi;
/*0x2b20*/ int                                           UncappedWis;
/*0x2b24*/ int                                           UncappedResistPoison;
/*0x2b28*/ int                                           UncappedResistMagic;
/*0x2b2c*/ int                                           UncappedResistDisease;
/*0x2b30*/ int                                           UncappedResistCorruption;
/*0x2b34*/ int                                           UncappedResistFire;
/*0x2b38*/ int                                           UncappedResistCold;
/*0x2b3c*/ int                                           UncappedResistPhysical;
/*0x2b40*/ int                                           NoBuffStr;
/*0x2b44*/ int                                           NoBuffSta;
/*0x2b48*/ int                                           NoBuffCha;
/*0x2b4c*/ int                                           NoBuffDex;
/*0x2b50*/ int                                           NoBuffInt;
/*0x2b54*/ int                                           NoBuffAgi;
/*0x2b58*/ int                                           NoBuffWis;
/*0x2b5c*/ int                                           NoBuffResistPoison;
/*0x2b60*/ int                                           NoBuffResistMagic;
/*0x2b64*/ int                                           NoBuffResistDisease;
/*0x2b68*/ int                                           NoBuffResistCorruption;
/*0x2b6c*/ int                                           NoBuffResistFire;
/*0x2b70*/ int                                           NoBuffResistCold;
/*0x2b74*/ int                                           NoBuffResistPhysical;
/*0x2b78*/
};

struct CHARINFONEW
{
/*********************** PcBase Begin ************************/
/*0x0000*/ void*                                         vtable1;
/*0x0004*/ void*                                         punknown;
/*0x0008*/ CI_INFO*                                      charinfo_info;
/*0x000c*/ void*                                         vftablealso;
/*0x0010*/ TSafeArrayStatic<int, 0xa>                    RecentTasks;
/*0x0038*/ TSafeArrayStatic<PCTaskStatus, 1>             Tasks;
/*0x00A8*/ TSafeArrayStatic<PCTaskStatus, 0x1d>          Quests;
/*0x0D58*/ TSafeArrayStatic<BYTE, 0x320>                 BitFlags;
/*0x1078*/ TSafeArrayStatic<BenefitSelection, 5>         ActiveTributeBenefits;          // size 0x28 8 * 5
/*0x10A0*/ TSafeArrayStatic<BenefitSelection, 0xa>       ActiveTrophyTributeBenefits;
/*0x10f0*/ TSafeArrayStatic<BYTE, 0x320>                 BitFlags2;
/*0x1410*/ ItemBaseContainer                             BankItems;                      // size 0x1c pBankArray
/*0x142c*/ ItemBaseContainer                             SharedBankItems;
/*0x1448*/ ItemBaseContainer                             OverflowBufferItems;
/*0x1464*/ ItemBaseContainer                             LimboBufferItems;
/*0x1480*/ ItemBaseContainer                             MercenaryItems;
/*0x149c*/ ItemBaseContainer                             MountKeyRingItems;
/*0x14b8*/ ItemBaseContainer                             IllusionKeyRingItems;
/*0x14d4*/ ItemBaseContainer                             FamiliarKeyRingItems;
/*0x14f0*/ ItemBaseContainer                             AltStorageItems;
/*0x150c*/ ItemBaseContainer                             ArchivedDeletedItems;
/*0x1528*/ ItemBaseContainer                             MailItems;
/*0x1544*/ HashTable<MailItemData, EqItemGuid, ResizePolicyNoShrink> MailItemsData;      // size 0x10
/*0x1554*/ TSafeArrayStatic<UINT, 1>                     RecentMoves;
/*0x1558*/ HashTable<DynamicZoneData>                    CurrentDynamicZones;
/*0x1568*/ HashTable<int>                                LearnedRecipes;
/*0x1578*/ EQList<TradeskillRecipeCount*>                QualifyingRecipeCounts;
/*0x1588*/ HashTable<int>                                NonrepeatableQuests;
/*0x1598*/ HashTable<int>                                CompletedTasks;
/*0x15a8*/ HashTable<int>                                CompletedQuests;
/*0x15b8*/ UINT                                          AlchemyTimestamp;
/*0x15bc*/ bool                                          bGoHomeOverride;
/*0x15bd*/ bool                                          bSomethingHome;
/*0x15c0*/ DWORD                                         LoginTime;                      // next must start on 8 align
/*0x15c8*/ int64_t                                       GuildID;                        // GuildID_0
/*0x15d0*/ int64_t                                       FellowshipID;
/*0x15d8*/ FELLOWSHIPINFO*                               pFellowship;
/*0x15dc*/ bool                                          GuildShowSprite;
/*0x15e0*/ UINT                                          CreationTime;                   // CharCreationTime
/*0x15e4*/ UINT                                          AccountCreationTime;
/*0x15e8*/ UINT                                          LastPlayedTime;
/*0x15ec*/ DWORD                                         MinutesPlayed;
/*0x15f0*/ BYTE                                          Anonymous;
/*0x15f1*/ bool                                          bGM;
/*0x15f2*/ bool                                          bGMStealth;
/*0x15f4*/ DWORD                                         AAExp;                          // Post60Exp
/*0x15f8*/ BYTE                                          NobilityRank;
/*0x15f9*/ BYTE                                          PercentEXPtoAA;
/*0x15fc*/ int                                           AirSupply;
/*0x1600*/ int                                           SerialNum;
/*0x1604*/ bool                                          bNewCharacter;
/*0x1608*/ int                                           TasksAssigned;
/*0x160c*/ int                                           TasksCompleted;
/*0x1610*/ long                                          TaskRequestTimer;
/*0x1614*/ unsigned int                                  UniquePlayerID;
/*0x1618*/ WorldLocation                                 DynamicZoneSafeReturnLocation;  // size 0x14
/*0x162c*/ DynamicZoneTimerData*                         pDZTimerRoot;
/*0x1630*/ DWORD                                         TributeTimer;
/*0x1634*/ DWORD                                         BenefitTimer;
/*0x1638*/ int64_t                                       CareerFavor;
/*0x1640*/ int64_t                                       CurrFavor;
/*0x1648*/ bool                                          bBenefitsActive;
/*0x1649*/ bool                                          bTrophyBenefitsActive;
/*0x164a*/ bool                                          bHasResetStartingCity;
/*0x164b*/ bool                                          bIsHeadStartCharacter;
/*0x164c*/ int                                           PvPKills;
/*0x1650*/ int                                           PvPDeaths;
/*0x1654*/ int                                           PvPCurrentPoints;
/*0x1658*/ int                                           PvPTotalPointsEarned;
/*0x165c*/ int                                           PvPKillStreak;
/*0x1660*/ int                                           PvPDeathStreak;
/*0x1664*/ int                                           PvPCurrentStreak;
/*0x1668*/ PvPKill                                       LastKill;                       // size 0x58
/*0x16c0*/ PvPDeath                                      LastDeath;                      // size 0x58
/*0x1718*/ HashTable<PvPKill24HourData>                  PvPLast24HoursKillHash;         // for sure see 5843D0
/*0x1728*/ int                                           PvPInfamyLevel;
/*0x172c*/ int                                           PvPVitality;
/*0x1730*/ UINT                                          PvPLastInfamyTime;
/*0x1734*/ int                                           LastLastNameChange;
/*0x1738*/ int                                           LastNameChangePriv;
/*0x173c*/ UINT                                          PvPLastVitalityTime;
/*0x1740*/ bool                                          bKeepItemsOnDeath;
/*0x1741*/ bool                                          bResetSpecializationSkills;
/*0x1744*/ DWORD                                         RadiantCrystals;                // GoodPointsAvailable
/*0x1748*/ int                                           GoodTotalPointsEarned;
/*0x174c*/ DWORD                                         EbonCrystals;                   // EvilPointsAvailable
/*0x1750*/ int                                           EvilTotalPointsEarned;
/*0x1754*/ bool                                          bCanRequestNameChange;
/*0x1755*/ bool                                          bCanRequestNameChange2;
/*0x1756*/ bool                                          bCanRequestServerTransfer;
/*0x1757*/ bool                                          bIsCopied;
/*0x1758*/ int                                           ServerTransferGrantTime;
/*0x175c*/ bool                                          bCanRequestRaceChange;
/*0x1760*/ UINT                                          LastAAResetTime;
/*0x1764*/ UINT                                          LastMercAAResetTime;
/*0x1768*/ DWORD                                         NewZoneID;                      // EQZoneIndex
/*0x176c*/ int                                           NewAreaID;
/*0x1770*/ int                                           eNewAreaCorner;                 // EAreaCorner
/*0x1774*/ DWORD                                         PreviousZoneID;                 // EQZoneIndex
/*0x1778*/ int                                           RealEstateZoneID;
/*0x177c*/ CHAR                                          ServerCreated[0x20];
/*0x179c*/ PCAdventureData                               AdventureData;                  // size 0x0d8
/*0x1874*/ PCSharedTaskData                              SharedTaskData;                 // size 0x8c
/*0x1900*/ TaskTimerData*                                pTaskTimerData;
/*0x1904*/ PCQuestHistoryData                            QuestHistoryData;               // size 0x258
/*0x1B5c*/ PCStatistics                                  PcStatistics;                   // size 0x104 i think
/*0x1C60*/ GroupMemberStats                              GroupStats;                     // size 0x150 i think
/*0x1Db0*/ BYTE                                          Unknown0x1Db0[0x9c];
/*0x1e4c*/ bool                                          bIsLfg;
/*0x1e50*/ int64_t                                       RaidId;                         // could be int
/*0x1e58*/ int64_t                                       GroupID;
/*0x1e60*/ int64_t                                       Exp;                            // confirmed jun 12 2017 test
/*0x1e68*/ int                                           DaysEntitled;
/*0x1e6c*/ int                                           SpentVeteranRewards;
/*0x1e70*/ bool                                          bVeteranRewardEntitled;
/*0x1e71*/ bool                                          bAutoConsentGroup;
/*0x1e72*/ bool                                          bAutoConsentRaid;
/*0x1e73*/ bool                                          bAutoConsentGuild;
/*0x1e74*/ bool                                          bPrivateForEqPlayers;
/*0x1e78*/ long                                          AchievementFilesModificationTime;
/*0x1e7c*/ char                                          StationID[0x20];
/*0x1ea0*/ EqGuid                                        Guid;                           // size 8 so it MUST start at a int64 sized address.. i.e. 0 or 8
/*0x1ea8*/ bool                                          bBetaBuffed;
/*0x1eac*/ int                                           Unknown0x1eac;
/*0x1eb0*/ int                                           StartingCity;
/*0x1eb4*/ int                                           MainLevel;
/*0x1eb8*/ bool	                                         bShowHelm;
/*0x1ec0*/ int64_t                                       LastTestCopyTime;
/*0x1ec8*/ CPlayerPointManager                           PointManager;                   // size 0x14
/*0x1edc*/ PointSystemBase                               PointSystem;                    // size 0x14
/*0x1ef0*/ UINT                                          LoyaltyVelocity;
/*0x1ef4*/ UINT                                          LoyaltyTokens;
/*0x1ef8*/ bool                                          bHasLoyaltyInfo;
/*0x1efc*/ ArrayClass_RO<int>                            OwnedRealEstates;
/*0x1f0c*/ ArrayClass_RO<int>                            OwnedItemRealEstates;
/*0x1f1c*/ ArrayClass_RO<int>                            ArchivedRealEstates;
/*0x1f2c*/ CHAR                                          OverridePetName[0x40];
/*0x1f6c*/ bool                                          bCanRequestPetNameChange;
/*0x1f6d*/ CHAR                                          OverrideFamiliarName[0x40];
/*0x1fad*/ bool                                          bCanRequestFamiliarNameChange;
/*0x1fb0*/ CXStr                                         OverrideMercName[0xb];
/*0x1Fdc*/ bool                                          bCanRequestMercNameChange;
/*0x1Fe0*/ PendingRewardList                             PendingRewards;                 // size 0x2c
/*0x200c*/ UINT                                          DowntimeReductionTime;
/*0x2010*/ UINT                                          DowntimeTimerStart;
/*0x2014*/ float                                         ActivityValue;
/*0x2018*/ UINT                                          NextItemId;
/*0x201c*/ CXStr                                         SharedBank;
/*0x2020*/ CXStr                                         BankBuffer;
/*0x2024*/ CXStr                                         LimboBuffer;
/*0x2028*/ CXStr                                         MercenaryBuffer;
/*0x202c*/ CXStr                                         KeyRingBuffer[3];
/*0x2038*/ CXStr                                         AltStorageBuffer;
/*0x203c*/ CXStr                                         ItemOverflow;
/*0x2040*/ UINT                                          AltStorageTimestamp;
/*0x2044*/ ELockoutCharacterReason                       LCR;
/*0x2048*/ HashTable<ProgressionExperience>              ProgressionExp;                 // size 0x10
/*0x2058*/ CXStr                                         ArchivedStorageBuffer;
/*0x205c*/ CXStr                                         MailItemsBuffer;
/*0x2060*/ CXStr                                         MailItemsDataBuffer;
/*0x2064*/ int                                           MailItemsOverCapWarningCount;
/*0x2068*/ ItemIndex                                     StatKeyRingItemIndex[3];        // size 0x12
/*0x207a*/ BYTE                                          UseAdvancedLooting;             // 0x1ff2 confirmed jun 12 2017 test               //0=off 1=on
/*0x207b*/ BYTE                                          MasterLootCandidate;            // 0=off 1=on
/*0x207c*/ bool                                          bIsCorrupted;
/*0x2080*/ char*                                         pCorruptionReport;
/*0x2084*/ TString<0x100>                                InspectText;
/*0x2184*/ HashTable<int>                                BlockedSpellsHash;
/*0x2194*/ int                                           BlockedSpell[0x28];
/*0x2234*/ HashTable<int>                                BlockedPetSpellsHash;
/*0x2244*/ int                                           BlockedPetSpell[0x28];
/*0x22e4*/ ClaimDataCollection                           ConsumableFeatures;             // size 0x10
/*0x22f4*/ bool                                          bGrantItemsRegistered;
/*0x22f8*/ uint64_t                                      CreatedGuildID;
/*0x2300*/ UINT                                          GuildCreateTime;
/*0x2304*/ CXStr                                         GuildCreateCharacter;
/*0x2308*/ bool                                          bInventoryUnserialized;
/*0x2309*/ bool                                          bAltStorageUnserialized;
/*0x230a*/ bool                                          bArchivedStorageUnserialized;
/*0x230b*/ bool                                          bMailUnserialized;
/*0x230c*/ bool                                          bPendingInventorySerialization;
/*0x2310*/ CXStr                                         BuyLines;
/*0x2314*/ ArrayClass<CXStr>                             OfflineTraderSoldItems;         // size 0x10
/*0x2324*/ ArrayClass<CXStr>                             OfflineBuyerBoughtItems;        // size 0x10
/*0x2334*/ DWORD                                         Krono;                          // confirmed jun 12 2017 test
/*0x2338*/ DWORD                                         CursorKrono;
/*0x233c*/ BYTE                                          Unknown0x233c[0x4];
/*0x2340*/ int64_t                                       MercAAExp;                      // divide this with 3.30f and you get the percent - eqmule
/*0x2348*/ DWORD                                         MercAAPoints;                   // number of unspent merc AA points
/*0x234c*/ DWORD                                         MercAAPointsSpent;              // number of spent merc AA points
/*0x2350*/ ArrayClass_RO<MercenaryAbilityInfo*>          MercenaryAbilities;//size 0x10
/*0x2360*/ HashTable<CompletedAchievementData, int, ResizePolicyNoShrink>         CompletedAchievements;               // size 0x10
/*0x2370*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> CompletedEventBasedSubComponents;    // size 0x10
/*0x2380*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> OpenEventBasedSubComponents;         // size 0x10
/*0x2390*/ int                                           LastFellowshipJoin;             // next is 8 bit aligned
/*0x2398*/ int64_t                                       Vitality;
/*0x23a0*/ int                                           AAVitality;
/*0x23a4*/ int                                           Unknown0x23a4;
/*0x23a8*/ int                                           FPStuff[0x1c];
/*0x2418*/
/********************* PcBase End **********************/
/************ CharacterZoneClient Begin ****************/
/*0x2418*/ void*                                         PcClient_CharacterZoneClient_vfTable; // see 61FB6A Nov 02 2018 beta
/*0x241c*/ EQC_INFO*                                     eqc_info;
/*0x2420*/ SPAWNINFO*                                    pSpawn;                         // pSpawn_0
/*0x2424*/ bool                                          bUpdateStuff;
/*0x2425*/ bool                                          bZoningStatProcessing;
/*0x2428*/ DWORD                                         ArmorClassBonus;                // vtable2+10
/*0x242c*/ DWORD                                         CurrWeight;                     // vtable2+14
/*0x2430*/ int                                           LastHitPointSendPercent;
/*0x2434*/ int                                           LastManaPointSendPercent;
/*0x2438*/ int                                           LastEndurancePointSendPercent;
/*0x243c*/ DWORD                                         HPBonus;                        // vtable2+24
/*0x2440*/ DWORD                                         ManaBonus;                      // vtable2+28
/*0x2444*/ DWORD                                         EnduranceBonus;                 // vtable2+2c
/*0x2448*/ int                                           EnduranceCostPerSecond;
/*0x244c*/ DWORD                                         CombatEffectsBonus;             // vtable2+34 Combat Effects in UI
/*0x2450*/ DWORD                                         ShieldingBonus;                 // vtable2+38 Melee Shielding in UI
/*0x2454*/ DWORD                                         SpellShieldBonus;               // vtable2+3c Spell Shielding in UI
/*0x2458*/ DWORD                                         AvoidanceBonus;                 // vtable2+40 Avoidance in UI
/*0x245c*/ DWORD                                         AccuracyBonus;                  // vtable2+44 Accuracy in UI
/*0x2460*/ DWORD                                         StunResistBonus;                // vtable2+48 Stun Resist in UI
/*0x2464*/ DWORD                                         StrikeThroughBonus;             // vtable2+4c Strike Through in UI
/*0x2468*/ DWORD                                         DoTShieldBonus;                 // vtable2+50 Dot Shielding in UI
/*0x246c*/ DWORD                                         DamageShieldMitigationBonus;    // vtable2+54 Damage Shield Mitig in UI
/*0x2470*/ DWORD                                         DamageShieldBonus;              // vtable2+58 Damage Shielding in UI
/*0x2474*/ TSafeArrayStatic<int, 9>                      ItemSkillMinDamageMod;          // size 0x24
/*0x2498*/ TSafeArrayStatic<int, 9>                      SkillMinDamageModBonus;         // size 0x24
/*0x24bc*/ DWORD                                         HeroicSTRBonus;                 // vtable2+a4
/*0x24c0*/ DWORD                                         HeroicINTBonus;                 // vtable2+a8
/*0x24c4*/ DWORD                                         HeroicWISBonus;                 // vtable2+ac
/*0x24c8*/ DWORD                                         HeroicAGIBonus;                 // vtable2+b0
/*0x24cc*/ DWORD                                         HeroicDEXBonus;                 // vtable2+b4
/*0x24d0*/ DWORD                                         HeroicSTABonus;                 // vtable2+b8
/*0x24d4*/ DWORD                                         HeroicCHABonus;                 // vtable2+bc
/*0x24d8*/ DWORD                                         HealAmountBonus;                // vtable2+d8
/*0x24dc*/ DWORD                                         SpellDamageBonus;               // vtable2+dc
/*0x24e0*/ int                                           ItemHealAmountDotMod;
/*0x24e4*/ int                                           ItemSpellDamageDotMod;
/*0x24e8*/ DWORD                                         ClairvoyanceBonus;              // vtable2+e8
/*0x24ec*/ DWORD                                         AttackBonus;                    // vtable2+ec
/*0x24f0*/ DWORD                                         HPRegenBonus;                   // vtable2+f0
/*0x24f4*/ DWORD                                         ManaRegenBonus;                 // vtable2+f4
/*0x24f8*/ DWORD                                         EnduranceRegenBonus;            // vtable2+f8
/*0x24fc*/ DWORD                                         AttackSpeed;                    // vtable2+fc
/*0x2500*/ int                                           NoBuffItemHitpointAdjustment;
/*0x2504*/ int                                           NoBuffItemManaAdjustment;
/*0x2508*/ int                                           NoBuffItemEnduranceAdjustment;
/*0x250c*/ int                                           NoBuffItemBaseChanceProc;
/*0x2510*/ int                                           NoBuffItemMinDamageMod;
/*0x2514*/ int                                           NoBuffItemInnateSpellRune;
/*0x2518*/ int                                           NoBuffItemAvoidance;
/*0x251c*/ int                                           NoBuffItemToHit;
/*0x2520*/ int                                           NoBuffItemResistStunChance;
/*0x2524*/ int                                           NoBuffItemDotShieldingEffect;
/*0x2528*/ int                                           NoBuffItemStrikeThroughChance;
/*0x252c*/ int                                           NoBuffItemAttack;
/*0x2530*/ int                                           NoBuffItemHitPointRegen;
/*0x2534*/ int                                           NoBuffItemManaRegen;
/*0x2538*/ int                                           NoBuffItemEnduranceRegen;
/*0x253c*/ int                                           NoBuffItemDamageShield;
/*0x2540*/ int                                           NoBuffItemDamageShieldMitigation;
/*0x2544*/ int                                           NoBuffItemHaste;
/*0x2548*/ TSafeArrayStatic<int, 9>                      NoBuffItemSkillMinDamageMod;    // size 0x24
/*0x256c*/ bool                                          bOutputHpRegen;
/*0x256d*/ bool                                          bInvulnerable;
/*0x256e*/ bool                                          bOnAVehicle;                    // 0x2420 + 0x156 see 4D94E8 in jun 11 2018 test
/*0x2570*/ SpellCache                                    spellCache;                     // size 0x58
/*0x25c8*/ HashListSet<int, 0x80>                        DoomEffectsBySlot;              // size 0x10 + (0x80 * 4)
/*0x27d8*/ UINT                                          LastHitEval;
/*0x27dc*/
/*********************** CharacterZoneClient End ***********************/
/******************* PcZoneClient Begin ******************/
/*0x27dc*/ void*                                         PcZoneClient_vfTable;           // see 61A04C jun 11 test 2018
/*0x27e0*/ TSafeArrayStatic<unsigned long, 3>            Flags;                          // size 0xc
/*0x27ec*/ uint32_t                                      TransfersReceived;
/*0x27f0*/ int                                           LastLanguageSpoken;
/*0x27f4*/ int                                           CurPowerSourceDrain;
/*0x27f8*/ EQList<ALCHEMYBONUSSKILLDATA*>                AlchemyBaseSkillBonusList;
/*0x2808*/ UINT                                          MomentumBalance; 
/*0x280c*/ UINT                                          LoyaltyRewardBalance;
/*0x2810*/
/******************* PcZoneClient End ******************/
/******************* PCClient Begin ************************/
/*0x2810*/ ExtendedTargetList*                           pXTargetMgr;
/*0x2814*/ DWORD                                         InCombat;
/*0x2818*/ DWORD                                         Downtime;
/*0x281c*/ DWORD                                         DowntimeStamp;
/*0x2820*/ bool                                          bOverrideAvatarProximity;
/*0x2824*/ GROUPINFO*                                    pGroupInfo;
/*0x2828*/ bool                                          bIAmCreatingGroup;
/*0x282c*/ VeArray<VePointer<CONTENTS*>>                 ItemsPendingID;                 // size 0xc
/*0x2838*/ int                                           ParcelStatus;                   // eParcelStatus
/*0x283c*/ int                                           SubscriptionDays;               // 24BC for sure see 7A6C40 in may 11 2018 live exe
/*0x2840*/ short                                         BaseKeyRingSlots[3];
/*0x2846*/ bool                                          bPickZoneFewest;                // for sure see 4A424A in may 11 2018 live exe
/*0x2848*/ int                                           Unknown0x2848;
/*0x284c*/
/******************* PCClient End ************************/
/******************* CharacterBase Begin ************************/
/*0x284c*/ void*                                         CharacterBase_vftable;
/*0x2850*/ CProfileManager                               ProfileManager;
/*0x2858*/ TSafeArrayStatic<BYTE, 0x20>                  languages;
/*0x2878*/ float                                         X;
/*0x287c*/ float                                         Y;
/*0x2880*/ float                                         Z;
/*0x2884*/ float                                         Heading;
/*0x2888*/ CHAR                                          Name[0x40];                     // CharBaseBegin+44
/*0x28c8*/ CHAR                                          Lastname[0x20];                 // CharBaseBegin+84
/*0x28e8*/ TSafeString<0x80>                             Title;
/*0x2968*/ TSafeString<0x40>                             VehicleName;
/*0x29a8*/ BYTE                                          Stunned;                        // CharBaseBegin+104
/*0x29a9*/ BYTE                                          Unknown0x29a9[0x3];
	union {
/*0x29ac*/ int                                           zoneId;                         // CharBaseBegin+108 Zone_0
		struct {
/*0x29ac*/ WORD                                          Unknown0x29ac;
/*0x29ae*/ WORD                                          instance;
		};
	};
/*0x29b0*/ BYTE                                          standstate;                     // CharBaseBegin+10c
/*0x29b4*/ RaidData                                      raidData;                       // size 0xdc
/*0x2a90*/ DWORD                                         ExpansionFlags;                 // CharBaseBegin+464
/*0x2a94*/ bool                                          bSuperPKILL;
/*0x2a95*/ bool                                          bUnclone;
/*0x2a96*/ bool                                          bDead;
/*0x2a98*/ int                                           LD_Timer;
/*0x2a9c*/ int                                           SpellInterruptCount;
/*0x2aa0*/ bool                                          bAutoSplit;
/*0x2aa1*/ bool                                          bTellsOff;
/*0x2aa2*/ bool                                          bGmInvis;
/*0x2aa4*/ int                                           KillMe;
/*0x2aa8*/ bool                                          CheaterLdFlag;                  // likely this is int SoulMarkCount instead.
/*0x2aa9*/ bool                                          NoRent;
/*0x2aaa*/ bool                                          Corpse;
/*0x2aab*/ bool                                          ClientGmFlagSet;
/*0x2aac*/ DWORD                                         BankSharedPlat;                 // 31e4 CharBaseBegin+488
/*0x2ab0*/ DWORD                                         BankSharedGold;                 // CharBaseBegin+48c
/*0x2ab4*/ DWORD                                         BankSharedSilver;               // CharBaseBegin+490
/*0x2ab8*/ DWORD                                         BankSharedCopper;               // CharBaseBegin+494
/*0x2abc*/ DWORD                                         BankPlat;                       // CharBaseBegin+498
/*0x2ac0*/ DWORD                                         BankGold;                       // CharBaseBegin+49c
/*0x2ac4*/ DWORD                                         BankSilver;                     // CharBaseBegin+4a0
/*0x2ac8*/ DWORD                                         BankCopper;                     // CharBaseBegin+4a4
/*0x2acc*/ DWORD                                         STR;                            // CharBaseBegin+4a8
/*0x2ad0*/ DWORD                                         STA;                            // CharBaseBegin+4ac
/*0x2ad4*/ DWORD                                         CHA;                            // CharBaseBegin+4b0
/*0x2ad8*/ DWORD                                         DEX;                            // CharBaseBegin+4b4
/*0x2adc*/ DWORD                                         INT;                            // CharBaseBegin+4b8
/*0x2ae0*/ DWORD                                         AGI;                            // CharBaseBegin+4bc
/*0x2ae4*/ DWORD                                         WIS;                            // CharBaseBegin+4c0
/*0x2ae8*/ DWORD                                         LCK;                            // CharBaseBegin+4c4
/*0x2aec*/ DWORD                                         SavePoison;                     // CharBaseBegin+4c8
/*0x2af0*/ DWORD                                         SaveMagic;                      // CharBaseBegin+4cc
/*0x2af4*/ DWORD                                         SaveDisease;                    // CharBaseBegin+4d0
/*0x2af8*/ DWORD                                         SaveCorruption;                 // CharBaseBegin+4d4
/*0x2afc*/ DWORD                                         SaveFire;                       // CharBaseBegin+4d8
/*0x2b00*/ DWORD                                         SaveCold;                       // CharBaseBegin+4dc
/*0x2b04*/ DWORD                                         SavePhysical;                   // CharBaseBegin+4e0
/*0x2b08*/ int                                           UncappedStr;
/*0x2b0c*/ int                                           UncappedSta;
/*0x2b10*/ int                                           UncappedCha;
/*0x2b14*/ int                                           UncappedDex;
/*0x2b18*/ int                                           UncappedInt;
/*0x2b1c*/ int                                           UncappedAgi;
/*0x2b20*/ int                                           UncappedWis;
/*0x2b24*/ int                                           UncappedResistPoison;
/*0x2b28*/ int                                           UncappedResistMagic;
/*0x2b2c*/ int                                           UncappedResistDisease;
/*0x2b30*/ int                                           UncappedResistCorruption;
/*0x2b34*/ int                                           UncappedResistFire;
/*0x2b38*/ int                                           UncappedResistCold;
/*0x2b3c*/ int                                           UncappedResistPhysical;
/*0x2b40*/ int                                           NoBuffStr;
/*0x2b44*/ int                                           NoBuffSta;
/*0x2b48*/ int                                           NoBuffCha;
/*0x2b4c*/ int                                           NoBuffDex;
/*0x2b50*/ int                                           NoBuffInt;
/*0x2b54*/ int                                           NoBuffAgi;
/*0x2b58*/ int                                           NoBuffWis;
/*0x2b5c*/ int                                           NoBuffResistPoison;
/*0x2b60*/ int                                           NoBuffResistMagic;
/*0x2b64*/ int                                           NoBuffResistDisease;
/*0x2b68*/ int                                           NoBuffResistCorruption;
/*0x2b6c*/ int                                           NoBuffResistFire;
/*0x2b70*/ int                                           NoBuffResistCold;
/*0x2b74*/ int                                           NoBuffResistPhysical;
/*0x2b78*/
};

//============================================================================
// CHARINFO2 a.k.a. PcProfile
//============================================================================

#if !USE_NEW_PCPROFILE
//aSdeityD CharInfo2__CharInfo2
#define CHARINFO2_Size 0xAFE8 // Jun 10 2019 test (see 8A2309) - eqmule

struct CHARINFO2
{
/******************************** BaseProfile Start ********************************/
/*0x0000*/ BYTE                                            Unknown0x0000[0x10];
/*0x0010*/ DWORD                                           BaseProfile;
/*0x0014*/ BYTE                                            Unknown0x0014[0x8];
/*0x001C*/ INVENTORYARRAY*                                 pInventoryArray;
/*0x0020*/ BYTE                                            Unknown0x0020[0x48];
/*0x0068*/ SPELLBUFF                                       Buff[NUM_LONG_BUFFS];                   // EQ_Affect size is 0x68 * 0x2a = 0x1110
/*0x1178*/ SPELLBUFF                                       ShortBuff[NUM_SHORT_BUFFS];             // EQ_Affect size is 0x68 * 0x37 = 0x1658
	// these IDs are gone (or moved?) from june 10 2019 test we never really used them so whatever... -eqmule
	//*0x27d0*/ DWORD    CasterSpellIDs[NUM_BUFF_SLOTS]; // caster IDs for the Effects Window of whoever cast the buff on you in the same zone...
/*0x27d0*/ DWORD                                           DiseaseSpreadTimers[NUM_BUFF_SLOTS];
/*0x2954*/ DWORD                                           SpellBook[NUM_BOOK_SLOTS];
/*0x3854*/ DWORD                                           MemorizedSpells[0x12];
/*0x389c*/ DWORD                                           Skill[NUM_SKILLS];
/*0x3a2c*/ DWORD                                           InnateSkill[0x19];
/*0x3a90*/ TSafeArrayStatic<ArmorProperties, 9>            ArmorProps;                             // size 0xb4
/*0x3b44*/ TSafeArrayStatic<DWORD, 9>                      CharacterTint;                          // size 0x24
/*0x3b68*/ BYTE                                            Gender;
/*0x3b6c*/ DWORD                                           Race;
/*0x3b70*/ DWORD                                           Class;
/*0x3b74*/ HashTable<int>                                  properties;
/*0x3b84*/ DWORD                                           Level;
/*0x3b88*/ DWORD                                           Mana;
/*0x3b8c*/ DWORD                                           Endurance;
/*0x3b90*/ int64_t                                         BaseHP;
/*0x3b98*/ DWORD                                           BaseSTR;
/*0x3b9c*/ DWORD                                           BaseSTA;
/*0x3ba0*/ DWORD                                           BaseCHA;
/*0x3ba4*/ DWORD                                           BaseDEX;
/*0x3ba8*/ DWORD                                           BaseINT;
/*0x3bac*/ DWORD                                           BaseAGI;
/*0x3bb0*/ DWORD                                           BaseWIS;
/*0x3bb4*/ BYTE                                            Face;
/*0x3bb8*/ DWORD                                           Plat;
/*0x3bbc*/ DWORD                                           Gold;
/*0x3bc0*/ DWORD                                           Silver;
/*0x3bc4*/ DWORD                                           Copper;
/*0x3bc8*/ DWORD                                           CursorPlat;
/*0x3bcc*/ DWORD                                           CursorGold;
/*0x3bd0*/ DWORD                                           CursorSilver;
/*0x3bd4*/ DWORD                                           CursorCopper;
/*0x3bd8*/ int                                             _max_allowed_spell_slots;
/*0x3bdc*/ int                                             practices;
/*0x3be0*/ int                                             height;
/*0x3be4*/ int                                             width;
/*0x3be8*/ int                                             length;
/*0x3bec*/ int                                             view_height;
/*0x3bf0*/ char                                            texture_type;
/*0x3bf1*/ char                                            m_armorMat;
/*0x3bf2*/ char                                            m_armorVariation;
/*0x3bf3*/ char                                            headType;
/*0x3bf4*/ char                                            caneditface;
/*0x3bf8*/ int                                             DisciplineTimer;
/*0x3bfc*/ UINT                                            MendTimer;
/*0x3c00*/ int                                             ForageTimer;
/*0x3c04*/ int                                             thirstlevel;
/*0x3c08*/ int                                             hungerlevel;
/*0x3c0c*/ int                                             PotionCount;
/*0x3c10*/ int                                             profileType;                            // enum PT_Main = 0, PT_Alt, PT_MonsterMission, PT_TypeUnknown
/*0x3c14*/ int                                             Shrouded;                               // templateId
/*0x3c18*/ int                                             systemId;
/*0x3c1c*/ int                                             designId;
/*0x3c20*/ int                                             InventorySlotBitmask;
/*0x3c24*/ UINT                                            CurrentProgressionID;
/*0x3c28*/ BYTE                                            Unknown0x3c28[0x54];
/*0x3c7c*/ int                                             ParentId;
/*0x3c80*/ int                                             TattooIndex;
/*0x3c84*/ int                                             FacialAttachmentIndex;
/******************************** BaseProfile End ********************************/
/******************************** PcProfile Start ********************************/
/*0x3c88*/ TSafeArrayStatic<WorldLocation, 5>              BoundLocations;                         // size 0x64 home_zone
/*0x3cec*/ TSafeArrayStatic<ArmorProperties, 0x16>         ArmorType;
/*0x3ea4*/ TSafeArrayStatic<AALIST, AA_CHAR_MAX_REAL>      AAList;                                 // AlternateAbilities
/*0x4cb4*/ TSafeArrayStatic<DWORD, 0x9>                    BodyColor;
/*0x4cd8*/ TSafeArrayStatic<int, 0x800>                    FactionTable;                           // factiontable
/*0x6cd8*/ TSafeArrayStatic<int, NUM_COMBAT_ABILITIES>     CombatAbilities;                        // KnownCombatAbilities
/*0x7188*/ TSafeArrayStatic<UINT, 0xF>                     SpellRecastTimer;                       // spell_used
/*0x71c4*/ TSafeArrayStatic<UINT, 0x19>                    CombatAbilityTimers;                    // fs
/*0x7228*/ TList<CombatAbilityTimer>                       CombatAbilityTimersList;                // size 8 for sure CombatAbilityTimersAddl
/*0x7230*/ TSafeArrayStatic<UINT, 0x19>                    LinkedSpellTimers;                      // for sure, we used to call thius CombatAbilityTimes...
/*0x7294*/ TSafeArrayStatic<UINT, 0x64>                    ItemRecastTimers;                       // for sure
/*0x7424*/ TSafeArrayStatic<UINT, 0x64>                    AATimers;                               // for sure
/*0x75b4*/ TSafeArrayStatic<BandolierSet, 0x14>            Bandolier;                              // size 0x1900 = 0x140 * 0x14 for sure see 8DE476 Jan 04 2019 test
/*0x8eb4*/ TSafeArrayStatic<BenefitSelection, 5>           ActiveTributeBenefits;                  // size 0x28 = 8 * 5 for sure see 8DE437 Jan 04 2019 test
/*0x8edc*/ TSafeArrayStatic<BenefitSelection, 0xa>         ActiveTrophyTributeBenefits;            // size 0x50 = 8 * 0xa
/*0x8f2c*/ ItemBaseContainer                               GuildTributeBenefitItems;               // size 0x1c for sure see 8C9D9C in 21 Sep 2018
/*0x8f48*/ ItemBaseContainer                               GuildTrophyTributeBenefitItems;         // size 0x1c
/*0x8f64*/ ArrayClass<CXStr>                               MercenarySaveStrings;                   // size 0x10
/*0x8f74*/ AssociatedNPCSaveStringNode*                    PetSaveString;                          // for sure
/*0x8f78*/ DWORD                                           Deity;                                  // fs see 8DE504 Jan 04 2019 test
/*0x8f7c*/ bool                                            bPVPFlag;
/*0x8f7d*/ BYTE                                            HighestLevel;
/*0x8f80*/ DWORD                                           Drunkenness;                            // inebriation
/*0x8f84*/ BYTE                                            HairColor;
/*0x8f85*/ BYTE                                            BeardColor;
/*0x8f88*/ int                                             NpcTintIndex;
/*0x8f8c*/ BYTE                                            LeftEye;
/*0x8f8d*/ BYTE                                            RightEye;
/*0x8f8e*/ BYTE                                            Hair;
/*0x8f8f*/ BYTE                                            Beard;
/*0x8f90*/ BYTE                                            OldFace;
/*0x8f94*/ DWORD                                           AAPoints;
/*0x8f98*/ CHAR                                            PocketPetSaveString[0x2000];            // 0x1000 in older clients
/*0xaf98*/ CXStr                                           ItemBuffer;
/*0xaf9c*/ UINT                                            LastShield;
/*0xafa0*/ bool                                            bSneak;
/*0xafa1*/ bool                                            bHide;
/*0xafa4*/ DWORD                                           AAPointsSpent;
/*0xafa8*/ DWORD                                           AAPointsAssigned[6];                    // none, general, arch, class, special, focus, merc
/*0xafc0*/ void*                                           pPetData;                               // PetObjectData todo fill in
/*0xafc4*/ DWORD                                           PrimActor;
/*0xafc8*/ DWORD                                           SecdActor;
/*0xafcc*/ bool                                            bUseTemplateFaction;
/*0xafd0*/ DWORD                                           TitlePrefixID;
/*0xafd4*/ DWORD                                           TitleSuffixID;
/*0xafd8*/ bool                                            bAreHandsMagic;
/*0xafdc*/ DWORD                                           SoleEnabledZoneID;
/*0xafe0*/ DWORD                                           NewBodyTint;
/*0xafe4*/ DWORD                                           CurrentMercenaryIndex;
/*0xafe8*/
/******************************** PcProfile End ********************************/
};
using PCHARINFO2 [[deprecated]] = CHARINFO2*;

#if !defined(NEWCHARINFO)
struct CI2_INFO
{
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
// EQ_Character
//============================================================================

// This is CharacterZoneClient now
class EQ_Character
{
public:
	EQLIB_OBJECT ~EQ_Character();
	EQLIB_OBJECT EQ_Character();
	EQLIB_OBJECT bool DoesSpellMatchFocusFilters(EQ_Spell const*, EQ_Spell const*);
	EQLIB_OBJECT bool IsSpellTooPowerfull(EQ_Spell*, EQ_Character*);
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
	EQLIB_OBJECT int BardCastBard(EQ_Spell const*, int) const;
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
#if defined(ROF2EMU) || defined(UFEMU)
	EQLIB_OBJECT void ModifyCurHP(int modification, PlayerZoneClient * resposibleplayer, int skilltype);
#else
	EQLIB_OBJECT void ModifyCurHP(int64_t modification, PlayerZoneClient* resposibleplayer, int skilltype);
#endif
	EQLIB_OBJECT void NotifyPCAffectChange(int, int);
	EQLIB_OBJECT void ProcessAllStats();
	EQLIB_OBJECT void ProcessEnvironment();
	EQLIB_OBJECT void ProcessHungerandThirst(unsigned int);
	EQLIB_OBJECT void RemovePCAffect(EQ_Affect*);
	EQLIB_OBJECT void RemovePCAffectex(EQ_Affect*, int);
	EQLIB_OBJECT void ResetCur_HP(int);
	EQLIB_OBJECT void UpdateMyVisibleStatus();
	EQLIB_OBJECT bool DoCombatAbility(int spellID, int dummy = 1);

	// PcClient::ConsiderTarget
	EQLIB_OBJECT unsigned long GetConLevel(const PlayerClient*);

	// private
	EQLIB_OBJECT int GetCachEQSPA(int);
	EQLIB_OBJECT void ReCachItemEffects();
	EQLIB_OBJECT void ReCachSpellEffects();
};

// This is also CharacterZoneClient
class EQ_Character1
{
public:
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
};

//============================================================================
// EQ_PC
//============================================================================

struct ItemContainingRealEstate
{
	int                RealEstateID;
	ItemGlobalIndex    ItemLocation;
};

// This is now PcZoneClient. Most of this class is defunct
class EQ_PC
{
public:
	EQLIB_OBJECT ~EQ_PC();
	EQLIB_OBJECT EQ_PC(EQ_PC*);
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
	EQLIB_OBJECT static EQ_PC* top;
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
	// EQLIB_OBJECT GetCombatAbilityTimer has 2 parameters confirmed apr 21 2016 eqgame.exe (live)
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT unsigned long GetCombatAbilityTimer(int, int);
	EQLIB_OBJECT unsigned long GetItemRecastTimer(EQ_Item* item, ItemSpellTypes etype);
#else
	EQLIB_OBJECT unsigned long GetCombatAbilityTimer(int);
	EQLIB_OBJECT unsigned long GetItemRecastTimer(class EQ_Item* item);
#endif
	EQLIB_OBJECT bool HasLoreItem(EQ_Item*, int, int, int, int);
	EQLIB_OBJECT void GetItemContainedRealEstateIds(ArrayClass<ItemContainingRealEstate>& Out, bool bCurrentProfileOnly = false, bool bIncludeAltStorage = true, bool bIncludeArchived = true);
	EQLIB_OBJECT void GetNonArchivedOwnedRealEstates(ArrayClass<int>& output);
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

class BaseProfile
{
public:
	EQLIB_OBJECT VePointer<CONTENTS> GetItemPossession(const ItemIndex& index) const;

/*0x0000*/ BYTE                                            Unknown0x0000[0x10];
/*0x0010*/ DWORD                                           BaseProfile;
/*0x0014*/ BYTE                                            Unknown0x0014[0x8];
/*0x001C*/ INVENTORYARRAY*                                 pInventoryArray;
/*0x0020*/ BYTE                                            Unknown0x0020[0x48];
/*0x0068*/ SPELLBUFF                                       Buff[NUM_LONG_BUFFS];                   // EQ_Affect size is 0x68 * 0x2a = 0x1110
/*0x1178*/ SPELLBUFF                                       ShortBuff[NUM_SHORT_BUFFS];             // EQ_Affect size is 0x68 * 0x37 = 0x1658
	// these IDs are gone (or moved?) from june 10 2019 test we never really used them so whatever... -eqmule
	//*0x27d0*/ DWORD    CasterSpellIDs[NUM_BUFF_SLOTS]; // caster IDs for the Effects Window of whoever cast the buff on you in the same zone...
/*0x27d0*/ DWORD                                           DiseaseSpreadTimers[NUM_BUFF_SLOTS];
/*0x2954*/ DWORD                                           SpellBook[NUM_BOOK_SLOTS];
/*0x3854*/ DWORD                                           MemorizedSpells[0x12];
/*0x389c*/ DWORD                                           Skill[NUM_SKILLS];
/*0x3a2c*/ DWORD                                           InnateSkill[0x19];
/*0x3a90*/ TSafeArrayStatic<ArmorProperties, 9>            ArmorProps;                             // size 0xb4
/*0x3b44*/ TSafeArrayStatic<DWORD, 9>                      CharacterTint;                          // size 0x24
/*0x3b68*/ BYTE                                            Gender;
/*0x3b6c*/ DWORD                                           Race;
/*0x3b70*/ DWORD                                           Class;
/*0x3b74*/ HashTable<int>                                  properties;
/*0x3b84*/ DWORD                                           Level;
/*0x3b88*/ DWORD                                           Mana;
/*0x3b8c*/ DWORD                                           Endurance;
/*0x3b90*/ int64_t                                         BaseHP;
/*0x3b98*/ DWORD                                           BaseSTR;
/*0x3b9c*/ DWORD                                           BaseSTA;
/*0x3ba0*/ DWORD                                           BaseCHA;
/*0x3ba4*/ DWORD                                           BaseDEX;
/*0x3ba8*/ DWORD                                           BaseINT;
/*0x3bac*/ DWORD                                           BaseAGI;
/*0x3bb0*/ DWORD                                           BaseWIS;
/*0x3bb4*/ BYTE                                            Face;
/*0x3bb8*/ DWORD                                           Plat;
/*0x3bbc*/ DWORD                                           Gold;
/*0x3bc0*/ DWORD                                           Silver;
/*0x3bc4*/ DWORD                                           Copper;
/*0x3bc8*/ DWORD                                           CursorPlat;
/*0x3bcc*/ DWORD                                           CursorGold;
/*0x3bd0*/ DWORD                                           CursorSilver;
/*0x3bd4*/ DWORD                                           CursorCopper;
/*0x3bd8*/ int                                             _max_allowed_spell_slots;
/*0x3bdc*/ int                                             practices;
/*0x3be0*/ int                                             height;
/*0x3be4*/ int                                             width;
/*0x3be8*/ int                                             length;
/*0x3bec*/ int                                             view_height;
/*0x3bf0*/ char                                            texture_type;
/*0x3bf1*/ char                                            m_armorMat;
/*0x3bf2*/ char                                            m_armorVariation;
/*0x3bf3*/ char                                            headType;
/*0x3bf4*/ char                                            caneditface;
/*0x3bf8*/ int                                             DisciplineTimer;
/*0x3bfc*/ UINT                                            MendTimer;
/*0x3c00*/ int                                             ForageTimer;
/*0x3c04*/ int                                             thirstlevel;
/*0x3c08*/ int                                             hungerlevel;
/*0x3c0c*/ int                                             PotionCount;
/*0x3c10*/ int                                             profileType;                            // enum PT_Main = 0, PT_Alt, PT_MonsterMission, PT_TypeUnknown
/*0x3c14*/ int                                             Shrouded;                               // templateId
/*0x3c18*/ int                                             systemId;
/*0x3c1c*/ int                                             designId;
/*0x3c20*/ int                                             InventorySlotBitmask;
/*0x3c24*/ UINT                                            CurrentProgressionID;
/*0x3c28*/ BYTE                                            Unknown0x3c28[0x54];
/*0x3c7c*/ int                                             ParentId;
/*0x3c80*/ int                                             TattooIndex;
/*0x3c84*/ int                                             FacialAttachmentIndex;
};

//============================================================================
// PcProfile
//============================================================================

class PcProfile : public BaseProfile
{
public:
/*0x3c88*/ TSafeArrayStatic<WorldLocation, 5>              BoundLocations;                         // size 0x64 home_zone
/*0x3cec*/ TSafeArrayStatic<ArmorProperties, 0x16>         ArmorType;
/*0x3ea4*/ TSafeArrayStatic<AALIST, AA_CHAR_MAX_REAL>      AAList;                                 // AlternateAbilities
/*0x4cb4*/ TSafeArrayStatic<DWORD, 0x9>                    BodyColor;
/*0x4cd8*/ TSafeArrayStatic<int, 0x800>                    FactionTable;                           // factiontable
/*0x6cd8*/ TSafeArrayStatic<int, NUM_COMBAT_ABILITIES>     CombatAbilities;                        // KnownCombatAbilities
/*0x7188*/ TSafeArrayStatic<UINT, 0xF>                     SpellRecastTimer;                       // spell_used
/*0x71c4*/ TSafeArrayStatic<UINT, 0x19>                    CombatAbilityTimers;                    // fs
/*0x7228*/ TList<CombatAbilityTimer>                       CombatAbilityTimersList;                // size 8 for sure CombatAbilityTimersAddl
/*0x7230*/ TSafeArrayStatic<UINT, 0x19>                    LinkedSpellTimers;                      // for sure, we used to call thius CombatAbilityTimes...
/*0x7294*/ TSafeArrayStatic<UINT, 0x64>                    ItemRecastTimers;                       // for sure
/*0x7424*/ TSafeArrayStatic<UINT, 0x64>                    AATimers;                               // for sure
/*0x75b4*/ TSafeArrayStatic<BandolierSet, 0x14>            Bandolier;                              // size 0x1900 = 0x140 * 0x14 for sure see 8DE476 Jan 04 2019 test
/*0x8eb4*/ TSafeArrayStatic<BenefitSelection, 5>           ActiveTributeBenefits;                  // size 0x28 = 8 * 5 for sure see 8DE437 Jan 04 2019 test
/*0x8edc*/ TSafeArrayStatic<BenefitSelection, 0xa>         ActiveTrophyTributeBenefits;            // size 0x50 = 8 * 0xa
/*0x8f2c*/ ItemBaseContainer                               GuildTributeBenefitItems;               // size 0x1c for sure see 8C9D9C in 21 Sep 2018
/*0x8f48*/ ItemBaseContainer                               GuildTrophyTributeBenefitItems;         // size 0x1c
/*0x8f64*/ ArrayClass<CXStr>                               MercenarySaveStrings;                   // size 0x10
/*0x8f74*/ AssociatedNPCSaveStringNode*                    PetSaveString;                          // for sure
/*0x8f78*/ DWORD                                           Deity;                                  // fs see 8DE504 Jan 04 2019 test
/*0x8f7c*/ bool                                            bPVPFlag;
/*0x8f7d*/ BYTE                                            HighestLevel;
/*0x8f80*/ DWORD                                           Drunkenness;                            // inebriation
/*0x8f84*/ BYTE                                            HairColor;
/*0x8f85*/ BYTE                                            BeardColor;
/*0x8f88*/ int                                             NpcTintIndex;
/*0x8f8c*/ BYTE                                            LeftEye;
/*0x8f8d*/ BYTE                                            RightEye;
/*0x8f8e*/ BYTE                                            Hair;
/*0x8f8f*/ BYTE                                            Beard;
/*0x8f90*/ BYTE                                            OldFace;
/*0x8f94*/ DWORD                                           AAPoints;
/*0x8f98*/ CHAR                                            PocketPetSaveString[0x2000];            // 0x1000 in older clients
/*0xaf98*/ CXStr                                           ItemBuffer;
/*0xaf9c*/ UINT                                            LastShield;
/*0xafa0*/ bool                                            bSneak;
/*0xafa1*/ bool                                            bHide;
/*0xafa4*/ DWORD                                           AAPointsSpent;
/*0xafa8*/ DWORD                                           AAPointsAssigned[6];                    // none, general, arch, class, special, focus, merc
/*0xafc0*/ void*                                           pPetData;                               // PetObjectData todo fill in
/*0xafc4*/ DWORD                                           PrimActor;
/*0xafc8*/ DWORD                                           SecdActor;
/*0xafcc*/ bool                                            bUseTemplateFaction;
/*0xafd0*/ DWORD                                           TitlePrefixID;
/*0xafd4*/ DWORD                                           TitleSuffixID;
/*0xafd8*/ bool                                            bAreHandsMagic;
/*0xafdc*/ DWORD                                           SoleEnabledZoneID;
/*0xafe0*/ DWORD                                           NewBodyTint;
/*0xafe4*/ DWORD                                           CurrentMercenaryIndex;
/*0xafe8*/
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

class CharacterBase
{
public:
/*0x0000*/ void*                       CharacterBase_vftable;
/*0x0004*/ CProfileManager             ProfileManager;
/*0x000C*/ TSafeArrayStatic<BYTE, 0x20> languages;
/*0x002C*/ float                       X;
/*0x0030*/ float                       Y;
/*0x0034*/ float                       Z;
/*0x0038*/ float                       Heading;
/*0x003c*/ TSafeString<0x40>           Name;
/*0x007c*/ TSafeString<0x20>           Lastname;
/*0x009c*/ TSafeString<0x80>           Title;
/*0x011c*/ TSafeString<0x40>           VehicleName;
/*0x015c*/ char                        Stunned;                      // well status really
/*0x0160*/ EQZoneIndex                 zoneId;
/*0x0164*/ BYTE                        standstate;
/*0x0168*/ RaidData                    raidData;
/*0x0244*/ int                         ExpansionFlags;
/*0x0248*/ bool                        bSuperPKILL;
/*0x024a*/ bool                        bUnclone;
/*0x024b*/ bool                        bDead;
/*0x024C*/ int                         LD_Timer;
/*0x0250*/ int                         SpellInterruptCount;
/*0x0254*/ bool                        bAutoSplit;
/*0x0255*/ bool                        bTellsOff;
/*0x0256*/ bool                        bGmInvis;
/*0x0258*/ int                         KillMe;
/*0x025c*/ bool                        CheaterLdFlag;                // likely this is int SoulMarkCount instead.
/*0x025d*/ bool                        NoRent;
/*0x025e*/ bool                        Corpse;
/*0x025f*/ bool                        ClientGmFlagSet;
/*0x0260*/ int                         BankSharedPlat;               // 31e4 CharBaseBegin+488
/*0x0264*/ int                         BankSharedGold;               // CharBaseBegin+48c
/*0x0268*/ int                         BankSharedSilver;             // CharBaseBegin+490
/*0x026c*/ int                         BankSharedCopper;             // CharBaseBegin+494
/*0x0270*/ int                         BankPlat;                     // CharBaseBegin+498
/*0x0274*/ int                         BankGold;                     // CharBaseBegin+49c
/*0x0278*/ int                         BankSilver;                   // CharBaseBegin+4a0
/*0x027c*/ int                         BankCopper;                   // CharBaseBegin+4a4
/*0x0280*/ int                         STR;                          // CharBaseBegin+4a8
/*0x0284*/ int                         STA;                          // CharBaseBegin+4ac
/*0x0288*/ int                         CHA;                          // CharBaseBegin+4b0
/*0x028c*/ int                         DEX;                          // CharBaseBegin+4b4
/*0x0290*/ int                         INT;                          // CharBaseBegin+4b8
/*0x0294*/ int                         AGI;                          // CharBaseBegin+4bc
/*0x0298*/ int                         WIS;                          // CharBaseBegin+4c0
/*0x029c*/ int                         SavePoison;                   // CharBaseBegin+4c4
/*0x02a0*/ int                         SaveMagic;                    // CharBaseBegin+4c8
/*0x02a4*/ int                         SaveDisease;                  // CharBaseBegin+4cc
/*0x02a8*/ int                         SaveCorruption;               // CharBaseBegin+4d0
/*0x02ac*/ int                         SaveFire;                     // CharBaseBegin+4d4
/*0x02b0*/ int                         SaveCold;                     // CharBaseBegin+4d8
/*0x02b4*/ int                         SavePhysical;
/*0x02b8*/ int                         UncappedStr;
/*0x02bc*/ int                         UncappedSta;
/*0x02c0*/ int                         UncappedCha;
/*0x02c4*/ int                         UncappedDex;
/*0x02c8*/ int                         UncappedInt;
/*0x02cc*/ int                         UncappedAgi;
/*0x02d0*/ int                         UncappedWis;
/*0x02d4*/ int                         UncappedResistPoison;
/*0x02d8*/ int                         UncappedResistMagic;
/*0x02dc*/ int                         UncappedResistDisease;
/*0x02e0*/ int                         UncappedResistCorruption;
/*0x02e4*/ int                         UncappedResistFire;
/*0x02e8*/ int                         UncappedResistCold;
/*0x02ec*/ int                         NoBuffStr;
/*0x02f0*/ int                         NoBuffSta;
/*0x02f4*/ int                         NoBuffCha;
/*0x02f8*/ int                         NoBuffDex;
/*0x02fc*/ int                         NoBuffInt;
/*0x0300*/ int                         NoBuffAgi;
/*0x0304*/ int                         NoBuffWis;
/*0x0308*/ int                         NoBuffResistPoison;
/*0x030c*/ int                         NoBuffResistMagic;
/*0x0310*/ int                         NoBuffResistDisease;
/*0x0314*/ int                         NoBuffResistCorruption;
/*0x0318*/ int                         NoBuffResistFire;
/*0x031c*/ int                         NoBuffResistCold;
/*0x0320*/ int                         NoBuffResistPhysical;
/*0x0320*/ int                         NoBuffResistPhysical2;
/*0x0320*/ int                         NoBuffResistPhysical3;
/*0x0324*/

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

class CharacterZoneClient : virtual public CharacterBase
{
public:
	union {
/*0x2424*/ PlayerClient*               me;                 // just here for comparing the 2, todo: fix
/*0x2424*/ SPAWNINFO*                  me2;
	};
/*0x242c*/ bool                        bUpdateStuff;
/*0x242d*/ bool                        bZoningStatProcessing;
/*0x2430*/ DWORD                       ArmorClassBonus;              // vtable2+10
/*0x2434*/ DWORD                       CurrWeight;                   // vtable2+14
/*0x2438*/ int                         LastHitPointSendPercent;
/*0x243c*/ int                         LastManaPointSendPercent;
/*0x2440*/ int                         LastEndurancePointSendPercent;
/*0x2444*/ DWORD                       HPBonus;                      // vtable2+24
/*0x2448*/ DWORD                       ManaBonus;                    // vtable2+28
/*0x244c*/ DWORD                       EnduranceBonus;               // vtable2+2c
/*0x2450*/ BYTE                        Unknown0x2450[0x4];
/*0x2454*/ DWORD                       CombatEffectsBonus;           // vtable2+34 Combat Effects in UI
/*0x2458*/ DWORD                       ShieldingBonus;               // vtable2+38 Melee Shielding in UI
/*0x245c*/ DWORD                       SpellShieldBonus;             // vtable2+3c Spell Shielding in UI
/*0x2460*/ DWORD                       AvoidanceBonus;               // vtable2+40 Avoidance in UI
/*0x2464*/ DWORD                       AccuracyBonus;                // vtable2+44 Accuracy in UI
/*0x2468*/ DWORD                       StunResistBonus;              // vtable2+48 Stun Resist in UI
/*0x246c*/ DWORD                       StrikeThroughBonus;           // vtable2+4c Strike Through in UI
/*0x2470*/ DWORD                       DoTShieldBonus;               // vtable2+50 Dot Shielding in UI
/*0x2474*/ DWORD                       DamageShieldMitigationBonus;  // vtable2+54 Damage Shield Mitig in UI
/*0x2478*/ DWORD                       DamageShieldBonus;            // vtable2+58 Damage Shielding in UI
/*0x247c*/ TSafeArrayStatic<int, 9>    ItemSkillMinDamageMod;
/*0x24a0*/ TSafeArrayStatic<int, 9>    SkillMinDamageModBonus;
/*0x24c4*/ DWORD                       HeroicSTRBonus;               // vtable2+a4
/*0x24c8*/ DWORD                       HeroicINTBonus;               // vtable2+a8
/*0x24cc*/ DWORD                       HeroicWISBonus;               // vtable2+ac
/*0x24d0*/ DWORD                       HeroicAGIBonus;               // vtable2+b0
/*0x24d4*/ DWORD                       HeroicDEXBonus;               // vtable2+b4
/*0x24d8*/ DWORD                       HeroicSTABonus;               // vtable2+b8
/*0x24dc*/ DWORD                       HeroicCHABonus;               // vtable2+bc
/*0x24e0*/ DWORD                       HeroicSvMagicBonus;           // vtable2+c0
/*0x24e4*/ DWORD                       HeroicSvFireBonus;            // vtable2+c4
/*0x24e8*/ DWORD                       HeroicSvColdBonus;            // vtable2+c8
/*0x24ec*/ DWORD                       HeroicSvDiseaseBonus;         // vtable2+cc
/*0x24f0*/ DWORD                       HeroicSvPoisonBonus;          // vtable2+d0
/*0x24f4*/ DWORD                       HeroicSvCorruptionBonus;      // vtable2+d4
/*0x24f8*/ DWORD                       HealAmountBonus;              // vtable2+d8
/*0x24fc*/ DWORD                       SpellDamageBonus;             // vtable2+dc
/*0x2500*/ int                         ItemHealAmountDotMod;
/*0x2504*/ int                         ItemSpellDamageDotMod;
/*0x2508*/ DWORD                       ClairvoyanceBonus;            // vtable2+e8
/*0x250c*/ DWORD                       AttackBonus;                  // vtable2+ec
/*0x2510*/ DWORD                       HPRegenBonus;                 // vtable2+f0
/*0x2514*/ DWORD                       ManaRegenBonus;               // vtable2+f4
/*0x2518*/ DWORD                       EnduranceRegenBonus;          // vtable2+f8
/*0x251c*/ DWORD                       AttackSpeed;                  // vtable2+fc
/*0x2520*/ //int                         ItemPotionBelt;
/*0x2520*/ int                         NoBuffItemHitpointAdjustment;
/*0x2524*/ int                         NoBuffItemManaAdjustment;
/*0x2528*/ int                         NoBuffItemEnduranceAdjustment;
/*0x252c*/ int                         NoBuffItemBaseChanceProc;
/*0x2530*/ int                         NoBuffItemMinDamageMod;
/*0x2534*/ int                         NoBuffItemInnateSpellRune;
/*0x2538*/ int                         NoBuffItemAvoidance;
/*0x253c*/ int                         NoBuffItemToHit;
/*0x2540*/ int                         NoBuffItemResistStunChance;
/*0x2544*/ int                         NoBuffItemDotShieldingEffect;
/*0x2548*/ int                         NoBuffItemStrikeThroughChance;
/*0x254c*/ int                         NoBuffItemAttack;
/*0x2550*/ int                         NoBuffItemHitPointRegen;
/*0x2554*/ int                         NoBuffItemManaRegen;
/*0x2558*/ int                         NoBuffItemEnduranceRegen;
/*0x255c*/ int                         NoBuffItemDamageShield;
/*0x2560*/ int                         NoBuffItemDamageShieldMitigation;
/*0x2564*/ int                         NoBuffItemHaste;
/*0x256c*/ //int                         NoBuffItemPotionBelt;
/*0x2568*/ TSafeArrayStatic<int, 9>    NoBuffItemSkillMinDamageMod;  // size 0x24
/*0x258c*/ bool                        bOutputHpRegen;
/*0x258d*/ bool                        bInvulnerable;
/*0x258e*/ bool                        bOnAVehicle;
/*0x2590*/ SpellCache                  spellCache;                   // size 0x58
/*0x25e8*/ HashListSet<int, 0x80>      DoomEffectsBySlot;            // size 0x10 + (0x80* 4)
/*0x27f8*/ UINT                        LastHitEval;
/*0x27fc*/

	EQLIB_OBJECT CharacterZoneClient();
	EQLIB_OBJECT int CalcAffectChange(const EQ_Spell* spell, BYTE casterLevel, BYTE affextIndex, const EQ_Affect* theAffect, int EffectIndex = 0, PlayerZoneClient* pCaster = NULL, bool overrideChangeVal = false, int ChangeVal = -1, bool bCap = true);
	EQLIB_OBJECT int CalcAffectChangeGeneric(const EQ_Spell* spell, BYTE casterLevel, BYTE affextIndex, const EQ_Affect* theAffect, int EffectIndex, bool bCap = true);
	EQLIB_OBJECT void MakeMeVisible(int, bool);
	EQLIB_OBJECT int GetItemCountWorn(int);
	EQLIB_OBJECT int GetItemCountInInventory(int);
	EQLIB_OBJECT int GetCursorItemCount(int);
	EQLIB_OBJECT bool HasSkill(int);
	EQLIB_OBJECT EQ_Affect* FindAffectSlot(int SpellID, SPAWNINFO* Caster, int* slindex, bool bJustTest, int CasterLevel = -1, EQ_Affect* BuffArray = NULL, int BuffArraySize = 0, bool bFailAltAbilities = true);
	EQLIB_OBJECT EQ_Affect* FindAffectSlotMine(int SpellID, SPAWNINFO* Caster, int* slindex, bool bJustTest, int CasterLevel = -1, EQ_Affect* BuffArray = NULL, int BuffArraySize = 0, bool bFailAltAbilities = true);
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT bool IsStackBlocked(const EQ_Spell* pSpell, SPAWNINFO* pCaster, EQ_Affect* pEffecs = NULL, int EffectsSize = 0, bool bMessageOn = false);
#else
	EQLIB_OBJECT bool IsStackBlocked(const EQ_Spell* pSpell, SPAWNINFO* pCaster, EQ_Affect* pEffecs = NULL, int EffectsSize = 0);
#endif
	EQLIB_OBJECT int BardCastBard(const EQ_Spell* pSpell, signed int caster_class) const;
	EQLIB_OBJECT unsigned char GetMaxEffects() const;
	EQLIB_OBJECT EQ_Affect& GetEffect(int) const;
	EQLIB_OBJECT int GetOpenEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill, int Index = -1);
	EQLIB_OBJECT int GetFirstEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill);
	EQLIB_OBJECT int GetLastEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill, bool bIsDisplay = false);
	EQLIB_OBJECT const int GetFocusReuseMod(const EQ_Spell* pSpell, VePointer<CONTENTS>& pOutItem);
	EQLIB_OBJECT bool FindItemByGuid(const EqItemGuid& ItemGuid, int* pos_slot, int* con_slot);
	EQLIB_OBJECT BYTE FindItemByRecord(int ItemNumber, int* pos_slot, int* con_slot, bool bReverseLookup);
};



// work in progres
class PcBase : virtual public CharacterBase
{
public:
/*0x0008*/ // void*    vfTable_CharacterZoneClient;
/*0x0008*/ // void*    vfTable_CharacterBase;
/*0x000C*/ // void*    vfTable_PcBase;
//last one changed
/*0x000C*/ virtual void vftableph() {};

/*0x0010*/ TSafeArrayStatic<int, 0xa>            RecentTasks;
/*0x0038*/ TSafeArrayStatic<PCTaskStatus, 1>     Tasks;
/*0x00A8*/ TSafeArrayStatic<PCTaskStatus, 0x1d>  Quests;
/*0x0D58*/ TSafeArrayStatic<BYTE, 6400 / 8>      BitFlags;
/*0x1078*/ TSafeArrayStatic<BenefitSelection, 5> ActiveTributeBenefits;
/*0x10A0*/ TSafeArrayStatic<BenefitSelection, 10> ActiveTrophyTributeBenefits;
/*0x10f0*/ TSafeArrayStatic<BYTE, 0x320>         BitFlags2;
/*0x10f0*/ ItemBaseContainer                     BankItems;
/*0x110c*/ ItemBaseContainer                     SharedBankItems;
/*0x1128*/ ItemBaseContainer                     OverflowBufferItems;
/*0x1144*/ ItemBaseContainer                     LimboBufferItems;
/*0x1160*/ ItemBaseContainer                     MercenaryItems;
/*0x117c*/ ItemBaseContainer                     MountKeyRingItems;
/*0x1198*/ ItemBaseContainer                     IllusionKeyRingItems;
/*0x11b4*/ ItemBaseContainer                     FamiliarKeyRingItems;
/*0x11d0*/ ItemBaseContainer                     AltStorageItems;
/*0x11ec*/ ItemBaseContainer                     ArchivedDeletedItems;
/*0x1208*/ ItemBaseContainer                     MailItems;
/*0x1224*/ HashTable<MailItemData, EqItemGuid, ResizePolicyNoShrink> MailItemsData;
/*0x1234*/ TSafeArrayStatic<UINT, 1>             RecentMoves;
//fine to this point
/*0x1238*/ HashTable<DynamicZoneData>            CurrentDynamicZones;
/*0x1248*/ HashTable<int>                        LearnedRecipes;
/*0x1258*/ EQList<TradeskillRecipeCount*>        QualifyingRecipeCounts;
/*0x1268*/ HashTable<int>                        NonrepeatableQuests;
/*0x1278*/ HashTable<int>                        CompletedTasks;
/*0x1288*/ HashTable<int>                        CompletedTasks2;
/*0x1298*/ UINT                                  AlchemyTimestamp;
/*0x129c*/ bool                                  bWhat;
/*0x12a0*/ bool                                  bSomethingHome;
/*0x12a4*/ DWORD                                 LoginTime;
/*0x12a8*/ int64_t                               GuildID;                      // GuildID_0
/*0x12b0*/ int64_t                               FellowshipID;
/*0x12b8*/ FELLOWSHIPINFO*                       pFellowship;
/*0x12bc*/ int                                   GuildStatus;
/*0x12c0*/ int                                   GuildFlags;
/*0x12c4*/ bool                                  GuildShowSprite;
/*0x12c8*/ UINT                                  CreationTime;
/*0x12cc*/ UINT                                  AccountCreationTime;
/*0x12d0*/ UINT                                  LastPlayedTime;
/*0x12d4*/ DWORD                                 MinutesPlayed;
/*0x12d8*/ BYTE                                  Anonymous;
/*0x12d9*/ bool                                  bGM;
/*0x12da*/ bool                                  bGMStealth;
/*0x12dc*/ DWORD                                 AAExp;
/*0x12e0*/ BYTE                                  NobilityRank;
/*0x12e1*/ BYTE                                  PercentEXPtoAA;
/*0x12e4*/ int                                   AirSupply;
/*0x12e8*/ int                                   SerialNum;
/*0x12ec*/ bool                                  bNewCharacter;
/*0x12f0*/ int                                   TasksAssigned;
/*0x12f4*/ int                                   TasksCompleted;
/*0x12f8*/ long                                  TaskRequestTimer;
/*0x12fc*/ unsigned int                          UniquePlayerID;
/*0x1300*/ WorldLocation                         DynamicZoneSafeReturnLocation;
/*0x1314*/ DynamicZoneTimerData*                 pDZTimerRoot;
/*0x1318*/ DWORD                                 TributeTimer;
/*0x131c*/ DWORD                                 BenefitTimer;
/*0x1320*/ int64_t                               CareerFavor;
/*0x1328*/ int64_t                               CurrFavor;
/*0x1330*/ bool                                  bBenefitsActive;
/*0x1331*/ bool                                  bTrophyBenefitsActive;
/*0x1332*/ bool                                  bHasResetStartingCity;
/*0x1333*/ bool                                  bIsHeadStartCharacter;
/*0x1334*/ int                                   PvPKills;
/*0x1338*/ int                                   PvPDeaths;
/*0x133c*/ int                                   PvPCurrentPoints;
/*0x1340*/ int                                   PvPTotalPointsEarned;
/*0x1344*/ int                                   PvPKillStreak;
/*0x1348*/ int                                   PvPDeathStreak;
/*0x134c*/ int                                   PvPCurrentStreak;
/*0x1350*/ PvPKill                               LastKill;
/*0x13a8*/ PvPDeath                              LastDeath;
/*0x1400*/ HashTable<PvPKill24HourData>          PvPLast24HoursKillHash;
/*0x1410*/ int                                   PvPInfamyLevel;
/*0x1414*/ int                                   PvPVitality;
/*0x1418*/ UINT                                  PvPLastInfamyTime;
/*0x141c*/ int                                   LastLastNameChange;
/*0x1420*/ int                                   LastNameChangePriv;
/*0x1424*/ UINT                                  PvPLastVitalityTime;
/*0x1428*/ bool                                  bKeepItemsOnDeath;
/*0x1429*/ bool                                  bResetSpecializationSkills;
/*0x142c*/ int                                   CharityPointsAvailable;
/*0x1430*/ int                                   CharityTotalPointsEarned;
/*0x1434*/ int                                   GoodPointsAvailable;
/*0x1438*/ int                                   GoodTotalPointsEarned;
/*0x143c*/ int                                   EvilPointsAvailable;
/*0x1440*/ int                                   EvilTotalPointsEarned;
/*0x1444*/ bool                                  bCanRequestNameChange;
/*0x1445*/ bool                                  bCanRequestNameChange2;
/*0x1446*/ bool                                  bCanRequestServerTransfer;
/*0x1447*/ bool                                  bIsCopied;
/*0x1448*/ int                                   ServerTransferGrantTime;
/*0x144c*/ bool                                  bCanRequestRaceChange;
/*0x1450*/ UINT                                  LastAAResetTime;
/*0x1454*/ UINT                                  LastMercAAResetTime;
/*0x1458*/ EQZoneIndex                           NewZoneID;
/*0x145c*/ int                                   NewAreaID;
/*0x1460*/ EAreaCorner                           eNewAreaCorner;
/*0x1464*/ EQZoneIndex                           PreviousZoneID;
/*0x1468*/ int                                   RealEstateZoneID;
/*0x146c*/ char                                  ServerCreated[0x20];
/*0x1470*/ PCAdventureData                       AdventureData;
/*0x14xx*/ PCSharedTaskData                      SharedTaskData;
/*0x14xx*/ TaskTimerData*                        pTaskTimerData;
/*0x14xx*/ PCQuestHistoryData                    QuestHistoryData;
/*0x14xx*/ PCStatistics                          PcStatistics;
/*0x1954*/ GroupMemberStats                      GroupStats;
/*0x1aa4*/ bool                                  bIsLfg;
/*0x1aa8*/ int64_t                               RaidId;
/*0x1ab0*/ int64_t                               GroupID;
/*0x1ab8*/ int64_t                               Exp;
/*0x1ac0*/ int                                   DaysEntitled;
/*0x1ac4*/ int                                   SpentVeteranRewards;
/*0x1ac8*/ bool                                  bVeteranRewardEntitled;
/*0x1ac9*/ bool                                  bAutoConsentGroup;
/*0x1aca*/ bool                                  bAutoConsentRaid;
/*0x1acb*/ bool                                  bAutoConsentGuild;
/*0x1acc*/ bool                                  bPrivateForEqPlayers;
/*0x1ad0*/ long                                  AchievementFilesModificationTime;
/*0x1ad4*/ char                                  StationID[0x20];
/*0x1af8*/ EqGuid                                Guid;
/*0x1b00*/ bool                                  bBetaBuffed;
/*0x1b04*/ int                                   Unknown0x1ad4;
/*0x1b08*/ int                                   StartingCity;
/*0x1b0c*/ int                                   MainLevel;
/*0x1b10*/ bool                                  bShowHelm;
/*0x1b18*/ int64_t                               LastTestCopyTime;
/*0x1b20*/ CPlayerPointManager                   PointManager;
/*0x1b34*/ PointSystemBase                       PointSystem;
/*0x1B48*/ UINT                                  LoyaltyVelocity;
/*0x1B4c*/ UINT                                  LoyaltyTokens;
/*0x1B50*/ bool                                  bHasLoyaltyInfo;
/*0x1B54*/ ArrayClass_RO<int>                    OwnedRealEstates;
/*0x1B64*/ ArrayClass_RO<int>                    OwnedItemRealEstates;
/*0x1B74*/ ArrayClass_RO<int>                    ArchivedRealEstates;
/*0x1B84*/ char                                  OverridePetName[0x40];
/*0x1Bc4*/ bool                                  bCanRequestPetNameChange;
/*0x1Bc5*/ char                                  OverrideFamiliarName[0x40];
/*0x1c05*/ bool                                  bCanRequestFamiliarNameChange;
/*0x1c08*/ CXStr                                 OverrideMercName[0xb];
/*0x1c34*/ bool                                  bCanRequestMercNameChange;
/*0x1c38*/ PendingRewardList                     PendingRewards;
/*0x1c64*/ UINT                                  DowntimeReductionTime;
/*0x1c68*/ UINT                                  DowntimeTimerStart;
/*0x1c6c*/ float                                 ActivityValue;
/*0x1c70*/ UINT                                  NextItemId;
/*0x1c74*/ CXStr                                 SharedBank;
/*0x1c78*/ CXStr                                 BankBuffer;
/*0x1c7c*/ CXStr                                 OverflowBuffer;
/*0x1c80*/ CXStr                                 LimboBuffer;
/*0x1c84*/ CXStr                                 MercenaryBuffer;
/*0x1c88*/ CXStr                                 KeyRingBuffer[3];
/*0x1c94*/ CXStr                                 AltStorageBuffer;
/*0x1c98*/ UINT                                  AltStorageTimestamp;
/*0x1c9c*/ ELockoutCharacterReason               LCR;
/*0x1ca0*/ HashTable<ProgressionExperience>      ProgressionExp;
/*0x1cb0*/ CXStr                                 ArchivedStorageBuffer;
/*0x1cb4*/ CXStr                                 MailItemsBuffer;
/*0x1cb8*/ CXStr                                 MailItemsDataBuffer;
/*0x1cbc*/ int                                   MailItemsOverCapWarningCount;
/*0x1cc0*/ ItemIndex                             StatKeyRingItemIndex[3];
/*0x1cd2*/ bool                                  UseAdvancedLooting;
/*0x1cd3*/ bool                                  MasterLootCandidate;
/*0x1cd4*/ bool                                  bIsCorrupted;
/*0x1cd8*/ char*                                 pCorruptionReport;
/*0x1cdc*/ TString<0x100>                        InspectText;
/*0x1ddc*/ HashTable<int>                        BlockedSpellsHash;
/*0x1dec*/ int                                   BlockedSpell[0x28];
/*0x1e8c*/ HashTable<int>                        BlockedPetSpellsHash;
/*0x1e9c*/ int                                   BlockedPetSpell[0x28];
/*0x1f3c*/ ClaimDataCollection                   ConsumableFeatures;
/*0x1f4c*/ bool                                  bGrantItemsRegistered;
/*0x1f50*/ uint64_t                              CreatedGuildID;
/*0x1f58*/ UINT                                  GuildCreateTime;
/*0x1f5c*/ CXStr                                 GuildCreateCharacter;
/*0x1f60*/ bool                                  bInventoryUnserialized;
/*0x1f61*/ bool                                  bAltStorageUnserialized;
/*0x1f62*/ bool                                  bArchivedStorageUnserialized;
/*0x1f63*/ bool                                  bMailUnserialized;
/*0x1f64*/ bool                                  bPendingInventorySerialization;
/*0x1f68*/ CXStr                                 BuyLines;
/*0x1f6c*/ ArrayClass_RO<CXStr>                  OfflineTraderSoldItems;
/*0x1f7c*/ ArrayClass_RO<CXStr>                  OfflineBuyerBoughtItems;
/*0x1f8c*/ UINT                                  Krono;
/*0x1f90*/ UINT                                  CursorKrono;
/*0x1f98*/ int64_t                               MercAAExp;                    // divide this with 3.30f and you get the percent
/*0x1fa0*/ DWORD                                 MercAAPoints;                 // number of unspent merc AA points
/*0x1fa4*/ DWORD                                 MercAAPointsSpent;            // number of spent merc AA points
/*0x1fa8*/ ArrayClass_RO<MercenaryAbilityInfo*>  MercenaryAbilities;
/*0x1fb8*/ HashTable<CompletedAchievementData, int, ResizePolicyNoShrink>         CompletedAchievements;
/*0x1fc8*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> CompletedEventBasedSubComponents;
/*0x1fd8*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> OpenEventBasedSubComponents;
/*0x1fe8*/ int                                   LastFellowshipJoin;
/*0x1ff0*/ int64_t                               Vitality;
/*0x1ff8*/ int                                   AAVitality;
/*0x1ffc*/ int                                   Unknown0x1ffc;
/*0x2000*/ int                                   FPStuff[0x1c];
/*0x2070*/ //CharacterZoneClient
};

class DebugText
{
public:
	EQLIB_OBJECT virtual void SendDebugText(const char* text, int color);
};

class PcZoneClient : public PcBase, public CharacterZoneClient, public DebugText
{
public:
/*0x245c*/ void*       vfTable_PcZoneClient;
/*0x2460*/ TSafeArrayStatic<unsigned long, 3> Flags;
/*0x246C*/ uint32_t    TransfersReceived;
/*0x2470*/ int         LastLanguageSpoken;
/*0x2474*/ int         CurPowerSourceDrain;
/*0x2478*/ EQList<ALCHEMYBONUSSKILLDATA*> AlchemyBaseSkillBonusList;
/*0x2488*/ UINT        MomentumBalance;
/*0x248C*/ UINT        LoyaltyRewardBalance;
/*0x2490*/

	EQLIB_OBJECT int GetPcSkillLimit(int);
	EQLIB_OBJECT bool HasCombatAbility(int);
	EQLIB_OBJECT void RemovePetEffect(int);
	EQLIB_OBJECT bool CanEquipItem(CONTENTS** pCont, int slotid, bool bOutputDebug, bool bUseRequiredLevel);
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT bool HasAlternateAbility(int aaindex, int*, bool, bool);
#else
	EQLIB_OBJECT bool HasAlternateAbility(int aaindex, int*, bool);
#endif
	EQLIB_OBJECT int GetCurrentMod(int index);
#if !defined(ROF2EMU) && !defined(UFEMU)
	int GetModCap(int index, bool bToggle = false);
#else
	EQLIB_OBJECT int GetModCap(int index);
#endif
	EQLIB_OBJECT void RemoveBuffEffect(int Index, int SpawnID);
	EQLIB_OBJECT CONTENTS** GetItemByID(CONTENTS** contOut, int itemid, ItemIndex* itemindex = nullptr);
	EQLIB_OBJECT CONTENTS** GetItemByItemClass(CONTENTS** contOut, int itemclass, ItemIndex* itemindex = nullptr);
	EQLIB_OBJECT void BandolierSwap(int index);
	EQLIB_OBJECT UINT GetLinkedSpellReuseTimer(int index);
};

class PcClient : public PcZoneClient
{
	// has a vftable but we get it from PcZoneClient
public:
	EQLIB_OBJECT PcClient();

	BYTE Filler[0x2b10];
};

} // namespace

using namespace eqlib;