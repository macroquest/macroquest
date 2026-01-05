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

#include "date/date.h"
#include "fmt/chrono.h"

namespace mq::datatypes {

//============================================================================

static bool IsFalsey(std::string_view var)
{
	return var.empty()
		|| ci_equals(var, "FALSE")
		|| ci_equals(var, "NULL")
		|| GetFloatFromString(var, 1) == 0;
}

// pure type, no members
bool MQ2BoolType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	return false;
}

bool MQ2BoolType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, VarPtr.Get<bool>() ? "TRUE" : "FALSE");
	return true;
}

bool MQ2BoolType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	VarPtr.Set(Source.Get<bool>());
	return true;
}

bool MQ2BoolType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.Set(!IsFalsey(Source));
	return true;
}

bool MQ2BoolType::dataBool(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	Ret.Type = pBoolType;
	Ret.Set(!IsFalsey(szIndex));
	return true;
}

//============================================================================

enum class IntMembers
{
	Float = 1,
	Double,
	Hex,
	Reverse,
	LowPart,
	HighPart,
	Prettify,
};

MQ2IntType::MQ2IntType() : MQ2Type("int")
{
	ScopedTypeMember(IntMembers, Float);
	ScopedTypeMember(IntMembers, Double);
	ScopedTypeMember(IntMembers, Hex);
	ScopedTypeMember(IntMembers, Reverse);
	ScopedTypeMember(IntMembers, LowPart);
	ScopedTypeMember(IntMembers, HighPart);
	ScopedTypeMember(IntMembers, Prettify);
}

bool MQ2IntType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2IntType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<IntMembers>(pMember->ID))
	{
	case IntMembers::Float:
		Dest.Float = static_cast<float>(VarPtr.Int);
		Dest.Type = pFloatType;
		return true;

	case IntMembers::Double:
		Dest.Double = static_cast<double>(VarPtr.Int);
		Dest.Type = pDoubleType;
		return true;

	case IntMembers::Hex:
		sprintf_s(DataTypeTemp, "0x%X", VarPtr.Int);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case IntMembers::Reverse:
		Dest.Int = _byteswap_ulong(VarPtr.Int);
		Dest.Type = pIntType;
		return true;

	case IntMembers::LowPart:
		Dest.DWord = LOWORD(VarPtr.DWord);
		Dest.Type = pIntType;
		return true;

	case IntMembers::HighPart:
		Dest.DWord = HIWORD(VarPtr.DWord);
		Dest.Type = pIntType;
		return true;

	case IntMembers::Prettify:
		sprintf_s(DataTypeTemp, "%d", VarPtr.Int);
		PrettifyNumber(DataTypeTemp, DataTypeTemp.size(), GetIntFromString(Index, 0));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default:
		return false;
	}
}

bool MQ2IntType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, std::to_string(VarPtr.Int).c_str());
	return true;
}

bool MQ2IntType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	VarPtr.Int = Source.Int;
	return true;
}

bool MQ2IntType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.Int = static_cast<int>(GetInt64FromString(Source, 0));
	return true;
}

bool MQ2IntType::dataInt(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	Ret.DWord = static_cast<int>(GetInt64FromString(szIndex, 0));
	Ret.Type = pIntType;
	return true;
}

//============================================================================

enum class Int64Members
{
	Float = 1,
	Double,
	Hex,
	Reverse,
	LowPart,
	HighPart,
	Prettify,
};

MQ2Int64Type::MQ2Int64Type() : MQ2Type("int64")
{
	ScopedTypeMember(Int64Members, Float);
	ScopedTypeMember(Int64Members, Double);
	ScopedTypeMember(Int64Members, Hex);
	ScopedTypeMember(Int64Members, Reverse);
	ScopedTypeMember(Int64Members, LowPart);
	ScopedTypeMember(Int64Members, HighPart);
	ScopedTypeMember(Int64Members, Prettify);
}

bool MQ2Int64Type::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2Int64Type::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<Int64Members>(pMember->ID))
	{
	case Int64Members::Float:
		Dest.Float = (float)1.0f * (VarPtr.Int64);
		Dest.Type = pFloatType;
		return true;

	case Int64Members::Double:
		Dest.Double = (double)1.0f * (VarPtr.Int64);
		Dest.Type = pDoubleType;
		return true;

	case Int64Members::Hex:
		sprintf_s(DataTypeTemp, "0x%llX", VarPtr.Int64);
		Dest.Ptr = &DataTypeTemp[0],
			Dest.Type = pStringType;
		return true;

	case Int64Members::Reverse:
		Dest.Int64 = _byteswap_uint64(VarPtr.Int64);
		Dest.Type = pInt64Type;
		return true;

	case Int64Members::LowPart:
		Dest.DWord = VarPtr.LowPart;
		Dest.Type = pIntType;
		return true;

	case Int64Members::HighPart:
		Dest.DWord = VarPtr.HighPart;
		Dest.Type = pIntType;
		return true;

	case Int64Members::Prettify:
		sprintf_s(DataTypeTemp, "%lld", VarPtr.Int64);
		PrettifyNumber(DataTypeTemp, DataTypeTemp.size(), GetIntFromString(Index, 0));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default:
		return false;
	}
}

bool MQ2Int64Type::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, std::to_string(VarPtr.Int64).c_str());
	return true;
}

bool MQ2Int64Type::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	VarPtr.Int64 = Source.Int64;
	return true;
}

bool MQ2Int64Type::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.Int64 = GetInt64FromString(Source, -1);
	return true;
}

//============================================================================

enum class ArgbMembers
{
	A = 0,
	R = 1,
	G = 2,
	B = 3,
	Int = 4,
};

MQ2ArgbType::MQ2ArgbType() : MQ2Type("argb")
{
	ScopedTypeMember(ArgbMembers, A);
	ScopedTypeMember(ArgbMembers, R);
	ScopedTypeMember(ArgbMembers, G);
	ScopedTypeMember(ArgbMembers, B);
	ScopedTypeMember(ArgbMembers, Int);
}

