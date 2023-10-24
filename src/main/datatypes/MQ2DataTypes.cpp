/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

namespace mq::datatypes {

//----------------------------------------------------------------------------
// Datatype Definitions

#define DATATYPE(Class, Var, Inherits)                               \
	Class* Var = nullptr;
#include "DataTypeList.h"
#undef DATATYPE

// Datatype deprecations
using MQ2TargetBuffType DEPRECATE("Use MQ2CachedBuffType instead") = MQ2CachedBuffType;
MQ2CachedBuffType* pTargetBuffType DEPRECATE("Use pCachedBuffType instead.") = pCachedBuffType;

//----------------------------------------------------------------------------
// DataType Initializations
void InitializeMQ2DataTypes()
{
#define DATATYPE(Class, Var, Inherits)                               \
	Var = new Class();                                               \
	if (Inherits != nullptr) {                                       \
		Var->SetInheritance(Inherits);                               \
	}
#include "DataTypeList.h"
#undef DATATYPE
}

//----------------------------------------------------------------------------
// DataType Shutdown
void ShutdownMQ2DataTypes()
{
#define DATATYPE(Class, Var, Inherits)                               \
	delete Var;
#include "DataTypeList.h"
#undef DATATYPE
}

//============================================================================
// MQ2Type

MQ2Type::MQ2Type(std::string_view newName)
{
	m_typeName = newName;
	m_owned = AddMQ2Type(*this);
}

MQ2Type::~MQ2Type()
{
	if (m_owned)
	{
		RemoveMQ2Type(*this);
	}
}

void MQ2Type::InitializeMembers(MQTypeMember* memberArray)
{
	for (int i = 0; memberArray[i].ID; i++)
	{
		AddMember(memberArray[i].ID, memberArray[i].Name);
	}
}

const char* MQ2Type::GetName() const
{
	return m_typeName.c_str();
}

const char* MQ2Type::GetMemberName(int ID) const
{
	for (const auto& pMember : Members)
	{
		if (pMember && pMember->ID == ID)
		{
			return &pMember->Name[0];
		}
	}

	return nullptr;
}

bool MQ2Type::GetMemberID(const char* Name, int& result) const
{
	std::scoped_lock lock(m_mutex);

	auto iter = MemberMap.find(Name);
	if (iter == MemberMap.end())
		return false;

	int index = iter->second;
	result = Members[index]->ID;
	return true;
}

mq::MQTypeMember* MQ2Type::FindMember(const char* Name)
{
	std::scoped_lock lock(m_mutex);

	auto iter = MemberMap.find(Name);
	if (iter == MemberMap.end())
		return nullptr;

	int index = MemberMap[Name];
	return Members[index].get();
}

mq::MQTypeMember* MQ2Type::FindMember(const std::string& Name)
{
	std::scoped_lock lock(m_mutex);

	auto iter = MemberMap.find(Name);
	if (iter == MemberMap.end())
		return nullptr;

	int index = MemberMap[Name];
	return Members[index].get();
}

mq::MQTypeMember* MQ2Type::FindMethod(const char* Name)
{
	std::scoped_lock lock(m_mutex);

	auto iter = MethodMap.find(Name);
	if (iter == MethodMap.end())
		return nullptr;

	int index = iter->second;
	return Methods[index].get();
}

mq::MQTypeMember* MQ2Type::FindMethod(const std::string& Name)
{
	std::scoped_lock lock(m_mutex);

	auto iter = MethodMap.find(Name);
	if (iter == MethodMap.end())
		return nullptr;

	int index = iter->second;
	return Methods[index].get();
}

bool MQ2Type::CanEvaluateMethodOrMember(const std::string& Name)
{
	std::scoped_lock lock(m_mutex);

	// exists in method map?
	return MemberMap.count(Name) != 0 || MethodMap.count(Name) != 0;
}

bool MQ2Type::AddMember(int id, const char* Name)
{
	std::scoped_lock lock(m_mutex);

	if (MemberMap.find(Name) != MemberMap.end())
		return false;

	// find an unused index from members.
	int index = -1;
	for (int i = 0; i < (int)Members.size(); ++i)
	{
		if (Members[i] == nullptr)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		Members.emplace_back();
		index = static_cast<int>(Members.size()) - 1;
	}

	Members[index] = std::make_unique<MQTypeMember>(id, Name, 0);
	MemberMap[Name] = index;
	return true;
}

bool MQ2Type::RemoveMember(const char* Name)
{
	std::scoped_lock lock(m_mutex);

	auto iter = MemberMap.find(Name);
	if (iter == MemberMap.end())
		return false;

	int index = iter->second;
	MemberMap.erase(iter);

	if (index < 0)
		return false;
	Members[index].reset();
	return true;
}

bool MQ2Type::AddMethod(int ID, const char* Name)
{
	std::scoped_lock lock(m_mutex);

	if (MethodMap.find(Name) != MethodMap.end())
		return false;

	// find an unused index from members.
	int index = -1;
	for (int i = 0; i < (int)Methods.size(); ++i)
	{
		if (Methods[i] == nullptr)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		Methods.emplace_back();
		index = static_cast<int>(Methods.size()) - 1;
	}

	Methods[index] = std::make_unique<MQTypeMember>(ID, Name, 1);
	MethodMap[Name] = index;
	return true;
}

bool MQ2Type::RemoveMethod(const char* Name)
{
	std::scoped_lock lock(m_mutex);

	auto iter = MethodMap.find(Name);
	if (iter == MethodMap.end())
		return false;

	int index = iter->second;
	MethodMap.erase(iter);

	if (index < 0)
		return false;
	Methods[index].reset();
	return true;
}

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

#if HAS_ADVANCED_LOOT
#include "MQ2AdvLootType.cpp"
#include "MQ2ItemFilterDataType.cpp"
#endif
#if HAS_KEYRING_WINDOW
#include "MQ2KeyRingType.cpp"
#endif