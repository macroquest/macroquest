/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

enum class XTargetMembers
{
	Address = 1,
	TargetType,
	ID,
	Name,
	PctAggro
};

MQ2XTargetType::MQ2XTargetType() : MQ2Type("xtarget")
{
	ScopedTypeMember(XTargetMembers, Address);
	ScopedTypeMember(XTargetMembers, TargetType);
	ScopedTypeMember(XTargetMembers, ID);
	ScopedTypeMember(XTargetMembers, Name);
	ScopedTypeMember(XTargetMembers, PctAggro);
}

bool MQ2XTargetType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!GetCharInfo() || !GetCharInfo()->pXTargetMgr || VarPtr.DWord >= MAX_EXTENDED_TARGETS)
		return false;

	if (MQTypeMember* pMember = MQ2XTargetType::FindMember(Member))
	{
		const XTARGETSLOT& xts = GetCharInfo()->pXTargetMgr->XTargetSlots[VarPtr.DWord];

		switch (static_cast<XTargetMembers>(pMember->ID))
		{
		case XTargetMembers::Address:
			Dest.DWord = (uint32_t)GetCharInfo()->pXTargetMgr;
			Dest.Type = pIntType;
			return true;

		case XTargetMembers::TargetType:
			if (const char* ptr = GetXtargetType(xts.xTargetType))
				strcpy_s(DataTypeTemp, ptr);
			else
				strcpy_s(DataTypeTemp, "UNKNOWN");
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;

		case XTargetMembers::ID:
			Dest.DWord = xts.SpawnID;
			Dest.Type = pIntType;
			return true;

		case XTargetMembers::Name:
			if (xts.Name[0] != 0)
				strcpy_s(DataTypeTemp, xts.Name);
			else
				strcpy_s(DataTypeTemp, "NULL");
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;

		case XTargetMembers::PctAggro:
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (pAggroInfo)
			{
				int index = AD_xTarget1 + VarPtr.DWord;
				if (index >= MAX_AGGRO_METER_SIZE)
					return false;

				Dest.DWord = pAggroInfo->aggroData[AD_xTarget1 + VarPtr.DWord].AggroPct;
				return true;
			}
			return false;

		default: break;
		}
	}
	else
	{
		if (VarPtr.DWord >= MAX_EXTENDED_TARGETS)
			return false;

		XTARGETSLOT xts = GetCharInfo()->pXTargetMgr->XTargetSlots[VarPtr.DWord];
		SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(xts.SpawnID);
		if (pSpawn)
		{
			MQVarPtr data;
			data.Ptr = pSpawn;

			return pSpawnType->GetMember(data, Member, Index, Dest);
		}
	}
	return false;
};

bool MQ2XTargetType::ToString(MQVarPtr VarPtr, char* Destination)
{
	int index = VarPtr.DWord;

	if (CHARINFO* pChar = GetCharInfo())
	{
		if (index <= 23 && pChar->pXTargetMgr && pChar->pXTargetMgr->XTargetSlots.Count)
		{
			XTARGETSLOT xtd = GetCharInfo()->pXTargetMgr->XTargetSlots[index];
			strcpy_s(Destination, MAX_STRING, xtd.Name);
		}
	}
	else
	{
		strcpy_s(Destination, MAX_STRING, "NULL");
	}

	return true;
}

} // namespace mq::datatypes
