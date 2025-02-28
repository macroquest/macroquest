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

enum class FriendsMembers
{
	Friend = 1
};

MQ2FriendsType::MQ2FriendsType() : MQ2Type("friend")
{
	ScopedTypeMember(FriendsMembers, Friend);
}

bool MQ2FriendsType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2FriendsType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<FriendsMembers>(pMember->ID))
	{
	case FriendsMembers::Friend:
		Dest.Type = pStringType;
		if (Index[0] && pChatService)
		{
			CChatService* pChat = pChatService;
			if (IsNumber(Index))
			{
				int i = GetIntFromString(Index, 0) - 1;
				if (i < 0 || i >= pChat->GetNumberOfFriends())
					return false;

				if (const char* ptr = pChat->GetFriendName(i))
				{
					strcpy_s(DataTypeTemp, ptr);
					Dest.Ptr = &DataTypeTemp[0];
					Dest.Type = pStringType;
					return true;
				}
			}
			else
			{
				for (int i = 0; i < pChat->GetNumberOfFriends(); i++)
				{
					if (ci_equals(pChat->GetFriendName(i), Index))
					{
						Dest.Set(true);
						Dest.Type = pBoolType;
						return true;
					}
				}
				return false;
			}
		}
		return false;

	default: break;
	};

	return false;
}

bool MQ2FriendsType::ToString(MQVarPtr VarPtr, char* Destination)
{
	// return the number of friends here...
	if (UniversalChatProxy* pChat = pEverQuest->chatService)
	{
		sprintf_s(Destination, MAX_STRING, "%d", pChat->GetNumberOfFriends());
		return true;
	}
	return false;
}

bool MQ2FriendsType::dataFriends(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pFriendsType;
	return true;
}

} // namespace mq::datatypes
