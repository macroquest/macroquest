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

bool MQ2TimeType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	tm* pTime = reinterpret_cast<tm*>(VarPtr.Ptr);
	if (!pTime)
		return false;

	MQTypeMember* pMember = MQ2TimeType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TimeMembers>(pMember->ID))
	{
	case Hour:
		Dest.DWord = pTime->tm_hour;
		Dest.Type = pIntType;
		return true;

	case Hour12: {
		unsigned long Hour = pTime->tm_hour % 12;
		if (!Hour)
			Hour = 12;
		sprintf_s(DataTypeTemp, "%d %s", Hour, pTime->tm_hour > 12 ? "PM" : "AM");
		Dest.Ptr = &DataTypeTemp[0],
			Dest.Type = pStringType;
		return true;
	}

	case Minute:
		Dest.DWord = pTime->tm_min;
		Dest.Type = pIntType;
		return true;

	case Second:
		Dest.DWord = pTime->tm_sec;
		Dest.Type = pIntType;
		return true;

	case DayOfWeek:
		Dest.DWord = pTime->tm_wday + 1;
		Dest.Type = pIntType;
		return true;

	case Day:
		Dest.DWord = pTime->tm_mday;
		Dest.Type = pIntType;
		return true;

	case Month:
		Dest.DWord = pTime->tm_mon + 1;
		Dest.Type = pIntType;
		return true;

	case Year:
		Dest.DWord = pTime->tm_year + 1900;
		Dest.Type = pIntType;
		return true;

	case Time12: {
		uint32_t Hour = pTime->tm_hour % 12;
		if (!Hour)
			Hour = 12;

		sprintf_s(DataTypeTemp, "%02d:%02d:%02d", Hour, pTime->tm_min, pTime->tm_sec);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	case Time24:
		sprintf_s(DataTypeTemp, "%02d:%02d:%02d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Date:
		sprintf_s(DataTypeTemp, "%02d/%02d/%04d", pTime->tm_mon + 1, pTime->tm_mday, pTime->tm_year + 1900);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Night:
		Dest.DWord = ((pTime->tm_hour < 7) || (pTime->tm_hour > 20));
		Dest.Type = pBoolType;
		return true;

	case SecondsSinceMidnight:
		Dest.DWord = pTime->tm_hour * 3600 + pTime->tm_min * 60 + pTime->tm_sec;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

