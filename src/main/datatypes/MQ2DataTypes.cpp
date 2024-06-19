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
#include "MQ2DataTypes.h"
#include "MQDataAPI.h"

namespace mq::datatypes {

 //----------------------------------------------------------------------------
 // Datatype Definitions

#define DATATYPE(Class, Var, Inherits)                               \
	Class* Var = nullptr;
#include "datatypes/DataTypeList.h"
#undef DATATYPE

void RegisterDataTypes()
{
#define DATATYPE(Class, Var, Inherits)                               \
	Var = new Class();                                               \
	if (Inherits != nullptr) {                                       \
		Var->SetInheritance(Inherits);                               \
	}
#include "datatypes/DataTypeList.h"
#undef DATATYPE
}

//----------------------------------------------------------------------------
// DataType Shutdown
void UnregisterDataTypes()
{
#define DATATYPE(Class, Var, Inherits)                               \
	delete Var;
#include "datatypes/DataTypeList.h"
#undef DATATYPE
}


// Datatype deprecations
using MQ2TargetBuffType DEPRECATE("Use MQ2CachedBuffType instead") = MQ2CachedBuffType;
MQ2CachedBuffType* pTargetBuffType DEPRECATE("Use pCachedBuffType instead.") = pCachedBuffType;

//============================================================================
// CDataArray

CDataArray::CDataArray(MQ2Type* Type, const char* Index)
{
	m_nExtents = 1;
	m_totalElements = 1;

	// count number of , 's
	if (const char* pComma = strchr(Index, ','))
	{
		m_nExtents++;
		while (pComma = strchr(&pComma[1], ','))
		{
			m_nExtents++;
		}
	}

	// allocate extents
	m_pExtents = new int[m_nExtents];

	// read extents
	std::string IndexCopy = Index;
	char* pStart = &IndexCopy[0];
	for (int index = 0; index < m_nExtents; index++)
	{
		char* pComma = strchr(pStart, ',');
		if (pComma)
			*pComma = 0;

		m_pExtents[index] = GetIntFromString(pStart, 0);
		m_totalElements *= m_pExtents[index];

		if (pComma)
		{
			*pComma = ',';
			pStart = &pComma[1];
		}
	}

	m_pType = Type;
	m_pData = new MQVarPtr[m_totalElements];
}

void CDataArray::Initialize(const char* defaultValue)
{
	if (m_pType != nullptr)
	{
		for (int index = 0; index < m_totalElements; index++)
		{
			m_pType->InitVariable(m_pData[index]);
			m_pType->FromString(m_pData[index], defaultValue);
		}
	}
}

void CDataArray::Initialize(const MQTypeVar& defaultValue)
{
	if (m_pType != nullptr)
	{
		for (int index = 0; index < m_totalElements; index++)
		{
			m_pType->InitVariable(m_pData[index]);
			m_pType->FromData(m_pData[index], defaultValue);
		}
	}
}


CDataArray::~CDataArray()
{
	if (m_pType && m_pData)
	{
		for (int index = 0; index < m_totalElements; index++)
		{
			m_pType->FreeVariable(m_pData[index]);
		}
	}

	delete[] m_pExtents;
	delete[] m_pData;
}

void CDataArray::Delete()
{
	if (m_pType && m_pData)
	{
		for (int index = 0; index < m_totalElements; index++)
		{
			m_pType->FreeVariable(m_pData[index]);
		}
	}

	delete[] m_pExtents;
	delete[] m_pData;

	m_pExtents = nullptr;
	m_pType = nullptr;
	m_pData = nullptr;
	m_nExtents = 0;
	m_totalElements = 0;
}

int CDataArray::GetElement(std::string_view Index) const
{
	if (m_nExtents == 1)
	{
		if (Index.find(',') != std::string_view::npos)
			return -1;

		int location = GetIntFromString(Index, 0) - 1;
		if (location >= m_totalElements)
			return -1;

		return location;
	}
	
	int num_extents = static_cast<int>(std::count(Index.begin(), Index.end(), ',') + 1);
	if (num_extents != m_nExtents)
		return -1;

	auto tokens = split_view(Index, ',');
	int extent = 0;
	return std::accumulate(tokens.begin(), tokens.end(), 0, [&extent, this](int location, std::string_view token) -> int
		{
			if (location < 0)
				return -1;

			int max_extent = m_pExtents[extent];
			int next_location = GetIntFromString(token, 0) - 1;
			if (next_location >= max_extent || next_location < 0)
				return -1;

			for (int extent_marker = extent + 1; extent_marker < m_nExtents; ++extent_marker)
				next_location *= m_pExtents[extent_marker];

			++extent;
			return location + next_location;
		});
}

int CDataArray::GetElement(char* Index)
{
	return GetElement(std::string_view(Index));
}

bool CDataArray::GetElement(std::string_view Index, MQTypeVar& Dest)
{
	int location = GetElement(std::string_view(Index));
	if (location >= 0)
	{
		Dest.Type = m_pType;
		Dest.VarPtr = m_pData[location];
	}

	return location >= 0;
}

bool CDataArray::GetElement(char* Index, MQTypeVar& Dest)
{
	return GetElement(std::string_view(Index), Dest);
}

} // namespace mq::datatypes