bool MQ2ArgbType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ArgbMembers>(pMember->ID))
	{
	case ArgbMembers::A:
		Dest.DWord = VarPtr.Argb.A;
		Dest.Type = pIntType;
		return true;

	case ArgbMembers::R:
		Dest.DWord = VarPtr.Argb.R;
		Dest.Type = pIntType;
		return true;

	case ArgbMembers::G:
		Dest.DWord = VarPtr.Argb.G;
		Dest.Type = pIntType;
		return true;

	case ArgbMembers::B:
		Dest.DWord = VarPtr.Argb.B;
		Dest.Type = pIntType;
		return true;

	case ArgbMembers::Int:
		Dest.DWord = VarPtr.DWord;
		Dest.Type = pIntType;
		return true;
	}

	return false;
}

bool MQ2ArgbType::ToString(MQVarPtr VarPtr, char* Destination)
{
	sprintf_s(Destination, MAX_STRING, "%x", VarPtr.Int);
	return true;
}

bool MQ2ArgbType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	VarPtr.DWord = Source.DWord;
	return true;
}

bool MQ2ArgbType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	ARGBCOLOR input;
	if (sscanf_s(Source, "%x", &input.ARGB))
	{
		VarPtr.Argb = input;
		return true;
	}

	return false;
}

//============================================================================

MQ2ByteType::MQ2ByteType() : MQ2Type("byte")
{
}

bool MQ2ByteType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	return false;
}

bool MQ2ByteType::ToString(MQVarPtr VarPtr, char* Destination)
{
	_itoa_s(VarPtr.Int, Destination, MAX_STRING, 10);
	return true;
}

bool MQ2ByteType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	VarPtr.DWord = Source.DWord & 0xFF;
	return true;
}

bool MQ2ByteType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.DWord = GetIntFromString(Source, 0) & 0xFF;
	return true;
}

//============================================================================

enum class StringMembers
{
	Arg,
	Mid,
	Left,
	Right,
	Find,
	Length,
	Upper,
	Lower,
	Compare,
	CompareCS,
	Equal,
	NotEqual,
	EqualCS,
	NotEqualCS,
	Count,
	Token,
	Replace,
	StripLinks,
};

MQ2StringType::MQ2StringType() : MQ2Type("string")
{
	ScopedTypeMember(StringMembers, Arg);
	ScopedTypeMember(StringMembers, Mid);
	ScopedTypeMember(StringMembers, Left);
	ScopedTypeMember(StringMembers, Right);
	ScopedTypeMember(StringMembers, Find);
	ScopedTypeMember(StringMembers, Length);
	ScopedTypeMember(StringMembers, Upper);
	ScopedTypeMember(StringMembers, Lower);
	ScopedTypeMember(StringMembers, Compare);
	ScopedTypeMember(StringMembers, CompareCS);
	ScopedTypeMember(StringMembers, Equal);
	ScopedTypeMember(StringMembers, NotEqual);
	ScopedTypeMember(StringMembers, EqualCS);
	ScopedTypeMember(StringMembers, NotEqualCS);
	ScopedTypeMember(StringMembers, Count);
	ScopedTypeMember(StringMembers, Token);
	ScopedTypeMember(StringMembers, Replace);
	ScopedTypeMember(StringMembers, StripLinks);
}

