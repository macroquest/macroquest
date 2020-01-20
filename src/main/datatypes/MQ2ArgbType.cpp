#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2ArgbType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ArgbMembers>(pMember->ID))
	{
	case A:
		Dest.DWord = VarPtr.Argb.A;
		Dest.Type = pIntType;
		return true;

	case R:
		Dest.DWord = VarPtr.Argb.R;
		Dest.Type = pIntType;
		return true;

	case G:
		Dest.DWord = VarPtr.Argb.G;
		Dest.Type = pIntType;
		return true;

	case B:
		Dest.DWord = VarPtr.Argb.B;
		Dest.Type = pIntType;
		return true;

	case Int:
		Dest.DWord = VarPtr.DWord;
		Dest.Type = pIntType;
		return true;
	}

	return false;
}

