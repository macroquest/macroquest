#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2TaskMemberType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	TASKMEMBER* pTaskMemberData = static_cast<TASKMEMBER*>(VarPtr.Ptr);
	if (!pTaskMemberData)
		return false;

	MQTypeMember* pMember = MQ2TaskMemberType::FindMember(Member);
	if (!pMember)
	{
		return false;
	}

	DataTypeTemp[0] = 0;

	switch (static_cast<TaskMemberTypeMembers>(pMember->ID))
	{
	case Name:
		strcpy_s(DataTypeTemp, pTaskMemberData->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Leader:
		Dest.Type = pBoolType;
		if (pTaskMemberData->IsLeader)
			return true;

		return false;

	case xIndex: {
		Dest.DWord = 0;
		Dest.Type = pIntType;
		TASKMEMBER* pTaskmember = pTaskMember;
		for (int i = 1; pTaskmember; pTaskmember = pTaskmember->pNext, i++)
		{
			if (ci_equals(pTaskmember->Name, pTaskMemberData->Name))
			{
				Dest.DWord = i;
				return true;
			}
		}
		return false;
	}

	default: break;
	}

	return false;
}