bool MQ2StringType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	const char* szString = static_cast<const char*>(VarPtr.Ptr);
	if (!szString)
		return false;

	MQTypeMember* pMember = MQ2StringType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<StringMembers>(pMember->ID))
	{
	case StringMembers::Length:
		Dest.DWord = static_cast<uint32_t>(strlen(szString));
		Dest.Type = pIntType;
		return true;

	case StringMembers::Left:
		Dest.Type = pStringType;

		if (!Index[0])
			return false;

		{
			size_t StrLen = strlen(szString);

			int Len = GetIntFromString(Index, 0);
			if (Len == 0)
				return false;

			if (Len > MAX_STRING - 1)
				Len = MAX_STRING - 1;

			if (Len > 0)
			{
				if (static_cast<size_t>(Len) > StrLen)
					Len = static_cast<int>(StrLen);

				memmove(DataTypeTemp, szString, Len);

				DataTypeTemp[Len] = 0;
				Dest.Ptr = &DataTypeTemp[0];
			}
			else
			{
				Len = -Len;

				if (static_cast<size_t>(Len) > StrLen)
				{
					strcpy_s(DataTypeTemp, "");
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}

				memmove(DataTypeTemp, szString, StrLen - Len);
				DataTypeTemp[StrLen - Len] = 0;
				Dest.Ptr = &DataTypeTemp[0];
			}
		}
		return true;

	case StringMembers::Right:
		Dest.Type = pStringType;

		if (!Index[0])
			return false;

		{
			size_t StrLen = strlen(szString);
			const char* pStart = szString;

			int Len = GetIntFromString(Index, 0);

			if (Len == 0)
				return false;

			if (Len < 0)
			{
				Len = -Len;

				if (static_cast<size_t>(Len) >= StrLen)
				{
					strcpy_s(DataTypeTemp, "");
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}

				pStart = &pStart[Len];
				Len = static_cast<int>(StrLen) - Len;

				memmove(DataTypeTemp, pStart, Len + 1);
				Dest.Ptr = &DataTypeTemp[0];
			}
			else
			{
				pStart = &pStart[strlen(pStart) - Len];

				if (pStart < szString)
					pStart = szString;

				memmove(DataTypeTemp, pStart, Len + 1);
				Dest.Ptr = &DataTypeTemp[0];
			}
		}
		return true;

	case StringMembers::Find: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		int pos = ci_find_substr(szString, Index);
		if (pos != -1)
		{
			Dest.DWord = pos + 1;
			return true;
		}

		return false;
	}

	case StringMembers::Replace: {
		Dest.Type = pStringType;

		if (!Index[0])
			return false;

		if (char* pComma = strchr(Index, ','))
		{
			// TODO: This could be optimized to reduce copies and side effects
			std::string subject = szString;

			*pComma = 0;
			const std::string search = (char*)Index;
			*pComma = ',';

			const std::string replace = (char*)&pComma[1];

			if (subject.empty() || search.empty())
				return false;

			size_t pos = 0;

			while ((pos = subject.find(search, pos)) != std::string::npos)
			{
				subject.replace(pos, search.length(), replace);
				pos += replace.length();
			}

			strcpy_s(DataTypeTemp, subject.c_str());

			void* x = Dest.Ptr = DataTypeTemp;

			if (Dest.Ptr = DataTypeTemp)
			{
				return true;
			}
		}

		return false;
	}

	case StringMembers::Upper:
		strcpy_s(DataTypeTemp, szString);
		_strupr_s(DataTypeTemp);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case StringMembers::Lower:
		strcpy_s(DataTypeTemp, szString);
		_strlwr_s(DataTypeTemp);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case StringMembers::Compare:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (Index[0])
		{
			Dest.Int = _stricmp(szString, Index);
			return true;
		}
		return false;

	case StringMembers::CompareCS:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (Index[0])
		{
			Dest.Int = strcmp(szString, Index);
			return true;
		}
		return false;

	case StringMembers::Mid:
		Dest.Type = pStringType;
		if (char* pComma = strchr(Index, ','))
		{
			*pComma = 0;
			pComma++;

			const char* pStr = szString;
			int nStart = GetIntFromString(Index, 0) - 1;
			if (nStart < 0)
			{
				nStart = 0;
			}

			int StrLen = static_cast<int>(strlen(pStr));
			int Len = GetIntFromString(pComma, StrLen);

			if (nStart >= StrLen)
			{
				strcpy_s(DataTypeTemp, "");
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}

			pStr += nStart;

			if (Len > StrLen || Len < 0)
			{
				Len = StrLen;
			}

			memmove(DataTypeTemp, pStr, Len);
			DataTypeTemp[Len] = '\0';
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case StringMembers::Equal:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (Index[0])
		{
			Dest.Set(_stricmp(szString, Index) == 0);
			return true;
		}
		return false;

	case StringMembers::NotEqual:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (Index[0])
		{
			Dest.Set(_stricmp(szString, Index) != 0);
			return true;
		}
		return false;

	case StringMembers::EqualCS:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (Index[0])
		{
			Dest.Set(strcmp(szString, Index) == 0);
			return true;
		}
		return false;

	case StringMembers::NotEqualCS:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (Index[0])
		{
			Dest.Set(strcmp(szString, Index) != 0);
			return true;
		}
		return false;

	case StringMembers::Count:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (Index[0])
		{
			Dest.DWord = 0;
			const char* pLast = szString - 1;

			while (pLast = strchr(&pLast[1], Index[0]))
				Dest.DWord++;

			return true;
		}
		return false;

	case StringMembers::Arg:
		Dest.Type = pStringType;

		if (IsNumberToComma(Index))
		{
			char Temp[MAX_STRING] = { 0 };
			strcpy_s(Temp, szString);

			if (char* pComma = strchr(Index, ','))
			{
				*pComma = 0;
				GetArg(DataTypeTemp, Temp, GetIntFromString(Index, 0), false, false, false, pComma[1]);
				*pComma = ',';

				if (DataTypeTemp[0])
				{
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
			else
			{
				GetArg(DataTypeTemp, Temp, GetIntFromString(Index, 0));

				if (DataTypeTemp[0])
				{
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
		}
		return false;

	case StringMembers::Token:
		Dest.Type = pStringType;
		if (IsNumberToComma(Index))
		{
			size_t index = GetIntFromString(Index, 0);
			if (!index)
				return false;

			if (char* pComma = strchr(Index, ','))
			{
				const char* pPos = szString;
				*pComma = 0;
				index--;

				while (index && pPos)
				{
					pPos = strchr(&pPos[1], pComma[1]);
					index--;
				}

				*pComma = ',';

				if (pPos)
				{
					if (pPos != (char*)VarPtr.Ptr)
						pPos++;

					const char* pEnd = strchr(&pPos[0], pComma[1]);

					if (pEnd)
					{
						if (pEnd != pPos)
						{
							strncpy_s(DataTypeTemp, pPos, pEnd - pPos);
							DataTypeTemp[pEnd - pPos] = 0;
						}
						else
							DataTypeTemp[0] = 0;
					}
					else
						strcpy_s(DataTypeTemp, pPos);

					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
		}
		return false;

	case StringMembers::StripLinks:
		Dest.Type = pStringType;
		strcpy_s(DataTypeTemp, CleanItemTags(szString).c_str());
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	default:
		return false;
	}
}

bool MQ2StringType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (VarPtr.Ptr)
	{
		strcpy_s(Destination, MAX_STRING, static_cast<const char*>(VarPtr.Ptr));
		return true;
	}
	return false;
}

void MQ2StringType::InitVariable(MQVarPtr& VarPtr)
{
	VarPtr.Ptr = LocalAlloc(LPTR, MAX_STRING);
}

void MQ2StringType::FreeVariable(MQVarPtr& VarPtr)
{
	LocalFree(VarPtr.Ptr);
}

bool MQ2StringType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pStringType)
		return false;

	strcpy_s(static_cast<char*>(VarPtr.Ptr), MAX_STRING, static_cast<const char*>(Source.Ptr));
	return true;
}

bool MQ2StringType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	strcpy_s(static_cast<char*>(VarPtr.Ptr), MAX_STRING, Source);
	return true;
}

bool MQ2StringType::dataString(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex)
		return false;

	strcpy_s(DataTypeTemp, szIndex);
	Ret.Ptr = &DataTypeTemp[0];
	Ret.Type = pStringType;
	return true;
}

