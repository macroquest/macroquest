#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2FriendsType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2FriendsType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<FriendsMembers>(pMember->ID))
	{
	case xFriend:
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
						Dest.DWord = 1;
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

