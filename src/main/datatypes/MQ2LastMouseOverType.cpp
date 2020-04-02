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

MQ2LastMouseOverType::MQ2LastMouseOverType() : MQ2Type("lastmouseover") {}

bool MQ2LastMouseOverType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	return false;
}

bool MQ2LastMouseOverType::ToString(MQVarPtr VarPtr, char* Destination)
{
	CXWnd* pWnd = static_cast<CXWnd*>(VarPtr.Ptr);

	if (pWnd)
	{
		if (CXMLData* pXMLData = pWnd->GetXMLData())
		{
			strcpy_s(Destination, MAX_STRING, pXMLData->Name.c_str());
			return true;
		}

		return false;
	}

	return true;
}
