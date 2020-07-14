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
bool MQ2TicksType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	VarPtr.DWord = Source.DWord;
	return true;
}
bool MQ2TicksType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.DWord = GetIntFromString(Source, 0);
	return true;
}

