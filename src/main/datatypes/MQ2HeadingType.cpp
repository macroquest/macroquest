#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2HeadingType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2HeadingType::FindMember(Member);
	if (!pMember)
		return false;

	float Heading = 360.0f - VarPtr.Float;
	switch (static_cast<HeadingMembers>(pMember->ID))
	{
	case Clock:
		Dest.DWord = ((static_cast<int>(Heading) + 15) / 30) % 12;
		if (Dest.DWord == 0)
			Dest.DWord = 12;
		Dest.Type = pIntType;
		return true;

	case Degrees:
		Dest.Float = Heading;
		Dest.Type = pFloatType;
		return true;

	case DegreesCCW:
		Dest.Float = VarPtr.Float;
		Dest.Type = pFloatType;
		return true;

	case ShortName:
		strcpy_s(DataTypeTemp, szHeadingNormalShort[static_cast<int>(Heading / 22.5f + 0.5f) % 16]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, szHeadingNormal[static_cast<int>(Heading / 22.5f + 0.5f) % 16]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2HeadingType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pHeadingType && Source.Type != pFloatType)
		VarPtr.Float = (float)Source.DWord;
	else
		VarPtr.Float = Source.Float;

	return true;
}

