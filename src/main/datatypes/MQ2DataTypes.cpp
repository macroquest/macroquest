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
#include "MQ2DataTypes.h"

namespace mq::datatypes {
//----------------------------------------------------------------------------
// Datatype Definitions

#define DATATYPE(Class, Var, Inherits, PersistentClass)              \
	Class* Var = nullptr;
#include "DataTypeList.h"
#undef DATATYPE

//----------------------------------------------------------------------------
// DataType Initializations
void InitializeMQ2DataTypes()
{
#define DATATYPE(Class, Var, Inherits, PersistentClass)              \
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
#define DATATYPE(Class, Var, Inherits, PersistentClass)              \
	delete Var;
#include "DataTypeList.h"
#undef DATATYPE
}

CDataArray::CDataArray(MQ2Type* Type, char* Index, const char* Default, bool ByData = false)
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
	char* pStart = Index;
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

	m_pData = new MQVarPtr[m_totalElements];
	m_pType = Type;
	if (m_pType != nullptr)
	{
		for (int index = 0; index < m_totalElements; index++)
		{
			m_pType->InitVariable(m_pData[index]);

			if (ByData)
				m_pType->FromData(m_pData[index], *(MQTypeVar*)Default);
			else
				m_pType->FromString(m_pData[index], (char*)Default);
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

int CDataArray::GetElement(char* Index)
{
	int Element = 0;
	if (m_nExtents == 1)
	{
		if (strchr(Index, ','))
			return -1;

		Element = GetIntFromString(Index, Element) - 1;
		if (Element >= m_totalElements)
			return -1;

		return Element;
	}

	int nGetExtents = 1;

	if (char* pComma = strchr(Index, ','))
	{
		nGetExtents++;
		while (pComma = strchr(&pComma[1], ','))
		{
			nGetExtents++;
		}
	}

	if (nGetExtents != m_nExtents)
		return -1;

	// read extents
	char* pStart = Index;
	for (int index = 0; index < m_nExtents; index++)
	{
		char* pComma = strchr(pStart, ',');
		if (pComma)
			*pComma = 0;

		int Temp = GetIntFromString(pStart, 0) - 1;
		if (Temp >= m_pExtents[index] || Temp < 0)
			return -1;

		for (int i = index + 1; i < m_nExtents; i++)
			Temp *= m_pExtents[i];
		Element += Temp;

		if (pComma)
		{
			*pComma = ',';
			pStart = &pComma[1];
		}
	}

	return Element;
}

bool CDataArray::GetElement(char* Index, MQTypeVar& Dest)
{
	if (m_nExtents == 1)
	{
		if (strchr(Index, ','))
			return false;

		int Element = GetIntFromString(Index, 0) - 1;
		if (Element >= m_totalElements || Element < 0)
			return false;

		Dest.Type = m_pType;
		Dest.VarPtr = m_pData[Element];

		return true;
	}

	int nGetExtents = 1;

	if (char* pComma = strchr(Index, ','))
	{
		nGetExtents++;
		while (pComma = strchr(&pComma[1], ','))
		{
			nGetExtents++;
		}
	}

	if (nGetExtents != m_nExtents)
		return false;

	// read extents
	char* pStart = Index;
	int Element = 0;

	for (int index = 0; index < m_nExtents; index++)
	{
		char* pComma = strchr(pStart, ',');
		if (pComma)
			*pComma = 0;

		int Temp = GetIntFromString(pStart, 0) - 1;
		if (Temp >= m_pExtents[index] || Temp < 0)
			return false;

		for (int i = index + 1; i < m_nExtents; i++)
			Temp *= m_pExtents[i];

		Element += Temp;
		if (pComma)
		{
			*pComma = ',';
			pStart = &pComma[1];
		}
	}

	Dest.Type = m_pType;
	Dest.VarPtr = m_pData[Element];
	return true;
}
}

#include "MQ2AdvLootItemType.cpp"
#include "MQ2AdvLootType.cpp"
#include "MQ2AlertListType.cpp"
#include "MQ2AlertType.cpp"
#include "MQ2AltAbilityType.cpp"
#include "MQ2ArgbType.cpp"
#include "MQ2ArrayType.cpp"
#include "MQ2AugType.cpp"
#include "MQ2AuraType.cpp"
#include "MQ2BandolierItemType.cpp"
#include "MQ2BandolierType.cpp"
#include "MQ2BodyType.cpp"
#include "MQ2BoolType.cpp"
#include "MQ2BuffType.cpp"
#include "MQ2CachedBuffType.cpp"
#include "MQ2CharacterType.cpp"
#include "MQ2CharSelectListType.cpp"
#include "MQ2ClassType.cpp"
#include "MQ2CorpseType.cpp"
#include "MQ2CurrentZoneType.cpp"
#include "MQ2DeityType.cpp"
#include "MQ2DoubleType.cpp"
#include "MQ2DynamicZoneType.cpp"
#include "MQ2DZMemberType.cpp"
#include "MQ2EverQuestType.cpp"
#include "MQ2EvolvingItemType.cpp"
#include "MQ2FellowshipMemberType.cpp"
#include "MQ2FellowshipType.cpp"
#include "MQ2FloatType.cpp"
#include "MQ2FriendsType.cpp"
#include "MQ2GroundType.cpp"
#include "MQ2GroupMemberType.cpp"
#include "MQ2GroupType.cpp"
#include "MQ2HeadingType.cpp"
#include "MQ2Int64Type.cpp"
#include "MQ2IntType.cpp"
#include "MQ2InvSlotType.cpp"
#include "MQ2ItemFilterDataType.cpp"
#include "MQ2ItemSpellType.cpp"
#include "MQ2ItemType.cpp"
#include "MQ2KeyRingType.cpp"
#include "MQ2MacroQuestType.cpp"
#include "MQ2MacroType.cpp"
#include "MQ2MathType.cpp"
#include "MQ2MenuType.cpp"
#include "MQ2MercenaryType.cpp"
#include "MQ2MerchantType.cpp"
#include "MQ2PetType.cpp"
#include "MQ2PluginType.cpp"
#include "MQ2PointMerchantItemType.cpp"
#include "MQ2PointMerchantType.cpp"
#include "MQ2RaceType.cpp"
#include "MQ2RangeType.cpp"
#include "MQ2SkillType.cpp"
#include "MQ2SolventType.cpp"
#include "MQ2SpawnType.cpp"
#include "MQ2SpellType.cpp"
#include "MQ2StringType.cpp"
#include "MQ2SwitchType.cpp"
#include "MQ2TargetBuffType.cpp"
#include "MQ2TargetType.cpp"
#include "MQ2TaskMemberType.cpp"
#include "MQ2TaskObjectiveType.cpp"
#include "MQ2TaskType.cpp"
#include "MQ2TicksType.cpp"
#include "MQ2TimerType.cpp"
#include "MQ2TimeType.cpp"
#include "MQ2Type.cpp"
#include "MQ2TypeType.cpp"
#include "MQ2WindowType.cpp"
#include "MQ2WorldLocationType.cpp"
#include "MQ2XTargetType.cpp"
#include "MQ2ZoneType.cpp"
