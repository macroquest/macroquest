#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2ArrayType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
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

