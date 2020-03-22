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

using namespace mq;

// TODO:
// - pGroundTarget needs to be deprecated
// - GroundObject needs to be deprecated
// - EnviroTarget needs to be deprecated
// - old GetFriendlyNameForGroundItem needs to be deprecated
// - export shared_ptr properly (likely create an interface in a shared header)

class GroundSpawnSearch;
std::shared_ptr<GroundSpawnSearch> s_groundSpawnSearch;

class GroundSpawnSearch : public MQ2Transient
{
private:
	// make this private because _all access_ to ground spawns should be through the list
	std::vector<std::shared_ptr<MQ2GroundSpawn>> m_searchResults;
	std::vector<std::shared_ptr<MQ2GroundSpawn>>::iterator m_currentResult;
	std::mutex s_resultMutex;

public:
	// Inherited via MQ2Transient
	virtual void Invalidate() override
	{
		m_searchResults.clear();
		m_currentResult = m_searchResults.end();
		m_invalidated = true;
		// we can't revalidate this, just drop it (which we do by releasing the shared_ptr that owns this)
		s_groundSpawnSearch.reset();
	}

	virtual operator bool() const override
	{
		return !m_searchResults.empty() && !m_invalidated;
	}

	template <typename GroundPred, typename PlacedPred>
	void Filter(SPAWNINFO* pSpawn, GroundPred GroundPredicate, PlacedPred PlacedPredicate)
	{
		std::scoped_lock lock(s_resultMutex);
		m_searchResults.clear();

		if (pItemList)
		{
			for (auto pGround = pItemList->Top; pGround; pGround = pGround->pNext)
			{
				// z filters are universal
				if (gZFilter < 10000.f && (pGround->Z > pSpawn->Z + gZFilter || pGround->Z < pSpawn->Z - gZFilter))
					continue;

				if (GroundPredicate(pGround))
					m_searchResults.emplace_back(std::make_shared<MQ2GroundSpawn>(pGround));
			}
		}

		auto placed_item_mgr = EQPlacedItemManager::Instance();
		for (auto pPlaced = placed_item_mgr.Top; pPlaced; pPlaced = pPlaced->pNext)
		{
			if (gZFilter < 10000.f && (pPlaced->Z > pSpawn->Z + gZFilter || pPlaced->Z < pSpawn->Z - gZFilter))
				continue;

			if (PlacedPredicate(pPlaced))
				m_searchResults.emplace_back(std::make_shared<MQ2GroundSpawn>(pPlaced));
		}

		m_currentResult = m_searchResults.begin();
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
		Filter(pSpawn,
			[&Name](EQGroundItem* ground)
			{
				return Name.empty() || ci_find_substr(GetFriendlyNameForGroundItem(ground), Name);
			},
			[&Name](EQPlacedItem* placed)
			{
				return Name.empty() || ci_find_substr(placed->Name, Name);
			});
	}

	void Sort(SPAWNINFO* pSpawn)
	{
		std::scoped_lock lock(s_resultMutex);

		DistanceSort(pSpawn, m_searchResults,
			[](SPAWNINFO* pSpawn, const std::shared_ptr<MQ2GroundSpawn>& ground)
			{
				if (ground)
				{
					if (ground->Type == MQ2GroundSpawnType::Ground)
					{
						auto pGround = std::get<MQ2EQObject<EQGroundItem>>(ground->Object);
						if (pGround)
							return Get3DDistance(pSpawn->X, pSpawn->Y, pSpawn->Z, pGround->X, pGround->Y, pGround->pSwitch->Z);
					}
					else if (ground->Type == MQ2GroundSpawnType::Placed)
					{
						auto pPlaced = std::get<MQ2EQObject<EQPlacedItem>>(ground->Object);
						if (pPlaced)
							return Get3DDistance(pSpawn->X, pSpawn->Y, pSpawn->Z, pPlaced->X, pPlaced->Y, pPlaced->Z);
					}
				}

				// if the object isn't valid or is nullptr, then stick them at the end of the list
				return std::numeric_limits<float>::max();
			});

		m_currentResult = m_searchResults.begin();
	}

	bool Empty() const { return m_searchResults.empty(); }

