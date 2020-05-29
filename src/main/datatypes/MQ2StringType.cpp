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
	CXStr string;
	if (VarPtr.Ptr != nullptr)
	{
		string = static_cast<const char*>(VarPtr.Ptr);
	}
	else
	{
		string = VarPtr.Get<CXStr>();
	}

	MQTypeMember* pMember = MQ2StringType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<StringMembers>(pMember->ID))
	{
	case StringMembers::Length:
		Dest.DWord = string.length();
		Dest.Type = pIntType;
		return true;

	case StringMembers::Left:
		Dest.Type = pStringType;

		if (Index[0] != 0)
		{
			int Len = GetIntFromString(Index, 0);
			if (Len == 0)
				return false;

			if (Len > 0)
			{
				Dest.SetString(string.substr(0, Len).c_str());
			}
			else // Len < 0
			{
				Len = string.length() + Len;
				if (Len <= 0)
				{
					Dest.SetString("");
				}
				else
				{
					Dest.SetString(string.substr(0, Len).c_str());
				}
			}

			return true;
		}

		return false;

	case StringMembers::Right:
		Dest.Type = pStringType;

		if (Index[0] != 0)
		{
			int Len = GetIntFromString(Index, 0);

			if (Len == 0)
				return false;

			if (static_cast<size_t>(abs(Len)) > string.length())
			{
				Dest.SetString("");
			}
			else if (Len < 0)
			{
				Dest.SetString(string.substr(-Len));
			}
			else // Len > 0
			{
				Dest.SetString(string.substr(string.length() - Len));
			}

			return true;
		}

		return false;

	case StringMembers::Find:
	{
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		int pos = ci_find_substr(string, Index);
		if (pos != -1)
		{
			Dest.DWord = pos + 1;
			return true;
		}

		return false;
	}

	case StringMembers::Replace:
		Dest.Type = pStringType;

		if (!Index[0])
			return false;

		if (char* pComma = strchr(Index, ','))
		{
			std::string_view search_for(Index, std::distance(Index, pComma));
			std::string_view replace_with(&pComma[1]);

			Dest.SetString(replace(string, { std::make_pair(search_for, replace_with) }));
			return true;
		}

		return false;

	case StringMembers::Upper:
	{
		std::string upper(string);
		MakeUpper(upper);
		Dest.SetString(upper);
		Dest.Type = pStringType;
		return true;
	}

	case StringMembers::Lower:
	{
		std::string lower(string);
		MakeLower(lower);
		Dest.SetString(lower);
		Dest.Type = pStringType;
		return true;
	}

	case StringMembers::Compare:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (Index[0] != 0)
		{
			Dest.Int = _stricmp(string.c_str(), Index);
			return true;
		}
		return false;

	case StringMembers::CompareCS:
		Dest.Type = pIntType;
		if (Index[0] != 0)
		{
			Dest.Int = string.compare(Index);
			return true;
		}
		return false;

	case StringMembers::Mid:
		Dest.Type = pStringType;

		if (Index[0] == 0)
			return false;

		if (char* pComma = strchr(Index, ','))
		{
			int start = GetIntFromString(std::string_view(Index, std::distance(Index, pComma)), 0) - 1;
			if (start < 0)
				return false;

			int length = GetIntFromString(&pComma[1], 0) - 1;
			if (length < 0)
				return false;

			if (start > length || (start > 0 && static_cast<size_t>(start) > string.length()))
			{
				Dest.SetString("");
			}
			else
			{
				Dest.SetString(string.substr(start, length));
			}

			return true;
		}

		return false;

	case StringMembers::Equal:
		Dest.Type = pBoolType;
		if (Index[0] != 0)
		{
			Dest.DWord = ci_equals(string, Index);
			return true;
		}
		return false;

	case StringMembers::NotEqual:
		Dest.Type = pBoolType;
		if (Index[0] != 0)
		{
			Dest.DWord = !ci_equals(string, Index);
			return true;
		}
		return false;

	case StringMembers::EqualCS:
		Dest.Type = pBoolType;
		if (Index[0] != 0)
		{
			Dest.DWord = string_equals(string, Index);
			return true;
		}
		return false;

	case StringMembers::NotEqualCS:
		Dest.Type = pBoolType;
		if (Index[0] != 0)
		{
			Dest.DWord = !string_equals(string, Index);
			return true;
		}
		return false;

	case StringMembers::Count:
		Dest.Type = pIntType;
		if (Index[0] != 0)
		{
			Dest.DWord = std::count_if(string.begin(), string.end(), [&Index](const char c)
				{
					return c == Index[0];
				});

			return true;
		}
		return false;

	case StringMembers::Arg:
		Dest.Type = pStringType;
		if (!IsNumberToComma(Index))
			return false;

		if (char* pComma = strchr(Index, ','))
		{
			int index = GetIntFromString(std::string_view(Index, std::distance(Index, pComma)), 0);
			if (index <= 0)
				return false;

			auto vec = split_view(string, pComma[1]);
			vec.erase(std::remove_if(vec.begin(), vec.end(),
				[](std::string_view s) { return s.empty(); }));

			if (vec.size() < static_cast<size_t>(index))
				return false;

			Dest.SetString(vec.at(index - 1));
			return true;
		}

		return false;

	case StringMembers::Token:
		Dest.Type = pStringType;
		if (!IsNumberToComma(Index))
			return false;

		if (char* pComma = strchr(Index, ','))
		{
			int index = GetIntFromString(std::string_view(Index, std::distance(Index, pComma)), 0);
			if (index <= 0)
				return false;

			auto vec = split_view(string, pComma[1]);
			if (vec.size() < static_cast<size_t>(index))
				return false;

			Dest.SetString(vec.at(index - 1));
			return true;
		}

		return false;

	default:
		return false;
	}
}

bool MQ2StringType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (VarPtr.Ptr != nullptr)
	{
		strcpy_s(Destination, MAX_STRING, static_cast<const char*>(VarPtr.Ptr));
	}
	else
	{
		strcpy_s(Destination, MAX_STRING, VarPtr.Get<CXStr>().c_str());
	}

	return true;
}

bool MQ2StringType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pStringType)
		return false;

	if (Source.Ptr != nullptr)
	{
		// assume the source is in a raw char string
		VarPtr.SetString(static_cast<const char*>(Source.Ptr));
	}
	else
	{
		VarPtr.Set(Source.Get<CXStr>());
	}

	return true;
}

bool MQ2StringType::FromString(MQVarPtr& VarPtr, char* Source)
{
	VarPtr.SetString(static_cast<const char*>(Source));
	return true;
}

