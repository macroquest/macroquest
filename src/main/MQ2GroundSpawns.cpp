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

#include "pch.h"
#include "MQ2Main.h"

namespace mq {

static void SetGameStateGroundSpawns(DWORD);

static MQModule s_GroundSpawnsModule = {
	"GroundSpawns",                // Name
	false,                         // CanUnload
	nullptr,                       // Initialize
	nullptr,                       // Shutdown
	nullptr,                       // Pulse
	SetGameStateGroundSpawns       // SetGameState
};
MQModule* GetGroundSpawnsModule() { return &s_GroundSpawnsModule; }

class GroundSpawnSearch
{
private:
	// make this private because _all access_ to ground spawns should be through the list
	std::vector<MQ2GroundSpawn> m_searchResults;
	std::vector<MQ2GroundSpawn>::iterator m_currentResult;
	bool m_valid;

	GroundSpawnSearch() : m_searchResults(), m_currentResult(m_searchResults.end()), m_valid(false) {}

public:
	GroundSpawnSearch(const GroundSpawnSearch&) = delete;
	GroundSpawnSearch& operator=(const GroundSpawnSearch&) = delete;

	static GroundSpawnSearch& Instance()
	{
		static GroundSpawnSearch instance;
		return instance;
	}

	static void Reset()
	{
		Instance().m_searchResults.clear();
		Instance().m_currentResult = Instance().m_searchResults.end();
		Instance().m_valid = false;
	}

	static GroundSpawnSearch& Search(SPAWNINFO* pSpawn)
	{
		if (!Instance().m_valid)
		{
			Instance().Filter(pSpawn);
			Instance().Sort(pSpawn);
		}

		return Instance();
	}

	static GroundSpawnSearch& Search(SPAWNINFO* pSpawn, std::string_view Name)
	{
		if (!Instance().m_valid)
		{
			Instance().Filter(pSpawn, Name);
			Instance().Sort(pSpawn);
		}

		return Instance();
	}

	static GroundSpawnSearch& Search(SPAWNINFO* pSpawn, int ID)
	{
		if (!Instance().m_valid)
		{
			Instance().Filter(pSpawn, ID);
			Instance().Sort(pSpawn);
		}

		return Instance();
	}

	template <typename GroundPred, typename PlacedPred>
	void Filter(SPAWNINFO* pSpawn, GroundPred GroundPredicate, PlacedPred PlacedPredicate)
	{
		m_searchResults.clear();

		if (pItemList)
		{
			for (auto pGround = pItemList->Top; pGround; pGround = pGround->pNext)
			{
				// z filters are universal
				if (gZFilter < 10000.f && (pGround->Z > pSpawn->Z + gZFilter || pGround->Z < pSpawn->Z - gZFilter))
					continue;

				if (GroundPredicate(pGround))
					m_searchResults.emplace_back(pGround);
			}
		}

		const auto& placed_item_mgr = EQPlacedItemManager::Instance();
		for (auto pPlaced = placed_item_mgr.Top; pPlaced; pPlaced = pPlaced->pNext)
		{
			if (gZFilter < 10000.f && (pPlaced->Z > pSpawn->Z + gZFilter || pPlaced->Z < pSpawn->Z - gZFilter))
				continue;

			if (PlacedPredicate(pPlaced))
				m_searchResults.emplace_back(pPlaced);
		}

		m_currentResult = m_searchResults.begin();
		m_valid = true;
	}

	void Filter(SPAWNINFO* pSpawn, int ID)
	{
		Filter(pSpawn,
			[&ID](EQGroundItem* ground)
			{
				return ground->DropID == ID;
			},
			[&ID](EQPlacedItem* placed)
			{
				return placed->RealEstateItemID == ID;
			});
	}

	void Filter(SPAWNINFO* pSpawn, std::string_view Name)
	{
		if (Name.empty())
		{
			Filter(pSpawn);
		}
		else
		{
			Filter(pSpawn,
				[&Name](EQGroundItem* ground)
				{
					return ci_find_substr(GetFriendlyNameForGroundItem(ground), Name) >= 0;
				},
				[&Name](EQPlacedItem* placed)
				{
					return ci_find_substr(GetFriendlyNameForPlacedItem(placed), Name) >= 0;
				});
		}
	}

