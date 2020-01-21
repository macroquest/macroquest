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

using namespace mq;
using namespace mq::datatypes;

bool MQ2XTargetType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!GetCharInfo() || !GetCharInfo()->pXTargetMgr || VarPtr.DWord >= MAX_EXTENDED_TARGETS)
		return false;

	if (MQTypeMember* pMember = MQ2XTargetType::FindMember(Member))
	{
		const XTARGETSLOT& xts = GetCharInfo()->pXTargetMgr->XTargetSlots[VarPtr.DWord];

		switch (static_cast<xTargetMembers>(pMember->ID))
		{
		case xAddress:
			Dest.DWord = (uint32_t)GetCharInfo()->pXTargetMgr;
			Dest.Type = pIntType;
			return true;

		case TargetType:
			if (const char* ptr = GetXtargetType(xts.xTargetType))
				strcpy_s(DataTypeTemp, ptr);
			else
				strcpy_s(DataTypeTemp, "UNKNOWN");
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;

		case ID:
			Dest.DWord = xts.SpawnID;
			Dest.Type = pIntType;
			return true;

		case Name:
			if (xts.Name[0] != 0)
				strcpy_s(DataTypeTemp, xts.Name);
			else
				strcpy_s(DataTypeTemp, "NULL");
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;

		case PctAggro:
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

