#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

MQ2TypeType::MQ2TypeType() : MQ2Type("type")
{
	AddMember(xName, "Name");
	AddMember(xTypeMember, "Member");
}

bool MQ2TypeType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQ2Type* pType = static_cast<MQ2Type*>(VarPtr.Ptr);
	if (!pType)
		return false;

	MQTypeMember* pMember = MQ2TypeType::FindMember(Member);
	if (!pMember)
		return false;


	switch (static_cast<TypeMembers>(pMember->ID))
	{
	case xName:
		strcpy_s(DataTypeTemp, pType->GetName());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case xTypeMember:
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// name by number
			if (Dest.Ptr = (void*)pType->GetMemberName(GetIntFromString(Index, 0)))
			{
				Dest.Type = pStringType;
				return true;
			}
		}
		else
		{
			// number by name
			if (pType->GetMemberID(Index, (int&)Dest.DWord))
			{
				Dest.Type = pIntType;
				return true;
			}
		}

		return false;

	default: break;
	}

	return false;
}

bool MQ2TypeType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, ((MQ2Type*)VarPtr.Ptr)->GetName());
	return true;
}
bool MQ2TypeType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	VarPtr.Ptr = Source.Type;
	return true;
}

bool MQ2TypeType::FromString(MQVarPtr& VarPtr, char* Source)
{
	if (VarPtr.Ptr = FindMQ2DataType(Source))
		return true;

	return false;
}