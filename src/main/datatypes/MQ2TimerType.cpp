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

enum class TimerMembers
{
	Value = 1,
	OriginalValue
};

enum class TimerMethods
{
	Reset = 1,
	Expire,
	Set
};

MQ2TimerType::MQ2TimerType() : MQ2Type("timer")
{
	ScopedTypeMember(TimerMembers, Value);
	ScopedTypeMember(TimerMembers, OriginalValue);

	ScopedTypeMethod(TimerMethods, Reset);
	ScopedTypeMethod(TimerMethods, Expire);
	ScopedTypeMethod(TimerMethods, Set);
}

bool MQ2TimerType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
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
		case TimerMethods::Expire:
			pTimer->Current = 0;
			return true;

		case TimerMethods::Reset:
			pTimer->Current = pTimer->Original;
			return true;

		case TimerMethods::Set:
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
	case TimerMembers::Value:
		Dest.DWord = pTimer->Current;
		Dest.Type = pIntType;
		return true;

	case TimerMembers::OriginalValue:
		Dest.DWord = pTimer->Original;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2TimerType::ToString(MQVarPtr VarPtr, char* Destination)
{
	MQTimer* pTimer = reinterpret_cast<MQTimer*>(VarPtr.Ptr);
	_ultoa_s(pTimer->Current, Destination, MAX_STRING, 10);
	return true;
}

void MQ2TimerType::InitVariable(MQVarPtr& VarPtr)
{
	MQTimer* pVar = new MQTimer();
	pVar->pNext = gTimer;

	if (gTimer)
		gTimer->pPrev = pVar;
	gTimer = pVar;

	VarPtr.Ptr = pVar;
}

void MQ2TimerType::FreeVariable(MQVarPtr& VarPtr)
{
	if (MQTimer* pVar = reinterpret_cast<MQTimer*>(VarPtr.Ptr))
	{
		if (pVar->pPrev)
			pVar->pPrev->pNext = pVar->pNext;
		else
			gTimer = pVar->pNext;
		if (pVar->pNext)
			pVar->pNext->pPrev = pVar->pPrev;

		delete pVar;
	}
}

bool MQ2TimerType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	MQTimer* pTimer = reinterpret_cast<MQTimer*>(VarPtr.Ptr);
	if (Source.Type == pFloatType)
	{
		pTimer->Current = (DWORD)Source.Float;
		pTimer->Original = pTimer->Current;
	}
	else
	{
		pTimer->Current = Source.DWord;
		pTimer->Original = pTimer->Current;
	}
	return true;
}

bool MQ2TimerType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	MQTimer* pTimer = reinterpret_cast<MQTimer*>(VarPtr.Ptr);

	float VarValue = GetFloatFromString(Source, 0);
	switch (Source[strlen(Source) - 1])
	{
	case 'm':
	case 'M':
		VarValue *= 60;
	case 's':
	case 'S':
		VarValue *= 10;
	}
	pTimer->Current = (DWORD)VarValue;
	pTimer->Original = pTimer->Current;
	return true;
}

} // namespace mq::datatypes