//============================================================================

enum class FloatMembers
{
	Deci = 1,
	Centi,
	Milli,
	Int,
	Precision,
	Raw,
	Prettify,
};

MQ2FloatType::MQ2FloatType() : MQ2Type("float")
{
	ScopedTypeMember(FloatMembers, Deci);
	ScopedTypeMember(FloatMembers, Centi);
	ScopedTypeMember(FloatMembers, Milli);
	ScopedTypeMember(FloatMembers, Int);
	ScopedTypeMember(FloatMembers, Precision);
	ScopedTypeMember(FloatMembers, Raw);
	ScopedTypeMember(FloatMembers, Prettify);
}

bool MQ2FloatType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2FloatType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<FloatMembers>(pMember->ID))
	{
	case FloatMembers::Deci:
		sprintf_s(DataTypeTemp, "%.1f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case FloatMembers::Centi:
		sprintf_s(DataTypeTemp, "%.2f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case FloatMembers::Milli:
		sprintf_s(DataTypeTemp, "%.3f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case FloatMembers::Int:
		Dest.Type = pIntType;
		Dest.Int = (int)(VarPtr.Float);
		return true;

	case FloatMembers::Precision:
		Dest.Type = pStringType;
		if (IsNumber(Index))
		{
			sprintf_s(DataTypeTemp, "%.*f", GetIntFromString(Index, 3), VarPtr.Float);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case FloatMembers::Raw:
		Dest.Type = pIntType;
		Dest.DWord = VarPtr.DWord;
		return true;

	case FloatMembers::Prettify:
		sprintf_s(DataTypeTemp, "%lld", VarPtr.Int64);
		PrettifyNumber(DataTypeTemp, DataTypeTemp.size(), GetIntFromString(Index, 2));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2FloatType::ToString(MQVarPtr VarPtr, char* Destination)
{
	sprintf_s(Destination, MAX_STRING, "%.2f", VarPtr.Float);
	return true;
}

bool MQ2FloatType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pFloatType && Source.Type != pHeadingType)
		VarPtr.Float = (float)Source.DWord;
	else
		VarPtr.Float = Source.Float;
	return true;
}

bool MQ2FloatType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.Float = GetFloatFromString(Source, 0);
	return true;
}

bool MQ2FloatType::dataFloat(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	Ret.Float = GetFloatFromString(szIndex, 0);
	Ret.Type = pFloatType;
	return true;
}

//============================================================================

enum class DoubleMembers
{
	Deci = 1,
	Centi,
	Milli,
	Int,
	Precision,
	Prettify,
};

MQ2DoubleType::MQ2DoubleType() : MQ2Type("double")
{
	ScopedTypeMember(DoubleMembers, Deci);
	ScopedTypeMember(DoubleMembers, Centi);
	ScopedTypeMember(DoubleMembers, Milli);
	ScopedTypeMember(DoubleMembers, Int);
	ScopedTypeMember(DoubleMembers, Precision);
	ScopedTypeMember(DoubleMembers, Prettify);
}

bool MQ2DoubleType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2DoubleType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<DoubleMembers>(pMember->ID))
	{
	case DoubleMembers::Deci:
		sprintf_s(DataTypeTemp, "%.1f", VarPtr.Double);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case DoubleMembers::Centi:
		sprintf_s(DataTypeTemp, "%.2f", VarPtr.Double);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case DoubleMembers::Milli:
		sprintf_s(DataTypeTemp, "%.3f", VarPtr.Double);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case DoubleMembers::Int:
		Dest.Type = pIntType;
		Dest.Int = (int)(VarPtr.Double);
		return true;

	case DoubleMembers::Precision:
		Dest.Type = pStringType;
		if (IsNumber(Index))
		{
			sprintf_s(DataTypeTemp, "%.*f", GetIntFromString(Index, 3), VarPtr.Double);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case DoubleMembers::Prettify:
		sprintf_s(DataTypeTemp, "%lld", VarPtr.Int64);
		PrettifyNumber(DataTypeTemp, DataTypeTemp.size(), GetIntFromString(Index, 2));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2DoubleType::ToString(MQVarPtr VarPtr, char* Destination)
{
	sprintf_s(Destination, MAX_STRING, "%.2f", VarPtr.Double);
	return true;
}

bool MQ2DoubleType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pDoubleType && Source.Type != pHeadingType)
		VarPtr.Double = Source.Double;
	else
		VarPtr.Double = Source.Double;
	return true;
}

bool MQ2DoubleType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.Double = GetDoubleFromString(Source, 0);
	return true;
}

//============================================================================

enum class TicksMembers
{
	Hours,
	Minutes,
	Seconds,
	Time,
	TotalMinutes,
	TotalSeconds,
	Ticks,
	TimeHMS,
};

MQ2TicksType::MQ2TicksType() : MQ2Type("ticks")
{
	ScopedTypeMember(TicksMembers, Hours);
	ScopedTypeMember(TicksMembers, Minutes);
	ScopedTypeMember(TicksMembers, Seconds);
	ScopedTypeMember(TicksMembers, Time);
	ScopedTypeMember(TicksMembers, TotalMinutes);
	ScopedTypeMember(TicksMembers, TotalSeconds);
	ScopedTypeMember(TicksMembers, Ticks);
	ScopedTypeMember(TicksMembers, TimeHMS);
}

