/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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

static void SetGameStateGroundSpawns(int);

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
	std::vector<MQGroundSpawn> m_searchResults;
	std::vector<MQGroundSpawn>::iterator m_currentResult;
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

	static bool IsValid()
	{
		return Instance().m_valid;
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

	static GroundSpawnSearch& Search(SPAWNINFO* pSpawn, const MQGroundSpawn& groundSpawn)
	{
		if (!Instance().m_valid)
		{
			Instance().Filter(pSpawn, groundSpawn);
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

	void Filter(SPAWNINFO* pSpawn, const MQGroundSpawn& groundSpawn)
	{
		Filter(pSpawn,
			[&groundSpawn](EQGroundItem* ground)
			{
				return ground == groundSpawn;
			},
			[&groundSpawn](EQPlacedItem* placed)
			{
				return placed == groundSpawn;
			});
	}

	void Filter(SPAWNINFO* pSpawn)
	{
		Filter(pSpawn, [](EQGroundItem*) { return true; }, [](EQPlacedItem*) { return true; });
	}

	void Sort(SPAWNINFO* pSpawn)
	{
		DistanceSort(pSpawn, m_searchResults,
			[](SPAWNINFO* pSpawn, const MQGroundSpawn& ground)
			{
				if (ground)
				{
					if (ground.Type == MQGroundSpawnType::Ground)
					{
						auto& pGround = *std::get<EQGroundItemPtr>(ground.Object);
						if (pGround)
							return Get3DDistanceSquared(pSpawn->X, pSpawn->Y, pSpawn->Z, pGround->X, pGround->Y, pGround->pActor->GetPosition().Z); // why pActor?
					}
					else if (ground.Type == MQGroundSpawnType::Placed)
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

	MQGroundSpawn Current()
	{
		if (m_currentResult != m_searchResults.end())
			return *m_currentResult;

		return MQGroundSpawn();
	}

	MQGroundSpawn First()
	{
		// begin == end for an empty vector by definition
		m_currentResult = m_searchResults.begin();
		return Current();
	}

	MQGroundSpawn Last()
	{
		if (m_searchResults.empty())
			return MQGroundSpawn();

		m_currentResult = std::prev(m_searchResults.end());
		return Current();
	}

	MQGroundSpawn Next()
	{
		if (m_searchResults.empty() || m_currentResult == std::prev(m_searchResults.end()))
			return MQGroundSpawn();

		++m_currentResult;
		return Current();
	}

	MQGroundSpawn Prev()
	{
		// begin == end for an empty vector by definition
		if (m_currentResult == m_searchResults.begin())
			return MQGroundSpawn();

		--m_currentResult;
		return Current();
	}

	MQGroundSpawn At(size_t Idx)
	{
		if (Idx >= m_searchResults.size())
			return MQGroundSpawn();

		return m_searchResults.at(Idx);
	}

	int Count()
	{
		return static_cast<int>(m_searchResults.size());
	}
};

static void SetGameStateGroundSpawns(int)
{
	GroundSpawnSearch::Reset();
}

MQGroundSpawn GetGroundSpawnByName(std::string_view Name)
{
	GroundSpawnSearch::Reset();
	return GroundSpawnSearch::Search(pControlledPlayer, Name).First();
}

MQGroundSpawn GetGroundSpawnByID(int ID)
{
	GroundSpawnSearch::Reset();
	return GroundSpawnSearch::Search(pControlledPlayer, ID).First();
}

MQGroundSpawn GetNearestGroundSpawn()
{
	GroundSpawnSearch::Reset();
	return GroundSpawnSearch::Search(pControlledPlayer).First();
}

MQGroundSpawn GetNthGroundSpawnFromMe(size_t N)
{
	return GroundSpawnSearch::Search(pControlledPlayer).At(N);
}

int GetGroundSpawnCount()
{
	GroundSpawnSearch::Reset();
	return GroundSpawnSearch::Search(pControlledPlayer).Count();
}

int GetGroundSpawnCountByName(std::string_view Name)
{
	GroundSpawnSearch::Reset();
	return GroundSpawnSearch::Search(pControlledPlayer, Name).Count();
}

MQGroundSpawn CurrentGroundSpawn()
{
	return GroundSpawnSearch::Search(pControlledPlayer).Current();
}

MQGroundSpawn FirstGroundSpawn()
{
	return GroundSpawnSearch::Search(pControlledPlayer).First();
}

MQGroundSpawn LastGroundSpawn()
{
	return GroundSpawnSearch::Search(pControlledPlayer).Last();
}

MQGroundSpawn NextGroundSpawn()
{
	if (GroundSpawnSearch::IsValid())
		return GroundSpawnSearch::Search(pControlledPlayer).Next();

	return FirstGroundSpawn();
}

MQGroundSpawn PrevGroundSpawn()
{
	if (GroundSpawnSearch::IsValid())
		return GroundSpawnSearch::Search(pControlledPlayer).Prev();

	return LastGroundSpawn();
}

CActorInterface* MQGroundSpawn::Actor() const
{
	if (Type == MQGroundSpawnType::Ground)
	{
		auto ground = Get<EQGroundItem>();
		if (ground)
			return ground->pActor;
	}
	else if (Type == MQGroundSpawnType::Placed)
	{
		auto placed = Get<EQPlacedItem>();
		if (placed)
			return placed->pActor;
	}

	return nullptr;
}

CXStr MQGroundSpawn::Name() const
{
	if (Type == MQGroundSpawnType::Ground)
	{
		auto ground = Get<EQGroundItem>();
		if (ground)
			return ground->Name;
	}
	else if (Type == MQGroundSpawnType::Placed)
	{
		auto placed = Get<EQPlacedItem>();
		if (placed)
			return placed->Name;
	}

	return CXStr();
}

CXStr MQGroundSpawn::DisplayName() const
{
	if (Type == MQGroundSpawnType::Ground)
	{
		auto ground = Get<EQGroundItem>();
		if (ground)
			return GetFriendlyNameForGroundItem(ground);
	}
	else if (Type == MQGroundSpawnType::Placed)
	{
		auto placed = Get<EQPlacedItem>();
		if (placed)
			return GetFriendlyNameForPlacedItem(placed);
	}

	return CXStr();
}

CVector3 MQGroundSpawn::Position() const
{
	if (Type == MQGroundSpawnType::Ground)
	{
		auto ground = Get<EQGroundItem>();
		if (ground)
			return CVector3(ground->X, ground->Y, ground->pActor ? ground->pActor->GetPosition().Z : ground->Z); // Why pActor??
	}
	else if (Type == MQGroundSpawnType::Placed)
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

void SetGroundSpawn(std::string_view Name)
{
	GroundSpawnSearch::Reset();
	GroundSpawnSearch::Search(pControlledPlayer, Name);
}

void SetGroundSpawn(const MQGroundSpawn& groundSpawn)
{
	GroundSpawnSearch::Reset();
	GroundSpawnSearch::Search(pControlledPlayer, groundSpawn);
}

void ClearGroundSpawn()
{
	GroundSpawnSearch::Reset();
}

bool HasCurrentGroundSpawn()
{
	return GroundSpawnSearch::IsValid();
}

CXStr GetFriendlyNameForGroundItem(const EQGroundItem* pItem)
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

CXStr GetFriendlyNameForPlacedItem(const EQPlacedItem* pItem)
{
	if (!pItem)
		return CXStr();

	const RealEstateManagerClient& real_estate = RealEstateManagerClient::Instance();
	auto pRealEstateItem = real_estate.GetItemByRealEstateAndItemIds(pItem->RealEstateID, pItem->RealEstateItemID);
	if (pRealEstateItem && pRealEstateItem->GetItem())
	{
		ItemDefinition* placed = pRealEstateItem->GetItem()->GetItemDefinition();
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

float MQGroundSpawn::Distance(SPAWNINFO* pSpawn) const
{
	if (Type == MQGroundSpawnType::Ground)
	{
		EQGroundItem* ground = Get<EQGroundItem>();
		if (ground)
			return DistanceToPoint(pSpawn, ground->X, ground->Y);
	}
	else if (Type == MQGroundSpawnType::Placed)
	{
		EQPlacedItem* placed = Get<EQPlacedItem>();
		if (placed)
			return DistanceToPoint(pSpawn, placed->X, placed->Y);
	}

	return std::numeric_limits<float>::max();
}

float MQGroundSpawn::Distance3D(SPAWNINFO* pSpawn) const
{
	if (Type == MQGroundSpawnType::Ground)
	{
		EQGroundItem* ground = Get<EQGroundItem>();
		if (ground)
			return Distance3DToPoint(pSpawn, ground->X, ground->Y, ground->pActor ? ground->pActor->GetPosition().Z : ground->Z); // why pActor?
	}
	else if (Type == MQGroundSpawnType::Placed)
	{
		EQPlacedItem* placed = Get<EQPlacedItem>();
		if (placed)
			return Distance3DToPoint(pSpawn, placed->X, placed->Y, placed->Z);
	}

	return std::numeric_limits<float>::max();
}

int MQGroundSpawn::ID() const
{
	if (Type == MQGroundSpawnType::Ground)
	{
		EQGroundItem* ground = Get<EQGroundItem>();
		if (ground)
			return ground->DropID;
	}
	else if (Type == MQGroundSpawnType::Placed)
	{
		EQPlacedItem* placed = Get<EQPlacedItem>();
		if (placed)
			return placed->RealEstateItemID;
	}

	return -1;
}

int MQGroundSpawn::SubID() const
{
	if (Type == MQGroundSpawnType::Ground)
	{
		EQGroundItem* ground = Get<EQGroundItem>();
		if (ground)
			return ground->DropSubID;
	}
	else if (Type == MQGroundSpawnType::Placed)
	{
		EQPlacedItem* placed = Get<EQPlacedItem>();
		if (placed)
			return placed->RealEstateID;
	}

	return -1;
}

int MQGroundSpawn::ZoneID() const
{
	if (Type == MQGroundSpawnType::Ground)
	{
		EQGroundItem* ground = Get<EQGroundItem>();
		if (ground)
			return ground->ZoneID & 0x7FFF;
	}
	else if (Type == MQGroundSpawnType::Placed)
	{
		return pLocalPlayer->GetZoneID() & 0x7FFF;
	}

	return -1;
}

float MQGroundSpawn::Heading() const
{
	if (Type == MQGroundSpawnType::Ground)
	{
		EQGroundItem* ground = Get<EQGroundItem>();
		if (ground)
			return ground->Heading * 0.703125f;
	}
	else if (Type == MQGroundSpawnType::Placed)
	{
		EQPlacedItem* placed = Get<EQPlacedItem>();
		if (placed)
			return placed->Heading * 0.703125f;
	}

	return std::numeric_limits<float>::max();
}

MQGameObject MQGroundSpawn::ToGameObject() const
{
	if (Type == MQGroundSpawnType::Ground)
	{
		EQGroundItem* ground = Get<EQGroundItem>();
		if (ground)
		{
			return mq::ToGameObject(*ground);
		}
	}
	else if (Type == MQGroundSpawnType::Placed)
	{
		EQPlacedItem* placed = Get<EQPlacedItem>();
		if (placed)
		{
			return mq::ToGameObject(*placed);
		}
	}

	return MQGameObject();
}

template <> EQGroundItem* MQGroundSpawn::Get<EQGroundItem>() const
{
	if (Type == MQGroundSpawnType::Ground)
	{
		EQGroundItemPtr ptr = std::get<EQGroundItemPtr>(Object);
		if (ptr)
			return ptr->Ptr();
	}

	return nullptr;
}

template <> EQPlacedItem* MQGroundSpawn::Get<EQPlacedItem>() const
{
	if (Type == MQGroundSpawnType::Placed)
	{
		EQPlacedItemPtr ptr = std::get<EQPlacedItemPtr>(Object);
		if (ptr)
			return ptr->Ptr();
	}

	return nullptr;
}

void MQGroundSpawn::Reset()
{
	Type = MQGroundSpawnType::None;
	Object = {};
}

} // namespace mq
