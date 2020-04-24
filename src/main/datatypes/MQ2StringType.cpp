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
	Replace
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
}

bool MQ2StringType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
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
		Dest.DWord = strlen(szString);
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
					Len = StrLen;

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
				Len = StrLen - Len;

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

			int StrLen = strlen(pStr);
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
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (Index[0])
		{
			Dest.DWord = _stricmp(szString, Index) == 0;
			return true;
		}
		return false;

	case StringMembers::NotEqual:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (Index[0])
		{
			Dest.DWord = _stricmp(szString, Index) != 0;
			return true;
		}
		return false;

	case StringMembers::EqualCS:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (Index[0])
		{
			Dest.DWord = strcmp(szString, Index) == 0;
			return true;
		}
		return false;

	case StringMembers::NotEqualCS:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (Index[0])
		{
			Dest.DWord = strcmp(szString, Index) != 0;
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

	default:
		return false;
	}
}

bool MQ2StringType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, static_cast<const char*>(VarPtr.Ptr));
	return true;
}

void MQ2StringType::InitVariable(MQVarPtr& VarPtr)
{
	VarPtr.Ptr = LocalAlloc(LPTR, MAX_STRING);
}

void MQ2StringType::FreeVariable(MQVarPtr& VarPtr)
{
	LocalFree(VarPtr.Ptr);
}

// TODO: This should be using the CXStr underlying type of VarPtr, but that is a very large change
bool MQ2StringType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pStringType)
		return false;

	strcpy_s(DataTypeTemp, static_cast<const char*>(Source.Ptr));
	VarPtr.Ptr = &DataTypeTemp[0];
	return true;
}

// TODO: This should be using the CXStr underlying type of VarPtr, but that is a very large change
bool MQ2StringType::FromString(MQVarPtr& VarPtr, char* Source)
{
	strcpy_s(DataTypeTemp, Source);
	VarPtr.Ptr = &DataTypeTemp[0];
	return true;
}