bool MQ2TicksType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	uint32_t nTicks = VarPtr.DWord;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TicksMembers>(pMember->ID))
	{
	case TicksMembers::Hours:
		Dest.DWord = nTicks / 600;
		Dest.Type = pIntType;
		return true;

	case TicksMembers::Minutes:
		Dest.DWord = (nTicks / 10) % 60;
		Dest.Type = pIntType;
		return true;

	case TicksMembers::Seconds:
		Dest.DWord = (nTicks * 6) % 60;
		Dest.Type = pIntType;
		return true;

	case TicksMembers::TimeHMS: {
		Dest.Type = pStringType;
		int Secs = nTicks * 6;
		int Mins = (Secs / 60) % 60;
		int Hrs = (Secs / 3600);
		Secs = Secs % 60;
		if (Secs < 0)
			sprintf_s(DataTypeTemp, "Perm");
		else if (Hrs)
			sprintf_s(DataTypeTemp, "%d:%02d:%02d", Hrs, Mins, Secs);
		else
			sprintf_s(DataTypeTemp, "%d:%02d", Mins, Secs);
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case TicksMembers::Time: {
		Dest.Type = pStringType;
		int Secs = nTicks * 6;
		int Mins = (Secs / 60);
		Secs = Secs % 60;
		if (Secs < 0)
			sprintf_s(DataTypeTemp, "Perm");
		else
			sprintf_s(DataTypeTemp, "%d:%02d", Mins, Secs);
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case TicksMembers::TotalMinutes:
		Dest.DWord = nTicks / 10;
		Dest.Type = pIntType;
		return true;

	case TicksMembers::TotalSeconds:
		Dest.DWord = nTicks * 6;
		Dest.Type = pIntType;
		return true;

	case TicksMembers::Ticks:
		Dest.DWord = nTicks;
		Dest.Type = pIntType;
		return true;
	}

	return false;
}

bool MQ2TicksType::ToString(MQVarPtr VarPtr, char* Destination)
{
	_itoa_s(VarPtr.DWord, Destination, MAX_STRING, 10);
	return true;
}
bool MQ2TicksType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	VarPtr.DWord = Source.DWord;
	return true;
}
bool MQ2TicksType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.DWord = GetIntFromString(Source, 0);
	return true;
}

//============================================================================

enum class TimeStampMembers
{
	Days,
	Hours,
	Minutes,
	Seconds,
	Time,
	TotalMinutes,
	TotalSeconds,
	Raw,
	Ticks,
	TimeHMS,
	TimeDHM,
	Float,
};

MQ2TimeStampType::MQ2TimeStampType() : MQ2Type("timestamp")
{
	ScopedTypeMember(TimeStampMembers, Days);
	ScopedTypeMember(TimeStampMembers, Hours);
	ScopedTypeMember(TimeStampMembers, Minutes);
	ScopedTypeMember(TimeStampMembers, Seconds);
	ScopedTypeMember(TimeStampMembers, Time);
	ScopedTypeMember(TimeStampMembers, TotalMinutes);
	ScopedTypeMember(TimeStampMembers, TotalSeconds);
	ScopedTypeMember(TimeStampMembers, Raw);
	ScopedTypeMember(TimeStampMembers, Ticks);
	ScopedTypeMember(TimeStampMembers, TimeHMS);
	ScopedTypeMember(TimeStampMembers, TimeDHM);
	ScopedTypeMember(TimeStampMembers, Float);
}

bool MQ2TimeStampType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	uint64_t nTimeStamp = VarPtr.UInt64;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TimeStampMembers>(pMember->ID))
	{
	case TimeStampMembers::Days:
		Dest.DWord = (uint32_t)((nTimeStamp / 1000) / 3600) / 24;
		Dest.Type = pIntType;
		return true;

	case TimeStampMembers::Hours:
		Dest.UInt64 = (nTimeStamp / 1000) / 3600;
		Dest.Type = pInt64Type;
		return true;

	case TimeStampMembers::Minutes:
		Dest.UInt64 = ((nTimeStamp / 1000) / 60) % 60;
		Dest.Type = pInt64Type;
		return true;

	case TimeStampMembers::Seconds:
		Dest.UInt64 = (nTimeStamp / 1000) % 60;
		Dest.Type = pInt64Type;
		return true;

	case TimeStampMembers::TimeHMS: {
		Dest.Type = pStringType;
		uint64_t Secs = nTimeStamp / 1000;
		uint64_t Mins = (Secs / 60) % 60;
		uint64_t Hrs = (Secs / 3600);

		Secs = Secs % 60;
		if (Hrs)
			sprintf_s(DataTypeTemp, "%d:%02u:%02u", (unsigned int)Hrs, (unsigned int)Mins, (unsigned int)Secs);
		else
			sprintf_s(DataTypeTemp, "%d:%02u", (unsigned int)Mins, (unsigned int)Secs);
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case TimeStampMembers::TimeDHM: {
		Dest.Type = pStringType;
		uint64_t Secs = nTimeStamp / 1000;
		uint64_t Mins = (Secs / 60) % 60;
		uint64_t Hours = (Secs / 3600) % 24;
		uint64_t Days = (Secs / 86400);

		if (Days)
			sprintf_s(DataTypeTemp, "%d:%02u:%02u", (unsigned int)Days, (unsigned int)Hours, (unsigned int)Mins);
		else
			sprintf_s(DataTypeTemp, "%d:%02u",  (unsigned int)Hours, (unsigned int)Mins);

		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case TimeStampMembers::Time: {
		Dest.Type = pStringType;
		uint64_t Secs = nTimeStamp / 1000;
		uint64_t Mins = Secs / 60;
		Secs = Secs % 60;
		if (Secs < 0)
			sprintf_s(DataTypeTemp, "Perm");
		else
			sprintf_s(DataTypeTemp, "%d:%02u", (unsigned int)Mins, (unsigned int)Secs);
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case TimeStampMembers::TotalMinutes:
		Dest.UInt64 = (nTimeStamp / 1000) / 60;
		Dest.Type = pInt64Type;
		return true;

	case TimeStampMembers::TotalSeconds:
		Dest.UInt64 = nTimeStamp / 1000;
		Dest.Type = pInt64Type;
		return true;

	case TimeStampMembers::Raw:
		Dest.UInt64 = nTimeStamp;
		Dest.Type = pInt64Type;
		return true;

	case TimeStampMembers::Float:
		Dest.Float = (float)nTimeStamp / 1000;
		Dest.Type = pFloatType;
		return true;

	case TimeStampMembers::Ticks:
		Dest.UInt64 = ((nTimeStamp / 1000) + 5) / 6;
		Dest.Type = pInt64Type;
		return true;
	}

	return false;
}

bool MQ2TimeStampType::ToString(MQVarPtr VarPtr, char* Destination)
{
	_i64toa_s(VarPtr.UInt64, Destination, MAX_STRING, 10);
	return true;
}

bool MQ2TimeStampType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	VarPtr.UInt64 = Source.UInt64;
	return true;
}

bool MQ2TimeStampType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.UInt64 = _atoi64(Source);
	return true;
}

