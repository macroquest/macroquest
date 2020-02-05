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

bool MQ2RangeType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2RangeType::FindMember(Member);
	if (!pMember)
		return false;
	if (!Index[0])
		return false;

	int64_t P1 = 0;
	int64_t P2 = 0;
	int64_t P3 = 0;

	switch (static_cast<RangeMembers>(pMember->ID))
	{
	case Inside:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (Index[0])
		{
			if (char* pColon = strchr(Index, ':'))
			{
				*pColon = 0;
				P3 = GetInt64FromString(&pColon[1], P3);
				if (char* pComma = strchr(Index, ','))
				{
					*pComma = 0;
					P2 = GetInt64FromString(&pComma[1], P2);
					P1 = GetInt64FromString(Index, P1);

					if (P3 > P1 && P3 < P2)
					{
						Dest.DWord = true;
						return true;
					}
				}
			}
		}
		return true;

	case Between:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (Index[0]) {
			if (char* pColon = strchr(Index, ':'))
			{
				*pColon = 0;
				P3 = GetInt64FromString(&pColon[1], P3);
				if (char* pComma = strchr(Index, ','))
				{
					*pComma = 0;
					P2 = GetInt64FromString(&pComma[1], P2);
					P1 = GetInt64FromString(Index, P1);

					if (P3 >= P1 && P3 <= P2)
					{
						Dest.DWord = true;
						return true;
					}
				}
			}
		}
		return true;

	default: break;
	}

	return false;
}

