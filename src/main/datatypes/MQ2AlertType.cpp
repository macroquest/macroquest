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

namespace mq::datatypes {

enum class AlertTypeMembers
{
	List = 1,
	Size,
};

MQ2AlertType::MQ2AlertType() : MQ2Type("alert")
{
	ScopedTypeMember(AlertTypeMembers, List);
	ScopedTypeMember(AlertTypeMembers, Size);
}

// /echo ${Alert[a].List[b].bGM}
// /echo ${Alert[a].Size}
// /echo ${Alert}
bool MQ2AlertType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!CAlerts.AlertExist(VarPtr.DWord))
		return false;

	MQTypeMember* pMember = MQ2AlertType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<AlertTypeMembers>(pMember->ID))
	{
	case AlertTypeMembers::List:
		if (IsNumber(Index))
		{
			Dest.DWord = MAKELONG(VarPtr.DWord, GetIntFromString(Index, 0));
			Dest.Type = pAlertListType;
			return true;
		}
		break;

	case AlertTypeMembers::Size:
		Dest.Type = pIntType;
		Dest.DWord = static_cast<int>(CAlerts.GetCount(VarPtr.DWord));
		return true;

	default: break;
	}

	return false;
}

bool MQ2AlertType::ToString(MQVarPtr VarPtr, char* Destination)
{
	std::vector<MQSpawnSearch> ss;

	if (CAlerts.GetAlert(VarPtr.DWord, ss))
	{
		_itoa_s(static_cast<int>(ss.size()), Destination, MAX_STRING, 10);
		return true;
	}

	return false;
}

bool MQ2AlertType::dataAlert(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
	{
		char szTemp[2048] = { 0 };

		if (CAlerts.ListAlerts(szTemp, 2048))
		{
			strcpy_s(DataTypeTemp, szTemp);
			Ret.Ptr = &DataTypeTemp[0];
			Ret.Type = pStringType;
			return true;
		}

		return false;
	}

	if (IsNumber(szIndex))
	{
		Ret.DWord = GetIntFromString(szIndex, 0);
		Ret.Type = pAlertType;
		return true;
	}

	return false;
}

} // namespace mq::datatypes
