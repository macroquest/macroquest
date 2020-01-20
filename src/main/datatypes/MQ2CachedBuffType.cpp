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

bool MQ2CachedBuffType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	TargetBuff* pcTB = (TargetBuff*)VarPtr.Ptr;
	if (!pcTB)
		return false;

	int buffid = pcTB->spellId;
	if (buffid <= 0)
		return false;

	MQTypeMember* pMember = MQ2CachedBuffType::FindMember(Member);
	if (!pMember)
	{
		if (SPELL* pSpell = GetSpellByID(buffid))
		{
			return pSpellType->GetMember(*(MQVarPtr*)& pSpell, Member, Index, Dest);
		}
		return false;
	}

	switch (static_cast<CachedBuffMembers>(pMember->ID))
	{
	case CasterName:
		strcpy_s(DataTypeTemp, pcTB->casterName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Count:
		Dest.Int = pcTB->count;
		Dest.Type = pIntType;
		return true;

	case Slot:
		Dest.Int = pcTB->slot;
		Dest.Type = pIntType;
		return true;

	case SpellID:
		Dest.Int = pcTB->spellId;
		Dest.Type = pIntType;
		return true;

	case Duration:
		int calcedduration = (pcTB->timeStamp + (pcTB->duration * 6000)) - EQGetTime();
		if (calcedduration < 0)
			calcedduration = 0;
		Dest.Int = calcedduration;
		Dest.Type = pTimeStampType;

		return true;
	}
	return false;
}