#include "MQ2BasicTypes.cpp"

#include "MQ2AchievementType.cpp"
#include "MQ2AlertListType.cpp"
#include "MQ2AlertType.cpp"
#include "MQ2AltAbilityType.cpp"
#include "MQ2AugType.cpp"
#include "MQ2AuraType.cpp"
#include "MQ2BandolierType.cpp"
#include "MQ2BodyType.cpp"
#include "MQ2BuffType.cpp"
#include "MQ2CachedBuffType.cpp"
#include "MQ2CharacterType.cpp"
#include "MQ2CharSelectListType.cpp"
#include "MQ2ClassType.cpp"
#include "MQ2CorpseType.cpp"
#include "MQ2CurrentZoneType.cpp"
#include "MQ2DeityType.cpp"
#include "MQ2DynamicZoneType.cpp"
#include "MQ2EverQuestType.cpp"
#include "MQ2EvolvingItemType.cpp"
#include "MQ2FellowshipType.cpp"
#include "MQ2FriendsType.cpp"
#include "MQ2GroundType.cpp"
#include "MQ2GroupType.cpp"
#include "MQ2InvSlotType.cpp"
#include "MQ2ItemSpellType.cpp"
#include "MQ2ItemType.cpp"
#include "MQ2MacroQuestType.cpp"
#include "MQ2MacroType.cpp"
#include "MQ2MathType.cpp"
#include "MQ2MenuType.cpp"
#include "MQ2MercenaryType.cpp"
#include "MQ2MerchantType.cpp"
#include "MQ2PetType.cpp"
#include "MQ2PluginType.cpp"
#include "MQ2PointMerchantType.cpp"
#include "MQ2RaceType.cpp"
#include "MQ2RaidType.cpp"
#include "MQ2SkillType.cpp"
#include "MQ2SolventType.cpp"
#include "MQ2SpawnType.cpp"
#include "MQ2SpellType.cpp"
#include "MQ2SwitchType.cpp"
#include "MQ2TargetType.cpp"
#include "MQ2TaskType.cpp"
#include "MQ2TimerType.cpp"
#include "MQ2TradeskillDepotType.cpp"
#include "MQ2WindowType.cpp"
#include "MQ2WorldLocationType.cpp"
#include "MQ2XTargetType.cpp"
#include "MQ2ZoneType.cpp"
#include "MQIniType.cpp"
#include "MQInventoryType.cpp"
#include "MQCursorAttachmentType.cpp"
#include "MQSocialType.cpp"

#if HAS_ADVANCED_LOOT
#include "MQ2AdvLootType.cpp"
#include "MQ2ItemFilterDataType.cpp"
#endif
#if HAS_KEYRING_WINDOW
#include "MQ2KeyRingType.cpp"
#endif