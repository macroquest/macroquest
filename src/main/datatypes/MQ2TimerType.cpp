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

bool MQ2TimerType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar & Dest)
{
	MQTimer* pTimer = static_cast<MQTimer*>(VarPtr.Ptr);
	if (!pTimer)
		return false;

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2TimerType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<TimerMethods>(pMethod->ID))
		{
		case Expire:
			pTimer->Current = 0;
			return true;

		case Reset:
			pTimer->Current = pTimer->Original;
			return true;

		case Set:
			FromString(VarPtr, Index);
			return true;

		default: break;
		}
		return false;
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2TimerType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TimerMembers>(pMember->ID))
	{
	case Value:
		Dest.DWord = pTimer->Current;
		Dest.Type = pIntType;
		return true;

	case OriginalValue:
		Dest.DWord = pTimer->Original;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