	std::shared_ptr<MQ2GroundSpawn> Current()
	{
		std::scoped_lock lock(s_resultMutex);

		if (m_currentResult != m_searchResults.end())
			return *m_currentResult;

		return {};
	}

	std::shared_ptr<MQ2GroundSpawn> First()
	{
		if (m_searchResults.empty())
			return {};

		m_currentResult = m_searchResults.begin();
		return Current();
	}

	std::shared_ptr<MQ2GroundSpawn> Last()
	{
		if (m_searchResults.empty())
			return {};

		m_currentResult = std::prev(m_searchResults.end());
		return Current();
	}

	std::shared_ptr<MQ2GroundSpawn> Next()
	{
		if (m_currentResult == m_searchResults.end())
			return {};

		++m_currentResult;
		return Current();
	}

	std::shared_ptr<MQ2GroundSpawn> Prev()
	{
		if (m_currentResult == m_searchResults.begin())
			return {};

		--m_currentResult;
		return Current();
	}

	std::shared_ptr<MQ2GroundSpawn> At(size_t Idx)
	{
		if (Idx >= m_searchResults.size())
			return {};

		return m_searchResults.at(Idx);
	}

	int Count()
	{
		return m_searchResults.size();
	}
};

std::shared_ptr<MQ2GroundSpawn> mq::GetGroundSpawnByName(std::string_view Name)
{
	s_groundSpawnSearch = std::make_shared<GroundSpawnSearch>(); // create a new search (will GC the old one)
	s_groundSpawnSearch->Filter(pCharSpawn, Name);
	s_groundSpawnSearch->Sort(pCharSpawn);
	return s_groundSpawnSearch->First();
}

std::shared_ptr<MQ2GroundSpawn> mq::GetGroundSpawnByID(int ID)
{
	s_groundSpawnSearch = std::make_shared<GroundSpawnSearch>(); // create a new search (will GC the old one)
	s_groundSpawnSearch->Filter(pCharSpawn, ID);
	s_groundSpawnSearch->Sort(pCharSpawn);
	return s_groundSpawnSearch->First();
}

std::shared_ptr<MQ2GroundSpawn> mq::GetNthGroundSpawnFromMe(size_t N)
{
	if (!s_groundSpawnSearch)
	{
		s_groundSpawnSearch = std::make_shared<GroundSpawnSearch>();
		s_groundSpawnSearch->Filter(pCharSpawn, "");
		s_groundSpawnSearch->Sort(pCharSpawn);
	}

	return s_groundSpawnSearch->At(N); // this does size checking for us
}

int mq::GetGroundSpawnCount()
{
	if (!s_groundSpawnSearch)
	{
		s_groundSpawnSearch = std::make_shared<GroundSpawnSearch>();
		s_groundSpawnSearch->Filter(pCharSpawn, "");
		s_groundSpawnSearch->Sort(pCharSpawn);
	}

	return s_groundSpawnSearch->Count();
}

std::shared_ptr<MQ2GroundSpawn> mq::CurrentGroundSpawn()
{
	if (!s_groundSpawnSearch)
	{
		s_groundSpawnSearch = std::make_shared<GroundSpawnSearch>();
		s_groundSpawnSearch->Filter(pCharSpawn, "");
		s_groundSpawnSearch->Sort(pCharSpawn);
	}

	return s_groundSpawnSearch->Current();
}

std::shared_ptr<MQ2GroundSpawn> mq::FirstGroundSpawn()
{
	if (!s_groundSpawnSearch)
	{
		s_groundSpawnSearch = std::make_shared<GroundSpawnSearch>();
		s_groundSpawnSearch->Filter(pCharSpawn, "");
		s_groundSpawnSearch->Sort(pCharSpawn);
	}

	return s_groundSpawnSearch->First();
}

std::shared_ptr<MQ2GroundSpawn> mq::LastGroundSpawn()
{
	if (!s_groundSpawnSearch)
	{
		s_groundSpawnSearch = std::make_shared<GroundSpawnSearch>();
		s_groundSpawnSearch->Filter(pCharSpawn, "");
		s_groundSpawnSearch->Sort(pCharSpawn);
	}

	return s_groundSpawnSearch->Last();
}