	void Filter(SPAWNINFO* pSpawn)
	{
		Filter(pSpawn, [](EQGroundItem*) { return true; }, [](EQPlacedItem*) { return true; });
	}

	void Sort(SPAWNINFO* pSpawn)
	{
		DistanceSort(pSpawn, m_searchResults,
			[](SPAWNINFO* pSpawn, const MQ2GroundSpawn& ground)
			{
				if (ground)
				{
					if (ground.Type == MQ2GroundSpawnType::Ground)
					{
						auto& pGround = *std::get<EQGroundItemPtr>(ground.Object);
						if (pGround)
							return Get3DDistanceSquared(pSpawn->X, pSpawn->Y, pSpawn->Z, pGround->X, pGround->Y, pGround->pSwitch->Z);
					}
					else if (ground.Type == MQ2GroundSpawnType::Placed)
					{
						auto& pPlaced = *std::get<EQPlacedItemPtr>(ground.Object);
						if (pPlaced)
							return Get3DDistanceSquared(pSpawn->X, pSpawn->Y, pSpawn->Z, pPlaced->X, pPlaced->Y, pPlaced->Z);
					}
				}

				// if the object isn't valid or is nullptr, then stick them at the end of the list
				return std::numeric_limits<float>::max();
			});

		m_currentResult = m_searchResults.begin();
	}

	bool Empty() const { return m_searchResults.empty(); }

	MQ2GroundSpawn Current()
	{
		if (m_currentResult != m_searchResults.end())
			return *m_currentResult;

		return MQ2GroundSpawn();
	}

	MQ2GroundSpawn First()
	{
		// begin == end for an empty vector by definition
		m_currentResult = m_searchResults.begin();
		return Current();
	}

	MQ2GroundSpawn Last()
	{
		if (m_searchResults.empty())
			return MQ2GroundSpawn();

		m_currentResult = std::prev(m_searchResults.end());
		return Current();
	}

	MQ2GroundSpawn Next()
	{
		if (m_currentResult == m_searchResults.end())
			return MQ2GroundSpawn();

		++m_currentResult;
		return Current();
	}

	MQ2GroundSpawn Prev()
	{
		if (m_currentResult == m_searchResults.begin())
			return MQ2GroundSpawn();

		--m_currentResult;
		return Current();
	}

	MQ2GroundSpawn At(size_t Idx)
	{
		if (Idx >= m_searchResults.size())
			return MQ2GroundSpawn();

		return m_searchResults.at(Idx);
	}