//============================================================================

enum class ArrayMembers
{
	Dimensions = 1,
	Size = 2,
};

MQ2ArrayType::MQ2ArrayType() : MQ2Type("array")
{
	ScopedTypeMember(ArrayMembers, Dimensions);
	ScopedTypeMember(ArrayMembers, Size);
}

bool MQ2ArrayType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	auto pArray = VarPtr.Get<CDataArray>();
	if (!pArray)
		return false;

	MQTypeMember* pMember = MQ2ArrayType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ArrayMembers>(pMember->ID))
	{
	case ArrayMembers::Dimensions:
		Dest.DWord = pArray->GetNumExtents();
		Dest.Type = pIntType;
		return true;

	case ArrayMembers::Size:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (Index[0])
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index < 0)
				return false;
			if (index < pArray->GetNumExtents())
			{
				Dest.DWord = pArray->GetExtents(index);
				return true;
			}
		}
		else
		{
			Dest.DWord = pArray->GetTotalElements();
			return true;
		}
		return false;

	default: break;
	}

	return false;
}

//============================================================================

enum class RangeMembers
{
	Between = 1,
	Inside = 2,
};

MQ2RangeType::MQ2RangeType() : MQ2Type("Range")
{
	ScopedTypeMember(RangeMembers, Between);
	ScopedTypeMember(RangeMembers, Inside);
}

bool MQ2RangeType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
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
	case RangeMembers::Inside:
		Dest.Set(false);
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
						Dest.Set(true);
						return true;
					}
				}
			}
		}
		return true;

	case RangeMembers::Between:
		Dest.Set(false);
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
						Dest.Set(true);
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

bool MQ2RangeType::ToString(MQVarPtr VarPtr, char* Destination)
{
	return false;
}

bool MQ2RangeType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pRangeType)
		return false;

	VarPtr.Ptr = Source.Ptr;
	return true;
}

bool MQ2RangeType::dataRange(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 1;
	Ret.Type = pRangeType;
	return true;
}

//============================================================================

enum class TypeMembers
{
	Name,
	Member,
	InheritedType,
};

MQ2TypeType::MQ2TypeType() : MQ2Type("type")
{
	ScopedTypeMember(TypeMembers, Name);
	ScopedTypeMember(TypeMembers, Member);
	ScopedTypeMember(TypeMembers, InheritedType);
}

bool MQ2TypeType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQ2Type* pType = static_cast<MQ2Type*>(VarPtr.Ptr);
	if (!pType)
		return false;

	MQTypeMember* pMember = MQ2TypeType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TypeMembers>(pMember->ID))
	{
	case TypeMembers::Name:
		strcpy_s(DataTypeTemp, pType->GetName());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case TypeMembers::Member:
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// name by number
			if (Dest.Ptr = (void*)pType->GetMemberName(GetIntFromString(Index, 0)))
			{
				Dest.Type = pStringType;
				return true;
			}
		}
		else
		{
			// number by name
			int memberID;
			if (pType->GetMemberID(Index, memberID))
			{
				Dest.Type = pIntType;
				Dest.Int = memberID;
				return true;
			}
		}

		return false;

	case TypeMembers::InheritedType:
		if (pType->GetParent())
		{
			Dest.Type = pTypeType;
			Dest.Ptr = pType->GetParent();
			return true;
		}
		return false;

	default: break;
	}

	return false;
}

bool MQ2TypeType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, ((MQ2Type*)VarPtr.Ptr)->GetName());
	return true;
}
bool MQ2TypeType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	VarPtr.Ptr = Source.Type;
	return true;
}

bool MQ2TypeType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	if (VarPtr.Ptr = pDataAPI->FindDataType(Source))
		return true;

	return false;
}

bool MQ2TypeType::dataType(const char* szIndex, MQTypeVar& Ret)
{
	if (MQ2Type* pType = pDataAPI->FindDataType(szIndex))
	{
		Ret.Ptr = pType;
		Ret.Type = datatypes::pTypeType;
		return true;
	}

	return false;
}

//============================================================================

using TimePointType = date::local_time<std::chrono::system_clock::duration>;

struct TimeTypeData
{
	TimePointType timePoint;
	int dayOfWeek = -1;
};

enum class TimeMembers
{
	Hour,
	Minute,
	Second,
	Millisecond,
	DayOfWeek,
	Day,
	Month,
	Year,
	Time12,
	Time24,
	Date,
	Night,
	SecondsSinceMidnight,
	MillisecondsSinceMidnight,
	Hour12,
	MillisecondsSinceEpoch,
	Format,
};

