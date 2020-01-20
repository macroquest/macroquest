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

bool MQ2TargetBuffType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (VarPtr.Int == -1)
		return false;

	int buffid = pTargetWnd->BuffSpellID[VarPtr.Int];
	if (buffid <= 0)
		return false;

	MQTypeMember* pMember = MQ2TargetBuffType::FindMember(Member);
	if (!pMember)
	{
		if (SPELL* pSpell = GetSpellByID(buffid))
		{
			return pSpellType->GetMember(*(MQVarPtr*)& pSpell, Member, Index, Dest);
		}
		return false;
	}

	static char Temp[128];
	switch (static_cast<TargetBuffMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)&pTargetWnd->BuffSpellID[VarPtr.Int];
		Dest.Type = pIntType;
		return true;

	case xIndex:
		Dest.Int = VarPtr.Int;
		Dest.Type = pIntType;
		return true;

	case Duration:
		Dest.UInt64 = pTargetWnd->BuffTimer[VarPtr.Int];
		Dest.Type = pTimeStampType;
		return true;
	}

	return false;
}