	int Count()
	{
		return m_searchResults.size();
	}
};

static void SetGameStateGroundSpawns(DWORD)
{
	GroundSpawnSearch::Reset();
}

MQ2GroundSpawn GetGroundSpawnByName(std::string_view Name)
{
	GroundSpawnSearch::Reset();
	return GroundSpawnSearch::Search(pCharSpawn, Name).First();
}

MQ2GroundSpawn GetGroundSpawnByID(int ID)
{
	GroundSpawnSearch::Reset();
	return GroundSpawnSearch::Search(pCharSpawn, ID).First();
}

MQ2GroundSpawn GetNearestGroundSpawn()
{
	GroundSpawnSearch::Reset();
	return GroundSpawnSearch::Search(pCharSpawn).First();
}

MQ2GroundSpawn GetNthGroundSpawnFromMe(size_t N)
{
	return GroundSpawnSearch::Search(pCharSpawn).At(N);
}

int GetGroundSpawnCount()
{
	return GroundSpawnSearch::Search(pCharSpawn).Count();
}

MQ2GroundSpawn CurrentGroundSpawn()
{
	return GroundSpawnSearch::Search(pCharSpawn).Current();
}

MQ2GroundSpawn FirstGroundSpawn()
{
	return GroundSpawnSearch::Search(pCharSpawn).First();
}

MQ2GroundSpawn LastGroundSpawn()
{
	return GroundSpawnSearch::Search(pCharSpawn).Last();
}

MQ2GroundSpawn NextGroundSpawn()
{
	return GroundSpawnSearch::Search(pCharSpawn).Next();
}

MQ2GroundSpawn PrevGroundSpawn()
{
	return GroundSpawnSearch::Search(pCharSpawn).Prev();
}

CActorInterface* MQ2GroundSpawn::Actor() const
{
	if (Type == MQ2GroundSpawnType::Ground)
	{
		auto ground = Get<EQGroundItem>();
		if (ground)
			return reinterpret_cast<CActorInterface*>(ground->pSwitch);
	}
	else if (Type == MQ2GroundSpawnType::Placed)
	{
		auto placed = Get<EQPlacedItem>();
		if (placed)
			return placed->pActor;
	}

	return nullptr;
}

CXStr MQ2GroundSpawn::Name() const
{
	if (Type == MQ2GroundSpawnType::Ground)
	{
		auto ground = Get<EQGroundItem>();
		if (ground)
			return ground->Name;
	}
	else if (Type == MQ2GroundSpawnType::Placed)
	{
		auto placed = Get<EQPlacedItem>();
		if (placed)
			return placed->Name;
	}

	return CXStr();
}

CXStr MQ2GroundSpawn::DisplayName() const
{
	if (Type == MQ2GroundSpawnType::Ground)
	{
		auto ground = Get<EQGroundItem>();
		if (ground)
			return GetFriendlyNameForGroundItem(ground);
	}
	else if (Type == MQ2GroundSpawnType::Placed)
	{
		auto placed = Get<EQPlacedItem>();
		if (placed)
			return GetFriendlyNameForPlacedItem(placed);
	}

	return CXStr();
}

CVector3 MQ2GroundSpawn::Position() const
{
	if (Type == MQ2GroundSpawnType::Ground)
	{
		auto ground = Get<EQGroundItem>();
		if (ground)
			return CVector3(ground->X, ground->Y, ground->pSwitch ? ground->pSwitch->Z : ground->Z);
	}
	else if (Type == MQ2GroundSpawnType::Placed)
	{
		auto placed = Get<EQPlacedItem>();
		if (placed)
			return CVector3(placed->X, placed->Y, placed->Z);
	}

	return CVector3(
		std::numeric_limits<float>::max(),
		std::numeric_limits<float>::max(),
		std::numeric_limits<float>::max()
		);
}

void SetGroundSpawn(SPAWNINFO* pSpawn, std::string_view Name)
{
	GroundSpawnSearch::Reset();
	GroundSpawnSearch::Search(pSpawn, Name);
}

void ClearGroundSpawn()
{
	GroundSpawnSearch::Reset();
}

CXStr GetFriendlyNameForGroundItem(EQGroundItem* pItem)
{
	if (!pItem)
		return CXStr();

	int item_def = GetIntFromString(&pItem->Name[2], 0);
	for (auto actor = ActorDefList; actor->Def; ++actor)
	{
		if (actor->Def == item_def && (actor->ZoneID < 0 || actor->ZoneID == (pItem->ZoneID & 0x7FFF)))
			return actor->Name;
	}

	// didn't find an actor def, so construct a name
	return CXStr(fmt::format("Drop{:05d}/{:d}", item_def, pItem->DropID));
}

CXStr GetFriendlyNameForPlacedItem(EQPlacedItem* pItem)
{
	if (!pItem)
		return CXStr();

	const auto& real_estate = RealEstateManagerClient::Instance();
	auto pRealEstateItem = real_estate.GetItemByRealEstateAndItemIds(pItem->RealEstateID, pItem->RealEstateItemID);
	if (pRealEstateItem && pRealEstateItem->Object.pItemBase)
	{
		auto placed = pRealEstateItem->Object.pItemBase->GetItemDefinition();
		if (placed)
			return placed->Name;
	}

	if (pItem->Name[0] != '\0')
		return pItem->Name;

	// didn't find a real estate item, so construct a name
	return CXStr(fmt::format("Placed{:05d}/{:d}", pItem->RealEstateID, pItem->RealEstateItemID));
}

char* GetFriendlyNameForGroundItem(PGROUNDITEM pItem, char* szName, size_t BufferSize)
{
	strcpy_s(szName, BufferSize, GetFriendlyNameForGroundItem(pItem).c_str());
	return szName;
}

float MQ2GroundSpawn::Distance(SPAWNINFO* pSpawn) const
{
	if (Type == MQ2GroundSpawnType::Ground)
	{
		auto ground = Get<EQGroundItem>();
		if (ground)
			return DistanceToPoint(pSpawn, ground->X, ground->Y);
	}
	else if (Type == MQ2GroundSpawnType::Placed)
	{
		auto placed = Get<EQPlacedItem>();
		if (placed)
			return DistanceToPoint(pSpawn, placed->X, placed->Y);
	}

	return std::numeric_limits<float>::max();
}

float MQ2GroundSpawn::Distance3D(SPAWNINFO* pSpawn) const
{
	if (Type == MQ2GroundSpawnType::Ground)
	{
		auto ground = Get<EQGroundItem>();
		if (ground)
			return Distance3DToPoint(pSpawn, ground->X, ground->Y, ground->pSwitch ? ground->pSwitch->Z : ground->Z);
	}
	else if (Type == MQ2GroundSpawnType::Placed)
	{
		auto placed = Get<EQPlacedItem>();
		if (placed)
			return Distance3DToPoint(pSpawn, placed->X, placed->Y, placed->Z);
	}

	return std::numeric_limits<float>::max();
}

int MQ2GroundSpawn::ID() const
{
	if (Type == MQ2GroundSpawnType::Ground)
	{
		auto ground = Get<EQGroundItem>();
		if (ground)
			return ground->DropID;
	}
	else if (Type == MQ2GroundSpawnType::Placed)
	{
		auto placed = Get<EQPlacedItem>();
		if (placed)
			return placed->RealEstateItemID;
	}

	return -1;
}

int MQ2GroundSpawn::SubID() const
{
	if (Type == MQ2GroundSpawnType::Ground)
	{
		auto ground = Get<EQGroundItem>();
		if (ground)
			return ground->DropSubID;
	}
	else if (Type == MQ2GroundSpawnType::Placed)
	{
		auto placed = Get<EQPlacedItem>();
		if (placed)
			return placed->RealEstateID;
	}

	return -1;
}

int MQ2GroundSpawn::ZoneID() const
{
	if (Type == MQ2GroundSpawnType::Ground)
	{
		auto ground = Get<EQGroundItem>();
		if (ground)
			return ground->ZoneID & 0x7FFF;
	}
	else if (Type == MQ2GroundSpawnType::Placed)
	{
		return pLocalPlayer->GetZoneID() & 0x7FFF;
	}

	return -1;
}

float MQ2GroundSpawn::Heading() const
{
	if (Type == MQ2GroundSpawnType::Ground)
	{
		auto ground = Get<EQGroundItem>();
		if (ground)
			return ground->Heading * 0.703125f;
	}
	else if (Type == MQ2GroundSpawnType::Placed)
	{
		auto placed = Get<EQPlacedItem>();
		if (placed)
			return placed->Heading * 0.703125f;
	}

	return std::numeric_limits<float>::max();
}

SPAWNINFO MQ2GroundSpawn::ToSpawn() const
{
	SPAWNINFO ret;

	strcpy_s(ret.Name, Name().c_str());
	strcpy_s(ret.DisplayedName, DisplayName().c_str());

	auto pos = Position();
	ret.Y = pos.Y;
	ret.X = pos.X;
	ret.Z = pos.Z;
	ret.Type = SPAWN_NPC;
	ret.HPCurrent = 1;
	ret.HPMax = 1;
	ret.Heading = Heading();
	ret.mActorClient.Race = ID();

	return ret;
}

template <> EQGroundItem* MQ2GroundSpawn::Get<EQGroundItem>() const
{
	if (Type == MQ2GroundSpawnType::Ground)
	{
		auto ptr = *std::get<EQGroundItemPtr>(Object);
		if (ptr)
			return ptr.Ptr();
	}

	return nullptr;
}

template <> EQPlacedItem* MQ2GroundSpawn::Get<EQPlacedItem>() const
{
	if (Type == MQ2GroundSpawnType::Placed)
	{
		auto ptr = *std::get<EQPlacedItemPtr>(Object);
		if (ptr)
			return ptr.Ptr();
	}

	return nullptr;
}
}
