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

bool MQ2ZoneType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	ZONELIST* pZone = static_cast<ZONELIST*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	MQTypeMember* pMember = MQ2ZoneType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ZoneMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, pZone->LongName);
		Dest.Ptr = &DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case ShortName:
		strcpy_s(DataTypeTemp, pZone->ShortName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ID:
		Dest.Int = pZone->Id & 0x7FFF;
		Dest.Type = pIntType;
		return true;

	case ZoneFlags:
		Dest.Int = pZone->ZoneFlags;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

