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

enum class TimeStampMembers
{
	Hours,
	Minutes,
	Seconds,
	Time,
	TotalMinutes,
	TotalSeconds,
	Raw,
	Ticks,
	TimeHMS,
	Float,
};

MQ2TimeStampType::MQ2TimeStampType() : MQ2Type("timestamp")
{
	ScopedTypeMember(TimeStampMembers, Hours);
	ScopedTypeMember(TimeStampMembers, Minutes);
	ScopedTypeMember(TimeStampMembers, Seconds);
	ScopedTypeMember(TimeStampMembers, Time);
	ScopedTypeMember(TimeStampMembers, TotalMinutes);
	ScopedTypeMember(TimeStampMembers, TotalSeconds);
	ScopedTypeMember(TimeStampMembers, Raw);
	ScopedTypeMember(TimeStampMembers, Ticks);
	ScopedTypeMember(TimeStampMembers, TimeHMS);
	ScopedTypeMember(TimeStampMembers, Float);
}

bool MQ2TimeStampType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	uint64_t nTimeStamp = VarPtr.UInt64;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TimeStampMembers>(pMember->ID))
	{
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
		if (Secs < 0)
			sprintf_s(DataTypeTemp, "Perm");
		else if (Hrs)
			sprintf_s(DataTypeTemp, "%d:%02u:%02u", (unsigned int)Hrs, (unsigned int)Mins, (unsigned int)Secs);
		else
			sprintf_s(DataTypeTemp, "%d:%02u", (unsigned int)Mins, (unsigned int)Secs);
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

bool MQ2TimeStampType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	VarPtr.UInt64 = Source.UInt64;
	return true;
}

bool MQ2TimeStampType::FromString(MQVarPtr& VarPtr, char* Source)
{
	VarPtr.UInt64 = _atoi64(Source);
	return true;
}