MQ2TimeType::MQ2TimeType() : MQ2Type("time")
{
	ScopedTypeMember(TimeMembers, Hour);
	ScopedTypeMember(TimeMembers, Minute);
	ScopedTypeMember(TimeMembers, Second);
	ScopedTypeMember(TimeMembers, Millisecond);
	ScopedTypeMember(TimeMembers, DayOfWeek);
	ScopedTypeMember(TimeMembers, Day);
	ScopedTypeMember(TimeMembers, Month);
	ScopedTypeMember(TimeMembers, Year);
	ScopedTypeMember(TimeMembers, Time12);
	ScopedTypeMember(TimeMembers, Time24);
	ScopedTypeMember(TimeMembers, Date);
	ScopedTypeMember(TimeMembers, Night);
	ScopedTypeMember(TimeMembers, SecondsSinceMidnight);
	ScopedTypeMember(TimeMembers, MillisecondsSinceMidnight);
	ScopedTypeMember(TimeMembers, Hour12);
	ScopedTypeMember(TimeMembers, MillisecondsSinceEpoch);
	ScopedTypeMember(TimeMembers, Format);
}

bool MQ2TimeType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	auto pTimePoint = VarPtr.Get<TimeTypeData>();
	if (!pTimePoint)
		return false;

	MQTypeMember* pMember = MQ2TimeType::FindMember(Member);
	if (!pMember)
		return false;

	auto days = date::floor<date::days>(pTimePoint->timePoint);
	auto ymd = date::year_month_day{ days };
	auto time = date::make_time(pTimePoint->timePoint - days);

	switch (static_cast<TimeMembers>(pMember->ID))
	{
	case TimeMembers::Hour:
		Dest.DWord = time.hours().count();
		Dest.Type = pIntType;
		return true;

	case TimeMembers::Hour12: {
		uint32_t Hour = date::make12(time.hours()).count();

		sprintf_s(DataTypeTemp, "%d %s", Hour, time.hours().count() > 11 ? "PM" : "AM");
		Dest.Ptr = &DataTypeTemp[0],
			Dest.Type = pStringType;

		return true;
	}

	case TimeMembers::Minute:
		Dest.Int = (int)time.minutes().count();
		Dest.Type = pIntType;
		return true;

	case TimeMembers::Second:
		Dest.Int = (int)time.seconds().count();
		Dest.Type = pIntType;
		return true;

	case TimeMembers::Millisecond:
		Dest.Int = (int)std::chrono::duration_cast<std::chrono::milliseconds>(time.subseconds()).count();
		Dest.Type = pIntType;
		return true;

	case TimeMembers::DayOfWeek:
		if (pTimePoint->dayOfWeek != -1)
			Dest.DWord = pTimePoint->dayOfWeek + 1;
		else
			Dest.DWord = date::year_month_weekday{ days }.weekday().c_encoding() + 1;
		Dest.Type = pIntType;
		return true;

	case TimeMembers::Day:
		Dest.DWord = (unsigned)ymd.day();
		Dest.Type = pIntType;
		return true;

	case TimeMembers::Month:
		Dest.DWord = (unsigned)ymd.month();
		Dest.Type = pIntType;
		return true;

	case TimeMembers::Year:
		Dest.Int = (int)ymd.year();
		Dest.Type = pIntType;
		return true;

	case TimeMembers::Time12: {
		sprintf_s(DataTypeTemp, "%02d:%02d:%02d",
			(int)date::make12(time.hours()).count(), (int)time.minutes().count(), (int)time.seconds().count());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	case TimeMembers::Time24:
		sprintf_s(DataTypeTemp, "%02d:%02d:%02d",
			(int)time.hours().count(), (int)time.minutes().count(), (int)time.seconds().count());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case TimeMembers::Date:
		sprintf_s(DataTypeTemp, "%02d/%02d/%04d", (unsigned)ymd.month(), (unsigned)ymd.day(), (int)ymd.year());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case TimeMembers::Night: {
		uint32_t Hour = time.hours().count();
		Dest.Set(Hour >= 19 || Hour < 5); // [7pm, 5am)
		Dest.Type = pBoolType;
		return true;
	}

	case TimeMembers::SecondsSinceMidnight:
		Dest.Int = (int)std::chrono::duration_cast<std::chrono::seconds>(time.to_duration()).count();
		Dest.Type = pIntType;
		return true;

	case TimeMembers::MillisecondsSinceMidnight:
		Dest.Int = (int)std::chrono::duration_cast<std::chrono::milliseconds>(time.to_duration()).count();
		Dest.Type = pIntType;
		return true;

	case TimeMembers::MillisecondsSinceEpoch:
		Dest.Int64 = std::chrono::duration_cast<std::chrono::milliseconds>(pTimePoint->timePoint.time_since_epoch()).count();
		Dest.Type = pInt64Type;
		return true;

	case TimeMembers::Format: {
		if (!Index[0])
			return false;

		try
		{
			std::time_t time_val{ std::chrono::duration_cast<std::chrono::seconds>(pTimePoint->timePoint.time_since_epoch()).count() };
			std::tm tm;
			gmtime_s(&tm, &time_val);

			fmt::memory_buffer format_buffer;

			sprintf_s(DataTypeTemp, MAX_STRING, "{:%s}", Index);
			const char* format_string = &DataTypeTemp[0];
			fmt::format_to(fmt::appender(format_buffer), fmt::runtime(format_string), tm);

			sprintf_s(DataTypeTemp, MAX_STRING, "%.*s", (int)format_buffer.size(), format_buffer.data());

			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;

			return true;
		}
		catch (const std::exception& e)
		{
			MacroError("Invalid format string: %s", Index);
		}

		return false;
	}

	default: break;
	}

	return false;
}

bool MQ2TimeType::ToString(MQVarPtr VarPtr, char* Destination)
{
	auto pTimePoint = VarPtr.Get<TimeTypeData>();
	if (!pTimePoint)
		return false;

	auto days = date::floor<date::days>(pTimePoint->timePoint);
	auto time = date::make_time(pTimePoint->timePoint - days);
	sprintf_s(Destination, MAX_STRING, "%02d:%02d:%02d",
		(int)time.hours().count(), (int)time.minutes().count(), (int)time.seconds().count());

	return true;
}

