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

bool MQ2MathType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2MathType::FindMember(Member);
	if (!pMember)
		return false;

	if (!Index[0])
		return false;

	double CalcResult = 0;

	switch (static_cast<MathMembers>(pMember->ID))
	{
	case Abs:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)CalcResult;
			if (Dest.Float < 0)
				Dest.Float *= -1;
			return true;
		}
		return false;

	case Rand:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (char* Arg = Index)
		{
			char szMin[MAX_STRING] = { 0 };
			char szMax[MAX_STRING] = { 0 };
			int Min = 0;
			int Max = 0;

			if (char* pDest = strchr(Arg, ','))
			{
				pDest[0] = '\0';
				Min = GetIntFromString(Arg, Min);
				pDest++;
				Max = GetIntFromString(pDest, Max);
			}
			else
			{
				Max = GetIntFromString(Arg, Max);
			}

			if (Max == 0 || Max > RAND_MAX)
				return false;

			Dest.DWord = RangeRandom(Min, Max);
			return true;
		}
		return false;

	case Sqrt:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)sqrt(CalcResult);
			return true;
		}
		return false;

	case Calc:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)CalcResult;
			return true;
		}
		return false;

	case Sin:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)sin(CalcResult / DegToRad);
			return true;
		}
		return false;

	case Cos:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)cos(CalcResult / DegToRad);
			return true;
		}
		return false;

	case Tan:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)tan(CalcResult / DegToRad);
			return true;
		}
		return false;

	case Asin:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)(asin(CalcResult) * DegToRad);
			return true;
		}
		return false;

	case Acos:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)(acos(CalcResult) * DegToRad);
			return true;
		}
		return false;

	case Atan:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)(atan(CalcResult) * DegToRad);
			return true;
		}
		return false;

	case Not:
		Dest.DWord = ~GetIntFromString(Index, 0);
		Dest.Type = pIntType;
		return true;

	case Hex:
		sprintf_s(DataTypeTemp, "0x%X", GetIntFromString(Index, 0));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Dec:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (sscanf_s(Index, "%x", &Dest.DWord)) {
			return true;
		}
		return false;

	case Clamp:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (char* Arg = Index)
		{
			// TODO:  Should probably add some error checking here to make sure good data went in
			char szN[MAX_STRING] = { 0 };
			GetArg(szN, Arg, 1, false, false, true);
			int n = GetIntFromString(szN, 0);

			char szMin[MAX_STRING] = { 0 };
			GetArg(szMin, Arg, 2, false, false, true);
			int Min = GetIntFromString(szMin, 0);

			char szMax[MAX_STRING] = { 0 };
			GetArg(szMax, Arg, 3, false, false, true);
			int Max = GetIntFromString(szMax, 0);

			Dest.Int = std::max(Min, std::min(n, Max));
			return true;
		}
		return false;

	case Distance:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		// TODO: This code appears in LineOfSight function, possibly clean and combine
		if (Index[0])
		{
			float P1[3];
			float P2[3];
			P1[0] = P2[0] = ((SPAWNINFO*)pCharSpawn)->Y;
			P1[1] = P2[1] = ((SPAWNINFO*)pCharSpawn)->X;
			P1[2] = P2[2] = ((SPAWNINFO*)pCharSpawn)->Z;

			if (char* pColon = strchr(Index, ':'))
			{
				*pColon = 0;
				if (char* pComma = strchr(&pColon[1], ','))
				{
					*pComma = 0;
					P2[0] = GetFloatFromString(&pColon[1], P2[0]);
					*pComma = ',';

					if (char* pComma2 = strchr(&pComma[1], ','))
					{
						*pComma2 = 0;
						P2[1] = GetFloatFromString(&pComma[1], P2[1]);
						*pComma2 = ',';
						P2[2] = GetFloatFromString(&pComma2[1], P2[2]);
					}
					else
					{
						P2[1] = GetFloatFromString(&pComma[1], P2[1]);
					}
				}
				else
				{
					P2[0] = GetFloatFromString(&pColon[1], P2[0]);
				}
			}

			if (char* pComma = strchr(Index, ','))
			{
				*pComma = 0;
				P1[0] = GetFloatFromString(Index, P1[0]);
				*pComma = ',';

				if (char* pComma2 = strchr(&pComma[1], ','))
				{
					*pComma2 = 0;
					P1[1] = GetFloatFromString(&pComma[1], P1[1]);
					*pComma2 = ',';
					P1[2] = GetFloatFromString(&pComma2[1], P1[2]);
				}
				else
				{
					P1[1] = GetFloatFromString(&pComma[1], P1[1]);
				}
			}
			else
			{
				P1[0] = GetFloatFromString(Index, P1[0]);
			}

			Dest.Float = (float)GetDistance3D(P1[0], P1[1], P1[2], P2[0], P2[1], P2[2]);
			return true;
		}
		return false;

	default: break;
	}

	return false;
}

