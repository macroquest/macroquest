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

enum class TimeMembers
{
	Hour,
	Minute,
	Second,
	DayOfWeek,
	Day,
	Month,
	Year,
	Time12,
	Time24,
	Date,
	Night,
	SecondsSinceMidnight,
	Hour12,
};

MQ2TimeType::MQ2TimeType() : MQ2Type("time")
{
	ScopedTypeMember(TimeMembers, Hour);
	ScopedTypeMember(TimeMembers, Minute);
	ScopedTypeMember(TimeMembers, Second);
	ScopedTypeMember(TimeMembers, DayOfWeek);
	ScopedTypeMember(TimeMembers, Day);
	ScopedTypeMember(TimeMembers, Month);
	ScopedTypeMember(TimeMembers, Year);
	ScopedTypeMember(TimeMembers, Time12);
	ScopedTypeMember(TimeMembers, Time24);
	ScopedTypeMember(TimeMembers, Date);
	ScopedTypeMember(TimeMembers, Night);
	ScopedTypeMember(TimeMembers, SecondsSinceMidnight);
	ScopedTypeMember(TimeMembers, Hour12);
}

bool MQ2TimeType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	tm* pTime = reinterpret_cast<tm*>(VarPtr.Ptr);
	if (!pTime)
		return false;

	MQTypeMember* pMember = MQ2TimeType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TimeMembers>(pMember->ID))
	{
	case TimeMembers::Hour:
		Dest.DWord = pTime->tm_hour;
		Dest.Type = pIntType;
		return true;

	case TimeMembers::Hour12: {
		unsigned long Hour = pTime->tm_hour % 12;
		if (!Hour)
			Hour = 12;
		sprintf_s(DataTypeTemp, "%d %s", Hour, pTime->tm_hour > 12 ? "PM" : "AM");
		Dest.Ptr = &DataTypeTemp[0],
			Dest.Type = pStringType;
		return true;
	}

	case TimeMembers::Minute:
		Dest.DWord = pTime->tm_min;
		Dest.Type = pIntType;
		return true;

	case TimeMembers::Second:
		Dest.DWord = pTime->tm_sec;
		Dest.Type = pIntType;
		return true;

	case TimeMembers::DayOfWeek:
		Dest.DWord = pTime->tm_wday + 1;
		Dest.Type = pIntType;
		return true;

	case TimeMembers::Day:
		Dest.DWord = pTime->tm_mday;
		Dest.Type = pIntType;
		return true;

	case TimeMembers::Month:
		Dest.DWord = pTime->tm_mon + 1;
		Dest.Type = pIntType;
		return true;

	case TimeMembers::Year:
		Dest.DWord = pTime->tm_year + 1900;
		Dest.Type = pIntType;
		return true;

	case TimeMembers::Time12: {
		uint32_t Hour = pTime->tm_hour % 12;
		if (!Hour)
			Hour = 12;

		sprintf_s(DataTypeTemp, "%02d:%02d:%02d", Hour, pTime->tm_min, pTime->tm_sec);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	case TimeMembers::Time24:
		sprintf_s(DataTypeTemp, "%02d:%02d:%02d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case TimeMembers::Date:
		sprintf_s(DataTypeTemp, "%02d/%02d/%04d", pTime->tm_mon + 1, pTime->tm_mday, pTime->tm_year + 1900);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case TimeMembers::Night:
		Dest.Set(pTime->tm_hour < 7 || pTime->tm_hour > 20);
		Dest.Type = pBoolType;
		return true;

	case TimeMembers::SecondsSinceMidnight:
		Dest.DWord = pTime->tm_hour * 3600 + pTime->tm_min * 60 + pTime->tm_sec;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2TimeType::ToString(MQVarPtr VarPtr, char* Destination)
{
	tm* Now = static_cast<tm*>(VarPtr.Ptr);
	if (!Now)
		return false;

	sprintf_s(Destination, MAX_STRING, "%02d:%02d:%02d", Now->tm_hour, Now->tm_min, Now->tm_sec);
	return true;
}

void MQ2TimeType::InitVariable(MQVarPtr& VarPtr)
{
	VarPtr.Ptr = new tm();
	ZeroMemory(VarPtr.Ptr, sizeof(tm));
}

void MQ2TimeType::FreeVariable(MQVarPtr& VarPtr)
{
	tm* Now = static_cast<tm*>(VarPtr.Ptr);
	delete Now;
}

bool MQ2TimeType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pTimeType)
		return false;

	memcpy(VarPtr.Ptr, Source.Ptr, sizeof(tm));
	return true;
}