bool MQ2TimeType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pTimeType)
		return false;

	VarPtr.Set(Source.Get<TimeTypeData>());
	return true;
}

void MQ2TimeType::InitVariable(MQVarPtr& VarPtr)
{
	VarPtr.Set(TimeTypeData{});
}

bool MQ2TimeType::dataTime(const char* szIndex, MQTypeVar& Ret)
{
	// Get the local time as a time_point (chrono system_clock gives us utc time)
	SYSTEMTIME time;
	GetLocalTime(&time);

	FILETIME ftime;
	SystemTimeToFileTime(&time, &ftime);

	int64_t ftNow = static_cast<int64_t>(ftime.dwLowDateTime)
		+ (static_cast<int64_t>(ftime.dwHighDateTime) << 32LL)
		- 116444736000000000LL;

	TimeTypeData data;
	data.timePoint = TimePointType{ std::chrono::milliseconds{ ftNow / 10000 } };

	Ret.Set(data);
	Ret.Type = pTimeType;
	return true;
}

bool MQ2TimeType::dataGameTime(const char* szIndex, MQTypeVar& Ret)
{
	if (!pWorldData)
		return false;

	Ret = pTimeType->MakeTypeVar(
		pWorldData->Year,
		pWorldData->Month,
		pWorldData->Day,
		pWorldData->Hour - 1,
		pWorldData->Minute,
		0, 0,
		(pWorldData->Day - 1) % 7);

	return true;
}

MQTypeVar MQ2TimeType::MakeTypeVar(int year, int month, int day, int hour, int minute,
	int seconds /* = 0 */, int milliseconds /* = 0 */, int dayOfWeek /*= -1*/)
{
	// Construct a time_point from the given components
	date::year_month_day ymd{
		date::year{ year },
		date::month{ static_cast<unsigned int>(month) },
		date::day{ static_cast<unsigned int>(day) }
	};

	date::local_days days{ ymd };

	// add hms to days to get time_point
	TimePointType timePoint =
		std::chrono::time_point_cast<std::chrono::system_clock::duration>(days)
		+ std::chrono::hours{ hour }
		+ std::chrono::minutes{ minute }
		+ std::chrono::seconds{ seconds }
		+ std::chrono::milliseconds{ milliseconds };

	TimeTypeData data;
	data.timePoint = timePoint;
	data.dayOfWeek = dayOfWeek;

	MQTypeVar Dest;
	Dest.Set(data);
	Dest.Type = this;

	return Dest;
}

MQTypeVar MQ2TimeType::MakeTypeVar(eqtime_t eqtime)
{

	TimeTypeData data;
	data.timePoint = TimePointType{ std::chrono::seconds{eqtime} };

	MQTypeVar Dest;
	Dest.Set(data);
	Dest.Type = this;

	return Dest;
}


//============================================================================

enum class HeadingMembers
{
	Name = 1,
	ShortName = 2,
	Degrees = 3,
	Clock = 4,
	DegreesCCW = 5,
};

MQ2HeadingType::MQ2HeadingType() : MQ2Type("heading")
{
	ScopedTypeMember(HeadingMembers, Name);
	ScopedTypeMember(HeadingMembers, ShortName);
	ScopedTypeMember(HeadingMembers, Degrees);
	ScopedTypeMember(HeadingMembers, Clock);
	ScopedTypeMember(HeadingMembers, DegreesCCW);
}

bool MQ2HeadingType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2HeadingType::FindMember(Member);
	if (!pMember)
		return false;

	float Heading = 360.0f - fmod(VarPtr.Float, 360.0f);
	if (Heading < 0) Heading += 360.0f;

	switch (static_cast<HeadingMembers>(pMember->ID))
	{
	case HeadingMembers::Clock:
		Dest.DWord = ((static_cast<int>(Heading) + 15) / 30) % 12;
		if (Dest.DWord == 0)
			Dest.DWord = 12;
		Dest.Type = pIntType;
		return true;

	case HeadingMembers::Degrees:
		Dest.Float = Heading;
		Dest.Type = pFloatType;
		return true;

	case HeadingMembers::DegreesCCW:
		Dest.Float = VarPtr.Float;
		Dest.Type = pFloatType;
		return true;

	case HeadingMembers::ShortName:
		strcpy_s(DataTypeTemp, szHeadingNormalShort[static_cast<int>(Heading / 22.5f + 0.5f) % 16]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case HeadingMembers::Name:
		strcpy_s(DataTypeTemp, szHeadingNormal[static_cast<int>(Heading / 22.5f + 0.5f) % 16]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2HeadingType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, szHeadingNormalShort[(INT)((360.0f - VarPtr.Float) / 22.5f + 0.5f) % 16]);
	return true;
}

bool MQ2HeadingType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pHeadingType && Source.Type != pFloatType)
		VarPtr.Float = (float)Source.DWord;
	else
		VarPtr.Float = Source.Float;

	return true;
}

bool MQ2HeadingType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.Float = GetFloatFromString(Source, 0);
	return true;
}

bool MQ2HeadingType::dataHeading(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	char szInput[256];
	strcpy_s(szInput, szIndex);

	if (char* pComma = strchr(szInput, ','))
	{
		*pComma = 0;
		float Y = GetFloatFromString(szInput, 0);
		*pComma = ',';
		float X = GetFloatFromString(&pComma[1], 0);

		Ret.Float = static_cast<float>(atan2f(pControlledPlayer->Y - Y, X - pControlledPlayer->X) * 180.0f / PI + 90.0f);
		if (Ret.Float < 0.0f)
			Ret.Float += 360.0f;
		else if (Ret.Float >= 360.0f)
			Ret.Float -= 360.0f;
		Ret.Type = pHeadingType;
		return true;
	}

	Ret.Float = GetFloatFromString(szIndex, 0);
	Ret.Type = pHeadingType;
	return true;
}

//============================================================================

} // namespace mq::datatypes
