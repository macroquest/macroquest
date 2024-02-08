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
#include <string_view>

namespace mq::datatypes {

enum class MathMembers
{
	Abs = 1,
	Rand,
	Calc,
	Sin,
	Cos,
	Tan,
	Asin,
	Acos,
	Atan,
	Hex,
	Dec,
	Not,
	Distance,
	Sqrt,
	Clamp
};

MQ2MathType::MQ2MathType() : MQ2Type("math")
{
	ScopedTypeMember(MathMembers, Abs);
	ScopedTypeMember(MathMembers, Rand);
	ScopedTypeMember(MathMembers, Calc);
	ScopedTypeMember(MathMembers, Sin);
	ScopedTypeMember(MathMembers, Cos);
	ScopedTypeMember(MathMembers, Tan);
	ScopedTypeMember(MathMembers, Asin);
	ScopedTypeMember(MathMembers, Acos);
	ScopedTypeMember(MathMembers, Atan);
	ScopedTypeMember(MathMembers, Hex);
	ScopedTypeMember(MathMembers, Dec);
	ScopedTypeMember(MathMembers, Not);
	ScopedTypeMember(MathMembers, Distance);
	ScopedTypeMember(MathMembers, Sqrt);
	ScopedTypeMember(MathMembers, Clamp);
}

bool MQ2MathType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2MathType::FindMember(Member);
	if (!pMember)
		return false;

	if (!Index[0])
		return false;

	double CalcResult = 0;

	switch (static_cast<MathMembers>(pMember->ID))
	{
	case MathMembers::Abs:
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

	case MathMembers::Rand:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (char* Arg = Index)
		{
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

			if (Min > Max)
				return false;

			Dest.DWord = RangeRandom(Min, Max);
			return true;
		}
		return false;

	case MathMembers::Sqrt:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)sqrt(CalcResult);
			return true;
		}
		return false;

	case MathMembers::Calc:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)CalcResult;
			return true;
		}
		return false;

	case MathMembers::Sin:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)sin(CalcResult / DegToRad);
			return true;
		}
		return false;

	case MathMembers::Cos:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)cos(CalcResult / DegToRad);
			return true;
		}
		return false;

	case MathMembers::Tan:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)tan(CalcResult / DegToRad);
			return true;
		}
		return false;

	case MathMembers::Asin:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)(asin(CalcResult) * DegToRad);
			return true;
		}
		return false;

	case MathMembers::Acos:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)(acos(CalcResult) * DegToRad);
			return true;
		}
		return false;

	case MathMembers::Atan:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)(atan(CalcResult) * DegToRad);
			return true;
		}
		return false;

	case MathMembers::Not:
		Dest.DWord = ~GetIntFromString(Index, 0);
		Dest.Type = pIntType;
		return true;

	case MathMembers::Hex:
		sprintf_s(DataTypeTemp, "0x%X", GetIntFromString(Index, 0));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case MathMembers::Dec:
	{
		Dest.Type = pIntType;
		DWORD scan;
		if (sscanf_s(Index, "%x", &scan)) {
			Dest.DWord = scan;
			return true;
		}
		return false;
	}

	case MathMembers::Clamp:
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

	case MathMembers::Distance:
	{
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		// TODO: This code appears in LineOfSight function, possibly clean and combine
		auto cleaned_index = replace(Index, ",", " ");						// Replace commas with spaces
		if (cleaned_index.size() > 0)
		{
			//auto sv_index = std::string_view(cleaned_index);				// Create a view of cleaned index
			auto p_list = split_view(cleaned_index, ':', true);				// create a list of points, ignore empty

			float P[2][3];													// Create 2d array, [Loc][Dimension]
			P[0][0] = P[1][0] = pControlledPlayer->Y;
			P[0][1] = P[1][1] = pControlledPlayer->X;
			P[0][2] = P[1][2] = pControlledPlayer->Z;

			for (size_t i = 0; i < p_list.size() && i < 2; i++)				// for ever separate location
			{
				auto pointList = split_view(p_list[i], ' ', true);			// create a string view list of each float
				for (size_t j = 0; j < pointList.size() && j < 3; j++)		// for every string broken by spaces
				{
					P[i][j] = GetFloatFromString(pointList[j], P[i][j]);	// Convert jth float and store in ith array
				}
			}

			Dest.Float = (float)GetDistance3D(P[0][0], P[0][1], P[0][2], P[1][0], P[1][1], P[1][2]);  // parse distance from p[0] to p[1]
			return true;
		}
		return false;
	}
	default: break;
	}

	return false;
}

bool MQ2MathType::ToString(MQVarPtr VarPtr, char* Destination)
{
	return false;
}

bool MQ2MathType::dataMath(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = nullptr;
	Ret.Type = pMathType;
	return true;
}

} // namespace mq::datatypes
