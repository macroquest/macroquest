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

enum class AuraTypeMembers
{
	ID = 1,
	Name,
	SpawnID,
	Find,
};

enum class AuraTypeMethods
{
	Remove = 1,
};

MQ2AuraType::MQ2AuraType() : MQ2Type("auratype")
{
	ScopedTypeMember(AuraTypeMembers, ID);
	ScopedTypeMember(AuraTypeMembers, Name);
	ScopedTypeMember(AuraTypeMembers, SpawnID);
	ScopedTypeMember(AuraTypeMembers, Find);

	ScopedTypeMethod(AuraTypeMethods, Remove);
}

bool MQ2AuraType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	AuraData* pAura = reinterpret_cast<AuraData*>(VarPtr.Ptr);
	if (!pAura)
		return false;

	int index = VarPtr.HighPart;

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2AuraType::FindMember(Member);
	if (pMember)
	{
		switch (static_cast<AuraTypeMembers>(pMember->ID))
		{
		case AuraTypeMembers::ID:
			Dest.DWord = index + 1;
			Dest.Type = pIntType;
			return true;

		case AuraTypeMembers::Find: {
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (!Index[0])
				return false;

			int pos = ci_find_substr(pAura->Name, Index);
			if (pos != -1)
			{
				Dest.DWord = pos + 1;
				return true;
			}

			return false;
		}

		case AuraTypeMembers::Name:
			strcpy_s(DataTypeTemp, pAura->Name);
			Dest.Ptr = DataTypeTemp;
			Dest.Type = pStringType;
			return true;

		case AuraTypeMembers::SpawnID:
			Dest.DWord = pAura->SpawnID;
			Dest.Type = pIntType;
			return true;

		default: break;
		};

		return false;
	}

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2AuraType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<AuraTypeMethods>(pMethod->ID))
		{
		case AuraTypeMethods::Remove:
			if (!pAuraWnd)
				break;

			if (CListWnd* clist = (CListWnd*)pAuraWnd->GetChildItem("AuraList"))
			{
				if (index > clist->ItemsArray.Count)
					break;

				clist->SetCurSel(index);
				pAuraWnd->WndNotification(clist, XWM_MENUSELECT, (void*)1);
				return true;
			}
			break;
		}
		return false;
	}

	return false;
}

bool MQ2AuraType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (AuraData* pAura = reinterpret_cast<AuraData*>(VarPtr.Ptr))
	{
		strcpy_s(Destination, MAX_STRING, pAura->Name);
		return true;
	}
	return false;
}

} // namespace mq::datatypes
