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

bool MQ2TicksType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	uint32_t nTicks = VarPtr.DWord;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TicksMembers>(pMember->ID))
	{
	case Hours:
		Dest.DWord = nTicks / 600;
		Dest.Type = pIntType;
		return true;

	case Minutes:
		Dest.DWord = (nTicks / 10) % 60;
		Dest.Type = pIntType;
		return true;

	case Seconds:
		Dest.DWord = (nTicks * 6) % 60;
		Dest.Type = pIntType;
		return true;

	case TimeHMS: {
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

	case Time: {
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

	case TotalMinutes:
		Dest.DWord = nTicks / 10;
		Dest.Type = pIntType;
		return true;

	case TotalSeconds:
		Dest.DWord = nTicks * 6;
		Dest.Type = pIntType;
		return true;

	case Ticks:
		Dest.DWord = nTicks;
		Dest.Type = pIntType;
		return true;
	}

	return false;
}

bool MQ2TimeStampType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	uint64_t nTimeStamp = VarPtr.UInt64;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TimeStampMembers>(pMember->ID))
	{
	case Hours:
		Dest.UInt64 = (nTimeStamp / 1000) / 3600;
		Dest.Type = pInt64Type;
		return true;

	case Minutes:
		Dest.UInt64 = ((nTimeStamp / 1000) / 60) % 60;
		Dest.Type = pInt64Type;
		return true;

	case Seconds:
		Dest.UInt64 = (nTimeStamp / 1000) % 60;
		Dest.Type = pInt64Type;
		return true;

	case TimeHMS: {
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

	case Time: {
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

	case TotalMinutes:
		Dest.UInt64 = (nTimeStamp / 1000) / 60;
		Dest.Type = pInt64Type;
		return true;

	case TotalSeconds:
		Dest.UInt64 = nTimeStamp / 1000;
		Dest.Type = pInt64Type;
		return true;

	case Raw:
		Dest.UInt64 = nTimeStamp;
		Dest.Type = pInt64Type;
		return true;

	case Float:
		Dest.Float = (float)nTimeStamp / 1000;
		Dest.Type = pFloatType;
		return true;

	case Ticks:
		Dest.UInt64 = ((nTimeStamp / 1000) + 5) / 6;
		Dest.Type = pInt64Type;
		return true;
	}

	return false;
}

