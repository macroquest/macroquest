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

bool MQ2ArrayType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	CDataArray* pArray = static_cast<CDataArray*>(VarPtr.Ptr);
	if (!pArray)
		return false;

	MQTypeMember* pMember = MQ2ArrayType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ArrayMembers>(pMember->ID))
	{
	case Dimensions:
		Dest.DWord = pArray->GetNumExtents();
		Dest.Type = pIntType;
		return true;

	case Size:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (Index[0])
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index < 0)
				return false;
			if (index < pArray->GetNumExtents())
			{
				Dest.DWord = pArray->GetExtents(index);
				return true;
			}
		}
		else
		{
			Dest.DWord = pArray->GetTotalElements();
			return true;
		}
		return false;

	default: break;
	}

	return false;
}

