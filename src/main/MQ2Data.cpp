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
#include "MQ2Main.h"
#include "mq/libutils/glmUtils.h"

#include <date/date.h>

namespace mq::datatypes {

bool dataSelect(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	char szArg[MAX_STRING] = { 0 };
	char szArg1[MAX_STRING] = { 0 };
	int N = 2;
	GetArg(szArg1, szIndex, 1, false, false, true);
	while (true)
	{
		GetArg(szArg, szIndex, N, false, false, true);
		N++;
		if (!szArg[0])
		{
			Ret.DWord = 0;
			Ret.Type = pIntType;
			return true;
		}

		if (!_stricmp(szArg1, szArg))
		{
			Ret.DWord = N - 2;
			Ret.Type = pIntType;
			return true;
		}
	}
}

bool dataIf(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		int nDelimiter = 0;
		const char* pDelimiter = strchr(szIndex, gIfAltDelimiter);

		while (pDelimiter != nullptr)
		{
			nDelimiter++;
			pDelimiter = strchr(pDelimiter + 1, gIfAltDelimiter);
		}

		char szTemp[MAX_STRING];
		strcpy_s(szTemp, szIndex);

		// condition| whentrue| whenfalse
		if (nDelimiter == 2)
		{
			if (char* pTrue = strchr(szTemp, gIfAltDelimiter))
			{
				*pTrue = 0;
				pTrue++;
				if (char* pFalse = strchr(pTrue, gIfAltDelimiter))
				{
					*pFalse = 0;
					pFalse++;
					double CalcResult;
					if (!Calculate(szTemp, CalcResult))
						return false;

					if (CalcResult != 0.0f)
					{
						strcpy_s(DataTypeTemp, pTrue);
						Ret.Ptr = &DataTypeTemp[0];
						Ret.Type = pStringType;
						return true;
					}
					else
					{
						strcpy_s(DataTypeTemp, pFalse);
						Ret.Ptr = &DataTypeTemp[0];
						Ret.Type = pStringType;
						return true;
					}
				}
			}
		}

		// condition, whentrue, whenfalse
		if (char* pTrue = strchr(szTemp, gIfDelimiter))
		{
			*pTrue = 0;
			pTrue++;
			if (char* pFalse = strchr(pTrue, gIfDelimiter))
			{
				*pFalse = 0;
				pFalse++;
				double CalcResult;
				if (!Calculate(szTemp, CalcResult))
					return false;

				if (CalcResult != 0.0f)
				{
					strcpy_s(DataTypeTemp, pTrue);
					Ret.Ptr = &DataTypeTemp[0];
					Ret.Type = pStringType;
					return true;
				}
				else
				{
					strcpy_s(DataTypeTemp, pFalse);
					Ret.Ptr = &DataTypeTemp[0];
					Ret.Type = pStringType;
					return true;
				}
			}
		}
	}
	return false;
}

bool dataDefined(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;
	Ret.Set(FindMQ2DataVariable(szIndex) != nullptr);
	Ret.Type = pBoolType;
	return true;
}

bool dataSubDefined(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;
	Ret.Set(gMacroBlock && (gMacroSubLookupMap.find(szIndex) != gMacroSubLookupMap.end()));
	Ret.Type = pBoolType;
	return true;
}

// Arguments are passed in as Y, X, Z per documentation
bool dataLineOfSight(const char* szIndex, MQTypeVar& Ret)
{
	if (!pControlledPlayer)
		return false;

	if (szIndex[0])
	{
		const glm::vec3 player_loc = { pLocalPlayer->Y, pLocalPlayer->X, pLocalPlayer->Z };
		const auto [coord1, coord2] = GetVec3SetFromString(szIndex, player_loc, player_loc);

		// This is possibly inaccurate because it adjusts the ray for the player model,
		// despite not necessarily using player model as the source location. Need to
		// evaluate CastRayLoc and see what it expects for that as well as x/y/z coordinates
		Ret.Set(CastRayLoc({ coord1[0], coord1[1], coord1[2] }, pControlledPlayer->GetRace(), coord2[0], coord2[1], coord2[2]));
		Ret.Type = pBoolType;
		return true;
	}

	return false;
}

bool dataAlias(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		if (IsAlias(szIndex))
		{
			Ret.Set(true);
			Ret.Type = pBoolType;
			return true;
		}
	}
	return false;
}

} // namespace mq::datatypes