std::shared_ptr<MQ2GroundSpawn> mq::NextGroundSpawn()
{
	if (!s_groundSpawnSearch)
	{
		s_groundSpawnSearch = std::make_shared<GroundSpawnSearch>();
		s_groundSpawnSearch->Filter(pCharSpawn, "");
		s_groundSpawnSearch->Sort(pCharSpawn);
	}

	return s_groundSpawnSearch->Next();
}

std::shared_ptr<MQ2GroundSpawn> mq::PrevGroundSpawn()
{
	if (!s_groundSpawnSearch)
	{
		s_groundSpawnSearch = std::make_shared<GroundSpawnSearch>();
		s_groundSpawnSearch->Filter(pCharSpawn, "");
		s_groundSpawnSearch->Sort(pCharSpawn);
	}

	return s_groundSpawnSearch->Prev();
}

CActorInterface* mq::MQ2GroundSpawn::Actor()
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

CXStr mq::MQ2GroundSpawn::Name()
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

	return "";
}

CXStr mq::MQ2GroundSpawn::DisplayName()
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
		{
			auto real_estate = RealEstateManagerClient::Instance();
			auto pRealEstateItem = real_estate.GetItemByRealEstateAndItemIds(placed->RealEstateID, placed->RealEstateItemID);
			if (pRealEstateItem && pRealEstateItem->Object.pItemBase)
			{
				auto pItem = pRealEstateItem->Object.pItemBase->GetItemDefinition();
				if (pItem)
					return pItem->Name;
			}
		}
	}

	return "";
}

CVector3 mq::MQ2GroundSpawn::Position()
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

void mq::SetGroundSpawn(SPAWNINFO* pSpawn, std::string_view Name)
{
	s_groundSpawnSearch = std::make_shared<GroundSpawnSearch>(); // create a new search (will GC the old one)
	s_groundSpawnSearch->Filter(pSpawn, Name);
	s_groundSpawnSearch->Sort(pSpawn);
}

void mq::ClearGroundSpawn()
{
	if (s_groundSpawnSearch)
		s_groundSpawnSearch.reset();
}

CXStr mq::GetFriendlyNameForGroundItem(EQGroundItem* pItem)
{
	if (!pItem)
		return "";

	int item_def = GetIntFromString(&pItem->Name[2], 0);
	for (auto actor = ActorDefList; actor->Def; ++actor)
	{
		if (actor->Def == item_def && ((actor->ZoneID < 0 || actor->ZoneID == (pItem->ZoneID & 0x7FFF))))
			return actor->Name;
	}

	// didn't find an actor def, so construct a name
	return CXStr(fmt::format("Drop{:05d}/{:d}", item_def, pItem->DropID));
}

char* mq::GetFriendlyNameForGroundItem(PGROUNDITEM pItem, char* szName, size_t BufferSize)
{
	strcpy_s(szName, BufferSize, GetFriendlyNameForGroundItem(pItem).c_str());
	return szName;
}

float mq::MQ2GroundSpawn::Distance(SPAWNINFO* pSpawn)
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

float mq::MQ2GroundSpawn::Distance3D(SPAWNINFO* pSpawn)
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

int mq::MQ2GroundSpawn::ID()
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

int mq::MQ2GroundSpawn::SubID()
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

int mq::MQ2GroundSpawn::ZoneID()
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

float mq::MQ2GroundSpawn::Heading()
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

std::optional<SPAWNINFO> mq::MQ2GroundSpawn::ToSpawn()
{
	if (Type != MQ2GroundSpawnType::None)
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
	}

	return std::nullopt;
}

template <> EQGroundItem* mq::MQ2GroundSpawn::Get<EQGroundItem>() const
{
	if (Type == MQ2GroundSpawnType::Ground)
	{
		auto ptr = std::get<MQ2EQObject<EQGroundItem>>(Object);
		if (ptr)
			return ptr.Ptr();
	}

	return nullptr;
}

template <> EQPlacedItem* mq::MQ2GroundSpawn::Get<EQPlacedItem>() const
{
	if (Type == MQ2GroundSpawnType::Placed)
	{
		auto ptr = std::get<MQ2EQObject<EQPlacedItem>>(Object);
		if (ptr)
			return ptr.Ptr();
	}

	return nullptr;
}
