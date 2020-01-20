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

MQ2KeyRingType::MQ2KeyRingType() : MQ2Type("keyring")
{
	AddMember(xIndex, "Index");
	AddMember(xName, "Name");
}

bool MQ2KeyRingType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2KeyRingType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<KeyRingTypeMembers>(pMember->ID))
	{
	case xIndex:
		Dest.DWord = LOWORD(VarPtr.DWord) + 1;
		Dest.Type = pIntType;
		return true;

	case xName:
		Dest.Type = pStringType;
		if (CXWnd* krwnd = FindMQ2Window(KeyRingWindowParent))
		{
			CListWnd* clist = nullptr;
			int16_t n = LOWORD(VarPtr.DWord);
			int16_t type = HIWORD(VarPtr.DWord);

			if (type == 2)
				clist = (CListWnd*)krwnd->GetChildItem(FamiliarWindowList);
			else if (type == 1)
				clist = (CListWnd*)krwnd->GetChildItem(IllusionWindowList);
			else
				clist = (CListWnd*)krwnd->GetChildItem(MountWindowList);

			if (clist)
			{
				CXStr Str = clist->GetItemText(n, 2);
				if (!Str.empty())
				{
					strcpy_s(DataTypeTemp, Str.c_str());
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
		}
		return false;
	}
	return false;
}

bool MQ2KeyRingType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (CXWnd* krwnd = FindMQ2Window(KeyRingWindowParent))
	{
		CListWnd* clist = nullptr;

		WORD n = LOWORD(VarPtr.DWord);
		WORD type = HIWORD(VarPtr.DWord);

		if (type == 2)
			clist = (CListWnd*)krwnd->GetChildItem(FamiliarWindowList);
		else if (type == 1)
			clist = (CListWnd*)krwnd->GetChildItem(IllusionWindowList);
		else
			clist = (CListWnd*)krwnd->GetChildItem(MountWindowList);

		if (clist)
		{
			CXStr Str = clist->GetItemText(n, 2);
			if (!Str.empty())
			{
				strcpy_s(Destination, MAX_STRING, Str.c_str());
				return true;
			}
		}
	}
	return false;
}

